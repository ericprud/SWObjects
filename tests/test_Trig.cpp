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

std::string errorStr (std::string filename, int lineNo) { // cater to emacs's comint mode
    return "                 from " + filename + ":" + boost::lexical_cast<std::string>(lineNo);
}

std::string unescape (std::string s, bool literal) {
    size_t len = s.length();
    char space[len+1];
    ::strncpy(space, s.c_str(), len);
    std::string stripped;
    if (literal)
	YaccDriver::unescapeString(space, len, &stripped, NULL);
    else
	YaccDriver::unescapeNumeric(space, len, &stripped, NULL, NULL);
    return stripped;
}

struct GetTTerm {
    const TTerm* t;
    GetTTerm (std::istream& iss, TTerm::String2BNode* bnodeMap)
	: t(readTerm(iss, bnodeMap))
    {  }
    static const TTerm* readTerm (std::istream& iss, TTerm::String2BNode* bnodeMap) {
	std::ostringstream lex;
	char ch;
	iss >> std::ws >> ch >> std::noskipws;
	switch (ch) {
	case '<':
	    while (iss >> ch && ch != '>')
		lex << ch;
	    return F.getURI(unescape(lex.str(), false));
	case '_':
	    iss >> ch; assert(ch == ':');
	    while (iss >> ch && ch != ' ' && ch != '.')
		lex << ch;
	    return F.getBNode(unescape(lex.str(), false), bnodeMap);
	case '"':
	    while (iss >> ch && ch != '"')
		if (ch == '\\') {
		    lex << ch;
		    iss >> ch;
		    lex << ch; // get past possible '"' or into u0022, or whatever
		} else {
		    lex << ch;
		}
	    {
		const TTerm* datatype = NULL;
		const LANGTAG* langtag = NULL;
		iss >> ch;
		if (ch == '^') {
		    iss >> ch; assert(ch == '^');
		    datatype = readTerm(iss, bnodeMap);
		} else if (ch == '@') {
		    std::string s;
		    iss >> s;
		    langtag = new LANGTAG(s);
		} else if (ch != ' ' && ch != '.')
		    throw std::runtime_error(std::string() + "unexpected character after string: " + ch);
		return F.getRDFLiteral(unescape(lex.str(), true), dynamic_cast<const URI*>(datatype), langtag, false);
	    }
	case '.':
	    return DefaultGraph;
	default:
	    throw std::runtime_error(std::string() + "unexpected delimiter: " + ch);
	}
    }
};

void parseNQuads (RdfDB* db, std::istream& is, std::string filename) {
    TTerm::String2BNode m;
    std::string line;
    int lineNo = 1;
    try {
	while (std::getline(is, line)) {
	    if (line.length() == 0)
		continue;
	    std::istringstream iss(line);
	    GetTTerm s(iss,&m), p(iss,&m), o(iss,&m), g(iss,&m);
	    BasicGraphPattern* graph = db->ensureGraph(g.t);
	    graph->addTriplePattern(F.getTriple(s.t, p.t, o.t));
	    ++lineNo;
	}
    } catch (std::runtime_error& e) {
	throw std::runtime_error
	    (errorStr("tests/"+filename, lineNo) + std::string(": ")+e.what());
    }
}

typedef enum {Expect, Parse, Fail} Action;
void parseAndCompare (std::string name, std::string trig, std::string nqad,
		      std::string manifestLoc, Action action) {
    test_case const& cur = boost::unit_test::framework::current_test_case();
    // std::cerr << cur.p_name << "\n";
    std::string context = errorStr("tests/"+trig, 1) + "\n";
    try {
	AtomFactory::validate = AtomFactory::VALIDATE_all;
	std::string base = std::string("http://www.w3.org/2013/") + trig.c_str();
	ReferenceDB tested(trig.c_str(), base.c_str(), true);
	if (action == Expect) {
	    context = errorStr("tests/"+nqad, 1) + "\n";
	    RdfDB expect;
	    std::ifstream nqstr(nqad.c_str());
	    parseNQuads(&expect, nqstr, nqad);
	    context
		= errorStr("tests/"+trig, 1) + "\n"
		+ errorStr("tests/"+nqad, 1) + "\n";
	    if (!(tested == expect)) {
		std::stringstream l; l << tested;
		std::stringstream r; r << expect;
		BOOST_ERROR ( "\n" + context + manifestLoc + " check tested == expect failed " +
			      "[" + l.str() + " != " + r.str() + "]" );
	    }
	} else if (action == Fail) {
	    BOOST_ERROR ( "\n" + context + manifestLoc + " expected parser to fail." );
	}
	/*G_EARL.report(TEST, tested == expect);*/
    } catch (NotImplemented& e) {
	std::cerr << e.what() << "\n";
	BOOST_ERROR ( "\n" + context + manifestLoc + " " + std::string("require implementation of ") + e.brief );
    } catch (std::string& s) {
	BOOST_ERROR ( "\n" + context + manifestLoc + " " + s );
    } catch (std::exception& s) {
	if (action != Fail)
	    BOOST_ERROR ( "\n" + context + manifestLoc + " " + s.what() );
    }
}

void readAndQueue (std::string filename, Action action, test_suite* ts) {
    std::ifstream tsv(filename.c_str());
    std::string name, trig, nqad;
    int lineNo = 1;
    while (tsv >> name >> trig) {
	name = name.substr(1,name.length()-2);
	trig = trig.substr(1,trig.length()-2);
	if (action == Expect) {
	    tsv >> nqad;
	    nqad = nqad.substr(1,nqad.length()-2);
	}
	ts->add(boost::unit_test::make_test_case
		(boost::unit_test::callback0<>(boost::bind
					       (&parseAndCompare, name, trig, nqad,
						errorStr("tests/"+filename, lineNo)+":",
						action)),
		 boost::unit_test::const_string(name.c_str(), name.length())));
	++lineNo;
    }
}

bool init_function () {
    framework::master_test_suite().p_name.value = "Trig tests";

    int argc = boost::unit_test::framework::master_test_suite().argc;
    char** argv = boost::unit_test::framework::master_test_suite().argv;

    test_suite* ts = BOOST_TEST_SUITE("WG");
    framework::master_test_suite().add(ts);

    readAndQueue("TrigEvalPos.tsv", Expect, ts);
    readAndQueue("TrigSynPos.tsv" , Parse , ts);
    readAndQueue("TrigSynNeg.tsv" , Fail  , ts);
    readAndQueue("TrigEvalNeg.tsv", Fail  , ts);
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

../bin/sparql -d TriGTests/manifest.ttl -e '
PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
PREFIX rdft:   <http://www.w3.org/ns/rdftest#>
SELECT ?name ?trig ?ntriples {
  ?m a mf:Manifest ; mf:entries MEMBERS(?entry) .
  ?entry a rdft:TestTrigEval ; mf:name ?name ; mf:action ?trig ; mf:result ?ntriples
}' -l tsv | sed 1d > TrigEvalPos.tsv # 136 lines

../bin/sparql -d TriGTests/manifest.ttl -e '
PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>
PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>
PREFIX rdft:   <http://www.w3.org/ns/rdftest#>
SELECT ?name ?trig {
  ?m a mf:Manifest ; mf:entries MEMBERS(?entry) .
  ?entry a rdft:TestTrigPositiveSyntax ; mf:name ?name ; mf:action ?trig
}' -l tsv | sed 1d > TrigSynPos.tsv # 96 lines

# rdft:TestTrigNegativeSyntax > TrigSynNeg.tsv with 99 lines
# rdft:TestTrigNegativeEval > TrigEvalNeg.tsv with 4 lines
*/
