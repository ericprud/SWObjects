/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "TrigSParser/TrigSParser.hpp"

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

    bool RdfDB::loadData (BasicGraphPattern* target, IStreamPtr* istr, std::string nameStr, POSFactory* posFactory) {
	if (!istr->mediaType.compare(0, 9, "text/html") || 
	    !istr->mediaType.compare(0, 9, "application/xhtml")) {
	    if (xmlParser == NULL)
		throw std::string("no XML parser to parse ") + istr->mediaType + 
		    " document " + nameStr;
	    RDFaParser rdfaParser(posFactory, xmlParser);
	    rdfaParser.parse(target, istr, nameStr);
	    return false;
	} else if (!istr->mediaType.compare(0, 8, "text/rdf") || 
		   !istr->mediaType.compare(0, 12, "text/rdf+xml")) {
	    if (xmlParser == NULL)
		throw std::string("no XML parser to parse ") + istr->mediaType + 
		    " document " + nameStr;
	    RdfXmlParser p(posFactory, xmlParser);
	    p.parse(assureGraph(NULL), istr);
	    return false;
	} else if (!istr->mediaType.compare(0, 11, "text/turtle")) {
	    TurtleSDriver turtleParser(nameStr, posFactory);
	    turtleParser.setGraph(target);
	    return turtleParser.parse_stream(istr);
	} else {
	    TrigSDriver trigParser(nameStr, posFactory);
	    trigParser.setDB(this);
	    return trigParser.parse_stream(istr);
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
	    ResultSet island(rs->getPOSFactory());
	    delete *(island.begin());
	    island.erase(island.begin());
	    for (vi = graphs.begin(); vi != graphs.end(); vi++)
		if (vi->first != DefaultGraph) {
		    ResultSet disjoint(rs->getPOSFactory());
		    vi->second->bindVariables(&disjoint, graph, toMatch, vi->first);
		    for (ResultSetIterator row = disjoint.begin() ; row != disjoint.end(); ) {
			island.insert(island.end(), (*row)->duplicate(&island, island.end()));
			delete *row;
			row = disjoint.erase(row);
		    }
		    ++matched;
		}
	    rs->joinIn(&island, false);
	}
	if (matched == 0)
	    for (ResultSetIterator it = rs->begin(); it != rs->end(); ) {
		delete *it;
		it = rs->erase(it);
	    }
    }

    void RdfDB::express (Expressor* expressor) const {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->express(expressor);
    }

} // namespace w3c_sw

