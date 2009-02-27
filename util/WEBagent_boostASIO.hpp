/* WEBagent_boostASIO.hpp: implementation of WEBagent for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once
#include <stack>
#include <map>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include "util/WEBagent.hpp"

using boost::asio::ip::tcp;

namespace w3c_sw {

    class WEBagent_boostASIO : public SWWEBagent {
    public:
	WEBagent_boostASIO () : SWWEBagent() {  }
	~WEBagent_boostASIO () {  }
	virtual std::string get (const char* url) {
#ifdef HAVE_REGEX
	    // !!! duplicate of SPARQL_server.cpp
	    boost::regex re;
	    boost::cmatch matches;

	    re = "(ftp|http|https):\\/\\/((?:\\w+\\.)*\\w*)(?::([0-9]+))?(.*)";
	    if (!boost::regex_match(url, matches, re))
		throw std::string("Address ") + url + " is not a valid URL\n";

#define PROT 1
#define HOST 2
#define PORT 3
#define PATH 4
	    std::string host(matches[HOST].first, matches[HOST].second);
	    std::string port(matches[PORT].first, matches[PORT].second);
	    std::string path(matches[PATH].first, matches[PATH].second);
#else /* !HAVE_REGEX */
#error "Need REGEX to create a WEBagent_boostASIO -- defaulting to http://localhost/"
	    std::string host("localhost");
	    std::string port("80");
	    std::string path("/");
#endif /* !HAVE_REGEX */

	    std::cerr << "http://" << host << ":" << port << path << std::endl;

	    boost::asio::io_service io_service;

	    // Get a list of endpoints corresponding to the server name.
	    tcp::resolver resolver(io_service);
	    tcp::resolver::query query(host.c_str(), port.c_str());
	    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	    tcp::resolver::iterator end;

	    // Try each endpoint until we successfully establish a connection.
	    tcp::socket socket(io_service);
	    boost::system::error_code error = boost::asio::error::host_not_found;
	    while (error && endpoint_iterator != end) {
		socket.close();
		socket.connect(*endpoint_iterator++, error);
	    }
	    if (error)
		throw boost::system::system_error(error);

	    // Form the request. We specify the "Connection: close" header so that the
	    // server will close the socket after transmitting the response. This will
	    // allow us to treat all data up until the EOF as the content.
	    boost::asio::streambuf request;
	    std::ostream request_stream(&request);
	    request_stream << "GET " << path << " HTTP/1.0\r\n";
	    request_stream << "Host: " << host << "\r\n";
	    request_stream << "Accept: */*\r\n";
	    request_stream << "Connection: close\r\n\r\n";

	    // Send the request.
	    boost::asio::write(socket, request);

	    // Read the response status line.
	    boost::asio::streambuf response;
	    boost::asio::read_until(socket, response, "\r\n");

	    // Check that response is OK.
	    std::istream response_stream(&response);
	    std::string http_version;
	    response_stream >> http_version;
	    unsigned int status_code;
	    response_stream >> status_code;
	    std::string status_message;
	    std::getline(response_stream, status_message);
	    if (!response_stream || http_version.substr(0, 5) != "HTTP/")
		throw "Invalid response";
	    if (status_code != 200)
		throw std::string("Response returned with status code "); // + status_code;

	    // Read the response headers, which are terminated by a blank line.
	    boost::asio::read_until(socket, response, "\r\n\r\n");

	    // Process the response headers.
	    std::string header;
	    while (std::getline(response_stream, header) && header != "\r")
		std::cout << header << "\n";
	    std::cout << "\n";

	    std::ostringstream xmlResults;
	    // Write whatever content we already have to output.
	    if (response.size() > 0)
		xmlResults << &response;

	    // Read until EOF, writing data to output as we go.
	    while (boost::asio::read(socket, response,
				     boost::asio::transfer_at_least(1), error))
		xmlResults << &response;
	    if (error != boost::asio::error::eof)
		throw boost::system::system_error(error);
	    return xmlResults.str();
	}
    };

} /* namespace w3c_sw */
