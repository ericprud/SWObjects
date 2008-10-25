/* RuleInverter.hpp - create a SPARQL CONSTRUCT rule that follows 
 * http://www.w3.org/2008/07/MappingRules/#_02
 *
 * $Id: RuleInverter.hpp,v 1.21 2008-10-25 23:36:03 eric Exp $
 */

#ifndef RuleInverter_H
#define RuleInverter_H

#include "SWObjectDuplicator.hpp"
#include "POS2BGPMap.hpp"
#include "SPARQLSerializer.hpp" // for debugging output
#include <set>
#include <algorithm>

namespace w3c_sw {

    class OperationResultSet : public ResultSet {
	class FilterCopier : public RecursiveExpressor {
	    class FilterDuplicator : public SWObjectDuplicator {

	    public:
		FilterDuplicator (POSFactory* posFactory) : SWObjectDuplicator(posFactory) {  }
		Filter* getFilter () { return last.filter; }
	    };
	    
	protected:
	    TableOperation* dest;

	public:
	    FilterCopier (TableOperation* dest) : dest(dest) {  }

	    virtual void base (Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

	    virtual void filter (Filter* self, w3c_sw::Expression*) {
		FilterDuplicator fd(NULL); // requires the same POSFactory.
		self->express(&fd);
		dest->addFilter(fd.getFilter());
	    }
	    virtual void namedGraphPattern (NamedGraphPattern*, w3c_sw::POS* /*p_name*/, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* /*p_TriplePatterns*/, ProductionVector<w3c_sw::Filter*>* p_Filters) {
		p_Filters->express(this);
	    }
	    virtual void defaultGraphPattern (DefaultGraphPattern*, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* /*p_TriplePatterns*/, ProductionVector<w3c_sw::Filter*>* p_Filters) {
		p_Filters->express(this);
	    }

	};
    protected:
	TableDisjunction* constructed;
	TableOperation* userQueryDisjoint;

    public:
	OperationResultSet (TableDisjunction* constructed, TableOperation* userQueryDisjoint) : 
	    ResultSet(), constructed(constructed), userQueryDisjoint(userQueryDisjoint) {  }
	void addTableOperation (TableOperation* op) { constructed->addTableOperation(op); }
	void copyFiltersTo (TableOperation* dest) {
	    /* Copy the FILTER patterns across.
	       !!! This isn't sound -- requires more exploration.
	    */
	    FilterCopier c(dest);
	    userQueryDisjoint->express(&c);
	}
    };

    /* MappingConstruct — extends Construct::execute to peform steps 4 through 8
     *                    in http://www.w3.org/2008/07/MappingRules/#_04 .
     */
    class MappingConstruct : public Construct {

	/* MappedDuplicator — 
	 * • reproduce all portions of the constructRuleBodyAsConsequent which
	 *   are implicated in constructed patterns which might be matched by
	 *   the user's query.
	 * • substituted variables and constants from the user query by calling
         *   construct on each triple pattern.
	 */
	class MappedDuplicator : public SWObjectDuplicator {

	protected:
	    ConsequentMap* includeRequiredness;
	    Result* row;
	public:
	    MappedDuplicator (POSFactory* posFactory, Result* row, ConsequentMap* includeRequiredness) : SWObjectDuplicator(posFactory), includeRequiredness(includeRequiredness), row(row) {  }
	    TableOperation* getTableOperation () { return last.tableOperation; }


	    virtual void _TriplePatterns (ProductionVector<TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
		for (std::vector<TriplePattern*>::iterator triple = p_TriplePatterns->begin();
		     triple != p_TriplePatterns->end(); triple++)
		    (*triple)->construct(p, row, posFactory, false);
	    }

	    /* Overload SWObjectDuplicator::_TableOperations to handle tree depletion. */
	    virtual void _TableOperations (ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
		for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    last.tableOperation = NULL;
		    (*it)->express(this);
		    if (last.tableOperation != NULL)
			j->addTableOperation(last.tableOperation);
		}
	    }

	    virtual void namedGraphPattern999 (NamedGraphPattern* self, w3c_sw::POS* p_name, bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::namedGraphPattern (self, p_name, p_allOpts, p_TriplePatterns, p_Filters);
		}
	    }
	    virtual void defaultGraphPattern999 (DefaultGraphPattern* self, bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::defaultGraphPattern (self, p_allOpts, p_TriplePatterns, p_Filters);
		}
	    }
	    virtual void tableConjunction999 (TableConjunction* self, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::tableConjunction (self, p_TableOperations, p_Filters);
		}
	    }
	    virtual void tableDisjunction999 (TableDisjunction* self, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::tableDisjunction (self, p_TableOperations, p_Filters);
		}
	    }
	    virtual void optionalGraphPattern (OptionalGraphPattern* self, TableOperation* p_GroupGraphPattern) {
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(p_GroupGraphPattern);
		if (s != GraphInclusion_NONE) {
		    if (s == GraphInclusion_STRONG)
			// let p_GroupGraphPattern set last.tableOperation
			p_GroupGraphPattern->express(this);
		    else
			SWObjectDuplicator::optionalGraphPattern(self, p_GroupGraphPattern);
		}
	    }
	    virtual void graphGraphPattern999 (GraphGraphPattern* self, w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
		FAIL("don't know how to deal with a graphGraphPattern in a stem query");
	    }
	};


    private:
	TableOperation* constructRuleBodyAsConsequent;
	Consequents consequents;
	POSFactory* posFactory;
	std::ostream** debugStream;

    public:
	MappingConstruct (TableOperation* constructRuleBodyAsConsequent, ProductionVector<DatasetClause*>* p_DatasetClauses, 
			  WhereClause* constructRuleHeadAsPattern, SolutionModifier* p_SolutionModifier, POSFactory* posFactory, std::ostream** debugStream) : 
	    Construct(NULL, p_DatasetClauses, constructRuleHeadAsPattern, p_SolutionModifier), 
	    constructRuleBodyAsConsequent(constructRuleBodyAsConsequent), 
	    consequents(constructRuleBodyAsConsequent, NULL, debugStream), 
	    posFactory(posFactory), debugStream(debugStream)
	{  }
	~MappingConstruct () {
	    delete constructRuleBodyAsConsequent;
	}
	WhereClause* getRuleBody () { return m_WhereClause; }
	virtual OperationResultSet* execute (RdfDB* userQueryAsAssertions, ResultSet* rs = NULL) {
	    OperationResultSet* opRS = dynamic_cast<OperationResultSet*>(rs);
	    if (opRS == NULL)
		throw(std::runtime_error("MappingConstrucs need a result set.")); // @@ shouldn't happen? consequents[pos][bgp] = false;

	    /* Build a disjoint in a where clause for the transformed user
	     * query. Currently, the approach is to express the rule head as a
	     * pattern with OPTIONALs; express the query as a graph, and create
	     * conjunctions for each match.  May be better to tweak the graph
	     * match to build the new query directly.
	     */

	    /* 04 — Execute the query C on the query disjoint D, producing a result set RScd.
	     * http://www.w3.org/2008/07/MappingRules/#_04
	     */
	    m_WhereClause->bindVariables(userQueryAsAssertions, opRS);
	    if (*debugStream != NULL)
		**debugStream << "produced result set" << std::endl << opRS->toString() << std::endl;

	    /* 05 — For each rule solution S in RScd:
	     * http://www.w3.org/2008/07/MappingRules/#_05
	     */

	    TableConjunction* patternSpanningRows = new TableConjunction();
	    for (ResultSetIterator row = opRS->begin() ; row != opRS->end(); ++row) {

		/* 06 — Scan each basic graph pattern GA in the antecedent graph pattern A for variables in triple patterns:
		 * http://www.w3.org/2008/07/MappingRules/#_06
		 */
		/* Set of { BGP => optional } associations to indicate if the BGP is optional. */
		ConsequentMap includeRequiredness = consequents.getIncludeRequiredness(opRS, row, posFactory);

		/* 07 — Substitute the values in S for the variables in A.
		 * 08 — Create a stem query disjoint DQS which is a reproduction of the mapping rule antecedent A
		 * http://www.w3.org/2008/07/MappingRules/#_07
		 */
		MappedDuplicator e(posFactory, *row, &includeRequiredness);
		constructRuleBodyAsConsequent->express(&e);
		TableOperation* t = e.getTableOperation();
		if (t != NULL)
		    patternSpanningRows->addTableOperation(t);
	    }

	    TableOperation* res = patternSpanningRows->simplify();
	    opRS->copyFiltersTo(res);

	    if (*debugStream != NULL) {
		SPARQLSerializer s;
		res->express(&s);
		**debugStream << "yielding transformed query disjoint:" << endl << s.getSPARQLstring() << endl;
	    }
	    opRS->addTableOperation(res);
	    return opRS;
	}
    };

    class RuleInverter : public SWObjectDuplicator {
    protected:
	DefaultGraphPattern* constructRuleHead;
	TableOperation* constructRuleBodyAsConsequent;
	MappingConstruct* m_Construct;
	std::ostream** debugStream;
	bool inUserRuleHead;
	std::map<POS*, size_t> variablesInLexicalOrder;
	size_t nextVariableIndex;
    public:
	RuleInverter (POSFactory* posFactory, std::ostream** debugStream = NULL) : 
	    SWObjectDuplicator(posFactory), debugStream(debugStream), inUserRuleHead(false), nextVariableIndex(0) {  }

	MappingConstruct* getConstruct() { return m_Construct; }

	/* duplicate triples and note the order of POSs.
	 * This is called from _TriplePatters call in _graphPatterns.
	 */
	virtual void triplePattern (TriplePattern* self, w3c_sw::POS* s, w3c_sw::POS* p, w3c_sw::POS* o) {
	    this->SWObjectDuplicator::triplePattern(self, s, p, o);
	    if (!inUserRuleHead) {
		/* We're in the UserRuleBody so note the order of introduced
		   variables. */
		variablesInLexicalOrder[s] = nextVariableIndex++;
		variablesInLexicalOrder[p] = nextVariableIndex++;
		variablesInLexicalOrder[o] = nextVariableIndex++;
	    }
	}
	/* MapOrder - adequate tool to make sure that the order of the optionals
	 * coming from matching the userRuleHead as a where clause are ordered
	 * to introduce variables in the same order as those introduced in the
	 * userRuleBody.
	 */
	struct MapOrder {
	    std::map<POS*, size_t>& v;
	    MapOrder (std::map<POS*, unsigned>& v) : v(v) {  }
	    int _orderAtoms (POS* l, POS* r) {
		if (v.find(l) == v.end())
		    v[l] = v.size();
		if (v.find(r) == v.end())
		    v[r] = v.size();
		return l == r ? 0 : v[l] < v[r] ? 1 : -1;
	    }
	    bool operator() (TriplePattern* l, TriplePattern* r) {
		int s = _orderAtoms(l->getS(), r->getS());
		if (s == 1) return true;
		if (s == -1) return false;

		int o = _orderAtoms(l->getO(), r->getO());
		if (o == 1) return true;
		if (o == -1) return false;

		int p = _orderAtoms(l->getP(), r->getP());
		if (p == 1) return true;
		if (p == -1) return false;

		/* older, more terse form was too random for MSVC debugging version of ::sort */
		return
		    v[l->getS()] < v[r->getS()] || 
		    v[l->getP()] < v[r->getP()] || 
		    v[l->getO()] < v[r->getO()];
		//return TriplePattern::gt(l, r);
	    }
	};
	void _graphPattern (BasicGraphPattern* bgp, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    _TriplePatterns(p_TriplePatterns, bgp);
	    _Filters(p_Filters, bgp);
	    last.tableOperation = bgp;

	    if (inUserRuleHead)
		std::sort(bgp->begin(), bgp->end(), MapOrder(variablesInLexicalOrder));
	}

	/* Create BasicGraphPatterns (named and default) with a flag
	 * indicating the special semantics of all triples being
	 * optional (03).
	 */
	virtual void namedGraphPattern (NamedGraphPattern*, POS* p_name, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    p_name->express(this);
	    _graphPattern(new NamedGraphPattern(last.posz.pos, inUserRuleHead), p_allOpts, p_TriplePatterns, p_Filters); // allOpts = true when in rule body
	}
	virtual void defaultGraphPattern (DefaultGraphPattern*, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    _graphPattern(new DefaultGraphPattern(inUserRuleHead), p_allOpts, p_TriplePatterns, p_Filters); // allOpts = true when in rule body
	}

	virtual void whereClause (WhereClause*, TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    if (p_BindingClause != NULL)
		throw(std::runtime_error("Don't know how to invert a Construct with a BindingClause."));

	    /* Create a rule head from the userRuleBody and record to use later
	     * to build a MappingConstruct. Traverse the userRuleBody before the
	     * constructRuleHead to establish the order of introduced variables.
	     */
	    p_GroupGraphPattern->express(this); // sets last.tableOperation
	    constructRuleBodyAsConsequent = last.tableOperation;

	    /* create a new CONSTRUCT with the consequent of the old
	     * query (constructRuleHead) treated as where clause.
	     *
	     * # 03 — Treat C as a query, each triple being optional.
	     * http://www.w3.org/2008/07/MappingRules/#_03
	     */
	    inUserRuleHead = true;
	    constructRuleHead->express(this);
	    inUserRuleHead = false;
	    TableOperation* op = last.tableOperation;

	    last.bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);
	    last.whereClause = new WhereClause(op, last.bindingClause);
	}

	virtual void construct (Construct*, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    if (p_DatasetClauses->size() != 0)
		throw(std::runtime_error("Don't know how to invert a Construct with a DatasetClauses."));

	    /* Record the current CONSTRUCT rule head.
	     * Expressing the WhereClause builds a new WhereClause based on
	     * constructRuleHead and sets constructRuleBodyAsConsequent to a
	     * copy of the graph pattern of the CONSTRUCT WhereClause.
	     */
	    constructRuleHead = p_ConstructTemplate;
	    p_WhereClause->express(this);
	    WhereClause* constructRuleHeadAsPattern = last.whereClause;

	    if (0 && *debugStream != NULL) {
		SPARQLSerializer sparqlizer("  ", SPARQLSerializer::DEBUG_graphs);
		constructRuleBodyAsConsequent->express(&sparqlizer);
		**debugStream << "product rule head (SPARQL):" << endl << sparqlizer.getSPARQLstring() << endl;
	    }
	    p_SolutionModifier->express(this);

	    m_Construct = new MappingConstruct(constructRuleBodyAsConsequent,	 // consequent of new mapping rule
					       _DatasetClauses(p_DatasetClauses),//
					       constructRuleHeadAsPattern,	 // antecedent of new mapping rule
					       last.solutionModifier, 		 //
					       posFactory, debugStream);
	}

	/* RuleInverter only works on CONSTRUCTs. All other verbs
	 * get a run-time error. (A compile-time error would be nice, but the
	 * expressor interface prevents that.
	 */
	virtual void select (Select*, e_distinctness, VarSet*, ProductionVector<DatasetClause*>*, WhereClause*, SolutionModifier*) {
	    throw(std::runtime_error("RuleInverter only works on CONSTRUCTs."));
	}
	// @@ should be similar errors for ASK, DESCRIBE and all SPARUL verbs.

    };

} // namespace w3c_sw

#endif // RuleInverter_H

