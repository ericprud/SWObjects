/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "RdfDB.hpp"
#include "ResultSet.hpp"

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

    BasicGraphPattern* RdfDB::assureGraph (const POS* name) {
	if (name == NULL)
	    name = DefaultGraph;
	graphmap_type::const_iterator vi = graphs.find(name);
	if (vi == graphs.end()) {
	    BasicGraphPattern* ret;
	    if (name == DefaultGraph)
		ret = new DefaultGraphPattern();
	    else
		ret = new NamedGraphPattern(name);
	    graphs[name] = ret;
	    return ret;
	} else {
	    return vi->second;
	}
    }

    DefaultGraphClass defaultGraphInst;
    POS* DefaultGraph = &defaultGraphInst;

    void RdfDB::bindVariables (ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch) {
	if (graph == NULL) graph = DefaultGraph;
	graphmap_type::const_iterator vi;
	size_t matched = 0;

	/* Look in each candidate graph. */
	if (graph->isConstant()) {
	    if ((vi = graphs.find(graph)) != graphs.end()) {
		vi->second->bindVariables(rs, graph, toMatch, vi->first);
		++matched;
	    }
	} else {
	    for (vi = graphs.begin(); vi != graphs.end(); vi++)
		if (vi->first != DefaultGraph) {
		    vi->second->bindVariables(rs, graph, toMatch, vi->first);
		    ++matched;
		}
	}
	if (matched == 0)
	    for (ResultSetIterator it = rs->begin(); it != rs->end(); )
		rs->erase(it++);
    }

    void RdfDB::express (Expressor* expressor) const {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->express(expressor);
    }

} // namespace w3c_sw

