/*
 */

#include "../interface/WEBserver.hpp"

namespace w3c_sw {

    /* WEBserver_dummy minimally implements the WEBserver interface.
     */
    class WEBserver_dummy : public WEBserver {
    protected:

    public:
	WEBserver_dummy () {  }
	void stop () {  }
	void serve (const char*, const char*, std::size_t, webserver::request_handler&) {  }
    };

} // namespace w3c_sw

#ifdef NEEDDEF_WEBSERVER
  #undef NEEDDEF_WEBSERVER
  #define WEBSERVER w3c_sw::WEBserver_dummy
#endif /* NEEDDEF_WEBSERVER */

