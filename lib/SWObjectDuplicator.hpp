/* SWObjectDuplicator.hpp - simple SPARQL duplicator for SPARQL compile trees.
 *
 * This duplicates an SWObject tree (e.g. a Select or a Construct). For each
 * object, it expresses each of the subobjects in turn and records the pointer
 * that was stored in last. It then builds a new object with of those pointers.
 * Classes derived from SWObjectDuplicator are likely to get and set the values
 * in last.
 *
 * invocation:
 *   Operation* copyMe = @@@;
 *   SWObjectDuplicator duper;
 *   copyMe->express(&duper);
 *   Operation* copy = copyMe.last.operation;
 *
 * Copies of parts of query objects are accessed through members of copyMe.last.
 *
 * $Id: SWObjectDuplicator.hpp,v 1.8 2008-11-21 17:13:29 eric Exp $
 */

#ifndef SWObjectDuplicator_H
#define SWObjectDuplicator_H

#include "SWObjects.hpp"

namespace w3c_sw {

    struct SWObjectDuplicator : public Expressor {
	AtomFactory* atomFactory; /* Can be used to create SWObjects in a different atom space. */
	TTerm::String2BNode nodeMap;

	union {
	    struct {
		const TTerm* tterm;
		const URI* uri;
		const Variable* variable;
		const RDFLiteral* rdfLiteral;
		const BooleanRDFLiteral* booleanRDFLiteral;
		const NumericRDFLiteral* numericRDFLiteral;
	    } tterms;
	    const TriplePattern* triplePattern;
	    const Expression* expression;
	    const ExpressionAlias* expressionAlias;
	    const Filter* filter;
	    TableOperation* tableOperation;
	    struct { VarSet* varSet; const ProductionVector<const ExpressionAlias*>* exprList; } varSets;
	    const DatasetClause* datasetClause;
	    //ProductionVector<DatasetClause*> datasetClauses;
	    SolutionModifier* solutionModifier;
	    const Binding* binding;
	    TTermList* posList;
	    const BindingClause* bindingClause;
	    WhereClause* whereClause;
	    const Operation* operation;
	    const ArgList* argList;
	    FunctionCall* functionCall;
	} last;

	SWObjectDuplicator (AtomFactory* atomFactory) : atomFactory(atomFactory) {  }

	virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void uri (const URI* const self, std::string lexicalValue) {
	    last.tterms.tterm = last.tterms.uri = atomFactory ? atomFactory->getURI(lexicalValue.c_str()) : self;
	}
	virtual void variable (const Variable* const self, std::string lexicalValue) {
	    last.tterms.tterm = last.tterms.variable = atomFactory ? atomFactory->getVariable(lexicalValue.c_str()) : self;
	}
	virtual void bnode (const BNode* const self, std::string lexicalValue) {
	    last.tterms.tterm = atomFactory ? atomFactory->getBNode(lexicalValue.c_str(), nodeMap) : self;
	}
	virtual void rdfLiteral (const RDFLiteral* const self, std::string lexicalValue, const URI* datatype, LANGTAG* p_LANGTAG) {
	    last.tterms.tterm = last.tterms.rdfLiteral = atomFactory ? atomFactory->getRDFLiteral(lexicalValue.c_str(), datatype, p_LANGTAG) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* const self, int p_value) {
	    std::stringstream s;
	    s << p_value;
	    last.tterms.tterm = last.tterms.numericRDFLiteral = atomFactory ? atomFactory->getNumericRDFLiteral(s.str().c_str(), p_value) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* const self, float p_value) {
	    std::stringstream s;
	    s << p_value;
	    last.tterms.tterm = last.tterms.numericRDFLiteral = atomFactory ? atomFactory->getNumericRDFLiteral(s.str().c_str(), p_value) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* const self, double p_value) {
	    std::stringstream s;
	    s << p_value;
	    last.tterms.tterm = last.tterms.numericRDFLiteral = atomFactory ? atomFactory->getNumericRDFLiteral(s.str().c_str(), p_value) : self;
	}
	virtual void rdfLiteral (const BooleanRDFLiteral* const self, bool p_value) {
	    last.tterms.tterm = last.tterms.booleanRDFLiteral = atomFactory ? atomFactory->getBooleanRDFLiteral(p_value ? "true" : "false", p_value) : self;
	}
	virtual void nulltterm (const NULLtterm* const self) {
	    last.tterms.tterm = TTerm::Unbound;
	}
	virtual void triplePattern (const TriplePattern* const self, const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) {
	    p_s->express(this);
	    const TTerm* s = last.tterms.tterm;
	    p_p->express(this);
	    const TTerm* p = last.tterms.tterm;
	    p_o->express(this);
	    const TTerm* o = last.tterms.tterm;
	    last.triplePattern = atomFactory ? atomFactory->getTriple(s, p, o) : self;
	}
	virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
	    Filter* lastFilter = NULL;
	    p_op->express(this);
	    TableOperation* ret = last.tableOperation;
	    for (std::vector<const Expression*>::const_iterator it = p_Constraints->begin();
		 it != p_Constraints->end(); ++it) {
		(*it)->express(this);
		if (last.expression != NULL) {
		    if (lastFilter == NULL)
			ret = lastFilter = new Filter(ret);
		    ((Filter*)lastFilter)->addExpression(last.expression); // !!! LIES
		}
	    }
	    last.tableOperation = ret;
	}
#if 0
	virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Expressions) {
	    p_op.express(this);
	    TableOperation* op = last.operation;
	    Filter* f = new Filter(op);
	    for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		if (last.expression != NULL)
		    f->addExpression(last.expression);
	    }
	    if (f.size() > 0)
		last.operation = last.filter = f;
	    else {
		delete op;
		last.filter = NULL;
		p_op.express(this); // re-sets last.operation;
	    }
	}
#endif
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const ProductionVector<const TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
	    for (std::vector<const TriplePattern*>::const_iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++) {
		(*it)->express(this);
		p->addTriplePattern(last.triplePattern);
	    }
	}
	virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    p_name->express(this);
	    NamedGraphPattern* ret = new NamedGraphPattern(last.tterms.tterm);
	    _TriplePatterns(p_TriplePatterns, ret);
	    last.tableOperation = ret;
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern();
	    _TriplePatterns(p_TriplePatterns, ret);
	    last.tableOperation = ret;
	}
	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (const ProductionVector<const TableOperation*>* p_TableOperations, TableJunction* j) {
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		(*it)->express(this);
		j->addTableOperation(last.tableOperation, true);
	    }
	}
	virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    TableDisjunction* ret = new TableDisjunction();
	    _TableOperations(p_TableOperations, ret);
	    last.tableOperation = ret;
	}
	virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    TableConjunction* ret = new TableConjunction();
	    _TableOperations(p_TableOperations, ret);
	    last.tableOperation = ret;
	}
	virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
	    p_GroupGraphPattern->express(this);
	    OptionalGraphPattern* ret = new OptionalGraphPattern(last.tableOperation);
	    for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		ret->addExpression(last.expression);
	    }
	    last.tableOperation = ret;
	}
	virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
	    p_GroupGraphPattern->express(this);
	    last.tableOperation = new MinusGraphPattern(last.tableOperation);
	}
	virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	    p_TTerm->express(this);
	    const TTerm* name = last.tterms.tterm;
	    p_GroupGraphPattern->express(this);
	    last.tableOperation = new GraphGraphPattern(name, last.tableOperation);
	}
	virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) {
	    p_TTerm->express(this);
	    const TTerm* name = last.tterms.tterm;
	    p_GroupGraphPattern->express(this);
	    last.tableOperation = new ServiceGraphPattern(name, last.tableOperation, atomFactory, lexicalCompare);
	}
	virtual void expressionAlias (const ExpressionAlias* const, const Expression* expr, const Bindable* label) {
	    expr->express(this);
	    const Expression* ex = last.expression;
	    if (label) {
		label->express(this);
		last.expressionAlias = new ExpressionAlias(ex, (const Bindable*)last.tterms.tterm); // @@ downcast -- could create separate tterms
	    } else {
		last.expressionAlias = new ExpressionAlias(ex);
	    }
	}
	virtual void expressionAliasList (const ExpressionAliasList* const, const ProductionVector<const ExpressionAlias*>* p_ExpressionAliases) {
	    ExpressionAliasList* ret = new ExpressionAliasList();
	    for (std::vector<const ExpressionAlias*>::const_iterator it = p_ExpressionAliases->begin();
		 it != p_ExpressionAliases->end(); it++) {
		(*it)->express(this);
		ret->push_back(last.expressionAlias);
	    }
	    last.varSets.varSet = /* last.varSets.exprList = */ ret;
	}
	virtual void posList (const TTermList* const, const ProductionVector<const TTerm*>* p_TTerms) {
	    TTermList* ret = new TTermList();
	    for (std::vector<const TTerm*>::const_iterator it = p_TTerms->begin();
		 it != p_TTerms->end(); ++it)
		ret->push_back(*it);
	    last.posList = ret;
	}
	virtual void starVarSet (const StarVarSet* const) {
	    last.varSets.varSet = new StarVarSet();
	}
	virtual void defaultGraphClause (const DefaultGraphClause* const, const TTerm* p_IRIref) {
	    p_IRIref->express(this);
	    last.datasetClause = new DefaultGraphClause(last.tterms.tterm, atomFactory);
	}
	virtual void namedGraphClause (const NamedGraphClause* const, const TTerm* p_IRIref) {
	    p_IRIref->express(this);
	    last.datasetClause = new NamedGraphClause(last.tterms.tterm, atomFactory);
	}
	virtual void solutionModifier (const SolutionModifier* const, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditionPairs, int p_limit, int p_offset) {
	    ExpressionAliasList* n_groupBy = NULL;
	    if (groupBy) {
		n_groupBy = new ExpressionAliasList();
		for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		     it != groupBy->end(); ++it) {
		    (*it)->express(this);
		    n_groupBy->push_back(last.expressionAlias);
		}
	    }
	    ProductionVector<const Expression*>* n_having = NULL;
	    if (having) {
		n_having = new ProductionVector<const Expression*>();
		for (std::vector<const Expression*>::const_iterator it = having->begin();
		     it != having->end(); ++it) {
		    (*it)->express(this);
		    n_having->push_back(last.expression);
		}
	    }
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
		last.solutionModifier = new SolutionModifier(n_groupBy, n_having, l_s_OrderConditionPairs, p_limit, p_offset);
	    } else {
		last.solutionModifier = new SolutionModifier(NULL, NULL, NULL, p_limit, p_offset);
	    }
	}
	virtual void binding (const Binding* const, const ProductionVector<const TTerm*>* values) {//!!!
	    Binding* ret = new Binding();
	    for (std::vector<const TTerm*>::const_iterator it = values->begin();
		 it != values->end(); it++) {
		(*it)->express(this);
		ret->push_back(last.tterms.tterm);
	    }
	    last.binding = ret;
	}
	virtual void bindingClause (const BindingClause* const, TTermList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) {
	    p_Vars->express(this);
	    BindingClause* ret = new BindingClause(last.posList); // last.varSets.posList);
	    for (std::vector<const Binding*>::const_iterator it = p_Bindings->begin();
		 it != p_Bindings->end(); it++) {
		(*it)->express(this);
		ret->push_back(last.binding);
	    }
	    last.bindingClause = ret;
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	    p_GroupGraphPattern->express(this);
	    const TableOperation* op = last.tableOperation;
	    last.bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);
	    last.whereClause = new WhereClause(op, last.bindingClause);
	}
	ProductionVector<const DatasetClause*>* _DatasetClauses (ProductionVector<const DatasetClause*>* p_DatasetClauses) {
	    ProductionVector<const DatasetClause*>* l_DatasetClauses = new ProductionVector<const DatasetClause*>();
	    for (std::vector<const DatasetClause*>::iterator it = p_DatasetClauses->begin();
		 it != p_DatasetClauses->end(); it++) {
		(*it)->express(this);
		l_DatasetClauses->push_back(last.datasetClause);
	    }
	    return l_DatasetClauses;
	}
	/* Operations */
	virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
	    OperationSet* ret = new OperationSet();
	    for (std::vector<const Operation*>::const_iterator it = p_Operations->begin();
		 it != p_Operations->end(); ++it) {
		(*it)->express(this);
		ret->push_back(last.operation);
	    }
	    last.operation = ret;
	}
	virtual void select (const Select* const, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    VarSet* varSet = last.varSets.varSet;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    last.operation = new Select(p_distinctness, varSet, _DatasetClauses(p_DatasetClauses), where, last.solutionModifier);
	}
	virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	    p_Select->express(this);
	    last.tableOperation = new SubSelect((const Select*)last.operation);
	}
	virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_ConstructTemplate->express(this);
	    TableOperation* construct = last.tableOperation;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    last.operation = new Construct(dynamic_cast<DefaultGraphPattern*>(construct), _DatasetClauses(p_DatasetClauses), where, last.solutionModifier);
	}
	virtual void describe (const Describe* const, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    VarSet* varSet = last.varSets.varSet;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    last.operation = new Describe(varSet, _DatasetClauses(p_DatasetClauses), where, last.solutionModifier);
	}
	virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    last.operation = new Ask(_DatasetClauses(p_DatasetClauses), last.whereClause);
	}
	virtual void replace (const Replace* const, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_GraphTemplate->express(this);
	    last.operation = new Replace(where, last.tableOperation);
	}
	virtual void insert (const Insert* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    last.whereClause = NULL;
	    if (p_WhereClause != NULL)
		p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_GraphTemplate->express(this);
	    last.operation = new Insert(last.tableOperation, where);
	}
	virtual void del (const Delete* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_GraphTemplate->express(this);
	    last.operation = new Delete(last.tableOperation, where);
	}
	virtual void load (const Load* const, ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) {
	    ProductionVector<const URI*>* l_URIs = new ProductionVector<const URI*>();
	    for (std::vector<const URI*>::iterator it = p_IRIrefs->begin();
		 it != p_IRIrefs->end(); it++) {
		(*it)->express(this);
		l_URIs->push_back(last.tterms.uri);
	    }
	    p_into->express(this);
	    last.operation = new Load(l_URIs, last.tterms.uri);
	}
	virtual void clear (const Clear* const, const URI* p__QGraphIRI_E_Opt) {
	    last.tterms.tterm = NULL;
	    if (p__QGraphIRI_E_Opt != NULL)
		p__QGraphIRI_E_Opt->express(this);
	    last.operation = new Clear(last.tterms.uri);
	}
	virtual void create (const Create* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    last.operation = new Create(p_Silence, last.tterms.uri);
	}
	virtual void drop (const Drop* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    last.operation = new Drop(p_Silence, last.tterms.uri);
	}

	/* Expressions */
	virtual void posExpression (const TTermExpression* const, const TTerm* p_TTerm) {
	    p_TTerm->express(this);
	    last.expression = new TTermExpression(last.tterms.tterm);
	}
	ProductionVector<const Expression*>* _Expressions (const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* l_Expressions = new ProductionVector<const Expression*>();
	    for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		l_Expressions->push_back(last.expression);
	    }
	    return l_Expressions;
	}
	virtual void argList (const ArgList* const, ProductionVector<const Expression*>* p_expressions) {
	    last.argList = new ArgList(_Expressions(p_expressions));
	}
	virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {
	    p_ArgList->express(this);
	    const ArgList* argList = last.argList;
	    p_IRIref->express(this);
	    last.functionCall = new FunctionCall(last.tterms.uri, argList);
	}
	virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	    last.expression = last.functionCall ? new FunctionCallExpression(last.functionCall) : NULL;
	}
	/* Expressions */
	virtual void booleanNegation (const BooleanNegation* const, const Expression* p_Expression) {
	    p_Expression->express(this);
	    last.expression = new BooleanNegation(last.expression);
	}
	virtual void booleanConjunction (const BooleanConjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new BooleanConjunction(v);
	    v->clear();
	    delete v;
	}
	virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new BooleanDisjunction(v);
	    v->clear();
	    delete v;
	}
	virtual void arithmeticSum (const ArithmeticSum* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new ArithmeticSum(v);
	    v->clear();
	    delete v;
	}
	virtual void arithmeticNegation (const ArithmeticNegation* const, const Expression* p_Expression) {
	    p_Expression->express(this);
	    last.expression = new ArithmeticNegation(last.expression);
	}
	virtual void arithmeticProduct (const ArithmeticProduct* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions);
	    last.expression = new ArithmeticProduct(v);
	    v->clear();
	    delete v;
	}
	virtual void arithmeticInverse (const ArithmeticInverse* const, const Expression* p_Expression) {
	    p_Expression->express(this);
	    last.expression = new ArithmeticInverse(last.expression);
	}
	virtual void booleanEQ (const BooleanEQ* const, const Expression* p_left, const Expression* p_right) {
	    p_right->express(this);
	    BooleanEQ* ret = new BooleanEQ(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanNE (const BooleanNE* const, const Expression* p_left, const Expression* p_right) {
	    p_right->express(this);
	    BooleanNE* ret = new BooleanNE(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanLT (const BooleanLT* const, const Expression* p_left, const Expression* p_right) {
	    p_right->express(this);
	    BooleanLT* ret = new BooleanLT(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanGT (const BooleanGT* const, const Expression* p_left, const Expression* p_right) {
	    p_right->express(this);
	    BooleanGT* ret = new BooleanGT(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanLE (const BooleanLE* const, const Expression* p_left, const Expression* p_right) {
	    p_right->express(this);
	    BooleanLE* ret = new BooleanLE(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void booleanGE (const BooleanGE* const, const Expression* p_left, const Expression* p_right) {
	    p_right->express(this);
	    BooleanGE* ret = new BooleanGE(last.expression);
	    p_left->express(this);
	    ret->setLeftParm(last.expression);
	    last.expression = ret;
	}
	virtual void comparatorExpression (const ComparatorExpression* const, const GeneralComparator* p_GeneralComparator) {
	    p_GeneralComparator->express(this);
	    last.expression = new ComparatorExpression(dynamic_cast<const GeneralComparator*>(last.expression));
	}
	virtual void numberExpression (const NumberExpression* const, const NumericRDFLiteral* p_NumericRDFLiteral) {
	    p_NumericRDFLiteral->express(this);
	    last.expression = new NumberExpression(last.tterms.numericRDFLiteral);
	}
    };

    struct BGPSimplifier : public SWObjectDuplicator {
	bool inConj;
	bool lastInConj;
	BasicGraphPattern* lastBGP;
	TableConjunction* nestingConj;
	BGPSimplifier (AtomFactory* atomFactory)
	    : SWObjectDuplicator(atomFactory), inConj(false), lastInConj(false), lastBGP(NULL), nestingConj(NULL) {  }

	struct NonConjunctionState {
	    bool inConj;
	    TableConjunction* nestingConj;
	    NonConjunctionState (bool inConj, TableConjunction* nestingConj)
		: inConj(inConj), nestingConj(nestingConj) {  }
	};

	NonConjunctionState flushConjunction () {
	    NonConjunctionState ret = NonConjunctionState(inConj, nestingConj);
	    if (inConj) {
		if (ret.nestingConj == NULL)
		    ret.nestingConj = new TableConjunction();
		if (lastBGP) {
		    ret.nestingConj->addTableOperation(lastBGP, false); // @@@ try true?
		    lastBGP = NULL;
		}
		inConj = false;
	    }
	    nestingConj = NULL;
	    lastInConj = false;
	    return ret;
	}
	void pendingConjunction (NonConjunctionState outer) {
	    inConj = outer.inConj;
	    nestingConj = outer.nestingConj;
	    if (nestingConj != NULL) {
		nestingConj->addTableOperation(last.tableOperation, false);
		last.tableOperation = nestingConj;
	    }
	    lastBGP = NULL;
	    lastInConj = false;
	}
	virtual void filter (const Filter* const self, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::filter (self, p_op, p_Constraints);
	    pendingConjunction(outer);
	}
	virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    NamedGraphPattern* ret = dynamic_cast<NamedGraphPattern*>(lastBGP);
	    if (ret == NULL || ret->m_name != p_name) {
		p_name->express(this);
		lastBGP = ret = new NamedGraphPattern(last.tterms.tterm);
		if (nestingConj != NULL)
		    nestingConj->addTableOperation(ret, false);
	    }
	    _TriplePatterns(p_TriplePatterns, ret);
	    last.tableOperation = ret;
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    BasicGraphPattern* ret = dynamic_cast<DefaultGraphPattern*>(lastBGP);
	    if (ret == NULL) {
		lastBGP = ret = new DefaultGraphPattern();
		if (nestingConj != NULL)
		    nestingConj->addTableOperation(ret, false);
	    }
	    _TriplePatterns(p_TriplePatterns, ret);
	    last.tableOperation = ret;
	}
	virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    TableDisjunction* ret = new TableDisjunction();
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		NonConjunctionState outer = flushConjunction();
		(*it)->express(this);
		ret->addTableOperation(last.tableOperation, true);
		pendingConjunction(outer);
	    }
	    last.tableOperation = ret;
	}
	virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    bool wasInConj = inConj;
	    inConj = true;
	    TableConjunction* autoAdd = NULL;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		(*it)->express(this);
		if (lastInConj) {
		    autoAdd = nestingConj;
		    if (nestingConj)
			last.tableOperation = nestingConj;
		} else {
		    if (autoAdd != NULL) {
			if (autoAdd != last.tableOperation && lastBGP == NULL)
			    autoAdd->addTableOperation(last.tableOperation, false);
			last.tableOperation = autoAdd;
		    }
		    autoAdd = lastBGP == NULL || lastInConj ? nestingConj : NULL;
		}
	    }
	    /*
	      ⋈({A}{B})	  => {A⋅B}:		last.tableOperation = lastBGP
	      ⋈({A}⋈({B}{C}))	  => {A⋅B⋅C}:		last.tableOperation = lastBGP
	      ⊎({A}{B})	  => ⊎({A}{B}):	last.tableOperation ← tableDisjunction()
	      ⋈{{A}¬{B}}	  => ⋈{{A}¬{B}}:	last.tableOperation = nestingConj
	      ⋈({A}⋈({B}¬{C}))	  => ⋈({A⋅B}¬{C}):	last.tableOperation = lastBGP
	      ⋈{{A}{B}¬{C}{D}{E}} => ⋈{{A⋅B}¬{C}{D⋅E}}: last.tableOperation = nestingConj       
	     */
	    inConj = wasInConj;
	    lastInConj = true;
	}
	virtual void optionalGraphPattern (const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::optionalGraphPattern (self, p_GroupGraphPattern, p_Expressions);
	    pendingConjunction(outer);
	}
	virtual void minusGraphPattern (const MinusGraphPattern* const self, const TableOperation* p_GroupGraphPattern) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::minusGraphPattern(self, p_GroupGraphPattern);
	    pendingConjunction(outer);
	}
	virtual void graphGraphPattern (const GraphGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::graphGraphPattern(self, p_TTerm, p_GroupGraphPattern);
	    pendingConjunction(outer);
	}
	virtual void serviceGraphPattern (const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::serviceGraphPattern(self, p_TTerm, p_GroupGraphPattern, atomFactory, lexicalCompare);
	    pendingConjunction(outer);
	}
    };

} // namespace w3c_sw

#endif // SWObjectDuplicator_H

