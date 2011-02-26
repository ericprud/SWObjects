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

    namespace Logger {

	enum severity_level {
	    critical = -3,
	    error = -2,
	    warning = -1,
	    admin = 0,
	    info = 1,
	    support = 2,
	    engineer = 3
	};

	// The formatting logic for the severity level
	template< typename CharT, typename TraitsT >
	inline std::basic_ostream< CharT, TraitsT >& operator<< (std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl) {
	    const int str_offset = 3;
	    static const char* const str[] = {
		"3      ",
		" 2     ",
		"  1    ",
		"   0   ",
		"    1  ",
		"     2 ",
		"      3"
	    };
	    if (static_cast< std::size_t >(lvl + str_offset) < (sizeof(str) / sizeof(*str)))
		strm << str[lvl + str_offset];
	    else
		strm << static_cast< int >(lvl);
	    return strm;
	}

	extern const char* ATTR_Timeline;
	extern const char* ATTR_Scope;
	extern const char* ATTR_ThreadID;
	extern const char* ATTR_LineId;
	extern const char* ATTR_Timestamp;
	extern const char* ATTR_Channel;

	typedef boost::log::sources::severity_channel_logger_mt<severity_level> SWObjectsLogger;

	BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(DefaultLog, SWObjectsLogger);
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(RewriteLog, SWObjectsLogger, (boost::log::keywords::channel = "Rewrite"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(IOLog, SWObjectsLogger, (boost::log::keywords::channel = "I/O"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(GraphMatchLog, SWObjectsLogger, (boost::log::keywords::channel = "GraphMatch"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(SQLLog, SWObjectsLogger, (boost::log::keywords::channel = "SQL"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(ServiceLog, SWObjectsLogger, (boost::log::keywords::channel = "Service"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(ProcessLog, SWObjectsLogger, (boost::log::keywords::channel = "Process"));

	extern severity_level DefaultLog_level;
	extern severity_level RewriteLog_level;
	extern severity_level IOLog_level;
	extern severity_level GraphMatchLog_level;
	extern severity_level SQLLog_level;
	extern severity_level ServiceLog_level;
	extern severity_level ProcessLog_level;
	
	typedef std::map<std::string, severity_level*> LabelToLevel_t;
	extern LabelToLevel_t LabelToLevel;
	extern std::vector<const char*> Labels;

	struct LabelInitializer {
	    LabelInitializer () {
		Labels.push_back("Default"); LabelToLevel["Default"] = &DefaultLog_level; LabelToLevel["default"] = &DefaultLog_level; LabelToLevel["DEFAULT"] = &DefaultLog_level; LabelToLevel[""] = &DefaultLog_level;
		Labels.push_back("Rewrite"); LabelToLevel["Rewrite"] = &RewriteLog_level; LabelToLevel["rewrite"] = &RewriteLog_level; LabelToLevel["REWRITE"] = &RewriteLog_level;
		Labels.push_back("IO"); LabelToLevel["IO"] = &IOLog_level; LabelToLevel["io"] = &IOLog_level; LabelToLevel["IO"] = &IOLog_level; LabelToLevel["i/o"] = &IOLog_level; LabelToLevel["I/O"] = &IOLog_level;
		Labels.push_back("GraphMatch"); LabelToLevel["GraphMatch"] = &GraphMatchLog_level; LabelToLevel["graphmatch"] = &GraphMatchLog_level; LabelToLevel["GRAPHMATCH"] = &GraphMatchLog_level;
		Labels.push_back("SQL"); LabelToLevel["SQL"] = &SQLLog_level; LabelToLevel["sql"] = &SQLLog_level; LabelToLevel["SQL"] = &SQLLog_level;
		Labels.push_back("Service"); LabelToLevel["Service"] = &ServiceLog_level; LabelToLevel["service"] = &ServiceLog_level; LabelToLevel["SERVICE"] = &ServiceLog_level;
		Labels.push_back("Process"); LabelToLevel["Process"] = &ProcessLog_level; LabelToLevel["process"] = &ProcessLog_level; LabelToLevel["PROCESS"] = &ProcessLog_level;
	    }
	};

	extern int depth;

	inline int indent (int incrementalDepth) {
	    int oldDepth = depth;
	    depth += incrementalDepth;
	    return oldDepth;
	}

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

	    // oprfxnstream prfxstr(strm.rdbuf(), depth, ' ');
	    // hack to chop the last \n off the log stream
	    std::stringstream ss;
	    oprfxnstream prfxstr(ss.rdbuf(), depth, ' ');

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

	    std::string s = ss.str();
	    if (s.substr(s.size() - 1) == "\n")
		s.resize(s.size() - 1);
	    strm << s;
	}

	typedef boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > Sink_t;

	inline bool GTDefault (severity_level l) { return l <= DefaultLog_level; }
	inline bool GTRewrite (severity_level l) { return l <= RewriteLog_level; }
	inline bool GTIO (severity_level l) { return l <= IOLog_level; }
	inline bool GTGraphMatch (severity_level l) { return l <= GraphMatchLog_level; }
	inline bool GTSQL (severity_level l) { return l <= SQLLog_level; }
	inline bool GTService (severity_level l) { return l <= ServiceLog_level; }
	inline bool GTProcess (severity_level l) { return l <= ProcessLog_level; }
	inline bool Logging (severity_level l, severity_level r) { return r <= l; }

	inline boost::shared_ptr< Sink_t > prepare () {
	    depth = 24;
	    boost::shared_ptr< logging::core > core = logging::core::get();

	    // Wrap backend in to the frontend
	    boost::shared_ptr< Sink_t > sink(new Sink_t());
	    core->add_sink(sink);

	    // core->set_filter(boost::log::filters::attr<severity_level>("Severity") >= *LabelToLevel[boost::log::filters::attr<std::string>("Channel")]);
	    core->set_filter
		(
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == ""          && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTDefault   )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "Rewrite"   && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTRewrite   )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "I/O"	 && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTIO        )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "GraphMatch"&& boost::log::filters::attr<severity_level>("Severity").satisfies(&GTGraphMatch)) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "SQL"       && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTSQL       )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "Service"   && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTService   )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "Process"   && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTProcess   ))
		 );

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

	inline std::string getLabels () {
	    std::stringstream ss;
	    for (std::vector<const char*>::const_iterator it = Labels.begin();
		 it != Labels.end(); ++it) {
		if (it != Labels.begin())
		    ss << " ";
		ss << *it;
	    }
	    return ss.str();
	}

	inline severity_level& getLabelLevel (const std::string label) {
	    LabelToLevel_t::iterator it = LabelToLevel.find(label.c_str());
	    if (it == LabelToLevel.end())
		throw std::string("Invalid log label \"") + label +"\". Try one of (" + getLabels() + ").";
	    return *it->second;
	}

    } /* namespace Logger */

#ifdef SWObjects_STAND_ALONE
    namespace Logger {
	const char* ATTR_Timeline = "Timeline";
	const char* ATTR_Scope = "Scope";
	const char* ATTR_ThreadID = "ThreadID";
	const char* ATTR_LineId = "LineId";
	const char* ATTR_Timestamp = "Timestamp";
	const char* ATTR_Channel = "Channel";
	int depth;

	severity_level DefaultLog_level;
	severity_level RewriteLog_level;
	severity_level IOLog_level;
	severity_level GraphMatchLog_level;
	severity_level SQLLog_level;
	severity_level ServiceLog_level;
	severity_level ProcessLog_level;
    
	LabelToLevel_t LabelToLevel;
	std::vector<const char*> Labels;
	namespace {
	    LabelInitializer TheLabelInitializer;
	}

    } /* namespace Logger */

#endif /* SWObjects_STAND_ALONE */

} // namespace w3c_sw

#endif /* ! defined LOGGING_HH */
