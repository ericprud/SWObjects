/* SWObjectDuplicator.hpp - simple SPARQL duplicator for SPARQL compile trees.
 *
 * $Id: SWObjectDuplicator.hpp,v 1.2.2.1 2008-09-12 03:17:48 eric Exp $
 */

#ifndef SWObjectDuplicator_H
#define SWObjectDuplicator_H

#include "SWObjects.hpp"

namespace w3c_sw {

    class SWObjectDuplicator : public Expressor {
    protected:
	POSFactory* posFactory;

	POS* pos;
	TriplePattern* m_triplePattern;
	Expression* expression;
	Filter* m_filter;
	TableOperation* tableOperation;
	VarSet* varSet;
	DatasetClause* datasetClause;
	//ProductionVector<DatasetClause*> datasetClauses;
	SolutionModifier* m_solutionModifier;
	Binding* m_binding;
	BindingClause* m_bindingClause;
	WhereClause* m_whereClause;
	Operation* operation;
	ArgList* m_argList;
	FunctionCall* m_functionCall;

    public:
	SWObjectDuplicator (POSFactory* posFactory) : posFactory(posFactory) {  }
	Operation* getCopy () { return operation; }
	//!!!
	virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual URI* uri (std::string terminal) {
	    pos = posFactory->getURI(terminal.c_str());
	    return NULL;
	}
	virtual Variable* variable (std::string terminal) {
	    pos = posFactory->getVariable(terminal.c_str());
	    return NULL;
	}
	virtual BNode* bnode (std::string terminal) {
	    pos = posFactory->getBNode(terminal.c_str());
	    return NULL;
	}
	virtual RDFLiteral* rdfLiteral (std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	    pos = posFactory->getRDFLiteral(terminal.c_str(), datatype, p_LANGTAG);
	    return NULL;
	}
	virtual NumericRDFLiteral* rdfLiteral (int p_value) {
	    std::stringstream s;
	    s << p_value;
	    pos = posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	    return NULL;
	}
	virtual NumericRDFLiteral* rdfLiteral (float p_value) {
	    std::stringstream s;
	    s << p_value;
	    pos = posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	    return NULL;
	}
	virtual NumericRDFLiteral* rdfLiteral (double p_value) {
	    std::stringstream s;
	    s << p_value;
	    pos = posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	    return NULL;
	}
	virtual BooleanRDFLiteral* rdfLiteral (bool p_value) {
	    pos = posFactory->getBooleanRDFLiteral(p_value ? "true" : "false", p_value);
	    return NULL;
	}
	virtual NULLpos* nullpos () {
	    pos = posFactory->getNULL();
	    return NULL;
	}
	virtual TriplePattern* triplePattern (POS* p_s, POS* p_p, POS* p_o) {
	    p_s->express(this);
	    POS* s = pos;
	    p_p->express(this);
	    POS* p = pos;
	    p_o->express(this);
	    POS* o = pos;
	    m_triplePattern = new TriplePattern(s, p, o);
	    return NULL;
	}
	virtual Filter* filter (Expression* p_Constraint) {
	    p_Constraint->express(this);
	    m_filter = new Filter(expression);
	    return NULL;
	}
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (ProductionVector<TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
	    for (std::vector<TriplePattern*>::iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++) {
		(*it)->express(this);
		p->addTriplePattern(m_triplePattern);
	    }
	}
	void _Filters (ProductionVector<Filter*>* p_Filters, TableOperation* op) {
	    for (std::vector<Filter*>::iterator it = p_Filters->begin();
		 it != p_Filters->end(); it++) {
		(*it)->express(this);
		op->addFilter(m_filter);
	    }
	}
	virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    p_name->express(this);
	    NamedGraphPattern* ret = new NamedGraphPattern(pos);
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	    return NULL;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern();
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	    return NULL;
	}
	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
	    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		(*it)->express(this);
		j->addTableOperation(tableOperation);
	    }
	}
	virtual TableDisjunction* tableDisjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    TableDisjunction* ret = new TableDisjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	    return NULL;
	}
	virtual TableConjunction* tableConjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    TableConjunction* ret = new TableConjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	    return NULL;
	}
	virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
	    p_GroupGraphPattern->express(this);
	    tableOperation = new OptionalGraphPattern(tableOperation);
	    return NULL;
	}
	virtual GraphGraphPattern* graphGraphPattern (POS* p_POS, TableOperation* p_GroupGraphPattern) {
	    p_POS->express(this);
	    POS* name = pos;
	    p_GroupGraphPattern->express(this);
	    tableOperation = new GraphGraphPattern(name, tableOperation);
	    return NULL;
	}
	void _POSs (ProductionVector<POS*>* p_POSs, POSList* p) { // !!! single use
	    for (std::vector<POS*>::iterator it = p_POSs->begin();
		 it != p_POSs->end(); it++) {
		(*it)->express(this);
		p->push_back(pos);
	    }
	}
	virtual POSList* posList (ProductionVector<POS*>* p_POSs) {
	    POSList* ret = new POSList();
	    _POSs(p_POSs, ret);
	    varSet = ret;
	    return NULL;
	}
	virtual StarVarSet* starVarSet () {
	    varSet = new StarVarSet();
	    return NULL;
	}
	virtual DefaultGraphClause* defaultGraphClause (POS* p_IRIref) {
	    datasetClause = new DefaultGraphClause(p_IRIref->express(this), posFactory);
	    return NULL;
	}
	virtual NamedGraphClause* namedGraphClause (POS* p_IRIref) {
	    datasetClause = new NamedGraphClause(p_IRIref->express(this), posFactory);
	    return NULL;
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
		m_solutionModifier = new SolutionModifier(l_s_OrderConditionPairs, p_limit, p_offset);
	    } else {
		m_solutionModifier = new SolutionModifier(NULL, p_limit, p_offset);
	    }
	    return NULL;
	}
	virtual Binding* binding (ProductionVector<POS*>* values) {//!!!
	    Binding* ret = new Binding();
	    for (std::vector<POS*>::iterator it = values->begin();
		 it != values->end(); it++) {
		(*it)->express(this);
		ret->push_back(pos);
	    }
	    m_binding = ret;
	    return NULL;
	}
	virtual BindingClause* bindingClause (POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	    BindingClause* ret = new BindingClause(p_Vars->express(this));
	    for (std::vector<Binding*>::iterator it = p_Bindings->begin();
		 it != p_Bindings->end(); it++) {
		(*it)->express(this);
		ret->push_back(m_binding);
	    }
	    m_bindingClause = ret;
	    return NULL;
	}
	virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    p_GroupGraphPattern->express(this);
	    m_bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);
	    m_whereClause = new WhereClause(tableOperation, m_bindingClause);
	    return NULL;
	}
	ProductionVector<DatasetClause*>* _DatasetClauses (ProductionVector<DatasetClause*>* p_DatasetClauses) {
	    ProductionVector<DatasetClause*>* l_DatasetClauses = new ProductionVector<DatasetClause*>();
	    for (std::vector<DatasetClause*>::iterator it = p_DatasetClauses->begin();
		 it != p_DatasetClauses->end(); it++) {
		(*it)->express(this);
		l_DatasetClauses->push_back(datasetClause);
	    }
	    return l_DatasetClauses;
	}
	/* Operations */
	virtual Select* select (e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    operation = new Select(p_distinctness, varSet, _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier);
	    return NULL;
	}
	virtual Construct* construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_ConstructTemplate->express(this);
	    TableOperation* construct = tableOperation;
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    operation = new Construct(dynamic_cast<DefaultGraphPattern*>(construct), _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier);
	    return NULL;
	}
	virtual Describe* describe (VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    operation = new Describe(varSet, _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier);
	    return NULL;
	}
	virtual Ask* ask (ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    operation = new Ask(_DatasetClauses(p_DatasetClauses), m_whereClause);
	    return NULL;
	}
	virtual Replace* replace (WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    operation = new Replace(m_whereClause, tableOperation);
	    return NULL;
	}
	virtual Insert* insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    m_whereClause = NULL;
	    if (p_WhereClause != NULL)
		p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    operation = new Insert(tableOperation, m_whereClause);
	    return NULL;
	}
	virtual Delete* del (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    operation = new Delete(tableOperation, m_whereClause);
	    return NULL;
	}
	virtual Load* load (ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	    ProductionVector<URI*>* l_URIs = new ProductionVector<URI*>();
	    for (std::vector<URI*>::iterator it = p_IRIrefs->begin();
		 it != p_IRIrefs->end(); it++) {
		(*it)->express(this);
		l_URIs->push_back(dynamic_cast<URI*>(pos));
	    }
	    p_into->express(this);
	    operation = new Load(l_URIs, dynamic_cast<URI*>(pos));
	    return NULL;
	}
	virtual Clear* clear (URI* p__QGraphIRI_E_Opt) {
	    pos = NULL;
	    if (p__QGraphIRI_E_Opt != NULL)
		p__QGraphIRI_E_Opt->express(this);
	    operation = new Clear(dynamic_cast<URI*>(pos));
	    return NULL;
	}
	virtual Create* create (e_Silence p_Silence, URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    operation = new Create(p_Silence, dynamic_cast<URI*>(pos));
	    return NULL;
	}
	virtual Drop* drop (e_Silence p_Silence, URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    operation = new Drop(p_Silence, dynamic_cast<URI*>(pos));
	    return NULL;
	}

	/* Expressions */
	virtual VarExpression* varExpression (Variable* p_Variable) {
	    p_Variable->express(this);
	    expression = new VarExpression(dynamic_cast<Variable*>(pos));
	    return NULL;
	}
	virtual LiteralExpression* literalExpression (RDFLiteral* p_RDFLiteral) {
	    p_RDFLiteral->express(this);
	    expression = new LiteralExpression(dynamic_cast<RDFLiteral*>(pos));
	    return NULL;
	}
	virtual BooleanExpression* booleanExpression (BooleanRDFLiteral* p_BooleanRDFLiteral) {
	    p_BooleanRDFLiteral->express(this);
	    expression = new BooleanExpression(dynamic_cast<BooleanRDFLiteral*>(pos));
	    return NULL;
	}
	virtual URIExpression* uriExpression (URI* p_URI) {
	    p_URI->express(this);
	    expression = new URIExpression(dynamic_cast<URI*>(pos));
	    return NULL;
	}
	ProductionVector<Expression*>* _Expressions (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* l_Expressions = new ProductionVector<Expression*>();
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		l_Expressions->push_back(expression);
	    }
	    return l_Expressions;
	}
	virtual ArgList* argList (ProductionVector<Expression*>* p_expressions) {
	    m_argList = new ArgList(_Expressions(p_expressions));
	    return NULL;
	}
	virtual FunctionCall* functionCall (URI* p_IRIref, ArgList* p_ArgList) {
	    p_ArgList->express(this);
	    p_IRIref->express(this);
	    m_functionCall = new FunctionCall(dynamic_cast<URI*>(pos), m_argList);
	    return NULL;
	}
	virtual FunctionCallExpression* functionCallExpression (FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	    expression = new FunctionCallExpression(m_functionCall);
	    return NULL;
	}
	/* Expressions */
	virtual BooleanNegation* booleanNegation (Expression* p_Expression) {
	    p_Expression->express(this);
	    expression = new BooleanNegation(expression);
	    return NULL;
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
	    expression = new BooleanConjunction(_car(v), v);
	    return NULL;
	}
	virtual BooleanDisjunction* booleanDisjunction (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new BooleanDisjunction(_car(v), v);
	    return NULL;
	}
	virtual ArithmeticSum* arithmeticSum (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new ArithmeticSum(_car(v), v);
	    return NULL;
	}
	virtual ArithmeticNegation* arithmeticNegation (Expression* p_Expression) {
	    return new ArithmeticNegation(p_Expression->express(this));
	}
	virtual ArithmeticProduct* arithmeticProduct (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new ArithmeticProduct(_car(v), v);
	    return NULL;
	}
	virtual ArithmeticInverse* arithmeticInverse (Expression* p_Expression) {
	    return new ArithmeticInverse(p_Expression->express(this));
	}
	virtual BooleanEQ* booleanEQ (Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanEQ* ret = new BooleanEQ(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	    return NULL;
	}
	virtual BooleanNE* booleanNE (Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanNE* ret = new BooleanNE(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	    return NULL;
	}
	virtual BooleanLT* booleanLT (Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanLT* ret = new BooleanLT(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	    return NULL;
	}
	virtual BooleanGT* booleanGT (Expression* p_left, Expression* p_right) {
	    BooleanGT* ret = new BooleanGT(p_right->express(this));
	    ret->setLeftParm(p_left->express(this));
	    return ret;
	}
	virtual BooleanLE* booleanLE (Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanLE* ret = new BooleanLE(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	    return NULL;
	}
	virtual BooleanGE* booleanGE (Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanGE* ret = new BooleanGE(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	    return NULL;
	}
	virtual ComparatorExpression* comparatorExpression (BooleanComparator* p_BooleanComparator) {
	    p_BooleanComparator->express(this);
	    expression = new ComparatorExpression(dynamic_cast<BooleanComparator*>(expression));
	    return NULL;
	}
	virtual NumberExpression* numberExpression (NumericRDFLiteral* p_NumericRDFLiteral) {
	    p_NumericRDFLiteral->express(this);
	    expression = new NumberExpression(dynamic_cast<NumericRDFLiteral*>(pos));
	    return NULL;
	}
    };

} // namespace w3c_sw

#endif // SWObjectDuplicator_H

