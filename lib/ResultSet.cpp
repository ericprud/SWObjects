/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.cpp,v 1.7 2008-12-02 03:36:12 eric Exp $
 */

#include <set>
#include "SWObjects.hpp"
#include "SPARQLSerializer.hpp"
#include "XMLQueryExpressor.hpp"
#include <iostream>

namespace w3c_sw {
    std::string Result::toString () const {
	std::stringstream s;
	s << "{";
	for (BindingSetConstIterator it = bindings.begin(); it != bindings.end(); ++it)
	    s << (it == bindings.begin() ? "" : ", ")
	      << it->first->toString() << "="
	      << it->second.pos->toString();
	s << "}";
	return s.str();
    }
    void Result::set (const POS* variable, const POS* value, bool weaklyBound, bool replace) {
	if (variable->toString() == "?") {
	    std::stringstream s;
	    s << "tried to assign empty variable  to \"" << value->toString() << "\"";
	    throw(std::runtime_error(s.str()));
	}
	BindingSet::const_iterator vi = bindings.find(variable);
	if (replace || vi == bindings.end()) {
	    BindingInfo b = {weaklyBound, value};
	    bindings[variable] = b;
	} else {
	    std::stringstream s;
	    s << "variable " << variable->toString() << " reassigned:"
		" old value:" << bindings[variable].pos->toString() << 
		" new value:" << value->toString();
	    throw(std::runtime_error(s.str()));
	}
    }

    const POS* Result::get (const POS* variable) const {
	BindingSet::const_iterator vi = bindings.find(variable);
	if (vi == bindings.end())
	    return NULL;
	else
	    return (*vi).second.pos;
    }

    XMLSerializer* Result::toXml (XMLSerializer* xml) {
	XMLQueryExpressor xmlizer(xml);
	xml->open("result");
	xml->attribute("addr", this);
	for (BindingSetIterator it = bindings.begin(); it != bindings.end(); it++) {
	    xml->open("binding");
	    xml->attribute(it->first->getBindingAttributeName(), it->first->getTerminal());
	    if (it->second.weaklyBound) xml->attribute("binding", "weak" );
	    it->second.pos->express(&xmlizer);
	    xml->close();
	}
	xml->close();
	return xml;
    }

    Result* Result::duplicate (ResultSet* rs, ResultSetIterator /* row */) {
	Result* ret = new Result(rs);
	for (BindingSetIterator it = bindings.begin(); it != bindings.end(); it++)
	    ret->set(it->first, it->second.pos, it->second.weaklyBound);
	return ret;
    }

    ResultSet::ResultSet (POSFactory* posFactory) : posFactory(posFactory), knownVars(), results(), ordered(false) {
	results.insert(results.begin(), new Result(this));
    }

#if REGEX_LIB == SWOb_BOOST
    ResultSet::ResultSet (POSFactory* posFactory, std::string str, bool ordered) : posFactory(posFactory), knownVars(), results(), ordered(ordered) {
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
#endif /* !REGEX_LIB == SWOb_BOOST */

    ResultSet::~ResultSet () {
	for (ResultSetIterator it = results.begin(); it != results.end(); it++)
	    delete *it;
    }

    ResultSet* Result::makeResultSet (POSFactory* posFactory) {
	ResultSet* ret = new ResultSet(posFactory);
	ret->erase(ret->begin());
	duplicate(ret, ret->begin());
	return ret;
    }
    void Result::assumeNewBindings (Result* from) {
	for (BindingSetIterator it = from->bindings.begin(); it != from->bindings.end(); it++)
	    bindings[it->first] = it->second;
	//	    set(it->first, it->second);	
    }


    class RSsax : public SWSAXhandler {
    protected:
	ResultSet* rs;
	POSFactory* posFactory;

	enum STATES {DOCUMENT, SPARQL, HEAD, LINK, VARIABLE, BOOLEAN,
		     RESULTS, RESULT, BINDING, _URI, BNODE, LITERAL, 
		     s_ERROR};
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
		error("element in unexpected namespace {%s}%s within %s", qName.c_str(), uri.c_str(), stateStr());
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
	    if (newState == s_ERROR)
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
    ResultSet::ResultSet (POSFactory* posFactory, SWSAXparser* parser, const char* filename) : posFactory(posFactory), knownVars(), results(), ordered(false) {
	RSsax handler(this, posFactory);
	parser->parse(filename, &handler);
    }
    ResultSet::ResultSet (POSFactory* posFactory, SWSAXparser* parser, std::string::iterator start, std::string::iterator finish) : posFactory(posFactory), knownVars(), results(), ordered(false) {
	RSsax handler(this, posFactory);
	parser->parse(start, finish, &handler);
    }
    bool ResultSet::operator== (const ResultSet & ref) const {
	if (ref.isOrdered() != isOrdered())
	    return false;
	if (isOrdered()) {
	    return compareOrdered(ref);
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
    ResultSet* ResultSet::clone () {
	ResultSet* ret = new ResultSet(posFactory);
	delete *ret->begin();
	ret->erase(ret->begin());
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    (*it)->duplicate(ret, ret->end());
	return ret;
    }

    void ResultSet::set (Result* r, const POS* variable, const POS* value, bool weaklyBound) {
	VariableList::const_iterator vi = knownVars.find(variable);
	if (vi == knownVars.end())
	    knownVars.insert(variable);
	r->set(variable, value, weaklyBound);
    }

    struct ResultComp {
	std::vector<s_OrderConditionPair>* orderConditions;
	POSFactory* posFactory;
	ResultComp (std::vector<s_OrderConditionPair>* orderConditions, POSFactory* posFactory) : 
	    orderConditions(orderConditions), posFactory(posFactory) {  }
	bool operator() (const Result* lhs, const Result* rhs) {
	    for (std::vector<s_OrderConditionPair>::iterator it = orderConditions->begin();
		 it != orderConditions->end(); ++it) {
		s_OrderConditionPair pair = *it;
		SPARQLSerializer s;
		pair.expression->express(&s);
		const POS* l = pair.expression->eval(lhs, posFactory, false);
		const POS* r = pair.expression->eval(rhs, posFactory, false);
		if (l != r)
		    return pair.ascOrDesc == ORDER_Desc ? posFactory->lessThan(r, l) : posFactory->lessThan(l, r);
	    }
	    return false;
	}
    };

    void ResultSet::project (ProductionVector<const POS*> const * varsV) {
	std::set<const POS*> vars(varsV->begin(), varsV->end());

	/* List of vars to delete.
	 * This is cheaper than walking all the bindings in a row, but assumes
	 * that the row has no bindings which fail to appear in knownVars.
	 */
	std::set<const POS*> toDel;
	for (std::set<const POS*>::const_iterator knownVar = knownVars.begin();
	     knownVar != knownVars.end(); ++knownVar)
	    if (vars.find(*knownVar) == vars.end())
		toDel.insert(*knownVar);

	/* Delete those vars from each row, and from knowVars. */
	for (ResultSetIterator row = results.begin();
	     row != results.end(); ++row)
	    for (std::set<const POS*>::const_iterator var = toDel.begin();
		 var != toDel.end(); ++var)
		(*row)->erase((*row)->find(*var));

	/* Delete those vars from knowVars. */
	for (std::set<const POS*>::const_iterator var = toDel.begin();
	     var != toDel.end(); ++var)
	    knownVars.erase(*var);
    }

    void ResultSet::order (std::vector<s_OrderConditionPair>* orderConditions, int offset, int limit) {
	if (orderConditions != NULL) {
	    ResultComp resultComp(orderConditions, posFactory);
	    results.sort(resultComp);
	}

	if (offset > 0) {
	    int at = 0;
	    for (ResultSetIterator it = begin() ; it != end() && at < offset; ++at) {
		delete *it;
		erase(it++);
	    }
	}

	if (limit > 0) {
	    int at = 0;
	    ResultSetIterator it = begin();
	    for ( ; it != end() && at < limit; ++at)
		++it;
	    for ( ; it != end(); ++at) {
		delete *it;
		erase(it++);
	    }
	}
    }

    std::string ResultSet::buildFederationString (std::set<const Variable*> vars) {
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

    void ResultSet::matchConstraint (const TriplePattern* constraint, 
				     const ProductionVector<const TriplePattern*>* data, 
				     bool allOpts, const POS* graphVar, const POS* graphName) {
	/* For each row, insert all the bindings which are consistent with that
	   row, then delete that row. */
	for (ResultSetIterator row = begin() ; row != end(); ) {
	    bool matched = false;
	    for (std::vector<const TriplePattern*>::const_iterator datum = data->begin();
		 datum != data->end(); datum++) {
		/* Because generators can produce more than one binding per
		   (TriplePattern:Datum) pair, create a span object which keeps
		   track of any row additions from e.g. { members(?x) <p1> 1 }. */
		ResultSetIterator newRow = insert(row, (*row)->duplicate(this, row));
		ResultSetIterator nextRow = newRow;
		ResultSetIteratorPair span(newRow, ++nextRow);

		/* If the binding matched, fab. Otherwise, remove any rows that
		   were generated either in creating the initial span, or while
		   it was binding generators, e.g. { memers(?x) <notFound> 1 }. */
		if (constraint->bindVariables(*datum, this, graphVar, graphName, &span))
		    matched = true;
		else
		    for (ResultSetIterator it = span.begin; it != span.end; ) {
			delete *it;
			erase(it++);
		    }
	    }
	    if (matched || !allOpts) {
		delete *row;
		erase(row++);
	    } else {
		row++;
	    }
	}
    }

    std::string ResultSet::toString () const {
	const char* NULL_REP = "--";
#if CONSOLE_ENCODING == SWOb_UTF8
	const char* ORDERED = "O";
	const char* UL = "┌"; const char* UB = "─"; const char* US = "┬"; const char* UR = "┐";
	const char* RL = "│"; const char* RB = " "; const char* RS = "│"; const char* RR = "│";
#if (INTRA_ROW_SEPARATORS)
	const char* SL = "├"; const char* SB = "─"; const char* SS = "┼"; const char* SR = "┤";
#endif
	const char* LL = "└"; const char* LB = "─"; const char* LS = "┴"; const char* LR = "┘";
	const char* UNLISTED_VAR = "!";
	class STRING : public std::string {
	public:
	    STRING (size_t repts, const char* str) : std::string() {
		for (size_t i = 0; i < repts; ++i)
		    append(str);
	    }
	};
#else /* !CONSOLE_ENCODING == SWOb_UTF8 */
	const char ORDERED = 'O';
	const char UL = '+'; const char UB = '-'; const char US = '+'; const char UR = '+';
	const char RL = '>'; const char RB = ' '; const char RS = '|'; const char RR = '<';
#if (INTRA_ROW_SEPARATORS)
	const char SL = '>'; const char SB = '-'; const char SS = '+'; const char SR = '<';
#endif
	const char LL = '+'; const char LB = '-'; const char LS = '+'; const char LR = '+';
	const char UNLISTED_VAR = '!';
#define STRING std::string
#endif /* !CONSOLE_ENCODING == SWOb_UTF8 */

	/* Get column widths. */
	std::vector< const POS* > vars;
	std::vector< size_t > widths;
	unsigned count = 0;
	unsigned lastInKnownVars = 0;
	{
	    std::map< const POS*, unsigned > pos2col;
	    for (std::set<const POS*>::const_iterator varIt = knownVars.begin() ; varIt != knownVars.end(); ++varIt) {
		const POS* var = *varIt;
		pos2col[var] = count++;
		widths.push_back(var->toString().size());
		vars.push_back(var);
	    }

	    VariableList intruders;
	    lastInKnownVars = count;
	    for (ResultSetConstIterator row = results.begin() ; row != results.end(); row++)
		for (BindingSetIterator b = (*row)->begin(); b != (*row)->end(); ++b) {
		    const POS* var = b->first;
		    if (pos2col.find(var) == pos2col.end()) {
			/* Error: a variable not listed in knownVars. */
			pos2col[var] = count++;
			widths.push_back(var->toString().size());
			vars.push_back(var);
			intruders.insert(var);
		    }
		    size_t width = b->second.pos->toString().length();
		    if (width > widths[pos2col[var]])
			widths[pos2col[var]] = width;
		}
	}

	/* Generate ResultSet string. */
	std::stringstream s;
	/*   Top Border */
	unsigned i;
	for (i = 0; i < count; i++) {
	    s << (i == 0 ? (ordered == true ? ORDERED : UL) : US);
	    s << STRING(widths[i]+2, UB);
	}
	s << UR << std::endl;

	/*   Column Headings */
	for (i = 0; i < count; i++) {
	    const POS* var = vars[i];
	    s << (i == 0 ? RL : i < lastInKnownVars ? RS : UNLISTED_VAR) << ' ';
	    size_t width = var->toString().length();
	    s << var->toString() << STRING(widths[i] - width, RB) << ' '; // left justified.
	}
	s << RR << std::endl;

	/*  Rows */
	for (ResultSetConstIterator row = results.begin() ; row != results.end(); row++) {
#if (INTRA_ROW_SEPARATORS)
	    /*  Intra-row Border */
	    for (i = 0; i < count; i++) {
		s << (i == 0 ? SL : SS);
		s << std::string(widths[i]+2, SB);
	    }
	    s << SR << std::endl;
#endif
	    /*  Values */
	    for (i = 0; i < count; ++i) {
		const POS* var = vars[i];
		const POS* val = (*row)->get(var);
		const std::string str = val ? val->toString().c_str() : NULL_REP;
		s << (i == 0 ? RL : RS) << ' ';
		size_t width = str.length();
		s << STRING(widths[i] - width, RB) << str << ' '; // right justified.
	    }
	    s << RR << std::endl;
	}

	/*   Bottom Border */
	for (i = 0; i < count; i++) {
	    s << (i == 0 ? LL : LS);
	    s << STRING(widths[i]+2, LB);
	}
	s << LR << std::endl;
	return s.str();
    }
    XMLSerializer* ResultSet::toXml (XMLSerializer* xml) {
	if (xml == NULL) xml = new XMLSerializer("  ");
	xml->open("sparql");
	xml->attribute("xmlns", "http://www.w3.org/2005/sparql-results#");
	xml->open("head");
	for (VariableListIterator it = knownVars.begin() ; it != knownVars.end(); it++) {
	    xml->empty("variable");
	    xml->attribute("name", (*it)->getTerminal());
	}
	xml->close();
	xml->open("results");
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    (*it)->toXml(xml);
	xml->close();
	xml->close();
	return xml;
    }

    std::ostream& operator<< (std::ostream& os, ResultSet const& my) {
	return os << my.toString() ;
    }
}

