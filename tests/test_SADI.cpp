/* test_Sadi.hpp -- 
 *
 * Test a SPARQL Parser and sadi serializer against references like
 *   http://www.sparql.org/validator.html
 *
 * $Id: test_Sadi.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE SADI

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

/** CurlPOSTtoSADIservice - invoke curl with parameters used in the server
 *  invocation.
 */
struct CurlPOSTtoSADIservice : w3c_sw::ClientServerInteraction {
    CurlPOSTtoSADIservice (std::string serverParams, const char* data, const char* media)
	: ClientServerInteraction(serverParams)
    {
	invoke(std::string()
	       + "curl -s -X POST -H 'Content-Type: " + media + "' " + serverURL + "  -d '" + data + "'");
    }
};

BOOST_AUTO_TEST_CASE( curl1to1 ) {
    CurlPOSTtoSADIservice i
	(// Server invocation -- construct a pattern from supplied graph.
	 // (A real SADI rule should include body data in the head.)
	 "--SADI 'CONSTRUCT { ?s <tag:eric@w3.org/2012/p2> \"X\" }\n"
	 "            WHERE { ?s <tag:eric@w3.org/2012/p1> ?o }' --once",

	 // Curl this data and media type to verify the server response.
	 "<s1> <tag:eric@w3.org/2012/p1> <ooo> .", "text/turtle");
    BOOST_CHECK_EQUAL("<s1> <tag:eric@w3.org/2012/p2> \"X\" .\n", i.clientS);
}

struct TableResultSetPrime : public w3c_sw::ResultSet {
    TableResultSetPrime (w3c_sw::AtomFactory* atomFactory, std::string srt, bool ordered, w3c_sw::TTerm::String2BNode& nodeMap) : 
	ResultSet(atomFactory) {
	erase(begin());
	w3c_sw::IStreamContext sptr(srt.c_str(), w3c_sw::IStreamContext::STRING, "text/sparql-results");
	parseTable(sptr, ordered, nodeMap);
    }
};

/** OperationOnSPARQLServer - client interactions with the server built into
 *  the bin/sparql binary.
 */
struct OperationOnSPARQLServer : w3c_sw::SPARQLServerInteraction {
    w3c_sw::ResultSet rs;
    w3c_sw::SPARQLfedDriver sparqlParser;

    OperationOnSPARQLServer (std::string serverParams, std::string query)
	: w3c_sw::SPARQLServerInteraction(serverParams), rs(&F), sparqlParser("", &F)
    {
	w3c_sw::IStreamContext istr(query, w3c_sw::IStreamContext::STRING);
	w3c_sw::Operation* op = sparqlParser.parse(istr);
	sparqlParser.clear(""); // clear out namespaces and base URI.
	w3c_sw::RdfDB d(&WebClient, &P);
	op->execute(&d, &rs);
    }

};

#ifdef SADI_INVOCATION
BOOST_AUTO_TEST_CASE( opinteraction ) {
    sleep(2);
    OperationOnSPARQLServer i
	(// Server invocation -- construct a pattern from supplied graph.
	 // (A real SADI rule should include body data in the head.)
	 "--SADI 'CONSTRUCT { ?s <tag:eric@w3.org/2012/p2> \"X\" }\n"
	 "            WHERE { ?s <tag:eric@w3.org/2012/p1> ?o }' --once",

	 // Client SPARQL operation to invoke the SADI service.
	 //   bind ?s
	 "+--------------------------+\n"
	 "| ?s                       |\n"
	 "| <tag:eric@w3.org/2012/S> |\n"
	 "+--------------------------+\n"
	 //   ask for the s2 return from the SADI service (should be <S>)
	 "SELECT ?s2 ?x\n"
	 " WHERE {\n"
	 //     from the server invoked above.
	 "    SADI <http://localhost:31533/SPARQL>\n"
	 //       sending { <S> <tag:eric@w3.org/2012/p1> <ooo> }
	 "        FROM { ?s <tag:eric@w3.org/2012/p1> <ooo> }\n"
	 //       and getting back { <S> <tag:eric@w3.org/2012/p2> \"X\" }
	 "        WHERE { ?s2 <tag:eric@w3.org/2012/p2> ?x }\n"
	 "}");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSetPrime
	expected(&F,
		 "+--------------------------+-----+\n"
		 "| ?s2                      | ?x  |\n"
		 "| <tag:eric@w3.org/2012/S> | \"X\" |\n"
		 "+--------------------------+-----+",
		 false, bnodeMap);
    BOOST_CHECK_EQUAL(i.rs, expected);
}
#endif /* SADI_INVOCATION */


#if 0
/* Simple SELECT.
 */
BOOST_AUTO_TEST_CASE( simple ) {
    ServerTableQuery i
	(// Server invocation -- construct a pattern from supplied graph:
	 "--SADI 'CONSTRUCT { ?s <tag:eric@w3.org/2012/p2> \"X\" }\n"
	 "            WHERE { ?s <tag:eric@w3.org/2012/p1> ?o }' --once",

	 // Client invocation -- bind ?s
	 "'+-----+\n"
	 "| ?s  |\n"
	 "| <S> |\n"
	 "+-----+\n"
	 //   ask for the s2 return from the SADI service (should be <S>)
	 "SELECT ?s2 ?x WHERE {"
	 //     from the server invoked above.
	 "    SADI <http://localhost:31533/SPARQL>\n"
	 //       sending { <S> <tag:eric@w3.org/2012/p1> <ooo> }
	 "        FROM { ?s <tag:eric@w3.org/2012/p1> <ooo> }\n"
	 //       and getting back { <S> <tag:eric@w3.org/2012/p2> \"X\" }
	 "        WHERE { ?s2 <tag:eric@w3.org/2012/p2> ?x }\n"
	 "}'",

	 // Expect these bound results:
	 "+-----+-----+\n"
	 "| ?s2 | ?x  |\n"
	 "| <S> | 'X' |\n"
	 "+-----+-----+");
    BOOST_CHECK_EQUAL(i.expected, i.got);
}

struct ServerTableQuery : w3c_sw::ClientServerInteraction {
    w3c_sw::ResultSet expected, got;

    ServerTableQuery (std::string serverParams,
		      std::string clientParams,
		      std::string expectedStr)
	: w3c_sw::ClientServerInteraction (serverParams, clientParams), expected(&F), got(&F)
    {
	w3c_sw::TTerm::String2BNode cliNodes, srvNodes;
	w3c_sw::IStreamContext clientIS(clientS, w3c_sw::IStreamContext::STRING, "text/sparql-results");
	// w3c_sw_LINEN << "clientS: " << clientS << std::endl;
	got = w3c_sw::ResultSet(&F, clientIS, false, cliNodes);
	// w3c_sw_LINEN << "got:\n" << got << std::endl;
	w3c_sw::IStreamContext expectedIS(expectedStr, w3c_sw::IStreamContext::STRING, "text/sparql-results");
	// w3c_sw_LINEN << "expected: " << expectedStr << std::endl;
	expected = w3c_sw::ResultSet(&F, expectedIS, false, srvNodes);
	// w3c_sw_LINEN << "expected:\n" << expected << std::endl;
    }
};

#endif

