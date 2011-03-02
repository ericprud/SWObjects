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

void loadWSDL (sw::ServiceDescription& tested, sw::ServiceDescription& expected,
	       std::string name, std::string inElt, std::string outElt,
	       std::string wsdlfile = "") {
    const std::string ns = Piqflow + "wsdl/" + name;

    // Load each WSDL file and add the expected operations and endpoints.
    if (wsdlfile.empty())
	wsdlfile = std::string("WSDLparser/PIQ/") + name + ".wsdl";
    sw::IStreamContext wsdl(wsdlfile);
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

BOOST_AUTO_TEST_CASE( prenormalizeF ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("WSDLparser/PIQ/prenormalize.rq", sw::IStreamContext::FILE);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( prenormalizeF_2 ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("WSDLparser/PIQ/prenormalize.rq", sw::IStreamContext::FILE);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput", "WSDLparser/PIQ/prenormalize-2.0.wsdl");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( partition ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition>\n\
LABEL tns:opPartition CONSTRUCT { ?a bas:has tns:DimFile } WHERE { ?a bas:has tns:ImageFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "partition", "ImageFile", "DimFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( chunkisize ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/chunkisize>\n\
LABEL tns:opChunkisize CONSTRUCT { ?a bas:has tns:ChucksizeMetaFile , tns:StackFile } WHERE { ?a bas:has tns:DimFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "chunkisize", "ChunkiSizeInput", "ChunkiSizeOutput");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( zproject ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/zproject>\n\
LABEL tns:opZproject CONSTRUCT { ?a bas:has tns:ProjectedChunkFile } WHERE { ?a bas:has tns:ChucksizeMetaFile , tns:StackFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "zproject", "zprojectInput", "ProjectedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( prenormalize ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/prenormalize>\n\
LABEL tns:opPrenormalize CONSTRUCT { ?a bas:has tns:OffsetTileFile , tns:AverageTileFile } WHERE { ?a bas:has tns:ProjectedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( normalizeZ ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/normalizeZ>\n\
LABEL tns:opNormalizeZ CONSTRUCT { ?a bas:has tns:NormalizedProjectedChunkFile } WHERE { ?a bas:has tns:ProjectedChunkFile , tns:OffsetTileFile , tns:AverageTileFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "normalizeZ", "normalizeZInput", "NormalizedProjectedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( autoalign ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/autoalign>\n\
LABEL tns:opAutoalign CONSTRUCT { ?a bas:has tns:OffsetsFile } WHERE { ?a bas:has tns:NormalizedProjectedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "autoalign", "NormalizedProjectedChunkFile", "OffsetsFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( mst ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/mst>\n\
LABEL tns:opMst CONSTRUCT { ?a bas:has tns:DisplacementsFile } WHERE { ?a bas:has tns:OffsetsFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "mst", "OffsetsFile", "DisplacementsFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( stitch ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/stitch>\n\
LABEL tns:opStitch CONSTRUCT { ?a bas:has tns:StichedChunkFile } WHERE { ?a bas:has tns:NormalizedProjectedChunkFile , tns:DisplacementsFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "stitch", "stitchInput", "StitchedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( reorganize ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/reorganize>\n\
LABEL tns:opReorganize CONSTRUCT { ?a bas:has tns:StichedChunkFile } WHERE { ?a bas:has tns:StichedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "reorganize", "StitchedChunkFile", "StitchedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( warp ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/warp>\n\
LABEL tns:opWarp CONSTRUCT { ?a bas:has tns:WarpMetaFile } WHERE { ?a bas:has tns:ControlPointsFile , tns:StichedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "warp", "warpInput", "WarpMetaFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( preprocess ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\n\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
LABEL tns:opPreprocess CONSTRUCT { ?a bas:has tns:PreprocessMetaFile } WHERE { ?a bas:has tns:WarpMetaFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    loadWSDL(tested, expected, "preprocess", "WarpMetaFile", "PreprocessMetaFile");

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

