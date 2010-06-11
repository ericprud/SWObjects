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
    std::stringstream ret;
    const ExprSet* injectFilter;
    bool normalizing; // no constructor switch for this yet.
    typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		  PREC_And, 
		  PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		  PREC_Plus, PREC_Minus, 
		  PREC_Times, PREC_Divide, 
		  PREC_Not, PREC_Pos, PREC_Neg, PREC_High = PREC_Neg} e_PREC;
    const char* tab;
    e_DEBUG debug;
    size_t depth;
    std::stack<e_PREC> precStack;
    const char* leadStr;
    NamespaceMap* namespaces;

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
    SPARQLSerializer (const char* p_tab = "  ", e_DEBUG debug = DEBUG_none, const char* leadStr = "", NamespaceMap* namespaces = NULL) : 
	injectFilter(NULL), normalizing(false), tab(p_tab), debug(debug), depth(0), precStack(), leadStr(leadStr), namespaces(namespaces)
    { precStack.push(PREC_High); }
    virtual std::string str () { return ret.str(); }
    virtual void str (std::string seed) { ret.str(seed); }
    //!!!
    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

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
    virtual void rdfLiteral (const RDFLiteral* const, std::string lexicalValue, const URI* datatype, LANGTAG* p_LANGTAG) {
	ret << '"' << lexicalValue << '"';
	if (datatype != NULL) { ret << "^^<" << datatype->getLexicalValue() << '>'; }
	if (p_LANGTAG != NULL) { ret << '@' << p_LANGTAG->getLexicalValue(); }
	ret << ' ';
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, int p_value) {
	if (normalizing)
	    ret << p_value << ' ';
	else
	    ret << self->toString() << ' ';
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, float p_value) {
	if (normalizing)
	    ret << p_value << ' ';
	else
	    ret << self->toString() << ' ';
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const self, double p_value) {
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
    virtual void nullpos (const NULLpos* const) {
	ret << "NULL ";
    }
    virtual void triplePattern (const TriplePattern* const, const POS* p_s, const POS* p_p, const POS* p_o) {
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
    virtual void namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
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
	lead();
	ret << "OPTIONAL ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	depth++;
	injectFilter = p_Expressions;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void minusGraphPattern (const MinusGraphPattern* const self, const TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "MINUS ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void _nestedGraphPattern (const POS* p_POS, const TableOperation* p_GroupGraphPattern) {
	p_POS->express(this);
	ret << std::endl;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const self, const POS* p_POS, const TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "GRAPH ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	_nestedGraphPattern (p_POS, p_GroupGraphPattern);
    }
    virtual void serviceGraphPattern (const ServiceGraphPattern* const self, const POS* p_POS, const TableOperation* p_GroupGraphPattern, POSFactory* /* posFactory */, bool /* lexicalCompare */) {
	lead();
	ret << "SERVICE ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	_nestedGraphPattern (p_POS, p_GroupGraphPattern);
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
    virtual void posList (const POSList* const, const ProductionVector<const POS*>* p_POSs) {
	p_POSs->express(this);
	ret << std::endl;
    }
    virtual void starVarSet (const StarVarSet* const) {
	ret << "* ";
    }
    virtual void defaultGraphClause (const DefaultGraphClause* const, const POS* p_IRIref) {
	ret << "FROM ";
	p_IRIref->express(this);
    }
    virtual void namedGraphClause (const NamedGraphClause* const, const POS* p_IRIref) {
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
    virtual void binding (const Binding* const, const ProductionVector<const POS*>* values) {//!!!
	ret << "  { ";
	for (std::vector<const POS*>::const_iterator it = values->begin();
	     it != values->end(); ++it)
	    (*it)->express(this);
	ret << ')' << std::endl;
    }
    virtual void bindingClause (const BindingClause* const, POSList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) {
	ret << "BINDINGS ";
	p_Vars->express(this);
	ret << '{' << std::endl; //!!!
	p_Bindings->ProductionVector<const Binding*>::express(this);
	ret << '}' << std::endl;
    }
    virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	ret << "WHERE" << std::endl;
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
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

    virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
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
    virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	lead();
	ret << "ASK ";
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
    }
    virtual void replace (const Replace* const, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	lead();
	ret << "REPLACE ";
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
    }
    virtual void insert (const Insert* const self, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "INSERT { ";
	if (debug & DEBUG_graphs) ret << self << ' ';
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	ret << "}" << std::endl;
    }
    virtual void del (const Delete* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "DELETE { ";
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	ret << "}" << std::endl;
    }
    virtual void load (const Load* const, ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) {
	lead();
	ret << "LOAD ";
	p_IRIrefs->express(this);
	p_into->express(this);
    }
    virtual void clear (const Clear* const, const URI* p__QGraphIRI_E_Opt) {
	lead();
	ret << "CLEAR ";
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
    virtual void posExpression (const POSExpression* const, const POS* p_POS) {
	p_POS->express(this);
    }
    virtual void argList (const ArgList* const, ProductionVector<const Expression*>* expressions) {
	expressions->express(this);
    }
    virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {

	if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-str"))
	    ret << "str";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-lang"))
	    ret << "lang";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"))
	    ret << "langMatches";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"))
	    ret << "datatype";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-bound"))
	    ret << "bound";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"))
	    ret << "sameTerm";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"))
	    ret << "isIRI";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"))
	    ret << "isIRI";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"))
	    ret << "isBlank";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"))
	    ret << "isLiteral";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-count"))
	    ret << "count";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-sum"))
	    ret << "sum";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-min"))
	    ret << "min";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-max"))
	    ret << "max";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-avg"))
	    ret << "avg";
	else if (p_IRIref->matches("http://www.w3.org/TR/rdf-sparql-query/#func-group_concat"))
	    ret << "group_concat";
	else
	    p_IRIref->express(this);
	ret << "(";
	p_ArgList->express(this);
	ret << ")";
    }
    virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
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

