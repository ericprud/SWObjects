/* RuleInverter.hpp - create a SPARQL CONSTRUCT rule that follows 
 * http://www.w3.org/2008/07/MappingRules/#_02
 *
 * $Id: RuleInverter.hpp,v 1.5.2.1 2008-09-12 03:17:48 eric Exp $
 */

#ifndef RuleInverter_H
#define RuleInverter_H

#include "SWObjectDuplicator.hpp"
#include "POS2BGPMap.hpp"
#include <set>

namespace w3c_sw {

    class OperationResultSet : public ResultSet {
    protected:
	TableDisjunction* constructed;
    public:
	OperationResultSet (TableDisjunction* constructed) : ResultSet(), constructed(constructed) {  }
	void addTableOperation (TableOperation* op) { constructed->addTableOperation(op); }
    };

    class MappingConstruct : public Construct {

	class MappedDuplicator : public SWObjectDuplicator {
	protected:
	    ConsequentMap* includeRequiredness;
	    Result* row;
	public:
	    MappedDuplicator (POSFactory* posFactory, Result* row, ConsequentMap* includeRequiredness) : SWObjectDuplicator(posFactory), includeRequiredness(includeRequiredness), row(row) {  }
	    TableOperation* getTableOperation () { return tableOperation; }


	    virtual void _TriplePatterns (ProductionVector<TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
		for (std::vector<TriplePattern*>::iterator triple = p_TriplePatterns->begin();
		     triple != p_TriplePatterns->end(); triple++)
		    (*triple)->construct(p, row);
	    }

	    virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
		SWObjectDuplicator::namedGraphPattern(p_name, p_allOpts, p_TriplePatterns, p_Filters);
		return NULL;
	    }
	    virtual DefaultGraphPattern* defaultGraphPattern (bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
		SWObjectDuplicator::defaultGraphPattern(p_allOpts, p_TriplePatterns, p_Filters);
		return NULL;
	    }
	    /* Overload SWObjectDuplicator::_TableOperations to handle tree depletion. */
	    virtual void _TableOperations (ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
		for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    tableOperation = NULL;
		    (*it)->express(this);
		    if (tableOperation != NULL)
			j->addTableOperation(tableOperation);
		}
	    }
	    virtual TableDisjunction* tableDisjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
		SWObjectDuplicator::tableDisjunction(p_TableOperations, p_Filters);
		return NULL;
	    }
	    virtual TableConjunction* tableConjunction (ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
		SWObjectDuplicator::tableConjunction(p_TableOperations, p_Filters);
		return NULL;
	    }
	    virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
		BasicGraphPattern* bgp = dynamic_cast<BasicGraphPattern*>(p_GroupGraphPattern);
		ConsequentMap::iterator it;
		if (bgp != NULL && (it = includeRequiredness->find(bgp)) != includeRequiredness->end()) {
		    if (it->second == Binding_STRONG) {
			// let p_GroupGraphPattern set tableOperation
			p_GroupGraphPattern->express(this);
			return NULL;
		    } else {
			std::cerr << "OPTIONAL: " << includeRequiredness->find(bgp)->second << std::endl;
			OptionalGraphPattern* ret = SWObjectDuplicator::optionalGraphPattern(p_GroupGraphPattern);
			tableOperation = ret;
			return NULL;
		    }
		}
		tableOperation = NULL;
		return NULL;
	    }
	    virtual GraphGraphPattern* graphGraphPattern (POS* p_POS, TableOperation* p_GroupGraphPattern) {
		GraphGraphPattern* ret = SWObjectDuplicator::graphGraphPattern(p_POS, p_GroupGraphPattern);
		tableOperation = ret;
		return NULL;
	    }
	};


    private:
	TableOperation* m_MappedAntecedent;
	Consequents consequents;
	POSFactory* posFactory;

    public:
	MappingConstruct (TableOperation* p_MappedAntecedent, ProductionVector<DatasetClause*>* p_DatasetClauses, 
			  WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier, POSFactory* posFactory) : 
	    Construct(NULL, p_DatasetClauses, p_WhereClause, p_SolutionModifier), 
	    m_MappedAntecedent(p_MappedAntecedent), consequents(p_MappedAntecedent), posFactory(posFactory)
	{  }
	~MappingConstruct () {
	    delete m_MappedAntecedent;
	}
	Variable* _genVar (Variable* base, int index, Result* row) {
	    Variable* ret = NULL;
	    do {
		std::stringstream name;
		name << base->getTerminal() << "_gen" << index;
		ret = posFactory->getVariable(name.str().c_str());
		++index;
	    } while (row->get(ret) != NULL);
	    return ret;
	}
	virtual OperationResultSet* execute (RdfDB* db, ResultSet* rs = NULL) {
	    OperationResultSet* opRS = dynamic_cast<OperationResultSet*>(rs);
	    if (opRS == NULL)
		throw(std::runtime_error("MappingConstrucs need a result set.")); // @@ shouldn't happen? consequents[pos][bgp] = false;

	    /* 04 — Execute the query C on the query disjoint D, producing a result set RScd.
	     * http://www.w3.org/2008/07/MappingRules/#_04
	     */
	    m_WhereClause->bindVariables(db, opRS);

	    /* 05 — For each rule solution S in RScd:
	     * http://www.w3.org/2008/07/MappingRules/#_05
	     */

	    for (ResultSetIterator row = opRS->begin() ; row != opRS->end(); ++row) {

		/* Set of { BGP => optional } associations to indicate if the BGP is optional. */
		ConsequentMap includeRequiredness;
		std::set<Variable*> neededVars;

		int genNo = 0;
		/* 06 — Scan each basic graph pattern GA in the antecedent graph pattern A for variables in triple patterns:
		 * http://www.w3.org/2008/07/MappingRules/#_06
		 */
		for (ConsequentMapList::iterator maps = consequents.begin();
		     maps != consequents.end(); ++maps) {
		    Variable* v = dynamic_cast<Variable*>(maps->first);
		    if (v == NULL)
			break;

		    for (ConsequentMap::iterator bgpBindings = maps->second.begin();
			 bgpBindings != maps->second.end(); ++bgpBindings) {
			/* 06a — If the variable is not weak in S or GA is not optional, tag GA as an included mandatory.
			 * 06b — If the variable is weak in S and GA is optional and the variable is not in any mandatory antecedent graph, tag GA as an included optional.
			 * 06c — If the variable is not bound in S, bind it to a novel variable e.g. ?B_gen1
			 * http://www.w3.org/2008/07/MappingRules/#_06a
			 * Note that optional variables that are in a mandatory antecedent graph are already removed from consequents.
			 */
			if ((*row)->find(v) == (*row)->end()) {
			    /* The BGP introduces v, which has no correspondence in our query. */
			    neededVars.insert(v);
			    if (bgpBindings->second == Binding_WEAK) {
				/* It's optional, so omit it. !!
				   This is acutally unsound as we may
				   want to include any OPT which
				   introduces constraints used by a
				   later included OPT.
				 */
#warning not including dependent optionals yet
				continue;
			    }
			}
			includeRequiredness[bgpBindings->first] = (bgpBindings->second == Binding_STRONG || 
								   (*row)->get(v) == false) ? Binding_WEAK : Binding_STRONG;
		    }
		    
		}

		for (std::set<Variable*>::iterator v = neededVars.begin();
		     v != neededVars.end(); ++v)
		    opRS->set(*row, *v, _genVar(*v, genNo++, *row), true);
		neededVars.clear();

		/* 07 — Substitute the values in S for the variables in A.
		 * 08 — Create a stem query disjoint DQS which is a reproduction of the mapping rule antecedent A
		 * http://www.w3.org/2008/07/MappingRules/#_07
		 */
		MappedDuplicator e(posFactory, *row, &includeRequiredness);
		m_MappedAntecedent->express(&e);
		opRS->addTableOperation(e.getTableOperation());
	    }
	    DefaultGraphPattern g;
	    //m_MappedAntecedent->construct(&g, opRS);
	    //	    SPARQLSerializer s2; r->express(&s2); std::cerr << "CONSTRUCTED: " << s2.getSPARQLstring() << std::endl;
	    //	    delete r;
	    return opRS;
	}
    };

    class RuleInverter : public SWObjectDuplicator {
    protected:
	DefaultGraphPattern* m_ConstructTemplate;
	TableOperation* m_GroupGraphPattern;
	MappingConstruct* m_Construct;
    public:
	RuleInverter (POSFactory* posFactory) : 
	    SWObjectDuplicator(posFactory) {  }

	MappingConstruct* getConstruct() { return m_Construct; }

	/* Create BasicGraphPatterns (named and default) with a flag
	 * indicating the special semantics of all triples being
	 * optional (03).
	 */
	virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    p_name->express(this);
	    NamedGraphPattern* ret = new NamedGraphPattern(pos, true); // allOpts = true
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	    return NULL;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern(true); // allOpts = true
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    tableOperation = ret;
	    return NULL;
	}

	virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    if (p_BindingClause != NULL)
		throw(std::runtime_error("Don't know how to invert a Construct with a BindingClause."));

	    /* store the original antecedent (p_GroupGraphPattern) and create
	     * a new graph pattern with the original consequent
	     * (m_ConstructTemplate).
	     */
	    m_GroupGraphPattern = p_GroupGraphPattern;
	    m_ConstructTemplate->express(this);
	    m_bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);
	    m_whereClause = new WhereClause(tableOperation, m_bindingClause);
	    return NULL;
	}

	virtual MappingConstruct* construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    if (p_DatasetClauses->size() != 0)
		throw(std::runtime_error("Don't know how to invert a Construct with a DatasetClauses."));
	    m_ConstructTemplate = p_ConstructTemplate;
	    p_WhereClause->express(this);

	    /* create a new CONSTRUCT with the consequent of the old
	     * query (m_ConstructTemplate) treated as where clause.
	     *
	     * # 03 — Treat C as a query, each triple being optional.
	     * http://www.w3.org/2008/07/MappingRules/#_03
	     */
	    m_GroupGraphPattern->express(this); // sets tableOperation
	    p_SolutionModifier->express(this);
	    m_Construct = new MappingConstruct(tableOperation, _DatasetClauses(p_DatasetClauses), m_whereClause, m_solutionModifier, posFactory);
	    operation = m_Construct;
	    return NULL;
	}

	/* RuleInverter only works on CONSTRUCTs. All other verbs
	 * get a run-time error. (A compile-time error would be nice, but the
	 * expressor interface prevents that.
	 */
	virtual Select* select (e_distinctness, VarSet*, ProductionVector<DatasetClause*>*, WhereClause*, SolutionModifier*) {
	    throw(std::runtime_error("RuleInverter only works on CONSTRUCTs."));
	}
	// @@ should be similar errors for ASK, DESCRIBE and all SPARUL verbs.

    };

} // namespace w3c_sw

#endif // RuleInverter_H

