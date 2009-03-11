/* perform DAWG tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE DAWG_tests
#include "../tests/SparqlQueryTestResultSet.hpp"

/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 */
#define DEFGRAPH_FILE_TEST(QUERY_FILE, RESULT_FILE)			       \
    std::ifstream query(QUERY_FILE);					       \
    if (!query.is_open())						       \
	throw std::string("failed to open query file ") + QUERY_FILE;	       \
    SparqlQueryTestResultSet measured(defaultGraph, NULL, 0, query);	       \
    std::string rfs(RESULT_FILE);				    	       \
    if (rfs.substr(rfs.size()-4, 4) == ".srx") { 		    	       \
	ResultSet expected(&F, &P, RESULT_FILE);		    	       \
	BOOST_CHECK_EQUAL(measured, expected);			    	       \
    } else {							    	       \
	ResultSet expected(&F, &turtleParser, &sparqlParser, RESULT_FILE);     \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    }
#define S Sentinel

//BOOST_AUTO_TEST_SUITE( basic )
BOOST_AUTO_TEST_CASE( basic__Basic___Prefix_Base_1_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-1.rq", "data-r2/basic/base-prefix-1.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Prefix_Base_2_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-2.rq", "data-r2/basic/base-prefix-2.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Prefix_Base_3_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-3.rq", "data-r2/basic/base-prefix-3.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Prefix_Base_4_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-4.rq", "data-r2/basic/base-prefix-4.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Prefix_Base_5_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-5.rq", "data-r2/basic/base-prefix-5.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___List_1_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-1.rq", "data-r2/basic/list-1.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___List_2_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-2.rq", "data-r2/basic/list-2.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___List_3_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-3.rq", "data-r2/basic/list-3.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___List_4_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-4.rq", "data-r2/basic/list-4.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Quotes_1_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-1.rq", "data-r2/basic/quotes-1.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Quotes_2_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-2.rq", "data-r2/basic/quotes-2.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Quotes_3_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-3.rq", "data-r2/basic/quotes-3.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Quotes_4_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-4.rq", "data-r2/basic/quotes-4.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_1_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-1.rq", "data-r2/basic/term-1.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_2_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-2.rq", "data-r2/basic/term-2.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_3_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-3.rq", "data-r2/basic/term-3.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_4_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-4.rq", "data-r2/basic/term-4.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_5_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-5.rq", "data-r2/basic/term-5.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_6_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-6.rq", "data-r2/basic/term-6.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_7_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-7.rq", "data-r2/basic/term-7.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_8_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-8.rq", "data-r2/basic/term-8.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Term_9_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-9.rq", "data-r2/basic/term-9.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Var_1_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-5.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/var-1.rq", "data-r2/basic/var-1.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic___Var_2_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-5.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/var-2.rq", "data-r2/basic/var-2.srx");
}
BOOST_AUTO_TEST_CASE( basic__Non_matching_triple_pattern_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-7.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/bgp-no-match.rq", "data-r2/basic/bgp-no-match.srx");
}
BOOST_AUTO_TEST_CASE( basic__Basic_graph_pattern___spoo_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-6.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/spoo-1.rq", "data-r2/basic/spoo-1.srx");
}
BOOST_AUTO_TEST_CASE( basic__Prefix_name_1_ ) {
    std::ifstream defaultGraph( "data-r2/basic/data-6.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/prefix-name-1.rq", "data-r2/basic/prefix-name-1.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* basic */)
//BOOST_AUTO_TEST_SUITE( triple_match )
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001_ ) {
    std::ifstream defaultGraph( "data-r2/triple-match/data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/triple-match/dawg-tp-01.rq", "data-r2/triple-match/result-tp-01.ttl");
}
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_002_ ) {
    std::ifstream defaultGraph( "data-r2/triple-match/data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/triple-match/dawg-tp-02.rq", "data-r2/triple-match/result-tp-02.ttl");
}
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_003_ ) {
    std::ifstream defaultGraph( "data-r2/triple-match/data-02.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/triple-match/dawg-tp-03.rq", "data-r2/triple-match/result-tp-03.ttl");
}
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_004_ ) {
    std::ifstream defaultGraph( "data-r2/triple-match/dawg-data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/triple-match/dawg-tp-04.rq", "data-r2/triple-match/result-tp-04.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* triple_match */)
//BOOST_AUTO_TEST_SUITE( open_world )
BOOST_AUTO_TEST_CASE( open_world__open_eq_01_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-01.rq", "data-r2/open-world/open-eq-01-result.srx");
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_02_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-02.rq", "data-r2/open-world/open-eq-02-result.srx");
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_03_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-03.rq", "data-r2/open-world/open-eq-03-result.srx");
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_04_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-04.rq", "data-r2/open-world/open-eq-04-result.srx");
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_05_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-05.rq", "data-r2/open-world/open-eq-05-result.srx");
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_06_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-06.rq", "data-r2/open-world/open-eq-06-result.srx");
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_09_ ) {
    std::ifstream defaultGraph( "data-r2/open-world/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/open-world/open-eq-09.rq", "data-r2/open-world/open-eq-09-result.srx");
}
//BOOST_AUTO_TEST_SUITE( algebra )
BOOST_AUTO_TEST_CASE( algebra__Nested_Optionals___1_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/two-nested-opt.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/two-nested-opt.rq", "data-r2/algebra/two-nested-opt.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Nested_Optionals___2_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/two-nested-opt.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/two-nested-opt-alt.rq", "data-r2/algebra/two-nested-opt-alt.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Optional_filter___1_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/opt-filter-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/opt-filter-1.rq", "data-r2/algebra/opt-filter-1.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Optional_filter___2_filters_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/opt-filter-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/opt-filter-2.rq", "data-r2/algebra/opt-filter-2.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Optional_filter___scope_of_variable_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/opt-filter-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/opt-filter-3.rq", "data-r2/algebra/opt-filter-3.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Filter_placement___1_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/filter-placement-1.rq", "data-r2/algebra/filter-placement-1.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Filter_placement___2_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/filter-placement-2.rq", "data-r2/algebra/filter-placement-2.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Filter_placement___3_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/filter-placement-3.rq", "data-r2/algebra/filter-placement-3.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Filter_nested___1_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/filter-nested-1.rq", "data-r2/algebra/filter-nested-1.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Filter_nested___2_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/filter-nested-2.rq", "data-r2/algebra/filter-nested-2.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Filter_scope___1_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/filter-scope-1.rq", "data-r2/algebra/filter-scope-1.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Join_scope___1_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/var-scope-join-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/var-scope-join-1.rq", "data-r2/algebra/var-scope-join-1.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Join_operator_with_OPTs__BGPs__and_UNIONs_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/join-combo-graph-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/join-combo-1.rq", "data-r2/algebra/join-combo-1.srx");
}
BOOST_AUTO_TEST_CASE( algebra__Join_operator_with_Graph_and_Union_ ) {
    std::ifstream defaultGraph( "data-r2/algebra/join-combo-graph-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/algebra/join-combo-2.rq", "data-r2/algebra/join-combo-2.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* algebra */)
//BOOST_AUTO_TEST_SUITE( bnode_coreference )
BOOST_AUTO_TEST_CASE( bnode_coreference__dawg_bnode_coreference_ ) {
    std::ifstream defaultGraph( "data-r2/bnode-coreference/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/bnode-coreference/query.rq", "data-r2/bnode-coreference/result.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* bnode_coreference */)
//BOOST_AUTO_TEST_SUITE( optional )
BOOST_AUTO_TEST_CASE( optional__One_optional_clause_ ) {
    std::ifstream defaultGraph( "data-r2/optional/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-1.rq", "data-r2/optional/result-opt-1.ttl");
}
BOOST_AUTO_TEST_CASE( optional__Two_optional_clauses_ ) {
    std::ifstream defaultGraph( "data-r2/optional/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-2.rq", "data-r2/optional/result-opt-2.ttl");
}
BOOST_AUTO_TEST_CASE( optional__Union_is_not_optional_ ) {
    std::ifstream defaultGraph( "data-r2/optional/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-3.rq", "data-r2/optional/result-opt-3.ttl");
}
BOOST_AUTO_TEST_CASE( optional__Complex_optional_semantics__1_ ) {
    std::ifstream defaultGraph( "data-r2/optional/complex-data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-complex-1.rq", "data-r2/optional/result-opt-complex-1.ttl");
}
BOOST_AUTO_TEST_CASE( optional__Complex_optional_semantics__2_ ) {
    std::ifstream defaultGraph( "data-r2/optional/complex-data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-complex-2.rq", "data-r2/optional/result-opt-complex-2.ttl");
}
BOOST_AUTO_TEST_CASE( optional__Complex_optional_semantics__3_ ) {
    std::ifstream defaultGraph( "data-r2/optional/complex-data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-complex-3.rq", "data-r2/optional/result-opt-complex-3.ttl");
}
BOOST_AUTO_TEST_CASE( optional__Complex_optional_semantics__4_ ) {
    std::ifstream defaultGraph( "data-r2/optional/complex-data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional/q-opt-complex-4.rq", "data-r2/optional/result-opt-complex-4.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* optional */)
//BOOST_AUTO_TEST_SUITE( optional_filter )
BOOST_AUTO_TEST_CASE( optional_filter__OPTIONAL_FILTER_ ) {
    std::ifstream defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional-filter/expr-1.rq", "data-r2/optional-filter/expr-1-result.ttl");
}
BOOST_AUTO_TEST_CASE( optional_filter__OPTIONAL___Outer_FILTER_ ) {
    std::ifstream defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional-filter/expr-2.rq", "data-r2/optional-filter/expr-2-result.ttl");
}
BOOST_AUTO_TEST_CASE( optional_filter__OPTIONAL___Outer_FILTER_with_BOUND_ ) {
    std::ifstream defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional-filter/expr-3.rq", "data-r2/optional-filter/expr-3-result.ttl");
}
BOOST_AUTO_TEST_CASE( optional_filter__OPTIONAL___Inner_FILTER_with_negative_EBV_for_outer_variables_ ) {
    std::ifstream defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/optional-filter/expr-4.rq", "data-r2/optional-filter/expr-4-result.ttl");
}
//BOOST_AUTO_TEST_SUITE( graph )
BOOST_AUTO_TEST_CASE( graph__graph_01_ ) {
    std::ifstream defaultGraph( "data-r2/graph/data-g1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/graph/graph-01.rq", "data-r2/graph/graph-01.ttl");
}
//BOOST_AUTO_TEST_SUITE( dataset )
//BOOST_AUTO_TEST_SUITE( type_promotion )
BOOST_AUTO_TEST_CASE( type_promotion__tP_double_double_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-double-double.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_double_float_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-double-float.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_double_decimal_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-double-decimal.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_float_float_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-float-float.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_float_decimal_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-float-decimal.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_decimal_decimal_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-decimal-decimal.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_integer_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-integer-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_nonPositiveInteger_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-nonPositiveInteger-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_negativeInteger_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-negativeInteger-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_long_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-long-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_int_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-int-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_byte_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-byte-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_nonNegativeInteger_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-nonNegativeInteger-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_unsignedLong_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-unsignedLong-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_unsignedInt_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-unsignedInt-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_unsignedShort_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-unsignedShort-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_unsignedByte_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-unsignedByte-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_positiveInteger_short_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-positiveInteger-short.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_double_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-double.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_float_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-float.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_decimal_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-decimal.rq", "data-r2/type-promotion/true.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_short_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-short-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_byte_short_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-byte-short-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_long_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-long-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_int_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-int-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_short_byte_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-short-byte-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_double_float_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-double-float-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_double_decimal_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-double-decimal-fail.rq", "data-r2/type-promotion/false.ttl");
}
BOOST_AUTO_TEST_CASE( type_promotion__tP_float_decimal_fail_ ) {
    std::ifstream defaultGraph( "data-r2/type-promotion/tP.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/type-promotion/tP-float-decimal-fail.rq", "data-r2/type-promotion/false.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* type_promotion */)
//BOOST_AUTO_TEST_SUITE( cast )
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_string_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-str.rq", "data-r2/cast/cast-str.srx");
}
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_float_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-flt.rq", "data-r2/cast/cast-flt.srx");
}
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_double_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-dbl.rq", "data-r2/cast/cast-dbl.srx");
}
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_decimal_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-dec.rq", "data-r2/cast/cast-dec.srx");
}
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_integer_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-int.rq", "data-r2/cast/cast-int.srx");
}
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_dateTime_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-dT.rq", "data-r2/cast/cast-dT.srx");
}
BOOST_AUTO_TEST_CASE( cast__Cast_to_xsd_boolean_ ) {
    std::ifstream defaultGraph( "data-r2/cast/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/cast/cast-bool.rq", "data-r2/cast/cast-bool.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* cast */)
//BOOST_AUTO_TEST_SUITE( boolean_effective_value )
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test_literal__true__ ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-boolean-literal.rq", "data-r2/boolean-effective-value/result-boolean-literal.ttl");
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test__boolean_effective_value____true_ ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-bev-1.rq", "data-r2/boolean-effective-value/result-bev-1.ttl");
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test__boolean_effective_value____false_ ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-bev-2.rq", "data-r2/boolean-effective-value/result-bev-2.ttl");
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test__boolean_effective_value_______ ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-bev-3.rq", "data-r2/boolean-effective-value/result-bev-3.ttl");
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test__boolean_effective_value_______B ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-bev-4.rq", "data-r2/boolean-effective-value/result-bev-4.ttl");
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test__boolean_effective_value____optional_ ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-bev-5.rq", "data-r2/boolean-effective-value/result-bev-5.ttl");
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__Test__boolean_effective_value____unknown_types_ ) {
    std::ifstream defaultGraph( "data-r2/boolean-effective-value/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/boolean-effective-value/query-bev-6.rq", "data-r2/boolean-effective-value/result-bev-6.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* boolean_effective_value */)
//BOOST_AUTO_TEST_SUITE( bound )
BOOST_AUTO_TEST_CASE( bound__dawg_bound_query_001_ ) {
    std::ifstream defaultGraph( "data-r2/bound/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/bound/bound1.rq", "data-r2/bound/bound1-result.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* bound */)
//BOOST_AUTO_TEST_SUITE( expr_builtin )
BOOST_AUTO_TEST_CASE( expr_builtin__str_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-str-1.rq", "data-r2/expr-builtin/result-str-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__str_2_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-str-2.rq", "data-r2/expr-builtin/result-str-2.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__str_3_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-str-3.rq", "data-r2/expr-builtin/result-str-3.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__str_4_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-str-4.rq", "data-r2/expr-builtin/result-str-4.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__isBlank_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-blank-1.rq", "data-r2/expr-builtin/result-blank-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__isLiteral_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-isliteral-1.rq", "data-r2/expr-builtin/result-isliteral-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__datatype_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-datatype-1.rq", "data-r2/expr-builtin/result-datatype-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__datatype_2___Literals_with_a_datatype_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-datatype-2.rq", "data-r2/expr-builtin/result-datatype-2.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__datatype_3___Literals_with_a_datatype_of_xsd_string_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-datatype-3.rq", "data-r2/expr-builtin/result-datatype-3.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_1___Literals_with_a_lang_tag_of_some_kind_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-lang-1.rq", "data-r2/expr-builtin/result-lang-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_2___Literals_with_a_lang_tag_of____ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-lang-2.rq", "data-r2/expr-builtin/result-lang-2.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_3___Graph_matching_with_lang_tag_being_a_different_case_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-lang-3.rq", "data-r2/expr-builtin/result-lang-3.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__isURI_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-uri-1.rq", "data-r2/expr-builtin/result-uri-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__isIRI_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-iri-1.rq", "data-r2/expr-builtin/result-iri-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__LangMatches_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-langMatches-1.rq", "data-r2/expr-builtin/result-langMatches-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__LangMatches_2_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-langMatches-2.rq", "data-r2/expr-builtin/result-langMatches-2.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__LangMatches_3_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-langMatches-3.rq", "data-r2/expr-builtin/result-langMatches-3.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__LangMatches_4_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-langMatches-4.rq", "data-r2/expr-builtin/result-langMatches-4.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__LangMatches_basic_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-langMatches-de.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/q-langMatches-de-de.rq", "data-r2/expr-builtin/result-langMatches-de.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_case_insensitive_eq_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/lang-case-sensitivity.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/lang-case-sensitivity-eq.rq", "data-r2/expr-builtin/lang-case-insensitive-eq.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_case_insensitive_ne_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/lang-case-sensitivity.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/lang-case-sensitivity-ne.rq", "data-r2/expr-builtin/lang-case-insensitive-ne.srx");
}
BOOST_AUTO_TEST_CASE( expr_builtin__sameTerm_simple_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/sameTerm.rq", "data-r2/expr-builtin/result-sameTerm.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__sameTerm_eq_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/sameTerm-eq.rq", "data-r2/expr-builtin/result-sameTerm-eq.ttl");
}
BOOST_AUTO_TEST_CASE( expr_builtin__sameTerm_not_eq_ ) {
    std::ifstream defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-builtin/sameTerm-not-eq.rq", "data-r2/expr-builtin/result-sameTerm-not-eq.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* expr_builtin */)
//BOOST_AUTO_TEST_SUITE( expr_ops )
BOOST_AUTO_TEST_CASE( expr_ops__Greater_than_or_equals_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-ge-1.rq", "data-r2/expr-ops/result-ge-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_ops__Less_than_or_equals_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-le-1.rq", "data-r2/expr-ops/result-le-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_ops__Multiplication_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-mul-1.rq", "data-r2/expr-ops/result-mul-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_ops__Addition_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-plus-1.rq", "data-r2/expr-ops/result-plus-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_ops__Subtraction_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-minus-1.rq", "data-r2/expr-ops/result-minus-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_ops__Unary_Plusn_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-unplus-1.rq", "data-r2/expr-ops/result-unplus-1.srx");
}
BOOST_AUTO_TEST_CASE( expr_ops__Unary_Minus_ ) {
    std::ifstream defaultGraph( "data-r2/expr-ops/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-ops/query-unminus-1.rq", "data-r2/expr-ops/result-unminus-1.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* expr_ops */)
//BOOST_AUTO_TEST_SUITE( expr_equals )
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_1_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-1.rq", "data-r2/expr-equals/result-eq-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_2_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-2.rq", "data-r2/expr-equals/result-eq-2.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_3_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-3.rq", "data-r2/expr-equals/result-eq-3.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_4_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-4.rq", "data-r2/expr-equals/result-eq-4.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_5_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-5.rq", "data-r2/expr-equals/result-eq-5.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality___2_var___test_equals_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq2-1.rq", "data-r2/expr-equals/result-eq2-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality___2_var___test_not_equals__ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq2-1.rq", "data-r2/expr-equals/result-eq2-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_1____graph_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-graph-1.rq", "data-r2/expr-equals/result-eq-graph-1.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_2____graph_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-graph-2.rq", "data-r2/expr-equals/result-eq-graph-2.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_3____graph_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-graph-3.rq", "data-r2/expr-equals/result-eq-graph-3.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_4____graph_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-graph-4.rq", "data-r2/expr-equals/result-eq-graph-4.ttl");
}
BOOST_AUTO_TEST_CASE( expr_equals__Equality_1_5____graph_ ) {
    std::ifstream defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/expr-equals/query-eq-graph-5.rq", "data-r2/expr-equals/result-eq-graph-5.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* expr_equals */)
//BOOST_AUTO_TEST_SUITE( regex )
BOOST_AUTO_TEST_CASE( regex__regex_query_001_ ) {
    std::ifstream defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/regex/regex-query-001.rq", "data-r2/regex/regex-result-001.ttl");
}
BOOST_AUTO_TEST_CASE( regex__regex_query_002_ ) {
    std::ifstream defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/regex/regex-query-002.rq", "data-r2/regex/regex-result-002.ttl");
}
BOOST_AUTO_TEST_CASE( regex__regex_query_003_ ) {
    std::ifstream defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/regex/regex-query-003.rq", "data-r2/regex/regex-result-003.ttl");
}
BOOST_AUTO_TEST_CASE( regex__regex_query_004_ ) {
    std::ifstream defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/regex/regex-query-004.rq", "data-r2/regex/regex-result-004.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* regex */)
//BOOST_AUTO_TEST_SUITE( i18n )
BOOST_AUTO_TEST_CASE( i18n__kanji_01_ ) {
    std::ifstream defaultGraph( "data-r2/i18n/kanji.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/i18n/kanji-01.rq", "data-r2/i18n/kanji-01-results.ttl");
}
BOOST_AUTO_TEST_CASE( i18n__kanji_02_ ) {
    std::ifstream defaultGraph( "data-r2/i18n/kanji.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/i18n/kanji-02.rq", "data-r2/i18n/kanji-02-results.ttl");
}
BOOST_AUTO_TEST_CASE( i18n__normalization_01_ ) {
    std::ifstream defaultGraph( "data-r2/i18n/normalization-01.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/i18n/normalization-01.rq", "data-r2/i18n/normalization-01-results.ttl");
}
BOOST_AUTO_TEST_CASE( i18n__normalization_02_ ) {
    std::ifstream defaultGraph( "data-r2/i18n/normalization-02.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/i18n/normalization-02.rq", "data-r2/i18n/normalization-02-results.ttl");
}
BOOST_AUTO_TEST_CASE( i18n__normalization_03_ ) {
    std::ifstream defaultGraph( "data-r2/i18n/normalization-03.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/i18n/normalization-03.rq", "data-r2/i18n/normalization-03-results.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* i18n */)
//BOOST_AUTO_TEST_SUITE( construct )
BOOST_AUTO_TEST_CASE( construct__dawg_construct_identity_ ) {
    std::ifstream defaultGraph( "data-r2/construct/data-ident.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/construct/query-ident.rq", "data-r2/construct/result-ident.ttl");
}
BOOST_AUTO_TEST_CASE( construct__dawg_construct_subgraph_ ) {
    std::ifstream defaultGraph( "data-r2/construct/data-ident.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/construct/query-subgraph.rq", "data-r2/construct/result-subgraph.ttl");
}
BOOST_AUTO_TEST_CASE( construct__dawg_construct_reification_1_ ) {
    std::ifstream defaultGraph( "data-r2/construct/data-reif.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/construct/query-reif-1.rq", "data-r2/construct/result-reif.ttl");
}
BOOST_AUTO_TEST_CASE( construct__dawg_construct_reification_2_ ) {
    std::ifstream defaultGraph( "data-r2/construct/data-reif.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/construct/query-reif-2.rq", "data-r2/construct/result-reif.ttl");
}
BOOST_AUTO_TEST_CASE( construct__dawg_construct_optional_ ) {
    std::ifstream defaultGraph( "data-r2/construct/data-opt.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/construct/query-construct-optional.rq", "data-r2/construct/result-construct-optional.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* construct */)
//BOOST_AUTO_TEST_SUITE( ask )
BOOST_AUTO_TEST_CASE( ask__ASK_1__SPARQL_XML_results__ ) {
    std::ifstream defaultGraph( "data-r2/ask/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/ask/ask-1.rq", "data-r2/ask/ask-1.srx");
}
BOOST_AUTO_TEST_CASE( ask__ASK_4__SPARQL_XML_results__ ) {
    std::ifstream defaultGraph( "data-r2/ask/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/ask/ask-4.rq", "data-r2/ask/ask-4.srx");
}
BOOST_AUTO_TEST_CASE( ask__ASK_7__SPARQL_XML_results__ ) {
    std::ifstream defaultGraph( "data-r2/ask/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/ask/ask-7.rq", "data-r2/ask/ask-7.srx");
}
BOOST_AUTO_TEST_CASE( ask__ASK_8__SPARQL_XML_results__ ) {
    std::ifstream defaultGraph( "data-r2/ask/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/ask/ask-8.rq", "data-r2/ask/ask-8.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* ask */)
//BOOST_AUTO_TEST_SUITE( distinct )
BOOST_AUTO_TEST_CASE( distinct__Numbers__No_distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-num.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-num.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Numbers__Distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-num.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-num.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Strings__No_distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-str.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-str.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Strings__Distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-str.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-str.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Nodes__No_distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-node.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-node.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Nodes__Distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-node.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-node.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Opt__No_distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-opt.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/no-distinct-2.rq", "data-r2/distinct/no-distinct-opt.srx");
}
BOOST_AUTO_TEST_CASE( distinct__Opt__Distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-opt.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/distinct-2.rq", "data-r2/distinct/distinct-opt.srx");
}
BOOST_AUTO_TEST_CASE( distinct__All__No_distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-all.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-all.srx");
}
BOOST_AUTO_TEST_CASE( distinct__All__Distinct_ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-all.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-all.srx");
}
BOOST_AUTO_TEST_CASE( distinct__SELECT_DISTINCT___ ) {
    std::ifstream defaultGraph( "data-r2/distinct/data-star.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/distinct/distinct-star-1.rq", "data-r2/distinct/distinct-star-1.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* distinct */)
//BOOST_AUTO_TEST_SUITE( sort )
BOOST_AUTO_TEST_CASE( sort__sort_1_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-1.rq", "data-r2/sort/result-sort-1.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_2_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-2.rq", "data-r2/sort/result-sort-2.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_3_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-3.rq", "data-r2/sort/result-sort-3.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_4_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-4.rq", "data-r2/sort/result-sort-4.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_5_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-5.rq", "data-r2/sort/result-sort-5.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_6_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-6.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-6.rq", "data-r2/sort/result-sort-6.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_7_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-7.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-4.rq", "data-r2/sort/result-sort-7.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_8_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-8.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-4.rq", "data-r2/sort/result-sort-8.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_9_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-9.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-9.rq", "data-r2/sort/result-sort-9.rdf");
}
BOOST_AUTO_TEST_CASE( sort__sort_10_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-9.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-10.rq", "data-r2/sort/result-sort-10.rdf");
}
BOOST_AUTO_TEST_CASE( sort__Expression_sort_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-numbers.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-numbers.rq", "data-r2/sort/result-sort-numbers.ttl");
}
BOOST_AUTO_TEST_CASE( sort__Builtin_sort_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-builtin.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-builtin.rq", "data-r2/sort/result-sort-builtin.ttl");
}
BOOST_AUTO_TEST_CASE( sort__Function_sort_ ) {
    std::ifstream defaultGraph( "data-r2/sort/data-sort-function.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/sort/query-sort-function.rq", "data-r2/sort/result-sort-function.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* sort */)
//BOOST_AUTO_TEST_SUITE( solution_seq )
BOOST_AUTO_TEST_CASE( solution_seq__Limit_1_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-01.rq", "data-r2/solution-seq/slice-results-01.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Limit_2_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-02.rq", "data-r2/solution-seq/slice-results-02.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Limit_3_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-03.rq", "data-r2/solution-seq/slice-results-03.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Limit_4_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-04.rq", "data-r2/solution-seq/slice-results-04.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Offset_1_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-10.rq", "data-r2/solution-seq/slice-results-10.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Offset_2_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-11.rq", "data-r2/solution-seq/slice-results-11.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Offset_3_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-12.rq", "data-r2/solution-seq/slice-results-12.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Offset_4_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-13.rq", "data-r2/solution-seq/slice-results-13.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Slice_1_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-20.rq", "data-r2/solution-seq/slice-results-20.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Slice_2_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-21.rq", "data-r2/solution-seq/slice-results-21.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Slice_3_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-22.rq", "data-r2/solution-seq/slice-results-22.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Slice_4_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-23.rq", "data-r2/solution-seq/slice-results-23.ttl");
}
BOOST_AUTO_TEST_CASE( solution_seq__Slice_5_ ) {
    std::ifstream defaultGraph( "data-r2/solution-seq/data.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/solution-seq/slice-24.rq", "data-r2/solution-seq/slice-results-24.ttl");
}
//BOOST_AUTO_TEST_SUITE_END(/* solution_seq */)
//BOOST_AUTO_TEST_SUITE( reduced )
BOOST_AUTO_TEST_CASE( reduced__SELECT_REDUCED___ ) {
    std::ifstream defaultGraph( "data-r2/reduced/reduced-star.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/reduced/reduced-1.rq", "data-r2/reduced/reduced-1.srx");
}
BOOST_AUTO_TEST_CASE( reduced__SELECT_REDUCED__x_with_strings_ ) {
    std::ifstream defaultGraph( "data-r2/reduced/reduced-str.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/reduced/reduced-2.rq", "data-r2/reduced/reduced-2.srx");
}
//BOOST_AUTO_TEST_SUITE_END(/* reduced */)

BOOST_AUTO_TEST_CASE( test_fail ) {
    BOOST_CHECK_EQUAL(1, 0);
}
// EOF

