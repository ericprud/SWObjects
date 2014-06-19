/** MSSQL - C++ wrapper for freetds to enable simultaneous connections to one or
 * more databases.
 *
 * build:
     g++ -DMSSQL_MAIN -Wall -g -o freetdsSample freetdsSample.cpp -lsybdb
     optionally add -DMSSQL_THREADING -std=c++0x

 * run:
     freetdsSample -S server -D database -U user_dwh -P password \
       'SELECT "1" AS a, "2" AS b, "3" AS c UNION ALL SELECT "4", "5", "6"' \
       'SELECT "A" AS a, "B" AS b, "C" AS c UNION ALL SELECT "D", "E", "F"' \
       'SELECT "a" AS a, "b" AS b, "c" AS c UNION ALL SELECT "d", "e", "f"' \
       2> stderr ; cat stderr 

 * copyright 2014 Eric Prud'hommeaux 
 * This free softare is released under the MIT license.
 * <http://opensource.org/licenses/MIT> (which basically means you can do
 * whatever you want with or without notification or credit.)
 *
 * Bugs:
 *   Don't delete a ClientConnection before all of its query results are
 *   deleted.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <memory>
#include <stdlib.h> // exit
#include <string.h>
#include <assert.h>
#include <stdexcept>

#ifdef MSSQL_THREADING
  #include <mutex>
#endif

#include <sybfront.h>	/* sybfront.h always comes first */
#include <sybdb.h>	/* sybdb.h is the only other file you need */

namespace MSSQL {

    struct Result;

    struct ErrorHandler {
	/** fault - internal errors like connection, memory, etc. */
	virtual void fault (int line, std::string what) {
	    std::stringstream ss; ss << line << ": " << what;
	    throw std::runtime_error(ss.str());
	}
	/** error - error messags from the server or library. */
	virtual void error (std::string what) { std::cerr << what; }
	/** msg - "msg" messags from the server or library. */
	virtual void msg (std::string what) { std::cerr << what; }

	// it would be nice to create a boost::log-like ostream which would
	// behave like an ostream but flush on std::endl:
        //   ostringstream& op<<(errorHandler_t& h, err_stream_t& unused) { /* ... */ ; return h.stringstream; }

	/** msg_handler - default function for building message strings. */
	virtual int msg_handler (DBPROCESS */* dbproc */, DBINT msgno, int msgstate, int severity,
			 char *msgtext, char *srvname, char *procname, int line)
	{									/* (1) */
	    enum {changed_database = 5701, changed_language = 5703 };		/* (2) */

	    if (msgno == changed_database || msgno == changed_language)
		return 0;

	    std::stringstream ss;
	    if (msgno > 0) {
		ss << "Msg " << msgno << ", Level " << severity << ", State " << msgstate << "\n";

		if (strlen(srvname) > 0)
		    ss << "Server '" << srvname << "', ";
		if (strlen(procname) > 0)
		    ss << "Procedure '" << procname << "', ";
		if (line > 0)
		    ss << "Line " << line << "";

		ss << "\n\t";
	    }
	    ss << msgtext << "\n";

	    if (severity > 10) {						/* (3) */
		ss << "error: severity " << severity << " > 10, exiting\n";
		error(ss.str());
	    } else {
		msg(ss.str());
	    }

	    return 0;							/* (4) */
	}

	/** err_handler - default function for building error strings. */
	virtual int err_handler (DBPROCESS */* dbproc */, int severity, int dberr, 
				 int /* oserr */, char *dberrstr, char */* oserrstr */)
	{									/* (5) */
	    if (dberr) {							/* (6) */
		std::stringstream ss; ss << "Msg " << dberr << ", Level " << severity << "\n";
		ss << dberrstr << "\n\n";
		error(ss.str());
	    } else {
		std::stringstream ss; ss << "DB-LIBRARY error:\n\t" << dberrstr << "\n";
		error(ss.str());
	    }
	    // returns INT_EXIT | INT_CANCEL (SQLETIME) | INT_CONTINUE (SQLETIME)
	    return INT_CANCEL;						/* (7) */
	}
    };

    /** ClientConnection - manage a connection to a single client with a given
     * host, usernane, password, and database.  */
    struct ClientConnection {
	// call dbexit when lsat copy of ClientConnection is destroyed.
	struct DBInitExitScope {
	    static size_t& getConnectionCount () {
		static size_t count = 0;
		return count;
	    }
	    DBInitExitScope () {
		/* (1) */
		if (getConnectionCount() == 0)
		    if (dbinit() == FAIL)
			throw std::runtime_error("couldn't initialize sybdb");
		getConnectionCount()++;
	    }
	    DBInitExitScope (const DBInitExitScope&) {
		getConnectionCount()++;
	    }
	    ~DBInitExitScope () {
		getConnectionCount()--;
		if (getConnectionCount() == 0)
		    dbexit();
	    }
	};
	DBInitExitScope _dummy;
	ErrorHandler* connectionErrorHandler;

	std::vector<DBPROCESS*> processes; // list of dbopened processes.
	std::stack<int> available;  // which of those are NOT in use.
	std::string servername, dbname, username, password; // connection parameters.

	static ErrorHandler* _getDefaultErrorHandler () { // default ErrorHandler object.
	    static ErrorHandler h;
	    return &h;
	}
	static std::map<DBPROCESS*, ErrorHandler*>& _getErrorHandlerMap () { // handler for each process.
	    static std::map<DBPROCESS*, ErrorHandler*> m;
	    return m;
	}
	static std::ostream& _printErrorHandlers (std::ostream& os) {
	    std::map<DBPROCESS*, ErrorHandler*>& m = _getErrorHandlerMap();
	    for (std::map<DBPROCESS*, ErrorHandler*>::const_iterator it = m.begin(); it != m.end(); ++it)
		os << it->first << ": " << it->second << "\n";
	    return os;
	}
	static void _dumpErrorHandlers () { _printErrorHandlers(std::cerr); }
	static ErrorHandler* getErrorHandler (DBPROCESS* dbproc) { // manage the process/handler map.
	    std::map<DBPROCESS*, ErrorHandler*>& m = _getErrorHandlerMap();
	    std::map<DBPROCESS*, ErrorHandler*>::iterator it = m.find(dbproc);
	    if (it == m.end())
		it = m.find(NULL);
	    if (it == m.end()) {
		std::stringstream ss;
		_printErrorHandlers(ss);
		throw std::runtime_error("unexpected lack of error handler in:\n" + ss.str());
	    }
	    return it->second;
	}

	ClientConnection (ErrorHandler* connectionErrorHandler = _getDefaultErrorHandler())
	    : connectionErrorHandler(connectionErrorHandler)
	{  }
	~ClientConnection () {
	    // if (_dummy.getConnectionCount() == 0) // can't check before _dummy is destroyed.
	    while (available.size()) {
		dbclose(processes[available.top()]); // close pending available.
		available.pop();
	    }
	}


	// Global handler hooks passed to freeTDS library.
	static int
	msg_handler(DBPROCESS *dbproc, DBINT msgno, int msgstate, int severity,
		    char *msgtext, char *srvname, char *procname, int line)
	{
	    return getErrorHandler(dbproc)->msg_handler(dbproc, msgno, msgstate, severity,
							msgtext, srvname, procname, line);
	}

	static int
	err_handler(DBPROCESS * dbproc, int severity, int dberr, 
		    int oserr, char *dberrstr, char *oserrstr)
	{
	    // _dumpErrorHandlers();
	    // { std::stringstream ss; ss << "200 errorHandler(" << getErrorHandler(dbproc) << ")->msg(...)\n"; getErrorHandler(dbproc)->msg(ss.str()); }
	    return getErrorHandler(dbproc)->err_handler(dbproc, severity, dberr, 
							oserr, dberrstr, oserrstr);
	}

	// dbopen, login, use database,
	void _makeConnection (ErrorHandler* errorHandler) {
	    /* Make sure that only one thread calls dbopen at a time because it
	     * can call err_handler and we can't set bdproc's errorHandler until
	     * it's returned back from dbopen.
	     */
#ifdef MSSQL_THREADING
	    static std::mutex openGuard;
	    openGuard.lock();
#endif
	    _getErrorHandlerMap()[NULL] = errorHandler;

	    LOGINREC *login;	/* (1) */

	    /* (2) */
	    dberrhandle(err_handler);
	    dbmsghandle(msg_handler);

	    /* (3) */
	    if ((login = dblogin()) == NULL)
		errorHandler->fault(__LINE__, "unable to allocate login structure\n");

	    /* (4) */
	    DBSETLUSER(login, username.c_str());
	    DBSETLPWD(login, password.c_str());

	    DBPROCESS *dbproc;

	    if ((dbproc = dbopen(login, servername.c_str())) == NULL) {
		std::stringstream ss; ss << "unable to connect to " << servername << " as " << username << "\n";
		errorHandler->fault(__LINE__, ss.str());
	    }
	    _getErrorHandlerMap()[dbproc] = errorHandler;
	    _getErrorHandlerMap().erase(NULL);
#ifdef MSSQL_THREADING
	    openGuard.unlock();
#endif
	    dbloginfree(login);

	    if (dbname.size() && dbuse(dbproc, dbname.c_str()) == FAIL) {
		std::stringstream ss; ss << "unable to connect to " << dbname << "\n";
		errorHandler->fault(__LINE__, ss.str());
	    }

	    available.push(processes.size());
	    processes.push_back(dbproc);
	}

	/** connect - make a connection to a database with given credentials. */
	void
	connect (std::string servername, std::string dbname,
		 std::string username, std::string password) {
	    this->servername = servername;
	    this->dbname = dbname;
	    this->username = username;
	    this->password = password;
	    _makeConnection(connectionErrorHandler); // constructed anticipating one thread use.
	}

	Result executeQuery(std::string query, ErrorHandler* errorHandler = NULL);

	// Make the DBPROCESS available for next executeQuery.
	void relinquish (size_t proc) {
	    available.push(proc);
	    _getErrorHandlerMap().erase(processes[proc]);
	}

    };

    /** COL - structure for receiving the values and NULL states from the database. */
    struct COL {						/* (1) */
	char *name;
	int type, status;
	size_t _size;
	std::string buffer;
	COL (char* name, int type, size_t size)
	    : name(name), type(type), _size(size)
	{
	    // note { string s; s.resize(5); strcpy(&s[0], "123"); s.resize(strlen(s.data())); cout << s; }
	    buffer.resize(_size+1);
	    if (::strlen(name) > size)
		_size = ::strlen(name);
	}
	bool operator== (const COL& r) const {
	    return name == r.name && type == r.type && _size == r._size && status == r.status && buffer == r.buffer;
	}
	const char* lexical () const {
	    return buffer.data();
	}
	int size () const { return _size; }
	bool isNULL () const { return status == -1; }
    };
    typedef std::vector<COL> Values;

    /** Row - all columns for a given row in the database.
     * TODO: add size() and operator[] for int-based access?
     */
    struct Row {
	DBPROCESS *dbproc;
	Values& values;
	Row (DBPROCESS* dbproc, Values& values)
	    : dbproc(dbproc), values(values)
	{  }
	Row& operator= (const Row& r) { dbproc = r.dbproc; values = r.values; return *this; }
	bool operator== (const Row& r) const {
	    return dbproc == r.dbproc && values == r.values;
	}
	Values::const_iterator begin () const {
	    return values.begin();
	}
	Values::const_iterator end () const {
	    return values.end();
	}
    };
    // bool operator== (const Row& l, const Row& r) { return l.operator==(r); }
    // bool operator!= (const Row& l, const Row& r) { return !( l == r ); }

    /** Result - all columns for a given row in the database. */
    struct Result {
	struct ReuseProcess {

	    // DBPROCESS handles can be re-used after all rows have been
	    // consumed. Otherise, you get this error:
	    // Attempt to initiate a new Adaptive Server operation with results pending

	    ClientConnection* conn;
	    int proc;
	    int refcount;
	    bool _exhausted;
	    Values values;
	    ReuseProcess (ClientConnection* conn, int proc)
		: conn(conn), proc(proc), refcount(0), _exhausted(false)
	    {  }
	    ~ReuseProcess () {
		if (_exhausted)
		    conn->relinquish(proc);
	    }
	    void exhausted () { _exhausted = true; }
	};

	/** InputIterator idiom for a single traversal through the results. */
	struct iterator {
	    DBPROCESS *dbproc;
	    Row row;
	    bool end;
	    ReuseProcess* reuse;
	    iterator (DBPROCESS *dbproc, Values& values, ReuseProcess* reuse)
		: dbproc(dbproc), row(dbproc, values), end(false), reuse(reuse)
	    {  }
	    iterator (Values& values)
		: dbproc(NULL), row(dbproc, values), end(true), reuse(NULL)
	    {  }
	    iterator operator++ () {
		switch (dbnextrow(dbproc)) {
		case NO_MORE_ROWS:	/* (6) */
		    end = true;
		    reuse->exhausted();
		    break;
		case REG_ROW:
		    break;
		case BUF_FULL:
		    ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, "BUF_FULL");
		case FAIL:
		    ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, "FAIL");
		default: 					/* (7) */
		    ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, "Compute IDs not supported.");
		}
		return *this;
	    }
	    iterator operator++ (int) {
		iterator tmp(*this);
		operator++();
		return tmp;
	    }
	    bool operator== (const iterator& r) const {
		if (end) return r.end;
		return dbproc == r.dbproc && row == r.row && end == r.end;
	    }
	    Row operator* () {
	    	return row;
	    }
	    Row* operator-> () {
		return &row;
	    }
	};
	ReuseProcess* reuse;
	DBPROCESS* dbproc;
	int ncols;
	Values& values;

	/** Result constructor - creates a place for the library to write the
	 * query results as each successive row comes back.
	 */
	Result (ReuseProcess* reuse)
	    : reuse(reuse), 
	      dbproc(reuse->conn->processes[reuse->proc]), ncols(dbnumcols(dbproc)), values(reuse->values)
	{
	    ++reuse->refcount;
	    values.reserve(ncols);
	    /*
	     * Read metadata and bind.
	     */
	    for (int curCol = 0; curCol < ncols; ++curCol) {
		int c = curCol + 1;
		int type = dbcoltype(dbproc, c);
		int size = (SYBCHAR == type)
		    ? dbcollen(dbproc, c)           /* pcol->size = n if the field is a CHAR(n). */
		    : dbwillconvert(type, SYBCHAR); /* Otherwise, dbwillconvert gives the max string width. */
		values.push_back(COL(dbcolname(dbproc, c),		/* (2) */
				     type, size
				     ));

		COL* pcol = &values[curCol];

		RETCODE erc;		/* (3) */
		erc = dbbind(dbproc, c, NTBSTRINGBIND,	/* (4) */
			     size+1, (BYTE*)&pcol->buffer[0]);
		if (erc == FAIL) {
		    std::stringstream ss; ss << "dbbind(" << c << ") failed\n";
		    ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, ss.str());
		}
			
		erc = dbnullbind(dbproc, c, &pcol->status);	/* (5) */
		if (erc == FAIL) {
		    std::stringstream ss; ss << "dbnullbind(" << c << ") failed\n";
		    ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, ss.str());
		}
	    }
	}
	Result (Result const &r)
	    : reuse(r.reuse), dbproc(r.dbproc), ncols(r.ncols), values(r.values)
	{
	    ++reuse->refcount;
	}
	Result& operator=(Result const &r) {
	    ReuseProcess* const old = reuse;
	    reuse = r.reuse;
	    ++reuse->refcount;
	    if (--old->refcount == 0) delete old;
	    return *this;
	}

	~Result () {
	    if (--reuse->refcount == 0) {
		/*
		 * Check return status. @@ This doesn't really fit in standard SQL APIs.
		 */
		if (dbhasretstat(dbproc) == TRUE) {
		    std::cout << "Procedure returned " << dbretstatus(dbproc) << "\n";
		}

		delete reuse;
	    }
	}


	/** rowCount - how many rows have been seen in the query results.
	 * returns:
	 *   -1: unknown.
	 */
	int rowCount () {
	    return DBCOUNT(dbproc);
	}

	/** headers - make header names visible. */
	const Values& headers () { return values; }

	iterator begin () {
	    switch (dbnextrow(dbproc)) {
	    case NO_MORE_ROWS:	/* (6) */
		reuse->exhausted();
		return end();
	    case REG_ROW:
		return iterator(dbproc, values, reuse);
	    case BUF_FULL:
		ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, "BUF_FULL");
	    case FAIL:
		ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, "FAIL");
	    default: 					/* (7) */
		ClientConnection::getErrorHandler(dbproc)->fault(__LINE__, "Compute IDs not supported.");
	    }
	    throw std::runtime_error("fault() function should not return");
	}
	iterator end () {
	    return iterator(values);
	}
    };
    bool operator== (const Result::iterator& l, const Result::iterator& r) { return l.operator==(r); }
    bool operator!= (const Result::iterator& l, const Result::iterator& r) { return !(l.operator==(r)); }

    /** executeQuery - send a query to the server and create a Row object with
     * the first set of results. */
    inline Result ClientConnection::executeQuery (std::string query, ErrorHandler* errorHandler) {
	if (errorHandler == NULL)
	    errorHandler = connectionErrorHandler; // can't be NULL

	RETCODE erc;		/* (3) */

	if (available.size() == 0)
	    _makeConnection(errorHandler);
	size_t curProc = available.top();
	_getErrorHandlerMap()[processes[curProc]] = errorHandler;
	available.pop();
	if ((erc = dbfcmd(processes[curProc], "%s ", query.c_str())) == FAIL)
	    errorHandler->fault(__LINE__, "dbcmd() failed\n");
 
	if ((erc = dbsqlexec(processes[curProc])) == FAIL)
	    errorHandler->fault(__LINE__, "dbsqlexec() failed\n");

	if ((erc = dbresults(processes[curProc])) == NO_MORE_RESULTS) {
	    throw "!! what to do when single query returns NO_MORE_RESULTS?";
	} else {
	    if (erc == FAIL)
		errorHandler->fault(__LINE__, "dbresults failed\n");
	    Result::ReuseProcess* process = new Result::ReuseProcess(this, curProc);
	    // !!TODO: store localy so ~ClientConnection can detach any pending processes.
	    return Result(process);
	}
    }
}

#ifdef MSSQL_MAIN
const static char syntax[] =
    " query -S server -D db -U user -P passwd\n";

extern char *optarg; // globals required by getopt
extern int optind;

int
main(int argc, char *argv[])
{
    std::string appname = basename(argv[0]);
    std::string servername, dbname, username, password;
    {
	int ch;
	while ((ch = getopt(argc, argv, "U:P:S:D:?")) != -1) {
	    switch (ch) {
	    case 'S':
		servername = optarg;
		break;
	    case 'D':
		dbname = optarg;
		break;
	    case 'U':
		username = optarg;
		break;
	    case 'P':
		password = optarg;
		break;
	    case '?':
		std::cout << "usage: " << appname << syntax;
		exit(1);
	    default:
		throw std::runtime_error(std::string("usage: ") + appname + syntax);
	    }
	}
    }
    if (!servername.size() || !username.size() || !password.size())
	throw std::runtime_error(std::string("usage: ") + appname + syntax);
    argc -= optind; // crazy getopt idiom
    argv += optind;

    /* freetdsSample.c prefixes all error messages with argv[0]. */
    struct MyErrorHandler : public MSSQL::ErrorHandler {
	std::string appname;
	MyErrorHandler (std::string appname) : appname(appname) {   }
	virtual void fault (int line, std::string what) {
	    std::stringstream ss; ss << appname << line << ": " << what;
	    throw std::runtime_error(ss.str());
	}
	virtual void error (std::string what) { throw std::runtime_error(appname + ": " + what); }
	virtual void msg   (std::string what) { std::cerr << appname << ": " << what; }
    };
    MyErrorHandler eh(appname);

    MSSQL::ClientConnection sql(&eh);
    try {
	sql.connect(servername, dbname, username, password);	/* (2) */
    } catch (std::runtime_error& e) {
	std::cerr << "failed to connect: " << e.what() << "\n";
	exit(-2);
    }

    bool interleave = true;
    if (interleave) {

	// Execute all of the supplied queries and store result objects.
	std::vector<MSSQL::Result> results;
	std::vector<MyErrorHandler> errorHandlers;
	for (int i=0; i < argc; i++) {
	    std::string query = argv[i];
	    std::cout << "query " << i << ": " << query << "\n";
	    errorHandlers.push_back(MyErrorHandler(query));
	    results.push_back(sql.executeQuery(query, &errorHandlers[i]));
	}

	// Flag to say we've exhausted one or more result sets.
	bool lastRow = false;

	// Create result iterators for each result.
	std::vector<MSSQL::Result::iterator> resIters;
	for (size_t i = 0; i < results.size() && !lastRow; ++i) {
	    MSSQL::Result::iterator resIter = results[i].begin();
	    if (resIter.operator==(results[i].end()))
		lastRow = true; // empty result set
	    else
		resIters.push_back(resIter);
	}

	// Walk through the rows and colums, displaying the results from each
	// query sequentially.
	while (!lastRow) {
	    std::vector<MSSQL::Values::const_iterator> cols;
	    for (size_t i = 0; i < resIters.size(); ++i)
		cols.push_back(resIters[i]->begin());
	    for (bool lastCol = false; !lastCol; ) {
		for (size_t i = 0; i < cols.size(); ++i) {
		    std::cout << std::setw(cols[i]->size()) << cols[i]->lexical() << ' ';
		    if (++cols[i] == resIters[i]->end())
			lastCol = true;
		}
		if (!lastCol)
		    std::cout << '|';
	    }
	    std::cout << "\n";
	    for (size_t i = 0; i < resIters.size(); ++i)
		if ((++resIters[i]).operator==(results[i].end()))
		    lastRow = true;
	    /*
	     * Get row count, if available.
	     */
	    if (lastRow)
		for (size_t i = 0; i < resIters.size(); ++i)
		    if (results[i].rowCount() > -1)
			std::cerr << "query " << i << ": " << results[i].rowCount() << " rows affected\n";

	}
    } else {

	// A single-"threaded" model for development and debugging.
	for (int i=0; i < argc; i++) {
	    assert(argv[i]);
	    std::string query = argv[i];
	    std::cout << query << "\n";
	    try {
		MyErrorHandler qeh(query);
		MSSQL::Result r = sql.executeQuery(argv[i], &qeh);
		for (MSSQL::Values::const_iterator col = r.headers().begin(); col != r.headers().end(); ++col)
		    std::cout << std::setw(col->size()) << col->name << ' ';
		std::cout << "\n";
		for (MSSQL::Result::iterator row = r.begin(); row != r.end(); ++row) {
		    for (MSSQL::Values::const_iterator col = row->begin(); col != row->end(); ++col)
			if (col->isNULL())
			    std::cout << std::setw(col->size()) << "NULL" << ' ';
			else
			    std::cout << std::setw(col->size()) << col->lexical() << ' ';
		    std::cout << "\n";
		}
		std::cerr << r.rowCount() << " rows affected\n";
	    } catch (std::runtime_error& e) {
		std::cerr << "main() caught " << e.what() << "\n";
	    }
	}
    }
    return 0;
}

#endif /* MSSQL_MAIN */

