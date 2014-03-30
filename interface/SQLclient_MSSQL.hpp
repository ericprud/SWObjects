/* SQLclient_MSSQL.hpp: implementation of SQLclient for MSSQL.

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#include "../interface/SQLclient.hpp"

#ifndef INCLUDED_interface_SQLclient_MSSQL_hpp
 #define INCLUDED_interface_SQLclient_MSSQL_hpp

#include "../interface/freetdsSample.cpp"
#include <boost/lexical_cast.hpp>
#include <sybfront.h>	/* sybfront.h always comes first */
#include <sybdb.h>	/* sybdb.h is the only other file you need */

namespace w3c_sw {

    class SQLclient_MSSQL : public SQLclient {
    protected:
	MSSQL::ClientConnection sql;

    public:

	/**
	 * SQLclient_MSSQL::Result - MSSQL-specific SQLclient::Result (row).
	 */
	class Result : public SQLclient::Result {
	protected:
	    MSSQL::Result result;
	    Result::Fixups& fixups;
	    ColumnSet colSet;
	    bool needIterator;
	    MSSQL::Result::iterator it;

	public:

	    Result (MSSQL::Result result, Result::Fixups& fixups)
		: result(result), fixups(fixups), needIterator(true), it(result.end())
	    {
		for (int i = 0; i < result.ncols; i++) {

		    // Create a field to store the name and RDF type of this column.
		    Field f;
		    f.name = std::string(result.headers()[i].name);
		    switch (result.headers()[i].type) {
			// is anything here a Field::TYPE_integer ?
			// mostly ignoring http://technet.microsoft.com/en-us/library/aa936992%28v=sql.80%29.aspx
		    case -1: // error
		    case SYBCHAR: f.type = Field::TYPE__literal ; break;
		    case SYBVARCHAR: f.type = Field::TYPE__literal ; break;
			//case SYBINTN: f.type = Field::TYPE_ ; break;
			//case SYBINT1: f.type = Field::TYPE_ ; break;
		    case SYBINT2: f.type = Field::TYPE_short ; break;
		    case SYBINT4: f.type = Field::TYPE_long ; break;
		    case SYBINT8: f.type = Field::TYPE_decimal ; break;
		    case SYBFLT8: f.type = Field::TYPE_double ; break;
		    case SYBDATETIME: f.type = Field::TYPE_dateTime ; break;
		    case SYBBIT: f.type = Field::TYPE_boolean ; break;
		    case SYBTEXT: f.type = Field::TYPE__literal ; break;
			//case SYBIMAGE: f.type = Field::TYPE_ ; break;
			//case SYBMONEY4: f.type = Field::TYPE_ ; break;
			//case SYBMONEY: f.type = Field::TYPE_ ; break;
		    case SYBDATETIME4: f.type = Field::TYPE_dateTime ; break;
		    case SYBREAL: f.type = Field::TYPE_double ; break;
		    // case SYBBINARY: f.type = Field::TYPE_hex64Binary ; break;
		    // case SYBVARBINARY: f.type = Field::TYPE_hex64Binary ; break;
		    case SYBNUMERIC: f.type = Field::TYPE_decimal ; break;
		    case SYBDECIMAL: f.type = Field::TYPE_decimal ; break;
		    case SYBFLTN: f.type = Field::TYPE_double ; break;
			//case SYBMONEYN: f.type = Field::TYPE_ ; break;
			//case SYBDATETIMN: f.type = Field::TYPE_ ; break;
		    default:
			if (true) { // do we want a switch to allow unknown datatypes?
			    std::stringstream s;
			    s << "fields[" << i << "] " << f.name << " of unknown type " << result.headers()[i].type;
			    throw std::runtime_error(s.str()); // !! fix in other interfaces
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
		if (needIterator) {
		    needIterator = false;
		    it = result.begin();
		} else {
		    ++it;
		}
		if (operator==(it, result.end()))
		    return ret; // returns SQLclient::Result.end()
		// could throwFailure(SQL_HANDLE_STMT, stmt) if it's the wrong error.

		// For each column:
		for (int i = 0; i < result.ncols; ++i) {
		    if (result.headers()[i].isNULL()) {
			ret.push_back(OptString());
		    } else {
			std::string lexval(result.headers()[i].lexical());

			// Perform necessary SQL-to-RDF lexical transformations:
			switch (colSet[i].type) {
			case Field::TYPE_dateTime:
			    {
				//string lexval = "JunT17 2003 12:00:00:000AM";
				const char* month = lexval.c_str();
				const char* M =
				    month[0] == 'J' ?
				    month[1] == 'a' ? "01" :
				    month[2] == 'n' ? "06" :
				    "07" :
				    month[0] == 'F' ? "02" :
				    month[0] == 'M' ?
				    month[2] == 'r' ? "03" :
				    "05" :
				    month[0] == 'A' ?
				    month[1] == 'p' ? "04" :
				    "08" :
				    month[0] == 'S' ? "09" :
				    month[0] == 'O' ? "10" :
				    month[0] == 'N' ? "11" :
				    month[0] == 'D' ? "12" :
				    "??";
				int h = boost::lexical_cast<int>(lexval.substr(12, 2));
				std::string m = lexval.substr(15, 2); 
				std::string s = lexval.substr(18);
				s.replace(s.find_first_of(":"), 1, ".");
				size_t apm = s.find_first_of("AP");
				if (apm != std::string::npos) {
				    if (s[apm] == 'P')
					h += 12;
				    else if (h == 12)
					h = 0;
				    s.resize(apm);
				}
				std::string h0 = h < 10 ? "0" : "";
				lexval
				    = lexval.substr(7, 4)+'-'+M+'-'+lexval.substr(4,2)
				    +' '+h0+boost::lexical_cast<std::string>(h)+':'+m+':'+s;
			    }
			    break;
			// case SQL_TIMESTAMP:
			//     lexval = "0-0-0T" + lexval;
			//     break;
			default:
			    break;
			}

			ret.push_back(OptString(lexval, ""));
		    }
		}
		return ret;
	    }
	};

	/**
	 * SQLclient_MSSQL constructor.
	 */
	SQLclient_MSSQL () : SQLclient(), sql() {
	}

	~SQLclient_MSSQL () {  }

	virtual void connect (std::string server, std::string database, std::string user) {
	    sql.connect(server, database, user, std::string());
	}
	virtual void connect (std::string server, std::string database, std::string user, std::string password) {
	    sql.connect(server, database, user, password.c_str());
	}

	/**
	 * executeQuery - Execute a generic SQL query.
	 * @param query		the query string to send to the engine.
	 */
	virtual Result* executeQuery (std::string query, Result::Fixups& fixups = Result::Fixups::Empty) {
	    // Normally, Result is constructed with a specific query context.
	    // MSSQL doesn't appear to provide one so if we want one connection
	    // to manage multiple Results, we need to create a pool of
	    // connection objects, each of which is _connected when created and
	    // made available when the Result is destroyed.
#if 0
	    dbcmd(proc, query);
	    if (dbsqlexec(proc) != SUCCEED)
		throw std::runtime_error("mssql://") + user + "@" + server + "/" + database +
		    "could not execute [[\n" + query + "\n]]";
#endif
	    return new Result(sql.executeQuery(query), fixups); 
	}
    };

} /* namespace w3c_sw */

#ifdef NEEDDEF_W3C_SW_SQLCLIENT
  #undef NEEDDEF_W3C_SW_SQLCLIENT
  #define W3C_SW_SQLCLIENT w3c_sw::SQLclient_MSSQL
#endif /* NEEDDEF_W3C_SW_SQLCLIENT */

#endif // !INCLUDED_interface_SQLclient_MSSQL_hpp

