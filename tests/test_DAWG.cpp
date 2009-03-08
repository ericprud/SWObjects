/* perform DAWG tests.
 * call from: ..
 * files: <tests>/data-r2  -- from http://www.w3.org/2001/sw/DataAccess/tests/data-r2/
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE DAWG_tests
#include <boost/test/unit_test.hpp>
//#pragma warning( disable : 4273 )
//#include <boost/test/included/unit_test.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "SPARQLSerializer.hpp"

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
  w3c_sw::SAXparser_libxml P;
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
  w3c_sw::SAXparser_expat P;
#else
  #warning DAWG tests require an XML parser
#endif

using namespace w3c_sw;

POSFactory F;
SPARQLfedDriver sparqlParser("", &F);
TurtleSDriver turtleParser("", &F);

/* Sentinal to mark end of arrays of files: */
const char* Sentinel = "sentinel";

struct TestResultSet : public ResultSet {
    RdfDB d;
    void _loadGraphWrapper (const POS* graphName, const char* fileName) {
	turtleParser.setGraph(d.assureGraph(graphName));
	turtleParser.parse_file(fileName);
    }
    TestResultSet (std::istream defGraphs[], size_t defCount, 
		   const char* namGraphs[], 
		   std::istream& query) : ResultSet(&F) {
 
	/* Parse query. */
	if (sparqlParser.parse_stream(query))
	    throw std::string("failed to parse query.");

	/* Parse data. */
	if (defGraphs != NULL)
	    for (size_t i = 0; i != defCount; ++i) {
		turtleParser.setGraph(d.assureGraph(NULL));
		turtleParser.parse_stream(defGraphs[i]);
	    }

	if (namGraphs != NULL)
	    for (size_t i = 0; namGraphs[i] != Sentinel; ++i)
		_loadGraphWrapper(F.getURI(namGraphs[i]), namGraphs[i]);

	/* Exectute query. */
	sparqlParser.root->execute(&d, this);
    }
};

std::ostream& operator<< (std::ostream& os, TestResultSet const& my) {
    os << "Database: " << my.d;
    os << "query: " << *sparqlParser.root;
    os << "result: ";
    operator<<(os, (ResultSet)my);
    return os;
}

/* Macros for terse test syntax: */
#define DEFGRAPH_FILE_TEST(QUERY_FILE, RESULT_FILE) \
    std::ifstream query(QUERY_FILE); \
    if (!query.is_open()) throw std::string("failed to open query file ") + QUERY_FILE; \
    TestResultSet measured(defaultGraphs, sizeof(defaultGraphs)/sizeof(defaultGraphs[0]), NULL, query); \
    ResultSet expected(&F, &P, RESULT_FILE); \
    BOOST_CHECK_EQUAL(measured, expected);
#define S Sentinel

BOOST_AUTO_TEST_SUITE( basic )

BOOST_AUTO_TEST_CASE( Basic_graph_pattern___spoo ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-6.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/spoo-1.rq", "data-r2/basic/spoo-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_1 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-2.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/list-1.rq", "data-r2/basic/list-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_2 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-2.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/list-2.rq", "data-r2/basic/list-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_3 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-2.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/list-3.rq", "data-r2/basic/list-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___List_4 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-2.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/list-4.rq", "data-r2/basic/list-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_1 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-1.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-1.rq", "data-r2/basic/base-prefix-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_2 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-1.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-2.rq", "data-r2/basic/base-prefix-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_3 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-1.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-3.rq", "data-r2/basic/base-prefix-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_4 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-1.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-4.rq", "data-r2/basic/base-prefix-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Prefix_Base_5 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-1.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/base-prefix-5.rq", "data-r2/basic/base-prefix-5.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_1 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-3.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-1.rq", "data-r2/basic/quotes-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_2 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-3.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-2.rq", "data-r2/basic/quotes-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_3 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-3.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-3.rq", "data-r2/basic/quotes-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Quotes_4 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-3.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/quotes-4.rq", "data-r2/basic/quotes-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_1 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-1.rq", "data-r2/basic/term-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_2 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-2.rq", "data-r2/basic/term-2.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_3 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-3.rq", "data-r2/basic/term-3.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_4 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-4.rq", "data-r2/basic/term-4.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_5 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-5.rq", "data-r2/basic/term-5.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_6 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-6.rq", "data-r2/basic/term-6.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_7 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-7.rq", "data-r2/basic/term-7.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_8 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-8.rq", "data-r2/basic/term-8.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Term_9 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-4.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/term-9.rq", "data-r2/basic/term-9.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Var_1 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-5.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/var-1.rq", "data-r2/basic/var-1.srx");
}
BOOST_AUTO_TEST_CASE( Basic___Var_2 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-5.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/var-2.rq", "data-r2/basic/var-2.srx");
}
BOOST_AUTO_TEST_CASE( Non_matching_triple_pattern ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-7.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/bgp-no-match.rq", "data-r2/basic/bgp-no-match.srx");
}
BOOST_AUTO_TEST_CASE( Prefix_name_1 ) {
    std::ifstream defaultGraphs[] = { std::ifstream( "data-r2/basic/data-6.ttl" ) };
    DEFGRAPH_FILE_TEST("data-r2/basic/prefix-name-1.rq", "data-r2/basic/prefix-name-1.srx");
}
BOOST_AUTO_TEST_SUITE_END()
#if 0
BOOST_AUTO_TEST_CASE( Members_1 ) {
    std::istringstream defaultGraphs[] ={ std::istringstream( "(<a> <b>) <p> (<x> <y> <z>) ." ) };
    std::istringstream query(std::istringstream("SELECT*{members(?s)<p>members(?o)}"));
    TestResultSet measured(defaultGraphs, sizeof(defaultGraphs)/sizeof(defaultGraphs[0]), NULL, query);
    BOOST_CHECK_EQUAL(measured, ResultSet(&F, 
					  "?s  ?o \n"
					  "<a> <x>\n"
					  "<a> <y>\n"
					  "<a> <z>\n"
					  "<b> <x>\n"
					  "<b> <y>\n"
					  "<b> <z>",
					  true));
}
#endif
// EOF

/*

-----------------------------+--------------------------------+------+-------------------------------+
                         name|                          result|  verb|                         target|
-----------------------------|--------------------------------|------|-------------------------------|
 "Basic graph pattern - spoo"|       data-r2/basic/spoo-1.srx>| data>|      data-r2/basic/data-6.ttl>|
 "Basic graph pattern - spoo"|       data-r2/basic/spoo-1.srx>|query>|       data-r2/basic/spoo-1.rq>|
             "Basic - List 1"|       data-r2/basic/list-1.srx>| data>|      data-r2/basic/data-2.ttl>|
             "Basic - List 1"|       data-r2/basic/list-1.srx>|query>|       data-r2/basic/list-1.rq>|
             "Basic - List 2"|       data-r2/basic/list-2.srx>| data>|      data-r2/basic/data-2.ttl>|
             "Basic - List 2"|       data-r2/basic/list-2.srx>|query>|       data-r2/basic/list-2.rq>|
             "Basic - List 3"|       data-r2/basic/list-3.srx>| data>|      data-r2/basic/data-2.ttl>|
             "Basic - List 3"|       data-r2/basic/list-3.srx>|query>|       data-r2/basic/list-3.rq>|
             "Basic - List 4"|       data-r2/basic/list-4.srx>| data>|      data-r2/basic/data-2.ttl>|
             "Basic - List 4"|       data-r2/basic/list-4.srx>|query>|       data-r2/basic/list-4.rq>|
      "Basic - Prefix/Base 1"|data-r2/basic/base-prefix-1.srx>| data>|      data-r2/basic/data-1.ttl>|
      "Basic - Prefix/Base 1"|data-r2/basic/base-prefix-1.srx>|query>|data-r2/basic/base-prefix-1.rq>|
      "Basic - Prefix/Base 2"|data-r2/basic/base-prefix-2.srx>| data>|      data-r2/basic/data-1.ttl>|
      "Basic - Prefix/Base 2"|data-r2/basic/base-prefix-2.srx>|query>|data-r2/basic/base-prefix-2.rq>|
      "Basic - Prefix/Base 3"|data-r2/basic/base-prefix-3.srx>| data>|      data-r2/basic/data-1.ttl>|
      "Basic - Prefix/Base 3"|data-r2/basic/base-prefix-3.srx>|query>|data-r2/basic/base-prefix-3.rq>|
      "Basic - Prefix/Base 4"|data-r2/basic/base-prefix-4.srx>| data>|      data-r2/basic/data-1.ttl>|
      "Basic - Prefix/Base 4"|data-r2/basic/base-prefix-4.srx>|query>|data-r2/basic/base-prefix-4.rq>|
      "Basic - Prefix/Base 5"|data-r2/basic/base-prefix-5.srx>| data>|      data-r2/basic/data-1.ttl>|
      "Basic - Prefix/Base 5"|data-r2/basic/base-prefix-5.srx>|query>|data-r2/basic/base-prefix-5.rq>|
           "Basic - Quotes 1"|     data-r2/basic/quotes-1.srx>| data>|      data-r2/basic/data-3.ttl>|
           "Basic - Quotes 1"|     data-r2/basic/quotes-1.srx>|query>|     data-r2/basic/quotes-1.rq>|
           "Basic - Quotes 2"|     data-r2/basic/quotes-2.srx>| data>|      data-r2/basic/data-3.ttl>|
           "Basic - Quotes 2"|     data-r2/basic/quotes-2.srx>|query>|     data-r2/basic/quotes-2.rq>|
           "Basic - Quotes 3"|     data-r2/basic/quotes-3.srx>| data>|      data-r2/basic/data-3.ttl>|
           "Basic - Quotes 3"|     data-r2/basic/quotes-3.srx>|query>|     data-r2/basic/quotes-3.rq>|
           "Basic - Quotes 4"|     data-r2/basic/quotes-4.srx>| data>|      data-r2/basic/data-3.ttl>|
           "Basic - Quotes 4"|     data-r2/basic/quotes-4.srx>|query>|     data-r2/basic/quotes-4.rq>|
             "Basic - Term 1"|       data-r2/basic/term-1.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 1"|       data-r2/basic/term-1.srx>|query>|       data-r2/basic/term-1.rq>|
             "Basic - Term 2"|       data-r2/basic/term-2.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 2"|       data-r2/basic/term-2.srx>|query>|       data-r2/basic/term-2.rq>|
             "Basic - Term 3"|       data-r2/basic/term-3.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 3"|       data-r2/basic/term-3.srx>|query>|       data-r2/basic/term-3.rq>|
             "Basic - Term 4"|       data-r2/basic/term-4.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 4"|       data-r2/basic/term-4.srx>|query>|       data-r2/basic/term-4.rq>|
             "Basic - Term 5"|       data-r2/basic/term-5.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 5"|       data-r2/basic/term-5.srx>|query>|       data-r2/basic/term-5.rq>|
             "Basic - Term 6"|       data-r2/basic/term-6.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 6"|       data-r2/basic/term-6.srx>|query>|       data-r2/basic/term-6.rq>|
             "Basic - Term 7"|       data-r2/basic/term-7.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 7"|       data-r2/basic/term-7.srx>|query>|       data-r2/basic/term-7.rq>|
             "Basic - Term 8"|       data-r2/basic/term-8.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 8"|       data-r2/basic/term-8.srx>|query>|       data-r2/basic/term-8.rq>|
             "Basic - Term 9"|       data-r2/basic/term-9.srx>| data>|      data-r2/basic/data-4.ttl>|
             "Basic - Term 9"|       data-r2/basic/term-9.srx>|query>|       data-r2/basic/term-9.rq>|
              "Basic - Var 1"|        data-r2/basic/var-1.srx>| data>|      data-r2/basic/data-5.ttl>|
              "Basic - Var 1"|        data-r2/basic/var-1.srx>|query>|        data-r2/basic/var-1.rq>|
              "Basic - Var 2"|        data-r2/basic/var-2.srx>| data>|      data-r2/basic/data-5.ttl>|
              "Basic - Var 2"|        data-r2/basic/var-2.srx>|query>|        data-r2/basic/var-2.rq>|
"Non-matching triple pattern"| data-r2/basic/bgp-no-match.srx>| data>|      data-r2/basic/data-7.ttl>|
"Non-matching triple pattern"| data-r2/basic/bgp-no-match.srx>|query>| data-r2/basic/bgp-no-match.rq>|
              "Prefix name 1"|data-r2/basic/prefix-name-1.srx>| data>|      data-r2/basic/data-6.ttl>|
              "Prefix name 1"|data-r2/basic/prefix-name-1.srx>|query>|data-r2/basic/prefix-name-1.rq>|
-----------------------------+-------------------------------------------+--------+-------------------------------------------------------------------------------------+-------------------------------------------------------------+------------------------------------------------------------------------------------+
*/
