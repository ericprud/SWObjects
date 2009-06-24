/* test_WEBagents.cpp - test WEBagent and WEBclient interfaces
 *
 * $Id: test_WEBagents.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define SERVER_ADDRESS "0.0.0.0"
// for ipv6 #define SERVER_ADDRESS "0::0"
#define SERVER_PORT "8088"

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE WEBagents
#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "SWObjects.hpp"

#if HTTP_SERVER == SWOb_ASIO
 #include "interface/WEBserver_asio.hpp"
#elif HTTP_SERVER == SWOb_DLIB
 #include "interface/WEBserver_dlib.hpp"
#else
 #error unknown HTTP_SERVER (neither ASIO or DLIB)
#endif

class MyHandler : public w3c_sw::webserver::request_handler {
    WEBSERVER server;
    bool runOnce;
    inline void handle_request (const w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
	// Decode url to path.
	std::string request_path;
	if (!url_decode(req.uri, request_path)) {
	    rep = w3c_sw::webserver::reply::stock_reply(w3c_sw::webserver::reply::bad_request);
	    return;
	}

	// Request path must be absolute and not contain "..".
	if (request_path.empty() || request_path[0] != '/'
	    || request_path.find("..") != std::string::npos) {
	    rep = w3c_sw::webserver::reply::stock_reply(w3c_sw::webserver::reply::bad_request);
	    return;
	}

	// If path ends in slash (i.e. is a directory) then add "index.html".
	if (request_path[request_path.size() - 1] == '/') {
	    //    request_path += "index.html";

	    std::string title = "directory index for " + request_path;
	    std::stringstream s;
	    s << 
		"<html>\n"
		"  <head>\n"
		"    <title>" << title << "</title>\n"
		"  </head>\n"
		"  <body>\n"
		"    <h1>" << title << "</h1>\n";
	    if (request_path != "/") {
		boost::filesystem::path rp(request_path.substr(0, request_path.size() - 1));
		boost::filesystem::path pp(rp.parent_path());
		std::string ppStr = pp == pp.root_directory() ? "/" : pp.string() + "/";
		s << "    <p>go up to <a href=\"..\">" << ppStr << "</a></p>\n";
	    }
	    s << 
		"    <ul>\n";

	    boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
	    for ( boost::filesystem::directory_iterator itr( doc_root_ + request_path );
		  itr != end_itr;
		  ++itr ) {
		std::string name = itr->leaf();
		if (boost::filesystem::is_directory(itr->status()))
		    name += "/";
		s << "      <li><a href=\"" << name << "\">" << name << "</a></li>\n";
	    }
	    s << 
		"    </ul>\n"
		"  </body>\n"
		"</html>\n";

	    rep.status = w3c_sw::webserver::reply::ok;
	    rep.content = s.str();
	    rep.headers.resize(2);
	    rep.headers[0].name = "Content-Length";
	    rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
	    rep.headers[1].name = "Content-Type";
	    rep.headers[1].value = "text/html";
	    return;
	}

	// Determine the file extension.
	std::size_t last_slash_pos = request_path.find_last_of("/");
	std::size_t last_dot_pos = request_path.find_last_of(".");
	std::string extension;
	if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos) {
	    extension = request_path.substr(last_dot_pos + 1);
	}

	// Open the file to send back.
	std::string full_path = doc_root_ + request_path;
	std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
	if (!is) {
	    rep = w3c_sw::webserver::reply::stock_reply(w3c_sw::webserver::reply::not_found);
	    return;
	}

	// Fill out the reply to be sent to the client.
	rep.status = w3c_sw::webserver::reply::ok;
	char buf[512];
	while (is.read(buf, sizeof(buf)).gcount() > 0)
	    rep.content.append(buf, is.gcount());
	rep.headers.resize(2);
	rep.headers[0].name = "Content-Length";
	rep.headers[0].value = boost::lexical_cast<std::string>(rep.content.size());
	rep.headers[1].name = "Content-Type";
	rep.headers[1].value = w3c_sw::mime_types::extension_to_type(extension);

	if (runOnce)
	    server.stop();
    }
public:
    MyHandler (const std::string& doc_root, WEBSERVER server, bool runOnce) : 
	w3c_sw::webserver::request_handler(doc_root), server(server), runOnce(runOnce)
    {  }
};

BOOST_AUTO_TEST_CASE( a ) {
    const char* address = SERVER_ADDRESS;
    const char* port = SERVER_PORT;
    size_t num_threads = 1;
    try	{
	WEBSERVER s;
	MyHandler h(".", s, true);
	s.serve(address, port, num_threads, h);
    }
    catch (std::exception& e)	{
	std::cerr << "exception: " << e.what() << "\n";
    }
}

