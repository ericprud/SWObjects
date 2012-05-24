/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.cpp,v 1.7 2008-12-02 03:36:12 eric Exp $
 */

#include <set>
#include "ResultSet.hpp"
#include "SWObjectDuplicator.hpp"
#include "XMLQueryExpressor.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "JSONresultsParser/JSONresultsParser.hpp"
#include "BRTparser.hpp"
#include "../interface/SAXparser.hpp"
#include "SPARQLSerializer.hpp"
#include "JSONSerializer.hpp"
#include <iostream>

namespace w3c_sw {

    const char* ResultSet::NS_srx = "http://www.w3.org/2005/sparql-results#";
    const char* ResultSet::NS_xml = "http://www.w3.org/XML/1998/namespace";
    size_t ResultSet::DebugEnumerateLimit = 50;

    void Result::set (const TTerm* variable, const TTerm* value, bool weaklyBound, bool replace) {
	if (variable->toString() == "?") {
	    std::stringstream s;
	    s << "tried to assign empty variable  to \"" << value->toString() << "\"";
	    throw(std::runtime_error(s.str()));
	}
	if (value == TTerm::Unbound)
	    throw std::string("setting ") + variable->toString() + " to Unbound is just wrong";
	BindingSet::const_iterator vi = bindings.find(variable);
	if (replace || vi == bindings.end()) {
	    BindingInfo b = {weaklyBound, value};
	    bindings[variable] = b;
	} else {
	    std::stringstream s;
	    s << "variable " << variable->toString() << " reassigned:"
		" old value:" << bindings[variable].tterm->toString() << 
		" new value:" << value->toString();
	    throw(std::runtime_error(s.str()));
	}
    }

    const TTerm* Result::get (const TTerm* variable) const {
	BindingSet::const_iterator vi = bindings.find(variable);
	if (vi == bindings.end())
	    return NULL;
	else
	    return (*vi).second.tterm;
    }

    XMLSerializer* Result::toXml (XMLSerializer* xml) const {
	XMLQueryExpressor xmlizer(xml);
	xml->open("result");
	xml->attribute("xmlns:xsd", NS_xsd);
	for (BindingSetConstIterator it = bindings.begin(); it != bindings.end(); it++) {
	    xml->open("binding");
	    xml->attribute(it->first->getBindingAttributeName(), it->first->getLexicalValue());
	    if (it->second.weaklyBound) xml->attribute("binding", "weak" );
	    it->second.tterm->express(&xmlizer);
	    xml->close();
	}
	xml->close();
	return xml;
    }

    Result* Result::duplicate (ResultSet* rs, ResultSetConstIterator /* row */) const {
	Result* ret = new Result(rs);
	for (BindingSetConstIterator it = bindings.begin(); it != bindings.end(); it++)
	    ret->set(it->first, it->second.tterm, it->second.weaklyBound);
	return ret;
    }

    ResultSet::ResultSet (AtomFactory* atomFactory) : 
	atomFactory(atomFactory), knownVars(), results(), ordered(false),  db(NULL), 
	selectOrder(), orderedSelect(false), resultType(RESULT_Tabular) {
	results.insert(results.begin(), new Result(this));
    }

    ResultSet::ResultSet (AtomFactory* atomFactory, IStreamContext& sptr, bool ordered, TTerm::String2BNode& nodeMap) : 
	atomFactory(atomFactory), knownVars(), 
	results(), ordered(ordered), db(NULL), selectOrder(), 
	orderedSelect(false), resultType(RESULT_Tabular) {
	if (!parseText(atomFactory, sptr, ordered, nodeMap))
	    throw(std::runtime_error(std::string("no ResultSet constructor for mediatype ")
				     + sptr.mediaType.get()));
    }

    ResultSet::ResultSet (AtomFactory* atomFactory, RdfDB* db, const char* baseURI)
	: atomFactory(atomFactory), knownVars(), 
	  results(), ordered(false), db(NULL), selectOrder(), 
	  orderedSelect(false), resultType(RESULT_Tabular) {

	SPARQLfedDriver sparqlParser(baseURI, atomFactory);
	IStreamContext boolq("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
			     "SELECT ?bool { ?t rs:boolean ?bool . }\n", IStreamContext::STRING);
	Operation* op = sparqlParser.parse(boolq);
	ResultSet booleanResult(atomFactory);
	op->execute(db, &booleanResult);
	delete op;
	sparqlParser.clear(""); // clear out namespaces and base URI.
	if (booleanResult.size() > 0) {
	    ResultSetIterator booleanRecord = booleanResult.begin();
	    const TTerm* btterm = (*booleanRecord)->get(atomFactory->getVariable("bool"));
	    const BooleanRDFLiteral* blit = dynamic_cast<const BooleanRDFLiteral*>(btterm);
	    if (blit == NULL /* !!! || ++booleanRecord != end() */)
		throw std::string("database:\n") + 
		    db->toString() + 
		    "\nis not a validate initializer for a boolen ResultSet.";
	    resultType = RESULT_Boolean;
	    /* So far, size() > 0 is how we test a boolean ResultSet. */
	    if (blit->getValue())
		results.insert(results.begin(), new Result(this));
	} else {
	    /* Get list of known variables. */
	    IStreamContext variablesQ("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
				      "SELECT ?var {?set rs:resultVariable ?var }\n", IStreamContext::STRING);
	    ResultSet listOfVariables(atomFactory);
	    sparqlParser.executeSelect(variablesQ, db, &listOfVariables);
	    sparqlParser.clear(""); // not necessary unless we re-use parser.
	    for (ResultSetIterator resultRecord = listOfVariables.begin(); 
		 resultRecord != listOfVariables.end(); ++resultRecord) {
		const TTerm* varStr = (*resultRecord)->get(atomFactory->getVariable("var" ));
		const TTerm* var  = atomFactory->getVariable(varStr->getLexicalValue());
		knownVars.insert(var);
	    }

	    /* Get list of bindings. */
	    IStreamContext bindingsQ("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
				     "SELECT * {?soln rs:binding [\n"
				     "		 rs:variable ?var ;\n"
				     "		 rs:value ?val\n"
				     " ]} ORDER BY ?soln\n", IStreamContext::STRING);
	    Operation* op = sparqlParser.parse(bindingsQ);
	    ResultSet listOfResults(atomFactory);
	    op->execute(db, &listOfResults);
	    delete op;
	    sparqlParser.clear(""); // not necessary unless we re-use parser.
	    std::map<const TTerm*, Result*> tterm2r;
	    for (ResultSetIterator resultRecord = listOfResults.begin(); 
		 resultRecord != listOfResults.end(); ++resultRecord) {
		const TTerm* soln = (*resultRecord)->get(atomFactory->getVariable("soln"));
		const TTerm* varStr = (*resultRecord)->get(atomFactory->getVariable("var" ));
		const TTerm* var  = atomFactory->getVariable(varStr->getLexicalValue());
		const TTerm* val  = (*resultRecord)->get(atomFactory->getVariable("val" ));
		std::map<const TTerm*, Result*>::iterator ttr = tterm2r.find(soln);
		if (ttr == tterm2r.end()) {
		    Result* r = new Result(this);
		    insert(end(), r);
		    tterm2r[soln] = r;
		}
		set(tterm2r[soln], var, val, false);
	    }
	}
    }

    ResultSet::ResultSet (AtomFactory* atomFactory, SWSAXparser* parser, IStreamContext& sptr) : 
	atomFactory(atomFactory), knownVars(), 
	results(), ordered(false), db(NULL), selectOrder(), 
	orderedSelect(false), resultType(RESULT_Tabular) {
	if (!sptr.mediaType.is_initialized() ||
	    sptr.mediaType.match("application/sparql-results+xml") ||
	    sptr.mediaType.match("application/xml")) {
	    if (parser == NULL)
		throw(std::runtime_error("ResultSet constructor requires a SAX parser."));
	    RSsax handler(this, atomFactory);
	    parser->parse(sptr, &handler);
	} else {
	    TTerm::String2BNode nodeMap;
	    if (!parseText(atomFactory, sptr, false, nodeMap))
		throw(std::runtime_error(std::string()
					 + "ResultSet constructor: no parser for mediatype \""
					 + sptr.mediaType.get()
					 + "\""));
	}
    }

    const TTerm* ResultSet::inventColumName (size_t s) {
	std::stringstream ss;
	ss << "__col" << s;
	const TTerm* ret = atomFactory->getVariable(ss.str());
	BOOST_LOG_SEV(Logger::ParsingLog::get(), Logger::engineer)
	    << "adding name for column " << s << ": " << ret->toString() << "\n";
	return ret;
    }
    void ResultSet::parseDelimSeparated (IStreamContext& sptr, bool ordered,
					 TTerm::String2BNode& nodeMap, 
					 std::string delimStr, bool atHeaderRow) {

	/* Iterate through the input string. */
	std::string str((std::istreambuf_iterator<char>(*sptr.p)),
			std::istreambuf_iterator<char>());
	std::string::const_iterator start = str.begin(); 
	std::string::const_iterator end = str.end(); 
	// boost::smatch what;
	boost::match_results<std::string::const_iterator> what;

	/* Populate <headers> from the first row ... */
	std::vector<const TTerm*> headers;
	/* ... and generate Results for each remaining row. */
	int col = 0;
	int lineNo = 1;
	Result* curRow = NULL;
	enum {AllParsed = 0, NewLine, Delimiter, BOL, TermText, Variable, IRI, Quoted, Double, Float, Integer, Bare, Empty};
	boost::regex ctsv("(\\n|\\r\\n?)"
			    "|(?:("+delimStr+")|(^))"
			    /* \TermText */ "("
			     /* \Variable ?abc  */ "\\?([a-zA-Z0-9_-]+)"
			     /* \IRI <abc>  */     "|<([^>]*)>"
			     /* \Quoted "abc" */   "|\\\"((?:[^\\\\\"]|\\\\[\"nrtb])*)\\\""
			     /* \Double 1.2e3 */   "|([+-]?[0-9]*\\.[0-9]*[Ee][+\\-]?[0-9]+)"
			     /* \Float 1.2   */    "|([+-]?[0-9]*\\.[0-9]*)"
			     /* \Integer 1     */  "|([+-]?[0-9]+)"
			     /* \Bare abc   */     "|([a-zA-Z0-9_-]+)" // ^" + delimStr + "
			     /* \Empty       */    "|()"
			    ")");


	boost::match_flag_type flags = boost::match_perl | boost::match_continuous;
	while (start != end) {
	    if (regex_search(start, end, what, ctsv, flags)) {
		// w3c_sw_LINEN << col << ": looking at \"" << std::string(start, end) << "\"\n";
		// for (size_t i = 0; i < what.size(); ++i)
		// 	w3c_sw_LINEN << i << ": \"" << (what[i].matched ? what[i] : std::string("--")) << "\"\n";

		if (what[NewLine].matched) {
		    BOOST_LOG_SEV(Logger::ParsingLog::get(), Logger::engineer)
			<< "ending " << (atHeaderRow ? "header" : "data") << " row " << lineNo << "\n";
		    atHeaderRow = false;
		    ++lineNo;
		    col = 0;
		    curRow = NULL;
		} else {
		    const TTerm* tterm =
			// If we're looking for variables...
			atHeaderRow ?
			(
			 what[Variable].matched ? (const TTerm*)atomFactory->getVariable(what[Variable]) :
			 what[Quoted]  .matched ? (const TTerm*)atomFactory->getVariable(AtomFactory::unescapeStr(what[Quoted])) :
			 what[Empty]   .matched ? (const TTerm*)TTerm::Unbound : // invent a variable later.
			 (const TTerm*)atomFactory->getVariable(what[TermText]) // Bare et al interpreted as var names.
			 ) :
			// If we're looking for data...
			what[Variable].matched ? (const TTerm*)atomFactory->getVariable(what[Variable]) :
			what[IRI]     .matched ? (const TTerm*)atomFactory->getURI(what[IRI]) :
			what[Quoted]  .matched ? (const TTerm*)atomFactory->getRDFLiteral(AtomFactory::unescapeStr(what[Quoted]), NULL, NULL) :
			what[Double]  .matched ? (const TTerm*)atomFactory->getDoubleLiteral(what[Double]) :
			what[Float]   .matched ? (const TTerm*)atomFactory->getDoubleLiteral(what[Float]) :
			what[Integer] .matched ? (const TTerm*)atomFactory->getDoubleLiteral(what[Integer]) :
			what[Bare]    .matched ? (const TTerm*)atomFactory->getRDFLiteral(what[Bare]) :
			what[Empty]   .matched ? (const TTerm*)TTerm::Unbound :
			atomFactory->getRDFLiteral("internal regex error at " w3c_sw_LOCATION);

		    if (atHeaderRow) {
			if (headers.size() == 0 && what[Delimiter].matched)
			    headers.push_back(inventColumName(0));

			if (what[Empty].matched) {
			    headers.push_back(inventColumName(headers.size()));
			} else {
			    headers.push_back(tterm);
			    BOOST_LOG_SEV(Logger::ParsingLog::get(), Logger::engineer)
				<< "adding name for column " << headers.size() - 1 << ": " << headers[headers.size() - 1]->toString() << "\n";
			}
		    } else {
			// account for the value that should have been at start of line.
			if (col == 0 && what[Delimiter].matched) {
			    if (col > (int)headers.size()-1)
				headers.push_back(inventColumName(headers.size()));
			    ++col;
			}

			// no value
			if (what[Empty].matched) {
			    if (col > (int)headers.size()-1)
				headers.push_back(inventColumName(headers.size()));
			    BOOST_LOG_SEV(Logger::ParsingLog::get(), Logger::engineer)
				<< "no value for column " << col << ": " << headers[col]->toString() << "\n";
			    ++col;
			} else {
			    int lastCol = col;
			    if (col > (int)headers.size()-1)
				headers.push_back(inventColumName(headers.size()));
			    ++col;
			    if (curRow == NULL) {
				curRow = new Result(this);
				insert(this->end(), curRow);
			    }
			    BOOST_LOG_SEV(Logger::ParsingLog::get(), Logger::engineer)
				<< "value for column " << col << ": " << headers[lastCol]->toString() << " is " << tterm->toString() << "\n";
			    set(curRow, headers[lastCol], tterm, false);
			}
		    }
		}
		if (start == what[AllParsed].second)
		    throw std::runtime_error(std::string() + "unable to match at " + boost::lexical_cast<std::string>(lineNo) + ": " + std::string(start, end));
		start = what[AllParsed].second;
	    } else {
		throw std::runtime_error(std::string() + "unable to match at " + boost::lexical_cast<std::string>(lineNo) + ": " + std::string(start, end));
	    }
	}

    }

    void ResultSet::parseTable (IStreamContext& sptr, bool ordered, TTerm::String2BNode& nodeMap) {
	// Note, early returns for CSV and TSV formats:
	if (sptr.mediaType.match("text/tab-separated-values")) {
	    parseDelimSeparated(sptr, true, nodeMap, "\\t", true);
	    return;
	} else if (sptr.mediaType.match("text/csv")) {
	    parseDelimSeparated(sptr, true, nodeMap, ","  , true);
	    return;
	}


	/* Iterate through the input string. */
	std::string str((std::istreambuf_iterator<char>(*sptr.p)),
			std::istreambuf_iterator<char>());
	std::string::const_iterator start = str.begin(); 
	std::string::const_iterator end = str.end(); 
	boost::match_results<std::string::const_iterator> what;

	/* Ignore leading whitespace and comments. */
	boost::match_flag_type flags = boost::match_perl|boost::match_single_line;
	while (regex_search(start, end, what, boost::regex("^[ \\t]*(#[^\\n]*)?\\n"), flags))
	    start = what[0].second; 

	/* Populate <headers> from the first row ... */
	bool firstRow = true;
	std::vector<const TTerm*> headers;
	/* ... and generate Results for each remaining row. */
	int col = 0;
	Result* curRow = NULL;
	enum {WholeString = 0, BoxChars = 1, CapturedTerm = 2, NullBinding = 3};
	const boost::regex srt("^[ \\t\\n]*(?:"		// ignore leading whitespace
			       "("				// \1: box chars
			       "(?:[┌┬┐├┼┤└┴┘─┏┳┓┣╋┫┗┻┛━]+"	//   unicode
			       "|(?:\\+-+)+\\+"		//   ascii
			       ")[ \\t\\n]*"		//     white space
			       //"|#[^\\n]+\\n?"	// in-line comments -- too weird?
			       ")"
			       "|(?:[|│┃][ \\t]*"
			       "("				// \2: captured term
			       "(?:<[^>]*>)"		// IRI
			       "|(?:_:[^[:space:]]+)"	// bnode
			       "|(?:[?$][^[:space:]]+)"	// variable
			       "|(?:\\\"(?:[^\\\\\"]|\\\\[\"nrtb])*\\\"" // literal
			       "(?:\\^\\^<[^>]*>|@[a-z_-]+)?)"
			       "|(?:[+-]?[0-9]*\\.[0-9]*"
			       "[Ee][+\\-]?[0-9]+)"	// double
			       "|(?:[+-]?[0-9]*\\.[0-9]*)"	// float
			       "|(?:[+-]?[0-9]+)"		// integer
			       "|(--|UNDEF)"		// \3: no binding
			       ")?))");
	const boost::regex plain("^[ \\t]*(?:"		// ignore leading whitespace
				 "(.^)"			// disable \1, box chars
				 "|\n|("			// \2: empty if \n
				 "(?:<[^>]*>)"		// IRI
				 "|(?:_:[^[:space:]]+)"	// bnode
				 "|(?:[?$][^[:space:]]+)"	// variable
				 "|(?:\\\"(?:[^\\\\\"]|\\\\[\"nrtb])*\\\"" // literal
				 "(?:\\^\\^<[^>]*>|@[a-z_-]+)?)"
				 "|(?:'[^']*')"		// literal
				 "|(?:[+-]?[0-9]*\\.[0-9]*"
				 "[Ee][+\\-]?[0-9]+)"	// double
				 "|(?:[+-]?[0-9]*\\.[0-9]*)"	// float
				 "|(?:[+-]?[0-9]+)"		// integer
				 "|(--|UNDEF)"		// no binding
				 "))");
	const boost::regex& expr =
	    sptr.mediaType.match("text/plain") ? plain : srt;

	while (regex_search(start, end, what, expr, flags)) {
	    BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		<< "matched \"" << std::string
		(what[WholeString].first, what[WholeString].second) << "\"\n";
	    if (what[BoxChars].first != what[BoxChars].second) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << "skipping box chars: \"" << std::string
		    (what[BoxChars].first, what[BoxChars].second) << "\"\n";
	    } else if (what[CapturedTerm].first == what[CapturedTerm].second) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << "end of header or solution\n";
		firstRow = false;
		col = 0;
		curRow = NULL;
	    } else if (what[NullBinding].first != what[NullBinding].second) {
		if (firstRow) {
		    const BNode* b = atomFactory->createBNode();
		    BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
			<< "fresh header variable: " << b->toString() << "\n";
		    headers.push_back(b);
		} else {
		    if (curRow == NULL) {
			curRow = new Result(this);
			insert(this->end(), curRow);
		    }
		    BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
			<< headers[col]->toString() << "unbound\n";
		    ++col;
		}
	    } else {
		std::string term(what[CapturedTerm].first, what[CapturedTerm].second);
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << "term text: \"" << term << "\"\n";
		const TTerm* tterm = atomFactory->getTTerm(term, nodeMap);
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << "term: " << tterm->toString() << "\n";
		if (firstRow)
		    headers.push_back(tterm);
		else {
		    if (curRow == NULL) {
			curRow = new Result(this);
			insert(this->end(), curRow);
		    }
		    set(curRow, headers[col++], tterm, false);
		}
	    }

	    /* Start after the end of the stuff we just parsed. */
	    start = what[WholeString].second; 
	    BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		<< "starting again at: \"" << std::string(start, end).substr(0, 20) << "\"\n";
	}
	if (start != end) {
	    std::string garbage(start, end);
	    if (garbage.size() > 20)
		garbage = garbage.substr(0, 20)+"...";
	    std::stringstream ss;
	    ss << "Garbage " << (end - start) << " bytes from end of stream: \""
	       << garbage << "\"";
	    throw(std::runtime_error(ss.str()));
	}
    }

    bool ResultSet::parseText (AtomFactory* atomFactory, IStreamContext& sptr, bool ordered, TTerm::String2BNode& nodeMap) {
#if REGEX_LIB != SWOb_DISABLED
	if (!sptr.mediaType.is_initialized() ||
	    sptr.mediaType.match("text/sparql-results") ||
	    sptr.mediaType.match("text/plain") ||
	    sptr.mediaType.match("text/tab-separated-values") ||
	    sptr.mediaType.match("text/csv")) {
	    parseTable(sptr, ordered, nodeMap);
	    return true;
	} else
#endif /* REGEX_LIB != SWOb_DISABLED */
	    if (sptr.mediaType.match("application/sparql-results+json")) {
		JSONresultsDriver jsonResParser(atomFactory);
		jsonResParser.parse(sptr, this);
		return true;
	    }
	    else if (sptr.mediaType.match("application/binary-rdf-results-table") ||
		     sptr.mediaType.match("application/x-binary-rdf-results-table"  )) {
		BRTparser brtParser(atomFactory, *this);
		brtParser(sptr, nodeMap);
		return true;
	    }
	return false;
    }
    ResultSet::~ResultSet () {
	selectOrder.clear();
	for (ResultSetIterator it = results.begin(); it != results.end(); it++)
	    delete *it;
    }

    ResultSet* Result::makeResultSet (AtomFactory* atomFactory) {
	ResultSet* ret = new ResultSet(atomFactory);
	for (BindingSetConstIterator it = bindings.begin(); it != bindings.end(); it++)
	    ret->set(*ret->begin(), it->first, it->second.tterm, it->second.weaklyBound);
	return ret;
    }
    bool Result::isCompatibleWith (const Result* with) const {
	for (BindingSetConstIterator it = with->bindings.begin();
	     it != with->bindings.end(); it++) {
	    const TTerm* val = get(it->first);
	    if (val != NULL && val != it->second.tterm)
		return false;
	}
	return true;
    }
    /**
     * this and with having bindings for at least one common variable.
     */
    bool Result::isContiguousWith (const Result* with) const {
	for (BindingSetConstIterator it = with->bindings.begin();
	     it != with->bindings.end(); it++)
	    if (get(it->first) != NULL)
		return true;
	return false;
    }
    void Result::assumeNewBindings (const Result* from) {
	for (BindingSetConstIterator it = from->bindings.begin(); it != from->bindings.end(); it++)
	    bindings[it->first] = it->second;
	//	    set(it->first, it->second);	
    }

    std::ostream& operator<< (std::ostream& os, Result const& my) {
	return os << my.toString() ;
    }


    ResultSet* ResultSet::clone () {
	ResultSet* ret = new ResultSet(atomFactory);
	delete *ret->begin();
	ret->erase(ret->begin());
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    ret->insert(ret->begin(), (*it)->duplicate(ret, ret->end()));
	return ret;
    }

    struct FilterInjector : public SWObjectDuplicator {
	const ResultSet& rs;
	FilterInjector (AtomFactory* atomFactory, const ResultSet& rs) : SWObjectDuplicator(atomFactory), rs(rs) {  }
	VariableList vars;
	virtual void variable (const Variable* const self, std::string lexicalValue) {
	    vars.insert(self);
	    SWObjectDuplicator::variable(self, lexicalValue);
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern) {
	    ResultSet* joined(NULL);
	    const ResultSet* working = &rs;

	    vars.clear(); // probably got filled with e.g. select vars.
	    p_GroupGraphPattern->express(this);
	    const TableOperation* op = last.tableOperation;
	    const VariableList* knownVars = working->getKnownVars();
	    std::vector<const TTerm*> v(vars.size() + knownVars->size());
	    std::vector<const TTerm*>::iterator end =
		std::set_intersection (vars.begin(), vars.end(), knownVars->begin(),
				       knownVars->end(), v.begin());
	    const std::set<const TTerm*> s(v.begin(), end);
	    const Expression* filter = working->getFederationExpression(s, false);
	    if (filter) {
		Filter* f = new Filter(op);
		f->addExpression(filter);
		op = f;
	    }

	    if (joined)
		delete joined;
	    last.whereClause = new WhereClause(op);
	}
    };

//     const TableOperation* ResultSet::getConstrainedTableOperation (const TableOperation* tableop) {
//     }
    const Operation* ResultSet::getConstrainedOperation (const Operation* op) const {
	/* The VarLister is a serializer which also records all variables.
	 */
	FilterInjector ij((AtomFactory*)atomFactory, *this); // this is const, but the factory isn't.
	op->express(&ij);
	return ij.last.operation;
    }

    const std::string ResultSet::getBindingsString (std::vector<const TTerm*> vars) const {
	std::vector<const TTerm*> ordered(vars.begin(), vars.end());
	std::set<std::string> rows;
	for (ResultSetConstIterator row = begin() ; row != end(); ++row) {
	    std::stringstream rowString;
	    rowString << "(";
	    for (std::vector<const TTerm*>::const_iterator col = ordered.begin();
		 col != ordered.end(); ++col) {
		if (col != ordered.begin())
		    rowString << ", ";
		const TTerm* v = (*row)->get(*col);
		rowString <<
		    (v != NULL
		     ? v->toString()
		     : std::string("UNDEF"));
	    }
	    rowString << ")";
	    rows.insert(rowString.str());
	}
	std::stringstream ret;
	ret << "BINDINGS";
	for (std::vector<const TTerm*>::const_iterator col = ordered.begin();
	     col != ordered.end(); ++col)
	    ret << " " << (*col)->toString();
	ret << " {\n";
	for (std::set<std::string>::const_iterator rowString = rows.begin();
	     rowString != rows.end(); ++rowString)
	    ret << "  " << *rowString << "\n";
	ret << "}";
	return ret.str();
    }

    void ResultSet::set (Result* r, const TTerm* variable, const TTerm* value, bool weaklyBound) {
	VariableList::const_iterator vi = knownVars.find(variable);
	if (vi == knownVars.end())
	    knownVars.insert(variable);
	r->set(variable, value, weaklyBound);
    }

    struct ResultComp {
	std::vector<s_OrderConditionPair>* orderConditions;
	AtomFactory* atomFactory;
	ResultComp (std::vector<s_OrderConditionPair>* orderConditions, AtomFactory* atomFactory) : 
	    orderConditions(orderConditions), atomFactory(atomFactory) {  }
	bool operator() (const Result* lhs, const Result* rhs) {
	    for (std::vector<s_OrderConditionPair>::iterator it = orderConditions->begin();
		 it != orderConditions->end(); ++it) {
		s_OrderConditionPair pair = *it;
		SPARQLSerializer s;
		pair.expression->express(&s);
		const TTerm* l = pair.expression->eval(lhs, atomFactory, NULL);
		const TTerm* r = pair.expression->eval(rhs, atomFactory, NULL);
		if (dynamic_cast<const Bindable*>(l) && 
		    dynamic_cast<const Bindable*>(r))
		    continue;
		if (l != r)
		    return pair.ascOrDesc == ORDER_Desc ? r->safeCmp(*l) == SORT_lt : l->safeCmp(*r) == SORT_lt;
	    }
	    return false;
	}
    };

    const TTerm* _getLabel (const ExpressionAlias* exprAlias, AtomFactory* atomFactory) {
	if (exprAlias->label == NULL) {
	    const TTermExpression* ex = dynamic_cast<const TTermExpression*>(exprAlias->expr);
	    if (ex == NULL) {
		SPARQLSerializer s;
		exprAlias->express(&s);
		return atomFactory->getRDFLiteral(s.str());
	    } else
		return ex->getTTerm();
	} else
	    return exprAlias->label;
    }

    void ResultSet::project (ProductionVector<const ExpressionAlias*> const * projection, ExpressionAliasList* groupBy,
			     ProductionVector<const w3c_sw::Expression*>* having, std::vector<s_OrderConditionPair>* orderConditions) {
	// std::cerr << "start\n" << *this;
	/* List of vars to erase.
	 * This is cheaper than walking all the bindings in a row, but assumes
	 * that the variables for all rows appear in knownVars.
	 */
	std::set<const TTerm*> delMes(knownVars.begin(), knownVars.end());
	if (groupBy != NULL)
	    for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		 it != groupBy->end(); ++it)
		delMes.insert(_getLabel(*it, atomFactory));

	/* Replace the known vars and the select order. */
	knownVars.clear();
	selectOrder.clear();
	orderedSelect = true;

	/* Each groupBy will be toString()'d and appended to groupIndex.
	 * example: <a>~1~11~"Bob"@en~
	 */
	std::string groupIndex;

	/* Map select variables to the expressions bound to them. */
	typedef std::map<const TTerm*,const Expression*> Pos2Expr;
	Pos2Expr pos2expr;

	/* Walk the select list to populate pos2expr. */
	for (std::vector<const ExpressionAlias*>::const_iterator varExpr = projection->begin();
	     varExpr != projection->end(); ++varExpr) {
	    const TTerm* label(_getLabel(*varExpr, atomFactory));

	    /* Add new alias name. */
	    knownVars.insert(label);
	    selectOrder.push_back(label);
	    if (delMes.find(label) != delMes.end())
		delMes.erase(delMes.find(label));

	    /* Duplicate projected expressions, simulated expressions
	     * for the aggregates.
	     */
	    struct AggregateStateInjector : public SWObjectDuplicator {
		std::string& groupIndexRef;
		struct FunctionState : public FunctionCall { // FunctionCall for virtual eval
		protected:
		    std::string& groupIndexRef;
		public:
		    FunctionState (std::string& groupIndexRef, const URI* functionName) : FunctionCall (functionName, NULL), groupIndexRef(groupIndexRef) {  }
		    ~FunctionState () {  }
		    static std::string mitoa (int i) {
			std::stringstream s;
			s << i;
			return s.str();
		    }
		};
		/** NoDelWrapper
		 * Wrap a reference to a FunctionCall; don't delete it.
		 */
		struct NoDelWrapper : public FunctionState { // FunctionCall for virtual eval
		protected:
		    const FunctionCall* func;
		public:
		    NoDelWrapper (std::string& groupIndexRef, const URI* functionName, const FunctionCall* func)
			: FunctionState (groupIndexRef, functionName), func(func) {  }
		    ~NoDelWrapper () {  }
		    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
			return func->eval(r, atomFactory, evaluator);
		    }
		};
		struct CountState : public FunctionState { // FunctionCall for virtual eval
		protected:
		    std::map<std::string, int> counts;
		public:
		    CountState (std::string& groupIndexRef)
			: FunctionState (groupIndexRef, TTerm::FUNC_count) {  }
		    ~CountState () {  }
		    virtual const TTerm* eval (const Result* /* r */, AtomFactory* atomFactory, BNodeEvaluator* /* evaluator */) const {
			int c = ++((CountState*)this)->counts[groupIndexRef];
			return atomFactory->getNumericRDFLiteral(mitoa(c), c);
		    }
		};
		struct SumState : public FunctionState { // FunctionCall for virtual eval
		protected:
		    const Expression* expr;
		    std::map<std::string, const TTerm*> vals;
		public:
		    SumState (std::string& groupIndexRef, const Expression* expr)
			: FunctionState (groupIndexRef, TTerm::FUNC_sum), expr(expr) {  }
		    ~SumState () { delete expr; }
		    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
			if (vals.find(groupIndexRef) == vals.end()) {
			    ((SumState*)this)->vals[groupIndexRef] = expr->eval(r, atomFactory, evaluator);
			} else {
			    ArithmeticSum::NaryAdder f(r, atomFactory, evaluator);
			    std::vector<const Expression*> addends;
			    TTermExpression valExpr(((SumState*)this)->vals[groupIndexRef]);
			    addends.push_back(&valExpr);
			    addends.push_back(expr);
			    ((SumState*)this)->vals[groupIndexRef] = atomFactory->applyCommonNumeric(addends, &f);
			}
			return ((SumState*)this)->vals[groupIndexRef];
		    }
		};
		AggregateStateInjector (AtomFactory* atomFactory, std::string& groupIndexRef) : SWObjectDuplicator(atomFactory), groupIndexRef(groupIndexRef) {  }
		virtual void functionCall (const FunctionCall* const self, const URI* p_IRIref, const ArgList* p_ArgList) {
		    std::vector<const Expression*>::const_iterator it = p_ArgList->begin();

		    /**
		     * Aggregate function invocations:
		     */
		    if (p_IRIref == TTerm::FUNC_count) {
			last.functionCall = new CountState(groupIndexRef);
		    } else if (p_IRIref == TTerm::FUNC_sum) {
			(*it)->express(this);
			last.functionCall = new SumState(groupIndexRef, last.expression);
		    } else {
			/**
			 * Non-aggregate functions invoked 
			 */
			last.functionCall = new NoDelWrapper(groupIndexRef, p_IRIref, self);
		    }
		}
	    };
	    AggregateStateInjector inj(atomFactory, groupIndex);
	    (*varExpr)->expr->express(&inj);
	    pos2expr[label] = inj.last.expression;
	}

	/* Map groupIndex to sole row with that GROUP BY pattern. */
	typedef std::map<std::string, ResultSetIterator> Group2Row;
	Group2Row group2row;

	for (ResultSetIterator row = begin() ; row != end(); ) {

	    ResultSetIterator aggregateRowIt;
	    if (groupBy != NULL) {
		/* eval groupIndex args, add to result */
		groupIndex = "";
		for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		     it != groupBy->end(); ++it) {
		    const TTerm* val = (*it)->expr->eval(*row, atomFactory, NULL);
		    groupIndex += val->toString() + "~";
		    (*row)->set(_getLabel(*it, atomFactory), val, false, true); // !! WG decision on overwrite
		}

		/* This working row may be redundant against an older row (with same
		 * groupIndex).
		 */
		Group2Row::iterator curAgg(group2row.find(groupIndex));
		if (curAgg == group2row.end()) {
		    group2row[groupIndex] = aggregateRowIt = row;
		    row++;
		} else {
		    aggregateRowIt = curAgg->second;
		    delete *row;
		    row = erase(row);
		}
	    } else {
		aggregateRowIt = row;
		row++;
	    }

	    Result* aggregateRow = *aggregateRowIt;

	    /* calculate projection, update idx */
	    for (std::set<const TTerm*>::const_iterator knownVar = knownVars.begin();
		 knownVar != knownVars.end(); ++knownVar) {
		try {
		    const TTerm* val = pos2expr[*knownVar]->eval(aggregateRow, atomFactory, NULL);
		    if (val != TTerm::Unbound)
			aggregateRow->set(*knownVar, val, false, true); // !! WG decision on overwrite
		} catch (TypeError& e) {
		    if (Logger::Logging(Logger::ServiceLog_level, Logger::engineer)) {
			SPARQLSerializer s;
			pos2expr[*knownVar]->express(&s);
			BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::engineer)
			    << "Error evaluating " << s.str() << " on " << aggregateRow->toString();
		    }
		}
	    }

	    if (orderConditions == NULL)
		/* Eliminate unselect attributes. */
		for (std::set<const TTerm*>::const_iterator delMe = delMes.begin();
		     delMe != delMes.end(); ++delMe)
		    if (aggregateRow->find(*delMe) != aggregateRow->end())
			aggregateRow->erase(aggregateRow->find(*delMe));
	}

	/* Enforce HAVING constraints. */
	if (having != NULL)
	    for (ResultSetIterator row = begin() ; row != end(); )
		for (std::vector<const w3c_sw::Expression*>::const_iterator expr = having->begin();
		     expr != having->end(); ++expr)
		    if (atomFactory->eval(*expr, *row) != true) {
			if (Logger::Logging(Logger::ServiceLog_level, Logger::engineer)) {
			    SPARQLSerializer s;
			    (*expr)->express(&s);
			    BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::engineer)
				<< "Evaluating " << s.str() << " removes row " << (*row)->toString();
			}
			delete *row;
			row = erase(row);
		    } else {
			++row;
		    }


	if (orderConditions != NULL) {
	    ResultComp resultComp(orderConditions, atomFactory);
	    results.sort(resultComp);
	    /* Eliminate unselect attributes. */
	    for (ResultSetIterator row = begin() ; row != end(); ++row)
		for (std::set<const TTerm*>::const_iterator delMe = delMes.begin();
		     delMe != delMes.end(); ++delMe) {
		    BindingSetIterator attr = (*row)->find(*delMe);
		    if (attr != (*row)->end())
			(*row)->erase(attr);
		}
	}

	/* Clean up new'd expressions. */
	for (Pos2Expr::iterator it = pos2expr.begin(); it != pos2expr.end(); ++it) {
	    const Expression* exp = it->second;
	    delete exp;
	}
	// std::cerr << "end\n" << *this;
    }

    void ResultSet::restrictResults (const Expression* expression) { // no longer called "restrict" 'cause it screws up php.

	if (Logger::Logging(Logger::ServiceLog_level, Logger::engineer)) {
	    SPARQLSerializer s;
	    expression->express(&s);
	    BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::engineer) << "Filtering on " << s.str();
	}
	for (ResultSetIterator it = begin(); it != end(); ) {
	    if (atomFactory->eval(expression, *it) == true) {
		BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::engineer) << "    keep " << (*it)->toString();
		++it;
	    } else {
		BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::support ) << "  strike " << (*it)->toString();
		delete *it;
		it = erase(it);
	    }
	}
    }

    void ResultSet::order () {
    	std::set<const Result*> unordered;
    	AscendingOrder resultComp(getOrderedVars(), &unordered);
    	results.sort(resultComp);
    }

    void ResultSet::trim (e_distinctness distinctness, int limit, int offset) {
	if (distinctness == DIST_distinct)
	    for (ResultSetIterator lead = begin() ; lead != end(); ) {
		bool matched = false;
		for (ResultSetIterator look = begin() ; look != lead; ++look)
		    if (**look == **lead) {
			delete *lead;
			lead = erase(lead);
			matched = true;
			break;
		    }
		if (matched == false)
		    ++lead;
	    }

	if (offset != OFFSET_None) {
	    int at = 0;
	    for (ResultSetIterator it = begin() ; it != end() && at < offset; ++at) {
		delete *it;
		it = erase(it);
	    }
	}

	if (limit != LIMIT_None) {
	    int at = 0;
	    ResultSetIterator it = begin();
	    for ( ; it != end() && at < limit; ++at)
		++it;
	    for ( ; it != end(); ++at) {
		delete *it;
		it = erase(it);
	    }
	}
    }
#if !defined SWIG
    BoxChars BoxChars::AsciiBoxChars(false, // instraRow
			   "--", // unbound
			   "O", // ordered
			   "!", // unlistedVar
			   /*        .l   .b   .s   .r */
			   /* u. */ "+", "-", "+", "+", 
			   /* r. */ "|", " ", "|", "|", 
			   /* s. */ "+", "-", "+", "+", 
			   /* l. */ "+", "-", "+", "+"
			   );
    BoxChars BoxChars::Utf8BoxChars (false, // instraRow
			   "--", // unbound
			   "O", // ordered
			   "!", // unlistedVar
			   /* Fancy rounded box chars not supported in many fonts: */
			   /*   "◜", "─", "┬", "◝", */
			   /*        .l   .b   .s   .r */
			   /* u. */ "┌", "─", "┬", "┐", 
			   /* r. */ "│", " ", "│", "│", 
			   /* s. */ "├", "─", "┼", "┤", 
			   /* l. */ "└", "─", "┴", "┘"
			   );

    /* Fancy rounded box chars not supported in many fonts: */
    BoxChars BoxChars::Utf8BldChars (false, // instraRow
			   "--", // unbound
			   "O", // ordered
			   "!", // unlistedVar
			   /*        .l   .b   .s   .r */
			   /* u. */ "┏", "━", "┯", "┓", 
			   /* r. */ "┃", " ", "│", "┃", 
			   /* s. */ "┠", "─", "┼", "┨", 
			   /* l. */ "┗", "━", "┷", "┛"
			   );
#endif /* !defined SWIG */

    BoxChars* BoxChars::GBoxChars = &BoxChars::AsciiBoxChars;

    class STRING : public std::string {
    public:
	STRING (size_t repts, const char* str) : std::string() {
	    for (size_t i = 0; i < repts; ++i)
		append(str);
	    }
    };

    std::string render (const TTerm* p, NamespaceMap* namespaces) {
	return
	    p == TTerm::Unbound
	    ? BoxChars::GBoxChars->unbound
	    : (namespaces == NULL || dynamic_cast<const URI*>(p) == NULL)
	    ? p->toString()
	    : namespaces->unmap(p->getLexicalValue());
    }

    std::string ResultSet::toString (NamespaceMap* namespaces) const {
	std::stringstream s;
	if (resultType == RESULT_Boolean)
	    return size() > 0 ? "true\n" : "false\n" ;

	else if (resultType == RESULT_Graphs)
	    return std::string("<RdfDB result>\n") + db->toString() + "\n</RdfDB result>";

	/* Get column widths and fill namespace declarations. */
	std::vector< const TTerm* > vars;
	std::vector< size_t > widths;
	unsigned count = 0;
	unsigned lastInKnownVars = 0;
	{
	    std::map< const TTerm*, unsigned > pos2col;
	    const VariableVector cols = getOrderedVars();
//	    vars = getOrderedVars();
	    for (VariableVectorConstIterator varIt = cols.begin() ; varIt != cols.end(); ++varIt) {
		const TTerm* var = *varIt;
		pos2col[var] = count++;
		widths.push_back(var->toString().size());
		vars.push_back(var);
	    }

	    VariableList intruders;
	    lastInKnownVars = count;
	    for (ResultSetConstIterator row = results.begin() ; row != results.end(); ++row)
		for (BindingSetIterator b = (*row)->begin(); b != (*row)->end(); ++b) {
		    const TTerm* var = b->first;
		    if (pos2col.find(var) == pos2col.end()) {
			/* Error: a variable not listed in knownVars. */
			pos2col[var] = count++;
			std::string rendered(render(var, namespaces));
			widths.push_back(rendered.size());
			vars.push_back(var);
			intruders.insert(var);
		    }
		    std::string rendered(render(b->second.tterm, namespaces));
		    size_t width = rendered.size();
		    if (width > widths[pos2col[var]])
			widths[pos2col[var]] = width;
		}
	}

	/* Generate ResultSet string. */
	/*   Top Border */
	unsigned i;
	for (i = 0; i < count; i++) {
	    s << (i == 0 ? (ordered == true ? BoxChars::GBoxChars->ordered : BoxChars::GBoxChars->ul) : BoxChars::GBoxChars->us);
	    s << STRING(widths[i]+2, BoxChars::GBoxChars->ub);
	}
	if (count == 0)
	    s << BoxChars::GBoxChars->ul << BoxChars::GBoxChars->ub;
	s << BoxChars::GBoxChars->ur << std::endl;

	/*   Column Headings */
	for (i = 0; i < count; i++) {
	    const TTerm* var = vars[i];
	    s << (i == 0 ? BoxChars::GBoxChars->rl : i < lastInKnownVars ? BoxChars::GBoxChars->rs : BoxChars::GBoxChars->unlistedVar) << ' ';
	    size_t width = var->toString().length();
	    s << var->toString() << STRING(widths[i] - width, BoxChars::GBoxChars->rb) << ' '; // left justified.
	}
	if (count == 0)
	    s << (i == 0 ? BoxChars::GBoxChars->rl : BoxChars::GBoxChars->rs) << ' ';
	s << BoxChars::GBoxChars->rr << std::endl;

	/*  Rows */
	for (ResultSetConstIterator row = results.begin() ; row != results.end(); row++) {
#if (INTRA_ROW_SEPARATORS)
	    /*  Intra-row Border */
	    for (i = 0; i < count; i++) {
		s << (i == 0 ? BoxChars::GBoxChars->sl : BoxChars::GBoxChars->ss);
		s << std::string(widths[i]+2, BoxChars::GBoxChars->sb);
	    }
	    s << BoxChars::GBoxChars->sr << std::endl;
#endif
	    /*  Values */
	    for (i = 0; i < count; ++i) {
		const TTerm* var = vars[i];
		const TTerm* val = (*row)->get(var);
		if (val == NULL)
		    val = TTerm::Unbound;
		const std::string str = render(val, namespaces);
		s << (i == 0 ? BoxChars::GBoxChars->rl : BoxChars::GBoxChars->rs) << ' ';
		size_t width = str.length();
		s << STRING(widths[i] - width, BoxChars::GBoxChars->rb) << str << ' '; // right justified.
	    }
	    if (count == 0)
		s << BoxChars::GBoxChars->rl << ' ';
	    s << BoxChars::GBoxChars->rr << std::endl;
	}

	/*   Bottom Border */
	for (i = 0; i < count; i++) {
	    s << (i == 0 ? BoxChars::GBoxChars->ll : BoxChars::GBoxChars->ls);
	    s << STRING(widths[i]+2, BoxChars::GBoxChars->lb);
	}
	if (count == 0)
	    s << BoxChars::GBoxChars->ll << BoxChars::GBoxChars->lb;
	s << BoxChars::GBoxChars->lr << std::endl;
	return s.str();
    }
    XMLSerializer* ResultSet::toXml (XMLSerializer* xml) const {
	switch (resultType) {
	case RESULT_Error:
	    throw std::runtime_error("unable to serialize malformed ResultSet.");
	case RESULT_Graphs:
	    xml->rawData(toString(MediaType("text/turtle"))); // !! Evolve to RDF/XML serializer.
	    break;
	case RESULT_Tabular:
	case RESULT_Boolean:
	    if (xml == NULL) xml = new XMLSerializer("  ");
	    xml->open("sparql");
	    xml->attribute("xmlns", "http://www.w3.org/2005/sparql-results#");
	    xml->open("head");
	    if (resultType == RESULT_Tabular) {
		const VariableVector cols = getOrderedVars();
		for (VariableVectorConstIterator varIt = cols.begin() ; varIt != cols.end(); ++varIt) {
		    xml->empty("variable");
		    xml->attribute("name", (*varIt)->getLexicalValue());
		}
	    }
	    xml->close();
	    if (resultType == RESULT_Tabular) {
		xml->open("results");
		for (ResultSetConstIterator it = begin() ; it != end(); it++)
		    (*it)->toXml(xml);
		xml->close();
	    } else {
		assert (resultType == RESULT_Boolean);
		xml->leaf("boolean", size() > 0 ? "true" : "false");
	    }
	    xml->close();
	    break;
	}
	return xml;
    }

    XMLSerializer* ResultSet::toHtmlTable (XMLSerializer* xml, XMLSerializer::Attributes attributes, std::string editPath) const {
	// Early returns
	if (resultType != RESULT_Tabular) {
	    xml->leaf("pre", toString(MediaType("text/turtle")));
	    return xml;
	}
	if (xml == NULL) xml = new XMLSerializer("  ");
	xml->open("table");
	xml->attributes(attributes);
	{
	    const VariableVector cols = getOrderedVars();
	    xml->open("thead"); {
		xml->open("tr"); {
		    if (!editPath.empty()) {
			xml->open("th"); xml->close();
		    }
		    for (VariableVector::const_iterator col = cols.begin();
			 col != cols.end(); ++col)
			xml->leaf("th", (*col)->toString());
		} xml->close();
	    } xml->close();
	    xml->open("tbody"); {
		size_t rowNo = 0;
		bool even = true; // 0 is even.
		for (ResultSetConstIterator row = begin(); row != end(); ++row, ++rowNo) {
		    xml->open("tr"); {
			std::string rowNoStr;
			if (!editPath.empty()) {
			    std::stringstream rowNoss;
			    rowNoss << "_" << rowNo;
			    rowNoStr = rowNoss.str();
			    xml->attribute("id", rowNoStr);
			}
			if ((even ^= 1) == true)
			    xml->attribute("class", "even");
			if (!editPath.empty()) {
//    <td>
//	<input id="_1_query" name="query" type="hidden" value="DELETE { &lt;/abcd&gt; { &lt;/as/s&gt; &lt;/as/p1&gt; &lt;/as/o1&gt; } }"/>
//	<input id="_1_submit" type="submit" value="delete"/>
//    </td>
			    xml->open("td"); {
				xml->open("form"); {
				    xml->attribute("id", rowNoStr + "_form");
				    xml->attribute("action", editPath);
				    xml->attribute("method", "post");
				    xml->open("input"); {
					xml->attribute("name", "media");
					xml->attribute("value", "edit");
					xml->attribute("type", "hidden");
				    } xml->close();
				    xml->open("input"); {
					xml->attribute("id", rowNoStr + "_query");
					xml->attribute("name", "query");
					xml->attribute("type", "hidden");
					std::stringstream delSS;
					// delSS << "DELETE DATA { GRAPH <" << editPath << "> { ";
					delSS << "DELETE DATA { ";
					for (VariableVector::const_iterator col = cols.begin();
					     col != cols.end(); ++col) {
					    const TTerm* val = (*row)->get(*col);
					    if (val != NULL)
						delSS <<  val->toString() << " ";
					    else 
						delSS << "[] ";
					}
					// delSS << "} }";
					delSS << "}";
					xml->attribute("value", delSS.str());
				    } xml->close();

				    xml->open("input"); {
					xml->attribute("id", rowNoStr + "_submit");
					xml->attribute("type", "submit");
					xml->attribute("value", "delete");
				    } xml->close();
				} xml->close();
			    } xml->close();
			}
			size_t colNo = 0;
			for (VariableVector::const_iterator col = cols.begin();
			     col != cols.end(); ++col, ++colNo) {
			    const TTerm* val = (*row)->get(*col);
			    if (val != NULL) {
				std::string colNoStr;
				if (!editPath.empty()) {
				    std::stringstream colNoss;
				    colNoss << "_" << colNo;
				    colNoStr = colNoss.str();
//    <span id="_1_0" onkeyup="modify('_1');" contenteditable="true">
				    xml->open("td"); {
					xml->leaf("span", val->toString());
					xml->attribute("onkeyup", std::string("modify('") + rowNoStr + "');");
					xml->attribute("contenteditable", "true");
					xml->attribute("id", rowNoStr + colNoStr);
				    } xml->close();
				} else {
				    xml->leaf("td", val->toString());
				}
			    } else {
				xml->open("td");
				xml->leaf("code", std::string("NULL")); // so it doesn't call leaf(std::string tag, bool p_value) (naughty c++)
				xml->close();
			    }
			}
		    } xml->close();
		} xml->close();
	    }
	} xml->close(); // table
	return xml;
    }

    std::string ResultSet::toDelimSeparatedValues (char separator, bool headerAsLexicals, NamespaceMap* namespaces) const {
	std::stringstream ret;
	const VariableVector vars = getOrderedVars();
	for (VariableVector::const_iterator var = vars.begin();
	     var != vars.end(); ++var) {
	    if (var != vars.begin())
		ret << separator;
	    ret << (headerAsLexicals ? (*var)->getLexicalValue() : (*var)->toString());
	}
	ret << "\n";
	for (ResultSetConstIterator row = begin() ; row != end(); ++row) {
	    for (VariableVector::const_iterator var = vars.begin();
		 var != vars.end(); ++var) {
		if (var != vars.begin())
		    ret << separator;
		const TTerm* val = (*row)->get(*var);
		if (val != NULL)
		    ret << val->toString();
	    }
	    ret << "\n";
	}
	return ret.str();
    }
    std::string ResultSet::toJSON (NamespaceMap* namespaces) const {
	std::stringstream ss;
	JSONSerializer jdoc(ss, JSONSerializer::Container_Map, "    "); {
	    jdoc.openMap("head"); {
		jdoc.openList("link"); {
		    jdoc.literal("http://www.w3.org/TR/rdf-sparql-XMLres/example.rq");
		} jdoc.closeList();
		jdoc.openList("vars"); {
		    for (std::set<const TTerm*>::const_iterator var = knownVars.begin();
			 var != knownVars.end(); ++var) {
			jdoc.literal((*var)->getLexicalValue());
		    }
		} jdoc.closeList();
	    } jdoc.closeMap();
	    jdoc.openMap("results"); {
		jdoc.openList("bindings"); {
		    for (ResultSetConstIterator row = begin() ; row != end(); ++row) {
			jdoc.openMap(); {
			    for (BindingSetConstIterator binding = (*row)->begin();
				 binding != (*row)->end(); ++binding) {
				const TTerm* var = binding->first;
				const TTerm* val = binding->second.tterm;
				jdoc.openMap(var->getLexicalValue()); {
				    jdoc.literal("value", val->getLexicalValue());
				    switch (val->getTypeOrder()) {
				    case TTerm::TYPE_BNode:
					jdoc.literal("type", "bnode");
					break;
				    case TTerm::TYPE_URI:
					jdoc.literal("type", "uri");
					break;
				    default:
					const RDFLiteral* lit = dynamic_cast<const RDFLiteral*>(val);
					jdoc.literal("type", lit->getDatatype() ? "typed-literal" : "literal");
					if (lit->getDatatype())
					    jdoc.literal("datatype", lit->getDatatype()->getLexicalValue());
					if (lit->getLangtag())
					    jdoc.literal("xml:lang", lit->getLangtag()->getLexicalValue());
				    }
				} jdoc.closeMap();
			    }
			} jdoc.closeMap();
		    }
		} jdoc.closeList();
	    } jdoc.closeMap();
	} jdoc.closeMap();
	ss << "\n";
	return ss.str();
    }

    std::ostream& operator<< (std::ostream& os, ResultSet const& my) {
	return os << my.toString() ;
    }
}

