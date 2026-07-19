/** LoggingFacade: the lightweight logging interface used throughout the
 * library. Call sites write
 *
 *   w3c_sw_LOG(ParsingLog, Logger::engineer) << "message";
 *
 * which evaluates its arguments only when a sink is prepared AND the
 * channel's level admits the severity. The Boost.Log machinery (sinks,
 * formatting, level-string parsing) lives behind this facade in
 * Logging.hpp / Logging.cpp, so translation units that only *emit* log
 * records never see Boost.Log headers.
 */

#ifndef LOGGING_FACADE_HH
# define LOGGING_FACADE_HH

#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

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

	/** The eight log channels. The _c suffix keeps the names clear of
	 * the Boost.Log global logger types (DefaultLog etc.) declared in
	 * Logging.hpp. */
	enum Channel {
	    DefaultLog_c, RewriteLog_c, IOLog_c, ParsingLog_c,
	    GraphMatchLog_c, SQLLog_c, ServiceLog_c, ProcessLog_c
	};

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

	/** True once Logger::prepare() has attached a sink. Records are
	 * neither built nor filtered before that. */
	extern bool sinkActive;

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

	inline bool Logging (severity_level l, severity_level r) { return r <= l; }

	inline severity_level& levelFor (Channel ch) {
	    switch (ch) {
	    case RewriteLog_c:    return RewriteLog_level;
	    case IOLog_c:         return IOLog_level;
	    case ParsingLog_c:    return ParsingLog_level;
	    case GraphMatchLog_c: return GraphMatchLog_level;
	    case SQLLog_c:        return SQLLog_level;
	    case ServiceLog_c:    return ServiceLog_level;
	    case ProcessLog_c:    return ProcessLog_level;
	    case DefaultLog_c:
	    default:              return DefaultLog_level;
	    }
	}

	inline bool enabled (Channel ch, severity_level lvl) {
	    return sinkActive && lvl <= levelFor(ch);
	}

	/** Hand a completed record to the Boost.Log backend (Logging.cpp). */
	void emit (Channel ch, severity_level lvl, const std::string& msg);

	/** One log record: buffers the streamed message and emits it on
	 * destruction (end of the full expression at the call site). */
	class LogRecord {
	    Channel ch;
	    severity_level lvl;
	    std::ostringstream ss;
	public:
	    LogRecord (Channel ch, severity_level lvl) : ch(ch), lvl(lvl) {  }
	    ~LogRecord () { emit(ch, lvl, ss.str()); }
	    std::ostream& stream () { return ss; }
	};

    } /* namespace Logger */

/* The definitions of the Logger globals live in SWObjects.cpp (see the
 * invocation there); an #ifdef-conditional block here would be skipped
 * when this header is precompiled. */
#define w3c_sw_DEFINE_LOGGER_GLOBALS \
    namespace w3c_sw { \
    namespace Logger { \
	int depth; \
\
	severity_level DefaultLog_level; \
	severity_level RewriteLog_level; \
	severity_level IOLog_level; \
	severity_level ParsingLog_level; \
	severity_level GraphMatchLog_level; \
	severity_level SQLLog_level; \
	severity_level ServiceLog_level; \
	severity_level ProcessLog_level; \
\
	LabelToLevel_t LabelToLevel; \
	std::vector<const char*> Labels; \
	namespace { \
	    LabelInitializer TheLabelInitializer; \
	} \
    } /* namespace Logger */ \
    } /* namespace w3c_sw */

} // namespace w3c_sw

/** Emit a log record on a channel at a severity; the streamed expression
 * is evaluated only when the record would be delivered. */
#define w3c_sw_LOG(CHANNEL, LVL) \
    if (!::w3c_sw::Logger::enabled(::w3c_sw::Logger::CHANNEL##_c, LVL)) {} \
    else ::w3c_sw::Logger::LogRecord(::w3c_sw::Logger::CHANNEL##_c, LVL).stream()

#endif /* ! defined LOGGING_FACADE_HH */
