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
#if REGEX_LIB == SWOb_BOOST
  #include "boost/regex.hpp"
#endif
#if HTTP_SERVER == SWOb_DLIB
#include "dlib/server.h"
using namespace dlib;
#endif
#if SQL_CLIENT == SWOb_SWOb_MYSQL
  #ifdef WIN32
    #include <mysql.h>
   #else
    #include <mysql/mysql.h>
  #endif
#endif /* SQL_CLIENT == SWOb_MYSQL */

#include "SWObjects.hpp"
#include "QueryMapper.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SQLizer.hpp"

#include "SPARQLSerializer.hpp"

const char* SELECT_QUERY = "SELECT * FROM test";

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

	head(sout, "Q&amp;D SPARQL Server Error");
	sout << 
	    "    <pre>" << msg << "</pre>\n";
	foot(sout);
	return sout.str();
    }
};

#if HTTP_SERVER == SWOb_DLIB
class WebServer : public server::http_1a_c
{

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
        void on_connect (
            std::istream& in,
            std::ostream& out,
            const std::string& foreign_ip,
            const std::string& local_ip,
            unsigned short foreign_port,
            unsigned short local_port,
            uint64
        )
        {
            bool my_fault = true;
            try
            {
                enum req_type {get, post} rtype;

                using namespace std;
                map_type cookies;
                string word;
                string path;
                in >> word;
                if (word == "GET" || word == "get")
                {
                    rtype = get;
                }
                else if ( word == "POST" || word == "post")
                {
                    rtype = post;
                }
                else
                {
                    // this isn't a GET or POST request so just drop the connection
                    return;
                }

                // get the path
                in >> path;

                // now loop over all the incoming_headers
                string line;
                getline(in,line);
                unsigned long content_length = 0;
                string content_type;
                map_type incoming_headers;
                string first_part_of_header;
                string::size_type position_of_double_point;
                while (line.size() > 2)
                {
                    position_of_double_point = line.find_first_of(':');
                    if ( position_of_double_point != string::npos )
                    {
                        first_part_of_header = line.substr(0, position_of_double_point);
                        if ( incoming_headers.is_in_domain(first_part_of_header) )
                        {
                            incoming_headers[ first_part_of_header ] += " " + line.substr(position_of_double_point+1);
                        }
                        else
                        {
                            string second_part_of_header(line.substr(position_of_double_point+1));
                            incoming_headers.add( first_part_of_header, second_part_of_header );
                        }

                        // look for Content-Type:
                        if (line.size() > 14 &&
                            line[0] == 'C' &&
                            line[1] == 'o' &&
                            line[2] == 'n' &&
                            line[3] == 't' &&
                            line[4] == 'e' &&
                            line[5] == 'n' &&
                            line[6] == 't' &&
                            line[7] == '-' &&
                            (line[8] == 'T' || line[8] == 't') &&
                            line[9] == 'y' &&
                            line[10] == 'p' &&
                            line[11] == 'e' &&
                            line[12] == ':' 
                        )
                        {
                            content_type = line.substr(14);
                            if (content_type[content_type.size()-1] == '\r')
                                content_type.erase(content_type.size()-1);
                        }
                        // look for Content-Length:
                        else if (line.size() > 16 &&
                                 line[0] == 'C' &&
                                 line[1] == 'o' &&
                                 line[2] == 'n' &&
                                 line[3] == 't' &&
                                 line[4] == 'e' &&
                                 line[5] == 'n' &&
                                 line[6] == 't' &&
                                 line[7] == '-' &&
                                 (line[8] == 'L' || line[8] == 'l') &&
                                 line[9] == 'e' &&
                                 line[10] == 'n' &&
                                 line[11] == 'g' &&
                                 line[12] == 't' &&
                                 line[13] == 'h' &&
                                 line[14] == ':' 
                        )
                        {
                            istringstream sin(line.substr(16));
                            sin >> content_length;
                            if (!sin)
                                content_length = 0;
                        }
                        // look for any cookies
                        else if (line.size() > 6 &&
                                 line[0] == 'C' &&
                                 line[1] == 'o' &&
                                 line[2] == 'o' &&
                                 line[3] == 'k' &&
                                 line[4] == 'i' &&
                                 line[5] == 'e' &&
                                 line[6] == ':' 
                        )
                        {
                            string::size_type pos = 6;
                            string key, value;
                            bool seen_key_start = false;
                            bool seen_equal_sign = false;
                            while (pos + 1 < line.size())
                            {
                                ++pos;
                                // ignore whitespace between cookies
                                if (!seen_key_start && line[pos] == ' ')
                                    continue;

                                seen_key_start = true;
                                if (!seen_equal_sign) 
                                {
                                    if (line[pos] == '=')
                                    {
                                        seen_equal_sign = true;
                                    }
                                    else
                                    {
                                        key += line[pos];
                                    }
                                }
                                else
                                {
                                    if (line[pos] == ';')
                                    {
                                        if (cookies.is_in_domain(key) == false)
                                            cookies.add(key,value);
                                        seen_equal_sign = false;
                                        seen_key_start = false;
                                    }
                                    else
                                    {
                                        value += line[pos];
                                    }
                                }
                            }
                            if (key.size() > 0 && cookies.is_in_domain(key) == false)
                                cookies.add(key,value);
                        }
                    } // no ':' in it!
                    getline(in,line);
                } // while (line.size() > 2 )

                // If there is data being posted back to us as a query string then
                // just stick it onto the end of the path so the following code can
                // then just pick it out like we do for GET requests.
                if (rtype == post && content_type == "application/x-www-form-urlencoded" 
                    && content_length > 0)
                {
                    line.resize(content_length);
                    in.read(&line[0],content_length);
                    path += "?" + line;
                }

                string result;
                map_type queries;
                string::size_type pos = path.find_first_of("?");
                if (pos != string::npos)
                {
                    word = path.substr(pos+1);
                    path = path.substr(0,pos);
                    for (pos = 0; pos < word.size(); ++pos)
                    {
                        if (word[pos] == '&')
                            word[pos] = ' ';
                    }

                    istringstream sin(word);
                    sin >> word;
                    while (sin)
                    {
                        pos = word.find_first_of("=");
                        if (pos != string::npos)
                        {
                            string key = decode_query_string(word.substr(0,pos));
                            string value = decode_query_string(word.substr(pos+1));
                            if (queries.is_in_domain(key) == false)
                                queries.add(key,value);
                        }
                        sin >> word;
                    }
                }


                my_fault = false;
                queue_type new_cookies;
                map_type response_headers;
                // if there wasn't a problem with the input stream at some point
                // then lets trigger this request callback.
                if (in)
                    on_request(path,result,queries,cookies,new_cookies,incoming_headers, response_headers, foreign_ip,local_ip,foreign_port,local_port);
                my_fault = true;

                out << "HTTP/1.0 200 OK\r\n";
                // only send this header if the user hasn't told us to send another kind
                if (response_headers.is_in_domain("Content-Type") == false && 
                    response_headers.is_in_domain("content-type") == false)
                {
                    out << "Content-Type: text/html\r\n";
                }
                out << "Content-Length: " << result.size() << "\r\n";

                // Set any new headers
                response_headers.reset();
                while (response_headers.move_next())
                    out << response_headers.element().key() << ':' << response_headers.element().value() << "\r\n";

                // set any cookies 
                new_cookies.reset();
                while (new_cookies.move_next())
                {
                    out << "Set-Cookie: " << new_cookies.element() << "\r\n";
                }
                out << "\r\n" << result;
            }
            catch (std::bad_alloc&)
            {
                //dlog << LERROR << "We ran out of memory in server_http::on_connect()";
		cerr << "out of memory\n";
                // If this is an escaped exception from on_request then let it fly! 
                // Seriously though, this way it is obvious to the user that something bad happened
                // since they probably won't have the dlib logger enabled.
                if (!my_fault)
                    throw;
            }

        }
    /* end import from dlib-17.11/dlib/server/server_http_1.h
     */



    void executeQuery (ostringstream& sout, Operation* query, string queryStr) {
	SPARQLSerializer s;
	query->express(&s);
	cout << s.getString() << endl;
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
	    throw(SimpleMessageException("couldn't connect to mysql://" + 
					 User + "@" + Server + "/" + Database));
	if (mysql_query(sock, sqlizer.getSQLstring().c_str()))
	    throw(SimpleMessageException("mysql://" + User + "@" + Server + "/" + Database +
					 "could not execute [[\n" + 
					 sqlizer.getSQLstring() + 
					 "\n]]"));
	if (!(result=mysql_store_result(sock)))
	    throw(SimpleMessageException("mysql://" + User + "@" + Server + "/" + Database +
					 "could not retrieve results of [[\n" + 
					 sqlizer.getSQLstring() + 
					 "\n]]"));

	stringstream ret;
#if HTML_RESULTS
	head(ret, "Query Results");

	ret <<
	    "<h1>SPARQL Query</h1>\n"
	    "<pre>" << queryStr << "</pre>\n"
	    "<h1>SQL Query</h1>\n"
	    "<pre>" << sqlizer.getSQLstring() << "</pre>\n";
	char space[1024];
	sprintf(space, "<p>number of fields: %d</p>\n", mysql_num_fields(result));
	ret << space;

	int num_fields = mysql_num_fields(result);
	ret << 
	    "    <table>\n"
	    "      <tr>";

	/* dump headers in <th/>s */
	MYSQL_FIELD *field;
       	while((field = mysql_fetch_field(result)))
	    ret << "<th>" << field->name << "[" << field->type << "]</th>";
	ret << "</tr>\n";

	/* dump data in <td/>s */
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
	    unsigned long *lengths;
	    lengths = mysql_fetch_lengths(result);
	    ret << "      <tr>";
	    for(int i = 0; i < num_fields; i++) {
		sprintf(space, "[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
		ret << "<td>" << space << "</td>";
	    }
	    ret("</tr>");
	}
	ret << "    </table>";
	foot(ret);

#else /* !HTML_RESULTS */
	int num_fields = mysql_num_fields(result);
	ret << 
	    "<?xml version='1.0'?>\n"
	    "<sparql xmlns='http://www.w3.org/2005/sparql-results#'>\n"
	    "  <head>\n";

	/* dump headers in <th/>s */
	MYSQL_FIELD *field;
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	for(int i = 0; i < num_fields; i++)
	    ret << "    <variable name='" << fields[i].name << "'/>\n";
	ret << "  </head>\n";
	ret << "  <results>\n";

	/* dump data in <td/>s */
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result))) {
	    unsigned long *lengths;
	    lengths = mysql_fetch_lengths(result);
	    ret << "    <result>\n";
	    for(int i = 0; i < num_fields; i++)
		if (row[i]) {
		    const char* dt = NULL;
		    std::string lexval(row[i]);
		    bool isNull = false;
		    switch (fields[i].type) {
		    case MYSQL_TYPE_DECIMAL:
			dt = "http://www.w3.org/2001/XMLSchema#decimal";
			break;
		    case MYSQL_TYPE_TINY:
			dt = "http://www.w3.org/2001/XMLSchema#tiny";
			break;
		    case MYSQL_TYPE_SHORT:
			dt = "http://www.w3.org/2001/XMLSchema#short";
			break;
		    case MYSQL_TYPE_LONG:
			dt = "http://www.w3.org/2001/XMLSchema#long";
			break;
		    case MYSQL_TYPE_FLOAT:
			dt = "http://www.w3.org/2001/XMLSchema#float";
			break;
		    case MYSQL_TYPE_DOUBLE:
			dt = "http://www.w3.org/2001/XMLSchema#double";
			break;
		    case MYSQL_TYPE_LONGLONG:
			dt = "http://www.w3.org/2001/XMLSchema#decimal";
			break;
		    case MYSQL_TYPE_INT24:
			dt = "http://www.w3.org/2001/XMLSchema#integer";
			break;
		    case MYSQL_TYPE_NULL:
			isNull = true;
			break;
		    case MYSQL_TYPE_TIMESTAMP:
			dt = "http://www.w3.org/2001/XMLSchema#dateTime";
			lexval = "0-0-0T" + lexval;
			break;
		    case MYSQL_TYPE_YEAR:
			dt = "http://www.w3.org/2001/XMLSchema#dateTime";
			lexval = lexval = "-0-0T00:00";
			break;
		    case MYSQL_TYPE_STRING:
			dt = "http://www.w3.org/2001/XMLSchema#string";
		    case MYSQL_TYPE_VARCHAR:
		    case MYSQL_TYPE_VAR_STRING:
			for (size_t p = lexval.find_first_of("&<>"); 
			     p != std::string::npos; p = lexval.find_first_of("&<>", p + 1))
			    lexval.replace(p, 1, 
					   lexval[p] == '&' ? "&amp;" : 
					   lexval[p] == '<' ? "&lt;" : 
					   lexval[p] == '>' ? "&gt;" : "huh??");
			break;
		    default:
			throw std::string("field value \"") + lexval + "\" has unknown datatype";// + fields[i].type;
		    }
		    if (!isNull) {
			ret << "      <binding name='" << fields[i].name << "'>\n"
			    "        ";
			ret << "<literal";
			if (dt)
			    ret << " datatype=\"" << dt << "\"";
			ret << ">" << lexval << "</literal>\n";
			ret << "      </binding>\n";
		    }
		}
	    ret << "    </result>\n";
	}
	ret << 
	    "  </results>\n"
	    "</sparql>";
#endif /* !HTML_RESULTS */

	sout << ret.str();
	cout << ret.str() << endl;
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
		    cerr << "400 Bad Request: " << queries["query"] << endl;

		    foot(sout);
		} else {
		    Operation* query = sparqlParser.root;
		    executeQuery(sout, query, queries["query"]);
		    string ct("Content-Type");
		    string mt("application/sparql-results+xml; charset=UTF-8");
		    response_headers.add(ct, mt);
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
		head(sout, "Q&amp;D SPARQL Server");
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
	    head(sout, "Q&amp;D SPARQL Server Error");
	    sout << 
		"    <pre>" << query << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << what << "</pre>\n"; 
	    foot(sout);
            result = sout.str();
        }
    }

};
 #elif HTTP_SERVER == SWOb_ASIO
  #error ASIO HTTP server not implemented
 #else
  #ifdef _MSC_VER
    #pragma message ("No HTTP server -- implementing fake server")
  #else /* !_MSC_VER */
    #warning No HTTP server -- implementing fake server
  #endif /* !_MSC_VER */
struct WebServer {
    void start () {  }
    void clear () {  }
    void set_listening_port (int) {  }
};
struct thread_function  {
    thread_function ( void (*funct)() ) {  }
};
#endif /* HTTP_SERVER == SWOb_DLIB */


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

