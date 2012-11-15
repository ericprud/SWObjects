/* perform SPARQL 1.1 tests.
 * call from: ..
 * files: <tests>/sparql11
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE SPARQL11_tests
#include "../tests/SPARQLTest.hpp"

w3c_sw_DEBUGGING_FUNCTIONS();

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
    // !! incompatible with final SPARQL aggregate semantics: GRAPH_TEST(NULL, "sparql11/ext_select_expr-01.rq", "sparql11/ext_select_expr-01.srt");
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


BOOST_AUTO_TEST_SUITE( generators )
BOOST_AUTO_TEST_CASE( olist ) {
    const char* defaultGraph( "generators/olist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/olist.rq", "generators/olist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( slist ) {
    const char* defaultGraph( "generators/slist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/slist.rq", "generators/slist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( solist ) {
    const char* defaultGraph( "generators/solist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist ) {
    const char* defaultGraph( "generators/namedsolist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_seq ) {
    const char* defaultGraph( "generators/namedsolist_p1_p2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_p1_p2.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_inv ) {
    const char* defaultGraph( "generators/namedsolist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_inv_p1.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_inv_seq ) {
    const char* defaultGraph( "generators/namedsolist_p1_p2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_inv__p1_p2.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_inv_p1__p2 ) {
    const char* defaultGraph( "generators/namedsolist_inv_p1__p2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_inv_p1__p2.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* generators */)


BOOST_AUTO_TEST_SUITE( SPARQL11_WG )
// Popluate with:
// tests$ sparql -d data-sparql11/manifest-all.ttl -e '
// PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
// PREFIX qt: <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
// PREFIX dawgt: <http://www.w3.org/2001/sw/DataAccess/tests/test-dawg#>
// PREFIX fn: <http://www.w3.org/2005/xpath-functions#>
// SELECT (CONCAT(
// "BOOST_AUTO_TEST_CASE( ", ?id, " ) {\n",
// "    /* name: ", ?name, " */\n",
// "    const char* defaultGraph( ", IF(BOUND(?data), CONCAT("\"", STR(?data), "\""), "NULL"), ");\n",
// "    const char*", IF(BOUND(?graph1), CONCAT(" namedGraphs[] = {", "\"", STR(?graph1), "\"", IF(BOUND(?graph2), CONCAT(", \"", STR(?graph2), "\""), ""), IF(BOUND(?graph3), CONCAT(", \"", STR(?graph3), "\""), ""), "}"), "* namedGraphs = NULL"), ";\n",
// "    const URI** requires = NULL;\n",
// "    DAWG_TEST(\"", STR(?query), "\", \"", STR(?result), "\", ", IF(BOUND(?graph1), IF(BOUND(?graph2), IF(BOUND(?graph3), "3", "2"), "1"), "0"), ", 0);\n",
// "}\n"
// ) AS ?unittest) {
//   {
//     <http://www.w3.org/TR/sparql11-query/> mf:conformanceRequirement MEMBERS(?manifest)
//   }
//   GRAPH ?manifest {
//     ?s a mf:Manifest ;
//        mf:entries MEMBERS(?entry) .
//     ?entry a mf:QueryEvaluationTest ;
//            mf:name ?name ;
//            dawgt:approval dawgt:Approved ;
//            mf:action ?action
//   }
//   OPTIONAL { GRAPH ?manifest { ?action qt:query ?query } }
//   OPTIONAL { GRAPH ?manifest { ?action qt:data ?data } }
//   OPTIONAL { GRAPH ?manifest { ?action qt:graphData ?graph1 OPTIONAL { ?action qt:graphData ?graph9 FILTER (?graph9 < ?graph1) } FILTER (!BOUND(?graph9)) } }
//   OPTIONAL { GRAPH ?manifest { ?action qt:graphData ?graph2 OPTIONAL { ?action qt:graphData ?graph8, ?graph7 FILTER (?graph8 < ?graph7 && ?graph7 < ?graph2) } FILTER (!BOUND(?graph8)) } FILTER (?graph2 > ?graph1) }
//   OPTIONAL { GRAPH ?manifest { ?action qt:graphData ?graph3 } FILTER (?graph3 > ?graph2) }
//   OPTIONAL { GRAPH ?manifest { ?entry mf:result ?result } }
//   BIND (fn:replace(strafter(str(?entry), "#"), "-", "_") AS ?id)
// }' -L text/raw

BOOST_AUTO_TEST_CASE( agg01 ) {
    /* name: COUNT 1 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg01.rq", "data-sparql11/aggregates/agg01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg02 ) {
    /* name: COUNT 2 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg02.rq", "data-sparql11/aggregates/agg02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg03 ) {
    /* name: COUNT 3 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg03.rq", "data-sparql11/aggregates/agg03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg04 ) {
    /* name: COUNT 4 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg04.rq", "data-sparql11/aggregates/agg04.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg05 ) {
    /* name: COUNT 5 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg05.rq", "data-sparql11/aggregates/agg05.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg06 ) {
    /* name: COUNT 6 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg06.rq", "data-sparql11/aggregates/agg06.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg07 ) {
    /* name: COUNT 7 */
    const char* defaultGraph( "data-sparql11/aggregates/agg01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg07.rq", "data-sparql11/aggregates/agg07.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg08b ) {
    /* name: COUNT 8b */
    const char* defaultGraph( "data-sparql11/aggregates/agg08.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg08b.rq", "data-sparql11/aggregates/agg08b.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_groupconcat_01 ) {
    /* name: GROUP_CONCAT 1 */
    const char* defaultGraph( "data-sparql11/aggregates/agg-groupconcat-1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-groupconcat-1.rq", "data-sparql11/aggregates/agg-groupconcat-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_groupconcat_02 ) {
    /* name: GROUP_CONCAT 2 */
    const char* defaultGraph( "data-sparql11/aggregates/agg-groupconcat-1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-groupconcat-2.rq", "data-sparql11/aggregates/agg-groupconcat-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_groupconcat_03 ) {
    /* name: GROUP_CONCAT with SEPARATOR */
    const char* defaultGraph( "data-sparql11/aggregates/agg-groupconcat-1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-groupconcat-3.rq", "data-sparql11/aggregates/agg-groupconcat-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_sum_01 ) {
    /* name: SUM */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-sum-01.rq", "data-sparql11/aggregates/agg-sum-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_sum_02 ) {
    /* name: SUM with GROUP BY */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-sum-02.rq", "data-sparql11/aggregates/agg-sum-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_avg_01 ) {
    /* name: AVG */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-avg-01.rq", "data-sparql11/aggregates/agg-avg-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_avg_02 ) {
    /* name: AVG with GROUP BY */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-avg-02.rq", "data-sparql11/aggregates/agg-avg-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_min_01 ) {
    /* name: MIN */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-min-01.rq", "data-sparql11/aggregates/agg-min-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_min_02 ) {
    /* name: MIN with GROUP BY */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-min-02.rq", "data-sparql11/aggregates/agg-min-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_max_01 ) {
    /* name: MAX */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-max-01.rq", "data-sparql11/aggregates/agg-max-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_max_02 ) {
    /* name: MAX with GROUP BY */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-max-02.rq", "data-sparql11/aggregates/agg-max-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_sample_01 ) {
    /* name: SAMPLE */
    const char* defaultGraph( "data-sparql11/aggregates/agg-numeric.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-sample-01.rq", "data-sparql11/aggregates/agg-sample-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_err_01 ) {
    /* name: Error in AVG */
    const char* defaultGraph( "data-sparql11/aggregates/agg-err-01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-err-01.rq", "data-sparql11/aggregates/agg-err-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_err_02 ) {
    /* name: Protect from error in AVG */
    const char* defaultGraph( "data-sparql11/aggregates/agg-err-02.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-err-02.rq", "data-sparql11/aggregates/agg-err-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( agg_empty_group ) {
    /* name: agg empty group */
    const char* defaultGraph( "data-sparql11/aggregates/empty.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/aggregates/agg-empty-group.rq", "data-sparql11/aggregates/agg-empty-group.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind01 ) {
    /* name: bind01 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind01.rq", "data-sparql11/bind/bind01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind02 ) {
    /* name: bind02 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind02.rq", "data-sparql11/bind/bind02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind03 ) {
    /* name: bind03 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind03.rq", "data-sparql11/bind/bind03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind04 ) {
    /* name: bind04 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind04.rq", "data-sparql11/bind/bind04.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind05 ) {
    /* name: bind05 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind05.rq", "data-sparql11/bind/bind05.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind06 ) {
    /* name: bind06 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind06.rq", "data-sparql11/bind/bind06.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind07 ) {
    /* name: bind07 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind07.rq", "data-sparql11/bind/bind07.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind08 ) {
    /* name: bind08 - BIND */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind08.rq", "data-sparql11/bind/bind08.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind10 ) {
    /* name: bind10 - BIND scoping - Variable in filter not in scope */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind10.rq", "data-sparql11/bind/bind10.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bind11 ) {
    /* name: bind11 - BIND scoping - Variable in filter in scope */
    const char* defaultGraph( "data-sparql11/bind/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bind/bind11.rq", "data-sparql11/bind/bind11.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values1 ) {
    /* name: Post-query VALUES with subj-var, 1 row */
    const char* defaultGraph( "data-sparql11/bindings/data01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values01.rq", "data-sparql11/bindings/values01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values2 ) {
    /* name: Post-query VALUES with obj-var, 1 row */
    const char* defaultGraph( "data-sparql11/bindings/data02.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values02.rq", "data-sparql11/bindings/values02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values3 ) {
    /* name: Post-query VALUES with 2 obj-vars, 1 row */
    const char* defaultGraph( "data-sparql11/bindings/data03.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values03.rq", "data-sparql11/bindings/values03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values4 ) {
    /* name: Post-query VALUES with 2 obj-vars, 1 row with UNDEF */
    const char* defaultGraph( "data-sparql11/bindings/data04.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values04.rq", "data-sparql11/bindings/values04.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values5 ) {
    /* name: Post-query VALUES with 2 obj-vars, 2 rows with UNDEF */
    const char* defaultGraph( "data-sparql11/bindings/data05.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values05.rq", "data-sparql11/bindings/values05.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values6 ) {
    /* name: Post-query VALUES with pred-var, 1 row */
    const char* defaultGraph( "data-sparql11/bindings/data06.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values06.rq", "data-sparql11/bindings/values06.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values7 ) {
    /* name: Post-query VALUES with (OPTIONAL) obj-var, 1 row */
    const char* defaultGraph( "data-sparql11/bindings/data07.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values07.rq", "data-sparql11/bindings/values07.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( values8 ) {
    /* name: Post-query VALUES with subj/obj-vars, 2 rows with UNDEF */
    const char* defaultGraph( "data-sparql11/bindings/data08.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/values08.rq", "data-sparql11/bindings/values08.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( inline1 ) {
    /* name: Inline VALUES graph pattern */
    const char* defaultGraph( "data-sparql11/bindings/data01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/inline01.rq", "data-sparql11/bindings/inline01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( inline2 ) {
    /* name: Post-subquery VALUES */
    const char* defaultGraph( "data-sparql11/bindings/data02.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/bindings/inline02.rq", "data-sparql11/bindings/inline02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( constructwhere01 ) {
    /* name: constructwhere01 - CONSTRUCT WHERE */
    const char* defaultGraph( "data-sparql11/construct/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/construct/constructwhere01.rq", "data-sparql11/construct/constructwhere01result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( constructwhere02 ) {
    /* name: constructwhere02 - CONSTRUCT WHERE */
    const char* defaultGraph( "data-sparql11/construct/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/construct/constructwhere02.rq", "data-sparql11/construct/constructwhere02result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( constructwhere03 ) {
    /* name: constructwhere03 - CONSTRUCT WHERE */
    const char* defaultGraph( "data-sparql11/construct/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/construct/constructwhere03.rq", "data-sparql11/construct/constructwhere03result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( constructwhere04 ) {
    /* name: constructwhere04 - CONSTRUCT WHERE */
    const char* defaultGraph( NULL);
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/construct/constructwhere04.rq", "data-sparql11/construct/constructwhere04result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( exists01 ) {
    /* name: Exists with one constant */
    const char* defaultGraph( "data-sparql11/exists/exists01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/exists/exists01.rq", "data-sparql11/exists/exists01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( exists02 ) {
    /* name: Exists with ground triple */
    const char* defaultGraph( "data-sparql11/exists/exists01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/exists/exists02.rq", "data-sparql11/exists/exists02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( exists03 ) {
    /* name: Exists within graph pattern */
    const char* defaultGraph( "data-sparql11/exists/exists01.ttl");
    const char* namedGraphs[] = {"data-sparql11/exists/exists02.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/exists/exists03.rq", "data-sparql11/exists/exists03.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( exists04 ) {
    /* name: Nested positive exists */
    const char* defaultGraph( "data-sparql11/exists/exists01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/exists/exists04.rq", "data-sparql11/exists/exists04.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( exists05 ) {
    /* name: Nested negative exists in positive exists */
    const char* defaultGraph( "data-sparql11/exists/exists01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/exists/exists05.rq", "data-sparql11/exists/exists05.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strdt01 ) {
    /* name: STRDT() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strdt01.rq", "data-sparql11/functions/strdt01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strdt02 ) {
    /* name: STRDT(STR()) */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strdt02.rq", "data-sparql11/functions/strdt02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strdt03 ) {
    /* name: STRDT() TypeErrors */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strdt03.rq", "data-sparql11/functions/strdt03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strlang01 ) {
    /* name: STRLANG() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strlang01.rq", "data-sparql11/functions/strlang01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strlang02 ) {
    /* name: STRLANG(STR()) */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strlang02.rq", "data-sparql11/functions/strlang02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strlang03 ) {
    /* name: STRLANG() TypeErrors */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strlang03.rq", "data-sparql11/functions/strlang03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( isnumeric01 ) {
    /* name: isNumeric() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/isnumeric01.rq", "data-sparql11/functions/isnumeric01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( abs01 ) {
    /* name: ABS() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/abs01.rq", "data-sparql11/functions/abs01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( ceil01 ) {
    /* name: CEIL() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/ceil01.rq", "data-sparql11/functions/ceil01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( floor01 ) {
    /* name: FLOOR() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/floor01.rq", "data-sparql11/functions/floor01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( round01 ) {
    /* name: ROUND() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/round01.rq", "data-sparql11/functions/round01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( concat01 ) {
    /* name: CONCAT() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/concat01.rq", "data-sparql11/functions/concat01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( concat02 ) {
    /* name: CONCAT() 2 */
    const char* defaultGraph( "data-sparql11/functions/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/concat02.rq", "data-sparql11/functions/concat02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( substring01 ) {
    /* name: SUBSTR() (3-argument) */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/substring01.rq", "data-sparql11/functions/substring01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( substring02 ) {
    /* name: SUBSTR() (2-argument) */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/substring02.rq", "data-sparql11/functions/substring02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( length01 ) {
    /* name: STRLEN() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/length01.rq", "data-sparql11/functions/length01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( ucase01 ) {
    /* name: UCASE() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/ucase01.rq", "data-sparql11/functions/ucase01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( lcase01 ) {
    /* name: LCASE() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/lcase01.rq", "data-sparql11/functions/lcase01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( encode01 ) {
    /* name: ENCODE_FOR_URI() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/encode01.rq", "data-sparql11/functions/encode01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( contains01 ) {
    /* name: CONTAINS() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/contains01.rq", "data-sparql11/functions/contains01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( starts01 ) {
    /* name: STRSTARTS() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/starts01.rq", "data-sparql11/functions/starts01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( ends01 ) {
    /* name: STRENDS() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/ends01.rq", "data-sparql11/functions/ends01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( plus_1 ) {
    /* name: plus-1 */
    const char* defaultGraph( "data-sparql11/functions/data-builtin-3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/plus-1.rq", "data-sparql11/functions/plus-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( plus_2 ) {
    /* name: plus-2 */
    const char* defaultGraph( "data-sparql11/functions/data-builtin-3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/plus-2.rq", "data-sparql11/functions/plus-2.srx", 0, 0);
}
#ifdef CRYPT_LIB
BOOST_AUTO_TEST_CASE( md5_01 ) {
    /* name: MD5() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/md5-01.rq", "data-sparql11/functions/md5-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( md5_02 ) {
    /* name: MD5() over Unicode data */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/md5-02.rq", "data-sparql11/functions/md5-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( sha1_01 ) {
    /* name: SHA1() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/sha1-01.rq", "data-sparql11/functions/sha1-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( sha1_02 ) {
    /* name: SHA1() on Unicode data */
    const char* defaultGraph( "data-sparql11/functions/hash-unicode.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/sha1-02.rq", "data-sparql11/functions/sha1-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( sha256_01 ) {
    /* name: SHA256() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/sha256-01.rq", "data-sparql11/functions/sha256-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( sha256_02 ) {
    /* name: SHA256() on Unicode data */
    const char* defaultGraph( "data-sparql11/functions/hash-unicode.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/sha256-02.rq", "data-sparql11/functions/sha256-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( sha512_01 ) {
    /* name: SHA512() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/sha512-01.rq", "data-sparql11/functions/sha512-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( sha512_02 ) {
    /* name: SHA512() on Unicode data */
    const char* defaultGraph( "data-sparql11/functions/hash-unicode.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/sha512-02.rq", "data-sparql11/functions/sha512-02.srx", 0, 0);
}
#endif /* CRYPT_LIB */
BOOST_AUTO_TEST_CASE( minutes ) {
    /* name: MINUTES() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/minutes-01.rq", "data-sparql11/functions/minutes-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( seconds ) {
    /* name: SECONDS() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/seconds-01.rq", "data-sparql11/functions/seconds-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( hours ) {
    /* name: HOURS() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/hours-01.rq", "data-sparql11/functions/hours-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( month ) {
    /* name: MONTH() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/month-01.rq", "data-sparql11/functions/month-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( year ) {
    /* name: YEAR() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/year-01.rq", "data-sparql11/functions/year-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( day ) {
    /* name: DAY() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/day-01.rq", "data-sparql11/functions/day-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( timezone ) {
    /* name: TIMEZONE() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/timezone-01.rq", "data-sparql11/functions/timezone-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( tz ) {
    /* name: TZ() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/tz-01.rq", "data-sparql11/functions/tz-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bnode01 ) {
    /* name: BNODE(str) */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/bnode01.rq", "data-sparql11/functions/bnode01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( bnode02 ) {
    /* name: BNODE() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/bnode02.rq", "data-sparql11/functions/bnode02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( in01 ) {
    /* name: IN 1 */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/in01.rq", "data-sparql11/functions/in01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( in02 ) {
    /* name: IN 2 */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/in02.rq", "data-sparql11/functions/in02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( notin01 ) {
    /* name: NOT IN 1 */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/notin01.rq", "data-sparql11/functions/notin01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( notin02 ) {
    /* name: NOT IN 2 */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/notin02.rq", "data-sparql11/functions/notin02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( now01 ) {
    /* name: NOW() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/now01.rq", "data-sparql11/functions/now01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( rand01 ) {
    /* name: RAND() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/rand01.rq", "data-sparql11/functions/rand01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( iri01 ) {
    /* name: IRI()/URI() */
    const char* defaultGraph( "data-sparql11/functions/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/iri01.rq", "data-sparql11/functions/iri01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( if01 ) {
    /* name: IF() */
    const char* defaultGraph( "data-sparql11/functions/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/if01.rq", "data-sparql11/functions/if01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( if02 ) {
    /* name: IF() error propogation */
    const char* defaultGraph( "data-sparql11/functions/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/if02.rq", "data-sparql11/functions/if02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( coalesce01 ) {
    /* name: COALESCE() */
    const char* defaultGraph( "data-sparql11/functions/data-coalesce.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/coalesce01.rq", "data-sparql11/functions/coalesce01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strbefore01a ) {
    /* name: STRBEFORE() */
    const char* defaultGraph( "data-sparql11/functions/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strbefore01.rq", "data-sparql11/functions/strbefore01a.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strbefore02 ) {
    /* name: STRBEFORE() datatyping */
    const char* defaultGraph( "data-sparql11/functions/data4.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strbefore02.rq", "data-sparql11/functions/strbefore02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strafter01a ) {
    /* name: STRAFTER() */
    const char* defaultGraph( "data-sparql11/functions/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strafter01.rq", "data-sparql11/functions/strafter01a.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( strafter02 ) {
    /* name: STRAFTER() datatyping */
    const char* defaultGraph( "data-sparql11/functions/data4.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/strafter02.rq", "data-sparql11/functions/strafter02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( replace01 ) {
    /* name: REPLACE() */
    const char* defaultGraph( "data-sparql11/functions/data3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/replace01.rq", "data-sparql11/functions/replace01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( replace02 ) {
    /* name: REPLACE() with overlapping pattern */
    const char* defaultGraph( "data-sparql11/functions/data3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/replace02.rq", "data-sparql11/functions/replace02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( replace03 ) {
    /* name: REPLACE() with captured substring */
    const char* defaultGraph( "data-sparql11/functions/data3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/replace03.rq", "data-sparql11/functions/replace03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( uuid01 ) {
    /* name: UUID() pattern match */
    const char* defaultGraph( "data-sparql11/functions/data-empty.nt");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/uuid01.rq", "data-sparql11/functions/uuid01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( struuid01 ) {
    /* name: STRUUID() pattern match */
    const char* defaultGraph( "data-sparql11/functions/data-empty.nt");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/functions/struuid01.rq", "data-sparql11/functions/struuid01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( group01 ) {
    /* name: Group-1 */
    const char* defaultGraph( "data-sparql11/grouping/group-data-1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/grouping/group01.rq", "data-sparql11/grouping/group01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( group03 ) {
    /* name: Group-3 */
    const char* defaultGraph( "data-sparql11/grouping/group-data-1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/grouping/group03.rq", "data-sparql11/grouping/group03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( group04 ) {
    /* name: Group-4 */
    const char* defaultGraph( "data-sparql11/grouping/group-data-1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/grouping/group04.rq", "data-sparql11/grouping/group04.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( group05 ) {
    /* name: Group-5 */
    const char* defaultGraph( "data-sparql11/grouping/group-data-2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/grouping/group05.rq", "data-sparql11/grouping/group05.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subset_by_exclusion_nex_1 ) {
    /* name: Subsets by exclusion (NOT EXISTS) */
    const char* defaultGraph( "data-sparql11/negation/subsetByExcl.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/subsetByExcl01.rq", "data-sparql11/negation/subsetByExcl01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subset_by_exclusion_minus_1 ) {
    /* name: Subsets by exclusion (MINUS) */
    const char* defaultGraph( "data-sparql11/negation/subsetByExcl.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/subsetByExcl02.rq", "data-sparql11/negation/subsetByExcl02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( temporal_proximity_by_exclusion_nex_1 ) {
    /* name: Medical, temporal proximity by exclusion (NOT EXISTS) */
    const char* defaultGraph( "data-sparql11/negation/temporalProximity01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/temporalProximity01.rq", "data-sparql11/negation/temporalProximity01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subset_01 ) {
    /* name: Calculate which sets are subsets of others (include A subsetOf A) */
    const char* defaultGraph( "data-sparql11/negation/set-data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/subset-01.rq", "data-sparql11/negation/subset-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subset_02 ) {
    /* name: Calculate which sets are subsets of others (exclude A subsetOf A) */
    const char* defaultGraph( "data-sparql11/negation/set-data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/subset-02.rq", "data-sparql11/negation/subset-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( set_equals_1 ) {
    /* name: Calculate which sets have the same elements */
    const char* defaultGraph( "data-sparql11/negation/set-data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/set-equals-1.rq", "data-sparql11/negation/set-equals-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subset_03 ) {
    /* name: Calculate proper subset */
    const char* defaultGraph( "data-sparql11/negation/set-data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/subset-03.rq", "data-sparql11/negation/subset-03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( exists_01 ) {
    /* name: Positive EXISTS 1 */
    const char* defaultGraph( "data-sparql11/negation/set-data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/exists-01.rq", "data-sparql11/negation/exists-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( exists_02 ) {
    /* name: Positive EXISTS 2 */
    const char* defaultGraph( "data-sparql11/negation/set-data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/exists-02.rq", "data-sparql11/negation/exists-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( full_minuend ) {
    /* name: Subtraction with MINUS from a fully bound minuend */
    const char* defaultGraph( "data-sparql11/negation/full-minuend.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/full-minuend.rq", "data-sparql11/negation/full-minuend.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( partial_minuend ) {
    /* name: Subtraction with MINUS from a partially bound minuend */
    const char* defaultGraph( "data-sparql11/negation/part-minuend.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/negation/part-minuend.rq", "data-sparql11/negation/part-minuend.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp01 ) {
    /* name: Expression is equality */
    const char* defaultGraph( "data-sparql11/project-expression/projexp01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp01.rq", "data-sparql11/project-expression/projexp01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp02 ) {
    /* name: Expression raise an error */
    const char* defaultGraph( "data-sparql11/project-expression/projexp02.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp02.rq", "data-sparql11/project-expression/projexp02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp03 ) {
    /* name: Reuse a project expression variable in select */
    const char* defaultGraph( "data-sparql11/project-expression/projexp03.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp03.rq", "data-sparql11/project-expression/projexp03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp04 ) {
    /* name: Reuse a project expression variable in order by */
    const char* defaultGraph( "data-sparql11/project-expression/projexp04.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp04.rq", "data-sparql11/project-expression/projexp04.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp05 ) {
    /* name: Expression may return no value */
    const char* defaultGraph( "data-sparql11/project-expression/projexp05.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp05.rq", "data-sparql11/project-expression/projexp05.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp06 ) {
    /* name: Expression has undefined variable */
    const char* defaultGraph( "data-sparql11/project-expression/projexp06.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp06.rq", "data-sparql11/project-expression/projexp06.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( projexp07 ) {
    /* name: Expression has variable that may be unbound */
    const char* defaultGraph( "data-sparql11/project-expression/projexp07.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/project-expression/projexp07.rq", "data-sparql11/project-expression/projexp07.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp01 ) {
    /* name: (pp01) Simple path */
    const char* defaultGraph( "data-sparql11/property-path/pp01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp01.rq", "data-sparql11/property-path/pp01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp02 ) {
    /* name: (pp02) Star path */
    const char* defaultGraph( "data-sparql11/property-path/pp01.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp02.rq", "data-sparql11/property-path/pp02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp03 ) {
    /* name: (pp03) Simple path with loop */
    const char* defaultGraph( "data-sparql11/property-path/pp03.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp03.rq", "data-sparql11/property-path/pp03.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp06 ) {
    /* name: (pp06) Path with two graphs */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/property-path/pp061.ttl", "data-sparql11/property-path/pp062.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp06.rq", "data-sparql11/property-path/pp06.srx", 2, 0);
}
BOOST_AUTO_TEST_CASE( pp07 ) {
    /* name: (pp07) Path with one graph */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/property-path/pp07.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp06.rq", "data-sparql11/property-path/pp07.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( pp08 ) {
    /* name: (pp08) Reverse path */
    const char* defaultGraph( "data-sparql11/property-path/pp08.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp08.rq", "data-sparql11/property-path/pp08.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp09 ) {
    /* name: (pp09) Reverse sequence path */
    const char* defaultGraph( "data-sparql11/property-path/pp09.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp09.rq", "data-sparql11/property-path/pp09.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp10 ) {
    /* name: (pp10) Path with negation */
    const char* defaultGraph( "data-sparql11/property-path/pp10.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp10.rq", "data-sparql11/property-path/pp10.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp11 ) {
    /* name: (pp11) Simple path and two paths to same target node */
    const char* defaultGraph( "data-sparql11/property-path/pp11.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp11.rq", "data-sparql11/property-path/pp11.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp12 ) {
    /* name: (pp12) Variable length path and two paths to same target node */
    const char* defaultGraph( "data-sparql11/property-path/pp11.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp12.rq", "data-sparql11/property-path/pp12.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp14 ) {
    /* name: (pp14) Star path over foaf:knows */
    const char* defaultGraph( "data-sparql11/property-path/pp14.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp14.rq", "data-sparql11/property-path/pp14.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp16 ) {
    /* name: (pp16) Duplicate paths and cycles through foaf:knows* */
    const char* defaultGraph( "data-sparql11/property-path/pp16.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp14.rq", "data-sparql11/property-path/pp16.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp21 ) {
    /* name: (pp21) Diamond -- :p+ */
    const char* defaultGraph( "data-sparql11/property-path/data-diamond.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-2-2.rq", "data-sparql11/property-path/diamond-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp23 ) {
    /* name: (pp23) Diamond, with tail -- :p+ */
    const char* defaultGraph( "data-sparql11/property-path/data-diamond-tail.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-2-2.rq", "data-sparql11/property-path/diamond-tail-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp25 ) {
    /* name: (pp25) Diamond, with loop -- :p+ */
    const char* defaultGraph( "data-sparql11/property-path/data-diamond-loop.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-2-2.rq", "data-sparql11/property-path/diamond-loop-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp28a ) {
    /* name: (pp28a) Diamond, with loop -- (:p/:p)? */
    const char* defaultGraph( "data-sparql11/property-path/data-diamond-loop.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-3-3.rq", "data-sparql11/property-path/diamond-loop-5a.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp30 ) {
    /* name: (pp30) Operator precedence 1 */
    const char* defaultGraph( "data-sparql11/property-path/path-p1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-p1.rq", "data-sparql11/property-path/path-p1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp31 ) {
    /* name: (pp31) Operator precedence 2 */
    const char* defaultGraph( "data-sparql11/property-path/path-p1.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-p2.rq", "data-sparql11/property-path/path-p2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp32 ) {
    /* name: (pp32) Operator precedence 3 */
    const char* defaultGraph( "data-sparql11/property-path/path-p3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-p3.rq", "data-sparql11/property-path/path-p3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp33 ) {
    /* name: (pp33) Operator precedence 4 */
    const char* defaultGraph( "data-sparql11/property-path/path-p3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-p4.rq", "data-sparql11/property-path/path-p4.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp34 ) {
    /* name: (pp34) Named Graph 1 */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/property-path/ng-01.ttl", "data-sparql11/property-path/ng-02.ttl", "data-sparql11/property-path/ng-03.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-ng-01.rq", "data-sparql11/property-path/path-ng-01.srx", 3, 0);
}
BOOST_AUTO_TEST_CASE( pp35 ) {
    /* name: (pp35) Named Graph 2 */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/property-path/ng-01.ttl", "data-sparql11/property-path/ng-02.ttl", "data-sparql11/property-path/ng-03.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/path-ng-02.rq", "data-sparql11/property-path/path-ng-01.srx", 3, 0);
}
BOOST_AUTO_TEST_CASE( pp36 ) {
    /* name: (pp36) Arbitrary path with bound endpoints */
    const char* defaultGraph( "data-sparql11/property-path/clique3.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp36.rq", "data-sparql11/property-path/pp36.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( pp37 ) {
    /* name: (pp37) Nested (*)* */
    const char* defaultGraph( "data-sparql11/property-path/pp37.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/property-path/pp37.rq", "data-sparql11/property-path/pp37.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery01 ) {
    /* name: sq01 - Subquery within graph pattern */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/subquery/sq01.rdf"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq01.rq", "data-sparql11/subquery/sq01.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( subquery02 ) {
    /* name: sq02 - Subquery within graph pattern, graph variable is bound */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/subquery/sq01.rdf"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq02.rq", "data-sparql11/subquery/sq02.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( subquery03 ) {
    /* name: sq03 - Subquery within graph pattern, graph variable is not bound */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/subquery/sq01.rdf"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq03.rq", "data-sparql11/subquery/sq03.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( subquery04 ) {
    /* name: sq04 - Subquery within graph pattern, default graph does not apply */
    const char* defaultGraph( "data-sparql11/subquery/sq04.rdf");
    const char* namedGraphs[] = {"data-sparql11/subquery/sq01.rdf"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq04.rq", "data-sparql11/subquery/sq04.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( subquery05 ) {
    /* name: sq05 - Subquery within graph pattern, from named applies */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/subquery/sq05.rdf"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq05.rq", "data-sparql11/subquery/sq05.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( subquery06 ) {
    /* name: sq06 - Subquery with graph pattern, from named applies */
    const char* defaultGraph( "data-sparql11/subquery/sq05.rdf");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq06.rq", "data-sparql11/subquery/sq06.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery07 ) {
    /* name: sq07 - Subquery with from  */
    const char* defaultGraph( NULL);
    const char* namedGraphs[] = {"data-sparql11/subquery/sq05.rdf"};
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq07.rq", "data-sparql11/subquery/sq07.srx", 1, 0);
}
BOOST_AUTO_TEST_CASE( subquery08 ) {
    /* name: sq08 - Subquery with aggregate */
    const char* defaultGraph( "data-sparql11/subquery/sq08.rdf");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq08.rq", "data-sparql11/subquery/sq08.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery09 ) {
    /* name: sq09 - Nested Subqueries */
    const char* defaultGraph( "data-sparql11/subquery/sq09.rdf");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq09.rq", "data-sparql11/subquery/sq09.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery10 ) {
    /* name: sq10 - Subquery with exists */
    const char* defaultGraph( "data-sparql11/subquery/sq10.rdf");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq10.rq", "data-sparql11/subquery/sq10.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery11 ) {
    /* name: sq11 - Subquery limit per resource */
    const char* defaultGraph( "data-sparql11/subquery/sq11.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq11.rq", "data-sparql11/subquery/sq11.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery12 ) {
    /* name: sq12 - Subquery in CONSTRUCT with built-ins */
    const char* defaultGraph( "data-sparql11/subquery/sq12.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq12.rq", "data-sparql11/subquery/sq12_out.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery13 ) {
    /* name: sq13 - Subqueries don't inject bindings */
    const char* defaultGraph( "data-sparql11/subquery/sq11.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq11.rq", "data-sparql11/subquery/sq11.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subquery14 ) {
    /* name: sq14 - limit by resource */
    const char* defaultGraph( "data-sparql11/subquery/sq14.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/subquery/sq14.rq", "data-sparql11/subquery/sq14-out.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* SPARQL11_WG */)

// EOF

