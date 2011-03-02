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
    const std::string NS_partition = "http://www.semanticbits.com/piq-workflow/wsdl/partition";
    sw::IStreamContext partition_wsdl("WSDLparser/PIQ/partition.wsdl");
    GWSDLparser.parse(&tested, partition_wsdl);
    expected.addOperation
	(QName(NS_partition, "opPartition"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_partition, "ImageFile"), // inElt,
	 QName(NS_partition, "DimFile"), // outElt,
	 QName(NS_partition, "partitionPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_partition, "partitionService"),
			   QName(NS_partition, "partitionSOAPBinding"),
			   QName(NS_partition, "opPartition"),
			   "http://www.semanticbits.com/piq-workflow/partition",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_chunkisize = "http://www.semanticbits.com/piq-workflow/wsdl/chunkisize";
    sw::IStreamContext chunkisize_wsdl("WSDLparser/PIQ/chunkisize.wsdl");
    GWSDLparser.parse(&tested, chunkisize_wsdl);
    expected.addOperation
	(QName(NS_chunkisize, "opChunkisize"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_chunkisize, "ChunkiSizeInput"), // inElt,
	 QName(NS_chunkisize, "ChunkiSizeOutput"), // outElt,
	 QName(NS_chunkisize, "chunkisizePortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_chunkisize, "chunkisizeService"),
			   QName(NS_chunkisize, "chunkisizeSOAPBinding"),
			   QName(NS_chunkisize, "opChunkisize"),
			   "http://www.semanticbits.com/piq-workflow/chunkisize",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_zproject = "http://www.semanticbits.com/piq-workflow/wsdl/zproject";
    sw::IStreamContext zproject_wsdl("WSDLparser/PIQ/zproject.wsdl");
    GWSDLparser.parse(&tested, zproject_wsdl);
    expected.addOperation
	(QName(NS_zproject, "opZproject"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_zproject, "zprojectInput"), // inElt,
	 QName(NS_zproject, "ProjectedChunkFile"), // outElt,
	 QName(NS_zproject, "zprojectPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_zproject, "zprojectService"),
			   QName(NS_zproject, "zprojectSOAPBinding"),
			   QName(NS_zproject, "opZproject"),
			   "http://www.semanticbits.com/piq-workflow/zproject",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_prenormalize = "http://www.semanticbits.com/piq-workflow/wsdl/prenormalize";
    sw::IStreamContext prenormalize_wsdl("WSDLparser/PIQ/prenormalize.wsdl");
    GWSDLparser.parse(&tested, prenormalize_wsdl);
    expected.addOperation
	(QName(NS_prenormalize, "opPrenormalize"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_prenormalize, "ProjectedChunkFile"), // inElt,
	 QName(NS_prenormalize, "prenormalizeOutput"), // outElt,
	 QName(NS_prenormalize, "prenormalizePortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_prenormalize, "prenormalizeService"),
			   QName(NS_prenormalize, "prenormalizeSOAPBinding"),
			   QName(NS_prenormalize, "opPrenormalize"),
			   "http://www.semanticbits.com/piq-workflow/prenormalize",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_normalizeZ = "http://www.semanticbits.com/piq-workflow/wsdl/normalizeZ";
    sw::IStreamContext normalizeZ_wsdl("WSDLparser/PIQ/normalizeZ.wsdl");
    GWSDLparser.parse(&tested, normalizeZ_wsdl);
    expected.addOperation
	(QName(NS_normalizeZ, "opNormalizeZ"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_normalizeZ, "normalizeZInput"), // inElt,
	 QName(NS_normalizeZ, "NormalizedProjectedChunkFile"), // outElt,
	 QName(NS_normalizeZ, "normalizeZPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_normalizeZ, "normalizeZService"),
			   QName(NS_normalizeZ, "normalizeZSOAPBinding"),
			   QName(NS_normalizeZ, "opNormalizeZ"),
			   "http://www.semanticbits.com/piq-workflow/normalizeZ",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_autoalign = "http://www.semanticbits.com/piq-workflow/wsdl/autoalign";
    sw::IStreamContext autoalign_wsdl("WSDLparser/PIQ/autoalign.wsdl");
    GWSDLparser.parse(&tested, autoalign_wsdl);
    expected.addOperation
	(QName(NS_autoalign, "opAutoalign"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_autoalign, "NormalizedProjectedChunkFile"), // inElt,
	 QName(NS_autoalign, "OffsetsFile"), // outElt,
	 QName(NS_autoalign, "autoalignPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_autoalign, "autoalignService"),
			   QName(NS_autoalign, "autoalignSOAPBinding"),
			   QName(NS_autoalign, "opAutoalign"),
			   "http://www.semanticbits.com/piq-workflow/autoalign",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_mst = "http://www.semanticbits.com/piq-workflow/wsdl/mst";
    sw::IStreamContext mst_wsdl("WSDLparser/PIQ/mst.wsdl");
    GWSDLparser.parse(&tested, mst_wsdl);
    expected.addOperation
	(QName(NS_mst, "opMst"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_mst, "OffsetsFile"), // inElt,
	 QName(NS_mst, "DisplacementsFile"), // outElt,
	 QName(NS_mst, "mstPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_mst, "mstService"),
			   QName(NS_mst, "mstSOAPBinding"),
			   QName(NS_mst, "opMst"),
			   "http://www.semanticbits.com/piq-workflow/mst",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_stitch = "http://www.semanticbits.com/piq-workflow/wsdl/stitch";
    sw::IStreamContext stitch_wsdl("WSDLparser/PIQ/stitch.wsdl");
    GWSDLparser.parse(&tested, stitch_wsdl);
    expected.addOperation
	(QName(NS_stitch, "opStitch"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_stitch, "stitchInput"), // inElt,
	 QName(NS_stitch, "StitchedChunkFile"), // outElt,
	 QName(NS_stitch, "stitchPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_stitch, "stitchService"),
			   QName(NS_stitch, "stitchSOAPBinding"),
			   QName(NS_stitch, "opStitch"),
			   "http://www.semanticbits.com/piq-workflow/stitch",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_reorganize = "http://www.semanticbits.com/piq-workflow/wsdl/reorganize";
    sw::IStreamContext reorganize_wsdl("WSDLparser/PIQ/reorganize.wsdl");
    GWSDLparser.parse(&tested, reorganize_wsdl);
    expected.addOperation
	(QName(NS_reorganize, "opReorganize"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_reorganize, "StitchedChunkFile"), // inElt,
	 QName(NS_reorganize, "StitchedChunkFile"), // outElt,
	 QName(NS_reorganize, "reorganizePortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_reorganize, "reorganizeService"),
			   QName(NS_reorganize, "reorganizeSOAPBinding"),
			   QName(NS_reorganize, "opReorganize"),
			   "http://www.semanticbits.com/piq-workflow/reorganize",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_warp = "http://www.semanticbits.com/piq-workflow/wsdl/warp";
    sw::IStreamContext warp_wsdl("WSDLparser/PIQ/warp.wsdl");
    GWSDLparser.parse(&tested, warp_wsdl);
    expected.addOperation
	(QName(NS_warp, "opWarp"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_warp, "warpInput"), // inElt,
	 QName(NS_warp, "WarpMetaFile"), // outElt,
	 QName(NS_warp, "warpPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_warp, "warpService"),
			   QName(NS_warp, "warpSOAPBinding"),
			   QName(NS_warp, "opWarp"),
			   "http://www.semanticbits.com/piq-workflow/warp",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.


    const std::string NS_preprocess = "http://www.semanticbits.com/piq-workflow/wsdl/preprocess";
    sw::IStreamContext preprocess_wsdl("WSDLparser/PIQ/preprocess.wsdl");
    GWSDLparser.parse(&tested, preprocess_wsdl);
    expected.addOperation
	(QName(NS_preprocess, "opPreprocess"),
	 sw::ServiceDescription::P_InOut,
	 QName(NS_preprocess, "WarpMetaFile"), // inElt,
	 QName(NS_preprocess, "PreprocessMetaFile"), // outElt,
	 QName(NS_preprocess, "preprocessPortType")// ifaceName
	 );
    expected.addEndpoint(boost::make_shared<sw::ServiceDescription::SoapEndpoint>
			 (sw::ServiceDescription::SoapEndpoint
			  (QName(NS_preprocess, "preprocessService"),
			   QName(NS_preprocess, "preprocessSOAPBinding"),
			   QName(NS_preprocess, "opPreprocess"),
			   "http://www.semanticbits.com/piq-workflow/preprocess",
			   sw::ServiceDescription::SOAP_11)));
    mapSetParser.clear(""); // clear out namespaces and base URI.
    BOOST_CHECK_EQUAL(tested, expected);
}

/* invoke with e.g. -DHTTP_Wsdl_test=http://mouni.local/Wsdl-0.rdf */
#if HTTP_CLIENT != SWOb_DISABLED && defined(HTTP_Wsdl_test)
BOOST_AUTO_TEST_CASE( by_http ) {
}
#endif /* HTTP_CLIENT != SWOb_DISABLED */

