/* SWObjectDuplicator.hpp - simple SPARQL duplicator for SPARQL compile trees.
 *
 * This duplicates an SWObject tree (e.g. a Select or a Construct). For each
 * object, it expresses each of the subobjects in turn and records the pointer
 * that was stored in last. It then builds a new object with of those pointers.
 * Classes derived from SWObjectDuplicator are likely to get and set the values
 * in last.
 *
 * $Id: SWObjectDuplicator.hpp,v 1.8 2008-11-21 17:13:29 eric Exp $
 */

#ifndef SWObjectDuplicator_H
#define SWObjectDuplicator_H

#include "SWObjects.hpp"

namespace w3c_sw {

    class SWObjectDuplicator : public Expressor {
    protected:
	POSFactory* posFactory; /* Can be used to create SWObjects in a different atom space. */

	union {
	    struct { POS* pos; URI* uri; Variable* variable; RDFLiteral* rdfLiteral; BooleanRDFLiteral* booleanRDFLiteral; NumericRDFLiteral* numericRDFLiteral; } posz;
	    TriplePattern* triplePattern;
	    Expression* expression;
	    Filter* filter;
	    TableOperation* tableOperation;
	    struct { VarSet* varSet; POSList* posList; } varSets;
	    DatasetClause* datasetClause;
	    //ProductionVector<DatasetClause*> datasetClauses;
	    SolutionModifier* solutionModifier;
	    Binding* binding;
	    BindingClause* bindingClause;
	    WhereClause* whereClause;
	    Operation* operation;
	    ArgList* argList;
	    FunctionCall* functionCall;
	} last;

    public:
	SWObjectDuplicator (POSFactory* posFactory) : posFactory(posFactory) {  }
	Operation* getCopy () { return last.operation; }
	//!!!
	virtual void base (const Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void uri (const URI* self, std::string terminal) {
	    last.posz.pos = last.posz.uri = posFactory ? posFactory->getURI(terminal.c_str()) : self;
	}
	virtual void variable (const Variable* self, std::string terminal) {
	    last.posz.pos = last.posz.variable = posFactory ? posFactory->getVariable(terminal.c_str()) : self;
	}
	virtual void bnode (const BNode* self, std::string terminal) {
	    last.posz.pos = posFactory ? posFactory->getBNode(terminal.c_str()) : self;
	}
	virtual void rdfLiteral (const RDFLiteral* self, std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	    last.posz.pos = last.posz.rdfLiteral = posFactory ? posFactory->getRDFLiteral(terminal.c_str(), datatype, p_LANGTAG) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* self, int p_value) {
	    std::stringstream s;
	    s << p_value;
	    last.posz.pos = last.posz.numericRDFLiteral = posFactory ? posFactory->getNumericRDFLiteral(s.str().c_str(), p_value) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* self, float p_value) {
	    std::stringstream s;
	    s << p_value;
	    last.posz.pos = last.posz.numericRDFLiteral = posFactory ? posFactory->getNumericRDFLiteral(s.str().c_str(), p_value) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* self, double p_value) {
	    std::stringstream s;
	    s << p_value;
	    last.posz.pos = last.posz.numericRDFLiteral = posFactory ? posFactory->getNumericRDFLiteral(s.str().c_str(), p_value) : self;
	}
	virtual void rdfLiteral (const BooleanRDFLiteral* self, bool p_value) {
	    last.posz.pos = last.posz.booleanRDFLiteral = posFactory ? posFactory->getBooleanRDFLiteral(p_value ? "true" : "false", p_value) : self;
	}
	virtual void nullpos (const NULLpos* self) {
	    last.posz.pos = posFactory ? posFactory->getNULL() : self;
	}
	virtual void triplePattern (const TriplePattern* self, POS* p_s, POS* p_p, POS* p_o) {
	    p_s->express(this);
	    POS* s = last.posz.pos;
	    p_p->express(this);
	    POS* p = last.posz.pos;
	    p_o->express(this);
	    POS* o = last.posz.pos;
	    last.triplePattern = posFactory ? posFactory->getTriple(s, p, o) : self;
	}
	virtual void filter (const Filter*, Expression* p_Constraint) {
	    p_Constraint->express(this);
	    last.filter = last.expression ? new Filter(last.expression) : NULL;
	}
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (ProductionVector<TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
	    for (std::vector<TriplePattern*>::iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++) {
		(*it)->express(this);
		p->addTriplePattern(last.triplePattern);
	    }
	}
	void _Filters (ProductionVector<Filter*>* p_Filters, TableOperation* op) {
	    for (std::vector<Filter*>::iterator it = p_Filters->begin();
		 it != p_Filters->end(); it++) {
		(*it)->express(this);
		if (last.filter != NULL)
		    op->addFilter(last.filter);
	    }
	}
	virtual void namedGraphPattern (NamedGraphPattern*, POS* p_name, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    p_name->express(this);
	    NamedGraphPattern* ret = new NamedGraphPattern(last.posz.pos);
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    last.tableOperation = ret;
	}
	virtual void defaultGraphPattern (DefaultGraphPattern*, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern();
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    last.tableOperation = ret;
	}
	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
	    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		(*it)->express(this);
		j->addTableOperation(last.tableOperation);
	    }
	}
	virtual void tableDisjunction (const TableDisjunction*, const ProductionVector<TableOperation*>* p_TableOperations, const ProductionVector<Filter*>* p_Filters) {
	    TableDisjunction* ret = new TableDisjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    last.tableOperation = ret;
	}
	virtual void tableConjunction (const TableConjunction*, const ProductionVector<TableOperation*>* p_TableOperations, const ProductionVector<Filter*>* p_Filters) {
	    TableConjunction* ret = new TableConjunction();
	    _TableOperations(p_TableOperations, ret);
	    _Filters(p_Filters, ret);
	    last.tableOperation = ret;
	}
	virtual void optionalGraphPattern (const OptionalGraphPattern*, TableOperation* p_GroupGraphPattern) {
	    p_GroupGraphPattern->express(this);
	    last.tableOperation = new OptionalGraphPattern(last.tableOperation);
	}
	virtual void graphGraphPattern (const GraphGraphPattern*, POS* p_POS, TableOperation* p_GroupGraphPattern) {
	    p_POS->express(this);
	    POS* name = last.posz.pos;
	    p_GroupGraphPattern->express(this);
	    last.tableOperation = new GraphGraphPattern(name, last.tableOperation);
	}
	void _POSs (ProductionVector<POS*>* p_POSs, POSList* p) { // !!! single use
	    for (std::vector<POS*>::iterator it = p_POSs->begin();
		 it != p_POSs->end(); it++) {
		(*it)->express(this);
		p->push_back(last.posz.pos);
	    }
	}
	virtual void posList (const POSList*, const ProductionVector<POS*>* p_POSs) {
	    POSList* ret = new POSList();
	    _POSs(p_POSs, ret);
	    last.varSets.varSet = last.varSets.posList = ret;
	}
	virtual void starVarSet (const StarVarSet*) {
	    last.varSets.varSet = new StarVarSet();
	}
	virtual void defaultGraphClause (const DefaultGraphClause*, POS* p_IRIref) {
	    p_IRIref->express(this);
	    last.datasetClause = new DefaultGraphClause(last.posz.pos, posFactory);
	}
	virtual void namedGraphClause (const NamedGraphClause*, POS* p_IRIref) {
	    p_IRIref->express(this);
	    last.datasetClause = new NamedGraphClause(last.posz.pos, posFactory);
	}
	virtual void solutionModifier (SolutionModifier*, std::vector<s_OrderConditionPair>* p_OrderConditionPairs, int p_limit, int p_offset) {
	    if (p_OrderConditionPairs) {
		std::vector<s_OrderConditionPair>* l_s_OrderConditionPairs = new std::vector<s_OrderConditionPair>();
		for (std::vector<s_OrderConditionPair>::iterator it = p_OrderConditionPairs->begin();
		     it != p_OrderConditionPairs->end(); it++) {
		    s_OrderConditionPair pair;
		    pair.ascOrDesc = (*it).ascOrDesc;
		    (*it).expression->express(this);
		    pair.expression = last.expression;
		    l_s_OrderConditionPairs->push_back(pair);
		}
		last.solutionModifier = new SolutionModifier(l_s_OrderConditionPairs, p_limit, p_offset);
	    } else {
		last.solutionModifier = new SolutionModifier(NULL, p_limit, p_offset);
	    }
	}
	virtual void binding (const Binding*, const ProductionVector<POS*>* values) {//!!!
	    Binding* ret = new Binding();
	    for (std::vector<POS*>::iterator it = values->begin();
		 it != values->end(); it++) {
		(*it)->express(this);
		ret->push_back(last.posz.pos);
	    }
	    last.binding = ret;
	}
	virtual void bindingClause (const BindingClause*, POSList* p_Vars, const ProductionVector<Binding*>* p_Bindings) {
	    p_Vars->express(this);
	    BindingClause* ret = new BindingClause(last.varSets.posList);
	    for (std::vector<Binding*>::iterator it = p_Bindings->begin();
		 it != p_Bindings->end(); it++) {
		(*it)->express(this);
		ret->push_back(last.binding);
	    }
	    last.bindingClause = ret;
	}
	virtual void whereClause (const WhereClause*, TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    p_GroupGraphPattern->express(this);
	    TableOperation* op = last.tableOperation;
	    last.bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);
	    last.whereClause = new WhereClause(op, last.bindingClause);
	}
	ProductionVector<DatasetClause*>* _DatasetClauses (ProductionVector<DatasetClause*>* p_DatasetClauses) {
	    ProductionVector<DatasetClause*>* l_DatasetClauses = new ProductionVector<DatasetClause*>();
	    for (std::vector<DatasetClause*>::iterator it = p_DatasetClauses->begin();
		 it != p_DatasetClauses->end(); it++) {
		(*it)->express(this);
		l_DatasetClauses->push_back(last.datasetClause);
	    }
	    return l_DatasetClauses;
	}
	/* Operations */
	virtual void select (const Select*, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    VarSet* varSet = last.varSets.varSet;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    last.operation = new Select(p_distinctness, varSet, _DatasetClauses(p_DatasetClauses), where, last.solutionModifier);
	}
	virtual void construct (const Construct*, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_ConstructTemplate->express(this);
	    TableOperation* construct = last.tableOperation;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    last.operation = new Construct(dynamic_cast<DefaultGraphPattern*>(construct), _DatasetClauses(p_DatasetClauses), where, last.solutionModifier);
	}
	virtual void describe (const Describe*, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    VarSet* varSet = last.varSets.varSet;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    last.operation = new Describe(varSet, _DatasetClauses(p_DatasetClauses), where, last.solutionModifier);
	}
	virtual void ask (const Ask*, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    last.operation = new Ask(_DatasetClauses(p_DatasetClauses), last.whereClause);
	}
	virtual void replace (const Replace*, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_GraphTemplate->express(this);
	    last.operation = new Replace(where, last.tableOperation);
	}
	virtual void insert (const Insert*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    last.whereClause = NULL;
	    if (p_WhereClause != NULL)
		p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_GraphTemplate->express(this);
	    last.operation = new Insert(last.tableOperation, where);
	}
	virtual void del (const Delete*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_GraphTemplate->express(this);
	    last.operation = new Delete(last.tableOperation, where);
	}
	virtual void load (const Load*, ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	    ProductionVector<URI*>* l_URIs = new ProductionVector<URI*>();
	    for (std::vector<URI*>::iterator it = p_IRIrefs->begin();
		 it != p_IRIrefs->end(); it++) {
		(*it)->express(this);
		l_URIs->push_back(last.posz.uri);
	    }
	    p_into->express(this);
	    last.operation = new Load(l_URIs, last.posz.uri);
	}
	virtual void clear (const Clear*, URI* p__QGraphIRI_E_Opt) {
	    last.posz.pos = NULL;
	    if (p__QGraphIRI_E_Opt != NULL)
		p__QGraphIRI_E_Opt->express(this);
	    last.operation = new Clear(last.posz.uri);
	}
	virtual void create (const Create*, e_Silence p_Silence, URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    last.operation = new Create(p_Silence, last.posz.uri);
	}
	virtual void drop (const Drop*, e_Silence p_Silence, URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    last.operation = new Drop(p_Silence, last.posz.uri);
	}

	/* Expressions */
	virtual void varExpression (const VarExpression*, const Variable* p_Variable) {
	    p_Variable->express(this);
	    last.expression = new VarExpression(last.posz.variable);
	}
	virtual void literalExpression (const LiteralExpression*, RDFLiteral* p_RDFLiteral) {
	    p_RDFLiteral->express(this);
	    last.expression = new LiteralExpression(last.posz.rdfLiteral);
	}
	virtual void booleanExpression (const BooleanExpression*, BooleanRDFLiteral* p_BooleanRDFLiteral) {
	    p_BooleanRDFLiteral->express(this);
	    last.expression = new BooleanExpression(last.posz.booleanRDFLiteral);
	}
	virtual void uriExpression (const URIExpression*, URI* p_URI) {
	    p_URI->express(this);
	    last.expression = new URIExpression(last.posz.uri);
	}
	ProductionVector<Expression*>* _Expressions (ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* l_Expressions = new ProductionVector<Expression*>();
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		l_Expressions->push_back(last.expression);
	    }
	    return l_Expressions;
	}
	virtual void argList (ArgList*, ProductionVector<Expression*>* p_expressions) {
	    last.argList = new ArgList(_Expressions(p_expressions));
	}
	virtual void functionCall (const FunctionCall*, URI* p_IRIref, ArgList* p_ArgList) {
	    p_ArgList->express(this);
	    ArgList* argList = last.argList;
	    p_IRIref->express(this);
	    last.functionCall = new FunctionCall(last.posz.uri, argList);
	}
	virtual void functionCallExpression (const FunctionCallExpression*, FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	    last.expression = last.functionCall ? new FunctionCallExpression(last.functionCall) : NULL;
	}
	/* Expressions */
	virtual void booleanNegation (const BooleanNegation*, Expression* p_Expression) {
	    p_Expression->express(this);
	    last.expression = new BooleanNegation(last.expression);
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
	virtual void booleanConjunction (const BooleanConjunction*, const ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new BooleanConjunction(_car(v), v);
	}
	virtual void booleanDisjunction (const BooleanDisjunction*, const ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new BooleanDisjunction(_car(v), v);
	}
	virtual void arithmeticSum (const ArithmeticSum*, const ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new ArithmeticSum(_car(v), v);
	}
	virtual void arithmeticNegation (const ArithmeticNegation*, Expression* p_Expression) {
	    p_Expression->express(this);
	    last.expression = new ArithmeticNegation(last.expression);
	}
	virtual void arithmeticProduct (const ArithmeticProduct*, const ProductionVector<Expression*>* p_Expressions) {
	    ProductionVector<Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new ArithmeticProduct(_car(v), v);
	}
	virtual void arithmeticInverse (const ArithmeticInverse*, Expression* p_Expression) {
	    p_Expression->express(this);
	    last.expression = new ArithmeticInverse(last.expression);
	}
	virtual void booleanEQ (const BooleanEQ*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanEQ* ret = new BooleanEQ(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanNE (const BooleanNE*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanNE* ret = new BooleanNE(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanLT (const BooleanLT*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanLT* ret = new BooleanLT(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanGT (const BooleanGT*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanGT* ret = new BooleanGT(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanLE (const BooleanLE*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanLE* ret = new BooleanLE(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanGE (const BooleanGE*, Expression* p_left, Expression* p_right) {
	    p_right->express(this);
	    BooleanGE* ret = new BooleanGE(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void comparatorExpression (const ComparatorExpression*, BooleanComparator* p_BooleanComparator) {
	    p_BooleanComparator->express(this);
	    last.expression = new ComparatorExpression(dynamic_cast<BooleanComparator*>(last.expression));
	}
	virtual void numberExpression (const NumberExpression*, NumericRDFLiteral* p_NumericRDFLiteral) {
	    p_NumericRDFLiteral->express(this);
	    last.expression = new NumberExpression(last.posz.numericRDFLiteral);
	}
    };

} // namespace w3c_sw

#endif // SWObjectDuplicator_H

