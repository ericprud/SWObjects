/**
 * SQLclient_main - a stand-alone tool for testing SQLclient drivers.
 *
 * Copy these files SQLclient.hpp, SQLclient_main.cpp and the driver
 * you want to develop, e.g. SQLclient_MySQL.hpp or SQLclient_ODBC.hpp from
 *   http://swobjects.svn.sourceforge.net/viewvc/swobjects/branches/sparql11/interface/
 * Go to the main (below) and uncomment the header you want to develop, e.g.
 *   #include "SQLclient_MySQL.hpp"
 * Uncomment (or add) the instantiation of the driver you want to develop
 * and follow the build and invocation instructions just above. Invocations
 * count on a database named "test" containing an SQL table toy:
 *  CREATE TABLE toy (id INT UNSIGNED NOT NULL PRIMARY KEY, name VARCHAR(20), age INT UNSIGNED);
 *  INSERT INTO toy (id, name, age) VALUES (7, "Alice", 30), (8, "Bob", 40), (9, "Eve", 50);
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>

namespace w3c_sw {

    class TTerm {
    protected:
	std::string lex;
    public:
	TTerm (std::string lex) : lex(lex) {  }
	virtual std::string toString() const = 0;
    };

    class Variable : public TTerm {
    public:
	Variable (std::string lex) : TTerm(lex) {  }
	virtual std::string toString () const { return std::string("?") + lex; }
    };

    class URI : public TTerm {
    public:
	URI (std::string lex) : TTerm(lex) {  }
	virtual std::string toString () const { return std::string("<") + lex + ">"; }
    };

    class LANGTAG {
    };

    class RDFLiteral : public TTerm {
    public:
	RDFLiteral (std::string lex) : TTerm(lex) {  }
	virtual std::string toString () const { return std::string("\"") + lex + "\""; }
    };

    class AtomFactory {
    public:
	const Variable* getVariable (std::string name) { return new Variable(name); }
	const URI* getURI (std::string name) { return new URI(name); }
	const RDFLiteral* getRDFLiteral (std::string p_String, const URI* p_URI = NULL, const LANGTAG* p_LANGTAG = NULL, bool validate = false) {
	    return new RDFLiteral(p_String);
	}
    };

    class ResultSet {
    public:
	class Result {
	    std::map<const TTerm*, const TTerm*> bindings;
	public:
	    Result (ResultSet*) {  }
	    void set (const TTerm* variable, const TTerm* value) {
		bindings[variable] = value;
	    }
	    std::string toString () {
		std::stringstream ss;
		ss << "{";
		for (std::map<const TTerm*, const TTerm*>::iterator it = bindings.begin(); it != bindings.end(); ++it)
		    ss << " " << it->first->toString() << "=" << it->second->toString();
		ss << " }";
		return ss.str();
	    }
	};

	typedef std::set<const TTerm*> VariableList;
	typedef std::set<const TTerm*>::iterator VariableListIterator;
	typedef std::set<const TTerm*>::const_iterator VariableListConstIterator;
	typedef std::list<Result*> ResultList;
	typedef std::list<Result*>::iterator ResultSetIterator;
	typedef std::list<Result*>::const_iterator ResultSetConstIterator;

	ResultList results;
	VariableList knownVars;

	ResultSet (AtomFactory*) {
	    results.insert(results.begin(), new Result(this));
	}

	ResultSetIterator begin () { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	ResultSetIterator erase (ResultSetIterator it) { return results.erase(it); }
	void set (Result* r, const TTerm* variable, const TTerm* value, bool) {
	    r->set(variable, value);	    
	}
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	std::string toString () {
	    std::stringstream ss;
	    for (ResultSetIterator it = begin(); it != end(); ++it)
		ss << (*it)->toString() << "\n";
	    return ss.str();
	}
    };

} // namespace w3c_sw

#include "SQLclient_MySQL.hpp"
//#include "SQLclient_ODBC.hpp"

int main (int argc, char* argv[]) {
    try {
	w3c_sw::AtomFactory atomFactory;

// g++ -o SQLclient_main -g SQLclient_main.cpp -lmysqlclient &&
// SQLclient_main localhost test root "" "SELECT who.name AS name, who.age AS age FROM toy AS who"
	w3c_sw::SQLclient_MySQL sql;
	sql.connect(argv[1], argv[2], argv[3], argv[4]);
	w3c_sw::SQLclient::Result* res = sql.executeQuery(argv[5]);

// g++ -o SQLclient_main -g SQLclient_main.cpp -lodbc &&
// SQLclient_main "odbc:oracle:Server=localhost;Database=test;Uid=root;" "SELECT who.name AS name, who.age AS age FROM toy AS who"
// 	w3c_sw::SQLclient_ODBC sql(argv[1]);
// 	sql.connect("", "", "", "");
// 	w3c_sw::SQLclient::Result* res = sql.executeQuery(argv[2]);

	w3c_sw::SqlResultSet rs(&atomFactory, res);
	std::cout << rs.toString();
	return 0;
    } catch (std::string s) {
	std::cerr << s;
    }
    return 1;
}

