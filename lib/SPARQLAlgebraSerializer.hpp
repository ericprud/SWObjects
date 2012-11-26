/* SPARQLAlgebraSerializer.hpp - simple SPARQL algebra for SPARQL compile trees.
 * Creates s-expressions similar to http://www.sparql.org/validator.html .
 *
 * $Id: SPARQLAlgebraSerializer.hpp,v 1.10 2008-11-13 20:53:54 eric Exp $
 */

#ifndef SPARQLAlgebraSerializer_H
#define SPARQLAlgebraSerializer_H

#include <stack>

namespace w3c_sw {

class SPARQLAlgebraSerializer : public ExpressorSerializer {
public:
    typedef enum { DEBUG_none, DEBUG_graphs } e_DEBUG;
    typedef enum {
	ALGEBRA_simple = 0, 
	/* options */
	ALGEBRA_binaryOpts = 1, 
	ALGEBRA_not_exists = 2, 
	/* compatibility modes */
	ALGEBRA_1_0 = 1, 
	ALGEBRA_arq = 3
    } e_ALGEBRA;
protected:
    std::stringstream ret;
    const ProductionVector<const Expression*>* injectFilter;
    bool normalizing; // no constructor switch for this yet.
    typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		  PREC_And, 
		  PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		  PREC_Plus, PREC_Minus, 
		  PREC_Times, PREC_Divide, 
		  PREC_Not, PREC_TTerm, PREC_Neg, PREC_High = PREC_Neg} e_PREC;
    const char* tab;
    e_DEBUG debug;
    size_t depth;
    std::stack<e_PREC> precStack;
    const char* leadStr;
    e_ALGEBRA algebra;

    /* Simulate SPARQL semantics serialization:
     *   Joins test members and express as leftjoins where 2nd is an optional.
     *   Optionals outside of a join express as (leftjoin (table unit) ...).
     *
     */
    bool optionalIsChildOfJoin;


    void start (e_PREC prec) {
	if (prec < precStack.top())
	    ret << "(";
	precStack.push(prec);
    }
    void end () {
	e_PREC prec = precStack.top();
	precStack.pop();
	if (prec < precStack.top())
	    ret << ")";
    }
    void lead () {
	ret << leadStr;
	for (size_t i = 0; i < depth; i++)
	    ret << tab;
    }
    void lead (size_t p_depth) {
	ret << leadStr;
	for (size_t i = 0; i < p_depth; i++)
	    ret << tab;
    }
public:
    SPARQLAlgebraSerializer (e_ALGEBRA algebra = ALGEBRA_simple, const char* p_tab = "  ", e_DEBUG debug = DEBUG_none, const char* leadStr = "") : 
	injectFilter(NULL), normalizing(false), tab(p_tab), debug(debug), depth(0), precStack(), leadStr(leadStr), algebra(algebra), optionalIsChildOfJoin(false)
    { precStack.push(PREC_High); }
    virtual std::string str () { return ret.str(); }
    virtual void str (std::string seed) { ret.str(seed); }
    //!!!
    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual void members (const Members* const self, ProductionVector<const TTerm*>* p_vars) {
	ret << "members(";
	for (std::vector<const TTerm*>::const_iterator it = p_vars->begin();
	     it != p_vars->end(); ++it) {
	    if (it != p_vars->begin())
		ret << ", ";
	    (*it)->express(this);
	}
	ret << ")";
    }
    virtual void uri (const URI* const, std::string lexicalValue) {
	ret << '<' << lexicalValue << '>';
    }
    virtual void variable (const Variable* const, std::string lexicalValue) {
	ret << '?' << lexicalValue;
    }
    virtual void bnode (const BNode* const, std::string lexicalValue) {
	ret << "_:" << lexicalValue; // rewrite when combining named BNodes from multiple docs?
    }
    virtual void rdfLiteral (const RDFLiteral* const, std::string lexicalValue, const URI* datatype, const LANGTAG* p_LANGTAG) {
	ret << '"' << lexicalValue << '"';
	if (datatype != NULL) { ret << "^^<" << datatype->getLexicalValue() << '>'; }
	if (p_LANGTAG != NULL) { ret << '@' << p_LANGTAG->getLexicalValue(); }
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, int p_value, const URI* /* p_datatype */) {
	if (normalizing)
	    ret << p_value;
	else
	    ret << self->toString();
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, float p_value, const URI* /* p_datatype */) {
	if (normalizing)
	    ret << p_value;
	else
	    ret << self->toString();
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, double p_value, const URI* /* p_datatype */) {
	if (normalizing)
	    ret << p_value;
	else
	    ret << self->toString();
    }
    virtual void rdfLiteral (const BooleanRDFLiteral* const self, bool p_value) {
	if (normalizing)
	    ret << (p_value ? "true" : "false");
	else
	    ret << self->toString();
    }
    virtual void nulltterm (const NULLtterm* const) {
	ret << "NULL ";
    }
    virtual void triplePattern (const TriplePattern* const, const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) {
	ret << "(triple ";
	p_s->express(this);
	ret << ' ';
	p_p->express(this);
	ret << ' ';
	p_o->express(this);
	ret << ")";
    }
    virtual void _exprlist (const ProductionVector<const Expression*>* p_Constraints) {
	if (p_Constraints->size() > 1)
	    ret << "(exprlist ";
	for (std::vector<const Expression*>::const_iterator it = p_Constraints->begin();
	     it != p_Constraints->end(); ++it) {
	    if (it != p_Constraints->begin())
		ret << " ";
	    (*it)->express(this);
	}
	if (p_Constraints->size() > 1)
	    ret << ")";
	ret << std::endl;
    }
    virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
#if 0
	injectFilter = p_Constraints;
#endif
	lead();
	ret << "(filter ";
	_exprlist(p_Constraints);
	++depth;
	if (p_op) p_op->express(this); else ret << "No nested operation!"; // !!!
	--depth;
	lead();
	ret << ")";
	ret << std::endl;
    }
    void injectFilters () {
	if (injectFilter != NULL) {
	    lead();
	    ret << "FILTER ";
	    injectFilter->express(this);
	    ret << std::endl;
	    injectFilter = NULL;
	}
    }
    virtual void bind (const Bind* const, const TableOperation* p_op, const Expression* p_exp, const Variable* p_var) {
	lead();
	ret << "(extend (";
	++depth;
	p_var->express(this);
	--depth;
	ret << " ";
	++depth;
	p_exp->express(this);
	--depth;
	ret << ")" << std::endl;
	++depth;
	if (p_op) p_op->express(this); else ret << "No nested operation!"; // !!!
	--depth;
	lead();
	ret << ")";
	ret << std::endl;
    }
    void _BasicGraphPattern (const BasicGraphPattern* self, const ProductionVector<const TriplePattern*>* p_TriplePatterns, bool p_allOpts) {
	/* Note early return for "(table unit)". */
	if (p_TriplePatterns->size() == 0) {
	    ret << "(table unit)" << std::endl;
	    return;
	}
	ret << "(bgp";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	if (p_TriplePatterns->size() > 1)
	    ret << std::endl;
	else
	    ret << " ";
	depth++;
	for (std::vector<const TriplePattern*>::const_iterator triple = p_TriplePatterns->begin();
	     triple != p_TriplePatterns->end(); triple++) {
	    if (p_TriplePatterns->size() > 1)
		lead();
	    if (p_allOpts)
		ret << "(optional " << std::endl << "  ";
	    depth++;
	    (*triple)->express(this);
	    if (p_TriplePatterns->size() > 1)
		ret << std::endl;
	    depth--;
	    if (p_allOpts)
		ret << ")" << std::endl;;
	    }
	injectFilters();
	depth--;
	if (p_TriplePatterns->size() > 1)
	    lead();
	ret << ")" << std::endl;
    }
    virtual void namedGraphPattern (const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	lead();
	p_name->express(this);
	ret << ' ';
	_BasicGraphPattern(self, p_TriplePatterns, p_allOpts);
    }
    virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	lead();
	_BasicGraphPattern(self, p_TriplePatterns, p_allOpts);
    }
    virtual void tableDisjunction (const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) {
	lead();
	ret << "(union";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
	depth++;
	for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
	     it != p_TableOperations->end(); ++it) {
	    (*it)->express(this);
	}
	injectFilters();
	depth--;
	lead();
	ret << ")" << std::endl;
    }

    void recursiveJoiner (const ProductionVector<const TableOperation*>* p_TableOperations, std::vector<const TableOperation*>::const_reverse_iterator it) {

	const TableOperation* r = *it;
	const OptionalGraphPattern* opt = dynamic_cast<const OptionalGraphPattern*>(r);
	++it;
	if (it == std::vector<const TableOperation*>::const_reverse_iterator(p_TableOperations->begin())) {
	    if (opt != NULL) {
		lead(); ret << "(leftjoin" << std::endl;
		depth++;
		lead(); ret << "(table unit)" << std::endl;
		optionalIsChildOfJoin = true;
		opt->express(this);
		optionalIsChildOfJoin = false;
		depth--;
		lead(); ret << ")" << std::endl;
	    } else {
		r->express(this);
	    }
	} else {
	    lead(); ret << (opt != NULL ? "(leftjoin" : "(join") << std::endl;
	    depth++;
	    recursiveJoiner(p_TableOperations, it);
	    if (opt != NULL) {
		optionalIsChildOfJoin = true;
		opt->express(this);
		optionalIsChildOfJoin = false;
	    } else {
		r->express(this);
	    }
	    depth--;
	    lead(); ret << ")" << std::endl;
	}
    }

    virtual void tableConjunction (const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) {
	if (algebra & ALGEBRA_binaryOpts)
	    recursiveJoiner(p_TableOperations, std::vector<const TableOperation*>::const_reverse_iterator(p_TableOperations->end()));
	else {
	    lead(); ret << "(join";
	    if (debug & DEBUG_graphs) ret << ' ' << self;
	    ret << std::endl;
	    depth++;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); ++it)
		(*it)->express(this);
	    depth--;
	    lead(); ret << ")" << std::endl;
	}
    }
    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
	if (algebra & ALGEBRA_binaryOpts) {
	    if (optionalIsChildOfJoin == false) {
		lead(); ret << "(leftjoin" << std::endl;
		depth++;
		lead(); ret << "(table unit)" << std::endl;
	    }
	    p_GroupGraphPattern->express(this);
	    if (p_Expressions->size() > 0) {
		lead();
		_exprlist(p_Expressions);
	    }
	    if (optionalIsChildOfJoin == false) {
		depth--;
		lead(); ret << ")" << std::endl;
	    }
	} else {
	    lead(); ret << "(optional" << std::endl;
	    depth++;
	    p_GroupGraphPattern->express(this);
	    if (p_Expressions->size() > 0)
		lead(), _exprlist(p_Expressions);
	    depth--;
	    lead(); ret << ")" << std::endl;
	}
    }
    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "MINUS ";
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    void _nestedGraphPattern (const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	p_TTerm->express(this);
	ret << std::endl;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "GRAPH ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	_nestedGraphPattern(p_TTerm, p_GroupGraphPattern);
    }
    virtual void serviceGraphPattern (const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* /* atomFactory */, bool /* lexicalCompare */) {
	lead();
	ret << "service(";
	p_TTerm->express(this);
	ret << ", ";
	if (p_Silence)
	    ret << "(silence true), ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	_nestedGraphPattern(p_TTerm, p_GroupGraphPattern);
	ret << ")";
    }
    virtual void expressionAlias (const ExpressionAlias* const, const Expression* expr, const Bindable* label) {
	if (label != NULL) {
	    lead();
	    ret << "alias(";
	    expr->express(this);
	    ret << ", ";
	    label->express(this);
	    ret << ")";
	} else
	    expr->express(this);
    }
    virtual void expressionAliasList (const ExpressionAliasList* const, const ProductionVector<const ExpressionAlias*>* p_Expressions) {
	for (std::vector<const ExpressionAlias*>::const_iterator it = p_Expressions->begin();
	     it != p_Expressions->end(); ++it) {
	    (*it)->express(this);
	    ret << ' ';
	}
    }
    virtual void posList (const TTermList* const, const ProductionVector<const TTerm*>* p_TTerms) {
	for (std::vector<const TTerm*>::const_iterator it = p_TTerms->begin();
	     it != p_TTerms->end(); ++it) {
	    if (it != p_TTerms->begin())
		ret << ' ';
	    (*it)->express(this);
	}
    }
    virtual void starVarSet (const StarVarSet* const) {
	ret << "* ";
    }
    virtual void defaultGraphClause (const DefaultGraphClause* const, const TTerm* p_IRIref) {
	ret << "FROM ";
	p_IRIref->express(this);
    }
    virtual void namedGraphClause (const NamedGraphClause* const, const TTerm* p_IRIref) {
	ret << "FROM NAMED ";
	p_IRIref->express(this);
    }
    virtual void solutionModifier (const SolutionModifier* const, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	bool indented = false;
	if (groupBy) {
	    { lead(); indented = true; }
	    ret << "GROUP BY";
	    for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		 it != groupBy->end(); ++it) {
		ret << ' ';
		(*it)->express(this);
	    }
	    ret << std::endl;
	}
	if (having) {
	    if (!indented) { lead(); indented = true; }
	    ret << "HAVING ";
	    for (std::vector<const Expression*>::const_iterator it = having->begin();
		 it != having->end(); ++it) {
		ret << ' ';
		(*it)->express(this);
	    }
	    ret << std::endl;
	}
	if (p_limit != LIMIT_None) {
	    if (!indented) { lead(); indented = true; }
	    ret << "LIMIT " << p_limit << std::endl;
	}
	if (p_offset != OFFSET_None) {
	    if (!indented) { lead(); indented = true; }
	    ret << "OFFSET " << p_offset << std::endl;
	}
	if (p_OrderConditions) {
	    if (!indented) { lead(); indented = true; }
	    ret << "ORDER BY ";
	    for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		if (p_OrderConditions->at(i).ascOrDesc == ORDER_Desc) ret << "DESC ";
		p_OrderConditions->at(i).expression->express(this);
	    }
	    ret << std::endl;
	}
    }
    virtual void bindingClause (const BindingClause* const, const ResultSet* p_ResultSet) {
	ret << "BINDINGS ";
	std::map< const TTerm*, unsigned > pos2col;
	std::vector<const TTerm*> vars;
	{
	    const VariableVector cols = p_ResultSet->getOrderedVars();
	    for (VariableVectorConstIterator varIt = cols.begin() ; varIt != cols.end(); ++varIt) {
		const TTerm* var = *varIt;
		pos2col[var] = vars.size();
		vars.push_back(var);
		var->express(this);
	    }
	}

	ret << '{' << std::endl; //!!!
	{

	    for (ResultSetConstIterator row = p_ResultSet->begin();
		 row != p_ResultSet->end(); row++) {
		ret << "(";
		/*  Values */
		for (size_t i = 0; i < vars.size(); ++i) {
		    if (i != 0)
			ret << ", ";
		    const TTerm* var = vars[i];
		    const TTerm* val = (*row)->get(var);
		    if (val == NULL)
			val = TTerm::Unbound;
		    ret << val->toString();
		}
		ret << ")" << std::endl;
	    }
	}
	ret << '}' << std::endl;
    }
    virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern) {
	p_GroupGraphPattern->express(this);
    }
    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
	lead();
	ret << "OPERATIONSET (";
	++depth;
	for (std::vector<const Operation*>::const_iterator it = p_Operations->begin();
	     it != p_Operations->end(); ++it) {
	    if (it != p_Operations->begin())
		ret << ";";
	    (*it)->express(this);
	}
	--depth;
	ret << ")";
    }
    virtual void select (const Select* const, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "SELECT ";
	if (p_distinctness == DIST_distinct) ret << "DISTINCT ";
	if (p_distinctness == DIST_reduced) ret << "REDUCED ";
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	ret << std::endl;
	lead();
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	lead();
	ret << "subselect(" << std::endl;
	++depth;
	p_Select->express(this);
	--depth;
	ret << ")" << std::endl;
    }

    // !!!2 -- use ConstructableOperation for p_ConstructTemplate
    virtual void construct (const Construct* const, const TableOperation* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "CONSTRUCT ";
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void describe (const Describe* const, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "DESCRIBE ";
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "(ask" << std::endl;
	++depth;
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	if (p_SolutionModifier)
	    p_SolutionModifier->express(this);
	--depth;
	ret << ")" << std::endl;
    }
    virtual void modify (const Modify* const, const Delete* p_delete, const Insert* p_insert, WhereClause* p_WhereClause) {
	lead();
	ret << "MODIFY ";
	if (p_delete != NULL)
	    p_delete->express(this);
	if (p_insert != NULL)
	    p_insert->express(this);
	p_WhereClause->express(this);
    }
    virtual void insert (const Insert* const self, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "INSERT { ";
	if (debug & DEBUG_graphs) ret << self << ' ';
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	ret << "}" << std::endl;
    }
    virtual void del (const Delete* const, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "DELETE { ";
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	ret << "}" << std::endl;
    }
    virtual void load (const Load* const, e_Silence p_Silence, const URI* p_from, const URI* p_into) {
	lead();
	ret << "LOAD ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_from->express(this);
	p_into->express(this);
    }
    virtual void clear (const Clear* const, e_Silence p_Silence, const URI* p__QGraphIRI_E_Opt) {
	lead();
	ret << "CLEAR ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p__QGraphIRI_E_Opt->express(this);
    }
    virtual void create (const Create* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	lead();
	ret << "CREATE ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_GraphIRI->express(this);
    }
    virtual void drop (const Drop* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	lead();
	ret << "DROP ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_GraphIRI->express(this);
    }
    virtual void add (const Add* const, e_Silence p_Silence, const URI* from, const URI* to) {
	lead();
	ret << "ADD ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	from->express(this);
	ret << " TO ";
	to->express(this);
    }
    virtual void move (const Move* const, e_Silence p_Silence, const URI* from, const URI* to) {
	lead();
	ret << "MOVE ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	from->express(this);
	ret << " TO ";
	to->express(this);
    }
    virtual void copy (const Copy* const, e_Silence p_Silence, const URI* from, const URI* to) {
	lead();
	ret << "COPY ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	from->express(this);
	ret << " TO ";
	to->express(this);
    }
    virtual void posExpression (const TTermExpression* const, const TTerm* p_TTerm) {
	p_TTerm->express(this);
    }
    virtual void argList (const ArgList* const, ProductionVector<const Expression*>* expressions) {
	for (std::vector<const Expression*>::const_iterator it = expressions->begin();
	     it != expressions->end(); ++it) {
	    if (it != expressions->begin())
		ret << ", ";
	    (*it)->express(this);
	}
    }
    virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {

	if (p_IRIref == TTerm::FUNC_str)
	    ret << "str";
	else if (p_IRIref == TTerm::FUNC_lang)
	    ret << "lang";
	else if (p_IRIref == TTerm::FUNC_langMatches)
	    ret << "langMatches";
	else if (p_IRIref == TTerm::FUNC_datatype)
	    ret << "datatype";
	else if (p_IRIref == TTerm::FUNC_bound)
	    ret << "bound";
	else if (p_IRIref == TTerm::FUNC_sameTerm)
	    ret << "sameTerm";
	else if (p_IRIref == TTerm::FUNC_isIRI)
	    ret << "isIRI";
	else if (p_IRIref == TTerm::FUNC_isIRI)
	    ret << "isIRI";
	else if (p_IRIref == TTerm::FUNC_isBlank)
	    ret << "isBlank";
	else if (p_IRIref == TTerm::FUNC_isLiteral)
	    ret << "isLiteral";
	else
	    p_IRIref->express(this);
	ret << "(";
	p_ArgList->express(this);
	ret << ")";
    }
    virtual void aggregateCall (const AggregateCall* const self, const URI* p_IRIref, const ArgList* p_ArgList, e_distinctness distinctness, const AggregateCall::ScalarVals* scalarVals) {
	w3c_sw_NEED_IMPL("AggregateCall algebra serializer");
    }
    virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
    }
    virtual void existsExpression (const ExistsExpression* const, const TableOperation* p_TableOperation) {
	ret << "exists(";
	++depth;
	p_TableOperation->express(this);
	--depth;
	ret << ")";
    }
/* Expressions */
    virtual void booleanNegation (const BooleanNegation* const, const Expression* p_Expression) {
	start(PREC_Not);
	ret << '!';
	p_Expression->express(this);
	end();
    }
    virtual void arithmeticNegation (const ArithmeticNegation* const, const Expression* p_Expression) {
	start(PREC_Neg);
	ret << "- ";
	p_Expression->express(this);
	end();
    }
    virtual void arithmeticInverse (const ArithmeticInverse* const, const Expression* p_Expression) {
	start(PREC_Divide);
	ret << "1/";
	p_Expression->express(this);
	end();
    }
    virtual void booleanConjunction (const BooleanConjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	start(PREC_And);
	for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
	     it != p_Expressions->end(); ++it) {
	    if (it != p_Expressions->begin())
		ret << " && ";
	    (*it)->express(this);
	}
	end();
    }
    virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	start(PREC_Or);
	for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
	     it != p_Expressions->end(); ++it) {
	    if (it != p_Expressions->begin())
		ret << " || ";
	    (*it)->express(this);
	}
	end();
    }
    virtual void arithmeticSum (const ArithmeticSum* const, const ProductionVector<const Expression*>* p_Expressions) {
	start(PREC_Plus);
	for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
	     it != p_Expressions->end(); ++it) {
	    if (it != p_Expressions->begin())
		ret << " + ";
	    (*it)->express(this);
	}
	end();
    }
    virtual void arithmeticProduct (const ArithmeticProduct* const, const ProductionVector<const Expression*>* p_Expressions) {
	start(PREC_Times);
	for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
	     it != p_Expressions->end(); ++it) {
	    if (it != p_Expressions->begin())
		ret << " * ";
	    (*it)->express(this);
	}
	end();
    }
    virtual void booleanEQ (const BooleanEQ* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_EQ);
	ret << "= ";
	p_left->express(this);
	ret << " ";
	p_right->express(this);
	end();
    }
    virtual void booleanNE (const BooleanNE* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_NE);
	ret << "!= ";
	p_left->express(this);
	ret << " ";
	p_right->express(this);
	end();
    }
    virtual void booleanLT (const BooleanLT* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_LT);
	ret << "< ";
	p_left->express(this);
	ret << " ";
	p_right->express(this);
	end();
    }
    virtual void booleanGT (const BooleanGT* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_GT);
	ret << "> ";
	p_left->express(this);
	ret << " ";
	p_right->express(this);
	end();
    }
    virtual void booleanLE (const BooleanLE* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_LE);
	ret << "<= ";
	p_left->express(this);
	ret << " ";
	p_right->express(this);
	end();
    }
    virtual void booleanGE (const BooleanGE* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_GE);
	ret << ">= ";
	p_left->express(this);
	ret << " ";
	p_right->express(this);
	end();
    }
    virtual void naryIn (const NaryIn* const, const Expression* p_left, const ProductionVector<const Expression*>* p_right) {
	start(PREC_High);
	p_left->express(this);
	ret << " IN (";
	p_right->express(this);
	ret << ")";
	end();
    }
    virtual void comparatorExpression (const ComparatorExpression* const, const GeneralComparator* p_GeneralComparator) {
	p_GeneralComparator->express(this);
    }
    virtual void numberExpression (const NumberExpression* const, const NumericRDFLiteral* p_NumericRDFLiteral) {
	p_NumericRDFLiteral->express(this);
    }
};

#ifdef STREAM_ALGEBRA
    inline std::ostream& operator<< (std::ostream& os, DefaultGraphPattern const& my) {
	SPARQLAlgebraSerializer s;
	((DefaultGraphPattern&)my).express(&s);
	return os << s.str();
    }

    inline std::ostream& operator<< (std::ostream& os, Operation const& my) {
	SPARQLAlgebraSerializer s;
	((Operation&)my).express(&s);
	return os << s.str();
    }
#endif /* STREAM_ALGEBRA */

}

#endif // SPARQLAlgebraSerializer_H

