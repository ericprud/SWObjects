/* SQLclient_MySQL.hpp: implementation of SQLclient for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

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
	virtual void _connect (std::string server, std::string database, std::string user, const char* password) {
	    this->server = server;
	    this->database = database;
	    this->user = user;
	    if (!(sock = mysql_real_connect(&mysql, server.c_str(), user.c_str(), 0, database.c_str(), 0, password, 0)))
		throw std::string("couldn't connect to mysql://") + user + "@" + server + "/" + database;
	}

    public:
	class Result : public SQLclient::Result {
	protected:
	    MYSQL_RES *result;
	    MYSQL_FIELD *fields;
	    int num_fields;
	    ColumnSet colSet;
	    Row row;
	public:
	    Result (MYSQL_RES *result) : result(result) {
		num_fields = mysql_num_fields(result);
		fields = mysql_fetch_fields(result);
		for(int i = 0; i < num_fields; i++) {
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
		    case MYSQL_TYPE_VAR_STRING:
			f.type = Field::TYPE__literal;
			break;
		    default:
			f.type = Field::TYPE__unknown;
		    }
		    colSet.push_back(f);
		}
	    }
	    virtual ColumnSet cols () { return colSet; }
	    virtual Row nextRow () {
		Row ret;
		MYSQL_ROW row;
		if ((row = mysql_fetch_row(result)) == NULL)
		    return ret;
		for(int i = 0; i < num_fields; i++) {
		    std::string lexval(row[i] ? row[i] : "SQL NULL");
		    switch (fields[i].type) {
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
	virtual Result* executeQuery (std::string query) {
	    if (mysql_query(sock, query.c_str()))
		throw std::string("mysql://") + user + "@" + server + "/" + database +
				  "could not execute [[\n" + query + "\n]]";
	    MYSQL_RES *result;
	    if (!(result = mysql_store_result(sock)))
		throw std::string("mysql://") + user + "@" + server + "/" + database +
				  "could not retrieve results of [[\n" + query + "\n]]";
	    return new Result(result);
	}
    };

} /* namespace w3c_sw */

#endif // !SQL_CLIENT_MYSQL_H

