/* SQLclient_Oracle.hpp: implementation of SQLclient for Oracle.
 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#include "../interface/SQLclient.hpp"

#ifndef INCLUDED_interface_SQLclient_Oracle_hpp
 #define INCLUDED_interface_SQLclient_Oracle_hpp

#include <occi.h>

namespace oocci = oracle::occi;

namespace w3c_sw {

    class SQLclient_Oracle : public SQLclient {
    protected:
	oocci::Environment *env;
	oocci::Connection *conn;
	oocci::Statement *stmt;
	std::string server, database, user;
	virtual void _connect (std::string server, std::string database, std::string user, const char* password) {
	    if (conn != NULL)
		env->terminateConnection(conn);
	    this->server = server;
	    this->database = database;
	    this->user = user;
	    std::stringstream ss;
	    ss << "//" << server << "/" << database;
	    if (!(conn = env->createConnection (user, password, ss.str())))
		throw std::runtime_error(std::string()
					 + "couldn't connect to oracle://" + user
					 + "@" + server + "/" + database);
	}

    public:
	class Result : public SQLclient::Result {
	protected:
	    oocci::ResultSet* result;
	    Result::Fixups& fixups;
	    std::vector<oocci::MetaData> selectcols;
	    ColumnSet colSet;
	    Row row;

	public:

	    struct IntegerToDouble : public Fixup {
		IntegerToDouble () {  }
		virtual std::string operator() (std::string lexval, Field::Type& sqlType) {
		    sqlType = Field::TYPE_double;
		    return lexval;
		}
	    };

	    Result (e_RESULT, Result::Fixups& fixups)
		: result(NULL), fixups(fixups)
	    {  }
	    Result (oocci::ResultSet* result, Result::Fixups& fixups)
		: result(result), fixups(fixups), selectcols(result->getColumnListMetaData())
	    {
		int columnCount = selectcols.size();
		for (int i = 0; i < columnCount; i++) {
		    Field f;
		    f.name = selectcols[i].getString(oocci::MetaData::ATTR_NAME);
		    int typeNo = selectcols[i].getInt(oocci::MetaData::ATTR_DATA_TYPE);
		    switch (typeNo) {
		    case oocci::OCCI_SQLT_NUM:
			f.type = Field::TYPE_integer;
			break;
		    case oocci::OCCI_SQLT_CHR:
		    case oocci::OCCI_SQLT_AFC:
			f.type = Field::TYPE__literal;
			break;
		    default:
			if (true) { // do want a switch to allow unknown datatypes?
			    std::stringstream s;
			    s << "fields[" << i << "] " << f.name << " of unknown type " << datatypeCstr(typeNo);
			    throw s.str();
			}
			f.type = Field::TYPE__unknown;
		    }
		    colSet.push_back(f);
		}
	    }

	    static const char* datatypeCstr (int type) {
		switch (type) {
		case oocci::OCCI_SQLT_CHR: return "OCCI_SQLT_CHR";
		case oocci::OCCI_SQLT_NUM: return "OCCI_SQLT_NUM";
		case oocci::OCCIINT: return "OCCIINT";
		case oocci::OCCIFLOAT: return "OCCIFLOAT";
		case oocci::OCCIBFLOAT: return "OCCIBFLOAT";
		case oocci::OCCIBDOUBLE: return "OCCIBDOUBLE";
		case oocci::OCCIIBFLOAT: return "OCCIIBFLOAT";
		case oocci::OCCIIBDOUBLE: return "OCCIIBDOUBLE";
		case oocci::OCCI_SQLT_STR: return "OCCI_SQLT_STR";
		case oocci::OCCI_SQLT_VNU: return "OCCI_SQLT_VNU";
		case oocci::OCCI_SQLT_PDN: return "OCCI_SQLT_PDN";
		case oocci::OCCI_SQLT_LNG: return "OCCI_SQLT_LNG";
		case oocci::OCCI_SQLT_VCS: return "OCCI_SQLT_VCS";
		case oocci::OCCI_SQLT_NON: return "OCCI_SQLT_NON";
		case oocci::OCCI_SQLT_RID: return "OCCI_SQLT_RID";
		case oocci::OCCI_SQLT_DAT: return "OCCI_SQLT_DAT";
		case oocci::OCCI_SQLT_VBI: return "OCCI_SQLT_VBI";
		case oocci::OCCI_SQLT_BIN: return "OCCI_SQLT_BIN";
		case oocci::OCCI_SQLT_LBI: return "OCCI_SQLT_LBI";
		case oocci::OCCIUNSIGNED_INT: return "OCCIUNSIGNED_INT";
		case oocci::OCCI_SQLT_SLS: return "OCCI_SQLT_SLS";
		case oocci::OCCI_SQLT_LVC: return "OCCI_SQLT_LVC";
		case oocci::OCCI_SQLT_LVB: return "OCCI_SQLT_LVB";
		case oocci::OCCI_SQLT_AFC: return "OCCI_SQLT_AFC";
		case oocci::OCCI_SQLT_AVC: return "OCCI_SQLT_AVC";
		case oocci::OCCI_SQLT_CUR: return "OCCI_SQLT_CUR";
		case oocci::OCCI_SQLT_RDD: return "OCCI_SQLT_RDD";
		case oocci::OCCI_SQLT_LAB: return "OCCI_SQLT_LAB";
		case oocci::OCCI_SQLT_OSL: return "OCCI_SQLT_OSL";
		case oocci::OCCI_SQLT_NTY: return "OCCI_SQLT_NTY";
		case oocci::OCCI_SQLT_REF: return "OCCI_SQLT_REF";
		case oocci::OCCI_SQLT_CLOB: return "OCCI_SQLT_CLOB";
		case oocci::OCCI_SQLT_BLOB: return "OCCI_SQLT_BLOB";
		case oocci::OCCI_SQLT_BFILEE: return "OCCI_SQLT_BFILEE";
		case oocci::OCCI_SQLT_CFILEE: return "OCCI_SQLT_CFILEE";
		case oocci::OCCI_SQLT_RSET: return "OCCI_SQLT_RSET";
		case oocci::OCCI_SQLT_NCO: return "OCCI_SQLT_NCO";
		case oocci::OCCI_SQLT_VST: return "OCCI_SQLT_VST";
		case oocci::OCCI_SQLT_ODT: return "OCCI_SQLT_ODT";
		case oocci::OCCI_SQLT_DATE: return "OCCI_SQLT_DATE";
		case oocci::OCCI_SQLT_TIME: return "OCCI_SQLT_TIME";
		case oocci::OCCI_SQLT_TIME_TZ: return "OCCI_SQLT_TIME_TZ";
		case oocci::OCCI_SQLT_TIMESTAMP: return "OCCI_SQLT_TIMESTAMP";
		case oocci::OCCI_SQLT_TIMESTAMP_TZ: return "OCCI_SQLT_TIMESTAMP_TZ";
		case oocci::OCCI_SQLT_INTERVAL_YM: return "OCCI_SQLT_INTERVAL_YM";
		case oocci::OCCI_SQLT_INTERVAL_DS: return "OCCI_SQLT_INTERVAL_DS";
		case oocci::OCCI_SQLT_TIMESTAMP_LTZ: return "OCCI_SQLT_TIMESTAMP_LTZ";
		    // OCCI_SQLT_FILE  == OCCI_SQLT_BFILEE
		    // OCCI_SQLT_CFILE == OCCI_SQLT_CFILEE
		    // OCCI_SQLT_BFILE == OCCI_SQLT_BFILEE
 
		case oocci::OCCICHAR: return "OCCICHAR";
		case oocci::OCCIDOUBLE: return "OCCIDOUBLE";
		case oocci::OCCIBOOL: return "OCCIBOOL";
		case oocci::OCCIANYDATA: return "OCCIANYDATA";
		case oocci::OCCINUMBER: return "OCCINUMBER";
		case oocci::OCCIBLOB: return "OCCIBLOB";
		case oocci::OCCIBFILE: return "OCCIBFILE";
		case oocci::OCCIBYTES: return "OCCIBYTES";
		case oocci::OCCICLOB: return "OCCICLOB";
		case oocci::OCCIVECTOR: return "OCCIVECTOR";
		case oocci::OCCIMETADATA: return "OCCIMETADATA";
		case oocci::OCCIPOBJECT: return "OCCIPOBJECT";
		case oocci::OCCIREF: return "OCCIREF";
		case oocci::OCCIREFANY: return "OCCIREFANY";
		case oocci::OCCISTRING: return "OCCISTRING";
		case oocci::OCCISTREAM: return "OCCISTREAM";
		case oocci::OCCIDATE: return "OCCIDATE";
		case oocci::OCCIINTERVALDS: return "OCCIINTERVALDS";
		case oocci::OCCIINTERVALYM: return "OCCIINTERVALYM";
		case oocci::OCCITIMESTAMP: return "OCCITIMESTAMP";
		case oocci::OCCIROWID: return "OCCIROWID";
		case oocci::OCCICURSOR: return "OCCICURSOR";
		default: return "???";
		}
	    }

	    virtual ColumnSet& cols () { return colSet; }
	    virtual Row nextRow () {
		Row ret;
		if (!result->next())
		    return ret;
		for(int i = 0; (size_t)i < selectcols.size(); i++) {
		    if (!result->isNull(i+1)) {

			std::string lexval(result->getString(i+1));
			int typeNo = selectcols[i].getInt(oocci::MetaData::ATTR_DATA_TYPE);
			switch (typeNo) {
			case oocci::OCCI_SQLT_NUM:
			case oocci::OCCI_SQLT_CHR:
			case oocci::OCCI_SQLT_AFC:
			    break;
			case oocci::OCCI_SQLT_TIMESTAMP:
			    lexval.replace(lexval.find_first_of(' '), 1, "T");
			    break;
			// case OCCI_SQLT_DATE:
			//     lexval = lexval + "T00:00";
			//     break;
			default:
			    w3c_sw_LINEN << "passing " << datatypeCstr(typeNo) << " \"" << lexval << "\"\n";
			    break;
			}
			for (Result::Fixups::const_iterator it = fixups.find(i); it != fixups.end() && it->first == i; ++it) {
			    boost::shared_ptr<Result::Fixup> p = it->second;
			    Result::Fixup& f = *p;
			    lexval = f(lexval, colSet[i].type);
			}
			ret.push_back(OptString(lexval.c_str())); // @@ why do i need 
		    } else {
			ret.push_back(OptString());
		    }
		}
		return ret;
	    }
	};
	SQLclient_Oracle ()
	    : SQLclient(), env(oocci::Environment::createEnvironment(oocci::Environment::DEFAULT)), conn(NULL)
	{  }
	~SQLclient_Oracle () {
	    if (conn != NULL)
		env->terminateConnection(conn);
	    oocci::Environment::terminateEnvironment(env);
	}
	virtual void connect (std::string server, std::string database, std::string user) {
	    _connect(server, database, user, NULL);
	}
	virtual void connect (std::string server, std::string database, std::string user, std::string password) {
	    _connect(server, database, user, password.c_str());
	}
	virtual Result* executeQuery (std::string query, Result::Fixups& fixups = Result::Fixups::Empty) {
	    stmt = conn->createStatement(query);
	    try {
		if (query.substr(0,6) == "SELECT") {
		     // w3c_sw_LINEN << "SQLclient_Oracle::executeQuery " << query << std::endl;
		    oocci::ResultSet* rset = stmt->executeQuery();
		     // w3c_sw_LINEN << rset->next() << "\n";
		     // w3c_sw_LINEN << rset->getString(0) << "\n";
		    return new Result(rset, fixups);
		} else {
		    // w3c_sw_LINEN << "SQLclient_Oracle::executeUpdate " << query << std::endl;
		    stmt->executeUpdate ();
		    stmt = conn->createStatement("COMMIT");
		    stmt->executeUpdate ();
		    return new Result(Result::RESULT_none, fixups);
		}
	    } catch (oocci::SQLException& err) {
		// w3c_sw_LINEN << err.what() << "\n";
		std::string whatStr = err.what();
		if (whatStr[whatStr.length()-1] == '\n')
		    whatStr.resize(whatStr.length()-1);
		throw std::runtime_error(std::string()
					 + "Oracle error: \"" + whatStr + "\""
					 + " while executing [[" + query + "]].");
	    }
	}

	static const char* datatypeCstr (int type) {
	    switch (type) {
	    case oocci::OCCI_SQLT_CHR: return "OCCI_SQLT_CHR";
	    case oocci::OCCI_SQLT_NUM: return "OCCI_SQLT_NUM";
	    case oocci::OCCIINT: return "OCCIINT";
	    case oocci::OCCIFLOAT: return "OCCIFLOAT";
	    case oocci::OCCIBFLOAT: return "OCCIBFLOAT";
	    case oocci::OCCIBDOUBLE: return "OCCIBDOUBLE";
	    case oocci::OCCIIBFLOAT: return "OCCIIBFLOAT";
	    case oocci::OCCIIBDOUBLE: return "OCCIIBDOUBLE";
	    case oocci::OCCI_SQLT_STR: return "OCCI_SQLT_STR";
	    case oocci::OCCI_SQLT_VNU: return "OCCI_SQLT_VNU";
	    case oocci::OCCI_SQLT_PDN: return "OCCI_SQLT_PDN";
	    case oocci::OCCI_SQLT_LNG: return "OCCI_SQLT_LNG";
	    case oocci::OCCI_SQLT_VCS: return "OCCI_SQLT_VCS";
	    case oocci::OCCI_SQLT_NON: return "OCCI_SQLT_NON";
	    case oocci::OCCI_SQLT_RID: return "OCCI_SQLT_RID";
	    case oocci::OCCI_SQLT_DAT: return "OCCI_SQLT_DAT";
	    case oocci::OCCI_SQLT_VBI: return "OCCI_SQLT_VBI";
	    case oocci::OCCI_SQLT_BIN: return "OCCI_SQLT_BIN";
	    case oocci::OCCI_SQLT_LBI: return "OCCI_SQLT_LBI";
	    case oocci::OCCIUNSIGNED_INT: return "OCCIUNSIGNED_INT";
	    case oocci::OCCI_SQLT_SLS: return "OCCI_SQLT_SLS";
	    case oocci::OCCI_SQLT_LVC: return "OCCI_SQLT_LVC";
	    case oocci::OCCI_SQLT_LVB: return "OCCI_SQLT_LVB";
	    case oocci::OCCI_SQLT_AFC: return "OCCI_SQLT_AFC";
	    case oocci::OCCI_SQLT_AVC: return "OCCI_SQLT_AVC";
	    case oocci::OCCI_SQLT_CUR: return "OCCI_SQLT_CUR";
	    case oocci::OCCI_SQLT_RDD: return "OCCI_SQLT_RDD";
	    case oocci::OCCI_SQLT_LAB: return "OCCI_SQLT_LAB";
	    case oocci::OCCI_SQLT_OSL: return "OCCI_SQLT_OSL";
	    case oocci::OCCI_SQLT_NTY: return "OCCI_SQLT_NTY";
	    case oocci::OCCI_SQLT_REF: return "OCCI_SQLT_REF";
	    case oocci::OCCI_SQLT_CLOB: return "OCCI_SQLT_CLOB";
	    case oocci::OCCI_SQLT_BLOB: return "OCCI_SQLT_BLOB";
	    case oocci::OCCI_SQLT_BFILEE: return "OCCI_SQLT_BFILEE";
	    case oocci::OCCI_SQLT_CFILEE: return "OCCI_SQLT_CFILEE";
	    case oocci::OCCI_SQLT_RSET: return "OCCI_SQLT_RSET";
	    case oocci::OCCI_SQLT_NCO: return "OCCI_SQLT_NCO";
	    case oocci::OCCI_SQLT_VST: return "OCCI_SQLT_VST";
	    case oocci::OCCI_SQLT_ODT: return "OCCI_SQLT_ODT";
	    case oocci::OCCI_SQLT_DATE: return "OCCI_SQLT_DATE";
	    case oocci::OCCI_SQLT_TIME: return "OCCI_SQLT_TIME";
	    case oocci::OCCI_SQLT_TIME_TZ: return "OCCI_SQLT_TIME_TZ";
	    case oocci::OCCI_SQLT_TIMESTAMP: return "OCCI_SQLT_TIMESTAMP";
	    case oocci::OCCI_SQLT_TIMESTAMP_TZ: return "OCCI_SQLT_TIMESTAMP_TZ";
	    case oocci::OCCI_SQLT_INTERVAL_YM: return "OCCI_SQLT_INTERVAL_YM";
	    case oocci::OCCI_SQLT_INTERVAL_DS: return "OCCI_SQLT_INTERVAL_DS";
	    case oocci::OCCI_SQLT_TIMESTAMP_LTZ: return "OCCI_SQLT_TIMESTAMP_LTZ";
		// OCCI_SQLT_FILE  == OCCI_SQLT_BFILEE
		// OCCI_SQLT_CFILE == OCCI_SQLT_CFILEE
		// OCCI_SQLT_BFILE == OCCI_SQLT_BFILEE
 
	    case oocci::OCCICHAR: return "OCCICHAR";
	    case oocci::OCCIDOUBLE: return "OCCIDOUBLE";
	    case oocci::OCCIBOOL: return "OCCIBOOL";
	    case oocci::OCCIANYDATA: return "OCCIANYDATA";
	    case oocci::OCCINUMBER: return "OCCINUMBER";
	    case oocci::OCCIBLOB: return "OCCIBLOB";
	    case oocci::OCCIBFILE: return "OCCIBFILE";
	    case oocci::OCCIBYTES: return "OCCIBYTES";
	    case oocci::OCCICLOB: return "OCCICLOB";
	    case oocci::OCCIVECTOR: return "OCCIVECTOR";
	    case oocci::OCCIMETADATA: return "OCCIMETADATA";
	    case oocci::OCCIPOBJECT: return "OCCIPOBJECT";
	    case oocci::OCCIREF: return "OCCIREF";
	    case oocci::OCCIREFANY: return "OCCIREFANY";
	    case oocci::OCCISTRING: return "OCCISTRING";
	    case oocci::OCCISTREAM: return "OCCISTREAM";
	    case oocci::OCCIDATE: return "OCCIDATE";
	    case oocci::OCCIINTERVALDS: return "OCCIINTERVALDS";
	    case oocci::OCCIINTERVALYM: return "OCCIINTERVALYM";
	    case oocci::OCCITIMESTAMP: return "OCCITIMESTAMP";
	    case oocci::OCCIROWID: return "OCCIROWID";
	    case oocci::OCCICURSOR: return "OCCICURSOR";
	    default: return "???";
	    }
	}
    };

} /* namespace w3c_sw */

#ifdef NEEDDEF_W3C_SW_SQLCLIENT
  #undef NEEDDEF_W3C_SW_SQLCLIENT
  #define W3C_SW_SQLCLIENT w3c_sw::SQLclient_Oracle
#endif /* NEEDDEF_W3C_SW_SQLCLIENT */

#endif // !INCLUDED_interface_SQLclient_Oracle_hpp

