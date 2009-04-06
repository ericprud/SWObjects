/* test_RDFaParser.cpp - test RDFaParser.hpp
 *
 * $Id: test_RDFaParser.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

/* test graph-matching.
 *
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE RDFaParser
#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

#include <map>
#include <vector>
#include "SWObjects.hpp"
#include "RDFaParser.hpp"

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
  #warning unable to test RDFa over HTTP
#endif /* ! HTTP_CLIENT == SWOb_ASIO */

using namespace w3c_sw;

POSFactory F;
TurtleSDriver turtleParser("", &F);
RDFaParser GRDFaParser(&F, &P);
const char* gabab = "http://hcls.deri.org/atag-data/gabab_example.html";

BOOST_AUTO_TEST_CASE( by_file ) {
    DefaultGraphPattern tested;
    GRDFaParser.parse(&tested, "RDFa-0.html", gabab);

    DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase(F.getURI(gabab));
    turtleParser.parse_file("RDFa-0.ttl");
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

#if HTTP_CLIENT != SWOb_DISABLED
BOOST_AUTO_TEST_CASE( by_http ) {
    DefaultGraphPattern tested;
    std::string s(WebClient.get("http://mouni.local/RDFa-0.html"));
    BOOST_CHECK_EQUAL(WebClient.getMediaType().substr(0, 9), "text/html");
    GRDFaParser.parse(&tested, s.begin(), s.end(), gabab);

    DefaultGraphPattern expected;
    turtleParser.setGraph(&expected);
    turtleParser.setBase(F.getURI(gabab));
    turtleParser.parse_file("RDFa-0.ttl");
    turtleParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}
#endif /* HTTP_CLIENT != SWOb_DISABLED */

