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
#include <vector>
#include "SWObjects.hpp"
#include "RdfDB.hpp"
#include "XMLSerializer.hpp"
#include "../interface/SAXparser.hpp"
#include "SPARQLSerializer.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"

namespace w3c_sw {

    typedef struct { bool weaklyBound; const TTerm* tterm; } BindingInfo;
    typedef std::map<const TTerm*, BindingInfo> BindingSet;
    typedef std::map<const TTerm*, BindingInfo>::iterator BindingSetIterator;
    typedef std::map<const TTerm*, BindingInfo>::const_iterator BindingSetConstIterator;
    //typedef std::pair<std::map<TTerm*,TTerm*>::iterator, bool> InsertRet;
    typedef std::set<const TTerm*> VariableList;
    typedef std::set<const TTerm*>::iterator VariableListIterator;
    typedef std::set<const TTerm*>::const_iterator VariableListConstIterator;
    typedef std::vector<const TTerm*> VariableVector;
    typedef std::vector<const TTerm*>::iterator VariableVectorIterator;
    typedef std::vector<const TTerm*>::const_iterator VariableVectorConstIterator;

    typedef std::list<Result*> ResultList;
    typedef std::list<Result*>::iterator ResultSetIterator;
    typedef std::list<Result*>::const_iterator ResultSetConstIterator;

    inline bool operator== (const BindingInfo& l, const BindingInfo& r) {
	return l.tterm == r.tterm;
    }

    class Result {
    protected:
	BindingSet bindings;
    public:
	Result (ResultSet*) : bindings() {  }
	Result (const Result& ref) : bindings() {
	    for (BindingSetConstIterator it = ref.begin(); it != ref.end(); ++it) {
		const TTerm* var = it->first;
		BindingInfo bi(it->second);
		bindings[var] = bi;
	    }
	}
	~Result () {  }
	/** operator== -- test that Results are identical.  */
	bool operator== (const Result& ref) const {
	    std::set<const TTerm*> boundInFirst;
	    for (BindingSetConstIterator it = begin(); it != end(); ++it)
		boundInFirst.insert(it->first);

	    for (BindingSetConstIterator it = ref.begin(); it != ref.end(); ++it)
		if (boundInFirst.find(it->first) == boundInFirst.end())
		    return false;
	    // done with boundInFirst

	    for (BindingSetConstIterator l = begin(); l != end(); ++l) {
		BindingSetConstIterator r = ref.find(l->first);
		if (r == ref.end())
		    return false;
		if (! (l->second == r->second) )
		    return false;
	    }

	    return true;	    
	}
	/** mappedBNodesEquals -- test that Results are identical after a BNode mapping */
	bool mappedBNodesEquals (const Result& ref, BiDiBNodeMap& refBNodes2myBNodes, std::ostream** debugStream) const {
	    if (size() != ref.size()) {
		if (debugStream != NULL && *debugStream != NULL)
		    **debugStream << "l->size: " << ref.size() << " != r->size: " << size() << std::endl;
		return false;
	    }
	    std::set<const TTerm*> yourVars;
	    for (BindingSetConstIterator yourBinding = begin();
		 yourBinding != end(); ++yourBinding)
		yourVars.insert(yourBinding->first);
	    for (BindingSetConstIterator myBinding = ref.begin();
		 myBinding != ref.end(); ++myBinding) {
		const TTerm* var = myBinding->first;
		if (yourVars.erase(var) == 0) {
		    if (debugStream != NULL && *debugStream != NULL)
			**debugStream << "r missing: " << var->toString() << std::endl;
		    return false;
		}
		const TTerm* yours = find(var)->second.tterm;
		const TTerm* mine = myBinding->second.tterm;
		if (dynamic_cast<const Bindable*>(yours) && 
		    dynamic_cast<const Bindable*>(mine)) {
		    if (!refBNodes2myBNodes.mappable(yours, mine))
			return false;
		    yours = mine;
		}
		if (yours != mine) {
		    if (debugStream != NULL && *debugStream != NULL)
			**debugStream << var->toString() << ": l:" << yours->toString() << " != r:" << myBinding->second.tterm->toString() << std::endl;
		    return false;
		}
	    }
	    if (yourVars.size() != 0) {
		if (debugStream != NULL && *debugStream != NULL)
		    **debugStream << "l missing: " << (*yourVars.begin())->toString() << std::endl;
		return false;
	    }
	    return true;
	}

	std::string toString () const {
	    std::stringstream s;
	    s << "{";
	    for (BindingSetConstIterator it = bindings.begin(); it != bindings.end(); ++it)
		s << (it == bindings.begin() ? "" : ", ")
		  << it->first->toString() << "="
		  << it->second.tterm->toString();
	    s << "}";
	    return s.str();
	}

	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	BindingSetIterator begin () { return bindings.begin(); }
	BindingSetConstIterator begin () const { return bindings.begin(); }
	BindingSetIterator end () { return bindings.end(); }
	BindingSetConstIterator end () const { return bindings.end(); }
	size_t size () const { return bindings.size(); }
	BindingSetIterator find (const TTerm* tterm) { return bindings.find(tterm); }
	BindingSetConstIterator find (const TTerm* tterm) const { return bindings.find(tterm); }
	void erase (BindingSetIterator it) { bindings.erase(it); }

	const TTerm* get(const TTerm* variable) const;
	/* set should only be used by ResultSet::set if you want to keep the
	   header consistent.
	 */
	void set(const TTerm* variable, const TTerm* value, bool weaklyBound, bool replace = false);
	Result* duplicate(ResultSet* rs, ResultSetConstIterator row) const;

	ResultSet* makeResultSet(AtomFactory* atomFactory);
	bool isCompatibleWith(const Result* from) const;
	void assumeNewBindings(const Result* from);
    };

    std::ostream& operator<<(std::ostream& os, Result const& my);

    class ResultSet {
    protected:
	AtomFactory* atomFactory;
	VariableList knownVars;
	ResultList results;
	bool ordered;
	RdfDB* db;
	ProductionVector<const TTerm*> selectOrder;
	bool orderedSelect;

    public:
#if defined(SWIG)
	%immutable;
#endif /* defined(SWIG) */
	static const char* NS_srx;
	static const char* NS_xml;
#if defined(SWIG)
	%mutable;
#endif /* defined(SWIG) */
	typedef enum {RESULT_Tabular, RESULT_Boolean, RESULT_Graphs} ResultType;
	ResultType resultType;
	std::ostream** debugStream;
	static size_t DebugEnumerateLimit;

	ResultSet(AtomFactory* atomFactory, std::ostream** debugStream = NULL);
	ResultSet (const ResultSet& ref) : 
	    atomFactory(ref.atomFactory), knownVars(ref.knownVars), 
	    results(), ordered(ref.ordered), db(ref.db), selectOrder(ref.selectOrder), 
	    orderedSelect(ref.orderedSelect), resultType(ref.resultType), debugStream(NULL) {
	    for (ResultSetConstIterator row = ref.results.begin() ; row != ref.results.end(); row++)
		insert(this->end(), new Result(**row));
	}
	ResultSet& operator= (const ResultSet& ref) {
	    if (this == &ref)
		return *this;

	    selectOrder.clear();
	    for (ResultSetIterator it = results.begin(); it != results.end(); it++)
		delete *it;
	    results.clear();

	    atomFactory = ref.atomFactory;
	    knownVars = ref.knownVars;
	    ordered = ref.ordered;
	    db = ref.db;
	    selectOrder = ref.selectOrder;
	    orderedSelect = ref.orderedSelect;
	    resultType = ref.resultType;
	    debugStream = ref.debugStream;
	    for (ResultSetConstIterator row = ref.results.begin() ; row != ref.results.end(); row++)
		insert(this->end(), new Result(**row));

	    return *this;
	}
	/* Parsed constructor, a la
		ResultSet(&f, 
			  "?n1  _:n2\n"
			  "<n1> <n2>\n"
			  "<n4> \"l1\"" )
	 * A \n on the last line creates a row with no bindings.
	 */
#if REGEX_LIB != SWOb_DISABLED
	ResultSet (AtomFactory* atomFactory, std::string str, bool ordered, TTerm::String2BNode& nodeMap) : 
	    atomFactory(atomFactory), knownVars(), 
	    results(), ordered(ordered), db(NULL), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Tabular), debugStream(NULL) {

	    /* Iterate through the input string. */
	    std::string::const_iterator start, end; 
	    start = str.begin(); 
	    end = str.end(); 

	    /* Ignore leading whitespace and comments. */
	    boost::match_results<std::string::const_iterator> what;
	    boost::match_flag_type flags = boost::match_default;
	    while (regex_search(start, end, what, boost::regex("^[ \\t]*(#[^\\n]*)?\\n"), flags)) {
		start = what[0].second; 
		flags |= boost::match_prev_avail; 
		flags |= boost::match_not_bob; 
	    }

	    /* Populate <headers> from the first row ... */
	    bool firstRow = true;
	    std::vector<const TTerm*> headers;
	    /* ... and generate Results for each remaining row. */
	    int col = 0;
	    Result* curRow = NULL;
	    const boost::regex expression("[ \\t]*"			// ignore leading whitespace
					  "((?:<[^>]*>)"		// IRI
					   "|(?:_:[^[:space:]]+)"	// bnode
					   "|(?:[?$][^[:space:]]+)"	// variable
					   "|(?:\\\"[^\\\"]+\\\")"	// literal
					   "|(?:'[^']+')"		// literal
					   "|(?:-?[0-9\\.]+)"		// integer
					   "|\\+|┌|├|└|┏|┠|┗|\\n"	// box chars
					  ")");
	    while (regex_search(start, end, what, expression, flags)) {
		std::string matched(what[1].first, what[1].second);
		if (matched == "\n") {
		    firstRow = false;
		    col = 0;
		    curRow = NULL;
		} else if (matched == "+" || matched == "┌" || matched == "├" || matched == "└") {
		    const boost::regex nl("[^\\n]*\\n");
		    regex_search(start, end, what, nl, flags); // skip rest of line
		} else {
		    const TTerm* tterm = atomFactory->getTTerm(matched, nodeMap);
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
		start = what[0].second; 
		/* Re-assert the flags. */
		flags |= boost::match_prev_avail; 
		flags |= boost::match_not_bob; 
	    }
	}
#endif /* REGEX_LIB != SWOb_DISABLED */

#if !defined(SWIG)
	class RSsax : public SWSAXhandler {
	protected:
	    ResultSet* rs;
	    AtomFactory* atomFactory;
	    TTerm::String2BNode	nodeMap;

	    enum STATES {DOCUMENT, SPARQL, HEAD, LINK, VARIABLE, BOOLEAN,
			 RESULTS, RESULT, BINDING, _URI, BNODE, LITERAL, 
			 s_ERROR};
	    std::stack<enum STATES> stateStack;
	    Result* result;
	    const TTerm* variable;
	    const URI* datatype;
	    std::string lang;
	    std::string chars;

	    const char* stateStr () {
		static const char* stateStrs[] =
		    {"document", "sparql", "head", "link", "variable", "boolean",
		     "results", "result", "binding", "uri", "bnode", "literal", "huh?"};
		return stateStrs[stateStack.top()];
	    }

	public:
	    RSsax (ResultSet* rs, AtomFactory* atomFactory) : 
		rs(rs), atomFactory(atomFactory), result(NULL), variable(NULL), datatype(NULL), chars("") {
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
			rs->addKnownVar(atomFactory->getVariable(attrs->getValue("", "name")));
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
			variable = atomFactory->getVariable(attrs->getValue("", "name"));
		    } break;
		case BINDING:
		    if (localName == "uri")
			newState = _URI;
		    else if (localName == "bnode")
			newState = BNODE;
		    else if (localName == "literal") {
			newState = LITERAL;
			std::string s = attrs->getValue("", "datatype");
			datatype = s.size() == 0 ? NULL : atomFactory->getURI(s.c_str());
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
		    rs->resultType = RESULT_Boolean;
		    chars = "";
		    break;
		case BINDING: //@@
		    break;
		case _URI:
		    result->set(variable, atomFactory->getURI(chars), false);
		    chars = "";
		    break;
		case BNODE:
		    result->set(variable, atomFactory->getBNode(chars, nodeMap), false);
		    chars = "";
		    break;
		case LITERAL:
		    {
			LANGTAG* l = NULL;
			if (lang.size() > 0)
			    l = new LANGTAG(lang); /* del'd by RDFLiteral. */
			result->set(variable, atomFactory->getRDFLiteral(chars, datatype, l), false);
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
#endif /* !defined(SWIG) */

	ResultSet (AtomFactory* atomFactory, RdfDB* db) : 
	    atomFactory(atomFactory), knownVars(), 
	    results(), ordered(false), db(db), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Graphs), debugStream(NULL) {  }

	ResultSet (AtomFactory* atomFactory, RdfDB* db, const char* baseURI) : 
	    atomFactory(atomFactory), knownVars(), 
	    results(), ordered(false), db(NULL), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Tabular), debugStream(NULL) {
	    SPARQLfedDriver sparqlParser(baseURI, atomFactory);
	    IStreamContext boolq("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
				 "SELECT ?bool { ?t rs:boolean ?bool . }\n", IStreamContext::STRING);
	    if (sparqlParser.parse(boolq))
		throw std::string("failed to parse boolean ResultSet constructor query.");
	    ResultSet booleanResult(atomFactory);
	    sparqlParser.root->execute(db, &booleanResult);
	    delete sparqlParser.root;
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
		if (sparqlParser.parse(variablesQ))
		    throw std::string("failed to parse boolean ResultSet variables query.");
		ResultSet listOfVariables(atomFactory);
		sparqlParser.root->execute(db, &listOfVariables);
		delete sparqlParser.root;
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
		if (sparqlParser.parse(bindingsQ))
		    throw std::string("failed to parse boolean ResultSet bindings query.");
		ResultSet listOfResults(atomFactory);
		sparqlParser.root->execute(db, &listOfResults);
		delete sparqlParser.root;
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

	ResultSet (AtomFactory* atomFactory, SWSAXparser* parser, IStreamContext& sptr) : 
	    atomFactory(atomFactory), knownVars(), 
	    results(), ordered(false), db(NULL), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Tabular), debugStream(NULL) {
	    RSsax handler(this, atomFactory);
	    parser->parse(sptr, &handler);
	}

	virtual ~ResultSet();

	struct AscendingOrder {
	    const VariableVector vars;
	    std::set<const Result*>* incomparables;
	    AscendingOrder (const VariableVector vars,
			    std::set<const Result*>* incomparables) : 
		vars(vars), incomparables(incomparables)
	    {  }
	    bool operator() (const Result* lhs, const Result* rhs) {
		bool incomparable = true;
		for (VariableVectorConstIterator it = vars.begin();
		     it != vars.end(); ++it) {
		    // 			SPARQLSerializer s;
		    // 			pair.expression->express(&s);
		    const TTerm* l = lhs->get(*it);
		    const TTerm* r = rhs->get(*it);
		    if (r == NULL) {
			if (l == NULL)
			    continue;
			else
			    return false;
		    }
		    if (l == NULL)
			return true;
		    if (dynamic_cast<const Bindable*>(l) && 
			dynamic_cast<const Bindable*>(r))
			continue;
		    if (l != r)
			return AtomFactory::safeCmp(l, r) == SORT_lt;
		    else
			incomparable = false;
		}
		if (incomparable && incomparables != NULL) {
		    incomparables->insert(lhs);
		    incomparables->insert(rhs);
		}
		return false;
	    }
	};

	bool operator== (const ResultSet & ref) const {
	    if (ref.isOrdered() != isOrdered() || 
		ref.resultType != resultType)
		return false;

	    if (isOrdered())
		return compareOrdered(ref);

	    else if (resultType == RESULT_Boolean)
		return (ref.size() > 0) == (size() > 0) ;

	    else if (resultType == RESULT_Graphs)
		return (*db == *ref.db) ;

	    else {
		/* Copy ResultSets */
		ResultSet self(*this);
		ResultSet newRef(ref);
		if (debugStream != NULL && *debugStream != NULL)
		    **debugStream << self.toString() << newRef.toString();

		/* Sort according to variables in this ResultSet. Record the
		   rows we couldn't sort so compareOrdered can handle them
		   exhaustively. */

		std::set<const Result*> lUnordered;
		AscendingOrder lComp(getOrderedVars(), &lUnordered);
		self.results.sort(lComp);

		newRef.leadWithColumns(self.getOrderedVars());

		std::set<const Result*> rUnordered;
		AscendingOrder rComp(newRef.getOrderedVars(), &rUnordered);
		newRef.results.sort(rComp);

		if (debugStream != NULL && *debugStream != NULL)
		    **debugStream << self.toString() << newRef.toString();
		return self.compareOrdered(newRef, lUnordered, rUnordered);
	    }
	}
	const VariableList* getKnownVars () const { return &knownVars; }
	void addKnownVar (const TTerm* var) { knownVars.insert(var); }
	VariableVector getOrderedVars () const {
	    VariableVector ret;
	    if (orderedSelect)
		for (std::vector<const TTerm*>::const_iterator it = selectOrder.begin() ; it != selectOrder.end(); ++it)
		    ret.push_back(*it);
	    else {
		for (VariableListConstIterator it = knownVars.begin() ; it != knownVars.end(); ++it)
		    ret.push_back(*it);
		std::sort(ret.begin(), ret.end(), TTermSorter());
	    }
	    return ret;
	}
	int leadWithColumns (VariableVector copyMe) {
	    int mismatches = 0;
	    VariableVector target;
	    VariableVector curOrder = getOrderedVars();
	    selectOrder.clear();
	    std::set<const TTerm*> curVars(curOrder.begin(), curOrder.end());
	    std::set<const TTerm*> newVars;

	    for (VariableVectorConstIterator it = copyMe.begin(); it != copyMe.end(); ++it)
		if (curVars.find(*it) == curVars.end())
		    ++mismatches;
		else {
		    selectOrder.push_back(*it);
		    newVars.insert(*it);
		}

	    for (VariableVectorConstIterator it = curOrder.begin(); it != curOrder.end(); ++it)
		if (newVars.find(*it) == newVars.end()) {
		    ++mismatches;
		    selectOrder.push_back(*it);
		}

	    orderedSelect = true;
	    return mismatches;
	}
	typedef enum {OP_join, OP_outer, OP_minus} e_OP;
	void joinIn (ResultSet* ref, const ProductionVector<const Expression*>* expressions = NULL, e_OP operation = OP_join) { // !!! make const ref
	    for (ResultSetIterator myRow = results.begin();
		 myRow != results.end(); ) {
		bool matchedSomeRow = false;
		for (ResultSetConstIterator yourRow = ref->results.begin();
		     yourRow != ref->results.end(); ++yourRow) {
		    bool matched = true;
		    std::set<const TTerm*>copy;
		    for (BindingSetConstIterator yourBinding = (*yourRow)->begin();
			 yourBinding != (*yourRow)->end(); ++yourBinding) {
			const TTerm* var = yourBinding->first;
			const TTerm* yourVal = yourBinding->second.tterm;
			const TTerm* myVal = (*myRow)->get(var);
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
			for (std::set<const TTerm*>::iterator vars = copy.begin();
			     vars != copy.end(); ++vars)
			    newRow->set(*vars, (*yourRow)->get(*vars), false);
			if (expressions != NULL)
			    for (std::vector<const Expression*>::const_iterator expression = expressions->begin();
				 matched && expression != expressions->end(); expression++)
				matched &= atomFactory->eval(*expression, newRow);
			if (matched) {
			    if (operation == OP_minus)
				delete newRow;
			    else
				insert(myRow, newRow);
			    matchedSomeRow = true;
			} else {
			    delete newRow;
			}
		    }
		}
		if ((operation == OP_outer || operation == OP_minus) && !matchedSomeRow)
		    myRow++;
		else {
		    delete *myRow;
		    myRow = erase(myRow);
		}
	    }
	}

	/** Test an unorderable vector of Results against another vector. */
	static bool _mapsTo (std::vector<const Result*> lv, std::vector<const Result*> rv,
		      BiDiBNodeMap& refBNodes2myBNodes,
		      std::ostream** debugStream) {
	    for (std::vector<const Result*>::iterator lit = lv.begin(); lit != lv.end(); ++lit) {
		const Result* l = *lit;
		lit = lv.erase(lit);
		for (std::vector<const Result*>::iterator rit = rv.begin(); rit != rv.end(); ++rit) {
		    const Result* r = *rit;
		    rit = rv.erase(rit);
		    BiDiBNodeMap provisional(refBNodes2myBNodes);
		    if (l->mappedBNodesEquals(*r, provisional, debugStream) &&
			(lv.size() == 0 ||
			 _mapsTo(std::vector<const Result*>(lv),
				 std::vector<const Result*>(rv), provisional, debugStream))) {
			refBNodes2myBNodes = provisional;
			return true;
		    }
		    rit = rv.insert(rit, r);
		}
		lit = lv.insert(lit, l);
	    }
	    return false;
	}

	bool compareOrdered (const ResultSet & ref,
			     std::set<const Result*> lUnordered = std::set<const Result*>(),
			     std::set<const Result*> rUnordered = std::set<const Result*>()) const {
	    if (ref.size() != size() || lUnordered.size() != rUnordered.size())
		return false;
	    ResultSetConstIterator myRow = results.begin();
	    ResultSetConstIterator yourRow = ref.results.begin();
	    BiDiBNodeMap refBNodes2myBNodes;

	    while (myRow != results.end() && yourRow != ref.results.end()) {
		// skip any results that were unordered.
		while (lUnordered.find(*myRow) != lUnordered.end() &&
		       ++myRow != results.end());
		while (rUnordered.find(*yourRow) != rUnordered.end() &&
		       ++yourRow != ref.results.end());
		if (myRow == results.end() || yourRow == ref.results.end()) {
		    // reached the end of at least one ResultSet.
		    if (myRow == results.end() && yourRow == ref.results.end())
			// fall through to unordered compare.
			break;
		    if (debugStream != NULL && *debugStream != NULL) {
			while (myRow != results.end())
			    **debugStream << "r missing result: " << **myRow++ << std::endl;
			while (yourRow != ref.results.end())
			    **debugStream << "l missing result: " << **yourRow++ << std::endl;
		    }
		    return false;
		}

		// carry on to compare these (ordered) results.
		if (!(*myRow)->mappedBNodesEquals(**yourRow, refBNodes2myBNodes, debugStream))
		    return false;
		++myRow;
		++yourRow;
	    }
	    assert(lUnordered.size() == rUnordered.size()); // I *think* that's always true...

	    if (lUnordered.size() == 0)
		return true;
	    // explore every combination of bnode mappings.
	    return _mapsTo(std::vector<const Result*>(lUnordered.begin(), lUnordered.end()),
			   std::vector<const Result*>(rUnordered.begin(), rUnordered.end()),
			   refBNodes2myBNodes, debugStream);
	}


	void project(ProductionVector<const ExpressionAlias*> const * exprs, ExpressionAliasList* groupBy, ProductionVector<const w3c_sw::Expression*>* having);
	void restrict(const Expression* expression);
	void order(std::vector<s_OrderConditionPair>* orderConditions);
	void order();
	bool isOrdered () const { return ordered; }
	void trim(e_distinctness distinctness, int offset, int limit);
	void setRdfDB (RdfDB* db) { this->db = db; }
	RdfDB* getRdfDB () { return db; }

	AtomFactory* getAtomFactory () const {
	    if (atomFactory == NULL)
		throw(std::runtime_error("ConstructResultSet has no AtomFactory."));
	    return atomFactory;
	}
	std::string toString(NamespaceMap* namespaces = NULL) const;
	std::string toString (MediaType mediaType, NamespaceMap* namespaces = NULL, bool preferDb = false) {
	    if (preferDb || resultType == RESULT_Graphs) {
		// text/ntriples , text/turtle , text/trig
		return db->toString(mediaType, namespaces);
	    } else if (mediaType.match("text/sparql-results")) {
		return toString(namespaces);
	    } else {
		// application/sparql-results+xml
		XMLSerializer s;
		toXml(&s);
		std::string ret = s.str();
		return ret;
	    }
	}
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	XMLSerializer* toHtmlTable(XMLSerializer* xml, XMLSerializer::Attributes attributes);
	ResultSetIterator begin () { return results.begin(); }
	ResultSetConstIterator begin () const { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	ResultSetConstIterator end () const { return results.end(); }
	size_t size () const { return results.size(); }
	ResultSetIterator erase (ResultSetIterator it) { return results.erase(it); }
	void set(Result* r, const TTerm* variable, const TTerm* value, bool weaklyBound);
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	ResultSet* clone();
	void remove (ResultSetIterator it, const Result* r) { results.erase(it); delete r; }
	void containsAtLeast (ResultSet*) { throw(std::runtime_error(FUNCTION_STRING)); }
	const Expression* getFederationExpression (std::set<const TTerm*> vars, bool lexicalCompare = false) const {
	    ExprSet disj;
	    for (ResultSetConstIterator row = results.begin();
		 row != results.end(); row++) {
		std::stringstream rowStr;
		ExprSet conj;
		for (std::set<const TTerm*>::const_iterator var = vars.begin();
		     var != vars.end(); ++var) {
		    const TTerm* value = (*row)->get(*var);
		    if (value != NULL) {

			/* Hideous dynamic cast to find the appropriate expression for the value. */
			const Expression* posExpression = new TTermExpression(value);

			if (lexicalCompare == true) {
			    conj.push_back
				(new BooleanEQ
				 (new FunctionCallExpression
				  (new FunctionCall
				   (&AtomFactory::FUNC_str,
				    new TTermExpression(*var), NULL, NULL)), 
				  posExpression));
			} else {
			    conj.push_back
				(new BooleanEQ
				 (new TTermExpression(*var), posExpression));
			}
		    }
		    
		}
		if (conj.size() == 0) {
		} else if (conj.size() == 0) {
		    disj.push_back(conj[0]);
		} else 
		    disj.push_back(new BooleanConjunction(&conj));
		conj.clear();

	    }
	    const Expression* ret = NULL;
	    if (disj.size() == 0) {
	    } else if (disj.size() == 0)
		ret = disj[0];
	    else 
		ret = new BooleanDisjunction(&disj);
	    disj.clear();
	    return ret;
	}
	const Operation* getConstrainedOperation(const Operation* op) const;
    };

    std::ostream& operator<<(std::ostream& os, ResultSet const& my);

    struct TreatAsVar : public BNodeEvaluator {
	virtual const TTerm* evaluate (const BNode* node, const Result* r) {
	    return r->get(node);
	}
    };

    struct BoxChars {
	bool intraRowSeparators;
#if defined(SWIG)
    %immutable;
#endif /* defined(SWIG) */
	const char* unbound; const char* ordered; const char* unlistedVar;
	const char* ul; const char* ub; const char* us; const char* ur;
	const char* rl; const char* rb; const char* rs; const char* rr;
	const char* sl; const char* sb; const char* ss; const char* sr;
	const char* ll; const char* lb; const char* ls; const char* lr;
#if defined(SWIG)
    %mutable;
#endif /* defined(SWIG) */
	BoxChars (bool intraRowSeparators, 
		  const char* unbound, const char* ordered, const char* unlistedVar,
		  const char* ul, const char* ub, const char* us, const char* ur, 
		  const char* rl, const char* rb, const char* rs, const char* rr, 
		  const char* sl, const char* sb, const char* ss, const char* sr,
		  const char* ll, const char* lb, const char* ls, const char* lr)
	    : intraRowSeparators(intraRowSeparators), 
	      unbound(unbound), ordered(ordered), unlistedVar(unlistedVar), 
	      ul(ul), ub(ub), us(us), ur(ur), 
	      rl(rl), rb(rb), rs(rs), rr(rr), 
	      sl(sl), sb(sb), ss(ss), sr(sr),
	      ll(ll), lb(lb), ls(ls), lr(lr)
	{  }
	static BoxChars AsciiBoxChars;
	static BoxChars Utf8BoxChars;
	static BoxChars Utf8BldChars;
	static BoxChars* GBoxChars;
    };

} // namespace w3c_sw

#endif // !RESULT_SET_H

