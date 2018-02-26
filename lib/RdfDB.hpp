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
	virtual std::string toString (MediaType /* mediaType */ = MediaType()) const { return "Default Graph"; }
	virtual std::string getBindingAttributeName () const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual void express (Expressor*) const { throw(std::runtime_error(FUNCTION_STRING)); };
    };
    extern TTerm* DefaultGraph;

    class RdfDB {
	struct graphmap_type : public std::map<const TTerm*, BasicGraphPattern*> {
	    graphmap_type ()
		: std::map<const TTerm*, BasicGraphPattern*>()
	    {  }
	    graphmap_type (const graphmap_type& ref)
		: std::map<const TTerm*, BasicGraphPattern*>()
	    {
		for (const_iterator it = ref.begin(); it != ref.end(); ++it)
		    if (it->first == DefaultGraph)
			insert(std::make_pair(it->first, new DefaultGraphPattern(*(DefaultGraphPattern*)it->second)));
		    else
			insert(std::make_pair(it->first, new NamedGraphPattern(*(NamedGraphPattern*)it->second)));
	    }
	};
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
	static bool GetGraphArguments;
	static bool DynamicLoading;
        static bool NotFoundIsEmpty;

	/** RdfDB: simple constructor with no GET or parsing facilities.
	 */
	RdfDB ()
	    : graphs(), webAgent(NULL), xmlParser(NULL), handler(&defaultHandler)
	{ ensureGraph(DefaultGraph); }

	/** RdfDB: constructor with GET and parsing facilities.
	 */
	RdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser = NULL, HandlerSet* handler = &defaultHandler)
	    : graphs() , webAgent(webAgent), xmlParser(xmlParser), handler(handler)
	{ ensureGraph(DefaultGraph); }

	/** RdfDB: copy constructor.
	 */
	RdfDB (const RdfDB& ref)
	    : graphs(ref.graphs), webAgent(ref.webAgent), xmlParser(ref.xmlParser)
	{  }

	/** RdfDB: copy things like parsers and handlers from an
	 * existing RdfDB, but don't copy the data.
	 */
	RdfDB (const RdfDB& ref, bool) // don't copy data
	    : webAgent(ref.webAgent), xmlParser(ref.xmlParser)
	{  }

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
		if (it->first != DefaultGraph)
		    names.insert(it->first);
	    return names;
		    
	}
	const BasicGraphPattern* getGraph (const TTerm* name) {
	    if (name == NULL)
		name = DefaultGraph;
	    graphmap_type::const_iterator vi = graphs.find(name);
	    return vi == graphs.end() ? NULL : vi->second;
	}
	virtual BasicGraphPattern* findGraph(const TTerm* name) const;
	virtual BasicGraphPattern* ensureGraph(const TTerm* name);
	void ensureGraphs (std::set<const TTerm*> names) {
	    for (std::set<const TTerm*>::const_iterator it = names.begin(); it != names.end(); ++it)
		ensureGraph(*it);
	}
	bool eraseGraph (const TTerm* name) {
	    if (name == NULL || name == DefaultGraph) {
		findGraph(DefaultGraph)->clearTriples();
		return true;
	    } else {
		BasicGraphPattern* eraseMe = findGraph(name);
		if (!eraseMe)
		    return false;
		// delete eraseMe;
		graphs.erase(name);
		return true;
	    }
	}
	bool moveGraph(const TTerm* from, const TTerm* to);

	/** assignDefaultGraph - use @from as the default graph.
	 * @param from: to new graph to serve as the default graph.
	 * @return the last default graph.
	 */
	BasicGraphPattern* assignDefaultGraph(BasicGraphPattern* from);
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
	bool onto(const RdfDB& ref) const;
	bool operator== (const RdfDB& ref) const {
	    return onto(ref) && ref.onto(*this);
	}
	virtual void bindVariables(ResultSet* rs, const RdfDB* ref) const;
	void clearTriples();
        std::map<std::string, time_t> cacheExpiry;
	virtual bool loadData(BasicGraphPattern* target, IStreamContext& istrP,
			      std::string nameStr, std::string baseURI,
			      AtomFactory* atomFactory, NamespaceMap* nsMap = NULL, GRDDLmap* grddlMap = NULL);
	virtual void bindVariables(ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch) const;
	void express(Expressor* expressor) const;

	/**
	 * If the mediaType doesn't match some named graphs type ("text/trig"),
	 * all triples are stuffed into the default graph. (Is this the right
	 * behavior?)
	 */
	std::string toString (MediaType mediaType = MediaType("text/trig"), NamespaceMap* namespaces = NULL) const {
	    /* simple unordered serializer -
	       SPARQLSerializer s;
	       express(&s);
	       return s.str(); */
	    if (!mediaType) // !!! not handled by parameter default?
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
	    for (std::list<const TTerm*>::const_iterator it = graphList.begin(); it != graphList.end(); ++it) {
		if (*it != DefaultGraph)
		    s << (*it)->toString();
		s << graphs.find(*it)->second->toString(mediaType, namespaces);
	    }
	    return s.str();
	}
	std::string str() const; // for simple invocation.
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

	virtual void bindVariables (ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch) const {
	    if (graph == NULL) graph = defaultTarget;
	    return RdfDB::bindVariables(rs, graph, toMatch);
	}
    };

} // namespace w3c_sw

#endif // !RDF_DB_H

