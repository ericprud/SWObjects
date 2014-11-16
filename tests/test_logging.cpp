// Copyright 2011 Stackjet Inc. (sean at stackjet dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// g++ -o test_logging test_logging.cpp -DBOOST_TEST_DYN_LINK -I. -Iboost-log -g -O0 -W -Wextra -Wnon-virtual-dtor -ansi -std=c++98 -Lboost-log/stage/lib -lboost_log -lboost_date_time -lboost_filesystem -lboost_system -lboost_thread -lpthread -lboost_unit_test_framework-mt && LD_LIBRARY_PATH=boost-log/stage/lib ./test_logging

#include "SWObjects.hpp"
#if (BOOST_VERSION == 105400)
# include <boost/log/utility/empty_deleter.hpp>
# define EMPTY_DELETER boost::log::empty_deleter
#else
# include <boost/utility/empty_deleter.hpp>
# define EMPTY_DELETER boost::empty_deleter
#endif

#define BOOST_TEST_MODULE logging
#include <boost/test/unit_test.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>

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

namespace w3c_sw {

    //! This function is executed in multiple threads
    void
    thread_fun(boost::barrier& bar, const useconds_t rand_sleep) {
	// Wait until all threads are created
	bar.wait();

	int log_state = 0;

	// Now, do some logging
	for (unsigned int i = 0; i < LOG_RECORDS_TO_WRITE; ++i) {
	    switch (log_state) {
	    case 0: {
		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::warning) << "Log record " << i << "\nLine 1      ";
		++log_state;
		break;
	    }
	    case 1: {
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::support) << "Log record " << i;
		++log_state;
		break;
	    }
	    default:
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::admin) << "Log record " << i;
		log_state = 0;
	    }
	    ::usleep(rand_sleep);
	}
    }

    BOOST_AUTO_TEST_CASE( a ) {
	int& argc = boost::unit_test::framework::master_test_suite().argc;
	char** argv = boost::unit_test::framework::master_test_suite().argv;

	boost::filesystem::path argv0(argv[0]);
	boost::filesystem::path logFile(argv0.filename().native() + "_%2N.log");
	std::cout << "logFile: " << logFile << "\n";
	try {

	    boost::shared_ptr< Logger::Sink_t > sink = Logger::prepare();
	    Logger::addStream(sink, boost::shared_ptr< std::ostream >(&std::clog, EMPTY_DELETER()));
	    Logger::addStream(sink, boost::shared_ptr< std::ostream >(new std::ofstream("toy-alt.log")));
	    boost::shared_ptr< boost::log::core > core = boost::log::core::get();

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

} // namespace w3c_sw

