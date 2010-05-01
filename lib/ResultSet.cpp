/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.cpp,v 1.7 2008-12-02 03:36:12 eric Exp $
 */

#include <set>
#include "ResultSet.hpp"
#include "SWObjectDuplicator.hpp"
#include "XMLQueryExpressor.hpp"
#include <iostream>

namespace w3c_sw {

    const char* ResultSet::NS_srx = "http://www.w3.org/2005/sparql-results#";
    const char* ResultSet::NS_xml = "http://www.w3.org/XML/1998/namespace";

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
	for (BindingSetIterator it = bindings.begin(); it != bindings.end(); it++) {
	    xml->open("binding");
	    xml->attribute(it->first->getBindingAttributeName(), it->first->getLexicalValue());
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

    ResultSet::ResultSet (POSFactory* posFactory, std::ostream** debugStream) : 
	posFactory(posFactory), knownVars(), results(), ordered(false),  db(NULL), 
	selectOrder(), orderedSelect(false), resultType(RESULT_Tabular), debugStream(debugStream) {
	results.insert(results.begin(), new Result(this));
    }

    ResultSet::~ResultSet () {
	selectOrder.clear();
	for (ResultSetIterator it = results.begin(); it != results.end(); it++)
	    delete *it;
    }

    ResultSet* Result::makeResultSet (POSFactory* posFactory) {
	ResultSet* ret = new ResultSet(posFactory);
	delete *ret->begin();
	ret->erase(ret->begin());
	ret->insert(ret->begin(), duplicate(ret, ret->begin()));
	return ret;
    }
    void Result::assumeNewBindings (Result* from) {
	for (BindingSetIterator it = from->bindings.begin(); it != from->bindings.end(); it++)
	    bindings[it->first] = it->second;
	//	    set(it->first, it->second);	
    }


    ResultSet* ResultSet::clone () {
	ResultSet* ret = new ResultSet(posFactory);
	delete *ret->begin();
	ret->erase(ret->begin());
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    ret->insert(ret->begin(), (*it)->duplicate(ret, ret->end()));
	return ret;
    }

    struct FilterInjector : public SWObjectDuplicator {
	const ResultSet& rs;
	FilterInjector (POSFactory* posFactory, const ResultSet& rs) : SWObjectDuplicator(posFactory), rs(rs) {  }
	VariableList vars;
	virtual void variable (const Variable* const self, std::string lexicalValue) {
	    vars.insert(self);
	    SWObjectDuplicator::variable(self, lexicalValue);
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	    ResultSet* joined(NULL);
	    const ResultSet* working = &rs;
	    if (p_BindingClause != NULL) {
		working = joined = new ResultSet(rs);
		p_BindingClause->bindVariables(NULL, joined);
	    }

	    vars.clear(); // probably got filled with e.g. select vars.
	    p_GroupGraphPattern->express(this);
	    const TableOperation* op = last.tableOperation;
	    const VariableList* knownVars = working->getKnownVars();
	    std::vector<const POS*> v(vars.size() + knownVars->size());
	    std::vector<const POS*>::iterator needed =
		std::set_intersection (vars.begin(), vars.end(), knownVars->begin(),
				       knownVars->end(), v.begin());
	    const std::set<const POS*> s(v.begin(), v.end());
	    const Expression* filter = working->getFederationExpression(s, false);
	    if (filter) {
		Filter* f = new Filter(op);
		f->addExpression(filter);
		op = f;
	    }

	    if (joined)
		delete joined;
	    last.whereClause = new WhereClause(op, NULL);
	}
    };

//     const TableOperation* ResultSet::getConstrainedTableOperation (const TableOperation* tableop) {
//     }
    const Operation* ResultSet::getConstrainedOperation (const Operation* op) const {
	/* The VarLister is a serializer which also records all variables.
	 */
	if (size() == 1 && (*results.begin())->size() == 0)
	    return NULL;
	FilterInjector ij((POSFactory*)posFactory, *this); // this is const, but the factory isn't.
	op->express(&ij);
	return ij.last.operation;
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
		if (dynamic_cast<const Bindable*>(l) && 
		    dynamic_cast<const Bindable*>(r))
		    continue;
		if (l != r)
		    return pair.ascOrDesc == ORDER_Desc ? posFactory->lessThan(r, l) : posFactory->lessThan(l, r);
	    }
	    return false;
	}
    };

    struct AscendingOrder {
	const VariableVector vars;
	POSFactory* posFactory;
	AscendingOrder (const VariableVector vars, POSFactory* posFactory) : 
	    vars(vars), posFactory(posFactory) {  }
	bool operator() (const Result* lhs, const Result* rhs) {
	    for (VariableVectorConstIterator it = vars.begin();
		 it != vars.end(); ++it) {
		// 			SPARQLSerializer s;
		// 			pair.expression->express(&s);
		const POS* l = lhs->get(*it);
		const POS* r = rhs->get(*it);
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
		    return posFactory->lessThan(l, r);
	    }
	    return false;
	}
    };

    const POS* _getLabel (const ExpressionAlias* exprAlias, POSFactory* posFactory) {
	if (exprAlias->label == NULL) {
	    const POSExpression* ex = dynamic_cast<const POSExpression*>(exprAlias->expr);
	    if (ex == NULL) {
		SPARQLSerializer s;
		exprAlias->express(&s);
		return posFactory->getRDFLiteral(s.str());
	    } else
		return ex->getPOS();
	} else
	    return exprAlias->label;
    }

    void ResultSet::project (ProductionVector<const ExpressionAlias*> const * exprs, ExpressionAliasList* groupBy, ProductionVector<const w3c_sw::Expression*>* having) {
	// std::cerr << "start\n" << *this;
	/* List of vars to erase.
	 * This is cheaper than walking all the bindings in a row, but assumes
	 * that the variables for all rows appear in knownVars.
	 */
	std::set<const POS*> delMes(knownVars.begin(), knownVars.end());
	if (groupBy != NULL && groupBy->size() > 0)
	    for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		 it != groupBy->end(); ++it)
		delMes.insert(_getLabel(*it, posFactory));

	/* Replace the known vars and the select order. */
	knownVars.clear();
	selectOrder.clear();
	orderedSelect = true;

	/* Each groupBy will be toString()'d and appended to groupIndex.
	 * example: <a>~1~11~"Bob"@en~
	 */
	std::string groupIndex;

	/* Map select variables to the expressions bound to them. */
	typedef std::map<const POS*,const Expression*> Pos2Expr;
	Pos2Expr pos2expr;

	/* Walk the select list to populate pos2expr. */
	for (std::vector<const ExpressionAlias*>::const_iterator varExpr = exprs->begin();
	     varExpr != exprs->end(); ++varExpr) {
	    const POS* label(_getLabel(*varExpr, posFactory));

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
		    FunctionState (std::string& groupIndexRef) : FunctionCall (NULL, NULL), groupIndexRef(groupIndexRef) {  }
		    ~FunctionState () {  }
		    virtual const POS* eval(const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const = 0; // @@ needed?
		    static std::string mitoa (int i) {
			std::stringstream s;
			s << i;
			return s.str();
		    }
		};
		struct CountState : public FunctionState { // FunctionCall for virtual eval
		protected:
		    std::map<std::string, int> counts;
		public:
		    CountState (std::string& groupIndexRef)
			: FunctionState (groupIndexRef) {  }
		    ~CountState () {  }
		    virtual const POS* eval (const Result* /* r */, POSFactory* posFactory, BNodeEvaluator* /* evaluator */) const {
			return posFactory->getNumericRDFLiteral(mitoa(++(((CountState*)this)->counts[groupIndexRef])), ((CountState*)this)->counts[groupIndexRef]);
		    }
		};
		struct SumState : public FunctionState { // FunctionCall for virtual eval
		protected:
		    const Expression* expr;
		    std::map<std::string, const POS*> vals;
		public:
		    SumState (const Expression* expr, std::string& groupIndexRef)
			: FunctionState (groupIndexRef), expr(expr) {  }
		    ~SumState () {  }
		    virtual const POS* eval (const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
			if (vals.find(groupIndexRef) == vals.end()) {
			    ((SumState*)this)->vals[groupIndexRef] = expr->eval(r, posFactory, evaluator);
			} else {
			    ArithmeticSum::NaryAdder f(r, posFactory, evaluator);
			    std::vector<const Expression*> addends;
			    POSExpression valExpr(((SumState*)this)->vals[groupIndexRef]);
			    addends.push_back(&valExpr);
			    addends.push_back(expr);
			    ((SumState*)this)->vals[groupIndexRef] = posFactory->applyCommonNumeric(addends, &f);
			}
			return ((SumState*)this)->vals[groupIndexRef];
		    }
		};
		AggregateStateInjector (POSFactory* posFactory, std::string& groupIndexRef) : SWObjectDuplicator(posFactory), groupIndexRef(groupIndexRef) {  }
		virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {
		    std::vector<const Expression*>::const_iterator it = p_ArgList->begin();
		    if (p_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count")) {
			last.functionCall = new CountState(groupIndexRef);
		    } else if (p_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum")) {
			(*it)->express(this);
			last.functionCall = new SumState(last.expression, groupIndexRef);
		    } else {
			NEED_IMPL(std::string("functionCall(") + p_IRIref->toString());
		    }
		}
	    };
	    AggregateStateInjector inj(posFactory, groupIndex);
	    (*varExpr)->expr->express(&inj);
	    pos2expr[label] = inj.last.expression;
	}

	/* Map groupIndex to sole row with that GROUP BY pattern. */
	typedef std::map<std::string, ResultSetIterator> Group2Row;
	Group2Row group2row;

	for (ResultSetIterator row = begin() ; row != end(); ) {

	    ResultSetIterator aggregateRow;
	    if (groupBy != NULL && groupBy->size() > 0) {
		/* eval groupIndex args, add to result */
		groupIndex = "";
		for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		     it != groupBy->end(); ++it) {
		    const POS* val = (*it)->expr->eval(*row, posFactory, NULL);
		    groupIndex += val->toString() + "~";
		    (*row)->set((*it)->label, val, false, true); // !! WG decision on overwrite
		}

		/* This working row may be redundant against an older row (with same
		 * groupIndex).
		 */
		Group2Row::iterator curAgg(group2row.find(groupIndex));
		if (curAgg == group2row.end()) {
		    group2row[groupIndex] = aggregateRow = row;
		    row++;
		} else {
		    aggregateRow = curAgg->second;
		    delete *row;
		    row = erase(row);
		}
	    } else {
		aggregateRow = row;
		row++;
	    }

	    /* calc project, update idx */
	    for (std::set<const POS*>::const_iterator knownVar = knownVars.begin();
		 knownVar != knownVars.end(); ++knownVar) {
		const POS* val = pos2expr[*knownVar]->eval(*aggregateRow, posFactory, NULL);
		if (val != NULL)
		    (*aggregateRow)->set(*knownVar, val, false, true); // !! WG decision on overwrite
	    }

	    /* Eliminate unselect attributes */
	    for (std::set<const POS*>::const_iterator delMe = delMes.begin();
		 delMe != delMes.end(); ++delMe)
		if ((*aggregateRow)->find(*delMe) != (*aggregateRow)->end())
		    (*aggregateRow)->erase((*aggregateRow)->find(*delMe));

	    /* Test against HAVING constraints */
	    if (having != NULL) {
		for (std::vector<const w3c_sw::Expression*>::const_iterator it = having->begin();
		     it != having->end(); ++it)
		    if (posFactory->eval(*it, *aggregateRow) != true)
			row = erase(aggregateRow);
	    }
	}

	/* Clean up new'd expressions. */
	for (Pos2Expr::iterator it = pos2expr.begin(); it != pos2expr.end(); ++it) {
	    const Expression* exp = it->second;
	    delete exp;
	}
	// std::cerr << "end\n" << *this;
    }

    void ResultSet::restrict (const Expression* expression) {

	for (ResultSetIterator it = begin(); it != end(); ) {
	    if (posFactory->eval(expression, *it) == true)
		++it;
	    else {
		delete *it;
		it = erase(it);
	    }
	}
    }

    void ResultSet::order (std::vector<s_OrderConditionPair>* orderConditions) {
	ResultComp resultComp(orderConditions, posFactory);
	results.sort(resultComp);
    }


    void ResultSet::order () {
	AscendingOrder resultComp(getOrderedVars(), posFactory);
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

    BoxChars BoxChars::AsciiBoxChars(false, // instraRow
			   "--", // null
			   "O", // ordered
			   "!", // unlistedVar
			   /*        .l   .b   .s   .r */
			   /* u. */ "+", "-", "+", "+", 
			   /* r. */ "|", " ", "|", "|", 
			   /* s. */ "+", "-", "+", "+", 
			   /* l. */ "+", "-", "+", "+"
			   );
    BoxChars BoxChars::Utf8BoxChars (false, // instraRow
			   "--", // null
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
			   "--", // null
			   "O", // ordered
			   "!", // unlistedVar
			   /*        .l   .b   .s   .r */
			   /* u. */ "┏", "━", "┯", "┓", 
			   /* r. */ "┃", " ", "│", "┃", 
			   /* s. */ "┠", "─", "┼", "┨", 
			   /* l. */ "┗", "━", "┷", "┛"
			   );

    BoxChars* BoxChars::GBoxChars = &BoxChars::AsciiBoxChars;

    class STRING : public std::string {
    public:
	STRING (size_t repts, const char* str) : std::string() {
	    for (size_t i = 0; i < repts; ++i)
		append(str);
	    }
    };

    std::string render (const POS* p, NamespaceMap* namespaces) {
	return
	    p == NULL
	    ? BoxChars::GBoxChars->null
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
	std::vector< const POS* > vars;
	std::vector< size_t > widths;
	unsigned count = 0;
	unsigned lastInKnownVars = 0;
	{
	    std::map< const POS*, unsigned > pos2col;
	    const VariableVector cols = getOrderedVars();
//	    vars = getOrderedVars();
	    for (VariableVectorConstIterator varIt = cols.begin() ; varIt != cols.end(); ++varIt) {
		const POS* var = *varIt;
		pos2col[var] = count++;
		widths.push_back(var->toString().size());
		vars.push_back(var);
	    }

	    VariableList intruders;
	    lastInKnownVars = count;
	    for (ResultSetConstIterator row = results.begin() ; row != results.end(); ++row)
		for (BindingSetIterator b = (*row)->begin(); b != (*row)->end(); ++b) {
		    const POS* var = b->first;
		    if (pos2col.find(var) == pos2col.end()) {
			/* Error: a variable not listed in knownVars. */
			pos2col[var] = count++;
			std::string rendered(render(var, namespaces));
			widths.push_back(rendered.size());
			vars.push_back(var);
			intruders.insert(var);
		    }
		    std::string rendered(render(b->second.pos, namespaces));
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
	s << BoxChars::GBoxChars->ur << std::endl;

	/*   Column Headings */
	for (i = 0; i < count; i++) {
	    const POS* var = vars[i];
	    s << (i == 0 ? BoxChars::GBoxChars->rl : i < lastInKnownVars ? BoxChars::GBoxChars->rs : BoxChars::GBoxChars->unlistedVar) << ' ';
	    size_t width = var->toString().length();
	    s << var->toString() << STRING(widths[i] - width, BoxChars::GBoxChars->rb) << ' '; // left justified.
	}
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
		const POS* var = vars[i];
		const POS* val = (*row)->get(var);
		const std::string str = render(val, namespaces);
		s << (i == 0 ? BoxChars::GBoxChars->rl : BoxChars::GBoxChars->rs) << ' ';
		size_t width = str.length();
		s << STRING(widths[i] - width, BoxChars::GBoxChars->rb) << str << ' '; // right justified.
	    }
	    s << BoxChars::GBoxChars->rr << std::endl;
	}

	/*   Bottom Border */
	for (i = 0; i < count; i++) {
	    s << (i == 0 ? BoxChars::GBoxChars->ll : BoxChars::GBoxChars->ls);
	    s << STRING(widths[i]+2, BoxChars::GBoxChars->lb);
	}
	s << BoxChars::GBoxChars->lr << std::endl;
	return s.str();
    }
    XMLSerializer* ResultSet::toXml (XMLSerializer* xml) {
	if (xml == NULL) xml = new XMLSerializer("  ");
	xml->open("sparql");
	xml->attribute("xmlns", "http://www.w3.org/2005/sparql-results#");
	xml->open("head");
	const VariableVector cols = getOrderedVars();
	for (VariableVectorConstIterator varIt = cols.begin() ; varIt != cols.end(); ++varIt) {
	    xml->empty("variable");
	    xml->attribute("name", (*varIt)->getLexicalValue());
	}
	xml->close();
	xml->open("results");
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    (*it)->toXml(xml);
	xml->close();
	xml->close();
	return xml;
    }

    XMLSerializer* ResultSet::toHtmlTable (XMLSerializer* xml, const char* tableClass) {
	if (xml == NULL) xml = new XMLSerializer("  ");
	xml->open("table");
	if (tableClass != NULL)
	    xml->attribute("class", "results");
	{
	    const VariableVector cols = getOrderedVars();
	    xml->open("tr"); {
		for (VariableVector::const_iterator col = cols.begin();
		     col != cols.end(); ++col)
		    xml->leaf("th", (*col)->toString());
	    } xml->close();
	    for (ResultSetConstIterator row = begin(); row != end(); ++row) {
		xml->open("tr"); {
		    for (VariableVector::const_iterator col = cols.begin();
			 col != cols.end(); ++col) {
			const POS* val = (*row)->get(*col);
			if (val != NULL)
			    xml->leaf("td", val->toString());
			else
			    xml->leaf("td", "");
		    }
		} xml->close();
	    }
	} xml->close();
	return xml;
    }

    std::ostream& operator<< (std::ostream& os, ResultSet const& my) {
	return os << my.toString() ;
    }
}

