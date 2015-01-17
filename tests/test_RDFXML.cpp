/* dyntest - fiddle with boost UTF init_unit_test_suite

CPATH=../libboost-1.55.inst/include/ g++ -c -o dyntest.o dyntest.cpp -DYYTEXT_POINTER=1 -fPIC -g -O0 -W -Wall -Wextra -Wnon-virtual-dtor -ansi -std=c++98 -pipe -Wno-empty-body -Wno-missing-field-initializers -Wwrite-strings -Wno-deprecated -Wno-unused -Wno-non-virtual-dtor -Wno-variadic-macros -ftemplate-depth-128 -fno-merge-constants 
LIBRARY_PATH=../libboost-1.55.inst/lib/ g++ -o dyntest dyntest.o -lboost_unit_test_framework
LD_LIBRARY_PATH=../libboost-1.55.inst/lib/ dyntest --log_level=all "--run_test=a/1" ab 12
 */

#include "tests/SPARQLTest.hpp"

#ifndef BOOST_TEST_DYN_LINK
# define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include "TSVmanifest.hpp"

w3c_sw_DEBUGGING_FUNCTIONS();

bool init_function () {
    boost::unit_test::framework::master_test_suite().p_name.value = "RDFXML tests";

    int argc = boost::unit_test::framework::master_test_suite().argc;
    char** argv = boost::unit_test::framework::master_test_suite().argv;

    boost::unit_test::test_suite* ts = BOOST_TEST_SUITE("WG");
    boost::unit_test::framework::master_test_suite().add(ts);

    w3c_sw::TSVmanifest::readAndQueue("RDFXMLEvalPos.tsv", w3c_sw::TSVmanifest::Expect, ts);
    w3c_sw::TSVmanifest::readAndQueue("RDFXMLSynNeg.tsv" , w3c_sw::TSVmanifest::Fail  , ts);
    return true;
}

int main (int argc, char* argv[]) {
    return ::boost::unit_test::unit_test_main( &init_function, argc, argv );
}


/* accounting
sparql -d tests/RDFXMLTests/manifest.ttl -e 'SELECT ?t (COUNT(*) AS ?c) { ?x a ?t } GROUP BY ?t'
+---------------------------------------------------------------------+-----+
| ?t                                                                  | ?c  |
| <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#Manifest> |   1 |
|                <http://www.w3.org/ns/rdftest#TestXMLNegativeSyntax> |  40 |
|                          <http://www.w3.org/ns/rdftest#TestXMLEval> | 122 |
+---------------------------------------------------------------------+-----+

../bin/sparql -d RDFXMLTests/manifest.ttl -e '
PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
PREFIX rdft:   <http://www.w3.org/ns/rdftest#>
SELECT ?name ?rdfxml ?ntriples {
  ?m a mf:Manifest ; mf:entries MEMBERS(?entry) .
  ?entry a rdft:TestXMLEval ; mf:name ?name ; mf:action ?rdfxml ; mf:result ?ntriples
}' -l tsv | sed 1d > RDFXMLEvalPos.tsv # 122 lines

../bin/sparql -d RDFXMLTests/manifest.ttl -e '
PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
PREFIX rdft:   <http://www.w3.org/ns/rdftest#>
SELECT ?name ?trig {
  ?m a mf:Manifest ; mf:entries MEMBERS(?entry) .
  ?entry a rdft:TestXMLNegativeSyntax ; mf:name ?name ; mf:action ?trig
}' -l tsv | sed 1d > RDFXMLSynNeg.tsv# 40 lines

*/
