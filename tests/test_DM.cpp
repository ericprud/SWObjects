/* test_DM.cpp - test the ../bin/dm-materialize executable
 *
 * The tests require UTF-8 support in the database.

MySQL:
  CREATE USER DM@localhost IDENTIFIED BY "DM";
  GRANT ALL PRIVILEGES ON DM.* TO DM@localhost;
  SET character_set_server = utf8;
  CREATE DATABASE DM;
 or create the database without setting character_set_server:
  CREATE DATABASE DM DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci;
 *
 * $Id: test_DM.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#include <sstream>
#define NEEDDEF_W3C_SW_SAXPARSER
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleParser.hpp"
/* We don't define NEEDDEF_W3C_SW_SQLCLIENT because we link to multiple
 * SQL clients. */
#include "interface/SQLclient.hpp"
#include "SQLParser.hpp"

#undef BOOST_ALL_DYN_LINK // Can't use dynamic linking with init_unit_test_suite()
#include <boost/test/included/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,GraphMatch:3"

#include <sys/types.h>  /* include this before any other sys headers */
#include <signal.h>     /* header for signal functions */
#include <stdio.h>      /* header for fprintf() */
#include <unistd.h>     /* header for fork() */

#define BASE_URI ""
w3c_sw::AtomFactory F;
w3c_sw::TurtleDriver TurtleParser(BASE_URI, &F);

/* SQL */
w3c_sw::sqlContext sqlParserContext;
w3c_sw::SQLDriver SQLParser(sqlParserContext);

std::string usage (const char* argv0) {
    return std::string()
	+ "Usage: " + argv0 + " <testlist> <testprogram> <baseURI> <SQLspec>* opts\n"
	+ "  e.g. ./test_DM tests.txt ./dm-materialize http://example.com/ tests/DM-manifest.txt mysql://root@/DM postgres://DMuser:DMpwd@/DM\n"
	+ "  testlist: file with lines in the form: SQL graph\n"
	+ "          SQL: filepath or URL to create SQL tables.\n"
	+ "          graph: filepath or URL to expected results.\n"
	+ "  testprogram: executable to invoke for each test à la\n"
	+ "          testprogram SQL SQLspec\n"
	+ "          e.g. ./bin/dm-materialize D017-I18NnoSpecialChars/create.sql SQLspec mysql://root@/DM\n"
	+ "  baseURI: base URI for the relative URIs defined by the direct mapping.\n"
	+ "  SQLspec: <driver>://<user>[:password]@[host]/<database>\n"
	+ "          e.g. mysql://root@/DM\n"
	+ "               postgres://DMuser:DMpwd@/DM\n"
	+ "               oracle://DMuser:DMpwd@localhost/ORCL\n"
	+ "  opts: --keep - don't delete the test tables.\n"
	+ "        --run_test= - name a test to run.\n"
	+ "        other boost test args per\n"
        + "<http://www.boost.org/doc/libs/1_45_0/libs/test/doc/html/utf/user-guide/runtime-config/reference.html>.\n";
}

bool Keep = false;
bool Wipe = false;
std::string DebugShell;
const char* TestProgram;

#include "ServerInteraction.hpp"


/** DMTest - set up SQL tables, execute a direct mapping dump and
 *  compare results to a reference graph.
 */
struct DMTest {
    w3c_sw::SQLClientList::Connection& client;
    w3c_sw::DefaultGraphPattern expect;
    w3c_sw::DefaultGraphPattern test;
    std::string execStr;
    std::string baseURI;
    std::vector<std::string> created;

    DMTest (w3c_sw::SQLClientList::Connection& client, std::string baseURI)
	: client(client), execStr(TestProgram), baseURI(baseURI)
    {  }
    void run (const std::string create, const std::string output)
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
	    // w3c_sw_LINEN << ss.str() << std::endl;
	    if (Wipe)
		// Mark for removal even if the creation fails.
		created.push_back(table->first);
	    client.wrap.executeQuery(ss.str());
	    if (!Wipe)
		// Only mark for removal even if the creation succeeds.
		created.push_back(table->first);
	}
	for (std::vector<const w3c_sw::sql::Insert*>::const_iterator it = SQLParser.inserts.begin();
	     it != SQLParser.inserts.end(); ++it) {
	    // w3c_sw_LINEN << (*it)->toString("", "", *client.serializer) << std::endl;
	    client.wrap.executeQuery((*it)->toString(SQLParser.tables, "", "", *client.serializer));
	}

	execStr
	    += " " + baseURI
	    + " " + client.info.sqlConnectString()
	    + " " + create;

	if (DebugShell.size() != 0) {
	    w3c_sw_LINEN << "now invoke " << execStr.c_str() << "\n";
	    execStr = DebugShell;
	}
	w3c_sw::OutputFromNonInteractiveProcess tested(execStr.c_str());

	// w3c_sw_LINEN << "DM graph: [[[" << tested.s << "]]]\n";
	TurtleParser.parse(tested.s, &test);
	w3c_sw::IStreamContext expStream(output, w3c_sw::IStreamContext::FILE);
	TurtleParser.parse(expStream, &expect);
    }
    ~DMTest () {
	if (!Keep || (test.size() > 0 && expect.size() > 0 && expect == test))
	    for (std::vector<std::string>::const_iterator it = created.begin();
		 it != created.end(); ++it) {
		// w3c_sw_LINEN << "DROP TABLE " << client.serializer->name(*it) << "\n";
		client.wrap.executeQuery(std::string() + "DROP TABLE "
					 + client.serializer->name(*it));
	    }
	else
	    std::cerr << "unexpected results from: " << execStr << "\n";

	SQLParser.tables.clear();
	SQLParser.inserts.clear();
    }
};


std::ostream& operator<< (std::ostream& os, const w3c_sw::SQLConnectInfo& info) {
    os << info.sqlConnectString();
    return os;
}

std::ostream& operator<< (std::ostream& os, const w3c_sw::SQLClientList::Connection& con) {
    // SQLConnectInfo info;
    // SQLClientWrapper wrap;
    // sql::Serializer* serializer;
    os << con.info;
    return os;
}


/** ManifestEntry - Direct Mapping test parameters.
 */
struct ManifestEntry {
    size_t lineNo;
    std::string sql;
    std::string refGraph;
    w3c_sw::SQLClientList::Connection* con;
    ManifestEntry (size_t lineNo, std::string sql, std::string refGraph, w3c_sw::SQLClientList::Connection* con)
	: lineNo(lineNo), sql(sql), refGraph(refGraph), con(con)
    {  }
    std::ostream& print (std::ostream& os) const {
	os << lineNo << "(" << *con << ") " << sql << " " << refGraph;
	return os;
    }
};

std::ostream& operator<< (std::ostream& os, const ManifestEntry& ment) {
    return ment.print(os);
}


// EntryList - a global list of test descriptions.
std::vector<ManifestEntry> EntryList;
std::vector<ManifestEntry>::const_iterator EntryListit;

std::string BaseURI;
std::string ManifestFile;

/** expectGraph - execute the test at the EntryList iterator.
 */
void expectGraph () {
    std::string doing;
    std::stringstream errorStr;
    size_t lineNo;
    try {
	BOOST_ASSERT(!(EntryListit == EntryList.end()));
	const ManifestEntry& ment = *EntryListit++;
	lineNo = ment.lineNo;
	doing = "setting up";
	DMTest h = DMTest(*ment.con, BaseURI);
	h.run(ment.sql, ment.refGraph);
	if (!(h.expect == h.test)) {
	    {
		std::stringstream ss;
		ss << "[[" << h.expect << " ?= " << h.test << "]]\n";
		doing = ss.str();
	    }
	    errorStr << "expect != test [[" << h.expect << " != " << h.test << "]]";
	}
	doing = "tearing down";
    } catch (w3c_sw::ParserException& p) {
	errorStr << "ParserException while " << doing << ": " << p.what();
    } catch (std::string& s) {
	errorStr << "std::string exception while " << doing << ": " << s;
    } catch (std::exception& e) {
	errorStr << "std::exception exception while " << doing << ": " << e.what();
    } catch (...) {
	errorStr << "unknown exception while " << doing;
    }
    if (!errorStr.str().empty())
	::boost::test_tools::tt_detail::check_impl
	      ((false),
	       ::boost::unit_test::lazy_ostream::instance() << errorStr.str(),
	       ManifestFile,
	       static_cast<std::size_t>(lineNo),
	       ::boost::test_tools::tt_detail::CHECK,
	       ::boost::test_tools::tt_detail::CHECK_MSG,
	       0);
}


// A global list of connections which hold the Connection pointers in
// the EntryList.
w3c_sw::SQLClientList connections;

/** init_unit_test_suite - init function called by boost::tests's main.
 * This reads a manifest and populates the EntryList.
 */
boost::unit_test::test_suite*
init_unit_test_suite (int argc, char* argv[])  {

    if (argc < 3)
	throw std::runtime_error(usage(argv[0]));
    ManifestFile = argv[1];
    std::ifstream testList(ManifestFile.c_str());
    TestProgram = argv[2];
    BaseURI = argv[3];
    if (BaseURI == ".")
	BaseURI.clear();

    // Populate the EntryList from the invocation parameters.
    for (int i = 4; i < argc; ++i)
	if (std::string(argv[i]) == "")
	    ;
	else if (std::string(argv[i]) == "--keep")
	    Keep = true;
	else if (std::string(argv[i]) == "--wipe")
	    Wipe = true;
	else if (!std::string(argv[i]).compare(0, 13, "--debug-shell")) {
	    std::string arg(argv[i]);
	    if (arg[13] == '=')
		DebugShell = arg.substr(14);
	    else if (i < argc-1)
		DebugShell = argv[++i];
	    else
		throw std::runtime_error("missing argument to --debug-shell");
	} else if (std::string(argv[i]).substr(0, 2).compare("--"))
	    connections.add(argv[i]);

    // Parse the manifest file and populate EntryList.
    char buf[1024];
    size_t lineNo = 0;
    while (testList.getline(buf, 1024)) {
	++lineNo;
	if (buf[0] == '#' || buf[0] == '\0') {
	    // Skip empty and leading comment characters.

	} else {

	    // Parse two paths from the manifest file line.
	    std::stringstream ss(buf);
	    std::string sql, refGraph;
	    ss >> sql >> refGraph;

	    size_t nameEnd = sql.rfind('/');
	    size_t nameStart = sql.rfind('/', nameEnd-1);
	    std::string testName(sql.substr(nameStart+1, nameEnd - nameStart-1)); // could use lineNo
	    boost::unit_test::test_suite* suite = BOOST_TEST_SUITE(testName);
	    boost::unit_test::framework::master_test_suite().add(suite);

	    for (std::vector<w3c_sw::SQLClientList::Connection>
		     ::iterator connection = connections.begin();
		 connection != connections.end(); ++connection) {

		// Add to and entry to EntryList.
		EntryList.push_back(ManifestEntry(lineNo, sql,
						  refGraph, &*connection));

		// Tell the boost test harness to add an invocation of
		// expectGraph.
		suite->add(boost::unit_test::make_test_case
			   (boost::unit_test::callback0<>(&expectGraph),
			    connection->info.driver));
 	    }
	}
    }

    // Start the EntryList iterator at top of the list.
    EntryListit = EntryList.begin();
    return NULL;
}

