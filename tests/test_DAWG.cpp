/* test graph-matching.
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 * call with e.g. ../../../WWW/2001/sw/DataAccess/tests/data-r2/manifest-syntax.ttl
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE DAWG_tests
#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>

#include <vector>
#include <iterator>
#include "SWObjects.hpp"
#include "SPARQLfedParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"

using namespace w3c_sw;

POSFactory f;
SPARQLfedDriver sparqlParser("", &f);

std::string readFile (const char* filename, const char* type) {
    std::ifstream dataStream(filename);
    if (!dataStream.is_open()) {
	std::string msg = std::string("failed to ") + std::string(type) + std::string(" data \"") + filename + std::string("\".");
	throw msg;
    }
    std::istreambuf_iterator<char> i(dataStream), e;
    std::string ret(i, e);
    dataStream.close();
    return ret;
}

void queryTestDefault (size_t iDefGraphs, const char* defGraphs[], size_t iNamGraphs, const char* namGraphs[], const char* queryFile, const char* resultsFile) {
    if (sparqlParser.parse_file(queryFile)) {
	std::string msg = std::string("failed to parse query \"") + queryFile + std::string("\".");
	throw msg;
    }
    RdfDB d;
    for (size_t i = 0; i < iDefGraphs; ++i)
	f.parseTriples(d.assureGraph(NULL), readFile(defGraphs[i], "data"));
    for (size_t i = 0; i < iNamGraphs; ++i)
	f.parseTriples(d.assureGraph(f.getURI(namGraphs[i])), readFile(namGraphs[i], "data"));

    ResultSet got;
    sparqlParser.root->execute(&d, &got);
    ResultSet expected(&f, readFile(resultsFile, "data"));
    BOOST_CHECK_EQUAL(got, expected);
}

BOOST_AUTO_TEST_CASE( basic_Basic_Var_1 ) {
    const char* defaultGraphs[] = { "tests/data-r2/basic/data-5.ttl" };
    const char* namedGraphs[] = {  };
    queryTestDefault(sizeof(defaultGraphs)/sizeof(defaultGraphs[0]), defaultGraphs, sizeof(namedGraphs)/sizeof(namedGraphs[0]), namedGraphs, "tests/data-r2/basic/var-1.rq", "tests/data-r2/basic/var-1.srx");
}

// EOF
