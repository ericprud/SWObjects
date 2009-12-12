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

    typedef struct { bool weaklyBound; const POS* pos; } BindingInfo;
    typedef std::map<const POS*, BindingInfo> BindingSet;
    typedef std::map<const POS*, BindingInfo>::iterator BindingSetIterator;
    typedef std::map<const POS*, BindingInfo>::const_iterator BindingSetConstIterator;
    //typedef std::pair<std::map<POS*,POS*>::iterator, bool> InsertRet;
    typedef std::set<const POS*> VariableList;
    typedef std::set<const POS*>::iterator VariableListIterator;
    typedef std::set<const POS*>::const_iterator VariableListConstIterator;
    typedef std::vector<const POS*> VariableVector;
    typedef std::vector<const POS*>::iterator VariableVectorIterator;
    typedef std::vector<const POS*>::const_iterator VariableVectorConstIterator;

    typedef std::list<Result*> ResultList;
    typedef std::list<Result*>::iterator ResultSetIterator;
    typedef std::list<Result*>::const_iterator ResultSetConstIterator;

    inline bool operator== (const BindingInfo& l, const BindingInfo& r) {
	return l.pos == r.pos;
    }

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
	bool operator== (const Result& ref) const {
	    std::set<const POS*> boundInFirst;
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
	BindingSetConstIterator find (const POS* pos) const { return bindings.find(pos); }
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
	RdfDB* db;
	ProductionVector<const POS*> selectOrder;
	bool orderedSelect;

    public:
	static const char* NS_srx;
	static const char* NS_xml;
	typedef enum {RESULT_Tabular, RESULT_Boolean, RESULT_Graphs} ResultType;
	ResultType resultType;
	std::ostream** debugStream;

	ResultSet(POSFactory* posFactory, std::ostream** debugStream = NULL);
	ResultSet (const ResultSet& ref) : 
	    posFactory(ref.posFactory), knownVars(ref.knownVars), 
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

	    posFactory = ref.posFactory;
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
	ResultSet (POSFactory* posFactory, std::string str, bool ordered, POS::String2BNode& nodeMap) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(ordered), db(NULL), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Tabular), debugStream(NULL) {
	    const boost::regex expression("[ \\t]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\")|\\+|┌|├|└|┏|┠|┗|\\n)");
	    std::string::const_iterator start, end; 
	    start = str.begin(); 
	    end = str.end(); 
	    boost::match_results<std::string::const_iterator> what;
	    boost::match_flag_type flags = boost::match_default;
	    bool firstRow = true;
	    std::vector<const POS*> headers;
	    int col = 0;
	    Result* curRow = NULL;
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
		    const POS* pos = posFactory->getPOS(matched, nodeMap);
		    if (firstRow)
			headers.push_back(pos);
		    else {
			if (curRow == NULL) {
			    curRow = new Result(this);
			    insert(this->end(), curRow);
			}
			set(curRow, headers[col++], pos, false);
		    }
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
	    POS::String2BNode	nodeMap;

	    enum STATES {DOCUMENT, SPARQL, HEAD, LINK, VARIABLE, BOOLEAN,
			 RESULTS, RESULT, BINDING, _URI, BNODE, LITERAL, 
			 s_ERROR};
	    std::stack<enum STATES> stateStack;
	    Result* result;
	    const POS* variable;
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
			rs->addKnownVar(posFactory->getVariable(attrs->getValue("", "name")));
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
		    rs->resultType = RESULT_Boolean;
		    chars = "";
		    break;
		case BINDING: //@@
		    break;
		case _URI:
		    result->set(variable, posFactory->getURI(chars), false);
		    chars = "";
		    break;
		case BNODE:
		    result->set(variable, posFactory->getBNode(chars, nodeMap), false);
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

	ResultSet (POSFactory* posFactory, RdfDB* db) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), db(db), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Graphs), debugStream(NULL) {  }

	ResultSet (POSFactory* posFactory, RdfDB* db, const char* baseURI) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), db(NULL), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Tabular), debugStream(NULL) {
	    SPARQLfedDriver sparqlParser(baseURI, posFactory);
	    IStreamContext boolq("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
			     "SELECT ?bool { ?t rs:boolean ?bool . }\n", StreamContext::STRING);
	    if (sparqlParser.parse(boolq))
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
		resultType = RESULT_Boolean;
		/* So far, size() > 0 is how we test a boolean ResultSet. */
		if (blit->getValue())
		    results.insert(results.begin(), new Result(this));
	    } else {
		/* Get list of known variables. */
		IStreamContext variablesQ("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
				      "SELECT ?var {?set rs:resultVariable ?var }\n", StreamContext::STRING);
		if (sparqlParser.parse(variablesQ))
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
		IStreamContext bindingsQ("PREFIX rs: <http://www.w3.org/2001/sw/DataAccess/tests/result-set#>\n"
				     "SELECT * {?soln rs:binding [\n"
				     "		 rs:variable ?var ;\n"
				     "		 rs:value ?val\n"
				     " ]} ORDER BY ?soln\n", StreamContext::STRING);
		if (sparqlParser.parse(bindingsQ))
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

	ResultSet (POSFactory* posFactory, SWSAXparser* parser, IStreamContext& sptr) : 
	    posFactory(posFactory), knownVars(), 
	    results(), ordered(false), db(NULL), selectOrder(), 
	    orderedSelect(false), resultType(RESULT_Tabular), debugStream(NULL) {
	    RSsax handler(this, posFactory);
	    parser->parse(sptr, &handler);
	}

	virtual ~ResultSet();
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

		/* Sort according to variables in this ResultSet. */
		self.order();
		newRef.leadWithColumns(self.getOrderedVars());
		newRef.order();

		if (debugStream != NULL && *debugStream != NULL)
		    **debugStream << self.toString() << newRef.toString();
		return self.compareOrdered(newRef);
	    }
	}
	const VariableList* getKnownVars () const { return &knownVars; }
	void addKnownVar (const POS* var) { knownVars.insert(var); }
	VariableVector getOrderedVars () const {
	    VariableVector ret;
	    if (orderedSelect)
		for (std::vector<const POS*>::const_iterator it = selectOrder.begin() ; it != selectOrder.end(); ++it)
		    ret.push_back(*it);
	    else {
		for (VariableListConstIterator it = knownVars.begin() ; it != knownVars.end(); ++it)
		    ret.push_back(*it);
		POSsorter sorter;
		std::sort(ret.begin(), ret.end(), sorter);
	    }
	    return ret;
	}
	int leadWithColumns (VariableVector copyMe) {
	    int mismatches = 0;
	    VariableVector target;
	    VariableVector curOrder = getOrderedVars();
	    selectOrder.clear();
	    std::set<const POS*> curVars(curOrder.begin(), curOrder.end());
	    std::set<const POS*> newVars;

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
			if (expressions != NULL)
			    for (std::vector<const Expression*>::const_iterator expression = expressions->begin();
				 matched && expression != expressions->end(); expression++)
				matched &= posFactory->eval(*expression, newRow);
			if (matched) {
			    insert(myRow, newRow);
			    matchedSomeRow = true;
			} else {
			    delete newRow;
			}
		    }
		}
		if (operation == OP_outer && !matchedSomeRow)
		    myRow++;
		else {
		    delete *myRow;
		    myRow = erase(myRow);
		}
	    }
	}
	bool compareOrdered (const ResultSet & ref) const {
	    if (ref.size() != size())
		return false;
	    ResultSetConstIterator myRow = results.begin();
	    ResultSetConstIterator yourRow = ref.results.begin();
	    std::map<const POS*, const POS*> refBNodes2myBNodes;
	    while (myRow != results.end()) {
		if ((*yourRow)->size() != (*myRow)->size()) {
		    if (debugStream != NULL && *debugStream != NULL)
			**debugStream << "l->size: " << (*myRow)->size() << " != r->size: " << (*yourRow)->size() << std::endl;
		    return false;
		}
		std::set<const POS*> yourVars;
		for (BindingSetConstIterator yourBinding = (*yourRow)->begin();
		     yourBinding != (*yourRow)->end(); ++yourBinding)
		    yourVars.insert(yourBinding->first);
		for (BindingSetConstIterator myBinding = (*myRow)->begin();
		     myBinding != (*myRow)->end(); ++myBinding) {
		    const POS* var = myBinding->first;
		    if (yourVars.erase(var) == 0) {
			if (debugStream != NULL && *debugStream != NULL)
			    **debugStream << "r missing: " << var->toString() << std::endl;
			return false;
		    }
		    const POS* yours = (*yourRow)->find(var)->second.pos;
		    const POS* mine = myBinding->second.pos;
		    if (dynamic_cast<const Bindable*>(yours) && 
			dynamic_cast<const Bindable*>(mine)) {
			if (refBNodes2myBNodes.find(yours) == refBNodes2myBNodes.end())
			    refBNodes2myBNodes[yours] = mine;
			yours = refBNodes2myBNodes[yours];
		    }
		    if (yours != mine) {
			if (debugStream != NULL && *debugStream != NULL)
			    **debugStream << var->toString() << ": l:" << yours->toString() << " != r:" << myBinding->second.pos->toString() << std::endl;
			return false;
		    }
		}
		if (yourVars.size() != 0) {
		    if (debugStream != NULL && *debugStream != NULL)
			**debugStream << "l missing: " << (*yourVars.begin())->toString() << std::endl;
		    return false;
		}
		++myRow;
		++yourRow;
	    }
	    return true;
	}

	void project(ProductionVector<const POS*> const * varsV);
	void restrict(const Expression* expression);
	void order(std::vector<s_OrderConditionPair>* orderConditions);
	void order();
	bool isOrdered () const { return ordered; }
	void trim(e_distinctness distinctness, int offset, int limit);
	void setRdfDB (RdfDB* db) { this->db = db; }
	RdfDB* getRdfDB () { return db; }

	POSFactory* getPOSFactory () const {
	    if (posFactory == NULL)
		throw(std::runtime_error("ConstructResultSet has no POSFactory."));
	    return posFactory;
	}
	std::string toString(NamespaceMap* namespaces = NULL) const;
	std::string toString (std::string mediaType = "", NamespaceMap* namespaces = NULL, bool preferDb = false) {
	    if (mediaType == "application/sparql-results+xml") {
		XMLSerializer s;
		toXml(&s);
		std::string ret = s.str();
		return ret;
	    } else
	    return
		mediaType == "text/turtle" ||
		mediaType == "text/trig" ||
		preferDb ||
		resultType == RESULT_Graphs ? db->toString(mediaType.empty() ? "text/trig" : mediaType, namespaces) :
		toString(namespaces);
	}
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	ResultSetIterator begin () { return results.begin(); }
	ResultSetConstIterator begin () const { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	ResultSetConstIterator end () const { return results.end(); }
	size_t size () const { return results.size(); }
	ResultSetIterator erase (ResultSetIterator it) { return results.erase(it); }
	void set(Result* r, const POS* variable, const POS* value, bool weaklyBound);
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	ResultSet* clone();
	void remove (ResultSetIterator it, const Result* r) { results.erase(it); delete r; }
	void containsAtLeast (ResultSet*) { throw(std::runtime_error(FUNCTION_STRING)); }
	const Expression* getFederationExpression (std::set<const Variable*> vars, bool lexicalCompare = false) {
	    ExprSet disj;
	    for (ResultSetConstIterator row = results.begin();
		 row != results.end(); row++) {
		std::stringstream rowStr;
		ExprSet conj;
		for (std::set<const Variable*>::const_iterator var = vars.begin();
		     var != vars.end(); ++var) {
		    const POS* value = (*row)->get(*var);
		    if (value != NULL) {

			/* Hideous dynamic cast to find the appropriate expression for the value. */
			const Expression* posExpression = new POSExpression(value);

			if (lexicalCompare == true) {
			    conj.push_back
				(new BooleanEQ
				 (new FunctionCallExpression
				  (new FunctionCall
				   (getPOSFactory()->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"),
				    new POSExpression(*var), NULL, NULL)), 
				  posExpression));
			} else {
			    conj.push_back
				(new BooleanEQ
				 (new POSExpression(*var), posExpression));
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
    };

    std::ostream& operator<<(std::ostream& os, ResultSet const& my);

    struct TreatAsVar : public BNodeEvaluator {
	virtual const POS* evaluate (const BNode* node, const Result* r) {
	    return r->get(node);
	}
    };

    struct BoxChars {
	bool intraRowSeparators;
	const char* null; const char* ordered; const char* unlistedVar;
	const char* ul; const char* ub; const char* us; const char* ur;
	const char* rl; const char* rb; const char* rs; const char* rr;
	const char* sl; const char* sb; const char* ss; const char* sr;
	const char* ll; const char* lb; const char* ls; const char* lr;
	BoxChars (bool intraRowSeparators, 
		  const char* null, const char* ordered, const char* unlistedVar,
		  const char* ul, const char* ub, const char* us, const char* ur, 
		  const char* rl, const char* rb, const char* rs, const char* rr, 
		  const char* sl, const char* sb, const char* ss, const char* sr,
		  const char* ll, const char* lb, const char* ls, const char* lr)
	    : intraRowSeparators(intraRowSeparators), 
	      null(null), ordered(ordered), unlistedVar(unlistedVar), 
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

