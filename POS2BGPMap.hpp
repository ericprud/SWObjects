/* POS2BGPMap.hpp - association variables with the BGPs in which they appear.
 *
 * $Id: POS2BGPMap.hpp,v 1.1 2008-08-31 22:37:11 eric Exp $
 */

#pragma once

#include "SWObjects.hpp"
#include "exs.hpp"
#include <set>
#include <vector>

namespace w3c_sw {

    typedef enum {Binding_STRONG = 1, Binding_WEAK = 0, Binding_COREF = 5} BindingStrength;
    typedef std::map<BasicGraphPattern*, BindingStrength> ConsequentMap;
    typedef std::map<BasicGraphPattern*, BindingStrength>::iterator ConsequentMapIterator;
    typedef std::map<POS*, ConsequentMap> ConsequentMapList;
    typedef std::map<POS*, ConsequentMap>::iterator ConsequentMapListIterator;

    class Consequents {

	class ConsequentsConstructor : public RecursiveExpressor {
	protected:
	    ConsequentMapList& consequents;  // hate refs, but like the [foo][bar] syntax
	    BindingStrength optState;
	    POS* graphName;
	    std::vector<TableOperation*> bgpStack;
	    void _depends (POS* pos, BindingStrength strength) {
		BasicGraphPattern* bgp = dynamic_cast<BasicGraphPattern*>(bgpStack.back());
		assert(bgp != NULL);
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
				if (bgps->second == Binding_WEAK) // I don't know a safer way to erase cur element.
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
		consequents(*consequents), optState(Binding_STRONG), graphName(NULL), bgpStack() {
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

	    void _each (ProductionVector<TableOperation*>* p_TableOperations) {
		for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		     it != p_TableOperations->end(); it++) {
		    bgpStack.push_back(*it);
		    (*it)->express(this);
		    bgpStack.pop_back();
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
		optState = oldOptState;
		return NULL;
	    }

	    virtual GraphGraphPattern* graphGraphPattern (w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
		POS* oldGraphName = graphName;
		graphName = p_POS;
		bgpStack.push_back(p_GroupGraphPattern);
		p_GroupGraphPattern->express(this);
		bgpStack.pop_back();
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
}

