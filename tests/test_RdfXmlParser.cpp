/* test_RdfXmlParser.cpp - test RdfXmlParser.hpp
 *
 * $Id: test_RdfXmlParser.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

/* test graph-matching.
 *
 */

#define BOOST_TEST_MODULE RdfXmlParser

#include <map>
#include <vector>

#define NEEDDEF_W3C_SW_SAXPARSER
#define NEEDDEF_W3C_SW_WEBAGENT
#include "SWObjects.hpp"
#include "TurtleParser.hpp"
#include "RdfXmlParser.hpp"

#if HTTP_CLIENT != SWOb_DISABLED
  W3C_SW_WEBAGENT<> WebClient;
#else /* HTTP_CLIENT == SWOb_DISABLED */
  #warning unable to test RDF/XML over HTTP
#endif /* HTTP_CLIENT == SWOb_DISABLED */

#if XML_PARSER != SWOb_DISABLED
  W3C_SW_SAXPARSER P;
#else
  #error RDF/XML tests require an XML parser
#endif


/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,Process:3"

namespace sw = w3c_sw;

sw::AtomFactory F;
sw::TurtleDriver turtleParser("", &F);
sw::RdfXmlParser GRdfXmlParser("", &F, &P);

struct MeasuredGraph : public sw::DefaultGraphPattern {
    
};

struct ReferenceGraph : public sw::DefaultGraphPattern {
};

BOOST_AUTO_TEST_CASE( Db0_Db1 ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/Db0_Db1.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("Db0_Db1.rdf");
    sw::IStreamContext reference("RdfXmlParser/Db0_Db1.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);

#ifdef FIXED_SOUND_GRAPH_COMPARE // !!!
    sw::DefaultGraphPattern notExpected;
    turtleParser.setGraph(&notExpected);
    turtleParser.setBase("Db0_Db1.rdf");
    sw::IStreamContext ref2("RdfXmlParser/Db0_Db0.ttl", sw::StreamContext::FILE);
    turtleParser.parse(ref2);
    turtleParser.clear(""); // clear out namespaces and base URI.
    if (tested == notExpected)
	BOOST_ERROR( "tested == notExpected" );
#endif /* SOUND_GRAPH_COMPARE */
}

BOOST_AUTO_TEST_CASE( Db0_Db0 ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/Db0_Db0.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("Db0_Db0.rdf");
    sw::IStreamContext reference("RdfXmlParser/Db0_Db0.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( result_sort_8 ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/result-sort-8.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("result-sort-8.rdf");
    sw::IStreamContext reference("RdfXmlParser/result-sort-8.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( SPARQLResultg ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/SPARQLResult.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("SPARQLResult.rdf");
    sw::IStreamContext reference("RdfXmlParser/SPARQLResult.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( Ts_To ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/Ts_To.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("Ts_To.rdf");
    sw::IStreamContext reference("RdfXmlParser/Ts_To.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( Ds_po ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/Ds_po.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("Ds_po.rdf");
    sw::IStreamContext reference("RdfXmlParser/Ds_po.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( Ds_Do ) {
    sw::DefaultGraphPattern tested;
    sw::IStreamContext rdfxml("RdfXmlParser/Ds_Do.rdf");
    GRdfXmlParser.parse(&tested, rdfxml);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase("Ds_Do.rdf");
    sw::IStreamContext reference("RdfXmlParser/Ds_Do.ttl", sw::IStreamContext::FILE);
    turtleParser.parse(reference);
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

/* invoke with e.g. -DHTTP_RdfXml_test=http://mouni.local/RdfXml-0.rdf */
#if HTTP_CLIENT != SWOb_DISABLED && defined(HTTP_RdfXml_test)
BOOST_AUTO_TEST_CASE( by_http ) {
    sw::DefaultGraphPattern tested;
    std::string s(WebClient.get(HTTP_RdfXml_test));
    BOOST_CHECK_EQUAL(WebClient.getMediaType().substr(0, 9), "application/rdf+xml");
    GRdfXmlParser.parse(&tested, s.begin(), s.end(), HTTP_RdfXml_test);

    sw::DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase(F.getURI(HTTP_RdfXml_test));
    turtleParser.parse_file("RdfXml-0.ttl");
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}
#endif /* HTTP_CLIENT != SWOb_DISABLED */

