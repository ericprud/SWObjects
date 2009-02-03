/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.cpp,v 1.7 2008-12-02 03:36:12 eric Exp $
 */

#include "ResultSet.hpp"
#include "XMLQueryExpressor.hpp"
#include <iostream>

namespace w3c_sw {
    void Result::set (const POS* variable, const POS* value, bool weaklyBound) {
	if (variable->toString() == "?") {
	    std::stringstream s;
	    s << "tried to assign empty variable  to \"" << value->toString() << "\"";
	    throw(std::runtime_error(s.str()));
	}
	BindingSet::const_iterator vi = bindings.find((POS*)variable);
	if (vi == bindings.end()) {
	    BindingInfo b = {weaklyBound, (POS*)value};
	    bindings[(POS*)variable] = b;
	} else {
	    std::stringstream s;
	    s << "variable " << variable->toString() << " reassigned:"
		" old value:" << bindings[(POS*)variable].pos->toString() << 
		" new value:" << value->toString();
	    throw(std::runtime_error(s.str()));
	}
    }

    POS* Result::get (const POS* variable) const {
	BindingSet::const_iterator vi = bindings.find((POS*)variable);
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

    ResultSet::ResultSet (POSFactory* posFactory) : posFactory(posFactory), knownVars(), results() {
	results.insert(results.begin(), new Result(this));
    }

    ResultSet::~ResultSet () {
	for (ResultSetIterator it = results.begin(); it != results.end(); it++)
	    delete *it;
    }

    ResultSet* Result::makeResultSet () {
	ResultSet* ret = new ResultSet();
	ret->erase(ret->begin());
	duplicate(ret, ret->begin());
	return ret;
    }
    void Result::assumeNewBindings (Result* from) {
	for (BindingSetIterator it = from->bindings.begin(); it != from->bindings.end(); it++)
	    bindings[it->first] = it->second;
	//	    set(it->first, it->second);	
    }


    ResultSet* ResultSet::clone () {
	ResultSet* ret = new ResultSet();
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
	ResultComp (std::vector<s_OrderConditionPair>* orderConditions) : 
	    orderConditions(orderConditions) {  }
	bool operator() (const Result* lhs, const Result* rhs) {
	    for (std::vector<s_OrderConditionPair>::iterator it = orderConditions->begin();
		 it != orderConditions->end(); ++it) {
		s_OrderConditionPair pair = *it;
		SPARQLSerializer s;
		pair.expression->express(&s);
		std::cout << "evaluating " << (pair.ascOrDesc == ORDER_Asc ? "Asc" : "Desc") << " expr: " << s.getSPARQLstring();
	    }
	    return lhs < rhs;
	}
    };

    void ResultSet::order (std::vector<s_OrderConditionPair>* orderConditions, int offset, int limit) {
  	ResultComp resultComp(orderConditions);
  	std::sort(results.begin(), results.end(), resultComp);
    }

    std::string ResultSet::toString () const {
	const char* NULL_REP = "--";
#if ASCII_BOX_CHARS
	const char UL = '+'; const char UB = '-'; const char US = '+'; const char UR = '+';
	const char RL = '>'; const char RB = ' '; const char RS = '|'; const char RR = '<';
#if (INTRA_ROW_SEPARATORS)
	const char SL = '>'; const char SB = '-'; const char SS = '+'; const char SR = '<';
#endif
	const char LL = '+'; const char LB = '-'; const char LS = '+'; const char LR = '+';
	const char UNLISTED_VAR = '!';
#define STRING std::string
#else /* !ASCII_BOX_CHARS */
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
#endif /* !ASCII_BOX_CHARS */

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
		    POS* var = b->first;
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
	    s << (i == 0 ? UL : US);
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

