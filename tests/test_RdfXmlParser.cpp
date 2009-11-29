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
#include "SWObjects.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "RdfXmlParser.hpp"

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
  w3c_sw::SAXparser_libxml P;
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
  w3c_sw::SAXparser_expat P;
#elif XML_PARSER == SWOb_MSXML3
  #include "../interface/SAXparser_msxml3.hpp"
  w3c_sw::SAXparser_msxml3 P;
#else
  #warning DAWG tests require an XML parser
#endif

#if HTTP_CLIENT == SWOb_ASIO
  #include "../interface/WEBagent_boostASIO.hpp"
  w3c_sw::WEBagent_boostASIO WebClient;
#else /* ! HTTP_CLIENT == SWOb_ASIO */
  #warning unable to test RdfXml over HTTP
#endif /* ! HTTP_CLIENT == SWOb_ASIO */

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>

namespace sw = w3c_sw;

sw::POSFactory F;
sw::TurtleSDriver turtleParser("", &F);
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
    sw::IStreamContext reference("RdfXmlParser/Db0_Db1.ttl", sw::StreamContext::FILE);
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
    sw::IStreamContext reference("RdfXmlParser/Db0_Db0.ttl", sw::StreamContext::FILE);
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
    sw::IStreamContext reference("RdfXmlParser/result-sort-8.ttl", sw::StreamContext::FILE);
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
    sw::IStreamContext reference("RdfXmlParser/SPARQLResult.ttl", sw::StreamContext::FILE);
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
    sw::IStreamContext reference("RdfXmlParser/Ts_To.ttl", sw::StreamContext::FILE);
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
    sw::IStreamContext reference("RdfXmlParser/Ds_po.ttl", sw::StreamContext::FILE);
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
    sw::IStreamContext reference("RdfXmlParser/Ds_Do.ttl", sw::StreamContext::FILE);
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

