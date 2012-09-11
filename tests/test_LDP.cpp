/* test_LDP.hpp -- 
 *
 * Test the LDP server built in to ../bin/sparql and LDP interactions built
 * into the SPARQLfed language.
 *
 * $Id: test_Ldp.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE LDP

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <boost/lexical_cast.hpp>
#define NEEDDEF_W3C_SW_SAXPARSER
#define NEEDDEF_W3C_SW_WEBAGENT
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "ServerInteraction.hpp"

#if HTTP_CLIENT != SWOb_DISABLED
  W3C_SW_WEBAGENT<> WebClient;
#else /* HTTP_CLIENT == SWOb_DISABLED */
  #warning unable to test RDFa over HTTP
#endif /* HTTP_CLIENT == SWOb_DISABLED */

#if XML_PARSER != SWOb_DISABLED
  W3C_SW_SAXPARSER P;
#else
  #error RDFa tests require an XML parser
#endif

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,GraphMatch:3"
w3c_sw_DEBUGGING_FUNCTIONS();

w3c_sw::AtomFactory F;

/** CurlPOSTtoLDPservice - invoke curl with parameters used in the server
 *  invocation.
 */
struct CurlPOSTtoLDPservice : w3c_sw::ClientServerInteraction {
    CurlPOSTtoLDPservice (std::string serverParams, std::string serverPath, const char* data, const char* media)
	: ClientServerInteraction(serverParams, serverPath)
    {
	invoke(std::string()
	       + "curl -s -X POST -H 'Content-Type: " + media + "' " + serverURL + "  -d '" + data + "'");
    }
};

/** ParsedResultSet - result set from a text string.
 */
struct ParsedResultSet : public w3c_sw::ResultSet {
    ParsedResultSet (std::string srt) : 
	ResultSet(&F) {
	delete *begin();
	erase(begin());
	w3c_sw::IStreamContext sptr(srt.c_str(), w3c_sw::IStreamContext::STRING, "text/sparql-results");
	w3c_sw::TTerm::String2BNode bnodeMap;
	parseTable(sptr, false, bnodeMap);
    }
};

/** EvaluatedPOSTresponseResultSet - result set from an executed query.
 */
struct EvaluatedPOSTresponseResultSet : public w3c_sw::ResultSet {
    EvaluatedPOSTresponseResultSet (std::string service, std::string postData, std::string query)
	: ResultSet(&F)
    {
	w3c_sw::RdfDB d(&WebClient, &P);

	{
	    boost::shared_ptr<w3c_sw::IStreamContext> istr;
	    istr = d.webAgent->post(service.c_str(), "text/turtle", postData.c_str());
	    if (w3c_sw::Logger::Logging(w3c_sw::Logger::IOLog_level, w3c_sw::Logger::info)) {
		std::stringstream o;
		o << "POSTing text/turtle [[\n" << postData.c_str() << "]] to " << service;
		o << " yielded  media type " << *istr->mediaType;
		o << ".\n";
		BOOST_LOG_SEV(w3c_sw::Logger::IOLog::get(), w3c_sw::Logger::info) << o.str();
	    }
	    d.loadData(d.ensureGraph(w3c_sw::DefaultGraph), *istr, service, service, &F);
	}

	{
	    w3c_sw::IStreamContext istr(query, w3c_sw::IStreamContext::STRING);
	    w3c_sw::SPARQLfedDriver sparqlParser("", &F);
	    w3c_sw::Operation* op = sparqlParser.parse(istr);
	    sparqlParser.clear(""); // clear out namespaces and base URI.
	    op->execute(&d, this);
	    delete op;
	}
    }
};


/** OperationOnInvokedServer - client interactions with the server built into
 *  the bin/sparql binary.
 */
struct OperationOnInvokedServer : w3c_sw::SPARQLServerInteraction {
    EvaluatedPOSTresponseResultSet got;
    ParsedResultSet expected;

    OperationOnInvokedServer (std::string serverParams, std::string serverPath, std::string postData, std::string query, std::string expect, std::string endState)
	: w3c_sw::SPARQLServerInteraction(serverParams, serverPath),
	  got(std::string() + "http://localhost:" + boost::lexical_cast<std::string>(port) + serverPath,
	      postData, w3c_sw::substituteQueryVariables(query, port)),
	  expected(expect)
    {
	w3c_sw_LINEN << "not validating endstate " << endState << "\n";
    }
};


//BOOST_AUTO_TEST_SUITE( local )

struct CurlPOSTtoSADIservice : w3c_sw::ClientServerInteraction {
    CurlPOSTtoSADIservice (std::string serverParams, std::string serverPath, const char* data, const char* media)
	: ClientServerInteraction(serverParams, serverPath)
    {
	invoke(std::string()
	       + "curl -s -X POST -H 'Content-Type: " + media + "' " + serverURL + "  -d '" + data + "'");
    }
};
BOOST_AUTO_TEST_CASE( curl1to1 ) {
    CurlPOSTtoLDPservice i
	(// Server invocation -- construct a pattern from supplied graph.
	 "--LDP 'PREFIX : <http://bugs.example/ns#>\n"
	 "       PREFIX ldp: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#>\n"
	 "       INSERT { GRAPH ?bug { ?bug a :Bug ; :whiner ?whiner ; :whatNow ?desc } }\n"
	 "    CONSTRUCT { ?bug a :Bug }\n"
	 "        WHERE { ?s :whiner ?whiner ; :whatNow ?desc\n"
	 "                BIND (ldp:host(</bugz>, </bugHead>, 2) AS ?bug) }' --once",
	 // interface path:
	 "/createBug",

	 // Curl this data and media type to verify the server response.
	 " @prefix : <http://bugs.example/ns#> .\n"
	 "_:myBug :whiner \"me\" ; :whatNow \"badly b0rked\" .", "text/turtle");
    BOOST_CHECK_EQUAL("{\n  </bugz/1> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://bugs.example/ns#Bug> .\n}\n", i.clientS);
}

BOOST_AUTO_TEST_CASE( invoked1 ) {
    OperationOnInvokedServer i
	(// Server invocation -- construct a pattern from supplied graph:
	 "--LDP 'PREFIX : <http://bugs.example/ns#>\n"
	 "       PREFIX ldp: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#>\n"
	 "       INSERT { GRAPH ?bug { ?bug a :Bug ; :whiner ?whiner ; :whatNow ?desc } }\n"
	 "    CONSTRUCT { ?bug a :Bug }\n"
	 "        WHERE { ?s :whiner ?whiner ; :whatNow ?desc\n"
	 "                BIND (ldp:host(</bugz>, </bugHead>, 2) AS ?bug) }' --once",
	 // interface path:
	 "/createBug",

	 // Client graph to POST to service:
	 " @prefix : <http://bugs.example/ns#> .\n"
	 "_:myBug :whiner 'me' ; :whatNow 'badly b0rked' .",

	 // Client SPARQL query to validate the response:
	 "SELECT ?type\n"
	 " WHERE { ?s a ?type\n"
	 //	 "         FILTER (STRSTARTS(STR(?s), 'http://localhost:%p/bugz/'))\n"
	 "}",

	 // Expected validation results:
	 "+------------------------------+\n"
	 "| ?type                        |\n"
	 "| <http://bugs.example/ns#Bug> |\n"
	 "+------------------------------+",

	 // Service database endstate:
	 "{}");
    BOOST_CHECK_EQUAL(i.got, i.expected);
}

//BOOST_AUTO_TEST_SUITE_END(/* local */)

