/* Copyright Eric Prud'hommeaux 2009.
 * Distributed under the Apache Software License.
 * thanks to Vladimir Prus's boost:program_options examples.

 * $Id$ */

#include <iostream>
#include <fstream>
#include <iterator>
#include <set>

#define NEEDDEF_W3C_SW_SAXPARSER
#define NEEDDEF_W3C_SW_WEBAGENT
#include "SWObjects.hpp" // #includes interface/WEBagent && interface/SAXparser

#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "MapSetParser/MapSetParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"

#include "XMLQueryExpressor.hpp"
#include "ChainingMapper.hpp"
#include "SPARQLSerializer.hpp"
#include "SPARQLAlgebraSerializer.hpp"
#include "XMLSerializer.hpp"
#include "SQLizer.hpp"

#define NEEDDEF_W3C_SW_WEBSERVER
#include "../interface/WEBserver.hpp"
/* We don't define NEEDDEF_W3C_SW_SQLCLIENT because we link to multiple
 * SQL clients. */
#include "../interface/SQLclient.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or include config.h manually) */
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#define VALIDATION_ERROR error
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <boost/regex.hpp>
#include <boost/iostreams/stream.hpp>

namespace sw = w3c_sw;

#include <fstream>
#ifdef BOOST_PROCESS
#include <boost/process.hpp>
#endif /* BOOST_PROCESS */

#include "SimpleServer.hpp"

#ifndef _MSC_VER
#include <dlfcn.h>
#endif /* !_MSC_VER */

struct ServerConfig {
    struct Request {
	bool allowBareNewlines_;

	Request () : allowBareNewlines_(true) {  }
	bool allowBareNewlines () { return allowBareNewlines_; }
    } request;
};

	unsigned char favicon[] = {
0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a,0x00,0x00,0x00,0x0d,0x49,0x48,0x44,0x52,
0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x08,0x06,0x00,0x00,0x00,0x1f,0xf3,0xff,
0x61,0x00,0x00,0x00,0x01,0x73,0x52,0x47,0x42,0x00,0xae,0xce,0x1c,0xe9,0x00,0x00,
0x00,0x04,0x67,0x41,0x4d,0x41,0x00,0x00,0xb1,0x8f,0x0b,0xfc,0x61,0x05,0x00,0x00,
0x00,0x20,0x63,0x48,0x52,0x4d,0x00,0x00,0x7a,0x26,0x00,0x00,0x80,0x84,0x00,0x00,
0xfa,0x00,0x00,0x00,0x80,0xe8,0x00,0x00,0x75,0x30,0x00,0x00,0xea,0x60,0x00,0x00,
0x3a,0x98,0x00,0x00,0x17,0x70,0x9c,0xba,0x51,0x3c,0x00,0x00,0x01,0xea,0x49,0x44,
0x41,0x54,0x38,0x4f,0x75,0x93,0xbd,0x4b,0x1d,0x41,0x14,0xc5,0xe7,0xce,0xdd,0xc5,
0x5a,0x21,0x45,0x52,0xd9,0x88,0x45,0x9a,0xf7,0x07,0x08,0x29,0x05,0x25,0x9d,0x22,
0x16,0x82,0x95,0xa0,0x06,0xb1,0x48,0x11,0x02,0x36,0x96,0x0b,0xe9,0x22,0x09,0x01,
0x41,0x03,0x22,0x88,0x20,0x82,0xa2,0xf8,0x81,0x4d,0x8a,0x90,0x14,0x16,0x76,0x12,
0x9b,0x10,0x22,0x89,0x62,0xaa,0x04,0x92,0x27,0xef,0xe6,0x37,0xb3,0xee,0xdb,0xf7,
0x5c,0xdd,0xe1,0x30,0x33,0x77,0xee,0x9c,0x39,0xf7,0x63,0xc5,0x39,0x37,0x08,0x9e,
0x80,0xca,0x27,0xc1,0x92,0x8a,0xb3,0xba,0x39,0x65,0x34,0x18,0xc6,0xb8,0xfd,0x2d,
0x60,0x08,0x56,0xe3,0x02,0xf0,0xe6,0x07,0xc0,0x92,0x9a,0x1c,0x7b,0x93,0x2f,0xac,
0x3f,0x7b,0xd3,0xb7,0x89,0x69,0x5f,0xc2,0xb9,0x44,0xdf,0x16,0xb8,0xac,0xd8,0xa4,
0x0f,0x52,0xd3,0x7d,0x2e,0x32,0xa0,0xaa,0x40,0x0c,0xa2,0x65,0xce,0x3b,0xda,0x48,
0x72,0x02,0xdf,0xc9,0xe1,0x49,0x62,0xfe,0x54,0xcd,0x6f,0x05,0x12,0x5f,0x21,0xf0,
0x5f,0x51,0x13,0xc6,0x2e,0xe7,0xbe,0x49,0xe2,0xb2,0x20,0xcb,0xaf,0xe6,0x2f,0xeb,
0x3c,0x52,0x1d,0x44,0x35,0x88,0xc2,0x6b,0x75,0x2e,0x7c,0x62,0x3d,0x02,0x42,0x78,
0xd1,0x8f,0xf9,0x25,0x73,0x1e,0x8e,0xcb,0x82,0x73,0xf9,0x22,0x87,0xe7,0x6a,0x3a,
0x07,0x66,0x21,0xfa,0xc6,0x5c,0x83,0xf4,0x29,0x04,0x3b,0xe4,0xe4,0x2a,0x0f,0x4d,
0x7e,0xb3,0x7e,0x58,0x10,0x64,0xed,0x72,0x75,0x2d,0xb1,0xa4,0x9f,0x7c,0x2c,0x92,
0x34,0x14,0xe8,0x28,0xfb,0x81,0x34,0x86,0x57,0xe4,0x26,0xa8,0xf5,0x93,0xec,0xc9,
0x7c,0x26,0x7b,0x2d,0x04,0x0d,0xc2,0x78,0xcf,0x6b,0x67,0xd8,0x7e,0xf0,0x02,0x7b,
0xf7,0x13,0xe7,0x0f,0x41,0x41,0x49,0x10,0x88,0xfc,0x62,0x24,0x90,0xcc,0x7f,0xac,
0x26,0xec,0xae,0x2a,0xdc,0xb6,0xc9,0x5a,0x11,0xc2,0xf6,0x3d,0x04,0x7f,0x70,0x08,
0xb8,0xa7,0xac,0xfa,0x06,0x05,0x31,0x89,0x24,0xac,0x2d,0xb6,0x03,0x12,0x37,0x4e,
0xe2,0x26,0xc0,0x10,0x98,0x22,0x99,0x2b,0xed,0xa5,0x8d,0x15,0x1b,0x2b,0x08,0x7a,
0xc8,0x28,0xa5,0x91,0x6b,0x8c,0x73,0x5c,0xe8,0x01,0x8f,0xb9,0x04,0x51,0x28,0xa1,
0x3e,0x07,0xdd,0x39,0x99,0x5c,0xe6,0x6a,0xfd,0x2f,0xaa,0xd5,0xc5,0x3a,0x28,0x70,
0xd4,0x53,0x5f,0xe3,0x70,0x05,0x90,0x25,0xff,0x70,0x58,0xe7,0xd2,0x26,0x04,0xdf,
0x99,0xe9,0x8d,0xd8,0x85,0xd8,0x8a,0x26,0xd3,0x67,0xf1,0xf5,0x82,0x80,0x4e,0x4c,
0x71,0xdc,0x4e,0x6e,0x42,0xe1,0x8d,0x0b,0x6f,0xc9,0x34,0xa5,0x1c,0x46,0xc9,0x51,
0x61,0x8f,0xc5,0x33,0x7d,0xd7,0x6c,0xa2,0x92,0x20,0xfe,0x4c,0x09,0x87,0xaf,0xb8,
0xf0,0x37,0x97,0x19,0xc3,0x6a,0x69,0x69,0x41,0xb6,0x96,0x1d,0xd8,0x54,0xb0,0x20,
0x52,0xfe,0x1c,0xb1,0xad,0x7b,0x89,0xef,0x05,0xd8,0x80,0xe0,0x30,0xb4,0x39,0xeb,
0x19,0xd6,0x8f,0x2a,0x7f,0xa2,0xfd,0x07,0xe6,0xae,0x7f,0xba,0xfb,0xc4,0x19,0x2f,
0x00,0x00,0x00,0x00,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,0x82,
	};

struct MyServer : W3C_SW_WEBSERVER<ServerConfig> { // W3C_SW_WEBSERVER defined to be e.g. w3c_sw::WEBserver_asio
    sw::SimpleEngine engine;
    ServerConfig config;
    std::string stopCommand;
    MyServer (std::string pkAttribute) : engine(pkAttribute)
    {  }
    std::string getStopCommand () { return stopCommand; }

    /** runServer - start an HTTP server
     * servicePath: (optional) add some service description about the service.
     */
    void runServer (sw::WebHandler& handler, std::string serviceURIstr, std::string serviceHost, int servicePort, std::string servicePath = "", bool addServiceDesc = true) {

	std::string startupMessage; // messages which get printed after a successful call to ::bind.

	if (!servicePath.empty()) {
	    const sw::URI* serviceURI = engine.atomFactory.getURI(serviceURIstr);
	    char buf[1024];
	    buf[0] = 0;
#if _MSC_VER
	    TCHAR szDirectory[MAX_PATH];	
	    szDirectory[0] = 0;
	    if (::GetCurrentDirectory(sizeof(szDirectory) - 1, szDirectory)) {
		std::wstring wstr(szDirectory);
		size_t len = (int)wstr.length();
		std::string str = "/";
		unsigned int i = 0;
		for (std::wstring::iterator it = wstr.begin();
		     i < len; ++it, ++i)
		    str += (char)(*it == '\\' ? '/' : *it);
		strncpy(buf, str.c_str(), sizeof(buf)-1);
	    }
#else /* !_MSV_VER */
	    getcwd(buf, sizeof(buf)-1);
#endif /* !_MSV_VER */
	    // const sw::TTerm* base;
	    if (buf[0]) {
		startupMessage += std::string() + "Working directory: " + buf + " .";
		// base = engine.htparseWrapper(buf, serviceURI);
	    }
	    if (addServiceDesc) {
		std::string sdesc =
		    "@prefix sd: <http://www.w3.org/ns/sparql-service-description#> .\n"
		    "@prefix ent: <http://www.w3.org/ns/entailment/> .\n"
		    "@prefix void: <http://rdfs.org/ns/void#> .\n"
		    "@prefix xpath: <http://www.w3.org/2005/xpath-functions#> .\n"
		    "@prefix swobj: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#> .\n"
		    "\n"
		    "[] a sd:Service ;\n"
		    "    sd:endpoint " + serviceURI->str() + " ;\n";
		// if (buf[0])
		//     sdesc += std::string() + "    sd:base " + base->str() + " ;\n";
		sdesc +=
		    "    sd:supportedLanguage sd:SPARQL11Query, sd:SPARQL11Update ;\n"
		    "    sd:resultFormat <http://www.w3.org/ns/formats/RDF_XML> ,\n"
		    "                <http://www.w3.org/ns/formats/Turtle> ,  \n"
		    "                <http://www.w3.org/ns/formats/N-Triples> ,\n"
		    "                <http://www.w3.org/ns/formats/SPARQL_Results_XML> ,\n"
		    "                <http://www.w3.org/ns/formats/SPARQL_Results_JSON> ,\n"
		    "                <http://www.w3.org/ns/formats/SPARQL_Results_CSV> ,\n"
		    "                <http://www.w3.org/ns/formats/SPARQL_Results_TSV> ;\n"
		    "    sd:extensionFunction xpath:normalize_space, swobj:lastTail, swobj:newTail, swobj:newNil, swobj:curTail, swobj:newObj ;\n"
		    "    sd:feature sd:DereferencesURIs, sd:BasicFederatedQuery ;\n"
		    "    sd:defaultEntailmentRegime ent:Simple ;\n"
		    "    sd:defaultDataset [\n"
		    "        a sd:Dataset ;\n"
		    "        sd:defaultGraph [\n"
		    "            a sd:Graph ;\n"
		    "            void:triples " + boost::lexical_cast<std::string>(engine.db.ensureGraph(sw::DefaultGraph)->size()) + "\n"
		    "        ] ;\n";

		// add the named graphs (including this one).
		sw::BasicGraphPattern* serviceGraph = engine.db.ensureGraph(serviceURI);
		std::set<const sw::TTerm*> names = engine.db.getGraphNames();
		for (std::set<const sw::TTerm*>::const_iterator it = names.begin(); it != names.end(); ++it) {
		    size_t thisSize = engine.db.ensureGraph(*it)->size();
		    if (*it == serviceURI)
			thisSize += 7*names.size()+31;
		    sdesc +=
			"        sd:namedGraph [\n"
			"            a sd:NamedGraph ;\n"
			"            sd:name " + (*it)->str() + " ;\n"
			"            sd:entailmentRegime ent:Simple ;\n"
			"            sd:graph [\n"
			"                a sd:Graph ;\n"
			"                void:triples " + boost::lexical_cast<std::string>(thisSize) + "\n"
			"            ]\n"
			"        ]\n";
		}
		sdesc +=
		    "    ] .\n"
		    "\n"
		    "xpath:normalize_space a sd:Function .\n"
		    "swobj:lastTail a sd:Function .\n"
		    "swobj:newTail a sd:Function .\n"
		    "swobj:newNil a sd:Function .\n"
		    "swobj:curTail a sd:Function .\n"
		    "swobj:newObj a sd:Function .\n"
		    "\n";

		sw::IStreamContext istr(sdesc, sw::IStreamContext::STRING);
		engine.turtleParser.parse(istr, serviceGraph);
	    }
	}

	std::stringstream tmpss;
	tmpss << servicePort;
	const char* bindMe = serviceHost.c_str(); // "0.0.0.0";
	try {
	    serve(bindMe, tmpss.str().c_str(), (int)1 /* one thread */, handler, config, startupMessage);
	} catch (boost::system::system_error e) {
	    throw std::string("Error binding ") + bindMe + ":" + tmpss.str().c_str() + ": " + e.what();
	}
    }

};


MyServer TheServer("ID");
bool Quiet = false;
bool ResultSetsLoaded = false;

struct MyLoadEntry {
    const sw::TTerm* graphName;
    const sw::TTerm* resource;
    const sw::TTerm* baseURI;
    sw::MediaType mediaType;
    
    MyLoadEntry (const sw::TTerm* graphName, const sw::TTerm* resource, const sw::TTerm* baseURI, sw::MediaType mediaType)
	: graphName(graphName), resource(resource), baseURI(baseURI), mediaType(mediaType) {  }
    MyLoadEntry (const MyLoadEntry& ref)
	: graphName(ref.graphName), resource(ref.resource), baseURI(ref.baseURI), mediaType(ref.mediaType) {  }
    void loadGraph () const {
	std::string nameStr = resource->getLexicalValue();
	sw::IStreamContext istr(nameStr, sw::IStreamContext::STDIN,
				mediaType ? mediaType.get().c_str() : NULL, 
				&TheServer.engine.webClient);

	const sw::TTerm* graph = graphName ? graphName : sw::DefaultGraph;
	ResultSetsLoaded = TheServer.engine.loadDataOrResults(graph, nameStr, baseURI, istr, TheServer.engine.resultSet, &TheServer.engine.db);
    }
};

struct MyLoadList : public std::vector<MyLoadEntry> {
    void enqueue (const sw::TTerm* graphName, const sw::TTerm* resource, const sw::TTerm* baseURI, sw::MediaType mediaType) {
	push_back(MyLoadEntry(graphName, resource, baseURI, mediaType));
    }
    void loadAll () const {
	for (const_iterator it = begin();
	     it != end(); ++it)
	    it->loadGraph();
    }
};

// std::ostream& operator<< (std::ostream& os, sw::NamespaceMap map) {
//     return os << map->toString();
// }

MyLoadList LoadList;
MyLoadList MapList;
MyLoadEntry Output(NULL, NULL, NULL, sw::MediaType());

boost::shared_ptr< sw::Logger::Sink_t > LogSink;

/* Set Debug when parsed. */
struct debugLevel { };
void validate (boost::any& v, const std::vector<std::string>& values, debugLevel*, int)
{
    const std::string& parm = po::validators::get_single_string(values);
    sw::Logger::parseLevelString(parm);
}

struct loggingFile { };
void validate (boost::any& v, const std::vector<std::string>& values, loggingFile*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    try {
	std::ofstream* fstream = new std::ofstream(s.c_str());
	BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Opening log file \"" << s << "\".";
	if (!fstream->is_open())
	    throw sw::StringException(s + " is not open");
	sw::Logger::addStream(LogSink, boost::shared_ptr< std::ostream >(fstream));
    } catch (std::exception& e) {
	BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::error) << "Unable to open logging file \"" << s << "\".";
    }
}

struct validationLevel { };
void validate (boost::any& v, const std::vector<std::string>& values, validationLevel*, int)
{
    sw::SPARQLfedDriver& sp = TheServer.engine.sparqlParser;
    std::string s = po::validators::get_single_string(values);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    bool m = false;
    if (s=="?") {
	m=true;
	std::string t;
	if (sp.validate & sp.VALIDATE_selectGrouped   ) {t+="selectGrouped|"   ;}
	if (sp.validate & sp.VALIDATE_uniqueProjection) {t+="uniqueProjection|";}
	if (sp.validate & sp.VALIDATE_namedProjection ) {t+="namedProjection|" ;}
	if (sp.validate & sp.VALIDATE_noReassign      ) {t+="noReassign|"      ;}
	if (sp.validate & sp.VALIDATE_constructNoQuads) {t+="constructNoQuads|";}
	if (sp.validate & sp.VALIDATE_bnodeScope      ) {t+="bnodeScope|"      ;}
	if (sw::AtomFactory::validate & sw::AtomFactory::VALIDATE_IRIcharacters)
	    {t+="IRIcharacters|"   ;}
	std::cout << "validation flag currently set to " << (t.size() > 0 ? t.substr(0, t.size()-1) : std::string("none")) << "\n";
    } else if (s=="all" || s=="true" || s=="1" || s=="yes") {
	m=true;
	sp.validate = sp.VALIDATE_all;
	sw::AtomFactory::validate = sw::AtomFactory::VALIDATE_all;
    } else if (s=="none" || s=="false" || s=="0" || s=="no") {
	m=true;
	sp.validate = sp.VALIDATE_none;
	sw::AtomFactory::validate = sw::AtomFactory::VALIDATE_none;
    } else {
	sp.validate = sp.VALIDATE_none;
	sw::AtomFactory::validate = sw::AtomFactory::VALIDATE_none;
	typedef sw::SPARQLfedDriver::e_Validation SP;
	if (s.find("selectgrouped"   )!=std::string::npos) { m=true; sp.validate = static_cast<SP>(sp.validate|sp.VALIDATE_selectGrouped)   ; }
	if (s.find("uniqueprojection")!=std::string::npos) { m=true; sp.validate = static_cast<SP>(sp.validate|sp.VALIDATE_uniqueProjection); }
	if (s.find("namedprojection" )!=std::string::npos) { m=true; sp.validate = static_cast<SP>(sp.validate|sp.VALIDATE_namedProjection) ; }
	if (s.find("noreassign"      )!=std::string::npos) { m=true; sp.validate = static_cast<SP>(sp.validate|sp.VALIDATE_noReassign)      ; }
	if (s.find("constructnoquads")!=std::string::npos) { m=true; sp.validate = static_cast<SP>(sp.validate|sp.VALIDATE_constructNoQuads); }
	if (s.find("bnodescope"      )!=std::string::npos) { m=true; sp.validate = static_cast<SP>(sp.validate|sp.VALIDATE_bnodeScope)      ; }
	if (s.find("iricharacters"   )!=std::string::npos)
	    { m=true; sw::AtomFactory::validate = static_cast<sw::AtomFactory::e_Validation>(sw::AtomFactory::validate|sw::AtomFactory::VALIDATE_IRIcharacters); }
    }
    if (!m)
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("validation argument \"").
			       append(s).append("\" must be one of selectGrouped, uniqueProjection, namedProjection, noReassign, constructNoQuads, bnodeScope."));
}

const sw::TTerm* Query; // URI is a guery ref; RDFLiteral is a query string.
const sw::TTerm* QueryBaseUri;
sw::MediaType QueryMediaType;


/* Set Query to an RDFLiteral when parsed. */
struct queryString {};
void validate (boost::any&, const std::vector<std::string>& values, queryString*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (Query != NULL)
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("query string: \"").
			       append(s).append("\" is redundant against ").
			       append(Query->getLexicalValue()));
    Query = TheServer.engine.atomFactory.getRDFLiteral(s);
    QueryBaseUri = TheServer.engine.baseURI;
    QueryMediaType = TheServer.engine.dataMediaType;
    TheServer.engine.dataMediaType = sw::MediaType();
}

/* URI to serve as a SPARQL server. */
struct serveURI {};
std::string ServerURI;
void validate (boost::any&, const std::vector<std::string>& values, serveURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!ServerURI.empty())
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("unable to serve \"").
			       append(s).append("\" and ").
			       append(ServerURI));
    ServerURI = s;
}

/* Set up a SADI service on the server. */
struct sadiConstruct {};
void validate (boost::any&, const std::vector<std::string>& values, sadiConstruct*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (TheServer.engine.sadiOp != NULL) {
	sw::SPARQLSerializer ss;
	TheServer.engine.sadiOp->express(&ss);
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("SADI CONSTRUCT: \"").
			       append(s).append("\" is redundant against ").
			       append(ss.str()));
    }
    sw::IStreamContext istr(s, sw::IStreamContext::STRING);
    sw::Operation* op = TheServer.engine.sparqlParser.parse(istr);
    sw::Construct* c = dynamic_cast<sw::Construct*>(op);
    if (c == NULL)
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("SADI argument \"").
			       append(s).append("\" is not a CONSTRUCT."));
    TheServer.engine.sadiOp = c;
}

/* Set up an LDP service on the server. */
struct ldpModify {};
void validate (boost::any&, const std::vector<std::string>& values, ldpModify*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (TheServer.engine.ldpOp != NULL) {
	sw::SPARQLSerializer ss;
	TheServer.engine.ldpOp->express(&ss);
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("LDP MODIFY: \"").
			       append(s).append("\" is redundant against ").
			       append(ss.str()));
    }
    sw::IStreamContext istr(s, sw::IStreamContext::STRING);
    const sw::Operation* parsed = TheServer.engine.sparqlParser.parse(istr);
    const sw::OperationSet* os = dynamic_cast<const sw::OperationSet*>(parsed);
    assert(os->size() == 1);
    const sw::Operation* first = *os->begin();
    const sw::Modify* c = dynamic_cast<const sw::Modify*>(first);
    if (c == NULL)
	throw boost::program_options
	    ::VALIDATION_ERROR(std::string("LDP argument \"").
			       append(s).append("\" is not a MODIFY."));
    TheServer.engine.ldpOp = c;
}

#if REGEX_LIB != SWOb_DISABLED
/* Add ServiceMaps from the form "s{from-URI}{to-URI}" */
struct servicemapArg {};
void validate (boost::any&, const std::vector<std::string>& values, servicemapArg*, int)
{
    const std::string& s = po::validators::get_single_string(values);

    const boost::regex serviceMapPattern("^s\\{(.*?)\\}\\{(.*?)\\}$");
    boost::cmatch matches;
    if (boost::regex_match(s.c_str(), matches, serviceMapPattern))
	sw::ServiceGraphPattern::ServiceMap.insert(std::make_pair(matches[1], matches[2]));
    else
	throw boost::program_options::VALIDATION_ERROR
	    (std::string("servicemap \"") + s +
	     "\" did not match expression \"" +
	     serviceMapPattern.str() + "\".");
}
#endif /* REGEX_LIB != SWOb_DISABLED */

#if REGEX_LIB != SWOb_DISABLED
/* Add PathMaps from the form "s{/some/URI/path}{relative/filesystem/path}" */
struct pathmapArg {};
void validate (boost::any&, const std::vector<std::string>& values, pathmapArg*, int)
{
    const std::string& s = po::validators::get_single_string(values);

    const boost::regex pathMapPattern("^s\\{(.*?)\\}\\{(.*?)\\}$");
    boost::cmatch matches;
    if (boost::regex_match(s.c_str(), matches, pathMapPattern))
	TheServer.engine.db.pathMaps.push_back
	    (sw::SimpleEngine::FilesystemRdfDB::PathMap
	     (boost::regex(std::string(matches[1])), std::string(matches[2])));
    else
	throw boost::program_options::VALIDATION_ERROR
	    (std::string("pathmap \"") + s +
	     "\" did not match expression \"" +
	     pathMapPattern.str() + "\".");
}
#endif /* REGEX_LIB != SWOb_DISABLED */


/* Set DataMediaType when parsed. */
struct langName { };
void validate (boost::any&, const std::vector<std::string>& values, langName*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!s.compare("?")) {
	std::cout << "data language options: \"\", guess, ntriples, turtle, trig, rdfa, rdfxml, sparqlt, sparqlx, sparqlj, csv, tsv, xml";
    } else {
	if (s == "" || s == "guess")
	    TheServer.engine.dataMediaType = sw::MediaType();
	else if (!s.compare("guess"))
	    TheServer.engine.dataMediaType = "text/plain";
	else if (!s.compare("ntriples"))
	    TheServer.engine.dataMediaType = "text/ntriples";
	else if (!s.compare("turtle"))
	    TheServer.engine.dataMediaType = "text/turtle";
	else if (!s.compare("trig"))
	    TheServer.engine.dataMediaType = "text/trig";
	else if (!s.compare("rdfa") || !s.compare("html"))
	    TheServer.engine.dataMediaType = "text/html";
	else if (!s.compare("rdfxml"))
	    TheServer.engine.dataMediaType = "application/rdf+xml";
	else if (!s.compare("sparqlt") || !s.compare("srt"))
	    TheServer.engine.dataMediaType = "text/sparql-results";
	else if (!s.compare("sparqlx") || !s.compare("srx"))
	    TheServer.engine.dataMediaType = "application/sparql-results+xml";
	else if (!s.compare("sparqlj") || !s.compare("srj"))
	    TheServer.engine.dataMediaType = "application/sparql-results+json";
	else if (!s.compare("csv"))
	    TheServer.engine.dataMediaType = "text/csv";
	else if (!s.compare("tsv"))
	    TheServer.engine.dataMediaType = "text/tab-separated-values";
	else if (!s.compare("xml"))
	    TheServer.engine.dataMediaType = "application/xml";
	else {
	    throw boost::program_options::VALIDATION_ERROR(std::string("invalid value: \"").append(s).append("\""));
	}
	if (!TheServer.engine.dataMediaType)
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Using no data language mediatype.\n";
	else
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Using data language mediatype " << *TheServer.engine.dataMediaType << ".\n";
    }
}
struct langType { };
void validate (boost::any&, const std::vector<std::string>& values, langType*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!s.compare("?")) {
	std::cout << "data mediatype options: \"\", text/plain, text/ntriples, text/turtle, text/trig, text/html, application/rdf+xml, application/sparql-results+xml, application/sparql-results+json, application/xml";
    } else {
	if (s == "" || s == "guess") {
	    TheServer.engine.dataMediaType = sw::MediaType(); // no media type
	} else {
	    if (!Quiet
		&& s.compare("text/plain")
		&& s.compare("text/ntriples")
		&& s.compare("text/turtle")
		&& s.compare("text/trig")
		&& s.compare("text/html")
		&& s.compare("application/rdf+xml")
		&& s.compare("text/sparql-results")
		&& s.compare("application/sparql-results+xml")
		&& s.compare("application/sparql-results+json")
		&& s.compare("text/csv")
		&& s.compare("text/tab-separated-values")
		&& s.compare("application/xml"))
		std::cerr << "proceeding with unknown media type \"" << s << "\"\n";
		// throw boost::program_options::VALIDATION_ERROR(std::string("invalid value: \"").append(s).append("\""));
	    TheServer.engine.dataMediaType = s;
	}
	if (!TheServer.engine.dataMediaType)
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Using no data mediatype mediatype.\n";
	else
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Using data mediatype mediatype " << *TheServer.engine.dataMediaType << ".\n";
    }
}

const sw::TTerm* CwdURI;
void validateBase(const std::vector<std::string>& values, const sw::TTerm** setMe, const sw::TTerm* copySource, const char* argName) {
    const std::string& s = po::validators::get_single_string(values);
    if (s == "?") {
	std::cout << argName << "URI: " << (*setMe ? (*setMe)->getLexicalValue() : "\"\"") << "\n";
    } else {
	*setMe = 
	    (s == ".") ? CwdURI : 
	    (s == ":") ? copySource : 
	    TheServer.engine.htparseWrapper(s, *setMe);
	BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Setting " << argName << " URI to " << (*setMe)->getLexicalValue() << ".\n";
    }
}

/* Base class for all relative URI arguments. */
struct relURI {};

/* Overload of relURI to validate --base arguments. */
struct baseURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, baseURI*, int)
{
    validateBase(values, &TheServer.engine.baseURI, TheServer.engine.argBaseURI, "base");
    TheServer.engine.sparqlParser.setBase(TheServer.engine.baseURI->getLexicalValue());
}

/* Overload of relURI to validate --arg-base arguments. */
struct argBaseURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, argBaseURI*, int)
{
    validateBase(values, &TheServer.engine.argBaseURI, TheServer.engine.baseURI, "argument base");
}

/* Overload of relURI to validate --output arguments. */
struct outPut : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, outPut*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* abs(TheServer.engine.htparseWrapper(s, TheServer.engine.argBaseURI));
    Output = MyLoadEntry(NULL, abs, TheServer.engine.baseURI, TheServer.engine.dataMediaType);
    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Sending output to " << abs->getLexicalValue() << TheServer.engine.baseUriMessage() << ".\n";
}

/* Overload of relURI to validate --in-place arguments. */
struct inPlace : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, inPlace*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (s == ".") {
	TheServer.engine.inPlace = true;
	BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Manipulating other input data.\n";
    } else {
	const sw::TTerm* abs(TheServer.engine.htparseWrapper(s, TheServer.engine.argBaseURI));
	LoadList.enqueue(NULL, abs, TheServer.engine.baseURI, TheServer.engine.dataMediaType);
	Output = MyLoadEntry(NULL, abs, TheServer.engine.baseURI, TheServer.engine.dataMediaType);
	if (sw::Logger::Logging(sw::Logger::IOLog_level, sw::Logger::info)) {
	    std::stringstream o;
	    o << "Replacing data from " << abs->getLexicalValue();
	    if (TheServer.engine.baseURI != NULL)
		o << " with base URI " << TheServer.engine.baseURI->getLexicalValue() << ".\n";
	    if (TheServer.engine.dataMediaType)
		o << " with media type " << *TheServer.engine.dataMediaType;
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << o.str();
	}
    }
}

/* Overload of relURI to validate --data arguments. */
struct dataURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, dataURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* abs(TheServer.engine.htparseWrapper(s, TheServer.engine.argBaseURI));
    LoadList.enqueue(NULL, abs, TheServer.engine.baseURI, TheServer.engine.dataMediaType);
    if (sw::Logger::Logging(sw::Logger::IOLog_level, sw::Logger::info)) {
	std::stringstream o;
	o << "Queued reading default data from " << abs->getLexicalValue();
	if (TheServer.engine.baseURI != NULL)
	    o << " with base URI " << TheServer.engine.baseURI->getLexicalValue();
	if (TheServer.engine.dataMediaType)
	    o << " with media type " << *TheServer.engine.dataMediaType;
	o << ".\n";
	BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::support) << o.str();
    }
}

/* Overload of xmlTransform to validate --data arguments. */
struct xmlTransform : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, xmlTransform*, int)
{
    const std::string& s = po::validators::get_single_string(values);

    size_t start, end;
    if (s.find_first_of("{") != 0)
	throw std::string("expected '{' at start of \"") + s + "\".";

    start = 0;
    end = s.find_first_of("}", start + 1);
    if (end == std::string::npos)
	throw std::string("expected '}' to delineate end of namespace in \"") + s + "\".";
    std::string nsS = s.substr(1, end - 1);

    start = end;
    end = s.find_first_of("{", start + 1);
    if (end == std::string::npos)
	throw std::string("expected '{' to end end \"") + s.substr(start + 1) + "\".";
    std::string tagS = s.substr(start + 1, end - start - 1);

    start = end;
    end = s.find_first_of("}", end + 1);
    if (end == std::string::npos)
	throw std::string("expected '}' to end end \"") + s.substr(start + 1) + "\".";
    std::string transformS = s.substr(start + 1, end - start - 1);

    std::string mediaTypeS = s.substr(end + 1);
    TheServer.engine.grddlMap.insert(nsS, tagS, transformS, mediaTypeS);
}

/* Overload of relURI to validate --mapset arguments. */
struct mapURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, mapURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* abs(TheServer.engine.htparseWrapper(s, TheServer.engine.argBaseURI));
    MapList.enqueue(NULL, abs, TheServer.engine.baseURI, TheServer.engine.dataMediaType);
    if (sw::Logger::Logging(sw::Logger::RewriteLog_level, sw::Logger::info)) {
	std::stringstream o;
	o << "Queued reading default map from " << abs->getLexicalValue();
	if (TheServer.engine.baseURI != NULL)
	    o << " with base URI " << TheServer.engine.baseURI->getLexicalValue();
	o << ".\n";
	BOOST_LOG_SEV(sw::Logger::RewriteLog::get(), sw::Logger::info) << o.str();
    }
}

/* Overload of relURI to validate --mapstring arguments. */
struct mapString {};
void validate (boost::any&, const std::vector<std::string>& values, mapString*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    MapList.enqueue(NULL, TheServer.engine.atomFactory.getRDFLiteral(s), TheServer.engine.baseURI, TheServer.engine.dataMediaType);
    if (sw::Logger::Logging(sw::Logger::RewriteLog_level, sw::Logger::info)) {
	std::stringstream o;
	o << "Queued reading default map from command line";
	if (TheServer.engine.baseURI != NULL)
	    o << " with base URI " << TheServer.engine.baseURI->getLexicalValue();
	o << ".\n";
	BOOST_LOG_SEV(sw::Logger::RewriteLog::get(), sw::Logger::info) << o.str();
    }
}

const sw::TTerm* NamedGraphName = NULL;
/* Overload of relURI to validate --graph arguments. */
struct graphURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, graphURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    NamedGraphName = s == "." ? TheServer.engine.atomFactory.getURI(".") : TheServer.engine.htparseWrapper(s, TheServer.engine.argBaseURI);
}

typedef std::vector<const sw::TTerm*> mapList;
mapList Maps;
/* Overload of relURI to validate --graph 2nd args, query and map arguments. */
struct orderedURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, orderedURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* vald = TheServer.engine.htparseWrapper(s, TheServer.engine.argBaseURI);
    if (NamedGraphName != NULL) {
	if (NamedGraphName->getLexicalValue() == ".")
	    NamedGraphName = vald;
	LoadList.enqueue(NamedGraphName, vald, TheServer.engine.baseURI, TheServer.engine.dataMediaType);
	BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info)
	    << "Reading named graph " << NamedGraphName->toString()
	    << " from " << vald->getLexicalValue()
	    << TheServer.engine.baseUriMessage() << ".\n";
	NamedGraphName = NULL;
    } else if (Query == NULL && ServerURI.empty()) {
	BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Query resource: " << vald->getLexicalValue() << ".\n";
	Query = vald;
	QueryBaseUri = TheServer.engine.baseURI;
	QueryMediaType = TheServer.engine.dataMediaType;
    } else {
	BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "View: " << vald->getLexicalValue() << ".\n";
	Maps.push_back(vald);
    }
}

/* Set UserName when parsed. */
struct userName {};
void validate (boost::any&, const std::vector<std::string>& values, userName*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    TheServer.engine.webClient_authPrompter.userName = s;
}
/* Set Password when parsed. */
struct passWord {};
void validate (boost::any&, const std::vector<std::string>& values, passWord*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    TheServer.engine.webClient_authPrompter.password = s;
}
/* Assign an HTTP header when parsed. */
struct HeaderPair {
    std::string name;
    std::string value;
    HeaderPair(std::string name, std::string value) : name(name), value(value) {  }
};
HeaderPair parseHeaderPair (const std::vector<std::string>& values)
{
    const std::string& s = po::validators::get_single_string(values);
    size_t pos = s.find_first_of(':');
    if (pos == std::string::npos)
	throw boost::program_options::VALIDATION_ERROR(std::string("no ':' found in HTTP header pair \"").append(s).append("\""));
    return HeaderPair(s.substr(0, pos), s.substr(pos+2));
}

std::map<std::string, std::string> HTTPHeaders;
struct headerAssign {};
void validate (boost::any&, const std::vector<std::string>& values, headerAssign*, int)
{
    HeaderPair pair = parseHeaderPair(values);
    HTTPHeaders[pair.name] = pair.value;
}
struct headerAppend {};
void validate (boost::any&, const std::vector<std::string>& values, headerAppend*, int)
{
    HeaderPair pair = parseHeaderPair(values);
    HTTPHeaders[pair.name].append(", ").append(pair.value);
}

#if REGEX_LIB != SWOb_DISABLED
struct sqlService {};
void validate (boost::any&, const std::vector<std::string>& values, sqlService*, int)
{
    const std::string s = po::validators::get_single_string(values);
    try {
	TheServer.engine.sqlConnectInfo.parse(s);
    } catch (std::runtime_error& re) {	
	// throw boost::program_options::VALIDATION_ERROR(s + " did not match expression " + TheServer.engine.sqlConnectInfo.odbcPattern.str());
	throw boost::program_options::VALIDATION_ERROR(re.what());
    }
}
#endif /* REGEX_LIB != SWOb_DISABLED */


std::string adjustPath (std::string nameStr) {
    if (nameStr.substr(0, 7) == "file://") {
	size_t slash = nameStr.find_first_of('/', 7);
	nameStr = nameStr.substr(slash);
    }
    return nameStr;
}

sw::Operation* parseQuery (const sw::TTerm* query) {
    std::string querySpec = query->getLexicalValue();
    sw::IStreamContext::e_opts opts = 
	(dynamic_cast<const sw::RDFLiteral*>(query) != NULL) ? 
	sw::IStreamContext::STRING : 
	sw::IStreamContext::STDIN;
    sw::IStreamContext iptr(querySpec, opts, NULL, &TheServer.engine.webClient);
    try {
	return TheServer.engine.sparqlParser.parse(iptr);
    } catch (sw::ParserException& e) {
	throw e;
    } catch (std::exception& e) {
	throw sw::StringException(std::string("error parsing query: ") + e.what());
    } catch(std::string& e) {
	throw std::string("error parsing query: ") + e;
    }
}

int main(int ac, char* av[])
{
    TheServer.engine.sparqlParser.validate = sw::SPARQLfedDriver::VALIDATE_none; // be forgiving about validation errors.
    sw::AtomFactory::validate = sw::AtomFactory::VALIDATE_none;
    int ret = 0; /* no errors */
    try {
	{   /* Logs default to level 0 (withing calling setLogLevels(logs, 0)). */
	    LogSink = sw::Logger::prepare();
	    sw::Logger::addStream(LogSink, boost::shared_ptr<std::ostream>
				  (&std::clog, boost::log::empty_deleter()));
	}

	Output = MyLoadEntry(NULL, TheServer.engine.atomFactory.getURI("-"), NULL, sw::MediaType());

	sw::BoxChars::GBoxChars = &sw::BoxChars::AsciiBoxChars;

	CwdURI = 
	    TheServer.engine.atomFactory.getURI(std::string("file://localhost")
		     .append(fs::current_path().string())
		     .append("/"));

        /* General options -- cli-only. */
        po::options_description generalOpts("General options");
        generalOpts.add_options()
            ("help,h", "brief help message")    
            ("Help,H", 
	     po::value< std::vector<std::string> >()->composing(), 
	     "general, results, uri, query, data, http, sql, tutorial, all")
            ("debug", po::value<debugLevel>(), 
	     "debugging level, e.g. \"*:1,SQL,Service:3,Process:-1\"")
            ("logging-file", po::value<loggingFile>(), 
	     "log file for debug output")
#ifndef _MSC_VER
	    ("function-library", po::value<std::string>(),
	     "load extension functions from a shared library")
#endif /* !_MSC_VER */
	    ("DbDebugEnumerateLimit", po::value<size_t>(),
	     "max number of triples to serialize in debug stream")
            ("ResultSetDebugEnumerateLimit", po::value<size_t>(),
	     "max number of results to serialize in debug stream")
            ("no-exec,n", "don't execute (or load data)")
            ("pipe,p", "pipe query to output (print final query)")
            ("quiet,q", "quiet")
            ("version,v", "print version string")
            ("validation", po::value<validationLevel>(), 
	     "how fussy to be about parsing")
	    ;
	/* rest: cli appends cfg file. */

        po::options_description resultsOpts("");
        resultsOpts.add_options()
            ("ascii,a", "output ASCII-only")
            ("utf-8,8", "output utf-8")
            ("bold", "output bold-bordered utf-8 boxes")
            ("nullterm,0", "terminate lines with \0")
            ("compare", po::value<std::string>(), 
	     "compare to some expected results.\n"
	     "Try `sparql -d a.ttl --compare b.ttl -q || echo fail` for minimal output")
            ("compare-as-result-set", po::value<std::string>(), 
	     "same as compare but the resultSet is in turtle.")
            ;
    
        po::options_description uriOpts("URI resolution");
        uriOpts.add_options()
            ("base,b", po::value<baseURI>(), 
	     "base URI for data/query resoultion")
            ("arg-base,B", 
	     po::value<argBaseURI>()->composing(), 
	     "base URI for command line arguments")
            ;

        po::options_description dataOpts("Reading data");
        dataOpts.add_options()
            ("data,d", po::value<dataURI>(), 
	     "read default graph from arg or stdin")
            ("graph,g", po::value<graphURI>(), 
	     "URI  read named graph <arg> from <URI> or stdin")
            ("xmltransform", po::value<xmlTransform>(), 
	     "GRDDL supplementary info: {namespace}tag{transformer}media/type")
            ("language-name,l", po::value<langName>(), 
	     "data language\n\"guess\" to guess by resource extension, or \"?\" to query options")
            ("lang-media-type,L", po::value<langType>(), 
	     "data language\n\"guess\" to guess by resource extension, or \"?\" to query options")
            ("output,o", po::value<outPut>(), 
	     "send results to relURI or \"-\" for stdout.")
            ("in-place,i", po::value<inPlace>(), 
	     "update arg with the results.\n\"-\" to read from stdin and write to stdout, \".\" manipulate input graphs.")
            ("description,D", 
	     "read application description graph (see section) into default graph.")
            ("description-graph,G", po::value<std::vector <std::string> >(), 
	     "read application description graph into graph arg.")

            ("get-graph-arguments", po::value<bool>(), 
	     "load named IRI in GRAPH <IRI> or GRAPH ?var when ?var is bound.")

            ("service", po::value<std::string>(), 
	     "relay all queries to service URL.")
#if REGEX_LIB != SWOb_DISABLED
            ("servicemap", po::value<servicemapArg>(), "service map in the form \"s{from-URI}{to-URI}\"")
#endif /* REGEX_LIB != SWOb_DISABLED */
            ("default-graph-uri", po::value<std::string>(), 
	     "default-graph-uri for calls to <service>.")
            ;
    
        po::options_description httpOpts("HTTP options");
        httpOpts.add_options()
            ("username,u", po::value<userName>(), 
	     "username for HTTP transactions")
            ("password", po::value<passWord>(), 
	     "password for HTTP transactions")
            ("header", po::value<headerAssign>(), 
	     "assign a header value.\n"
	     "\"--header ’Accept: text/turtle,text/html;q=.8’\" prefers turtle over HTML.")
            ("header+", po::value<headerAppend>(), 
	     "append earlier value of header.")
            ("stop-after", po::value<unsigned int>(), "SPARQL server handles n requests, then exits.")
            ("stop", po::value<std::string>(), "query string to stop the server.")
            ("post", "use POST (while GET is obviously superior) for SPARQL services.")
            ("federation-use-filters", "use FILTERs to convey constraints to SPARQL services.")
            ("federation-row-limit", po::value<size_t>(),
	     (std::string("max number of results to send to a remote service, default ")
	      + boost::lexical_cast<std::string>(sw::ServiceGraphPattern::defaultFederationRowLimit)).c_str()
	     )
            ("server-strict-HTTP", "HTTP server will expect strict conformance with HTTP specification, e.g. \\r\\n request line separators.")
            ("server-no-description", "Don't add SPARQL Service Description to the SPARQL endpoint.")
            ;

        po::options_description sqlOpts("SQL options");
        sqlOpts.add_options()
            ("stem", po::value<std::string>(), 
	     "stem URL.")
#if REGEX_LIB != SWOb_DISABLED
            ("sql-service,S", po::value<sqlService>(), 
	     "odbc-style SQL database\n\tdriver://[username[:password]@]host[:port]/database\nmysql://localhost/orders")
#endif /* REGEX_LIB != SWOb_DISABLED */

	    /** hmm, these aren't strictly SQL-related... */
            ("mapset,m", po::value<mapURI>(), 
	     "mapset resource, which supplies above parameters.")
            ("mapstring,M", po::value<mapString>(), 
	     "mapset, which supplies above parameters.")
            ;

        /* Ordered options -- not shown with --help.
	 * Hack: 2nd arg to --graph is a orderedURI 'cause boost::po doesn't
	 * handle "--foo arg1 arg2".
	 */
        po::options_description hidden("Hidden options");
        hidden.add_options()
            ("exec,e", po::value<queryString>(), "queries")
            ("serve", po::value<serveURI>(), "serve URI")

	    /** simple SADI CONSTRUCT service
	     * test with:
	     *   server invocation: --SADI 'CONSTRUCT { ?s <tag:eric@w3.org/2012/p2> "X" } WHERE { ?s <tag:eric@w3.org/2012/p1> ?o }' --serve http://localhost:8088/SADI
	     *   client call: curl -X POST -H 'Content-Type: text/turtle' http://localhost:8088/SADI -d '<s1> <tag:eric@w3.org/2012/p1> <ooo> .'
	     */
            ("SADI", po::value<sadiConstruct>(), "SADI server (instead of default SPARQL server)")
            ("LDP", po::value<ldpModify>(), "LDP server (instead of default SPARQL server)")
#if REGEX_LIB != SWOb_DISABLED
            ("pathmap", po::value<pathmapArg>(), "path map in the form \"s{/some/URI/path}{relative/filesystem/path}\"")
#endif /* REGEX_LIB != SWOb_DISABLED */
            ("ordered", po::value<orderedURI>(), "URIs")
	    ("trap-sig-int", po::value<bool>(), "0|1 no|yes")
            ;

        po::options_description cmdline_options;
        cmdline_options.add(generalOpts).add(resultsOpts).add(uriOpts).add(dataOpts).add(httpOpts).add(sqlOpts).add(hidden);

        po::options_description config_file_options;
        config_file_options.add(resultsOpts).add(uriOpts).add(dataOpts).add(httpOpts).add(sqlOpts).add(hidden);

        po::options_description visible("");
        visible.add(generalOpts).add(resultsOpts).add(uriOpts).add(httpOpts).add(sqlOpts).add(dataOpts);
        
        po::options_description cursory("");
        cursory.add(generalOpts).add(resultsOpts).add(uriOpts).add(dataOpts);
        
        po::positional_options_description p;
        p.add("ordered", -1);

	// A variable map for all parsed arguments...
        po::variables_map vm; {
	    // ...populated by command line...
	    po::store(po::command_line_parser(ac, av).
		      options(cmdline_options).positional(p).run(), vm);
	    // ...and a config file.
	    std::ifstream ifs(".sparql.cfg");
	    po::store(parse_config_file(ifs, config_file_options), vm);
	    po::notify(vm);
	}
    
	if (vm.count("post")) {
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Using HTTP POST.\n";
	    sw::ServiceGraphPattern::defaultHTTPmethod = sw::ServiceGraphPattern::HTTP_METHOD_POST;
	}

	if (vm.count("federation-use-filters")) {
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Using FILTER for query federation.\n";
	    sw::ServiceGraphPattern::useFilters = true;
	}

	if (vm.count("federation-row-limit")) {
	    size_t rows = vm["federation-row-limit"].as<size_t>();
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "Limiting result set federation to" << rows << " rows.\n";
	    sw::ServiceGraphPattern::defaultFederationRowLimit = rows;
	}

	if (vm.count("server-strict-HTTP")) {
	    BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::info) << "HTTP server will expect strict conformance with HTTP specification.\n";
	    TheServer.config.request.allowBareNewlines_ = false;
	}

        if (vm.count("utf-8")) {
	    BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Switching to utf-8.\n";
	    sw::BoxChars::GBoxChars = &sw::BoxChars::Utf8BoxChars;
        }

        if (vm.count("ascii")) {
	    BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Switching to ASCII.\n";
	    sw::BoxChars::GBoxChars = &sw::BoxChars::AsciiBoxChars;
        }

        if (vm.count("bold")) {
	    BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Switching to bold-bordered boxes.\n";
	    sw::BoxChars::GBoxChars = &sw::BoxChars::Utf8BldChars;
        }

        if (vm.count("no-exec")) {
	    BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Execution suppressed.\n";
            TheServer.engine.noExec = true;
        }

        if (vm.count("quiet")) {
	    BOOST_LOG_SEV(sw::Logger::DefaultLog::get(), sw::Logger::info) << "Non-debug messages supressed.\n";
            Quiet = true;
        }

	static const char* queryHelp = "Queries and maps:\n"
	    "  <queryURI>            read and execute a query from <queryURI>.\n"
	    "  -e <query>            execute <query>.\n"
	    "  <mapURI>              map query through a map at <mapURI> before executing.\n"
	    "  <mapString>           map query through <mapString> before executing.\n";
	static const char* appDescGraph = 
	    "    @prefix doap: <http://usefulinc.com/ns/doap#> .\n"
	    "    <> a doap:Project ;\n"
            "        doap:homepage <http://swobj.org/sparql/v1> ;\n"
            "        doap:shortdesc \"a semantic web query toolbox\" .\n";
	static const char* tutorial = 
	    "Tutorial:\n"
	    "  The SPARQL Query Language matches patterns of Semantic Web data. This sparql\n"
	    "  executable allows you to aggregate and query Semantic Web resources. To\n"
	    "  introduce this, the sparql executable contains a short description of itself,\n"
	    "  with the following assertions:\n"
	    "    sparql is a doap project.\n"
	    "    sparql has a homepage http://swobj.org/sparql/v1 .\n"
	    "    sparql is \"a Semantic Web query toolbox\".\n"
	    "  The sparql program starts with an empty database. You can load the above\n"
	    "  description (-D) and display it with \"sparql -D\":\n"
	    "{\n"
	    "  <> <http://...-rdf-syntax-ns#type> <http://usefulinc.com/ns/doap#Project> .\n"
	    "  <> <http://...#homepage> <http://swobj.org/sparql/v1> .\n"
	    "  <> <http://...#shortdesc> \"a semantic web query toolbox\"  .\n"
	    "}\n"
	    "  Because you supplied no query, sparql showed the contents of the loaded\n"
	    "  database. The default database output format is TriG, as specified at\n"
	    "    http://www4.wiwiss.fu-berlin.de/bizer/TriG/\n"
	    "\n"
	    "  You can query for all the triples:\n"
	    "    sparql -D -e \"SELECT ?s ?p ?o WHERE {?s ?p ?o}\"\n"
	    "  , giving resuls like:\n"
	    " +----+-------------------------------+----------------------------------------+\n"
	    " | ?s | ?p                            | ?o                                     |\n"
	    " | <> | <http://www.w3....ax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
	    " | <> |           <http...p#homepage> |           <http://swobj.org/sparql/v1> |\n"
	    " | <> |          <http:...#shortdesc> |         \"a semantic web query toolbox\" |\n"
	    " +----+-------------------------------+----------------------------------------+\n"
	    "\n"
	    "  -D loaded the three assertions into the \"default graph\", the graph to which\n"
	    "  SPARQL queries are directed unless otherwise directed by GRAPH clause. To try\n"
	    "  a GRAPH clause, load the description into the graph foo and query that graph:\n"
	    "    sparql -G foo -e \"SELECT ?s ?p ?o WHERE { GRAPH <foo> { ?s ?p ?o } }\"\n"
	    "\n"
	    "  We can load the description into a couple graphs *and* the default graph and\n"
	    "  ask all of the graphs which include an assertion about a doap project:\n"
	    "    sparql -a -DG foo -G foo2 -e \"SELECT ?g {\n"
            "       GRAPH ?g {?s ?p <http://usefulinc.com/ns/doap#Project>}}\"\n"
	    "    +--------+\n"
	    "    | ?g     |\n"
	    "    |  <foo> |\n"
	    "    | <foo2> |\n"
	    "    +--------+\n"
	    "\n"
	    "  Note that the default graph did not appear as the query only matches loaded\n"
	    "  *named* graphs. You can use a UNION to match both the default graph and loaded\n"
	    "  named graphs:\n"
	    "    ./sparql -a -DG foo -G foo2 -e \"SELECT ?g {\n"
	    "        {?s ?p <http://usefulinc.com/ns/doap#Project>}\n"
	    "      UNION\n"
	    "        {GRAPH ?g{?s ?p <http://usefulinc.com/ns/doap#Project>}}}\"\n"
	    "    +--------+\n"
	    "    | ?g     |\n"
	    "    |     -- |\n"
	    "    |  <foo> |\n"
	    "    | <foo2> |\n"
	    "    +--------+\n"
	    ;

	// --help
        if (vm.count("help")) {
            std::cout << 
		"Usage: sparql [opts] queryURI mapURI*\n"
		"       sparql [opts] -e query mapURI*\n"
		"       sparql [opts] --server URL mapURI*\n\n"
		"get started with: sparql --Help tutorial\n" << 
		queryHelp << cursory;
            TheServer.engine.noExec = true;
        }

	// --Help   (a bit more urgent and specific).
        if (vm.count("Help")) {
	    std::vector<std::string> helps(vm["Help"].as< std::vector<std::string> >());
	    for (std::vector<std::string>::const_iterator it = helps.begin();
		 it != helps.end(); ++it) {
		std::string nl = "\n"; // !it->compare("all") ? "\n" : "";
		bool matched = false;
		if (!it->compare("general") || !it->compare("all"))
		    matched = true, std::cout << generalOpts << nl;
		if (!it->compare("results") || !it->compare("all"))
		    matched = true, std::cout << resultsOpts << nl;
 		if (!it->compare("uri") || !it->compare("all"))
		    matched = true, std::cout << uriOpts << nl;
 		if (!it->compare("query") || !it->compare("all"))
		    matched = true, std::cout
			<< queryHelp
			<<  nl;
		if (!it->compare("data") || !it->compare("all"))
		    matched = true, std::cout
			<< dataOpts
			<< "sparql will \"guess\" that data from ’-’ is trig and output is either a table or trig.\n\n"
			<< "Application description graph:\n" << appDescGraph
			<< nl;
 		if (!it->compare("http") || !it->compare("all"))
		    matched = true, std::cout << httpOpts << nl;
 		if (!it->compare("sql") || !it->compare("all"))
		    matched = true, std::cout << sqlOpts << nl;
 		if (!it->compare("tutorial") || !it->compare("all"))
		    matched = true, std::cout << tutorial << nl;
		if (matched == false)
		    std::cout << "Unknown help topic: " << *it << "\n";
	    }
            TheServer.engine.noExec = true;
        }

#include "version.h"
        if (vm.count("version"))
            std::cout <<
		"sparql version 1.0 .\n"
		"Revision " SVN_Revision " modified " SVN_Last_Changed_Date " by " SVN_Last_Changed_Author ".\n"
		SVN_URL "\n";
	else {
	    if (TheServer.engine.noExec == false) {
		if (vm.count("description")) {
		    sw::IStreamContext s(appDescGraph, sw::IStreamContext::STRING);
		    s.mediaType = "text/turtle";
		    TheServer.engine.db.loadData(TheServer.engine.db.ensureGraph(sw::DefaultGraph), s, TheServer.engine.uriString(TheServer.engine.baseURI), TheServer.engine.uriString(TheServer.engine.baseURI), &TheServer.engine.atomFactory, &TheServer.engine.nsRelay);
		}

		if (vm.count("description-graph")) {
		    std::vector<std::string> descs(vm["description-graph"].as< std::vector<std::string> >());
		    for (std::vector<std::string>::const_iterator it = descs.begin();
			 it != descs.end(); ++it) {
			sw::IStreamContext s(appDescGraph, sw::IStreamContext::STRING);
			s.mediaType = "text/turtle";
			TheServer.engine.db.loadData(TheServer.engine.db.ensureGraph(TheServer.engine.atomFactory.getURI(*it)), s, TheServer.engine.uriString(TheServer.engine.baseURI), TheServer.engine.uriString(TheServer.engine.baseURI), &TheServer.engine.atomFactory);
		    }
		}

		LoadList.loadAll();

#ifndef _MSC_VER
		if (vm.count("function-library")) {
		    std::string libpath = vm["function-library"].as<std::string>();

		    void* libHandle = dlopen(libpath.c_str(), RTLD_NOW);
		    if (libHandle == NULL)
			throw std::runtime_error
			    (std::string() + "unable to open function library \""
			     + libpath.c_str() + "\". error: " + strerror(errno));
		    sw::AtomicFunction::Library::Initialize* fptr =
			(sw::AtomicFunction::Library::Initialize*)dlsym(libHandle, "initialize");

		    if(fptr == NULL)
			throw std::runtime_error
			    (std::string() + "unable to find \"initialize\" function in function library \""
			     + libpath.c_str() + "\". error: " + strerror(errno));
		    (*fptr)(&sw::AtomicFunction::GlobalMap, &TheServer.engine.atomFactory);
		}
#endif /* !_MSC_VER */
		if (vm.count("DbDebugEnumerateLimit"))
		    sw::RdfDB::DebugEnumerateLimit = vm["DbDebugEnumerateLimit"].as<size_t>();
		if (vm.count("ResultSetDebugEnumerateLimit"))
		    sw::ResultSet::DebugEnumerateLimit = vm["ResultSetDebugEnumerateLimit"].as<size_t>();
		if (vm.count("ResultSetDebugEnumerateLimit"))
		    sw::ResultSet::DebugEnumerateLimit = vm["ResultSetDebugEnumerateLimit"].as<size_t>();
		if (vm.count("get-graph-arguments"))
		    sw::RdfDB::GetGraphArguments = vm["get-graph-arguments"].as<bool>();

		if (sw::Logger::Logging(sw::Logger::IOLog_level, sw::Logger::support)) {
		    size_t size = TheServer.engine.db.size();
		    if (size > sw::RdfDB::DebugEnumerateLimit) {
			size_t graphCount = TheServer.engine.db.getGraphNames().size();
			BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::support)
			    << "Loaded "
			    << size << " triple" << (size == 1 ? "" : "s")
			    << " into "
			    << graphCount << " graph" << (graphCount == 1 ? "" : "s")
			    << ".\n";
		    } else
			BOOST_LOG_SEV(sw::Logger::IOLog::get(), sw::Logger::support) << "<loadedData>\n" << TheServer.engine.db << "</loadedData>\n";
		}
	    }

	    if (vm.count("stem"))
		TheServer.engine.stemURI = vm["stem"].as<std::string>();
	    if (vm.count("service"))
		TheServer.engine.serviceURI = vm["service"].as<std::string>();
	    if (vm.count("default-graph-uri"))
		TheServer.engine.defaultGraphURI = vm["default-graph-uri"].as<std::string>();
	    if (vm.count("pipe"))
		TheServer.engine.printQuery = true;

	    for (MyLoadList::iterator it = MapList.begin();
		 it != MapList.end(); ++it) {
		std::string nameStr = it->resource->getLexicalValue();
		sw::IStreamContext::e_opts opts = 
		    (dynamic_cast<const sw::RDFLiteral*>(it->resource) != NULL) ? 
		    sw::IStreamContext::STRING : 
		    sw::IStreamContext::STDIN;
		sw::IStreamContext istr(nameStr, opts, NULL, &TheServer.engine.webClient);
		sw::MapSet* ms = TheServer.engine.mapSetParser.parse(istr); // throws if it fails to parse
		// could catch and re-throw std::string("error when parsing map ").append(nameStr);

		if (ms->driver)   TheServer.engine.sqlConnectInfo.driver   = ms->driver->getLexicalValue();
		if (ms->server)   TheServer.engine.sqlConnectInfo.server   = ms->server->getLexicalValue();
		if (ms->user)     TheServer.engine.sqlConnectInfo.user     = ms->user->getLexicalValue();
		if (ms->password) TheServer.engine.sqlConnectInfo.password = ms->password->getLexicalValue();
		if (ms->database) TheServer.engine.sqlConnectInfo.database = ms->database->getLexicalValue();
		if (ms->stemURI)  TheServer.engine.stemURI = ms->stemURI->getLexicalValue();
		TheServer.engine.queryMapper.sharedVars = ms->sharedVars;
		for (sw::MapSet::ConstructList::const_iterator it = ms->maps.begin();
		     it != ms->maps.end(); ++it)
		    TheServer.engine.queryMapper.addRule(it->constr, it->label);
		TheServer.engine.queryMapper.nodeShare = ms->nodeShare;

		if (ms->primaryKey) TheServer.engine.pkAttribute = ms->primaryKey->getLexicalValue();
		TheServer.engine.keyMap = ms->keyMap;
		delete ms;
	    }

	    for (mapList::const_iterator it = Maps.begin(); it != Maps.end(); ++it) {
		sw::Operation* rule = parseQuery(*it);
		sw::Construct* c;
		if ((c = dynamic_cast<sw::Construct*>(rule)) == NULL)
		    throw std::string("Rule file ").append(": ").
			append((*it)->getLexicalValue()).
			append(" was not a SPARQL CONSTRUCT");
		TheServer.engine.queryMapper.addRule(c, *it);
		delete rule;
	    }

	    if (!ServerURI.empty()) {
		/* Act as a SPARQL server. */
		if (vm.count("stop-after"))
		    TheServer.engine.stopAfter = vm["stop-after"].as<unsigned int>();
		if (vm.count("stop"))
		    TheServer.stopCommand = vm["stop"].as<std::string>();
		if (vm.count("trap-sig-int"))
		    TheServer.set_trap_sig_int(vm["trap-sig-int"].as<bool>());

#if REGEX_LIB == SWOb_BOOST
		boost::regex re;
		boost::cmatch matches;

		re = "(?:(ftp|http|https):)?\\/\\/((?:\\w+\\.)*\\w*)(?::([0-9]+))?(.*)";
		if (!boost::regex_match(ServerURI.c_str(), matches, re)) {
		    std::cerr << "Address " << ServerURI << " is not a valid URL" << std::endl;
		    exit(1);
		}

#define PROT 1
#define HOST 2
#define PORT 3
#define PATH 4
		std::string serviceHost(matches[HOST].first, matches[HOST].second);
		std::string ports(matches[PORT].first, matches[PORT].second);
		int servicePort = ::atoi(ports.c_str());
		std::string servicePath = std::string(matches[PATH].first + 1, matches[PATH].second);
#else /* !REGEX_LIB == SWOb_BOOST */
		std::string serviceHost = "127.0.0.1";
		int servicePort = 8888;
		std::string servicePath = "SPARQL";
#endif /* !REGEX_LIB == SWOb_BOOST */

		sw::ChainedHandler handler;
		sw::SimpleInterface<sw::SimpleEngine, MyLoadList, MyServer>
		    // p3 is a controller, which, do to current limitations in
		    // web_server_asio, is the same as the server.
		    dynamicHandler(TheServer.engine, &TheServer, ServerURI, servicePath, ""); // "" is the interfacePath
		handler.add_handler(&dynamicHandler);
		sw::StaticHandler stat;
		stat.addContent("/favicon.ico", "image/x-icon", sizeof(favicon), (char*)favicon);
		handler.add_handler(&stat);

		TheServer.runServer(handler, ServerURI, serviceHost, servicePort, servicePath, vm.count("server-no-description") == 0);
	    }

	    // For operations which create a new database.
	    sw::RdfDB constructed(NULL, &TheServer.engine.xmlParser);

	    if (Query == NULL) {
		if (Maps.begin() != Maps.end())
		    throw std::string("Mapping rules found with no query to map.");
		TheServer.engine.resultSet.setRdfDB(&TheServer.engine.db);
	    } else {
		sw::Operation* query = parseQuery(Query);
		TheServer.engine.resultSet.setRdfDB(dynamic_cast<sw::Construct*>(query) != NULL && !TheServer.engine.inPlace ? &constructed : &TheServer.engine.db);

		std::string language; // not used here
		std::string finalQuery; // not used here

		// Painful hack to set aside the current engine state and use
		// the current values as of when the query was validated.
		const sw::TTerm* oldBaseUri = TheServer.engine.baseURI;
		sw::MediaType oldMediaType = TheServer.engine.dataMediaType;
		TheServer.engine.baseURI       = QueryBaseUri;
		TheServer.engine.dataMediaType = QueryMediaType;
		if (!TheServer.engine.executeQuery(query, TheServer.engine.resultSet, language, finalQuery))
		    Output.resource = NULL;
		delete query;
		TheServer.engine.baseURI = oldBaseUri;
		TheServer.engine.dataMediaType = oldMediaType;

	    }
	    {
		bool compareAsResultSet = vm.count("compare-as-result-set") != 0;
		if (vm.count("compare") || compareAsResultSet) {
		    std::string resrc = compareAsResultSet
			? vm["compare-as-result-set"].as<std::string>()
			: vm["compare"].as<std::string>();
		    const sw::TTerm* cmp = TheServer.engine.htparseWrapper(resrc, TheServer.engine.argBaseURI);
		    sw::IStreamContext iptr(cmp->getLexicalValue(), 
					    sw::IStreamContext::NONE, 
					    NULL, &TheServer.engine.webClient);
		    sw::RdfDB refDB(NULL, &TheServer.engine.xmlParser);
		    // sw::ResultSet reference(&TheServer.engine.atomFactory, &refDB);
		    sw::ResultSet reference(&TheServer.engine.atomFactory);
		    reference.setRdfDB(&refDB);
		    bool refIsResultSet = TheServer.engine.loadDataOrResults
			(NULL, // turtle and trig default graphs go into rdfDB's default graph.
			 cmp->getLexicalValue(), TheServer.engine.baseURI, iptr, reference, &refDB);

		    if (compareAsResultSet) // Comparing against an RDF representation of a result set.
			reference = sw::ResultSet(&TheServer.engine.atomFactory, reference.getRdfDB(), "");

		    if (TheServer.engine.resultSet == reference) {
			if (!Quiet)
			    std::cout << "matched\n";
			ret = 0;
		    } else {
			if (Quiet)
			    ret = 1;
			else
			    std::cout << TheServer.engine.resultSet << "!=\n" << reference << "\n";
		    }
//		    delete reference;
		    Output.resource = NULL; // No other output reqired.
		}
	    }
	    if (!Quiet && Output.resource != NULL) {
		std::string outres = Output.resource->getLexicalValue();
		sw::OStreamContext optr(outres, sw::OStreamContext::STDOUT,
					TheServer.engine.dataMediaType.c_str(),
					&TheServer.engine.webClient);
		bool mustDumpDb = Query == NULL && ResultSetsLoaded == false;
		if (!mustDumpDb && TheServer.engine.resultSet.resultType != sw::ResultSet::RESULT_Graphs && 
		    !TheServer.engine.dataMediaType)
		    optr.mediaType = "text/sparql-results";
		*optr << TheServer.engine.resultSet.toString(optr.mediaType.c_str(),
						      &TheServer.engine.nsAccumulator, mustDumpDb);
	    }
	    //std::cerr << NsAccumulator.toString(); // @@
	}
    } catch(std::exception& e) {
        std::cout << e.what() << "\n";
        ret = 2;
    } catch(std::string& e) {
        std::cout << e << "\n";
        ret = 2;
    }    

    return ret;
}

