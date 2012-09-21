/* test_SPARQL.cpp - test the ../bin/SPARQL executable
 *
 * $Id: test_SPARQL.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#define NEEDDEF_W3C_SW_SAXPARSER
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "ServerInteraction.hpp"

#define BOOST_TEST_MODULE SPARQL
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,Process:3"

w3c_sw::AtomFactory F;

// Allocate distinct server port ranges to prevent conflicts in simultaneous tests.
// test_SPARQL: 9000-90ff, test_SADI: 9100-91ff, test_LWP: 9200-92ff
#define LOWPORT 0x9000
#define HIPORT  0x90ff

const char* Doutput =
    "+----+---------------------------------------------------+----------------------------------------+\n"
    "| ?s | ?p                                                | ?o                                     |\n"
    "| <> |           <http://usefulinc.com/ns/doap#homepage> |           <http://swobj.org/sparql/v1> |\n"
    "| <> | <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
    "| <> |          <http://usefulinc.com/ns/doap#shortdesc> |         'a semantic web query toolbox' |\n"
    "+----+---------------------------------------------------+----------------------------------------+\n";

const char* Dwide =
    "+----+---------------------------------------------------+----------------------------------------+-----------------------------------------+\n"
    "| ?s | ?p                                                | ?o                                     | ?o2                                     |\n"
    "| <> | <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> | <http://usefulinc.com/ns/doap#Project> | <http://usefulinc.com/ns/doap#Project2> |\n"
    "| <> |          <http://usefulinc.com/ns/doap#shortdesc> |         'a semantic web query toolbox' |         'a semantic web query toolbox2' |\n"
    "+----+---------------------------------------------------+----------------------------------------+-----------------------------------------+\n";

const char* Dshort = 
    "| ?s | ?p                                                | ?o                                     |\n"
    "| <> | <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
    "| <> |          <http://usefulinc.com/ns/doap#shortdesc> |         'a semantic web query toolbox' |\n"
    "| <> |           <http://usefulinc.com/ns/doap#homepage> |           <http://swobj.org/sparql/v1> |";

const char* Dtrig = 
    "{\n"
    "  <> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://usefulinc.com/ns/doap#Project> .\n"
    "  <> <http://usefulinc.com/ns/doap#homepage> <http://swobj.org/sparql/v1> .\n"
    "  <> <http://usefulinc.com/ns/doap#shortdesc> \"a semantic web query toolbox\"  .\n"
    "}\n";

const char* Dturtle =
    "<> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://usefulinc.com/ns/doap#Project> .\n"
    "<> <http://usefulinc.com/ns/doap#homepage> <http://swobj.org/sparql/v1> .\n"
    "<> <http://usefulinc.com/ns/doap#shortdesc> \"a semantic web query toolbox\" .\n";

const char* Dturtle_percentEscaped =
    "%7B%0A%20%20%3C%3E%20%3Chttp%3A%2F%2Fwww.w3.org%2F1999%2F02%2F22-rdf-syntax-ns%23type%3E%20%3Chttp%3A%2F%2Fusefulinc.com%2Fns%2Fdoap%23Project%3E%20.%0A"
    "%20%20%3C%3E%20%3Chttp%3A%2F%2Fusefulinc.com%2Fns%2Fdoap%23homepage%3E%20%3Chttp%3A%2F%2Fswobj.org%2Fsparql%2Fv1%3E%20.%0A"
    "%20%20%3C%3E%20%3Chttp%3A%2F%2Fusefulinc.com%2Fns%2Fdoap%23shortdesc%3E%20%22a%20semantic%20web%20query%20toolbox%22%20%20.%0A%7D";

const char* Dturtle_base64encoded =
    "PD4gPGh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyN0eXBlPiA8aHR0cDovL3VzZWZ1bGluYy5jb20vbnMvZG9hcCNQcm9qZWN0PiAuC"
    "jw+IDxodHRwOi8vdXNlZnVsaW5jLmNvbS9ucy9kb2FwI2hvbWVwYWdlPiA8aHR0cDovL3N3b2JqLm9yZy9zcGFycWwvdjE+IC4K"
    "PD4gPGh0dHA6Ly91c2VmdWxpbmMuY29tL25zL2RvYXAjc2hvcnRkZXNjPiAiYSBzZW1hbnRpYyB3ZWIgcXVlcnkgdG9vbGJveCIgLgo=";

const char* Dturtle_encodedEscaped =
    "PD4gPGh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyN0eXBlPiA8aHR0cDovL3VzZWZ1bGluYy5jb20vbnMvZG9hcCNQcm9qZWN0PiAuC"
    "jw%2BIDxodHRwOi8vdXNlZnVsaW5jLmNvbS9ucy9kb2FwI2hvbWVwYWdlPiA8aHR0cDovL3N3b2JqLm9yZy9zcGFycWwvdjE%2BIC4K"
    "PD4gPGh0dHA6Ly91c2VmdWxpbmMuY29tL25zL2RvYXAjc2hvcnRkZXNjPiAiYSBzZW1hbnRpYyB3ZWIgcXVlcnkgdG9vbGJveCIgLgo%3D";

/** ExecResults - get output from process did not return an error.
 */
struct ExecResults : public w3c_sw::OutputFromNonInteractiveProcess {
    ExecResults (const std::string cmd) : w3c_sw::OutputFromNonInteractiveProcess(cmd) {
	BOOST_REQUIRE(w3c_sw::SigChildGuard::ChildRetSet == false ||	// if child has finished,
		      w3c_sw::SigChildGuard::ChildRet == 0);		// make sure it returned 0.
    }
};

struct TableResultSet : public w3c_sw::ResultSet {
    TableResultSet (w3c_sw::AtomFactory* atomFactory, std::string srt, bool ordered, w3c_sw::TTerm::String2BNode* bnodeMap) : 
	ResultSet(atomFactory) {
	erase(begin());
	w3c_sw::IStreamContext sptr(srt.c_str(), w3c_sw::IStreamContext::STRING, "text/sparql-results");
	parseTable(sptr, ordered, bnodeMap);
    }
};

struct BooleanResultSet : public w3c_sw::ResultSet {
    BooleanResultSet (w3c_sw::AtomFactory* atomFactory, bool b) : 
	ResultSet(atomFactory) {
	resultType = RESULT_Boolean;
	if (!b)
	    erase(begin());
    }
};

BOOST_AUTO_TEST_SUITE( tutorial )
BOOST_AUTO_TEST_CASE( D ) {
    ExecResults tested("../bin/sparql -D");
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( D_trig ) {
    ExecResults tested("../bin/sparql -D -L text/trig");
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( D_turtle ) {
    ExecResults tested("../bin/sparql -D -L text/turtle");
    BOOST_CHECK_EQUAL(tested.s, Dturtle);
}
BOOST_AUTO_TEST_CASE( D_spo ) {
    ExecResults invocation("../bin/sparql -D -e \"SELECT ?s ?p ?o WHERE {?s ?p ?o}\"");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, Doutput, false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( D_spo_utf8 ) {
    ExecResults invocation("../bin/sparql -D -8 -e \"SELECT ?s ?p ?o WHERE {?s ?p ?o}\"");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, Doutput, false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( G_spo ) {
    ExecResults invocation("../bin/sparql -G foo -e \"SELECT ?s ?p ?o WHERE { GRAPH <foo> { ?s ?p ?o } }\"");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, Doutput, false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( DG_sp ) {
    ExecResults invocation("../bin/sparql -a -DG foo -G foo2 -e \"SELECT ?g {\n"
		       "    GRAPH ?g {?s ?p <http://usefulinc.com/ns/doap#Project>}}\"");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+--------+\n"
		 "| ?g     |\n"
		 "|  <foo> |\n"
		 "| <foo2> |\n"
		 "+--------+\n", 
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( DG_sp_U_sp ) {
    ExecResults invocation("../bin/sparql -a -DG foo -G foo2 -e \"SELECT ?g {\n"
			   "        {?s ?p <http://usefulinc.com/ns/doap#Project>}\n"
			   "    UNION\n"
			   "        {GRAPH ?g{?s ?p <http://usefulinc.com/ns/doap#Project>}}}\"\n");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+--------+\n"
		 "| ?g     |\n"
		 "|     -- |\n"
		 "|  <foo> |\n"
		 "| <foo2> |\n"
		 "+--------+\n", 
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( data_uri ) {
    ExecResults tested(std::string() + "../bin/sparql -d 'data:text/trig," + Dturtle_percentEscaped + "'");
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_unencoded ) {
    std::string s = std::string() + "../bin/sparql -d 'data:text/turtle," + Dturtle + "'";
    ExecResults tested(s);
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_charset ) {
    ExecResults tested(std::string() + "../bin/sparql -d 'data:text/trig;charset=UTF-8," + Dturtle_percentEscaped + "'");
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_unencoded_charset ) {
    std::string s = std::string() + "../bin/sparql -d 'data:text/turtle;charset=UTF-8," + Dturtle + "'";
    ExecResults tested(s);
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_base64 ) {
    ExecResults tested(std::string() + "../bin/sparql -d 'data:text/turtle;base64," + Dturtle_encodedEscaped + "'");
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_unencoded_base64 ) {
    std::string s = std::string() + "../bin/sparql -d 'data:text/turtle;base64," + Dturtle_base64encoded + "'";
    ExecResults tested(s);
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_charset_base64 ) {
    ExecResults tested(std::string() + "../bin/sparql -d 'data:text/turtle;charset=UTF-8;base64," + Dturtle_encodedEscaped + "'");
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( data_uri_unencoded_charset_base64 ) {
    std::string s = std::string() + "../bin/sparql -d 'data:text/turtle;charset=UTF-8;base64," + Dturtle_base64encoded + "'";
    ExecResults tested(s);
    BOOST_CHECK_EQUAL(tested.s, Dtrig);
}
BOOST_AUTO_TEST_CASE( map_noG ) {
    ExecResults invocation("../bin/sparql -d 'data:text/trig, { <s1> <p1> <o1>, \"o2\" }' -M 'CONSTRUCT { ?s <p2> ?o } WHERE { ?s <p1> ?o }' -e 'SELECT ?s ?o WHERE { ?s ?p ?o }'");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+------+------+\n"
		 "| ?s   | ?o   |\n"
		 "| <s1> | 'o2' |\n"
		 "| <s1> | <o1> |\n"
		 "+------+------+\n",
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( map_bodyG ) {
    ExecResults invocation("../bin/sparql -d 'data:text/trig, <g1> { <s1> <p1> <o1>, \"o2\" }' -M 'CONSTRUCT { ?s <p2> ?o } WHERE { GRAPH <g1> { ?s <p1> ?o } }' -e 'SELECT ?s ?o WHERE { ?s ?p ?o }'");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+------+------+\n"
		 "| ?s   | ?o   |\n"
		 "| <s1> | 'o2' |\n"
		 "| <s1> | <o1> |\n"
		 "+------+------+\n",
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( map_headG ) {
    ExecResults invocation("../bin/sparql -d 'data:text/trig, { <s1> <p1> <o1>, \"o2\" }' -M 'CONSTRUCT { GRAPH <g2> { ?s <p2> ?o } } WHERE { ?s <p1> ?o }' -e 'SELECT ?s ?o WHERE { GRAPH <g2> { ?s ?p ?o } }'");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+------+------+\n"
		 "| ?s   | ?o   |\n"
		 "| <s1> | 'o2' |\n"
		 "| <s1> | <o1> |\n"
		 "+------+------+\n",
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_SUITE_END(/* tutorial */)

#ifdef FIXED_SPARQL_ARGS_ORDER // !!!
/* sensitivity to position of -b directive */
BOOST_AUTO_TEST_CASE( Dbe ) {
    ExecResults tested("../bin/sparql -D -b http://foo.example/ -e \"SELECT * WHERE { <> a ?t}\"");
    BOOST_CHECK_EQUAL(tested.s, 
		      "+\n"
		      "|\n"
		      "+\n");
}
#endif

/* make sure we fail mis-matches */
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001_002 ) {
    ExecResults tested("../bin/sparql -d data-r2/triple-match/data-01.ttl data-r2/triple-match/dawg-tp-01.rq --compare-as-result-set data-r2/triple-match/result-tp-02.ttl");
    BOOST_CHECK_EQUAL(tested.s, 
		      "+-----------------------------+------------------------------+\n"
		      "| ?p                          | ?q                           |\n"
		      "| <http://example.org/data/p> | <http://example.org/data/v1> |\n"
		      "| <http://example.org/data/p> | <http://example.org/data/v2> |\n"
		      "+-----------------------------+------------------------------+\n"
		      "!=\n"
		      "+------------------------------+-----------------------------+\n"
		      "| ?q                           | ?x                          |\n"
		      "| <http://example.org/data/v2> | <http://example.org/data/x> |\n"
		      "| <http://example.org/data/v1> | <http://example.org/data/x> |\n"
		      "+------------------------------+-----------------------------+\n"
		      "\n");
}

BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001 ) {
    ExecResults tested("../bin/sparql -d data-r2/triple-match/data-01.ttl data-r2/triple-match/dawg-tp-01.rq --compare-as-result-set data-r2/triple-match/result-tp-01.ttl");
    BOOST_CHECK_EQUAL(tested.s, 
		      "matched\n");
}

BOOST_AUTO_TEST_CASE( insert ) {
    ExecResults tested("../bin/sparql -d sparul/g_12_12.trig -e \"INSERT { ?g ?y 3 } WHERE  { GRAPH ?g  { ?x ?y ?z } }\"");
    BOOST_CHECK_EQUAL(tested.s, 
		      "{\n"
		      "  <sparul/g> <sparul/y> 1  .\n"
		      "  <sparul/g> <sparul/y> 2  .\n"
		      "  <sparul/g> <sparul/y> 3  .\n"
		      "}\n"
		      "<sparul/g> {\n"
		      "  <sparul/x> <sparul/y> 1  .\n"
		      "  <sparul/x> <sparul/y> 2  .\n"
		      "}\n");
}

BOOST_AUTO_TEST_CASE( construct ) {
    ExecResults tested("../bin/sparql -d sparul/g_12_12.trig -e \"CONSTRUCT { ?g ?y 3 } WHERE  { GRAPH ?g  { ?x ?y ?z } }\"");
    BOOST_CHECK_EQUAL(tested.s, 
		      "{\n"
		      "  <sparul/g> <sparul/y> 3  .\n"
		      "}\n");
}

BOOST_AUTO_TEST_CASE( bool_no_base ) {
    ExecResults tested("../bin/sparql -b '' -d SPARQL/rel.ttl SPARQL/rel.rq");
    BOOST_CHECK_EQUAL(tested.s, 
		      "true\n");
}

BOOST_AUTO_TEST_CASE( bool_base_0 ) {
    ExecResults tested("../bin/sparql -b http://foo.example/ -d SPARQL/rel.ttl SPARQL/rel.rq");
    BOOST_CHECK_EQUAL(tested.s, 
		      "true\n");
}

BOOST_AUTO_TEST_CASE( bool_base_1 ) {
    ExecResults tested("../bin/sparql -d SPARQL/rel.ttl -b http://foo.example/ SPARQL/rel.rq");
    BOOST_CHECK_EQUAL(tested.s, 
		      "false\n");
}

#ifdef FIXED_CORRUPTION_FROM_DL_LOAD
BOOST_AUTO_TEST_CASE( function_library ) {
    ExecResults invocation("../bin/sparql --function-library ../examples/functionExtension.so"
			   " -d \"data:text/csv,x,y\n<foo>,\\\"bar\\\"\""
			   " -e \"SELECT (<tag:eric@w3.org,2012-swobjfunc/chatty_concat>"
					   "('a', STR(?x), 'b', ?y) AS ?t) {}\"");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+--------------------------------------------------------------+\n"
		 "| ?t                                                           |\n"
		 "| \"CONCAT(\\\"a\\\", \\\"foo\\\", \\\"b\\\", \\\"bar\\\") yields \\\"afoobbar\\\"\" |\n"
		 "+--------------------------------------------------------------+\n",
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
#endif /* FIXED_CORRUPTION_FROM_DL_LOAD */

// e.g. PARSE_RESULTS("SPARQL/D.srt", Doutput)
#define PARSE_RESULTS(TEST, EXPECT) \
    w3c_sw::TTerm::String2BNode bnodeMap;			\
    ExecResults cat("../bin/sparql -d " TEST);			\
    TableResultSet cat_measured(&F, cat.s, false, &bnodeMap);	\
    TableResultSet cat_expected(&F, EXPECT, false, &bnodeMap);	\
    BOOST_CHECK_EQUAL(cat_measured, cat_expected);

// e.g. CREATE_RESULTS("-l sparqlx", "SPARQL/Dt.srx", Doutput)
#define CREATE_RESULTS(OUTSPEC, OUTPATH, EXPECT) \
    w3c_sw::TTerm::String2BNode bnodeMap;			\
    ExecResults creation("../bin/sparql -D -e \"SELECT*{?s ?p ?o}\" " OUTSPEC " -o " OUTPATH); \
    BOOST_CHECK_EQUAL(creation.s, "");				\
    ExecResults cat("../bin/sparql -d " OUTPATH);		\
    TableResultSet cat_measured(&F, cat.s, false, &bnodeMap);	\
    TableResultSet cat_expected(&F, EXPECT, false, &bnodeMap);	\
    BOOST_CHECK_EQUAL(cat_measured, cat_expected);

BOOST_AUTO_TEST_SUITE( parseResults )
BOOST_AUTO_TEST_CASE( resultsFormat ) {
    {   /* Create an simple table dump. */
	ExecResults creation("../bin/sparql -D -e \"SELECT*{?s ?p ?o}\" -o SPARQL/Dt.srt");
	BOOST_CHECK_EQUAL(creation.s, "");
    }
}
BOOST_AUTO_TEST_CASE( table ) { PARSE_RESULTS("SPARQL/D.srt", Doutput) }
BOOST_AUTO_TEST_CASE( flat_text ) { PARSE_RESULTS("SPARQL/D.txt", Doutput) }
BOOST_AUTO_TEST_CASE( tab_separated ) { PARSE_RESULTS("SPARQL/D.tsv", Doutput) }
BOOST_AUTO_TEST_CASE( comma_separated ) { PARSE_RESULTS("SPARQL/D.csv", Doutput) }
BOOST_AUTO_TEST_CASE( xml ) { PARSE_RESULTS("SPARQL/D.srx", Doutput) }
BOOST_AUTO_TEST_CASE( json ) { PARSE_RESULTS("SPARQL/D.srj", Doutput) }
BOOST_AUTO_TEST_SUITE( create )
BOOST_AUTO_TEST_CASE( srt_   ) { CREATE_RESULTS("", "SPARQL/Dt.srt", Doutput) } // srt is the default results output format
BOOST_AUTO_TEST_CASE( srt_l1 ) { CREATE_RESULTS("-l ''", "SPARQL/Dt.srt", Doutput) }
BOOST_AUTO_TEST_CASE( srt_l2 ) { CREATE_RESULTS("-l sparqlt", "SPARQL/Dt.srt", Doutput) }
BOOST_AUTO_TEST_CASE( srt_l3 ) { CREATE_RESULTS("-l srt", "SPARQL/Dt.srt", Doutput) }
BOOST_AUTO_TEST_CASE( srt_L  ) { CREATE_RESULTS("-L text/sparql-results", "SPARQL/Dt.srt", Doutput) }
BOOST_AUTO_TEST_CASE( srx_l1 ) { CREATE_RESULTS("-l sparqlx", "SPARQL/Dt.srx", Doutput) }
BOOST_AUTO_TEST_CASE( srx_l2 ) { CREATE_RESULTS("-l srx", "SPARQL/Dt.srx", Doutput) }
BOOST_AUTO_TEST_CASE( srx_L  ) { CREATE_RESULTS("-L application/sparql-results+xml", "SPARQL/Dt.srx", Doutput) }
BOOST_AUTO_TEST_CASE( srj_l1 ) { CREATE_RESULTS("-l sparqlj", "SPARQL/Dt.srj", Doutput) }
BOOST_AUTO_TEST_CASE( srj_l2 ) { CREATE_RESULTS("-l srj", "SPARQL/Dt.srj", Doutput) }
BOOST_AUTO_TEST_CASE( srj_L  ) { CREATE_RESULTS("-L application/sparql-results+json", "SPARQL/Dt.srj", Doutput) }
BOOST_AUTO_TEST_CASE( csv_l  ) { CREATE_RESULTS("-l csv", "SPARQL/Dt.csv", Doutput) }
BOOST_AUTO_TEST_CASE( csv_L  ) { CREATE_RESULTS("-L text/csv", "SPARQL/Dt.csv", Doutput) }
BOOST_AUTO_TEST_CASE( tsv_l  ) { CREATE_RESULTS("-l tsv", "SPARQL/Dt.tsv", Doutput) }
BOOST_AUTO_TEST_CASE( tsv_L  ) { CREATE_RESULTS("-L text/tab-separated-values", "SPARQL/Dt.tsv", Doutput) }
BOOST_AUTO_TEST_SUITE_END(/* parseResults/create */)
BOOST_AUTO_TEST_CASE( merge ) { PARSE_RESULTS("SPARQL/D.srt -d SPARQL/E.srt", Dwide) } // works 'cause p1 is concatonated to execution string.
BOOST_AUTO_TEST_CASE( SRJ_note ) {
    w3c_sw::TTerm::String2BNode bnodeMap;
    ExecResults join("../bin/sparql -d SPARQL/note.srj");
    TableResultSet join_measured(&F, join.s, false, &bnodeMap);
    w3c_sw::IStreamContext istr("SPARQL/note.srj", w3c_sw::IStreamContext::FILE);
    w3c_sw::ResultSet join_expected(&F, istr, false, &bnodeMap);
    BOOST_CHECK_EQUAL(join_measured, join_expected);
}
BOOST_AUTO_TEST_SUITE_END(/* parseResults */)


BOOST_AUTO_TEST_CASE( resultsInSparql ) {
    w3c_sw::TTerm::String2BNode bnodeMap; // share, not used for these tests.
    {
	ExecResults join("../bin/sparql SPARQL/redundantRows.rq");
	TableResultSet join_measured(&F, join.s, false, &bnodeMap);
	TableResultSet
	    join_expected(&F, 
			  "+----+----+\n"
			  "| ?X | ?Z |\n"
			  "|  1 |  3 |\n"
			  "|  1 |  3 |\n"
			  "|  1 |  3 |\n"
			  "|  1 |  3 |\n"
			  "|  2 |  4 |\n"
			  "+----+----+\n", 
			  false, &bnodeMap);
	BOOST_CHECK_EQUAL(join_measured, join_expected);
    }
    {
	ExecResults join("../bin/sparql SPARQL/fiveForms.rq");
	TableResultSet join_measured(&F, join.s, false, &bnodeMap);
	TableResultSet
	    join_expected(&F, 
			  "+----+----+----+----+----+----+\n"
			  "| ?A | ?B | ?C | ?D | ?E | ?X |\n"
			  "|  2 |  3 |  3 |  3 |  5 |  1 |\n"
			  "|  2 |  3 |  3 |  3 |  6 |  1 |\n"
			  "|  2 |  3 |  3 |  3 |  5 |  1 |\n"
			  "|  2 |  3 |  3 |  3 |  6 |  1 |\n"
			  "+----+----+----+----+----+----+\n", 
			  false, &bnodeMap);
	BOOST_CHECK_EQUAL(join_measured, join_expected);
    }
}

BOOST_AUTO_TEST_CASE( GRDDL0 ) {
    ::setenv("XSLT", "/usr/bin/xsltproc %STYLESHEET %DATA", 1);
    ::setenv("XML_CATALOG_FILES", "xml/catalog.xml", 1);
    ExecResults invocation("../bin/sparql -d SPARQL/GRDDL0.html -e 'SELECT ?fam {?s <http://xmlns.com/foaf/0.1/family_name> ?fam}'");
    w3c_sw::TTerm::String2BNode bnodeMap;
    TableResultSet tested(&F, invocation.s, false, &bnodeMap);
    TableResultSet
	expected(&F, 
		 "+-----------------+\n"
		 "| ?fam            |\n"
		 "| \"Prud'hommeaux\" |\n"
		 "+-----------------+\n", 
		 false, &bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
    ::unsetenv("XSLT");
}

BOOST_AUTO_TEST_CASE( escapes ) {
    ExecResults tested("../bin/sparql -d SPARQL/escape.trig");
    BOOST_CHECK_EQUAL(tested.s, 
		      "{\n"
		      "  <SPARQL/s> <SPARQL/p> \"as\\r\\n\\b\\t\\\"'\\\\df\"  .\n"
		      "}\n");
}

#if XML_PARSER != SWOb_DISABLED
W3C_SW_SAXPARSER P;

BOOST_AUTO_TEST_CASE( empty_ask ) {
    ExecResults invocation("../bin/sparql -e 'ASK {}' -l sparqlx");
    w3c_sw::IStreamContext sptr(invocation.s, w3c_sw::IStreamContext::STRING, "application/sparql-results+xml");
    w3c_sw::ResultSet tested(&F, &P, sptr);
    BooleanResultSet expected(&F, true);
    BOOST_CHECK_EQUAL(tested, expected);
}
#endif /* XML_PARSER != SWOb_None */

BOOST_AUTO_TEST_CASE( empty_construct ) {
    ExecResults tested("../bin/sparql -e 'CONSTRUCT {} {}'");
    BOOST_CHECK_EQUAL(tested.s, 
		      "{\n"
		      "}\n");
}


struct ServerTableQuery : w3c_sw::SPARQLClientServerInteraction {
    w3c_sw::ResultSet expected, got;

    ServerTableQuery (std::string serverParams,
		      std::string clientParams,
		      std::string expectedStr)
	: w3c_sw::SPARQLClientServerInteraction (serverParams, "/SPARQL", clientParams, LOWPORT, HIPORT),
	  expected(&F), got(&F)
    {
	w3c_sw::TTerm::String2BNode cliNodes, srvNodes;
	w3c_sw::IStreamContext clientIS(clientS, w3c_sw::IStreamContext::STRING, "text/sparql-results");
	// w3c_sw_LINEN << "clientS: " << clientS << std::endl;
	got = w3c_sw::ResultSet(&F, clientIS, false, &cliNodes);
	// w3c_sw_LINEN << "got:\n" << got << std::endl;
	w3c_sw::IStreamContext expectedIS(expectedStr, w3c_sw::IStreamContext::STRING, "text/sparql-results");
	// w3c_sw_LINEN << "expected: " << expectedStr << std::endl;
	expected = w3c_sw::ResultSet(&F, expectedIS, false, &srvNodes);
	// w3c_sw_LINEN << "expected:\n" << expected << std::endl;
    }
};

/* Simple SELECT.
 */
BOOST_AUTO_TEST_CASE( D_SELECT_SPO ) {
    ServerTableQuery i("-D --once",
		       "-e 'SELECT ?s ?p ?o WHERE { ?s ?p ?o}'", Dshort);
    BOOST_CHECK_EQUAL(i.expected, i.got);
}

/* SELECT with results in utf-8 box chars.
 */
BOOST_AUTO_TEST_CASE( D_8SELECT_SPO ) {
    ServerTableQuery i("-D --once",
		       "-8e 'SELECT ?s ?p ?o WHERE { ?s ?p ?o}'", Dshort);
    BOOST_CHECK_EQUAL(i.expected, i.got);
}

/* POSTed SELECT.
 */
BOOST_AUTO_TEST_CASE( D_post_SELECT_SPO ) {
    ServerTableQuery i("-D --once",
		       "--post -e 'SELECT ?s ?p ?o WHERE { ?s ?p ?o}'", Dshort);
    BOOST_CHECK_EQUAL(i.expected, i.got);
}


struct HttpServerInteraction : w3c_sw::SPARQLServerInteraction {
    int clientfd;

    HttpServerInteraction (std::string serverParams,
			   std::string query)
	: w3c_sw::SPARQLServerInteraction (serverParams, "/SPARQL", LOWPORT, HIPORT)
    {
	sockaddr_in remote;
	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr = inet_addr(hostIP.c_str());
	remote.sin_port = htons(port);

	clientfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(clientfd != -1);

	if (connect(clientfd, (struct sockaddr *) &remote, sizeof(remote)) < 0) {
	    std::stringstream ss;
	    ss << "failed to connect to "
	       << hostIP << ":" << port << " - error: " << strerror(errno);
	    throw ss.str();
	}

	std::stringstream reqSS;
	reqSS << "POST " << path << " HTTP/1.1\r\n"
	      << "Host: localhost:" << port << "\r\n"
	      << "Content-Length: " << query.size() << "\r\n"
	      << "Content-Type: application/x-www-form-urlencoded\r\n"
	      << "\r\n"
	      << query;

	std::string req = reqSS.str();
	const char* ptr = req.c_str();
	for (size_t i = 0; i < req.size(); ) {
	    ssize_t wrote = write(clientfd, ptr+i, req.size() - i);
	    if (wrote == -1) {
		std::stringstream ss;
		ss << "failed to write " << req.size() - i << " bytes to "
		   << hostIP << ":" << port << " - error: " << strerror(errno);
		throw ss.str();
	    }
	    i += wrote;
	}
    }

    ~HttpServerInteraction () {
	close(clientfd);
	// if (pclose(serverPipe) == -1 && errno != ECHILD)
	//     throw std::string() + "pclose(server pipe)" + strerror(errno);
	// Could call
	//   readToExhaustion(serverPipe, serverS, "server pipe");
	// but there's no reason to read from serverPipe.
    }
};

/* POSTed STOP.
 */
BOOST_AUTO_TEST_CASE( D_post_STOP ) {
    HttpServerInteraction i("-D --stop STOP", "query=STOP");
    std::string response;
    char line[80];
    for (;;) {
	ssize_t red = read(i.clientfd, line, sizeof line);
	if (red == 0)
	    break;
	if (red < 0) {
		std::stringstream ss;
		ss << "failed to read " << (sizeof line) << " bytes from "
		   << i.hostIP << ":" << i.port << " - error: " << strerror(errno);
		throw ss.str();
	}
	response += std::string(line, red);
    }
    BOOST_CHECK_EQUAL(response.substr(0, 15), "HTTP/1.0 200 OK");
    BOOST_CHECK(response.find("Done!") != std::string::npos);
}


#include "TrigSParser/TrigSParser.hpp"

struct ServerGraphQuery : w3c_sw::SPARQLClientServerInteraction {
    w3c_sw::RdfDB expected, got;

    ServerGraphQuery (std::string serverParams,
		      std::string clientParams,
		      std::string expectedStr)
	: w3c_sw::SPARQLClientServerInteraction(serverParams, "/SPARQL", clientParams, LOWPORT, HIPORT)
    {
	{
	    std::stringstream tss(clientS);
	    w3c_sw::IStreamContext tstream ("got:", tss, "text/trig");
	    w3c_sw::TrigSDriver parser("", &F);
	    parser.parse(tstream, &got, NULL);
	}

	{
	    std::stringstream ess (expectedStr);
	    w3c_sw::IStreamContext estream ("expected:", ess, "text/trig");
	    w3c_sw::TrigSDriver parser(serverURL, &F);
	    parser.parse(estream, &expected, NULL);
	}
    }
};

/* Simple CONSTRUCT.
 */
BOOST_AUTO_TEST_CASE( D_CONSTRUCT_SPO ) {
    ServerGraphQuery i("-D --once",
		       "-e 'CONSTRUCT { ?s ?p ?o } WHERE { ?s ?p ?o}'",
		       Dtrig);
    BOOST_CHECK_EQUAL(i.expected, i.got);
}


#if 0
#if THREADING != SWOb_DISABLED

#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>
 
struct Agent {
    std::string exec;
    std::string& s;

    Agent(std::string exec, std::string& s) : exec(exec), s(s) { }

    void operator()()
    {
	ExecResults tested(exec.c_str());
	s = tested.s;
    }
};

    int port = 31533;
    std::string serverURL;
    {
	std::stringstream ss;
	ss << "http://localhost:" << port << "/SPARQL";
	serverURL = ss.str();
    }

    std::string exe = "../bin/sparql";

    std::string serverS;
    boost::thread server(Agent(exe + " -D --once"
			       " --serve " + serverURL,
			       serverS));
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;
    ::sleep(1);
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;
    ::sleep(3);
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;
    ::sleep(5);
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;
    std::string clientS;
    boost::thread client(Agent(exe + " --service " + serverURL +
			       " -e 'CONSTRUCT { ?s ?p ?o } WHERE { ?s ?p ?o}'",
			       clientS));
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;
    client.join();
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;
    server.join();
    w3c_sw_LINEN << "serverS: " << serverS << std::endl;

    w3c_sw::RdfDB expected, got;
    {
	std::stringstream tss(clientS);
	w3c_sw::IStreamContext tstream ("got:", tss, "text/trig");
	w3c_sw::TrigSDriver parser("", &F);
	parser.parse(tstream, &got, NULL);
    }

    {
	std::stringstream ess(Dtrig);
	w3c_sw::IStreamContext estream ("expected:", ess, "text/trig");
	w3c_sw::TrigSDriver parser(serverURL, &F);
	parser.parse(estream, &expected, NULL);
    }
#endif /* THREADING != SWOb_DISABLED */
#endif /* 0 */

#if 0
struct NetCatInteraction {
    std::string clientS, serverS, serverURL;

    NetCatInteraction (std::string serverParams,
		       std::string clientParams) {
	int port = 3333;
	{
	    std::stringstream ss;
	    ss << port;
	    serverURL = ss.str();
	}

	std::string exe = "/bin/nc";

	std::string serverCmd("/bin/echo -e line1\\\\nline2 | (sleep 3 && echo starting && "
			      + exe + " " + serverParams + 
			      " -l " + serverURL +")");

	char line[800];

	FILE *serverPipe = popen(serverCmd.c_str(), "r");
	if (serverPipe == NULL)
	    throw std::string("popen") + strerror(errno);

	if (fgets(line, sizeof line, serverPipe) == NULL ||
	    strcmp("starting\n", line))
	    throw std::string("server didn't print a status line");
	serverS += line;

	std::string clientCmd(exe + " 127.0.0.1 " + serverURL + "  && echo done");
	w3c_sw_LINEN << "serverCmd: " << serverCmd << std::endl;
	w3c_sw_LINEN << "clientCmd: " << clientCmd << std::endl;
	FILE *clientPipe = popen(clientCmd.c_str(), "r");

	int& argc = boost::unit_test::framework::master_test_suite().argc;
	char** argv = boost::unit_test::framework::master_test_suite().argv;
	w3c_sw_LINEN << "argc: " << argc << "\n";
	for (int i = 1; i < argc; ++i)
	    if (std::string("sleep") == argv[i])
		sleep(1);

	if (fgets(line, sizeof line, clientPipe) == NULL)
	    throw std::string("client was speechless");
	clientS += line;

	w3c_sw_LINEN << "clientS: " << clientS << std::endl;

	while (fgets(line, sizeof line, clientPipe) != NULL)
	    clientS += line;
	w3c_sw_LINEN << "clientS: " << clientS << std::endl;
	if (pclose(clientPipe) == -1 && errno != ECHILD)
	    throw std::string("pclose") + strerror(errno);

	while (fgets(line, sizeof line, serverPipe) != NULL)
	    serverS += line;
	if (pclose(serverPipe) == -1 && errno != ECHILD)
	    throw std::string("pclose") + strerror(errno);
    }
};

int toy (int argc, char* argv[]) {
    char line[80];
    FILE* server = popen("/bin/echo -e line1\\\\nline2 | (sleep 3 && echo starting && nc -l 3333)", "r");
    if (fgets(line, sizeof line, server) == NULL ||
	strcmp("starting\n", line)) {
	fprintf(stderr, "server didn't print a starting line");
	return -1;
    }

    FILE* client = popen("nc 127.0.0.1 3333 && echo done", "r");
    if (fgets(line, sizeof line, client) == NULL) {
	fprintf(stderr, "client was speachless");
	return -2;
    }
    fprintf(stderr, "%s", line);
    while (fgets(line, sizeof line, client) != NULL) {
	fprintf(stderr, "%s", line);
    }
    if (pclose(client) == -1 && errno != ECHILD) {
	perror("pclose(client):");
	return -3;
    }
    if (pclose(server) == -1 && errno != ECHILD) {
	perror("pclose(server):");
	return -4;
    }
    return 0;
}

#endif /* 0 */

