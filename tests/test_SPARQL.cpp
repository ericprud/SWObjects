/* test_SPARQL.cpp - test the ../bin/SPARQL executable
 *
 * $Id: test_SPARQL.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>

#define BOOST_TEST_MODULE SPARQL
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( D ) {
    std::string s("execution failure");
    try {
	FILE *p = ::popen("../bin/SPARQL -D --debug 1", "r");
	char buf[100];
	s = "";
	for (size_t count; (count = fread(buf, 1, sizeof(buf), p));)
	    s += std::string(buf, buf + count);
	pclose(p);
    } catch (std::exception e) {
	std::cerr << e.what();
    } catch (std::string e) {
	std::cerr << e;
    }
    BOOST_CHECK_EQUAL(s, 
		      "debug level: 1\n"
		      "<loadedData>\n"
		      "{\n"
		      "  <> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://usefulinc.com/ns/doap#Project> .\n"
		      "  <> <http://usefulinc.com/ns/doap#homepage> <http://swobj.org/SPARQL/v1> .\n"
		      "  <> <http://usefulinc.com/ns/doap#shortdesc> \"a semantic web query toolbox\"  .\n"
		      "}\n"
		      "</loadedData>\n");
}

