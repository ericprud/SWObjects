/* WEBagent - abstract inferface for WEB clients and servers

 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $

 * SWWEBagent is prefixed with SW to avoid collisions with
 * implementation names.
 */

#ifndef WEB_AGENT_H
#define WEB_AGENT_H

#include <string>
#include "SWObjects.hpp"

namespace w3c_sw {

    class SWWEBagent {
    public:
	SWWEBagent () {  }
	virtual ~SWWEBagent () {  }
	virtual std::string get(const char* url) = 0;
    };

} // namespace w3c_sw

#endif // !WEB_AGENT_H

