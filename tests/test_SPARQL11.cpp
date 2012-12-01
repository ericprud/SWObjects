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


BOOST_AUTO_TEST_SUITE( sparql11_query )
// populate with:
// cd tests
// LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl -e '
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
    DAWG_TEST("data-sparql11/aggregates/agg-empty-group.rq", "data-sparql11/aggregates/agg-empty-group2.srx", 0, 0);
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
BOOST_AUTO_TEST_SUITE_END(/* sparql11_query */)

BOOST_AUTO_TEST_SUITE( sparql11_update )
// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl q.rq -L text/raw
// with q.rq [[
// PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
// PREFIX ut: <http://www.w3.org/2009/sparql/tests/test-update#>
// PREFIX dawgt: <http://www.w3.org/2001/sw/DataAccess/tests/test-dawg#>
// PREFIX fn: <http://www.w3.org/2005/xpath-functions#>
// PREFIX rdfs:   <http://www.w3.org/2000/01/rdf-schema#>
// SELECT
//   (CONCAT("BOOST_AUTO_TEST_CASE( ", ?id, " ) {\n")										AS ?line1)
//   (CONCAT("    // name: ", ?name, "\n")												AS ?line2)
//   (CONCAT("    // manifest: ", STR(?manifest), "\n")										AS ?line3)
//   (CONCAT("    const char* defaultGraph_in = ", IF(BOUND(?dgraph_in), CONCAT("\"", STR(?dgraph_in), "\""), "NULL"), ";\n")	AS ?line4)
//   (CONCAT("    LabeledGraph namedGraphs_in[] = {", IF(BOUND(?graph_in), ?graph_in, ""), "};\n")					AS ?line5)
//   (CONCAT("    const char* request = \"", STR(?request), "\";\n")								AS ?line6)
//   (CONCAT("    const char* defaultGraph_out = ", IF(BOUND(?dgraph_out), CONCAT("\"", STR(?dgraph_out), "\""), "NULL"), ";\n")	AS ?line7)
//   (CONCAT("    LabeledGraph namedGraphs_out[] = {", IF(BOUND(?graph_out), ?graph_out, ""), "};\n")				AS ?line8)
//   (CONCAT("    UPDATE_TEST();\n")												AS ?line9)
//   (CONCAT("} /* BOOST_AUTO_TEST_CASE( ", ?id, " ) */\n")									AS ?lineA)
// {
//   <http://www.w3.org/TR/sparql11-update/> mf:conformanceRequirement MEMBERS(?manifest)
// 
//   GRAPH ?manifest {
//     ?s a mf:Manifest ;
//        mf:entries MEMBERS(?entry) .
//     ?entry a mf:UpdateEvaluationTest ;
//            mf:name ?name ;
//            dawgt:approval dawgt:Approved ;
//            mf:action ?action ;
//            mf:result ?result .
//     ?action ut:request ?request .
//   }
//   OPTIONAL { GRAPH ?manifest { ?action ut:data ?dgraph_in } }
//   OPTIONAL { SELECT ?action (GROUP_CONCAT(?graph_row_in; SEPARATOR=", ") AS ?graph_in) WHERE { GRAPH ?manifest { ?action ut:graphData [ ut:graph ?source_in ; rdfs:label ?label_in] BIND (CONCAT("LG(\"", STR(?source_in), "\", \"", STR(?label_in), "\")") AS ?graph_row_in) } } GROUP BY ?id ?action }
// 
//   OPTIONAL { GRAPH ?manifest { ?result ut:data ?dgraph_out } }
//   OPTIONAL { SELECT ?result (GROUP_CONCAT(?graph_row_out; SEPARATOR=", ") AS ?graph_out) WHERE { GRAPH ?manifest { ?result ut:graphData [ ut:graph ?source_out ; rdfs:label ?label_out] BIND (CONCAT("LG(\"", STR(?source_out), "\", \"", STR(?label_out), "\")") AS ?graph_row_out) } } GROUP BY ?id ?result }
// 
//   BIND (fn:replace(strafter(str(?entry), "#"), "-", "_") AS ?id)
// #  FILTER (?id = "insert_using_01") # limit to one for fiddling
// }
// ]]

#define UPDATE_TEST999()			       \
    try {								       \
	if (TEST_ENABLED(REQS)) {					       \
	    MeasuredRS measured(defaultGraph, namedGraphs,		       \
				NGS, requires, REQS, QUERY_FILE);	       \
	    ReferenceRS expected(measured, RESULT_FILE, &F, &P);	       \
	    BOOST_CHECK_EQUAL(measured, expected);			       \
	}								       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

#define LG(SOURCE, NAME) LabeledGraph(SOURCE, NAME)
#define SIZE(ARRAY) (sizeof(ARRAY)/sizeof(ARRAY[0]))
#define UPDATE_TEST() \
    try {								       \
	MeasuredRS measured(defaultGraph_in, namedGraphs_in,		       \
			    (sizeof(namedGraphs_in)/sizeof(namedGraphs_in[0])), request); \
	/*w3c_sw_LINEN << "in:" << (sizeof(namedGraphs_in)/sizeof(namedGraphs_in[0])) << " -- out:" << (sizeof(namedGraphs_out)/sizeof(namedGraphs_out[0])) << "\n"; */ \
	/* w3c_sw_LINEN << measured; */					       \
	ReferenceDB expected(defaultGraph_out, namedGraphs_out,		       \
			     SIZE(namedGraphs_out), request);		       \
	BOOST_CHECK_EQUAL(measured.d, expected);			       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_CASE( add01 ) {
    // name: ADD 1
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/add/add-01.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-post.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add01 ) */
BOOST_AUTO_TEST_CASE( add02 ) {
    // name: ADD 2
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/add/add-01.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-default.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add02 ) */
BOOST_AUTO_TEST_CASE( add03 ) {
    // name: ADD 3
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1"), LG("data-sparql11/add/add-02-pre.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/add/add-03.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1"), LG("data-sparql11/add/add-02-post.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add03 ) */
BOOST_AUTO_TEST_CASE( add04 ) {
    // name: ADD 4
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/add/add-03.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1"), LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add04 ) */
BOOST_AUTO_TEST_CASE( add05 ) {
    // name: ADD 5
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1"), LG("data-sparql11/add/add-03-pre.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/add/add-05.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1"), LG("data-sparql11/add/add-03-post.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add05 ) */
BOOST_AUTO_TEST_CASE( add06 ) {
    // name: ADD 6
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/add/add-06.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add06 ) */
BOOST_AUTO_TEST_CASE( add07 ) {
    // name: ADD 7
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/add/add-07.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-01-post.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add07 ) */
BOOST_AUTO_TEST_CASE( add08 ) {
    // name: ADD 8
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/add/add-08.ru";
    const char* defaultGraph_out = "data-sparql11/add/add-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/add/add-01-pre.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add08 ) */
BOOST_AUTO_TEST_CASE( insert_data_spo1 ) {
    // name: Simple insert data 1
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/basic-update/insert-data-spo1.ru";
    const char* defaultGraph_out = "data-sparql11/basic-update/spo.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_data_spo1 ) */
BOOST_AUTO_TEST_CASE( insert_data_spo_named1 ) {
    // name: Simple insert data named 1
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/basic-update/insert-data-named1.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/spo.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_data_spo_named1 ) */
BOOST_AUTO_TEST_CASE( insert_data_spo_named2 ) {
    // name: Simple insert data named 2
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/basic-update/spo.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/basic-update/insert-data-named2.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/spo2.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_data_spo_named2 ) */
BOOST_AUTO_TEST_CASE( insert_data_spo_named3 ) {
    // name: Simple insert data named 3
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/basic-update/spo.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/basic-update/insert-data-named1.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/spo.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_data_spo_named3 ) */
BOOST_AUTO_TEST_CASE( insert_where_01 ) {
    // name: INSERT 01
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/basic-update/insert-01-pre.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/basic-update/insert-01.ru";
    const char* defaultGraph_out = "data-sparql11/basic-update/insert-01-post.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_where_01 ) */
BOOST_AUTO_TEST_CASE( insert_where_02 ) {
    // name: INSERT 02
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/basic-update/insert-02-pre.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/basic-update/insert-02.ru";
    const char* defaultGraph_out = "data-sparql11/basic-update/insert-02-post.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/insert-02-g1-post.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_where_02 ) */
BOOST_AUTO_TEST_CASE( insert_where_03 ) {
    // name: INSERT 03
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/basic-update/insert-03-pre.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/basic-update/insert-03-g1-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/basic-update/insert-03.ru";
    const char* defaultGraph_out = "data-sparql11/basic-update/insert-03-post.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/insert-03-g1-post.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_where_03 ) */
BOOST_AUTO_TEST_CASE( insert_where_04 ) {
    // name: INSERT 04
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/basic-update/insert-04-pre.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/basic-update/insert-04-g1-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/basic-update/insert-04.ru";
    const char* defaultGraph_out = "data-sparql11/basic-update/insert-04-post.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/insert-04-g1-post.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_where_04 ) */
BOOST_AUTO_TEST_CASE( insert_using_01 ) {
    // name: INSERT USING 01
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/basic-update/insert-using-01-pre.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/basic-update/insert-using-01-g1-pre.ttl", "http://example.org/g1"), LG("data-sparql11/basic-update/insert-using-01-g2-pre.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/basic-update/insert-using-01.ru";
    const char* defaultGraph_out = "data-sparql11/basic-update/insert-using-01-post.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/insert-using-01-g1-post.ttl", "http://example.org/g1"), LG("data-sparql11/basic-update/insert-using-01-g2-post.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_using_01 ) */
BOOST_AUTO_TEST_CASE( insert_05a ) {
    // name: INSERT same bnode twice
    // manifest: data-sparql11/basic-update/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/basic-update/insert-05a-g1-pre.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/basic-update/insert-05a.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/basic-update/insert-05a-g3-post.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( insert_05a ) */
BOOST_AUTO_TEST_CASE( dawg_clear_default_01 ) {
    // name: CLEAR DEFAULT
    // manifest: data-sparql11/clear/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/clear/clear-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/clear/clear-g1.ttl", "http://example.org/g1"), LG("data-sparql11/clear/clear-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/clear/clear-default-01.ru";
    const char* defaultGraph_out = "data-sparql11/clear/empty.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/clear/clear-g1.ttl", "http://example.org/g1"), LG("data-sparql11/clear/clear-g2.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_clear_default_01 ) */
BOOST_AUTO_TEST_CASE( dawg_clear_graph_01 ) {
    // name: CLEAR GRAPH
    // manifest: data-sparql11/clear/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/clear/clear-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/clear/clear-g1.ttl", "http://example.org/g1"), LG("data-sparql11/clear/clear-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/clear/clear-graph-01.ru";
    const char* defaultGraph_out = "data-sparql11/clear/clear-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/clear/clear-g2.ttl", "http://example.org/g2"), LG("data-sparql11/clear/empty.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_clear_graph_01 ) */
BOOST_AUTO_TEST_CASE( dawg_clear_named_01 ) {
    // name: CLEAR NAMED
    // manifest: data-sparql11/clear/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/clear/clear-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/clear/clear-g1.ttl", "http://example.org/g1"), LG("data-sparql11/clear/clear-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/clear/clear-named-01.ru";
    const char* defaultGraph_out = "data-sparql11/clear/clear-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/clear/empty.ttl", "http://example.org/g1"), LG("data-sparql11/clear/empty.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_clear_named_01 ) */
BOOST_AUTO_TEST_CASE( dawg_clear_all_01 ) {
    // name: CLEAR ALL
    // manifest: data-sparql11/clear/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/clear/clear-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/clear/clear-g1.ttl", "http://example.org/g1"), LG("data-sparql11/clear/clear-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/clear/clear-all-01.ru";
    const char* defaultGraph_out = "data-sparql11/clear/empty.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/clear/empty.ttl", "http://example.org/g1"), LG("data-sparql11/clear/empty.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_clear_all_01 ) */
BOOST_AUTO_TEST_CASE( copy01 ) {
    // name: COPY 1
    // manifest: data-sparql11/copy/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/copy/copy-01.ru";
    const char* defaultGraph_out = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/copy/copy-default.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy01 ) */
BOOST_AUTO_TEST_CASE( copy02 ) {
    // name: COPY 2
    // manifest: data-sparql11/copy/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/copy/copy-01.ru";
    const char* defaultGraph_out = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/copy/copy-default.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy02 ) */
BOOST_AUTO_TEST_CASE( copy03 ) {
    // name: COPY 3
    // manifest: data-sparql11/copy/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1"), LG("data-sparql11/copy/copy-02.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/copy/copy-03.ru";
    const char* defaultGraph_out = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1"), LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy03 ) */
BOOST_AUTO_TEST_CASE( copy04 ) {
    // name: COPY 4
    // manifest: data-sparql11/copy/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/copy/copy-03.ru";
    const char* defaultGraph_out = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1"), LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy04 ) */
BOOST_AUTO_TEST_CASE( copy06 ) {
    // name: COPY 6
    // manifest: data-sparql11/copy/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/copy/copy-06.ru";
    const char* defaultGraph_out = "data-sparql11/copy/copy-01.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy06 ) */
BOOST_AUTO_TEST_CASE( copy07 ) {
    // name: COPY 7
    // manifest: data-sparql11/copy/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/copy/copy-07.ru";
    const char* defaultGraph_out = "data-sparql11/copy/copy-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/copy/copy-01.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy07 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_data_01 ) {
    // name: Simple DELETE DATA 1
    // manifest: data-sparql11/delete-data/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-data/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-data/delete-data-01.ru";
    const char* defaultGraph_out = "data-sparql11/delete-data/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_data_01 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_data_02 ) {
    // name: Simple DELETE DATA 2
    // manifest: data-sparql11/delete-data/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-data/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete-data/delete-data-02.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-data/delete-post-01s.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_data_02 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_data_03 ) {
    // name: Simple DELETE DATA 3
    // manifest: data-sparql11/delete-data/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-data/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-data/delete-data-03.ru";
    const char* defaultGraph_out = "data-sparql11/delete-data/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_data_03 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_data_04 ) {
    // name: Simple DELETE DATA 4
    // manifest: data-sparql11/delete-data/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-data/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete-data/delete-data-04.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-data/delete-post-01f.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_data_04 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_data_05 ) {
    // name: Graph-specific DELETE DATA 1
    // manifest: data-sparql11/delete-data/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-data/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-data/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete-data/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete-data/delete-data-05.ru";
    const char* defaultGraph_out = "data-sparql11/delete-data/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-data/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete-data/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_data_05 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_data_06 ) {
    // name: Graph-specific DELETE DATA 2
    // manifest: data-sparql11/delete-data/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-data/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-data/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete-data/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete-data/delete-data-06.ru";
    const char* defaultGraph_out = "data-sparql11/delete-data/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-data/delete-post-03f.ttl", "http://example.org/g3"), LG("data-sparql11/delete-data/delete-post-02s.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_data_06 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_01 ) {
    // name: DELETE INSERT 1
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-01.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-01.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_01 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_01b ) {
    // name: DELETE INSERT 1b
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-01b.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-01b.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_01b ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_01c ) {
    // name: DELETE INSERT 1c
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-01c.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-01b.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_01c ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_02 ) {
    // name: DELETE INSERT 2
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-02.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-02.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_02 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_04 ) {
    // name: DELETE INSERT 4
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-04.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-02.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_04 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_04b ) {
    // name: DELETE INSERT 4b
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-04b.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-02.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_04b ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_05b ) {
    // name: DELETE INSERT 5b
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-05b.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-post-05.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_05b ) */
BOOST_AUTO_TEST_CASE( dawg_delete_insert_06b ) {
    // name: DELETE INSERT 6b
    // manifest: data-sparql11/delete-insert/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-insert/delete-insert-pre-06.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-insert/delete-insert-05b.ru";
    const char* defaultGraph_out = "data-sparql11/delete-insert/delete-insert-pre-06.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_insert_06b ) */
BOOST_AUTO_TEST_CASE( dawg_delete_where_01 ) {
    // name: Simple DELETE WHERE 1
    // manifest: data-sparql11/delete-where/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-where/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-where/delete-where-01.ru";
    const char* defaultGraph_out = "data-sparql11/delete-where/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_where_01 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_where_02 ) {
    // name: Simple DELETE WHERE 2
    // manifest: data-sparql11/delete-where/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-where/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete-where/delete-where-02.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-where/delete-post-01s.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_where_02 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_where_03 ) {
    // name: Simple DELETE WHERE 3
    // manifest: data-sparql11/delete-where/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-where/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete-where/delete-where-03.ru";
    const char* defaultGraph_out = "data-sparql11/delete-where/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_where_03 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_where_04 ) {
    // name: Simple DELETE WHERE 4
    // manifest: data-sparql11/delete-where/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-where/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete-where/delete-where-04.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-where/delete-post-01f.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_where_04 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_where_05 ) {
    // name: Graph-specific DELETE WHERE 1
    // manifest: data-sparql11/delete-where/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-where/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-where/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete-where/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete-where/delete-where-05.ru";
    const char* defaultGraph_out = "data-sparql11/delete-where/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-where/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete-where/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_where_05 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_where_06 ) {
    // name: Graph-specific DELETE WHERE 2
    // manifest: data-sparql11/delete-where/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete-where/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete-where/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete-where/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete-where/delete-where-06.ru";
    const char* defaultGraph_out = "data-sparql11/delete-where/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete-where/delete-post-03f.ttl", "http://example.org/g3"), LG("data-sparql11/delete-where/delete-post-02s.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_where_06 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_01 ) {
    // name: Simple DELETE 1
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete/delete-01.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_01 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_02 ) {
    // name: Simple DELETE 2
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete/delete-02.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01s.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_02 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_03 ) {
    // name: Simple DELETE 3
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete/delete-03.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_03 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_04 ) {
    // name: Simple DELETE 4
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete/delete-04.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01f.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_04 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_05 ) {
    // name: Graph-specific DELETE 1
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-05.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_05 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_06 ) {
    // name: Graph-specific DELETE 2
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-06.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3"), LG("data-sparql11/delete/delete-post-02s.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_06 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_07 ) {
    // name: Simple DELETE 7
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/delete/delete-07.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_07 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_with_01 ) {
    // name: Simple DELETE 1 (WITH)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete/delete-with-01.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01s.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_with_01 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_with_02 ) {
    // name: Simple DELETE 2 (WITH)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/delete/delete-with-02.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01s.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_with_02 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_with_03 ) {
    // name: Simple DELETE 3 (WITH)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/delete/delete-with-03.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01f.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_with_03 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_with_04 ) {
    // name: Simple DELETE 4 (WITH)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/delete/delete-with-04.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01f.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_with_04 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_with_05 ) {
    // name: Graph-specific DELETE 1 (WITH)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-with-05.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01s2.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_with_05 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_with_06 ) {
    // name: Graph-specific DELETE 2 (WITH)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-with-06.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3"), LG("data-sparql11/delete/delete-post-02s.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_with_06 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_using_01 ) {
    // name: Simple DELETE 1 (USING)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/delete/delete-using-01.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01s.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_using_01 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_using_02a ) {
    // name: Simple DELETE 2 (USING)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-using-02.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_using_02a ) */
BOOST_AUTO_TEST_CASE( dawg_delete_using_03 ) {
    // name: Simple DELETE 3 (USING)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-01.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/delete/delete-using-03.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-01f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_using_03 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_using_04 ) {
    // name: Simple DELETE 4 (USING)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/delete/delete-pre-03.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-using-04.ru";
    const char* defaultGraph_out = "data-sparql11/delete/delete-post-03f.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_using_04 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_using_05 ) {
    // name: Graph-specific DELETE 1 (USING)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-using-05.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01s2.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_using_05 ) */
BOOST_AUTO_TEST_CASE( dawg_delete_using_06a ) {
    // name: Graph-specific DELETE 2 (USING)
    // manifest: data-sparql11/delete/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/delete/delete-pre-01.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-pre-02.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-pre-03.ttl", "http://example.org/g3")};
    const char* request = "data-sparql11/delete/delete-using-06.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/delete/delete-post-01f.ttl", "http://example.org/g1"), LG("data-sparql11/delete/delete-post-02f.ttl", "http://example.org/g2"), LG("data-sparql11/delete/delete-post-03f.ttl", "http://example.org/g3")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_delete_using_06a ) */
BOOST_AUTO_TEST_CASE( dawg_drop_default_01 ) {
    // name: DROP DEFAULT
    // manifest: data-sparql11/drop/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/drop/drop-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/drop/drop-g1.ttl", "http://example.org/g1"), LG("data-sparql11/drop/drop-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/drop/drop-default-01.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/drop/drop-g1.ttl", "http://example.org/g1"), LG("data-sparql11/drop/drop-g2.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_drop_default_01 ) */
BOOST_AUTO_TEST_CASE( dawg_drop_graph_01 ) {
    // name: DROP GRAPH
    // manifest: data-sparql11/drop/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/drop/drop-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/drop/drop-g1.ttl", "http://example.org/g1"), LG("data-sparql11/drop/drop-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/drop/drop-graph-01.ru";
    const char* defaultGraph_out = "data-sparql11/drop/drop-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/drop/drop-g2.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_drop_graph_01 ) */
BOOST_AUTO_TEST_CASE( dawg_drop_named_01 ) {
    // name: DROP NAMED
    // manifest: data-sparql11/drop/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/drop/drop-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/drop/drop-g1.ttl", "http://example.org/g1"), LG("data-sparql11/drop/drop-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/drop/drop-named-01.ru";
    const char* defaultGraph_out = "data-sparql11/drop/drop-default.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_drop_named_01 ) */
BOOST_AUTO_TEST_CASE( dawg_drop_all_01 ) {
    // name: DROP ALL
    // manifest: data-sparql11/drop/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/drop/drop-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/drop/drop-g1.ttl", "http://example.org/g1"), LG("data-sparql11/drop/drop-g2.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/drop/drop-all-01.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( dawg_drop_all_01 ) */
BOOST_AUTO_TEST_CASE( move01 ) {
    // name: MOVE 1
    // manifest: data-sparql11/move/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/move/move-01.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/move/move-default.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move01 ) */
BOOST_AUTO_TEST_CASE( move02 ) {
    // name: MOVE 2
    // manifest: data-sparql11/move/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/move/move-01.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/move/move-default.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move02 ) */
BOOST_AUTO_TEST_CASE( move03 ) {
    // name: MOVE 3
    // manifest: data-sparql11/move/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g1"), LG("data-sparql11/move/move-02.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/move/move-03.ru";
    const char* defaultGraph_out = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move03 ) */
BOOST_AUTO_TEST_CASE( move04 ) {
    // name: MOVE 4
    // manifest: data-sparql11/move/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/move/move-03.ru";
    const char* defaultGraph_out = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move04 ) */
BOOST_AUTO_TEST_CASE( move06 ) {
    // name: MOVE 6
    // manifest: data-sparql11/move/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/move/move-06.ru";
    const char* defaultGraph_out = "data-sparql11/move/move-01.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move06 ) */
BOOST_AUTO_TEST_CASE( move07 ) {
    // name: MOVE 7
    // manifest: data-sparql11/move/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/move/move-07.ru";
    const char* defaultGraph_out = "data-sparql11/move/move-default.ttl";
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/move/move-01.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move07 ) */
BOOST_AUTO_TEST_CASE( load_silent ) {
    // name: LOAD SILENT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/load-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( load_silent ) */
BOOST_AUTO_TEST_CASE( load_into_silent ) {
    // name: LOAD SILENT INTO
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/load-silent-into.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( load_into_silent ) */
BOOST_AUTO_TEST_CASE( clear_silent ) {
    // name: CLEAR SILENT GRAPH iri
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/update-silent/spo.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/clear-silent.ru";
    const char* defaultGraph_out = "data-sparql11/update-silent/spo.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( clear_silent ) */
BOOST_AUTO_TEST_CASE( clear_default_silent ) {
    // name: CLEAR SILENT DEFAULT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/clear-default-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( clear_default_silent ) */
BOOST_AUTO_TEST_CASE( create_silent ) {
    // name: CREATE SILENT iri
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g1")};
    const char* request = "data-sparql11/update-silent/create-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( create_silent ) */
BOOST_AUTO_TEST_CASE( drop_silent ) {
    // name: DROP SILENT GRAPH iri
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/update-silent/spo.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/drop-silent.ru";
    const char* defaultGraph_out = "data-sparql11/update-silent/spo.ttl";
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( drop_silent ) */
BOOST_AUTO_TEST_CASE( drop_default_silent ) {
    // name: DROP SILENT DEFAULT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/drop-default-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( drop_default_silent ) */
BOOST_AUTO_TEST_CASE( copy_silent ) {
    // name: COPY SILENT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/update-silent/copy-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy_silent ) */
BOOST_AUTO_TEST_CASE( copy_to_default_silent ) {
    // name: COPY SILENT TO DEFAULT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/copy-to-default-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( copy_to_default_silent ) */
BOOST_AUTO_TEST_CASE( move_silent ) {
    // name: MOVE SILENT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/update-silent/move-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move_silent ) */
BOOST_AUTO_TEST_CASE( move_to_default_silent ) {
    // name: MOVE SILENT TO DEFAULT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/move-to-default-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( move_to_default_silent ) */
BOOST_AUTO_TEST_CASE( add_silent ) {
    // name: ADD SILENT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g2")};
    const char* request = "data-sparql11/update-silent/add-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {LG("data-sparql11/update-silent/spo.ttl", "http://example.org/g2")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add_silent ) */
BOOST_AUTO_TEST_CASE( add_to_default_silent ) {
    // name: ADD SILENT TO DEFAULT
    // manifest: data-sparql11/update-silent/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/update-silent/add-to-default-silent.ru";
    const char* defaultGraph_out = NULL;
    LabeledGraph namedGraphs_out[] = {};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( add_to_default_silent ) */
BOOST_AUTO_TEST_SUITE_END(/* sparql11_update */)

BOOST_AUTO_TEST_SUITE( sparql11_results_csv_tsv )
// BOOST_AUTO_TEST_CASE( toy ) {
//     AtomFactory f;
//     IStreamContext istr
// 	(
// 	 "o,p,s\n"
// 	 "http://swobj.org/sparql/v1,http://usefulinc.com/ns/doap#homepage,\n"
// 	 "http://usefulinc.com/ns/doap#Project,http://www.w3.org/1999/02/22-rdf-syntax-ns#type,\n"
// 	 "a semantic web query toolbox,http://usefulinc.com/ns/doap#shortdesc,\n",
// 
// 	 // "s,p,o\n"
// 	 // "http://example.org/s1,http://example.org/p1,http://example.org/s2\n"
// 	 // "http://example.org/s2,http://example.org/p2,foo\n"
// 	 // "http://example.org/s3,http://example.org/p3,bar\n"
// 	 // "http://example.org/s4,http://example.org/p4,4\n"
// 	 // "http://example.org/s5,http://example.org/p5,5.5\n"
// 	 // "http://example.org/s6,http://example.org/p6,_:o\n",
// 	 IStreamContext::STRING, "text/csv");
//     w3c_sw_LINE;
//     ResultSet r(&f, &P, istr);
//     w3c_sw_LINEN << "\n" << r;
// }

BOOST_AUTO_TEST_CASE( csv01 ) {
    /* name: csv01 - CSV Result Format */
    const char* defaultGraph( "data-sparql11/csv-tsv-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWGSV_TEST("data-sparql11/csv-tsv-res/csvtsv01.rq", "data-sparql11/csv-tsv-res/csvtsv01.csv", 0, 0);
}
BOOST_AUTO_TEST_CASE( csv02 ) {
    /* name: cvs02 - CSV Result Format */
    const char* defaultGraph( "data-sparql11/csv-tsv-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWGSV_TEST("data-sparql11/csv-tsv-res/csvtsv02.rq", "data-sparql11/csv-tsv-res/csvtsv02.csv", 0, 0);
}
BOOST_AUTO_TEST_CASE( csv03 ) {
    /* name: csv03 - CSV Result Format */
    const char* defaultGraph( "data-sparql11/csv-tsv-res/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWGSV_TEST("data-sparql11/csv-tsv-res/csvtsv01.rq", "data-sparql11/csv-tsv-res/csvtsv03.csv", 0, 0);
}
BOOST_AUTO_TEST_CASE( tsv01 ) {
    /* name: tsv01 - TSV Result Format */
    const char* defaultGraph( "data-sparql11/csv-tsv-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/csv-tsv-res/csvtsv01.rq", "data-sparql11/csv-tsv-res/csvtsv01.tsv", 0, 0);
}
BOOST_AUTO_TEST_CASE( tsv02 ) {
    /* name: tvs02 - TSV Result Format */
    const char* defaultGraph( "data-sparql11/csv-tsv-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/csv-tsv-res/csvtsv02.rq", "data-sparql11/csv-tsv-res/csvtsv02.tsv", 0, 0);
}
BOOST_AUTO_TEST_CASE( tsv03 ) {
    /* name: tsv03 - TSV Result Format */
    const char* defaultGraph( "data-sparql11/csv-tsv-res/data2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/csv-tsv-res/csvtsv01.rq", "data-sparql11/csv-tsv-res/csvtsv03.tsv", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* sparql11_results_csv_tsv */)

BOOST_AUTO_TEST_SUITE( sparql11_json )
BOOST_AUTO_TEST_CASE( jsonres01 ) {
    /* name: jsonres01 - JSON Result Format */
    const char* defaultGraph( "data-sparql11/json-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/json-res/jsonres01.rq", "data-sparql11/json-res/jsonres01.srj", 0, 0);
}
BOOST_AUTO_TEST_CASE( jsonres02 ) {
    /* name: jsonres02 - JSON Result Format */
    const char* defaultGraph( "data-sparql11/json-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/json-res/jsonres02.rq", "data-sparql11/json-res/jsonres02.srj", 0, 0);
}
BOOST_AUTO_TEST_CASE( jsonres03 ) {
    /* name: jsonres03 - JSON Result Format */
    const char* defaultGraph( "data-sparql11/json-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/json-res/jsonres03.rq", "data-sparql11/json-res/jsonres03.srj", 0, 0);
}
BOOST_AUTO_TEST_CASE( jsonres04 ) {
    /* name: jsonres04 - JSON Result Format */
    const char* defaultGraph( "data-sparql11/json-res/data.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-sparql11/json-res/jsonres04.rq", "data-sparql11/json-res/jsonres04.srj", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* sparql11_json */)

BOOST_AUTO_TEST_SUITE( sparql11_federated_query )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_federated_query */)

BOOST_AUTO_TEST_SUITE( sparql11_entailment )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_entailment */)

BOOST_AUTO_TEST_SUITE( sparql11_service_description )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_service_description */)

BOOST_AUTO_TEST_SUITE( sparql11_protocol )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_protocol */)

BOOST_AUTO_TEST_SUITE( sparql11_http_rdf_update )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_http_rdf_update */)


// EOF

