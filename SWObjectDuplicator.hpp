/* SWObjectDuplicator.hpp - simple SPARQL duplicator for SPARQL compile trees.
 *
 * $Id: SWObjectDuplicator.hpp,v 1.2 2008-08-27 02:21:42 eric Exp $
 */

#ifndef SWObjectDuplicator_H
#define SWObjectDuplicator_H

#include "SWObjects.hpp"

namespace w3c_sw {

    class SWObjectDuplicator : public Expressor {
    protected:
	POSFactory* posFactory;
	Operation* p_Operation;
    public:
	SWObjectDuplicator (POSFactory* posFactory) : posFactory(posFactory) {  }
	Operation* getCopy () { return p_Operation; }
	//!!!
	virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual URI* uri (std::string terminal) {
	    return posFactory->getURI(terminal.c_str());
	}
	virtual Variable* variable (std::string terminal) {
	    return posFactory->getVariable(terminal.c_str());
	}
	virtual BNode* bnode (std::string terminal) {
	    return posFactory->getBNode(terminal.c_str());
	}
	virtual RDFLiteral* rdfLiteral (std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	    return posFactory->getRDFLiteral(terminal.c_str(), datatype, p_LANGTAG);
	}
	virtual NumericRDFLiteral* rdfLiteral (int p_value) {
	    std::stringstream s;
	    s << p_value;
	    return posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	}
	virtual NumericRDFLiteral* rdfLiteral (float p_value) {
	    std::stringstream s;
	    s << p_value;
	    return posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	}
	virtual NumericRDFLiteral* rdfLiteral (double p_value) {
	    std::stringstream s;
	    s << p_value;
	    return posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	}
	virtual BooleanRDFLiteral* rdfLiteral (bool p_value) {
	    return posFactory->getBooleanRDFLiteral(p_value ? "true" : "false", p_value);
	}
	virtual NULLpos* nullpos () {
	    return posFactory->getNULL();
	}
	virtual TriplePattern* triplePattern (POS* p_s, POS* p_p, POS* p_o) {
	    return new TriplePattern(p_s->express(this), p_p->express(this), p_o->express(this));
	}
	virtual Filter* filter (Expression* p_Constraint) {
	    return new Filter(p_Constraint->express(this));
	}
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (ProductionVector<TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
	    for (std::vector<TriplePattern*>::iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)		
		p->addTriplePattern((*it)->express(this));
	}
	void _Filters (ProductionVector<Filter*>* p_Filters, TableOperation* op) {
	    for (std::vector<Filter*>::iterator it = p_Filters->begin();
		 it != p_Filters->end(); it++)
		op->addFilter((*it)->express(this));
	}
	virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    NamedGraphPattern* ret = new NamedGraphPattern(p_name->express(this));
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern();
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
	    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++)
		j->addTableOperation((*it)->express(this));
	}
	virtual TableDisjunction* tableDisjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    TableDisjunction* ret = new TableDisjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	virtual TableConjunction* tableConjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    TableConjunction* ret = new TableConjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
	    return new OptionalGraphPattern(p_GroupGraphPattern->express(this));
	}
	virtual GraphGraphPattern* graphGraphPattern (POS* p_POS, TableOperation* p_GroupGraphPattern) {
	    return new GraphGraphPattern(p_POS->express(this), p_GroupGraphPattern->express(this));
	}
	void _POSs (ProductionVector<POS*>* p_POSs, POSList* p) { // !!! single use
	    for (std::vector<POS*>::iterator it = p_POSs->begin();
		 it != p_POSs->end(); it++)
		p->push_back((*it)->express(this));
	}
	virtual POSList* posList (ProductionVector<POS*>* p_POSs) {
	    POSList* ret = new POSList();
	    _POSs(p_POSs, ret);
	    return ret;
	}
	virtual StarVarSet* starVarSet () {
	    return new StarVarSet();
	}
	virtual DefaultGraphClause* defaultGraphClause (POS* p_IRIref) {
	    return new DefaultGraphClause(p_IRIref->express(this), posFactory);
	}
	virtual NamedGraphClause* namedGraphClause (POS* p_IRIref) {
	    return new NamedGraphClause(p_IRIref->express(this), posFactory);
	}
	virtual SolutionModifier* solutionModifier (std::vector<s_OrderConditionPair>* p_OrderConditionPairs, int p_limit, int p_offset) {
	    if (p_OrderConditionPairs) {
		std::vector<s_OrderConditionPair>* l_s_OrderConditionPairs = new std::vector<s_OrderConditionPair>();
		for (std::vector<s_OrderConditionPair>::iterator it = p_OrderConditionPairs->begin();
		     it != p_OrderConditionPairs->end(); it++) {
		    s_OrderConditionPair pair;
		    pair.ascOrDesc = (*it).ascOrDesc;
		    pair.expression = (*it).expression->express(this);
		    l_s_OrderConditionPairs->push_back(pair);
		}
		return new SolutionModifier(l_s_OrderConditionPairs, p_limit, p_offset);
	    } else {
		return new SolutionModifier(NULL, p_limit, p_offset);
	    }
	}
	virtual Binding* binding (ProductionVector<POS*>* values) {//!!!
	    Binding* ret = new Binding();
	    for (std::vector<POS*>::iterator it = values->begin();
		 it != values->end(); it++)
		ret->push_back((*it)->express(this));
	    return ret;
	}
	virtual BindingClause* bindingClause (POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	    BindingClause* ret = new BindingClause(p_Vars->express(this));
	    for (std::vector<Binding*>::iterator it = p_Bindings->begin();
		 it != p_Bindings->end(); it++)
		ret->push_back((*it)->express(this));
	    return ret;
	}
	virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    return new WhereClause(p_GroupGraphPattern->express(this), p_BindingClause ? p_BindingClause->express(this) : NULL);
	}
	ProductionVector<DatasetClause*>* _DatasetClauses (ProductionVector<DatasetClause*>* p_DatasetClauses) {
	    ProductionVector<DatasetClause*>* l_DatasetClauses = new ProductionVector<DatasetClause*>();
	    for (std::vector<DatasetClause*>::iterator it = p_DatasetClauses->begin();
		 it != p_DatasetClauses->end(); it++)
		l_DatasetClauses->push_back((*it)->express(this));
	    return l_DatasetClauses;
	}
	/* Operations */
	virtual Select* select (e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    return new Select(p_distinctness, p_VarSet->express(this), _DatasetClauses(p_DatasetClauses), p_WhereClause->express(this), p_SolutionModifier->express(this));
	}
	virtual Construct* construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    return new Construct(p_ConstructTemplate->express(this), _DatasetClauses(p_DatasetClauses), p_WhereClause->express(this), p_SolutionModifier->express(this));
	}
	virtual Describe* describe (VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    return new Describe(p_VarSet->express(this), _DatasetClauses(p_DatasetClauses), p_WhereClause->express(this), p_SolutionModifier->express(this));
	}
	virtual Ask* ask (ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    return new Ask(_DatasetClauses(p_DatasetClauses), p_WhereClause->express(this));
	}
	virtual Replace* replace (WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    return new Replace(p_WhereClause->express(this), p_GraphTemplate->express(this));
	}
	virtual Insert* insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    return new Insert(p_GraphTemplate->express(this), p_WhereClause ? p_WhereClause->express(this) : NULL);
	}
	virtual Delete* del (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    return new Delete(p_GraphTemplate->express(this), p_WhereClause->express(this));
	}
	virtual Load* load (ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	    ProductionVector<URI*>* l_URIs = new ProductionVector<URI*>();
	    for (std::vector<URI*>::iterator it = p_IRIrefs->begin();
		 it != p_IRIrefs->end(); it++)
		l_URIs->push_back((*it)->express(this));
	    p_into->express(this);
	    return new Load(l_URIs, p_into->express(this));
	}
	virtual Clear* clear (URI* p__QGraphIRI_E_Opt) {
	    return new Clear(p__QGraphIRI_E_Opt ? p__QGraphIRI_E_Opt->express(this) : NULL);
	}
	virtual Create* create (e_Silence p_Silence, URI* p_GraphIRI) {
	    return new Create(p_Silence, p_GraphIRI->express(this));
	}
	virtual Drop* drop (e_Silence p_Silence, URI* p_GraphIRI) {
	    return new Drop(p_Silence, p_GraphIRI->express(this));
	}
	/* Expressions */
	virtual VarExpression* varExpression (Variable* p_Variable) {
	    return new VarExpression(p_Variable->express(this));
	}
	virtual LiteralExpression* literalExpression (RDFLiteral* p_RDFLiteral) {
	    return new LiteralExpression(p_RDFLiteral->express(this));
	}
	virtual BooleanExpression* booleanExpression (BooleanRDFLiteral* p_BooleanRDFLiteral) {
	    return new BooleanExpression(p_BooleanRDFLiteral->express(this));
	}
	virtual URIExpression* uriExpression (URI* p_URI) {
	    return new URIExpression(p_URI->express(this));
	}
	ProductionVector<Expression*>* _Expressions (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* l_Expressions = new ProductionVector<Expression*>();
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++)
		l_Expressions->push_back((*it)->express(this));
	    return l_Expressions;
	}
	virtual ArgList* argList (ProductionVector<Expression*>* p_expressions) {
	    return new ArgList(_Expressions(p_expressions));
	}
	virtual FunctionCall* functionCall (URI* p_IRIref, ArgList* p_ArgList) {
	    return new FunctionCall(p_IRIref->express(this), p_ArgList->express(this));
	}
	virtual FunctionCallExpression* functionCallExpression (FunctionCall* p_FunctionCall) {
	    return new FunctionCallExpression(p_FunctionCall->express(this));
	}
	/* Expressions */
	virtual BooleanNegation* booleanNegation (Expression* p_Expression) {
	    return new BooleanNegation(p_Expression->express(this));
	}
	/*	typedef struct {
	    Expression* first
	    ProductionVector<Expression*>* rest;
	    } _Car; */
	Expression* _car(ProductionVector<Expression*>* p_Expressions) {
	    Expression* ret = p_Expressions->at(0);
	    p_Expressions->erase(p_Expressions->begin());
	    return ret;
	}
	virtual BooleanConjunction* booleanConjunction (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    return new BooleanConjunction(_car(v), v);
	}
	virtual BooleanDisjunction* booleanDisjunction (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    return new BooleanDisjunction(_car(v), v);
	}
	virtual ArithmeticSum* arithmeticSum (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    return new ArithmeticSum(_car(v), v);
	}
	virtual ArithmeticNegation* arithmeticNegation (Expression* p_Expression) {
	    return new ArithmeticNegation(p_Expression->express(this));
	}
	virtual ArithmeticProduct* arithmeticProduct (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    return new ArithmeticProduct(_car(v), v);
	}
	virtual ArithmeticInverse* arithmeticInverse (Expression* p_Expression) {
	    return new ArithmeticInverse(p_Expression->express(this));
	}
	virtual BooleanEQ* booleanEQ (Expression* p_left, Expression* p_right) {
	    BooleanEQ* ret = new BooleanEQ(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual BooleanNE* booleanNE (Expression* p_left, Expression* p_right) {
	    BooleanNE* ret = new BooleanNE(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual BooleanLT* booleanLT (Expression* p_left, Expression* p_right) {
	    BooleanLT* ret = new BooleanLT(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual BooleanGT* booleanGT (Expression* p_left, Expression* p_right) {
	    BooleanGT* ret = new BooleanGT(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual BooleanLE* booleanLE (Expression* p_left, Expression* p_right) {
	    BooleanLE* ret = new BooleanLE(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual BooleanGE* booleanGE (Expression* p_left, Expression* p_right) {
	    BooleanGE* ret = new BooleanGE(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual ComparatorExpression* comparatorExpression (BooleanComparator* p_BooleanComparator) {
	    return new ComparatorExpression(p_BooleanComparator->express(this));
	}
	virtual NumberExpression* numberExpression (NumericRDFLiteral* p_NumericRDFLiteral) {
	    return new NumberExpression(p_NumericRDFLiteral->express(this));
	}
    };

} // namespace w3c_sw

#endif // SWObjectDuplicator_H

