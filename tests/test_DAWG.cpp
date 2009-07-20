/* perform DAWG tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * compilations switches:
 *   usual ones from ../CONFIG
 *   TEST_DAWG_EXTENSIONS
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define MARK std::cout << __FILE__ "(" TOSTRING(__LINE__) "): warning MARK" << std::endl;

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE DAWG_tests
#include "../tests/SparqlQueryTestResultSet.hpp"

BOOST_AUTO_TEST_SUITE( triple_match )
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001 ) {
    /* name: dawg-triple-pattern-001
     * Simple triple match
     */
    const char* defaultGraph( "data-r2/triple-match/data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/triple-match/dawg-tp-01.rq", "data-r2/triple-match/result-tp-01.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_002 ) {
    /* name: dawg-triple-pattern-002
     * Simple triple match
     */
    const char* defaultGraph( "data-r2/triple-match/data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/triple-match/dawg-tp-02.rq", "data-r2/triple-match/result-tp-02.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_003 ) {
    /* name: dawg-triple-pattern-003
     * Simple triple match - repeated variable
     */
    const char* defaultGraph( "data-r2/triple-match/data-02.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/triple-match/dawg-tp-03.rq", "data-r2/triple-match/result-tp-03.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_004 ) {
    /* name: dawg-triple-pattern-004
     * Simple triple match - two triples, common variable
     */
    const char* defaultGraph( "data-r2/triple-match/dawg-data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/triple-match/dawg-tp-04.rq", "data-r2/triple-match/result-tp-04.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* triple_match */)

BOOST_AUTO_TEST_SUITE( basic )
BOOST_AUTO_TEST_CASE( basic__base_prefix_1 ) {
    /* name: Basic - Prefix/Base 1
     */
    const char* defaultGraph( "data-r2/basic/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/base-prefix-1.rq", "data-r2/basic/base-prefix-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__base_prefix_2 ) {
    /* name: Basic - Prefix/Base 2
     */
    const char* defaultGraph( "data-r2/basic/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/base-prefix-2.rq", "data-r2/basic/base-prefix-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__base_prefix_3 ) {
    /* name: Basic - Prefix/Base 3
     */
    const char* defaultGraph( "data-r2/basic/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/base-prefix-3.rq", "data-r2/basic/base-prefix-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__base_prefix_4 ) {
    /* name: Basic - Prefix/Base 4
     */
    const char* defaultGraph( "data-r2/basic/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/base-prefix-4.rq", "data-r2/basic/base-prefix-4.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__base_prefix_5 ) {
    /* name: Basic - Prefix/Base 5
     */
    const char* defaultGraph( "data-r2/basic/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/base-prefix-5.rq", "data-r2/basic/base-prefix-5.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__list_1 ) {
    /* name: Basic - List 1
     */
    const char* defaultGraph( "data-r2/basic/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/list-1.rq", "data-r2/basic/list-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__list_2 ) {
    /* name: Basic - List 2
     */
    const char* defaultGraph( "data-r2/basic/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/list-2.rq", "data-r2/basic/list-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__list_3 ) {
    /* name: Basic - List 3
     */
    const char* defaultGraph( "data-r2/basic/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/list-3.rq", "data-r2/basic/list-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__list_4 ) {
    /* name: Basic - List 4
     */
    const char* defaultGraph( "data-r2/basic/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/list-4.rq", "data-r2/basic/list-4.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__quotes_1 ) {
    /* name: Basic - Quotes 1
     */
    const char* defaultGraph( "data-r2/basic/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/quotes-1.rq", "data-r2/basic/quotes-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__quotes_2 ) {
    /* name: Basic - Quotes 2
     */
    const char* defaultGraph( "data-r2/basic/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/quotes-2.rq", "data-r2/basic/quotes-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__quotes_3 ) {
    /* name: Basic - Quotes 3
     */
    const char* defaultGraph( "data-r2/basic/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/quotes-3.rq", "data-r2/basic/quotes-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__quotes_4 ) {
    /* name: Basic - Quotes 4
     */
    const char* defaultGraph( "data-r2/basic/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/quotes-4.rq", "data-r2/basic/quotes-4.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_1 ) {
    /* name: Basic - Term 1
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-1.rq", "data-r2/basic/term-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_2 ) {
    /* name: Basic - Term 2
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-2.rq", "data-r2/basic/term-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_3 ) {
    /* name: Basic - Term 3
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-3.rq", "data-r2/basic/term-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_4 ) {
    /* name: Basic - Term 4
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-4.rq", "data-r2/basic/term-4.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_5 ) {
    /* name: Basic - Term 5
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-5.rq", "data-r2/basic/term-5.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_6 ) {
    /* name: Basic - Term 6
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-6.rq", "data-r2/basic/term-6.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_7 ) {
    /* name: Basic - Term 7
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-7.rq", "data-r2/basic/term-7.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_8 ) {
    /* name: Basic - Term 8
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-8.rq", "data-r2/basic/term-8.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__term_9 ) {
    /* name: Basic - Term 9
     */
    const char* defaultGraph( "data-r2/basic/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/term-9.rq", "data-r2/basic/term-9.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__var_1 ) {
    /* name: Basic - Var 1
     */
    const char* defaultGraph( "data-r2/basic/data-5.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/var-1.rq", "data-r2/basic/var-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__var_2 ) {
    /* name: Basic - Var 2
     */
    const char* defaultGraph( "data-r2/basic/data-5.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/var-2.rq", "data-r2/basic/var-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__bgp_no_match ) {
    /* name: Non-matching triple pattern
     * Patterns not in data don't match
     */
    const char* defaultGraph( "data-r2/basic/data-7.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/bgp-no-match.rq", "data-r2/basic/bgp-no-match.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__spoo_1 ) {
    /* name: Basic graph pattern - spoo
     * Test the :x :y :o1, :o2 construct
     */
    const char* defaultGraph( "data-r2/basic/data-6.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/spoo-1.rq", "data-r2/basic/spoo-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( basic__prefix_name_1 ) {
    /* name: Prefix name 1
     * No local name - foo:
     */
    const char* defaultGraph( "data-r2/basic/data-6.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/basic/prefix-name-1.rq", "data-r2/basic/prefix-name-1.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* basic */)

BOOST_AUTO_TEST_SUITE( ask )
BOOST_AUTO_TEST_CASE( ask__ask_1 ) {
    /* name: ASK-1 (SPARQL XML results)
     */
    const char* defaultGraph( "data-r2/ask/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/ask/ask-1.rq", "data-r2/ask/ask-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( ask__ask_4 ) {
    /* name: ASK-4 (SPARQL XML results)
     */
    const char* defaultGraph( "data-r2/ask/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/ask/ask-4.rq", "data-r2/ask/ask-4.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( ask__ask_7 ) {
    /* name: ASK-7 (SPARQL XML results)
     */
    const char* defaultGraph( "data-r2/ask/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/ask/ask-7.rq", "data-r2/ask/ask-7.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( ask__ask_8 ) {
    /* name: ASK-8 (SPARQL XML results)
     */
    const char* defaultGraph( "data-r2/ask/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/ask/ask-8.rq", "data-r2/ask/ask-8.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* ask */)

BOOST_AUTO_TEST_SUITE( construct )
BOOST_AUTO_TEST_CASE( construct__construct_1 ) {
    /* name: dawg-construct-identity
     * Graph equivalent result graph
     */
    const char* defaultGraph( "data-r2/construct/data-ident.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/construct/query-ident.rq", "data-r2/construct/result-ident.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( construct__construct_2 ) {
    /* name: dawg-construct-subgraph
     * Result subgraph of original graph
     */
    const char* defaultGraph( "data-r2/construct/data-ident.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/construct/query-subgraph.rq", "data-r2/construct/result-subgraph.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( construct__construct_3 ) {
    /* name: dawg-construct-reification-1
     * Reification of the default graph
     */
    const char* defaultGraph( "data-r2/construct/data-reif.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/construct/query-reif-1.rq", "data-r2/construct/result-reif.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( construct__construct_4 ) {
    /* name: dawg-construct-reification-2
     * Reification of the default graph
     */
    const char* defaultGraph( "data-r2/construct/data-reif.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/construct/query-reif-2.rq", "data-r2/construct/result-reif.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( construct__construct_5 ) {
    /* name: dawg-construct-optional
     * Reification of the default graph
     */
    const char* defaultGraph( "data-r2/construct/data-opt.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/construct/query-construct-optional.rq", "data-r2/construct/result-construct-optional.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* construct */)

BOOST_AUTO_TEST_SUITE( algebra )
BOOST_AUTO_TEST_CASE( algebra__nested_opt_1 ) {
    /* name: Nested Optionals - 1
     * Nested-optionals with a shared variable that does not appear in the middle pattern (a not well-formed query pattern as per "Semantics and Complexity" of SPARQL
     */
    const char* defaultGraph( "data-r2/algebra/two-nested-opt.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/two-nested-opt.rq", "data-r2/algebra/two-nested-opt.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__nested_opt_2 ) {
    /* name: Nested Optionals - 2
     * OPTIONALs parse in a left-associative manner
     */
    const char* defaultGraph( "data-r2/algebra/two-nested-opt.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/two-nested-opt-alt.rq", "data-r2/algebra/two-nested-opt-alt.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__opt_filter_1 ) {
    /* name: Optional-filter - 1
     * A FILTER inside an OPTIONAL can reference a variable bound in the required part of the OPTIONAL
     */
    const char* defaultGraph( "data-r2/algebra/opt-filter-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/opt-filter-1.rq", "data-r2/algebra/opt-filter-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__opt_filter_2 ) {
    /* name: Optional-filter - 2 filters
     * FILTERs inside an OPTIONAL can refer to variables from both the required and optional parts of the construct.
     */
    const char* defaultGraph( "data-r2/algebra/opt-filter-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/opt-filter-2.rq", "data-r2/algebra/opt-filter-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__opt_filter_3 ) {
    /* name: Optional-filter - scope of variable
     * FILTERs in an OPTIONAL do not extend to variables bound outside of the LeftJoin(...) operation
     */
    const char* defaultGraph( "data-r2/algebra/opt-filter-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/opt-filter-3.rq", "data-r2/algebra/opt-filter-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__filter_place_1 ) {
    /* name: Filter-placement - 1
     * FILTER placed after the triple pattern that contains the variable tested
     */
    const char* defaultGraph( "data-r2/algebra/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/filter-placement-1.rq", "data-r2/algebra/filter-placement-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__filter_place_2 ) {
    /* name: Filter-placement - 2
     * FILTERs are scoped to the nearest enclosing group - placement within that group does not matter
     */
    const char* defaultGraph( "data-r2/algebra/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/filter-placement-2.rq", "data-r2/algebra/filter-placement-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__filter_place_3 ) {
    /* name: Filter-placement - 3
     * FILTERs are scoped to the nearest enclosing group - placement within that group does not matter
     */
    const char* defaultGraph( "data-r2/algebra/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/filter-placement-3.rq", "data-r2/algebra/filter-placement-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__filter_nested_1 ) {
    /* name: Filter-nested - 1
     * A FILTER is in scope for variables bound at the same level of the query tree
     */
    const char* defaultGraph( "data-r2/algebra/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/filter-nested-1.rq", "data-r2/algebra/filter-nested-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__filter_nested_2 ) {
    /* name: Filter-nested - 2
     * A FILTER in a group { ... } cannot see variables bound outside that group
     */
    const char* defaultGraph( "data-r2/algebra/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/filter-nested-2.rq", "data-r2/algebra/filter-nested-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__filter_scope_1 ) {
    /* name: Filter-scope - 1
     * FILTERs in an OPTIONAL do not extend to variables bound outside of the LeftJoin(...) operation
     */
    const char* defaultGraph( "data-r2/algebra/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/filter-scope-1.rq", "data-r2/algebra/filter-scope-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__join_scope_1 ) {
    /* name: Join scope - 1
     * Variables have query scope.
     */
    const char* defaultGraph( "data-r2/algebra/var-scope-join-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/var-scope-join-1.rq", "data-r2/algebra/var-scope-join-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__join_combo_1 ) {
    /* name: Join operator with OPTs, BGPs, and UNIONs
     * Tests nested combination of Join with a BGP / OPT and a BGP / UNION
     */
    const char* defaultGraph( "data-r2/algebra/join-combo-graph-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/join-combo-1.rq", "data-r2/algebra/join-combo-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( algebra__join_combo_2 ) {
    /* name: Join operator with Graph and Union
     * Tests combination of Join operator with Graph on LHS and Union on RHS
     */
    const char* defaultGraph( "data-r2/algebra/join-combo-graph-2.ttl" );
    const char* namedGraphs[] = {"data-r2/algebra/join-combo-graph-1.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/algebra/join-combo-2.rq", "data-r2/algebra/join-combo-2.srx", 1, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* algebra */)

BOOST_AUTO_TEST_SUITE( dataset )
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_01 ) {
    /* name: dataset-01
     * Data: default dataset / Query: default dataset
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-01.rq", "data-r2/dataset/dataset-01.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_02 ) {
    /* name: dataset-02
     * Data: named dataset / Query: default dataset
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-02.rq", "data-r2/dataset/dataset-02.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_03 ) {
    /* name: dataset-03
     * Data: named dataset / Query: named dataset dataset
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-03.rq", "data-r2/dataset/dataset-03.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_04 ) {
    /* name: dataset-04
     * Data: named dataset / Query: default dataset
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-04.rq", "data-r2/dataset/dataset-04.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_05 ) {
    /* name: dataset-05
     * Data: default and named / Query: default dataset
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-05.rq", "data-r2/dataset/dataset-05.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_06 ) {
    /* name: dataset-06
     * Data: default and named / Query: named dataset
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-06.rq", "data-r2/dataset/dataset-06.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_07 ) {
    /* name: dataset-07
     * Data: default and named / Query: all data by UNION
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-07.rq", "data-r2/dataset/dataset-07.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_08 ) {
    /* name: dataset-08
     * Data: default and named / Query: common subjects
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-08.rq", "data-r2/dataset/dataset-08.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_11 ) {
    /* name: dataset-11
     * Data: default and named (several) / Query: get everything
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-11.rq", "data-r2/dataset/dataset-11.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_09b ) {
    /* name: dataset-09b
     * Data: default and named (bnodes) / Query: common subjects
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-09b.rq", "data-r2/dataset/dataset-09.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_10b ) {
    /* name: dataset-10b
     * Data: default and named (same data, with bnodes) / Query: common subjects
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-10b.rq", "data-r2/dataset/dataset-10.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( dataset__dawg_dataset_12b ) {
    /* name: dataset-12b
     * Data: default (several) and named (several) / Query: get everything
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/dataset/dataset-12b.rq", "data-r2/dataset/dataset-12.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* dataset */)

BOOST_AUTO_TEST_SUITE( graph )
BOOST_AUTO_TEST_CASE( graph__dawg_graph_01 ) {
    /* name: graph-01
     * Data: default graph / Query: default graph
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-01.rq", "data-r2/graph/graph-01.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_02 ) {
    /* name: graph-02
     * Data: named graph / Query: default graph
     */
    const char* defaultGraph( NULL );
    const char* namedGraphs[] = {"data-r2/graph/data-g1.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-02.rq", "data-r2/graph/graph-02.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_03 ) {
    /* name: graph-03
     * Data: named graph / Query: named graph graph
     */
    const char* defaultGraph( NULL );
    const char* namedGraphs[] = {"data-r2/graph/data-g1.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-03.rq", "data-r2/graph/graph-03.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_04 ) {
    /* name: graph-04
     * Data: named graph / Query: default graph
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-04.rq", "data-r2/graph/graph-04.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_05 ) {
    /* name: graph-05
     * Data: default and named / Query: default graph
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g2.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-05.rq", "data-r2/graph/graph-05.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_06 ) {
    /* name: graph-06
     * Data: default and named / Query: named graph
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g2.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-06.rq", "data-r2/graph/graph-06.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_07 ) {
    /* name: graph-07
     * Data: default and named / Query: all data by UNION
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g2.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-07.rq", "data-r2/graph/graph-07.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_08 ) {
    /* name: graph-08
     * Data: default and named / Query: common subjects
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g2.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-08.rq", "data-r2/graph/graph-08.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_09 ) {
    /* name: graph-09
     * Data: default and named (bnodes) / Query: common subjects
     */
    const char* defaultGraph( "data-r2/graph/data-g3.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g4.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-09.rq", "data-r2/graph/graph-09.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_10b ) {
    /* name: graph-10b
     * Data: default and named (same data, with bnodes) / Query: common subjects
     */
    const char* defaultGraph( "data-r2/graph/data-g3.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g3-dup.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-10.rq", "data-r2/graph/graph-10.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( graph__dawg_graph_11 ) {
    /* name: graph-11
     * Data: default and named (several) / Query: get everything
     */
    const char* defaultGraph( "data-r2/graph/data-g1.ttl" );
    const char* namedGraphs[] = {"data-r2/graph/data-g1.ttl",
                                 "data-r2/graph/data-g2.ttl",
                                 "data-r2/graph/data-g3.ttl",
                                 "data-r2/graph/data-g4.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/graph/graph-11.rq", "data-r2/graph/graph-11.ttl", 4, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* graph */)

BOOST_AUTO_TEST_SUITE( i18n )
BOOST_AUTO_TEST_CASE( i18n__kanji_1 ) {
    /* name: kanji-01
     */
    const char* defaultGraph( "data-r2/i18n/kanji.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/i18n/kanji-01.rq", "data-r2/i18n/kanji-01-results.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( i18n__kanji_2 ) {
    /* name: kanji-02
     */
    const char* defaultGraph( "data-r2/i18n/kanji.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/i18n/kanji-02.rq", "data-r2/i18n/kanji-02-results.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( i18n__normalization_1 ) {
    /* name: normalization-01
     */
    const char* defaultGraph( "data-r2/i18n/normalization-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL; /* SPARQLfedParser sends 0x301 to stdout; TurtleSParser sends two. */
    DAWG_TEST("data-r2/i18n/normalization-01.rq", "data-r2/i18n/normalization-01-results.ttl", 0, 0); std::cout << "<-- uglies" << std::endl;
}
BOOST_AUTO_TEST_CASE( i18n__normalization_2 ) {
    /* name: normalization-02
     * Example 1 from http://lists.w3.org/Archives/Public/public-rdf-dawg/2005JulSep/0096
     */
    const char* defaultGraph( "data-r2/i18n/normalization-02.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/i18n/normalization-02.rq", "data-r2/i18n/normalization-02-results.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( i18n__normalization_3 ) {
    /* name: normalization-03
     * Example 2 from http://lists.w3.org/Archives/Public/public-rdf-dawg/2005JulSep/0096
     */
    const char* defaultGraph( "data-r2/i18n/normalization-03.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/i18n/normalization-03.rq", "data-r2/i18n/normalization-03-results.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* i18n */)

BOOST_AUTO_TEST_SUITE( open_world )
BOOST_AUTO_TEST_CASE( open_world__open_eq_01 ) {
    /* name: open-eq-01
     * graph match - no lexical form in data (assumes no value matching)
     */
    const char* defaultGraph( "data-r2/open-world/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-01.rq", "data-r2/open-world/open-eq-01-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_02 ) {
    /* name: open-eq-02
     * graph match - unknown type
     */
    const char* defaultGraph( "data-r2/open-world/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-02.rq", "data-r2/open-world/open-eq-02-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_03 ) {
    /* name: open-eq-03
     * Filter(?v=1)
     */
    const char* defaultGraph( "data-r2/open-world/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-03.rq", "data-r2/open-world/open-eq-03-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_04 ) {
    /* name: open-eq-04
     * Filter(?v!=1)
     */
    const char* defaultGraph( "data-r2/open-world/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-04.rq", "data-r2/open-world/open-eq-04-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_05 ) {
    /* name: open-eq-05
     * FILTER(?v = unknown type)
     */
    const char* defaultGraph( "data-r2/open-world/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-05.rq", "data-r2/open-world/open-eq-05-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_06 ) {
    /* name: open-eq-06
     * FILTER(?v != unknown type)
     */
    const char* defaultGraph( "data-r2/open-world/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-06.rq", "data-r2/open-world/open-eq-06-result.srx", 0, 0);
}
#ifdef TEST_DAWG_EXTENSIONS
BOOST_AUTO_TEST_CASE( open_world__open_eq_07 ) {
    /* name: open-eq-07
     * Test of '=' 
     */
    const char* defaultGraph( "data-r2/open-world/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#LangTagAwareness"),
                             F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#StringSimpleLiteralCmp")};
    DAWG_TEST("data-r2/open-world/open-eq-07.rq", "data-r2/open-world/open-eq-07-result.srx", 0, 2);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_08 ) {
    /* name: open-eq-08
     * Test of '!='
     */
    const char* defaultGraph( "data-r2/open-world/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#StringSimpleLiteralCmp"),
                             F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#LangTagAwareness"),
                             F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#KnownTypesDefault2Neq")};
    DAWG_TEST("data-r2/open-world/open-eq-08.rq", "data-r2/open-world/open-eq-08-result.srx", 0, 3);
}
#endif /* TEST_DAWG_EXTENSIONS */
BOOST_AUTO_TEST_CASE( open_world__open_eq_09 ) {
    /* name: open-eq-09
     * Test of '='
     */
    const char* defaultGraph( "data-r2/open-world/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-eq-09.rq", "data-r2/open-world/open-eq-09-result.srx", 0, 0);
}
#ifdef TEST_DAWG_EXTENSIONS
BOOST_AUTO_TEST_CASE( open_world__open_eq_10 ) {
    /* name: open-eq-10
     * Test of '!='
     */
    const char* defaultGraph( "data-r2/open-world/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#KnownTypesDefault2Neq"),
                             F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#LangTagAwareness")};
    DAWG_TEST("data-r2/open-world/open-eq-10.rq", "data-r2/open-world/open-eq-10-result.srx", 0, 2);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_11 ) {
    /* name: open-eq-11
     * test of '=' || '!='
     */
    const char* defaultGraph( "data-r2/open-world/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#KnownTypesDefault2Neq")};
    DAWG_TEST("data-r2/open-world/open-eq-11.rq", "data-r2/open-world/open-eq-11-result.srx", 0, 1);
}
BOOST_AUTO_TEST_CASE( open_world__open_eq_12 ) {
    /* name: open-eq-12
     * find pairs that don't value-compare
     */
    const char* defaultGraph( "data-r2/open-world/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#KnownTypesDefault2Neq"),
                             F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#LangTagAwareness")};
    DAWG_TEST("data-r2/open-world/open-eq-12.rq", "data-r2/open-world/open-eq-12-result.srx", 0, 2);
}
BOOST_AUTO_TEST_CASE( open_world__date_2 ) {
    /* name: date-2
     * Added type : xsd:date '!='
     */
    const char* defaultGraph( "data-r2/open-world/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#XsdDateOperations")};
    DAWG_TEST("data-r2/open-world/date-2.rq", "data-r2/open-world/date-2-result.srx", 0, 1);
}
BOOST_AUTO_TEST_CASE( open_world__date_3 ) {
    /* name: date-3
     * Added type : xsd:date '>'
     */
    const char* defaultGraph( "data-r2/open-world/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI* requires[] = {F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#XsdDateOperations")};
    DAWG_TEST("data-r2/open-world/date-3.rq", "data-r2/open-world/date-3-result.srx", 0, 1);
}
#endif /* TEST_DAWG_EXTENSIONS */
BOOST_AUTO_TEST_CASE( open_world__date_4 ) {
    /* name: date-4
     * xsd:date ORDER BY
     */
    const char* defaultGraph( "data-r2/open-world/data-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/date-4.rq", "data-r2/open-world/date-4-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_cmp_01 ) {
    /* name: open-cmp-01
     * Find things that compare with < or >
     */
    const char* defaultGraph( "data-r2/open-world/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-cmp-01.rq", "data-r2/open-world/open-cmp-01-result.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( open_world__open_cmp_02 ) {
    /* name: open-cmp-02
     * Find things that compare with <= and >
     */
    const char* defaultGraph( "data-r2/open-world/data-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/open-world/open-cmp-02.rq", "data-r2/open-world/open-cmp-02-result.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* open_world */)

BOOST_AUTO_TEST_SUITE( optional )
BOOST_AUTO_TEST_CASE( optional__dawg_optional_001 ) {
    /* name: One optional clause
     * One optional clause
     */
    const char* defaultGraph( "data-r2/optional/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-1.rq", "data-r2/optional/result-opt-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional__dawg_optional_002 ) {
    /* name: Two optional clauses
     * One optional clause
     */
    const char* defaultGraph( "data-r2/optional/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-2.rq", "data-r2/optional/result-opt-2.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional__dawg_union_001 ) {
    /* name: Union is not optional
     * Union is not optional
     */
    const char* defaultGraph( "data-r2/optional/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-3.rq", "data-r2/optional/result-opt-3.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional__dawg_optional_complex_1 ) {
    /* name: Complex optional semantics: 1
     * Complex optional: LeftJoin(LeftJoin(BGP(..),{..}),Join(BGP(..),Union(..,..)))
     */
    const char* defaultGraph( "data-r2/optional/complex-data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-complex-1.rq", "data-r2/optional/result-opt-complex-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional__dawg_optional_complex_2 ) {
    /* name: Complex optional semantics: 2
     * Complex optional: LeftJoin(Join(BGP(..),Graph(var,{..})),Union(..,..))
     */
    const char* defaultGraph( "data-r2/optional/complex-data-2.ttl" );
    const char* namedGraphs[] = {"data-r2/optional/complex-data-1.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-complex-2.rq", "data-r2/optional/result-opt-complex-2.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( optional__dawg_optional_complex_3 ) {
    /* name: Complex optional semantics: 3
     * Complex optional: LeftJoin(Join(BGP(..),Graph(var,{..})),LeftJoin(BGP(..),{..}))
     */
    const char* defaultGraph( "data-r2/optional/complex-data-2.ttl" );
    const char* namedGraphs[] = {"data-r2/optional/complex-data-1.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-complex-3.rq", "data-r2/optional/result-opt-complex-3.ttl", 1, 0);
}
BOOST_AUTO_TEST_CASE( optional__dawg_optional_complex_4 ) {
    /* name: Complex optional semantics: 4
     * Complex optional: LeftJoin(Join(BGP(..),Union(..,..)),Join(BGP(..),Graph(varOrIRI,{..})))
     */
    const char* defaultGraph( "data-r2/optional/complex-data-2.ttl" );
    const char* namedGraphs[] = {"data-r2/optional/complex-data-1.ttl"};
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional/q-opt-complex-4.rq", "data-r2/optional/result-opt-complex-4.ttl", 1, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* optional */)

BOOST_AUTO_TEST_SUITE( optional_filter )
BOOST_AUTO_TEST_CASE( optional_filter__dawg_optional_filter_001 ) {
    /* name: OPTIONAL-FILTER
     * FILTER inside an OPTIONAL does not block an entire solution
     */
    const char* defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional-filter/expr-1.rq", "data-r2/optional-filter/expr-1-result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional_filter__dawg_optional_filter_002 ) {
    /* name: OPTIONAL - Outer FILTER
     * FILTER outside an OPTIONAL tests bound and unbound variables
     */
    const char* defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional-filter/expr-2.rq", "data-r2/optional-filter/expr-2-result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional_filter__dawg_optional_filter_003 ) {
    /* name: OPTIONAL - Outer FILTER with BOUND
     * Use !bound to only run outer FILTERs against variables bound in an OPTIONAL
     */
    const char* defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional-filter/expr-3.rq", "data-r2/optional-filter/expr-3-result.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( optional_filter__dawg_optional_filter_004 ) {
    /* name: OPTIONAL - Inner FILTER with negative EBV for outer variables
     * FILTER inside an OPTIONAL does not corrupt the entire solution
     */
    const char* defaultGraph( "data-r2/optional-filter/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/optional-filter/expr-4.rq", "data-r2/optional-filter/expr-4-result.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* optional_filter */)

BOOST_AUTO_TEST_SUITE( solution_seq )
BOOST_AUTO_TEST_CASE( solution_seq__limit_1 ) {
    /* name: Limit 1
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-01.rq", "data-r2/solution-seq/slice-results-01.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__limit_2 ) {
    /* name: Limit 2
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-02.rq", "data-r2/solution-seq/slice-results-02.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__limit_3 ) {
    /* name: Limit 3
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-03.rq", "data-r2/solution-seq/slice-results-03.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__limit_4 ) {
    /* name: Limit 4
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-04.rq", "data-r2/solution-seq/slice-results-04.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__offset_1 ) {
    /* name: Offset 1
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-10.rq", "data-r2/solution-seq/slice-results-10.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__offset_2 ) {
    /* name: Offset 2
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-11.rq", "data-r2/solution-seq/slice-results-11.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__offset_3 ) {
    /* name: Offset 3
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-12.rq", "data-r2/solution-seq/slice-results-12.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__offset_4 ) {
    /* name: Offset 4
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-13.rq", "data-r2/solution-seq/slice-results-13.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__slice_1 ) {
    /* name: Slice 1
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-20.rq", "data-r2/solution-seq/slice-results-20.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__slice_2 ) {
    /* name: Slice 2
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-21.rq", "data-r2/solution-seq/slice-results-21.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__slice_3 ) {
    /* name: Slice 3
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-22.rq", "data-r2/solution-seq/slice-results-22.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__slice_4 ) {
    /* name: Slice 4
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-23.rq", "data-r2/solution-seq/slice-results-23.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( solution_seq__slice_5 ) {
    /* name: Slice 5
     */
    const char* defaultGraph( "data-r2/solution-seq/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/solution-seq/slice-24.rq", "data-r2/solution-seq/slice-results-24.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* solution_seq */)

BOOST_AUTO_TEST_SUITE( boolean_effective_value )
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_boolean_literal ) {
    /* name: Test literal 'true'
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-boolean-literal.rq", "data-r2/boolean-effective-value/result-boolean-literal.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_bev_1 ) {
    /* name: Test 'boolean effective value' - true
     * Non-zero numerics, non-empty strings, and the true boolean have an EBV of true
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-bev-1.rq", "data-r2/boolean-effective-value/result-bev-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_bev_2 ) {
    /* name: Test 'boolean effective value' - false
     * Zero-valued numerics, the empty string, and the false boolean have an EBV of false
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-bev-2.rq", "data-r2/boolean-effective-value/result-bev-2.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_bev_3 ) {
    /* name: Test 'boolean effective value' - &&
     * The && operator takes the EBV of its operands
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-bev-3.rq", "data-r2/boolean-effective-value/result-bev-3.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_bev_4 ) {
    /* name: Test 'boolean effective value' - ||
     * The || operator takes the EBV of its operands
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-bev-4.rq", "data-r2/boolean-effective-value/result-bev-4.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_bev_5 ) {
    /* name: Test 'boolean effective value' - optional
     * The EBV of an unbound value  or a literal with an unknown datatype is a type error, which eliminates the solution in question
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-bev-5.rq", "data-r2/boolean-effective-value/result-bev-5.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( boolean_effective_value__dawg_bev_6 ) {
    /* name: Test 'boolean effective value' - unknown types
     * Negating a type error is still a type error
     */
    const char* defaultGraph( "data-r2/boolean-effective-value/data-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/boolean-effective-value/query-bev-6.rq", "data-r2/boolean-effective-value/result-bev-6.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* boolean_effective_value */)

BOOST_AUTO_TEST_SUITE( bound )
BOOST_AUTO_TEST_CASE( bound__dawg_bound_query_001 ) {
    /* name: dawg-bound-query-001
     * BOUND test case.
     */
    const char* defaultGraph( "data-r2/bound/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/bound/bound1.rq", "data-r2/bound/bound1-result.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* bound */)

BOOST_AUTO_TEST_SUITE( cast )
BOOST_AUTO_TEST_CASE( cast__cast_str ) {
    /* name: Cast to xsd:string
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-str.rq", "data-r2/cast/cast-str.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( cast__cast_flt ) {
    /* name: Cast to xsd:float
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-flt.rq", "data-r2/cast/cast-flt.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( cast__cast_dbl ) {
    /* name: Cast to xsd:double
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-dbl.rq", "data-r2/cast/cast-dbl.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( cast__cast_dec ) {
    /* name: Cast to xsd:decimal
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-dec.rq", "data-r2/cast/cast-dec.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( cast__cast_int ) {
    /* name: Cast to xsd:integer
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-int.rq", "data-r2/cast/cast-int.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( cast__cast_dT ) {
    /* name: Cast to xsd:dateTime
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-dT.rq", "data-r2/cast/cast-dT.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( cast__cast_bool ) {
    /* name: Cast to xsd:boolean
     */
    const char* defaultGraph( "data-r2/cast/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/cast/cast-bool.rq", "data-r2/cast/cast-bool.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* cast */)

BOOST_AUTO_TEST_SUITE( expr_builtin )
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_str_1 ) {
    /* name: str-1
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-str-1.rq", "data-r2/expr-builtin/result-str-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_str_2 ) {
    /* name: str-2
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-str-2.rq", "data-r2/expr-builtin/result-str-2.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_str_3 ) {
    /* name: str-3
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-str-3.rq", "data-r2/expr-builtin/result-str-3.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_str_4 ) {
    /* name: str-4
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-str-4.rq", "data-r2/expr-builtin/result-str-4.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_isBlank_1 ) {
    /* name: isBlank-1
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-blank-1.rq", "data-r2/expr-builtin/result-blank-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_isLiteral_1 ) {
    /* name: isLiteral
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-isliteral-1.rq", "data-r2/expr-builtin/result-isliteral-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_datatype_1 ) {
    /* name: datatype-1
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-datatype-1.rq", "data-r2/expr-builtin/result-datatype-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_datatype_2 ) {
    /* name: datatype-2 : Literals with a datatype
     * updated from original test case: eliminated ordering from test
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-datatype-2.rq", "data-r2/expr-builtin/result-datatype-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_datatype_3 ) {
    /* name: datatype-3 : Literals with a datatype of xsd:string
     * updated from original test case: eliminated ordering from test
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-datatype-3.rq", "data-r2/expr-builtin/result-datatype-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_lang_1 ) {
    /* name: lang-1 : Literals with a lang tag of some kind
     * updated from original test case: eliminated ordering from test
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-lang-1.rq", "data-r2/expr-builtin/result-lang-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_lang_2 ) {
    /* name: lang-2 : Literals with a lang tag of ''
     * updated from original test case: eliminated ordering from test
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-lang-2.rq", "data-r2/expr-builtin/result-lang-2.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_lang_3 ) {
    /* name: lang-3 : Graph matching with lang tag being a different case
     * updated from original test case: eliminated ordering from test
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-2.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-lang-3.rq", "data-r2/expr-builtin/result-lang-3.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_isURI_1 ) {
    /* name: isURI-1
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-uri-1.rq", "data-r2/expr-builtin/result-uri-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_isIRI_1 ) {
    /* name: isIRI-1
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-iri-1.rq", "data-r2/expr-builtin/result-iri-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_langMatches_1 ) {
    /* name: LangMatches-1
     * langMatches(lang(?v), 'en-GB') matches 'abc'@en-gb
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-langMatches-1.rq", "data-r2/expr-builtin/result-langMatches-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_langMatches_2 ) {
    /* name: LangMatches-2
     * langMatches(lang(?v), 'en') matches 'abc'@en, 'abc'@en-gb
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-langMatches-2.rq", "data-r2/expr-builtin/result-langMatches-2.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_langMatches_3 ) {
    /* name: LangMatches-3
     * langMatches(lang(?v), '*') matches 'abc'@en, 'abc'@en-gb, 'abc'@fr
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-langMatches-3.rq", "data-r2/expr-builtin/result-langMatches-3.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_langMatches_4 ) {
    /* name: LangMatches-4
     * ! langMatches(lang(?v), '*') matches 'abc'
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-langMatches.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-langMatches-4.rq", "data-r2/expr-builtin/result-langMatches-4.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__dawg_langMatches_basic ) {
    /* name: LangMatches-basic
     * the basic range 'de-de' does not match 'de-Latn-de'
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-langMatches-de.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/q-langMatches-de-de.rq", "data-r2/expr-builtin/result-langMatches-de.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_case_insensitive_eq ) {
    /* name: lang-case-insensitive-eq
     * 'xyz'@en = 'xyz'@EN
     */
    const char* defaultGraph( "data-r2/expr-builtin/lang-case-sensitivity.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/lang-case-sensitivity-eq.rq", "data-r2/expr-builtin/lang-case-insensitive-eq.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__lang_case_insensitive_ne ) {
    /* name: lang-case-insensitive-ne
     * 'xyz'@en != 'xyz'@EN
     */
    const char* defaultGraph( "data-r2/expr-builtin/lang-case-sensitivity.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/lang-case-sensitivity-ne.rq", "data-r2/expr-builtin/lang-case-insensitive-ne.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__sameTerm_simple ) {
    /* name: sameTerm-simple
     * sameTerm(?v1, ?v2)
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/sameTerm.rq", "data-r2/expr-builtin/result-sameTerm.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__sameTerm_eq ) {
    /* name: sameTerm-eq
     * sameTerm(?v1, ?v2) && ?v1 = ?v2
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/sameTerm-eq.rq", "data-r2/expr-builtin/result-sameTerm-eq.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_builtin__sameTerm_not_eq ) {
    /* name: sameTerm-not-eq
     * !sameTerm(?v1, ?v2) && ?v1 = ?v2
     */
    const char* defaultGraph( "data-r2/expr-builtin/data-builtin-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-builtin/sameTerm-not-eq.rq", "data-r2/expr-builtin/result-sameTerm-not-eq.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* expr_builtin */)

BOOST_AUTO_TEST_SUITE( expr_equals )
BOOST_AUTO_TEST_CASE( expr_equals__eq_1 ) {
    /* name: Equality 1-1
     * = in FILTER expressions is value equality
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-1.rq", "data-r2/expr-equals/result-eq-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_2 ) {
    /* name: Equality 1-2
     * = in FILTER expressions is value equality
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-2.rq", "data-r2/expr-equals/result-eq-2.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_3 ) {
    /* name: Equality 1-3
     * Numerics are not value-equivalent to plain literals
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-3.rq", "data-r2/expr-equals/result-eq-3.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_4 ) {
    /* name: Equality 1-4
     * = compares plain literals and unknown types with the same lexical form as false
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-4.rq", "data-r2/expr-equals/result-eq-4.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_5 ) {
    /* name: Equality 1-5
     * = on IRI terms
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-5.rq", "data-r2/expr-equals/result-eq-5.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_2_1 ) {
    /* name: Equality - 2 var - test equals
     * = in FILTER is value equality
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq2-1.rq", "data-r2/expr-equals/result-eq2-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_2_2 ) {
    /* name: Equality - 2 var - test not equals 
     * != in FILTER is value inequality
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq2-1.rq", "data-r2/expr-equals/result-eq2-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_graph_1 ) {
    /* name: Equality 1-1 -- graph
     * Graph pattern matching matches exact terms, not values
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-graph-1.rq", "data-r2/expr-equals/result-eq-graph-1.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_graph_2 ) {
    /* name: Equality 1-2 -- graph
     * Graph pattern matching matches exact terms, not values
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-graph-2.rq", "data-r2/expr-equals/result-eq-graph-2.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_graph_3 ) {
    /* name: Equality 1-3 -- graph
     * Graph pattern matching matches exact terms, not values
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-graph-3.rq", "data-r2/expr-equals/result-eq-graph-3.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_graph_4 ) {
    /* name: Equality 1-4 -- graph
     * Graph pattern matching matches exact terms, not values
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-graph-4.rq", "data-r2/expr-equals/result-eq-graph-4.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_equals__eq_graph_5 ) {
    /* name: Equality 1-5 -- graph
     * Graph pattern matching matches exact terms, not values
     */
    const char* defaultGraph( "data-r2/expr-equals/data-eq.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-equals/query-eq-graph-5.rq", "data-r2/expr-equals/result-eq-graph-5.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* expr_equals */)

BOOST_AUTO_TEST_SUITE( expr_ops )
BOOST_AUTO_TEST_CASE( expr_ops__ge_1 ) {
    /* name: Greater-than or equals
     * >= in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-ge-1.rq", "data-r2/expr-ops/result-ge-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_ops__le_1 ) {
    /* name: Less-than or equals
     * <= in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-le-1.rq", "data-r2/expr-ops/result-le-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_ops__mul_1 ) {
    /* name: Multiplication
     * A * B in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-mul-1.rq", "data-r2/expr-ops/result-mul-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_ops__plus_1 ) {
    /* name: Addition
     * A + B in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-plus-1.rq", "data-r2/expr-ops/result-plus-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_ops__minus_1 ) {
    /* name: Subtraction
     * A - B in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-minus-1.rq", "data-r2/expr-ops/result-minus-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_ops__unplus_1 ) {
    /* name: Unary Plusn
     * +A in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-unplus-1.rq", "data-r2/expr-ops/result-unplus-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( expr_ops__unminus_1 ) {
    /* name: Unary Minus
     * -A in FILTER expressions
     */
    const char* defaultGraph( "data-r2/expr-ops/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/expr-ops/query-unminus-1.rq", "data-r2/expr-ops/result-unminus-1.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* expr_ops */)

BOOST_AUTO_TEST_SUITE( regex )
BOOST_AUTO_TEST_CASE( regex__dawg_regex_001 ) {
    /* name: regex-query-001
     * Simple unanchored match test
     */
    const char* defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/regex/regex-query-001.rq", "data-r2/regex/regex-result-001.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( regex__dawg_regex_002 ) {
    /* name: regex-query-002
     * Case insensitive unanchored match test
     */
    const char* defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/regex/regex-query-002.rq", "data-r2/regex/regex-result-002.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( regex__dawg_regex_003 ) {
    /* name: regex-query-003
     * Use/mention test
     */
    const char* defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/regex/regex-query-003.rq", "data-r2/regex/regex-result-003.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( regex__dawg_regex_004 ) {
    /* name: regex-query-004
     * str()+URI test
     */
    const char* defaultGraph( "data-r2/regex/regex-data-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/regex/regex-query-004.rq", "data-r2/regex/regex-result-004.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* regex */)

BOOST_AUTO_TEST_SUITE( sort )
BOOST_AUTO_TEST_CASE( sort__dawg_sort_1 ) {
    /* name: sort-1
     * Alphabetic sort (ascending) on untyped literals
     */
    const char* defaultGraph( "data-r2/sort/data-sort-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-1.rq", "data-r2/sort/result-sort-1.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_2 ) {
    /* name: sort-2
     * Alphabetic sort (descending) on untyped literals
     */
    const char* defaultGraph( "data-r2/sort/data-sort-1.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-2.rq", "data-r2/sort/result-sort-2.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_3 ) {
    /* name: sort-3
     * Sort on (possibly unbound) URIs
     */
    const char* defaultGraph( "data-r2/sort/data-sort-3.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-3.rq", "data-r2/sort/result-sort-3.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_4 ) {
    /* name: sort-4
     * Sort on datatyped (integer) literals
     */
    const char* defaultGraph( "data-r2/sort/data-sort-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-4.rq", "data-r2/sort/result-sort-4.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_5 ) {
    /* name: sort-5
     * Sort first on untyped literals (ascending), then on datatyped (integer) literals (descending
     */
    const char* defaultGraph( "data-r2/sort/data-sort-4.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-5.rq", "data-r2/sort/result-sort-5.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_6 ) {
    /* name: sort-6
     * Sort on mixed result of uris and literals.
     */
    const char* defaultGraph( "data-r2/sort/data-sort-6.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-6.rq", "data-r2/sort/result-sort-6.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_7 ) {
    /* name: sort-7
     * Sort on comparable mixed typed literals (integer and float)
     */
    const char* defaultGraph( "data-r2/sort/data-sort-7.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-4.rq", "data-r2/sort/result-sort-7.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_8 ) {
    /* name: sort-8
     * Sort on several mixed values (bnode, uri, literal)
     */
    const char* defaultGraph( "data-r2/sort/data-sort-8.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-4.rq", "data-r2/sort/result-sort-8.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_9 ) {
    /* name: sort-9
     * Alphabetic sort (ascending) on datatyped (string) literals
     */
    const char* defaultGraph( "data-r2/sort/data-sort-9.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-9.rq", "data-r2/sort/result-sort-9.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_10 ) {
    /* name: sort-10
     * Alphabetic sort (descending) on datatyped (string) literals
     */
    const char* defaultGraph( "data-r2/sort/data-sort-9.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-10.rq", "data-r2/sort/result-sort-10.rdf", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_numbers ) {
    /* name: Expression sort
     * Sort by a bracketted expression
     */
    const char* defaultGraph( "data-r2/sort/data-sort-numbers.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-numbers.rq", "data-r2/sort/result-sort-numbers.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_builtin ) {
    /* name: Builtin sort
     * Sort by a builtin operator
     */
    const char* defaultGraph( "data-r2/sort/data-sort-builtin.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-builtin.rq", "data-r2/sort/result-sort-builtin.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( sort__dawg_sort_function ) {
    /* name: Function sort
     * Sort by function invocation
     */
    const char* defaultGraph( "data-r2/sort/data-sort-function.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/sort/query-sort-function.rq", "data-r2/sort/result-sort-function.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* sort */)

BOOST_AUTO_TEST_SUITE( type_promotion )
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_01 ) {
    /* name: tP-double-double
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-double-double.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_02 ) {
    /* name: tP-double-float
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-double-float.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_03 ) {
    /* name: tP-double-decimal
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-double-decimal.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_04 ) {
    /* name: tP-float-float
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-float-float.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_05 ) {
    /* name: tP-float-decimal
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-float-decimal.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_06 ) {
    /* name: tP-decimal-decimal
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-decimal-decimal.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_07 ) {
    /* name: tP-integer-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-integer-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_08 ) {
    /* name: tP-nonPositiveInteger-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-nonPositiveInteger-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_09 ) {
    /* name: tP-negativeInteger-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-negativeInteger-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_10 ) {
    /* name: tP-long-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-long-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_11 ) {
    /* name: tP-int-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-int-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_12 ) {
    /* name: tP-short-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_13 ) {
    /* name: tP-byte-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-byte-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_14 ) {
    /* name: tP-nonNegativeInteger-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-nonNegativeInteger-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_15 ) {
    /* name: tP-unsignedLong-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-unsignedLong-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_16 ) {
    /* name: tP-unsignedInt-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-unsignedInt-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_17 ) {
    /* name: tP-unsignedShort-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-unsignedShort-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_18 ) {
    /* name: tP-unsignedByte-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-unsignedByte-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_19 ) {
    /* name: tP-positiveInteger-short
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-positiveInteger-short.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_20 ) {
    /* name: tP-short-double
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-double.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_21 ) {
    /* name: tP-short-float
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-float.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_22 ) {
    /* name: tP-short-decimal
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-decimal.rq", "data-r2/type-promotion/true.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_23 ) {
    /* name: tP-short-short-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-short-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_24 ) {
    /* name: tP-byte-short-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-byte-short-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_25 ) {
    /* name: tP-short-long-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-long-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_26 ) {
    /* name: tP-short-int-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-int-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_27 ) {
    /* name: tP-short-byte-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-short-byte-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_28 ) {
    /* name: tP-double-float-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-double-float-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_29 ) {
    /* name: tP-double-decimal-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-double-decimal-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_CASE( type_promotion__type_promotion_30 ) {
    /* name: tP-float-decimal-fail
     * Positive test: product of type promotion within the xsd:decimal type tree.
     */
    const char* defaultGraph( "data-r2/type-promotion/tP.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/type-promotion/tP-float-decimal-fail.rq", "data-r2/type-promotion/false.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* type_promotion */)

BOOST_AUTO_TEST_SUITE( bnode_coreference )
BOOST_AUTO_TEST_CASE( bnode_coreference__dawg_bnode_coref_001 ) {
    /* name: dawg-bnode-coreference
     * Query results must maintain bnode co-references in the dataset
     */
    const char* defaultGraph( "data-r2/bnode-coreference/data.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/bnode-coreference/query.rq", "data-r2/bnode-coreference/result.ttl", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* bnode_coreference */)

BOOST_AUTO_TEST_SUITE( distinct )
BOOST_AUTO_TEST_CASE( distinct__no_distinct_1 ) {
    /* name: Numbers: No distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-num.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-num.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__distinct_1 ) {
    /* name: Numbers: Distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-num.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-num.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__no_distinct_2 ) {
    /* name: Strings: No distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-str.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-str.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__distinct_2 ) {
    /* name: Strings: Distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-str.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-str.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__no_distinct_3 ) {
    /* name: Nodes: No distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-node.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-node.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__distinct_3 ) {
    /* name: Nodes: Distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-node.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-node.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__no_distinct_4 ) {
    /* name: Opt: No distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-opt.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/no-distinct-2.rq", "data-r2/distinct/no-distinct-opt.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__distinct_4 ) {
    /* name: Opt: Distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-opt.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/distinct-2.rq", "data-r2/distinct/distinct-opt.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__no_distinct_9 ) {
    /* name: All: No distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-all.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/no-distinct-1.rq", "data-r2/distinct/no-distinct-all.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__distinct_9 ) {
    /* name: All: Distinct
     */
    const char* defaultGraph( "data-r2/distinct/data-all.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/distinct-1.rq", "data-r2/distinct/distinct-all.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( distinct__distinct_star_1 ) {
    /* name: SELECT DISTINCT *
     */
    const char* defaultGraph( "data-r2/distinct/data-star.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/distinct/distinct-star-1.rq", "data-r2/distinct/distinct-star-1.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* distinct */)

BOOST_AUTO_TEST_SUITE( reduced )
BOOST_AUTO_TEST_CASE( reduced__reduced_1 ) {
    /* name: SELECT REDUCED *
     */
    const char* defaultGraph( "data-r2/reduced/reduced-star.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/reduced/reduced-1.rq", "data-r2/reduced/reduced-1.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( reduced__reduced_2 ) {
    /* name: SELECT REDUCED ?x with strings
     */
    const char* defaultGraph( "data-r2/reduced/reduced-str.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("data-r2/reduced/reduced-2.rq", "data-r2/reduced/reduced-2.srx", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* reduced */)

BOOST_AUTO_TEST_CASE( test_fail ) {
    BOOST_CHECK_EQUAL(1, 0);
}
// EOF

