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

/** substituteQueryVariables - perform the following substitutions on s:
 *   %p -> port.
 */
std::string substituteQueryVariables (std::string s, int port) {
    std::string portStr = boost::lexical_cast<std::string>(port);
    for (size_t i = 0; i < s.length(); ) {
	i = s.find("%p", i);
	if (i == std::string::npos)
	    break;
	s.replace(i, 2, portStr);
    }
    return s;
}

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

/** ParsedResultSet - result set from a text string.
 */
struct ParsedResultSet : public w3c_sw::ResultSet {
    ParsedResultSet (std::string srt) : 
	ResultSet(&F) {
	erase(begin());
	w3c_sw::IStreamContext sptr(srt.c_str(), w3c_sw::IStreamContext::STRING, "text/sparql-results");
	w3c_sw::TTerm::String2BNode bnodeMap;
	parseTable(sptr, false, bnodeMap);
    }
};

/** EvaluatedResultSet - result set from an executed query.
 */
struct EvaluatedResultSet : public w3c_sw::ResultSet {
    EvaluatedResultSet (std::string query)
	: ResultSet(&F)
    {
	w3c_sw::IStreamContext istr(query, w3c_sw::IStreamContext::STRING);
	w3c_sw::SPARQLfedDriver sparqlParser("", &F);
	w3c_sw::Operation* op = sparqlParser.parse(istr);
	sparqlParser.clear(""); // clear out namespaces and base URI.
	w3c_sw::RdfDB d(&WebClient, &P);
	op->execute(&d, this);
    }
};


/** OperationOnInvokedServer - client interactions with the server built into
 *  the bin/sparql binary.
 */
struct OperationOnInvokedServer : w3c_sw::SPARQLServerInteraction {
    EvaluatedResultSet got;
    ParsedResultSet expected;

    OperationOnInvokedServer (std::string serverParams, std::string query, std::string expect)
	: w3c_sw::SPARQLServerInteraction(serverParams),
	  got(substituteQueryVariables(query, port)),
	  expected(expect)
    {  }
};

#ifdef INVOKED_SADI
BOOST_AUTO_TEST_CASE( invoked1 ) {
    OperationOnInvokedServer i
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
	 "    SADI <http://localhost:%p/SPARQL>\n"
	 //       sending { <S> <tag:eric@w3.org/2012/p1> <ooo> }
	 "        FROM { ?s <tag:eric@w3.org/2012/p1> <ooo> }\n"
	 //       and getting back { <S> <tag:eric@w3.org/2012/p2> \"X\" }
	 "        WHERE { ?s2 <tag:eric@w3.org/2012/p2> ?x }\n"
	 "}",
	 "+--------------------------+-----+\n"
	 "| ?s2                      | ?x  |\n"
	 "| <tag:eric@w3.org/2012/S> | \"X\" |\n"
	 "+--------------------------+-----+");
    BOOST_CHECK_EQUAL(i.got, i.expected);
}
#endif /* INVOKED_SADI */


/** OperationOnRemoteServer - client interactions with the server built into
 *  the bin/sparql binary.
 */
struct OperationOnRemoteServer {
    EvaluatedResultSet got;
    ParsedResultSet expected;

    OperationOnRemoteServer (std::string query, std::string expect)
	: got(query),
	  expected(expect)
    {  }
};

#ifdef REMOTE_SADI
BOOST_AUTO_TEST_CASE( remote1 ) {
    OperationOnRemoteServer i
	("SELECT ?greeting\n"
	 "WHERE {\n"
	 "  SADI <http://sadiframework.org/examples/hello>\n"
	 "  FROM {\n"
	 "    <http://example.com/1> a <http://sadiframework.org/examples/hello.owl#NamedIndividual> ;\n"
	 "        <http://xmlns.com/foaf/0.1/name> 'Guy Incognito' .\n"
	 "  } WHERE {\n"
	 "    <http://example.com/1> <http://sadiframework.org/examples/hello.owl#greeting> ?greeting .\n"
	 "  }\n"
	 "}",
	 " +-------------------------+\n"
	 " | ?greeting               |\n"
	 " | \"Hello, Guy Incognito!\"^^<http://www.w3.org/2001/XMLSchema#string> |\n"
	 " +-------------------------+");
    BOOST_CHECK_EQUAL(i.got, i.expected);
}
#endif /* REMOTE_SADI */
