#include <sstream>

#if HTTP_SERVER == SWOb_ASIO
 #include <boost/asio.hpp>
 #define CONST_BUFFER boost::asio::const_buffer
 #define MUTABLE_BUFFER boost::asio::buffer
 #include <boost/algorithm/string.hpp>
 #define HEADER_EQUALS(A, B) boost::iequals(A, B)
#elif HTTP_SERVER == SWOb_DLIB || HTTP_SERVER == SWOb_DISABLED
 #define CONST_BUFFER std::string
 #define MUTABLE_BUFFER std::string
 #define HEADER_EQUALS(A, B) A.compare(B)
#else
 #error unknown HTTP_SERVER (neither ASIO, DLIB)
#endif

#include "SWObjects.hpp"
#include "ParserCommon.hpp"

namespace w3c_sw {

    namespace webserver {
	struct header
	{
	    std::string name;
	    std::string value;
	    header () {  }
	    header (std::string name, std::string value) : name(name), value(value) {  }
	};

	/// A request received from a client.
	struct request
	{
	    std::string method;
	    std::string uri;
	    int http_version_major;
	    int http_version_minor;
	    typedef std::vector<header> headerset;
	    headerset headers;
	    std::string body;
	    virtual std::string getPath() const = 0;
	    request () : content_length(0), content_type("") {  };
	    virtual ~request () {  }
	    void url_decode();
	    std::string request_path;
	    typedef std::multimap<std::string, std::string> parmmap;
	    parmmap parms;
	    size_t content_length;
	    std::string content_type;
	};

	struct reply
	{
	    /// The status of the reply.
	    enum status_type
		{
		    ok = 200,
		    created = 201,
		    accepted = 202,
		    no_content = 204,
		    multiple_choices = 300,
		    moved_permanently = 301,
		    moved_temporarily = 302,
		    not_modified = 304,
		    bad_request = 400,
		    unauthorized = 401,
		    forbidden = 403,
		    not_found = 404,
		    internal_server_error = 500,
		    not_implemented = 501,
		    bad_gateway = 502,
		    service_unavailable = 503
		} status;

	    /// The headers to be included in the reply.
	    std::vector<header> headers;

	    void addHeader (std::string name, std::string value) {
		headers.push_back(header(name, value));
	    }

	    /// The content to be sent in the reply.
	    std::string content;

	    /// Convert the reply into a vector of buffers. The buffers do not own the
	    /// underlying memory blocks, therefore the reply object must remain valid and
	    /// not be changed until the write operation has completed.
	    std::vector<CONST_BUFFER> to_buffers(bool noBody);

	    /// Get a stock reply.
	    static reply stock_reply(status_type status);
	};

	// inline void request::url_decode ()
	inline void request::url_decode ()
	{
	    if (method != "GET" && method != "POST" && method != "HEAD" && method != "PUT" && method != "DELETE")
		throw "not implemented error: url_decode only supports GET and POST.";
	    request_path.clear();
	    request_path.reserve(uri.size());
	    std::string& in = uri;
	    std::string* out = &request_path;
	    enum {IN_path, IN_parm, IN_value} nowIn = IN_path;
	    std::string parm;
	    std::string value;
	    std::size_t end = uri.find_last_of("?");
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
				throw w3c_sw::webserver::reply::
				    stock_reply(w3c_sw::webserver::reply::bad_request);
			    }
			} else {
			    throw w3c_sw::webserver::reply::
				stock_reply(w3c_sw::webserver::reply::bad_request);
			}
		    } else if (in[i] == '+') {
			*out += ' ';
		    } else {
			*out += in[i];
		    }
		}
		switch (nowIn) {
		case IN_path:
		    if (((method == "GET" || method == "HEAD") && in[end] == '?') || 
			(method == "POST" && end == uri.size() && content_type == "application/x-www-form-urlencoded")) {
			if (method == "POST" && content_type == "application/x-www-form-urlencoded") {
			    in = body;
			    i = -1;
			    end = 0;
			}
			nowIn = IN_parm;
			out = &parm;
			++i;
			if (++end != in.size()) {
			    end = in.find_first_of("=", end);
			    if (end == std::string::npos)
				throw w3c_sw::webserver::reply::
				    stock_reply(w3c_sw::webserver::reply::bad_request);
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
			throw w3c_sw::webserver::reply::
			    stock_reply(w3c_sw::webserver::reply::bad_request);
		    ++i;
		    break;
		}
	    };
	done:
	    ;
	}

	namespace status_strings {

	    // !!! needs to be static but multi-module-safe
		const std::string ok =
		    "HTTP/1.0 200 OK\r\n";
		const std::string created =
		    "HTTP/1.0 201 Created\r\n";
		const std::string accepted =
		    "HTTP/1.0 202 Accepted\r\n";
		const std::string no_content =
		    "HTTP/1.0 204 No Content\r\n";
		const std::string multiple_choices =
		    "HTTP/1.0 300 Multiple Choices\r\n";
		const std::string moved_permanently =
		    "HTTP/1.0 301 Moved Permanently\r\n";
		const std::string moved_temporarily =
		    "HTTP/1.0 302 Moved Temporarily\r\n";
		const std::string not_modified =
		    "HTTP/1.0 304 Not Modified\r\n";
		const std::string bad_request =
		    "HTTP/1.0 400 Bad Request\r\n";
		const std::string unauthorized =
		    "HTTP/1.0 401 Unauthorized\r\n";
		const std::string forbidden =
		    "HTTP/1.0 403 Forbidden\r\n";
		const std::string not_found =
		    "HTTP/1.0 404 Not Found\r\n";
		const std::string internal_server_error =
		    "HTTP/1.0 500 Internal Server Error\r\n";
		const std::string not_implemented =
		    "HTTP/1.0 501 Not Implemented\r\n";
		const std::string bad_gateway =
		    "HTTP/1.0 502 Bad Gateway\r\n";
		const std::string service_unavailable =
		    "HTTP/1.0 503 Service Unavailable\r\n";

	    inline CONST_BUFFER to_buffer(reply::status_type status)
	    {
		switch (status)
		    {
		    case reply::ok:
			return MUTABLE_BUFFER(ok);
		    case reply::created:
			return MUTABLE_BUFFER(created);
		    case reply::accepted:
			return MUTABLE_BUFFER(accepted);
		    case reply::no_content:
			return MUTABLE_BUFFER(no_content);
		    case reply::multiple_choices:
			return MUTABLE_BUFFER(multiple_choices);
		    case reply::moved_permanently:
			return MUTABLE_BUFFER(moved_permanently);
		    case reply::moved_temporarily:
			return MUTABLE_BUFFER(moved_temporarily);
		    case reply::not_modified:
			return MUTABLE_BUFFER(not_modified);
		    case reply::bad_request:
			return MUTABLE_BUFFER(bad_request);
		    case reply::unauthorized:
			return MUTABLE_BUFFER(unauthorized);
		    case reply::forbidden:
			return MUTABLE_BUFFER(forbidden);
		    case reply::not_found:
			return MUTABLE_BUFFER(not_found);
		    case reply::internal_server_error:
			return MUTABLE_BUFFER(internal_server_error);
		    case reply::not_implemented:
			return MUTABLE_BUFFER(not_implemented);
		    case reply::bad_gateway:
			return MUTABLE_BUFFER(bad_gateway);
		    case reply::service_unavailable:
			return MUTABLE_BUFFER(service_unavailable);
		    default:
			return MUTABLE_BUFFER(internal_server_error);
		    }
	    }

	} // namespace status_strings

	inline std::vector<CONST_BUFFER> reply::to_buffers(bool noBody)
	{
	    static const char name_value_separator[] = { ':', ' ' };
	    static const char crlf[] = { '\r', '\n' };
	    static std::string cl("Content-Length");
	    bool clFound = false;

	    std::vector<CONST_BUFFER> buffers;
	    buffers.push_back(status_strings::to_buffer(status));
	    for (std::size_t i = 0; i < headers.size(); ++i) {
		header& h = headers[i];
		buffers.push_back(MUTABLE_BUFFER(h.name));
		buffers.push_back(MUTABLE_BUFFER(name_value_separator));
		buffers.push_back(MUTABLE_BUFFER(h.value));
		buffers.push_back(MUTABLE_BUFFER(crlf));
		if (HEADER_EQUALS(cl, h.name))
		    clFound = true;
	    }
	    if (clFound == false) {
		static char size[100] = ""; // @@!!!
		std::stringstream s;
		buffers.push_back(MUTABLE_BUFFER(cl));
		buffers.push_back(MUTABLE_BUFFER(name_value_separator));
		s << content.size();
		strcpy(size, s.str().c_str());
		buffers.push_back(MUTABLE_BUFFER(size, strlen(size)));
		buffers.push_back(MUTABLE_BUFFER(crlf));
	    }
	    buffers.push_back(MUTABLE_BUFFER(crlf));
	    if (!noBody)
		buffers.push_back(MUTABLE_BUFFER(content));
	    // for (std::vector<CONST_BUFFER>::const_iterator it = buffers.begin();
	    // 	 it != buffers.end(); ++it) {
	    // 	std::size_t s = boost::asio::buffer_size(*it);
	    // 	const char* p = boost::asio::buffer_cast<const char*>(*it);
	    // 	std::cout.write(p, s);
	    // }
	    return buffers;
	}

	namespace stock_replies {

	    // !!! needs to be static but multi-module-safe
		const char ok[] = "";
		const char created[] =
		    "<html>"
		    "<head><title>Created</title></head>"
		    "<body><h1>201 Created</h1></body>"
		    "</html>";
		const char accepted[] =
		    "<html>"
		    "<head><title>Accepted</title></head>"
		    "<body><h1>202 Accepted</h1></body>"
		    "</html>";
		const char no_content[] =
		    "<html>"
		    "<head><title>No Content</title></head>"
		    "<body><h1>204 Content</h1></body>"
		    "</html>";
		const char multiple_choices[] =
		    "<html>"
		    "<head><title>Multiple Choices</title></head>"
		    "<body><h1>300 Multiple Choices</h1></body>"
		    "</html>";
		const char moved_permanently[] =
		    "<html>"
		    "<head><title>Moved Permanently</title></head>"
		    "<body><h1>301 Moved Permanently</h1></body>"
		    "</html>";
		const char moved_temporarily[] =
		    "<html>"
		    "<head><title>Moved Temporarily</title></head>"
		    "<body><h1>302 Moved Temporarily</h1></body>"
		    "</html>";
		const char not_modified[] =
		    "<html>"
		    "<head><title>Not Modified</title></head>"
		    "<body><h1>304 Not Modified</h1></body>"
		    "</html>";
		const char bad_request[] =
		    "<html>"
		    "<head><title>Bad Request</title></head>"
		    "<body><h1>400 Bad Request</h1></body>"
		    "</html>";
		const char unauthorized[] =
		    "<html>"
		    "<head><title>Unauthorized</title></head>"
		    "<body><h1>401 Unauthorized</h1></body>"
		    "</html>";
		const char forbidden[] =
		    "<html>"
		    "<head><title>Forbidden</title></head>"
		    "<body><h1>403 Forbidden</h1></body>"
		    "</html>";
		const char not_found[] =
		    "<html>"
		    "<head><title>Not Found</title></head>"
		    "<body><h1>404 Not Found</h1></body>"
		    "</html>";
		const char internal_server_error[] =
		    "<html>"
		    "<head><title>Internal Server Error</title></head>"
		    "<body><h1>500 Internal Server Error</h1></body>"
		    "</html>";
		const char not_implemented[] =
		    "<html>"
		    "<head><title>Not Implemented</title></head>"
		    "<body><h1>501 Not Implemented</h1></body>"
		    "</html>";
		const char bad_gateway[] =
		    "<html>"
		    "<head><title>Bad Gateway</title></head>"
		    "<body><h1>502 Bad Gateway</h1></body>"
		    "</html>";
		const char service_unavailable[] =
		    "<html>"
		    "<head><title>Service Unavailable</title></head>"
		    "<body><h1>503 Service Unavailable</h1></body>"
		    "</html>";

	    inline std::string to_string(reply::status_type status)
	    {
		switch (status)
		    {
		    case reply::ok:
			return ok;
		    case reply::created:
			return created;
		    case reply::accepted:
			return accepted;
		    case reply::no_content:
			return no_content;
		    case reply::multiple_choices:
			return multiple_choices;
		    case reply::moved_permanently:
			return moved_permanently;
		    case reply::moved_temporarily:
			return moved_temporarily;
		    case reply::not_modified:
			return not_modified;
		    case reply::bad_request:
			return bad_request;
		    case reply::unauthorized:
			return unauthorized;
		    case reply::forbidden:
			return forbidden;
		    case reply::not_found:
			return not_found;
		    case reply::internal_server_error:
			return internal_server_error;
		    case reply::not_implemented:
			return not_implemented;
		    case reply::bad_gateway:
			return bad_gateway;
		    case reply::service_unavailable:
			return service_unavailable;
		    default:
			return internal_server_error;
		    }
	    }

	} // namespace stock_replies

	inline reply reply::stock_reply(reply::status_type status)
	{
	    reply rep;
	    rep.status = status;
	    rep.content = stock_replies::to_string(status);
	    rep.headers.resize(2);
	    rep.headers[0].name = "Content-Length";
	    char space[30];
	    sprintf(space, "%d", (int)rep.content.size());
	    rep.headers[0].value = std::string(space);
	    rep.headers[1].name = "Content-Type";
	    rep.headers[1].value = "text/html";
	    return rep;
	}

    } // namespace webserver

    namespace mime_types {

	/// Convert a file extension into a MIME type.
	    // !!! needs to be static but multi-module-safe
	struct mapping
	{
	    const char* extension;
	    const char* mime_type;
	} mappings[] =
	    {
		{ "gif", "image/gif" },
		{ "htm", "text/html" },
		{ "html", "text/html" },
		{ "jpg", "image/jpeg" },
		{ "png", "image/png" },
		{ 0, 0 } // Marks end of list.
	    };

	inline std::string extension_to_type(const std::string& extension)
	{
	    for (mapping* m = mappings; m->extension; ++m)
		{
		    if (m->extension == extension)
			{
			    return m->mime_type;
			}
		}

	    return "text/plain";
	}

    } // namespace mime_types


    namespace webserver {
	class request_handler
#if HTTP_SERVER == SWOb_ASIO
	    : private boost::noncopyable // copied from boost http server demo
#endif
	{
	public:
	    /// Construct with a directory containing files to be served.
	    explicit request_handler(const std::string& doc_root);
	    virtual ~request_handler () {  }

	    /// Handle a request and produce a reply.
	    virtual void handle_request(request& req, reply& rep) = 0;

	protected:
	    /// The directory containing the files to be served.
	    std::string doc_root_;

	    /// Perform URL-decoding on a string. Returns false if the encoding was
	    /// invalid.
	};

	inline request_handler::request_handler(const std::string& doc_root)
	    : doc_root_(doc_root)
	{
	}

    }

    class WEBserver {
    public:
	virtual ~WEBserver () {  }
	virtual void serve(const char* address, const char* port, std::size_t num_threads, webserver::request_handler& handler) = 0;
    };

    class WebHandler : public w3c_sw::webserver::request_handler {
    public:
	WebHandler (const std::string& doc_root)
	    : w3c_sw::webserver::request_handler(doc_root)
	{  }
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

    };

} // namespace w3c_sw

#define NEEDDEF_WEBSERVER 1

