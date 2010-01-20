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

const char* SELECT_QUERY = "SELECT * FROM test";

using namespace std;
using namespace w3c_sw;

ostream* DebugStream = NULL;
string ServerPath = "/SPARQL";
int ServerPort = 8888;
string ServiceURLstr;
const char* ServerURI;
std::string StemURI;
POSFactory posFactory;
SPARQLfedDriver sparqlParser("", &posFactory);
QueryMapper queryMapper(&posFactory, &DebugStream);
bool RunOnce = false;
bool Done = false;
int Served = 0;
std::string Server;
std::string User;
std::string Database;
std::string PkAttribute;

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

void head (ostringstream& sout, string title) {
    sout << 
	"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n"
	"          \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
	"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
	"  <head>\n"
	"    <title>" << title << "</title>\n"
	"  </head>\n"
	"  <body>\n"
	"    <h1>" << title << "</h1>\n";
}
void foot (ostringstream& sout) {
    sout << "  </body>\n</html>\n";
}

struct SimpleMessageException : public StringException {
    SimpleMessageException (string msg) : StringException(make(msg)) {  }
    string make (string msg) {
	ostringstream sout;

	head(sout, "Q&amp;D SPARQL Server Error");
	sout << 
	    "    <pre>" << msg << "</pre>\n";
	foot(sout);
	return sout.str();
    }
};

#if SQL_CLIENT == SWOb_MYSQL
class SqlResultSet : public ResultSet {
public:
    SqlResultSet (POSFactory* posFactory, SQLclient::Result* res) : ResultSet(posFactory) {
	erase(begin());
	SQLclient::Result::ColumnSet cols = res->cols();
	std::vector<const POS*> vars;

	/* dump headers in <th/>s */
	for (SQLclient::Result::ColumnSet::const_iterator it = cols.begin();
	     it != cols.end(); ++it)
	    vars.push_back(posFactory->getVariable(it->name));

	knownVars.insert(vars.begin(), vars.end());

	SQLclient::Result::Row row;
	while ((row = res->nextRow()) != res->end()) { // !!! use iterator
	    Result* result = new Result(this);
	    for(size_t i = 0; i < cols.size(); i++)
		if (row[i].size() > 0) {
		    std::string dt = SQLclient::Result::Field::typeNames[cols[i].type];
		    std::string lexval(row[i]);
		    if (cols[i].type == SQLclient::Result::Field::TYPE__err || 
			cols[i].type == SQLclient::Result::Field::TYPE__unknown)
			throw std::string("field value \"") + lexval + "\" has unknown datatype";// + cols[i].type;

		    if (cols[i].type != SQLclient::Result::Field::TYPE__null) {
			const URI* dtpos = dt.size() > 0 ? posFactory->getURI(dt.c_str()) : NULL;
			const POS* val = posFactory->getRDFLiteral(lexval, dtpos, NULL);
			set(result, vars[i], val, false);
		    }
		}
	    insert(end(), result);
	}
    }
};
#endif /* SQL_CLIENT == SWOb_MYSQL */

struct MyServer : WEBSERVER { // w3c_sw::WEBserver_asio
    RdfDB db;
    bool runOnce;

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

    MyServer () : db(pClient, pParser) {  }
    BasicGraphPattern* assureGraph (const POS* name) {
	return db.assureGraph(name);
    }
};

class MyHandler : public w3c_sw::webserver::request_handler {
    MyServer& server;

public:
    MyHandler (MyServer& server) : 
	w3c_sw::webserver::request_handler("."), // @@ docroot is irrelevant -- create a docserver
	server(server)
    {  }
protected:

    /* wholesale import of stuff from dlib-17.11/dlib/server/server_http_1.h
     * in order to provide control over the status message.
     */
        unsigned char to_hex (
            unsigned char ch
        ) const
        {
            if (ch <= '9' && ch >= '0')
                ch -= '0';
            else if (ch <= 'f' && ch >= 'a')
                ch -= 'a' - 10;
            else if (ch <= 'F' && ch >= 'A')
                ch -= 'A' - 10;
            else 
                ch = 0;
            return ch;
        }
        const std::string decode_query_string (
            const std::string& str
        ) const
        {
            using namespace std;
            string result;
            string::size_type i;
            for (i = 0; i < str.size(); ++i)
            {
                if (str[i] == '+')
                {
                    result += ' ';
                }
                else if (str[i] == '%' && str.size() > i+2)
                {
                    const unsigned char ch1 = to_hex(str[i+1]);
                    const unsigned char ch2 = to_hex(str[i+2]);
                    const unsigned char ch = (ch1 << 4) | ch2;
                    result += ch;
                    i += 2;
                }
                else
                {
                    result += str[i];
                }
            }
            return result;
        }

    static std::string escapeHTML (std::string escapeMe) {
	std::string ret;
	for (size_t p = ret.find_first_of("&<>"); 
	     p != std::string::npos; p = ret.find_first_of("&<>", p + 1))
	    ret.replace(p, 1, 
			   ret[p] == '&' ? "&amp;" : 
			   ret[p] == '<' ? "&lt;" : 
			   ret[p] == '>' ? "&gt;" : "huh??");
	return ret;
    }


    void executeQuery (ostringstream& sout, Operation* query, string queryStr, bool htmlResults) {
#if SQL_CLIENT == SWOb_DISABLED
	ostringstream ret;
	string finalQuery = queryStr;
	string language = "SPARQL";
	ResultSet rs(&posFactory);
	query->execute(&db, &rs);
#else /* SQL_CLIENT != SWOb_DISABLED */

	SPARQLSerializer s;
	query->express(&s);
	cout << s.str() << endl;
	query->express(&queryMapper);
	const Operation* mapped = queryMapper.last.operation;
	delete query;

	char predicateDelims[]={'#',' ',' '};
	char nodeDelims[]={'/','.',' '};
	SQLizer sqlizer(StemURI, predicateDelims, nodeDelims, PkAttribute, &DebugStream);
	mapped->express(&sqlizer);

	string finalQuery = sqlizer.getSQLstring();
	string language = "SQL";

	SQLclient_MySQL MySQLclient;
	SQLclient* SQLclient(&MySQLclient);
	SQLclient::Result* res;
	try {
	    SQLclient->connect(Server, Database, User);
	    res = SQLclient->executeQuery(finalQuery);
	}
	catch (std::string ex) {
	    std::cerr << ex << std::endl;
	    throw SimpleMessageException(ex);
	}
	SqlResultSet rs(&posFactory, res);

	ostringstream ret;

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
		    std::string lexval(escapeHTML(val->getLexicalValue()));

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
	cout << ret.str() << endl;
	++Served;
	if (RunOnce)
	    Done = true;
    }

    inline void handle_request (w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
	string query;
        try {
	    std::string path(req.getPath());
            ostringstream sout;

	    if (path == ServerPath) {
		w3c_sw::webserver::request::parmmap::const_iterator it = req.parms.find("query");
		if (it != req.parms.end())
		    query = it->second;
		if (query == "stop") {
		    head(sout, "Done!");
		    sout << "    <p>Served " << Served << " queries.</p>\n";
		    foot(sout);

		    Done = true;
		} else {
		    IStreamContext istr(query, IStreamContext::STRING);
		    if (sparqlParser.parse(istr)) {
			head(sout, "Query Error");

			sout << "    <p>Query</p>\n"
			    "    <pre>" << escapeHTML(query) << "</pre>\n"
			    "    <p>is screwed up.</p>\n"
			     << endl;
			cerr << "400: " << query << endl;
			rep.status = webserver::reply::bad_request;

			foot(sout);
		    } else {
			Operation* op = sparqlParser.root;
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
		    "    <form action='" << ServerPath << "' method='get'>\n"
		    "      Query: <textarea name='query' rows='25' cols='50'></textarea> <input type='submit' />\n"
		    "    </form>\n"
		    "    <form action='" << ServerPath << "' method='post'>\n"
		    "      server status: running, " << Served << " served. <input name='query' type='submit' value='stop'/>\n"
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
		     << endl;
		cerr << "404: " << path << endl;
		rep.status = webserver::reply::not_found;

		sout << "    <h2>Client Headers</h2>\n"
		    "    <ul>";
		// Why not dump the HTTP headers? Sure...
		for (w3c_sw::webserver::request::headerset::const_iterator it = req.headers.begin();
		     it != req.headers.end(); ++it)
		    sout << "      <li>" << it->name 
			 << ": " << it->value 
			 << "</li>\n" << endl;
		sout << "    </ul>\n" << endl;

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
        catch (exception& e)
        {
	    string what(e.what());
            ostringstream sout;

	    rep.status = webserver::reply::bad_request;
            cerr << what << endl;
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

MyServer TheServer;
MyHandler TheHandler(TheServer);

void startServer (const char* url) {
#if REGEX_LIB == SWOb_BOOST
    boost::regex re;
    boost::cmatch matches;

    re = "(ftp|http|https):\\/\\/((?:\\w+\\.)*\\w*)(?::([0-9]+))?(.*)";
    if (!boost::regex_match(url, matches, re)) {
	cerr << "Address " << url << " is not a valid URL" << endl;
	exit(1);
    }

#define PROT 1
#define HOST 2
#define PORT 3
#define PATH 4
    string ports(matches[PORT].first, matches[PORT].second);
    istringstream portss(ports);
    portss >> ServerPort;
    ServerPath = string(matches[PATH].first, matches[PATH].second);
#else /* !REGEX_LIB == SWOb_BOOST */
#endif /* !REGEX_LIB == SWOb_BOOST */

    ostringstream s;
    s << "http://localhost:" << ServerPort << ServerPath;
    ServiceURLstr = s.str();

    const URI* serviceURI = posFactory.getURI(ServiceURLstr);
    BasicGraphPattern* serviceGraph = TheServer.assureGraph(serviceURI);
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
	    cout << "working directory: " << buf << endl;
	    std::string base = std::string("file://localhost") + buf;
	    serviceGraph->addTriplePattern(posFactory.getTriple(
			   serviceURI, 
			   posFactory.getURI(std::string(NS_sadl)+"base"), 
			   posFactory.getURI(base)));
	}
    }

    std::stringstream tmpss;
    tmpss << ServerPort;
    const char* bindMe = "0.0.0.0";
    TheServer.serve(bindMe, tmpss.str().c_str(), (int)1 /* one thread */, TheHandler);
}

int main (int argc, char** argv) {

    int iArg = 1;
    if (argc > 1 && !::strcmp(argv[iArg], "--once")) {
	RunOnce = true;
	++iArg;
    }

    if (argc - iArg < 1) {
	cerr << "Usage: " << argv[0] << "[--once] serverURL ruleMap.rq+" << endl;
	return 1;
    }

    ServerURI = argv[iArg++];

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
		    Server = value;
		} else if (parm == "user") {
		    User = value;
		} else if (parm == "database") {
		    Database = value;
		} else if (parm == "stemURI") {
		    StemURI = value;
		} else if (parm == "primaryKey") {
		    PkAttribute = value;
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
		queryMapper.addRule(c);
		delete rule;
	    } else {
		cerr << "Rule file " << (queryMapper.getRuleCount() + 1) << ": " << argv[iArg] << " was not a SPARQL CONSTRUCT." << endl;
		return 1;
	    }
	}

	startServer(ServerURI);
	return 0;
    }
    catch (exception& e) {
	cerr << e.what() << endl;
    }
    catch (std::string& s) {
	cerr << s << endl;
    }
    return 1;
}

