/* RuleInverter.hpp - create a SPARQL CONSTRUCT rule that follows 
 * http://www.w3.org/2008/07/MappingRules/#_02
 *
 * $Id: RuleInverter.hpp,v 1.23 2008-11-27 19:40:11 eric Exp $
 */

#ifndef RuleInverter_H
#define RuleInverter_H

#include "SWObjectDuplicator.hpp"
#include "POS2BGPMap.hpp"
#include "SPARQLSerializer.hpp" // for debugging output
#include <set>
#include <algorithm>

#if REGEX_LIB == SWOb_BOOST
  #include <boost/regex.hpp>
#endif /* REGEX_LIB == SWOb_BOOST */


/* APPLY_VARMAPS_INDISCRIMINATELY -- Apply tr:rewrite(?foo,p1,p2) to
 * any URI in the transformation output, not just bindings for ?foo.
 */
#define APPLY_VARMAPS_INDISCRIMINATELY

namespace w3c_sw {

#if REGEX_LIB == SWOb_BOOST
    struct POSmap {
	const POS* selector;
	boost::regex ifacePattern;
	std::string localPattern;
	std::string mapString (const std::string tweak) const {
	    std::ostringstream t(std::ios::out | std::ios::binary);
	    std::ostream_iterator<char, char> oi(t);
	    boost::regex_replace(oi, tweak.begin(), tweak.end(),
				 ifacePattern, localPattern, 
				 boost::match_default | boost::format_all | boost::format_no_copy);
	    //if (t.str().size() != 0) {
	    //	std::cerr << "s{" << ifacePattern << "}\n {" << localPattern << "}\n (" << tweak << ")\n=>";
	    //	std::cerr << t.str() << std::endl;
	    //}
	    return t.str();
	}
    };
#endif /* REGEX_LIB == SWOb_BOOST */

    class OperationResultSet : public ResultSet {
	class FilterCopier : public RecursiveExpressor {
	    class FilterDuplicator : public SWObjectDuplicator {

	    public:
		FilterDuplicator (POSFactory* posFactory) : SWObjectDuplicator(posFactory) {  }
		const Filter* getFilter () { return last.filter; }
	    };
	    
	protected:
	    TableOperation* dest;

	public:
	    FilterCopier (TableOperation* dest) : dest(dest) {  }

	    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	    virtual void filter (const Filter* const self, const Expression*) {
		FilterDuplicator fd(NULL); // requires the same POSFactory.
		self->express(&fd);
		dest->addFilter(fd.getFilter());
	    }
	    virtual void namedGraphPattern (const NamedGraphPattern* const, const POS* /*p_name*/, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* /*p_TriplePatterns*/, const ProductionVector<const Filter*>* p_Filters) {
		p_Filters->express(this);
	    }
	    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* /*p_TriplePatterns*/, const ProductionVector<const Filter*>* p_Filters) {
		p_Filters->express(this);
	    }

	};

    protected:
	TableDisjunction* constructed;
	const TableOperation* userQueryDisjoint;

    public:
	OperationResultSet (POSFactory* posFactory, TableDisjunction* constructed, const TableOperation* userQueryDisjoint) : 
	    ResultSet(posFactory), constructed(constructed), userQueryDisjoint(userQueryDisjoint) {  }
	void addTableOperation (const TableOperation* op) { constructed->addTableOperation(op); }
	void copyFiltersTo (TableOperation* dest) {
	    /* Copy the FILTER patterns across.
	       !!! This isn't sound -- requires more exploration.
	    */
	    FilterCopier c(dest);
	    userQueryDisjoint->express(&c);
	}
#ifndef APPLY_VARMAPS_INDISCRIMINATELY
#if REGEX_LIB == SWOb_BOOST
	size_t applyMaps (std::vector<POSmap> const &maps) {
	    size_t matches = 0;
	    for (ResultSetIterator row = begin(); row != end(); ++row) {
		for (std::vector<POSmap>::const_iterator map = maps.begin();
		     map != maps.end(); ++map) {
		    BindingSetIterator binding = (*row)->find(map->selector);
		    if (binding != (*row)->end()) {
			const URI* u = dynamic_cast<const URI*>(binding->second.pos);
			if ((u) != NULL) {
			    std::string changed = map->mapString(u->getLexicalValue());
			    if (changed.size() == 0)
				throw std::string("URI map ") + map->ifacePattern.str() + " failed to match " + u->getLexicalValue();
			    (*row)->set(map->selector, posFactory->getURI(changed), false, true);
			    ++matches;
			}
		    }
		}
	    }
	    return matches;
	}
#endif /* REGEX_LIB == SWOb_BOOST */
#endif /* !APPLY_VARMAPS_INDISCRIMINATELY */
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
#define WatchOptsOnly false

	protected:
	    ConsequentMap* includeRequiredness;
	    Result* row;
#if REGEX_LIB == SWOb_BOOST
	    std::vector<POSmap> uriMaps;
#endif /* REGEX_LIB == SWOb_BOOST */
	public:
	    MappedDuplicator (POSFactory* posFactory, Result* row, ConsequentMap* includeRequiredness
#if REGEX_LIB == SWOb_BOOST
			      , std::vector<POSmap> uriMaps
#endif /* REGEX_LIB == SWOb_BOOST */
			      ) :
		SWObjectDuplicator(posFactory), includeRequiredness(includeRequiredness), row(row)
#if REGEX_LIB == SWOb_BOOST
		, uriMaps(uriMaps)
#endif /* REGEX_LIB == SWOb_BOOST */
		    {  }
	    TableOperation* getTableOperation () { return last.tableOperation; }

	    virtual void _TriplePatterns (const ProductionVector<const TriplePattern*>* p_TriplePatterns, BasicGraphPattern* bgp) {
		for (std::vector<const TriplePattern*>::const_iterator triple = p_TriplePatterns->begin();
		     triple != p_TriplePatterns->end(); triple++)
#ifdef APPLY_VARMAPS_INDISCRIMINATELY
		    {
			/* Copy TriplePattern::construct functionality and inject transformation. */
			const POS *s, *p, *o;
			if ((s = (*triple)->getS()->evalPOS(row, false)) != NULL && 
			    (p = (*triple)->getP()->evalPOS(row, false)) != NULL && 
			    (o = (*triple)->getO()->evalPOS(row, false)) != NULL) {
			    /* inject transformations */
#if REGEX_LIB == SWOb_BOOST
			    const POS** uris[3] = {&s, &p, &o};
			    for (unsigned i = 0; i < 3; ++i) {
				const URI* u = dynamic_cast<const URI*>(*uris[i]);
				if (u != NULL) {
				    for (std::vector<POSmap>::const_iterator map = uriMaps.begin();
					 map != uriMaps.end(); ++map) {
					std::string changed = map->mapString(u->getLexicalValue());
					if (changed.size() != 0) {
					    *uris[i] = posFactory->getURI(changed.c_str());
					    break;
					}
				    }
				}
			    }
#endif /* REGEX_LIB == SWOb_BOOST */
			    if (posFactory == NULL) {
				if (s == (*triple)->getS() && p == (*triple)->getP() && o == (*triple)->getO()) // lost:  && !weaklyBound
				    bgp->addTriplePattern(*triple);
				else
				    throw(std::runtime_error("TriplePattern::construct requires POSFactory when constructing new triples."));
			    } else
				bgp->addTriplePattern(posFactory->getTriple(s, p, o));
			}
		    }
#else /* !APPLY_VARMAPS_INDISCRIMINATELY */
		    (*triple)->construct(bgp, row, posFactory, false);
#endif /* !APPLY_VARMAPS_INDISCRIMINATELY */
	    }

	    /* Overload SWObjectDuplicator::_TableOperations to handle tree depletion. */
	    virtual void _TableOperations (const ProductionVector<const TableOperation*>* p_TableOperations, TableJunction* j) {
		for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    last.tableOperation = NULL;
		    (*it)->express(this);
		    if (last.tableOperation != NULL)
			j->addTableOperation(last.tableOperation);
		}
	    }

	    virtual void namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::namedGraphPattern(self, p_name, p_allOpts, p_TriplePatterns, p_Filters);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::namedGraphPattern (self, p_name, p_allOpts, p_TriplePatterns, p_Filters);
		}
	    }
	    virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::defaultGraphPattern(self, p_allOpts, p_TriplePatterns, p_Filters);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::defaultGraphPattern (self, p_allOpts, p_TriplePatterns, p_Filters);
		}
	    }
	    virtual void tableConjunction (const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations, const ProductionVector<const Filter*>* p_Filters) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::tableConjunction(self, p_TableOperations, p_Filters);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::tableConjunction (self, p_TableOperations, p_Filters);
		}
	    }
	    virtual void tableDisjunction (const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations, const ProductionVector<const Filter*>* p_Filters) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::tableDisjunction(self, p_TableOperations, p_Filters);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::tableDisjunction (self, p_TableOperations, p_Filters);
		}
	    }
	    virtual void optionalGraphPattern (const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Filter*>* p_Filters) {
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
	    virtual void graphGraphPattern (const GraphGraphPattern* const, const POS* /* p_POS */, const TableOperation* /* p_GroupGraphPattern */) {
		FAIL("don't know how to deal with a graphGraphPattern in a stem query");
	    }
	};


    private:
	TableOperation* constructRuleBodyAsConsequent;
	Consequents consequents;
	POSFactory* posFactory;
#if REGEX_LIB == SWOb_BOOST
	std::vector<POSmap> uriMaps;
#endif /* REGEX_LIB == SWOb_BOOST */
	std::ostream** debugStream;

    public:
	MappingConstruct (TableOperation* constructRuleBodyAsConsequent, ProductionVector<const DatasetClause*>* p_DatasetClauses, 
			  WhereClause* constructRuleHeadAsPattern, SolutionModifier* p_SolutionModifier, POSFactory* posFactory, 
#if REGEX_LIB == SWOb_BOOST
			  std::vector<POSmap> uriMaps, 
#endif /* REGEX_LIB == SWOb_BOOST */
			  std::ostream** debugStream) : 
	    Construct(NULL, p_DatasetClauses, constructRuleHeadAsPattern, p_SolutionModifier), 
	    constructRuleBodyAsConsequent(constructRuleBodyAsConsequent), 
	    consequents(constructRuleBodyAsConsequent, NULL, debugStream), 
	    posFactory(posFactory), 
#if REGEX_LIB == SWOb_BOOST
	    uriMaps(uriMaps), 
#endif /* REGEX_LIB == SWOb_BOOST */
	    debugStream(debugStream)
	{  }
	~MappingConstruct () {
	    delete constructRuleBodyAsConsequent;
	}
	WhereClause* getRuleBody () { return m_WhereClause; }
	virtual OperationResultSet* executeMapping (RdfDB* userQueryAsAssertions, OperationResultSet* opRS) {

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
#ifndef APPLY_VARMAPS_INDISCRIMINATELY
 	    opRS->applyMaps(uriMaps);
#endif
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
		MappedDuplicator e(posFactory, *row, &includeRequiredness
#if REGEX_LIB == SWOb_BOOST
				   , uriMaps
#endif /* REGEX_LIB == SWOb_BOOST */
				   );
		constructRuleBodyAsConsequent->express(&e);
		TableOperation* t = e.getTableOperation();
		if (t != NULL)
		    patternSpanningRows->addTableOperation(t);
	    }

	    TableOperation* res = patternSpanningRows->simplify(); // !!! should be a simplifying expressor
	    if (res != NULL) {
		opRS->copyFiltersTo(res);
		opRS->addTableOperation(res);

	    }
	    if (*debugStream != NULL) {
		if (res == NULL)
		    **debugStream << "yielding no transformed query disjoint." << endl << endl;
		else
		    **debugStream << "yielding transformed query disjoint:" << endl << *res << endl;
	    }
	    return opRS;
	}
    };

    struct VarDetails { int i; std::string pattern; }; // can't embed where it's needed -- template errors

    class RuleInverter : public SWObjectDuplicator {
    protected:
	DefaultGraphPattern* constructRuleHead;
	TableOperation* constructRuleBodyAsConsequent;
	MappingConstruct* m_Construct;
	std::ostream** debugStream;
	bool inUserRuleHead;
	std::map<const POS*, size_t> variablesInLexicalOrder;
	size_t nextVariableIndex;

#if REGEX_LIB == SWOb_BOOST
	std::vector<POSmap> uriMaps;
#endif /* REGEX_LIB == SWOb_BOOST */

    public:
	RuleInverter (POSFactory* posFactory, std::ostream** debugStream = NULL) : 
	    SWObjectDuplicator(posFactory), debugStream(debugStream), inUserRuleHead(false), nextVariableIndex(0) {  }

	MappingConstruct* getConstruct() { return m_Construct; }

	/* duplicate triples and note the order of POSs.
	 * This is called from _TriplePatters call in _graphPatterns.
	 */
	virtual void triplePattern (TriplePattern* self, POS* s, POS* p, POS* o) {
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
	    std::map<const POS*, size_t>& v;
	    MapOrder (std::map<const POS*, size_t>& v) : v(v) {  }
	    int _orderAtoms (const POS* l, const POS* r) {
		if (v.find(l) == v.end())
		    v[l] = v.size();
		if (v.find(r) == v.end())
		    v[r] = v.size();
		return l == r ? 0 : v[l] < v[r] ? 1 : -1;
	    }
	    bool operator() (const TriplePattern* l, const TriplePattern* r) {
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

	void _graphPattern (BasicGraphPattern* bgp, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
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
	virtual void namedGraphPattern (const NamedGraphPattern* const, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
	    p_name->express(this);
	    _graphPattern(new NamedGraphPattern(last.posz.pos, inUserRuleHead), p_allOpts, p_TriplePatterns, p_Filters); // allOpts = true when in rule body
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
	    _graphPattern(new DefaultGraphPattern(inUserRuleHead), p_allOpts, p_TriplePatterns, p_Filters); // allOpts = true when in rule body
	}

	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
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

	virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
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

	    if (*debugStream != NULL) {
		SPARQLSerializer sparqlizer("  ", SPARQLSerializer::DEBUG_graphs);
		constructRuleBodyAsConsequent->express(&sparqlizer);
		**debugStream << "product rule head (SPARQL):" << endl << sparqlizer.getSPARQLstring() << endl;
	    }
	    p_SolutionModifier->express(this);

	    m_Construct = new MappingConstruct(constructRuleBodyAsConsequent,	 // consequent of new mapping rule
					       _DatasetClauses(p_DatasetClauses),//
					       constructRuleHeadAsPattern,	 // antecedent of new mapping rule
					       last.solutionModifier, 		 //
					       posFactory, 
#if REGEX_LIB == SWOb_BOOST
					       uriMaps, 
#endif /* REGEX_LIB == SWOb_BOOST */
					       debugStream);
	}

	/* RuleInverter only works on CONSTRUCTs. All other verbs
	 * get a run-time error. (A compile-time error would be nice, but the
	 * expressor interface prevents that.
	 */
	virtual void select (const Select* const, e_distinctness, VarSet*, ProductionVector<const DatasetClause*>*, WhereClause*, SolutionModifier*) {
	    throw(std::runtime_error("RuleInverter only works on CONSTRUCTs."));
	}
	// @@ should be similar errors for ASK, DESCRIBE and all SPARUL verbs.

	ProductionVector<const Expression*>* _Expressions (const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* l_Expressions = new ProductionVector<const Expression*>();
	    for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		if (last.expression)
		    l_Expressions->push_back(last.expression);
	    }
	    if (l_Expressions->size() == 0) {
		delete l_Expressions;
		return NULL;
	    }
	    return l_Expressions;
	}

	virtual void argList (const ArgList* const, ProductionVector<const Expression*>* p_expressions) {
	    last.argList = new ArgList(_Expressions(p_expressions)); /* links to RuleInverter::_Expressions */
	}

	virtual void functionCall (const FunctionCall* const me, const URI* p_IRIref, const ArgList* p_ArgList) {
#if REGEX_LIB == SWOb_BOOST
	    if (p_IRIref != posFactory->getURI("http://www.w3.org/2008/04/SPARQLfed/#rewriteVar"))
		SWObjectDuplicator::functionCall(me, p_IRIref, p_ArgList);
	    if (p_ArgList->size() != 3)
		FAIL("wrong number of arguments to sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\")");
	    std::vector<const Expression*>::iterator it = p_ArgList->begin();
	    const VarExpression* varExp = dynamic_cast<const VarExpression*>(*it);
	    if (varExp == NULL)
		FAIL("sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\"): parm 1 not a variable");
	    const Bindable* toModify = varExp->getBindable();
	    ++it;
	    const LiteralExpression* litExp = dynamic_cast<const LiteralExpression*>(*it);
	    if (litExp == NULL)
		FAIL("sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\"): parm 2 not a literal");
	    /* localName
	     * http://bsbm.example/db/productfeatureproduct/offer.nr=(?@offer=[0-9]+)&publisher=(?@pub=[0-9]+)
	     */
	    const RDFLiteral* localName = litExp->getLiteral();

	    ++it;
	    litExp = dynamic_cast<const LiteralExpression*>(*it);
	    if (litExp == NULL)
		FAIL("sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\"): parm 3 not a literal");
	    /* ifaceName
	     * http://www4.wiwiss.fu-berlin.de/bizer/bsbm/v01/instances/dataFromVendor(?@pub=[0-9]+)/Offer(?@offer=[0-9]+)
	     */
	    const RDFLiteral* ifaceName = litExp->getLiteral();
	    last.expression = NULL;

	    /* create a substitution regexp:
	       from: http://www4.wiwiss.fu-berlin.de/bizer/bsbm/v01/instances/dataFromVendor([0-9]+)/Offer([0-9]+)
	       to: http://bsbm.example/db/productfeatureproduct/offer.nr=\2&publisher=\1
	     */

	    const boost::regex re("\\(\\$([a-z]+)(?:=([^)]+))?\\)");
	    const int desiredMatches[] = {-1, 1, 2};
	    const boost::sregex_token_iterator nullIt;

	    std::map<std::string, VarDetails> patternVars;
	    std::vector<std::string> ifaceComponents;

	    {
		string iriStr(ifaceName->getLexicalValue());
		boost::sregex_token_iterator it(iriStr.begin(), iriStr.end(), re, desiredMatches);
		for (unsigned index = 1; it != nullIt; ++index) {
		    ifaceComponents.push_back(*it++);
		    if (it != nullIt) {
			std::string var = *it++;
			patternVars[var].i = index;
			patternVars[var].pattern = *it++;
			ifaceComponents.push_back(var);
		    }
		}
	    }

	    POSmap newMap;
	    newMap.selector = toModify;

	    {
		string iriStr(localName->getLexicalValue());
		boost::sregex_token_iterator it(iriStr.begin(), iriStr.end(), re, desiredMatches);
		std::stringstream subPattern;
		while (it != nullIt) {
		    subPattern << *it++;
		    if (it != nullIt) {
			std::string var = *it++;
			if (patternVars[var].i == 0)
			    FAIL1("unknown var: %s", var.c_str());

			subPattern << '\\' << patternVars[var].i;
			std::string pattern = *it++;
			if (pattern.size() != 0) {
			    if (patternVars[var].pattern.size() == 0)
				patternVars[var].pattern = pattern;
			    else if (patternVars[var].pattern != pattern)
				FAIL3("local pattern for var %s: %s doesn't match iface pattern %s", 
				      var.c_str(), pattern.c_str(), patternVars[var].pattern.c_str());
			}
		    }
		}
		newMap.localPattern = subPattern.str();
	    }

	    for (std::map<std::string, VarDetails>::const_iterator it = patternVars.begin();
		 it != patternVars.end(); ++it)
		if (it->second.pattern.size() == 0)
		    patternVars[it->first].pattern = ".*?";

	    {
		std::stringstream iface;
		for (std::vector<std::string>::iterator component = ifaceComponents.begin();
		     component != ifaceComponents.end();) {
		    iface << *component++;
		    if (component != ifaceComponents.end())
			iface << "(" << patternVars[*component++].pattern << ")";
		}
		newMap.ifacePattern.assign(iface.str());
	    }
	    uriMaps.push_back(newMap);
#else /* !REGEX_LIB == SWOb_BOOST */
	    SWObjectDuplicator::functionCall(me, p_IRIref, p_ArgList);
#endif /* !REGEX_LIB == SWOb_BOOST */
	}

	virtual void booleanConjunction (const BooleanConjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions); /* links to RuleInverter::_Expressions */
	    if (v == NULL)
		last.expression = NULL;
	    else {
		last.expression = new BooleanConjunction(v);
		v->clear();
		delete v;
	    }
	}
	virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions); /* links to RuleInverter::_Expressions */
	    if (v == NULL)
		last.expression = NULL;
	    else {
		last.expression = new BooleanDisjunction(v);
		v->clear();
		delete v;
	    }
	}
	virtual void arithmeticSum (const ArithmeticSum* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions); /* links to RuleInverter::_Expressions */
	    if (v == NULL)
		last.expression = NULL;
	    else {
		last.expression = new ArithmeticSum(v);
		v->clear();
		delete v;
	    }
	}
	virtual void arithmeticProduct (const ArithmeticProduct* const, const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* v = _Expressions(p_Expressions); /* links to RuleInverter::_Expressions */
	    if (v == NULL)
		last.expression = NULL;
	    else {
		last.expression = new ArithmeticProduct(v);
		v->clear();
		delete v;
	    }
	}
    };

} // namespace w3c_sw

#endif // RuleInverter_H

