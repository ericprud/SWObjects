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
#include "SAXparser.hpp"
#include "SPARQLSerializer.hpp"

namespace w3c_sw {

    typedef struct { bool weaklyBound; POS* pos; } BindingInfo;
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

	POS* get(const POS* variable) const;
	/* set should only be used by ResultSet::set if you want to keep the
	   header consistent.
	 */
	void set(const POS* variable, const POS* value, bool weaklyBound);
	Result* duplicate(ResultSet* rs, ResultSetIterator row);

	ResultSet* makeResultSet();
	void assumeNewBindings(Result* from);
    };

    class ResultSet {
    protected:
	POSFactory* posFactory;
	VariableList knownVars;
	ResultList results;
	bool ordered;

    public:
	ResultSet(POSFactory* posFactory = NULL);
	ResultSet (const ResultSet& ref) : posFactory(ref.posFactory), knownVars(ref.knownVars), results(), ordered(ref.ordered) {
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
	ResultSet (POSFactory* posFactory, std::string str) : posFactory(posFactory), knownVars(), results(), ordered(false) {
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

	class RSsax : public SWSAXhandler {
	protected:
	    ResultSet* rs;
	    POSFactory* posFactory;

	    enum STATES {DOCUMENT, SPARQL, HEAD, LINK, VARIABLE, BOOLEAN,
			 RESULTS, RESULT, BINDING, _URI, BNODE, LITERAL, ERROR};
	    std::vector<std::string> knownVars;
	    std::stack<enum STATES> stateStack;
#define SRX "http://www.w3.org/2005/sparql-results#"
#define XML "http://www.w3.org/XML/1998/namespace"
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
				       Attributes* attrs) {
		if (uri != SRX)
		    error("element in unexpected namespace %s within %s", qName.c_str(), stateStr());
		enum STATES newState = ERROR;
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
			lang = attrs->getValue(XML, "lang");
		    }
		    break;
		case _URI:
		    break;
		case BNODE:
		    break;
		case LITERAL:
		    break;
		default:
		    error("unexpected element %s within %s", qName.c_str(), stateStr());
		}
		if (newState == ERROR)
		    error("unexpected element %s within %s", qName.c_str(), stateStr());
		stateStack.push(newState);
		chars = "";
	    }
	    virtual void endElement (std::string,
				     std::string,
				     std::string) {
		switch (stateStack.top()) {
		case BOOLEAN:
		    error("boolean ResultSets not implemented");
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
		    error("unexpected characters %s within %s", chars.c_str(), stateStr());
		stateStack.pop();
	    }
	    virtual void characters (const char ch[],
				     int start,
				     int length) {
		chars += std::string(ch + start, length);
	    }
	};
	ResultSet (POSFactory* posFactory, SWSAXparser* parser, const char* filename) : posFactory(posFactory), knownVars(), results(), ordered(false) {
	    RSsax handler(this, posFactory);
	    parser->parse(filename, &handler);
	}

	virtual ~ResultSet();
	bool operator== (const ResultSet & ref) const {
	    if (ref.isOrdered() != isOrdered())
		return false;
	    if (isOrdered()) {
		return compareOrdered(ref);
	    } else {
		std::vector<s_OrderConditionPair> orderConditions;
		for (VariableListConstIterator it = knownVars.begin();
		     it != knownVars.end(); ++it) {
		    const Variable* v = dynamic_cast<const Variable*>(*it);
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
		    POS* yours = (*yourRow)->find(var)->second.pos;
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

	void order(std::vector<s_OrderConditionPair>* orderConditions, int offset, int limit);
	bool isOrdered () const { return ordered; }

	POSFactory* getPOSFactory () {
	    if (posFactory == NULL)
		throw(std::runtime_error("ConstructResultSet has no POSFactory."));
	    return posFactory;
	}
	std::string toString() const;
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	ResultSetIterator begin () { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	size_t size () const { return results.size(); }
	void erase (ResultSetIterator it) { results.erase(it); }
	void set(Result* r, const POS* variable, const POS* value, bool weaklyBound);
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	ResultSet* clone();
	void remove (ResultSetIterator it, const Result* r) { results.erase(it); delete r; }
	void containsAtLeast (ResultSet*) { throw(std::runtime_error(FUNCTION_STRING)); }
    };

    class ConstructResultSet : ResultSet {
	ConstructResultSet(POSFactory* posFactory) : ResultSet(posFactory) {  }
    };

    /* TransformerResultSet: extra bits needed for query on query.
     */
    class TransformerResultSet : public ResultSet {
    };

    std::ostream& operator<<(std::ostream& os, ResultSet const& my);

} // namespace w3c_sw

#endif // !RESULT_SET_H

