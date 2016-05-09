/** Logging: SWObjects logging using the Boost Log library.
 * 
 * Enable logging to e.g. std::clog with:
 *   boost::shared_ptr<Logger::Sink_t> logSink= Logger::prepare();
 *   Logger::addStream(logSink, boost::shared_ptr<std::ostream>
 *		       (&std::clog, boost::empty_deleter()));
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

#include "prfxbuf.hpp"

#include <set>

#include <fstream>

#include "boost/bind.hpp"
#include "boost/format.hpp"
#include "boost/log/attributes.hpp"
#include "boost/log/common.hpp"
#include "boost/log/expressions.hpp"
#include "boost/log/sinks.hpp"
#include "boost/log/utility/record_ordering.hpp"
#include "boost/log/utility/value_ref.hpp"
#include "boost/log/utility/formatting_ostream.hpp"
#include "boost/phoenix/bind.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/random/linear_congruential.hpp"
#include "boost/random/uniform_int.hpp"
#include "boost/random/variate_generator.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/thread/barrier.hpp"
#if BOOST_VERSION == 105400
# include "boost/log/utility/empty_deleter.hpp"
# define BOOST_NULL_DELETER boost::log::empty_deleter
#elif BOOST_VERSION < 105800
# include "boost/log/utility/empty_deleter.hpp"
# define BOOST_NULL_DELETER boost::empty_deleter
#else /* BOOST_VERSION != 105400 */
# include "boost/core/null_deleter.hpp"
# define BOOST_NULL_DELETER boost::null_deleter
#endif /* BOOST_VERSION != 105400 */

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

	typedef boost::log::sources::severity_channel_logger_mt<severity_level> SWObjectsLogger;

	BOOST_LOG_ATTRIBUTE_KEYWORD(a_channel, "Channel", std::string)
	BOOST_LOG_ATTRIBUTE_KEYWORD(a_severity, "Severity", severity_level)
	BOOST_LOG_ATTRIBUTE_KEYWORD(a_timestamp, "Timestamp", boost::log::attributes::utc_clock::value_type)
	BOOST_LOG_ATTRIBUTE_KEYWORD(a_timeline, "Timeline", boost::posix_time::time_duration)
	BOOST_LOG_ATTRIBUTE_KEYWORD(a_scope, "Scope", boost::log::attributes::named_scope::value_type)
	BOOST_LOG_ATTRIBUTE_KEYWORD(a_thread_id, "ThreadID", boost::log::attributes::current_thread_id::value_type)
	BOOST_LOG_ATTRIBUTE_KEYWORD(a_line_id, "LineID", unsigned int)

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

	inline void myFormatter(logging::formatting_ostream& strm, logging::record_view const& rec)
	{
	    /**
	     * Overload prfxbuf to not indent the first line.
	     */
	    class prfxnbuf: public prfxbuf {

	    public:
		prfxnbuf (std::streambuf *sb, _w3c_sw_STREAMSIZE width, const char space):
		    prfxbuf(sb, std::string(width, space).c_str())
		{
		    i_newline = false; // don't indent first line
		}
	    };
	    class oprfxnstream: public std::ostream
	    {
		prfxnbuf* b;
	    public:
		oprfxnstream (std::streambuf *sb, _w3c_sw_STREAMSIZE width, const char space):
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

	    if (logging::value_ref< tag::a_timestamp::value_type, tag::a_timestamp > timestamp = rec[a_timestamp])
		prfxstr << timestamp.get() << ": ";

	    if (logging::value_ref< tag::a_line_id::value_type, tag::a_line_id > line_id = rec[a_line_id])
		prfxstr << format("%08x") % line_id.get() << ": ";
            // prfxstr << std::hex << std::setw(8) << std::right << line_id.get() << ": ";

	    if (logging::value_ref< tag::a_channel::value_type, tag::a_channel > channel = rec[a_channel])
		prfxstr << format("%-11s") % channel.get() << " ";
            // prfxstr << std::left << std::setw(11) << channel.get() << " ";

	    prfxstr << "[-" << rec[a_severity] << "+] ";

	    if (logging::value_ref< tag::a_scope::value_type, tag::a_scope > scope = rec[a_scope])
		prfxstr << "[" << scope.get() << "] ";

	    if (logging::value_ref< tag::a_thread_id::value_type, tag::a_thread_id > thread_id = rec[a_thread_id])
		prfxstr << "[" << thread_id.get() << "] - ";

	    prfxstr << rec[boost::log::expressions::smessage];

	    if (logging::value_ref< tag::a_timeline::value_type, tag::a_timeline > timeline = rec[a_timeline])
		prfxstr << " [taking: " << timeline.get() << "]";

	    std::string s = ss.str();
	    if (s.substr(s.size() - 1) == "\n")
		s.resize(s.size() - 1);
	    strm << s;
	}

	typedef boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > Sink_t;

	/*
	inline bool GTDefault (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= DefaultLog_level; }
	inline bool GTRewrite (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= RewriteLog_level; }
	inline bool GTIO (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= IOLog_level; }
	inline bool GTParsing (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= ParsingLog_level; }
	inline bool GTGraphMatch (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= GraphMatchLog_level; }
	inline bool GTSQL (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= SQLLog_level; }
	inline bool GTService (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= ServiceLog_level; }
	inline bool GTProcess (logging::value_ref< severity_level, tag::a_severity > const& l) { return l <= ProcessLog_level; }
	*/
	inline bool Logging (severity_level l, severity_level r) { return r <= l; }

	inline bool LabelBasedFilter
	(
	 logging::value_ref< tag::a_channel::value_type, tag::a_channel > const& channel,
	 logging::value_ref< tag::a_severity::value_type, tag::a_severity > const& severity
	 )
	{
	    const severity_level* threshold = NULL;

	    if (channel)
		{
		    LabelToLevel_t::const_iterator it = LabelToLevel.find(channel.get());
		    if (it != LabelToLevel.end())
			threshold = it->second;
		}

	    if (!threshold)
		threshold = &DefaultLog_level;

	    return severity <= *threshold;
	}

	inline boost::shared_ptr< Sink_t > prepare () {
	    depth = 24;
	    boost::shared_ptr< logging::core > core = logging::core::get();

	    // Wrap backend in to the frontend
	    boost::shared_ptr< Sink_t > sink(new Sink_t());
	    core->add_sink(sink);

	    // This works:
	    /*
	      core->set_filter
	      (
	      (a_channel == ""           && boost::phoenix::bind(&GTDefault,    a_severity.or_throw())) ||
	      (a_channel == "Rewrite"    && boost::phoenix::bind(&GTRewrite,    a_severity.or_throw())) ||
	      (a_channel == "I/O"        && boost::phoenix::bind(&GTIO,         a_severity.or_throw())) ||
	      (a_channel == "Parsing"    && boost::phoenix::bind(&GTParsing,    a_severity.or_throw())) ||
	      (a_channel == "GraphMatch" && boost::phoenix::bind(&GTGraphMatch, a_severity.or_throw())) ||
	      (a_channel == "SQL"        && boost::phoenix::bind(&GTSQL,        a_severity.or_throw())) ||
	      (a_channel == "Service"    && boost::phoenix::bind(&GTService,    a_severity.or_throw())) ||
	      (a_channel == "Process"    && boost::phoenix::bind(&GTProcess,    a_severity.or_throw()))
	      );
	    */
	    // But this looks simpler:
	    core->set_filter(boost::phoenix::bind(&LabelBasedFilter, a_channel.or_none(), a_severity.or_throw()));
	    // Also, take a look at this: http://www.boost.org/doc/libs/1_55_0/libs/log/doc/html/log/detailed/expressions.html#log.detailed.expressions.predicates.channel_severity_filter

	    { // Begin: lock backend
		Sink_t::locked_backend_ptr backend = sink->locked_backend();
		// backend->add_stream(boost::shared_ptr< std::ostream >(&std::clog, boost::empty_deleter()));
		core->add_sink(sink);

		sink->set_formatter(boost::phoenix::bind(&myFormatter, boost::log::expressions::stream, boost::log::expressions::record));
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
			} catch (boost::bad_lexical_cast&) {
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
		core->add_global_attribute(a_scope.get_name(),
					   boost::log::attributes::named_scope());
	    if (false)
		core->add_global_attribute(a_thread_id.get_name(),
					   boost::log::attributes::current_thread_id());

	    // Add some attributes too
	    if (false)
		core->add_global_attribute(a_timestamp.get_name(),
					   boost::log::attributes::utc_clock());
	    if (false)
		core->add_global_attribute(a_line_id.get_name(),
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
			      (os, BOOST_NULL_DELETER()));

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
