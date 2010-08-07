/* test_SPARQLSerializer.hpp -- 
 *
 * Test a SPARQL Parser and serializer.
 *
 * $Id: test_SPARQLSerializer.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */


#define BOOST_TEST_MODULE SPARQLSerializer

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SPARQLSerializer.hpp"
#include "SPARQLAlgebraSerializer.hpp"
#include "SWObjectDuplicator.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>

using namespace w3c_sw;

AtomFactory F;
SPARQLfedDriver sparqlParser("", &F);

struct OpWrap {
    OpWrap () {  }
    OpWrap (std::string str, const Operation* op) : 
	str(str), op(op) {  }
    std::string str;
    const Operation* op;
};

bool operator== (const OpWrap& l, const OpWrap& r) {
    return *l.op == *r.op;
}

std::ostream& operator<< (std::ostream& os, OpWrap const& my) {
    os << operator<<(os, my.str);
    SPARQLAlgebraSerializer s;
    my.op->express(&s);
    return os << s.str();
}

struct OpPair {
    OpPair (const OpWrap once, const OpWrap twice, const OpWrap dup) : 
	once(once), twice(twice), dup(dup) {  }
    void cleanup () { delete once.op; delete twice.op; delete dup.op; } // i never worked out the Op copy constructor
    const OpWrap once;
    const OpWrap twice;
    const OpWrap dup;
};

OpPair algebrize_TWICE (std::string sparql) {
    /* Parse query. */
    IStreamContext sparstream(sparql, IStreamContext::STRING);
    if (sparqlParser.parse(sparstream))
	throw std::string("failed to parse SPARQL \"") + sparql + "\".";
    sparqlParser.clear(""); // clear out namespaces and base URI.

    SPARQLSerializer s;
    sparqlParser.root->express(&s);
    OpWrap once(sparql, sparqlParser.root);
    sparqlParser.root = NULL;

    IStreamContext serialstream(s.str(), IStreamContext::STRING);
    if (sparqlParser.parse(serialstream))
	throw std::string("failed to parse re-serialized SPARQL \"") + s.str() + "\".";
    OpWrap twice(s.str(), sparqlParser.root);
    sparqlParser.root = NULL;

    SWObjectDuplicator duper(&F);
    once.op->express(&duper);
    s.str(""); // Clear out serializer.
    duper.last.operation->express(&s);
    OpWrap dup(s.str(), duper.last.operation);

    return OpPair(once, twice, dup);
}


/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 */
//@@SWOBjectDuplicator

#define SERIALIZER_TEST(SPARQL)						       \
    try {								       \
	OpPair p = algebrize_TWICE(SPARQL);				       \
	BOOST_CHECK_EQUAL(p.once, p.twice);				       \
	BOOST_CHECK_EQUAL(p.once, p.dup);				       \
	p.cleanup();							       \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

BOOST_AUTO_TEST_CASE( algebra__filter_nested_2 ) {
    /* copy of DAWG test algebra/filter_nested_2
     */
    SERIALIZER_TEST("ASK { <x> <p> ?v . { FILTER(?v = 1) } }");
}

BOOST_AUTO_TEST_CASE( triple_match__dawg_triple_pattern_001 ) {
    /* shape of DAWG test triple_match/dawg_triple_pattern_001
     */
    SERIALIZER_TEST("ASK { <x> ?p ?q . }");
}

BOOST_AUTO_TEST_CASE( algebra__filter_place_3 ) {
    /* shape of DAWG test algebra/filter_place_3.
     */
    SERIALIZER_TEST("ASK\n\
{ \n\
    FILTER (?v = 2)\n\
    FILTER (?w = 3)\n\
    ?s <p> ?v . \n\
    ?s <q> ?w .\n\
}\n\
");
}

BOOST_AUTO_TEST_CASE( algebra__opt_filter_1 ) {
    /* shape of DAWG test algebra/opt_filter_1.
     */
    SERIALIZER_TEST("ASK { \n\
  ?x <p> ?v .\n\
  OPTIONAL\n\
  { \n\
    FILTER(?v=1)\n\
    ?y <q> ?w .\n\
    FILTER(?v=2)\n\
  }\n\
}");
}

BOOST_AUTO_TEST_CASE( triple_filter ) {
    /* Simple FILTER after a triple.
     */
    SERIALIZER_TEST("ASK {\n\
  ?s <p> 1 .\n\
  FILTER (1)\n\
  }");
}

BOOST_AUTO_TEST_CASE( filter_triple ) {
    /* Simple FILTER before a triple.
     */
    SERIALIZER_TEST("ASK {\n\
  FILTER (1)\n\
  ?s <p> 1 .\n\
  }");
}

BOOST_AUTO_TEST_CASE( bgp_before_nth ) {
    /* Simple FILTER before a later BGP.
     */
    SERIALIZER_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  FILTER (1)\n\
  ?s <p> 2 .\n\
}");
}
BOOST_AUTO_TEST_CASE( bgp_after_nth ) {
    /* Simple FILTER after a later BGP.
     */
    SERIALIZER_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  ?s <p> 2 .\n\
  FILTER (1)\n\
}");
}

BOOST_AUTO_TEST_CASE( bgp_in_nth ) {
    /* Simple FILTER in a later BGP.
     */
    SERIALIZER_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  ?s <p> 2 .\n\
  FILTER (1)\n\
  ?s <p> 3 .\n\
}");
}

BOOST_AUTO_TEST_CASE( bgp_trailing_conjunction ) {
    /* Simple FILTER trailing a conjunction.
     */
    SERIALIZER_TEST("ASK {\n\
  {\n\
    ?s <p> 1 .\n\
  }\n\
  {\n\
    ?s <p> 2 .\n\
  }\n\
  FILTER (1)\n\
  }");
}

BOOST_AUTO_TEST_CASE( bgp_opt_combo ) {
    /* A FILTER inside an OPTIONAL can reference a variable bound in the required part of the OPTIONAL
     */
    SERIALIZER_TEST("ASK {\
  OPTIONAL {?s?p 0}\
  FILTER (1)\
  ?s?p 1\
  FILTER (2)\
  ?s?p 2\
}");
}

BOOST_AUTO_TEST_CASE( bgp_with_triples ) {
    /* Simple FILTER intermingled with triples.
     */
    SERIALIZER_TEST("ASK {\n\
  ?s <p> 1 .\n\
  FILTER (1)\n\
  ?s <p> 2 .\n\
  FILTER (2)\n\
  }");
}

