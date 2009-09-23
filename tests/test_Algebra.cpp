/* test_Algebra.hpp -- 
 *
 * Test a SPARQL Parser and algebra serializer against references like
 *   http://www.sparql.org/validator.html
 *
 * $Id: test_Algebra.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */


#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE Algebra
#include <boost/test/unit_test.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SPARQLAlgebraSerializer.hpp"

using namespace w3c_sw;

POSFactory F;
SPARQLfedDriver sparqlParser("", &F);

std::string algebrize (std::string sparql) {
    /* Parse query. */
    if (sparqlParser.parse_string(sparql))
	throw std::string("failed to parse SPARQL \"") + sparql + "\".";
    sparqlParser.clear(""); // clear out namespaces and base URI.

    SPARQLAlgebraSerializer s;
    sparqlParser.root->express(&s);
    delete sparqlParser.root;
    return s.getString();
}


/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 */

#define ALGEBRA_TEST(SPARQL, ALGEBRA)					       \
    try {								       \
	std::string measured(algebrize(SPARQL));			       \
	std::string expected(ALGEBRA);					       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_CASE( algebra__filter_nested_2 ) {
    /* copy of DAWG test algebra/filter_nested_2
     */
    ALGEBRA_TEST("ASK { <x> <p> ?v . { FILTER(?v = 1) } }", "(ask\n\
  (join\n\
    (bgp (triple <x> <p> ?v))\n\
    (filter (= ?v 1)\n\
      (table unit)\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001 ) {
    /* shape of DAWG test triple_match/dawg_triple_pattern_001
     */
    ALGEBRA_TEST("ASK { <x> ?p ?q . }", "(ask\n\
  (bgp (triple <x> ?p ?q))\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( algebra__filter_place_3 ) {
    /* shape of DAWG test algebra/filter_place_3.
     */
    ALGEBRA_TEST("ASK\n\
{ \n\
    FILTER (?v = 2)\n\
    FILTER (?w = 3)\n\
    ?s <p> ?v . \n\
    ?s <q> ?w .\n\
}\n\
", "(ask\n\
  (filter (exprlist (= ?v 2) (= ?w 3))\n\
    (bgp\n\
      (triple ?s <p> ?v)\n\
      (triple ?s <q> ?w)\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( algebra__opt_filter_1 ) {
    /* shape of DAWG test algebra/opt_filter_1.
     */
    ALGEBRA_TEST("ASK { \n\
  ?x <p> ?v .\n\
  OPTIONAL\n\
  { \n\
    FILTER(?v=1)\n\
    ?y <q> ?w .\n\
    FILTER(?v=2)\n\
  }\n\
}", "(ask\n\
  (leftjoin\n\
    (bgp (triple ?x <p> ?v))\n\
    (bgp (triple ?y <q> ?w))\n\
    (exprlist (= ?v 1) (= ?v 2))))\n\
");
}

BOOST_AUTO_TEST_CASE( triple_filter ) {
    /* Simple FILTER after a triple.
     */
    ALGEBRA_TEST("ASK {\n\
  ?s <p> 1 .\n\
  FILTER (1)\n\
  }", "(ask\n\
  (filter 1\n\
    (bgp (triple ?s <p> 1))\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( filter_triple ) {
    /* Simple FILTER before a triple.
     */
    ALGEBRA_TEST("ASK {\n\
  FILTER (1)\n\
  ?s <p> 1 .\n\
  }", "(ask\n\
  (filter 1\n\
    (bgp (triple ?s <p> 1))\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_before_nth ) {
    /* Simple FILTER before a later BGP.
     */
    ALGEBRA_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  FILTER (1)\n\
  ?s <p> 2 .\n\
}", "(ask\n\
  (filter 1\n\
    (join\n\
      (bgp (triple ?s <p> 1))\n\
      (bgp (triple ?s <p> 2))\n\
    )\n\
  )\n\
)\n\
");
}
BOOST_AUTO_TEST_CASE( bgp_after_nth ) {
    /* Simple FILTER after a later BGP.
     */
    ALGEBRA_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  ?s <p> 2 .\n\
  FILTER (1)\n\
}", "(ask\n\
  (filter 1\n\
    (join\n\
      (bgp (triple ?s <p> 1))\n\
      (bgp (triple ?s <p> 2))\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_in_nth ) {
    /* Simple FILTER in a later BGP.
     */
    ALGEBRA_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  ?s <p> 2 .\n\
  FILTER (1)\n\
  ?s <p> 3 .\n\
}", "(ask\n\
  (filter 1\n\
    (join\n\
      (bgp (triple ?s <p> 1))\n\
      (bgp\n\
        (triple ?s <p> 2)\n\
        (triple ?s <p> 3)\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_trailing_conjunction ) {
    /* Simple FILTER trailing a conjunction.
     */
    ALGEBRA_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  {\n\
    ?s <p> 2 .\n\
  }\n\
  FILTER (1)\n\
  }", "(ask\n\
  (filter 1\n\
    (join\n\
      (bgp (triple ?s <p> 1))\n\
      (bgp (triple ?s <p> 2))\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_opt_combo ) {
    /* A FILTER inside an OPTIONAL can reference a variable bound in the required part of the OPTIONAL
     */
    ALGEBRA_TEST("ASK {\
  OPTIONAL {?s?p 0}\
  FILTER (1)\
  ?s?p 1\
  FILTER (2)\
  ?s?p 2\
}", "(ask\n\
  (filter (exprlist 1 2)\n\
    (join\n\
      (leftjoin\n\
        (table unit)\n\
        (bgp (triple ?s ?p 0)))\n\
      (bgp\n\
        (triple ?s ?p 1)\n\
        (triple ?s ?p 2)\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_with_triples ) {
    /* Simple FILTER intermingled with triples.
     */
    ALGEBRA_TEST("ASK {\n\
  ?s <p> 1 .\n\
  FILTER (1)\n\
  ?s <p> 2 .\n\
  FILTER (2)\n\
  }", "(ask\n\
  (filter (exprlist 1 2)\n\
    (bgp\n\
      (triple ?s <p> 1)\n\
      (triple ?s <p> 2)\n\
    )\n\
  )\n\
)\n\
");
}

