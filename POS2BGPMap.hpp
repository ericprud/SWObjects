/* POS2BGPMap.hpp — association variables with the BGPs in which they appear.
 * $Id: POS2BGPMap.hpp,v 1.26 2008-11-04 15:12:53 eric Exp $
 *
 * POS2BGP does double duty:
 *
 * • For SQL query translation, POS2BGP determines which variables are coref'd
 *   in which table operations. This is needed for the mapping from SPARQL
 *   queries, which have a single namespace for all veriables, to SQL, which
 *   requires subqueries with different table alias namespaces to express
 *   certain OPTIONALs and all UNIONs.
 * vector<POS*> entriesFor(TableOperation*)
 *
 * • For RuleMap query translation, POS2BGP keeps track of which OPTIONALs in
 *   the rule antecedent are needed to produce the data for a given query, and
 *   which are treated as mandatory because they correspond to mandatory parts
 *   of the query. Any OPTIONALs which introduce variables referenced in a later
 *   graph pattern must also be included. <antecedents> maps graph patterns to
 *   the graph patterns that may affect them.
 *
 * ConsequentMap getIncludeRequiredness(ResultSet*, ResultSetIterator, POSFactory*)
 *   called by: MappingConstruct::execute
 *   returns: a ConsequentMap of the constructRuleBodyAsConsequent (see below).
 *
 * std::vector<POS*> entriesFor (TableOperation* op)
 *   called by: SQLizer::tableDisjunction
 *              SQLizer::optionalGraphPattern
 *   returns: all the POS entries referenced in a particular TableOperation.
 *   Used to determine which fields in an SQL subquery are referenced outside
 *   that query.
 *
 * GraphInclusion ConsequentMap::getOperationStrength(TableOperation*)
 *   called by: MappingConstruct::MappedDuplicator table operation expressors.
 *   returns: whether a TableOperation in constructRuleBodyAsConsequent was
 *            implicated in the user's query.
 *
 * 
 *
 */

#pragma once

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "exs.hpp"
#include <set>
#include <vector>

namespace w3c_sw {

    /* used for GraphInclusion getOperationStrength(TableOperation*) */
    typedef enum {GraphInclusion_NONE = 1, GraphInclusion_STRONG, GraphInclusion_WEAK} GraphInclusion;

    /* internal representation. */
    typedef enum {_Binding_GRAPH = 1, _Binding_SELECT = 2, _Binding_FILTER = 4, _Binding_COREF = 8, 
		  _Binding_WEAK = 0x10, _Binding_INTRODUCED = 0x20} _BindingStrength;

    class ConsequentMap : public std::map<const TableOperation*, _BindingStrength> {
	friend class Consequents;
	friend class ConsequentMapList;
    public:
	//_BindingStrength& operator[] (const TableOperation*& subscript) { return std::map<TableOperation*, _BindingStrength>::operator[](subscript); }

	GraphInclusion getOperationStrength (const TableOperation* bgp) {
	    std::map<const TableOperation*, _BindingStrength>::iterator it = find(bgp);
	    if (it == end() || 
		(it->second & _Binding_WEAK && 0)) // !(it->second & _Binding_INTRODUCED)))
		return GraphInclusion_NONE;
	    return it->second & _Binding_GRAPH ? GraphInclusion_STRONG : GraphInclusion_WEAK;
	}
    };
    class ConsequentMapList : public std::map<const POS*, ConsequentMap> {
	friend class Consequents;
	friend class ConsequentMap;

	//ConsequentMap& operator[] (POS*& subscript) { return std::map<POS*, ConsequentMap>::operator[](subscript); }

	/* Stuff for building a consequents list.
	 */
	static string _hex (_BindingStrength s) {
	    stringstream ret;
	    ret << (void*)s;
	    return ret.str();
	}

    public:
	static string bindingStr (_BindingStrength s) {
	    string ret;
	    if (s & _Binding_GRAPH)  ret.append("GRAPH " );
	    if (s & _Binding_FILTER) ret.append("FILTER ");
	    if (s & _Binding_SELECT) ret.append("SELECT ");
	    if (s & _Binding_COREF)  ret.append("COREF " );
	    if (s & _Binding_WEAK)
		ret.append(" WEAK");
	    if (s & _Binding_INTRODUCED)
		ret.append(" INTRODUCED");
	    return ret;
	}

	string dump () {
	    stringstream s;
	    for (ConsequentMapList::iterator varIt = begin();
		 varIt != end(); ++varIt)
		for (ConsequentMap::iterator graphIt = varIt->second.begin();
		     graphIt != varIt->second.end(); ++graphIt)
		    s << "consequents[" << varIt->first->getTerminal() << "]["
		      << graphIt->first << "] = "
		      << bindingStr(operator[](varIt->first)[graphIt->first])
		      << endl;
	    return s.str();
	}
    };

    class Consequents {

	typedef std::set< const TableOperation* >			OuterGraphList;
	typedef std::map< const TableOperation*, OuterGraphList >	OuterGraphs;

	typedef std::pair< const POS*, const TableOperation* >		IQEnt;
	typedef std::vector< IQEnt >				InsertQueue;

	/* ConsequentsConstructor — helper class to compile ConsequentMapLists.
	 */
	class ConsequentsConstructor : public RecursiveExpressor {
	protected:
	    ConsequentMapList& consequents;  // hate refs, but like the [foo][bar] syntax
	    _BindingStrength optState;
	    const POS* graphName;
	    const TableOperation* currentBGP;
	    OuterGraphs outerGraphs;

	    void _depends (const POS* pos, _BindingStrength strength) {
		/* The dependencies algorithm works fine with literals and URIs,
		   but we don't need them (yet?). */
		if (!dynamic_cast<const Variable*>(pos) &&
		    !dynamic_cast<const BNode*>(pos))
		    return;

		consequents[pos][currentBGP] = strength;
	    }

	public:
	    /* ConsequentsConstructor — helper class to compile ConsequentMapLists.
	     *   consequents: list to build
	     *   op: TableOperation to use as root (needed for marking variabe
	     *       references like those in a SELECT posList.
	     */
	    ConsequentsConstructor (ConsequentMapList* consequents, const TableOperation* op) : 
		consequents(*consequents), optState(_Binding_GRAPH), graphName(NULL), currentBGP(op), outerGraphs()
	    {  }

	    /* RecursiveExpressor overloads:
	     */
	    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	    virtual void triplePattern (const TriplePattern* const, const POS* p_s, const POS* p_p, const POS* p_o) {
		START("POS2BGPMap::triplePattern");
		_depends(p_s, optState);
		_depends(p_p, optState);
		_depends(p_o, optState);
	    }

	    void _nestedIn (const TableOperation* inner, const TableOperation* outer) {
		if (outer == NULL)
		    return;
		outerGraphs[inner].insert(outer);
		for (std::set< const TableOperation* >::iterator it = outerGraphs[outer].begin();
		     it != outerGraphs[outer].end(); ++it)
		    outerGraphs[inner].insert(*it);
	    }

	    virtual void namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
		START("POS2BGPMap::namedGraphPattern");
		const TableOperation* parent = currentBGP;
		currentBGP = self;
		_nestedIn(self, parent);
		_depends(p_name, optState);
		p_TriplePatterns->express(this);
		p_Filters->express(this);
		currentBGP = parent;
	    }

	    virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
		START("POS2BGPMap::defaultGraphPattern");
		const TableOperation* parent = currentBGP;
		currentBGP = self;
		_nestedIn(self, parent);
		p_TriplePatterns->express(this);
		p_Filters->express(this);
		currentBGP = parent;
	    }

	    void _each (const TableOperation* self, const ProductionVector<const TableOperation*>* p_TableOperations) {
		const TableOperation* parent = currentBGP;
		currentBGP = self;
		_nestedIn(self, parent);
		currentBGP = self;
		for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    (*it)->express(this);
		}
		currentBGP = parent;
	    }

	    virtual void tableDisjunction (const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations, const ProductionVector<const Filter*>* p_Filters) {
		_each(self, p_TableOperations);
		p_Filters->express(this);
	    }
	    virtual void tableConjunction (const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations, const ProductionVector<const Filter*>* p_Filters) {
		_each(self, p_TableOperations);
		p_Filters->express(this);
	    }
	    virtual void optionalGraphPattern (const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern) {
		_BindingStrength oldOptState = optState;
		optState = (_BindingStrength)(optState | _Binding_WEAK);
		const TableOperation* parent = currentBGP;
		currentBGP = self;
		_nestedIn(self, parent);

		p_GroupGraphPattern->express(this);

		currentBGP = parent;
		optState = oldOptState;
	    }

	    virtual void graphGraphPattern (const GraphGraphPattern* const self, const POS* p_POS, const TableOperation* p_GroupGraphPattern) {
		const POS* oldGraphName = graphName;
		graphName = p_POS;
		const TableOperation* parent = currentBGP;
		currentBGP = self;
		_nestedIn(self, parent);

		p_GroupGraphPattern->express(this);

		currentBGP = parent;
		graphName = oldGraphName;
	    }

	    /* Add _Binding_SELECT where necessary. */
	    virtual void posList (const POSList* const, const ProductionVector<const POS*>* p_POSs) {
		for (std::vector<const POS*>::const_iterator it = p_POSs->begin();
		     it != p_POSs->end(); it++)
		    _depends(*it, _Binding_SELECT);
	    }
	    virtual void starVarSet (const StarVarSet* const) {
		FAIL("umm, I'm not really up to handling SELECT *.");
	    }

	    virtual void varExpression (const VarExpression* const, const Variable* p_Variable) {
		_depends(p_Variable, _Binding_FILTER);
	    }
	    virtual void literalExpression (const LiteralExpression* const, RDFLiteral* p_RDFLiteral) {
		_depends(p_RDFLiteral, _Binding_FILTER);
	    }
	    virtual void booleanExpression (const BooleanExpression* const, BooleanRDFLiteral* p_BooleanRDFLiteral) {
		_depends(p_BooleanRDFLiteral, _Binding_FILTER);
	    }
	    virtual void uriExpression (const URIExpression* const, URI* p_URI) {
		_depends(p_URI, _Binding_FILTER);
	    }

	    string dumpConsequents () {
		return consequents.dump();
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

	    /* findCorefs: Add COREF _BindingStrengths to consequents whereever a
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
	    void findCorefs (const TableOperation* parent) {
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
		    const POS* pos = varIt->first;
		    ConsequentMap cons = consequents[pos];
		    ConsequentMap::reverse_iterator last = cons.rbegin();
		    //		    ConsequentMap::iterator last = consequents[varIt->first].rbegin();
		    if (last == cons.rend()) {
			cerr << "no entry for " << varIt->first->toString() << endl; // !!! check with a FAIL
			continue; // no entries for this whatever.
		    }
		    const TableOperation* lastTableOp = last->first;
		    for (ConsequentMap::iterator graph1It = consequents[varIt->first].begin();
			 graph1It->first != lastTableOp; ++graph1It) {
			ConsequentMap::iterator graph2It = graph1It;
			for (++graph2It; graph2It != consequents[varIt->first].end(); ++graph2It) {

			    /* Walk pairwise through the lineage of g1,g2 from the root
			     * until the lineage diverges, storing the common parents. */
			    OuterGraphList::iterator graph1parents = outerGraphs[graph1It->first].begin();
			    OuterGraphList::iterator graph2parents = outerGraphs[graph2It->first].begin();
			    const TableOperation* commonAncestor = parent; // assignment not strictly necessary, but useful for templating.
			    while (graph1parents != outerGraphs[graph1It->first].end() && 
				   graph2parents != outerGraphs[graph2It->first].end() && 
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
			    if (graph1parents != outerGraphs[graph1It->first].end() && *graph1parents != graph2It->first &&
				graph2parents != outerGraphs[graph2It->first].end() && *graph2parents != graph1It->first &&
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
			consequents[p->first][p->second] = _Binding_COREF;
		}
	    }

	};

    protected:
	ConsequentMapList consequents;
	std::set<POS*> gendVars; // @@@ could be a re-use map outside
	Bindable* _genVar (const Bindable* base, int index, Result* row, POSFactory* posFactory) {
	    Bindable* ret = NULL;
	    do {
		std::stringstream name;
		name << base->getTerminal() << "_gen" << index;
		ret = posFactory->getVariable(name.str().c_str());
		++index;
	    } while (row->get(ret) != NULL || gendVars.find(ret) != gendVars.end());
	    gendVars.insert(ret);
	    return ret;
	}

    public:
	Consequents (const TableOperation* op, VarSet* p_VarSet = NULL, std::ostream** debugStream = NULL) {
	    START("POS2BGPMap Consequents constructor");
	    ConsequentsConstructor ctor(&consequents, op);
	    NOW("traversing TableOperation");
	    op->express(&ctor);
	    NOW("storing select vars");
	    if (p_VarSet != NULL) p_VarSet->express(&ctor);
	    NOW("finding corefs");
	    ctor.findCorefs(op);
	    if (*debugStream != NULL) {
		**debugStream << "Consequents:" << std::endl << consequents.dump();
		**debugStream << "OuterGraphs:" << std::endl << ctor.dumpOuterGraphs();
	    }
	}
	~Consequents () {
	    for (ConsequentMapList::iterator maps = consequents.begin();
		 maps != consequents.end(); ++maps) {
		maps->second.clear();
	    }
	    consequents.clear();
	}

	ConsequentMap getIncludeRequiredness (ResultSet* rs, ResultSetIterator row, POSFactory* posFactory) {
	    ConsequentMap ret;
	    std::set<const Bindable*> neededVars;

	    int genNo = 0;
	    /* 06 — Scan each basic graph pattern GA in the antecedent graph pattern A for variables in triple patterns:
	     * http://www.w3.org/2008/07/MappingRules/#_06
	     */
	    for (ConsequentMapList::iterator maps = consequents.begin();
		 maps != consequents.end(); ++maps) {
		const Bindable* v = dynamic_cast<const Bindable*>(maps->first);
		if (v == NULL)
		    break;
		//cerr << "considering includedness of " << v->toString() << endl;
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
			if (bgpBindings->second & _Binding_WEAK) {
			    /* It's optional, so omit it. !!
			       This is acutally unsound as we
			       want to include any OPT which
			       introduces constraints used by
			       an OPT included later.
			    */
#ifndef WIN32
#warning not including dependent optionals yet
#endif
			    continue;
			}
		    }
		    /* References to this variable mean we need this graph pattern.
		     * It is only weak if there were no bindings for this variable.
		     @@ that's wierd. figure it out. */
		    const TableOperation* op = bgpBindings->first;
		    ret[op] = (_BindingStrength)(bgpBindings->second & ~_Binding_WEAK);
		    if ((*row)->get(v) == false)
			ret[op] = (_BindingStrength)(ret[op] | _Binding_WEAK);
		    //cerr << "includedRequiredness[" << op << " = " << ConsequentMapList::bindingStr(ret[op]) << " for " << v->toString() << endl;
		}
		    
	    }

	    for (std::set<const Bindable*>::iterator v = neededVars.begin();
		 v != neededVars.end(); ++v)
		rs->set(*row, *v, _genVar(*v, genNo++, *row, posFactory), true);
	    neededVars.clear();
	    return ret;
	}

	/* Collect all the POS entries referenced in a particular TableOperation
	 * so that SQL subqueries know which variables to propagate up in the
	 * select.
	 */
	std::vector<const POS*> entriesFor (const TableOperation* op) {
	    std::vector<const POS*> ret;
	    for (ConsequentMapList::iterator varIt = consequents.begin();
		 varIt != consequents.end(); ++varIt)
		if (varIt->second.find(op) != varIt->second.end())
		    ret.push_back(varIt->first);
	    return ret;
	}
    };
}

