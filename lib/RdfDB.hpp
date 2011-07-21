/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_DB_H
#define RDF_DB_H

#include <fstream>
#include "SWObjects.hpp"
#include "../interface/WEBagent.hpp"
#include "../interface/SAXparser.hpp"
#include "RdfXmlParser.hpp"
#include "RDFaParser.hpp"

namespace w3c_sw {
#if 0
    class Triple {
    protected:
	TTerm* subject;
	TTerm* predicate;
	TTerm* object;
    public:
	Triple (TTerm* s, TTerm* p, TTerm* o) : subject(s), predicate(p), object(o) {  }
    };
    //class cls { protected: char* name; std::vector<char*> names; cls () : names(), name() {  } };
    class Graph {
    protected:
	TTerm* name;
	std::vector<TriplePattern*> triples;
    public:
	Graph (TTerm* p_name) : name(p_name), triples() {  }
    };
#endif

    class DefaultGraphClass : public TTerm {
    protected:
	virtual e_TYPE getTypeOrder () { return TYPE_Err; }
    public:
	DefaultGraphClass () : TTerm("::DefaultGraphClass::") {  }
	virtual e_TYPE getTypeOrder () const { return TYPE_Err; }
	virtual std::string toXMLResults (TTerm::BNode2string*) const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual std::string toString () const { return "Default Graph"; }
	virtual std::string getBindingAttributeName () const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual void express (Expressor*) const { throw(std::runtime_error(FUNCTION_STRING)); };
    };
    extern TTerm* DefaultGraph;

    class RdfDB {
	typedef std::map<const TTerm*, BasicGraphPattern*> graphmap_type;
    protected:
	graphmap_type graphs;

    public:
	struct HandlerSet {
	    virtual ~HandlerSet () {  }
	    virtual bool parse (std::string mediaType, std::vector<std::string> args,
				BasicGraphPattern* /* target */, IStreamContext& /* istr */,
				std::string /* nameStr */, std::string /* baseURI */,
				AtomFactory* /* atomFactory */, NamespaceMap* /* nsMap */) {
		throw std::string("no handler for ") + mediaType + "(" + args[0] + ")";
	    }
	};

	SWWEBagent* webAgent;
	SWSAXparser* xmlParser;
	HandlerSet* handler;
	static HandlerSet defaultHandler;
	static size_t DebugEnumerateLimit;

	RdfDB (SWSAXparser* xmlParser = NULL)
	    : graphs(), webAgent(NULL), xmlParser(xmlParser), handler(&defaultHandler)
	{ ensureGraph(DefaultGraph); }
	RdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser = NULL)
	    : graphs() , webAgent(webAgent), xmlParser(xmlParser), handler(&defaultHandler)
	{ ensureGraph(DefaultGraph); }
	RdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser, HandlerSet* handler)
	    : graphs() , webAgent(webAgent), xmlParser(xmlParser), handler(handler)
	{ ensureGraph(DefaultGraph); }
	RdfDB (RdfDB const &)
	    : graphs()
	{ throw(std::runtime_error(FUNCTION_STRING)); ensureGraph(DefaultGraph); }
	RdfDB (const DefaultGraphPattern* graph) : graphs(), handler(&defaultHandler) {
	    BasicGraphPattern* bgp = ensureGraph(DefaultGraph);
	    for (std::vector<const TriplePattern*>::const_iterator it = graph->begin();
		 it != graph->end(); it++)
		bgp->addTriplePattern(*it);
	}
	virtual ~RdfDB();
	size_t size () const {
	    size_t ret = 0;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		ret += it->second->size();
	    return ret;
	}
	std::set<const TTerm*> getGraphNames () const {
	    std::set<const TTerm*> names;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		names.insert(it->first);
	    return names;
		    
	}
	const BasicGraphPattern* getGraph (const TTerm* name) {
	    graphmap_type::const_iterator vi = graphs.find(name);
	    return vi == graphs.end() ? NULL : vi->second;
	}
	virtual BasicGraphPattern* findGraph(const TTerm* name);
	virtual BasicGraphPattern* ensureGraph(const TTerm* name);
	void ensureGraphs(std::set<const TTerm*> names) {
	    for (std::set<const TTerm*>::const_iterator it = names.begin(); it != names.end(); ++it)
		ensureGraph(*it);
	}
	virtual bool isDefaultGraph (const TTerm* t) const {
	    return t == DefaultGraph;
	}

	RdfDB& operator= (const RdfDB &ref) {
	    for (graphmap_type::const_iterator it = graphs.begin(); // @@@ same as ~RdfDB()
		 it != graphs.end(); it++)
		delete it->second;
	    graphs.clear();

	    for (graphmap_type::const_iterator it = ref.graphs.begin(); it != ref.graphs.end(); ++it) {
		BasicGraphPattern* to = ensureGraph(it->first);
		const BasicGraphPattern* from = it->second;
		for (std::vector<const TriplePattern*>::const_iterator it = from->begin(); 
		     it != from->end(); ++it)
		    to->addTriplePattern(*it);
	    }	

	    webAgent = ref.webAgent;
	    xmlParser = ref.xmlParser;

	    return *this;
	}
	bool operator== (const RdfDB& ref) const {
	    std::set<const TTerm*> thisGraphs;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		// if (it->second->size() > 0)
		    thisGraphs.insert(it->first);

	    std::set<const TTerm*> refGraphs;
	    for (graphmap_type::const_iterator it = ref.graphs.begin(); it != ref.graphs.end(); ++it)
		// if (it->second->size() > 0)
		    refGraphs.insert(it->first);

	    if (thisGraphs != refGraphs)
		return false;

	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it) {
		// compare BasicGraphPatterns *it->second and *ref.graphs.find(it->first)->second;
		const TTerm* label = it->first;
		BasicGraphPattern* l = it->second;
		graphmap_type::const_iterator rit = ref.graphs.find(label);
		if (rit == ref.graphs.end())
		    return false;
		BasicGraphPattern* r = rit->second;
		if (! (*l == *r) )
		    return false;
	    }

	    return true;
	}
	void clearTriples();
	virtual bool loadData(BasicGraphPattern* target, IStreamContext& istrP,
			      std::string nameStr, std::string baseURI,
			      AtomFactory* atomFactory, NamespaceMap* nsMap = NULL, GRDDLmap* grddlMap = NULL);
	virtual void bindVariables(ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch);
	void express(Expressor* expressor) const;
	std::string toString (MediaType mediaType = MediaType("text/trig"), NamespaceMap* namespaces = NULL) const {
	    /* simple unordered serializer -
	       SPARQLSerializer s;
	       express(&s);
	       return s.str(); */
	    if (!mediaType)
		mediaType = "text/trig";

	    /* ordered serializer */
	    std::list<const TTerm*> graphList;
	    if (mediaType.match("text/turtle") || 
		mediaType.match("text/ntriples") || 
		mediaType.match("application/rdf+xml"))
		graphList.push_back(DefaultGraph);
	    else
		for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		    // if (it->second->size() > 0)
		    graphList.push_back(it->first);
	    graphList.sort(TTermSorter());
	    std::stringstream s;
	    for (std::list<const TTerm*>::const_iterator it = graphList.begin(); it != graphList.end(); ++it) 
		s << graphs.find(*it)->second->toString(mediaType, namespaces);
	    return s.str();
	}

    };

    inline std::ostream& operator<< (std::ostream& os, RdfDB const& my) {
	return os << my.toString();
    }

    /** TargetedRdfDB - an RdfDB which overrides the default graph with a named
     * target graph.
     * defaultTarget: the name of the graph to use in lieu of the default graph.
     */
    class TargetedRdfDB : public RdfDB {
    protected:
	const TTerm* defaultTarget;

    public:
	TargetedRdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser, HandlerSet* handler)
	    : RdfDB(webAgent, xmlParser, handler), defaultTarget(NULL)
	{  }
	void setTarget (const TTerm* target) { defaultTarget = target; }

	virtual BasicGraphPattern* ensureGraph (const TTerm* name) {
	    if (name == NULL)
		name = DefaultGraph;
	    if (name == DefaultGraph && defaultTarget != NULL)
		name = defaultTarget;
	    return RdfDB::ensureGraph(name);
	}

	virtual bool isDefaultGraph (const TTerm* t) const {
	    return t == DefaultGraph || t == defaultTarget;
	}

	virtual void bindVariables (ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch) {
	    if (graph == NULL) graph = defaultTarget;
	    return RdfDB::bindVariables(rs, graph, toMatch);
	}
    };

} // namespace w3c_sw

#endif // !RDF_DB_H

