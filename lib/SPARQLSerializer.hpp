/* SPARQLSerializer.hpp - simple SPARQL serializer for SPARQL compile trees.
 *
 * $Id: SPARQLSerializer.hpp,v 1.10 2008-11-13 20:53:54 eric Exp $
 */

#ifndef SPARQLSerializer_H
#define SPARQLSerializer_H

#include <stack>

namespace w3c_sw {

class SPARQLSerializer : public ExpressorSerializer {
public:
    typedef enum { DEBUG_none, DEBUG_graphs } e_DEBUG;
protected:
    MediaType mediaType;
    NamespaceMap* namespaces;
    std::stringstream ret;
    const ExprSet* injectFilter;
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
    bool needBraces;

    void start (e_PREC prec) {
	if (prec < precStack.top())
	    ret << "( ";
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
    SPARQLSerializer (MediaType mediaType = MediaType(), NamespaceMap* namespaces = NULL, const char* p_tab = "  ", e_DEBUG debug = DEBUG_none, const char* leadStr = "") : 
	mediaType(mediaType), namespaces(namespaces), injectFilter(NULL), normalizing(false), tab(p_tab), debug(debug), depth(0), precStack(), leadStr(leadStr), needBraces(false)
    { precStack.push(PREC_High); }
    virtual std::string str () { return ret.str(); }
    virtual void str (std::string seed) { ret.str(seed); }
    //!!!
    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual void members (const Members* const self, ProductionVector<const TTerm*>* p_vars) {
	ret << "MEMBERS(";
	for (std::vector<const TTerm*>::const_iterator it = p_vars->begin();
	     it != p_vars->end(); ++it) {
	    if (it != p_vars->begin())
		ret << ", ";
	    (*it)->express(this);
	}
	ret << ")";
    }
    virtual void uri (const URI* const, std::string lexicalValue) {
	std::string l;
	if (namespaces != NULL)
	    l = namespaces->unmap(lexicalValue);
	if (l.empty())
	    l = '<' + lexicalValue + '>';
	ret << l;
    }
    virtual void variable (const Variable* const, std::string lexicalValue) {
	ret << '?' << lexicalValue;
    }
    virtual void bnode (const BNode* const, std::string lexicalValue) {
	ret << "_:" << lexicalValue; // rewrite when combining named BNodes from multiple docs?
    }
    virtual void rdfLiteral (const RDFLiteral* const, std::string lexicalValue, const URI* datatype, const LANGTAG* p_LANGTAG) {
	// ret << '"' << lexicalValue << '"';
	ret << '"';
	for (std::string::const_iterator it = lexicalValue.begin();
	     it != lexicalValue.end(); ++it)
	    if (*it == '\t')
		ret << "\\t";
	    else if (*it == '\n')
		ret << "\\n";
	    else if (*it == '\r')
		ret << "\\r";
	    else if (*it == '\b')
		ret << "\\b";
	    else if (*it == '\f')
		ret << "\\f";
	    else if (*it == '\\')
		ret << "\\\\";
	    else if (*it == '"')
		ret << "\\\"";
	    else
		ret << *it;
	ret << '"';
	if (datatype != NULL) { ret << "^^<" << datatype->getLexicalValue() << '>'; }
	if (p_LANGTAG != NULL) { ret << '@' << p_LANGTAG->getLexicalValue(); }
	ret << ' ';
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, int p_value, const URI* /* p_datatype */) {
	if (normalizing)
	    ret << p_value << ' ';
	else
	    ret << self->toString() << ' ';
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, float p_value, const URI* /* p_datatype */) {
	if (normalizing)
	    ret << p_value << ' ';
	else
	    ret << self->toString() << ' ';
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, double p_value, const URI* /* p_datatype */) {
	if (normalizing)
	    ret << p_value << ' ';
	else
	    ret << self->toString() << ' ';
    }
    virtual void rdfLiteral (const BooleanRDFLiteral* const self, bool p_value) {
	if (normalizing)
	    ret << (p_value ? "true" : "false") << ' ';
	else
	    ret << self->toString() << ' ';
    }
    virtual void nulltterm (const NULLtterm* const) {
	ret << "NULL ";
    }
    virtual void triplePattern (const TriplePattern* const, const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) {
	lead();
	p_s->express(this);
	ret << ' ';
	p_p->express(this);
	ret << ' ';
	p_o->express(this);
	ret << " ." << std::endl;
    }
    virtual void filter (const Filter* const, const TableOperation* p_op, const ExprSet* p_Constraints) {
	injectFilter = p_Constraints;
	p_op->express(this);
	ret << std::endl;
    }
    void serializeFilter (const ExprSet* exprs) {
	if (exprs != NULL) {
	    for (std::vector<const Expression*>::const_iterator expr = exprs->begin();
		 expr != exprs->end(); ++expr) {
		lead();
		ret << "FILTER (";
		(*expr)->express(this);
		ret << ")" << std::endl;
	    }
	}
    }
    virtual void bind (const Bind* const, const TableOperation* p_op, const Expression* p_exp, const Variable* p_var) {
	lead();
	ret << "{" << std::endl;
	++depth;
	const ExprSet* filters = injectFilter; injectFilter = NULL;
	p_op->express(this);
	lead();
	ret << "BIND (";
	++depth;
	p_exp->express(this);
	--depth;
	ret << " AS ";
	p_var->express(this);
	ret << ")" << std::endl;
	serializeFilter(filters);
	--depth;
	lead();
	ret << "}" << std::endl;
    }
    void _BasicGraphPattern (const BasicGraphPattern* self, const ProductionVector<const TriplePattern*>* p_TriplePatterns, bool p_allOpts) {
	ret << '{';
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
	depth++;
	const ExprSet* filters = injectFilter; injectFilter = NULL;
	if (p_allOpts)
	    for (std::vector<const TriplePattern*>::const_iterator triple = p_TriplePatterns->begin();
		 triple != p_TriplePatterns->end(); triple++) {
		lead(); ret << "optional {" << std::endl << "  ";
		depth++;
		(*triple)->express(this);
		depth--;
		lead(); ret << "}" << std::endl;;
	    }
	else
	    p_TriplePatterns->express(this);
	serializeFilter(filters);
	depth--;
	lead();
	ret << '}' << std::endl;
    }
    virtual void namedGraphPattern (const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	bool braces = needBraces;
	needBraces = false;
	// p_name->express(this); handled by graphGraphPattern
	if (braces)
	    ret << "{ ";
	lead();
	ret << ' ';
	_BasicGraphPattern(self, p_TriplePatterns, p_allOpts);
	if (braces)
	    ret << " }";
    }
    virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	needBraces = false;
	lead();
	_BasicGraphPattern(self, p_TriplePatterns, p_allOpts);
    }
    virtual void tableDisjunction (const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) {
	lead();
	needBraces = false;
	ret << '{';
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
	depth++;
	const ExprSet* filters = injectFilter; injectFilter = NULL;
	for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
	     it != p_TableOperations->end(); ++it) {
	    if (it != p_TableOperations->begin()) {
		lead(depth - 1);
		ret << "UNION" << std::endl;
	    }
	    (*it)->express(this);
	}
	serializeFilter(filters);
	depth--;
	lead();
	ret << '}' << std::endl;
    }
    virtual void tableConjunction (const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) {
	lead();
	needBraces = false;
	ret << '{';
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
	depth++;
	const ExprSet* filters = injectFilter; injectFilter = NULL;
	p_TableOperations->express(this);
	serializeFilter(filters);
	depth--;
	lead();
	ret << '}' << std::endl;
    }
    virtual void optionalGraphPattern (const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ExprSet* p_Expressions) {
	bool braces = needBraces;
	needBraces = false;
	if (braces)
	    ret << "{ ";
	lead();
	ret << "OPTIONAL ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	depth++;
	injectFilter = p_Expressions;
	p_GroupGraphPattern->express(this);
	depth--;
	if (braces)
	    ret << " }";
    }
    virtual void minusGraphPattern (const MinusGraphPattern* const self, const TableOperation* p_GroupGraphPattern) {
	bool braces = needBraces;
	needBraces = false;
	if (braces)
	    ret << "{ ";
	lead();
	ret << "MINUS ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
	if (braces)
	    ret << " }";
    }
    virtual void _nestedGraphPattern (const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	p_TTerm->express(this); // note that any nested NamedGraphPattern must not output p_TTerm.
	ret << std::endl;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	bool braces = needBraces;
	needBraces = false;
	if (braces)
	    ret << "{ ";
	lead();
	ret << "GRAPH ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	_nestedGraphPattern (p_TTerm, p_GroupGraphPattern);
	if (braces)
	    ret << " }";
    }
    virtual void serviceGraphPattern (const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* /* atomFactory */, bool /* lexicalCompare */) {
	bool braces = needBraces;
	needBraces = false;
	if (braces)
	    ret << "{ ";
	lead();
	ret << "SERVICE " << p_TTerm->toString() << ' ';
	if (p_Silence == SILENT_Yes)
	    ret << "SILENT ";
	if (debug & DEBUG_graphs) ret << self << ' ';
	_nestedGraphPattern (p_TTerm, p_GroupGraphPattern);
	if (braces)
	    ret << " }";
    }
    virtual void expressionAlias (const ExpressionAlias* const, const Expression* expr, const Bindable* label) {
	if (label != NULL) {
	    lead();
	    ret << "(";
	    expr->express(this);
	    ret << " AS ";
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
	p_TTerms->express(this);
	ret << std::endl;
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
	lead();
	if (groupBy) {
	    ret << "GROUP BY";
	    for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		 it != groupBy->end(); ++it) {
		ret << ' ';
		(*it)->express(this);
	    }
	    ret << std::endl;
	}
	if (having) {
	    ret << "HAVING ";
	    for (std::vector<const Expression*>::const_iterator it = having->begin();
		 it != having->end(); ++it) {
		ret << ' ';
		(*it)->express(this);
	    }
	    ret << std::endl;
	}
	if (p_limit != LIMIT_None) ret << "LIMIT " << p_limit << std::endl;
	if (p_offset != OFFSET_None) ret << "OFFSET " << p_offset << std::endl;
	if (p_OrderConditions) {
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
	ret << "WHERE" << std::endl;
	needBraces = true;
	p_GroupGraphPattern->express(this);
    }
    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
	for (std::vector<const Operation*>::const_iterator it = p_Operations->begin();
	     it != p_Operations->end(); ++it) {
	    if (it != p_Operations->begin())
		ret << ";";
	    (*it)->express(this);
	}
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
	ret << '{' << std::endl;
	++depth;
	p_Select->express(this);
	--depth;
	lead();
	ret << '}' << std::endl;
    }

    // !!!2 -- use ConstructableOperation for p_ConstructTemplate
    virtual void construct (const Construct* const, const TableOperation* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "CONSTRUCT ";
	needBraces = true;
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
	ret << "ASK ";
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void modify (const Modify* const, const Delete* p_delete, const Insert* p_insert, WhereClause* p_WhereClause, const URI* with, std::vector<s_UsingPair>* usingGraphs) {
	lead();
	if (with)
	    ret << "WITH " << with->toString() << " ";
	if (p_delete != NULL)
	    p_delete->express(this);
	if (p_insert != NULL)
	    p_insert->express(this);
	if (usingGraphs)
	    for (std::vector<s_UsingPair>::const_iterator it = usingGraphs->begin();
		 it != usingGraphs->end(); ++it)
		ret << "USING " << (it->named ? "NAMED " : "") << it->name->toString();

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
    virtual void del (const Delete* const, bool rangeOverUnboundVars, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "DELETE";
	if (rangeOverUnboundVars)
	    ret << " DATA";
	ret << " { ";
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
	const char* s = AtomFactory::getOperatorName(p_IRIref);
	if (s != NULL)
	    ret << s;
	else
	    p_IRIref->express(this);
	ret << "(";
	if (p_IRIref == TTerm::FUNC_count && p_ArgList->size() == 0)
	    ret << "*";
	else
	    p_ArgList->express(this);
	ret << ")";
    }
    virtual void aggregateCall (const AggregateCall* const self, const URI* p_IRIref, const ArgList* p_ArgList, e_distinctness distinctness, const AggregateCall::ScalarVals* scalarVals) {
	if (distinctness == DIST_distinct) ret << "DISTINCT ";
	const char* s = AtomFactory::getOperatorName(p_IRIref);
	if (s != NULL)
	    ret << s;
	else
	    p_IRIref->express(this);
	ret << "(";
	p_ArgList->express(this);
	if (scalarVals)
	    for (AggregateCall::ScalarVals::const_iterator it = scalarVals->begin(); it != scalarVals->end(); ++it)
		ret << ";" << it->first << "=" << it->second;
	ret << ")";
    }
    virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
    }
    virtual void existsExpression (const ExistsExpression* const, const TableOperation* p_TableOperation) {
	ret << "EXISTS";
	++depth;
	p_TableOperation->express(this);
	--depth;
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
	p_left->express(this);
	ret << " = ";
	p_right->express(this);
	end();
    }
    virtual void booleanNE (const BooleanNE* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_NE);
	p_left->express(this);
	ret << " != ";
	p_right->express(this);
	end();
    }
    virtual void booleanLT (const BooleanLT* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_LT);
	p_left->express(this);
	ret << " < ";
	p_right->express(this);
	end();
    }
    virtual void booleanGT (const BooleanGT* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_GT);
	p_left->express(this);
	ret << " > ";
	p_right->express(this);
	end();
    }
    virtual void booleanLE (const BooleanLE* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_LE);
	p_left->express(this);
	ret << " <= ";
	p_right->express(this);
	end();
    }
    virtual void booleanGE (const BooleanGE* const, const Expression* p_left, const Expression* p_right) {
	start(PREC_GE);
	p_left->express(this);
	ret << " >= ";
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

    inline std::ostream& operator<< (std::ostream& os, DefaultGraphPattern const& my) {
	SPARQLSerializer s;
	my.express(&s);
	return os << s.str();
    }

    inline std::ostream& operator<< (std::ostream& os, Operation const& my) {
	SPARQLSerializer s;
	my.express(&s);
	return os << s.str();
    }

}

#endif // SPARQLSerializer_H

