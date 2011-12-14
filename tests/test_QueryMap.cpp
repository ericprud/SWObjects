/* test query-mapping.
 *
 * $Id: test_QueryMap.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE QueryMap

#include <map>
#include <vector>
#include <fstream>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "MapSetParser/MapSetParser.hpp"
#include "SQLParser/SQLParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "ChainingMapper.hpp"
#include "SQLizer.hpp"

#ifndef MANUAL_TEST
  #include <boost/test/unit_test.hpp>
#endif

using namespace w3c_sw;

AtomFactory f;
SPARQLfedDriver sparqlParser("", &f);
MapSetDriver mapSetParser("", &f);
ChainingMapper queryMapper(&f);


struct EqualsTest {
    Operation* left, * right;
    bool (*mapper)(const TTerm*);
    EqualsTest (const char* leftString, const char* rightString) {

	/* Parse left. */
	IStreamContext lstream(leftString, IStreamContext::STRING);
	left = sparqlParser.parse(lstream);

	/* Parse right. */
	IStreamContext rstream(rightString, IStreamContext::STRING);
	right = sparqlParser.parse(rstream);
	mapper = BasicGraphPattern::MappableTerm;
	BasicGraphPattern::MappableTerm = BasicGraphPattern::MapBNodes;
    }
    ~EqualsTest () {
	BasicGraphPattern::MappableTerm = mapper;
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
BOOST_AUTO_TEST_CASE( respect_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p ?o { ?s ?p ?o}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
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
BOOST_AUTO_TEST_CASE( nested_respect_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
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
BOOST_AUTO_TEST_CASE( named_respect_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
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
    EqualsTest t("SELECT ?s ?p ?o ?o2 {{ ?s ?p ?o } { ?s ?p ?o2 }}", 
		 "SELECT ?s ?p ?o ?o2 {{ ?s ?p ?o } { ?s ?p ?o2 }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( conjunct_negative ) {
    EqualsTest t("SELECT $p ?s $o {{ ?s ?p ?o } { ?s ?p ?o }}", 
		 "SELECT $s ?p ?o {{ ?s ?p ?o } { ?s ?o ?p }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( conjunct_equiv_filter ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
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
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( union_negative ) {
    EqualsTest t("SELECT $p ?s $o {{ ?s ?p ?o } UNION { ?s ?p ?o }}", 
		 "SELECT $s ?p ?o {{ ?s ?p ?o } UNION { ?s ?o ?p }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( union_equiv_filter ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
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
	GetRootOp () : rootOp(NULL) {  }
	const TableOperation* rootOp;
	virtual void base (const w3c_sw::Base* const, std::string) {  }
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern) {
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
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( A_and_B_or_C ) {
    DNFtest t("ASK { { ?s1 ?p1 ?o1 } { { ?s2 ?p2 ?o2 } UNION { ?s3 ?p3 ?o3 } } }", 
	      "ASK { { { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } } UNION  { { ?s1 ?p1 ?o1 } { ?s3 ?p3 ?o3 } } }");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
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


struct SimplifiedBGPtest : public EqualsTest {
    SimplifiedBGPtest (const char* leftString, const char* rightString) : 
	EqualsTest (leftString, rightString) {
	BGPSimplifier s(&f);
	left->express(&s);
	delete left;
	left = const_cast<Operation*>(s.last.operation);
    }
};

BOOST_AUTO_TEST_SUITE( SimplifiedBGPtests )

BOOST_AUTO_TEST_SUITE( unions )
BOOST_AUTO_TEST_CASE( A_and_B ) {
    SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } }", 
			"ASK { ?s1 ?p1 ?o1 . ?s2 ?p2 ?o2 }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( Y_and_Y ) {
    SimplifiedBGPtest t("SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			"           SERVICE <S3> { ?qs <p3> ?qo } }",
			"SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			"           SERVICE <S3> { ?qs <p3> ?qo } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}

BOOST_AUTO_TEST_CASE( A_and_C_or_B_and_C ) {
    SimplifiedBGPtest t("ASK { { { ?s1 ?p1 ?o1 } { ?s3 ?p3 ?o3 } } UNION { { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } } }", 
			"ASK { {   ?s1 ?p1 ?o1  .  ?s3 ?p3 ?o3 }   UNION {   ?s2 ?p2 ?o2  .  ?s3 ?p3 ?o3 }   }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( A_and__B_and_C ) {
    SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } } }", 
			"ASK { ?s1 ?p1 ?o1    .    ?s2 ?p2 ?o2  .  ?s3 ?p3 ?o3 }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( A_and__B_minus_C ) {
    SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { { ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } } }", 
			"ASK { { ?s1 ?p1 ?o1  .    ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( optional_A_B ) {
    SimplifiedBGPtest t("ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } }", 
			"ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( optional_A_B_C ) {
    SimplifiedBGPtest t("ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } }", 
			"ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2  .  ?s3 ?p3 ?o3 } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
// BOOST_AUTO_TEST_CASE( A_B_minus_C_D_E ) {
//     SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } { ?s4 ?p4 ?o4 } { ?s5 ?p5 ?o5 } }", 
// 			"ASK { { ?s1 ?p1 ?o1  .  ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } { ?s4 ?p4 ?o4  .  ?s5 ?p5 ?o5 } }");
//     BOOST_CHECK_EQUAL(*t.left, *t.right);
// }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct CanonicalizerTest {
    bool (*bgpMappableTerm)(const TTerm*);
    const Operation* canon;
    const Operation* expected;

    CanonicalizerTest (const char* queryFile, const char* expectedFile,
		 IStreamContext::e_opts type = IStreamContext::FILE) :
	bgpMappableTerm(BasicGraphPattern::MappableTerm) {

	sparqlParser.unnestTree = true;
	/* Parse query. */
	IStreamContext qstr(queryFile, type);
	Operation* query = sparqlParser.parse(qstr);
	canon = canonicalize(query);
	delete query;

	/* Parse map expected. */
	IStreamContext rstr(expectedFile, type);
	expected = sparqlParser.parse(rstr);

	BasicGraphPattern::MappableTerm = &BasicGraphPattern::MapVarsAndBNodes;
    }
    const Operation* canonicalize (const Operation* op) {
	SWObjectCanonicalizer canon(&f);
	op->express(&canon);
	return canon.last.operation;
    }
    ~CanonicalizerTest () {
	BasicGraphPattern::MappableTerm = bgpMappableTerm;
	queryMapper.clear();
	delete expected;
	delete canon;
    }
};

#define CANON_TEST(QUERY, EXPECTED, TYPE)	       \
    try {								       \
	CanonicalizerTest t(QUERY, EXPECTED, TYPE);           \
	BOOST_CHECK_EQUAL(*t.expected, *t.canon);	       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_SUITE( canon )

	BOOST_AUTO_TEST_CASE( empty ) {
	    CANON_TEST("SELECT * {  }",
		       "SELECT * {  }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( bgps2_asis ) {
	    CANON_TEST("SELECT * { ?qs <p1> ?qo ; \n"
		       "               <p2> ?qo }",
		       "SELECT * { ?qs <p1> ?qo ; \n"
		       "               <p2> ?qo }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( bgps2_reorder ) {
	    CANON_TEST("SELECT * { ?qs <p2> ?qo ; \n"
		       "               <p1> ?qo }",
		       "SELECT * { ?qs <p1> ?qo ; \n"
		       "               <p2> ?qo }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( services2_asis ) {
	    CANON_TEST("SELECT * { SERVICE <S1> { ?qs <p1> ?qo }\n"
		       "           SERVICE <S2> { ?qs <p2> ?qo } }",
		       "SELECT * { SERVICE <S1> { ?qs <p1> ?qo }\n"
		       "           SERVICE <S2> { ?qs <p2> ?qo } }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( services2_onservice ) {
	    CANON_TEST("SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
		       "           SERVICE <S1> { ?qs <p1> ?qo } }",
		       "SELECT * { SERVICE <S1> { ?qs <p1> ?qo }\n"
		       "           SERVICE <S2> { ?qs <p2> ?qo } }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( services2_bgps2_reorder ) {
	    CANON_TEST("SELECT * { SERVICE <S1> { ?qs <p2> ?qo1 , ?qo2 }\n"
		       "           SERVICE <S1> { ?qs <p1> ?qo1 , ?qo2 } }",
		       "SELECT * { SERVICE <S1> { ?qs <p1> ?qo1 , ?qo2 . \n"
		       "                          ?qs <p2> ?qo1 , ?qo2 } }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( services2_bgps2_asis ) {
	    CANON_TEST("SELECT * { SERVICE <S1> { ?qs <p1> ?qo1 , ?qo2 }\n"
		       "           SERVICE <S1> { ?qs <p2> ?qo1 , ?qo2 } }",
		       "SELECT * { SERVICE <S1> { ?qs <p1> ?qo1 , ?qo2 .\n"
		       "                          ?qs <p2> ?qo1 , ?qo2 } }",
		       IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( services4 ) {
	    CANON_TEST("SELECT * { { SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town } }\n"
		       "           UNION\n"
		       "           { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech }\n"
		       "             SERVICE <nixonzpage> { <nixon> <hometown> ?town } }\n"
		       "           UNION\n"
		       "           { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?_presidents_1_inpech }\n"
		       "             SERVICE <nixonzpage> { <nixon> <impeachment> ?impech ; <hometown> ?town } }\n"
		       "           UNION\n"
		       "           { SERVICE <presidents> { <nixon> <inauguration> ?_presidents_2_inaug ; <impeachment> ?impech }\n"
		       "             SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <hometown> ?town } } }",
		       "SELECT * { { SERVICE <nixonzpage> { <nixon> <hometown> ?town ; <impeachment> ?impech ; <inauguration> ?inaug } }\n"
		       "           UNION\n"
		       "           { SERVICE <nixonzpage> { <nixon> <impeachment> ?impech ; <hometown> ?town }\n"
		       "             SERVICE <presidents> { <nixon> <impeachment> ?_presidents_1_inpech ; <inauguration> ?inaug } }\n"
		       "           UNION\n"
		       "           { SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <hometown> ?town }\n"
		       "             SERVICE <presidents> { <nixon> <impeachment> ?impech ; <inauguration> ?_presidents_2_inaug } }\n"
		       "           UNION\n"
		       "           { SERVICE <nixonzpage> { <nixon> <hometown> ?town }\n"
		       "             SERVICE <presidents> { <nixon> <impeachment> ?impech ; <inauguration> ?inaug } } }",
		       IStreamContext::STRING);
	}

BOOST_AUTO_TEST_SUITE_END( )


struct RuleMapTest {
    bool (*bgpMappableTerm)(const TTerm*);
    const Operation* transformed;
    const Operation* mapResults;
    const Operation* transformedNorm;
    const Operation* mapResultsNorm;

    RuleMapTest (const char* queryFile, const char* mapFile, 
		 const char* mapResultsFile,
		 IStreamContext::e_opts type = IStreamContext::FILE) :
	bgpMappableTerm(BasicGraphPattern::MappableTerm) {

	namespace tst = boost::unit_test::framework;
	for (int i = 1; i < tst::master_test_suite().argc; ++i)
	    if (std::string(tst::master_test_suite().argv[i]) == "-D")
		Logger::addStream(Logger::prepare(), boost::shared_ptr< std::ostream >(&std::clog, boost::log::empty_deleter()));

	sparqlParser.unnestTree = true;
	/* Parse query. */
	IStreamContext qstr(queryFile, type);
	Operation* query = sparqlParser.parse(qstr);

	/* Parse map. */
	IStreamContext mstr(mapFile, type);
	MapSet* ms = mapSetParser.parse(mstr);
	queryMapper.sharedVars = ms->sharedVars;
	for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
	     it != ms->maps.end(); ++it)
	    queryMapper.addRule(it->constr, it->label);
	queryMapper.nodeShare = ms->nodeShare;
	delete ms;

	try {
	    transformed = queryMapper.map(query);
	} catch (RuleMatchingException e) { // !! should catch whatever
	    delete query;
	    queryMapper.clear();
	    //std::string m(e.what());
	    //throw m;
	    throw e;
	}
	delete query;
	transformedNorm = canonicalize(transformed);

	/* Parse map results. */
	IStreamContext rstr(mapResultsFile, type);
	mapResults = sparqlParser.parse(rstr);
	mapResultsNorm = canonicalize(mapResults);

	BasicGraphPattern::MappableTerm = &BasicGraphPattern::MapVarsAndBNodes;
    }
    const Operation* canonicalize (const Operation* op) {
	SWObjectCanonicalizer canon(&f);
	op->express(&canon);
	return canon.last.operation;
    }
    ~RuleMapTest () {
	BasicGraphPattern::MappableTerm = bgpMappableTerm;
	queryMapper.clear();
	delete mapResults;
	delete transformed;
	delete mapResultsNorm;
	delete transformedNorm;
    }
};

struct SQLizerTest {
    //std::iostream* sqlErrorStream;
    sqlContext context;
    SQLDriver sqlParser;
    sql::SQLQuery* transformed;
    sql::SQLQuery* ref;
    Operation* deleteOperation;
    SQLizerTest (const char* queryFile, 
		 const char* stemURI, const char* sqlResultsFile)
	: sqlParser(context), deleteOperation(NULL)
	//: sqlErrorStream(SQLizer::ErrorStream)
    {
	//SQLizer::ErrorStream = &std::cerr;
	IStreamContext qstr(queryFile, IStreamContext::FILE);
	deleteOperation = sparqlParser.parse(qstr);
	_init(deleteOperation, stemURI, sqlResultsFile);
    }
    SQLizerTest (const Operation* sparqlQuery, 
		 const char* stemURI, const char* sqlResultsFile)
	: sqlParser(context), deleteOperation(NULL)
	//: sqlErrorStream(SQLizer::ErrorStream)
    { _init(sparqlQuery, stemURI, sqlResultsFile); }
    void _init (const Operation* sparqlQuery, 
		const char* stemURI, const char* sqlResultsFile)
    {
	//SQLizer::ErrorStream = &std::cerr;

	/* map SPARQLquery to SQL. */
	char predicateDelims[]={'#',' ',' '};
	char nodeDelims[]={'/','.',' '};
	SQLizer s(&f, stemURI, predicateDelims, nodeDelims, "id", KeyMap(), "");
	sparqlQuery->express(&s);
	IStreamContext generated(s.getSQLstring(), IStreamContext::STRING);
	try {
	    transformed = sqlParser.parse(generated);
	    //std::cout << s.getSQLstring() << endl;

	    /* Read reference SQL. */
	    IStreamContext parsed(sqlResultsFile, IStreamContext::FILE);
	    try {
		ref = sqlParser.parse(parsed);
	    } catch (std::string e) {
		std::cerr << e;
		ref = NULL;
	    }
	} catch (std::string e) { // SQL parser exceptions aren't very elegant yet.
	    std::cerr << e;
	    transformed = NULL;
	}
    }
    ~SQLizerTest () {
	delete transformed;
	delete ref;
	//SQLizer::ErrorStream = sqlErrorStream;
    }
};

#define RULE_MAP_TEST(QUERY_FILE, MAP_FILE, MAP_RESULTS_FILE, TYPE)	       \
    try {								       \
	RuleMapTest t(QUERY_FILE, MAP_FILE, MAP_RESULTS_FILE, TYPE);           \
	BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);	       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

#define SQLIZER_TEST(QUERY_FILE, MAP_FILE, MAP_RESULTS_FILE,		       \
		     STEMURI, SQLRESULTSFILE, TYPE)			       \
    try {								       \
	RuleMapTest t(QUERY_FILE, MAP_FILE, MAP_RESULTS_FILE, TYPE);           \
	BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);	       \
	SQLizerTest s(t.mapResults, STEMURI, SQLRESULTSFILE);		       \
	BOOST_CHECK_EQUAL(*s.transformed, *s.ref);			       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_SUITE( sparql2sparql )
    BOOST_AUTO_TEST_SUITE( simple )
	BOOST_AUTO_TEST_CASE( order ) {
	    RULE_MAP_TEST("SELECT * { ?q1 <p2> ?q2 ; <p3> ?q3 }",
			  "LABEL 'p2' CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S2> { ?rs <p2> ?ro } }\n"
			  "LABEL 'p3' CONSTRUCT { ?rs <p3> ?ro } { SERVICE <S3> { ?rs <p3> ?ro } }",
			  "SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			  "           SERVICE <S3> { ?qs <p3> ?qo } }",
			  IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( by_P_by_S ) {
	    RULE_MAP_TEST("SELECT * { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town}",
			  "LABEL 'presidents' CONSTRUCT { ?pres <inauguration> ?inaug ; <impeachment> ?inpech } { SERVICE <presidents> { ?pres <inauguration> ?inaug ; <impeachment> ?inpech } }\n"
			  "LABEL 'nixonzpage' CONSTRUCT { <nixon> ?p ?o } { SERVICE <nixonzpage> { <nixon> ?p ?o } }",
			  "SELECT * { { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech }\n"
			  "             SERVICE <nixonzpage> { <nixon> <hometown> ?town } }\n"
			  "           UNION\n"
			  "           { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?_presidents_1_inpech }\n"
			  "             SERVICE <nixonzpage> { <nixon> <impeachment> ?impech ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "           { SERVICE <presidents> { <nixon> <inauguration> ?_presidents_2_inaug ; <impeachment> ?impech }\n"
			  "             SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "           { SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town } } }",
			  IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( by_P_by_S_msr ) {
	    RULE_MAP_TEST("SELECT * { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town}",
			  "LABEL 'inaug'      CONSTRUCT { ?pres <inauguration> ?inaug } { SERVICE <presidents> { ?pres <inauguration> ?inaug } }\n"
			  "LABEL 'impeach'    CONSTRUCT { ?pres <impeachment> ?inpech } { SERVICE <presidents> { ?pres <impeachment> ?inpech } }\n"
			  "LABEL 'nixonzpage' CONSTRUCT { <nixon> ?p ?o } { SERVICE <nixonzpage> { <nixon> ?p ?o } }",
			  "SELECT * { { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech }\n"
			  "               SERVICE <nixonzpage> { <nixon> <hometown> ?town } }\n"
			  "           UNION\n"
			  "             { SERVICE <presidents> { <nixon> <inauguration> ?inaug }\n"
			  "               SERVICE <nixonzpage> { <nixon> <impeachment> ?impech ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "             { SERVICE <presidents> { <nixon> <impeachment> ?impech }\n"
			  "               SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "             { SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town } } }",
			  IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( p1_p2 ) {
	    RULE_MAP_TEST("SELECT * { ?qs <p2> ?qo }",
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro }",
			  "SELECT * { ?qs <p1> ?qo }",
			  IStreamContext::STRING);
	}
	BOOST_AUTO_TEST_CASE( p01_p2 ) {
	    RULE_MAP_TEST("SELECT * { ?qs <p2> ?qo }",
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro ; <p0> 'x' }",
			  "SELECT * { ?qs <p1> ?qo ; <p0> 'x' }",
			  IStreamContext::STRING);
	}
	BOOST_AUTO_TEST_CASE( p3 ) {
	    BOOST_CHECK_THROW
		(RuleMapTest("SELECT * { ?qs <p3> ?qo }",
			     "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro }",
			     "",
			     IStreamContext::STRING),
		 RuleMatchingException);
	}
	BOOST_AUTO_TEST_CASE( p1_S1_p2 ) {
	    RULE_MAP_TEST("SELECT * { ?qs <p2> ?qo }",
			  "LABEL 'p1_S1_p2' CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S1> { ?rs <p1> ?ro } }",
			  "SELECT * { SERVICE <S1> { ?qs <p1> ?qo } }",
			  IStreamContext::STRING);
	}
	BOOST_AUTO_TEST_CASE( p1_S2_p2_S3_p3 ) {
	    RULE_MAP_TEST("SELECT * { ?q1 <p2> ?q2 ; <p3> ?q3 }",
			  "CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S2> { ?rs <p2> ?ro } }\n"
			  "CONSTRUCT { ?rs <p3> ?ro } { SERVICE <S3> { ?rs <p3> ?ro } }",
			  "SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			  "           SERVICE <S3> { ?qs <p3> ?qo } }",
			  IStreamContext::STRING);
	}

	BOOST_AUTO_TEST_CASE( to_many_to_many ) {
	    RULE_MAP_TEST("PREFIX foaf: <http://xmlns.com/foaf/0.1/>\n"
			  "PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>\n"
			  "SELECT ?lname {\n"
			  "  ?who  foaf:last_name    ?lname .\n"
			  "  ?who  foaf:knows        ?whom  .\n"
			  "  ?whom foaf:last_name    'Smith'^^xsd:string }",

			  "  PREFIX foaf: <http://xmlns.com/foaf/0.1/>\n"
			  "  PREFIX empP: <http://hr.example/DB/Employee#>\n"
			  "  PREFIX task: <http://hr.example/DB/Task#>\n"
			  "  SHAREDVARS DRACONIAN\n"
			  "  INTERSECTION {<Emp_TaskToFoaf>}?emp {<Emp_TaskToFoaf>}?man\n"
			  "LABEL <Emp_TaskToFoaf> \n"
			  "  CONSTRUCT { ?emp  foaf:last_name  ?wname .\n"
			  "             ?emp  foaf:knows      ?man .\n"
			  "             ?man  foaf:last_name  ?mname }\n"
			  "  WHERE { ?emp  empP:lastName   ?wname .\n"
			  "         ?pair task:drone      ?emp .\n"
			  "         ?pair task:manager    ?man .\n"
			  "         ?man  empP:lastName   ?mname }",

			  "PREFIX empP: <http://hr.example/DB/Employee#>\n"
			  "PREFIX task: <http://hr.example/DB/Task#>\n"
			  "PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>\n"
			  "SELECT ?lname\n"
			  "     { ?who  empP:lastName   ?lname .\n"
			  "       ?_0_pair task:drone      ?who .\n"
			  "       ?_0_pair task:manager    ?whom .\n"
			  "       ?whom empP:lastName   'Smith'^^xsd:string }",
			  IStreamContext::STRING);
	}

    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( toy )
	BOOST_AUTO_TEST_CASE( const_p ) {
	    RULE_MAP_TEST("SELECT * { ?s <p3> ?o }",
			  "CONSTRUCT { <x> <p1> ?ro } { ?rs <q1> ?ro }\n"
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <q2> ?ro }\n"
			  "CONSTRUCT { <x> <p3> ?ro } { ?rs <q3> ?ro }\n"
			  "CONSTRUCT { ?rs <p4> ?ro } { ?rs <q4> ?ro }",
			  "SELECT * { ?s <q3> ?o }",
			  IStreamContext::STRING);
	}
	BOOST_AUTO_TEST_CASE( var_p ) {
	    RULE_MAP_TEST("SELECT * { ?s ?p ?o }",
			  "CONSTRUCT { ?rs <p1> ?ro } { ?rs <q1> ?ro }\n"
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <q2> ?ro }",
			  "SELECT * { { ?s <q1> ?qo }\n"
			  "           UNION\n"
			  "           { ?s <q2> ?qo } }",
			  IStreamContext::STRING);
	}
	BOOST_AUTO_TEST_CASE( poly_p ) {
	    RULE_MAP_TEST("SELECT * { ?s <p1> ?o }",
			  "LABEL <1> CONSTRUCT { ?s3 <p1> ?ro } { ?rs <q1> ?ro }\n"
			  "LABEL <2> CONSTRUCT { <x> <p1> ?ro } { ?rs <q1b> ?ro }",
			  "SELECT * { { ?rs1 <q1> ?qo }\n"
			  "           UNION\n"
			  "           { ?rs2 <q1b> ?qo } }",
			  IStreamContext::STRING);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( healthCare )
    BOOST_AUTO_TEST_SUITE( simple )
	BOOST_AUTO_TEST_CASE( hl7_sdtm ) {
	    RULE_MAP_TEST("healthCare/simple/sdtm.rq", "healthCare/simple/hl7-sdtm.rq", "healthCare/simple/hl7.rq", IStreamContext::FILE);
	}
	BOOST_AUTO_TEST_CASE( sdtm_db ) {
	    RuleMapTest t("healthCare/simple/hl7.rq", "healthCare/simple/db-hl7.rq", "healthCare/simple/db.rq");
	    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
		std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
		BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	    SQLizerTest s(t.mapResults, "http://hospital.example/DB/", "healthCare/simple/db.sql");
	    BOOST_CHECK_EQUAL(*s.transformed, *s.ref);
	}
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE( i2b2 )
	BOOST_AUTO_TEST_SUITE( monolithic )
	    BOOST_AUTO_TEST_CASE( subselect ) {
		SQLIZER_TEST("i2b2/tmo_pat_test_date.rq", "i2b2/monolithic/i2b2_to_tmo-subselect.map", "i2b2/monolithic/db_pat_test_date-subselect.rq",
			     "http://informatics.kumc.edu/404/i2b2demo/", "i2b2/monolithic/db_pat_test_date-subselect.sql", IStreamContext::FILE);
	    }
	    BOOST_AUTO_TEST_CASE( bind ) {
		SQLIZER_TEST("i2b2/tmo_pat_test_date.rq", "i2b2/monolithic/i2b2_to_tmo-bind.map", "i2b2/monolithic/db_pat_test_date-bind.rq",
			     "http://informatics.kumc.edu/404/i2b2demo/", "i2b2/monolithic/db_pat_test_date-bind.sql", IStreamContext::FILE);
	    }
	BOOST_AUTO_TEST_SUITE_END() //monolithic
	BOOST_AUTO_TEST_SUITE( modular )
	    BOOST_AUTO_TEST_CASE( subselect ) {
		SQLIZER_TEST("i2b2/tmo_pat_test_date.rq", "i2b2/modular/i2b2_to_tmo-subselect.map", "i2b2/modular/db_pat_test_date-subselect.rq",
			     "http://informatics.kumc.edu/404/i2b2demo/", "i2b2/modular/db_pat_test_date-subselect.sql", IStreamContext::FILE);
	    }
	    BOOST_AUTO_TEST_CASE( bind ) {
		SQLIZER_TEST("i2b2/tmo_pat_test_date.rq", "i2b2/modular/i2b2_to_tmo-bind.map", "i2b2/modular/db_pat_test_date-bind.rq",
			     "http://informatics.kumc.edu/404/i2b2demo/", "i2b2/modular/db_pat_test_date-bind.sql", IStreamContext::FILE);
	    }
	BOOST_AUTO_TEST_SUITE_END() //modular
    BOOST_AUTO_TEST_SUITE_END() //i2b2

    BOOST_AUTO_TEST_SUITE( notBound )
	BOOST_AUTO_TEST_CASE( lists_notBound ) {
	    SQLIZER_TEST("healthCare/lists-notBound/hl7.rq", "healthCare/lists-notBound/db-hl7.rq", "healthCare/lists-notBound/db.rq",
			 "http://hospital.example/DB/", "healthCare/lists-notBound/db.sql", IStreamContext::FILE);
        }
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE( cabig )
	BOOST_AUTO_TEST_CASE( bg_hl7 ) {
	RULE_MAP_TEST("healthCare/cabig/twoWayBGQuery.rq", "healthCare/cabig/twoWayHL7-BGMap.rq", "healthCare/cabig/twoWayHL7Query.rq", IStreamContext::FILE);
	}
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_CASE( goProt ) {
	RuleMapTest t("goProt/goProt2.rq", "goProt/goProt2.map", "goProt/goProt2-srvc.rq");
	BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( bsbm )
    BOOST_AUTO_TEST_SUITE( pieces )
	BOOST_AUTO_TEST_CASE( parseQuery ) {
	    IStreamContext::e_opts type = IStreamContext::FILE;
	    IStreamContext qstr("bsbm/q1.rq", type);
	    Operation* query = sparqlParser.parse(qstr);
	    delete query;
	}

	BOOST_AUTO_TEST_CASE( parseMap ) {
	    IStreamContext::e_opts type = IStreamContext::FILE;
	    IStreamContext mstr("bsbm/db2bsbm.map", type);
	    MapSet* ms = mapSetParser.parse(mstr);
	    queryMapper.sharedVars = ms->sharedVars;
	    for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
		 it != ms->maps.end(); ++it)
		queryMapper.addRule(it->constr, it->label);
	    queryMapper.nodeShare = ms->nodeShare;
	    delete ms;
	}

	BOOST_AUTO_TEST_CASE( transformQuery ) {
	    IStreamContext::e_opts type = IStreamContext::FILE;
	    IStreamContext qstr("bsbm/q1.rq", type);
	    Operation* query = sparqlParser.parse(qstr);

	    IStreamContext mstr("bsbm/db2bsbm.map", type);
	    MapSet* ms = mapSetParser.parse(mstr);
	    queryMapper.sharedVars = ms->sharedVars;
	    for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
		 it != ms->maps.end(); ++it)
		queryMapper.addRule(it->constr, it->label);
	    queryMapper.nodeShare = ms->nodeShare;

	    const Operation* transformed = queryMapper.map(query);
	    delete transformed;
	    delete query;
	    delete ms;
	}

	BOOST_AUTO_TEST_CASE( canonicalizeTransformation ) {
	    IStreamContext::e_opts type = IStreamContext::FILE;
	    IStreamContext qstr("bsbm/q1.rq", type);
	    Operation* query = sparqlParser.parse(qstr);

	    IStreamContext mstr("bsbm/db2bsbm.map", type);
	    MapSet* ms = mapSetParser.parse(mstr);
	    queryMapper.sharedVars = ms->sharedVars;
	    for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
		 it != ms->maps.end(); ++it)
		queryMapper.addRule(it->constr, it->label);
	    queryMapper.nodeShare = ms->nodeShare;

	    const Operation* transformed = queryMapper.map(query);
	    SPARQLSerializer s;
	    transformed->express(&s);
	    delete transformed;
	    delete query;
	    delete ms;
	}
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_CASE( q1 ) {
	RuleMapTest t("bsbm/q1.rq", "bsbm/db2bsbm.map", "bsbm/q1-db.rq");
	BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
    }

BOOST_AUTO_TEST_SUITE_END()

/** record how to access test argc/argv 'cause i always forget:
    namespace tst = boost::unit_test::framework;
    for (int i = 1; i < tst::master_test_suite().argc; ++i) {
	std::string s = tst::master_test_suite().argv[i];
	if (s.find_first_of("stem=") == 0)
	    stem = s.substr(5, s.size()-5);
    }

    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
	std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
*/

