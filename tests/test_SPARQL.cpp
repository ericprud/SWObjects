/* test_SPARQL.cpp - test the ../bin/SPARQL executable
 *
 * $Id: test_SPARQL.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#include "SWObjects.hpp"
#include "ResultSet.hpp"

#define BOOST_TEST_MODULE SPARQL
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

w3c_sw::POSFactory F;

struct ExecResults {
    std::string s;
    ExecResults (const char* cmd) {
	s  = "execution failure";
	FILE *p = ::popen(cmd, "r");
	BOOST_REQUIRE(p != NULL);
	char buf[100];
	s = "";
	for (size_t count; (count = fread(buf, 1, sizeof(buf), p));)
	    s += std::string(buf, buf + count);
	pclose(p);
    }
};

bool operator== (ExecResults& tested, std::string& ref) {
    return tested.s == ref;
}

std::ostream& operator== (std::ostream& o, ExecResults& tested) {
    return o << tested.s;
}

BOOST_AUTO_TEST_SUITE( tutorial )
BOOST_AUTO_TEST_CASE( D ) {
    ExecResults tested("../bin/SPARQL -D");
    BOOST_CHECK_EQUAL(tested.s, 
		      "{\n"
		      "  <> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://usefulinc.com/ns/doap#Project> .\n"
		      "  <> <http://usefulinc.com/ns/doap#homepage> <http://swobj.org/SPARQL/v1> .\n"
		      "  <> <http://usefulinc.com/ns/doap#shortdesc> \"a semantic web query toolbox\"  .\n"
		      "}\n");
}
BOOST_AUTO_TEST_CASE( D_spo ) {
    ExecResults invocation("../bin/SPARQL -D -e \"SELECT ?s ?p ?o WHERE {?s ?p ?o}\"");
    w3c_sw::POS::String2BNode bnodeMap;
    w3c_sw::ResultSet tested(&F, invocation.s, false, bnodeMap);
    w3c_sw::ResultSet
	expected(&F, 
		 "+----+---------------------------------------------------+----------------------------------------+\n"
		 "| ?s | ?p                                                | ?o                                     |\n"
		 "| <> | <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
		 "| <> |           <http://usefulinc.com/ns/doap#homepage> |           <http://swobj.org/SPARQL/v1> |\n"
		 "| <> |          <http://usefulinc.com/ns/doap#shortdesc> |         \"a semantic web query toolbox\" |\n"
		 "+----+---------------------------------------------------+----------------------------------------+\n",
		 false, bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( D_spo_utf8 ) {
    ExecResults invocation("../bin/SPARQL -D -u -e \"SELECT ?s ?p ?o WHERE {?s ?p ?o}\"");
    w3c_sw::POS::String2BNode bnodeMap;
    w3c_sw::ResultSet tested(&F, invocation.s, false, bnodeMap);
    w3c_sw::ResultSet
	expected(&F, 
		 "+----+---------------------------------------------------+----------------------------------------+\n"
		 "| ?s | ?p                                                | ?o                                     |\n"
		 "| <> | <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
		 "| <> |           <http://usefulinc.com/ns/doap#homepage> |           <http://swobj.org/SPARQL/v1> |\n"
		 "| <> |          <http://usefulinc.com/ns/doap#shortdesc> |         \"a semantic web query toolbox\" |\n"
		 "+----+---------------------------------------------------+----------------------------------------+\n",
		 false, bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( G_spo ) {
    ExecResults invocation("../bin/SPARQL -G foo -e \"SELECT ?s ?p ?o WHERE { GRAPH <foo> { ?s ?p ?o } }\"");
    w3c_sw::POS::String2BNode bnodeMap;
    w3c_sw::ResultSet tested(&F, invocation.s, false, bnodeMap);
    w3c_sw::ResultSet
	expected(&F, 
		 "+----+---------------------------------------------------+----------------------------------------+\n"
		 "| ?s | ?p                                                | ?o                                     |\n"
		 "| <> | <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> | <http://usefulinc.com/ns/doap#Project> |\n"
		 "| <> |           <http://usefulinc.com/ns/doap#homepage> |           <http://swobj.org/SPARQL/v1> |\n"
		 "| <> |          <http://usefulinc.com/ns/doap#shortdesc> |         \"a semantic web query toolbox\" |\n"
		 "+----+---------------------------------------------------+----------------------------------------+\n", 
		 false, bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( DG_sp ) {
    ExecResults invocation("../bin/SPARQL -a -DG foo -G foo2 -e \"SELECT ?g {\n"
		       "    GRAPH ?g {?s ?p <http://usefulinc.com/ns/doap#Project>}}\"");
    w3c_sw::POS::String2BNode bnodeMap;
    w3c_sw::ResultSet tested(&F, invocation.s, false, bnodeMap);
    w3c_sw::ResultSet
	expected(&F, 
		 "+--------+\n"
		 "| ?g     |\n"
		 "|  <foo> |\n"
		 "| <foo2> |\n"
		 "+--------+\n", 
		 false, bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_CASE( DG_sp_U_sp ) {
    ExecResults invocation("../bin/SPARQL -a -DG foo -G foo2 -e \"SELECT ?g {\n"
			   "        {?s ?p <http://usefulinc.com/ns/doap#Project>}\n"
			   "    UNION\n"
			   "        {GRAPH ?g{?s ?p <http://usefulinc.com/ns/doap#Project>}}}\"\n");
    w3c_sw::POS::String2BNode bnodeMap;
    w3c_sw::ResultSet tested(&F, invocation.s, false, bnodeMap);
    w3c_sw::ResultSet
	expected(&F, 
		 "+--------+\n"
		 "| ?g     |\n"
		 "|     -- |\n"
		 "|  <foo> |\n"
		 "| <foo2> |\n"
		 "+--------+\n", 
		 false, bnodeMap);
    BOOST_CHECK_EQUAL(tested, expected);
}
BOOST_AUTO_TEST_SUITE_END(/* tutorial */)

#ifdef FIXED_SPARQL_ARGS_ORDER // !!!
/* sensitivity to position of -b directive */
BOOST_AUTO_TEST_CASE( Dbe ) {
    ExecResults tested("../bin/SPARQL -D -b http://foo.example/ -e \"SELECT * WHERE { <> a ?t}\"");
    BOOST_CHECK_EQUAL(tested.s, 
		      "+\n"
		      "|\n"
		      "+\n");
}
#endif

/* make sure we fail mis-matches */
BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001_002 ) {
    ExecResults tested("../bin/SPARQL -d data-r2/triple-match/data-01.ttl data-r2/triple-match/dawg-tp-01.rq --compare data-r2/triple-match/result-tp-02.ttl");
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
    ExecResults tested("../bin/SPARQL -d data-r2/triple-match/data-01.ttl data-r2/triple-match/dawg-tp-01.rq --compare data-r2/triple-match/result-tp-01.ttl");
    BOOST_CHECK_EQUAL(tested.s, 
		      "matched\n");
}

BOOST_AUTO_TEST_CASE( bool_no_base ) {
    ExecResults tested("../bin/SPARQL -d SPARQL/rel.ttl SPARQL/rel.rq");
    BOOST_CHECK_EQUAL(tested.s, 
		      "true\n");
}

BOOST_AUTO_TEST_CASE( bool_base_0 ) {
    ExecResults tested("../bin/SPARQL -b http://foo.example/ -d SPARQL/rel.ttl SPARQL/rel.rq");
    BOOST_CHECK_EQUAL(tested.s, 
		      "true\n");
}

BOOST_AUTO_TEST_CASE( bool_base_1 ) {
    ExecResults tested("../bin/SPARQL -d SPARQL/rel.ttl -b http://foo.example/ SPARQL/rel.rq");
    BOOST_CHECK_EQUAL(tested.s, 
		      "false\n");
}

