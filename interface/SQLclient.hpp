/* SQLclient - abstract inferface for SQL clients

 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef SQL_CLIENT_H
#define SQL_CLIENT_H

#define PREFIX_XSI "http://www.w3.org/2001/XMLSchema#"
#define PREFIX_SWO "http://swobjects.sourceforge.net/ns#"

namespace w3c_sw {

    class SQLclient {
    protected:
	std::string mediaType;
    public:
	class Result {
	public:
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
		    TYPE__unknown, 
		} Type;
		Type type;
		std::string name;
		static std::string typeNames[];
	    };
	    typedef std::vector<Field> ColumnSet;
	    virtual ColumnSet cols() = 0;
	    typedef std::vector<std::string> Row;
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
	PREFIX_SWO "_literal", 
	PREFIX_SWO "_null", 
	PREFIX_SWO "_unknown", 
    };

} // namespace w3c_sw

#endif // !SQL_CLIENT_H

