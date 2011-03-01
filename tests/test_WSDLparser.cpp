/* test_WSDLparser.cpp - test WSDLparser.hpp
 *
 * $Id: test_WSDLparser.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

/* test graph-matching.
 *
 */

#define BOOST_TEST_MODULE WSDLparser

#include <map>
#include <vector>
#include "SWObjects.hpp"
#include "MapSetParser/MapSetParser.hpp"
#include "WSDLparser.hpp"

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

sw::AtomFactory F;
sw::MapSetDriver mapSetParser("", &F);
sw::WSDLparser GWSDLparser("", &F, &P);

typedef sw::SWSAXhandler::QName QName;

BOOST_AUTO_TEST_CASE( prenormalize ) {
    sw::IStreamContext rdfxml("WSDLparser/prenormalize.wsdl");
    sw::ServiceDescription tested;
    GWSDLparser.parse(&tested, rdfxml);

    const std::string NS_prenorm = "http://www.semanticbits.com/piq-workflow/wsdl/prenormalize";
    sw::ServiceDescription expected;
    sw::IStreamContext reference("WSDLparser/prenormalize.rq", sw::IStreamContext::FILE);
    expected.ms = mapSetParser.parse(reference);
    QName opName = QName(NS_prenorm, "opPrenormalize");
    expected.addOperation
	(opName,
	 sw::ServiceDescription::P_InOut,
	 QName(NS_prenorm, "ProjectedChunkFile"), // inElt,
	 QName(NS_prenorm, "prenormalizeOutput"), // outElt,
	 QName(NS_prenorm, "prenormalizePortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_prenorm, "prenormalizeService"),
			   QName(NS_prenorm, "prenormalizeSOAPBinding"),
			   QName(NS_prenorm, "opPrenormalize"),
			   "http://www.semanticbits.com/piq-workflow/prenormalize",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( prenormalize_2 ) {
    sw::IStreamContext rdfxml("WSDLparser/prenormalize-2.0.wsdl");
    sw::ServiceDescription tested;
    GWSDLparser.parse(&tested, rdfxml);

    const std::string NS_prenorm = "http://www.semanticbits.com/piq-workflow/wsdl/prenormalize";
    sw::ServiceDescription expected;
    sw::IStreamContext reference("WSDLparser/prenormalize.rq", sw::IStreamContext::FILE);
    expected.ms = mapSetParser.parse(reference);
    QName opName = QName(NS_prenorm, "opPrenormalize");
    expected.addOperation
	(opName,
	 sw::ServiceDescription::P_InOut,
	 QName(NS_prenorm, "ProjectedChunkFile"), // inElt,
	 QName(NS_prenorm, "prenormalizeOutput"), // outElt,
	 QName(NS_prenorm, "prenormalizePortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_prenorm, "prenormalizeService"),
			   QName(NS_prenorm, "prenormalizeSOAPBinding"),
			   QName(NS_prenorm, "opPrenormalize"),
			   "http://www.semanticbits.com/piq-workflow/prenormalize",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.

    BOOST_CHECK_EQUAL(tested, expected);
}

/* invoke with e.g. -DHTTP_RdfXml_test=http://mouni.local/RdfXml-0.rdf */
#if HTTP_CLIENT != SWOb_DISABLED && defined(HTTP_RdfXml_test)
BOOST_AUTO_TEST_CASE( by_http ) {
}
#endif /* HTTP_CLIENT != SWOb_DISABLED */

