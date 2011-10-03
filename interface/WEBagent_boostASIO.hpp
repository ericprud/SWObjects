/* WEBagent_boostASIO.hpp: implementation of WEBagent for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef INCLUDED_interface_WEBagent_boostASIO_hpp
 #define INCLUDED_interface_WEBagent_boostASIO_hpp

#include <stack>
#include <map>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include "../interface/WEBagent.hpp"

using boost::asio::ip::tcp;

namespace w3c_sw {

    struct console_auth_prompter {
	typedef std::string AuthHandler(std::string url, std::string realm);
	typedef std::string AuthPreempt(std::string url);

	std::string userName;
	std::string password;

	console_auth_prompter ()
	    : userName(""), password("")
	{  }

	console_auth_prompter (const console_auth_prompter& ref)
	    : userName(ref.userName), password(ref.password)
	{  }

	console_auth_prompter (std::string userName, std::string password)
	    : userName(userName), password(password)
	{  }

	std::string basicAuthHeader (std::string username, std::string password) {
	    return std::string("Authorization: Basic ")
		+ SWWEBagent::base64encode(username + ":" + password)
		+ "\n";
	}
	// w3c_sw::console_auth_prompter::AuthHandler authHandler;
	std::string authHandler (std::string url, std::string realm) {
	    std::cout << "GET " + url + " wants a stinkin' password for realm \"" + realm + "\"" << std::endl;
	    std::cout << "username: "; std::string username; std::cin >> username;
	    std::cout << "password: "; std::string password; std::cin >> password;
	    return basicAuthHeader(username, password);
	}
	// w3c_sw::console_auth_prompter::AuthPreempt authPreempt;
	std::string authPreempt (std::string /* url */) {
	    if (userName.empty())
		return "";
	    return basicAuthHeader(userName, password);
	}
    };

    template <class auth_manager = console_auth_prompter>
    class web_agent_asio : public SWWEBagent {
    public:
	auth_manager* authManager;
	web_agent_asio (auth_manager* authManager)
	    : SWWEBagent(), authManager(authManager)
	{  }
	~web_agent_asio () {  }
	virtual boost::shared_ptr<IStreamContext> _execute (std::string method,
#if REGEX_LIB == SWOb_DISABLED
				 std::string host, std::string port, std::string path
#else /* !REGEX_LIB == SWOb_BOOST */
				 std::string url
#endif /* !REGEX_LIB == SWOb_BOOST */
				 , std::string urlParms, std::string reqBody
				 ) {
#if REGEX_LIB == SWOb_BOOST
	    // !!! duplicate of SPARQL_server.cpp
	    boost::regex re;
	    boost::cmatch matches;

	    re = "(ftp|http|https):\\/\\/((?:\\w(?:\\w|-)+\\.)*\\w*)(?::([0-9]+))?(.*)";
	    if (!boost::regex_match(url.c_str(), matches, re))
		throw std::string("Address ") + url + " is not a valid URL\n";

#define PROT 1
#define HOST 2
#define PORT 3
#define PATH 4
	    std::string host(matches[HOST].first, matches[HOST].second);
	    std::string port(matches[PORT].first, matches[PORT].second);
	    std::string path(matches[PATH].first, matches[PATH].second);
#endif /* !REGEX_LIB == SWOb_BOOST */

	    if (port.empty())
		port = "80";

	    bool redo = false;
	    boost::system::error_code error;
	    boost::asio::streambuf response;
	    boost::asio::io_service io_service;
	    tcp::socket socket(io_service);
	    std::ostringstream body;
	    std::string authString;

	    authString = authManager != NULL ? authManager->authPreempt(url) : "";
	    do {
		// Form the request. We specify the "Connection: close" header so that the
		// server will close the socket after transmitting the response. This will
		// allow us to treat all data up until the EOF as the content.
		boost::asio::streambuf request;
#ifdef LOGGING_HH
		std::stringstream request_stream;
#else /* !LOGGING_HH */
		std::ostream request_stream(&request);
#endif /* !LOGGING_HH */
		request_stream << method << " " << path;
		if (urlParms.size() != 0)
		    request_stream << (path.find_first_of("?") == std::string::npos ? "?" : 
				       path.at(path.size()-1) == '&' ? "" : 
				       "&") << urlParms;
		request_stream << " HTTP/1.0\r\n";

		request_stream << "Host: " << host;
		if (port != "80")
		    request_stream << ":" << port;
		request_stream << "\r\n";

		request_stream << "Accept: "
		    /* 1. */ "application/binary-rdf-results-table,application/x-binary-rdf-results-table,"
		    /* .9 */ "application/sparql-results+xml;q=.9,text/sparql-results;q=.9,"
		    /* .8 */ "application/xml;q=.8,application/html+xml;q=.8,"
		    /* .7 */ "text/html;q=.7"
		    "\r\n"; // !! Boy does this need to be a parameter...

		request_stream << authString;
		request_stream << "User-Agent: web_agent_asio 0.1\r\n";
		if (reqBody.size() != 0) {
		    request_stream << "Content-Type: application/x-www-form-urlencoded\r\n";
		    request_stream << "Content-Length: " << reqBody.size() << "\r\n";
		}
		request_stream << "Connection: close\r\n\r\n";
		request_stream << reqBody;

#ifdef LOGGING_HH
		{
		    BOOST_LOG_SEV(w3c_sw::Logger::IOLog::get(), w3c_sw::Logger::support) << "Request: " << request_stream.str() << "\n";
		    std::ostream rs(&request);
		    rs << request_stream.str();
		}
#endif /* LOGGING_HH */

		// Get a list of endpoints corresponding to the server name.
		tcp::resolver resolver(io_service);
		tcp::resolver::query query(host.c_str(), port.c_str());
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::resolver::iterator end;

		// Try each endpoint until we successfully establish a connection.
		error = boost::asio::error::host_not_found;
		while (error && endpoint_iterator != end) {
		    socket.close();
		    socket.connect(*endpoint_iterator++, error);
		}
		if (error)
		    throw boost::system::system_error(error);

		// Send the request.
		boost::asio::write(socket, request);

		// Read the response status line.
		boost::asio::read_until(socket, response, "\r\n");

		// Check that response is OK.
		std::istream response_stream(&response);
		std::string http_version;
		response_stream >> http_version;
		unsigned int status_code = 0;
		response_stream >> status_code;
		std::string status_message;
		std::getline(response_stream, status_message);
		if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
		    std::stringstream ss;
		    ss << "Invalid HTTP response: " << http_version << " " << status_code << " " << status_message;
		    throw ss.str();
		}

		// Read the response headers, which are terminated by a blank line.
		boost::asio::read_until(socket, response, "\r\n\r\n");

		// Process the response headers.
		std::string header;
		std::string authType("unspecified");
		std::string realm("unspecified");
		while (std::getline(response_stream, header) && header != "\r") {
		    header.resize(header.size()-1);
		    size_t colon = header.find_first_of(":");
		    if (colon != std::string::npos) {
			std::transform(header.begin(), header.end(), header.begin(), ::tolower);
			if (!header.compare(0, colon, "www-authenticate")) {
			    size_t space = header.find_first_of(" ", colon + 1);
			    realm = header.substr(colon+2, space);
			    size_t equal = header.find_first_of("=", space + 2);
			    realm = header.substr(equal+1);
			}
			if (!header.compare(0, colon, "content-type"))
			    mediaType = header.substr(colon+2);
		    }
		    //std::cout << header << "\n";
		}
		switch (status_code) {
		case 401: {
		    while (boost::asio::read(socket, response,
					     boost::asio::transfer_at_least(1), error))
			;
		    if (authManager != NULL)
			authString = authManager->authHandler(url, realm);
		    else
			throw std::string() + "authentication required for \"" + url + "\" in realm \"" + realm + "\".";
		    redo = true;
		}
		case 200: {
		    // Write whatever content we already have to output.
		    if (response.size() > 0)
			body << &response;

		    // Read until EOF, writing data to output as we go.
		    while (boost::asio::read(socket, response,
					     boost::asio::transfer_at_least(1), error))
			body << &response;
		    if (error != boost::asio::error::eof)
			throw boost::system::system_error(error);
		    break;
		}
		default: {
		    //std::cout << "\n";
		    std::stringstream s;
		    s << status_code;
		    { // @@ quick hack to allow users to see the returned error bodies
			if (response.size() > 0)
			    body << &response;

			// Read until EOF, writing data to output as we go.
			while (boost::asio::read(socket, response,
						 boost::asio::transfer_at_least(1), error))
			    body << &response;
			s << ": " << body.str();
		    }
		    throw method + " " + url + " returned with status code " + s.str();
		}

		}
	    } while (redo);

	    return boost::shared_ptr<IStreamContext>(new IStreamContext(body.str(), IStreamContext::STRING, mediaType.empty() ? NULL : mediaType.c_str()));
	}

    };

} /* namespace w3c_sw */

#ifdef NEEDDEF_W3C_SW_WEBAGENT
  #undef NEEDDEF_W3C_SW_WEBAGENT
  #define W3C_SW_WEBAGENT w3c_sw::web_agent_asio
#endif /* NEEDDEF_W3C_SW_WEBAGENT */

#endif /* !INCLUDED_interface_WEBagent_boostASIO_hpp */
