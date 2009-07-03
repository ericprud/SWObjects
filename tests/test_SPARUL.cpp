/* perform SPARUL tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE SPARUL_tests
#include "../tests/SparqlQueryTestResultSet.hpp"

/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 */
#define SPARUL_TEST(QUERY_FILE, RESULT_FILE, NGS, REQS)			       \
    try {								       \
    SparqlQueryTestResultSet measured(defaultGraph, namedGraphs, NGS, requires, REQS, QUERY_FILE); \
    std::string rfs(RESULT_FILE);				    	       \
    if (rfs.substr(rfs.size()-4, 4) == ".srx") { 		    	       \
	ResultSet expected(&F, &P, RESULT_FILE);		    	       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    } else {								       \
	RdfDB rdfDB;							       \
	if (rfs.substr(rfs.size()-4, 4) == ".ttl") {			       \
	    turtleParser.setGraph(rdfDB.assureGraph(NULL));		       \
	    turtleParser.parse_file(RESULT_FILE);			       \
	    turtleParser.clear("");					       \
	} else if (rfs.substr(rfs.size()-4, 4) == ".rdf") {		       \
	    GRdfXmlParser.parse(rdfDB.assureGraph(NULL), RESULT_FILE);	       \
	} else {							       \
	    throw std::string("unable to parse results file ") + RESULT_FILE;  \
	}								       \
	if (measured.getGraph() == NULL)				       \
	    BOOST_CHECK_EQUAL(measured, ResultSet(&F, &rdfDB, "")); 	       \
	else								       \
	    BOOST_CHECK_EQUAL(measured, ResultSet(&F, rdfDB.assureGraph(NULL)));\
    }									       \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    }

void SPARUL_TEST1(const char* defaultGraph, const char* namedGraphs[], const URI** requires, const char* QUERY_FILE, const char* RESULT_FILE, int NGS, int REQS)			       {
    try {								       
    SparqlQueryTestResultSet measured(defaultGraph, namedGraphs, NGS, requires, REQS, QUERY_FILE); 
    std::string rfs(RESULT_FILE);				    	       
    if (rfs.substr(rfs.size()-4, 4) == ".srx") { 		    	       
	ResultSet expected(&F, &P, RESULT_FILE);		    	       
	BOOST_CHECK_EQUAL(measured, expected);				       
    } else {								       
	RdfDB rdfDB;							       
	if (rfs.substr(rfs.size()-4, 4) == ".ttl") {			       
	    turtleParser.setGraph(rdfDB.assureGraph(NULL));		       
	    turtleParser.parse_file(RESULT_FILE);			       
	    turtleParser.clear("");					       
	} else if (rfs.substr(rfs.size()-4, 4) == ".trg") {			       
	    trigParser.setDB(&rdfDB);		       
	    trigParser.parse_file(RESULT_FILE);			       
	    trigParser.clear("");					       
	} else if (rfs.substr(rfs.size()-4, 4) == ".rdf") {		       
	    GRdfXmlParser.parse(rdfDB.assureGraph(NULL), RESULT_FILE);	       
	} else {							       
	    throw std::string("unable to parse results file ") + RESULT_FILE;  
	}								       
	if (measured.getRdfDB() == NULL)				       
	    BOOST_CHECK_EQUAL(measured, ResultSet(&F, &rdfDB, "")); 	       
	else								       
	    BOOST_CHECK_EQUAL(measured, ResultSet(&F, &rdfDB));
    }									       
    } catch (std::string& s) {						       
	BOOST_ERROR ( s );						       
    }
}


BOOST_AUTO_TEST_SUITE( insert )
BOOST_AUTO_TEST_CASE( insert0 ) {
    /* name: dawg-triple-pattern-001
     * Simple triple match
     */
    const char* defaultGraph( NULL );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    //SPARUL_TEST("sparul/insert0.rq", "sparul/insert0.ttl", 0, 0);
    SPARUL_TEST1(defaultGraph, namedGraphs, requires, "sparul/insert0.rq", "sparul/insert0.trg", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* insert */)


BOOST_AUTO_TEST_CASE( test_fail ) {
    BOOST_CHECK_EQUAL(1, 0);
}
BOOST_AUTO_TEST_CASE( test_succeed ) {
    BOOST_CHECK_EQUAL(1, 1);
}
// EOF

