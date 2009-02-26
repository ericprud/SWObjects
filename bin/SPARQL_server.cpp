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
#ifdef HAVE_REGEX
  #include "boost/regex.hpp"
#endif
#ifdef WIN32
  #include <mysql.h>
 #else
  #include <mysql/mysql.h>
#endif

#include "SWObjects.hpp"
#include "QueryMapper.hpp"
#include "SPARQLfedParser.hpp"
#include "SQLizer.hpp"

#include "SPARQLSerializer.hpp"

const char* SELECT_QUERY = "SELECT * FROM test";

#if HTTP_SERVER == DLIB
#include "dlib/server.h"
using namespace dlib;
#endif
using namespace std;
using namespace w3c_sw;

ostream* DebugStream = NULL;
string ServerPath = "/SPARQL";
int ServerPort = 8888;
string ServerTerminate;
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

	head(sout, "Q&D SPARQL Server Error");
	sout << 
	    "    <pre>" << msg << "</pre>\n";
	foot(sout);
	return sout.str();
    }
};

#if HTTP_SERVER == DLIB
class WebServer : public server::http_1a_c
{
    void executeQuery (ostringstream& sout, Operation* query, string queryStr) {
	SPARQLSerializer s;
	query->express(&s);
	cerr << s.getSPARQLstring() << endl;
	query->express(&queryMapper);
	const Operation* mapped = queryMapper.last.operation;
	delete query;

	char predicateDelims[]={'#',' ',' '};
	char nodeDelims[]={'/','.',' '};
	SQLizer sqlizer(StemURI, predicateDelims, nodeDelims, PkAttribute, &DebugStream);
	mapped->express(&sqlizer);

	MYSQL mysql,*sock;
	MYSQL_RES *result;
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql,Server.c_str(),User.c_str(),0,Database.c_str(),0,NULL,0)))
	    throw(SimpleMessageException("couldn't connect"));
	if (mysql_query(sock, sqlizer.getSQLstring().c_str()))
	    throw(SimpleMessageException("couldn't execute"));
	if (!(result=mysql_store_result(sock)))
	    throw(SimpleMessageException("couldn't get result"));

#if HTML_RESULTS
	head(sout, "Query Results");

	sout <<
	    "<h1>SPARQL Query</h1>\n"
	    "<pre>" << queryStr << "</pre>\n"
	    "<h1>SQL Query</h1>\n"
	    "<pre>" << sqlizer.getSQLstring() << "</pre>\n";
	char space[1024];
	sprintf(space, "<p>number of fields: %d</p>\n", mysql_num_fields(result));
	sout << space;

	int num_fields = mysql_num_fields(result);
	sout << 
	    "    <table>\n"
	    "      <tr>";

	/* dump headers in <th/>s */
	MYSQL_FIELD *field;
       	while((field = mysql_fetch_field(result)))
	    sout << "<th>" << field->name << "[" << field->type << "]</th>";
	sout << "</tr>\n";

	/* dump data in <td/>s */
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
	    unsigned long *lengths;
	    lengths = mysql_fetch_lengths(result);
	    sout << "      <tr>";
	    for(int i = 0; i < num_fields; i++) {
		sprintf(space, "[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
		sout << "<td>" << space << "</td>";
	    }
	    sout("</tr>");
	}
	sout << "    </table>";
	foot(sout);

#else /* !HTML_RESULTS */
	int num_fields = mysql_num_fields(result);
	sout << 
	    "<?xml version='1.0'?>\n"
	    "<sparql xmlns='http://www.w3.org/2005/sparql-results#'>\n"
	    "  <head>\n";

	/* dump headers in <th/>s */
	MYSQL_FIELD *field;
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	for(int i = 0; i < num_fields; i++)
	    sout << "    <variable name='" << fields[i].name << "'/>\n";
	sout << "  </head>\n";
	sout << "  <results>\n";

	/* dump data in <td/>s */
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
	    unsigned long *lengths;
	    lengths = mysql_fetch_lengths(result);
	    sout << "    <result>\n";
	    for(int i = 0; i < num_fields; i++)
		if (row[i])
		    sout << "      <binding name='" << fields[i].name << "'>\n"
			"        <literal>" << row[i] << "</literal>\n"
			"      </binding>\n";
	    sout << "    </result>\n";
	}
	sout << 
	    "  </results>\n"
	    "</sparql>";
#endif /* !HTML_RESULTS */

	++Served;
	if (RunOnce)
	    Done = true;
    }

    void on_request (
        const std::string& path,
        std::string& result,
        const map_type& queries,
        const map_type& cookies,
        queue_type& new_cookies,
        const map_type& incoming_headers,
        map_type& response_headers,
        const std::string& foreign_ip,
        const std::string& local_ip,
        unsigned short foreign_port,
        unsigned short local_port
    )
    {
        try {
            ostringstream sout;

	    if (path == ServerPath) {
		/* dlib doesn't use STL.  I don't know how to test
		   queries["action"] without throwing an exception
		   when it's not set.  So, I make all uses of this
		   function use exactly the same query parameters.
		 */
		if (queries["query"] == "stop") {
		    head(sout, "Done!");
		    sout << "    <p>Served " << Served << " queries.</p>\n";
		    foot(sout);

		    Done = true;
		} else if (sparqlParser.parse_string(queries["query"])) {
		    head(sout, "Query Error");

		    sout << "    <p>Query</p>\n"
			"    <pre>" << queries["query"] << "</pre>\n"
			"    <p>is screwed up.</p>\n"
			 << endl;
		    cerr << "500: " << queries["query"] << endl;

		    foot(sout);
		} else {
		    Operation* query = sparqlParser.root;
		    executeQuery(sout, query, queries["query"]);
		}
	    } else if (path != "/") {
		head(sout, "Not Found");

		sout << 
		    "    <p>path: " << path << "</p>\n"
		    "    <p>Try the <a href=\"/\">query interface</a>.</p>\n"
		     << endl;
		cerr << "404: " << path << endl;

		sout << "    <h2>Client Headers</h2>\n"
		    "    <ul>";
		// Why not dump the HTTP headers? Sure...
		incoming_headers.reset();
		while (incoming_headers.move_next())
		    sout << "      <li>" << incoming_headers.element().key() 
			 << ": " << incoming_headers.element().value() 
			 << "</li>\n" << endl;
		sout << "    </ul>\n" << endl;

		foot(sout);
	    } else {
		head(sout, "Q&D SPARQL Server");
		sout << 
		    "    <form action='" << ServerPath << "' method='get'>\n"
		    "      Query: <textarea name='query' rows='25' cols='50'></textarea> <input type='submit' />\n"
		    "    </form>\n"
		    "    <form action='" << ServerPath << "' method='post'>\n"
		    "      server status: running, " << Served << " served. <input name='query' type='submit' value='stop'/>\n"
		    "    </form>\n"; 
		foot(sout);
	    }
            result = sout.str();
        }
        catch (SimpleMessageException& e)
        {
	    result = e.what();
        }
        catch (exception& e)
        {
	    string query(queries["query"]);
	    string what(e.what());
            ostringstream sout;

            cerr << what << endl;
	    head(sout, "Q&D SPARQL Server Error");
	    sout << 
		"    <pre>" << query << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << what << "</pre>\n"; 
	    foot(sout);
            result = sout.str();
        }
    }

};
 #elif HTTP_SERVER == ASIO
  #error ASIO HTTP server not implemented
 #else
  #warning No HTTP server -- implementing fake server
struct WebServer {
    void start () {  }
    void clear () {  }
    void set_listening_port (int) {  }
};
struct thread_function  {
    thread_function ( void (*funct)() ) {  }
};
#endif /* HTTP_SERVER == DLIB */


// create an instance of our web server
WebServer TheServer;

void thread ()
{
#if DLIB_TIGHT_LOOP
    cout << "a POST to <" << ServerTerminate << "> with query=stop will terminate the server." << endl;
    while (!Done) dlib::sleep(1000);
    cout << "Done: served " << Served << " queries." << endl;
#else
    cout << "Press enter to end this program" << endl;
    cin.get();
#endif
    TheServer.clear();
}

void startServer (const char* url) {
#ifdef HAVE_REGEX
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
#else /* !HAVE_REGEX */
#endif /* !HAVE_REGEX */

    ostringstream s;
    s << "http://localhost:" << ServerPort << ServerPath;
    ServerTerminate = s.str();

    TheServer.set_listening_port(ServerPort);
    thread_function t(thread);
    TheServer.start();
}

int main (int argc, char** argv) {

    unsigned iArg = 1;
    if (argc > 1 && !::strcmp(argv[iArg], "--once")) {
	RunOnce = true;
	++iArg;
    }

    if (argc - iArg < 2) {
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
	    const std::string streamName = std::string(argv[iArg]) + " (post map:)";
	    sparqlParser.parse_string(std::string(it, end), streamName);
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
    }
    catch (exception& e) {
	cerr << e.what() << endl;
    }
    return 0;
}

