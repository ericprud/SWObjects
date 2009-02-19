/* test query-mapping.
 *
 * $Id: test_QueryMap.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE QueryMap
#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

#include <map>
#include <vector>
#include "SWObjects.hpp"
#include "SPARQLfedParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "QueryMapper.hpp"
#include "SQLizer.hpp"


using namespace w3c_sw;

POSFactory f;
SPARQLfedDriver sparqlParser("", &f);
std::ostream* DebugStream = NULL; // &std::cerr;
QueryMapper queryMapper(&f, &DebugStream);


void equalsTest (const char* leftString, const char* rightString, bool expect) {

    /* Parse left. */
    if (sparqlParser.parse_string(leftString)) {
	std::string msg = std::string("failed to parse left \"") + 
	    leftString + std::string("\".");
	throw msg;
    }
    Operation* left = sparqlParser.root;

    /* Parse right. */
    if (sparqlParser.parse_string(rightString)) {
	std::string msg = std::string("failed to parse right \"") + 
	    rightString + std::string("\".");
	throw msg;
    }
    Operation* right = sparqlParser.root;

    if (expect == true)
	BOOST_CHECK_EQUAL(*left, *right);
    else
	BOOST_CHECK_MESSAGE( !(*left == *right), *left << " == " << *right );

    delete left;
    delete right;
}

struct MapTest {
    const Operation* transformed;
    Operation* mapResults;
    MapTest (const char* queryFile, const char* mapFile, 
	     const char* mapResultsFile, 
	     const char* stemURI, const char* sqlResultsFile) {

	/* Parse query. */
	if (sparqlParser.parse_file(queryFile)) {
	    std::string msg = std::string("failed to parse query \"") + 
		queryFile + std::string("\".");
	    throw msg;
	}
	Operation* query = sparqlParser.root;

	/* Parse map. */
	if (sparqlParser.parse_file(mapFile)) {
	    std::string msg = std::string("failed to parse map \"") + 
		mapFile + std::string("\".");
	    throw msg;
	}
	queryMapper.addRule(dynamic_cast<Construct*>(sparqlParser.root));
	delete sparqlParser.root;

	query->express(&queryMapper);
	transformed = queryMapper.last.operation;
	delete query;

	/* Parse map results. */
	if (sparqlParser.parse_file(mapResultsFile)) {
	    std::string msg = std::string("failed to parse map results \"") + 
		mapResultsFile + std::string("\".");
	    throw msg;
	}
	mapResults = sparqlParser.root;

	if (stemURI != NULL) {
	    char predicateDelims[]={'#',' ',' '};
	    char nodeDelims[]={'/','.',' '};
	    SQLizer s(stemURI, predicateDelims, nodeDelims, "id", &DebugStream);
	    transformed->express(&s);
	    std::cout << s.getSQLstring() << endl;
	}
    }
    ~MapTest () {
	delete mapResults;
	delete transformed;
    }
};

BOOST_AUTO_TEST_CASE( op_equals ) {
    equalsTest("SELECT * WHERE { ?s ?p ?o }", 
	       "select*{?s?p?o}", true);
    equalsTest("SELECT ?s ?p ?o { ?s ?p ?o }", 
	       "SELECT ?s ?p $o { ?s ?p ?o}", true);
    equalsTest("SELECT ?p ?s ?o { ?s ?p ?o }", 
	       "SELECT ?s ?p ?o { ?s ?p ?o}", true);
    equalsTest("SELECT ?s ?p ?o { ?s ?p ?o }", 
	       "SELECT ?s ?p $o { ?s ?o ?p}", false);
    equalsTest("SELECT * { FILTER(1*(2+3)=?x) }", 
	       "SELECT * { FILTER(1*(2+3)=$x) }", true);
    equalsTest("SELECT * { FILTER( ?x ) }", 
	       "SELECT * { FILTER( ?y ) }", false);
}

BOOST_AUTO_TEST_CASE( simple_hl7_sdtm ) {
    MapTest t("tests/healthCare/simple/sdtm.rq", "tests/healthCare/simple/hl7-sdtm.rq", "tests/healthCare/simple/hl7.rq", NULL, NULL);
    BOOST_CHECK_EQUAL(*t.transformed, *t.mapResults);
}
BOOST_AUTO_TEST_CASE( simple_sdtm_db ) {
    MapTest t("tests/healthCare/simple/hl7.rq", "tests/healthCare/simple/db-hl7.rq", "tests/healthCare/simple/db.rq", "http://hospital.example/DB/", "tests/healthCare/simple/db.sql");
    BOOST_CHECK_EQUAL(*t.transformed, *t.mapResults);
}
BOOST_AUTO_TEST_CASE( bsbm_1 ) {
    MapTest t("bsbm/q1.rq", "bsbm/ruleMap.rq", "bsbm/q1-db.rq", NULL, NULL);
    BOOST_CHECK_EQUAL(*t.transformed, *t.mapResults);
}

