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

    union SWObjectDuplicator_Last {
      struct Tterms {
	  const TTerm* tterm;
	  const Members* members;
	  const URI* uri;
	  const Variable* variable;
	  const RDFLiteral* rdfLiteral;
	  const BooleanRDFLiteral* booleanRDFLiteral;
	  const NumericRDFLiteral* numericRDFLiteral;
      };
      const PropertyPath::PathBase* pathBase;
      Tterms tterms;
      const TriplePattern* triplePattern;
      const Expression* expression;
      const ExpressionAlias* expressionAlias;
      const Filter* filter;
      TableOperation* tableOperation;
      struct { VarSet* varSet; const ProductionVector<const ExpressionAlias*>* exprList; } varSets;
      const DatasetClause* datasetClause;
      //ProductionVector<DatasetClause*> datasetClauses;
      SolutionModifier* solutionModifier;
      TTermList* posList;
      const ValuesClause* valuesClause;
      WhereClause* whereClause;
      const Operation* operation;
      const ArgList* argList;
      FunctionCall* functionCall;
    };

    struct SWObjectDuplicator : public Expressor {
	AtomFactory* atomFactory; /* Can be used to create SWObjects in a different atom space. */
	TTerm::String2BNode bnodeMap;

        SWObjectDuplicator_Last last;
	SWObjectDuplicator (AtomFactory* atomFactory) : atomFactory(atomFactory) {  }

	virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void members (const Members* const /* self */, ProductionVector<const TTerm*>* p_vars) {
	    ProductionVector<const TTerm*>* newVec = new ProductionVector<const TTerm*>();
	    for (std::vector<const TTerm*>::const_iterator it = p_vars->begin();
		 it != p_vars->end(); it++) {
		(*it)->express(this);
		newVec->push_back(last.tterms.tterm);
	    }
	    last.tterms.tterm = last.tterms.members = new Members(newVec);
	}
	virtual void uri (const URI* const self, std::string lexicalValue) {
	    last.tterms.tterm = last.tterms.uri = atomFactory ? atomFactory->getURI(lexicalValue.c_str()) : self;
	}
	virtual void variable (const Variable* const self, std::string lexicalValue) {
	    last.tterms.tterm = last.tterms.variable = atomFactory ? atomFactory->getVariable(lexicalValue.c_str()) : self;
	}
	virtual void bnode (const BNode* const self, std::string lexicalValue) {
	    last.tterms.tterm = atomFactory ? atomFactory->getBNode(lexicalValue.c_str(), &bnodeMap) : self;
	}
	virtual void rdfLiteral (const RDFLiteral* const self, std::string lexicalValue, const URI* datatype, const LANGTAG* p_LANGTAG) {
	    last.tterms.tterm = last.tterms.rdfLiteral = atomFactory ? atomFactory->getRDFLiteral(lexicalValue.c_str(), datatype, p_LANGTAG ? new LANGTAG(*p_LANGTAG) : NULL) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* const self, int p_value, const URI* p_datatype) {
	    std::stringstream s;
	    s << p_value;
	    last.tterms.tterm = last.tterms.numericRDFLiteral = atomFactory ? atomFactory->getNumericRDFLiteral(s.str().c_str(), p_value, p_datatype) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* const self, float p_value, const URI* p_datatype) {
	    std::stringstream s;
	    s << p_value;
	    last.tterms.tterm = last.tterms.numericRDFLiteral = atomFactory ? atomFactory->getNumericRDFLiteral(s.str().c_str(), p_value, p_datatype) : self;
	}
	virtual void rdfLiteral (const NumericRDFLiteral* const self, double p_value, const URI* p_datatype) {
	    std::stringstream s;
	    s << p_value;
	    last.tterms.tterm = last.tterms.numericRDFLiteral = atomFactory ? atomFactory->getNumericRDFLiteral(s.str().c_str(), p_value, p_datatype) : self;
	}
	virtual void rdfLiteral (const BooleanRDFLiteral* const self, bool p_value) {
	    last.tterms.tterm = last.tterms.booleanRDFLiteral = atomFactory ? atomFactory->getBooleanRDFLiteral(p_value ? "true" : "false", p_value) : self;
	}
	virtual void nulltterm (const NULLtterm* const /* self */) {
	    last.tterms.tterm = TTerm::Unbound;
	}

	virtual void predicate (const PropertyPath::Predicate* const, const URI* nested) {
	    nested->express(this);
	    last.pathBase = new PropertyPath::Predicate(last.tterms.uri);
	}
	virtual void inverse (const PropertyPath::Inverse* const, const PropertyPath::PathBase* nested) {
	    nested->express(this);
	    last.pathBase = new PropertyPath::Inverse(last.pathBase);
	}
	virtual void sequence (const PropertyPath::Sequence* const, const PropertyPath::PathBase* l, const PropertyPath::PathBase* r) {
	    l->express(this);
	    const PropertyPath::PathBase* l2 = last.pathBase;
	    r->express(this);
	    last.pathBase = new PropertyPath::Sequence(l2, last.pathBase);
	}
	virtual void alternative (const PropertyPath::Alternative* const, const PropertyPath::PathBase* l, const PropertyPath::PathBase* r) {
	    l->express(this);
	    const PropertyPath::PathBase* l2 = last.pathBase;
	    r->express(this);
	    last.pathBase = new PropertyPath::Alternative(l2, last.pathBase);
	    r->express(this);
	}
	virtual void repeated (const PropertyPath::Repeated* const, const PropertyPath::PathBase* nested, unsigned min, unsigned max) {
	    nested->express(this);
	    last.pathBase = new PropertyPath::Repeated(last.pathBase, min, max);
	}
	virtual void negated (const PropertyPath::Negated* const, const PropertyPath::PathBase* nested) {
	    nested->express(this);
	    last.pathBase = new PropertyPath::Negated(last.pathBase);
	}
	virtual void propertyPath (const PropertyPath* const, const PropertyPath::PathBase* nested) {
	    void* v = new PropertyPath(nested); // !! crime against nature, emulated in SPARQLParser
	    last.tterms.tterm = last.tterms.uri = (const URI*)v;
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
	virtual void bind (const Bind* const, const TableOperation* p_op, const Expression* expr, const Variable* label) {
	    p_op->express(this);
	    const TableOperation* op = last.tableOperation;
	    expr->express(this);
	    const Expression* e = last.expression;
	    label->express(this);
	    last.tableOperation = new Bind(op, e, last.tterms.variable);
	}
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
		if (last.tableOperation != NULL)  // make it easy for filters to eliminate conjoints.
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
	virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* atomFactory, bool lexicalCompare) {
	    p_TTerm->express(this);
	    const TTerm* name = last.tterms.tterm;
	    p_GroupGraphPattern->express(this);
	    last.tableOperation = new ServiceGraphPattern(name, last.tableOperation, p_Silence, atomFactory, lexicalCompare);
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
		last.solutionModifier = new SolutionModifier(n_groupBy, n_having, NULL, p_limit, p_offset);
	    }
	}
	virtual void valuesClause (const ValuesClause* const, const ResultSet* p_ResultSet) {
	    last.valuesClause = new ValuesClause(new ResultSet(*p_ResultSet));
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern) {
	    p_GroupGraphPattern->express(this);
	    const TableOperation* op = last.tableOperation;
	    last.whereClause = new WhereClause(op);
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
	    SolutionModifier* solutionModifier = last.solutionModifier;
	    last.operation = new Select(p_distinctness, varSet, _DatasetClauses(p_DatasetClauses), where, solutionModifier);
	}
	virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	    p_Select->express(this);
	    last.tableOperation = new SubSelect((const Select*)last.operation);
	}
	// !!!2 -- use ConstructableOperation for p_ConstructTemplate
	virtual void construct (const Construct* const, const TableOperation* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_ConstructTemplate->express(this);
	    TableOperation* construct = last.tableOperation;
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    SolutionModifier* solutionModifier = last.solutionModifier;
	    // !!!2 -- use ConstructableOperation for p 1
	    last.operation = new Construct(construct, _DatasetClauses(p_DatasetClauses), where, solutionModifier);
	}
	virtual void describe (const Describe* const, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_VarSet->express(this);
	    VarSet* varSet = last.varSets.varSet;
	    WhereClause* where = NULL;
	    if (p_WhereClause != NULL) {
		p_WhereClause->express(this);
		where = last.whereClause;
	    }
	    p_SolutionModifier->express(this);
	    SolutionModifier* solutionModifier = last.solutionModifier;
	    last.operation = new Describe(varSet, _DatasetClauses(p_DatasetClauses), where, solutionModifier);
	}
	virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    p_WhereClause->express(this);
	    WhereClause* where = last.whereClause;
	    p_SolutionModifier->express(this);
	    SolutionModifier* solutionModifier = last.solutionModifier;
	    last.operation = new Ask(_DatasetClauses(p_DatasetClauses), where, solutionModifier);
	}
	virtual void modify (const Modify* const, const Delete* p_delete, const Insert* p_insert, WhereClause* p_WhereClause, const URI* with, std::vector<s_UsingPair>* usingGraphs) {
	    const Delete* del = NULL;
	    if (p_delete != NULL) {
		p_delete->express(this);
		del = dynamic_cast<const Delete*>(last.operation);
	    }
	    const Insert* ins = NULL;
	    if (p_insert != NULL) {
		p_insert->express(this);
		ins = dynamic_cast<const Insert*>(last.operation);
	    }
	    p_WhereClause->express(this);
	    std::vector<s_UsingPair>* copiedUsingGraphs = NULL;
	    if (usingGraphs)
		copiedUsingGraphs = new std::vector<s_UsingPair>(usingGraphs->begin(), usingGraphs->end());
	    last.operation = new Modify(del, ins, last.whereClause, NULL, with, copiedUsingGraphs);
	}
	virtual void insert (const Insert* const, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    WhereClause* where = NULL;
	    if (p_WhereClause != NULL) {
		p_WhereClause->express(this);
		where = last.whereClause;
	    }
	    p_GraphTemplate->express(this);
	    last.operation = new Insert(last.tableOperation, where);
	}
	virtual void del (const Delete* const, bool rangeOverUnboundVars, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    WhereClause* where = NULL;
	    if (p_WhereClause != NULL) {
		p_WhereClause->express(this);
		where = last.whereClause;
	    }
	    p_GraphTemplate->express(this);
	    last.operation = new Delete(rangeOverUnboundVars, last.tableOperation, where);
	}
	virtual void load (const Load* const, e_Silence p_Silence, const URI* p_from, const URI* p_into) {
	    p_from->express(this);
	    const URI* from = last.tterms.uri;
	    if (p_into) {
		p_into->express(this);
		last.operation = new Load(p_Silence, from, last.tterms.uri);
	    } else {
		last.operation = new Load(p_Silence, from, NULL);
	    }
	}
	virtual void clear (const Clear* const, e_Silence p_Silence, const URI* p__QGraphIRI_E_Opt) {
	    last.tterms.tterm = NULL;
	    if (p__QGraphIRI_E_Opt != NULL)
		p__QGraphIRI_E_Opt->express(this);
	    last.operation = new Clear(p_Silence, last.tterms.uri);
	}
	virtual void create (const Create* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    last.operation = new Create(p_Silence, last.tterms.uri);
	}
	virtual void drop (const Drop* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	    p_GraphIRI->express(this);
	    last.operation = new Drop(p_Silence, last.tterms.uri);
	}
	virtual void add (const Add* const, e_Silence p_Silence, const URI* from, const URI* to) {
	    from->express(this);
	    const URI* f = last.tterms.uri;
	    to->express(this);
	    last.operation = new Add(p_Silence, f, last.tterms.uri);
	}
	virtual void move (const Move* const, e_Silence p_Silence, const URI* from, const URI* to) {
	    from->express(this);
	    const URI* f = last.tterms.uri;
	    to->express(this);
	    last.operation = new Move(p_Silence, f, last.tterms.uri);
	}
	virtual void copy (const Copy* const, e_Silence p_Silence, const URI* from, const URI* to) {
	    from->express(this);
	    const URI* f = last.tterms.uri;
	    to->express(this);
	    last.operation = new Copy(p_Silence, f, last.tterms.uri);
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
	virtual void aggregateCall (const AggregateCall* const, const URI* p_IRIref, const ArgList* p_ArgList, e_distinctness distinctness, const AggregateCall::ScalarVals* scalarVals) {
	    p_ArgList->express(this);
	    const ArgList* argList = last.argList;
	    p_IRIref->express(this);
	    AggregateCall::ScalarVals newScalarVals = scalarVals
		? AggregateCall::ScalarVals(scalarVals->begin(), scalarVals->end())
		: AggregateCall::ScalarVals();
	    last.functionCall = new AggregateCall(last.tterms.uri, distinctness, argList, newScalarVals);
	}
	virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	    last.expression = last.functionCall ? new FunctionCallExpression(last.functionCall) : NULL;
	}
	virtual void existsExpression (const ExistsExpression* const, const TableOperation* p_TableOperation) {
	    p_TableOperation->express(this);
	    last.expression = new ExistsExpression(last.tableOperation);
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
	virtual void naryIn (const NaryIn* const, const Expression* p_left, const ProductionVector<const Expression*>* p_right) {
	    ProductionVector<const Expression*>* v = _Expressions(p_right);
	    NaryIn* ret = new NaryIn(v);
	    // don't clear v; it's owned by ret.
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
		    autoAdd = lastBGP == NULL || nestingConj || lastInConj ? nestingConj : NULL;
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
	virtual void serviceGraphPattern (const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* atomFactory, bool lexicalCompare) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::serviceGraphPattern(self, p_TTerm, p_GroupGraphPattern, p_Silence, atomFactory, lexicalCompare);
	    pendingConjunction(outer);
	}
	virtual void subSelect (const SubSelect* const self, const Select* p_Select) {
	    NonConjunctionState outer = flushConjunction();
	    SWObjectDuplicator::subSelect(self, p_Select);
	    pendingConjunction(outer);
	}
    };

    struct GraphAndServiceMerger : public SWObjectDuplicator {
	/**
	 * ReferenceCounter - count how many times a variable is referenced
	 * in a query.
	 */
	struct TermReferenceCount : std::map<const TTerm*, int> {
	    std::string str () {
		std::stringstream ss;
		for (std::map<const TTerm*, int>::const_iterator it = begin();
		     it != end(); ++it) {
		    if (it != begin())
			ss << ", ";
		    ss << it->first->toString() << ": " << it->second;
		}
		return ss.str();
	    }
	};

	struct ReferenceCounter : public RecursiveExpressor {
	    TermReferenceCount& vars;
	    ReferenceCounter (TermReferenceCount& vars) : vars(vars) {  }
	    virtual void base (const Base* const /* self */, std::string /* productionName */) {  }
	    virtual void variable (const Variable* const self, std::string /* lexicalValue */) {
		vars[self]++;
	    }
	    /* specifically elide label->express(this) as labels in subselect
	       expression aliases do not consitute co-references, I think.
	    */
	    virtual void expressionAlias (const ExpressionAlias* const, const Expression* expr, const Bindable* /* label */) {
		expr->express(this);
	    }
	};

	const TTerm* lastGraphName;
	GraphGraphPattern* lastGraph;
	const TTerm* lastServiceName;
	ServiceGraphPattern* lastService;
	bool changed;
	TermReferenceCount termRefCount;
	bool elideSubSelect;

	GraphAndServiceMerger (AtomFactory* atomFactory)
	    : SWObjectDuplicator(atomFactory), lastGraphName(NULL), lastServiceName(NULL), changed(false) {  }
	virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    const TTerm* parentLastGraphName = lastGraphName; lastGraphName = NULL;
	    const TTerm* parentLastServiceName = lastServiceName; lastServiceName = NULL;

	    ProductionVector<TableOperation*> ops;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); it++) {
		(*it)->express(this);
		if (last.tableOperation != NULL)  // make it easy for filters to eliminate conjoints.
		    ops.push_back(last.tableOperation);
	    }
	    if (ops.size() == 1) {
		last.tableOperation = ops[0];
	    } else {
		TableConjunction* ret = new TableConjunction();
		last.tableOperation = ret;
		for (std::vector<TableOperation*>::const_iterator it = ops.begin();
		     it != ops.end(); it++)
		    ret->addTableOperation(*it, false);
		last.tableOperation = ret;
	    }
	    ops.clear(); // don't delete members.

	    lastGraphName = parentLastGraphName;
	    lastServiceName = parentLastServiceName;
	}
	virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	    p_TTerm->express(this);
	    const TTerm* name = last.tterms.tterm;
	    p_GroupGraphPattern->express(this);
	    lastGraphName = name;
	    last.tableOperation = lastGraph = new GraphGraphPattern(name, last.tableOperation);
	}
	virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* atomFactory, bool lexicalCompare) {
	    p_TTerm->express(this);
	    const TTerm* name = last.tterms.tterm;
	    ServiceGraphPattern* mergeMe = p_TTerm == lastServiceName ? lastService : NULL;
	    p_GroupGraphPattern->express(this);
	    if (mergeMe) {
		changed = true;
		TableConjunction* conj = new TableConjunction();
		conj->addTableOperation(mergeMe->m_TableOperation, true);
		conj->addTableOperation(last.tableOperation, true);
		BGPSimplifier b(atomFactory);
		conj->express(&b);
		delete conj;
		mergeMe->m_TableOperation = b.last.tableOperation;
		last.tableOperation = NULL;
	    } else {
		lastServiceName = name;
		last.tableOperation = lastService = new ServiceGraphPattern(name, last.tableOperation, p_Silence, atomFactory, lexicalCompare);
	    }
	}
	/** doesn't seem needed - EGP 20101226
	virtual void whereClause (const WhereClause* const self, const TableOperation* p_GroupGraphPattern) {
	    if (elideSubSelect)
		// just set last.tableOperation
		p_GroupGraphPattern->express(this);
	    else
		SWObjectDuplicator::whereClause(self, p_GroupGraphPattern);
	}
	*/
	bool _unneededProject (const ExpressionAliasList* eal) {
	    for (std::vector<const ExpressionAlias*>::const_iterator it = eal->begin();
		 it != eal->end(); ++it) {
		if (((*it)->label != NULL && termRefCount[(*it)->label] > 1) ||
		    ((*it)->label == NULL && dynamic_cast<const TTermExpression*>((*it)->expr) != NULL && termRefCount[dynamic_cast<const TTermExpression*>((*it)->expr)->getTTerm()] > 1))
		    return false;
	    }
	    return true;
	}
	virtual void whereClause (const WhereClause* const self, const TableOperation* p_GroupGraphPattern) {
	    if (elideSubSelect)
		p_GroupGraphPattern->express(this);
	    else
		SWObjectDuplicator::whereClause(self,  p_GroupGraphPattern);
	}
	virtual void select (const Select* const self, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    ExpressionAliasList* eal(dynamic_cast<ExpressionAliasList*>(p_VarSet));
	    if (eal != NULL && _unneededProject(eal)) {
		elideSubSelect = true;
		changed = true;
		p_WhereClause->express(this);
	    } else {
		SWObjectDuplicator::select(self, p_distinctness, p_VarSet, p_DatasetClauses, p_WhereClause, p_SolutionModifier);
	    }
	}
	virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	    bool parent_elideSubSelect(elideSubSelect);
	    elideSubSelect = false;
	    p_Select->express(this);
	    if (!elideSubSelect)
		last.tableOperation = new SubSelect((const Select*)last.operation);
	    elideSubSelect = parent_elideSubSelect;
	}
	TableOperation* apply(TableConjunction* conj) {
	    ReferenceCounter c(termRefCount);
	    conj->express(&c);
	    // w3c_sw_LINEN << *conj << "\n  had " << termRefCount.str() << std::endl;
	    conj->express(this);
	    if (changed) {
		delete conj;
		return last.tableOperation;
	    } else {
		delete last.tableOperation;
		return conj;
	    }
	}
    };

    struct SWObjectCanonicalizer : public SWObjectDuplicator {
	SWObjectCanonicalizer (AtomFactory* atomFactory)
	    : SWObjectDuplicator(atomFactory) {  }

	struct Root {
	    unsigned depth;
	    std::set<const TTerm*> peers;
	    Root () : depth(-1) {  }

	    void consider (const TTerm* peer, unsigned peerDepth) {
		if (peers.size() == 0 || depth >= peerDepth) {
		    if (depth > peerDepth)
			peers.clear();
		    depth = peerDepth;
		    peers.insert(peer);
		}
	    }
	    void consider (const Root& candidateRoot) {
		if (peers.size() == 0 || depth >= candidateRoot.depth) {
		    if (depth > candidateRoot.depth)
			peers.clear();
		    depth = candidateRoot.depth;
		    for (std::set<const TTerm*>::const_iterator peer = candidateRoot.peers.begin();
			 peer != candidateRoot.peers.end(); ++peer)
			peers.insert(*peer);
		}
	    }
	};

	struct DepthList {
	    Root root;
	    std::map<const TTerm*, unsigned> leads;
	    std::map<const TTerm*, unsigned> touched;
	    void print (std::ostream& os) const {
		//assert(leads.size()>1 || root.peers.size()>1);
		if (root.peers.size() > 0) {
		    os << "roots: ";
		    for (std::set<const TTerm*>::const_iterator it = root.peers.begin();
			 it != root.peers.end(); ++it)
			os << (*it)->toString();
		    os << "@" << root.depth;
		}
		if (leads.size() > 0) {
		    os << "leads: ";
		    for (std::map<const TTerm*, unsigned>::const_iterator via = leads.begin();
			 via != leads.end(); ++via) {
			if (via != leads.begin())
			    os << "|";
			os << via->first->toString() << "@" << via->second;
		    }
		}
		if (touched.size() > 0) {
		    os << " touched: ";
		    for (std::map<const TTerm*, unsigned>::const_iterator touch = touched.begin();
			 touch != touched.end(); ++touch) {
			if (touch != touched.begin())
			    os << ",";
			os << touch->first->toString() << "@" << touch->second;
		    }
		}
	    }
	};

	struct ObjectOf : public std::map<const TTerm*, DepthList> {
	    void print (std::ostream& os) const {
		for (ObjectOf::const_iterator it = begin();
		     it != end(); ++it) {
		    os << it->first->toString() << ": ";
		    it->second.print(os);
		    os << std::endl;
		}
	    }
	    unsigned depthOf (const TTerm* t) const {
		ObjectOf::const_iterator it = find(t);
		return it == end() ? 0 : it->second.root.depth;
	    }
	};

	struct DepthTriple {
	    unsigned depth;
	    const TriplePattern* triple;
	    const ObjectOf& oo;
	    AtomFactory* atomFactory;
	    DepthTriple(const TriplePattern* triple, const ObjectOf& oo, AtomFactory* atomFactory)
		: depth(oo.depthOf(triple->getS())), triple(triple), oo(oo), atomFactory(atomFactory) {  }
	    bool operator< (const DepthTriple& ref) const {
		if (depth != ref.depth)
		    return depth < ref.depth;
		return *triple < *ref.triple;
	    }
	};

	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const ProductionVector<const TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
	    /*
	     * A → B   D
	     * ↓ ↖ ↓   ↓
	     * F   C → E
	     */
	    ObjectOf work;
	    std::set<const TTerm*> subjects;
	    size_t pendingLeads = 0;

	    for (std::vector<const TriplePattern*>::const_iterator t = p_TriplePatterns->begin();
		 t != p_TriplePatterns->end(); ++t) {
		work[(*t)->getO()].leads[(*t)->getS()] = 1;
		++pendingLeads;
		subjects.erase((*t)->getO());
		if (work.find((*t)->getS()) == work.end())
		    subjects.insert((*t)->getS());
		/* !!! <s> <p> <s> . */
	    }

	    /* A: C
	     * B: A
	     * F: A|C
	     * C: B
	     * E: C+D
	     */
	    for (unsigned gen = 1; pendingLeads > 0 && gen < 5; ++gen) {
		pendingLeads = 0;
		// work.print(std::cerr);
		for (ObjectOf::iterator oo = work.begin();
		     oo != work.end(); ) {
		    /* A		 * B		 * F		 * C		 * E		 */
		    const TTerm* goal = oo->first;
		    // std::cerr << *goal;

		    std::map<const TTerm*, unsigned> nextLeads;
		    Root candidateRoot;
		    /* (C)		 * (A)		 * (AC)		 * (B)		 * (CD)		 */
		    for (std::map<const TTerm*, unsigned>::const_iterator leads = oo->second.leads.begin();
			 leads != oo->second.leads.end(); ++leads) {
			const TTerm* lead = leads->first;
			unsigned curDistance = leads->second;
			ObjectOf::const_iterator follow = work.find(lead);
			oo->second.touched[lead] = gen;
			if (follow == work.end()) {
			    // std::cerr << " finished with " << *lead << " in " << gen << " generations\n";
			    candidateRoot.consider(lead, gen);
			} else {
			    /* C:1		 * A:1		 * A:1,C:1	 * B:1		 * C:1,D:1	 */
			    // if (leads != oo->second.leads.begin())
			    //     std::cerr << "   ";
			    // std::cerr << " following " << *lead << " to (";
			    /* (B)		 * (A)		 * (AC)		 * (B)		 * (CD)		 */
			    for (std::map<const TTerm*, unsigned>::const_iterator followLead = follow->second.leads.begin();
				 followLead != follow->second.leads.end(); ++followLead) {
				const TTerm* gp = followLead->first;
				unsigned nextDepth = curDistance + followLead->second;
				if (gp == goal) {
				    // std::cerr << "!";
				    oo->second.touched[gp] = nextDepth;
				    candidateRoot.consider(gp, nextDepth);
				} else
				    nextLeads[gp] = nextDepth;
				// std::cerr << *gp << "@" << curDistance + followLead->second;
			    }
			    if (follow->second.leads.size() == 0 && follow->second.root.peers.size() > 0 && nextLeads.size() == 0) {
				Root followedRoot(follow->second.root);
				++followedRoot.depth;
				candidateRoot.consider(followedRoot);
			    }
			    for (std::map<const TTerm*, unsigned>::const_iterator t = follow->second.touched.begin();
				 t != follow->second.touched.end(); ++t)
				if (oo->second.touched.find(t->first) != oo->second.touched.end()) {
				    std::stringstream ss;
				    // ss << t->first->toString() << "[" << oo->second.touched[t->first] << "]/" << t->first->toString() << "[" << t->second + gen << "] ";
				    // std::cerr << ss.str();
				} else {
				    if (t->first == goal) {
					// std::cerr << "^";
					candidateRoot.consider(t->first, t->second + gen);
				    }
				    oo->second.touched[t->first] = t->second + gen;
				}
			    // std::cerr << ")" << std::endl;
			}
		    }
		    if (nextLeads.size() == 0 && candidateRoot.peers.size() > 0)
			oo->second.root.consider(candidateRoot);
		    oo->second.leads = nextLeads;
		    pendingLeads += nextLeads.size();
		    // std::cerr << *goal << "-";
		    // oo->second.print(std::cerr);
		    // std::cerr << std::endl;
		    ++oo;
		}
	    }
	    // work.print(std::cerr);

	    std::set<DepthTriple> ordered; // @@@ would like const DepthTriple
	    for (std::vector<const TriplePattern*>::const_iterator t = p_TriplePatterns->begin();
		 t != p_TriplePatterns->end(); ++t) {
		const DepthTriple dt(*t, work, atomFactory);
		ordered.insert(dt);
		//	    *ret += (*t)->copy();
	    }
	    for (std::set<DepthTriple>::const_iterator it = ordered.begin();
		 it != ordered.end(); ++it)
		p->addTriplePattern(it->triple);
	}

	struct TableOperationSorter {

	    typedef enum { DT_Err, DT_DefaultGraphPattern, DT_NamedGraphPattern, 
			   DT_GraphGraphPattern, DT_ServiceGraphPattern,
			   DT_TableConjunction, DT_TableDisjunction,
			   DT_Filter, DT_OptionalGraphPattern,
			   DT_MinusGraphPattern} DT_TableOperationSortOrder;

	    AtomFactory* atomFactory;
	    TableOperationSorter (AtomFactory* atomFactory)
		: atomFactory(atomFactory) {  }
	    struct OperationSorter : public RecursiveExpressor {
		struct RHSslave : public RecursiveExpressor {
		    AtomFactory* atomFactory;
		    e_SORT ret;
		    RHSslave (AtomFactory* atomFactory) : atomFactory(atomFactory), ret(SORT_error) {  }
		    virtual void base (const Base* const, std::string) { throw "OperationSorter::RHSslave::base should not be called.";}
		    virtual void defaultGraphPattern(const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
		    virtual void namedGraphPattern(const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
		    virtual void graphGraphPattern(const GraphGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) = 0;
		    virtual void serviceGraphPattern(const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* atomFactory, bool lexicalCompare) = 0;
		    virtual void optionalGraphPattern(const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) = 0;
		    virtual void minusGraphPattern(const MinusGraphPattern* const self, const TableOperation* p_GroupGraphPattern) = 0;
		    virtual void filter(const Filter* const self, const TableOperation* p_op, const ProductionVector<const w3c_sw::Expression*>* p_Constraints) = 0;
		    virtual void tableConjunction(const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
		    virtual void tableDisjunction(const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
		    virtual void operationSet(const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) = 0;
		};

		/* BasicGraphPattern-derived types: DefaultGraphPattern, NamedGraphPattern */
		struct _BasicGraphPattern : public RHSslave {
		    const ProductionVector<const TriplePattern*>* lhs;
		    _BasicGraphPattern (AtomFactory* atomFactory, const ProductionVector<const TriplePattern*>* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    e_SORT _basicGraphPattern (const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
			std::vector<const TriplePattern*>::const_iterator ltriple = lhs->begin();
			std::vector<const TriplePattern*>::const_iterator rtriple = p_TriplePatterns->begin();
			while (ltriple != lhs->end() && rtriple != p_TriplePatterns->end()) {
			    if (*ltriple != *rtriple)
				return (*ltriple)->safeCmp(**rtriple);
			    ++ltriple;
			    ++rtriple;
			}
			return SORT_eq;
		    }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_lt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_lt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>*) { ret = SORT_lt; }
		};
		struct RHS_defaultGraphPattern : public _BasicGraphPattern {
		    bool l_allOpts;
		    RHS_defaultGraphPattern (AtomFactory* atomFactory, bool l_allOpts, const ProductionVector<const TriplePattern*>* l_TriplePatterns)
			: _BasicGraphPattern(atomFactory, l_TriplePatterns), l_allOpts(l_allOpts) {  }
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
			ret = _basicGraphPattern(p_TriplePatterns);
		    }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_lt; }
		};
		struct RHS_namedGraphPattern : public _BasicGraphPattern {
		    const TTerm* l_name;
		    bool l_allOpts;
		    RHS_namedGraphPattern (AtomFactory* atomFactory, const TTerm* l_name, bool l_allOpts, const ProductionVector<const TriplePattern*>* l_TriplePatterns)
			: _BasicGraphPattern(atomFactory, l_TriplePatterns), l_name(l_name), l_allOpts(l_allOpts) {  }
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
			ret = l_name != p_name ? l_name->cmp(*p_name) : _basicGraphPattern(p_TriplePatterns);
		    }
		};


		/* TableOperationOnOperation-derived types: Filter ServiceGraphPattern GraphGraphPattern OptionalGraphPattern MinusGraphPattern */
		struct _TableOperationOnOperation : public RHSslave {
		    const TableOperation* lhs;
		    _TableOperationOnOperation (AtomFactory* atomFactory, const TableOperation* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    e_SORT _tableOperationOnOperation(const TableOperation* p_TableOperation);
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }

		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>*) { ret = SORT_lt; }
		};
		struct RHS_graphGraphPattern : public _TableOperationOnOperation {
		    const TTerm* l_TTerm;
		    RHS_graphGraphPattern (AtomFactory* atomFactory, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_TTerm(p_TTerm) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
			ret = l_TTerm != p_TTerm ? l_TTerm->cmp(*p_TTerm) : _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_lt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_serviceGraphPattern : public _TableOperationOnOperation {
		    const TTerm* l_TTerm;
		    RHS_serviceGraphPattern (AtomFactory* atomFactory, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence, bool)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_TTerm(p_TTerm) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence, AtomFactory*, bool) {
			ret = l_TTerm != p_TTerm ? l_TTerm->cmp(*p_TTerm) : _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_optionalGraphPattern : public _TableOperationOnOperation {
		    const ProductionVector<const w3c_sw::Expression*>* l_Expressions;
		    RHS_optionalGraphPattern (AtomFactory* atomFactory, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_Expressions(p_Expressions) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>*) {
			// !!! ret = l_Expressions != p_TTerm ? atomFactory->cmp(l_Expressions, p_TTerm) : 
			ret = _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_minusGraphPattern : public _TableOperationOnOperation {
		    RHS_minusGraphPattern (AtomFactory* atomFactory, const TableOperation* p_GroupGraphPattern)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
			ret = _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_filter : public _TableOperationOnOperation {
		    const ProductionVector<const w3c_sw::Expression*>* l_Expressions;
		    RHS_filter (AtomFactory* atomFactory, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_Expressions(p_Expressions) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_gt; }
		    virtual void filter (const Filter* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>*) {
			// !!! ret = l_Expressions != p_TTerm ? atomFactory->cmp(l_Expressions, p_TTerm) : 
			ret = _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		};

		/* TableJunction-derived types: TableConjunction, TableDisjunction */
		struct _TableJunction : public RHSslave {
		    const ProductionVector<const TableOperation*>* lhs;
		    _TableJunction (AtomFactory* atomFactory, const ProductionVector<const TableOperation*>* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    e_SORT _tableJunction(const ProductionVector<const TableOperation*>* p_TableOperations);
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_gt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }

		    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>*) { ret = SORT_lt; }
		};
		struct RHS_tableConjunction : public _TableJunction {
		    RHS_tableConjunction (AtomFactory* atomFactory, const ProductionVector<const TableOperation*>* p_TableOperations)
			: _TableJunction(atomFactory, p_TableOperations) {  }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
			ret = _tableJunction(p_TableOperations);
		    }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		};
		struct RHS_tableDisjunction : public _TableJunction {
		    RHS_tableDisjunction (AtomFactory* atomFactory, const ProductionVector<const TableOperation*>* p_TableOperations)
			: _TableJunction(atomFactory, p_TableOperations) {  }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_gt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
			ret = _tableJunction(p_TableOperations);
		    }
		};

		struct RHS_operationSet : public RHSslave {
		    const ProductionVector<const Operation*>* lhs;
		    RHS_operationSet (AtomFactory* atomFactory, const ProductionVector<const Operation*>* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, e_Silence, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_gt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void operationSet(const OperationSet* const, const ProductionVector<const Operation*>*);
		};
		/* END of slave sorters */


		AtomFactory* atomFactory;
		const TableOperation* rhs;
		e_SORT ret;
		OperationSorter (AtomFactory* atomFactory, const TableOperation* rhs)
		    : atomFactory(atomFactory), rhs(rhs), ret(SORT_error) {  }
		virtual void base (const Base* const, std::string) { throw "OperationSorter::base should not be called.";}
		virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		    RHS_defaultGraphPattern slave(atomFactory, p_allOpts, p_TriplePatterns);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		    RHS_namedGraphPattern slave(atomFactory, p_name, p_allOpts, p_TriplePatterns);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
		    RHS_graphGraphPattern slave(atomFactory, p_TTerm, p_GroupGraphPattern);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* atomFactory, bool lexicalCompare) {
		    RHS_serviceGraphPattern slave(atomFactory, p_TTerm, p_GroupGraphPattern, p_Silence, lexicalCompare);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
		    RHS_optionalGraphPattern slave(atomFactory, p_GroupGraphPattern, p_Expressions);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
		    RHS_minusGraphPattern slave(atomFactory, p_GroupGraphPattern);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void filter (const Filter* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Constraints) {
		    RHS_filter slave(atomFactory, p_GroupGraphPattern, p_Constraints);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
		    RHS_tableConjunction slave(atomFactory, p_TableOperations);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
		    RHS_tableDisjunction slave(atomFactory, p_TableOperations);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
		    RHS_operationSet slave(atomFactory, p_Operations);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		
	    };
	    bool operator () (const TableOperation* lhs, const TableOperation* rhs) {
		OperationSorter os(atomFactory, rhs);
		lhs->express(&os);
		return os.ret == SORT_lt;
	    }
	};


	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (const ProductionVector<const TableOperation*>* p_TableOperations, TableJunction* j) {
	    ProductionVector<const TableOperation*> ops;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
	    	 it != p_TableOperations->end(); it++) {
	    	(*it)->express(this);
	    	ops.push_back(last.tableOperation);
	    }
	    std::sort(ops.begin(), ops.end(), TableOperationSorter(atomFactory));
	    for (std::vector<const TableOperation*>::const_iterator it = ops.begin();
	    	 it != ops.end(); it++)
		j->addTableOperation(*it, false);
	    ops.clear(); // don't delete members.
	}

	virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    TableConjunction* ret = new TableConjunction();
	    _TableOperations(p_TableOperations, ret);
	    GraphAndServiceMerger m(atomFactory);
	    TableOperation* op = m.apply(ret);
	    if (m.changed) {

		/** Eliminate adjoining conjoints. */
		BGPSimplifier b(atomFactory);
		op->express(&b);
		delete op;

		/** Canonicalize (e.g. order triple patterns). */
		b.last.tableOperation->express(this);
		delete b.last.tableOperation;
	    } else
		last.tableOperation = op;
	    // last.tableOperation = GraphAndServiceMerger(atomFactory).apply(ret);
	}

    };

    inline e_SORT SWObjectCanonicalizer::TableOperationSorter::OperationSorter::_TableOperationOnOperation::_tableOperationOnOperation (const TableOperation* p_TableOperation) {
	OperationSorter s(atomFactory, lhs);
	p_TableOperation->express(&s);
	return s.ret;
    }

    inline e_SORT SWObjectCanonicalizer::TableOperationSorter::OperationSorter::_TableJunction::_tableJunction (const ProductionVector<const TableOperation*>* p_TableOperations) {
	std::vector<const TableOperation*>::const_iterator lop = lhs->begin();
	std::vector<const TableOperation*>::const_iterator rop = p_TableOperations->begin();
	while (lop != lhs->end() && rop != p_TableOperations->end()) {
	    OperationSorter s(atomFactory, *lop);
	    (*rop)->express(&s);
	    if (s.ret != SORT_eq)
		return s.ret;
	    ++lop;
	    ++rop;
	}
	return SORT_eq;
    }

    inline void SWObjectCanonicalizer::TableOperationSorter::OperationSorter::RHS_operationSet::operationSet(const OperationSet* const, const ProductionVector<const Operation*>*) {
	w3c_sw_NEED_IMPL("extend sorter to sort Operations");
    }


} // namespace w3c_sw

#endif // SWObjectDuplicator_H

