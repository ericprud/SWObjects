/* SQLclient - abstract inferface for SQL clients

 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef INCLUDED_interface_SQLclient_hpp
 #define INCLUDED_interface_SQLclient_hpp

#define PREFIX_XSI "http://www.w3.org/2001/XMLSchema#"
#define PREFIX_SWO "http://swobjects.sourceforge.net/ns#"

namespace w3c_sw {

    class SQLclient {
    protected:
	std::string mediaType;
    public:
	class Result {
	public:
	    virtual ~Result () {  }
	    struct Field {
		typedef enum {
		    TYPE__err = 0, 
		    TYPE_decimal, 
		    TYPE_float, 
		    TYPE_double, 
		    TYPE_short, 
		    TYPE_integer, 
		    TYPE_long, 
		    TYPE_dateTime, 
		    TYPE_string, 
		    TYPE__literal, 
		    TYPE__null, 
		    TYPE__unknown
		} Type;
		Type type;
		std::string name;
		static std::string typeNames[];
	    };
	    typedef std::vector<Field> ColumnSet;
	    virtual ColumnSet cols() = 0;
	    struct value {
	    };
	    typedef std::vector<OptString> Row;
	    virtual Row nextRow() = 0;
	    Row end () { return Row(); } // count on operator!= to say that two empty Row's are ==
	};
	SQLclient () {  }
	virtual ~SQLclient () {  }
	virtual void connect(std::string server, std::string database, std::string user) = 0;
	virtual void connect(std::string server, std::string database, std::string user, std::string password) = 0;
	virtual Result* executeQuery(std::string query) = 0;
    };

    std::string SQLclient::Result::Field::typeNames[] = {
	PREFIX_SWO "_err", 
	PREFIX_XSI "decimal", 
	PREFIX_XSI "float", 
	PREFIX_XSI "double", 
	PREFIX_XSI "short", 
	PREFIX_XSI "integer", 
	PREFIX_XSI "long", 
	PREFIX_XSI "dateTime", 
	PREFIX_XSI "string", 
	"", // PREFIX_SWO "_literal", 
	PREFIX_SWO "_null", 
	PREFIX_SWO "_unknown", 
    };

    class SqlResultSet : public ResultSet {
    public:
	SqlResultSet (AtomFactory* atomFactory, SQLclient::Result* res) : ResultSet(atomFactory) {
	    erase(begin());
	    SQLclient::Result::ColumnSet cols = res->cols();
	    std::vector<const TTerm*> vars;

	    /* dump headers in <th/>s */
	    for (SQLclient::Result::ColumnSet::const_iterator it = cols.begin();
		 it != cols.end(); ++it)
		vars.push_back(atomFactory->getVariable(it->name));

	    knownVars.insert(vars.begin(), vars.end());

	    SQLclient::Result::Row row;
	    while ((row = res->nextRow()) != res->end()) { // !!! use iterator
		Result* result = new Result(this);
		for(size_t i = 0; i < cols.size(); i++)
		    if (row[i].is_initialized()) {
			std::string dt = SQLclient::Result::Field::typeNames[cols[i].type];
			std::string lexval(row[i].get());
			if (cols[i].type == SQLclient::Result::Field::TYPE__err || 
			    cols[i].type == SQLclient::Result::Field::TYPE__unknown)
			    throw std::string("field value \"") + lexval + "\" has unknown datatype";// + cols[i].type;

			if (cols[i].type != SQLclient::Result::Field::TYPE__null) {
			    const URI* dtpos = dt.size() > 0 ? atomFactory->getURI(dt.c_str()) : NULL;
			    const TTerm* val = atomFactory->getRDFLiteral(lexval, dtpos, NULL);
			    set(result, vars[i], val, false);
			}
		    }
		insert(end(), result);
	    }
	}
    };

} // namespace w3c_sw

#ifdef SQL_CLIENT_MYSQL
  #include "../interface/SQLclient_MySQL.hpp"
#endif /* SQL_CLIENT_MYSQL */

#ifdef SQL_CLIENT_ORACLE
  #include "../interface/SQLclient_Oracle.hpp"
#endif /* SQL_CLIENT_ORACLE */

#ifdef SQL_CLIENT_ODBC
  #include "../interface/SQLclient_ODBC.hpp"
#endif /* SQL_CLIENT_ODBC */

#endif // !INCLUDED_interface_SQLclient_hpp

