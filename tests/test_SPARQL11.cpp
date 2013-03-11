/* perform SPARQL 1.1 tests.
 * call from: ..
 * files: <tests>/sparql11
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

//#define BOOST_TEST_MAIN
//#define BOOST_TEST_MODULE SPARQL11_tests
#define NEEDDEF_W3C_SW_WEBAGENT
#include "tests/SPARQLTest.hpp"
#include "tests/ServerInteraction.hpp"

#define LG(SOURCE, NAME) LabeledGraph(SOURCE, NAME)
#define SIZE(ARRAY) (sizeof(ARRAY)/sizeof(ARRAY[0]))

    namespace Initializer {
	struct ArgConsumer {
	    virtual bool operator()(int* i, int argc, char** argv) = 0;
	};
	extern std::vector<ArgConsumer*> consumers;
	void consume(int argc, char** argv);
    }; // namespace Initializer

    namespace Initializer {
	void consume (int argc, char** argv) {
	    for (int i = 0; i < argc; ++i)
		for (std::vector<ArgConsumer*>::const_iterator it = consumers.begin();
		     it != consumers.end(); ++it)
		    if ((*it)->operator()(&i, argc, argv))
			break;
	}
    } // namespace Initializer

bool prepare_test_suite () {
    boost::unit_test::framework::master_test_suite().p_name.value = "test_SPARQL11";

    int& argc = boost::unit_test::framework::master_test_suite().argc;
    char** argv = boost::unit_test::framework::master_test_suite().argv;
    Initializer::consume(argc, argv);
    return true;
}

int main (int argc, char* argv[]) {
    boost::unit_test::init_unit_test_func init_func = &prepare_test_suite;
    return ::boost::unit_test::unit_test_main( init_func, argc, argv );
}

struct EARL {
    // invocation: TEST_ARGS=--earl\ SWObjects-EARL-2012-12-16.ttl
    struct consumer : public Initializer::ArgConsumer {
	struct EARL* earl;
	consumer (struct EARL* earl) : earl(earl) {  }
	virtual bool operator() (int* i, int argc, char** argv) {
	    if (std::string("--earl") == argv[*i] && *i < argc-1) {
		earl->reportStream = new std::ofstream(argv[++*i]);
		// reportStream = &std::cout;
		std::string tester = boost::unit_test::framework::master_test_suite().p_name.value;
		if (earl->reportStream->good())
		    *earl->reportStream
			<< "# EARL report by " << boost::unit_test::framework::master_test_suite().p_name.value << "\n"
			<< "@prefix doap: <http://usefulinc.com/ns/doap#>.\n"
			<< "@prefix earl: <http://www.w3.org/ns/earl#>.\n"
			<< "@prefix foaf: <http://xmlns.com/foaf/0.1/>.\n"
			<< "@prefix swobj: <http://swobjects.org/>.\n"
			<< "@prefix dct: <http://purl.org/dc/terms/>.\n"
			<< "@prefix xsd: <http://www.w3.org/2001/XMLSchema#>.\n"
			<< "\n"
			<< "<> foaf:primaryTopic swobj:sparql ;\n"
			<< "	dct:issued \"" + w3c_sw::Util::GMTimeAs8601() + "\"^^xsd:dateTime ;\n"
			<< "	foaf:maker <http://www.w3.org/People/Eric/ericP-foaf#ericP> .\n"
			<< "\n"
			<< "swobj:sparql\n"
			<< "	a doap:Project ;\n"
			<< "	doap:name \"SWObjects\" ;\n"
			<< "	doap:homepage <http://swobjects.org/> .\n"
			<< "\n"
			<< "<http://www.w3.org/People/Eric/ericP-foaf#ericP> a foaf:Person ;\n"
			<< "	foaf:name \"Eric Prud'hommeaux\" ;\n"
			<< "	foaf:mbox <mailto:eric@w3.org> ;\n"
			<< "	foaf:mbox_sha1sum \"e2d67791b2a0ce3441c0c770f94daa130b4e6d95\" ;\n"
			<< "	foaf:homepage <http://www.w3.org/People/Eric/> .\n"
			<< "\n"
			<< "swobj:" + tester + "\n"
			<< "	a earl:Software ;\n"
			<< "	dct:title \"SWObjects SPARQL11 test harness\" ;\n"
			<< "	foaf:maker <http://www.w3.org/People/Eric/ericP-foaf#ericP> .\n"
			<< "\n"
			<< "\n";
		else
		    throw std::runtime_error(std::string() + "unable to open \"" + argv[*i] + "\"");
		return true;
	    }
	    return false;
	}
    };
    consumer theConsumer;
    std::ostream* reportStream;
    EARL () : theConsumer(this), reportStream(NULL) {
	Initializer::consumers.push_back(&theConsumer);
    }
    void report (const char* test, bool passed) {
	if (reportStream == NULL || test == NULL)
	    return;
	*reportStream <<
	    "[] a earl:Assertion ;\n"
	    "	earl:assertedBy <http://swobjects.org/" + boost::unit_test::framework::master_test_suite().p_name.value + "> ;\n"
	    "	earl:result [\n"
	    "		a earl:TestResult ;\n"
	    "		earl:outcome earl:" + (passed ? "pass" : "fail") + " ;\n"
	    "		dct:date \"" + w3c_sw::Util::GMTimeAs8601() + "\"^^xsd:dateTime\n"
	    "	] ;\n"
	    "	earl:subject <http://swobjects.org/sparql> ;\n"
	    "	earl:test <" + test + "> ." << std::endl;
    }
};

std::vector<Initializer::ArgConsumer*> Initializer::consumers;
EARL G_EARL;

#if HTTP_CLIENT != SWOb_DISABLED
  W3C_SW_WEBAGENT<> WebClient;
#else /* HTTP_CLIENT == SWOb_DISABLED */
  #warning unable to test SERVICE queries
#endif /* HTTP_CLIENT == SWOb_DISABLED */

w3c_sw_DEBUGGING_FUNCTIONS();

// Allocate distinct server port ranges to prevent conflicts in simultaneous tests.
// test_SPARQL: 9000-90ff, test_SADI: 9100-91ff, test_LWP: 9200-92ff, test_SPARQL11: 0x9300-0x93ff
#define LOWPORT 0x9300
#define HIPORT  0x93ff

BOOST_AUTO_TEST_SUITE( subselect )
BOOST_AUTO_TEST_CASE( subselect_01 ) {
    /* name: 
     * 
     */
    const char* defaultGraph( "sparql11/subselect-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/subselect-01.rq", "sparql11/subselect-01.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( subselect_02 ) {
    /* name: 
     * 
     */
    const char* defaultGraph( "sparql11/subselect-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/subselect-02.rq", "sparql11/subselect-02.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( not_not_exists ) {
    /* name: 
     * 
     */
    const char* defaultGraph( "sparql11/exists-01.ttl" );
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("sparql11/not-not-exists.rq", "sparql11/not-not-exists.srx", 0, 0);
}
BOOST_AUTO_TEST_CASE( count_star ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+--------+
| ?count |
|      3 |
+--------+
     */
    GRAPH_TEST(NULL, "sparql11/count-star.rq", "sparql11/count-star.srx");
}
BOOST_AUTO_TEST_CASE( nestedAggregates ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+--------+
| ?count |
|      3 |
+--------+
     */
    GRAPH_TEST(NULL, "sparql11/ia-nestedAggregates.rq", "sparql11/ia-nestedAggregates.srt");
}
BOOST_AUTO_TEST_CASE( count_star_groupBy_v ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+----+--------+
| ?a | ?count |
|  1 |      3 |
+----+--------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-v.rq", "sparql11/groupBy-v.srx");
}
BOOST_AUTO_TEST_CASE( count_a_groupBy_v ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+----+--------+
| ?a | ?count |
|  1 |      3 |
+----+--------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-v.rq", "sparql11/groupBy-v.srx");
}
BOOST_AUTO_TEST_CASE( groupBy_v_AS ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+----+--------+
| ?x | ?count |
|  1 |      3 |
+----+--------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-v-AS.rq", "sparql11/groupBy-v-AS.srx");
}
BOOST_AUTO_TEST_CASE( groupBy_f ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+---------+------------+----------------+
| ?bPlusC | ?sumBPlusC | ?oneMinusCount |
|      12 |         24 |             -1 |
|      15 |         15 |              0 |
+---------+------------+----------------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-f.rq", "sparql11/groupBy-f.srx");
}
BOOST_AUTO_TEST_CASE( groupBy_f_having_f ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+---------+------------+----------------+
| ?bPlusC | ?sumBPlusC | ?oneMinusCount |
|      12 |         24 |             -1 |
+---------+------------+----------------+
     */
    GRAPH_TEST(NULL, "sparql11/groupBy-f-having-f.rq", "sparql11/groupBy-f-having-f.srx");
}
BOOST_AUTO_TEST_CASE( ext_select_expr_01 ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+---------+--------------+----------------+
| ?bPlusC | "SUM(?b+?c)" | ?oneMinusCount |
|      12 |           24 |             -1 |
+---------+--------------+----------------+
     */
    // !! incompatible with final SPARQL aggregate semantics: GRAPH_TEST(NULL, "sparql11/ext_select_expr-01.rq", "sparql11/ext_select_expr-01.srt");
}
BOOST_AUTO_TEST_SUITE_END(/* subselect */)

BOOST_AUTO_TEST_SUITE( bindings_and_bind )
BOOST_AUTO_TEST_CASE( _1 ) {
    /* name: 
     * 
start
+----+----+----+
| ?a | ?b | ?c |
|  1 | 10 |  2 |
|  1 |  9 |  3 |
|  1 | 11 |  4 |
+----+----+----+
end
+----+----+----+----+
| ?a | ?b | ?c | ?d |
|  1 | 10 |  2 |  9 |
|  1 |  9 |  3 |  7 |
|  1 | 11 |  4 |  8 |
+----+----+----+----+
     */
    GRAPH_TEST(NULL, "sparql11/bind_1.rq", "sparql11/bind_1.srx");
}
BOOST_AUTO_TEST_SUITE_END(/* bind */)


BOOST_AUTO_TEST_SUITE( generators )
BOOST_AUTO_TEST_CASE( olist ) {
    const char* defaultGraph( "generators/olist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/olist.rq", "generators/olist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( slist ) {
    const char* defaultGraph( "generators/slist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/slist.rq", "generators/slist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( solist ) {
    const char* defaultGraph( "generators/solist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist ) {
    const char* defaultGraph( "generators/namedsolist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_seq ) {
    const char* defaultGraph( "generators/namedsolist_p1_p2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_p1_p2.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_inv ) {
    const char* defaultGraph( "generators/namedsolist.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_inv_p1.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_inv_seq ) {
    const char* defaultGraph( "generators/namedsolist_p1_p2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_inv__p1_p2.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_CASE( namedsolist_pp_inv_p1__p2 ) {
    const char* defaultGraph( "generators/namedsolist_inv_p1__p2.ttl");
    const char** namedGraphs = NULL;
    const URI** requires = NULL;
    DAWG_TEST("generators/solist_inv_p1__p2.rq", "generators/solist.srt", 0, 0);
}
BOOST_AUTO_TEST_SUITE_END(/* generators */)


BOOST_AUTO_TEST_SUITE( sparql11_query )
#define QUERY_TEST()							       \
    RdfDB::DynamicLoading = false;					       \
    try {								       \
	MeasuredRS measured(defaultGraph_in, namedGraphs_in,		       \
			    SIZE(namedGraphs_in), request, true);	       \
	ReferenceRS expected(measured, result, &F, &P);			       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
	G_EARL.report(test, measured == expected);			       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_query.rq -L text/raw > IMPORTED_sparql11_query.hpp 
#include "tests/IMPORTED_sparql11_query.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_query */)

BOOST_AUTO_TEST_SUITE( sparql11_update )

#define UPDATE_TEST() \
    try {								       \
	MeasuredRS measured(defaultGraph_in, namedGraphs_in,		       \
			    SIZE(namedGraphs_in), request, false);	       \
	ReferenceDB expected(defaultGraph_out, namedGraphs_out,		       \
			     SIZE(namedGraphs_out), request);		       \
	BOOST_CHECK_EQUAL(measured.d, expected);			       \
	G_EARL.report(test, measured.d == expected);			       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_CASE( construct_filter ) {
    const char* test = NULL; // disable EARL report.
    // name: ADD 1
    // manifest: data-sparql11/add/manifest.ttl
    const char* defaultGraph_in = "sparql11/dates.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "sparql11/insert_filter.ru";
    const char* defaultGraph_out = "sparql11/dates.ttl";
    LabeledGraph namedGraphs_out[] = {LG("sparql11/insert_filter-res.ttl", "sparql11/g1")};
    UPDATE_TEST();
} /* BOOST_AUTO_TEST_CASE( construct_filter ) */

// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_update.rq -L text/raw > IMPORTED_sparql11_update.hpp 
#include "tests/IMPORTED_sparql11_update.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_update */)

BOOST_AUTO_TEST_SUITE( sparql11_results_csv_tsv )

#define CSV_QUERY_TEST()		       \
    try {								       \
	MeasuredRS measured(defaultGraph_in, namedGraphs_in,		       \
			    SIZE(namedGraphs_in), request, true);	       \
	const char* type = "text/csv";		       \
	std::string asCSV = measured.toString(type);		       \
	/* w3c_sw_LINEN << "as " << type << ":\n" << asCSV; */	       \
	IStreamContext istr(asCSV, IStreamContext::STRING, type);	       \
	TTerm::String2BNode bnodeMap;				       \
	ResultSet parsed(&F, istr, measured.isOrdered(), &bnodeMap);       \
	ReferenceRS expected(measured, result, &F, &P);			       \
	/* w3c_sw_LINEN << "parsed:\n" << parsed.toString("text/sparql-results;datatypes=explicit"); */ \
	/* w3c_sw_LINEN << "expected:\n" << expected.toString("text/sparql-results;datatypes=explicit"); */ \
	BOOST_CHECK_EQUAL(parsed, expected);			       \
	G_EARL.report(test, parsed == expected);			       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_csv.rq -L text/raw > IMPORTED_sparql11_csv.hpp 
#include "tests/IMPORTED_sparql11_csv.hpp"

// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_tsv.rq -L text/raw > IMPORTED_sparql11_tsv.hpp 
#include "tests/IMPORTED_sparql11_tsv.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_results_csv_tsv */)

BOOST_AUTO_TEST_SUITE( sparql11_json )
// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_json.rq -L text/raw > IMPORTED_sparql11_json.hpp 
#include "tests/IMPORTED_sparql11_json.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_json */)

struct SPARQLServerInteractionVector : public std::vector<w3c_sw::SPARQLServerInteraction*> {
    SPARQLServerInteractionVector (LabeledGraph* services, size_t serviceCount) {
    	for (size_t i = 0; i < serviceCount; ++i) {
	    std::string handledBy = add(services[i].source, LOWPORT, HIPORT);
	    ServiceGraphPattern::ServiceMap.insert(std::make_pair(services[i].name, handledBy));
	}
    }

    ~SPARQLServerInteractionVector () {
	for (const_iterator it = begin(); it != end(); ++it) {
	    w3c_sw::SocketMessage((*it)->port, (*it)->hostIP, (*it)->path, "query=STOP");
	    delete *it;
	}
    }

    std::string add (std::string dataPath, int lowPort, int highPort) {
	SPARQLServerInteraction* s = new SPARQLServerInteraction("-d " + dataPath + " --stop STOP" /* + " --stop-after 1" */, "/SPARQL", lowPort, highPort);
	insert(end(), s);
	return s->serverURL;
    }
};

struct FederationTest {

    struct myLoader : public EvaluatedResultSet::DBLoader {
	const char* defGraph;
	myLoader (const char* defGraph) : defGraph(defGraph) {  }
	virtual void operator() (RdfDB* db) {
	    if (defGraph != NULL)
		MeasuredRS::read(defGraph, defGraph, db->ensureGraph(DefaultGraph));
	}
    };
    myLoader l;
    SPARQLServerInteractionVector servers;
    static std::string read (std::string filename) {
	std::ifstream fileis(filename.c_str()); assert (fileis.is_open());
	std::istreambuf_iterator<char> filei(fileis), filee;
	return std::string(filei, filee);
    }
    EvaluatedResultSet got;
    ReferenceRS expected;

    FederationTest (LabeledGraph* services, size_t serviceCount,
		    const char* defaultGraph_in, const char* request, const char* results)
	: l(defaultGraph_in), servers(services, serviceCount), got(&F, &WebClient, &P, read(request), &l), expected(got, results, &F, &P)
    {
    	// MeasuredRS got(defaultGraph_in, NULL, 0, request);
    	/*w3c_sw_LINEN << "in:" << (sizeof(services)/sizeof(services[0])) << " -- out:" << (sizeof(namedGraphs_out)/sizeof(namedGraphs_out[0])) << "\n"; */
    	/* w3c_sw_LINEN << got; */
    }
};

#define SERVICE_TEST()							       \
    try {								       \
	FederationTest i(services, (sizeof(services)/sizeof(services[0])),     \
			 defaultGraph_in, request, results);		       \
	BOOST_CHECK_EQUAL(i.got, i.expected);				       \
	G_EARL.report(test, i.got == i.expected);			       \
    } catch (NotImplemented& e) {					       \
    	std::cerr << e.what() << "\n";					       \
    	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
    	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
    	BOOST_ERROR ( s.what() );					       \
    }									       \


BOOST_AUTO_TEST_SUITE( sparql11_federated_query )
// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_federated_query.rq -L text/raw > IMPORTED_sparql11_federated_query.hpp 
#include "tests/IMPORTED_sparql11_federated_query.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_federated_query */)

BOOST_AUTO_TEST_SUITE( sparql11_entailment )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_entailment */)

BOOST_AUTO_TEST_SUITE( sparql11_service_description )
BOOST_AUTO_TEST_SUITE_END(/* sparql11_service_description */)

BOOST_AUTO_TEST_SUITE( sparql11_protocol )
// use http://www.w3.org/2009/sparql/protocol_validator
BOOST_AUTO_TEST_SUITE_END(/* sparql11_protocol */)

BOOST_AUTO_TEST_SUITE( sparql11_http_rdf_update )
// http://metacognition.info/gsp_validation/gsp.validator.form
BOOST_AUTO_TEST_SUITE_END(/* sparql11_http_rdf_update */)

BOOST_AUTO_TEST_SUITE( sparql11_syntax_positive )
#define POSITIVE_SYNTAX_TEST()					\
    std::string baseURI(request);				\
    baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);	\
    bool parsed = false;					\
    try {							\
	IStreamContext istr(request, IStreamContext::FILE);	\
	sparqlParser.setBase(baseURI);				\
	delete sparqlParser.parse(istr);			\
	sparqlParser.clear(BASE_URI);				\
	parsed = true;						\
    } catch (...) {						\
    }								\
    BOOST_CHECK(parsed);					\
    G_EARL.report(test, parsed);				\

// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_syntax_positive.rq -L text/raw > IMPORTED_sparql11_syntax_positive.hpp 
#include "tests/IMPORTED_sparql11_syntax_positive.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_syntax_positive */)

BOOST_AUTO_TEST_SUITE( sparql11_syntax_negative )
#define NEGATIVE_SYNTAX_TEST()					\
    std::string baseURI(request);				\
    baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);	\
    bool parsed = false;					\
    try {							\
	IStreamContext istr(request, IStreamContext::FILE);	\
	sparqlParser.setBase(baseURI);				\
	delete sparqlParser.parse(istr);			\
	sparqlParser.clear(BASE_URI);				\
	parsed = true;						\
    } catch (...) {						\
    }								\
    BOOST_CHECK(!parsed);					\
    G_EARL.report(test, !parsed);				\

// update with: LD_LIBRARY_PATH=/usr/local/instantclient_11_2/:/home/eric/checkouts/libbooost.inst/lib/:../boost-log-1.46/stage/lib ../bin/sparql --get-graph-arguments true -d data-sparql11/manifest-all.ttl IMPORTED_sparql11_syntax_negative.rq -L text/raw > IMPORTED_sparql11_syntax_negative.hpp 
#include "tests/IMPORTED_sparql11_syntax_negative.hpp"
BOOST_AUTO_TEST_SUITE_END(/* sparql11_syntax_negative */)

// EOF

