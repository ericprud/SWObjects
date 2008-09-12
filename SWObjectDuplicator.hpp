/* SWObjectDuplicator.hpp - simple SPARQL duplicator for SPARQL compile trees.
 *
 * $Id: SWObjectDuplicator.hpp,v 1.2.2.2 2008-09-12 04:38:54 eric Exp $
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
	virtual void base (Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void uri (URI*, std::string terminal) {
	    pos = posFactory->getURI(terminal.c_str());
	}
	virtual void variable (Variable*, std::string terminal) {
	    pos = posFactory->getVariable(terminal.c_str());
	}
	virtual void bnode (BNode*, std::string terminal) {
	    pos = posFactory->getBNode(terminal.c_str());
	}
	virtual void rdfLiteral (RDFLiteral*, std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	    pos = posFactory->getRDFLiteral(terminal.c_str(), datatype, p_LANGTAG);
	}
	virtual void rdfLiteral (NumericRDFLiteral*, int p_value) {
	    std::stringstream s;
	    s << p_value;
	    pos = posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	}
	virtual void rdfLiteral (NumericRDFLiteral*, float p_value) {
	    std::stringstream s;
	    s << p_value;
	    pos = posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	}
	virtual void rdfLiteral (NumericRDFLiteral*, double p_value) {
	    std::stringstream s;
	    s << p_value;
	    pos = posFactory->getNumericRDFLiteral(s.str().c_str(), p_value);
	}
	virtual void rdfLiteral (BooleanRDFLiteral*, bool p_value) {
	    pos = posFactory->getBooleanRDFLiteral(p_value ? "true" : "false", p_value);
	}
	virtual void nullpos (NULLpos*) {
	    pos = posFactory->getNULL();
	}
	virtual void triplePattern (TriplePattern*, POS* p_s, POS* p_p, POS* p_o) {
	    p_s->express(this);
	    POS* s = pos;
	    p_p->express(this);
	    POS* p = pos;
	    p_o->express(this);
	    POS* o = pos;
	    m_triplePattern = new TriplePattern(s, p, o);
	}
	virtual void filter (Filter*, Expression* p_Constraint) {
	    p_Constraint->express(this);
	    m_filter = new Filter(expression);
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
	virtual void namedGraphPattern (NamedGraphPattern*, POS* p_name, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    p_name->express(this);
	    NamedGraphPattern* ret = new NamedGraphPattern(pos);
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	}
	virtual void defaultGraphPattern (DefaultGraphPattern*, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern();
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	}
	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
	    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		(*it)->express(this);
		j->addTableOperation(tableOperation);
	    }
	}
	virtual void tableDisjunction (TableDisjunction*, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    TableDisjunction* ret = new TableDisjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	}
	virtual void tableConjunction (TableConjunction*, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    TableConjunction* ret = new TableConjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	}
	virtual void optionalGraphPattern (OptionalGraphPattern*, TableOperation* p_GroupGraphPattern) {
	    p_GroupGraphPattern->express(this);
	    tableOperation = new OptionalGraphPattern(tableOperation);
	}
	virtual void graphGraphPattern (GraphGraphPattern*, POS* p_POS, TableOperation* p_GroupGraphPattern) {
	    p_POS->express(this);
	    POS* name = pos;
	    p_GroupGraphPattern->express(this);
	    tableOperation = new GraphGraphPattern(name, tableOperation);
	}
	void _POSs (ProductionVector<POS*>* p_POSs, POSList* p) { // !!! single use
	    for (std::vector<POS*>::iterator it = p_POSs->begin();
		 it != p_POSs->end(); it++) {
		(*it)->express(this);
		p->push_back(pos);
	    }
	}
	virtual void posList (POSList*, ProductionVector<POS*>* p_POSs) {
	    POSList* ret = new POSList();
	    _POSs(p_POSs, ret);
	    varSet = ret;
	}
	virtual void starVarSet (StarVarSet*) {
	    varSet = new StarVarSet();
	}
	virtual void defaultGraphClause (DefaultGraphClause*, POS* p_IRIref) {
	    p_IRIref->express(this);
	    datasetClause = new DefaultGraphClause(pos, posFactory);
	}
	virtual void namedGraphClause (NamedGraphClause*, POS* p_IRIref) {
	    p_IRIref->express(this);
	    datasetClause = new NamedGraphClause(pos, posFactory);
	}
	virtual void solutionModifier (SolutionModifier*, std::vector<s_OrderConditionPair>* p_OrderConditionPairs, int p_limit, int p_offset) {
	    if (p_OrderConditionPairs) {
		std::vector<s_OrderConditionPair>* l_s_OrderConditionPairs = new std::vector<s_OrderConditionPair>();
		for (std::vector<s_OrderConditionPair>::iterator it = p_OrderConditionPairs->begin();
		     it != p_OrderConditionPairs->end(); it++) {
		    s_OrderConditionPair pair;
		    pair.ascOrDesc = (*it).ascOrDesc;
		    (*it).expression->express(this);
		    pair.expression = expression;
		    l_s_OrderConditionPairs->push_back(pair);
		}
		m_solutionModifier = new SolutionModifier(l_s_OrderConditionPairs, p_limit, p_offset);
	    } else {
		m_solutionModifier = new SolutionModifier(NULL, p_limit, p_offset);
	    }
	}
	virtual void binding (Binding*, ProductionVector<POS*>* values) {//!!!
	    Binding* ret = new Binding();
	    for (std::vector<POS*>::iterator it = values->begin();
		 it != values->end(); it++) {
		(*it)->express(this);
		ret->push_back(pos);
	    }
	    m_binding = ret;
	}
	virtual void bindingClause (BindingClause*, POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	    p_Vars->express(this);
	    BindingClause* ret = new BindingClause(dynamic_cast<POSList*>(varSet));
	    for (std::vector<Binding*>::iterator it = p_Bindings->begin();
		 it != p_Bindings->end(); it++) {
		(*it)->express(this);
		ret->push_back(m_binding);
	    }
	    m_bindingClause = ret;
	}
	virtual void whereClause (WhereClause*, TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    p_GroupGraphPattern->express(this);
	    m_bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);
	    m_whereClause = new WhereClause(tableOperation, m_bindingClause);
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
	virtual void select (Select*, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    operation = new Select(p_distinctness, varSet, _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier);
	}
	virtual void construct (Construct*, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_ConstructTemplate->express(this);
	    TableOperation* construct = tableOperation;
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    operation = new Construct(dynamic_cast<DefaultGraphPattern*>(construct), _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier);
	}
	virtual void describe (Describe*, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    operation = new Describe(varSet, _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier);
	}
	virtual void ask (Ask*, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    operation = new Ask(_DatasetClauses(p_DatasetClauses), m_whereClause);
	}
	virtual void replace (Replace*, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    operation = new Replace(m_whereClause, tableOperation);
	}
	virtual void insert (Insert*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    m_whereClause = NULL;
	    if (p_WhereClause != NULL)
		p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    operation = new Insert(tableOperation, m_whereClause);
	}
	virtual void del (Delete*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    operation = new Delete(tableOperation, m_whereClause);
	}
	virtual void load (Load*, ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	    ProductionVector<URI*>* l_URIs = new ProductionVector<URI*>();
	    for (std::vector<URI*>::iterator it = p_IRIrefs->begin();
		 it != p_IRIrefs->end(); it++) {
		(*it)->express(this);
		l_URIs->push_back(dynamic_cast<URI*>(pos));
	    }
	    p_into->express(this);
	    operation = new Load(l_URIs, dynamic_cast<URI*>(pos));
	}
	virtual void clear (Clear*, URI* p__QGraphIRI_E_Opt) {
	    pos = NULL;
	    if (p__QGraphIRI_E_Opt != NULL)
		p__QGraphIRI_E_Opt->express(this);
	    operation = new Clear(dynamic_cast<URI*>(pos));
	}
	virtual void create (Create*, e_Silence p_Silence, URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    operation = new Create(p_Silence, dynamic_cast<URI*>(pos));
	}
	virtual void drop (Drop*, e_Silence p_Silence, URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    operation = new Drop(p_Silence, dynamic_cast<URI*>(pos));
	}

	/* Expressions */
	virtual void varExpression (VarExpression*, Variable* p_Variable) {
	    p_Variable->express(this);
	    expression = new VarExpression(dynamic_cast<Variable*>(pos));
	}
	virtual void literalExpression (LiteralExpression*, RDFLiteral* p_RDFLiteral) {
	    p_RDFLiteral->express(this);
	    expression = new LiteralExpression(dynamic_cast<RDFLiteral*>(pos));
	}
	virtual void booleanExpression (BooleanExpression*, BooleanRDFLiteral* p_BooleanRDFLiteral) {
	    p_BooleanRDFLiteral->express(this);
	    expression = new BooleanExpression(dynamic_cast<BooleanRDFLiteral*>(pos));
	}
	virtual void uriExpression (URIExpression*, URI* p_URI) {
	    p_URI->express(this);
	    expression = new URIExpression(dynamic_cast<URI*>(pos));
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
	virtual void argList (ArgList*, ProductionVector<Expression*>* p_expressions) {
	    m_argList = new ArgList(_Expressions(p_expressions));
	}
	virtual void functionCall (FunctionCall*, URI* p_IRIref, ArgList* p_ArgList) {
	    p_ArgList->express(this);
	    p_IRIref->express(this);
	    m_functionCall = new FunctionCall(dynamic_cast<URI*>(pos), m_argList);
	}
	virtual void functionCallExpression (FunctionCallExpression*, FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	    expression = new FunctionCallExpression(m_functionCall);
	}
	/* Expressions */
	virtual void booleanNegation (BooleanNegation*, Expression* p_Expression) {
	    p_Expression->express(this);
	    expression = new BooleanNegation(expression);
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
	virtual void booleanConjunction (BooleanConjunction*, ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new BooleanConjunction(_car(v), v);
	}
	virtual void booleanDisjunction (BooleanDisjunction*, ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new BooleanDisjunction(_car(v), v);
	}
	virtual void arithmeticSum (ArithmeticSum*, ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new ArithmeticSum(_car(v), v);
	}
	virtual void arithmeticNegation (ArithmeticNegation*, Expression* p_Expression) {
	    p_Expression->express(this);
	    expression = new ArithmeticNegation(expression);
	}
	virtual void arithmeticProduct (ArithmeticProduct*, ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    expression = new ArithmeticProduct(_car(v), v);
	}
	virtual void arithmeticInverse (ArithmeticInverse*, Expression* p_Expression) {
	    p_Expression->express(this);
	    expression = new ArithmeticInverse(expression);
	}
	virtual void booleanEQ (BooleanEQ*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanEQ* ret = new BooleanEQ(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	}
	virtual void booleanNE (BooleanNE*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanNE* ret = new BooleanNE(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	}
	virtual void booleanLT (BooleanLT*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanLT* ret = new BooleanLT(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	}
	virtual void booleanGT (BooleanGT*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanGT* ret = new BooleanGT(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	}
	virtual void booleanLE (BooleanLE*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanLE* ret = new BooleanLE(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	}
	virtual void booleanGE (BooleanGE*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanGE* ret = new BooleanGE(expression);
	    p_left->express(this);
	    ret->setLeftParm(expression);
	    expression = ret;
	}
	virtual void comparatorExpression (ComparatorExpression*, BooleanComparator* p_BooleanComparator) {
	    p_BooleanComparator->express(this);
	    expression = new ComparatorExpression(dynamic_cast<BooleanComparator*>(expression));
	}
	virtual void numberExpression (NumberExpression*, NumericRDFLiteral* p_NumericRDFLiteral) {
	    p_NumericRDFLiteral->express(this);
	    expression = new NumberExpression(dynamic_cast<NumericRDFLiteral*>(pos));
	}
    };

} // namespace w3c_sw

#endif // SWObjectDuplicator_H

