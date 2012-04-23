/* SQLclient_Postgres.hpp: implementation of SQLclient for Postgres.

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#include "../interface/SQLclient.hpp"

#ifndef INCLUDED_interface_SQLclient_Postgres_hpp
#define INCLUDED_interface_SQLclient_Postgres_hpp

#ifdef NEEDDEF_W3C_SW_SQLCLIENT
  #undef NEEDDEF_W3C_SW_SQLCLIENT
  #define W3C_SW_POSTGRES_SQLCLIENT 1
  #define W3C_SW_SQLCLIENT ::w3c_sw::SQLclient_Postgres
#endif /* NEEDDEF_W3C_SW_SQLCLIENT */

#include <stdexcept>
#include <postgresql/libpq-fe.h>

namespace w3c_sw {

    class SQLclient_Postgres : public SQLclient {
    protected:
	PGconn* conn;
	int transactionDepth;
	bool transactionError;

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
	    std::string connStr = "dbname = ";
	    connStr += database;
	    conn = PQconnectdb(connStr.c_str());
	    if (PQstatus(conn) != CONNECTION_OK)
		throw std::runtime_error(std::string("Connection failed: ")
					 + PQerrorMessage(conn));
	    PQclear(PQexec(conn, "SET client_min_messages=WARNING"));
	    // if (mysql_set_character_set(&mysql, "utf8"))
	    // 	throw std::string("couldn't set mysql://") + user + "@" + server + "/" + database + " to use utf8";
	}

    public:

	// Internal exception which adds a Postgres error message.
	struct PGResultException : public std::runtime_error {
	    PGResultException (std::string mesg, PGresult* res)
		: std::runtime_error(mesg + PQresultErrorMessage(res))
	    {
		PQclear(res);
	    } 
	    virtual ~PGResultException () throw() {  }
	};


	/**
	 * SQLclient_Postgres::Result - Postgres-specific SQLclient::Result (row).
	 */
	class Result : public SQLclient::Result {
	protected:
	    PGresult* result;
	    Result::Fixups& fixups;
	    size_t num_rows;
	    size_t cur_row;
	    int num_fields;
	    ColumnSet colSet;
	    Row row;
	public:

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
		virtual std::string operator() (std::string lexval, Field::Type& sqlType) {
		    return lexval + std::string(precision - lexval.size(), ' ');
		}
	    };

	    Result (e_RESULT, Result::Fixups& fixups)
		: result(NULL), fixups(fixups), num_rows(0), cur_row(0), num_fields(-1)
	    {  }

	    /**
	     * SQLclient_Postgres::Result constructor.
	     * @result: Postgres result handle returned from PQexec.
	     */
	    Result (PGresult* result, Result::Fixups& fixups)
		: result(result), fixups(fixups), num_rows(PQntuples(result)), cur_row(0), num_fields(PQnfields(result))
	    {
		for(int i = 0; i < num_fields; i++) {

		    // Create a field to store the name and RDF type of this column.
		    Field f;
		    f.name = PQfname(result, i);
		    // w3c_sw_LINEN << "fields[" << i << "].type(" << PQfname(result, i) << "): " << PQftype(result, i) << std::endl;
		    switch (PQftype(result, i)) {
		    // case MYSQL_TYPE_DECIMAL:
		    // 	f.type = Field::TYPE_decimal;
		    // 	break;
		    // case MYSQL_TYPE_TINY:
		    // 	f.type = Field::TYPE_short;
		    // 	break;
		    case 16: // bool
		    case 1000: // _bool
			f.type = Field::TYPE_boolean;
			break;
		    case 21: // int2
		    case 1005: // _int2
			f.type = Field::TYPE_short;
			break;
		    case 23: // int4
		    case 1007: // _int4
			f.type = Field::TYPE_long;
			break;
		    case 700: // float4
		    case 1021: // _float4
			f.type = Field::TYPE_float;
			break;
		    case 701: // float8
		    case 1022: // _float8
			f.type = Field::TYPE_double;
			break;
		    case 20: // int8
		    case 1016: // _int8
			f.type = Field::TYPE_decimal;
			break;
		    // case MYSQL_TYPE_INT24:
		    // 	f.type = Field::TYPE_integer;
		    // 	break;
		    case 1082: // date
		    case 1182: // _date
			f.type = Field::TYPE_date;
			break;
		    case 1083: // time
		    case 1183: // _time
			f.type = Field::TYPE_time;
			break;
		    // case MYSQL_TYPE_NULL:
		    // 	f.type = Field::TYPE__null;
		    // 	break;
		    // case MYSQL_TYPE_DATETIME:
		    case 1114: // timestamp
		    case 1115: // _timestamp
		    case 1184: // timestamptz
		    case 1185: // _timestamptz
			f.type = Field::TYPE_dateTime;
			break;
		    // case MYSQL_TYPE_YEAR:
		    // 	f.type = Field::TYPE_dateTime;
		    // 	break;
		    case 2275: // cstring
		    case 1263: // _cstring
		    case 18: // _char
		    case 1002: // char
		    case 1015: // _varchar
		    case 1043: // varchar
		    case 17: // bytea
		    case 1001: // _bytea
		    case 1042: // bpchar
		    case 1014: // _bpchar
		    // case MYSQL_TYPE_BLOB:
		    // case MYSQL_TYPE_VAR_STRING:
			f.type = Field::TYPE__literal;
			break;
		    default:
			if (true) { // do want a switch to allow unknown datatypes?
			    std::stringstream s;
			    s << "fields[" << i << "] " << PQfname(result, i) << " of unknown type " << PQftype(result, i);
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
		if (cur_row == num_rows)
		    return ret; // returns SQLclient::Result.end()

		// For each column:
		for(int i = 0; i < num_fields; i++) {

		    if (!PQgetisnull(result, cur_row, i)) {

			/* retrieve column data as a string */
			std::string lexval(PQgetvalue(result, cur_row, i));

			// Perform necessary SQL-to-RDF lexical transformations:
			switch (PQftype(result, i)) {
			case 16: // bool
			case 1000: // _bool
			    lexval = (lexval == "t" ? "TRUE" : "FALSE");
			    break;
			case 2275: // cstring
			case 1263: // _cstring
			case 18: // _char
			case 1002: // char
			case 1015: // _varchar
			case 1043: // varchar
			case 17: // bytea
			case 1001: // _bytea
			case 1042: // bpchar
			case 1014: // _bpchar
			    {
				size_t l = lexval.size();
				size_t esc = lexval.find('\\');
				std::string built(lexval, 0, esc);
				while (esc != std::string::npos) {
				    assert(esc < l - 3);
				    size_t n = lexval.find('\\', esc+4);
				    unsigned char b
					= (lexval[esc+1]-'0')*64
					+ (lexval[esc+2]-'0')*8
					+ (lexval[esc+3]-'0');
				    built
					.append(std::string(1, b))
					.append(lexval, esc+4, n-esc-4);
				    esc = n;
				}
				lexval = built;
			    }
			    break;
			default:
			    break;
			}
			for (Result::Fixups::const_iterator it = fixups.find(i); it != fixups.end() && it->first == i; ++it) {
			    boost::shared_ptr<Result::Fixup> p = it->second;
			    Result::Fixup& f = *p;
			    lexval = f(lexval, colSet[i].type);
			}
			ret.push_back(OptString(lexval, ""));
		    } else {
			ret.push_back(OptString());
		    }
		}
		++cur_row;
		return ret;
	    }
	};

	/**
	 * SQLclient_Postgres constructor.
	 */
	SQLclient_Postgres () : SQLclient() {  }

	~SQLclient_Postgres () {  }

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
	    PGresult* result = PQexec(conn, query.c_str());
	    if (PQresultStatus(result) != PGRES_TUPLES_OK &&
		PQresultStatus(result) != PGRES_COMMAND_OK)
		throw PGResultException(std::string() + "EXEC \"" + query + "\" failed: ", result);
	    return new Result(result, fixups);
		// throw std::string("error calling mysql_store_result: ") + mysql_error(sock);
// 		throw std::string("mysql://") + user + "@" + server + "/" + database +
// 				  "could not retrieve results of [[\n" + query + "\n]]";

	}
    };

} /* namespace w3c_sw */

#endif // !INCLUDED_interface_SQLclient_Postgres_hpp

