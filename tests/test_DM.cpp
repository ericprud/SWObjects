/* test_DM.cpp - test the ../bin/dm-materialize executable
 *
 * $Id: test_DM.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#define NEEDDEF_W3C_SW_SAXPARSER
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
/* We don't define NEEDDEF_W3C_SW_SQLCLIENT because we link to multiple
 * SQL clients. */
#include "interface/SQLclient.hpp"
#include "SQLParser/SQLParser.hpp"
#define BOOST_TEST_NO_MAIN

#define BOOST_TEST_MODULE DM
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,GraphMatch:3"

#define BASE_URI ""
w3c_sw::AtomFactory F;
w3c_sw::TurtleSDriver TurtleParser(BASE_URI, &F);

/* SQL */
w3c_sw::sqlContext sqlParserContext;
w3c_sw::SQLDriver SQLParser(sqlParserContext);
w3c_sw::SQLClientList connections;

std::string usage (const char* argv0) {
    return std::string()
	+ "Usage: " + argv0 + " <SQLspec> opts\n"
	+ "  opts: --keep - don't delete the test tables.\n"
	+ "        --run_test= - name a test to run.\n"
	+ "        other boost test args per\n"
        + "<http://www.boost.org/doc/libs/1_45_0/libs/test/doc/html/utf/user-guide/runtime-config/reference.html>.\n";
}

bool Keep = false;
const char* TestProgram;

int BOOST_TEST_CALL_DECL
main( int argc, char* argv[] )
{
    // namespace tst = boost::unit_test::framework;
    // const int argc = tst::master_test_suite().argc;
    // char** argv = tst::master_test_suite().argv;
    if (argc < 3)
	throw std::runtime_error(usage(argv[0]));
    TestProgram = argv[1];
    for (int i = 2; i < argc; ++i)
	if (std::string(argv[i]) == "")
	    ;
	else if (std::string(argv[i]) == "--keep")
	    Keep = true;
	else if (std::string(argv[i]).substr(0, 2).compare("--"))
	    connections.add(argv[i]);
    return ::boost::unit_test::unit_test_main( &init_unit_test, argc, argv );
}

struct ExecResults {
    std::string s;
    ExecResults (const char* cmd) {
	s  = "execution failure";
	FILE *p = ::popen(cmd, "r");
	BOOST_REQUIRE(p != NULL);
	char buf[100];
	s = "";

	/* Gave up on [[ ferror(p) ]] because it sometimes returns EPERM on OSX. */
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
    w3c_sw::SQLClientList::Connection& client;
    w3c_sw::DefaultGraphPattern expect;
    w3c_sw::DefaultGraphPattern test;
    std::string execStr;

    DMTest (w3c_sw::SQLClientList::Connection& client)
	: client(client), execStr(TestProgram)
    {  }
    void run (const char* create, const char* output)
    {
	w3c_sw::IStreamContext ddlStream(create, w3c_sw::IStreamContext::FILE);
	SQLParser.parse(ddlStream);
	// w3c_sw_LINEN << SQLParser.tables.toString("", "", *client.serializer);

	for (w3c_sw::sql::schema::Database::const_iterator table = SQLParser.tables.begin();
	     table != SQLParser.tables.end(); ++table) {
	    std::stringstream ss;
	    ss << "CREATE TABLE " << client.serializer->name(table->first) << " (\n";
	    size_t fieldCount = 0;
	    for (std::vector<const w3c_sw::sql::schema::FieldOrKey*>::const_iterator it = (*table->second).begin();
		 it != (*table->second).end(); ++it) {
		// strip out foreign keys.
		if (dynamic_cast<const w3c_sw::sql::schema::ForeignKey*>(*it) == NULL) {
		    if (fieldCount > 0)
			ss << ",\n";
		    ++fieldCount;
		    ss << "  " << (*it)->toString("", "", *client.serializer);
		}
	    }
	    ss << "\n)";
	    // w3c_sw_LINEN << ss.str() << ";" << std::endl;
	    client.wrap.executeQuery(ss.str() + ";");
	}
	for (std::vector<const w3c_sw::sql::Insert*>::const_iterator it = SQLParser.inserts.begin();
	     it != SQLParser.inserts.end(); ++it) {
	    // w3c_sw_LINEN << (*it)->toString("", "", *client.serializer) << ";" << std::endl;
	    client.wrap.executeQuery((*it)->toString("", "", *client.serializer) + ";");
	}

	execStr
	    += " " + client.info.sqlConnectString()
	    + " " + create;

	ExecResults tested(execStr.c_str());
	// w3c_sw_LINEN << "DM graph: " << tested.s << "\n";
	TurtleParser.parse(tested.s, &test);
	w3c_sw::IStreamContext expStream(output, w3c_sw::IStreamContext::FILE);
	TurtleParser.parse(expStream, &expect);
    }
    ~DMTest () {
	if (!Keep || (test.size() > 0 && expect.size() > 0 && expect == test))
	    for (w3c_sw::sql::schema::Database::const_iterator it = SQLParser.tables.begin();
		 it != SQLParser.tables.end(); ++it)
		client.wrap.executeQuery(std::string() + "DROP TABLE "
					 + client.serializer->name(it->first) + ";");
	else
	    std::cerr << "failed to execute: " << execStr << "\n";

	SQLParser.tables.clear();
	SQLParser.inserts.clear();
    }
};

#define DMTEST(NAME)						\
    try {							\
	for (std::vector<w3c_sw::SQLClientList::Connection>	\
	     ::iterator connection = connections.begin();	\
	     connection != connections.end();			\
	     ++connection) {					\
	    DMTest h = DMTest(*connection);			\
	    h.run(NAME "create.sql", NAME "directGraph.ttl");	\
	    BOOST_CHECK_EQUAL(h.expect, h.test);		\
	}							\
    } catch (w3c_sw::ParserException& p) {			\
	BOOST_FAIL(std::string("ParserException:") + p.what());	\
    } catch (std::string& s) {					\
	BOOST_FAIL(std::string("std::string exception:") + s);	\
    } catch (std::exception& e) {				\
	BOOST_FAIL(std::string("std::exception:") + e.what());	\
    } catch (...) {						\
	BOOST_FAIL("unknown exception");			\
    }								\


BOOST_AUTO_TEST_SUITE( committed )
BOOST_AUTO_TEST_CASE(_1table1column0rows)                                 { DMTEST("rdb2rdf-tests/D000-1table1column0rows/") }
BOOST_AUTO_TEST_CASE(_1table1column1row)                                  { DMTEST("rdb2rdf-tests/D001-1table1column1row/") }
BOOST_AUTO_TEST_CASE(_1table2columns1row_2)                               { DMTEST("rdb2rdf-tests/D002-1table2columns1row/") }
BOOST_AUTO_TEST_CASE(_1table3columns1row)                                 { DMTEST("rdb2rdf-tests/D003-1table3columns1row/") }
BOOST_AUTO_TEST_CASE(_1table2columns1row_4)                               { DMTEST("rdb2rdf-tests/D004-1table2columns1row/") }
BOOST_AUTO_TEST_CASE(_1table3columns3rows2duplicates)                     { DMTEST("rdb2rdf-tests/D005-1table3columns3rows2duplicates/") }
BOOST_AUTO_TEST_CASE(_1table1primarykey1column1row)                       { DMTEST("rdb2rdf-tests/D006-1table1primarykey1column1row/") }
BOOST_AUTO_TEST_CASE(_1table1primarykey2columns1row)                      { DMTEST("rdb2rdf-tests/D007-1table1primarykey2columns1row/") }
BOOST_AUTO_TEST_CASE(_1table1compositeprimarykey3columns1row)             { DMTEST("rdb2rdf-tests/D008-1table1compositeprimarykey3columns1row/") }
BOOST_AUTO_TEST_CASE(_2tables1primarykey1foreignkey)                      { DMTEST("rdb2rdf-tests/D009-2tables1primarykey1foreignkey/") }
BOOST_AUTO_TEST_CASE(_1table1primarykey3colums3rows)                      { DMTEST("rdb2rdf-tests/D010-1table1primarykey3colums3rows/") }
BOOST_AUTO_TEST_CASE(_M2MRelations)                                       { DMTEST("rdb2rdf-tests/D011-M2MRelations/") }
BOOST_AUTO_TEST_CASE(_2tables2duplicates0nulls)                           { DMTEST("rdb2rdf-tests/D012-2tables2duplicates0nulls/") }
BOOST_AUTO_TEST_CASE(_1table1primarykey3columns2rows1nullvalue)           { DMTEST("rdb2rdf-tests/D013-1table1primarykey3columns2rows1nullvalue/") }
BOOST_AUTO_TEST_CASE(_3tables1primarykey1foreignkey)                      { DMTEST("rdb2rdf-tests/D014-3tables1primarykey1foreignkey/") }
BOOST_AUTO_TEST_CASE(_1table3columns1composityeprimarykey3rows2languages) { DMTEST("rdb2rdf-tests/D015-1table3columns1composityeprimarykey3rows2languages/") }
BOOST_AUTO_TEST_CASE(_1table1primarykey10columns3rowsSQLdatatypes)        { DMTEST("rdb2rdf-tests/D016-1table1primarykey10columns3rowsSQLdatatypes/") }
BOOST_AUTO_TEST_CASE(_I18NnoSpecialChars)                                 { DMTEST("rdb2rdf-tests/D017-I18NnoSpecialChars/") }
BOOST_AUTO_TEST_CASE(_1table1primarykey2columns3rows)                     { DMTEST("rdb2rdf-tests/D018-1table1primarykey2columns3rows/") }
BOOST_AUTO_TEST_SUITE_END(/* committed */)

BOOST_AUTO_TEST_SUITE( ericPz )
BOOST_AUTO_TEST_CASE(ref_no_pk)      { DMTEST("rdb2rdf-tests/ref-no-pk/") }
BOOST_AUTO_TEST_CASE(ref_not_pk)     { DMTEST("rdb2rdf-tests/ref-not-pk/") }
BOOST_AUTO_TEST_CASE(ref_some_nulls) { DMTEST("rdb2rdf-tests/ref-some-nulls/") }
BOOST_AUTO_TEST_CASE(ref_all_nulls)  { DMTEST("rdb2rdf-tests/ref-all-nulls/") }
BOOST_AUTO_TEST_SUITE_END(/* ericPz */)

BOOST_AUTO_TEST_SUITE( spec )
BOOST_AUTO_TEST_CASE(ref_no_pk)  { DMTEST("rdb2rdf-tests/spec-ref-no-pk/") }
BOOST_AUTO_TEST_SUITE_END(/* spec */)
