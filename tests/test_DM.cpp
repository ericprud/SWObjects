/* test_dm-materialize.cpp - test the ../bin/dm-materialize executable
 *
 * $Id: test_dm-materialize.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#define NEEDDEF_W3C_SW_SAXPARSER
#include "SWObjects.hpp"
#include "ResultSet.hpp"

#define BOOST_TEST_MODULE dm-materialize
#include <boost/test/unit_test.hpp>
#include <stdio.h>

w3c_sw::AtomFactory F;

struct ExecResults {
    std::string s;
    ExecResults (const char* cmd) {
	s  = "execution failure";
	FILE *p = ::popen(cmd, "r");
	BOOST_REQUIRE(p != NULL);
	char buf[100];
	s = "";

	/* Gave up on [[ ferror(p) ]] because it sometimes returns EPERM on OSX.
	 */
	for (size_t count; (count = fread(buf, 1, sizeof(buf), p)) || !feof(p);) {
	    s += std::string(buf, buf + count);
	    ::fflush(p);
	}
	pclose(p);
    }
};

bool operator== (ExecResults& tested, std::string& ref) {
    return tested.s == ref;
}

std::ostream& operator== (std::ostream& o, ExecResults& tested) {
    return o << tested.s;
}

struct TableResultSet : public w3c_sw::ResultSet {
    TableResultSet (w3c_sw::AtomFactory* atomFactory, std::string srt, bool ordered, w3c_sw::TTerm::String2BNode& nodeMap) : 
	ResultSet(atomFactory) {
	erase(begin());
	w3c_sw::IStreamContext sptr(srt.c_str(), w3c_sw::IStreamContext::STRING, "text/sparql-results");
	parseTable(sptr, ordered, nodeMap);
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

BOOST_AUTO_TEST_SUITE( invoke )
BOOST_AUTO_TEST_CASE( a ) {
    ExecResults tested("../bin/dm-materialize rdb2rdf-tests/D017-I18NnoSpecialChars/create.sql");
    BOOST_CHECK_EQUAL(tested.s, 
		      "t\n");
}
BOOST_AUTO_TEST_SUITE_END(/* invoke */)
