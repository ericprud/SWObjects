/* test_Algebra.hpp -- 
 *
 * Test a SPARQL Parser and algebra serializer against references like
 *   http://www.sparql.org/validator.html
 *
 * $Id: test_Algebra.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE Algebra

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SPARQLAlgebraSerializer.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>

using namespace w3c_sw;

AtomFactory F;
SPARQLfedDriver sparqlParser("", &F);

std::string algebrize (std::string sparql, SPARQLAlgebraSerializer::e_ALGEBRA algebra) {
    /* Parse query. */
    IStreamContext istr(sparql, IStreamContext::STRING);
    Operation* op = sparqlParser.parse(istr);
    sparqlParser.clear(""); // clear out namespaces and base URI.

    SPARQLAlgebraSerializer s(algebra);
    op->express(&s);
    delete op;
    return s.str();
}


/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 */

#define ALGEBRA_TEST(SPARQL, ALGEBRA, REFERENCE)			       \
    try {								       \
	std::string measured(algebrize(SPARQL, ALGEBRA));		       \
	std::string expected(REFERENCE);				       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_CASE( algebra__filter_nested_2 ) {
    /* copy of DAWG test algebra/filter_nested_2
     */
    ALGEBRA_TEST("ASK { <x> <p> ?v . { FILTER(?v = 1) } }", 
		 SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
    ALGEBRA_TEST("ASK { <x> ?p ?q . }", 
		 SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter (exprlist (= ?v 2) (= ?w 3))\n\
    (bgp\n\
      (triple ?s <p> ?v)\n\
      (triple ?s <q> ?w)\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( opt_filter_filter_arq ) {
    /* OPTIONAL with two FILTERs.
     */
    ALGEBRA_TEST("ASK {\n\
  OPTIONAL {\n\
    FILTER(0) FILTER(1)\n\
  }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_arq, "(ask\n\
  (leftjoin\n\
    (table unit)\n\
    (table unit)\n\
    (exprlist 0 1)\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( opt_filter_filter_terse ) {
    /* OPTIONAL with two FILTERs.
     */
    ALGEBRA_TEST("ASK {\n\
  OPTIONAL {\n\
    FILTER(0) FILTER(1)\n\
  }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (optional\n\
    (table unit)\n\
    (exprlist 0 1)\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( opt_filter_unit_filter_arq ) {
    /* OPTIONAL with FILTER, unit, FILTER.
     */
    ALGEBRA_TEST("ASK {\n\
  OPTIONAL {\n\
    FILTER(0) { } FILTER(1)\n\
  }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_arq, "(ask\n\
  (leftjoin\n\
    (table unit)\n\
    (filter 0\n\
      (table unit)\n\
    )\n\
    1\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( opt_filter_unit_filter_terse ) {
    /* OPTIONAL with FILTER, unit, FILTER.
     */
    ALGEBRA_TEST("ASK {\n\
  OPTIONAL {\n\
    FILTER(0) { } FILTER(1)\n\
  }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (optional\n\
    (filter 0\n\
      (table unit)\n\
    )\n\
    1\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( opt_filter_union_filter_terse ) {
    /* OPTIONAL with FILTER, UNION, FILTER.
     */
    ALGEBRA_TEST("ASK {\n\
  OPTIONAL {\n\
    FILTER(0) { } UNION { } FILTER(1)\n\
  }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (optional\n\
    (join\n\
      (filter 0\n\
        (table unit)\n\
      )\n\
      (union\n\
        (table unit)\n\
        (table unit)\n\
      )\n\
    )\n\
    1\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( opt_filter_union_filter_arq ) {
    /* OPTIONAL with FILTER, UNION, FILTER.
     */
    ALGEBRA_TEST("ASK {\n\
  OPTIONAL {\n\
    FILTER(0) { } UNION { } FILTER(1)\n\
  }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_arq, "(ask\n\
  (leftjoin\n\
    (table unit)\n\
    (join\n\
      (filter 0\n\
        (table unit)\n\
      )\n\
      (union\n\
        (table unit)\n\
        (table unit)\n\
      )\n\
    )\n\
    1\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( algebra__opt_filter_1_terse ) {
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
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (join\n\
    (bgp (triple ?x <p> ?v))\n\
    (optional\n\
      (bgp (triple ?y <q> ?w))\n\
      (exprlist (= ?v 1) (= ?v 2))\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( algebra__opt_filter_1_arq ) {
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
}", SPARQLAlgebraSerializer::ALGEBRA_arq, "(ask\n\
  (leftjoin\n\
    (bgp (triple ?x <p> ?v))\n\
    (bgp (triple ?y <q> ?w))\n\
    (exprlist (= ?v 1) (= ?v 2))\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( triple_filter ) {
    /* Simple FILTER after a triple.
     */
    ALGEBRA_TEST("ASK {\n\
  ?s <p> 1 .\n\
  FILTER (1)\n\
  }", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
  }", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
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
  }", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter 1\n\
    (join\n\
      (bgp (triple ?s <p> 1))\n\
      (bgp (triple ?s <p> 2))\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_opt_combo_terse ) {
    /* A FILTER inside an OPTIONAL can reference a variable bound in the required part of the OPTIONAL
     */
    ALGEBRA_TEST("ASK {\
  OPTIONAL {?s?p 0}\
  FILTER (1)\
  ?s?p 1\
  FILTER (2)\
  ?s?p 2\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter (exprlist 1 2)\n\
    (join\n\
      (optional\n\
        (bgp (triple ?s ?p 0))\n\
      )\n\
      (bgp\n\
        (triple ?s ?p 1)\n\
        (triple ?s ?p 2)\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( bgp_opt_combo_arq ) {
    /* A FILTER inside an OPTIONAL can reference a variable bound in the required part of the OPTIONAL
     */
    ALGEBRA_TEST("ASK {\
  OPTIONAL {?s?p 0}\
  FILTER (1)\
  ?s?p 1\
  FILTER (2)\
  ?s?p 2\
}", SPARQLAlgebraSerializer::ALGEBRA_arq, "(ask\n\
  (filter (exprlist 1 2)\n\
    (join\n\
      (leftjoin\n\
        (table unit)\n\
        (bgp (triple ?s ?p 0))\n\
      )\n\
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
  }", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter (exprlist 1 2)\n\
    (bgp\n\
      (triple ?s <p> 1)\n\
      (triple ?s <p> 2)\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( union_with_filters ) {
    /* Filters in both sides of a UNION.
     */
    ALGEBRA_TEST("ASK {\n\
  { ?s ?p ?o FILTER(1) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(2) }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n \
 (union\n\
    (filter 1\n\
      (bgp (triple ?s ?p ?o))\n\
    )\n\
    (filter 2\n\
      (bgp (triple ?s ?p ?o))\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( union_with_leading_filter ) {
    /* Filters in three sides and begin and end of a UNION.
     */
    ALGEBRA_TEST("ASK {\n\
  FILTER(0)\n\
  { ?s ?p ?o }\n\
 UNION\n\
  { ?s ?p ?o }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (join\n\
    (filter 0\n\
      (table unit)\n\
    )\n\
    (union\n\
      (bgp (triple ?s ?p ?o))\n\
      (bgp (triple ?s ?p ?o))\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( union_with_trailing_filter ) {
    /* Filters in both sides and end of a UNION.
     */
    ALGEBRA_TEST("ASK {\n\
  { ?s ?p ?o FILTER(1) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(2) }\n\
  FILTER(3)\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter 3\n\
    (union\n\
      (filter 1\n\
        (bgp (triple ?s ?p ?o))\n\
      )\n\
      (filter 2\n\
        (bgp (triple ?s ?p ?o))\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( triple_union_with_trailing_filter ) {
    /* Filters in three sides and end of a UNION.
     */
    ALGEBRA_TEST("ASK {\n\
  { ?s ?p ?o FILTER(1) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(2) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(3) }\n\
  FILTER(4)\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter 4\n\
    (union\n\
      (union\n\
        (filter 1\n\
          (bgp (triple ?s ?p ?o))\n\
        )\n\
        (filter 2\n\
          (bgp (triple ?s ?p ?o))\n\
        )\n\
      )\n\
      (filter 3\n\
        (bgp (triple ?s ?p ?o))\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( filtered_union_with_leading_filter ) {
    /* Filters in three sides and begin and end of a UNION.
     */
    ALGEBRA_TEST("ASK {\n\
  FILTER(0)\n\
  { ?s ?p ?o FILTER(1) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(2) }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (join\n\
    (filter 0\n\
      (table unit)\n\
    )\n\
    (union\n\
      (filter 1\n\
        (bgp (triple ?s ?p ?o))\n\
      )\n\
      (filter 2\n\
        (bgp (triple ?s ?p ?o))\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( triple_union_with_leading_and_trailing_filter ) {
    /* Filters in three sides and begin and end of a UNION.
     */
    ALGEBRA_TEST("ASK {\n\
  FILTER(0)\n\
  { ?s ?p ?o FILTER(1) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(2) }\n\
 UNION\n\
  { ?s ?p ?o FILTER(3) }\n\
  FILTER(4)\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (filter 4\n\
    (join\n\
      (filter 0\n\
        (table unit)\n\
      )\n\
      (union\n\
        (union\n\
          (filter 1\n\
            (bgp (triple ?s ?p ?o))\n\
          )\n\
          (filter 2\n\
            (bgp (triple ?s ?p ?o))\n\
          )\n\
        )\n\
        (filter 3\n\
          (bgp (triple ?s ?p ?o))\n\
        )\n\
      )\n\
    )\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( optional__q_opt_complex_1_terse ) {
    /* copy of DAWG test optional/q-opt-complex-1
     */
    ALGEBRA_TEST("PREFIX  foaf:   <http://xmlns.com/foaf/0.1/>\n\
ASK { \n\
    OPTIONAL { \n\
        # { ?person foaf:depiction ?img } UNION \n\
        { ?person foaf:firstName ?firstN } \n\
    }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_simple, "(ask\n\
  (optional\n\
    (bgp (triple ?person <http://xmlns.com/foaf/0.1/firstName> ?firstN))\n\
  )\n\
)\n\
"); // "
}

BOOST_AUTO_TEST_CASE( optional__q_opt_complex_1_arq ) {
    /* copy of DAWG test optional/q-opt-complex-1
     */
    ALGEBRA_TEST("PREFIX  foaf:   <http://xmlns.com/foaf/0.1/>\n\
ASK { \n\
    OPTIONAL { \n\
        # { ?person foaf:depiction ?img } UNION \n\
        { ?person foaf:firstName ?firstN } \n\
    }\n\
}", SPARQLAlgebraSerializer::ALGEBRA_arq, "(ask\n\
  (leftjoin\n\
    (table unit)\n\
    (bgp (triple ?person <http://xmlns.com/foaf/0.1/firstName> ?firstN))\n\
  )\n\
)\n\
");
}

BOOST_AUTO_TEST_CASE( getBNode ) {

    /** make sure that getBNode gives unique bnodes when called with new
     * different String2BNode maps.
     */
    TTerm::String2BNode m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    BOOST_CHECK_EQUAL(F.getBNode("X", m1)->getLexicalValue(), "X");
    BOOST_CHECK_EQUAL(F.getBNode("X", m4)->getLexicalValue(), "X_1");
    BOOST_CHECK_EQUAL(F.getBNode("X", m5)->getLexicalValue(), "X_2");
    BOOST_CHECK_EQUAL(F.getBNode("X_3", m2)->getLexicalValue(), "X_3");
    BOOST_CHECK_EQUAL(F.getBNode("X_3_1", m3)->getLexicalValue(), "X_3_1");
    BOOST_CHECK_EQUAL(F.getBNode("X", m6)->getLexicalValue(), "X_3_1_1");
    BOOST_CHECK_EQUAL(F.getBNode("X", m7)->getLexicalValue(), "X_3_1_2");
    BOOST_CHECK_EQUAL(F.getBNode("X_3_1", m8)->getLexicalValue(), "X_3_1_1_1");
    BOOST_CHECK_EQUAL(F.getBNode("X_3", m9)->getLexicalValue(), "X_3_1_2_1");
    BOOST_CHECK_EQUAL(F.getBNode("X_3_1_2_1", m10)->getLexicalValue(), "X_3_1_2_1_1");
}

