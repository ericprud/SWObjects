/* RuleInverter.hpp - create a SPARQL CONSTRUCT rule that follows 
 * http://www.w3.org/2008/07/MappingRules/#_02
 *
 * $Id: RuleInverter.hpp,v 1.1 2008-08-26 05:30:48 jnorthru Exp $
 */

#ifndef RuleInverter_H
#define RuleInverter_H

#include "SWObjectDuplicator.hpp"
#include <set>

namespace SPARQLfedNS {

    class OperationResultSet : public ResultSet {
    protected:
	TableDisjunction* constructed;
    public:
	OperationResultSet (TableDisjunction* constructed) : ResultSet(), constructed(constructed) {  }
	void addTableOperation (TableOperation* op) { constructed->addTableOperation(op); }
    };

    class MappingConstruct : public Construct {

	typedef std::map<BasicGraphPattern*, bool> ConsequentMap;
	typedef std::map<BasicGraphPattern*, bool>::iterator ConsequentMapIterator;
	typedef std::map<POS*, ConsequentMap> ConsequentMapList;
	typedef std::map<POS*, ConsequentMap>::iterator ConsequentMapListIterator;

	class Consequents {

	    class ConsequentsConstructor : public yacker::RecursiveExpressor {
	    protected:
		ConsequentMapList& consequents;  // hate refs, but like the [foo][bar] syntax
		BasicGraphPattern* bgp;
		bool optState;
		POS* graphName;
		void _depends (POS* pos, BasicGraphPattern* bgp, bool weaklyBound) {
		    ConsequentMapListIterator maps = consequents.find(pos);
		    if (maps == consequents.end()) {
			/* No BGP has introduced this variable. */
			consequents[pos][bgp] = weaklyBound;
		    } else {
			ConsequentMapIterator consequent = consequents[pos].find(bgp);
			if (consequent == consequents[pos].end()) {
			    /* This BGP has not introduced this variable. */

			    /* Omit { variables => BGP } mappings where the BGP is optional and the variable is mandatory elsewhere.
			     * 06b — If the variable is weak in S and GA is optional and the variable is not in any mandatory antecedent graph, tag GA as an included optional.
			     *                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			     */
			    if (weaklyBound == true) {
				/* Only assert if no existing mandatory BGPs introduce this variable. */
				for (ConsequentMapIterator bgps = consequents[pos].begin();
				     bgps != consequents[pos].end(); ++bgps)
				    if (bgps->second == false)
					/* Already introduced elsewhere, so just return. */
					return;
			    } else {
				/* No existing optional BGPs introduce this variable. */
				for (ConsequentMapIterator bgps = consequents[pos].begin();
				     bgps != consequents[pos].end();)
				    if (bgps->second == true) // I don't know a safer way to erase cur element.
					consequents[pos].erase(bgps++);
				    else
					bgps++;
			    }

			    consequents[pos][bgp] = weaklyBound;
			} else if (consequents[pos][bgp] == true && weaklyBound == false)
			    throw(std::runtime_error("reassignment of weakly bound variable to strongly bound in the same BGP.")); // @@ shouldn't happen? consequents[pos][bgp] = false;
		    }
		}

	    public:
		ConsequentsConstructor (ConsequentMapList* consequents, TableOperation* op) : consequents(*consequents), bgp(dynamic_cast<BasicGraphPattern*>(op)), optState(false), graphName(NULL) {  }
		virtual yacker::Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

		virtual TriplePattern* triplePattern (SPARQLfedNS::POS* p_s, SPARQLfedNS::POS* p_p, SPARQLfedNS::POS* p_o) {
		    _depends(p_s, bgp, optState);
		    _depends(p_p, bgp, optState);
		    _depends(p_o, bgp, optState);
		    return NULL;
		}

		virtual NamedGraphPattern* namedGraphPattern (SPARQLfedNS::POS* p_name, bool /*p_allOpts*/, yacker::ProductionVector<SPARQLfedNS::TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<SPARQLfedNS::Filter*>*) {
		    _depends(p_name, bgp, optState);
		    p_TriplePatterns->express(this);
		    // p_Filters->express(this); @@ what to do with these?
		    return NULL;
		}

		virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, yacker::ProductionVector<SPARQLfedNS::TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<SPARQLfedNS::Filter*>*) {
		    p_TriplePatterns->express(this);
		    // p_Filters->express(this); @@ what to do with these?
		    return NULL;
		}

		void _each (yacker::ProductionVector<TableOperation*>* p_TableOperations) {
		    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
			 it != p_TableOperations->end(); it++) {
			bgp = dynamic_cast<BasicGraphPattern*>(*it);
			(*it)->express(this);
		    }
		    bgp = NULL;
		}

		virtual TableDisjunction* tableDisjunction (yacker::ProductionVector<SPARQLfedNS::TableOperation*>* p_TableOperations, yacker::ProductionVector<SPARQLfedNS::Filter*>*) {
		    _each(p_TableOperations);
		    //p_Filters->express(this);
		    return NULL;
		}
		virtual TableConjunction* tableConjunction (yacker::ProductionVector<SPARQLfedNS::TableOperation*>* p_TableOperations, yacker::ProductionVector<SPARQLfedNS::Filter*>*) {
		    _each(p_TableOperations);
		    //p_Filters->express(this);
		    return NULL;
		}
		virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
		    bool oldOptState = optState;
		    optState = true;
		    bgp = dynamic_cast<BasicGraphPattern*>(p_GroupGraphPattern);
		    p_GroupGraphPattern->express(this);
		    bgp = NULL;
		    optState = oldOptState;
		    return NULL;
		}

		virtual GraphGraphPattern* graphGraphPattern (SPARQLfedNS::POS* p_POS, SPARQLfedNS::TableOperation* p_GroupGraphPattern) {
		    POS* oldGraphName = graphName;
		    graphName = p_POS;
		    bgp = dynamic_cast<BasicGraphPattern*>(p_GroupGraphPattern);
		    p_GroupGraphPattern->express(this);
		    bgp = NULL;
		    graphName = oldGraphName;
		    return NULL;
		}

	    };

	protected:
	    ConsequentMapList consequents;

	public:
	    Consequents (TableOperation* op) {
		ConsequentsConstructor ctor(&consequents, op);
		op->express(&ctor);
	    }
	    ~Consequents () {
		for (ConsequentMapListIterator maps = consequents.begin();
		     maps != consequents.end(); ++maps) {
		    maps->second.clear();
		}
		consequents.clear();
	    }

	    ConsequentMapListIterator begin () { return consequents.begin(); }
	    ConsequentMapListIterator end () { return consequents.end(); }
	};


	class MappedDuplicator : public SWObjectDuplicator {
	protected:
	    TableOperation* m_TableOperation;
	    ConsequentMap* includeRequiredness;
	    Result* row;
	public:
	    MappedDuplicator (POSFactory* posFactory, Result* row, ConsequentMap* includeRequiredness) : SWObjectDuplicator(posFactory), includeRequiredness(includeRequiredness), row(row) {  }
	    TableOperation* getTableOperation () { return m_TableOperation; }


	    virtual void _TriplePatterns (yacker::ProductionVector<TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
		for (std::vector<TriplePattern*>::iterator triple = p_TriplePatterns->begin();
		     triple != p_TriplePatterns->end(); triple++)
		    (*triple)->construct(p, row);
	    }

	    virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool p_allOpts, yacker::ProductionVector<TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<Filter*>* p_Filters) {
		NamedGraphPattern* ret = SWObjectDuplicator::namedGraphPattern(p_name, p_allOpts, p_TriplePatterns, p_Filters);
		m_TableOperation = ret;
		return ret;
	    }
	    virtual DefaultGraphPattern* defaultGraphPattern (bool p_allOpts, yacker::ProductionVector<TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<Filter*>* p_Filters) {
		DefaultGraphPattern* ret = SWObjectDuplicator::defaultGraphPattern(p_allOpts, p_TriplePatterns, p_Filters);
		m_TableOperation = ret;
		return ret;
	    }
	    /* Overload SWObjectDuplicator::_TableOperations to handle tree depletion. */
	    virtual void _TableOperations (yacker::ProductionVector<TableOperation*>* p_TableOperations, TableJunction* j) {
		for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    m_TableOperation = NULL;
		    TableOperation* r = (*it)->express(this);
		    if (r != NULL)
			j->addTableOperation(r);
		    else if (m_TableOperation != NULL)
			j->addTableOperation(m_TableOperation);
		}
	    }
	    virtual TableDisjunction* tableDisjunction (yacker::ProductionVector<TableOperation*>* p_TableOperations, yacker::ProductionVector<Filter*>* p_Filters) {
		TableDisjunction* ret = SWObjectDuplicator::tableDisjunction(p_TableOperations, p_Filters);
		m_TableOperation = ret;
		return ret;
	    }
	    virtual TableConjunction* tableConjunction (yacker::ProductionVector<TableOperation*>* p_TableOperations, yacker::ProductionVector<Filter*>* p_Filters) {
		TableConjunction* ret = SWObjectDuplicator::tableConjunction(p_TableOperations, p_Filters);
		m_TableOperation = ret;
		return ret;
	    }
	    virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
		BasicGraphPattern* bgp = dynamic_cast<BasicGraphPattern*>(p_GroupGraphPattern);
		ConsequentMapIterator it;
		if (bgp != NULL && (it = includeRequiredness->find(bgp)) != includeRequiredness->end()) {
		    if (it->second == false) {
			m_TableOperation = p_GroupGraphPattern->express(this);
			return NULL;
		    } else {
			std::cerr << "OPTIONAL: " << includeRequiredness->find(bgp)->second << std::endl;
			OptionalGraphPattern* ret = SWObjectDuplicator::optionalGraphPattern(p_GroupGraphPattern);
			m_TableOperation = ret;
			return ret;
		    }
		}
		return NULL;
	    }
	    virtual GraphGraphPattern* graphGraphPattern (POS* p_POS, TableOperation* p_GroupGraphPattern) {
		GraphGraphPattern* ret = SWObjectDuplicator::graphGraphPattern(p_POS, p_GroupGraphPattern);
		m_TableOperation = ret;
		return ret;
	    }
	};


    private:
	TableOperation* m_MappedAntecedent;
	Consequents consequents;
	POSFactory* posFactory;

    public:
	MappingConstruct (TableOperation* p_MappedAntecedent, yacker::ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier, POSFactory* posFactory) : Construct(NULL, p_DatasetClauses, p_WhereClause, p_SolutionModifier), m_MappedAntecedent(p_MappedAntecedent), consequents(p_MappedAntecedent), posFactory(posFactory) {  }
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
		for (ConsequentMapListIterator maps = consequents.begin();
		     maps != consequents.end(); ++maps) {
		    Variable* v = dynamic_cast<Variable*>(maps->first);
		    if (v == NULL)
			break;

		    for (ConsequentMapIterator bgpBindings = maps->second.begin();
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
			    if (bgpBindings->second == true) {
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
			includeRequiredness[bgpBindings->first] = (bgpBindings->second == false || (*row)->get(v) == false);
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
	virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool /*p_allOpts*/, yacker::ProductionVector<TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<Filter*>* p_Filters) {
	    NamedGraphPattern* ret = new NamedGraphPattern(p_name->express(this), true); // allOpts = true
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, yacker::ProductionVector<TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern(true); // allOpts = true
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}

	virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    if (p_BindingClause != NULL)
		throw(std::runtime_error("Don't know how to invert a Construct with a BindingClause."));

	    /* store the original antecedent (p_GroupGraphPattern) and create
	     * a new graph pattern with the original consequent
	     * (m_ConstructTemplate).
	     */
	    m_GroupGraphPattern = p_GroupGraphPattern;
	    return new WhereClause(m_ConstructTemplate->express(this), p_BindingClause ? p_BindingClause->express(this) : NULL);
	}

	virtual MappingConstruct* construct (DefaultGraphPattern* p_ConstructTemplate, yacker::ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    if (p_DatasetClauses->size() != 0)
		throw(std::runtime_error("Don't know how to invert a Construct with a DatasetClauses."));
	    m_ConstructTemplate = p_ConstructTemplate;
	    WhereClause* whereClause = p_WhereClause->express(this);

	    /* create a new CONSTRUCT with the consequent of the old
	     * query (m_ConstructTemplate) treated as where clause.
	     *
	     * # 03 — Treat C as a query, each triple being optional.
	     * http://www.w3.org/2008/07/MappingRules/#_03
	     */
	    m_Construct = new MappingConstruct(m_GroupGraphPattern->express(this), _DatasetClauses(p_DatasetClauses), whereClause, p_SolutionModifier->express(this), posFactory);
	    return m_Construct;
	}

	/* RuleInverter only works on CONSTRUCTs. All other verbs
	 * get a run-time error. (A compile-time error would be nice, but the
	 * expressor interface prevents that.
	 */
	virtual Select* select (e_distinctness, VarSet*, yacker::ProductionVector<DatasetClause*>*, WhereClause*, SolutionModifier*) {
	    throw(std::runtime_error("RuleInverter only works on CONSTRUCTs."));
	}
	// @@ should be similar errors for ASK, DESCRIBE and all SPARUL verbs.

    };

} // namespace SPARQLfedNS

#endif // RuleInverter_H

