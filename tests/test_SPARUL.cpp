/* perform SPARUL tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE SPARUL_tests
#include "../tests/SPARQLTest.hpp"

BOOST_AUTO_TEST_SUITE( insert )
BOOST_AUTO_TEST_CASE( g_0_insert_1 ) {
    GRAPH_TEST(NULL, "sparul/insert_1.rq", "sparul/1.trig");
}
BOOST_AUTO_TEST_CASE( g_0_insert_g_1 ) {
    GRAPH_TEST(NULL, "sparul/insert_g_1.rq", "sparul/g_1.trig");
}
BOOST_AUTO_TEST_CASE( g_0_insert_g_12 ) {
    GRAPH_TEST(NULL, "sparul/insert_g_12.rq", "sparul/g_12.trig");
}
BOOST_AUTO_TEST_CASE( g_1_insert_g_12 ) {
    GRAPH_TEST("sparul/g_1.trig", "sparul/insert_g_12.rq", "sparul/g_12.trig");
}
BOOST_AUTO_TEST_CASE( g_1_insert_g_2_where_g_1 ) {
    GRAPH_TEST("sparul/g_1.trig", "sparul/insert_g_2_where_g_1.rq", "sparul/g_12.trig");
}
BOOST_AUTO_TEST_CASE( g_1_insert_v_2_where_v_1 ) {
    GRAPH_TEST("sparul/g_1.trig", "sparul/insert_v_2_where_v_1.rq", "sparul/g_12.trig");
}
BOOST_AUTO_TEST_CASE( g_12_insert_h_vpo_where_v_spo ) {
    GRAPH_TEST("sparul/g_12.trig", "sparul/insert_h_vpo_where_v_spo.rq", "sparul/g_12_h_12.trig");
}
BOOST_AUTO_TEST_SUITE_END(/* insert */)


BOOST_AUTO_TEST_SUITE( _delete )
BOOST_AUTO_TEST_CASE( g_0_delete_g_1 ) {
    GRAPH_TEST(NULL, "sparul/delete_g_1.rq", NULL);
}
BOOST_AUTO_TEST_CASE( g_1_delete_g_1 ) {
    GRAPH_TEST("sparul/g_1.trig", "sparul/delete_g_1.rq", NULL);
}
BOOST_AUTO_TEST_CASE( g_1_delete_g_12 ) {
    GRAPH_TEST("sparul/g_1.trig", "sparul/delete_g_12.rq", NULL);
}
BOOST_AUTO_TEST_CASE( g_12_delete_g_1 ) {
    GRAPH_TEST("sparul/g_12.trig", "sparul/delete_g_1.rq", "sparul/g_2.trig");
}
BOOST_AUTO_TEST_CASE( g_12_delete_g_12 ) {
    GRAPH_TEST("sparul/g_12.trig", "sparul/delete_g_12.rq", NULL);
}
BOOST_AUTO_TEST_CASE( g_1_delete_g_2_where_g_1 ) {
    GRAPH_TEST("sparul/g_12.trig", "sparul/delete_g_2_where_g_1.rq", "sparul/g_1.trig");
}
BOOST_AUTO_TEST_CASE( g_1_delete_v_2_where_v_1 ) {
    GRAPH_TEST("sparul/g_12.trig", "sparul/delete_v_2_where_v_1.rq", "sparul/g_1.trig");
}
BOOST_AUTO_TEST_CASE( g_12_h_12_delete_h_vpo_where_v_spo ) {
    GRAPH_TEST("sparul/g_12_h_12.trig", "sparul/delete_h_vpo_where_v_spo.rq", "sparul/g_12.trig");
}
BOOST_AUTO_TEST_SUITE_END(/* _delete */)


// EOF

