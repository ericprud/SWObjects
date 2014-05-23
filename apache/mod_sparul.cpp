/**
 * activate with:
 *   LoadModule sparul_module /tmp/sparql11/apache/.libs/mod_sparul.so
 * superstitious dev cycle:
 *   rm -rf apache/.libs apache/mod_sparul.o && CODEA=~/checkouts/codea CCL=~/checkouts/ccl make -k -j 8 install-mod_sparul
 *  (which, if you're not root, will fail with a Permission denied, but it does create the .so)
 *   LD_LIBRARY_PATH=/tmp/sparql11/boost-log/stage/lib apachectl stop
 *   LD_LIBRARY_PATH=/tmp/sparql11/boost-log/stage/lib apachectl start
 *   reload
 *
 * To debug in gdb on debian, you have to provide a bunch of env vars:
set env LD_LIBRARY_PATH /home/eric/checkouts/sparql11-apache/boost-log/stage/lib
set env APACHE_RUN_DIR /var/run/apache2
set env APACHE_PID_FILE /var/run/apache2.pid
set env APACHE_LOCK_DIR /var/lock/apache2
set env APACHE_RUN_GROUP www
set env APACHE_RUN_USER www-data
set env APACHE_LOG_DIR /var/log/apache2
R -X
 */

#include "codea_hookmap.h"
#include "codea_hooks.h"
#include "codea_log.h"
#define NEEDDEF_W3C_SW_SAXPARSER
#define NEEDDEF_W3C_SW_WEBAGENT
#include "SWObjects.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "ParserCommon.hpp"
#include "SPARQLParser.hpp"
#include "TurtleParser.hpp"
#include "MapSetParser.hpp"
#include "ChainingMapper.hpp"
#include "SPARQLSerializer.hpp"
#include "SPARQLAlgebraSerializer.hpp"
#include "SQLizer.hpp"
#include "../interface/SQLclient.hpp"
#include <boost/iostreams/stream.hpp>
#include "version.h"
#include <apr_strings.h>

namespace w3c_sw {

struct WebHandler {
    WebHandler (std::string) {  } // @@ docroot is irrelevant -- create a docserver
    // #lib/SWObjects.hpp:155
class StringException : public std::exception {
public:
#if defined(SWIG)
    %immutable;
#endif /* defined(SWIG) */
    std::string str;
#if defined(SWIG)
    %mutable;
#endif /* defined(SWIG) */

    StringException (std::string m) : str(m.c_str()) {  }
    // !!! needs copy constructor in MS compilations, but
    //     haven't got UnknownPrefixException working in g++
    virtual ~StringException () throw() {  }
    virtual const char* what() const throw() { return str.c_str(); }
};

    // #interface/WEBserver.hpp:590
	struct SimpleMessageException : public StringException {
	    SimpleMessageException (std::string msg) : StringException(make(msg)) {  }
	    std::string make (std::string msg) {
		std::ostringstream sout;

		head(sout, "Q&amp;D SPARQL Server Error");
		sout << 
		    "    <pre>" << msg << "</pre>\n";
		foot(sout);
		return sout.str();
	    }
	    
	    SimpleMessageException (ParserException& ex) : StringException(make(ex)) {  }
	    std::string make (ParserException& ex) {
		std::ostringstream ss;
		head(ss, "Q&amp;D SPARQL Server Parsing Error");
		ss << "<h2>Parsing Error</h2>\n";
		ss << "<p><code>" << escapeHTML(ex.what()) << "</code></p>\n";
		std::string& str(*ex.begin.filename);
		size_t begin = 0;
		size_t end = 0;
		size_t line = 0;
		bool overrun = false;
		for (; !overrun && line < ex.begin.line; ++line) {
		    size_t pos = str.find_first_of("\r\n", begin);
		    if (pos == std::string::npos) {
			end = str.size();
			overrun = true;
		    } else {
			if (str[pos] == '\r' && pos < str.size()-1 && str[pos+1] == '\n')
			    ++pos;
			begin = pos + 1; // continue after \n
		    }
		}
		if (!overrun) {
		    if (begin + ex.begin.column > str.size()) {
			end = str.size();
			overrun = true;
		    } else {
			begin += ex.begin.column;
			end = begin;
			for (; !overrun && line < ex.end.line; ++line) {
			    size_t pos = str.find_first_of("\r\n", end);
			    if (pos == std::string::npos) {
				end = str.size();
				overrun = true;
			    } else {
				if (str[pos] == '\r' && pos < str.size()-1 && str[pos+1] == '\n')
				    ++pos;
				end = pos;
			    }
			}
		    }
		    if (!overrun) {
			if (end + ex.end.column > str.size()) {
			    end = str.size();
			    overrun = true;
			} else {
			    end += ex.begin.line == ex.end.line
				? ex.end.column-ex.begin.column
				: ex.end.column;
			}
		    }
		}
		std::string before(str.substr(0, begin));
		std::string error(str.substr(begin, end - begin));
		std::string after(str.substr(end, str.size() - end));

		/** Paint in some unicode characters to make lexer errors on a
		    word boundry visible. */
		for (size_t pos = 0; pos < error.size() && (pos = error.find_first_of("\r", pos)) != std::string::npos; )
		    if (pos == error.size()-1 || error[pos+1] != '\n') {
			error.insert(pos, "␍");
			pos += 4; // 3 bytes for unicode char
		    } else
			error.replace(pos, pos+1, "");
		for (size_t pos = 0; pos < error.size() && (pos = error.find_first_of("\n", pos)) != std::string::npos; ) {
		    error.insert(pos, "␊");
		    pos += 4; // 3 bytes for unicode char
		}

		//std::cerr << "begin: " << begin << "\nend: " << end << std::endl;
		ss
		    << "<pre style='border:1px solid #000; padding:.5em; float:left;'>" << escapeHTML(before)
		    << "<span style='background-color: #f00;'>" << escapeHTML(error) << "</span>"
		    << escapeHTML(after) << "</pre>\n  </body>\n</html>";
		return ss.str();
	    }
	};

	static std::string escapeHTML (std::string escapeMe) { // @@ same as lib/XMLSerializer::escapeCharData
	    std::string ret = escapeMe;
	    for (size_t p = ret.find_first_of("&<>"); 
		 p != std::string::npos; p = ret.find_first_of("&<>", p + 1))
		ret.replace(p, 1, 
			    ret[p] == '&' ? "&amp;" : 
			    ret[p] == '<' ? "&lt;" : 
			    ret[p] == '>' ? "&gt;" : "huh??");
	    return ret;
	}

	static void head (std::ostringstream& sout, std::string title, std::string head = "") {
	    sout << 
		"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
		"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n"
		"          \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\n"
		"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
		"  <head>\n"
		"    <title>" << title << "</title>\n" <<
		head <<
		"  </head>\n"
		"  <body>\n"
		"    <h1>" << title << "</h1>\n";
	}
	static void foot (std::ostringstream& sout) {
	    sout << "  </body>\n</html>\n";
	}
};

namespace webserver {
    struct request {
	request_rec* r;
	request (request_rec* r) : r(r), initialized(false)
	{  }
	std::string getPath () {
	    if (!initialized) {
		url_decode();
		initialized = true;
	    }
	    return r->parsed_uri.path;
	}
	std::string getMethod () { return r->method; }
	std::string getUri () { return r->uri; }
	std::string getContentType () { return r->content_type; }
	std::string _body;
	std::string getBody();
	std::string request_path;
	typedef std::multimap<std::string, std::string> parmmap;
	parmmap parms;
	void url_decode();
	protected:
	    bool initialized;
    };
    struct reply {
	request_rec* r;
	reply (request_rec* r) : r(r)
	{  }
	enum status_type {
	    declined = DECLINED,
	    ok = OK,
	    bad_request = HTTP_BAD_REQUEST,
	    internal_server_error = HTTP_INTERNAL_SERVER_ERROR
	};
	status_type status;
	void setStatus (status_type s) { status = s; }
	void setContentType (std::string s) { ap_set_content_type(r, apr_pstrdup(r->pool, s.c_str())); }
	void addHeader (std::string header, std::string value) {
	    apr_table_set(r->headers_out,
			  apr_pstrdup(r->pool, header.c_str()),
			  apr_pstrdup(r->pool, value.c_str()));
	}
	void setContent (std::string s) {
	    ap_rputs(apr_pstrdup(r->pool, s.c_str()), r);
	};
    };
    std::string request::getBody () {
	ap_setup_client_block(r, REQUEST_CHUNKED_DECHUNK);
	// trigger SPARUL query on request URI
	int ret = 0;
	_body = "";
	char buf[1024];
	buf[0] = 0;

	if (!ap_should_client_block(r))
	    throw reply::declined;

	// accumulate client post data (_body)
	while ((ret = ap_get_client_block(r, buf, 1024)) > 0) {
	    _body.append(buf, ret);
	    if (ret < 1024)
		break;
	}
	//printf("_body: %s\n", _body.c_str());
	return _body;
    }
	// from interface/WEBserver.hpp, but request_rec.args already at beginning of args.
	inline void request::url_decode ()
	{
	    if (r->args == NULL)
		return;
	    std::string uri(r->args);
	    if (getMethod() != "GET" && getMethod() != "POST" && getMethod() != "HEAD" && getMethod() != "PUT" && getMethod() != "DELETE")
		throw "not implemented error: url_decode only supports GET and POST.";
	    request_path.clear();
	    request_path.reserve(uri.size());
	    std::string& in = uri;
	    std::string* out = &request_path;
	    enum {IN_path, IN_parm, IN_value} nowIn = IN_path;
	    std::string parm;
	    std::string value;
	    std::size_t end = 0; // uri.find_last_of("?");
	    if (end == std::string::npos)
		end = uri.size();
	    std::size_t i = 0;
	    while (true) {
		for (; i < end; ++i) {
		    if (in[i] == '%') {
			if (i + 3 <= in.size()) {
			    int value;
			    std::istringstream is(in.substr(i + 1, 2));
			    if (is >> std::hex >> value) {
				*out += static_cast<char>(value);
				i += 2;
			    } else {
				throw webserver::reply::bad_request;
			    }
			} else {
			    throw webserver::reply::bad_request;
			}
		    } else if (in[i] == '+') {
			*out += ' ';
		    } else {
			*out += in[i];
		    }
		}
		switch (nowIn) {
		case IN_path:
		    if (((getMethod() == "GET" || getMethod() == "HEAD")) || 
			(getMethod() == "POST" && getContentType() == "application/x-www-form-urlencoded")) {
			nowIn = IN_parm;
			out = &parm;
			i = 0;
			if (++end != in.size()) {
			    end = in.find_first_of("=", end);
			    if (end == std::string::npos)
				throw webserver::reply::bad_request;
			}
		    } else if (end == uri.size())
			goto done;
		    break;
		case IN_parm:
		    nowIn = IN_value;
		    out = &value;
		    end = in.find_first_of("&", end);
		    if (end == std::string::npos)
			end = in.size();
		    if (i < in.size())
			++i;
		    break;
		case IN_value:
		    parms.insert(std::pair<std::string, std::string>(parm, value));
		    if (end == in.size())
		        goto done;
		    nowIn = IN_parm;
		    parm.clear();
		    value.clear();
		    out = &parm;
		    end = in.find_first_of("=", end);
		    if (end == std::string::npos)
			throw webserver::reply::bad_request;
		    ++i;
		    break;
		}
	    };
	done:
	    ;
	}

};

} /* namespace w3c_sw */

#include "SimpleServer.hpp"

#include "apr_strings.h"
#include "httpd.h"
#include "http_core.h"

struct Controller {
    std::string getStopCommand () { return ""; }
    void stop () {  }
};

w3c_sw::SimpleEngine engine("ID");

static const CodeaHooks::tag_t& SPARUL_tag( "SPARUL" );
class SPARULHooks : public CodeaHooks
{

////////////////////////////////////////////////////////////////////////////////
struct MyLoadEntry {
    const w3c_sw::TTerm* graphName;
    const w3c_sw::TTerm* resource;
    const w3c_sw::TTerm* baseURI;
    w3c_sw::MediaType mediaType;
    
    MyLoadEntry (const w3c_sw::TTerm* graphName, const w3c_sw::TTerm* resource, const w3c_sw::TTerm* baseURI, w3c_sw::MediaType mediaType)
	: graphName(graphName), resource(resource), baseURI(baseURI), mediaType(mediaType) {  }
    MyLoadEntry (const MyLoadEntry& ref)
	: graphName(ref.graphName), resource(ref.resource), baseURI(ref.baseURI), mediaType(ref.mediaType) {  }
    void loadGraph () {
	std::string nameStr = resource->getLexicalValue();
	w3c_sw::IStreamContext istr(nameStr, w3c_sw::IStreamContext::STDIN,
				mediaType ? mediaType.get().c_str() : NULL, 
				&engine.webClient);
    }
};

struct MyLoadList : public std::vector<MyLoadEntry> {
    void enqueue (const w3c_sw::TTerm* graphName, const w3c_sw::TTerm* resource, const w3c_sw::TTerm* baseURI, w3c_sw::MediaType mediaType) {
	push_back(MyLoadEntry(graphName, resource, baseURI, mediaType));
    }
    void loadAll () {
	for (iterator it = begin();
	     it != end(); ++it)
	    it->loadGraph();
    }
};

////////////////////////////////////////////////////////////////////////////////


public:

    static const tag_t& GetTag() { return SPARUL_tag; }

    struct MyInterface : public w3c_sw::SimpleInterface<w3c_sw::SimpleEngine, MyLoadList, Controller> {
	MyInterface (w3c_sw::SimpleEngine& engine, Controller* controller, std::string servicePath, std::string interfacePath)
	    : SimpleInterface (engine, controller, servicePath, interfacePath)
	{  }

	// make handle_request public
	w3c_sw::webserver::reply::status_type
	handle_request (w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
	    return w3c_sw::SimpleInterface<w3c_sw::SimpleEngine, MyLoadList, Controller>
		::handle_request(req, rep);
	}
    };

    static int Handler( request_rec* r ) {

	/* Set "LogLevel debug" in /etc/apache2/sites-available/default
	 * to see something in /var/log/apache2/error.log
	 */
        ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
		     "mod_sparul Handler serving <%s>.", r->uri);

	if (!strcmp(r->handler, "sparul-soundoff")) {
	    w3c_sw::webserver::request req(r);
	    w3c_sw::webserver::reply rep(r);
	    Controller noControl;
	    MyInterface dynamicHandler(engine, &noControl, "soundoff/SPARQL", "soundoff");
	    w3c_sw_LINEN << "start\n";
	    return dynamicHandler.handle_request(req, rep);

	    /* Add this to /etc/apache2/apache2.conf:
	    <Location /soundoff>
	      SetHandler sparul-soundoff
	    </Location>
	    and GET http://localhost/soundoff for instant gratification. */

	    ap_set_content_type(r, "text/html");
	    if (r->header_only)
		return OK;

	    ap_rputs(DOCTYPE_HTML_3_2, r);
	    ap_rputs("<html>\n", r);
	    ap_rputs(" <head>\n<title>mod_sparul Module Content-Handler Output\n</title>\n</head>\n", r);
	    ap_rputs(" <body>\n", r);
	    ap_rputs("  <h1><samp>mod_sparul</samp> Module Content-Handler Output\n</h1>\n", r);
	    ap_rputs("  <p>\n", r);
	    ap_rprintf(r, "  Apache HTTP Server version: \"%s\"<br />\n",
		       ap_get_server_banner());
	    ap_rprintf(r, "  Server built: %s<br />\n", ap_get_server_built());
	    ap_rprintf(r, "  Module built: %s %s<br />\n", __DATE__, __TIME__);
	    ap_rprintf(r, "  SWObjects Revision: %s modified %s by %s<br />\n",
		       SVN_Revision, SVN_Last_Changed_Date, SVN_Last_Changed_Author);
	    ap_rprintf(r, "  %s<br />\n", SVN_URL);
	    ap_rputs("  </p>\n", r);;
	    ap_rputs(" </body>\n", r);
	    ap_rputs("</html>\n", r);
	    return OK;
	}
        const char *ctype;
        ctype = apr_table_get(r->headers_in, "Content-Type");
        if (r->method_number == M_POST && ctype != NULL
            && strcmp(ctype, "application/sparql-query")==0) {
            ap_setup_client_block(r, REQUEST_CHUNKED_DECHUNK);

            // trigger SPARUL query on request URI
            int ret = 0;
            std::string query = "";
            char buf[1024];
            buf[0] = 0;

            if (!ap_should_client_block(r))
                return DECLINED;

            // accumulate client post data (query)
            while ((ret = ap_get_client_block(r, buf, 1024)) > 0) {
                query.append(buf, ret);
                if (ret < 1024)
                    break;
            }
            //printf("query: %s\n", query.c_str());

            // determine absolute URI
            const char *req_uri, *port;
            port = ap_is_default_port(ap_get_server_port(r), r)
                   ? "" : apr_psprintf(r->pool, ":%u", ap_get_server_port(r));
            req_uri = apr_psprintf(r->pool, "%s://%s%s%s%s",
                                   ap_http_scheme(r), ap_get_server_name(r), port,
                                   (*r->uri == '/') ? "" : "/",
                                   r->uri);
            //printf("req_uri: %s\n", req_uri);
            //printf("filename: %s\n", r->filename);

            // execute query
	    w3c_sw::AtomFactory f;
            w3c_sw::RdfDB db;

            w3c_sw::TurtleDriver tp(req_uri, &f);
            tp.setGraph(db.ensureGraph(NULL));
            w3c_sw::IStreamContext istr(r->filename, w3c_sw::IStreamContext::FILE);
            tp.parse(istr);

            w3c_sw::ResultSet rs(&f);
            rs.setRdfDB(&db);

            w3c_sw::SPARQLDriver sp(req_uri, &f);
            w3c_sw::IStreamContext qstr(query, w3c_sw::IStreamContext::STRING);
            sp.parse(qstr);
            sp.root->execute(&db, &rs);

            //std::string out = db.ensureGraph(NULL)->toString();
            //std::ofstream of(r->filename);
            //delete tp.root;
	    std::cout << db.ensureGraph(NULL)->toString();

            return OK;
        }

	return DECLINED;
    }
};

CODEA_REGISTER_HOOK_CLASS( SPARULHooks, SPARULHooks::GetTag() );

CODEA_BEGIN_HOOK_MAP( sparul )
CODEA_HANDLER( SPARULHooks::Handler, 0, 0, APR_HOOK_MIDDLE )
CODEA_END_HOOK_MAP( sparul )

CODEA_PUBLISH_MODULE( sparul, 0, 0, 0, 0, 0 )

