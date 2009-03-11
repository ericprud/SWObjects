/* RdfRemoteDB - extension of RdfDB which federates queries to remote servers.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_REMOTE_DB_H
#define RDF_REMOTE_DB_H

#include "RdfDB.hpp"
#include "../interface/SAXparser.hpp"
#include "../interface/WEBagent_boostASIO.hpp"

namespace w3c_sw {

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

	    virtual void namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
		if (expectOuterGraph) {
		    expectOuterGraph = false;
		    lead();

		    /* Serialize nested stuff. */
		    depth++;
		    p_TriplePatterns->express(this);
		    p_Filters->express(this);
		    depth--;
		    // _BasicGraphPattern(self, p_TriplePatterns, p_Filters, p_allOpts);

		    /* Build SELECT and FILTER strings from enountered Variables. */
		    selectString = "SELECT ";
		    for (std::set<const Variable*>::const_iterator it = vars.begin();
			 it != vars.end(); ++it)
			selectString += (*it)->toString() + ' ';
		    federationString = rs->buildFederationString(vars);

		    expectOuterGraph = true;
		} else
		    SPARQLSerializer::namedGraphPattern(self, p_name, p_allOpts, p_TriplePatterns, p_Filters);
	    }

	};
    protected:
	std::vector<const char*> endpointPatterns;
	std::set<const POS*> loadedEndpoints;
	POSFactory* posFactory;
	SWSAXparser* xmlParser;
	SWWEBagent* webAgent;

    public:
	RdfRemoteDB (std::vector<const char*> endpointPatterns, SWSAXparser* xmlParser, SWWEBagent* webAgent) : 
	    RdfDB(), endpointPatterns(endpointPatterns), xmlParser(xmlParser), webAgent(webAgent) {  }
#if REGEX_LIB == SWOb_BOOST
	virtual void loadData (const POS* name, POSFactory* posFactory) {
	    for (std::vector<const char*>::const_iterator it = endpointPatterns.begin();
		 it != endpointPatterns.end(); ++it) {
		boost::regex re(*it);
		boost::cmatch matches;
		if (boost::regex_match(name->getLexicalValue().c_str(), matches, re)) {
		    loadedEndpoints.insert(name);
		    this->posFactory = posFactory;
		    return;
		}
	    }
	    RdfDB::loadData(name, posFactory);
	}
#endif /* REGEX_LIB == SWOb_BOOST */

	virtual void bindVariables (ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch) {
#if REGEX_LIB == SWOb_BOOST
	    if (loadedEndpoints.find(graph) == loadedEndpoints.end())
#endif /* REGEX_LIB == SWOb_BOOST */
		RdfDB::bindVariables(rs, graph, toMatch);
#if REGEX_LIB == SWOb_BOOST
	    else {
		/* Build the request URL in buffer u. */
		std::stringstream u;
		u.setf(std::ios::hex, std::ios::basefield);
		u.setf(std::ios::uppercase);

		u << graph->getLexicalValue() << "?query=";
		GraphSerializer ser(rs);
		toMatch->express(&ser);
		std::string q = ser.getSelectString() + '{' + ser.getSPARQLstring() + ser.getFederationString() + '}';
		for (std::string::const_iterator it = q.begin(); it != q.end(); ++it) {
		    if (*it == ' ')
			u << '+';
		    else if ((*it >= 'a' && *it <= 'z') || 
			     (*it >= 'A' && *it <= 'Z') || 
			     (*it >= '0' && *it <= '9'))
			u << *it;
		    else if (*it < 0x10)
			u << "%0" << (unsigned)*it;
		    else
			u << '%' << (unsigned)*it;
		}

		/* Do an HTTP GET. */
		std::string s(webAgent->get(
#if REGEX_LIB == SWOb_DISABLED
#warning "Web agent needs REGEX to parse service URL -- defaulting to http://localhost:8888/sparql"
					    "localhost", "8888", "/sparql"
#else /* !REGEX_LIB == SWOb_DISABLED */
					    u.str().c_str()
#endif /* !REGEX_LIB == SWOb_DISABLED */
					    ));

		/* Parse results into a ResultSet. */
		ResultSet red(posFactory, xmlParser, s.begin(), s.end());

		/* Join those results against our initial results. */
		rs->joinIn(&red);
	    }
#endif /* REGEX_LIB == SWOb_BOOST */
	}

    };

} // namespace w3c_sw

#endif // !RDF_REMOTE_DB_H

