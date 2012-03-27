/* SQLclient - abstract inferface for SQL clients

 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef INCLUDED_interface_SQLclient_hpp
 #define INCLUDED_interface_SQLclient_hpp

#include <boost/shared_ptr.hpp>

#define PREFIX_XSI "http://www.w3.org/2001/XMLSchema#"
#define PREFIX_SWO "http://swobjects.sourceforge.net/ns#"

namespace w3c_sw {

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


	    typedef std::vector<Field> ColumnSet;
	    virtual ColumnSet& cols() = 0;
	    struct Row : public std::vector<OptString> {

		static std::string base64_encode(std::string encodeMe) {
	    // http://www.adp-gmbh.ch/cpp/common/base64.html
	    static const std::string base64_chars = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";

	    char const* bytes_to_encode = &encodeMe[0];
	    unsigned int in_len = encodeMe.size();

  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

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
			    lexval = base64_encode(lexval);
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
	};

	SQLclient () {  }
	virtual ~SQLclient () {  }
	virtual void connect(std::string server, std::string database, std::string user) = 0;
	virtual void connect(std::string server, std::string database, std::string user, std::string password) = 0;
	virtual Result* executeQuery(std::string query, Result::Fixups& fixups = Result::Fixups::Empty) = 0;
    };

    /* SQL type to XSD type mapping: http://www.w3.org/2001/sw/rdb2rdf/r2rml/#table-type-mapping */
    std::string SQLclient::Result::Field::typeNames[] = {
	PREFIX_SWO "_err", 
	"", /* PREFIX_SWO "_literal", */
	PREFIX_XSI "base64Binary", 
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

	    /* dump headers in <th/>s */
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

#ifdef SQL_CLIENT_ORACLE
  #include "../interface/SQLclient_Oracle.hpp"
#endif /* SQL_CLIENT_ORACLE */

#ifdef SQL_CLIENT_ODBC
  #include "../interface/SQLclient_ODBC.hpp"
#endif /* SQL_CLIENT_ODBC */

#endif // !INCLUDED_interface_SQLclient_hpp

