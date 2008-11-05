/*

    This example illustrates the use of the HTTP extension to the server object 
    from the dlib C++ Library.
    It creates a server that always responds with a simple HTML form.

    To view the page this program displays you should go to http://localhost:5000

*/

#include <iostream>
#include <sstream>
#include <string>
#include "boost/regex.hpp"
#include "dlib/server.h"
#include <mysql/mysql.h>

#include "SWObjects.hpp"
#include "QueryMapper.hpp"
#include "SPARQLfedParser.hpp"
#include "SQLizer.hpp"

#include "SPARQLSerializer.hpp"

using namespace dlib;
using namespace std;
using namespace w3c_sw;

ostream* DebugStream = NULL;
string SPARQL_path;
string StemURI;
POSFactory posFactory;
SPARQLfedDriver sparqlParser("", &posFactory);
QueryMapper queryMapper(&posFactory, &DebugStream);

class WebServer : public server::http_1a_c
{
    void head (ostringstream& sout, string title) {
	sout << 
	    "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n"
	    "          \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
	    "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
	    "  <head>\n"
	    "    <title>" << title << "</title>\n"
	    "  </head>\n"
	    "  <body>\n";
    }
    void foot (ostringstream& sout) {
	sout << "  </body>\n</html>\n";
    }
    void executeQuery (ostringstream& sout, Operation* query, string queryStr) {
	head(sout, "Query Results");

	SPARQLSerializer s;
	query->express(&s);
	cerr << s.getSPARQLstring() << endl;
	query->express(&queryMapper);
	Operation* mapped = queryMapper.getCopy();
	delete query;

	char predicateDelims[]={'#',' ',' '};
	char nodeDelims[]={'/','.',' '};
	SQLizer sqlizer(StemURI, predicateDelims, nodeDelims, &DebugStream);
	mapped->express(&sqlizer);
	sout <<
	    "<h1>SPARQL Query</h1>\n"
	    "<pre>" << queryStr << "</pre>\n"
	    "<h1>SQL Query</h1>\n"
	    "<pre>" << sqlizer.getSQLstring() << "</pre>\n";

	MYSQL mysql,*sock;
	MYSQL_RES *res;
	if (!(sock = mysql_real_connect(&mysql,NULL,"root",0,"DiabeticPatientsDataSet",0,NULL,0)))
	    perror("connect");
	else {
	    if (mysql_query(sock, sqlizer.getSQLstring().c_str()))
		sout << "<p>query</p>" << endl;
	    else {
		char space[1024];
		if (!(res=mysql_store_result(sock))) {
		    sprintf(space,"Couldn't get result from %s\n",
			    mysql_error(sock));
		    sout << space;
		} else {
		    sprintf(space, "<p>number of fields: %d</p>\n",mysql_num_fields(res));
		    sout << space;
		}
	    }
	}
	

	foot(sout);
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
        try
        {
            ostringstream sout;

	    if (path == SPARQL_path) {
		if (sparqlParser.parse_string(queries["query"])) {
		    head(sout, "Query Error");

		    sout << "    <h1>Query Error</h1>\n"
			"    <p>Query</p>\n"
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

		sout << "    <h1>Not Found</h1>\n"
		    "    <p>path: " << path << "</p>\n"
		    "    <p>Try the <a href=\"/\">query interface</a>.</p>\n"
		     << endl;
		cerr << "404: " << path << endl;

		sout << "    <h2>Client Headers</h2>\n"
		    "    <ul>";
		// Echo out all the HTTP headers we received from the client web browser
		incoming_headers.reset();
		while (incoming_headers.move_next())
		    sout << "      <li>" << incoming_headers.element().key() << ": " << incoming_headers.element().value() << "</li>\n" << endl;
		sout << "    </ul>\n" << endl;

		foot(sout);
	    } else {
		head(sout, "Q&D SPARQL Server");

		sout << "    <h1>SPARQL Query Interface</h1>\n"
		    "    <form action='" << SPARQL_path << "' method='get'>\n"
		    "      Query: <textarea name='query' rows='25' cols='50'></textarea> <input type='submit' />\n"
		    "    </form>\n"; 

		foot(sout);
	    }
            result = sout.str();
        }
        catch (exception& e)
        {
	    string query(queries["query"]);
	    string what(e.what());
            ostringstream sout;

            cerr << what << endl;
	    head(sout, "Q&D SPARQL Server Error");
	    sout << "    <h1>Q&D SPARQL Server Error</h1>\n"
		"    <pre>" << query << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << what << "</pre>\n"; 
	    foot(sout);
            result = sout.str();
        }
    }

};

// create an instance of our web server
WebServer TheServer;

void thread ()
{
    cout << "Press enter to end this program" << endl;
    cin.get();
    // this will cause the server to shut down which will in turn cause 
    // TheServer.start() to unblock and thus the main() function will terminate.
    TheServer.clear();
}

void startServer (const char* url) {
#ifdef WIN32
    int port = 8888;
    SPARQL_path = "/SPARQL";
#else /* !WIN32 */
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
    int port;
    portss >> port;
    SPARQL_path = string(matches[PATH].first, matches[PATH].second);
#endif /* !WIN32 */

    // make it listen on port port
    TheServer.set_listening_port(port);
    TheServer.start();
}

int main (int argc, char** argv) {
    if (argc < 4) {
	cerr << "Usage: " << argv[0] << "serverURL stemURI ruleMap.rq+" << endl;
	return 1;
    }

     StemURI = argv[2];

     try {
	 /* Parse deduction rules. */
	 for (int iArg = 3; iArg < argc; ++iArg) {
	     sparqlParser.parse_file(argv[iArg]);
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

	 thread_function t(thread);
	 startServer(argv[1]);
     }
     catch (exception& e) {
         cerr << e.what() << endl;
     }
     return 0;
}

