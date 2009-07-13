/* perform SPARUL tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE SPARUL_tests
#include "../tests/SparqlQueryTestResultSet.hpp"

BOOST_AUTO_TEST_SUITE( insert )
BOOST_AUTO_TEST_CASE( insert0 ) {
    GRAPH_TEST(NULL, "sparul/insert0.rq", "sparul/insert0.trg");
}
BOOST_AUTO_TEST_SUITE_END(/* insert */)

BOOST_AUTO_TEST_SUITE( _delete )
BOOST_AUTO_TEST_CASE( delete0 ) {
    GRAPH_TEST("sparul/insert0.trg", "sparul/delete0.rq", NULL);
}
BOOST_AUTO_TEST_SUITE_END(/* _delete */)


BOOST_AUTO_TEST_CASE( test_fail ) {
    BOOST_CHECK_EQUAL(1, 0);
}
BOOST_AUTO_TEST_CASE( test_succeed ) {
    BOOST_CHECK_EQUAL(1, 1);
}
// EOF

