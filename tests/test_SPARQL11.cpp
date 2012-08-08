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
BOOST_AUTO_TEST_CASE( not_not_exists ) {
    /* name: 
     * 
     */
    const char* defaultGraph( "sparql11/exists-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/not-not-exists.rq", "sparql11/not-not-exists.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( count_star ) {
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
+--------+
| ?count |
|      3 |
+--------+
     */
    GRAPH_TEST(NULL, "sparql11/count-star.rq", "sparql11/count-star.srx");
}
BOOST_AUTO_TEST_CASE( nestedAggregates ) {
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
+--------+
| ?count |
|      3 |
+--------+
     */
    GRAPH_TEST(NULL, "sparql11/ia-nestedAggregates.rq", "sparql11/ia-nestedAggregates.srt");
}
BOOST_AUTO_TEST_CASE( count_star_groupBy_v ) {
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
+----+--------+
| ?a | ?count |
|  1 |      3 |
+----+--------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-v.rq", "sparql11/groupBy-v.srx");
}
BOOST_AUTO_TEST_CASE( count_a_groupBy_v ) {
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
+----+--------+
| ?a | ?count |
|  1 |      3 |
+----+--------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-v.rq", "sparql11/groupBy-v.srx");
}
BOOST_AUTO_TEST_CASE( groupBy_v_AS ) {
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
+----+--------+
| ?x | ?count |
|  1 |      3 |
+----+--------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-v-AS.rq", "sparql11/groupBy-v-AS.srx");
}
BOOST_AUTO_TEST_CASE( groupBy_f ) {
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
    GRAPH_TEST(NULL, "sparql11/groupBy-f.rq", "sparql11/groupBy-f.srx");
}
BOOST_AUTO_TEST_CASE( groupBy_f_having_f ) {
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
    GRAPH_TEST(NULL, "sparql11/groupBy-f-having-f.rq", "sparql11/groupBy-f-having-f.srx");
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

BOOST_AUTO_TEST_SUITE( bindings_and_bind )
BOOST_AUTO_TEST_CASE( _1 ) {
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
+----+----+----+----+
| ?a | ?b | ?c | ?d |
|  1 | 10 |  2 |  9 |
|  1 |  9 |  3 |  7 |
|  1 | 11 |  4 |  8 |
+----+----+----+----+
     */
    GRAPH_TEST(NULL, "sparql11/bind_1.rq", "sparql11/bind_1.srx");
}
BOOST_AUTO_TEST_SUITE_END(/* bind */)


// EOF

