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
 * SQL:
 *   CREATE TABLE toy (id INTEGER NOT NULL PRIMARY KEY, name VARCHAR(20), age INTEGER);
 *   INSERT INTO toy (id, name, age) VALUES (7, 'Alice', 30);
 *   INSERT INTO toy (id, name, age) VALUES (8, 'Bob', 40);
 *   INSERT INTO toy (id, name, age) VALUES (9, 'Eve', 50);
 * MySQL variant:
 *   CREATE TABLE toy (id INT UNSIGNED NOT NULL PRIMARY KEY, name VARCHAR(20), age INT UNSIGNED);
 *   INSERT INTO toy (id, name, age) VALUES (7, "Alice", 30), (8, "Bob", 40), (9, "Eve", 50);

g++ -DTHREADING -std=c++0x -Wall -g -o SQLclient_main SQLclient_main.cpp -I . -I ../lib -lsybdb && ./SQLclient_main <host> <database> <user> <password> 'SELECT "1" AS a, "2" AS b, "3" AS c UNION ALL SELECT "4", "5", "6"' 'SELECT "A" AS a, "B" AS b, "C" AS c UNION ALL SELECT "D", "E", "F"' 'SELECT "a" AS a, "b" AS b, "c" AS c UNION ALL SELECT "d", "e", "f"' 2> stderr ; cat stderr

 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <string.h>

#include <boost/optional.hpp>
#include <stdarg.h>

#define BOOST_LOG_SEV(A, B) std::cerr

// Excerpts from w3c_sw to enable driver
namespace w3c_sw {

/* ptrequal == algorithm to test equivalence of ptr iteratables. */
template<typename LEFT, typename RIGHT>
inline bool ptrequal(LEFT lit, LEFT end, RIGHT rit) {
    for (; lit != end; ++lit, ++rit)
	if (!(**lit == **rit))
	    return false;
    return true;
}

namespace permute {

    const int UnsetValue = -1; // Must be -1 for { ++level; if (level == 0) } to work.

    /** permute::equals - perform permutation equivalence test.
     * 
     * @indexes - a []-addressable "array" which will hold the indexes of the
     *            order of elements in @r required to matche @l.
     * @l, @r - []-addressable "arrays" of items testable with ==.
     * @f - a functor to call when a permutation of l matches r.
     *      @f returns true to force an early return from walking permutations.
     * 
     * Algorithm taken from <http://www.cut-the-knot.org/do_you_know/AllPerm.shtml>.
     */
    template <typename Index, typename EquatableContainer, typename Functor>
    bool equals(Index& indexes, EquatableContainer& l, EquatableContainer& r,
		Functor& f, int digit = 0, int level = -1) {
	if (level == -1)
	    for (int i = 0; i < (int)l.size(); ++i)
		indexes[i] = UnsetValue;
	++level;
	indexes[digit] = level - 1;
	if (level == 0 || l[digit] == r[level - 1]) { // false truncates this branch of the permutation tree.
	    if (level == (int)l.size()) {
		if (f())
		    return true; // functor says we're done.
	    } else
		for (int i = 0; i < (int)l.size(); ++i)
		    if (indexes[i] == UnsetValue)
			if (equals(indexes, l, r, f, i, level))
			    return true;
	}
	--level;
	indexes[digit] = UnsetValue;
	return false;
    }

    /** permute::equals - perform permutation equivalence test.
     * 
     * @l, @r - []-addressable "arrays" of items testable with ==.
     * @f - a functor to call when a permutation of l matches r.
     *      @f returns true to force an early return from walking permutations.
     */
    template <typename EquatableContainer, typename Functor>
    bool equals(EquatableContainer& l,
    		EquatableContainer& r, Functor& f) {
	int* indexes = new int[l.size()];
    	bool ret = equals(indexes, l, r, f, 0, -1);
	delete[] indexes;
	return ret;
    }

    namespace test {
	struct PermutationList : public std::set<std::vector<int> > {
	    PermutationList () {  }
	    PermutationList (int rows, int cols, ...) {
		va_list args;
		va_start(args, cols);
		for (int r = 0; r < rows; ++r) {
		    std::vector<int> v(cols);
		    for (int c = 0; c < cols; ++c)
			v[c] = va_arg(args, int);
		    insert(v);
		}
		va_end(args);
	    }
	    std::ostream& print(std::ostream& os) const {
		os << "{";
		for (std::set<std::vector<int> >::const_iterator s = begin();
		     s != end(); ++s) {
		    if (s != begin())
			os << "\n ";
		    os << "(";
		    for (std::vector<int>::const_iterator v = s->begin();
			 v != s->end(); ++v) {
			if (v != s->begin())
			    os << ", ";
			os << *v;
		    }
		    os << ")";
		}
		os << "}";
		return os;
	    }
	};
	inline std::ostream& operator<< (std::ostream& os, const PermutationList f) {
	    return f.print(os);
	}

	struct ByVector : PermutationList {
	    std::vector<int>& indexes;
	    // PermutationList found;
	    ByVector (std::vector<int>& indexes) : indexes(indexes) {  }
	    bool operator() ()  {
		std::vector<int> f(indexes.size());
		for (size_t i = 0; i < indexes.size(); ++i)
		    f[i] = indexes[i];
		insert(f);
		return false;
	    }
	};

	struct ByArray : PermutationList {
	    int* indexes;
	    int size;
	    ByArray (int indexes[], int size) : indexes(indexes), size(size) {  }
	    bool operator() ()  {
		std::vector<int> f(size);
		for (int i = 0; i < size; ++i)
		    f[i] = indexes[i];
		insert(f);
		return true;
	    }
	};

	struct EQ {
	    char i;
	    EQ (char i) : i(i) {  }
	    //    void operator= (const EQ& r) { i = r.i; }
	    bool operator== (const EQ& r) const { return i == r.i; }
	    bool operator!= (const EQ& r) const { return i != r.i; }
	    //    bool operator< (const EQ& r) const { return this < &r; }
	    bool operator< (const EQ& r) const { return i < r.i; }
	    std::ostream& print (std::ostream& os) const { return os << i; }
	};
	inline std::ostream& operator<< (std::ostream& os, const EQ& eq) {
	    return eq.print(os);
	}

	struct dereferencer {
	    const std::vector<const EQ*>& ptrs;
	    dereferencer(const std::vector<const EQ*>& ptrs) : ptrs(ptrs) {  }
	    const EQ& operator[] (size_t s) { return *ptrs[s]; }
	    size_t size () const { return ptrs.size(); }
	};

	inline int All () {
	    char il[] = {'a', 'b', 'c', 'a', 'e', 'f', 'g', 'h'};
	    char ir[] = {'a', 'c', 'b', 'a', 'e', 'f', 'h', 'g'};
	    std::vector<EQ> vl(il, il+8);
	    std::vector<EQ> vr(ir, ir+8);

	    PermutationList oneRow(1, 8,
				   0,2,1,3,4,5,7,6);
	    PermutationList twoRows(2, 8,
				    0,2,1,3,4,5,7,6,
				    3,2,1,0,4,5,7,6);

	    {
		std::vector<int> indexes(8);
		ByVector bv(indexes);
		equals(indexes, vl, vr, bv);
		assert(twoRows == bv);
	    }

	    {
		int idx[8];
		ByArray ba(idx, 8);
		equals(idx, vl, vr, ba);
		assert(oneRow == ba);
	    }

	    {
		int* idx = new int[8];
		ByArray ba(idx, 8);
		equals(idx, vl, vr, ba);
		assert(oneRow == ba);
		delete[] idx;
	    }

	    {
		std::vector<const EQ*> vlp(8);
		std::vector<const EQ*> vrp(8);
		for (int i = 0; i < 8; ++i)
		    vlp[i] = new EQ(il[i]);
		for (int i = 0; i < 8; ++i)
		    vrp[i] = new EQ(ir[i]);

		int idx[8];
		ByArray ba(idx, 8);
		dereferencer vld(vlp);
		dereferencer vrd(vrp);
		equals(idx, vld, vrd, ba);
		assert(oneRow == ba);

		for (int i = 0; i < 8; ++i)
		    delete vlp[i];
		for (int i = 0; i < 8; ++i)
		    delete vrp[i];
	    }

	    return 4; // I see three tests above.
	}
    } // namespace test
} // namespace permute

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
	bool addKnownVar (const TTerm* var) { return knownVars.insert(var).second; }
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

class OptString : public boost::optional<std::string> {
    std::string m_emptyString;

public:
    OptString (std::string p_emptyString = "")
	: boost::optional<std::string>(), m_emptyString(p_emptyString) {  }
    OptString (const char* p_str, std::string p_emptyString = "")
	: m_emptyString(p_emptyString) {
	if (p_str != NULL)
	    assign(p_str);
    }
    OptString (std::string p_str, std::string p_emptyString = "")
	: m_emptyString(p_emptyString) {
	assign(p_str);
    }
    std::string toString () {
	return is_initialized() ? get() : m_emptyString;
    }
    const char* c_str () {
	return is_initialized() ? get().c_str() : NULL;
    }
    bool match (const char* match) {
	return (is_initialized() && !strncmp(c_str(), match, strlen(match)));
    }
};
} // namespace w3c_sw


#define SWOb_DISABLED		1
#include <boost/regex.hpp>
#define SWOBJECTS_HH // don't import SWObjects.hpp
#include "SQLclient_MSSQL.hpp"
//#include "SQLclient_Postgres.hpp"


int main (int argc, char* argv[]) {
    try {
	w3c_sw::AtomFactory atomFactory;

	w3c_sw::SQLclient_MSSQL sql;
	sql.connect(argv[1], argv[2], argv[3], argv[4]);
	for (int i = 5; i < argc; ++i) {
	    w3c_sw::SQLclient::Result* res = sql.executeQuery(argv[i]);
	    w3c_sw::SqlResultSet rs(&atomFactory, res);
	    std::cout << rs.toString();
	}
	return 0;
    } catch (std::string s) {
	std::cerr << s;
    }
    return 1;
}

