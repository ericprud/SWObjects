/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_DB_H
#define RDF_DB_H

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser.hpp"
#include "SPARQLSerializer.hpp"

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
	RdfDB () : graphs() {  }
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
	virtual void loadData (const POS* name, POSFactory* posFactory) {
#ifdef _MSC_VER
	    /* @@@ Temporary work-around for a build bug in MSVC++ where TurltSDriver
	     *     isn't defined by including TurtleSParser/TurtleSParser.hpp .
	     */
	    BasicGraphPattern* graph = assureGraph(NULL);
	    if (loadGraph(graph, posFactory, "text/turtle", "", name->getTerminal())) {
		std::cerr << name->getTerminal() << ":0: error: unable to parse document" << std::endl;
	    } else {
#else /* !_MSC_VER */
	    TurtleSDriver turtleParser("http://example.org/", posFactory);
	    if (turtleParser.parse_file(name->getTerminal())) {
		std::cerr << name->getTerminal() << ":0: error: unable to parse document" << std::endl;
	    } else {
		BasicGraphPattern* graph = turtleParser.root;
#endif /* !_MSC_VER */
		SPARQLSerializer s; graph->express(&s); std::cerr << "PARSED: " << s.getSPARQLstring() << std::endl;
		BasicGraphPattern* target = assureGraph(name);
		for (std::vector<const TriplePattern*>::iterator from = graph->begin();
		     from != graph->end(); ) {
		    target->addTriplePattern(*from);
		    graph->erase(from);
		}
		delete graph;
	    }
	}
	virtual void bindVariables(ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch);
	void express(Expressor* expressor) const;
    };

    inline std::ostream& operator<< (std::ostream& os, RdfDB const& my) {
	SPARQLSerializer s;
	my.express(&s);
	return os << s.getSPARQLstring();
    }

} // namespace w3c_sw

#endif // !RDF_DB_H

