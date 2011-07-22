/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.cpp,v 1.7 2008-12-02 03:36:12 eric Exp $
 */

#include <set>
#include "ResultSet.hpp"
#include "SWObjectDuplicator.hpp"
#include "XMLQueryExpressor.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "JSONresultsParser/JSONresultsParser.hpp"
#include "../interface/SAXparser.hpp"
#include "SPARQLSerializer.hpp"
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

    ResultSet::ResultSet (AtomFactory* atomFactory, RdfDB* db, const char* baseURI) : 
	atomFactory(atomFactory), knownVars(), 
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
	    sptr.mediaType.match("application/sparql-results+xml")) {
	    if (parser == NULL)
		throw(std::runtime_error("ResultSet constructor requires a SAX parser."));
	    RSsax handler(this, atomFactory);
	    parser->parse(sptr, &handler);
	} else {
	    TTerm::String2BNode nodeMap;
	    if (!parseText(atomFactory, sptr, false, nodeMap))
		throw(std::runtime_error(std::string("no ResultSet constructor for mediatype ")
					 + sptr.mediaType.get()));
	}
    }

    bool ResultSet::parseText (AtomFactory* atomFactory, IStreamContext& sptr, bool ordered, TTerm::String2BNode& nodeMap) {
#if REGEX_LIB != SWOb_DISABLED
	if (!sptr.mediaType.is_initialized() ||
	    sptr.mediaType.match("text/sparql-results") || 
	    sptr.mediaType.match("text/plain")) {
	    TTerm::String2BNode nodeMap;
	    parseTable(sptr, ordered, nodeMap);
	    return true;
	} else
#endif /* REGEX_LIB != SWOb_DISABLED */
	    if (sptr.mediaType.match("application/sparql-results+json")) {
		TTerm::String2BNode nodeMap;
		JSONresultsDriver jsonResParser(atomFactory);
		jsonResParser.parse(sptr, this);
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
	    std::vector<const TTerm*>::iterator needed =
		std::set_intersection (vars.begin(), vars.end(), knownVars->begin(),
				       knownVars->end(), v.begin());
	    const std::set<const TTerm*> s(v.begin(), v.end());
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
	if (size() == 1 && (*results.begin())->size() == 0)
	    return NULL;
	FilterInjector ij((AtomFactory*)atomFactory, *this); // this is const, but the factory isn't.
	op->express(&ij);
	return ij.last.operation;
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

    void ResultSet::project (ProductionVector<const ExpressionAlias*> const * exprs, ExpressionAliasList* groupBy, ProductionVector<const w3c_sw::Expression*>* having) {
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
	for (std::vector<const ExpressionAlias*>::const_iterator varExpr = exprs->begin();
	     varExpr != exprs->end(); ++varExpr) {
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
			return atomFactory->getNumericRDFLiteral(mitoa(++(((CountState*)this)->counts[groupIndexRef])), ((CountState*)this)->counts[groupIndexRef]);
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

	    ResultSetIterator aggregateRow;
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
	    for (std::set<const TTerm*>::const_iterator knownVar = knownVars.begin();
		 knownVar != knownVars.end(); ++knownVar) {
		const TTerm* val = pos2expr[*knownVar]->eval(*aggregateRow, atomFactory, NULL);
		if (val != TTerm::Unbound)
		    (*aggregateRow)->set(*knownVar, val, false, true); // !! WG decision on overwrite
	    }

	    /* Eliminate unselect attributes */
	    for (std::set<const TTerm*>::const_iterator delMe = delMes.begin();
		 delMe != delMes.end(); ++delMe)
		if ((*aggregateRow)->find(*delMe) != (*aggregateRow)->end())
		    (*aggregateRow)->erase((*aggregateRow)->find(*delMe));

	    /* Test against HAVING constraints */
	    if (having != NULL) {
		for (std::vector<const w3c_sw::Expression*>::const_iterator it = having->begin();
		     it != having->end(); ++it)
		    if (atomFactory->eval(*it, *aggregateRow) != true) {
			delete *aggregateRow;
			row = erase(aggregateRow);
		    }
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

	for (ResultSetIterator it = begin(); it != end(); ) {
	    if (atomFactory->eval(expression, *it) == true)
		++it;
	    else {
		delete *it;
		it = erase(it);
	    }
	}
    }

    void ResultSet::order (std::vector<s_OrderConditionPair>* orderConditions) {
	ResultComp resultComp(orderConditions, atomFactory);
	results.sort(resultComp);
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
	s << BoxChars::GBoxChars->ur << std::endl;

	/*   Column Headings */
	for (i = 0; i < count; i++) {
	    const TTerm* var = vars[i];
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
		const TTerm* var = vars[i];
		const TTerm* val = (*row)->get(var);
		if (val == NULL)
		    val = TTerm::Unbound;
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
    XMLSerializer* ResultSet::toXml (XMLSerializer* xml) const { // Early returns
	if (resultType != RESULT_Tabular) {
	    xml->rawData(toString(MediaType("text/turtle")));
	    return xml;
	}
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
	for (ResultSetConstIterator it = begin() ; it != end(); it++)
	    (*it)->toXml(xml);
	xml->close();
	xml->close();
	return xml;
    }

    XMLSerializer* ResultSet::toHtmlTable (XMLSerializer* xml, XMLSerializer::Attributes attributes, std::string editPath) { // Early returns
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

    std::ostream& operator<< (std::ostream& os, ResultSet const& my) {
	return os << my.toString() ;
    }
}

