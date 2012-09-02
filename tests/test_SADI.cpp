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
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "ServerInteraction.hpp"

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

BOOST_AUTO_TEST_CASE( simple ) {
    CurlPOSTtoSADIservice i
	(// Server invocation -- construct a pattern from supplied graph.
	 // (A real SADI rule should include body data in the head.)
	 "--SADI 'CONSTRUCT { ?s <tag:eric@w3.org/2012/p2> \"X\" }\n"
	 "            WHERE { ?s <tag:eric@w3.org/2012/p1> ?o }' --once",

	 // Curl this data and media type to verify the server response.
	 "<s1> <tag:eric@w3.org/2012/p1> <ooo> .", "text/turtle");
    BOOST_CHECK_EQUAL("<s1> <tag:eric@w3.org/2012/p2> \"X\" .\n", i.clientS);
}

#if 0
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

#endif

