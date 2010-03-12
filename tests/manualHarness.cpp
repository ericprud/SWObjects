/* manualHarness - emulate the boost unit test environment for testing with valgrind.

 * $Id$
 */

#define BOOST_AUTO_TEST_CASE(name) void name ()
#define BOOST_AUTO_TEST_SUITE(name) namespace name {
#define BOOST_AUTO_TEST_SUITE_END() }
#define BOOST_CHECK_EQUAL(l, r) assert(l == r)
#define BOOST_TEST_CHECKPOINT(s) std::cout << s << std::endl
#define BOOST_CHECK_MESSAGE(test, message) if (test) std::cout << message
namespace boost { namespace unit_test { namespace framework {
	    struct Args { int argc; char** argv; };
	    Args TheArgs;
	    Args master_test_suite () { return TheArgs; }
	} } }
#define MANUAL_TEST
/* #include test file.cpp */

int main (int argc, char** argv) {
    boost::unit_test::framework::TheArgs.argc = argc;
    boost::unit_test::framework::TheArgs.argv = argv;
    /* tests(); */
    return 0;
}

