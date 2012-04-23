/* test_DM.cpp - test the ../bin/dm-materialize executable
 *
 * $Id: test_DM.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <iostream>
#include <fstream>
#include <sstream>
#define NEEDDEF_W3C_SW_SAXPARSER
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
/* We don't define NEEDDEF_W3C_SW_SQLCLIENT because we link to multiple
 * SQL clients. */
#include "interface/SQLclient.hpp"
#include "SQLParser/SQLParser.hpp"

#undef BOOST_ALL_DYN_LINK // Can't use dynamic linking with init_unit_test_suite()
#include <boost/test/included/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,GraphMatch:3"

#include <sys/types.h>  /* include this before any other sys headers */
#include <sys/wait.h>   /* header for waitpid() and various macros */
#include <signal.h>     /* header for signal functions */
#include <stdio.h>      /* header for fprintf() */
#include <unistd.h>     /* header for fork() */

#define BASE_URI ""
w3c_sw::AtomFactory F;
w3c_sw::TurtleSDriver TurtleParser(BASE_URI, &F);

/* SQL */
w3c_sw::sqlContext sqlParserContext;
w3c_sw::SQLDriver SQLParser(sqlParserContext);

std::string usage (const char* argv0) {
    return std::string()
	+ "Usage: " + argv0 + " <testlist> <testprogram> <SQLspec>* opts\n"
	+ "  e.g. ./test_DM tests.txt ./dm-materialize mysql://root@/DM postgres://DMuser:DMpwd@/DM\n"
	+ "  testlist: file with lines in the form: SQL graph\n"
	+ "          SQL: filepath or URL to create SQL tables.\n"
	+ "          graph: filepath or URL to expected results.\n"
	+ "  testprogram: executable to invoke for each test à la\n"
	+ "          testprogram SQL SQLspec\n"
	+ "          e.g. ./bin/dm-materialize D017-I18NnoSpecialChars/create.sql SQLspec mysql://root@/DM\n"
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
const char* TestProgram;


/** SigChildGuard - capture SIGCHLD signals and record the child return value.
 */
int ChildRet;		// A global to capture the result from a childHandler
bool ChildRetSet;	// and a marker for whether it's set.
struct SigChildGuard {
    struct sigaction oldact;

    SigChildGuard () {
	ChildRetSet = false;
	if (sigaction(SIGCHLD, NULL, &oldact) < 0)
	    throw std::runtime_error("unable to get current SIGCHLD action");

	struct sigaction act;
	sigemptyset(&act.sa_mask); // clear out act's sigset_t

	act.sa_handler = childHandler;
	act.sa_flags = SA_NOCLDSTOP; // only catch terminated children
	if (sigaction(SIGCHLD, &act, NULL) < 0)
	    throw std::runtime_error("unable to set SIGCHLD action");
    }

    ~SigChildGuard () {
	if (sigaction(SIGCHLD, &oldact, NULL) < 0)
	    throw std::runtime_error("unable to restore old SIGCHLD action");
    }

    static void childHandler (int signo) {
	int status, child_val;

	/* Wait for any child without blocking */
	if (waitpid(-1, &status, WNOHANG) < 0) 
	    ; // sometimes returns error in linux
	    // throw std::runtime_error("signal caught but child failed to terminate");
	if (WIFEXITED(status)) {            /* If child exited normally   */
	    ChildRet = WEXITSTATUS(status); /*   get child's exit status. */
	    ChildRetSet = true;
	}
    }
};


/** ExecResults - execute cmd and return the standard output.
 */
struct ExecResults {
    std::string s;
    ExecResults (const char* cmd) {
	{
	    SigChildGuard g;
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
	if (!ChildRetSet)
	    w3c_sw_LINEN "child hasn't terminated\n";
	    // throw std::runtime_error("child hasn't terminated");
	if (ChildRet != 0)
	    std::cout << "child exited with status " << ChildRet << std::endl; \
    }
};

bool operator== (ExecResults& tested, std::string& ref) {
    return tested.s == ref;
}

std::ostream& operator== (std::ostream& o, ExecResults& tested) {
    return o << tested.s;
}


/** DMTest - set up SQL tables, execute a direct mapping dump and
 *  compare results to a reference graph.
 */
struct DMTest {
    w3c_sw::SQLClientList::Connection& client;
    w3c_sw::DefaultGraphPattern expect;
    w3c_sw::DefaultGraphPattern test;
    std::string execStr;
    std::vector<std::string> created;

    DMTest (w3c_sw::SQLClientList::Connection& client)
	: client(client), execStr(TestProgram)
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
	    client.wrap.executeQuery(ss.str());
	    created.push_back(table->first);
	}
	for (std::vector<const w3c_sw::sql::Insert*>::const_iterator it = SQLParser.inserts.begin();
	     it != SQLParser.inserts.end(); ++it) {
	    // w3c_sw_LINEN << (*it)->toString("", "", *client.serializer) << std::endl;
	    client.wrap.executeQuery((*it)->toString(SQLParser.tables, "", "", *client.serializer));
	}

	execStr
	    += " " + client.info.sqlConnectString()
	    + " " + create;

#ifdef DEBUG_SHELL // e.g. -DDEBUG_SHELL=/usr/bin/xterm
	w3c_sw_LINEN << "now invoke " << execStr.c_str() << "\n";
	ExecResults tested(DEBUG_SHELL);
#else
	ExecResults tested(execStr.c_str());
#endif
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
	DMTest h = DMTest(*ment.con);
	h.run(ment.sql, ment.refGraph);
	if (!(h.expect == h.test)) {
	    {
		std::stringstream ss;
		ss << "[[" << h.expect << " != " << h.test << "]]\n";
		doing = ss.str();
	    }
	    errorStr << "[[" << h.expect << " != " << h.test << "]]";
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

    // Populate the EntryList from the invocation parameters.
    for (int i = 3; i < argc; ++i)
	if (std::string(argv[i]) == "")
	    ;
	else if (std::string(argv[i]) == "--keep")
	    Keep = true;
	else if (std::string(argv[i]).substr(0, 2).compare("--"))
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

	    std::stringstream testName;
	    testName << lineNo;
	    boost::unit_test::test_suite* suite = BOOST_TEST_SUITE(testName.str());
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

