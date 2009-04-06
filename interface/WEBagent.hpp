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
    protected:
	std::string mediaType;
    public:
	SWWEBagent () {  }
	virtual ~SWWEBagent () {  }
	std::string getMediaType () { return mediaType; }
	virtual std::string get(
#if REGEX_LIB == SWOb_DISABLED
				std::string host, std::string port, std::string path
#else /* !REGEX_LIB == SWOb_DISABLED */
				const char* url
#endif /* !REGEX_LIB == SWOb_DISABLED */
				) = 0;
    };

} // namespace w3c_sw

#endif // !WEB_AGENT_H

