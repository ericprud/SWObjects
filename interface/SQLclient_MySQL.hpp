/* SQLclient_MySQL.hpp: implementation of SQLclient for MySQL.

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#include "../interface/SQLclient.hpp"

#ifndef INCLUDED_interface_SQLclient_MySQL_hpp
#define INCLUDED_interface_SQLclient_MySQL_hpp

#ifdef NEEDDEF_W3C_SW_SQLCLIENT
  #undef NEEDDEF_W3C_SW_SQLCLIENT
  #define W3C_SW_MYSQL_SQLCLIENT 1
  #define W3C_SW_SQLCLIENT ::w3c_sw::SQLclient_MySQL
#endif /* NEEDDEF_W3C_SW_SQLCLIENT */

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
	 * @param server	database server.
	 * @param database	database name.
	 * @param user		username to access the database.
	 * @param password	#user's password.
	 */
	virtual void _connect (std::string server, std::string database, std::string user, const char* password) {
	    this->server = server;
	    this->database = database;
	    this->user = user;
	    if (!(sock = mysql_real_connect(&mysql, server.c_str(), user.c_str(), password, database.c_str(), 0, NULL, 0)))
		throw std::runtime_error(std::string()
					 + "couldn't connect to mysql://" + user
					 + "@" + server + "/" + database);
	    if (mysql_set_character_set(&mysql, "utf8"))
		throw std::runtime_error(std::string()
					 + "couldn't set mysql://" + user
					 + "@" + server + "/" + database + " to use utf8");
	}

    public:

	/**
	 * SQLclient_MySQL::Result - MySQL-specific SQLclient::Result (row).
	 */
	class Result : public SQLclient::Result {
	protected:
	    MYSQL_RES *result;
	    Result::Fixups& fixups;
	    MYSQL_FIELD *fields; // keep a native list of fields to trigger fixups
	    int columnCount;
	    ColumnSet colSet;
	    Row row;
	public:

	    struct IntToBoolean : public Fixup {
		IntToBoolean () {  }
		virtual std::string operator() (std::string lexval, Field::Type& sqlType) {
		    sqlType = Field::TYPE_boolean;
		    return lexval == "1" ? "TRUE" : "FALSE";
		}
	    };

	    struct LiteralToBinary : public Fixup {
		LiteralToBinary () {  }
		virtual std::string operator() (std::string lexval, Field::Type& sqlType) {
		    sqlType = Field::TYPE_binary;
		    return lexval;
		}
	    };

	    struct CharTrailingChars : public Fixup {
		int precision;
		CharTrailingChars (int precision) : precision(precision) {  }
		virtual std::string operator() (std::string lexval, Field::Type& /* sqlType */) {
		    return lexval + std::string(precision - lexval.size(), ' ');
		}
	    };

	    Result (e_RESULT, Result::Fixups& fixups)
		: result(NULL), fixups(fixups)
	    {  }
	    /**
	     * SQLclient_MySQL::Result constructor.
	     * @result: MySQL result handle returned from mysql_query.
	     */
	    Result (MYSQL_RES *result, Result::Fixups& fixups)
		: result(result), fixups(fixups)
	    {
		columnCount = mysql_num_fields(result);
		fields = mysql_fetch_fields(result);
		for(int i = 0; i < columnCount; i++) {

		    // Create a field to store the name and RDF type of this column.
		    Field f;
		    f.name = fields[i].name;
		    // w3c_sw_LINEN << "fields[" << i << "].type(" << fields[i].name << "): " << fields[i].type << std::endl;
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
		    case MYSQL_TYPE_DATE:
			f.type = Field::TYPE_date;
			break;
		    case MYSQL_TYPE_TIME:
			f.type = Field::TYPE_time;
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
		    case MYSQL_TYPE_STRING: // used to be Field::TYPE_string;
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

	    virtual ColumnSet& cols () { return colSet; }

	    /**
	     * nextRow: create a Row record for the next fetchable row.
	     * @returns: SQLclient::Row, or SQLclient::Result.end() if at the end.
	     */
	    virtual Row nextRow () {
		Row ret;
		MYSQL_ROW row;
		if ((row = mysql_fetch_row(result)) == NULL)
		    return ret; // returns SQLclient::Result.end()

		unsigned long* lengths = mysql_fetch_lengths(result);

		// For each column:
		for(int i = 0; i < columnCount; i++) {

		    if (row[i]) {

			/* retrieve column data as a string */
			std::string lexval(row[i], lengths[i]);

			// Perform necessary SQL-to-RDF lexical transformations:
			switch (fields[i].type) {
			case MYSQL_TYPE_YEAR:
			    lexval = lexval = "-0-0T00:00";
			    break;
			default:
			    break;
			}
			for (Result::Fixups::const_iterator it = fixups.find(i); it != fixups.end() && it->first == i; ++it) {
			    boost::shared_ptr<Result::Fixup> p = it->second;
			    Result::Fixup& f = *p;
			    lexval = f(lexval, colSet[i].type);
			}
			ret.push_back(OptString(lexval, std::string("")));
		    } else {
			ret.push_back(OptString());
		    }
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
	 * @param query		the query string to send to the engine.
	 * @return		an SQLclient#Result with the table results of #query.
	 */
	virtual Result* executeQuery (std::string query, Result::Fixups& fixups = Result::Fixups::Empty) {
	    if (mysql_query(sock, query.c_str()))
		throw std::runtime_error(std::string() + "error calling mysql_query: " + mysql_error(sock));
	    MYSQL_RES *result;
	    if ((result = mysql_store_result(sock)) == NULL)
		return new Result(Result::RESULT_none, fixups);
	    return new Result(result, fixups);
		// throw std::runtime_error("error calling mysql_store_result: ") + mysql_error(sock);
// 		throw std::runtime_error("mysql://") + user + "@" + server + "/" + database +
// 				  "could not retrieve results of [[\n" + query + "\n]]";

	}
    };

} /* namespace w3c_sw */

#endif // !INCLUDED_interface_SQLclient_MySQL_hpp

