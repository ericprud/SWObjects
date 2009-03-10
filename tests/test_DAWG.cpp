/* perform DAWG tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE DAWG_tests
#include "../tests/SparqlQueryTestResultSet.hpp"

/* Macros for terse test syntax: */
#define DEFGRAPH_FILE_TEST(QUERY_FILE, RESULT_FILE) \
    std::ifstream query(QUERY_FILE); \
    if (!query.is_open()) throw std::string("failed to open query file ") + QUERY_FILE; \
    SparqlQueryTestResultSet measured(defaultGraph, NULL, 0, query);	\
    ResultSet expected(&F, &P, RESULT_FILE); \
    BOOST_CHECK_EQUAL(measured, expected);
#define S Sentinel

BOOST_AUTO_TEST_SUITE( basic )
BOOST_AUTO_TEST_CASE( nada ) {
    BOOST_CHECK_EQUAL(1, 1);
}
BOOST_AUTO_TEST_CASE( Basic_graph_pattern___spoo ) {
    std::ifstream defaultGraph( "data-r2/basic/data-6.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/spoo-1.rq", "data-r2/basic/spoo-1.srx");
}
#if 0
BOOST_AUTO_TEST_CASE( Basic___List_1 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-1.rq", "data-r2/basic/list-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_2 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-2.rq", "data-r2/basic/list-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_3 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-3.rq", "data-r2/basic/list-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_4 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-2.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/list-4.rq", "data-r2/basic/list-4.srx");
}
#endif
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_1 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-1.rq", "data-r2/basic/base-prefix-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_2 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-2.rq", "data-r2/basic/base-prefix-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_3 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-3.rq", "data-r2/basic/base-prefix-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_4 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-4.rq", "data-r2/basic/base-prefix-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_5 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-1.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-5.rq", "data-r2/basic/base-prefix-5.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_1 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-1.rq", "data-r2/basic/quotes-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_2 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-2.rq", "data-r2/basic/quotes-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_3 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-3.rq", "data-r2/basic/quotes-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_4 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-3.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-4.rq", "data-r2/basic/quotes-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_1 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-1.rq", "data-r2/basic/term-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_2 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-2.rq", "data-r2/basic/term-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_3 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-3.rq", "data-r2/basic/term-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_4 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-4.rq", "data-r2/basic/term-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_5 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-5.rq", "data-r2/basic/term-5.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_6 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-6.rq", "data-r2/basic/term-6.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_7 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-7.rq", "data-r2/basic/term-7.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_8 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-8.rq", "data-r2/basic/term-8.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_9 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-4.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/term-9.rq", "data-r2/basic/term-9.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Var_1 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-5.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/var-1.rq", "data-r2/basic/var-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Var_2 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-5.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/var-2.rq", "data-r2/basic/var-2.srx");
}
BOOST_AUTO_TEST_CASE( Non_matching_triple_pattern ) {
    std::ifstream defaultGraph( "data-r2/basic/data-7.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/bgp-no-match.rq", "data-r2/basic/bgp-no-match.srx");
}
BOOST_AUTO_TEST_CASE( Prefix_name_1 ) {
    std::ifstream defaultGraph( "data-r2/basic/data-6.ttl" );
    DEFGRAPH_FILE_TEST("data-r2/basic/prefix-name-1.rq", "data-r2/basic/prefix-name-1.srx");
}
BOOST_AUTO_TEST_SUITE_END()

// EOF

