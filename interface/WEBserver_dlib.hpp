/**
 * badly atrophied. should be dropped or updated to match the WEBserver_asio model.
 */

// #include <iostream>
// #include <sstream>

#ifndef INCLUDED_interface_WEBserver_dlib_hpp
 #define INCLUDED_interface_WEBserver_dlib_hpp

#include "interface/WEBserver.hpp"
#ifdef max // for WIN32
  #undef max
#endif
#ifdef min // for WIN32
  #undef min
#endif
#include "dlib/server.h"

// ISO C++ code
#include "dlib/base64/base64_kernel_1.cpp"
#include "dlib/bigint/bigint_kernel_1.cpp"
#include "dlib/bigint/bigint_kernel_2.cpp"
#include "dlib/bit_stream/bit_stream_kernel_1.cpp"
#include "dlib/entropy_decoder/entropy_decoder_kernel_1.cpp"
#include "dlib/entropy_decoder/entropy_decoder_kernel_2.cpp"
#include "dlib/entropy_encoder/entropy_encoder_kernel_1.cpp"
#include "dlib/entropy_encoder/entropy_encoder_kernel_2.cpp"
#include "dlib/md5/md5_kernel_1.cpp"
#include "dlib/tokenizer/tokenizer_kernel_1.cpp"
#include "dlib/unicode/unicode.cpp"

#ifndef DLIB_ISO_CPP_ONLY
// Code that depends on OS specific APIs

// include this first so that it can disable the older version
// of the winsock API when compiled in windows.
#include "dlib/sockets/sockets_kernel_1.cpp"

#include "dlib/dir_nav/dir_nav_kernel_1.cpp"
#include "dlib/dir_nav/dir_nav_kernel_2.cpp"
#include "dlib/dir_nav/dir_nav_extensions.cpp"
#include "dlib/linker/linker_kernel_1.cpp"
#include "dlib/logger/extra_logger_headers.cpp"
#include "dlib/logger/logger_kernel_1.cpp"
#include "dlib/logger/logger_config_file.cpp"
#include "dlib/misc_api/misc_api_kernel_1.cpp"
#include "dlib/misc_api/misc_api_kernel_2.cpp"
#include "dlib/sockets/sockets_extensions.cpp"
#include "dlib/sockets/sockets_kernel_2.cpp"
#include "dlib/sockstreambuf/sockstreambuf_kernel_1.cpp"
#include "dlib/sockstreambuf/sockstreambuf_kernel_2.cpp"
#include "dlib/threads/multithreaded_object_extension.cpp"
#include "dlib/threads/threaded_object_extension.cpp"
#include "dlib/threads/threads_kernel_1.cpp"
#include "dlib/threads/threads_kernel_2.cpp"
#include "dlib/threads/threads_kernel_shared.cpp"
#include "dlib/threads/thread_pool_extension.cpp"
#include "dlib/timer/timer_kernel_2.cpp"
#include "dlib/stack_trace.cpp"

#ifdef DLIB_PNG_SUPPORT
#include "dlib/image_loader/png_loader.cpp"
#endif

#endif // DLIB_ISO_CPP_ONLY


// using namespace dlib;

namespace w3c_sw {

    /* WEBserver_asio implements the WEBserver interface. This is the intended
     * interface to user code.
     * TODO:
     *   Would w3c_sw::webserver::asio be better than w3c_sw::WEBserver_asio ?
     */
    class WEBserver_dlib : public dlib::server::http_1a_c, public WEBserver {
    protected:
	static WEBserver_dlib* TheServer;
	static void thread () {
#if DLIB_TIGHT_LOOP
	    std::cout << "a POST to <" << ServiceURLstr << "> with query=stop will terminate the server." << std::endl;
	    while (!Done) dlib::sleep(1000);
	    std::cout << "Done: served " << Served << " queries." << std::endl;
#else
	    std::cout << "Press enter to end this program" << std::endl;
	    std::cin.get();
#endif
	    TheServer->clear();
	}
	webserver::request_handler* handler;

	const std::string on_request (const incoming_things& incoming, outgoing_things& outgoing) {
	    std::vector<webserver::header> headers;
            for (key_value_map::const_iterator ci = incoming.headers.begin(); 
		 ci != incoming.headers.end(); ++ci )
		headers.push_back(webserver::header(ci->first, ci->second));

	    webserver::request req = {"GET", incoming.path, 1, 1, headers};
	    webserver::reply rep;
	    handler->handle_request(req, rep);

	    for (std::vector<webserver::header>::const_iterator it = rep.headers.begin();
		 it != rep.headers.end(); ++it)
		outgoing.headers[it->name] = it->value;
	    outgoing.http_return = rep.status;
	    outgoing.http_return_status = "@@";
	    return rep.content;
	}

    public:
	WEBserver_dlib () { TheServer = this; }
	void serve (const char* /* address */, const char* ports, std::size_t /* num_threads */, webserver::request_handler& handler) {
	    this->handler = &handler;
	    int port;
	    std::istringstream portss(ports);
	    portss >> port;
	    dlib::thread_function t(thread);
	    set_listening_port(port);
	    start();
	}
    };

    WEBserver_dlib* WEBserver_dlib::TheServer;

} // namespace w3c_sw

#ifdef NEEDDEF_W3C_SW_WEBSERVER
  #undef NEEDDEF_W3C_SW_WEBSERVER
  #define W3C_SW_WEBSERVER w3c_sw::WEBserver_dlib
#endif /* NEEDDEF_W3C_SW_WEBSERVER */

#endif /* INCLUDED_interface_WEBserver_dlib_hpp */
