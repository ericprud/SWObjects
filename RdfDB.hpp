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
	    TurtleSDriver turtleParser("http://example.org/", posFactory);
	    if (turtleParser.parse_file(name->getTerminal())) {
		std::cerr << name->getTerminal() << ":0: error: unable to parse document" << std::endl;
	    } else {
		BasicGraphPattern* graph = turtleParser.root;
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

    class RdfRemoteDB : public RdfDB {
	class GraphSerializer : public SPARQLSerializer {
	    ResultSet* rs;
	    bool expectOuterGraph;
	    std::set<const Variable*> vars;
	    std::string selectString;
	    std::string federationString;

	public:
	    GraphSerializer (ResultSet* rs) : SPARQLSerializer(), rs(rs), expectOuterGraph(true) {  }
	    std::string getSelectString () const { return selectString; }
	    std::string getFederationString () const { return federationString; }

	protected:
	    virtual void variable (const Variable* const self, std::string terminal) {
		vars.insert(self);
		SPARQLSerializer::variable(self, terminal);
	    }

	    virtual void namedGraphPattern(const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters);
	};
    protected:
	std::vector<const char*> endpointPatterns;
	std::set<const POS*> loadedEndpoints;
    public:
	RdfRemoteDB (std::vector<const char*> endpointPatterns) : 
	    RdfDB(), endpointPatterns(endpointPatterns) {
	}
	virtual void loadData(const POS* name, POSFactory* posFactory);
	virtual void bindVariables(ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch);
    };

} // namespace w3c_sw

#endif // !RDF_DB_H

