/* Logging: Boost Log library.

 * $Id: Logging.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef LOGGING_HH
# define LOGGING_HH

#include "config.h"
#include "prfxbuf.hpp"

// #include <stdexcept>
// #include <string>
// #include <iostream>
#include <fstream>
// #include <functional>

#include "boost/bind.hpp"
// #include "boost/date_time/posix_time/posix_time_types.hpp"
#include "boost/log/attributes.hpp"
// #include "boost/log/attributes/current_thread_id.hpp"
// #include "boost/log/attributes/named_scope.hpp"
// #include "boost/log/attributes/timer.hpp"
#include "boost/log/common.hpp"
#include "boost/log/filters.hpp"
#include "boost/log/formatters.hpp"
// #include "boost/log/formatters/if.hpp"
#include "boost/log/sinks.hpp"
// #include "boost/log/utility/empty_deleter.hpp"
#include "boost/log/utility/record_ordering.hpp"
// #include "boost/log/attributes/scoped_attribute.hpp"
#include "boost/random/linear_congruential.hpp"
#include "boost/random/uniform_int.hpp"
#include "boost/random/variate_generator.hpp"
// #include "boost/ref.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/thread/barrier.hpp"
// #include "boost/thread/thread.hpp"


namespace w3c_sw {

    enum {
	LOG_RECORDS_TO_WRITE = 5,
	THREAD_COUNT = 3,
	USLEEP_MIN = 1,
	USLEEP_MAX = 1000
    };

    enum severity_level {
	engineer = -3,
	support = -2,
	info = -1,
	admin = 0,
	warning = 1,
	error = 2,
	critical = 3
    };

    // The formatting logic for the severity level
    template< typename CharT, typename TraitsT >
    inline std::basic_ostream< CharT, TraitsT >& operator<< (
							     std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl) {
	const int str_offset = 3;
	static const char* const str[] = {
	    "      3",
	    "     2 ",
	    "    1  ",
	    "   0   ",
	    "  1    ",
	    " 2     ",
	    "3      "
	};
	if (static_cast< std::size_t >(lvl + str_offset) < (sizeof(str) / sizeof(*str)))
	    strm << str[lvl + str_offset];
	else
	    strm << static_cast< int >(lvl);
	return strm;
    }

    namespace Logger {
	extern const char* ATTR_Timeline;
	extern const char* ATTR_Scope;
	extern const char* ATTR_ThreadID;
	extern const char* ATTR_LineId;
	extern const char* ATTR_Timestamp;
	extern const char* ATTR_Channel;

	typedef boost::log::sources::severity_channel_logger_mt<severity_level> SWObjectsLogger;

	BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(Default, SWObjectsLogger);
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(GraphMatch, SWObjectsLogger, (boost::log::keywords::channel = "graph-match"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(http_lg, SWObjectsLogger, (boost::log::keywords::channel = "http"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(sparql2sql_lg, SWObjectsLogger, (boost::log::keywords::channel = "sparql2sql"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(Net, SWObjectsLogger, (boost::log::keywords::channel = "NET "));

	namespace logging = boost::log;

	inline void myFormatter(std::ostream& strm, logging::record const& rec)
	{
	    /**
	     * Overload prfxbuf to not indent the first line.
	     */
	    class prfxnbuf: public prfxbuf {

	    public:
		prfxnbuf (std::streambuf *sb, std::streamsize width, const char space):
		    prfxbuf(sb, std::string(width, space).c_str())
		{
		    i_newline = false; // don't indent first line
		}
	    };  
	    class oprfxnstream: public std::ostream
	    {
		prfxnbuf* b;
	    public:
		oprfxnstream (std::streambuf *sb, std::streamsize width, const char space):
		    std::ostream(new prfxnbuf(sb, width, space)), b((prfxnbuf*)rdbuf())
		{  } 
		~oprfxnstream () {
		    delete rdbuf();
		}
	    }; 

	    oprfxnstream prfxstr(strm.rdbuf(), 24, ' ');

	    using boost::format;

	    if (logging::extract<boost::posix_time::ptime>(Logger::ATTR_Timestamp, rec).is_initialized())
		prfxstr << logging::extract<boost::posix_time::ptime>(Logger::ATTR_Timestamp, rec).get() << ": ";

	    if (logging::extract< unsigned int >(Logger::ATTR_LineId, rec).is_initialized())
		prfxstr << format("%08x") % logging::extract< unsigned int >(Logger::ATTR_LineId, rec).get() << ": ";
	    // 	prfxstr << std::hex << std::setw(8) << std::right << logging::extract< unsigned int >(Logger::ATTR_LineId, rec).get() << ": ";

	    if (logging::extract<std::string>(Logger::ATTR_Channel, rec).is_initialized())
		prfxstr << format("%-11s") % logging::extract<std::string>(Logger::ATTR_Channel, rec).get() << " ";
	    // 	prfxstr << std::left << std::setw(11) << logging::extract<std::string>(Logger::ATTR_Channel, rec).get() << " ";

	    prfxstr << "[-" << logging::extract<severity_level>("Severity", rec).get() << "+] ";

	    if (logging::extract<std::string>(Logger::ATTR_Scope, rec).is_initialized())
		prfxstr << "[" << logging::extract<std::string>(Logger::ATTR_Scope, rec).get() << "] ";

	    if (logging::extract<boost::thread::id>(Logger::ATTR_ThreadID, rec).is_initialized())
		prfxstr << "[" << logging::extract<boost::thread::id>(Logger::ATTR_ThreadID, rec).get() << "] - ";

	    prfxstr << rec.message();

	    if (logging::extract<boost::posix_time::time_duration>(Logger::ATTR_Timeline, rec).is_initialized())
		prfxstr << " [taking: " << logging::extract< boost::posix_time::time_duration >(Logger::ATTR_Timeline, rec).get() << "]";
	}

	typedef boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > Sink_t;

	inline boost::shared_ptr< Sink_t > prepare () {
	    boost::shared_ptr< logging::core > core = logging::core::get();

	    // Wrap backend in to the frontend
	    boost::shared_ptr< Sink_t > sink(new Sink_t());
	    core->add_sink(sink);

	    { // Begin: lock backend
		Sink_t::locked_backend_ptr backend = sink->locked_backend();
		//		backend->add_stream(boost::shared_ptr< std::ostream >(&std::clog, logging::empty_deleter()));
		core->add_sink(sink);

		backend->set_formatter(&myFormatter);

	    } // End: Locked backend

	    return sink;

	}

	inline void addStream (boost::shared_ptr< Sink_t > sink, boost::shared_ptr< std::ostream > sptr) {
	    { // Begin: lock backend
		Sink_t::locked_backend_ptr backend = sink->locked_backend();
		backend->add_stream(sptr);
	    } // End: Locked backend
	}

    } /* namespace Logger */

} // namespace w3c_sw

#endif /* ! defined LOGGING_HH */
