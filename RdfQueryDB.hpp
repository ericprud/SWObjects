/* RdfQueryDB - sets of variable bindings and their proofs.
 * $Id: RdfQueryDB.hpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#ifndef RDF_QUERY_DB_H
#define RDF_QUERY_DB_H

#include "RdfDB.hpp"

namespace w3c_sw {
    class DBExpressor;
    class RdfQueryDB : public RdfDB {
	friend class DBExpressor;
	Operation* op;
	TableOperation* top;

    public:
	RdfQueryDB (Operation* p_op); // deprecate
	RdfQueryDB (TableOperation* p_op);
    };
    class DBExpressor : public RecursiveExpressor {
    protected:
	RdfQueryDB* db;
	bool optState;
    public:
	DBExpressor (RdfQueryDB* p_db) : db(p_db), optState(false) {  }
	virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual Filter* filter (Expression*) { // p_Constraint
	    return NULL;
	}
	void _absorbGraphPattern (BasicGraphPattern* g, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>*) {  // p_Filters
	    for (std::vector<TriplePattern*>::iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)
		g->addTriplePattern(new TriplePattern(**it, optState));
	}
	virtual NamedGraphPattern* namedGraphPattern (POS* p_IRIref, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    _absorbGraphPattern(db->assureGraph(p_IRIref), p_TriplePatterns, p_Filters);
	    return NULL;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    _absorbGraphPattern(db->assureGraph(DefaultGraph), p_TriplePatterns, p_Filters);
	    return NULL;
	}
	virtual TableDisjunction* tableDisjunction (ProductionVector<TableOperation*>*, ProductionVector<Filter*>*) { // p_TableOperations p_Filters
	    throw(std::runtime_error(__PRETTY_FUNCTION__)); // query should already be DNF'd, ergo no disjunctions.
	}
	virtual TableConjunction* tableConjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    p_TableOperations->express(this);
	    p_Filters->express(this);
	    return NULL;
	}
	virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
	    bool oldOptState = optState;
	    optState = true;
	    p_GroupGraphPattern->express(this);
	    optState = oldOptState;
	    return NULL;
	}
#if 0
	virtual POSList* posList (ProductionVector<POS*>*) { // p_POSs
	    return NULL;
	}
	virtual StarVarSet* starVarSet () { 
	    return NULL;
	}
	virtual NamedGraphClause* namedGraphClause (POS*) {
	    return NULL;
	}
	virtual SolutionModifier* solutionModifier (std::vector<s_OrderConditionPair>*, int, int) {
	    return NULL;
	}
	virtual Binding* binding (ProductionVector<POS*>*) {
	    return NULL;
	}
	virtual BindingClause* bindingClause (POSList*, ProductionVector<Binding*>*) {
	    return NULL;
	}
	virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    if (p_BindingClause) p_BindingClause->express(this);
	    p_GroupGraphPattern->express(this);
	    return NULL;
	}
	virtual Select* select (e_distinctness, VarSet*, ProductionVector<DatasetClause*>*, WhereClause* p_WhereClause, SolutionModifier*) { // p_POS p_GroupGraphPattern p_WhereClause p_SolutionModifier
	    p_WhereClause->express(this);
	    return NULL;
	}
	virtual Construct* construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>*, WhereClause* p_WhereClause, SolutionModifier*) { // p_ConstructTemplate p_DatasetClauses p_WhereClause p_SolutionModifier
	    p_WhereClause->express(this);
	    p_ConstructTemplate->express(this);
	    return NULL;
	}
	virtual Describe* describe (VarSet*, ProductionVector<DatasetClause*>*, WhereClause*, SolutionModifier*) {
	    return NULL;
	}
	virtual Ask* ask (ProductionVector<DatasetClause*>*, WhereClause* p_WhereClause) { // p_DatasetClauses
	    p_WhereClause->express(this);
	    return NULL;
	}
	virtual Replace* replace (WhereClause* p_WhereClause, TableOperation*  p_GraphTemplate) { // p_WhereClause p_GraphTemplate
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    return NULL;
	}
	virtual Insert* insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    if (p_WhereClause) p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    return NULL;
	}
	virtual Delete* del (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    return NULL;
	}
	virtual Load* load (ProductionVector<URI*>*, URI*) {
	    return NULL;
	} // p_IRIrefs p_into
	virtual Clear* clear (URI* p__QGraphIRI_E_Opt) {
	    p__QGraphIRI_E_Opt->express(this);
	    return NULL;
	}
	virtual Create* create (e_Silence, URI* p_GraphIRI) { // p_Silence
	    p_GraphIRI->express(this);
	    return NULL;
	}
	virtual Drop* drop (e_Silence, URI* p_GraphIRI) { // p_Silence
	    p_GraphIRI->express(this);
	    return NULL;
	}
	virtual VarExpression* varExpression (Variable*) {
	    return NULL;
	}
	virtual LiteralExpression* literalExpression (RDFLiteral*) {
	    return NULL;
	}
	virtual BooleanExpression* booleanExpression (BooleanRDFLiteral*) {
	    return NULL;
	}
	virtual URIExpression* uriExpression (URI*) {
	    return NULL;
	}
	virtual ArgList* argList (ProductionVector<Expression*>*) {
	    return NULL;
	}
	virtual FunctionCall* functionCall (URI*, ArgList*) {
	    return NULL;
	}
	virtual FunctionCallExpression* functionCallExpression (FunctionCall*) {
	    return NULL;
	}
	/* Expressions */
	virtual BooleanNegation* booleanNegation (Expression*) {
	    return NULL;
	}
	virtual ArithmeticNegation* arithmeticNegation (Expression*) {
	    return NULL;
	}
	virtual ArithmeticInverse* arithmeticInverse (Expression*) {
	    return NULL;
	}
	virtual BooleanConjunction* booleanConjunction (ProductionVector<Expression*>*) {
	    return NULL;
	}
	virtual BooleanDisjunction* booleanDisjunction (ProductionVector<Expression*>*) {
	    return NULL;
	}
	virtual ArithmeticSum* arithmeticSum (ProductionVector<Expression*>*) {
	    return NULL;
	}
	virtual ArithmeticProduct* arithmeticProduct (ProductionVector<Expression*>*) {
	    return NULL;
	}
	virtual BooleanEQ* booleanEQ (Expression*, Expression*) {
	    return NULL;
	}
	virtual BooleanNE* booleanNE (Expression*, Expression*) {
	    return NULL;
	}
	virtual BooleanLT* booleanLT (Expression*, Expression*) {
	    return NULL;
	}
	virtual BooleanGT* booleanGT (Expression*, Expression*) {
	    return NULL;
	}
	virtual BooleanLE* booleanLE (Expression*, Expression*) {
	    return NULL;
	}
	virtual BooleanGE* booleanGE (Expression*, Expression*) {
	    return NULL;
	}
	virtual ComparatorExpression* comparatorExpression (BooleanComparator*) {
	    return NULL;
	}
	virtual NumberExpression* numberExpression (NumericRDFLiteral*) {
	    return NULL;
	}
#endif
    };

} // namespace w3c_sw

#endif // !RDF_QUERY_DB_H

