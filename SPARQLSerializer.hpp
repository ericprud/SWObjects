/* SPARQLSerializer.hpp - simple SPARQL serializer for SPARQL compile trees.
 *
 * $Id: SPARQLSerializer.hpp,v 1.10 2008-11-13 20:53:54 eric Exp $
 */

#ifndef SPARQLSerializer_H
#define SPARQLSerializer_H

namespace w3c_sw {

class SPARQLSerializer : public Expressor {
public:
    typedef enum { DEBUG_none, DEBUG_graphs } e_DEBUG;
protected:
    std::stringstream ret;
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
    SPARQLSerializer (const char* p_tab = "  ", e_DEBUG debug = DEBUG_none, const char* leadStr = "") : 
	tab(p_tab), debug(debug), depth(0), precStack(), leadStr(leadStr)
    { precStack.push(PREC_High); }
    std::string getSPARQLstring () { return ret.str(); }
    //!!!
    virtual void base (Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual void uri (URI*, std::string terminal) {
	ret << '<' << terminal << '>';
    }
    virtual void variable (Variable*, std::string terminal) {
	ret << '?' << terminal;
    }
    virtual void bnode (BNode*, std::string terminal) {
	ret << "_:" << terminal; // rewrite when combining named BNodes from multiple docs?
    }
    virtual void rdfLiteral (RDFLiteral*, std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	ret << '"' << terminal << '"';
	if (datatype != NULL) { ret << "^^<" << datatype->getTerminal() << '>'; }
	if (p_LANGTAG != NULL) { ret << '@' << p_LANGTAG->getTerminal(); }
	ret << ' ';
    }
    virtual void rdfLiteral (NumericRDFLiteral*, int p_value) {
	ret << p_value << ' ';
    }
    virtual void rdfLiteral (NumericRDFLiteral*, float p_value) {
	ret << p_value << ' ';
    }
    virtual void rdfLiteral (NumericRDFLiteral*, double p_value) {
	ret << p_value << ' ';
    }
    virtual void rdfLiteral (BooleanRDFLiteral*, bool p_value) {
	ret << (p_value ? "true" : "false") << ' ';
    }
    virtual void nullpos (NULLpos*) {
	ret << "NULL ";
    }
    virtual void triplePattern (TriplePattern*, POS* p_s, POS* p_p, POS* p_o) {
	lead();
	p_s->express(this);
	ret << ' ';
	p_p->express(this);
	ret << ' ';
	p_o->express(this);
	ret << " ." << std::endl;
    }
    virtual void filter (Filter*, Expression* p_Constraint) {
	lead();
	ret << "FILTER ";
	p_Constraint->express(this);
	ret << std::endl;
    }
    void _BasicGraphPattern (BasicGraphPattern* self, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters, bool p_allOpts) {
	lead();
	ret << '{';
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
	depth++;
	if (p_allOpts)
	    for (std::vector<TriplePattern*>::iterator triple = p_TriplePatterns->begin();
		 triple != p_TriplePatterns->end(); triple++) {
		lead(); ret << "optional {" << std::endl << "  ";
		depth++;
		(*triple)->express(this);
		depth--;
		lead(); ret << "}" << std::endl;;
	    }
	else
	    p_TriplePatterns->express(this);
	p_Filters->express(this);
	depth--;
	lead();
	ret << '}' << std::endl;
    }
    virtual void namedGraphPattern (NamedGraphPattern* self, POS*, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	_BasicGraphPattern(self, p_TriplePatterns, p_Filters, p_allOpts);
    }
    virtual void defaultGraphPattern (DefaultGraphPattern* self, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	_BasicGraphPattern(self, p_TriplePatterns, p_Filters, p_allOpts);
    }
    virtual void tableDisjunction (TableDisjunction* self, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	lead();
	ret << '{';
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
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
    }
    virtual void tableConjunction (TableConjunction* self, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	lead();
	ret << '{';
	if (debug & DEBUG_graphs) ret << ' ' << self;
	ret << std::endl;
	depth++;
	p_TableOperations->express(this);
	p_Filters->express(this);
	depth--;
	lead();
	ret << '}' << std::endl;
    }
    virtual void optionalGraphPattern (OptionalGraphPattern* self, TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "OPTIONAL ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void graphGraphPattern (GraphGraphPattern* self, POS* p_POS, TableOperation* p_GroupGraphPattern) {
	lead();
	ret << "GRAPH ";
	if (debug & DEBUG_graphs) ret << ' ' << self;
	p_POS->express(this);
	ret << std::endl;
	depth++;
	p_GroupGraphPattern->express(this);
	depth--;
    }
    virtual void posList (POSList*, ProductionVector<POS*>* p_POSs) {
	for (size_t i = 0; i < p_POSs->size(); i++) {
	    p_POSs->at(i)->express(this);
	    ret << ' ';
	}
    }
    virtual void starVarSet (StarVarSet*) {
	ret << "* ";
    }
    virtual void defaultGraphClause (DefaultGraphClause*, POS* p_IRIref) {
	ret << "FROM ";
	p_IRIref->express(this);
    }
    virtual void namedGraphClause (NamedGraphClause*, POS* p_IRIref) {
	ret << "FROM NAMED ";
	p_IRIref->express(this);
    }
    virtual void solutionModifier (SolutionModifier*, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	lead();
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
    virtual void binding (Binding*, ProductionVector<POS*>* values) {//!!!
	ret << "  { ";
	for (size_t i = 0; i < values->size(); i++)
	    values->at(i)->express(this);
	ret << ')' << std::endl;
    }
    virtual void bindingClause (BindingClause*, POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	ret << "BINDINGS ";
	p_Vars->express(this);
	ret << '{' << std::endl; //!!!
	p_Bindings->ProductionVector<Binding*>::express(this);
	ret << '}' << std::endl;
    }
    virtual void whereClause (WhereClause*, TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	ret << "WHERE" << std::endl;
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
    }
    virtual void select (Select*, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
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
    virtual void construct (Construct*, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "CONSTRUCT ";
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void describe (Describe*, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	lead();
	ret << "DESCRIBE ";
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void ask (Ask*, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	lead();
	ret << "ASK ";
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
    }
    virtual void replace (Replace*, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	lead();
	ret << "REPLACE ";
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
    }
    virtual void insert (Insert* self, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "INSERT { ";
	if (debug & DEBUG_graphs) ret << self << ' ';
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	ret << "}" << std::endl;
    }
    virtual void del (Delete*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	lead();
	ret << "DELETE";
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
    }
    virtual void load (Load*, ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	lead();
	ret << "LOAD ";
	p_IRIrefs->express(this);
	p_into->express(this);
    }
    virtual void clear (Clear*, URI* p__QGraphIRI_E_Opt) {
	lead();
	ret << "CLEAR ";
	p__QGraphIRI_E_Opt->express(this);
    }
    virtual void create (Create*, e_Silence p_Silence, URI* p_GraphIRI) {
	lead();
	ret << "CREATE ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_GraphIRI->express(this);
    }
    virtual void drop (Drop*, e_Silence p_Silence, URI* p_GraphIRI) {
	lead();
	ret << "DROP ";
	if (p_Silence != SILENT_Yes) ret << "SILENT";
	p_GraphIRI->express(this);
    }
    virtual void varExpression (VarExpression*, Variable* p_Variable) {
	p_Variable->express(this);
    }
    virtual void literalExpression (LiteralExpression*, RDFLiteral* p_RDFLiteral) {
	p_RDFLiteral->express(this);
    }
    virtual void booleanExpression (BooleanExpression*, BooleanRDFLiteral* p_BooleanRDFLiteral) {
	p_BooleanRDFLiteral->express(this);
    }
    virtual void uriExpression (URIExpression*, URI* p_URI) {
	p_URI->express(this);
    }
    virtual void argList (ArgList*, ProductionVector<Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
    }
    virtual void functionCall (FunctionCall*, URI* p_IRIref, ArgList* p_ArgList) {

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
	else
	    p_IRIref->express(this);
	ret << "(";
	p_ArgList->express(this);
	ret << ")";
    }
    virtual void functionCallExpression (FunctionCallExpression*, FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
    }
/* Expressions */
    virtual void booleanNegation (BooleanNegation*, Expression* p_Expression) {
	start(PREC_Not);
	ret << '!';
	p_Expression->express(this);
	end();
    }
    virtual void arithmeticNegation (ArithmeticNegation*, Expression* p_Expression) {
	start(PREC_Neg);
	ret << "- ";
	p_Expression->express(this);
	end();
    }
    virtual void arithmeticInverse (ArithmeticInverse*, Expression* p_Expression) {
	start(PREC_Divide);
	ret << "1/";
	p_Expression->express(this);
	end();
    }
    virtual void booleanConjunction (BooleanConjunction*, ProductionVector<Expression*>* p_Expressions) {
	start(PREC_And);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " && ";
	}
	end();
    }
    virtual void booleanDisjunction (BooleanDisjunction*, ProductionVector<Expression*>* p_Expressions) {
	start(PREC_Or);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " || ";
	}
	end();
    }
    virtual void arithmeticSum (ArithmeticSum*, ProductionVector<Expression*>* p_Expressions) {
	start(PREC_Plus);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " + ";
	}
	end();
    }
    virtual void arithmeticProduct (ArithmeticProduct*, ProductionVector<Expression*>* p_Expressions) {
	start(PREC_Times);
	for (size_t i = 0; i < p_Expressions->size(); i++) {
	    p_Expressions->at(i)->express(this);
	    if (i < p_Expressions->size() - 1)
		ret << " * ";
	}
	end();
    }
    virtual void booleanEQ (BooleanEQ*, Expression* p_left, Expression* p_right) {
	start(PREC_EQ);
	p_left->express(this);
	ret << " = ";
	p_right->express(this);
	end();
    }
    virtual void booleanNE (BooleanNE*, Expression* p_left, Expression* p_right) {
	start(PREC_NE);
	p_left->express(this);
	ret << " != ";
	p_right->express(this);
	end();
    }
    virtual void booleanLT (BooleanLT*, Expression* p_left, Expression* p_right) {
	start(PREC_LT);
	p_left->express(this);
	ret << " < ";
	p_right->express(this);
	end();
    }
    virtual void booleanGT (BooleanGT*, Expression* p_left, Expression* p_right) {
	start(PREC_GT);
	p_left->express(this);
	ret << " > ";
	p_right->express(this);
	end();
    }
    virtual void booleanLE (BooleanLE*, Expression* p_left, Expression* p_right) {
	start(PREC_LE);
	p_left->express(this);
	ret << " <= ";
	p_right->express(this);
	end();
    }
    virtual void booleanGE (BooleanGE*, Expression* p_left, Expression* p_right) {
	start(PREC_GE);
	p_left->express(this);
	ret << " >= ";
	p_right->express(this);
	end();
    }
    virtual void comparatorExpression (ComparatorExpression*, BooleanComparator* p_BooleanComparator) {
	p_BooleanComparator->express(this);
    }
    virtual void numberExpression (NumberExpression*, NumericRDFLiteral* p_NumericRDFLiteral) {
	p_NumericRDFLiteral->express(this);
    }
};

}

#endif // SPARQLSerializer_H

