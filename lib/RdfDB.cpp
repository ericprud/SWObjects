/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "TrigSParser/TrigSParser.hpp"
#include "RdfXmlParser.hpp"
#include <boost/iostreams/stream.hpp>

namespace w3c_sw {

    size_t RdfDB::DebugEnumerateLimit = 50;

    RdfDB::HandlerSet RdfDB::defaultHandler;

    RdfDB::~RdfDB () {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    delete it->second;
    }

    std::string RdfDB::str () const { return toString(); } // for simple invocation.

    void RdfDB::clearTriples () {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->clearTriples();
    }


    BasicGraphPattern* RdfDB::findGraph (const TTerm* name) const {
	if (name == NULL)
	    name = DefaultGraph;
	graphmap_type::const_iterator vi = graphs.find(name);
	return vi == graphs.end() ? NULL : vi->second;
    }

    BasicGraphPattern* RdfDB::ensureGraph (const TTerm* name) {
	if (name == NULL)
	    name = DefaultGraph;
	BasicGraphPattern* ret = findGraph(name);
	if (ret == NULL) {
	    if (name == DefaultGraph)
		ret = new DefaultGraphPattern();
	    else
		ret = new NamedGraphPattern(name);
	    graphs[name] = ret;
	    return ret;
	} else {
	    return ret;
	}
    }


    bool RdfDB::loadData (BasicGraphPattern* target, IStreamContext& istrP,
			  std::string nameStr, std::string baseURI,
			  AtomFactory* atomFactory, NamespaceMap* nsMap, GRDDLmap* grddlMap) {
	w3c_sw::StreamRewinder rb(*istrP);
	boost::iostreams::stream_buffer<w3c_sw::StreamRewinder::Device> srsb(rb.device); // ## debug with small buffer size, e.g. 4
	std::istream is(&srsb);
	IStreamContext istr(istrP.nameStr, is, 
			    istrP.mediaType.is_initialized() ? istrP.mediaType.get().c_str() : NULL);
	try {
	    if (istr.mediaType.match("text/html") || 
		istr.mediaType.match("application/xhtml") || 
		istr.mediaType.match("application/xml")) {
		if (xmlParser == NULL)
		    throw std::string("no XML parser to parse ")
			+ istr.mediaType.toString()
			+ " document " + nameStr;
		RDFaParser parser(nameStr, atomFactory, xmlParser, grddlMap);
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
		RdfXmlParser parser(nameStr, atomFactory, xmlParser);
		if (baseURI != "")
		    parser.setBase(baseURI);
		if (nsMap != NULL)
		    parser.setNamespaceMap(nsMap);
		return parser.parse(target, istr);
	    } else if (istr.mediaType.match("text/turtle") || 
		       istr.mediaType.match("text/ntriples")) {
		TurtleSDriver parser(nameStr, atomFactory);
		if (baseURI != "")
		    parser.setBase(baseURI);
		if (nsMap != NULL)
		    parser.setNamespaceMap(nsMap);
		parser.parse(istr, target);
		return false;
	    } else {
		TrigSDriver parser(nameStr, atomFactory);
		if (baseURI != "")
		    parser.setBase(baseURI);
		if (nsMap != NULL)
		    parser.setNamespaceMap(nsMap);
		parser.parse(istr, this, target);
		return false;
	    }
	} catch (ChangeMediaTypeException& e) {
	    if (Logger::Logging(Logger::ProcessLog_level, Logger::engineer)) {
		std::stringstream o;
		o << "Changing media type to " << e.mediaType << " with " << e.args.size() << " args:" ;
		for (std::vector<std::string>::const_iterator it = e.args.begin();
		     it != e.args.end(); ++it)
		    o << " " << *it;
		BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::engineer) << o.str();
	    }
	    rb.replay();
	    boost::iostreams::stream_buffer<StreamRewinder::Device> sb2(rb.device);
	    std::istream is2(&sb2);
	    IStreamContext again(istrP.nameStr, is, e.mediaType.c_str());
	    return handler->parse(e.mediaType, e.args, target, again, nameStr, baseURI, atomFactory, nsMap);
	}
    }

    DefaultGraphClass defaultGraphInst;
    TTerm* DefaultGraph = &defaultGraphInst;

    void RdfDB::bindVariables (ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch) const {
	if (graph == NULL) graph = DefaultGraph;
	size_t matched = 0;

	/* Look in each candidate graph. */
	if (graph->isConstant()) {
	    const BasicGraphPattern* found = findGraph(graph);
	    if (found != NULL) {
		found->bindVariables(rs, toMatch, graph, graph);
		++matched;
	    }
	} else {
	    /* Multi-graph match algorithm:
	     * for each graph
	     *     BasicGraphPattern::bindVariables(... ?graph, foundGraph)
	     *         for each rs row...
	     * 
	     * The lack of SPOG index means we always iterate across all graphs.
	     * It could be cheaper to iterate across rows in the result set and
	     * only iterate across graphs if ?graph is unbound. Could decide by:
	     *   rs->first()->get(?graph) == TTerm::Unbound
	     */
	    for (ResultSetIterator outerRow = rs->begin() ; outerRow != rs->end(); ) {
		ResultSet* single = (*outerRow)->makeResultSet(rs->getAtomFactory());
		const TTerm* graphName = (*outerRow)->get(graph);
		if (graphName != NULL) {
		    BasicGraphPattern* found = findGraph(graphName);
		    if (found == NULL) {
			w3c_sw_LINEN << "loading " << graphName->toString() << "\n";
			IStreamContext istr(graphName->getLexicalValue(), IStreamContext::FILE, NULL, NULL); // @@ no web
			found = const_cast<RdfDB*>(this)->ensureGraph(graphName); // !! const cheat
			const_cast<RdfDB*>(this)->loadData(found, istr, graphName->getLexicalValue(), 
							   graphName->getLexicalValue(), rs->getAtomFactory());
		    }
		    if (found != NULL) {
			found->bindVariables(single, toMatch, graphName, graphName);
			++matched;
		    }
		} else {
		    ResultSet island(rs->getAtomFactory());
		    delete *(island.begin());
		    island.erase(island.begin());
		    for (graphmap_type::const_iterator vi = graphs.begin(); vi != graphs.end(); vi++)
			if (!isDefaultGraph(vi->first)) {
			    ResultSet disjoint(rs->getAtomFactory());
			    vi->second->bindVariables(&disjoint, toMatch, graph, vi->first);
			    for (ResultSetIterator row = disjoint.begin() ; row != disjoint.end(); ) {
				island.insert(island.end(), (*row)->duplicate(&island, island.end()));
				delete *row;
				row = disjoint.erase(row);
			    }
			    ++matched;
			}
		    single->joinIn(&island);
		}
		const VariableList* innerVars = single->getKnownVars();
		for (VariableList::const_iterator v = innerVars->begin(); v != innerVars->end(); ++v)
		    rs->addKnownVar(*v);
		for (ResultSetIterator innerRow = single->begin() ; innerRow != single->end(); ) {
		    rs->insert(outerRow, *innerRow);
		    innerRow = single->erase(innerRow);
		}
		delete single;
		delete *outerRow;
		outerRow = rs->erase(outerRow);
	    }
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

