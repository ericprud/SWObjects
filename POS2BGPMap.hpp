/* POS2BGPMap.hpp - association variables with the BGPs in which they appear.
 *
 * $Id: POS2BGPMap.hpp,v 1.2 2008-09-01 16:53:11 eric Exp $
 */

#pragma once

#include "SWObjects.hpp"
#include "exs.hpp"
#include <set>
#include <vector>

namespace w3c_sw {

    typedef enum {Binding_STRONG = 1, Binding_WEAK = 0, Binding_COREF = 5} BindingStrength;
    typedef std::map<TableOperation*, BindingStrength> ConsequentMap;
    typedef std::map<TableOperation*, BindingStrength>::iterator ConsequentMapIterator;
    typedef std::map<POS*, ConsequentMap> ConsequentMapList;
    typedef std::map<POS*, ConsequentMap>::iterator ConsequentMapListIterator;

    typedef std::set< TableOperation* >			OuterGraphList;
    typedef std::map< TableOperation*, OuterGraphList >	OuterGraphs;

    typedef std::pair< POS*, TableOperation* >		IQEnt;
    typedef std::vector< IQEnt >			InsertQueue;

    class Consequents {

	class ConsequentsConstructor : public RecursiveExpressor {
	protected:
	    ConsequentMapList& consequents;  // hate refs, but like the [foo][bar] syntax
	    BindingStrength optState;
	    POS* graphName;
	    std::vector<TableOperation*> bgpStack;
	    OuterGraphs outerGraphs;

	    void _depends (POS* pos, BindingStrength strength) {
		TableOperation* bgp = bgpStack.back();
		assert(dynamic_cast<BasicGraphPattern*>(bgp) != NULL);
		ConsequentMapListIterator maps = consequents.find(pos);
		if (maps == consequents.end()) {
		    /* No BGP has introduced this variable. */
		    consequents[pos][bgp] = strength;
		} else {
		    ConsequentMapIterator consequent = consequents[pos].find(bgp);
		    if (consequent == consequents[pos].end()) {
			/* This BGP has not introduced this variable. */

			/* Omit { variables => BGP } mappings where the BGP is optional and the variable is mandatory elsewhere.
			 * 06b — If the variable is weak in S and GA is optional and the variable is not in any mandatory antecedent graph, tag GA as an included optional.
			 *                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			 */
			if (strength == Binding_WEAK) {
			    /* Only assert if no existing mandatory BGPs introduce this variable. */
			    for (ConsequentMapIterator bgps = consequents[pos].begin();
				 bgps != consequents[pos].end(); ++bgps)
				if (bgps->second == Binding_STRONG)
				    /* Already introduced elsewhere, so just return. */
				    return;
			} else {
			    /* No existing optional BGPs introduce this variable. */
			    for (ConsequentMapIterator bgps = consequents[pos].begin();
				 bgps != consequents[pos].end();)
				if (bgps->second == Binding_WEAK) // !!! OPT { ?x } .?x  -- keep the first one? guess not.
				    consequents[pos].erase(bgps++);
				else
				    bgps++;
			}

			consequents[pos][bgp] = strength;
		    } else if (consequents[pos][bgp] == Binding_WEAK && strength == Binding_STRONG)
			FAIL("reassignment of weakly bound variable to strongly bound in the same BGP."); // @@ shouldn't happen? consequents[pos][bgp] = false;
		}
	    }

	public:
	    ConsequentsConstructor (ConsequentMapList* consequents, TableOperation* op) : 
		consequents(*consequents), optState(Binding_STRONG), graphName(NULL), bgpStack(), outerGraphs() {
		bgpStack.push_back(op);
	    }
	    virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

	    virtual TriplePattern* triplePattern (w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) {
		_depends(p_s, optState);
		_depends(p_p, optState);
		_depends(p_o, optState);
		return NULL;
	    }

	    virtual NamedGraphPattern* namedGraphPattern (w3c_sw::POS* p_name, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>*) {
		_depends(p_name, optState);
		p_TriplePatterns->express(this);
		// p_Filters->express(this); @@ what to do with these?
		return NULL;
	    }

	    virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>*) {
		p_TriplePatterns->express(this);
		// p_Filters->express(this); @@ what to do with these?
		return NULL;
	    }

	    /* {:1 {:2 ?x ?z }
                   {:3 OPT {:4 ?x ?y } FILTER ?y }
                   {:5 {:6 {:7 ?z } }
                       {:8 {:9 {:10 ?z } } }
                    }
                }
	       consequents[x][1] = COREF
	                     [2] = STRONG
	                     [3] = COREF
	                     [4] = WEAK
	       consequents[y][3] = FILTER
	                     [4] = WEAK
	       consequents[z][5] = STRONG
	                     [6] = FILTER
	                     [7] = STRONG
	                     [8] = COREF
	                     [9] = COREF
	                    [10] = STRONG
	    */
	    /* 1st pass: {:1 {:2 ?x }
                             {:3 OPT {:4 ?x ?y } FILTER ?y }
                             {:5 {:6 {:7 ?z } FILTER ?z }
                                 {:8 {:9 {:10 ?z } } }
                              }
                          }
	       consequents[x][2] = STRONG
	       consequents[x][4] = WEAK
	       consequents[y][3] = FILTER
	       consequents[y][4] = WEAK
	       consequents[z][6] = FILTER
	       consequents[z][5] = STRONG
	       consequents[z][10] = STRONG

	       outerGraphs[2][1]
	       outerGraphs[3][1]
	       outerGraphs[4][3,1]
	       outerGraphs[5][1]
	       outerGraphs[6][5,1]
	       outerGraphs[7][6,5,1]
	       outerGraphs[8][5,1]
	       outerGraphs[9][8,5,1]
	       outerGraphs[10][9,8,5,1]
	    */
	    void _copyCorefs (TableOperation* child, TableOperation* parent) {
		outerGraphs[child].insert(parent);
	    }

	    void findCorefs (TableOperation* parent) {
		/* For each known variable: */
		for (ConsequentMapList::iterator varIt = consequents.begin();
		     varIt != consequents.end(); ++varIt) {

		    /* Create an insert queue so we don't muck with the iterator. */
		    InsertQueue iq;

		    /* For each pair of graphs that reference var: */
		    for (ConsequentMap::iterator graph1It = consequents[varIt->first].begin();
			 graph1It->first != consequents[varIt->first].rbegin()->first; ++graph1It) {
			ConsequentMap::iterator graph2It = graph1It;
			for (++graph2It; graph2It != consequents[varIt->first].end(); ++graph2It) {

			    /* Walk pairwise through the lineage of g1,g2 from the root
			     * until the lineage diverges, storing the common parents. */
			    OuterGraphList::iterator graph1parents = outerGraphs[graph1It->first].begin();
			    OuterGraphList::iterator graph2parents = outerGraphs[graph2It->first].begin();
			    TableOperation* commonAncestor = parent; // assignment not strictly necessary, but useful for templating.
			    while (*graph1parents == *graph2parents) {
				commonAncestor = *graph1parents;
				++graph1parents;
				++graph2parents;
			    }

			    /* If neither lineage is not subsumed by the other, and
			     * there's no existing entry for that pair, the last
			     * ancestor is the top COREF. */
			    if (*graph1parents != graph2It->first &&
				*graph2parents != graph1It->first &&
				consequents[varIt->first].find(commonAncestor) == consequents[varIt->first].end())
				iq.push_back(IQEnt(varIt->first, commonAncestor));

			    /* All items in the lineage from here down are COREFs unless
			     * they are already set to something else */
			    for (; graph1parents != outerGraphs[graph1It->first].end(); ++graph1parents)
				if (consequents[varIt->first].find(*graph1parents) == consequents[varIt->first].end())
				    iq.push_back(IQEnt(varIt->first, *graph1parents));

			    for (; graph2parents != outerGraphs[graph2It->first].end(); ++graph2parents)
				if (consequents[varIt->first].find(*graph2parents) == consequents[varIt->first].end())
				    iq.push_back(IQEnt(varIt->first, *graph2parents));
			}
		    }
		    /* Insert queued items (so they don't muck with the iterators).
		     */
		    for (InsertQueue::iterator p = iq.begin(); p != iq.end(); ++p)
			consequents[p->first][p->second] = Binding_COREF;
		}
	    }

	    void _each (ProductionVector<TableOperation*>* p_TableOperations) {
		for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    bgpStack.push_back(*it);
		    (*it)->express(this);
		    bgpStack.pop_back();
		    _copyCorefs(*it, bgpStack.back());
		}
	    }

	    virtual TableDisjunction* tableDisjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>*) {
		_each(p_TableOperations);
		//p_Filters->express(this);
		return NULL;
	    }
	    virtual TableConjunction* tableConjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>*) {
		_each(p_TableOperations);
		//p_Filters->express(this);
		return NULL;
	    }
	    virtual OptionalGraphPattern* optionalGraphPattern (TableOperation* p_GroupGraphPattern) {
		BindingStrength oldOptState = optState;
		optState = Binding_WEAK;
		bgpStack.push_back(p_GroupGraphPattern);
		p_GroupGraphPattern->express(this);
		bgpStack.pop_back();
		_copyCorefs(p_GroupGraphPattern, bgpStack.back());
		optState = oldOptState;
		return NULL;
	    }

	    virtual GraphGraphPattern* graphGraphPattern (w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
		POS* oldGraphName = graphName;
		graphName = p_POS;
		bgpStack.push_back(p_GroupGraphPattern);
		p_GroupGraphPattern->express(this);
		bgpStack.pop_back();
		_copyCorefs(p_GroupGraphPattern, bgpStack.back());
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
	    /* eliminate unnecessary corefs from tree */
	    //ctor.findCorefs(op);
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
}

