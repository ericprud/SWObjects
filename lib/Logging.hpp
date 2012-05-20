/** Logging: SWObjects logging using the Boost Log library.
 * 
 * Enable logging to e.g. std::clog with:
 *   boost::shared_ptr<Logger::Sink_t> logSink= Logger::prepare();
 *   Logger::addStream(logSink, boost::shared_ptr<std::ostream>
 *		       (&std::clog, boost::log::empty_deleter()));
 * and set specific levels manually:
 *   Logger::getLabelLevel("Default")= Logger::severity_level(Logger::engineer);
 * or with the built-in parser:
 *   parseLevelString("*:1,IO:3");
 * 
 * Boost unit_tests may prepare the logger by invoking the macro
 *   w3c_sw_PREPARE_TEST_LOGGER("--log");
 * and passing command like arguments like "--debug *:1,IO:3".
 * 
 * $Id: Logging.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef LOGGING_HH
# define LOGGING_HH

#include "config.h"
#include "prfxbuf.hpp"

#include <set>

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
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(ParsingLog, SWObjectsLogger, (boost::log::keywords::channel = "Parsing"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(GraphMatchLog, SWObjectsLogger, (boost::log::keywords::channel = "GraphMatch"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(SQLLog, SWObjectsLogger, (boost::log::keywords::channel = "SQL"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(ServiceLog, SWObjectsLogger, (boost::log::keywords::channel = "Service"));
	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(ProcessLog, SWObjectsLogger, (boost::log::keywords::channel = "Process"));

	extern severity_level DefaultLog_level;
	extern severity_level RewriteLog_level;
	extern severity_level IOLog_level;
	extern severity_level ParsingLog_level;
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
		Labels.push_back("IO"); LabelToLevel["PARSING"] = &ParsingLog_level; LabelToLevel["parsing"] = &ParsingLog_level; LabelToLevel["Parsing"] = &ParsingLog_level; LabelToLevel["PARSE"] = &ParsingLog_level; LabelToLevel["parse"] = &ParsingLog_level;
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

	inline void myFormatter (std::ostream& strm, logging::record const& rec)
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
		// prfxstr << std::hex << std::setw(8) << std::right << logging::extract< unsigned int >(Logger::ATTR_LineId, rec).get() << ": ";

	    if (logging::extract<std::string>(Logger::ATTR_Channel, rec).is_initialized())
		prfxstr << format("%-11s") % logging::extract<std::string>(Logger::ATTR_Channel, rec).get() << " ";
		// prfxstr << std::left << std::setw(11) << logging::extract<std::string>(Logger::ATTR_Channel, rec).get() << " ";

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
	inline bool GTParsing (severity_level l) { return l <= ParsingLog_level; }
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
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "Parsing"	 && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTIO        )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "GraphMatch"&& boost::log::filters::attr<severity_level>("Severity").satisfies(&GTGraphMatch)) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "SQL"       && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTSQL       )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "Service"   && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTService   )) ||
		 (boost::log::filters::attr<std::string>("Channel", std::nothrow) == "Process"   && boost::log::filters::attr<severity_level>("Severity").satisfies(&GTProcess   ))
		 );

	    { // Begin: lock backend
		Sink_t::locked_backend_ptr backend = sink->locked_backend();
		// backend->add_stream(boost::shared_ptr< std::ostream >(&std::clog, logging::empty_deleter()));
		core->add_sink(sink);

#if (BOOST_VERSION > 104600) // could use (BOOST_LOG_COMPATIBILITY == "1.46") if cpp compared strings
		sink->set_formatter(&myFormatter);
#else
		backend->set_formatter(&myFormatter);
#endif

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

	/** Logging level control interface functions for main.
	 * Note parseLevelString("*:1,IO:3") and
	 * prepare(argc, argv, "--log", &std::clog) below.
	 */

	/** addLogLabel - add lable to logs and visitedLogs
	 */
	inline void addLogLabel (std::vector<std::string>& logs, std::set<std::string>& visitedLogs, std::string label) {
	    if (label == "*") {
		for (std::vector<const char*>::const_iterator it = w3c_sw::Logger::Labels.begin();
		     it != w3c_sw::Logger::Labels.end(); ++it)
		    if (visitedLogs.find(*it) == visitedLogs.end()) {
			logs.push_back(*it);
			visitedLogs.insert(*it);
		    }
	    } else {
		w3c_sw::Logger::getLabelLevel(label);
		logs.push_back(label);
		visitedLogs.insert(label);
	    }
	}

	/** setLogLevels - for each @logs, set the logging level to @level
	 */
	inline void setLogLevels (const std::vector<std::string>& logs, int level) {
	    for (std::vector<std::string>::const_iterator it = logs.begin();
		 it != logs.end(); ++it) {
		w3c_sw::Logger::getLabelLevel(*it) = w3c_sw::Logger::severity_level(level);
		BOOST_LOG_SEV(w3c_sw::Logger::DefaultLog::get(), w3c_sw::Logger::support) << "log level \"" << *it << "\" set to " << level << ".";
	    }
	}

	/** parseLevelString - parse a string like "SQL,Service:3,Process:-1"
	 * into a set of visitedLogs and set those log levels.
	 */
	inline void parseLevelString (const std::string parm) {
	    std::set<std::string> visitedLogs;
	    std::vector<std::string> curLogList;
	    size_t start = 0;
	    do {
		size_t next = parm.find_first_of(",:", start);
		if (next == std::string::npos) {
		    if (start == 0) {
			try {
			    int l = boost::lexical_cast<int>(parm.substr(start));
			    addLogLabel(curLogList, visitedLogs, "*");
			    setLogLevels(curLogList, l);
			    curLogList.clear();
			} catch (boost::bad_lexical_cast&) { }
		    } else {
			addLogLabel(curLogList, visitedLogs, parm.substr(start));
			setLogLevels(curLogList, 1);
			curLogList.clear();
		    }
		} else {
		    addLogLabel(curLogList, visitedLogs, parm.substr(start, next - start));
		    if (parm[next] == ':') {
			start = next + 1;
			next = parm.find_first_of(",:", start);
			std::string is
			    = next == std::string::npos
			    ? parm.substr(start)
			    : parm.substr(start, next - start);
			if (next != std::string::npos)
			    ++next;
			int l;		
			try {
			    l = boost::lexical_cast<int>(is);
			} catch (boost::bad_lexical_cast& e) {
			    std::stringstream ss;
			    ss << "invalid int \"" << is << "\" at offeset " << start << " in \"" << parm << "\".";
			    throw ss.str();
			}
			setLogLevels(curLogList, l);
			curLogList.clear();
		    } else
			++next;
		}
		start = next;
	    } while (start != std::string::npos);

	    boost::shared_ptr< boost::log::core > core = boost::log::core::get();

	    // Add a global scope attribute
	    if (false)
		core->add_global_attribute(w3c_sw::Logger::ATTR_Scope,
					   boost::log::attributes::named_scope());
	    if (false)
		core->add_global_attribute(w3c_sw::Logger::ATTR_ThreadID,
					   boost::log::attributes::current_thread_id());

	    // Add some attributes too
	    if (false)
		core->add_global_attribute(w3c_sw::Logger::ATTR_Timestamp,
					   boost::log::attributes::utc_clock());
	    if (false)
		core->add_global_attribute(w3c_sw::Logger::ATTR_LineId,
					   boost::log::attributes::counter< unsigned int >());
	}

	/** prepare - a simple prepare interface for scanning a set of
	 * main-style argv arguments for a given logging flag.
	 * 
	 * @argc - a count of arguments.
	 * @argv - an array of arguments.
	 * @flag - the flag to look for.
	 * @os - where to send the logging output.
	 */
	inline bool prepare (int argc, char** argv, const char* flag,
			     std::ostream* os = &std::clog) {
	    bool ret = false;

	    boost::shared_ptr< Logger::Sink_t > LogSink;
	    LogSink = Logger::prepare();
	    Logger::addStream(LogSink, boost::shared_ptr< std::ostream >
			      (os, boost::log::empty_deleter()));

	    for (int c = 0; c < argc - 1; ++c)
		if (!strcmp(argv[c], flag)) {
		    Logger::parseLevelString(argv[c+1]);
		    ret = true;
		}

	    return ret;
	}

	/** w3c_sw_PREPARE_TEST_LOGGER - set up a logger based on boost
	 *  unit_test arguments.
	 * 
	 * @FLAG - a command line flag, like "--log", to provide logging
	 * arguments. Note, you must avoid arguments which boost::unit_test
	 * swallows, like "-d".
	 */
#define w3c_sw_PREPARE_TEST_LOGGER(FLAG) \
struct PrepareBoostTestLogger { \
    PrepareBoostTestLogger ()   { \
	w3c_sw::Logger::prepare(boost::unit_test::framework::master_test_suite().argc-1, \
				boost::unit_test::framework::master_test_suite().argv+1, \
				FLAG); \
    } \
}; \
BOOST_GLOBAL_FIXTURE( PrepareBoostTestLogger );

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
	severity_level ParsingLog_level;
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
