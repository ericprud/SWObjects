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
#include <fstream>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "QueryMapper.hpp"
#include "SQLizer.hpp"


using namespace w3c_sw;

POSFactory f;
SPARQLfedDriver sparqlParser("", &f);
std::ostream* DebugStream = NULL; // &std::cerr;
QueryMapper queryMapper(&f, &DebugStream);


struct EqualsTest {
    Operation* left, * right;
    EqualsTest (const char* leftString, const char* rightString) {

	/* Parse left. */
	IStreamContext lstream(leftString, StreamContext::STRING);
	if (sparqlParser.parse(lstream)) {
	    std::string msg = std::string("failed to parse left \"") + 
		leftString + std::string("\".");
	    throw msg;
	}
	left = sparqlParser.root;

	/* Parse right. */
	IStreamContext rstream(rightString, StreamContext::STRING);
	if (sparqlParser.parse(rstream)) {
	    std::string msg = std::string("failed to parse right \"") + 
		rightString + std::string("\".");
	    throw msg;
	}
	right = sparqlParser.root;
    }
    ~EqualsTest () {
	delete left;
	delete right;
    }
};

BOOST_AUTO_TEST_SUITE( op_equals )

BOOST_AUTO_TEST_SUITE( bgp )
BOOST_AUTO_TEST_CASE( case_and_space_sensitivity ) {
    BOOST_TEST_CHECKPOINT( "executing BGP tests" );
    EqualsTest t("SELECT * WHERE { ?s ?p ?o }", 
		 "select*{?s?p?o}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( question_dollar_vars ) {
    EqualsTest t("SELECT ?s ?p ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p $o { ?s ?p ?o}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( ignore_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p ?o { ?s ?p ?o}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( observe_triple_order ) {
    EqualsTest t("SELECT ?s ?p ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p $o { ?s ?o ?p}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( equiv_filter ) {
    EqualsTest t("SELECT * { FILTER(1*(2+3)=?x) }", 
		 "SELECT * { FILTER(1*(2+3)=$x) }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( different_vars_in_filter ) {
    EqualsTest t("SELECT * { FILTER( ?x ) }", 
		 "SELECT * { FILTER( ?y ) }");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( nested )
BOOST_AUTO_TEST_CASE( nested_case_and_space_sensitivity ) {
    BOOST_TEST_CHECKPOINT( "executing nested tests" );
    EqualsTest t("SELECT * WHERE { { ?s ?p ?o } }", 
		 "select*{{?s?p?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_question_dollar_vars ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {{ ?s ?p ?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_ignore_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_observe_triple_order ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {{ ?s ?o ?p}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( nested_equiv_filter ) {
    EqualsTest t("SELECT * {{ FILTER(1*(2+3)=?x) }}", 
		 "SELECT * {{ FILTER(1*(2+3)=$x) }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_different_vars_in_filter ) {
    EqualsTest t("SELECT * {{ FILTER( ?x ) }}", 
		 "SELECT * {{ FILTER( ?y ) }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( named )
BOOST_AUTO_TEST_CASE( named_case_and_space_sensitivity ) {
    BOOST_TEST_CHECKPOINT( "executing named graph tests" );
    EqualsTest t("SELECT * WHERE { GRAPH<x> { ?s ?p ?o } }", 
		 "select*{graph<x>{?s?p?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_question_dollar_vars ) {
    EqualsTest t("SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {GRAPH<x>{ ?s ?p ?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_ignore_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_observe_triple_order ) {
    EqualsTest t("SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {GRAPH<x>{ ?s ?o ?p}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( named_equiv_filter ) {
    EqualsTest t("SELECT * {GRAPH<x>{ FILTER(1*(2+3)=?x) }}", 
		 "SELECT * {GRAPH<x>{ FILTER(1*(2+3)=$x) }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_different_vars_in_filter ) {
    EqualsTest t("SELECT * {GRAPH<x>{ FILTER( ?x ) }}", 
		 "SELECT * {GRAPH<x>{ FILTER( ?y ) }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( conjuncts )
BOOST_AUTO_TEST_CASE( conjunct_positive ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } { ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( conjunct_negative ) {
    EqualsTest t("SELECT $p ?s $o {{ ?s ?p ?o } { ?s ?p ?o }}", 
		 "SELECT $s ?p ?o {{ ?s ?p ?o } { ?s ?o ?p }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( conjunct_equiv_filter ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER(1*(2+3)=?x)}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( conjunct_different_vars_in_filter ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER( ?x )}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER( ?y )}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( unions )
BOOST_AUTO_TEST_CASE( union_positive ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } UNION { ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( union_negative ) {
    EqualsTest t("SELECT $p ?s $o {{ ?s ?p ?o } UNION { ?s ?p ?o }}", 
		 "SELECT $s ?p ?o {{ ?s ?p ?o } UNION { ?s ?o ?p }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( union_equiv_filter ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( union_different_vars_in_filter ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER( ?x )}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER( ?y )}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct DNFtest : public EqualsTest {
    const TableOperation* dnf;
    const TableOperation* ref;
    struct GetRootOp : public RecursiveExpressor {
	const TableOperation* rootOp;
	virtual void base (const w3c_sw::Base* const, std::string) {  }
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause*) {
	    rootOp = p_GroupGraphPattern;
	}
    };
    DNFtest (const char* leftString, const char* rightString) : 
	EqualsTest (leftString, rightString) {
	GetRootOp g;
	left->express(&g);
	dnf = g.rootOp->getDNF();

	right->express(&g);
	ref = g.rootOp;
    }
    ~DNFtest () {
	delete dnf;
    }
};

BOOST_AUTO_TEST_SUITE( DNFtests )

BOOST_AUTO_TEST_SUITE( unions )
BOOST_AUTO_TEST_CASE( A_or_B ) {
    DNFtest t("ASK {{ ?s1 ?p1 ?o1 } UNION { ?s2 ?p2 ?o2 }}", 
	      "ASK {{ ?s1 ?p1 ?o1 } UNION { ?s2 ?p2 ?o2 }}");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( A_or_B_and_C ) {
    DNFtest t("ASK { { { ?s1 ?p1 ?o1 } UNION { ?s2 ?p2 ?o2 } } { ?s3 ?p3 ?o3 } }", 
	      "ASK { { { ?s1 ?p1 ?o1 } { ?s3 ?p3 ?o3 } } UNION { { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } } }");
    BOOST_CHECK_MESSAGE( !(*t.dnf == *t.ref), *t.dnf << " == " << *t.ref );
}
BOOST_AUTO_TEST_CASE( union_equiv_filter_positive ) {
    DNFtest t("ASK { { ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
	      "ASK { { { ?s ?p ?o FILTER(1*(2+3)=?x) } } UNION { { ?s ?p ?o FILTER(1*(2+3)=?x) } } }");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( union_different_vars_in_filter ) {
    DNFtest t("ASK { { ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
	      "ASK { { ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}");
    BOOST_CHECK_MESSAGE( !(*t.dnf == *t.ref), *t.dnf << " == " << *t.ref );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct RuleMapTest {
    bool bgpCompareVars;
    const Operation* transformed;
    Operation* mapResults;

    RuleMapTest (const char* queryFile, const char* mapFile, 
		 const char* mapResultsFile) :
	bgpCompareVars(BasicGraphPattern::CompareVars) {

	/* Parse query. */
	IStreamContext qstr(queryFile, StreamContext::FILE);
	if (sparqlParser.parse(qstr)) {
	    std::string msg = std::string("failed to parse query \"") + 
		queryFile + std::string("\".");
	    throw msg;
	}
	Operation* query = sparqlParser.root;

	/* Parse map. */
	IStreamContext mstr(mapFile, StreamContext::FILE);
	if (sparqlParser.parse(mstr)) {
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
	IStreamContext rstr(mapResultsFile, StreamContext::FILE);
	if (sparqlParser.parse(rstr)) {
	    std::string msg = std::string("failed to parse map results \"") + 
		mapResultsFile + std::string("\".");
	    throw msg;
	}
	mapResults = sparqlParser.root;

	BasicGraphPattern::CompareVars = true;
    }
    ~RuleMapTest () {
	BasicGraphPattern::CompareVars = bgpCompareVars;
	queryMapper.clear();
	delete mapResults;
	delete transformed;
    }
};

struct SQLizerTest {
    //std::iostream* sqlErrorStream;
    std::string transformed, ref;
    SQLizerTest (const Operation* sparqlQuery, 
		 const char* stemURI, const char* sqlResultsFile)
	//: sqlErrorStream(SQLizer::ErrorStream)
    {
	//SQLizer::ErrorStream = &std::cerr;

	/* map SPARQLquery to SQL. */
	char predicateDelims[]={'#',' ',' '};
	char nodeDelims[]={'/','.',' '};
	SQLizer s(stemURI, predicateDelims, nodeDelims, "id", &DebugStream);
	sparqlQuery->express(&s);
	transformed = s.getSQLstring() + "\n";
	//std::cout << s.getSQLstring() << endl;

	/* Read reference SQL. */
	std::ifstream dataStream(sqlResultsFile);
	if (!dataStream.is_open()) {
	    std::string msg = std::string("failed to read data \"") + 
		sqlResultsFile + std::string("\".");
	    throw msg;
	}
	std::istreambuf_iterator<char> i(dataStream), e;
	ref = std::string(i, e);
	dataStream.close();
    }
    ~SQLizerTest () {
	//SQLizer::ErrorStream = sqlErrorStream;
    }
};

BOOST_AUTO_TEST_SUITE( healthCare )
BOOST_AUTO_TEST_SUITE( simple )
BOOST_AUTO_TEST_CASE( hl7_sdtm ) {
    RuleMapTest t("healthCare/simple/sdtm.rq", "healthCare/simple/hl7-sdtm.rq", "healthCare/simple/hl7.rq");
    BOOST_CHECK_EQUAL(*t.transformed, *t.mapResults);
}
BOOST_AUTO_TEST_CASE( sdtm_db ) {
    RuleMapTest t("healthCare/simple/hl7.rq", "healthCare/simple/db-hl7.rq", "healthCare/simple/db.rq");
    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
	std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
	BOOST_CHECK_EQUAL(*t.transformed, *t.mapResults);
    SQLizerTest s(t.mapResults, "http://hospital.example/DB/", "healthCare/simple/db.sql");
    BOOST_CHECK_EQUAL(s.transformed, s.ref);
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE( bsbm_1 ) {
    RuleMapTest t("bsbm/q1.rq", "bsbm/ruleMap.rq", "bsbm/q1-db.rq");
    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
	std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
	BOOST_CHECK_EQUAL(*t.transformed, *t.mapResults);
}

