/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_DB_H
#define RDF_DB_H

#include "SWObjects.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "SPARQLSerializer.hpp"
#if HTTP_CLIENT != SWOb_DISABLED
  #include "../interface/WEBagent.hpp"
  #include "../interface/SAXparser.hpp"
  #include "RDFaParser.hpp"
#endif /* HTTP_CLIENT != SWOb_DISABLED */

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
#if HTTP_CLIENT != SWOb_DISABLED
	SWWEBagent* webAgent;
#endif /* HTTP_CLIENT != SWOb_DISABLED */
	SWSAXparser* xmlParser;

    public:
	RdfDB (SWSAXparser* xmlParser = NULL) : graphs(), 
#if HTTP_CLIENT != SWOb_DISABLED
		webAgent(NULL), 
#endif /* HTTP_CLIENT != SWOb_DISABLED */
		xmlParser(xmlParser) {  }
#if HTTP_CLIENT != SWOb_DISABLED
	RdfDB (SWWEBagent* webAgent, SWSAXparser* xmlParser = NULL) : graphs() , webAgent(webAgent), xmlParser(xmlParser) {  }
#endif /* HTTP_CLIENT != SWOb_DISABLED */
	RdfDB (RdfDB const &) : graphs() { throw(std::runtime_error(FUNCTION_STRING)); }
	RdfDB (const DefaultGraphPattern* graph) : graphs() {
	    BasicGraphPattern* bgp = assureGraph(DefaultGraph);
	    for (std::vector<const TriplePattern*>::const_iterator it = graph->begin();
		 it != graph->end(); it++)
		bgp->addTriplePattern(*it);
	}
	virtual ~RdfDB();
	void clearTriples();
	BasicGraphPattern* assureGraph(const POS* name);
	virtual void loadData (const POS* name, BasicGraphPattern* target, POSFactory* posFactory) {
#if XML_PARSER != SWOb_DISABLED && HTTP_CLIENT != SWOb_DISABLED
	    std::string nameStr = name->getLexicalValue();
	    if (!nameStr.compare(0, 5, "http:")) {
		std::string s(webAgent->get(nameStr.c_str()));
		std::stringstream stream(s); // would be nice to use webAgent stream, or have a callback.
		if (!webAgent->getMediaType().compare(0, 9, "text/html")) {
		    RDFaParser rdfaParser(posFactory, xmlParser);
		    rdfaParser.parse(target, s.begin(), s.end(), nameStr);
		} else {
		    TurtleSDriver turtleParser(nameStr, posFactory);
		    turtleParser.setGraph(target);
		    if (turtleParser.parse_stream(stream))
			throw nameStr + ":0: error: unable to parse document";
		}
	    } else {
		TurtleSDriver turtleParser(name->getLexicalValue(), posFactory);
		turtleParser.setGraph(target);
		if (turtleParser.parse_file(name->getLexicalValue()))
		    throw name->getLexicalValue() + ":0: error: unable to parse document";
	    }
#else /* XML_PARSER == SWOb_DISABLED || HTTP_CLIENT == SWOb_DISABLED */
	    TurtleSDriver turtleParser(name->getLexicalValue(), posFactory);
	    turtleParser.setGraph(target);
	    if (turtleParser.parse_file(name->getLexicalValue()))
		throw name->getLexicalValue() + ":0: error: unable to parse document";
#endif /* XML_PARSER == SWOb_DISABLED || HTTP_CLIENT == SWOb_DISABLED */
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

