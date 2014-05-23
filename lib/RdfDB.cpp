/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "TurtleParser.hpp"
#include "TrigParser.hpp"
#include "RdfXmlParser.hpp"
#include <boost/iostreams/stream.hpp>

namespace w3c_sw {

    size_t RdfDB::DebugEnumerateLimit = 50;
    bool RdfDB::GetGraphArguments = false;
    bool RdfDB::DynamicLoading = true;

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

    bool RdfDB::moveGraph (const TTerm* from, const TTerm* to) {
	const BasicGraphPattern* source = getGraph(from);
	BasicGraphPattern* target = ensureGraph(to);
	for (std::vector<const TriplePattern*>::const_iterator it = source->begin(); it != source->end(); ++it)
	    target->addTriplePattern(*it);
	//	graphs[to] = graphs[from];
	// graphs.erase(from);
	eraseGraph(from);
	return true;
    }

    BasicGraphPattern* RdfDB::assignDefaultGraph (BasicGraphPattern* from) {
	//std::map<const TTerm*, BasicGraphPattern*>::iterator f = graphs.find(DefaultGraph);
	BasicGraphPattern* ret = graphs[DefaultGraph];
	graphs[DefaultGraph] = from;
	return ret;
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
	    } else if (istr.mediaType.match("text/plain") ||
		       istr.mediaType.match("text/turtle") || 
		       istr.mediaType.match("text/ntriples")) {
		TurtleDriver parser(nameStr, atomFactory);
		if (baseURI != "")
		    parser.setBase(baseURI);
		if (nsMap != NULL)
		    parser.setNamespaceMap(nsMap);
		parser.parse(istr, target);
		return false;
	    } else {
		TrigDriver parser(nameStr, atomFactory);
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

	/* Look in each candidate graph. */
	if (graph->isConstant()) {
	    const BasicGraphPattern* found = findGraph(graph);
	    if (found != NULL)
		found->bindVariables(rs, toMatch, graph, graph);
	} else {

	    /* Variable graph name so we have to look in row to see whether the graph variable is bound.
	     * Fortunately, the JoinCache keeps us from executing identical matches on duplicate rows.
	     */
	    JoinCache jc;
	    for (ResultSetIterator outerRow = rs->begin() ; outerRow != rs->end(); ) {
		ResultSet* nested = jc.find(*outerRow);
		if (nested == NULL) {

		    /* *outerRow doesn't show up in the cache.
		     */
		    nested = (*outerRow)->makeResultSet(rs->getAtomFactory());
		    jc.add(*outerRow, nested);
		    const TTerm* graphName = (*outerRow)->get(graph);
		    if (graphName != NULL) {

			/* This result has a binding to the graph name we're matching against.
			 */
			BasicGraphPattern* found = findGraph(graphName);
			if (found == NULL && GetGraphArguments == true) {
			    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << "Loading graph " << graphName->toString() << std::endl;
			    IStreamContext istr(graphName->getLexicalValue(), IStreamContext::FILE, NULL, NULL); // @@ no web
			    found = const_cast<RdfDB*>(this)->ensureGraph(graphName); // !! const cheat
			    const_cast<RdfDB*>(this)->loadData(found, istr, graphName->getLexicalValue(), 
							       graphName->getLexicalValue(), rs->getAtomFactory());
			}
			if (found != NULL)
			    found->bindVariables(nested, toMatch, graphName, graphName);
		    } else {

			/* The graph name is still unbound so we have to iterate across all graphs.
			 * The lack of SPOG index means we have to try this Multi-graph match algorithm:
			 * for each graph
			 *     BasicGraphPattern::bindVariables(... ?graph, foundGraph)
			 *         for each rs row...all graphs.
			 */
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
			    }
			nested->joinIn(&island);
		    }
		}

		/* Copy the nested results into rs and clean up.
		 */
		const VariableList* innerVars = nested->getKnownVars();
		for (VariableList::const_iterator v = innerVars->begin(); v != innerVars->end(); ++v)
		    rs->addKnownVar(*v);
		for (ResultSetIterator innerRow = nested->begin();
		     innerRow != nested->end(); ++innerRow)
		    rs->insert(outerRow, (*innerRow)->duplicate(rs, outerRow));
		delete *outerRow;
		outerRow = rs->erase(outerRow);
	    }
	}
    }

    void RdfDB::express (Expressor* expressor) const {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->express(expressor);
    }

} // namespace w3c_sw

