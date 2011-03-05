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
#include "TurtleSParser/TurtleSParser.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "WSDLparser.hpp"
#include "ChainingMapper.hpp"

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

void loadWSDL (sw::ServiceDescription& sd, std::string wsdlfile) {
    sw::IStreamContext wsdl(wsdlfile);
    GWSDLparser.parse(&sd, wsdl);
}

void synWSDL (sw::ServiceDescription& tested, sw::ServiceDescription& expected,
	       std::string name, std::string inElt, std::string outElt,
	       std::string wsdlfile = "") {
    const std::string ns = Piqflow + "wsdl/" + name;

    // Load each WSDL file and add the expected operations and endpoints.
    if (wsdlfile.empty())
	wsdlfile = std::string("WSDLparser/PIQ/") + name + ".wsdl";
    loadWSDL(tested, wsdlfile);

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

    synWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( prenormalizeF_2 ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("WSDLparser/PIQ/prenormalize.rq", sw::IStreamContext::FILE);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput", "WSDLparser/PIQ/prenormalize-2.0.wsdl");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( partition ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition>\n\
LABEL tns:opPartition CONSTRUCT { ?a bas:has bas:DimFile } WHERE { ?a bas:has bas:ImageFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "partition", "ImageFile", "DimFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( chunkisize ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/chunkisize>\n\
LABEL tns:opChunkisize CONSTRUCT { ?a bas:has bas:ChucksizeMetaFile , bas:StackFile } WHERE { ?a bas:has bas:DimFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "chunkisize", "ChunkiSizeInput", "ChunkiSizeOutput");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( zproject ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/zproject>\n\
LABEL tns:opZproject CONSTRUCT { ?a bas:has bas:ProjectedChunkFile } WHERE { ?a bas:has bas:ChucksizeMetaFile , bas:StackFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "zproject", "zprojectInput", "ProjectedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( prenormalize ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/prenormalize>\n\
LABEL tns:opPrenormalize CONSTRUCT { ?a bas:has bas:OffsetTileFile , bas:AverageTileFile } WHERE { ?a bas:has bas:ProjectedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( normalizeZ ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/normalizeZ>\n\
LABEL tns:opNormalizeZ CONSTRUCT { ?a bas:has bas:NormalizedProjectedChunkFile } WHERE { ?a bas:has bas:ProjectedChunkFile , bas:OffsetTileFile , bas:AverageTileFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "normalizeZ", "normalizeZInput", "NormalizedProjectedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( autoalign ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/autoalign>\n\
LABEL tns:opAutoalign CONSTRUCT { ?a bas:has bas:OffsetsFile } WHERE { ?a bas:has bas:NormalizedProjectedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "autoalign", "NormalizedProjectedChunkFile", "OffsetsFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( mst ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/mst>\n\
LABEL tns:opMst CONSTRUCT { ?a bas:has bas:DisplacementsFile } WHERE { ?a bas:has bas:OffsetsFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "mst", "OffsetsFile", "DisplacementsFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( stitch ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/stitch>\n\
LABEL tns:opStitch CONSTRUCT { ?a bas:has bas:StichedChunkFile } WHERE { ?a bas:has bas:NormalizedProjectedChunkFile , bas:DisplacementsFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "stitch", "stitchInput", "StitchedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( reorganize ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/reorganize>\n\
LABEL tns:opReorganize CONSTRUCT { ?a bas:has bas:StichedChunkFile } WHERE { ?a bas:has bas:StichedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "reorganize", "StitchedChunkFile", "StitchedChunkFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( warp ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/warp>\n\
LABEL tns:opWarp CONSTRUCT { ?a bas:has bas:WarpMetaFile } WHERE { ?a bas:has bas:ControlPointsFile , bas:StichedChunkFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "warp", "warpInput", "WarpMetaFile");

    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( preprocess ) {
    sw::ServiceDescription tested;
    sw::ServiceDescription expected;

    sw::IStreamContext reference("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
LABEL tns:opPreprocess CONSTRUCT { ?a bas:has bas:PreprocessMetaFile } WHERE { ?a bas:has bas:WarpMetaFile }\n\
", sw::IStreamContext::STRING);
    sw::MapSet* ms = mapSetParser.parse(reference);
    expected.ms.append(*ms);
    delete ms;

    synWSDL(tested, expected, "preprocess", "WarpMetaFile", "PreprocessMetaFile");

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
    synWSDL(tested, expected, "partition", "ImageFile", "DimFile");
    synWSDL(tested, expected, "chunkisize", "ChunkiSizeInput", "ChunkiSizeOutput");
    synWSDL(tested, expected, "zproject", "zprojectInput", "ProjectedChunkFile");
    synWSDL(tested, expected, "prenormalize", "ProjectedChunkFile", "prenormalizeOutput");
    synWSDL(tested, expected, "normalizeZ", "normalizeZInput", "NormalizedProjectedChunkFile");
    synWSDL(tested, expected, "autoalign", "NormalizedProjectedChunkFile", "OffsetsFile");
    synWSDL(tested, expected, "mst", "OffsetsFile", "DisplacementsFile");
    synWSDL(tested, expected, "stitch", "stitchInput", "StitchedChunkFile");
    synWSDL(tested, expected, "reorganize", "StitchedChunkFile", "StitchedChunkFile");
    synWSDL(tested, expected, "warp", "warpInput", "WarpMetaFile");
    synWSDL(tested, expected, "preprocess", "WarpMetaFile", "PreprocessMetaFile");
    BOOST_CHECK_EQUAL(tested, expected);
}

BOOST_AUTO_TEST_CASE( forwardChainOne ) {
    sw::RdfDB db;
    sw::TurtleSDriver tparser("", &F);
    sw::SPARQLfedDriver sparser("", &F);
    sw::ServiceDescription sd;

    loadWSDL(sd, "WSDLparser/PIQ/partition.wsdl");

    tparser.parse("\
@prefix bas: <http://www.semanticbits.com/piq-workflow/wsdl/> .\n\
@prefix tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition> .\n\
<I> bas:has bas:ImageFile .\n\
", &db);
    sw::ResultSet working(&F), rs(&F);
    for (sw::MapSet::ConstructList::const_iterator it = sd.ms.maps.begin();
	 it != sd.ms.maps.end(); ++it)
	it->constr->execute(&db, &working);

//     rs.clear();
//     rs.setRdfDB(&db);
//     rs.resultType = sw::ResultSet::RESULT_Tabular;
    sw::Operation* q = sparser.parse("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
SELECT ?who WHERE { ?who bas:has bas:DimFile }\n\
");
    q->execute(&db, &rs);

    sw::TTerm::String2BNode bnodeMap;
    sw::ResultSet ref(&F, "\
# Who has da PreprocessMetaFile?\n\
+------+\n\
| ?who |\n\
| <I>  |\n\
+------+\n\
", false, bnodeMap);

    BOOST_CHECK_EQUAL(rs, ref);
}


BOOST_AUTO_TEST_CASE( forwardChainAll ) {
    sw::RdfDB db;
    sw::TurtleSDriver tparser("", &F);
    sw::SPARQLfedDriver sparser("", &F);
    sw::ServiceDescription sd;

    loadWSDL(sd, "WSDLparser/PIQ/partition.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/chunkisize.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/zproject.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/prenormalize.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/normalizeZ.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/autoalign.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/mst.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/stitch.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/reorganize.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/warp.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/preprocess.wsdl");

    tparser.parse("\
@prefix bas: <http://www.semanticbits.com/piq-workflow/wsdl/> .\n\
@prefix tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition> .\n\
<I> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
", &db);
    sw::ResultSet working(&F), rs(&F);
    for (sw::MapSet::ConstructList::const_iterator it = sd.ms.maps.begin();
	 it != sd.ms.maps.end(); ++it)
	it->constr->execute(&db, &working);

//     rs.clear();
//     rs.setRdfDB(&db);
//     rs.resultType = sw::ResultSet::RESULT_Tabular;
    sw::Operation* q = sparser.parse("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
SELECT ?who WHERE { ?who bas:has bas:PreprocessMetaFile }\n\
");
    q->execute(&db, &rs);

    sw::TTerm::String2BNode bnodeMap;
    sw::ResultSet ref(&F, "\
# Who has da PreprocessMetaFile?\n\
+------+\n\
| ?who |\n\
| <I>  |\n\
+------+\n\
", false, bnodeMap);

    BOOST_CHECK_EQUAL(rs, ref);
}


namespace w3c_sw {

    /** BackwardChainingRdfDB - an RdfDB which backward-chains
     * ms: MapSet of rules
     */
    class BackwardChainingRdfDB : public RdfDB {
    protected:
	AtomFactory* atomFactory;
	std::vector<Rule> rules;
	MapSet::e_sharedVars sharedVars;
	NodeShare nodeShare;

    public:
	BackwardChainingRdfDB (AtomFactory* atomFactory, const MapSet* ms)
	    : RdfDB(), atomFactory(atomFactory), sharedVars(MapSet::e_PROMISCUOUS) 
	{
	    for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
		 it != ms->maps.end(); ++it)
		addRule(it->constr, it->label);
	}
	void addRule (const Construct* rule, const TTerm* name) {
	    if (name == NULL) {
		std::stringstream ss;
		ss << rule;
		name = atomFactory->getRDFLiteral(ss.str());
	    }
	    Rule r = RuleParser().parseConstruct(rule, name);
	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "adding rule: " << r.toString();
	    rules.push_back(r);
	}
	virtual void bindVariables (ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch) {
	    ResultSet island(rs->getAtomFactory());
	    RdfDB::bindVariables(&island, graph, toMatch);

	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "matching: " << *toMatch << "\nagainst ground facts got:\n" << island;

	    Bindings bindings(atomFactory, rules, sharedVars, nodeShare);
	    bindings.alternatives.opts.clear();
	    bindings.alternatives.opts.push_back(Bindings::Rule2rs());
	    for (std::vector<const TriplePattern*>::const_iterator it = toMatch->begin();
		 it != toMatch->end(); it++)
		bindings.match(toMatch, *it);

// w3c_sw_LINEN << "opts: " << bindings.alternatives.opts.str() << "\n";
	    if (bindings.failed.size() > 0) {
		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "unable to match\n" << bindings.failed.toString(toMatch);
	    } else {
		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "reachable by rules: " << bindings << " -> [[\n";
		ResultSet disjoint(rs->getAtomFactory());

		Bindings::Alternatives::VarUniquifier varUniquifier;
		const TableOperation* gp = bindings.alternatives.instantiate(atomFactory, varUniquifier);
		// ResultSet copy(atomFactory);
    // w3c_sw_LINEN << "gp: " << *gp;
		gp->bindVariables(this, rs);
    // w3c_sw_LINEN << "got " << *rs;

		for (ResultSetIterator row = disjoint.begin() ; row != disjoint.end(); ) {
		    island.insert(island.end(), (*row)->duplicate(&island, island.end()));
		    delete *row;
		    row = disjoint.erase(row);
		}

		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "]]\n";
	    }

	    rs->joinIn(&island);
	    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "Backward chaining produced\n" << *rs;
	}
    };
}


BOOST_AUTO_TEST_CASE( backwardChainOne ) {
    sw::TurtleSDriver tparser("", &F);
    sw::SPARQLfedDriver sparser("", &F);
    sw::ServiceDescription sd;

    loadWSDL(sd, "WSDLparser/PIQ/partition.wsdl");

    sw::BackwardChainingRdfDB db(&F, &sd.ms);

    tparser.parse("\
@prefix bas: <http://www.semanticbits.com/piq-workflow/wsdl/> .\n\
@prefix tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition> .\n\
<I> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
<you> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
<they> bas:has bas:ImageFile999, bas:ControlPointsFile .\n\
", &db);
    sw::ResultSet rs(&F);

    sw::Operation* q = sparser.parse("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
SELECT ?who WHERE { ?who bas:has bas:DimFile }\n\
");

    q->execute(&db, &rs);

    sw::TTerm::String2BNode bnodeMap;
    sw::ResultSet ref(&F, "\
# Who has da PreprocessMetaFile?\n\
+--------+\n\
|   ?who |\n\
|   <I>  |\n\
| <you>  |\n\
+--------+\n\
", false, bnodeMap);

    BOOST_CHECK_EQUAL(rs, ref);
}


BOOST_AUTO_TEST_CASE( backwardChainTwo ) {
    sw::TurtleSDriver tparser("", &F);
    sw::SPARQLfedDriver sparser("", &F);
    sw::ServiceDescription sd;

    loadWSDL(sd, "WSDLparser/PIQ/partition.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/chunkisize.wsdl");

    sw::BackwardChainingRdfDB db(&F, &sd.ms);

    tparser.parse("\
@prefix bas: <http://www.semanticbits.com/piq-workflow/wsdl/> .\n\
@prefix tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition> .\n\
<I> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
<you> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
<they> bas:has bas:ImageFile999, bas:ControlPointsFile .\n\
", &db);
    sw::ResultSet rs(&F);

    sw::Operation* q = sparser.parse("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
SELECT ?who WHERE { ?who bas:has bas:StackFile }\n\
#SELECT ?who WHERE { ?who bas:has bas:PreprocessMetaFile }\n\
");

    q->execute(&db, &rs);

    sw::TTerm::String2BNode bnodeMap;
    sw::ResultSet ref(&F, "\
# Who has da PreprocessMetaFile?\n\
+--------+\n\
|   ?who |\n\
|   <I>  |\n\
| <you>  |\n\
+--------+\n\
", false, bnodeMap);

    BOOST_CHECK_EQUAL(rs, ref);
}

void logAllAt3 () {
    boost::shared_ptr< sw::Logger::Sink_t > sink = sw::Logger::prepare();
    sw::Logger::addStream(sink, boost::shared_ptr< std::ostream >(&std::clog, boost::log::empty_deleter()));
    for (std::vector<const char*>::const_iterator it = sw::Logger::Labels.begin();
	 it != sw::Logger::Labels.end(); ++it)
	sw::Logger::getLabelLevel(*it) = sw::Logger::severity_level(3);
}

BOOST_AUTO_TEST_CASE( backwardChainAll ) {
    sw::TurtleSDriver tparser("", &F);
    sw::SPARQLfedDriver sparser("", &F);
    sw::ServiceDescription sd;

    loadWSDL(sd, "WSDLparser/PIQ/partition.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/chunkisize.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/zproject.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/prenormalize.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/normalizeZ.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/autoalign.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/mst.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/stitch.wsdl");
//     loadWSDL(sd, "WSDLparser/PIQ/reorganize.wsdl");
    loadWSDL(sd, "WSDLparser/PIQ/warp.wsdl");
//     loadWSDL(sd, "WSDLparser/PIQ/preprocess.wsdl");

    sw::BackwardChainingRdfDB db(&F, &sd.ms);

    tparser.parse("\
@prefix bas: <http://www.semanticbits.com/piq-workflow/wsdl/> .\n\
@prefix tns: <http://www.semanticbits.com/piq-workflow/wsdl/partition> .\n\
<I> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
<you> bas:has bas:ImageFile, bas:ControlPointsFile .\n\
<they> bas:has bas:ImageFile999, bas:ControlPointsFile .\n\
", &db);
    sw::ResultSet rs(&F);

    sw::Operation* q = sparser.parse("\
PREFIX bas: <http://www.semanticbits.com/piq-workflow/wsdl/>\n\
PREFIX tns: <http://www.semanticbits.com/piq-workflow/wsdl/preprocess>\n\
SELECT ?who WHERE { ?who bas:has bas:StichedChunkFile }\n\
#SELECT ?who WHERE { ?who bas:has bas:WarpMetaFile }\n\
#SELECT ?who WHERE { ?who bas:has bas:PreprocessMetaFile }\n\
");

    // logAllAt3();

    q->execute(&db, &rs);

    sw::TTerm::String2BNode bnodeMap;
    sw::ResultSet ref(&F, "\
# Who has da PreprocessMetaFile?\n\
+--------+\n\
|   ?who |\n\
|   <I>  |\n\
| <you>  |\n\
+--------+\n\
", false, bnodeMap);

    BOOST_CHECK_EQUAL(rs, ref);
}


/* invoke with e.g. -DHTTP_Wsdl_test=http://mouni.local/Wsdl-0.rdf */
#if HTTP_CLIENT != SWOb_DISABLED && defined(HTTP_Wsdl_test)
BOOST_AUTO_TEST_CASE( by_http ) {
}
#endif /* HTTP_CLIENT != SWOb_DISABLED */

