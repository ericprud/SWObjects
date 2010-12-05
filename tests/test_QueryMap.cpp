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
std::ostream* DebugStream = NULL; // &std::cerr;
ChainingMapper queryMapper(&f, &DebugStream);


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
	SQLizer s(stemURI, predicateDelims, nodeDelims, "id", KeyMap(), &DebugStream);
	sparqlQuery->express(&s);
	IStreamContext generated(s.getSQLstring(), IStreamContext::STRING);
	try {
	    BOOST_CHECK_EQUAL(0, sqlParser.parse(generated));
	    transformed = sqlParser.root;
	    //std::cout << s.getSQLstring() << endl;

	    /* Read reference SQL. */
	    IStreamContext parsed(sqlResultsFile, IStreamContext::FILE);
	    try {
		BOOST_CHECK_EQUAL(0, sqlParser.parse(parsed));
		ref = sqlParser.root;
	    } catch (std::string e) {
		std::cerr << e;
		ref = NULL;
	    }
	} catch (std::string e) {
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

BOOST_AUTO_TEST_SUITE( sparql2sparql )
    BOOST_AUTO_TEST_SUITE( simple )
	BOOST_AUTO_TEST_CASE( order ) {
	    RuleMapTest t("SELECT * { ?q1 <p2> ?q2 ; <p3> ?q3 }",
			  "'p2' CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S2> { ?rs <p2> ?ro } }\n"
			  "'p3' CONSTRUCT { ?rs <p3> ?ro } { SERVICE <S3> { ?rs <p3> ?ro } }",
			  "SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			  "           SERVICE <S3> { ?qs <p3> ?qo } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}

#if PARSER_BUG && SERVICE_MERGING
	BOOST_AUTO_TEST_CASE( by_P_by_S ) {
	    RuleMapTest t("SELECT * { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town}",
			  "'presidents' CONSTRUCT { ?pres <inauguration> ?inaug ; <impeachment> ?inpech } { SERVICE <presidents> { ?pres <inauguration> ?inaug ; <impeachment> ?inpech } }\n"
			  "'nixonzpage' CONSTRUCT { <nixon> ?p ?o } { SERVICE <nixonzpage> { <nixon> ?p ?o } }",
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
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
#endif /* PARSER_BUG && SERVICE_MERGING */

#if PARSER_BUG && SERVICE_MERGING
	BOOST_AUTO_TEST_CASE( by_P_by_S_msr ) {
	    RuleMapTest t("SELECT * { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town}",
			  "'inaug'      CONSTRUCT { ?pres <inauguration> ?inaug } { SERVICE <presidents> { ?pres <inauguration> ?inaug } }\n"
			  "'impeach'    CONSTRUCT { ?pres <impeachment> ?inpech } { SERVICE <presidents> { ?pres <impeachment> ?inpech } }\n"
			  "'nixonzpage' CONSTRUCT { <nixon> ?p ?o } { SERVICE <nixonzpage> { <nixon> ?p ?o } }",
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
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
#endif /* PARSER_BUG && SERVICE_MERGING */

	BOOST_AUTO_TEST_CASE( p1_p2 ) {
	    RuleMapTest t("SELECT * { ?qs <p2> ?qo }",
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro }",
			  "SELECT * { ?qs <p1> ?qo }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( p01_p2 ) {
	    RuleMapTest t("SELECT * { ?qs <p2> ?qo }",
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro ; <p0> 'x' }",
			  "SELECT * { ?qs <p1> ?qo ; <p0> 'x' }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
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
	    RuleMapTest t("SELECT * { ?qs <p2> ?qo }",
			  "'p1_S1_p2' CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S1> { ?rs <p1> ?ro } }",
			  "SELECT * { SERVICE <S1> { ?qs <p1> ?qo } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( p1_S2_p2_S3_p3 ) {
	    RuleMapTest t("SELECT * { ?q1 <p2> ?q2 ; <p3> ?q3}",
			  "CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S2> { ?rs <p2> ?ro } }\n"
			  "CONSTRUCT { ?rs <p3> ?ro } { SERVICE <S3> { ?rs <p3> ?ro } }",
			  "SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			  "           SERVICE <S3> { ?qs <p3> ?qo } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}

	BOOST_AUTO_TEST_CASE( to_many_to_many ) {
	    RuleMapTest t("PREFIX foaf: <http://xmlns.com/foaf/0.1/>\n"
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
			  "<Emp_TaskToFoaf> \n"
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
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}

    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( healthCare )
    BOOST_AUTO_TEST_SUITE( simple )
	BOOST_AUTO_TEST_CASE( hl7_sdtm ) {
	    RuleMapTest t("healthCare/simple/sdtm.rq", "healthCare/simple/hl7-sdtm.rq", "healthCare/simple/hl7.rq");
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( sdtm_db ) { // !! leaky
	    RuleMapTest t("healthCare/simple/hl7.rq", "healthCare/simple/db-hl7.rq", "healthCare/simple/db.rq");
	    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
		std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
		BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	    SQLizerTest s(t.mapResults, "http://hospital.example/DB/", "healthCare/simple/db.sql");
	    BOOST_CHECK_EQUAL(*s.transformed, *s.ref);
	}
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE( notBound )
	BOOST_AUTO_TEST_CASE( lists_notBound ) {
	    RuleMapTest t("healthCare/lists-notBound/hl7.rq", "healthCare/lists-notBound/db-hl7.rq", "healthCare/lists-notBound/db.rq");
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	    SQLizerTest s(t.mapResults, "http://hospital.example/DB/", "healthCare/lists-notBound/db.sql");
	    BOOST_CHECK_EQUAL(*s.transformed, *s.ref);
        }
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE( cabig )
	BOOST_AUTO_TEST_CASE( bg_hl7 ) {
	    RuleMapTest t("healthCare/cabig/twoWayBGQuery.rq", "healthCare/cabig/twoWayHL7-BGMap.rq", "healthCare/cabig/twoWayHL7Query.rq");
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
    BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()

#if 0
BOOST_AUTO_TEST_CASE( refree ) { // !! leaky
    namespace tst = boost::unit_test::framework;
    std::string stem = "http://someClinic.exampe/DB/";
    for (int i = 1; i < tst::master_test_suite().argc; ++i) {
	std::string s = tst::master_test_suite().argv[i];
	if (s.find_first_of("stem=") == 0)
	    stem = s.substr(5, s.size()-5);
    }
    SQLizerTest s("toy.rq", stem.c_str(), "healthCare/simple/db.sql");
    BOOST_CHECK_EQUAL(s.transformed, s.ref);
}

BOOST_AUTO_TEST_CASE( bsbm_1 ) {
    RuleMapTest t("bsbm/q1.rq", "bsbm/ruleMap.rq", "bsbm/q1-db.rq");
    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
	std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
	BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
}
#endif


