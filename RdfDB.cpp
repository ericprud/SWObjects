/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2.6.1 2008-12-05 00:39:22 eric Exp $
 */

#include "RdfDB.hpp"

namespace w3c_sw {

    RdfDB::~RdfDB () {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    delete it->second;
    }

    void RdfDB::clearTriples () {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->clearTriples();
    }

    BasicGraphPattern* RdfDB::assureGraph (POS* name, BasicGraphPattern::MatchSemantics matchSemantics) {
	graphmap_type::const_iterator vi = graphs.find(name);
	if (vi == graphs.end()) {
	    BasicGraphPattern* ret;
	    if (name == NULL || name == DefaultGraph)
		ret = new DefaultGraphPattern(matchSemantics);
	    else
		ret = new NamedGraphPattern(name, matchSemantics);
	    graphs[name] = ret;
	    return ret;
	} else if (vi->second->getMatchSemantics() != matchSemantics) {
	    throw(std::runtime_error("RdfDB::assureGraph returning graph with different match semantics than requested."));
	} else {
	    return vi->second;
	}
    }

    DefaultGraphClass defaultGraphInst;
    POS* DefaultGraph = &defaultGraphInst;

    void RdfDB::bindVariables (ResultSet* rs, POS* graph, BasicGraphPattern* toMatch) {
	graphmap_type::const_iterator vi;
	if (graph == NULL) graph = DefaultGraph;

	/* Look in each candidate graph. */
	if (graph->isConstant()) {
	    if ((vi = graphs.find(graph)) != graphs.end())
		vi->second->bindVariables(rs, graph, toMatch, vi->first);
	} else {
	    for (vi = graphs.begin(); vi != graphs.end(); vi++)
		if (vi->first != DefaultGraph)
		    vi->second->bindVariables(rs, graph, toMatch, vi->first);
	}
    }

    void RdfDB::express (Expressor* expressor) {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->express(expressor);
    }

} // namespace w3c_sw

