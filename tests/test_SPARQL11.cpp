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
BOOST_AUTO_TEST_CASE( subselect_03 ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+---------+------------+----------------+
| ?bPlusC | ?sumBPlusC | ?oneMinusCount |
|      12 |         24 |             -1 |
|      15 |         15 |              0 |
+---------+------------+----------------+
     */
    const char* defaultGraph( "sparql11/subselect-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/subselect-03.rq", "sparql11/subselect-03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subselect_04 ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+---------+------------+----------------+
| ?bPlusC | ?sumBPlusC | ?oneMinusCount |
|      12 |         24 |             -1 |
+---------+------------+----------------+
     */
    GRAPH_TEST(NULL, "sparql11/subselect-04.rq", "sparql11/subselect-04.srx");
}
BOOST_AUTO_TEST_CASE( ext_select_expr_01 ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+---------+--------------+----------------+
| ?bPlusC | "SUM(?b+?c)" | ?oneMinusCount |
|      12 |           24 |             -1 |
+---------+--------------+----------------+
     */
    GRAPH_TEST(NULL, "sparql11/ext_select_expr-01.rq", "sparql11/ext_select_expr-01.srt");
}
BOOST_AUTO_TEST_SUITE_END(/* subselect */)


// EOF

