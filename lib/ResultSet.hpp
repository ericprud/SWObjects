/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.hpp,v 1.10 2008-12-02 04:55:46 eric Exp $

 Consider reverting to a version before BindingInfo:
   ResultSet.hpp,v 1.10 2008/08/13 22:47:37
   ResultSet.cc,v 1.11 2008/08/13 22:47:36
 and storing the weakness in a wrapper class created / Result.

 */

#ifndef RESULT_SET_H
#define RESULT_SET_H

#include <set>
#include <list>
#include "SWObjects.hpp"
#include "RdfDB.hpp"
#include "XMLSerializer.hpp"
#include "../interface/SAXparser.hpp"
#include "SPARQLSerializer.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"

namespace w3c_sw {

    typedef struct { bool weaklyBound; const POS* pos; } BindingInfo;
    typedef std::map<const POS*, BindingInfo> BindingSet;
    typedef std::map<const POS*, BindingInfo>::iterator BindingSetIterator;
    typedef std::map<const POS*, BindingInfo>::const_iterator BindingSetConstIterator;
    //typedef std::pair<std::map<POS*,POS*>::iterator, bool> InsertRet;
    typedef std::set<const POS*> VariableList;
    typedef std::set<const POS*>::iterator VariableListIterator;
    typedef std::set<const POS*>::const_iterator VariableListConstIterator;

    typedef std::list<Result*> ResultList;
    typedef std::list<Result*>::iterator ResultSetIterator;
    typedef std::list<Result*>::const_iterator ResultSetConstIterator;


    class Result {
    protected:
	BindingSet bindings;
    public:
	Result (ResultSet*) : bindings() {  }
	Result (const Result& ref) : bindings() {
	    for (BindingSetConstIterator it = ref.begin(); it != ref.end(); ++it) {
		const POS* var = it->first;
		BindingInfo bi(it->second);
		bindings[var] = bi;
	    }
	}
	~Result () {  }
	std::string toString () const {
	    std::stringstream s;
	    s << "{";
	    for (BindingSetConstIterator it = bindings.begin(); it != bindings.end(); ++it)
		s << (it == bindings.begin() ? "" : ", ")
		  << it->first->toString() << "="
		  << it->second.pos->toString();
	    s << "}";
	    return s.str();
	}
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	BindingSetIterator begin () { return bindings.begin(); }
	BindingSetConstIterator begin () const { return bindings.begin(); }
	BindingSetIterator end () { return bindings.end(); }
	BindingSetConstIterator end () const { return bindings.end(); }
	size_t size () const { return bindings.size(); }
	BindingSetIterator find (const POS* pos) { return bindings.find(pos); }
	void erase (BindingSetIterator it) { bindings.erase(it); }

	const POS* get(const POS* variable) const;
	/* set should only be used by ResultSet::set if you want to keep the
	   header consistent.
	 */
	void set(const POS* variable, const POS* value, bool weaklyBound, bool replace = false);
	Result* duplicate(ResultSet* rs, ResultSetIterator row);

	ResultSet* makeResultSet(POSFactory* posFactory);
	void assumeNewBindings(Result* from);
    };

    class ResultSet {
    protected:
	POSFactory* posFactory;
	VariableList knownVars;
	ResultList results;
	bool ordered;
	bool isBool;
	BasicGraphPattern* bgp;
	RdfDB* db;
	ProductionVector<const POS*> selectOrder;
	bool orderedSelect;

    public:
	static const char* NS_srx;
	static const char* NS_xml;

	ResultSet(POSFactory* posFactory);
	ResultSet (const ResultSet& ref) : 
	    posFactory(ref.posFactory), knownVars(ref.knownVars), 
	    results(), ordered(ref.ordered), isBool(ref.isBool), 
	    bgp(ref.bgp), db(ref.db), selectOrder(), orderedSelect(false) {
	    for (ResultSetConstIterator row = ref.results.begin() ; row != ref.results.end(); row++)
		insert(this->end(), new Result(**row));
	}
	/* Parsed constructor, a la
		ResultSet(&f, 
			  "?n1  _:n2\n"
			  "<n1> <n2>\n"
			  "<n4> \"l1\"" )
	 * A \n on the last line creates a row with no bindings.
	 */
#if REGEX_LIB != SWOb_DISABLED
	ResultSet (POSFactory* posFactory, std::string str, bool ordered) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(ordered), isBool(false), 
	    bgp(NULL), db(NULL), selectOrder(), orderedSelect(false) {
	    const boost::regex expression("[ \\t]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\")|\\n)");
	    std::string::const_iterator start, end; 
	    start = str.begin(); 
	    end = str.end(); 
	    boost::match_results<std::string::const_iterator> what;
	    boost::match_flag_type flags = boost::match_default;
	    bool firstRow = true;
	    std::vector<POS*> headers;
	    int col = 0;
	    Result* curRow;
	    while (regex_search(start, end, what, expression, flags)) {
		std::string matched(what[1].first, what[1].second);
		if (matched == "\n") {
		    firstRow = false;
		    col = 0;
		    curRow = new Result(this);
		    insert(this->end(), curRow);
		} else {
		    POS* pos = posFactory->getPOS(matched);
		    if (firstRow)
			headers.push_back(pos);
		    else
			set(curRow, headers[col++], pos, false);
		}

		start = what[0].second; 
		// update flags: 
		flags |= boost::match_prev_avail; 
		flags |= boost::match_not_bob; 
	    }
	}
#endif /* REGEX_LIB != SWOb_DISABLED */

	class RSsax : public SWSAXhandler {
	protected:
	    ResultSet* rs;
	    POSFactory* posFactory;

	    enum STATES {DOCUMENT, SPARQL, HEAD, LINK, VARIABLE, BOOLEAN,
			 RESULTS, RESULT, BINDING, _URI, BNODE, LITERAL, 
			 s_ERROR};
	    std::vector<std::string> knownVars;
	    std::stack<enum STATES> stateStack;
	    Result* result;
	    POS* variable;
	    URI* datatype;
	    std::string lang;
	    std::string chars;

	    const char* stateStr () {
		static const char* stateStrs[] =
		    {"document", "sparql", "head", "link", "variable", "boolean",
		     "results", "result", "binding", "uri", "bnode", "literal", "huh?"};
		return stateStrs[stateStack.top()];
	    }

	public:
	    RSsax (ResultSet* rs, POSFactory* posFactory) : 
		rs(rs), posFactory(posFactory), result(NULL), variable(NULL), datatype(NULL), chars("") {
		stateStack.push(DOCUMENT);
	    }

	    virtual void startElement (std::string uri,
				       std::string localName,
				       std::string qName,
				       Attributes* attrs, 
				       NSmap& /* nsz */) {
		if (uri != NS_srx)
		    varError("element in unexpected namespace {%s}%s within %s", qName.c_str(), uri.c_str(), stateStr());
		enum STATES newState = s_ERROR;
		switch (stateStack.top()) {
		case DOCUMENT:
		    if (localName == "sparql")
			newState = SPARQL;
		    break;
		case SPARQL:
		    if (localName == "head")
			newState = HEAD;
		    else if (localName == "boolean")
			newState = BOOLEAN;
		    else if (localName == "results")
			newState = RESULTS;
		    break;
		case HEAD:
		    if (localName == "link")
			newState = LINK;
		    else if (localName == "variable") {
			newState = VARIABLE;
			knownVars.push_back(attrs->getValue("", "name"));
		    }
		    break;
		case LINK:
		    break;
		case VARIABLE:
		    break;
		case BOOLEAN:
		    break;
		case RESULTS:
		    if (localName == "result") {
			newState = RESULT;
			result = new Result(rs);
			rs->insert(rs->end(), result);
		    } break;
		case RESULT:
		    if (localName == "binding") {
			newState = BINDING;
			variable = posFactory->getVariable(attrs->getValue("", "name"));
		    } break;
		case BINDING:
		    if (localName == "uri")
			newState = _URI;
		    else if (localName == "bnode")
			newState = BNODE;
		    else if (localName == "literal") {
			newState = LITERAL;
			std::string s = attrs->getValue("", "datatype");
			datatype = s.size() == 0 ? NULL : posFactory->getURI(s.c_str());
			lang = attrs->getValue(NS_xml, "lang");
		    }
		    break;
		case _URI:
		    break;
		case BNODE:
		    break;
		case LITERAL:
		    break;
		default:
		    varError("unexpected element %s within %s", qName.c_str(), stateStr());
		}
		if (newState == s_ERROR)
		    varError("unexpected element %s within %s", qName.c_str(), stateStr());
		stateStack.push(newState);
		chars = "";
	    }
	    virtual void endElement (std::string,
				     std::string,
				     std::string, 
				     NSmap& /* nsz */) {
		switch (stateStack.top()) {
		case BOOLEAN:
		    /* http://www.w3.org/TR/rdf-sparql-XMLres/#boolean-results */
		    if (chars == "true")
			rs->insert(rs->end(), new Result(rs));
		    rs->makeBoolean();
		    chars = "";
		    break;
		case BINDING: //@@
		    break;
		case _URI:
		    result->set(variable, posFactory->getURI(chars), false);
		    chars = "";
		    break;
		case BNODE:
		    result->set(variable, posFactory->getBNode(chars), false);
		    chars = "";
		    break;
		case LITERAL:
		    {
			LANGTAG* l = NULL;
			if (lang.size() > 0)
			    l = new LANGTAG(lang); /* del'd by RDFLiteral. */
			result->set(variable, posFactory->getRDFLiteral(chars, datatype, l), false);
			datatype = NULL;
		    }
		    chars = "";
		    break;
		default: /* avoid enum not handled in switch warnings */
		    break;
		}
		if (chars.size() > 0 && chars.find_first_not_of(" \t\n") != std::string::npos)
		    varError("unexpected characters %s within %s", chars.c_str(), stateStr());
		stateStack.pop();
	    }
	    virtual void characters (const char ch[],
				     int start,
				     int length, 
				     NSmap& /* nsz */) {
		chars += std::string(ch + start, length);
	    }
	};

	ResultSet (POSFactory* posFactory, BasicGraphPattern* bgp) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), isBool(false), 
	    bgp(bgp), db(NULL), selectOrder(), orderedSelect(false) {  }

	ResultSet (POSFactory* posFactory, RdfDB* db) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), isBool(false), 
	    bgp(NULL), db(db), selectOrder(), orderedSelect(false) {  }

	ResultSet (POSFactory* posFactory, RdfDB* db, const char* baseURI) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), isBool(false), 
	    bgp(NULL), db(NULL), selectOrder(), orderedSelect(false) {
	    SPARQLfedDriver sparqlParser(baseURI, posFactory);
	    std::stringstream boolq("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
				    "SELECT ?bool { ?t rs:boolean ?bool . }\n");
	    if (sparqlParser.parse_stream(boolq))
		throw std::string("failed to parse boolean ResultSet constructor query.");
	    ResultSet booleanResult(posFactory);
	    sparqlParser.root->execute(db, &booleanResult);
	    delete sparqlParser.root;
	    sparqlParser.clear(""); // clear out namespaces and base URI.
	    if (booleanResult.size() > 0) {
		ResultSetIterator booleanRecord = booleanResult.begin();
		const POS* bpos = (*booleanRecord)->get(posFactory->getVariable("bool"));
		const BooleanRDFLiteral* blit = dynamic_cast<const BooleanRDFLiteral*>(bpos);
		if (blit == NULL /* !!! || ++booleanRecord != end() */)
		    throw std::string("database:\n") + 
			db->toString() + 
			"\nis not a validate initializer for a boolen ResultSet.";
		isBool = true;
		/* So far, size() > 0 is how we test a boolean ResultSet. */
		if (blit->getValue())
		    results.insert(results.begin(), new Result(this));
	    } else {
		/* Get list of known variables. */
		std::stringstream variablesQ("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
					     "SELECT ?var {?set rs:resultVariable ?var }\n");
		if (sparqlParser.parse_stream(variablesQ))
		    throw std::string("failed to parse boolean ResultSet variables query.");
		ResultSet listOfVariables(posFactory);
		sparqlParser.root->execute(db, &listOfVariables);
		delete sparqlParser.root;
		sparqlParser.clear(""); // not necessary unless we re-use parser.
		for (ResultSetIterator resultRecord = listOfVariables.begin(); 
		     resultRecord != listOfVariables.end(); ++resultRecord) {
		    const POS* varStr = (*resultRecord)->get(posFactory->getVariable("var" ));
		    const POS* var  = posFactory->getVariable(varStr->getLexicalValue());
		    knownVars.insert(var);
		}

		/* Get list of bindings. */
		std::stringstream bindingsQ("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
					    "SELECT * {?soln rs:binding [\n"
					    "		 rs:variable ?var ;\n"
					    "		 rs:value ?val\n"
					    " ]} ORDER BY ?soln\n");
		if (sparqlParser.parse_stream(bindingsQ))
		    throw std::string("failed to parse boolean ResultSet bindings query.");
		ResultSet listOfResults(posFactory);
		sparqlParser.root->execute(db, &listOfResults);
		delete sparqlParser.root;
		sparqlParser.clear(""); // not necessary unless we re-use parser.
		const POS* lastSoln = NULL;
		Result* r = NULL;
		for (ResultSetIterator resultRecord = listOfResults.begin(); 
		     resultRecord != listOfResults.end(); ++resultRecord) {
		    const POS* soln = (*resultRecord)->get(posFactory->getVariable("soln"));
		    const POS* varStr = (*resultRecord)->get(posFactory->getVariable("var" ));
		    const POS* var  = posFactory->getVariable(varStr->getLexicalValue());
		    const POS* val  = (*resultRecord)->get(posFactory->getVariable("val" ));
		    if (lastSoln != soln) {
			r = new Result(this);
			insert(end(), r);
			lastSoln = soln;
		    }
		    set(r, var, val, false);
		}
	    }
	}

	ResultSet (POSFactory* posFactory, SWSAXparser* parser, const char* filename) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), isBool(false), 
	    bgp(NULL), db(NULL), selectOrder(), orderedSelect(false) {
	    RSsax handler(this, posFactory);
	    parser->parse(filename, &handler);
	}

	ResultSet (POSFactory* posFactory, SWSAXparser* parser, std::string::iterator start, std::string::iterator finish) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), isBool(false), 
	    bgp(NULL), db(NULL), selectOrder(), orderedSelect(false) {
	    RSsax handler(this, posFactory);
	    parser->parse(start, finish, &handler);
	}

	virtual ~ResultSet();
	bool operator== (const ResultSet & ref) const {
	    if (ref.isOrdered() != isOrdered())
		return false;
	    if (isOrdered()) {
		return compareOrdered(ref);
	    } else if (isBoolean()) {
		return ref.isBool && (ref.size() > 0) == (size() > 0) ;
	    } else if (db != NULL && ref.db != NULL) {
		return (*db == *ref.db) ;
	    } else if (bgp != NULL && ref.bgp != NULL) {
		return (*bgp == *ref.bgp) ;
	    } else {
		std::vector<s_OrderConditionPair> orderConditions;
		for (VariableListConstIterator it = knownVars.begin();
		     it != knownVars.end(); ++it) {
		    const Bindable* v = dynamic_cast<const Bindable*>(*it);
		    VarExpression* ve = new VarExpression(v);
		    s_OrderConditionPair p = {ORDER_Asc, ve}; // @@@ expand for our expanded key types (URI, lit...).
		    orderConditions.push_back(p);
		}
		ResultSet self(*this);
		ResultSet newRef(ref);
		self.order(&orderConditions, -1, -1);
		newRef.order(&orderConditions, -1, -1);
		
		for (std::vector<s_OrderConditionPair>::iterator it = orderConditions.begin();
		     it != orderConditions.end(); ++it) {
 		    delete it->expression;
		}
		return self.compareOrdered(newRef);
	    }
	}
	const VariableList* getKnownVars () { return &knownVars; }
	void joinIn (ResultSet* ref, bool outer = false) { // !!! make const ref
	    for (ResultSetIterator myRow = results.begin();
		 myRow != results.end(); ) {
		bool matchedSomeRow = false;
		for (ResultSetConstIterator yourRow = ref->results.begin();
		     yourRow != ref->results.end(); ++yourRow) {
		    bool matched = true;
		    std::set<const POS*>copy;
		    for (BindingSetConstIterator yourBinding = (*yourRow)->begin();
			 yourBinding != (*yourRow)->end(); ++yourBinding) {
			const POS* var = yourBinding->first;
			const POS* yourVal = yourBinding->second.pos;
			const POS* myVal = (*myRow)->get(var);
			if (myVal == NULL) {
			    knownVars.insert(var); // means we can bypass ResultSet::set(...).
			    if (yourVal != NULL)
				copy.insert(var);
			} else if (myVal != yourVal) {
			    matched = false;
			    break;
			}
		    }
		    if (matched) {
			Result* newRow = (*myRow)->duplicate(this, myRow);
			for (std::set<const POS*>::iterator vars = copy.begin();
			     vars != copy.end(); ++vars)
			    newRow->set(*vars, (*yourRow)->get(*vars), false);
			insert(myRow, newRow);
			matchedSomeRow = true;
		    }
		}
		if (outer && !matchedSomeRow)
		    myRow++;
		else {
		    delete *myRow;
		    erase(myRow++);
		}
	    }
	}
	bool compareOrdered (const ResultSet & ref) const {
	    if (ref.size() != size())
		return false;
	    ResultSetConstIterator myRow = results.begin();
	    ResultSetConstIterator yourRow = ref.results.begin();
	    while (myRow != results.end()) {
		if ((*yourRow)->size() != (*myRow)->size())
		    return false;
		std::set<const POS*> yourVars;
		for (BindingSetConstIterator yourBinding = (*yourRow)->begin();
		     yourBinding != (*yourRow)->end(); ++yourBinding)
		    yourVars.insert(yourBinding->first);
		for (BindingSetConstIterator myBinding = (*myRow)->begin();
		     myBinding != (*myRow)->end(); ++myBinding) {
		    const POS* var = myBinding->first;
		    if (yourVars.erase(var) == 0)
			return false;
		    const POS* yours = (*yourRow)->find(var)->second.pos;
		    if (yours != myBinding->second.pos)
			return false;
		}
		if (yourVars.size() != 0)
		    return false;
		++myRow;
		++yourRow;
	    }
	    return true;
	}

	void project(ProductionVector<const POS*> const * varsV);
	void restrict(const Filter* filter);
	void order(std::vector<s_OrderConditionPair>* orderConditions, int offset, int limit);
	bool isOrdered () const { return ordered; }
	void makeBoolean () { isBool = true; }
	bool isBoolean () const { return isBool; }
	void setGraph (BasicGraphPattern* bgp) { this->bgp = bgp; }
	BasicGraphPattern* getGraph () { return bgp; }
	void setRdfDB (RdfDB* db) { this->db = db; }
	RdfDB* getRdfDB () { return db; }

	POSFactory* getPOSFactory () const {
	    if (posFactory == NULL)
		throw(std::runtime_error("ConstructResultSet has no POSFactory."));
	    return posFactory;
	}
	std::string toString() const;
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	ResultSetIterator begin () { return results.begin(); }
	ResultSetConstIterator begin () const { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	ResultSetConstIterator end () const { return results.end(); }
	size_t size () const { return results.size(); }
	void erase (ResultSetIterator it) { results.erase(it); }
	void set(Result* r, const POS* variable, const POS* value, bool weaklyBound);
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	ResultSet* clone();
	void remove (ResultSetIterator it, const Result* r) { results.erase(it); delete r; }
	void containsAtLeast (ResultSet*) { throw(std::runtime_error(FUNCTION_STRING)); }
	std::string buildFederationString (std::set<const Variable*> vars) {
	    std::stringstream rsStr;
	    bool noRowsYet = true;
	    for (ResultSetConstIterator row = results.begin();
		 row != results.end(); row++) {
		std::stringstream rowStr;
		bool noValuesYet = true;
		for (std::set<const Variable*>::const_iterator var = vars.begin();
		     var != vars.end(); ++var) {
		    const POS* value = (*row)->get(*var);
		    if (value != NULL) {
			if (noValuesYet)
			    noValuesYet = false;
			else
			    rowStr << " && ";
			rowStr << (*var)->toString() << "=" << value->toString();
		    }
		    
		}
		if (!noValuesYet) {
		    if (noRowsYet)
			noRowsYet = false;
		    else
			rsStr << " ||\n";
		    rsStr << '(' << rowStr.str() << ')';
		}
	    }
	    if (noRowsYet)
		return "";
	    std::string ret = "FILTER (" + rsStr.str() + ")\n";
	    return ret;
	}
    };

    std::ostream& operator<<(std::ostream& os, ResultSet const& my);

    struct TreatAsVar : public BNodeEvaluator {
	virtual const POS* evaluate (const BNode* node, const Result* r) {
	    return r->get(node);
	}
    };

} // namespace w3c_sw

#endif // !RESULT_SET_H

