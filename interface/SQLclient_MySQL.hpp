/* SQLclient_MySQL.hpp: implementation of SQLclient for MySQL.

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef SQL_CLIENT_MYSQL_H
#define SQL_CLIENT_MYSQL_H

#include "../interface/SQLclient.hpp"

#ifdef WIN32
  #include <mysql.h>
#else
  #include <mysql/mysql.h>
#endif

namespace w3c_sw {

    class SQLclient_MySQL : public SQLclient {
    protected:
	MYSQL mysql, *sock;
	std::string server, database, user;

	/**
	 * _connect - connect to the database using the supplied credentials.
	 * @server: database server.
	 * @database: database name.
	 * @user: username to access the database.
	 * @password: @user's password.
	 */
	virtual void _connect (std::string server, std::string database, std::string user, const char* password) {
	    this->server = server;
	    this->database = database;
	    this->user = user;
	    if (!(sock = mysql_real_connect(&mysql, server.c_str(), user.c_str(), password, database.c_str(), 0, NULL, 0)))
		throw std::string("couldn't connect to mysql://") + user + "@" + server + "/" + database;
	}

    public:

	/**
	 * SQLclient_MySQL::Result - MySQL-specific SQLclient::Result (row).
	 */
	class Result : public SQLclient::Result {
	protected:
	    MYSQL_RES *result;
	    MYSQL_FIELD *fields;
	    int num_fields;
	    ColumnSet colSet;
	    Row row;
	public:

	    /**
	     * SQLclient_MySQL::Result constructor.
	     * @result: MySQL result handle returned from mysql_query.
	     */
	    Result (MYSQL_RES *result) : result(result) {
		num_fields = mysql_num_fields(result);
		fields = mysql_fetch_fields(result);
		for(int i = 0; i < num_fields; i++) {

		    // Create a field to store the name and RDF type of this column.
		    Field f;
		    f.name = fields[i].name;
		    switch (fields[i].type) {
		    case MYSQL_TYPE_DECIMAL:
			f.type = Field::TYPE_decimal;
			break;
		    case MYSQL_TYPE_TINY:
			f.type = Field::TYPE_short;
			break;
		    case MYSQL_TYPE_SHORT:
			f.type = Field::TYPE_short;
			break;
		    case MYSQL_TYPE_LONG:
			f.type = Field::TYPE_long;
			break;
		    case MYSQL_TYPE_FLOAT:
			f.type = Field::TYPE_float;
			break;
		    case MYSQL_TYPE_DOUBLE:
			f.type = Field::TYPE_double;
			break;
		    case MYSQL_TYPE_LONGLONG:
			f.type = Field::TYPE_decimal;
			break;
		    case MYSQL_TYPE_INT24:
			f.type = Field::TYPE_integer;
			break;
		    case MYSQL_TYPE_NULL:
			f.type = Field::TYPE__null;
			break;
		    case MYSQL_TYPE_DATETIME:
		    case MYSQL_TYPE_TIMESTAMP:
			f.type = Field::TYPE_dateTime;
			break;
		    case MYSQL_TYPE_YEAR:
			f.type = Field::TYPE_dateTime;
			break;
		    case MYSQL_TYPE_STRING:
			f.type = Field::TYPE_string;
			break;
		    case MYSQL_TYPE_VARCHAR:
		    case MYSQL_TYPE_BLOB:
		    case MYSQL_TYPE_VAR_STRING:
			f.type = Field::TYPE__literal;
			break;
		    default:
			if (true) { // do want a switch to allow unknown datatypes?
			    std::stringstream s;
			    s << "fields[" << i << "] " << fields[i].name << " of unknown type " << fields[i].type;
			    throw s.str();
			}
			f.type = Field::TYPE__unknown;
		    }

		    colSet.push_back(f); 		// Store the new Field.
		}
	    }

	    virtual ColumnSet cols () { return colSet; }

	    /**
	     * nextRow: create a Row record for the next fetchable row.
	     * @returns: SQLclient::Row, or SQLclient::Result.end() if at the end.
	     */
	    virtual Row nextRow () {
		Row ret;
		MYSQL_ROW row;
		if ((row = mysql_fetch_row(result)) == NULL)
		    return ret; // returns SQLclient::Result.end()

		// For each column:
		for(int i = 0; i < num_fields; i++) {

		    /* retrieve column data as a string */
		    std::string lexval(row[i] ? row[i] : "SQL NULL");

		    // Perform necessary SQL-to-RDF lexical transformations:
		    switch (fields[i].type) {
		    case MYSQL_TYPE_DATETIME:
			lexval.replace(lexval.find_first_of(' '), 1, "T");
			break;
		    case MYSQL_TYPE_TIMESTAMP:
			lexval = "0-0-0T" + lexval;
			break;
		    case MYSQL_TYPE_YEAR:
			lexval = lexval = "-0-0T00:00";
			break;
		    default:
			break;
		    }
		    ret.push_back(lexval);
		}
		return ret;
	    }
	};

	/**
	 * SQLclient_MySQL constructor.
	 */
	SQLclient_MySQL () : SQLclient() { 
	    mysql_init(&mysql);
	}

	~SQLclient_MySQL () {  }

	virtual void connect (std::string server, std::string database, std::string user) {
	    _connect(server, database, user, NULL);
	}
	virtual void connect (std::string server, std::string database, std::string user, std::string password) {
	    _connect(server, database, user, password.c_str());
	}

	/**
	 * executeQuery - Execute a generic SQL query.
	 * @query: the query string to send to the engine.
	 */
	virtual Result* executeQuery (std::string query) {
	    if (mysql_query(sock, query.c_str()))
		throw std::string("error calling mysql_query: ") + mysql_error(sock);
	    MYSQL_RES *result;
	    if (!(result = mysql_store_result(sock)))
		throw std::string("error calling mysql_store_result: ") + mysql_error(sock);
// 		throw std::string("mysql://") + user + "@" + server + "/" + database +
// 				  "could not retrieve results of [[\n" + query + "\n]]";

	    return new Result(result);
	}
    };

} /* namespace w3c_sw */

#endif // !SQL_CLIENT_MYSQL_H

