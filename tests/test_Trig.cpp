/* dyntest - fiddle with boost UTF init_unit_test_suite

CPATH=../libboost-1.55.inst/include/ g++ -c -o dyntest.o dyntest.cpp -DYYTEXT_POINTER=1 -fPIC -g -O0 -W -Wall -Wextra -Wnon-virtual-dtor -ansi -std=c++98 -pipe -Wno-empty-body -Wno-missing-field-initializers -Wwrite-strings -Wno-deprecated -Wno-unused -Wno-non-virtual-dtor -Wno-variadic-macros -ftemplate-depth-128 -fno-merge-constants 
LIBRARY_PATH=../libboost-1.55.inst/lib/ g++ -o dyntest dyntest.o -lboost_unit_test_framework
LD_LIBRARY_PATH=../libboost-1.55.inst/lib/ dyntest --log_level=all "--run_test=a/1" ab 12
 */

#include "tests/SPARQLTest.hpp"
w3c_sw_DEBUGGING_FUNCTIONS();

#ifndef BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <fstream>
using namespace boost::unit_test;

//____________________________________________________________________________//

void parseNQuads (RdfDB* db, std::istream& is) {
    TTerm::String2BNode bnodeMap;
    std::string line;
    while (std::getline(is, line)) {
	std::istringstream iss(line);
	std::string s, p, o, g;
	if (!(iss >> s >> p >> o >> g))
	    throw "didn't parse " + line;
	BasicGraphPattern* graph = db->ensureGraph(g == "." ? DefaultGraph : F.getTTerm(g, &bnodeMap));
	graph->addTriplePattern(F.getTriple(s, p, o, &bnodeMap));
    }
}

void parseAndCompare (std::string name, std::string trig, std::string ntrp) {
    test_case const& cur = boost::unit_test::framework::current_test_case();
    // std::cerr << cur.p_name << "\n";
    // std::cerr << "name: " << name << " -- trig: " << trig << " -- ntrp: " << ntrp << "\n";
    // BOOST_CHECK_EQUAL(trig, ntrp);
    try {
	AtomFactory::validate = AtomFactory::VALIDATE_all;
	ReferenceDB tested(trig.c_str(), "http://www.w3.org/2013/TurtleTests/turtle-subm-01.ttl");
	RdfDB expect;
	std::ifstream nqstr(ntrp.c_str());
	parseNQuads(&expect, nqstr);
	BOOST_CHECK_EQUAL(tested, expect);
	/*G_EARL.report(TEST, tested == expect);*/
    } catch (NotImplemented& e) {
	std::cerr << e.what() << "\n";
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );
    } catch (std::string& s) {
	BOOST_ERROR ( s );
    } catch (std::exception& s) {
	BOOST_ERROR ( s.what() );
    }
}

bool init_function () {
    framework::master_test_suite().p_name.value = "top";

    int argc = boost::unit_test::framework::master_test_suite().argc;
    char** argv = boost::unit_test::framework::master_test_suite().argv;

    std::ifstream file("TrigEvalPos.tsv");
    std::string name, trig, ntrp;
    while (file >> name >> trig >> ntrp) {
	name = name.substr(1,name.length()-2);
	trig = trig.substr(1,trig.length()-2);
	ntrp = ntrp.substr(1,ntrp.length()-2);
	test_suite* ts = BOOST_TEST_SUITE("WG");
	framework::master_test_suite().add(ts);
	ts->add(boost::unit_test::make_test_case
		(boost::unit_test::callback0<>(boost::bind
					       (&parseAndCompare, name, trig, ntrp)),
		 boost::unit_test::const_string(name.c_str(), name.length())));
    }

    return true;
}

int main (int argc, char* argv[]) {
    return ::boost::unit_test::unit_test_main( &init_function, argc, argv );
}


/* accounting
+-------------------------------------------------------+-----+
| ?t                                                    | ?c  |
|           <http://www.w3.org/ns/rdftest#TestTrigEval> | 136 |
| <http://www.w3.org/ns/rdftest#TestTrigNegativeSyntax> |  99 |
| <http://www.w3.org/ns/rdftest#TestTrigPositiveSyntax> |  96 |
|   <http://www.w3.org/ns/rdftest#TestTrigNegativeEval> |   4 |
+-------------------------------------------------------+-----+

../bin/sparql -d TrigTests/manifest.ttl -e '
PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
PREFIX rdft:   <http://www.w3.org/ns/rdftest#>
SELECT ?name ?trig ?ntriples {
  ?m a mf:Manifest ; mf:entries MEMBERS(?entry) .
  ?entry a rdft:TestTrigEval ; mf:action ?trig ; mf:result ?ntriples
}' -l tsv | sed 1d > TrigEvalPos.tsv # 136 lines

../bin/sparql -d TrigTests/manifest.ttl -e '
PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
PREFIX rdft:   <http://www.w3.org/ns/rdftest#>
SELECT ?trig {
  ?m a mf:Manifest ; mf:entries MEMBERS(?entry) .
  ?entry a rdft:TestTrigPositiveSyntax ; mf:action ?trig
}' -l tsv | sed 1d > TrigSynPos.tsv # 96 lines

# rdft:TestTrigNegativeSyntax > TrigSynNeg.tsv with 99 lines
# rdft:TestTrigNegativeEval > TrigEvalNeg.tsv with 4 lines
*/
