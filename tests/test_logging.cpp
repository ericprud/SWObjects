// Copyright 2011 Stackjet Inc. (sean at stackjet dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// g++ -o test_logging test_logging.cpp -DBOOST_TEST_DYN_LINK -I. -Iboost-log -g -O0 -W -Wextra -Wnon-virtual-dtor -ansi -std=c++98 -Lboost-log/stage/lib -lboost_log -lboost_date_time -lboost_filesystem -lboost_system -lboost_thread -lpthread -lboost_unit_test_framework-mt && LD_LIBRARY_PATH=boost-log/stage/lib ./test_logging

#include "config.h"

#define BOOST_TEST_MODULE logging
#include <boost/test/unit_test.hpp>

#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>

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


#ifdef _MSC_VER
  #include <windows.h>
  typedef DWORD useconds_t;
  #define usleep(X) Sleep(X)
#endif /* _MSC_VER */

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
} /* namespace Logger */

namespace Logger {
    const char* ATTR_Timeline = "Timeline";
    const char* ATTR_Scope = "Scope";
    const char* ATTR_ThreadID = "ThreadID";
    const char* ATTR_LineId = "LineId";
    const char* ATTR_Timestamp = "Timestamp";
    const char* ATTR_Channel = "Channel";
} /* namespace Logger */


namespace logging = boost::log;
namespace attrs = boost::log::attributes;

#include "prfxbuf.hpp"

//! This function is executed in multiple threads
void
thread_fun(boost::barrier& bar, const useconds_t rand_sleep) {
  // Wait until all threads are created
  bar.wait();

  BOOST_LOG_SCOPED_LOGGER_ATTR(Logger::GraphMatch::get(), Logger::ATTR_Timeline, attrs::timer);

  // BOOST_LOG_SCOPED_THREAD_ATTR_CTOR(Logger::ATTR_Scope, attrs::constant< std::string >, ("Scope is thread_fun"));

  int log_state = 0;

  // Now, do some logging
  for (unsigned int i = 0; i < LOG_RECORDS_TO_WRITE; ++i) {
    switch (log_state) {
      case 0: {
        BOOST_LOG_SEV(Logger::GraphMatch::get(), warning) << "Log record " << i;
        ++log_state;
        break;
      }
      case 1: {
	  BOOST_LOG_SEV(Logger::Net::get(), support) << "Log record " << i << std::endl << "Line2\nLine3";
        ++log_state;
        break;
      }
      default:
        BOOST_LOG_SEV(Logger::Default::get(), admin) << "Log record " << i;
        log_state = 0;
    }
    ::usleep(rand_sleep);
  }
}

void myFormatter(std::ostream& strm, logging::record const& rec)
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

BOOST_AUTO_TEST_CASE( a ) {
    int& argc = boost::unit_test::framework::master_test_suite().argc;
    char** argv = boost::unit_test::framework::master_test_suite().argv;

    boost::filesystem::path argv0(argv[0]);
    boost::filesystem::path logFile(argv0.filename() + "_%2N.log");
    std::cout << "logFile: " << logFile << "\n";
  try {
    boost::shared_ptr< logging::core > core = logging::core::get();

    // Add a global scope attribute
    if (false)
	core->add_global_attribute(Logger::ATTR_Scope, attrs::named_scope());
    if (false)
	core->add_global_attribute(Logger::ATTR_ThreadID, attrs::current_thread_id());


    // Add some attributes too
    if (false)
	core->add_global_attribute(Logger::ATTR_Timestamp, attrs::utc_clock());
    if (false)
	core->add_global_attribute(Logger::ATTR_LineId, attrs::counter< unsigned int >());


    typedef boost::log::sinks::synchronous_sink< boost::log::sinks::text_ostream_backend > SparqlAppSync;

    // Wrap backend in to the frontend
    boost::shared_ptr< SparqlAppSync > sink(new SparqlAppSync());
    core->add_sink(sink);

    { // Begin: lock backend
      SparqlAppSync::locked_backend_ptr backend = sink->locked_backend();
      backend->add_stream(
      boost::shared_ptr< std::ostream >(&std::clog, logging::empty_deleter()));
      backend->add_stream(
        boost::shared_ptr< std::ostream >(new std::ofstream("toy-alt.log")));

      core->add_sink(sink);

      backend->set_formatter(&myFormatter);

    } // End: Locked backend


    // Only initialize the random number generator once
    typedef boost::minstd_rand base_generator_type;
    base_generator_type generator(42u);
    typedef boost::uniform_int<useconds_t> usleep_rand_type;
    typedef boost::variate_generator<base_generator_type&, usleep_rand_type> gen_type;
    gen_type usleep_rand_gen(generator, usleep_rand_type(USLEEP_MIN, USLEEP_MAX));


    // Create logging threads
    boost::barrier bar(THREAD_COUNT);
    boost::thread_group threads;
    for (unsigned int i = 0; i < THREAD_COUNT; ++i) {
      useconds_t usleep_time = usleep_rand_gen();
      std::cerr << boost::format("Thread sleeping for: %1%us\n") % usleep_time;
      threads.create_thread(boost::bind(&thread_fun, boost::ref(bar), usleep_time));
    }

    // Wait until all action ends
    threads.join_all();

  } catch (std::exception& e) {
    std::cout << "FAILURE: " << e.what() << std::endl;
  }
}
