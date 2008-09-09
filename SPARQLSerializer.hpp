/* SPARQLSerializer.hpp - simple SPARQL serializer for SPARQL compile trees.
 *
 * $Id: SPARQLSerializer.hpp,v 1.3 2008-09-09 09:35:27 eric Exp $
 */

#ifndef SPARQLSerializer_H
#define SPARQLSerializer_H

namespace w3c_sw {

class SPARQLSerializer : public Expressor {
    std::stringstream ret;
    typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		  PREC_And, 
		  PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		  PREC_Plus, PREC_Minus, 
		  PREC_Times, PREC_Divide, 
		  PREC_Not, PREC_Pos, PREC_Neg, PREC_High = PREC_Neg} e_PREC;
    const char* tab;
    size_t depth;
    std::stack<e_PREC> precStack;
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
	for (size_t i = 0; i < depth; i++)
	    ret << tab;
    }
    void lead (size_t p_depth) {
	for (size_t i = 0; i < p_depth; i++)
	    ret << tab;
    }
public:
    SPARQLSerializer (const char* p_tab = "  ") : tab(p_tab), depth(0), precStack() { precStack.push(PREC_High); }
    std::string getSPARQLstring () { return ret.str(); }
    //!!!
    virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual URI* uri (std::string terminal) {
	ret << '<' << terminal << '>';
	return NULL;
    }
    virtual Variable* variable (std::string terminal) {
	ret << '?' << terminal;
	return NULL;
    }
    virtual BNode* bnode (std::string terminal) {
	ret << "_:" << terminal; // rewrite when combining named BNodes from multiple docs?
	return NULL;
    }
    virtual RDFLiteral* rdfLiteral (std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	ret << '"' << terminal << '"';
	if (datatype != NULL) { ret << "^^<" << datatype->getTerminal() << '>'; }
	if (p_LANGTAG != NULL) { ret << '@' << p_LANGTAG->getTerminal(); }
	ret << ' ';
	return NULL;
    }
    virtual NumericRDFLiteral* rdfLiteral (int p_value) {
	ret << p_value << ' ';
	return NULL;
    }
    virtual NumericRDFLiteral* rdfLiteral (float p_value) {
	ret << p_value << ' ';
	return NULL;
    }
    virtual NumericRDFLiteral* rdfLiteral (double p_value) {
	ret << p_value << ' ';
	return NULL;
    }
    virtual BooleanRDFLiteral* rdfLiteral (bool p_value) {
	ret << (p_value ? "true" : "false") << ' ';
	return NULL;
    }
    virtual NULLpos* nullpos () {
	ret << "NULL ";
	return NULL;
    }
    virtual TriplePattern* triplePattern (POS* p_s, POS* p_p, POS* p_o) {
	lead();
	p_s->express(this);
	ret << ' ';
	p_p->express(this);
	ret << ' ';
	p_o->express(this);
	ret << " ." << std::endl;
	return NULL;
    }
    virtual Filter* filter (Expression* p_Constraint) {
	lead();
	ret << "FILTER ";
	p_Constraint->express(this);
	ret << std::endl;
	return NULL;
    }
    void _BasicGraphPattern (ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	lead();
	ret << '{' << std::endl;
	depth++;
	p_TriplePatterns->express(this);
	p_Filters->express(this);
	depth--;
	lead();
	ret << '}' << std::endl;
    }
    virtual NamedGraphPattern* namedGraphPattern (POS*, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	_BasicGraphPattern(p_TriplePatterns, p_Filters);
	return NULL;
    }
    virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	_BasicGraphPattern(p_TriplePatterns, p_Filters);
	return NULL;
    }
    virtual TableDisjunction* tableDisjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	lead();
	ret << '{' << std::endl;
	depth++;
	for (size_t i = 0; i < p_TableOperations->size(); i++) {
	    p_TableOperations->at(i)->express(this);
	    if (i < p_TableOperations->size() - 1) {
		lead(depth - 1);
		ret << "UNION" << std::endl;
	    }
	}
	p_Filters->express(this);
	depth--;
	lead();
	ret << '}' << std::endl;
	return NULL;
    }
    virtual TableConjunction* tableConjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	lead();
	ret << '{' << std::endl;
	depth++;
	p_TableOperations->express(this);
	p_Filters->express(this);
	depth--;
	lead();
	ret << '}' << std::endl;
	return NULL;
    }
    virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "OPTIONAL ";
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
	return NULL;
    }
    virtual GraphGraphPattern* graphGraphPattern (POS* p_POS, TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "GRAPH ";
	p_POS->express(this);
	ret << std::endl;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
	return NULL;
    }
    virtual POSList* posList (ProductionVector<POS*>* p_POSs) {
	for (size_t i = 0; i < p_POSs->size(); i++) {
	    p_POSs->at(i)->express(this);
	    ret << ' ';
	}
	return NULL;
    }
    virtual StarVarSet* starVarSet () {
	ret << "* ";
	return NULL;
    }
    virtual DefaultGraphClause* defaultGraphClause (POS* p_IRIref) {
	ret << "FROM ";
	p_IRIref->express(this);
	return NULL;
    }
    virtual NamedGraphClause* namedGraphClause (POS* p_IRIref) {
	ret << "FROM NAMED ";
	p_IRIref->express(this);
	return NULL;
    }
    virtual SolutionModifier* solutionModifier (std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	if (p_limit != LIMIT_None) ret << "LIMIT " << p_limit;
	if (p_offset != OFFSET_None) ret << "OFFSET " << p_offset;
	if (p_OrderConditions) {
	    ret << "ORDER BY ";
	    for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		if (p_OrderConditions->at(i).ascOrDesc == ORDER_Desc) ret << "DESC ";
		p_OrderConditions->at(i).expression->express(this);
	    }
	}
	return NULL;
    }
    virtual Binding* binding (ProductionVector<POS*>* values) {//!!!
	ret << "  { ";
	for (size_t i = 0; i < values->size(); i++)
	    values->at(i)->express(this);
	ret << ')' << std::endl;
	return NULL;
    }
    virtual BindingClause* bindingClause (POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	ret << "BINDINGS ";
	p_Vars->express(this);
	ret << '{' << std::endl; //!!!
	p_Bindings->ProductionVector<Binding*>::express(this);
	ret << '}' << std::endl;
	return NULL;
    }
    virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	ret << "WHERE" << std::endl;
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
	return NULL;
    }
    virtual Select* select (e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	ret << "SELECT ";
	if (p_distinctness == DIST_distinct) ret << "DISTINCT ";
	if (p_distinctness == DIST_reduced) ret << "REDUCED ";
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	ret << std::endl;
	lead();
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	return NULL;
    }
    virtual Construct* construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	ret << "CONSTRUCT ";
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	return NULL;
    }
    virtual Describe* describe (VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	ret << "DESCRIBE ";
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	return NULL;
    }
    virtual Ask* ask (ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	ret << "ASK ";
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	return NULL;
    }
    virtual Replace* replace (WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	ret << "REPLACE ";
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
	return NULL;
    }
    virtual Insert* insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	ret << "INSERT { ";
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	ret << "}" << std::endl;
	return NULL;
    }
    virtual Delete* del (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	ret << "DELETE";
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
	return NULL;
    }
    virtual Load* load (ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	ret << "LOAD ";
	p_IRIrefs->express(this);
	p_into->express(this);
	return NULL;
    }
    virtual Clear* clear (URI* p__QGraphIRI_E_Opt) {
	ret << "CLEAR ";
	p__QGraphIRI_E_Opt->express(this);
	return NULL;
    }
    virtual Create* create (e_Silence p_Silence, URI* p_GraphIRI) {
	ret << "CREATE ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_GraphIRI->express(this);
	return NULL;
    }
    virtual Drop* drop (e_Silence p_Silence, URI* p_GraphIRI) {
	ret << "DROP ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_GraphIRI->express(this);
	return NULL;
    }
    virtual VarExpression* varExpression (Variable* p_Variable) {
	p_Variable->express(this);
	return NULL;
    }
    virtual LiteralExpression* literalExpression (RDFLiteral* p_RDFLiteral) {
	p_RDFLiteral->express(this);
	return NULL;
    }
    virtual BooleanExpression* booleanExpression (BooleanRDFLiteral* p_BooleanRDFLiteral) {
	p_BooleanRDFLiteral->express(this);
	return NULL;
    }
    virtual URIExpression* uriExpression (URI* p_URI) {
	p_URI->express(this);
	return NULL;
    }
    virtual ArgList* argList (ProductionVector<Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
	return NULL;
    }
    virtual FunctionCall* functionCall (URI* p_IRIref, ArgList* p_ArgList) {
	p_IRIref->express(this);
	ret << "(";
	p_ArgList->express(this);
	ret << ")";
	return NULL;
    }
    virtual FunctionCallExpression* functionCallExpression (FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
	return NULL;
    }
/* Expressions */
    virtual BooleanNegation* booleanNegation (Expression* p_Expression) {
	start(PREC_Not);
	ret << '!';
	p_Expression->express(this);
	end();
	return NULL;
    }
    virtual ArithmeticNegation* arithmeticNegation (Expression* p_Expression) {
	start(PREC_Neg);
	ret << "- ";
	p_Expression->express(this);
	end();
	return NULL;
    }
    virtual ArithmeticInverse* arithmeticInverse (Expression* p_Expression) {
	start(PREC_Divide);
	ret << "1/";
	p_Expression->express(this);
	end();
	return NULL;
    }
    virtual BooleanConjunction* booleanConjunction (ProductionVector<Expression*>* p_Expressions) {
	start(PREC_And);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " && ";
	}
	end();
	return NULL;
    }
    virtual BooleanDisjunction* booleanDisjunction (ProductionVector<Expression*>* p_Expressions) {
	start(PREC_Or);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " || ";
	}
	end();
	return NULL;
    }
    virtual ArithmeticSum* arithmeticSum (ProductionVector<Expression*>* p_Expressions) {
	start(PREC_Plus);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " + ";
	}
	end();
	return NULL;
    }
    virtual ArithmeticProduct* arithmeticProduct (ProductionVector<Expression*>* p_Expressions) {
	start(PREC_Times);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " * ";
	}
	end();
	return NULL;
    }
    virtual BooleanEQ* booleanEQ (Expression* p_left, Expression* p_right) {
	start(PREC_EQ);
	p_left->express(this);
	ret << " = ";
	p_right->express(this);
	end();
	return NULL;
    }
    virtual BooleanNE* booleanNE (Expression* p_left, Expression* p_right) {
	start(PREC_NE);
	p_left->express(this);
	ret << " != ";
	p_right->express(this);
	end();
	return NULL;
    }
    virtual BooleanLT* booleanLT (Expression* p_left, Expression* p_right) {
	start(PREC_LT);
	p_left->express(this);
	ret << " < ";
	p_right->express(this);
	end();
	return NULL;
    }
    virtual BooleanGT* booleanGT (Expression* p_left, Expression* p_right) {
	start(PREC_GT);
	p_left->express(this);
	ret << " > ";
	p_right->express(this);
	end();
	return NULL;
    }
    virtual BooleanLE* booleanLE (Expression* p_left, Expression* p_right) {
	start(PREC_LE);
	p_left->express(this);
	ret << " <= ";
	p_right->express(this);
	end();
	return NULL;
    }
    virtual BooleanGE* booleanGE (Expression* p_left, Expression* p_right) {
	start(PREC_GE);
	p_left->express(this);
	ret << " >= ";
	p_right->express(this);
	end();
	return NULL;
    }
    virtual ComparatorExpression* comparatorExpression (BooleanComparator* p_BooleanComparator) {
	p_BooleanComparator->express(this);
	return NULL;
    }
    virtual NumberExpression* numberExpression (NumericRDFLiteral* p_NumericRDFLiteral) {
	p_NumericRDFLiteral->express(this);
	return NULL;
    }
};

}

#endif // SPARQLSerializer_H

