/* SQLclient_MySQL.hpp: implementation of SQLclient for ODBC.

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef SQL_CLIENT_ODBC_H
#define SQL_CLIENT_ODBC_H

#include "../interface/SQLclient.hpp"

#include <sql.h>
#include<sqltypes.h>
#include<sqlext.h>

namespace w3c_sw {

    class SQLclient_ODBC : public SQLclient {
    protected:
	std::string driver;
	SQLHENV env;
	SQLHDBC dbc;
	std::string server, database, user;

	/**
	 * throwFailure - throw as informative an error as we can muster.
	 * @param leader	context error string to start the exception text.
	 * @param type		the type of handle: SQL_HANDLE_ENV | SQL_HANDLE_DBC | SQL_HANDLE_STMT | SQL_HANDLE_DESC
	 * @param handle	ODBC handle used in the failed operation.
	 */
	static void throwFailure (std::string leader, SQLSMALLINT type, SQLHANDLE handle) {
	    SQLINTEGER	i = 0;
	    SQLRETURN	r;
	    std::stringstream ss;
	    ss << leader;
	    do {
		SQLINTEGER	native;
		SQLCHAR		state[7];
		SQLCHAR		text[256];
		SQLSMALLINT	len;
		if ((r = SQLGetDiagRec(type, handle, ++i, state,
				       &native, text, sizeof(text), &len )) == SQL_SUCCESS) {
		    if (i > 1)	// can have multiple lines in message.
			ss << "\n";
		    ss << state << ":" << i << ":" << native << ":" << text;
		}
	    } while (r == SQL_SUCCESS);
	    throw ss.str();
	}

	/**
	 * _connect - connect to the database using the credentials in SQLclient_ODBC#driver.
	 * The four parameters (server, database, user, password) are ignored.
	 */
	virtual void _connect (std::string, std::string, std::string, const char*) {
	    std::string conString;
	    if (!SQL_SUCCEEDED(::SQLDriverConnect(dbc, NULL, (SQLCHAR*)driver.c_str(), SQL_NTS,
						  NULL, 0, NULL, SQL_DRIVER_COMPLETE)))
		throwFailure("SQLDriverConnect failed: ", SQL_HANDLE_DBC, dbc);
	}

    public:

	/**
	 * SQLclient_ODBC::Result - ODBC-specific SQLclient::Result (row).
	 */
	class Result : public SQLclient::Result {
	protected:
	    SQLHSTMT stmt;
	    SQLSMALLINT num_fields;
	    ColumnSet colSet;
	    std::vector<SQLSMALLINT> sqlColTypes;
	    Row row;

	public:

	    /**
	     * SQLclient_ODBC::Result constructor.
	     * @param stmt	handle used in SQLExec.
	     */
	    Result (SQLHSTMT stmt) : stmt(stmt) {
		if (!SQL_SUCCEEDED(::SQLNumResultCols(stmt, &num_fields)))
		    throwFailure("SQLNumResultCols failed: ", SQL_HANDLE_STMT, stmt);
		for(int i = 0; i < num_fields; i++) {
		    SQLCHAR	colname [32];
		    SQLSMALLINT	colnamelen;
		    SQLSMALLINT	coltype;
		    SQLULEN	collen;
		    SQLSMALLINT	scale;
		    SQLSMALLINT	nullable;

		    if (!SQL_SUCCEEDED(::SQLDescribeCol(stmt, (SQLSMALLINT) (i + 1),
							colname, (SQLSMALLINT) sizeof(colname),
							&colnamelen, &coltype, &collen,
							&scale, &nullable)))
			throwFailure("SQLDescribeCol failed: ", SQL_HANDLE_STMT, stmt);

		    // Create a field to store the name and RDF type of this column.
		    Field f;
		    f.name = std::string((const char*)colname, colnamelen);
		    switch (coltype) {
		    case SQL_DECIMAL:
			f.type = Field::TYPE_decimal;
			break;
		    case SQL_CHAR:
			f.type = Field::TYPE_short;
			break;
		    case SQL_SMALLINT:
			f.type = Field::TYPE_short;
			break;
		    case SQL_NUMERIC:
			f.type = Field::TYPE_long;
			break;
		    case SQL_FLOAT:
			f.type = Field::TYPE_float;
			break;
		    case SQL_DOUBLE:
			f.type = Field::TYPE_double;
			break;
		    case SQL_REAL:
			f.type = Field::TYPE_decimal;
			break;
		    case SQL_INTEGER:
			f.type = Field::TYPE_integer;
			break;
		    case SQL_DATETIME:
		    case SQL_TIMESTAMP:
			f.type = Field::TYPE_dateTime;
			break;
		    case SQL_VARCHAR:
			f.type = Field::TYPE__literal;
			break;
		    default:
			if (true) { // do we want a switch to allow unknown datatypes?
			    std::stringstream s;
			    s << "fields[" << i << "] " << colname << " of unknown type " << coltype;
			    throw s.str();
			}
			f.type = Field::TYPE__unknown;
		    }

		    colSet.push_back(f); 		// Store the new Field.
		    sqlColTypes.push_back(coltype);	// Also store the SQL-native type.
		}
	    }

	    virtual ColumnSet cols () { return colSet; }

	    /**
	     * nextRow: create a Row record for the next fetchable row.
	     * @returns: SQLclient::Row, or SQLclient::Result.end() if at the end.
	     */
	    virtual Row nextRow () {
		Row ret;
		if (!SQL_SUCCEEDED(::SQLFetch(stmt)))
		    return ret; // returns SQLclient::Result.end()
		// could throwFailure(SQL_HANDLE_STMT, stmt) if it's the wrong error.

		// For each column:
		for(SQLSMALLINT i = 0; i < num_fields; i++) {

		    /* retrieve column data as a string */
		    SQLLEN indicator;
		    char buf[512];
		    if (!SQL_SUCCEEDED(::SQLGetData(stmt, i+1, SQL_C_CHAR,
						    buf, sizeof(buf), &indicator)))
			throwFailure("SQLGetData failed: ", SQL_HANDLE_STMT, stmt);
		    if (indicator == SQL_NULL_DATA) {
			ret.push_back(OptString());
		    } else {
			std::string lexval(buf);

			// Perform necessary SQL-to-RDF lexical transformations:
			switch (sqlColTypes[i]) {
			case SQL_DATETIME:
			    lexval.replace(lexval.find_first_of(' '), 1, "T");
			    break;
			case SQL_TIMESTAMP:
			    lexval = "0-0-0T" + lexval;
			    break;
			default:
			    break;
			}

			ret.push_back(OptString(lexval.c_str())); // @@ why do i need 
		    }
		}
		return ret;
	    }
	};

	/**
	 * SQLclient_ODBC constructor.
	 * @param driver	the ODBC connect string.
	 * We don't even try to parse out e.g. database and user names.
	 */
	SQLclient_ODBC (std::string driver) : SQLclient(), driver(driver) {
	    if (!SQL_SUCCEEDED(::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env)))
		    throwFailure("SQLAllocHandle ENV failed: ", SQL_HANDLE_ENV, env);
	    if (!SQL_SUCCEEDED(::SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0)))
		    throwFailure("SQLSetEnvAttr failed: ", SQL_HANDLE_ENV, env);
	    if (!SQL_SUCCEEDED(::SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc)))
		    throwFailure("SQLAllocHandle DBC failed: ", SQL_HANDLE_DBC, env);
	}

	~SQLclient_ODBC () {  }

	virtual void connect (std::string server, std::string database, std::string user) {
	    _connect(server, database, user, NULL);
	}
	virtual void connect (std::string server, std::string database, std::string user, std::string password) {
	    _connect(server, database, user, password.c_str());
	}

	/**
	 * executeQuery - Execute a generic SQL query.
	 * @param query		the query string to send to the engine.
	 */
	virtual Result* executeQuery (std::string query) {
	    SQLHSTMT stmt;

	    if (!SQL_SUCCEEDED(::SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt)))
		throwFailure("SQLAllocHandle statement failed: ", SQL_HANDLE_STMT, env);
	    if (!SQL_SUCCEEDED(::SQLExecDirect(stmt, (SQLCHAR*)query.c_str(), SQL_NTS)))
		throwFailure("SQLExecDirect failed: ", SQL_HANDLE_STMT, env);

	    return new Result(stmt);
	}
    };

} /* namespace w3c_sw */

#endif // !SQL_CLIENT_ODBC_H

/* Add extra return code debugging info someday:
		SQLRETURN r;
		if (!(SQL_SUCCEEDED(r = ::SQLFetch(stmt)))) {
		    std::stringstream ss;
		    ss << __FILE__ << "(" << __LINE__ << "): error: SQLFetch failed with " << r << "(" <<
			(r == SQL_SUCCESS ? "SQL_SUCCESS" :
			 r == SQL_SUCCESS_WITH_INFO ? "SQL_SUCCESS_WITH_INFO" :
			 r == SQL_NO_DATA ? "SQL_NO_DATA" :
			 r == SQL_STILL_EXECUTING ? "SQL_STILL_EXECUTING" :
			 r == SQL_ERROR ? "SQL_ERROR" :
			 r == SQL_INVALID_HANDLE ? "SQL_INVALID_HANDLE" :
			 "???")
		       << "): ";
		    sql.throwFailure(ss.str(), SQL_HANDLE_STMT, (stmt);
		}

 */
