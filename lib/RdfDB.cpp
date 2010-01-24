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

    bool RdfDB::loadData (BasicGraphPattern* target, IStreamContext& istr, std::string nameStr, std::string baseURI, POSFactory* posFactory, NamespaceMap* nsMap) {
	if (istr.mediaType.match("text/html") || 
	    istr.mediaType.match("application/xhtml")) {
	    if (xmlParser == NULL)
		throw std::string("no XML parser to parse ")
		    + istr.mediaType.toString()
		    + " document " + nameStr;
	    RDFaParser parser(posFactory, xmlParser);
	    if (baseURI != "")
		parser.setBase(baseURI);
	    if (nsMap != NULL)
		parser.setNamespaceMap(nsMap);
	    return parser.parse(target, istr);
	} else if (istr.mediaType.match("text/rdf") || 
		   istr.mediaType.match("application/rdf+xml")) {
	    if (xmlParser == NULL)
		throw std::string("no XML parser to parse ")
		    + istr.mediaType.toString()
		    + " document " + nameStr;
	    RdfXmlParser parser(posFactory, xmlParser);
	    if (baseURI != "")
		parser.setBase(baseURI);
	    if (nsMap != NULL)
		parser.setNamespaceMap(nsMap);
	    return parser.parse(assureGraph(NULL), istr);
	} else if (istr.mediaType.match("text/turtle") || 
		   istr.mediaType.match("text/ntriples")) {
	    TurtleSDriver parser(nameStr, posFactory);
	    parser.setGraph(target);
	    if (baseURI != "")
		parser.setBase(baseURI);
	    if (nsMap != NULL)
		parser.setNamespaceMap(nsMap);
	    return parser.parse(istr);
	} else {
	    TrigSDriver parser(nameStr, posFactory);
	    parser.setDB(this);
	    if (baseURI != "")
		parser.setBase(baseURI);
	    if (nsMap != NULL)
		parser.setNamespaceMap(nsMap);
	    return parser.parse(istr);
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

