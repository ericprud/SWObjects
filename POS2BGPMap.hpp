/* POS2BGPMap.hpp — association variables with the BGPs in which they appear.
 *
 * POS2BGP does double duty:
 *
 * • For SQL query translation, POS2BGP determines which variables are coref'd
 *   in which table operations. This is needed for the mapping from SPARQL
 *   queries, which have a single namespace for all veriables, to SQL, which
 *   requires subqueries with different table alias namespaces to express
 *   certain OPTIONALs and all UNIONs.
 *
\ * • For RuleMap query translation, POS2BGP keeps track of which OPTIONALs in
 *   the rule antecedent are needed to produce the data for a given query, and
 *   which are treated as mandatory because they correspond to mandatory parts
 *   of the query. Any OPTIONALs which introduce variables referenced in a later
 *   graph pattern must also be included. <antecedents> maps graph patterns to
 *   the graph patterns that may affect them.
 *
 * $Id: POS2BGPMap.hpp,v 1.12 2008-09-16 18:57:13 eric Exp $
 */

#pragma once

#include "SWObjects.hpp"
#include "exs.hpp"
#include <set>
#include <vector>

namespace w3c_sw {

    typedef enum {Binding_NONE = 0x20, 
		  Binding_STRONG = 1, Binding_FILTER = 2, Binding_SELECT = 4, 
		  Binding_WEAK = 8, Binding_COREF = 0x10} BindingStrength;
    class ConsequentMap : public std::map<TableOperation*, BindingStrength> {
    public:
	BindingStrength getOperationStrength (TableOperation* bgp) {
	    ConsequentMap::iterator it = find(bgp);
	    if (it == end())
		return Binding_NONE;
	    return it->second == Binding_STRONG ? Binding_STRONG : Binding_WEAK;
	}
    };
    typedef std::map<POS*, ConsequentMap>		ConsequentMapList;

    class Consequents {

	typedef std::set< TableOperation* >			OuterGraphList;
	typedef std::map< TableOperation*, OuterGraphList >	OuterGraphs;

	typedef std::pair< POS*, TableOperation* >		IQEnt;
	typedef std::vector< IQEnt >				InsertQueue;

	class ConsequentsConstructor : public RecursiveExpressor {
	protected:
	    ConsequentMapList& consequents;  // hate refs, but like the [foo][bar] syntax
	    BindingStrength optState;
	    POS* graphName;
	    std::vector<TableOperation*> bgpStack;
	    OuterGraphs outerGraphs;

	    void _depends (POS* pos, BindingStrength strength) {
		/* The dependencies algorithm works fine with literals and URIs,
		   but we don't need them (yet?). */
		if (!dynamic_cast<Variable*>(pos) &&
		    !dynamic_cast<BNode*>(pos))
		    return;

		TableOperation* bgp = bgpStack.back();
		ConsequentMapList::iterator maps = consequents.find(pos);
		if (maps == consequents.end()) {
		    /* No BGP has introduced this variable. */
		    consequents[pos][bgp] = strength;
		} else {
		    ConsequentMap::iterator consequent = consequents[pos].find(bgp);
		    if (consequent == consequents[pos].end()) {
			/* This BGP has not introduced this variable. */

			/* Omit { variables => BGP } mappings where the BGP is optional and the variable is mandatory elsewhere.
			 * 06b — If the variable is weak in S and GA is optional and the variable is not in any mandatory antecedent graph, tag GA as an included optional.
			 *                                                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			 */
			if (strength == Binding_WEAK) {
			    /* Only assert if no existing mandatory BGPs introduce this variable. */
			    for (ConsequentMap::iterator bgps = consequents[pos].begin();
				 bgps != consequents[pos].end(); ++bgps)
				if (bgps->second == Binding_STRONG)
				    /* Already introduced elsewhere, so just return. */
				    return;
			} else {
			    /* No existing optional BGPs introduce this variable. */
			    for (ConsequentMap::iterator bgps = consequents[pos].begin();
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

	    /* RecursiveExpressor overloads:
	     */
	    virtual void base (Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

	    virtual void triplePattern (TriplePattern*, w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) {
		_depends(p_s, optState);
		_depends(p_p, optState);
		_depends(p_o, optState);
	    }

	    virtual void namedGraphPattern (NamedGraphPattern*, w3c_sw::POS* p_name, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>*) {
		_depends(p_name, optState);
		p_TriplePatterns->express(this);
		// p_Filters->express(this); @@ what to do with these?
	    }

	    virtual void defaultGraphPattern (DefaultGraphPattern*, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>*) {
		p_TriplePatterns->express(this);
		// p_Filters->express(this); @@ what to do with these?
	    }

	    void _each (ProductionVector<TableOperation*>* p_TableOperations) {
		for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    bgpStack.push_back(*it);
		    (*it)->express(this);
		    bgpStack.pop_back();
		    outerGraphs[*it].insert(bgpStack.back());
		}
	    }

	    virtual void tableDisjunction (TableDisjunction*, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>*) {
		_each(p_TableOperations);
		//p_Filters->express(this);
	    }
	    virtual void tableConjunction (TableConjunction*, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>*) {
		_each(p_TableOperations);
		//p_Filters->express(this);
	    }
	    virtual void optionalGraphPattern (OptionalGraphPattern*, TableOperation* p_GroupGraphPattern) {
		BindingStrength oldOptState = optState;
		optState = Binding_WEAK;
		bgpStack.push_back(p_GroupGraphPattern);
		p_GroupGraphPattern->express(this);
		bgpStack.pop_back();
		outerGraphs[p_GroupGraphPattern].insert(bgpStack.back());
		optState = oldOptState;
	    }

	    virtual void graphGraphPattern (GraphGraphPattern*, w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
		POS* oldGraphName = graphName;
		graphName = p_POS;
		bgpStack.push_back(p_GroupGraphPattern);
		p_GroupGraphPattern->express(this);
		bgpStack.pop_back();
		outerGraphs[p_GroupGraphPattern].insert(bgpStack.back());
		graphName = oldGraphName;
	    }

	    /* Add Binding_SELECT where necessary. */
	    virtual void posList (POSList*, ProductionVector<w3c_sw::POS*>* p_POSs) {
		for (std::vector<POS*>::iterator it = p_POSs->begin();
		     it != p_POSs->end(); it++)
		    _depends(*it, Binding_SELECT);
	    }
	    virtual void starVarSet (StarVarSet*) {
		FAIL("um, I'm not really up to handling SELECT *.");
	    }

	    /* Stuff for building a consequents list.
	     */
	    static string bindingStr (BindingStrength s) {
		return s == Binding_STRONG ? "STRONG" : 
		    s == Binding_WEAK   ? "WEAK"   :
		    s == Binding_FILTER ? "FILTER" :
		    s == Binding_SELECT ? "SELECT" :
		    s == Binding_COREF  ? "COREF"  : 
		    "???";
	    }

	    string dumpConsequents () {
		stringstream s;
		for (ConsequentMapList::iterator varIt = consequents.begin();
		     varIt != consequents.end(); ++varIt)
		    for (ConsequentMap::iterator graphIt = varIt->second.begin();
			 graphIt != varIt->second.end(); ++graphIt)
			s << "consequents[" << varIt->first->getTerminal() << "][" << graphIt->first << "] = " << bindingStr(consequents[varIt->first][graphIt->first]) << endl;
		return s.str();
	    }

	    string dumpOuterGraphs () {
		stringstream s;
		for (OuterGraphs::iterator innerGraphIt = outerGraphs.begin();
		     innerGraphIt != outerGraphs.end(); ++innerGraphIt) {
		    s << "outerGraphs[" << innerGraphIt->first << "]={";
		    for (OuterGraphList::iterator outerGraphIt = innerGraphIt->second.begin();
			 outerGraphIt != innerGraphIt->second.end(); ++outerGraphIt) {
			if (outerGraphIt != innerGraphIt->second.begin())
			    s << ",";
			s << *outerGraphIt;
		    }
		    s << "}" << endl;
		}
		return s.str();
	    }

	    /* findCorefs: Add COREF BindingStrengths to consequents whereever a
	     * variable referenced in multiple subgraphs. For example, given the
	     * query graph
	         {:1 {:2 ?x }
                     {:3 OPT {:4 ?x ?y } FILTER ?y }
                     {:5 {:6 {:7 ?z } FILTER ?z }
                         {:8 {:9 {:10 ?z } } }
                      }
                  }
	     * the complete consequents tree, including corefs is
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

	     * We start with a tree without the corefs
	         consequents[x][2] = STRONG
	                       [4] = WEAK
	         consequents[y][3] = FILTER
	                       [4] = WEAK
	         consequents[z][5] = STRONG
	                       [6] = FILTER
	                       [10] = STRONG
	     * and a list for each graph of the graphs that contain it
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
	    void findCorefs (TableOperation* parent) {
		/* For each known variable: */
		for (ConsequentMapList::iterator varIt = consequents.begin();
		     varIt != consequents.end(); ++varIt) {

		    /* Create an insert queue so we don't muck with the iterator. */
		    InsertQueue iq;

		    /* For each pair of graphs that reference var
		       e.g. for z: graph1It graph2It
					5	6
					5	10
					6	10 */
		    TableOperation* lastTableOp = consequents[varIt->first].rbegin()->first;
		    for (ConsequentMap::iterator graph1It = consequents[varIt->first].begin();
			 graph1It->first != lastTableOp; ++graph1It) {
			ConsequentMap::iterator graph2It = graph1It;
			for (++graph2It; graph2It != consequents[varIt->first].end(); ++graph2It) {

			    /* Walk pairwise through the lineage of g1,g2 from the root
			     * until the lineage diverges, storing the common parents. */
			    OuterGraphList::iterator graph1parents = outerGraphs[graph1It->first].begin();
			    OuterGraphList::iterator graph2parents = outerGraphs[graph2It->first].begin();
			    TableOperation* commonAncestor = parent; // assignment not strictly necessary, but useful for templating.
			    while (graph1parents != outerGraphs[graph1It->first].end() && 
				   *graph1parents == *graph2parents) {
				commonAncestor = *graph1parents;
				++graph1parents;
				++graph2parents;
// 				if (*graph1parents == *graph2parents &&
// 				    graph1parents == outerGraphs[graph1It->first].end()) {
// 				    std::cout << "while resolving " << varIt->first->getTerminal() <<  ", got to " << *graph1parents << " == " << *graph2parents << " but at end of graph1. last was " << commonAncestor << endl;
// 				    std::cout << dumpConsequents();
// 				    std::cout << dumpOuterGraphs();
// 				}
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

		    /* Insert queued items. */
		    for (InsertQueue::iterator p = iq.begin(); p != iq.end(); ++p)
			consequents[p->first][p->second] = Binding_COREF;
		}
	    }

	};

    protected:
	ConsequentMapList consequents;

    public:
	Consequents (TableOperation* op, VarSet* p_VarSet = NULL, std::ostream* debugStream = NULL) {
	    ConsequentsConstructor ctor(&consequents, op);
	    op->express(&ctor);
	    if (p_VarSet != NULL) p_VarSet->express(&ctor);
	    ctor.findCorefs(op);
	    if (debugStream != NULL) {
		*debugStream << "Consequents:" << std::endl << ctor.dumpConsequents();
		*debugStream<< "OuterGraphs:" << std::endl << ctor.dumpOuterGraphs();
	    }
	}
	~Consequents () {
	    for (ConsequentMapList::iterator maps = consequents.begin();
		 maps != consequents.end(); ++maps) {
		maps->second.clear();
	    }
	    consequents.clear();
	}

	Variable* _genVar (Variable* base, int index, Result* row, POSFactory* posFactory) {
	    Variable* ret = NULL;
	    do {
		std::stringstream name;
		name << base->getTerminal() << "_gen" << index;
		ret = posFactory->getVariable(name.str().c_str());
		++index;
	    } while (row->get(ret) != NULL);
	    return ret;
	}

	ConsequentMap getIncludeRequiredness (ResultSet* rs, ResultSetIterator row, POSFactory* posFactory) {
	    ConsequentMap ret;
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
			       This is acutally unsound as we
			       want to include any OPT which
			       introduces constraints used by
			       an OPT included later.
			    */
#warning not including dependent optionals yet
			    continue;
			}
		    }
		    ret[bgpBindings->first] = (bgpBindings->second == Binding_STRONG || 
					       (*row)->get(v) == false) ? Binding_WEAK : Binding_STRONG;
		}
		    
	    }

	    for (std::set<Variable*>::iterator v = neededVars.begin();
		 v != neededVars.end(); ++v)
		rs->set(*row, *v, _genVar(*v, genNo++, *row, posFactory), true);
	    neededVars.clear();
	    return ret;
	}

	/* Collect all the POS entries referenced in a particular TableOperation. */
	std::vector<POS*> entriesFor (TableOperation* op) {
	    std::vector<POS*> ret;
	    for (ConsequentMapList::iterator varIt = consequents.begin();
		 varIt != consequents.end(); ++varIt)
		if (varIt->second.find(op) != varIt->second.end())
		    ret.push_back(varIt->first);
	    return ret;
	}
    };
}

