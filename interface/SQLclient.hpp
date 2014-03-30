/* SQLclient - abstract inferface for SQL clients

 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef INCLUDED_interface_SQLclient_hpp
 #define INCLUDED_interface_SQLclient_hpp

#include <boost/shared_ptr.hpp>
#include <SQL.hpp>

#define PREFIX_XSI "http://www.w3.org/2001/XMLSchema#"
#define PREFIX_SWO "http://swobjects.sourceforge.net/ns#"

namespace w3c_sw {

    struct SQLConnectInfo {
	bool useODBC;
	std::string driver;
	std::string user;
	std::string password;
	std::string server;
	std::string port;
	std::string database;

	SQLConnectInfo ()
	    : useODBC(false)
	{  }

	SQLConnectInfo (const std::string s)
	    : useODBC(false)
	{
	    parse(s);
	}

#if REGEX_LIB != SWOb_DISABLED
	void parse (const std::string s)
	{
	    /**
	     * ODBC drivers patterns are pretty random.
	     * c.f. http://www.herongyang.com/JDBC/Summary-Connection-URL.html
	     * We let ODBC work it out.
	     */
	    size_t p = s.find("odbc:");
	    if (p == 0) {
		useODBC = true;
		driver = s.substr(5);
		return;
	    }

	    const boost::regex odbcPattern("^([^:]+)://"	// 1: protocol ://
					   "(?:"		//    [
					   "([^:]+)"		// 2:   user
					   "(?::([^@]+))?"	// 3:   [ : password ]
					   "@)?"		//    @ ]
					   "([^:]*)"		// 4: host -- can be empty
					   "(?::([0-9]+))?"	// 5: [ port ]
					   "/(.+)$");		// 6: database
	    boost::cmatch matches;
	    if (boost::regex_match(s.c_str(), matches, odbcPattern)) {
		if (matches[1] != "mysql" && matches[1] != "postgres" && matches[1] != "oracle" && matches[1] != "mssql")
		    throw std::string("only mysql, postgres or oracle SQL service is currently supported -- saw ") + matches[1];
		driver = matches[1];
		if (matches[2].matched)
		    user = matches[2];
		if (matches[3].matched)
		    password = matches[3];
		server = matches[4];
		if (matches[5].matched)
		    port = matches[5];
		database = matches[6];
	    } else {
		throw std::runtime_error(std::string() +
					 "SQL connection string \"" + s + "\" "
					 "did not match expression \"" + odbcPattern.str() + "\"");
	    }
	}
#endif /* REGEX_LIB != SWOb_DISABLED */


	bool initialized () {
	    return !driver.empty()
		|| !server.empty()
		|| !database.empty()
		|| !user.empty();
	}


	std::string sqlConnectString () const {
	    std::stringstream ss;
	    ss << driver + "://";
	    if (!user.empty()) {
		ss << user;
		if (!password.empty())
		    ss << ":" + password;
		ss << "@";
	    }
	    ss << server + "/" + database;
	    return ss.str();
	}
    };

    class SQLclient {
    protected:
	std::string mediaType;
    public:
	class Result {
	public:
	    typedef enum {
		RESULT_none = 0
	    } e_RESULT;
	    virtual ~Result () {  }
	    struct Field {
		typedef enum {
/* plain    | 'NATIONAL'? 'CHARACTER' ('VARYING' | 'LARGE' 'OBJECT')? | 'VARCHAR'
 * Base64   | 'BINARY' ('VARYING' | 'LARGE' 'OBJECT')?
 * decimal  | 'NUMERIC' | 'DECIMAL'
 * integer  | 'SMALLINT' | ('INTEGER' | 'INT') | 'BIGINT'
 * double   | 'FLOAT' | 'REAL' | 'DOUBLE' 'PRECISION'
 * boolean  | 'BOOLEAN'
 * date     | 'DATE'
 * time     | 'TIME'
 * datetime | 'TIMESTAMP' | 'DATETIME'
 * 'INTERVAL'
 */

		    TYPE__err = 0, 
		    TYPE__literal, 
		    TYPE_binary, 
		    TYPE_decimal, 
		    TYPE_short, TYPE_integer, TYPE_long, 
		    TYPE_float, TYPE_real, TYPE_double, 
		    TYPE_boolean, 
		    TYPE_date, 
		    TYPE_time, 
		    TYPE_timeStamp, TYPE_dateTime, 
		    TYPE__null, 
		    TYPE__unknown
		} Type;
		Type type;
		std::string name;
		static std::string typeNames[];
	    };

	    struct Fixup {
		virtual std::string operator()(std::string lexval, Field::Type& sqlType) = 0;
	    };
	    template <int dummy>
	    struct Fixups_dummyTemplate : public std::multimap<int, boost::shared_ptr<Fixup> > {
		iterator insert (int colNo, Fixup* fixup) {
		    return std::multimap<int, boost::shared_ptr<Fixup> >::insert
			(std::make_pair(colNo, boost::shared_ptr<Fixup>(fixup)));
		}
		static Fixups_dummyTemplate<dummy> Empty;
	    };
	    typedef Fixups_dummyTemplate<0> Fixups;

	    struct IntToBoolean : public Fixup {
		IntToBoolean () {  }
		virtual std::string operator() (std::string lexval, Field::Type& sqlType) {
		    sqlType = Field::TYPE_boolean;
		    return lexval == "1" ? "TRUE" : "FALSE";
		}
	    };


	    typedef std::vector<Field> ColumnSet;
	    virtual ColumnSet& cols() = 0;
	    struct Row : public std::vector<OptString> {

		static char _hex (const char ch) {
		    return ch < 0x0a ? ch + '0' : ch + 'A' - 10;
		}
		static std::string hex_encode(std::string encodeMe) {
		    std::string ret;
		    for (std::string::const_iterator ch = encodeMe.begin();
			 ch != encodeMe.end(); ++ch) {
			unsigned char uc = *ch;
			ret += _hex(uc>> 4);
			ret += _hex(uc & 0x0F);
		    }
		    return ret;
		}

		const TTerm* getTTerm (size_t i, ColumnSet& cols, AtomFactory* atomFactory) {
		    std::string lexval(at(i).get());
		    Field::Type type = cols[i].type;
		    if (type == SQLclient::Result::Field::TYPE__err || 
			type == SQLclient::Result::Field::TYPE__unknown)
			throw std::string("field value \"") + lexval + "\" has unknown datatype";// + type;

		    if (type != SQLclient::Result::Field::TYPE__null) {
			if (type == SQLclient::Result::Field::TYPE_binary)
			    lexval = hex_encode(lexval);
			else if (type == SQLclient::Result::Field::TYPE_boolean) {
			    lexval = lexval == "TRUE" ? "true" : "false";
			} else if (type == SQLclient::Result::Field::TYPE_dateTime)
			    lexval.replace(lexval.find_first_of(' '), 1, "T");
			else if (type == SQLclient::Result::Field::TYPE_float || 
				 type == SQLclient::Result::Field::TYPE_real || 
				 type == SQLclient::Result::Field::TYPE_double) {
			    std::stringstream input(lexval);
			    double val;
			    input >> val;

			    if (val == 0) {
				lexval = "0.0E0";
			    } else {
				// canonical << std::scientific << val; yields e.g. 1.230000E04
				std::stringstream canonical;
				int ex = log10(val);
				if (val < 1)
				    --ex;
				canonical << val/exp(ex*log(10)/log10(10));
				if (canonical.str().find('.') == std::string::npos)
				    canonical << ".0";
				canonical << "E" << ex;

				lexval = canonical.str();
			    }
			}

			std::string dt = Field::typeNames[type];
			const URI* dtpos = dt.size() > 0 ? atomFactory->getURI(dt.c_str()) : NULL;
			return atomFactory->getRDFLiteral(lexval, dtpos, NULL);
			// w3c_sw_LINEN << "val(" << val << "): " << val->toString() << " of dtpos: " << dtpos->toString() << std::endl;
		    } else
			return NULL;
		}
	    };
	    virtual Row nextRow() = 0;
	    Row end () { return Row(); } // count on operator!= to say that two empty Row's are ==
	    std::ostream& print (std::ostream& os) {
		ColumnSet& columns = cols();
		std::vector<size_t> widths(columns.size());
		std::vector<std::string> names;
		std::vector<std::vector<std::string> > values;

		for (size_t i = 0; i < columns.size(); ++i) {
		    names.push_back(columns[i].name);
		    widths[i] = columns[i].name.length();
		}

		Row row;
		while ((row = nextRow()) != end()) {
		    values.resize(values.size()+1);
		    for(size_t i = 0; i < columns.size(); i++) {
			std::string v
			    = row[i].is_initialized()
			    ? row[i].get()
			    : "NULL";
			values[values.size()-1][i] = v;
			if (widths[i] < v.length())
			    widths[i] = v.length();
		    }
		}

		for (size_t i = 0; i < columns.size(); ++i) {
		    if (i == 0)
			os << "| ";
		    os << names[i] << std::string(widths[i] - names[i].length(), ' ') << " |";
		}

		for (size_t row = 0; row < values.size(); ++row) {
		    for (size_t col = 0; col < columns.size(); ++col) {
			if (col == 0)
			    os << "| ";
			os << values[row][col] << std::string(widths[col] - values[row][col].length(), ' ') << " |";
		    }
		    os << "\n";
		}

		return os;
	    }
	};

	SQLclient () {  }
	virtual ~SQLclient () {  }
	virtual void connect(std::string server, std::string database, std::string user) = 0;
	virtual void connect(std::string server, std::string database, std::string user, std::string password) = 0;
	void connect (const SQLConnectInfo& con) {
	    if (con.password.empty())
		// @@ wrap password with Optional to enable --password=''
		connect(con.server, con.database, con.user);
	    else
		connect(con.server, con.database, con.user, con.password);
	}

	virtual Result* executeQuery(std::string query, Result::Fixups& fixups = Result::Fixups::Empty) = 0;
    };

    std::ostream& operator<< (std::ostream& os, SQLclient::Result& rs) {
	return rs.print(os);
    }

    /* SQL type to XSD type mapping: http://www.w3.org/2001/sw/rdb2rdf/r2rml/#table-type-mapping */
    std::string SQLclient::Result::Field::typeNames[] = {
	PREFIX_SWO "_err", 
	"", /* PREFIX_SWO "_literal", */
	PREFIX_XSI "hexBinary", 
	PREFIX_XSI "decimal", 
	PREFIX_XSI "integer", PREFIX_XSI "integer", PREFIX_XSI "integer", 
	PREFIX_XSI "double", PREFIX_XSI "double", PREFIX_XSI "double", 
	PREFIX_XSI "boolean", 
	PREFIX_XSI "date", 
	PREFIX_XSI "time", 
	PREFIX_XSI "dateTime", PREFIX_XSI "dateTime", 
	PREFIX_SWO "_null", 
	PREFIX_SWO "_unknown", 
    };

    class SqlResultSet : public ResultSet {
    public:
	SqlResultSet (AtomFactory* atomFactory, SQLclient::Result* res) : ResultSet(atomFactory) {
	    erase(begin());
	    SQLclient::Result::ColumnSet& cols = res->cols();
	    std::vector<const TTerm*> vars;

	    for (SQLclient::Result::ColumnSet::const_iterator it = cols.begin();
		 it != cols.end(); ++it)
		vars.push_back(atomFactory->getVariable(it->name));

	    knownVars.insert(vars.begin(), vars.end());

	    SQLclient::Result::Row row;
	    while ((row = res->nextRow()) != res->end()) { // !!! use iterator
		Result* result = new Result(this);
		for(size_t i = 0; i < cols.size(); i++)
		    if (row[i].is_initialized())
			set(result, vars[i], row.getTTerm(i, cols, atomFactory), false);
		    else
			addKnownVar(vars[i]);
		insert(end(), result);
	    }
	}
    };

    template <int dummy>
    SQLclient::Result::Fixups_dummyTemplate<dummy> SQLclient::Result::Fixups_dummyTemplate<dummy>::Empty;

} // namespace w3c_sw

#ifdef SQL_CLIENT_MYSQL
  #include "../interface/SQLclient_MySQL.hpp"
#endif /* SQL_CLIENT_MYSQL */

#ifdef SQL_CLIENT_POSTGRES
  #include "../interface/SQLclient_Postgres.hpp"
#endif /* SQL_CLIENT_POSTGRES */

#ifdef SQL_CLIENT_ORACLE
  #include "../interface/SQLclient_Oracle.hpp"
#endif /* SQL_CLIENT_ORACLE */

#ifdef SQL_CLIENT_MSSQL
  #include "../interface/SQLclient_MSSQL.hpp"
#endif /* SQL_CLIENT_MSSQL */

#ifdef SQL_CLIENT_ODBC
  #include "../interface/SQLclient_ODBC.hpp"
#endif /* SQL_CLIENT_ODBC */

namespace w3c_sw {
    struct SQLClientWrapper : public SQLclient {
	SQLclient* client;
    public:
	SQLClientWrapper (const SQLConnectInfo& con)
	    : client(makeClient(con.driver, con.useODBC))
	{  }
	SQLClientWrapper (const SQLClientWrapper& ref)
	    : client(ref.client)
	{
	    ((SQLClientWrapper&)ref).client = NULL; // !! allow wrappers in containers.
	}
	~SQLClientWrapper () {
	    if (client != NULL)
		delete client;
	}
	static SQLclient* makeClient (std::string driver, bool useODBC) {
#ifdef SQL_CLIENT_ODBC
	    if (useODBC) return new SQLclient_ODBC(driver);
#endif
#ifdef SQL_CLIENT_MSSQL
	    if (driver == "mssql") return new SQLclient_MSSQL();
#endif
#ifdef SQL_CLIENT_MYSQL
	    if (driver == "mysql") return new SQLclient_MySQL();
#endif
#ifdef SQL_CLIENT_POSTGRES
	    if (driver == "postgres") return new SQLclient_Postgres();
#endif
#ifdef SQL_CLIENT_ORACLE
	    if (driver == "oracle") return new SQLclient_Oracle();
#endif
	    throw driver + " driver not linked in.";
	}
	SQLclient* takeClient () {
	    SQLclient* ret = client;
	    client = NULL;
	    return ret;
	}
	virtual void connect(std::string engine, std::string database, std::string user) {
	    client->connect(engine, database, user);
	}
	virtual void connect(std::string engine, std::string database, std::string user, std::string password) {
	    client->connect(engine, database, user, password);
	}
	void connect (const SQLConnectInfo& con) { // @@ need this to compile, despite "public SQLclient".
	    return SQLclient::connect(con);
	}
	virtual Result* executeQuery(std::string query, Result::Fixups& fixups = Result::Fixups::Empty) {
	    return client->executeQuery(query, fixups);
	}
    };

    struct SQLClientList {
	struct Connection {
	    SQLConnectInfo info;
	    SQLClientWrapper wrap;
	    sql::Serializer* serializer;

	    Connection (std::string sqlspec)
		: info(sqlspec), wrap(info), serializer(sql::Serializer::best(info.driver))
	    {
		wrap.connect(info);
	    }
	};
	std::vector<Connection> cons;
	typedef std::vector<Connection>::iterator iterator;
	iterator begin () { return cons.begin(); }
	iterator end () { return cons.end(); }
	void add (std::string sqlspec) {
	    cons.push_back(Connection(sqlspec));
	}
	void executeQuery (std::string query) {
	    for (std::vector<Connection>::iterator connection = cons.begin();
		 connection != cons.end(); ++connection)
		connection->wrap.executeQuery(query);
	}
    };
} // namespace w3c_sw

#endif // !INCLUDED_interface_SQLclient_hpp

