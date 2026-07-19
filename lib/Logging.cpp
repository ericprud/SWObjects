/* Logging.cpp - the one library translation unit that sees Boost.Log.
 * The facade (LoggingFacade.hpp) forwards completed records here.
 */

#include "Logging.hpp"

namespace w3c_sw {
    namespace Logger {

	bool sinkActive = false;

	void emit (Channel ch, severity_level lvl, const std::string& msg) {
	    switch (ch) {
	    case RewriteLog_c:    BOOST_LOG_SEV(RewriteLog::get(), lvl) << msg; break;
	    case IOLog_c:         BOOST_LOG_SEV(IOLog::get(), lvl) << msg; break;
	    case ParsingLog_c:    BOOST_LOG_SEV(ParsingLog::get(), lvl) << msg; break;
	    case GraphMatchLog_c: BOOST_LOG_SEV(GraphMatchLog::get(), lvl) << msg; break;
	    case SQLLog_c:        BOOST_LOG_SEV(SQLLog::get(), lvl) << msg; break;
	    case ServiceLog_c:    BOOST_LOG_SEV(ServiceLog::get(), lvl) << msg; break;
	    case ProcessLog_c:    BOOST_LOG_SEV(ProcessLog::get(), lvl) << msg; break;
	    case DefaultLog_c:
	    default:              BOOST_LOG_SEV(DefaultLog::get(), lvl) << msg; break;
	    }
	}

    } /* namespace Logger */
} /* namespace w3c_sw */
