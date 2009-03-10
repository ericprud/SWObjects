/* perform DAWG tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE ListOp_tests
#include "../tests/SparqlQueryTestResultSet.hpp"

BOOST_AUTO_TEST_SUITE( lists )
typedef std::stringstream STREAM;
#if REGEX_LIB == SWOb_DISABLED
  #warning ListOp tests require REGEX
#else /* ! REGEX_LIB == SWOb_DISABLED */

BOOST_AUTO_TEST_CASE( Members_SO ) {
    STREAM defaultGraph( "(<a> <b>) <p> (<x> <y> <z>) ." );
    STREAM query( "SELECT * {members(?s) <p> members(?o)}" );
    SparqlQueryTestResultSet measured(defaultGraph, NULL, 0, query);
    BOOST_CHECK_EQUAL(measured, ResultSet(&F, 
					  "?s  ?o \n"
					  "<a> <x>\n"
					  "<a> <y>\n"
					  "<a> <z>\n"
					  "<b> <x>\n"
					  "<b> <y>\n"
					  "<b> <z>",
					  false));
}
BOOST_AUTO_TEST_CASE( Members_sO ) {
    STREAM defaultGraph( "<a> <p> (<x> <y> <z>) ." );
    STREAM query( "SELECT * {members(?s) <p> members(?o)}" );
    SparqlQueryTestResultSet measured(defaultGraph, NULL, 0, query);
    BOOST_CHECK_EQUAL(measured, ResultSet(&F, 
					  "?s  ?o ",
					  false));
}
BOOST_AUTO_TEST_CASE( Members_SS ) {
    STREAM defaultGraph( "@PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .\n"
			 "_:head rdf:first 1 ; rdf:rest _:elt1 .\n"
			 "_:elt1 rdf:first 2 ; rdf:rest rdf:nil .\n"
			 "_:head <p1> (1 2) .\n"
			 "_:head <p2> _:head ." );
    STREAM query( "SELECT * {members(?s) ?p members(?s)}" );
    SparqlQueryTestResultSet measured(defaultGraph, NULL, 0, query);
    BOOST_CHECK_EQUAL(measured, ResultSet(&F, 
					  "?s  ?p   ?o \n"
					  "1   <p2> 1\n"
					  "1   <p2> 2\n"
					  "2   <p2> 1\n"
					  "2   <p2> 2",
					  false));
}

#endif /* ! REGEX_LIB == SWOb_DISABLED */

BOOST_AUTO_TEST_SUITE_END()

// EOF

