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

const std::string Piqflow = "http://www.semanticbits.com/piq-workflow/";

void loadWSDL (sw::ServiceDescription& tested, sw::ServiceDescription& expected, std::string name, std::string inElt, std::string outElt) {
    const std::string ns = Piqflow + "wsdl/" + name;

    // Load each WSDL file and add the expected operations and endpoints.
    sw::IStreamContext wsdl(std::string("WSDLparser/PIQ/") + name + ".wsdl");
    GWSDLparser.parse(&tested, wsdl);

    std::string op = name;
    op[0] = ::toupper(op[0]);
    op.insert(0, "op");

    expected.addOperation
	(QName(ns, op),
	 sw::ServiceDescription::P_InOut,
	 QName(ns, inElt), // inElt,
	 QName(ns, outElt), // outElt,
	 QName(ns, name + "PortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(ns, name + "Service"),
			   QName(ns, name + "SOAPBinding"),
			   QName(ns, op),
			   Piqflow + name,
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.

}

BOOST_AUTO_TEST_CASE( prenormalize ) {
    sw::IStreamContext wsdl("WSDLparser/PIQ/prenormalize.wsdl");
    sw::ServiceDescription tested;
    GWSDLparser.parse(&tested, wsdl);

    const std::string NS_prenorm = "http://www.semanticbits.com/piq-workflow/wsdl/prenormalize";
    sw::ServiceDescription expected;
    sw::IStreamContext reference("WSDLparser/PIQ/prenormalize.rq", sw::IStreamContext::FILE);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;
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
    sw::IStreamContext wsdl("WSDLparser/PIQ/prenormalize-2.0.wsdl");
    sw::ServiceDescription tested;
    GWSDLparser.parse(&tested, wsdl);

    const std::string NS_prenorm = "http://www.semanticbits.com/piq-workflow/wsdl/prenormalize";
    sw::ServiceDescription expected;
    sw::IStreamContext reference("WSDLparser/PIQ/prenormalize.rq", sw::IStreamContext::FILE);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;
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

BOOST_AUTO_TEST_CASE( all ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    // Read the file containing all of the rules.
    sw::IStreamContext all_ref("WSDLparser/PIQ/all.rq", sw::IStreamContext::FILE);
    sw::MapSet* ms = mapSetParser.parse(all_ref);
    expected.ms.append(*ms);
    delete ms;

    // Load each WSDL file and add the expected operations and endpoints.
    loadWSDL(tested, expected, "partition", "ImageFile", "DimFile");
    loadWSDL(tested, expected, "chunkisize", "ChunkiSizeInput", "ChunkiSizeOutput");
    loadWSDL(tested, expected, "zproject", "zprojectInput", "ProjectedChunkFile");
    loadWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput");
    loadWSDL(tested, expected, "normalizeZ", "normalizeZInput", "NormalizedProjectedChunkFile");
    loadWSDL(tested, expected, "autoalign", "NormalizedProjectedChunkFile", "OffsetsFile");
    loadWSDL(tested, expected, "mst", "OffsetsFile", "DisplacementsFile");
    loadWSDL(tested, expected, "stitch", "stitchInput", "StitchedChunkFile");
    loadWSDL(tested, expected, "reorganize", "StitchedChunkFile", "StitchedChunkFile");
    loadWSDL(tested, expected, "warp", "warpInput", "WarpMetaFile");
    loadWSDL(tested, expected, "preprocess", "WarpMetaFile", "PreprocessMetaFile");
    BOOST_CHECK_EQUAL(tested, expected);
}

/* invoke with e.g. -DHTTP_Wsdl_test=http://mouni.local/Wsdl-0.rdf */
#if HTTP_CLIENT != SWOb_DISABLED && defined(HTTP_Wsdl_test)
BOOST_AUTO_TEST_CASE( by_http ) {
}
#endif /* HTTP_CLIENT != SWOb_DISABLED */

