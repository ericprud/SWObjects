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
	const TTerm* selector;
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
		FilterDuplicator (AtomFactory* atomFactory) : SWObjectDuplicator(atomFactory) {  }
		const Filter* getFilter () { return last.filter; }
	    };
	    
	protected:
	    TableOperation* dest;

	public:
	    FilterCopier (TableOperation* dest) : dest(dest) {  }

	    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	    virtual void filter (const Filter* const self, const ProductionVector<const Expression*>*) {
		FilterDuplicator fd(NULL); // requires the same AtomFactory.
		self->express(&fd);
		// dest->addFilter(fd.getFilter()); // !!!
	    }
	    // virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* /*p_name*/, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* /*p_TriplePatterns*/) {
	    // 	p_Filters->express(this);
	    // }
	    // virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* /*p_TriplePatterns*/) {
	    // 	p_Filters->express(this);
	    // }

	};

    protected:
	TableDisjunction* constructed;
	const TableOperation* userQueryDisjoint;

    public:
	OperationResultSet (AtomFactory* atomFactory, TableDisjunction* constructed, const TableOperation* userQueryDisjoint) : 
	    ResultSet(atomFactory), constructed(constructed), userQueryDisjoint(userQueryDisjoint) {  }
	void addTableOperation (const TableOperation* op) { constructed->addTableOperation(op, true); }
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
			const URI* u = dynamic_cast<const URI*>(binding->second.tterm);
			if ((u) != NULL) {
			    std::string changed = map->mapString(u->getLexicalValue());
			    if (changed.size() == 0)
				throw std::string("URI map ") + map->ifacePattern.str() + " failed to match " + u->getLexicalValue();
			    (*row)->set(map->selector, atomFactory->getURI(changed), false, true);
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
	    MappedDuplicator (AtomFactory* atomFactory, Result* row, ConsequentMap* includeRequiredness
#if REGEX_LIB == SWOb_BOOST
			      , std::vector<POSmap> uriMaps
#endif /* REGEX_LIB == SWOb_BOOST */
			      ) :
		SWObjectDuplicator(atomFactory), includeRequiredness(includeRequiredness), row(row)
#if REGEX_LIB == SWOb_BOOST
		, uriMaps(uriMaps)
#endif /* REGEX_LIB == SWOb_BOOST */
		    {  }
	    TableOperation* getTableOperation () { return last.tableOperation; }

	    virtual void _TriplePatterns (const ProductionVector<const TriplePattern*>* p_TriplePatterns, BasicGraphPattern* bgp) {
		TreatAsVar treatAsVar;
		for (std::vector<const TriplePattern*>::const_iterator triple = p_TriplePatterns->begin();
		     triple != p_TriplePatterns->end(); triple++)
#ifdef APPLY_VARMAPS_INDISCRIMINATELY
		    {
			/* Copy TriplePattern::construct functionality and inject transformation. */
			const TTerm *s, *p, *o;
			if ((s = (*triple)->getS()->evalTTerm(row, &treatAsVar)) != NULL && 
			    (p = (*triple)->getP()->evalTTerm(row, &treatAsVar)) != NULL && 
			    (o = (*triple)->getO()->evalTTerm(row, &treatAsVar)) != NULL) {
			    /* inject transformations */
#if REGEX_LIB == SWOb_BOOST
			    const TTerm** uris[3] = {&s, &p, &o};
			    for (unsigned i = 0; i < 3; ++i) {
				const URI* u = dynamic_cast<const URI*>(*uris[i]);
				if (u != NULL) {
				    for (std::vector<POSmap>::const_iterator map = uriMaps.begin();
					 map != uriMaps.end(); ++map) {
					std::string changed = map->mapString(u->getLexicalValue());
					if (changed.size() != 0) {
					    *uris[i] = atomFactory->getURI(changed.c_str());
					    break;
					}
				    }
				}
			    }
#endif /* REGEX_LIB == SWOb_BOOST */
			    if (atomFactory == NULL) {
				if (s == (*triple)->getS() && p == (*triple)->getP() && o == (*triple)->getO()) // lost:  && !weaklyBound
				    bgp->addTriplePattern(*triple);
				else
				    throw(std::runtime_error("TriplePattern::construct requires AtomFactory when constructing new triples."));
			    } else
				bgp->addTriplePattern(atomFactory->getTriple(s, p, o));
			}
		    }
#else /* !APPLY_VARMAPS_INDISCRIMINATELY */
		    (*triple)->construct(bgp, row, atomFactory, false);
#endif /* !APPLY_VARMAPS_INDISCRIMINATELY */
	    }

	    /* Overload SWObjectDuplicator::_TableOperations to handle tree depletion. */
	    virtual void _TableOperations (const ProductionVector<const TableOperation*>* p_TableOperations, TableJunction* j) {
		for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    last.tableOperation = NULL;
		    (*it)->express(this);
		    if (last.tableOperation != NULL)
			j->addTableOperation(last.tableOperation, true);
		}
	    }

	    virtual void namedGraphPattern (const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::namedGraphPattern(self, p_name, p_allOpts, p_TriplePatterns);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::namedGraphPattern (self, p_name, p_allOpts, p_TriplePatterns);
		}
	    }
	    virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::defaultGraphPattern(self, p_allOpts, p_TriplePatterns);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::defaultGraphPattern (self, p_allOpts, p_TriplePatterns);
		}
	    }
	    virtual void tableConjunction (const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::tableConjunction(self, p_TableOperations);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::tableConjunction (self, p_TableOperations);
		}
	    }
	    virtual void tableDisjunction (const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) {
		if (WatchOptsOnly) {
		    SWObjectDuplicator::tableDisjunction(self, p_TableOperations);
		    return;
		}
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(self);
		if (s != GraphInclusion_NONE) {
		    SWObjectDuplicator::tableDisjunction (self, p_TableOperations);
		}
	    }
	    virtual void optionalGraphPattern (const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
		last.tableOperation = NULL;
		GraphInclusion s = includeRequiredness->getOperationStrength(p_GroupGraphPattern);
		if (s != GraphInclusion_NONE) {
		    if (s == GraphInclusion_STRONG)
			// let p_GroupGraphPattern set last.tableOperation
			p_GroupGraphPattern->express(this);
			// !!! p_Expressions
		    else
			SWObjectDuplicator::optionalGraphPattern(self, p_GroupGraphPattern, p_Expressions);
		}
	    }
	    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* /* p_TTerm */, const TableOperation* /* p_GroupGraphPattern */) {
		w3c_sw_FAIL("don't know how to deal with a graphGraphPattern in a stem query");
	    }
	    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* /* p_TTerm */, const TableOperation* /* p_GroupGraphPattern */, AtomFactory* /* atomFactory */, bool /* lexicalCompare */) {
		w3c_sw_FAIL("don't know how to deal with a serviceGraphPattern in a stem query");
	    }
	};


    private:
	TableOperation* constructRuleBodyAsConsequent;
	Consequents consequents;
	AtomFactory* atomFactory;
#if REGEX_LIB == SWOb_BOOST
	std::vector<POSmap> uriMaps;
#endif /* REGEX_LIB == SWOb_BOOST */
	std::ostream** debugStream;

    public:
	MappingConstruct (TableOperation* constructRuleBodyAsConsequent, ProductionVector<const DatasetClause*>* p_DatasetClauses, 
			  WhereClause* constructRuleHeadAsPattern, SolutionModifier* p_SolutionModifier, AtomFactory* atomFactory, 
#if REGEX_LIB == SWOb_BOOST
			  std::vector<POSmap> uriMaps, 
#endif /* REGEX_LIB == SWOb_BOOST */
			  std::ostream** debugStream) : 
	    Construct(NULL, p_DatasetClauses, constructRuleHeadAsPattern, p_SolutionModifier), 
	    constructRuleBodyAsConsequent(constructRuleBodyAsConsequent), 
	    consequents(constructRuleBodyAsConsequent, NULL, debugStream), 
	    atomFactory(atomFactory), 
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
		ConsequentMap includeRequiredness = consequents.getIncludeRequiredness(opRS, row, atomFactory);

		/* 07 — Substitute the values in S for the variables in A.
		 * 08 — Create a stem query disjoint DQS which is a reproduction of the mapping rule antecedent A
		 * http://www.w3.org/2008/07/MappingRules/#_07
		 */
		MappedDuplicator e(atomFactory, *row, &includeRequiredness
#if REGEX_LIB == SWOb_BOOST
				   , uriMaps
#endif /* REGEX_LIB == SWOb_BOOST */
				   );
		constructRuleBodyAsConsequent->express(&e);
		TableOperation* t = e.getTableOperation();
		if (t != NULL)
		    patternSpanningRows->addTableOperation(t, true);
	    }

	    TableOperation* res = patternSpanningRows->simplify(); // !!! should be a simplifying expressor
	    if (res != NULL) {
		opRS->copyFiltersTo(res);
		opRS->addTableOperation(res);

	    }
	    if (*debugStream != NULL) {
		if (res == NULL)
		    **debugStream << "yielding no transformed query disjoint." << std::endl << std::endl;
		else
		    **debugStream << "yielding transformed query disjoint:" << std::endl << *res << std::endl;
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
	std::map<const TTerm*, size_t> variablesInLexicalOrder;
	size_t nextVariableIndex;

#if REGEX_LIB == SWOb_BOOST
	std::vector<POSmap> uriMaps;
#endif /* REGEX_LIB == SWOb_BOOST */

    public:
	RuleInverter (AtomFactory* atomFactory, std::ostream** debugStream = NULL) : 
	    SWObjectDuplicator(atomFactory), debugStream(debugStream), inUserRuleHead(false), nextVariableIndex(0) {  }

	MappingConstruct* getConstruct() { return m_Construct; }

	/* duplicate triples and note the order of POSs.
	 * This is called from _TriplePatters call in _graphPatterns.
	 */
	virtual void triplePattern (TriplePattern* self, TTerm* s, TTerm* p, TTerm* o) {
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
	    std::map<const TTerm*, size_t>& v;
	    MapOrder (std::map<const TTerm*, size_t>& v) : v(v) {  }
	    int _orderAtoms (const TTerm* l, const TTerm* r) {
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

	void _graphPattern (BasicGraphPattern* bgp, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    _TriplePatterns(p_TriplePatterns, bgp);
	    last.tableOperation = bgp;

	    if (inUserRuleHead)
		std::sort(bgp->begin(), bgp->end(), MapOrder(variablesInLexicalOrder));
	}

	/* Create BasicGraphPatterns (named and default) with a flag
	 * indicating the special semantics of all triples being
	 * optional (03).
	 */
	virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    p_name->express(this);
	    _graphPattern(new NamedGraphPattern(last.tterms.tterm, inUserRuleHead), p_allOpts, p_TriplePatterns); // allOpts = true when in rule body
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    _graphPattern(new DefaultGraphPattern(inUserRuleHead), p_allOpts, p_TriplePatterns); // allOpts = true when in rule body
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
		SPARQLSerializer sparqlizer(MediaType(), NULL, "  ", SPARQLSerializer::DEBUG_graphs);
		constructRuleBodyAsConsequent->express(&sparqlizer);
		**debugStream << "product rule head (SPARQL):" << std::endl << sparqlizer.str() << std::endl;
	    }
	    p_SolutionModifier->express(this);

	    m_Construct = new MappingConstruct(constructRuleBodyAsConsequent,	 // consequent of new mapping rule
					       _DatasetClauses(p_DatasetClauses),//
					       constructRuleHeadAsPattern,	 // antecedent of new mapping rule
					       last.solutionModifier, 		 //
					       atomFactory, 
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
	    if (p_IRIref != atomFactory->getURI("http://www.w3.org/2008/04/SPARQLfed/#rewriteVar"))
		SWObjectDuplicator::functionCall(me, p_IRIref, p_ArgList);
	    if (p_ArgList->size() != 3)
		w3c_sw_FAIL("wrong number of arguments to sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\")");
	    std::vector<const Expression*>::iterator it = p_ArgList->begin();
	    const TTermExpression* exp;
	    exp = dynamic_cast<const TTermExpression*>(*it);
	    const Bindable* toModify = exp ? dynamic_cast<const Bindable*>(exp->getTTerm()) : NULL;
	    if (toModify == NULL)
		w3c_sw_FAIL("sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\"): parm 1 not a variable");
	    ++it;
	    exp = dynamic_cast<const TTermExpression*>(*it);
	    const RDFLiteral* localName = exp ? dynamic_cast<const RDFLiteral*>(exp->getTTerm()) : NULL;
	    if (localName == NULL)
		w3c_sw_FAIL("sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\"): parm 2 not a literal");
	    /* localName
	     * http://bsbm.example/db/productfeatureproduct/offer.nr=(?@offer=[0-9]+)&publisher=(?@pub=[0-9]+)
	     */

	    ++it;
	    exp = dynamic_cast<const TTermExpression*>(*it);
	    const RDFLiteral* ifaceName = exp ? dynamic_cast<const RDFLiteral*>(exp->getTTerm()) : NULL;
	    if (ifaceName == NULL)
		w3c_sw_FAIL("sp:rewriteVar(?var, \"localPattern\", \"ifacePattern\"): parm 3 not a literal");
	    /* ifaceName
	     * http://www4.wiwiss.fu-berlin.de/bizer/bsbm/v01/instances/dataFromVendor(?@pub=[0-9]+)/Offer(?@offer=[0-9]+)
	     */
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
		std::string iriStr(ifaceName->getLexicalValue());
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
		std::string iriStr(localName->getLexicalValue());
		boost::sregex_token_iterator it(iriStr.begin(), iriStr.end(), re, desiredMatches);
		std::stringstream subPattern;
		while (it != nullIt) {
		    subPattern << *it++;
		    if (it != nullIt) {
			std::string var = *it++;
			if (patternVars[var].i == 0)
			    w3c_sw_FAIL1("unknown var: %s", var.c_str());

			subPattern << '\\' << patternVars[var].i;
			std::string pattern = *it++;
			if (pattern.size() != 0) {
			    if (patternVars[var].pattern.size() == 0)
				patternVars[var].pattern = pattern;
			    else if (patternVars[var].pattern != pattern)
				w3c_sw_FAIL3("local pattern for var %s: %s doesn't match iface pattern %s", 
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

