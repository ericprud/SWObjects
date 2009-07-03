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
	virtual std::string toXMLResults (POS::BNodeMap*) const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual std::string toString () const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual std::string getBindingAttributeName () const { throw(std::runtime_error(FUNCTION_STRING)); }
	virtual void express (Expressor*) const { throw(std::runtime_error(FUNCTION_STRING)); };
    };
    extern POS* DefaultGraph;

    class RdfDB {
	typedef std::map<const POS*, BasicGraphPattern*> graphmap_type;
    protected:
	graphmap_type graphs;
	SWWEBagent* webAgent;
	SWSAXparser* xmlParser;

	std::ostream** debugStream;

    public:
	RdfDB (SWSAXparser* xmlParser = NULL) : 
	    graphs(), webAgent(NULL), xmlParser(xmlParser) {  }
	RdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser = NULL, std::ostream** debugStream = NULL) : 
	    graphs() , webAgent(webAgent), xmlParser(xmlParser), debugStream(debugStream) {  }
	RdfDB (RdfDB const &) : graphs() { throw(std::runtime_error(FUNCTION_STRING)); }
	RdfDB (const DefaultGraphPattern* graph) : graphs() {
	    BasicGraphPattern* bgp = assureGraph(DefaultGraph);
	    for (std::vector<const TriplePattern*>::const_iterator it = graph->begin();
		 it != graph->end(); it++)
		bgp->addTriplePattern(*it);
	}
	virtual ~RdfDB();
	bool operator== (const RdfDB& ref) const {
	    std::set<const POS*> thisGraphs;
	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		thisGraphs.insert(it->first);

	    std::set<const POS*> refGraphs;
	    for (graphmap_type::const_iterator it = ref.graphs.begin(); it != ref.graphs.end(); ++it)
		refGraphs.insert(it->first);

	    if (thisGraphs != refGraphs)
		return false;

	    for (graphmap_type::const_iterator it = graphs.begin(); it != graphs.end(); ++it)
		// compare BasicGraphPatterns *it->second and *ref.graphs.find(it->first)->second;
		if (!(*it->second == *ref.graphs.find(it->first)->second))
		    return false;

	    return true;
	}
	void clearTriples();
	BasicGraphPattern* assureGraph(const POS* name);
	bool loadData (BasicGraphPattern* target, std::istream& stream, std::string mediaType, std::string nameStr, POSFactory* posFactory) {
	    if (!mediaType.compare(0, 9, "text/html") || 
		!mediaType.compare(0, 9, "application/xhtml")) {
		if (xmlParser != NULL)
		    throw std::string("no XML parser to parse ") + mediaType + 
			" document " + nameStr;
		RDFaParser rdfaParser(posFactory, xmlParser);
		std::string s;
		stream >> s;
		rdfaParser.parse(target, s.begin(), s.end(), nameStr);
		return false;
	    } else if (!mediaType.compare(0, 9, "text/rdf") || 
		       !mediaType.compare(0, 9, "text/rdf+xml")) {
		if (xmlParser != NULL)
		    throw std::string("no XML parser to parse ") + mediaType + 
			" document " + nameStr;
		RdfXmlParser p(posFactory, xmlParser);
		std::string s;
		stream >> s;
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
	    if (webAgent != NULL && !nameStr.compare(0, 5, "http:")) {
		if (*debugStream != NULL)
		    **debugStream << "reading web resource " << nameStr << std::endl;
		std::string s(webAgent->get(nameStr.c_str()));
		std::stringstream stream(s); // would be nice to use webAgent stream, or have a callback.
		std::string mediaType = webAgent->getMediaType();
		if (loadData(target, stream, mediaType, nameStr, posFactory))
		    throw nameStr + ":0: error: unable to parse web document";
	    } else {
		if (*debugStream != NULL)
		    **debugStream << "reading file " << nameStr << std::endl;
		std::ifstream stream(nameStr.c_str());
		std::string mediaType = 
		    nameStr.substr(nameStr.size()-5, 5) == ".html" ? "text/html" : 
		    nameStr.substr(nameStr.size()-4, 4) == ".ttl" ? "text/rdf+xml" : 
		    "text/turtle";
		if (loadData(target, stream, mediaType, nameStr, posFactory))
		    throw nameStr + ":0: error: unable to parse file";
	    }
	}
	virtual void bindVariables(ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch);
	void express(Expressor* expressor) const;
	std::string toString () const {
	    SPARQLSerializer s;
	    express(&s);
	    return s.getString();
	}
    };

    inline std::ostream& operator<< (std::ostream& os, RdfDB const& my) {
	return os << my.toString();
    }

} // namespace w3c_sw

#endif // !RDF_DB_H

