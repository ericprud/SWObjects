/* SQLclient_MySQL.hpp: implementation of SQLclient for Oracle.

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $

!!! Actually, this is just a place holder for an Oracle library.
    The following code sample may help this become reallized.

#include <DbManager.h>
#include <iostream>
 
using namespace std;
 
using namespace oracle::occi;
 
const string sqlString("select empno, ename, hiredate from emp");
 
const string dateFormat("DD-MON-YYYY HH24:MI:SS");
 
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cerr << "\nUsage: " << argv[0] << " <db-user-name>\n" << endl;
    exit(1);
  }
 
  string userName = argv[1];
 
  // Initialize OracleServices
 
  DbManager* dbm = NULL;
 
  OracleServices* oras = NULL;
 
  Statement *stmt = NULL;
 
  ResultSet *resultSet = NULL;
 
  try
 
  {
 
    // Obtain OracleServices object with the default args.
 
    // The default args creates OracleServices with an environment of
 
    // Environment::OBJECT|Environment::THREADED_MUTEXED
 
    dbm = new DbManager(userName);
 
    oras = dbm->getOracleServices();
 
    // Obtain a cached connection
 
    Connection * conn = oras->connection();
 
    // Create a statement
 
    stmt = conn->createStatement(sqlString);
 
    int empno;
 
    string ename;
 
    Date hireDate;
 
    string dateAsString;
 
    // Execute query to get a resultset
 
    resultSet = stmt->executeQuery();
 
    while (resultSet->next())
    {
      empno = resultSet->getInt(1);  // get the first column returned by the query;
 
      ename = resultSet->getString(2);  // get the second column returned by the query
 
      hireDate = resultSet->getDate(3);  // get the third column returned by the query
 
      dateAsString="";
 
      //You cannot check for null until the data has been read
 
      if (resultSet->isNull(1))
 
      {
 
                cout << "Employee num is null... " << endl;
 
      }
 
      if (resultSet->isNull(2))
 
      {
 
                cout << "Employee name is null..." << endl;
 
      }
 
      if (resultSet->isNull(3))
 
      {
 
                cout << "Hire date is null..." << endl;
 
      }
      else
      {
                dateAsString=hireDate.toText(dateFormat);
      }
 
      cout << empno << "\t" << ename << "\t" << dateAsString << endl;
 
    }
 
    // Close ResultSet and Statement
 
    stmt->closeResultSet(resultSet);
 
    conn->terminateStatement(stmt);
  
 
    // Close Connection and OCCI Environment
 
    delete dbm;
 
  }
 
  catch (SQLException& ex)
 
  {
 
    if (dbm != NULL)
 
    {
        dbm->rollbackActions(ex, stmt, resultSet); // free resources and rollback transaction
 
    }
 
  }
 
   
  return 0;
 
}


 */

#ifndef SQL_CLIENT_ORACLE_H
#define SQL_CLIENT_ORACLE_H

#include "../interface/SQLclient.hpp"

#ifdef WIN32
  #include <mysql.h>
 #else
  #include <mysql/mysql.h>
#endif

namespace w3c_sw {

    class SQLclient_Oracle : public SQLclient {
    protected:
	MYSQL mysql, *sock;
	std::string server, database, user;
	virtual void _connect (std::string server, std::string database, std::string user, const char* password) {
	    this->server = server;
	    this->database = database;
	    this->user = user;
	    if (!(sock = mysql_real_connect(&mysql, server.c_str(), user.c_str(), password, database.c_str(), 0, NULL, 0)))
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
	SQLclient_Oracle () : SQLclient() { 
	    mysql_init(&mysql);
	}
	~SQLclient_Oracle () {  }
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

#endif // !SQL_CLIENT_ORACLE_H

