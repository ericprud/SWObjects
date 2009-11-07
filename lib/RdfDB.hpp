/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_DB_H
#define RDF_DB_H

#include <fstream>
#include "SWObjects.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "SPARQLSerializer.hpp"
#include "../interface/WEBagent.hpp"
#include "../interface/SAXparser.hpp"
#include "RdfXmlParser.hpp"
#include "RDFaParser.hpp"

namespace w3c_sw {
#if 0
    class Triple {
    protected:
	POS* subject;
	POS* predicate;
	POS* object;
    public:
	Triple (POS* s, POS* p, POS* o) : subject(s), predicate(p), object(o) {  }
    };
    //class cls { protected: char* name; std::vector<char*> names; cls () : names(), name() {  } };
    class Graph {
    protected:
	POS* name;
	std::vector<TriplePattern*> triples;
    public:
	Graph (POS* p_name) : name(p_name), triples() {  }
    };
#endif

    class DefaultGraphClass : public POS {
    public:
	DefaultGraphClass () : POS("::DefaultGraphClass::") {  }
	virtual std::string toXMLResults (POS::BNode2string*) const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual std::string toString () const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual std::string getBindingAttributeName () const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual void express (Expressor*) const { throw(std::runtime_error(FUNCTION_STRING)); };
    };
    extern POS* DefaultGraph;

    class RdfDB {
	typedef std::map<const POS*, BasicGraphPattern*> graphmap_type;
    protected:
	graphmap_type graphs;

    public:
	SWWEBagent* webAgent;
	SWSAXparser* xmlParser;
	std::ostream** debugStream;
	std::string baseURIstr; // base for loading relative URIs (e.g. files)

	RdfDB (SWSAXparser* xmlParser = NULL) : 
	    graphs(), webAgent(NULL), xmlParser(xmlParser), debugStream(NULL) {  }
	RdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser = NULL, std::ostream** debugStream = NULL) : 
	    graphs() , webAgent(webAgent), xmlParser(xmlParser), debugStream(debugStream) {  }
	RdfDB (RdfDB const &) : graphs() { throw(std::runtime_error(FUNCTION_STRING)); }
	RdfDB (const DefaultGraphPattern* graph) : graphs(), debugStream(NULL) {
	    BasicGraphPattern* bgp = assureGraph(DefaultGraph);
	    for (std::vector<const TriplePattern*>::const_iterator it = graph->begin();
		 it != graph->end(); it++)
		bgp->addTriplePattern(*it);
	}
	virtual ~RdfDB();
	std::set<const POS*> getGraphNames () {
	    std::set<const POS*> names;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		names.insert(it->first);
	    return names;
		    
	}
	BasicGraphPattern* assureGraph(const POS* name);
	void assureGraphs(std::set<const POS*> names) {
	    for (std::set<const POS*>::const_iterator it = names.begin(); it != names.end(); ++it)
		assureGraph(*it);
	}
	RdfDB& operator= (const RdfDB &ref) {
	    for (graphmap_type::const_iterator it = graphs.begin(); // @@@ same as ~RdfDB()
		 it != graphs.end(); it++)
		delete it->second;

	    for (graphmap_type::const_iterator it = ref.graphs.begin(); it != ref.graphs.end(); ++it) {
		BasicGraphPattern* to = assureGraph(it->first);
		const BasicGraphPattern* from = it->second;
		for (std::vector<const TriplePattern*>::const_iterator it = from->begin(); 
		     it != from->end(); ++it)
		    to->addTriplePattern(*it);
	    }	

	    webAgent = ref.webAgent;
	    xmlParser = ref.xmlParser;

	    debugStream = ref.debugStream;
	    return *this;
	}
	bool operator== (const RdfDB& ref) const {
	    std::set<const POS*> thisGraphs;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		// if (it->second->size() > 0)
		    thisGraphs.insert(it->first);

	    std::set<const POS*> refGraphs;
	    for (graphmap_type::const_iterator it = ref.graphs.begin(); it != ref.graphs.end(); ++it)
		// if (it->second->size() > 0)
		    refGraphs.insert(it->first);

	    if (thisGraphs != refGraphs)
		return false;

	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it) {
		// compare BasicGraphPatterns *it->second and *ref.graphs.find(it->first)->second;
		const POS* label = it->first;
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
	bool loadData (BasicGraphPattern* target, std::istream& stream, std::string mediaType, std::string nameStr, POSFactory* posFactory) {
	    if (!mediaType.compare(0, 9, "text/html") || 
		!mediaType.compare(0, 9, "application/xhtml")) {
		if (xmlParser == NULL)
		    throw std::string("no XML parser to parse ") + mediaType + 
			" document " + nameStr;
		RDFaParser rdfaParser(posFactory, xmlParser);
		std::istreambuf_iterator<char> i(stream), e;
		std::string s(i, e); 
		rdfaParser.parse(target, s.begin(), s.end(), nameStr);
		return false;
	    } else if (!mediaType.compare(0, 9, "text/rdf") || 
		       !mediaType.compare(0, 9, "text/rdf+xml")) {
		if (xmlParser == NULL)
		    throw std::string("no XML parser to parse ") + mediaType + 
			" document " + nameStr;
		RdfXmlParser p(posFactory, xmlParser);
		std::istreambuf_iterator<char> i(stream), e;
		std::string s(i, e); 
		p.parse(assureGraph(NULL), s.c_str());
		return false;
	    } else {
		TurtleSDriver turtleParser(nameStr, posFactory);
		turtleParser.setGraph(target);
		return turtleParser.parse_stream(stream);
	    }
	}
	virtual void loadData (const POS* name, BasicGraphPattern* target, POSFactory* posFactory) {
	    std::string nameStr = name->getLexicalValue();
	    std::string mediaType;
	    std::auto_ptr<std::istream> iptr = 
		OpenResourceStream(nameStr, baseURIstr, ISTREAM_none, 
				   &mediaType, webAgent, debugStream);
	    if (loadData(target, *iptr, mediaType, nameStr, posFactory))
		throw nameStr + ":0: error: unable to parse web document";
	}
	virtual void bindVariables(ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch);
	void express(Expressor* expressor) const;
	std::string toString () const {
	    /* simple unordered serializer -
	       SPARQLSerializer s;
	       express(&s);
	       return s.str(); */

	    /* ordered serializer */
	    std::list<const POS*> graphList;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		// if (it->second->size() > 0)
		    graphList.push_back(it->first);
	    POSsorter sorter;
	    graphList.sort(sorter);
	    std::stringstream s;
	    for (std::list<const POS*>::const_iterator it = graphList.begin(); it != graphList.end(); ++it)
		s << *graphs.find(*it)->second;
	    return s.str();
	}
    };

    inline std::ostream& operator<< (std::ostream& os, RdfDB const& my) {
	return os << my.toString();
    }

} // namespace w3c_sw

#endif // !RDF_DB_H

