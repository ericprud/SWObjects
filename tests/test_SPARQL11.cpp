/* perform SPARQL 1.1 tests.
 * call from: ..
 * files: <tests>/sparql11
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE SPARQL11_tests
#include "../tests/SPARQLTest.hpp"

BOOST_AUTO_TEST_SUITE( subselect )
BOOST_AUTO_TEST_CASE( subselect_01 ) {
    /* name: 
     * 
     */
    const char* defaultGraph( "sparql11/subselect-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/subselect-01.rq", "sparql11/subselect-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subselect_02 ) {
    /* name: 
     * 
     */
    const char* defaultGraph( "sparql11/subselect-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/subselect-02.rq", "sparql11/subselect-02.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* subselect */)


// EOF

