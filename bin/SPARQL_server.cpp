/*

    This example illustrates the use of the HTTP extension to the server object 
    from the dlib C++ Library.
    It creates a server that always responds with a simple HTML form.

    To view the page this program displays you should go to http://localhost:5000

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>  //\_for strcmp
#include <string.h> ///
#if !_MSC_VER
  #include <unistd.h>
#endif /* !_MSC_VER */
#include "SWObjects.hpp"
#include "QueryMapper.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SQLizer.hpp"

#if HTTP_CLIENT == SWOb_ASIO
  #include "../interface/WEBagent_boostASIO.hpp"
#endif /* HTTP_CLIENT == SWOb_ASIO */

#if REGEX_LIB == SWOb_BOOST
  #include "boost/regex.hpp"
#endif

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
#endif

#if SQL_CLIENT == SWOb_MYSQL
  #include "../interface/SQLclient_MySQL.hpp"
#endif /* SQL_CLIENT == SWOb_MYSQL */

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
#elif XML_PARSER == SWOb_MSXML3
  #include "../interface/SAXparser_msxml3.hpp"
#else
  #ifdef _MSC_VER
    #pragma message ("unable to parse RDF/XML without an RDF parser")
  #else /* !_MSC_VER */
    #warning unable to parse RDF/XML without an RDF parser
  #endif /* !_MSC_VER */
#endif

#include "SPARQLSerializer.hpp"

//using namespace std;
using namespace w3c_sw;

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

struct MyServer : WEBSERVER { // w3c_sw::WEBserver_asio
    class MyHandler : public WebHandler {
	MyServer& server;

    public:
	MyHandler (MyServer& server) : 
	    WebHandler("."), // @@ docroot is irrelevant -- create a docserver
	    server(server)
	{  }
    protected:

	void executeQuery (std::ostringstream& sout, Operation* query, std::string queryStr, bool htmlResults) {
#if SQL_CLIENT == SWOb_DISABLED
	    std::ostringstream ret;
	    std::string finalQuery = queryStr;
	    std::string language = "SPARQL";
	    ResultSet rs(&posFactory);
	    query->execute(&db, &rs);
#else /* SQL_CLIENT != SWOb_DISABLED */

	    SPARQLSerializer s;
	    query->express(&s);
	    std::cout << s.str() << std::endl;
	    query->express(&server.queryMapper);
	    const Operation* mapped = server.queryMapper.last.operation;
	    delete query;

	    char predicateDelims[]={'#',' ',' '};
	    char nodeDelims[]={'/','.',' '};
	    SQLizer sqlizer(server.stemURI, predicateDelims, nodeDelims, server.pkAttribute, server.debugStream);
	    mapped->express(&sqlizer);

	    std::string finalQuery = sqlizer.getSQLstring();
	    std::string language = "SQL";

	    SQLclient_MySQL MySQLclient;
	    SQLclient* SQLclient(&MySQLclient);
	    SQLclient::Result* res;
	    try {
		SQLclient->connect(server.SQLServer, server.SQLDatabase, server.SQLUser);
		res = SQLclient->executeQuery(finalQuery);
	    }
	    catch (std::string ex) {
		std::cerr << ex << std::endl;
		throw SimpleMessageException(ex);
	    }
	    SqlResultSet rs(&server.posFactory, res);

	    std::ostringstream ret;

#endif /* SQL_CLIENT != SWOb_DISABLED */

	    const VariableVector cols = rs.getOrderedVars();

	    if (htmlResults) {
		head(ret, "Query Results");

		ret <<
		    "<h1>SPARQL Query</h1>\n"
		    "<pre>" << queryStr << "</pre>\n"
		    "<h1>" << language << " Query</h1>\n"
		    "<pre>" << finalQuery << "</pre>\n";
		char space[1024];
		sprintf(space, "<p>number of fields: %d</p>\n", cols.size());
		ret << space;

		ret << 
		    "    <table>\n"
		    "      <tr>";

		/* dump headers in <th/>s */
		for (VariableVector::const_iterator col = cols.begin();
		     col != cols.end(); ++col)
		    ret << "<th>" << (*col)->toString() << "</th>";
		ret << "</tr>\n";

		/* dump data in <td/>s */
		for (ResultSetConstIterator row = rs.begin(); row != rs.end(); ++row) { // !!! use iterator
		    ret << "      <tr>";
		    for (VariableVector::const_iterator col = cols.begin();
			 col != cols.end(); ++col) {
			const POS* val = (*row)->get(*col);
			if (val != NULL)
			    ret << "<td>" << val->toString() << "</td>";
			else
			    ret << "<td></td>";
		    }
		    ret << "</tr>";
		}
		ret << "    </table>";
		foot(ret);
	    } else { /* !htmlResults */
		ret << 
		    "<?xml version='1.0'?>\n"
		    "<sparql xmlns='http://www.w3.org/2005/sparql-results#'>\n"
		    "  <head>\n";

		/* dump headers in <th/>s */
		for (VariableVector::const_iterator col = cols.begin();
		     col != cols.end(); ++col)
		    ret << "    <variable name='" << (*col)->getLexicalValue() << "'/>\n";
		ret << "  </head>\n";
		ret << "  <results>\n";

		/* dump data in <td/>s */
		POS::BNode2string nodeMap;
		for (ResultSetConstIterator row = rs.begin(); row != rs.end(); ++row) { // !!! use iterator
		    ret << "    <result>\n";
		    for (BindingSetConstIterator binding = (*row)->begin(); binding != (*row)->end(); ++binding) {
			const POS* val = binding->second.pos;
			std::string lexval(XMLSerializer::escapeCharData(val->getLexicalValue()));

			ret << 
			    "      <binding name='" << binding->first->getLexicalValue() << "'>\n"
			    "        " << val->toXMLResults(&nodeMap) << "\n"
			    "      </binding>\n";
		    }
		    ret << "    </result>\n";
		}
		ret << 
		    "  </results>\n"
		    "</sparql>";
	    } /* !htmlResults */

	    sout << ret.str();
	    std::cout << ret.str() << std::endl;
	    ++server.served;
	    if (server.runOnce)
		server.done = true;
	}

	inline void handle_request (w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
	    std::string query;
	    try {
		std::string path(req.getPath());
		std::ostringstream sout;

		if (path == server.path) {
		    w3c_sw::webserver::request::parmmap::const_iterator it = req.parms.find("query");
		    if (it != req.parms.end())
			query = it->second;
		    if (query == "stop") {
			head(sout, "Done!");
			sout << "    <p>Served " << server.served << " queries.</p>\n";
			foot(sout);

			server.done = true;
		    } else {
			IStreamContext istr(query, IStreamContext::STRING);
			if (server.sparqlParser.parse(istr)) {
			    head(sout, "Query Error");

			    sout << "    <p>Query</p>\n"
				"    <pre>" << XMLSerializer::escapeCharData(query) << "</pre>\n"
				"    <p>is screwed up.</p>\n"
				 << std::endl;
			    std::cerr << "400: " << query << std::endl;
			    rep.status = webserver::reply::bad_request;

			    foot(sout);
			} else {
			    Operation* op = server.sparqlParser.root;
			    executeQuery(sout, op, query, false);
			    rep.status = webserver::reply::ok;
			    rep.addHeader("Content-Type", 
					  "application/sparql-results+xml; charset=UTF-8");
			}
		    }
		} else if (path == "/") {
		    rep.status = webserver::reply::ok;
		    head(sout, "Q&amp;D SPARQL Server");
		    sout << 
			"    <form action='" << server.path << "' method='get'>\n"
			"      Query: <textarea name='query' rows='25' cols='50'></textarea> <input type='submit' />\n"
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
		    rep.status = webserver::reply::not_found;

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
	    catch (SimpleMessageException& e)
		{
		    rep.status = webserver::reply::bad_request;
		    rep.addHeader("Content-Type", "text/html");
		    rep.content = e.what();
		}
	    catch (std::exception& e)
		{
		    std::string what(e.what());
		    std::ostringstream sout;

		    rep.status = webserver::reply::bad_request;
		    std::cerr << what << std::endl;
		    head(sout, "Q&amp;D SPARQL Server Error");
		    sout << 
			"    <pre>" << query << "</pre>\n"
			"    <p>yeilded</p>\n"
			"    <pre>" << what << "</pre>\n"; 
		    foot(sout);
		    rep.content = sout.str();
		}
	}

    };

    RdfDB db;
    bool runOnce;
    bool done;
    int served;
    std::string path;
    std::string stemURI;
    SPARQLfedDriver& sparqlParser;
    POSFactory& posFactory;
    std::string pkAttribute;
    QueryMapper queryMapper;
    std::string SQLServer;
    std::string SQLUser;
    std::string SQLDatabase;
    std::ostream**   debugStream;


#if HTTP_CLIENT != SWOb_DISABLED
    WEBagent_boostASIO client;
    #define pClient &client
#else /* HTTP_CLIENT == SWOb_DISABLED */
    #define pClient NULL
#endif /* HTTP_CLIENT == SWOb_DISABLED */
#if XML_PARSER != SWOb_DISABLED
    SAXPARSER p;
    #define pParser &p
#else /* XML_PARSER == SWOb_DISABLED */
    #define pParser NULL
#endif /* XML_PARSER == SWOb_DISABLED */

    MyServer (POSFactory& posFactory, SPARQLfedDriver& sparqlParser, std::string pkAttribute, std::ostream** debugStream = NULL)
	: db(pClient, pParser), runOnce(false), done(false), served(0), posFactory(posFactory), sparqlParser(sparqlParser), pkAttribute(pkAttribute), queryMapper(&posFactory, debugStream), debugStream(debugStream)
    {  }
    BasicGraphPattern* assureGraph (const POS* name) {
	return db.assureGraph(name);
    }
    void startServer (MyHandler& handler, const char* url, int serverPort) {
	std::ostringstream s;
	s << "http://localhost:" << serverPort << path;

	const URI* serviceURI = posFactory.getURI(s.str());
	BasicGraphPattern* serviceGraph = assureGraph(serviceURI);
	const URI* rdfType = posFactory.
	    getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");

	serviceGraph->addTriplePattern(posFactory.getTriple(
							    serviceURI, 
							    posFactory.getURI(std::string(NS_rdf)+"type"), 
							    posFactory.getURI(std::string(NS_sadl)+"Service")));
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
	    if (buf) {
		std::cout << "working directory: " << buf << std::endl;
		std::string base = std::string("file://localhost") + buf;
		serviceGraph->addTriplePattern(posFactory.getTriple(
								    serviceURI, 
								    posFactory.getURI(std::string(NS_sadl)+"base"), 
								    posFactory.getURI(base)));
	    }
	}

	std::stringstream tmpss;
	tmpss << serverPort;
	const char* bindMe = "0.0.0.0";
	serve(bindMe, tmpss.str().c_str(), (int)1 /* one thread */, handler);
    }

};

int main (int argc, char** argv) {
    POSFactory posFactory;
    SPARQLfedDriver sparqlParser("", &posFactory);
    std::ostream* debugStream = NULL;
    MyServer server(posFactory, sparqlParser, "ID", &debugStream);
    MyServer::MyHandler handler(server);

    int iArg = 1;
    if (argc > 1 && !::strcmp(argv[iArg], "--once")) {
	server.runOnce = true;
	++iArg;
    }

    if (argc - iArg < 1) {
	std::cerr << "Usage: " << argv[0] << "[--once] serverURL ruleMap.rq+" << std::endl;
	return 1;
    }

    const char* serverURI = argv[iArg++];

    try {

	/* Parse deduction rules. */
	for ( ; iArg < argc; ++iArg) {

	    /* Open stream from map file. */
	    std::ifstream dataStream(argv[iArg]);
	    if (!dataStream.is_open()) {
		std::string msg = std::string("failed to open map file \"") + argv[iArg] + "\".";
		throw msg;
	    }
	    /* Parse conf parameters. */
	    std::istreambuf_iterator<char> it(dataStream), end;
	    while (it != end) {
		std::string parm;
		while (it != end && (*it == ' '  || *it == '\r' ||
				     *it == '\n' || *it == '\t'))
		    ++it;
		/* Comment markers must be the first non-whitespace char. */
		if (it == end || *it == '#') {
		    while (it != end && *it != '\n')
			++it;
		    continue;
		}

		/* The parameter name is anything before the first ':'. */
		while (it != end && *it != ':')
		    parm += *it++;

		if (it == end)
		    break;
		++it;
		if (parm == "construct")
		    /* Pass on to the the SPARQL parser. */
		    break;

		/* The value is the rest of the line. */
		std::string value;
		while (it != end && (*it == ' '  || *it == '\r' ||
				     *it == '\n' || *it == '\t'))
		    ++it;
		while (it != end && *it != '\n')
		    value += *it++;

		/* Pull out known parameters. */
		if (parm == "server") {
		    server.SQLServer = value;
		} else if (parm == "user") {
		    server.SQLUser = value;
		} else if (parm == "database") {
		    server.SQLDatabase = value;
		} else if (parm == "stemURI") {
		    server.stemURI = value;
		} else if (parm == "primaryKey") {
		    server.pkAttribute = value;
		} else
		    /* Whine about unknown parameters. */
		    std::cout << "unknown parm: " << parm << " -- value: " << value << std::endl;
	    }

	    /* Remainder of file is a SPARQL query. */
	    IStreamContext istr(std::string(it, end), IStreamContext::STRING);
	    istr.nameStr = std::string(argv[iArg]) + " (post map:)";
	    sparqlParser.parse(istr);
	    dataStream.close();

	    Operation* rule = sparqlParser.root;
	    Construct* c;
	    if ((c = dynamic_cast<Construct*>(rule)) != NULL) {
		server.queryMapper.addRule(c);
		delete rule;
	    } else {
		std::cerr << "Rule file " << (server.queryMapper.getRuleCount() + 1) << ": " << argv[iArg] << " was not a SPARQL CONSTRUCT." << std::endl;
		return 1;
	    }
	}

	int serverPort = 8888;

#if REGEX_LIB == SWOb_BOOST
	boost::regex re;
	boost::cmatch matches;

	re = "(ftp|http|https):\\/\\/((?:\\w+\\.)*\\w*)(?::([0-9]+))?(.*)";
	if (!boost::regex_match(serverURI, matches, re)) {
	    std::cerr << "Address " << serverURI << " is not a valid URL" << std::endl;
	    exit(1);
	}

#define PROT 1
#define HOST 2
#define PORT 3
#define PATH 4
	std::string ports(matches[PORT].first, matches[PORT].second);
	std::istringstream portss(ports);
	portss >> serverPort;
	server.path = std::string(matches[PATH].first, matches[PATH].second);
#else /* !REGEX_LIB == SWOb_BOOST */
	server.path = "/SPARQL";
#endif /* !REGEX_LIB == SWOb_BOOST */

	server.startServer(handler, serverURI, serverPort);
	return 0;
    }
    catch (std::exception& e) {
	std::cerr << e.what() << std::endl;
    }
    catch (std::string& s) {
	std::cerr << s << std::endl;
    }
    return 1;
}

