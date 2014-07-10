/* test_WEBagents.cpp - test WEBagent and WEBclient interfaces
 *
 * $Id: test_WEBagents.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $

 * You can quickly compile from .. (for iterative development) with:
    g++ -Ilib -I. -g -o tests/test_WEBagents tests/test_WEBagents.cpp -lboost_unit_test_framework-mt -lboost_filesystem-mt -lboost_thread-mt && ./tests/test_WEBagents
 * or play with a config.h local to tests with:
    g++ -Ilib -Itests -I. -g -o tests/test_WEBagents tests/test_WEBagents.cpp -lboost_unit_test_framework-mt -lboost_filesystem-mt -lboost_thread-mt && ./tests/test_WEBagents
 */

#define SERVER_ADDRESS "0.0.0.0"
// for ipv6 #define SERVER_ADDRESS "0::0"
#define SERVER_PORT "8088"

#include <iostream>
#include <fstream>
#include <sstream>

#include "SWObjects.hpp"

#define NEEDDEF_W3C_SW_WEBSERVER
#include "../interface/WEButil.hpp"
#include "../interface/WEBserver.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#define BOOST_TEST_MODULE WEBagents
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,Process:3"
//#include <boost/test/included/unit_test.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

struct ServerConfig {
    struct Request {
	bool allowBareNewlines () { return false; }
    } request;
};

class MyHandler : public w3c_sw::webserver::request_handler {
    W3C_SW_WEBSERVER<ServerConfig>& server;
    bool runOnce;

    inline w3c_sw::webserver::reply::status_type
    handle_request (w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
	/* caution: early returns */

	try {
	    // Decode url to path.
	    std::string request_path(req.getPath());

	    std::map<std::string, std::string>::const_iterator force = req.parms.find("force");
	    if (force != req.parms.end()) {
		std::stringstream s;
		if (force->second == "all") {
		    s << 
			req.method << " " << 
			req.request_path << " HTTP" << 
			req.http_version_major << "/" << req.http_version_minor << "\n";
		    for (std::vector<w3c_sw::web_util::header>::const_iterator it = req.headers.begin(); 
			 it != req.headers.end(); ++it)
			s << it->name << ": " << it->value << "\n";
		    s << "\n";
		}

		if (force->second == "parms" || force->second == "all")
		    for (std::map<std::string, std::string>::const_iterator it = req.parms.begin(); 
			 it != req.parms.end(); ++it)
			s << it->first << ": " << it->second << "\n";
		else
		    s << force->second << "\n";

		rep.status = w3c_sw::webserver::reply::ok;
		rep.content = s.str();
		rep.headers.resize(2);
		rep.headers[0].name = "Content-Length";
		rep.headers[0].value = boost::lexical_cast<std::string>((unsigned)rep.content.size());
		rep.headers[1].name = "Content-Type";
		rep.headers[1].value = "text/plain";
		return w3c_sw::webserver::reply::ok;
	    }

	    // Request path must be absolute and not contain "..".
	    if (request_path.empty() || request_path[0] != '/'
		|| request_path.find("..") != std::string::npos) {
		rep = w3c_sw::webserver::reply::stock_reply(w3c_sw::webserver::reply::bad_request);
		return w3c_sw::webserver::reply::bad_request;
	    }

	    // If path ends in slash, scan the directory.
	    if (request_path[request_path.size() - 1] == '/') {

		std::string title = "Directory index for " + request_path;
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
		s << "    <ul>\n";

		boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
		for ( boost::filesystem::directory_iterator itr( doc_root_ + request_path );
		      itr != end_itr;
		      ++itr ) {
		    std::string name = itr->path().filename().native();
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
		return w3c_sw::webserver::reply::ok;
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
		return w3c_sw::webserver::reply::not_found;
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
	catch (w3c_sw::webserver::reply& e) {
	    rep = e;
	}
	return w3c_sw::webserver::reply::internal_server_error;
    }
public:
    MyHandler (const std::string& doc_root, W3C_SW_WEBSERVER<ServerConfig>& server, bool runOnce) : 
	w3c_sw::webserver::request_handler(doc_root), server(server), runOnce(runOnce)
    {  }
};

BOOST_AUTO_TEST_CASE( a ) {
    const char* address = SERVER_ADDRESS;
    const char* port = SERVER_PORT;
    size_t num_threads = 1;
    bool runServer =
	boost::unit_test::framework::master_test_suite().argc > 1 && 
	std::string("serve") == boost::unit_test::framework::master_test_suite().argv[1]
	? true
	: false;
    try	{
	W3C_SW_WEBSERVER<ServerConfig> s;
	ServerConfig config;
	MyHandler h(".", s, true);
	if (runServer)
	    s.serve(address, port, num_threads, h, config);
    }
    catch (std::exception& e)	{
	std::cerr << "exception: " << e.what() << "\n";
    }
}

#ifdef NOT_YET
  std::string basicAuthHeader (std::string username, std::string password) {
      return std::string("Authorization: Basic ")
	  + sw::SWWEBagent::base64encode(username + ":" + password)
	  + "\n";
  }
// sw::WEBagent_boostASIO::AuthHandler authHandler;
  std::string authHandler (std::string url, std::string realm) {
      std::cout << "GET " + url + " wants a password for realm \"" + realm + "\"" << std::endl;
      std::cout << "username: "; std::string username; std::cin >> username;
      std::cout << "password: "; std::string password; std::cin >> password;
      return basicAuthHeader(username, password);
  }
// sw::WEBagent_boostASIO::AuthPreempt authPreempt;
  std::string authPreempt (std::string /* url */) {
      if (UserName.empty())
	  return "";
      return basicAuthHeader(UserName, PassWord);
  }

#endif /* NOT_YET */
