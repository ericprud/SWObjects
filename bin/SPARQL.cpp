/* Copyright Eric Prud'hommeaux 2009.
 * Distributed under the Apache Software License.
 * thanks to Vladimir Prus's boost:program_options examples.

 * $Id$ */

#include <iostream>
#include <fstream>
#include <iterator>

#ifndef TEST_CLI
#include "SWObjects.hpp"
namespace sw = w3c_sw;
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

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
  sw::SAXparser_libxml P;
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
  sw::SAXparser_expat P;
#elif XML_PARSER == SWOb_MSXML3
  #include "../interface/SAXparser_msxml3.hpp"
  sw::SAXparser_msxml3 P;
#else
  #warning DAWG tests require an XML parser
#endif

std::string UserName;
std::string PassWord;
#if HTTP_CLIENT == SWOb_ASIO
  #include "../interface/WEBagent_boostASIO.hpp"
  std::string basicAuthHeader (std::string username, std::string password) {
      return std::string("Authorization: Basic ")
	  + sw::SWWEBagent::base64encode(username + ":" + password)
	  + "\n";
  }
  sw::WEBagent_boostASIO::AuthHandler authHandler;
  std::string authHandler (std::string url, std::string realm) {
      std::cout << "GET " + url + " wants a stinkin' password for realm \"" + realm + "\"" << std::endl;
      std::cout << "username: "; std::string username; std::cin >> username;
      std::cout << "password: "; std::string password; std::cin >> password;
      return basicAuthHeader(username, password);
  }
  sw::WEBagent_boostASIO::AuthPreempt authPreempt;
  std::string authPreempt (std::string /* url */) {
      if (UserName.empty())
	  return "";
      return basicAuthHeader(UserName, PassWord);
  }
sw::WEBagent_boostASIO Agent(&authHandler, authPreempt);
#endif /* HTTP_CLIENT == SWOb_ASIO */
#endif /* !TEST_CLI */

#if HTTP_SERVER == SWOb_ASIO
 #include "../interface/WEBserver_asio.hpp"
#elif HTTP_SERVER == SWOb_DLIB
 #include "../interface/WEBserver_dlib.hpp"
#else
 #ifdef _MSC_VER
  #pragma message ("unable to serve HTTP without an HTTP server.")
 #else /* !_MSC_VER */
  #warning unable to serve HTTP without an HTTP server.
 #endif /* !_MSC_VER */
 #include "../interface/WEBserver_dummy.hpp"
#endif

#if SQL_CLIENT == SWOb_MYSQL
  #include "../interface/SQLclient_MySQL.hpp"
#endif /* SQL_CLIENT == SWOb_MYSQL */

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or include config.h manually) */
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#define VALIDATION_ERROR error
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <boost/regex.hpp>
#include <boost/iostreams/stream.hpp>
namespace io = boost::iostreams;


#if TEST_CLI
/* Simulate HTParse interface (with bogus results, but good enough for testing CLI). */
namespace sw {
    namespace libwww {
	typedef enum {PARSE_all} e_PARSE_opts;
	std::string HTParse (std::string name, const std::string* rel, e_PARSE_opts /* wanted */)
	{
	    std::string ret;
	    if (rel)
		ret = *rel;
	    return ret.append(name);
	}
    };
};
#endif

const sw::TTerm* CwdURI;
const sw::TTerm* BaseURI;
std::string BaseUriMessage () {
    return (BaseURI == NULL)
	? std::string(" with no base URI")
	: std::string(" with base URI ") + BaseURI->getLexicalValue();
}
std::string UriString (const sw::TTerm* uri) {
    return (uri == NULL)
	? ""
	: std::string(uri->getLexicalValue());
}

const sw::TTerm* ArgBaseURI;
bool NoExec = false;
int Debug = 0;
bool Quiet = false;
bool ResultSetsLoaded = false;
const sw::TTerm* NamedGraphName = NULL;
const sw::TTerm* Query; // URI is a guery ref; RDFLiteral is a query string.
typedef std::vector<const sw::TTerm*> mapList;
mapList Maps;
sw::MediaType DataMediaType;
std::map<std::string, std::string> HTTPHeaders;

#ifndef TEST_CLI
std::ostream* DebugStream = NULL;
sw::AtomFactory F;

#include <fstream>
#ifdef BOOST_PROCESS
#include <boost/process.hpp>
#endif /* BOOST_PROCESS */

std::string genTempFile (std::string dir, std::istream& istr) {
#ifdef _MSC_VER
    TCHAR buffer[MAX_PATH+1];
    DWORD len = ::GetTempPath(MAX_PATH, &buffer[0]);
               
    std::wstring directory(buffer, len);
    TCHAR prefix[] = TEXT("SWObj");

    if (!GetTempFileName(directory.c_str(), prefix, 0, buffer))
	throw ::GetLastError();

    size_t dlen(wcsnlen(directory.c_str(), MAX_PATH));
    size_t flen(wcsnlen(buffer, MAX_PATH));
    std::wstring file(buffer); // +dlen);

    std::string filename;
    for (std::wstring::const_iterator it = file.begin();
	 it != file.end(); ++it)
	filename += *it;
    int fileHandle = POSIX_open(filename.c_str(), POSIX_trunkwrite, POSIX_USER_RW);
#else /* !_MSC_VER */
    char buf[] = "SWObjXXXXXX";
    int fileHandle = mkstemp(buf);
    std::string filename(buf);
#endif /* !_MSC_VER */
    std::istreambuf_iterator<char> i(istr), e;
    std::string input(i, e);
    io::stream_buffer<sw::FileHandleDevice> ofs(fileHandle, filename);
    std::ostream os(&ofs);
    os << input;
    os.flush();
    ofs.close();
    POSIX_close(fileHandle);

    return filename;
}

class DBHandlers : public sw::RdfDB::HandlerSet {
    virtual bool parse(std::string mediaType, std::vector<std::string> args,
		       sw::BasicGraphPattern* target, sw::IStreamContext& istr,
		       std::string nameStr, std::string baseURI,
		       sw::AtomFactory* atomFactory, sw::NamespaceMap* nsMap);
};

DBHandlers  RdfDBHandlers;

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

	std::string CSS_common =
"code {\n"
"  font-weight: bold;\n"
"  }\n"
"\n"
"#query { \n"
"  border:1px solid #000;\n"
"  padding-left: 1em;\n"
"  background-color: #eee;\n"
"  font-size: smaller;\n"
"  }\n"
"\n"
	    ;
	std::string CSS_Results =
"#results {\n"
"  font-family:\"Trebuchet MS\", Arial, Helvetica, sans-serif;\n"
"  width:100%;\n"
"  border-collapse:collapse;\n"
"  }\n"
"#results td, #results th {\n"
"  font-size:1.2em;\n"
"  border:1px solid #98bf21;\n"
"  padding:3px 7px 2px 7px;\n"
"  }\n"
"#results th {\n"
"  font-size:1.4em;\n"
"  text-align:left;\n"
"  padding-top:5px;\n"
"  padding-bottom:4px;\n"
"  background-color:#A7C942;\n"
"  color:#fff;\n"
"  }\n"
"#results tr.even td {\n"
"  color:#000;\n"
"  background-color:#EAF2D3;\n"
"  }\n"
	    ;
	std::string Javascript_TableSorter_remote =
"    <link rel=\"stylesheet\" href=\"http://tablesorter.com/themes/blue/style.css\" type=\"text/css\" media=\"print, projection, screen\" />\n"
"    <script type=\"text/javascript\" src=\"http://tablesorter.com/jquery-latest.js\"></script>\n"
"    <script type=\"text/javascript\" src=\"http://tablesorter.com/jquery.tablesorter.js\"></script>\n"
	    ;
	std::string Javascript_ToggleDisplay_init =
"	toggleDisplay('query');\n"
"	var query = document.getElementById('query');\n"
"	var p = document.createElement('p');\n"
"	document.body.insertBefore(p, query);\n"
"	var input = document.createElement('input');\n"
"	input.setAttribute('type', 'checkbox');\n"
"	input.setAttribute('onclick', 'toggleDisplay(\"query\")');\n"
"	p.appendChild(input);\n"
"	p.appendChild(document.createTextNode(\" display query\"));\n"
	  ;
	std::string Javascript_TableSorter_init =
"	$(\"#results\").tablesorter({widgets: ['zebra']});\n"
	  ;
	std::string Javascript_ToggleDisplay_defn =
"    function toggleDisplay(element){\n"
"	s = document.getElementById(element).style\n"
"	if(s.display == 'none')\n"
"	    s.display = 'block';\n"
"	else\n"
"	    s.display = 'none';\n"
"    }\n"
	    ;

struct MyServer : WEBSERVER { // sw::WEBserver_asio
    class MyHandler : public sw::WebHandler {
	MyServer& server;

    public:
	MyHandler (MyServer& server) : 
	    WebHandler("."), // @@ docroot is irrelevant -- create a docserver
	    server(server)
	{  }
    protected:

	void handle_request(w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep);
	void errorMessage (w3c_sw::webserver::reply& rep, std::string query, std::string what) {
	    std::ostringstream sout;

	    rep.status = sw::webserver::reply::bad_request;
	    std::cerr << what << std::endl;
	    head(sout, "Q&amp;D SPARQL Server Error");
	    sout << 
		"    <pre>" << query << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << what << "</pre>\n"; 
	    foot(sout);
	    rep.content = sout.str();
	}
    };

    sw::RdfDB db;
    bool runOnce;
    bool done;
    int served;
    std::string path;
    std::string stemURI;
    std::string serviceURI;
    std::string defaultGraphURI;
    bool printQuery;
    sw::AtomFactory& atomFactory;
    sw::SPARQLfedDriver& sparqlParser;
    std::string pkAttribute;
    sw::KeyMap keyMap;
    sw::MapSetDriver mapSetParser;
    sw::ChainingMapper queryMapper;
    std::string SQLUser;
    std::string SQLPassword;
    std::string SQLServer;
    std::string SQLPort;
    std::string SQLDatabase;
    std::ostream**   debugStream;

    MyServer (sw::AtomFactory& atomFactory, sw::SPARQLfedDriver& sparqlParser,
	      std::string pkAttribute, std::ostream** debugStream = NULL)
	: db(&Agent, &P, debugStream, &RdfDBHandlers),
	  runOnce(false), done(false), served(0), stemURI(""),
	  serviceURI(""), defaultGraphURI(""),
	  printQuery(false), atomFactory(atomFactory), sparqlParser(sparqlParser),
	  pkAttribute(pkAttribute), mapSetParser("", &atomFactory), 
	  queryMapper(&atomFactory, debugStream), debugStream(debugStream)
    {  }
    sw::BasicGraphPattern* ensureGraph (const sw::TTerm* name) {
	return db.ensureGraph(name);
    }
    void startServer (MyHandler& handler, std::string url, int serverPort) {
	std::ostringstream s;
	s << "http://localhost:" << serverPort << path;

	const sw::URI* serviceURI = atomFactory.getURI(s.str());
	sw::BasicGraphPattern* serviceGraph = ensureGraph(serviceURI);
	serviceGraph->addTriplePattern(atomFactory.getTriple(
		    serviceURI, 
		    atomFactory.getURI(std::string(sw::NS_rdf)+"type"), 
		    atomFactory.getURI(std::string(sw::NS_sadl)+"Service")));
	{
	    char buf[1024];
	    buf[0] = 0;
#if _MSC_VER
	    TCHAR szDirectory[MAX_PATH];	
	    szDirectory[0] = 0;
	    if (::GetCurrentDirectory(sizeof(szDirectory) - 1, szDirectory)) {
		std::wstring wstr(szDirectory);
		size_t len = (int)wstr.length();
		std::string str = "\\";
		unsigned int i = 0;
		for (std::wstring::iterator it = wstr.begin();
		     i < len; ++it, ++i)
		    str += (char)*it;
		strncpy(buf, str.c_str(), sizeof(buf)-1);
	    }
#else /* !_MSV_VER */
	    getcwd(buf, sizeof(buf)-1);
#endif /* !_MSV_VER */
	    if (buf[0]) {
		std::cout << "Working directory: " << buf << " ." << std::endl;
		std::string base = std::string("file://localhost") + buf;
		serviceGraph->addTriplePattern(atomFactory.getTriple(
		    serviceURI, 
		    atomFactory.getURI(std::string(sw::NS_sadl)+"base"), 
		    atomFactory.getURI(base)));
	    }
	}

	std::stringstream tmpss;
	tmpss << serverPort;
	const char* bindMe = "0.0.0.0";
	try {
	    serve(bindMe, tmpss.str().c_str(), (int)1 /* one thread */, handler);
	} catch (boost::system::system_error e) {
	    throw std::string("Error binding ") + bindMe + ":" + tmpss.str().c_str() + ": " + e.what();
	}
    }

    std::string sqlConnectString () const {
	return SQLUser + ":" + SQLPassword + "@" + SQLServer + "/" + SQLDatabase;
    }

    bool executeQuery (const sw::Operation* query, sw::ResultSet& rs, std::string& language, std::string& finalQuery) {
	language = "SPARQL";
	const sw::Operation* delMe = rs.getConstrainedOperation(query);
	if (delMe != NULL)
	    query = delMe;

	if (queryMapper.getRuleCount() > 0) {
	    if (DebugStream != NULL)
		*DebugStream << "Transforming user query by applying " << queryMapper.getRuleCount() << " rule maps.\n";
	    const sw::Operation* transformed(queryMapper.map(query));
	    if (delMe != NULL)
		delete delMe;
	    query = delMe = transformed;
	}

	if (DebugStream != NULL) {
	    sw::SPARQLAlgebraSerializer s;
	    query->express(&s);
	    *DebugStream << "<Query_algebra>\n" << s.str() << "</Query_algebra>" << std::endl;
	}

	bool executed = false;
// 	if (rs.size() > 0 && (!serviceURI.empty() || !stemURI.empty())) {
// 	    const sw::Operation* t = rs.getConstrainedOperation (query);
// 	    if (t != NULL) {
// 		if (delMe != NULL)
// 		    delete delMe;
// 		query = delMe = t;
// 	    }
// 	}
	if (!stemURI.empty()) {
	    language = "SQL";
	    char predicateDelims[]={'#',' ',' '};
	    char nodeDelims[]={'/','.',' '};
	    sw::SQLizer sqlizer(stemURI, predicateDelims, nodeDelims, pkAttribute, keyMap, &DebugStream);
	    query->express(&sqlizer);
	    finalQuery = sqlizer.getSQLstring();

	    bool doSQLquery = !SQLServer.empty() || !SQLDatabase.empty() || !SQLUser.empty();
	    if (DebugStream != NULL)
		*DebugStream << "SQL: " << std::endl;
	    if (doSQLquery == false)
		std::cout << finalQuery << std::endl;
	    else if (DebugStream != NULL)
		*DebugStream << "SQL Query: " << finalQuery << std::endl;

#if SQL_CLIENT != SWOb_DISABLED
	    if (doSQLquery == true) {
		sw::SQLclient_MySQL MySQLclient;
		sw::SQLclient* SQLclient(&MySQLclient);
		sw::SQLclient::Result* res;
		try {
		    if (SQLPassword.empty())
			SQLclient->connect(SQLServer, SQLDatabase, SQLUser); // @@ wrap password with Optional to enable --password=''
		    else
			SQLclient->connect(SQLServer, SQLDatabase, SQLUser, SQLPassword);
		}
		catch (std::string ex) {
		    throw std::string("unable to connect to ") + sqlConnectString() + ": " + ex;
		}
		try {
		    res = SQLclient->executeQuery(finalQuery);
		}
		catch (std::string ex) {
		    throw ex + "\n" + sqlConnectString() + " was unable to execute " + finalQuery;
		}
		sw::SqlResultSet rs2(&atomFactory, res);
		rs.joinIn(&rs2);
		executed = true;
	    }
#endif /* SQL_CLIENT != SWOb_DISABLED */
	} else {
	    if (!serviceURI.empty()) {
		sw::SWWEBagent::ParameterList p;
		p.set("query", query->toString());
		if (!defaultGraphURI.empty())
		    p.set("default-graph-uri", defaultGraphURI);
		if (printQuery) {
		    if (DebugStream != NULL)
			*DebugStream << "Service query: " << std::endl;
		    std::cout << serviceURI << " " << p << std::endl;
		}
		if (NoExec == false) {
		    std::string s;
		    switch (sw::ServiceGraphPattern::defaultServiceProtocol) {
		    case sw::ServiceGraphPattern::HTTP_METHOD_GET:
			s = Agent.get(serviceURI.c_str(), p);
			break;
		    case sw::ServiceGraphPattern::HTTP_METHOD_POST:
			s = Agent.post(serviceURI.c_str(), p);
			break;
		    default:
			throw "program flow exception -- unknown defaultServiceProtocol";
		    }
		    sw::IStreamContext istr(s, sw::IStreamContext::STRING);
		    sw::ResultSet red(&F, &P, istr);
		    if (DebugStream != NULL)
			*DebugStream << " yielded\n" << red;

		    /* Join those results against our initial results. */
		    rs.joinIn(&red);
		    executed = true;
		}
	    } else {
		if (printQuery) {
		    if (DebugStream != NULL)
			*DebugStream << "Final query: " << ".\n";
		    std::cout << query->toString() << std::endl;
		}
		if (NoExec == false) {
		    query->execute(&db, &rs);
		    executed = true;
		}
	    }
	}
	if (delMe != NULL)
	    delete delMe;
	return executed;
    }
};

sw::SPARQLfedDriver SparqlParser("", &F);
sw::TurtleSDriver TurtleParser("", &F);
sw::ResultSet rs(&F);

MyServer TheServer(F, SparqlParser, "ID", &DebugStream);

struct loadEntry {
    const sw::TTerm* graphName;
    const sw::TTerm* resource;
    const sw::TTerm* baseURI;
    loadEntry (const sw::TTerm* graphName, const sw::TTerm* resource, const sw::TTerm* baseURI)
	: graphName(graphName), resource(resource), baseURI(baseURI) {  }
    void loadGraph () {
	const sw::TTerm* graph = graphName ? graphName : sw::DefaultGraph;
	std::string nameStr = resource->getLexicalValue();
	sw::IStreamContext istr(nameStr, sw::IStreamContext::STDIN, NULL, 
				&Agent, &DebugStream);
	if (istr.mediaType.match("application/sparql-results+xml")) {
	    if (DebugStream != NULL) {
		*DebugStream << "Reading SPARQL XML Result Set " << nameStr;
		if (baseURI != NULL)
		    *DebugStream << " with base URI <" << BaseURI->getLexicalValue() << ">";
		*DebugStream << " into result set.\n";
	    }
	    sw::ResultSet loaded(&F, &P, istr);
	    rs.joinIn(&loaded);
	    ResultSetsLoaded = true;
	} else if (istr.mediaType.match("text/sparql-results")) {
	    if (DebugStream != NULL) {
		*DebugStream << "Reading data table " << nameStr;
		if (baseURI != NULL)
		    *DebugStream << " with base URI <" << BaseURI->getLexicalValue() << ">";
		*DebugStream << " into result set.\n";
	    }
	    sw::TTerm::String2BNode bnodeMap;
	    sw::ResultSet loaded(&F, istr, false, bnodeMap);
	    rs.joinIn(&loaded);
	    ResultSetsLoaded = true;
	} else {
	    if (DebugStream != NULL) {
		*DebugStream << "Reading " << nameStr;
		if (baseURI != NULL)
		    *DebugStream << " with base URI <" << BaseURI->getLexicalValue() << ">";
		*DebugStream << " into " << graph->toString() << ".\n";
	    }
	    TheServer.db.loadData(TheServer.db.ensureGraph(graph), istr, UriString(baseURI), 
			baseURI ? UriString(baseURI) : nameStr, &F);
	}
    }
};
typedef std::vector<loadEntry> loadList;

const sw::TTerm* htparseWrapper(std::string s, const sw::TTerm* base) {
    std::string baseURIstring = base ? base->getLexicalValue() : "";
    std::string t = libwww::HTParse(s, &baseURIstring, libwww::PARSE_all); // !! maybe with PARSE_less ?
    return F.getURI(t.c_str());
}

inline void MyServer::MyHandler::handle_request (w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
    std::string query;
    try {
	std::string path(req.getPath());
	std::ostringstream sout;
	loadList queryLoadList;

	if (path == server.path) {
	    w3c_sw::webserver::request::parmmap::const_iterator parm;
	    parm = req.parms.find("default-graph-uri");
	    if (parm != req.parms.end() && parm->second != "") {
		const sw::TTerm* abs(htparseWrapper(parm->second, ArgBaseURI));
		queryLoadList.push_back(loadEntry(NULL, abs, BaseURI));
		std::cerr << "default graph: " << parm->second << std::endl;
	    }
	    parm = req.parms.find("named-graph-uri");
	    while (parm != req.parms.end() && parm->first == "namedGraph" && parm->second != "") {
		const sw::TTerm* abs(htparseWrapper(parm->second, ArgBaseURI));
		queryLoadList.push_back(loadEntry(abs, abs, BaseURI));
		std::cerr << "named graph: " << parm->second << std::endl;
		++parm;
	    }
	    parm = req.parms.find("query");
	    if (parm != req.parms.end())
		query = parm->second;
	    if (query == "stop") {
		head(sout, "Done!");
		sout << "    <p>Served " << server.served << " queries.</p>\n";
		foot(sout);

		server.done = true;
	    } else {
		sw::IStreamContext istr(query, sw::IStreamContext::STRING);
		try {
		    sw::Operation* op = server.sparqlParser.parse(istr);
		    if (op == NULL) { // @@@ i think this can't be reached; that is, return NULL would entail having thrown an exception.
			head(sout, "Query Error");

			sout << "    <p>Query</p>\n"
			    "    <pre>" << sw::XMLSerializer::escapeCharData(query) << "</pre>\n"
			    "    <p>is screwed up.</p>\n"
			     << std::endl;
			std::cerr << "400: " << query << std::endl;
			rep.status = sw::webserver::reply::bad_request;

			foot(sout);
		    } else {
			sw::ResultSet rs(&server.atomFactory);
			std::string language;
			std::string newQuery(query);

			try {
			    for (loadList::iterator it = queryLoadList.begin();
				 it != queryLoadList.end(); ++it)
				it->loadGraph();

			    server.executeQuery(op, rs, language, newQuery);
			    delete op;
			} catch (sw::ParserException& ex) {
			    delete op;
			    std::cerr << ex.what() << std::endl;
			    throw sw::WebHandler::SimpleMessageException(ex);
			} catch (std::string ex) {
			    delete op;
			    std::cerr << ex << std::endl;
			    throw sw::WebHandler::SimpleMessageException(sw::XMLSerializer::escapeCharData(ex));
			}
			const sw::VariableVector cols = rs.getOrderedVars();

			sw::XMLSerializer xml("  ");
			parm = req.parms.find("media");
			if (parm != req.parms.end()
			    && (parm->second == "html"
				|| parm->second == "tablesorter")) {
			    std::string headStr =
"    <style type=\"text/css\" media=\"screen\">\n"
"/*<![CDATA[*/\n" + CSS_common
				;
			    if (parm->second == "html")
				headStr += CSS_Results;
			    headStr +=
"/*]]>*/\n"
"    </style>\n"
"\n"
				;
			    if (parm->second == "tablesorter")
				headStr += Javascript_TableSorter_remote;
			    headStr +=
"    <script language=\"javascript\" type=\"text/javascript\">\n"
"<!--\n"
				;
			    if (parm->second == "tablesorter")
				headStr +=
"    $(function() {\n"
				    ;
			    else
				headStr +=
"    window.onload=function(){\n"
				    ;
			    headStr += Javascript_ToggleDisplay_init;
				
			    if (parm->second == "tablesorter")
				headStr += Javascript_TableSorter_init;
			    if (parm->second == "tablesorter")
				headStr +=
"    });\n"
				    ;
			    else
				headStr +=
"    };\n"
				    ;
			    headStr += Javascript_ToggleDisplay_defn +
"-->\n"
"    </script>\n"
				;
			    head(sout, "SPARQL Query Results", headStr);

			    /** construct XHTML body with query and results. */
			    sw::XMLSerializer::Attributes queryAttrs;
			    queryAttrs["id"] = "query";
			    queryAttrs["style"] = "display:block;";
			    xml.leaf("pre", newQuery, queryAttrs);

			    sw::XMLSerializer::Attributes resultsAttrs;
			    resultsAttrs["id"] = "results";
			    resultsAttrs["class"] = "tablesorter";
			    rs.toHtmlTable(&xml, resultsAttrs);

			    /** construct reply from headers and XHTML body */
			    rep.status = sw::webserver::reply::ok;
			    rep.addHeader("Content-Type", 
					  "text/html; charset=UTF-8");
			    sout << xml.str();
			    foot(sout);

			} else if (parm != req.parms.end() && parm->second == "textplain") {
			    head(sout, "SPARQL Query Results");

			    // cute lexical representation of xml nesting:
			    xml.leaf("pre", newQuery);
			    rep.status = sw::webserver::reply::ok;
			    rep.addHeader("Content-Type", 
					  "text/html; charset=UTF-8");

			    sw::XMLSerializer rsSerializer("  ");
			    rs.toXml(&rsSerializer);
			    std::string source(rsSerializer.str());
			    xml.leaf("pre", rsSerializer.str());

			    sout << xml.str();
			    foot(sout);
			} else { /* !htmlResults */
			    rep.status = sw::webserver::reply::ok;
			    rep.addHeader("Content-Type", 
					  "application/sparql-results+xml; charset=UTF-8");
			    rs.toXml(&xml);
			    sout << xml.str();
			} /* !htmlResults */

			if (server.debugStream != NULL && *server.debugStream != NULL)
			    **server.debugStream << sout.str() << std::endl;
			++server.served;
			if (server.runOnce)
			    server.done = true;
		    }
		} catch (sw::ParserException& ex) {
		    std::cerr << ex.what() << std::endl;
		    throw sw::WebHandler::SimpleMessageException(ex);
		}
	    }
	} else if (path == "/") {
	    rep.status = sw::webserver::reply::ok;
	    head(sout, "Q&amp;D SPARQL Server");
	    const char* method =
		sw::ServiceGraphPattern::defaultServiceProtocol == sw::ServiceGraphPattern::HTTP_METHOD_GET ? "get" :
		"post";
	    sout << 
		"    <form action='" << server.path << "' method='" << method << "'>\n"
		"      Query: <textarea name='query' rows='25' cols='80'></textarea> <input type='submit' /><br />\n"
		"      default graph: <input type='text' name='default-graph-uri' size='50' /><br />\n"
		"      named graph:   <input type='text' name=  'named-graph-uri' size='50' /><br />\n"
		"      named graph:   <input type='text' name=  'named-graph-uri' size='50' /><br />\n"
		"      <input type='radio' name='media' value='xmlres' />SPARQL XML Results\n"
		"      <input type='radio' name='media' value='html' checked='checked' />HTML Results\n"
		"      <input type='radio' name='media' value='tablesorter' />JQuery Tablesorter\n"
		"      <input type='radio' name='media' value='textplain' />SPARQL XML Results in text/html\n"
		"    </form>\n"
		"    <form action='" << server.path << "' method='post'>\n"
		"      server status: running, " << server.served << " served. <input name='query' type='submit' value='stop'/>\n"
		"    </form>\n"; 
	    rep.addHeader("Content-Type", "text/html");
	    foot(sout);
	} else if (path == "/favicon.ico") {
	    sout.write((char*)favicon, sizeof(favicon));
	    rep.addHeader("Content-Type", "image/x-icon");
	} else {
	    head(sout, "Not Found");

	    sout << 
		"    <p>path: " << path << "</p>\n"
		"    <p>Try the <a href=\"/\">query interface</a>.</p>\n"
		 << std::endl;
	    std::cerr << "404: " << path << std::endl;
	    rep.status = sw::webserver::reply::not_found;

	    sout << "    <h2>Client Headers</h2>\n"
		"    <ul>";
	    // Why not dump the HTTP headers? Sure...
	    for (w3c_sw::webserver::request::headerset::const_iterator it = req.headers.begin();
		 it != req.headers.end(); ++it)
		sout << "      <li>" << it->name 
		     << ": " << it->value 
		     << "</li>\n" << std::endl;
	    sout << "    </ul>\n" << std::endl;

	    foot(sout);
	}
	rep.content = sout.str();
    }
    catch (SimpleMessageException& e) {
	rep.status = sw::webserver::reply::bad_request;
	rep.addHeader("Content-Type", "text/html");
	rep.content = e.what();
    } catch (std::exception& e) {
	errorMessage(rep, query, e.what());
    } catch (std::string& e) {
	errorMessage(rep, query, e);
    }
}

bool DBHandlers::parse (std::string mediaType, std::vector<std::string> args,
			sw::BasicGraphPattern* target, sw::IStreamContext& istr,
			std::string nameStr, std::string baseURI,
			sw::AtomFactory* atomFactory, sw::NamespaceMap* nsMap) {
    if (mediaType == "application/x-grddl") {
	const char* env = ::getenv("XSLT");
	if (env == NULL)
	    return sw::RdfDB::HandlerSet::parse(mediaType, args,
						target, istr,
						nameStr, baseURI,
						atomFactory, nsMap);

	// break up $XSLT
	std::vector<std::string> tokens;
	{
	    std::string buf;
	    std::stringstream ss(env);
	    while (ss >> buf)
		tokens.push_back(buf);
	}

	std::vector<std::string> createdFiles;
	for (std::vector<std::string>::iterator iToken = tokens.begin();
	     iToken != tokens.end(); ++iToken) {
	    if (*iToken == "%DATA") {
		*iToken = genTempFile(".", *istr);
		createdFiles.push_back(*iToken);
	    } else if (*iToken == "%STYLESHEET") {
		sw::IStreamContext xsltIstr(args[0], sw::IStreamContext::NONE, NULL, 
					    &Agent, &DebugStream);
		*iToken = genTempFile(".", *xsltIstr);
		createdFiles.push_back(*iToken);
	    }
	}

#ifdef BOOST_PROCESS
	std::string exec = $tokens[0]; // "/usr/bin/xsltproc"; // POSIX_cat;

	namespace bp = ::boost::process; 

	bp::context ctx;
	ctx.stdout_behavior = bp::capture_stream();
	bp::child c = bp::launch(exec, tokens, ctx);
	bp::pistream &pis = c.get_stdout();
#else /* !BOOST_PROCESS */
	std::stringstream cmd;
	for (std::vector<std::string>::const_iterator iToken = tokens.begin();
	     iToken != tokens.end(); ++iToken) {
	    if (iToken != tokens.begin())
		cmd << " ";
	    cmd << *iToken;
	}
	if (DebugStream != NULL)
	    *DebugStream << "Executing \"" << cmd.str().c_str() << "\".\n";
	FILE *p = POSIX_popen(cmd.str().c_str(), "r"); // 
	assert(p != NULL);
	char buf[100];
	std::string s  = "execution failure";
	s = "";

	/* Gave up on [[ ferror(p) ]] because it sometimes returns EPERM on OSX.
	 */
	for (size_t count; (count = fread(buf, 1, sizeof(buf), p)) || !feof(p);)
	    s += std::string(buf, buf + count);
	POSIX_pclose(p);
	std::stringstream pis(s);
#endif /* !BOOST_PROCESS */
	for (std::vector<std::string>::const_iterator iCreatedFile = createdFiles.begin();
	     iCreatedFile != createdFiles.end(); ++iCreatedFile)
	    if (POSIX_unlink(iCreatedFile->c_str()) != 0)
		std::cerr << "error unlinking " << *iCreatedFile << ": " << strerror(errno);
	sw::IStreamContext istr2(istr.nameStr, pis, "application/rdf+xml");
	return TheServer.db.loadData(target, istr2, nameStr, baseURI, atomFactory, nsMap);
    } else
	return sw::RdfDB::HandlerSet::parse(mediaType, args,
					    target, istr,
					    nameStr, baseURI,
					    atomFactory, nsMap);
}

class NamespaceAccumulator : public sw::NamespaceMap {
public:
    std::string toString (const char* mediaType = NULL) {
	std::stringstream sstr;
	if (mediaType == NULL)
	    for (sw::NamespaceMap::const_iterator it = begin();
		 it != end(); ++it)
		sstr << it->first << "=> " << it->second->toString() << "\n";
	return sstr.str();
    }
};
class NamespaceRelay : public sw::NamespaceMap {
    sw::NamespaceMap& relay;
public:
    NamespaceRelay (sw::NamespaceMap& relay) : relay(relay) {  }
    virtual void set (std::string prefix, const sw::URI* uri) {
	sw::NamespaceMap::set(prefix, uri);
	relay.set(prefix, uri);
    }
};

// std::ostream& operator<< (std::ostream& os, sw::NamespaceMap map) {
//     return os << map->toString();
// }

NamespaceAccumulator NsAccumulator;
NamespaceRelay NsRelay(NsAccumulator);

loadList LoadList;
loadList MapList;
loadEntry Output(NULL, NULL, NULL);
bool InPlace = false;

#endif /* TEST_CLI */

/* Set Debug when parsed. */
struct debugLevel { };
void validate (boost::any& v, const std::vector<std::string>& values, debugLevel*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    std::stringstream stream(s);
    int i;
    stream >> i;
    Debug = i;
    DebugStream = (i > 0) ? &std::cerr : NULL;
    v = boost::any(debugLevel());
    if (DebugStream != NULL)
	*DebugStream << "Debug level: " << Debug << ".\n";
}

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
    Query = F.getRDFLiteral(s);
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

/* Set DataMediaType when parsed. */
struct langName { };
void validate (boost::any&, const std::vector<std::string>& values, langName*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!s.compare("?")) {
	std::cout << "data language options: \"\", guess, ntriples, turtle, trig, rdfa, rdfxml, sparqlx";
    } else {
	if (!s.compare(""))
	    DataMediaType = "";
	else if (!s.compare("guess"))
	    DataMediaType = "text/plain";
	else if (!s.compare("ntriples"))
	    DataMediaType = "text/ntriples";
	else if (!s.compare("turtle"))
	    DataMediaType = "text/turtle";
	else if (!s.compare("trig"))
	    DataMediaType = "text/trig";
	else if (!s.compare("rdfa") || !s.compare("html"))
	    DataMediaType = "text/html";
	else if (!s.compare("rdfxml"))
	    DataMediaType = "application/rdf+xml";
	else if (!s.compare("sparqlx"))
	    DataMediaType = "application/sparql-results+xml";
	else {
	    throw boost::program_options::VALIDATION_ERROR(std::string("invalid value: \"").append(s).append("\""));
	}
	if (DebugStream != NULL) {
	    if (!DataMediaType)
		*DebugStream << "Using no data language mediatype.\n";
	    else
		*DebugStream << "Using data language mediatype " << *DataMediaType << ".\n";
	}
    }
}
struct langType { };
void validate (boost::any&, const std::vector<std::string>& values, langType*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!s.compare("?")) {
	std::cout << "data mediatype options: \"\", text/plain, text/ntriples, text/turtle, text/trig, text/html, application/rdf+xml, application/sparql-results+xml";
    } else {
	if (!Quiet && s.compare("") && s.compare("text/plain")
	    && s.compare("text/ntriples") && s.compare("text/turtle")
	    && s.compare("text/trig") && s.compare("text/html")
	    && s.compare("application/rdf+xml")
	    && s.compare("application/sparql-results+xml"))
	    std::cerr << "proceeding with unknown media type \"" << s << "\"";
	    // throw boost::program_options::VALIDATION_ERROR(std::string("invalid value: \"").append(s).append("\""));
	DataMediaType = s;
	if (DebugStream != NULL) {
	    if (!DataMediaType)
		*DebugStream << "Using no data mediatype mediatype.\n";
	    else
		*DebugStream << "Using data mediatype mediatype " << *DataMediaType << ".\n";
	}
    }
}

void validateBase(const std::vector<std::string>& values, const sw::TTerm** setMe, const sw::TTerm* copySource, const char* argName) {
    const std::string& s = po::validators::get_single_string(values);
    if (s == "?") {
	std::cout << argName << "URI: " << (*setMe ? (*setMe)->getLexicalValue() : "\"\"") << "\n";
    } else {
	*setMe = 
	    (s == ".") ? CwdURI : 
	    (s == ":") ? copySource : 
	    htparseWrapper(s, *setMe);
	if (DebugStream != NULL)
	    *DebugStream << "Setting " << argName << " URI to " << (*setMe)->getLexicalValue() << ".\n";
    }
}

/* Base class for all relative URI arguments. */
struct relURI {};

/* Overload of relURI to validate --base arguments. */
struct baseURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, baseURI*, int)
{
    validateBase(values, &BaseURI, ArgBaseURI, "base");
    SparqlParser.setBase(BaseURI->getLexicalValue());
}

/* Overload of relURI to validate --arg-base arguments. */
struct argBaseURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, argBaseURI*, int)
{
    validateBase(values, &ArgBaseURI, BaseURI, "argument base");
}

/* Overload of relURI to validate --output arguments. */
struct outPut : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, outPut*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* abs(htparseWrapper(s, ArgBaseURI));
    Output = loadEntry(NULL, abs, BaseURI);
    if (DebugStream != NULL)
	*DebugStream << "Sending output to " << abs->getLexicalValue() << BaseUriMessage() << ".\n";
}

/* Overload of relURI to validate --in-place arguments. */
struct inPlace : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, inPlace*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (s == ".") {
	InPlace = true;
	if (DebugStream != NULL)
	    *DebugStream << "Manipulating other input data.\n";
    } else {
	const sw::TTerm* abs(htparseWrapper(s, ArgBaseURI));
	LoadList.push_back(loadEntry(NULL, abs, BaseURI));
	Output = loadEntry(NULL, abs, BaseURI);
	if (DebugStream != NULL) {
	    *DebugStream << "Replacing data from " << abs->getLexicalValue();
	    if (BaseURI != NULL)
		*DebugStream << " with base URI " << BaseURI->getLexicalValue() << ".\n";
	}
    }
}

/* Overload of relURI to validate --data arguments. */
struct dataURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, dataURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* abs(htparseWrapper(s, ArgBaseURI));
    LoadList.push_back(loadEntry(NULL, abs, BaseURI));
    if (DebugStream != NULL) {
	*DebugStream << "Queued reading default data from " << abs->getLexicalValue();
	if (BaseURI != NULL)
	    *DebugStream << " with base URI " << BaseURI->getLexicalValue();
	*DebugStream << ".\n";
    }
}

/* Overload of relURI to validate --mapset arguments. */
struct mapURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, mapURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* abs(htparseWrapper(s, ArgBaseURI));
    MapList.push_back(loadEntry(NULL, abs, BaseURI));
    if (DebugStream != NULL) {
	*DebugStream << "Queued reading default map from " << abs->getLexicalValue();
	if (BaseURI != NULL)
	    *DebugStream << " with base URI " << BaseURI->getLexicalValue();
	*DebugStream << ".\n";
    }
}

/* Overload of relURI to validate --mapstring arguments. */
struct mapString {};
void validate (boost::any&, const std::vector<std::string>& values, mapString*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    MapList.push_back(loadEntry(NULL, F.getRDFLiteral(s), BaseURI));
    if (DebugStream != NULL) {
	*DebugStream << "Queued reading default map from command line";
	if (BaseURI != NULL)
	    *DebugStream << " with base URI " << BaseURI->getLexicalValue();
	*DebugStream << ".\n";
    }
}

/* Overload of relURI to validate --graph arguments. */
struct graphURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, graphURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    NamedGraphName = s == "." ? F.getURI(".") : htparseWrapper(s, ArgBaseURI);
}

/* Overload of relURI to validate --graph 2nd args, query and map arguments. */
struct orderedURI : public relURI {};
void validate (boost::any&, const std::vector<std::string>& values, orderedURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    const sw::TTerm* vald = htparseWrapper(s, ArgBaseURI);
    if (NamedGraphName != NULL) {
	if (NamedGraphName->getLexicalValue() == ".")
	    NamedGraphName = vald;
	LoadList.push_back(loadEntry(NamedGraphName, vald, BaseURI));
	if (DebugStream != NULL)
	    *DebugStream << "Reading named graph " << NamedGraphName->toString()
		      << " from " << vald->getLexicalValue()
		      << BaseUriMessage() << ".\n";
	NamedGraphName = NULL;
    } else if (Query == NULL && ServerURI.empty()) {
	if (DebugStream != NULL)
	    *DebugStream << "Query resource: " << vald->getLexicalValue() << ".\n";
	Query = vald;
    } else {
	if (DebugStream != NULL)
	    *DebugStream << "View: " << vald->getLexicalValue() << ".\n";
	Maps.push_back(vald);
    }
}

/* Set UserName when parsed. */
struct userName {};
void validate (boost::any&, const std::vector<std::string>& values, userName*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    UserName = s;
}
/* Set Password when parsed. */
struct passWord {};
void validate (boost::any&, const std::vector<std::string>& values, passWord*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    PassWord = s;
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
    const std::string& s = po::validators::get_single_string(values);
    const boost::regex odbcPattern("^([^:]+)://"	// 1: protocol ://
				   "(?:"		//    [
				   "([^:]+)"		// 2:   user
				   "(?::([^@]+))?"	// 3:   [ : password ]
				   "@)?"		//    @ ]
				   "([^:]+)"		// 4: host
				   "(?::([0-9]+))?"	// 5: [ port ]
				   "/(.+)$");		// 6: database
    boost::cmatch matches;
    if (boost::regex_match(s.c_str(), matches, odbcPattern)) {
	if (matches[1] != "mysql")
	    throw std::string("only mysql SQL service is currently supported -- saw ") + matches[1];
	if (matches[2].matched)
	    TheServer.SQLUser = matches[2];
	if (matches[3].matched)
	    TheServer.SQLPassword = matches[3];
	TheServer.SQLServer = matches[4];
	if (matches[5].matched)
	    TheServer.SQLPort = matches[5];
	TheServer.SQLDatabase = matches[6];
    } else { 
	throw boost::program_options::VALIDATION_ERROR(s + " did not match expression " + odbcPattern.str());
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
    sw::IStreamContext iptr(querySpec, opts, NULL, &Agent, &DebugStream);
    try {
	return SparqlParser.parse(iptr);
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
    MyServer::MyHandler handler(TheServer);
    Output = loadEntry(NULL, F.getURI("-"), NULL);

    int ret = 0; /* no errors */
    sw::BoxChars::GBoxChars = &sw::BoxChars::AsciiBoxChars;
    try {
	CwdURI = 
	    F.getURI(std::string("file://localhost")
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
	     "debugging level")
            ("DbDebugEnumerateLimit", po::value<size_t>(),
	     "max number of triples to serialize in debug stream")
            ("ResultSetDebugEnumerateLimit", po::value<size_t>(),
	     "max number of results to serialize in debug stream")
            ("no-exec,n", "don't execute (or load data)")
            ("pipe,p", "pipe query to output (print final query)")
            ("quiet,q", "quiet")
            ("version,v", "print version string")
	    ;

	/* rest: cli appends cfg file. */

        po::options_description resultsOpts("");
        resultsOpts.add_options()
            ("ascii,a", "output ASCII-only")
            ("utf-8,8", "output utf-8")
            ("bold", "output bold-bordered utf-8 boxes")
            ("nullterm,0", "terminate lines with \0")
            ("compare", po::value<std::string>(), 
	     "compare to some expected results.")
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
            ("language-name,l", po::value<langName>(), 
	     "data language\n\"guess\" to guess by resource extension, or \"-\" for stdin")
            ("lang-media-type,L", po::value<langType>(), 
	     "data language\n\"guess\" to guess by resource extension, or \"-\" for stdin")
            ("output,o", po::value<outPut>(), 
	     "send results to relURI or \"-\" for stdout.")
            ("in-place,i", po::value<inPlace>(), 
	     "update arg with the results.\n\"-\" to read from stdin and write to stdout, \".\" manipulate input graphs.")
            ("description,D", 
	     "read application description graph (see section) into default graph.")
            ("desc-graph,G", po::value<std::vector <std::string> >(), 
	     "read application description graph into graph arg.")
            ("service", po::value<std::string>(), 
	     "relay all queries to service URL.")
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
            ("once", "SPARQL server handles one request.")
            ("post", "use POST (while GET is obviously superior) for SPARQL services.")
            ;

        po::options_description sqlOpts("SQL options");
        sqlOpts.add_options()
            ("stem", po::value<std::string>(), 
	     "stem URL.")
#if REGEX_LIB != SWOb_DISABLED
            ("sql-service,S", po::value<sqlService>(), 
	     "odbc-style SQL database\n\tdriver://[username[:password]@]host[:port]/database\nmysql://localhost/orders")
#endif /* REGEX_LIB != SWOb_DISABLED */
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
            ("ordered", po::value<orderedURI>(), "URIs")
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
        
        po::variables_map vm;
	po::store(po::command_line_parser(ac, av).
              options(cmdline_options).positional(p).run(), vm);

	std::ifstream ifs(".SPARQL.cfg");
	po::store(parse_config_file(ifs, config_file_options), vm);
	po::notify(vm);
    
        if (vm.count("utf-8")) {
	    if (DebugStream != NULL)
		*DebugStream << "Switching to utf-8.\n";
	    sw::BoxChars::GBoxChars = &sw::BoxChars::Utf8BoxChars;
        }

        if (vm.count("ascii")) {
	    if (DebugStream != NULL)
		*DebugStream << "Switching to ASCII.\n";
	    sw::BoxChars::GBoxChars = &sw::BoxChars::AsciiBoxChars;
        }

        if (vm.count("bold")) {
	    if (DebugStream != NULL)
		*DebugStream << "Switching to bold-bordered boxes.\n";
	    sw::BoxChars::GBoxChars = &sw::BoxChars::Utf8BldChars;
        }

        if (vm.count("no-exec")) {
	    if (DebugStream != NULL)
		*DebugStream << "Execution suppressed.\n";
            NoExec = true;
        }

        if (vm.count("quiet")) {
	    if (DebugStream != NULL)
		*DebugStream << "Non-debug messages supressed.\n";
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
            "        doap:homepage <http://swobj.org/SPARQL/v1> ;\n"
            "        doap:shortdesc \"a semantic web query toolbox\" .\n";
	static const char* tutorial = 
	    "Tutorial:\n"
	    "  The SPARQL Query Language matches patterns of Semantic Web data. This SPARQL\n"
	    "  executable allows you to aggregate and query Semantic Web resources. To\n"
	    "  introduce this, the SPARQL executable contains a short description of itself,\n"
	    "  with the following assertions:\n"
	    "    SPARQL is a doap project.\n"
	    "    SPARQL has a homepage http://swobj.org/SPARQL/v1 .\n"
	    "    SPARQL is \"a Semantic Web query toolbox\".\n"
	    "  The SPARQL program starts with an empty database. You can load the above\n"
	    "  description (-D) and display it with \"SPARQL -D\":\n"
	    "{\n"
	    "  <> <http://...-rdf-syntax-ns#type> <http://usefulinc.com/ns/doap#Project> .\n"
	    "  <> <http://...#homepage> <http://swobj.org/SPARQL/v1> .\n"
	    "  <> <http://...#shortdesc> \"a semantic web query toolbox\"  .\n"
	    "}\n"
	    "  Because you supplied no query, SPARQL showed the contents of the loaded\n"
	    "  database. The default database output format is TriG, as specified at\n"
	    "    http://www4.wiwiss.fu-berlin.de/bizer/TriG/\n"
	    "\n"
	    "  You can query for all the triples:\n"
	    "    SPARQL -D -e \"SELECT ?s ?p ?o WHERE {?s ?p ?o}\"\n"
	    "  , giving resuls like:\n"
	    " +----+-------------------------------+----------------------------------------+\n"
	    " | ?s | ?p                            | ?o                                     |\n"
	    " | <> | <http://www.w3....ax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
	    " | <> |           <http...p#homepage> |           <http://swobj.org/SPARQL/v1> |\n"
	    " | <> |          <http:...#shortdesc> |         \"a semantic web query toolbox\" |\n"
	    " +----+-------------------------------+----------------------------------------+\n"
	    "\n"
	    "  -D loaded the three assertions into the \"default graph\", the graph to which\n"
	    "  SPARQL queries are directed unless otherwise directed by GRAPH clause. To try\n"
	    "  a GRAPH clause, load the description into the graph foo and query that graph:\n"
	    "    SPARQL -G foo -e \"SELECT ?s ?p ?o WHERE { GRAPH <foo> { ?s ?p ?o } }\"\n"
	    "\n"
	    "  We can load the description into a couple graphs *and* the default graph and\n"
	    "  ask all of the graphs which include an assertion about a doap project:\n"
	    "    SPARQL -a -DG foo -G foo2 -e \"SELECT ?g {\n"
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
	    "    ./SPARQL -a -DG foo -G foo2 -e \"SELECT ?g {\n"
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

        if (vm.count("help")) {
            std::cout << 
		"Usage: SPARQL [opts] queryURI mapURI*\n"
		"       SPARQL [opts] -e query mapURI*\n"
		"       SPARQL [opts] --server URL mapURI*\n\n"
		"get started with: SPARQL --Help tutorial\n" << 
		queryHelp << cursory;
            NoExec = true;
        }

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
			<< "SPARQL will \"guess\" that data from ’-’ is trig and output is either a table or trig.\n\n"
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
            NoExec = true;
        }


        if (vm.count("version"))
            std::cout << "SPARQL version 1.0, revision: $Id$\n";
	else {
	    if (NoExec == false) {
		if (vm.count("description")) {
		    sw::IStreamContext s(appDescGraph, sw::IStreamContext::STRING);
		    s.mediaType = "text/turtle";
		    TheServer.db.loadData(TheServer.db.ensureGraph(sw::DefaultGraph), s, UriString(BaseURI), UriString(BaseURI), &F, &NsRelay);
		}

		if (vm.count("desc-graph")) {
		    std::vector<std::string> descs(vm["desc-graph"].as< std::vector<std::string> >());
		    for (std::vector<std::string>::const_iterator it = descs.begin();
			 it != descs.end(); ++it) {
			sw::IStreamContext s(appDescGraph, sw::IStreamContext::STRING);
			s.mediaType = "text/turtle";
			TheServer.db.loadData(TheServer.db.ensureGraph(F.getURI(*it)), s, UriString(BaseURI), UriString(BaseURI), &F);
		    }
		}

		for (loadList::iterator it = LoadList.begin();
		     it != LoadList.end(); ++it)
		    it->loadGraph();

		if (vm.count("DbDebugEnumerateLimit"))
		    sw::RdfDB::DebugEnumerateLimit = vm["DbDebugEnumerateLimit"].as<size_t>();
		if (vm.count("ResultSetDebugEnumerateLimit"))
		    sw::ResultSet::DebugEnumerateLimit = vm["ResultSetDebugEnumerateLimit"].as<size_t>();

		if (DebugStream != NULL) {
		    size_t size = TheServer.db.size();
		    if (size > sw::RdfDB::DebugEnumerateLimit) {
			size_t graphCount = TheServer.db.getGraphNames().size();
			*DebugStream << "Loaded " << size
				     << " triple" << (size == 1 ? "" : "s")
				     << " into "
				     << graphCount << " graph" << (graphCount == 1 ? "" : "s")
				     << ".\n";
		    } else
			*DebugStream << "<loadedData>\n" << TheServer.db << "</loadedData>\n";
		}
	    }

	    if (vm.count("stem"))
		TheServer.stemURI = vm["stem"].as<std::string>();
	    if (vm.count("service"))
		TheServer.serviceURI = vm["service"].as<std::string>();
	    if (vm.count("default-graph-uri"))
		TheServer.defaultGraphURI = vm["default-graph-uri"].as<std::string>();
	    if (vm.count("pipe"))
		TheServer.printQuery = true;

	    for (loadList::iterator it = MapList.begin();
		 it != MapList.end(); ++it) {
		std::string nameStr = it->resource->getLexicalValue();
		sw::IStreamContext::e_opts opts = 
		    (dynamic_cast<const sw::RDFLiteral*>(it->resource) != NULL) ? 
		    sw::IStreamContext::STRING : 
		    sw::IStreamContext::STDIN;
		sw::IStreamContext istr(nameStr, opts, NULL, &Agent, &DebugStream);
		if (TheServer.mapSetParser.parse(istr) != 0)
		    throw std::string("error when parsing map ").append(nameStr);
		sw::MapSet* ms = dynamic_cast<sw::MapSet*>(TheServer.mapSetParser.root);
		if (ms->server) TheServer.SQLServer = ms->server->getLexicalValue();
		if (ms->user) TheServer.SQLUser = ms->user->getLexicalValue();
		if (ms->password) TheServer.SQLPassword = ms->password->getLexicalValue();
		if (ms->database) TheServer.SQLDatabase = ms->database->getLexicalValue();
		if (ms->stemURI) TheServer.stemURI = ms->stemURI->getLexicalValue();
		TheServer.queryMapper.sharedVars = ms->sharedVars;
		for (sw::MapSet::ConstructList::const_iterator it = ms->maps.begin();
		     it != ms->maps.end(); ++it)
		    TheServer.queryMapper.addRule(it->constr, it->label);
		TheServer.queryMapper.nodeShare = ms->nodeShare;

		if (ms->primaryKey) TheServer.pkAttribute = ms->primaryKey->getLexicalValue();
		TheServer.keyMap = ms->keyMap;
		delete ms;
	    }

	    for (mapList::const_iterator it = Maps.begin(); it != Maps.end(); ++it) {
		sw::Operation* rule = parseQuery(*it);
		sw::Construct* c;
		if ((c = dynamic_cast<sw::Construct*>(rule)) == NULL)
		    throw std::string("Rule file ").append(": ").
			append((*it)->getLexicalValue()).
			append(" was not a SPARQL CONSTRUCT");
		TheServer.queryMapper.addRule(c, *it);
		delete rule;
	    }

	    if (!ServerURI.empty()) {
		/* Act as a SPARQL server. */
		if (vm.count("once"))
		    TheServer.runOnce = true;
		if (vm.count("post"))
		    sw::ServiceGraphPattern::defaultServiceProtocol = sw::ServiceGraphPattern::HTTP_METHOD_POST;
		int serverPort = 8888;

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
		std::string ports(matches[PORT].first, matches[PORT].second);
		std::istringstream portss(ports);
		portss >> serverPort;
		TheServer.path = std::string(matches[PATH].first, matches[PATH].second);
#else /* !REGEX_LIB == SWOb_BOOST */
		TheServer.path = "/SPARQL";
#endif /* !REGEX_LIB == SWOb_BOOST */

		TheServer.startServer(handler, ServerURI, serverPort);
	    }

	    sw::RdfDB constructed; // For operations which create a new database.

	    if (Query == NULL) {
		if (Maps.begin() != Maps.end())
		    throw std::string("Mapping rules found with no query to map.");
		rs.setRdfDB(&TheServer.db);
	    } else {
		sw::Operation* query = parseQuery(Query);
		rs.setRdfDB(dynamic_cast<sw::Construct*>(query) != NULL && !InPlace ? &constructed : &TheServer.db);

		std::string language; // not used here
		std::string finalQuery; // not used here
		if (!TheServer.executeQuery(query, rs, language, finalQuery))
		    Output.resource = NULL;
		delete query;

		if (vm.count("compare")) {
		    const sw::TTerm* cmp = htparseWrapper(vm["compare"].as<std::string>(), ArgBaseURI);
		    sw::IStreamContext iptr(cmp->getLexicalValue(), 
					    sw::IStreamContext::NONE, 
					    NULL, &Agent, &DebugStream);

		    sw::ResultSet* reference;
		    if (iptr.mediaType.match("application/sparql-results+xml")) {
			reference = new sw::ResultSet(&F, &P, iptr);
		    } else if (iptr.mediaType.match("text/sparql-results")) {
			sw::TTerm::String2BNode str2b;
			reference = new sw::ResultSet(&F, iptr, false, str2b);
		    } else {
			sw::RdfDB resGraph;
			if (iptr.mediaType.match("text/ntriples") || 
			    iptr.mediaType.match("text/turtle")) {
			    TurtleParser.setGraph(resGraph.ensureGraph(NULL));
			    TurtleParser.parse(iptr);
			    TurtleParser.clear("");
			} else {
			    throw std::string("media-type \"").append(iptr.mediaType.toString()).append("\" unknown.");
			}
			reference = 
			    rs.resultType == sw::ResultSet::RESULT_Graphs ?
			    new sw::ResultSet(&F, &resGraph) :
			    new sw::ResultSet(&F, &resGraph, "");
		    }
		    if (rs == *reference) {
			if (!Quiet)
			    std::cout << "matched\n";
			ret = 0;
		    } else {
			if (Quiet)
			    ret = 1;
			else
			    std::cout << rs << "!=\n" << *reference << "\n";
		    }
		    delete reference;
		    Output.resource = NULL; // No other output reqired.
		}
	    }
	    if (!Quiet && Output.resource != NULL) {
		std::string outres = Output.resource->getLexicalValue();
		sw::OStreamContext optr(outres, sw::OStreamContext::STDOUT,
					DataMediaType.c_str(),
					&Agent, &DebugStream);
		bool mustDumpDb = Query == NULL && ResultSetsLoaded == false;
		if (!mustDumpDb && rs.resultType != sw::ResultSet::RESULT_Graphs && 
		    !DataMediaType)
		    optr.mediaType = "text/sparql-results";
		*optr << rs.toString(optr.mediaType.c_str(),
				     &NsAccumulator, mustDumpDb);
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

