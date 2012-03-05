/* test_dm-materialize.cpp - test the ../bin/dm-materialize executable
 *
 * $Id: test_dm-materialize.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#define NEEDDEF_W3C_SW_SAXPARSER
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "interface/SQLclient_MySQL.hpp"
#include "SQLParser/SQLParser.hpp"

#define BOOST_TEST_MODULE dm-materialize
#include <boost/test/unit_test.hpp>
#include <stdio.h>

#define BASE_URI ""
w3c_sw::AtomFactory F;
w3c_sw::TurtleSDriver TurtleParser(BASE_URI, &F);

/* MySQL */
w3c_sw::sql::MySQLSerializer Serializer;
w3c_sw::SQLclient_MySQL SQLDriver;
w3c_sw::sqlContext sqlParserContext;
w3c_sw::SQLDriver SQLParser(sqlParserContext);


struct Init {
    Init () {
	SQLDriver.connect("", "DM", "root");
    }
};
Init init;

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

struct DMTest {
    w3c_sw::DefaultGraphPattern expect;
    w3c_sw::DefaultGraphPattern test;
    DMTest (const char* create, const char* output) {
	w3c_sw::IStreamContext ddlStream(create, w3c_sw::IStreamContext::FILE);
	SQLParser.parse(ddlStream);
	// w3c_sw_LINEN << SQLParser.tables.toString("", "", Serializer);

	for (w3c_sw::sql::schema::Database::const_iterator it = SQLParser.tables.begin();
	     it != SQLParser.tables.end(); ++it) {
	    // w3c_sw_LINEN << it->second->toString("", "", Serializer) << ";" << std::endl;
	    w3c_sw::SQLclient::Result* res = SQLDriver.executeQuery(it->second->toString("", "", Serializer) + ";");
	}
	for (std::vector<const w3c_sw::sql::Insert*>::const_iterator it = SQLParser.inserts.begin();
	     it != SQLParser.inserts.end(); ++it) {
	    // w3c_sw_LINEN << (*it)->toString("", "", Serializer) << ";" << std::endl;
	    w3c_sw::SQLclient::Result* res = SQLDriver.executeQuery((*it)->toString("", "", Serializer) + ";");
	}

	ExecResults tested((std::string() + "../bin/dm-materialize " + create).c_str());
	TurtleParser.parse(tested.s, &test);
	w3c_sw::IStreamContext expStream(output, w3c_sw::IStreamContext::FILE);
	TurtleParser.parse(expStream, &expect);
    }
    ~DMTest () {
	bool keep = false;
	namespace tst = boost::unit_test::framework;
	for (int i = 1; i < tst::master_test_suite().argc; ++i)
	    if (std::string(tst::master_test_suite().argv[i]) == "--keep")
		keep = true;

	if (!keep || expect == test)
	    for (w3c_sw::sql::schema::Database::const_iterator it = SQLParser.tables.begin();
		 it != SQLParser.tables.end(); ++it)
		w3c_sw::SQLclient::Result* res = SQLDriver.executeQuery(std::string() + "DROP TABLE " + Serializer.name(it->first) + ";");
    }
};

#define DMTEST(NAME)				\
    try {					\
	DMTest h(NAME "/create.sql",		\
		 NAME "/directGraph.nt");	\
	BOOST_CHECK_EQUAL(h.expect, h.test);	\
    } catch (std::string& s) {			\
	w3c_sw_LINEN << s << std::endl;		\
    }


BOOST_AUTO_TEST_SUITE( invoke )

BOOST_AUTO_TEST_CASE(_1table1primarykey2columns3rows) { DMTEST("rdb2rdf-tests/D018-1table1primarykey2columns3rows") }
BOOST_AUTO_TEST_CASE(_1table1primarykey3columns2rows1nullvalue) { DMTEST("rdb2rdf-tests/D013-1table1primarykey3columns2rows1nullvalue") }
//BOOST_AUTO_TEST_CASE(_1table1primarykey10columns3rowsSQLdatatypes) { DMTEST("rdb2rdf-tests/D016-1table1primarykey10columns3rowsSQLdatatypes") } SEGV
BOOST_AUTO_TEST_CASE(_1table2columns1row) { DMTEST("rdb2rdf-tests/D004-1table2columns1row") }
//BOOST_AUTO_TEST_CASE(_2tables1primarykey1foreignkey) { DMTEST("rdb2rdf-tests/D009-2tables1primarykey1foreignkey") } SEGV
BOOST_AUTO_TEST_CASE(_I18NnoSpecialChars) { DMTEST("rdb2rdf-tests/D017-I18NnoSpecialChars") }
//BOOST_AUTO_TEST_CASE(_1table1primarykey2columns1row) { DMTEST("rdb2rdf-tests/D007-1table1primarykey2columns1row") }
//BOOST_AUTO_TEST_CASE(_1table1column1row) { DMTEST("rdb2rdf-tests/D001-1table1column1row") }
//BOOST_AUTO_TEST_CASE(_1table1primarykey1column1row) { DMTEST("rdb2rdf-tests/D006-1table1primarykey1column1row") }
//BOOST_AUTO_TEST_CASE(_1table1primarykey3colums3rows) { DMTEST("rdb2rdf-tests/D010-1table1primarykey3colums3rows") }
//BOOST_AUTO_TEST_CASE(_1table3columns1row) { DMTEST("rdb2rdf-tests/D003-1table3columns1row") }
//BOOST_AUTO_TEST_CASE(_3tables1primarykey1foreignkey) { DMTEST("rdb2rdf-tests/D014-3tables1primarykey1foreignkey") } // UNIQUE
//BOOST_AUTO_TEST_CASE(_2tables2duplicates0nulls) { DMTEST("rdb2rdf-tests/D012-2tables2duplicates0nulls") }
BOOST_AUTO_TEST_CASE(_1table3columns1composityeprimarykey3rows2languages) { DMTEST("rdb2rdf-tests/D015-1table3columns1composityeprimarykey3rows2languages") }
//BOOST_AUTO_TEST_CASE(_M2MRelations) { DMTEST("rdb2rdf-tests/D011-M2MRelations") }
//BOOST_AUTO_TEST_CASE(_1table1column0rows) { DMTEST("rdb2rdf-tests/D000-1table1column0rows") }
//BOOST_AUTO_TEST_CASE(_1table2columns1row) { DMTEST("rdb2rdf-tests/D002-1table2columns1row") }
//BOOST_AUTO_TEST_CASE(_1table1compositeprimarykey3columns1row) { DMTEST("rdb2rdf-tests/D008-1table1compositeprimarykey3columns1row") }
//BOOST_AUTO_TEST_CASE(_1table3columns3rows2duplicates) { DMTEST("rdb2rdf-tests/D005-1table3columns3rows2duplicates") }

BOOST_AUTO_TEST_SUITE_END(/* invoke */)


#if 0    
    std::ifstream createStream(create);
    std::istreambuf_iterator<char> createStream_i(createStream), e;
    std::string create(createStream_i, e);

    /* MySQL uses backquotes: */
    size_t p;
    while ((p = create.find_first_of("\"")) != std::string::npos)
	create[p] = '`';
#endif
