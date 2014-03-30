/**
 * SQL expression structure with equivalence method "mapsTo" which allows for
 * relvar (table alias) mappings, e.g.
 *    SELECT * FROM tbl1 AS rv1, tbl2 AS rv2 WHERE (rv1.attr1 = rv2.attr2)
 *   is equivalent to
 *    SELECT * FROM tbl1 AS rvA, tbl2 AS rvB WHERE (rvA.attr1 = rvB.attr2)
 *   with (rv1->rvA, rv2->rvB)
 *
 * Expression have a method mapsTo(const Expression& right). In order to compare
 * final Expression subtypes, there mapsTo calls right->finalMapsTo(*this) which
 * invokes either a default virtual method which returns false, or a specific
 * overload which compares final types, eg. BooleanEQ::finalMapsTo(BooleanEQ*).
 * (This uses the vtable for what would be an enumerated union in C).
 *
 * Copyright 2011 Eric Prud'hommeaux for W3C.
 * Released into the public domain under MIT and Apache open source licenses.
 */

#ifndef INCLUDE_SQL_HPP
 #define INCLUDE_SQL_HPP

#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include "SWObjects.hpp"
#include <boost/shared_ptr.hpp>
#include <stdarg.h>

namespace w3c_sw {

    namespace sql {

	/* SQL types: */
	/* 'NATIONAL'? 'CHARACTER' ('VARYING' | 'LARGE' 'OBJECT')? | 'VARCHAR'
	 * 'BINARY' ('VARYING' | 'LARGE' 'OBJECT')? | 'VARBINARY'
	 * 'NUMERIC' | 'DECIMAL'
	 * 'SMALLINT' | ('INTEGER' | 'INT') | 'BIGINT'
	 * 'FLOAT' | 'REAL' | 'DOUBLE' 'PRECISION'
	 * 'BOOLEAN'
	 * 'DATE'
	 * 'TIME'
	 * 'TIMESTAMP' | 'DATETIME'
	 * 'INTERVAL'
	 */
	struct DataType {
	    typedef enum {TYPENAME_error,
			  TYPENAME_char,
			  TYPENAME_binary,
			  TYPENAME_decimal,
			  TYPENAME_int,
			  TYPENAME_float,
			  TYPENAME_real,
			  TYPENAME_double,
			  TYPENAME_boolean,
			  TYPENAME_date,
			  TYPENAME_time,
			  TYPENAME_datetime,
			  TYPENAME_timestamp,
			  TYPENAME_interval} e_TYPENAME;
	    typedef enum {NATIONALITY_domestic,
			  NATIONALITY_national} e_NATIONALITY;
	    typedef enum {VARIABILITY_fixed,
			  VARIABILITY_varying,
			  VARIABILITY_blob} e_VARIABILITY;
	    e_TYPENAME name;
	    e_NATIONALITY national;
	    e_VARIABILITY variable;
	    bool operator== (const DataType& ref) const {
		return name == ref.name
		    && national == ref.national
		    && variable == ref.variable;
	    }
	    DataType ()
	    	: name(TYPENAME_error), national(NATIONALITY_domestic), variable(VARIABILITY_fixed)
	    {  }
	    DataType (e_TYPENAME name)
	    	: name(name), national(NATIONALITY_domestic), variable(VARIABILITY_fixed)
	    {  }
	    DataType (e_TYPENAME name, e_VARIABILITY variable)
	    	: name(name), national(NATIONALITY_domestic), variable(variable)
	    {  }
	    DataType (e_TYPENAME name, e_NATIONALITY national, e_VARIABILITY variable)
	    	: name(name), national(national), variable(variable)
	    {  }
	};
#define SQL_PRECISION_unspecified -1

	/** abstract class for serializing SQL.
	 */
	class AliasAttr;
	struct Serializer {
	    virtual std::string name(std::string s) = 0;
	    virtual std::string name(AliasAttr aa);
	    virtual std::string literal(std::string s) = 0;
	    virtual std::string typeString(DataType type, int precision) = 0;
	    virtual std::string typedValue(DataType type, std::string representation) = 0;
	    virtual std::string hexString(const std::vector<unsigned char>& bytes) = 0;
	    virtual std::string booleanValue(bool value) = 0;
	    virtual std::string as() = 0;
	    virtual std::string limit(int l) = 0;
	    virtual std::string offset(int o) = 0;
	    static Serializer* best(std::string driver);
	};
	template<int dummy>
	struct SQLSerializer_dummyTemplate : public Serializer {
	    virtual std::string name (std::string s) {
		return std::string() + (true ? "\"" : "") + s + (true ? "\"" : "");
	    }
	    virtual std::string literal (std::string s) {
		return std::string() + (true ? "'" : "") + s + (true ? "'" : "");
	    }
	    virtual std::string typeString (DataType type, int precision) {
		std::stringstream ss;
		if (type.national == DataType::NATIONALITY_national)
		    ss << "NATIONAL ";
		switch (type.name) {
		case DataType::TYPENAME_error:	   ss << "ERROR"    ; break;
		case DataType::TYPENAME_char:	   ss << "CHAR"	    ; break;
		case DataType::TYPENAME_binary:	   ss << "BINARY"   ; break;
		case DataType::TYPENAME_decimal:   ss << "DECIMAL"  ; break;
		case DataType::TYPENAME_int:	   ss << "INT"	    ; break;
		case DataType::TYPENAME_float:	   ss << "FLOAT"    ; break;
		case DataType::TYPENAME_real:	   ss << "REAL"	    ; break;
		case DataType::TYPENAME_double:	   ss << "DOUBLE"   ; break;
		case DataType::TYPENAME_boolean:   ss << "BOOLEAN"  ; break;
		case DataType::TYPENAME_date:	   ss << "DATE"	    ; break;
		case DataType::TYPENAME_time:	   ss << "TIME"	    ; break;
		case DataType::TYPENAME_timestamp: ss << "TIMESTAMP"; break;
		case DataType::TYPENAME_datetime:  ss << "DATETIME" ; break;
		case DataType::TYPENAME_interval:  ss << "INTERVAL" ; break;
		default:
		    {
			std::stringstream ss;
			ss << "unknown DataType: " << type.name;
			throw std::runtime_error(ss.str());
		    }
		}
		if (type.variable == DataType::VARIABILITY_varying)
		    ss << " VARYING";
		if (precision != SQL_PRECISION_unspecified)
		    ss << "(" << precision << ")";
		return ss.str();
	    }

	    // typeString_VAR is an explicit variation factored out for all those DBs which don't parse "VARYING":
	    std::string typeString_VAR (DataType type, int precision) {
		if (type.variable == DataType::VARIABILITY_varying) {
		    std::stringstream ss;
		    if (type.national == DataType::NATIONALITY_national)
			ss << "NATIONAL ";
		    switch (type.name) {
		    case DataType::TYPENAME_char:	ss << "VARCHAR"   << "(" << precision << ")"; break;
		    case DataType::TYPENAME_binary:	ss << "VARBINARY" << "(" << precision << ")"; break;
		    default:
			{
			    ss << "DataType: " << type.name << " can't be VARYING";
			    throw std::runtime_error(ss.str());
			}
		    }
		    return ss.str();
		}
		return SQLSerializer_dummyTemplate<dummy>::typeString(type, precision);
	    }

	    virtual std::string typedValue (DataType, std::string representation) {
		return representation;
	    }
	    virtual std::string booleanValue (bool value) {
		return value ? "true" : "false";
	    }
	    virtual std::string hexString (const std::vector<unsigned char>& bytes) {
		std::stringstream ss;
		ss << "X'" << std::hex << std::uppercase;
		for (std::vector<unsigned char>::const_iterator it = bytes.begin();
		     it != bytes.end(); ++it)
		    ss << std::setw(2) << std::setfill('0') << (int)*it;
		ss << "'";
		return ss.str();
	    }
	    virtual std::string as () { return "AS "; }
	    virtual std::string limit (int l) {
		std::stringstream ss;
		ss << "LIMIT " << l;
		return ss.str();
	    }
	    virtual std::string offset (int o) {
		std::stringstream ss;
		ss << "OFFSET " << o;
		return ss.str();
	    }
	    static SQLSerializer_dummyTemplate<dummy> It;
	};
	template<int dummy>
	SQLSerializer_dummyTemplate<dummy> SQLSerializer_dummyTemplate<dummy>::It;
	typedef SQLSerializer_dummyTemplate<0> SQLSerializer;

	/* Serializers for popular SQL engines. */
	struct MySQLSerializer : public SQLSerializer {
	    virtual std::string name (std::string s) {
		return std::string() + (true ? "`" : "") + s + (true ? "`" : "");
	    }
	    virtual std::string literal (std::string s) {
		return std::string() + (true ? "\"" : "") + s + (true ? "\"" : "");
	    }
	    virtual std::string typeString (DataType type, int precision) {
		return SQLSerializer::typeString_VAR(type, precision);
	    }
	};
	struct PostgresSerializer : public SQLSerializer {
	    virtual std::string typeString (DataType type, int precision) {
		return
		    type.name == DataType::TYPENAME_binary
		    ? "BYTEA"
		    : SQLSerializer::typeString(type, precision);
	    }
	    virtual std::string hexString (const std::vector<unsigned char>& bytes) {
		std::stringstream ss;
		ss << "decode('" << std::hex << std::uppercase;
		for (std::vector<unsigned char>::const_iterator it = bytes.begin();
		     it != bytes.end(); ++it)
		    ss << std::setw(2) << std::setfill('0') << (int)*it;
		ss << "', 'hex')";
		return ss.str();
	    }
	};
	struct OracleSerializer : public SQLSerializer {
	    virtual std::string typeString (DataType type, int precision) {
		return
		    type.name == DataType::TYPENAME_boolean
		    ? "NUMERIC(1)"
		    : type.name == DataType::TYPENAME_binary
		    ? "BLOB"
		    : SQLSerializer::typeString(type, precision);
	    }
	    virtual std::string typedValue (DataType type, std::string representation) {
		return
		    type.name == DataType::TYPENAME_date
		    ? std::string() + "TO_DATE(" + representation + ", 'yyyy-mm-dd')"
		    : type.name == DataType::TYPENAME_time
		    ? std::string() + "TO_DATE(" + representation + ", 'yyyy-mm-dd')"
		    : (type.name == DataType::TYPENAME_timestamp || type.name == DataType::TYPENAME_datetime)
		    ? std::string() + "TO_DATE(" + representation + ", 'yyyy-mm-dd HH24:MI:SS')"
		    : representation;
	    }
	    virtual std::string hexString (const std::vector<unsigned char>& bytes) {
		std::stringstream ss; // presuming a RAW field, just insert a quoted hex string.
		ss << "'" << std::hex << std::uppercase;
		for (std::vector<unsigned char>::const_iterator it = bytes.begin();
		     it != bytes.end(); ++it)
		    ss << std::setw(2) << std::setfill('0') << (int)*it;
		ss << "'";
		return ss.str();
	    }
	    virtual std::string booleanValue(bool value) {
		return value ? "1" : "0"; // goes with NUMERIC(1)
	    }
	    virtual std::string as () { return ""; }
	    virtual std::string offset (int o) {
		std::stringstream ss;
		ss << "rownum > " << o;
		return ss.str();
	    }
	    virtual std::string limit (int l) {
		std::stringstream ss;
		ss << "rownum <= " << l;
		return ss.str();
	    }
	};

	struct MSSQLSerializer : public SQLSerializer {
	    virtual std::string as () { return ""; }
	    virtual std::string offset (int o) {
		std::stringstream ss;
		ss << " OFFSET " << o << " ROW";
		return ss.str();
	    }
	    virtual std::string limit (int l) {
		std::stringstream ss;
		ss << " FETCH NEXT " << l << " ROWS ONLY";
		return ss.str();
	    }
	};

	inline Serializer* Serializer::best (std::string driver) {
	    if (driver == "mysql")
		return new w3c_sw::sql::MySQLSerializer();
	    else if (driver == "postgres")
		return new w3c_sw::sql::PostgresSerializer();
	    else if (driver == "oracle")
		return new w3c_sw::sql::OracleSerializer();
	    else if (driver == "mssql")
		return new w3c_sw::sql::MSSQLSerializer();
	    else
		return new w3c_sw::sql::SQLSerializer();
	}

	/**
	 * enforce type consistency for
	 *   RelationName - a table name.
	 *   RelVar - a table alias.
	 *   Attribute - a table column name.
	 *   AttrAlias - an alias for a selected Attribute.
	 */
	struct RelationName : public std::string {
	    RelationName (std::string s) : std::string(s) {  }
	};
	struct RelVar : public std::string {
	    RelVar (std::string s) : std::string(s) {  }
	};
	struct Attribute : public std::string {
	    Attribute (std::string s) : std::string(s) {  }
	};
	struct AttrAlias : public std::string { // select foo as bar;
	    AttrAlias (std::string s) : std::string(s) {  }
	};

	struct OnezFine {
	    bool operator() ()  { return true; }
	};

	template <typename T>
	struct dereferencer {
	    const std::vector<T*>& ptrs;
	    dereferencer(const std::vector<T*>& ptrs) : ptrs(ptrs) {  }
	    T& operator[] (size_t s) { return *ptrs[s]; }
	    size_t size () const { return ptrs.size(); }
	};


	/**
	 * test if "SELECT rv1.attr1 FROM t1 AS rv1" == "SELECT rv2.attr1 FROM t1 AS rv2"
	 */
	namespace AliasMapping {
	    struct Row : public std::map<RelVar, RelVar> {
		std::string str () const {
		    std::stringstream ss;
		    ss << "  " << size() << " bindings: ( ";
		    for (const_iterator binding = begin(); binding != end(); ++binding)
			ss << binding->first << "->" << binding->second << " ";
		    ss << ")";
		    return ss.str();
		}
	    };
	    struct List : std::list<Row> {
		List (size_t s) : std::list<Row>(s) {  }
		List (int rows, int cols, ...) {
		    va_list args;
		    va_start(args, cols);
		    for (int r = 0; r < rows; ++r) {
			Row m;
			for (int c = 0; c < cols; ++c) {
			    RelVar l(va_arg(args, const char*));
			    RelVar r(va_arg(args, const char*));
			    m.insert(std::make_pair(l, r));
			}
			push_back(m);
		    }
		    va_end(args);
		}
		std::string str () const {
		    std::stringstream ss;
		    ss << size() << " rows: {\n";
		    for (const_iterator row = begin(); row != end(); ++row)
			ss << row->str() << "\n";
		    ss << "}\n";
		    return ss.str();
		}
		List () : std::list<Row>(1) {  }
		List (AliasMapping::Row& row) : std::list<Row>(0) {
		    std::list<Row>::insert(end(), AliasMapping::Row(row));
		}
		void operator+= (const List& r) {
		    for (const_iterator it = r.begin(); it != r.end(); ++it)
			push_back(*it);
		}
		virtual bool matches (const RelVar& key, const RelVar& value) {
		    bool ret = false;
		    for (iterator row = begin();
			 row != end();) {
			Row::iterator m = row->find(key);
			if (m != row->end()) {
			    if (m->second == value) {
				ret = true;
				++row;
			    } else {
				row = erase(row);
			    }
			} else {
			    row->insert(make_pair(key, value));
			    ret = true;
			    ++row;
			}
		    }
		    return ret;
		}
		bool fail () {
		    clear();
		    return false;
		}

		/** Exploring the ways one conjunction can map onto another
		 * requires testing all of the permutations of those
		 * combinations.  permute iterates over calls to the internal
		 * permute1 method.
		 * 
		 * Note that this algorithm enables recursive traversal of lists
		 * of solutions. Other algorithms would require a (costly) trie
		 * of working result sets for any tree of permutations.
		 */

		/** permute - recursive function to explore the ways two
		 * ExprSets can be combined.
		 * @Mappable - can bool mapsTo(const Mappable& right, Editor);
		 */
		template <typename Mappable>
		bool permute (std::set<Mappable*> l, std::set<Mappable*> r) {
		    // Knock off a couple simple ones:
		    if (l.size() != r.size())
			return false;
		    if (l.size() == 0)
			return true;

		    bool ret = false;
		    const Mappable* left = *l.begin();
		    l.erase(left);

		    List newMap;
		    newMap.erase(newMap.begin());
		    for (typename std::set<Mappable*>::const_iterator rit = r.begin();
			 rit != r.end(); ++rit) {
			std::set<Mappable*> rcopy(r);
			const Mappable* right = *rit; rcopy.erase(right);

			List m2(*this);
			bool matched = left->mapsTo(*right, m2);
			// w3c_sw_LINEN << (matched ? "matched" : "no match") << "\n";
			ret |= matched;
			if (matched) {
			    if (l.size() > 0)
				m2.permute(l, rcopy);
			    newMap += m2;
			}
		    }

		    *this = newMap;
		    return ret;
		}

		/** orderedMap - test each element in a container.
		 * 
		 * @Mappable - can bool mapsTo(const Mappable& right, Editor);
		 */
		template<typename LEFT, typename RIGHT>
		inline bool orderedMap(LEFT lit, LEFT end, RIGHT rit) {
		    for (; lit != end; ++lit, ++rit)
			if (!((*lit)->mapsTo(**rit, *this)))
			    return false;
		    return true;
		}
	    };
	} // namespace AliasMapping

	/** e_PREC - operator precedence levels
	 * Useful to keep unnecessary ()s out of expression serializations.
	 */
	typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		      PREC_And, 
		      PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		      PREC_Plus, PREC_Minus, 
		      PREC_Times, PREC_Divide, 
		      PREC_Not, PREC_TTerm, PREC_Neg, PREC_High = PREC_Neg} e_PREC;

	/** AliasAttr - attribute in a relvar. In SQL, this looks like
	 *   SELECT tableAlias1.attribute1
	 */
	class AliasAttr {
	public:
	    RelVar alias;
	    Attribute attr;
	    //	    AliasAttr () {  }
	    AliasAttr (RelVar alias, Attribute attr) : alias(alias), attr(attr) {  }
	    virtual ~AliasAttr () {  }
	    virtual bool mapsTo (const AliasAttr& ref, AliasMapping::List& map) const {
		if (attr == ref.attr)
		    return map.matches(alias, ref.alias);
		else
		    return map.fail();
	    }
	    virtual bool operator== (const AliasAttr& ref) const {
		return alias == ref.alias && attr == ref.attr;
	    }
	    std::string str () const { return toString(); } // for debugger invocation
	    virtual std::string toString (Serializer& /* s */ = SQLSerializer::It) const {
		return alias + "." + attr;
	    }
	};

	inline std::string Serializer::name (AliasAttr aa) {
	    return name(aa.alias) + "." + name(aa.attr);
	}

	/* Implementable subclassed of Constraint:  */
	class DisjunctionConstraint;
	class ConjunctionConstraint;
	class AliasAttrConstraint;
	class IsNullConstraint;
	class IntConstraint;
	class FloatConstraint;
	class DoubleConstraint;
	class LiteralConstraint;
	class HexConstraint;
	class BoolConstraint;
	//class BooleanConjunction;
	class NotNullConstraint;
	class NegationConstraint;
	class ArithOperation;
	class BooleanEQ;
	class BooleanNE;
	class BooleanLT;
	class BooleanGT;
	class BooleanLE;
	class BooleanGE;
	class BooleanNegation;
	class ArithmeticProduct;
	class ArithmeticInverse;
	class ArithmeticSum;
	class ArithmeticNegation;
	class HomologConstraint;
	class RegexConstraint;
	class CastConstraint;

	struct EquivSet;

	class Expression {
	protected:
	public:
	    Expression () {  }
	    virtual ~Expression () {  }
	    virtual Expression* clone() const = 0;
	    std::string str () const { return toString(); }
	    bool logNotMappable (const Expression& r) const {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << toString() << " doesn't map to " << r.toString();
		return false;
	    }
	    bool logNotEqual (const Expression& r) const {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << toString() << " != " << r.toString();
		return false;
	    }
	    virtual std::string toString(std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const = 0;
	    virtual e_PREC getPrecedence() const = 0;
	    virtual bool finalEq (const DisjunctionConstraint&) const { return false; }
	    virtual bool finalEq (const ConjunctionConstraint&) const { return false; }
	    virtual bool finalEq (const IsNullConstraint&) const { return false; }
	    virtual bool finalEq (const IntConstraint&) const { return false; }
	    virtual bool finalEq (const FloatConstraint&) const { return false; }
	    virtual bool finalEq (const DoubleConstraint&) const { return false; }
	    virtual bool finalEq (const LiteralConstraint&) const { return false; }
	    virtual bool finalEq (const HexConstraint&) const { return false; }
	    virtual bool finalEq (const BoolConstraint&) const { return false; }
	    //virtual bool finalEq (const BooleanConjunction&) const { return false; }
	    virtual bool finalEq (const NotNullConstraint&) const { return false; }
	    virtual bool finalEq (const NegationConstraint&) const { return false; }
	    virtual bool finalEq (const AliasAttrConstraint&) const { return false; }
	    virtual bool finalEq (const ArithOperation&) const { return false; }
	    virtual bool finalEq (const BooleanEQ&) const { return false; }
	    virtual bool finalEq (const BooleanNE&) const { return false; }
	    virtual bool finalEq (const BooleanLT&) const { return false; }
	    virtual bool finalEq (const BooleanGT&) const { return false; }
	    virtual bool finalEq (const BooleanLE&) const { return false; }
	    virtual bool finalEq (const BooleanGE&) const { return false; }
	    virtual bool finalEq (const BooleanNegation&) const { return false; }
	    virtual bool finalEq (const ArithmeticProduct&) const { return false; }
	    virtual bool finalEq (const ArithmeticInverse&) const { return false; }
	    virtual bool finalEq (const ArithmeticSum&) const { return false; }
	    virtual bool finalEq (const ArithmeticNegation&) const { return false; }
	    virtual bool finalEq (const HomologConstraint&) const { return false; }
	    virtual bool finalEq (const RegexConstraint&) const { return false; }
	    virtual bool finalEq (const CastConstraint&) const { return false; }
	    virtual bool mapsTo(const Expression&, AliasMapping::List&) const = 0;
	    virtual bool operator==(const Expression&) const = 0;

	    virtual bool finalMapsTo (const DisjunctionConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const ConjunctionConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const IsNullConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const IntConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const FloatConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const DoubleConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const LiteralConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const HexConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BoolConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    //virtual bool finalMapsTo (const BooleanConjunction&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const NotNullConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const NegationConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const AliasAttrConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const ArithOperation&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanEQ&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanNE&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanLT&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanGT&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanLE&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanGE&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const BooleanNegation&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const ArithmeticProduct&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const ArithmeticInverse&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const ArithmeticSum&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const ArithmeticNegation&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const HomologConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const RegexConstraint&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const CastConstraint&, AliasMapping::List& map) const { return map.fail(); }
	};
	
	/** OrderedExpression - Expressions with an ascending or descending sense.
	 */
	struct OrderedExpression {
	    Expression* expression;
	    bool descending;
	    OrderedExpression (Expression* expression, bool descending)
		: expression(expression), descending(descending)
	    {  }
	    bool operator== (const OrderedExpression& r) const {
		return descending != r.descending && *expression == *r.expression;
	    }
	    virtual bool mapsTo (const OrderedExpression& r, AliasMapping::List& map) const {
		// !! shouldn't do an unordered test of orderedBy
		return expression->mapsTo(*r.expression, map);
	    }
	    std::string toString (std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::string ret = expression->toString(pad, parentPrec, driver, s);
		if (descending)
		    ret += " DESC";
		return ret;
	    }
	};

	/** ConstraintList - ordered list of Expressions.
	 */
	struct ConstraintList : public std::vector<const Expression*> {
	    ConstraintList () {  }
	    ConstraintList (const_iterator start,
			    const_iterator end)
		: std::vector<const Expression*>(start, end)
	    {  }
	    std::ostream& print(std::ostream& os, std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const;
	    std::string toString (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		print(ss, pad, driver, s);
		return ss.str();
	    }
	};

	class JunctionConstraint : public Expression {
	public:
	    ConstraintList constraints;
	public:
	    JunctionConstraint () : Expression(), constraints() {  }
	    JunctionConstraint (ConstraintList::const_iterator start,
				ConstraintList::const_iterator end)
		: constraints(start, end)
	    {  }
	    virtual ~JunctionConstraint () {
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++)
		    delete *it;
	    }
	    virtual Expression* clone() const = 0;
	    void addConstraint (Expression* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		if (getPrecedence() < parentPrec) ss << "(";
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    if (it != constraints.begin()) ss << getJunctionString();
		    ss << (*it)->toString(pad, getPrecedence(), driver, s);
		}
		if (getPrecedence() < parentPrec) ss << ")";
		return ss.str();
	    }

	    /** test the permutations of this (the right-hand argument to the
	     * comparison function) and l (the left-hand argument).
	     */
	    virtual bool baseMapsTo (const JunctionConstraint& r, AliasMapping::List& map) const {
		return constraints.size() == r.constraints.size()
		    && map.permute(std::set<const Expression*>(  constraints.begin(),   constraints.end()),
				   std::set<const Expression*>(r.constraints.begin(), r.constraints.end()))
		    ? true : logNotMappable(r);
	    }
	    virtual bool baseEq (const JunctionConstraint& r) const {
		if (constraints.size() != r.constraints.size())
		    return logNotEqual(r);
		dereferencer<const Expression> vld(  constraints);
		dereferencer<const Expression> vrd(r.constraints);
		OnezFine of;
		return permute::equals(vld, vrd, of)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string getJunctionString() const = 0;
	};
	class ConjunctionConstraint : public JunctionConstraint {
	public:
	    ConjunctionConstraint () : JunctionConstraint() {  }
	    ConjunctionConstraint (ConstraintList::const_iterator start,
				   ConstraintList::const_iterator end)
		: JunctionConstraint(start, end)
	    {  }
	    virtual Expression* clone () const {
		ConjunctionConstraint* ret = new ConjunctionConstraint();
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    ret->addConstraint((*it)->clone());
		}
		return ret;
	    }
	    virtual std::string getJunctionString () const { return " AND "; }
	    virtual e_PREC getPrecedence () const { return PREC_And; }
	    virtual bool finalMapsTo (const ConjunctionConstraint& l, AliasMapping::List& map) const {
		return l.JunctionConstraint::baseMapsTo(*this, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const ConjunctionConstraint& l) const {
		return l.JunctionConstraint::baseEq(*this);
	    }
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	};
	class DisjunctionConstraint : public JunctionConstraint {
	public:
	    DisjunctionConstraint () {  }
	    DisjunctionConstraint (ConstraintList::const_iterator start,
				   ConstraintList::const_iterator end)
		: JunctionConstraint(start, end)
	    {  }
	    virtual Expression* clone () const {
		DisjunctionConstraint* ret = new DisjunctionConstraint();
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    ret->addConstraint((*it)->clone());
		}
		return ret;
	    }
	    virtual std::string getJunctionString () const { return " OR "; }
	    virtual e_PREC getPrecedence () const { return PREC_Or; }
	    virtual bool finalMapsTo (const DisjunctionConstraint& l, AliasMapping::List& map) const {
		return l.JunctionConstraint::baseMapsTo(*this, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const DisjunctionConstraint& l) const {
		return l.JunctionConstraint::baseEq(*this);
	    }
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	};

	/** BooleanComparator - base for e.g. BooleanEQ, BooleanLT, etc.
	 */
	class BooleanComparator : public Expression {
	protected:
	    const Expression* left;
	    const Expression* right;
	public:
	    BooleanComparator (const Expression* right) : Expression(), right(right) {  }
	    BooleanComparator (const Expression* left, const Expression* right) : Expression(), left(left), right(right) {  }
	    ~BooleanComparator () { delete left; delete right; }
	    virtual Expression* clone() const = 0;
	    virtual void setLeftParm (const Expression* p_left) { left = p_left; }
	    virtual const char* getComparisonNotation() const = 0;
	    virtual std::string toString (std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		if (getPrecedence() < parentPrec) ss << "(";
		ss << left->toString(pad, getPrecedence(), driver, s);
		ss << getComparisonNotation();
		ss << right->toString(pad, getPrecedence(), driver, s);
		if (getPrecedence() < parentPrec) ss << ")";
		return ss.str();
	    }
	};
	class BooleanEQ : public BooleanComparator {
	public:
	    BooleanEQ (const Expression* right) : BooleanComparator(right) {  }
	    BooleanEQ (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanEQ(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_EQ; }
	    /** Test l.left.mapsTo(this->left) && l.right.mapsTo(right), or,
		l.left.mapsTo(this->right) && l.right.mapsTo(left)
	     */
	    virtual bool finalMapsTo (const BooleanEQ& l, AliasMapping::List& map) const {
		AliasMapping::List& newMap(map);
		bool ret = false;
		ret |= (l.left->mapsTo(*left, map)
			&& l.right->mapsTo(*right, map));
		ret |= (l.left->mapsTo(*right, newMap)
			&& l.right->mapsTo(*left, newMap));
		map += newMap;
		return ret;
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const BooleanEQ& l) const {
		return (*l.left == *left  && *l.right == *right) // unordered
		    || (*l.left == *right && *l.right == *left);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getComparisonNotation () const { return "="; };
	};
	class BooleanNE : public BooleanComparator {
	public:
	    BooleanNE (const Expression* right) : BooleanComparator(right) {  }
	    BooleanNE (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanNE(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_NE; }
	    /** Test l.left.mapsTo(this->left) && l.right.mapsTo(right), or,
		l.left.mapsTo(this->right) && l.right.mapsTo(left)
	     */
	    virtual bool finalMapsTo (const BooleanNE& l, AliasMapping::List& map) const {
		AliasMapping::List& newMap(map);
		bool ret = false;
		ret |= (l.left->mapsTo(*left, map)
			&& l.right->mapsTo(*right, map));
		ret |= (l.left->mapsTo(*right, newMap)
			&& l.right->mapsTo(*left, newMap));
		map += newMap;
		return ret;
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const BooleanNE& l) const {
		return (*l.left == *left  && *l.right == *right) // unordered
		    || (*l.left == *right && *l.right == *left);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getComparisonNotation () const { return "!="; };
	};
	class BooleanLT : public BooleanComparator {
	public:
	    BooleanLT (const Expression* right) : BooleanComparator(right) {  }
	    BooleanLT (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanLT(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_LT; }
	    virtual bool finalMapsTo (const BooleanLT& l, AliasMapping::List& map) const {
		return (l.left->mapsTo(*left, map)
			&& l.right->mapsTo(*right, map));
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const BooleanLT& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getComparisonNotation () const { return "<"; };
	};
	class BooleanGT : public BooleanComparator {
	public:
	    BooleanGT (const Expression* right) : BooleanComparator(right) {  }
	    BooleanGT (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanGT(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_GT; }
	    virtual bool finalMapsTo (const BooleanGT& l, AliasMapping::List& map) const {
		return (l.left->mapsTo(*left, map)
			&& l.right->mapsTo(*right, map));
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const BooleanGT& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getComparisonNotation () const { return ">"; };
	};
	class BooleanLE : public BooleanComparator {
	public:
	    BooleanLE (const Expression* right) : BooleanComparator(right) {  }
	    BooleanLE (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanLE(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_LT; }
	    virtual bool finalMapsTo (const BooleanLE& l, AliasMapping::List& map) const {
		return (l.left->mapsTo(*left, map)
			&& l.right->mapsTo(*right, map));
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const BooleanLE& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getComparisonNotation () const { return "<="; };
	};
	class BooleanGE : public BooleanComparator {
	public:
	    BooleanGE (const Expression* right) : BooleanComparator(right) {  }
	    BooleanGE (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanGE(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_GT; }
	    virtual bool finalMapsTo (const BooleanGE& l, AliasMapping::List& map) const {
		return (l.left->mapsTo(*left, map)
			&& l.right->mapsTo(*right, map));
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const BooleanGE& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getComparisonNotation () const { return ">="; };
	};
	class UnaryExpression : public Expression {
	protected:
	    const Expression* arg;
	public:
	    UnaryExpression (const Expression* arg) : Expression(), arg(arg) {  }
	    ~UnaryExpression () {
		delete arg;
	    }
	    virtual Expression* clone() const = 0;
	    bool baseMapsTo (const UnaryExpression& r, AliasMapping::List& map) const {
		return arg->mapsTo(*r.arg, map);
	    }
	    bool baseEq (const UnaryExpression& r) const {
		return *arg == *r.arg;
	    }
	    virtual const char* getPrefixOperator() const = 0;
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		if (getPrecedence() < parentPrec) ss << "(";
		ss << getPrefixOperator();
		ss << arg->toString(pad, parentPrec, driver, s);
		if (getPrecedence() < parentPrec) ss << ")";
		return ss.str();
	    }
	};
	class NaryExpression : public Expression {
	protected:
	    ConstraintList args;
	public:
	    NaryExpression (ConstraintList::const_iterator start,
			    ConstraintList::const_iterator end)
		: args(start, end)
	    {  }
	    NaryExpression (ConstraintList* args) : Expression(), args(*args) {  }
	    ~NaryExpression () {
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); ++it)
		    delete *it;
	    }
	    virtual Expression* clone() const = 0;
	    bool baseMapsTo (const NaryExpression& r, AliasMapping::List& map) const {
		if (args.size() != r.args.size())
		    return map.fail();
		ConstraintList::const_iterator lit =   args.begin();
		ConstraintList::const_iterator rit = r.args.begin();
		for (; lit != args.end(); ++lit, ++rit)
		    if (!(*lit)->mapsTo(**rit, map))
			return map.fail();
		return true;
	    }
	    bool baseEq (const NaryExpression& r) const {
		return ptrequal(args.begin(), args.end(), r.args.begin());
	    }
	    virtual const char* getInfixOperator() const = 0;
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		if (getPrecedence() < parentPrec) ss << "(";
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); ++it) {
		    if (it != args.begin())
			ss << getInfixOperator();
		    ss << (*it)->toString(pad, parentPrec, driver, s);
		}
		if (getPrecedence() < parentPrec) ss << ")";
		return ss.str();
	    }
	};
	class UnorderedExpression : public NaryExpression {
	public:
	    UnorderedExpression (ConstraintList::const_iterator begin,
				 ConstraintList::const_iterator end)
		: NaryExpression (begin, end)
	    {  }
	    UnorderedExpression (ConstraintList* args)
		: NaryExpression (args)
	    {  }
	    bool baseMapsTo (const UnorderedExpression& r, AliasMapping::List& map) const {
		return map.permute(std::set<const Expression*>(  args.begin(),   args.end()),
				   std::set<const Expression*>(r.args.begin(), r.args.end()));
	    }

	    bool baseEq (const UnorderedExpression& r) const {
		dereferencer<const Expression> vld(  args);
		dereferencer<const Expression> vrd(r.args);
		OnezFine of;
		return permute::equals(vld, vrd, of);
		// return permute::equals(args.begin(), args.end(), r.args.begin());
	    }
	};
	class BooleanNegation : public UnaryExpression {
	public:
	    BooleanNegation (const Expression* arg) : UnaryExpression(arg) {  }
	    virtual Expression* clone () const {
		return new BooleanNegation(arg->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const BooleanNegation& l, AliasMapping::List& map) const {
		return l.UnaryExpression::baseMapsTo(*this, map);
	    }	    
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const BooleanNegation& l) const {
		return l.UnaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getPrefixOperator () const { return "!"; }
	};
	class ArithmeticProduct : public UnorderedExpression {
	public:
	    ArithmeticProduct (ConstraintList::const_iterator start,
			       ConstraintList::const_iterator end)
		: UnorderedExpression(start, end)
	    {  }
	    virtual Expression* clone () const {
		ConstraintList v;
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); it++) {
		    v.push_back((*it)->clone());
		}
		return new ArithmeticProduct(v.begin(), v.end());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const ArithmeticProduct& l, AliasMapping::List& map) const {
		return l.UnorderedExpression::baseMapsTo(*this, map);
	    }	    
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const ArithmeticProduct& l) const {
		return l.UnorderedExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getInfixOperator () const { return " * "; }
	};
	class ArithmeticInverse : public UnaryExpression {
	public:
	    ArithmeticInverse (const Expression* arg) : UnaryExpression(arg) {  }
	    virtual Expression* clone () const {
		return new ArithmeticInverse(arg->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const ArithmeticInverse& l, AliasMapping::List& map) const {
		return l.UnaryExpression::baseMapsTo(*this, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const ArithmeticInverse& l) const {
		return l.UnaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getPrefixOperator () const { return "1/"; }
	};
	class ArithmeticSum : public UnorderedExpression {
	public:
	    ArithmeticSum (ConstraintList::const_iterator start,
			   ConstraintList::const_iterator end)
		: UnorderedExpression(start, end)
	    {  }
	    virtual Expression* clone () const {
		ConstraintList v;
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); it++) {
		    v.push_back((*it)->clone());
		}
		return new ArithmeticSum(v.begin(), v.end());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const ArithmeticSum& l, AliasMapping::List& map) const {
		return l.UnorderedExpression::baseMapsTo(*this, map);
	    }	    
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const ArithmeticSum& l) const {
		return l.UnorderedExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getInfixOperator () const { return " + "; }
	};
	class ArithmeticNegation : public UnaryExpression {
	public:
	    ArithmeticNegation (const Expression* arg) : UnaryExpression(arg) {  }
	    virtual Expression* clone () const {
		return new ArithmeticNegation(arg->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const ArithmeticNegation& l, AliasMapping::List& map) const {
		return l.UnaryExpression::baseMapsTo(*this, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const ArithmeticNegation& l) const {
		return l.UnaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getPrefixOperator () const { return "-"; }
	};
	class LiteralConstraint : public Expression {
	    std::string value;
	public:
	    LiteralConstraint (std::string value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new LiteralConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const LiteralConstraint& l, AliasMapping::List& map) const {
		return finalEq(l) ? true : map.fail();
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const LiteralConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High , std::string /* driver */ = "" , Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		ss << s.literal(value);
		return ss.str();
	    }
	};
	class IntConstraint : public Expression {
	    int value;
	public:
	    IntConstraint (int value) : Expression(), value(value) {  }
	    virtual ~IntConstraint () {  }
	    virtual Expression* clone () const {
		return new IntConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const IntConstraint& l, AliasMapping::List& map) const {
		return finalEq(l) ? true : map.fail();
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const IntConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const {
		std::stringstream ss;
		ss << value;
		return ss.str();
	    }
	    int getValue () const { return value; }
	};
	class FloatConstraint : public Expression {
	    float value;
	public:
	    FloatConstraint (float value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new FloatConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const FloatConstraint& l, AliasMapping::List& map) const {
		return finalEq(l) ? true : map.fail();
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const FloatConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const {
		std::stringstream ss;
		ss << value;
		return ss.str();
	    }
	};
	class DoubleConstraint : public Expression {
	    double value;
	public:
	    DoubleConstraint (double value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new DoubleConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const DoubleConstraint& l, AliasMapping::List& map) const {
		return finalEq(l) ? true : map.fail();
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const DoubleConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const {
		std::stringstream ss;
		ss << value;
		return ss.str();
	    }
	};
	class HexConstraint : public Expression {
	    std::vector<unsigned char> bytes;
	public:
	    HexConstraint (const std::vector<unsigned char>& bytes) : Expression(), bytes(bytes) {  }
	    virtual Expression* clone () const {
		return new HexConstraint(bytes);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const HexConstraint& l, AliasMapping::List& map) const {
		return finalEq(l) ? true : map.fail();
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const HexConstraint& l) const {
		return l.bytes == bytes;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		return s.hexString(bytes);
	    }
	};
	class BoolConstraint : public Expression {
	    bool value;
	public:
	    BoolConstraint (bool value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new BoolConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const BoolConstraint& l, AliasMapping::List& map) const {
		return finalEq(l) ? true : map.fail();
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const BoolConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		return s.booleanValue(value);
	    }
	};
	class IsNullConstraint : public Expression {
	public:
	    IsNullConstraint () : Expression() {  }
	    virtual Expression* clone () const {
		return new IsNullConstraint();
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const IsNullConstraint& /* l */, AliasMapping::List& /* map */) const {
		return true;
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const IsNullConstraint&) const {
		return true;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const {
		return "NULL";
	    }
	};
	class NotNullConstraint : public Expression {
	    const Expression* tterm;
	public:
	    NotNullConstraint (const Expression* tterm) : Expression(), tterm(tterm) {  }
	    ~NotNullConstraint () { delete tterm; }
	    virtual Expression* clone () const {
		return new NotNullConstraint(tterm->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const NotNullConstraint& /* l */, AliasMapping::List& /* map */) const {
		return true;
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const NotNullConstraint&) const {
		return true;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const {
		std::stringstream ss;
		ss << tterm->toString();
		ss << " IS NOT NULL";
		return ss.str();
	    }
	};
	class NegationConstraint : public Expression {
	    Expression* negated;
	public:
	    NegationConstraint (Expression* negated) : Expression(), negated(negated) {  }
	    ~NegationConstraint () { delete negated; }
	    virtual Expression* clone () const {
		return new NegationConstraint(negated->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_Neg; }
	    virtual bool finalMapsTo (const NegationConstraint& l, AliasMapping::List& map) const {
		return l.negated->mapsTo(*negated, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }	    
	    virtual bool finalEq (const NegationConstraint& l) const {
		return *l.negated == *negated;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		ss << "!(" << negated->toString(pad, parentPrec, driver, s) << ")";
		return ss.str();
	    }
	};

	/** AliasAttrConstraint - use of an AliasAttr as an Expression.
	 */
	class AliasAttrConstraint : public Expression {
	protected:
	    AliasAttr aattr;
	public:
	    AliasAttrConstraint (AliasAttr aattr) : Expression(), aattr(aattr) {  }
	    AliasAttr getAliasAttr () const { return aattr; }
	    virtual Expression* clone () const {
		return new AliasAttrConstraint(aattr);
	    }
	    virtual bool finalMapsTo (const AliasAttrConstraint& l, AliasMapping::List& map) const {
		return l.aattr.mapsTo(aattr, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const AliasAttrConstraint& l) const {
		return l.aattr == aattr;
	    }
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */, e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const {
		std::stringstream ss;
		ss << aattr.alias;
		ss << ".";
		ss << aattr.attr;
		return ss.str();
	    }
	    virtual e_PREC getPrecedence () const { return PREC_TTerm; }
	};

	/** HomologConstraint - Nary functions which have the same parameter
	 * semantics in XPath and SQL.
	 */
	class HomologConstraint : public NaryExpression {
	    std::string sqlOp;
	public:
	    HomologConstraint (std::string sqlOp,
			       ConstraintList::const_iterator start,
			       ConstraintList::const_iterator end)
		: NaryExpression(start, end), sqlOp(sqlOp)
	    {  }
	    virtual Expression* clone () const {
		ConstraintList v;
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); it++) {
		    v.push_back((*it)->clone());
		}
		return new HomologConstraint(sqlOp, v.begin(), v.end());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const HomologConstraint& l, AliasMapping::List& map) const {
		return l.NaryExpression::baseMapsTo(*this, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const HomologConstraint& l) const {
		return l.NaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual const char* getInfixOperator () const { return ", "; }
	    virtual std::string toString (std::string /* pad */ = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		return sqlOp + "("
		    + NaryExpression::toString("", parentPrec, driver, s) + ")";
	    }
	};

	class RegexConstraint : public Expression {
	    const Expression* text;
	    const Expression* pattern;
	public:
	    RegexConstraint (const Expression* text, const Expression* pattern) : Expression(), text(text), pattern(pattern) {  }
	    virtual Expression* clone () const {
		return new RegexConstraint(text->clone(), pattern->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const RegexConstraint& l, AliasMapping::List& map) const {
		return l.text->mapsTo(*text, map) && l.pattern->mapsTo(*pattern, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const RegexConstraint& l) const {
		return l.text == text && l.pattern == pattern; // @@ does this compare by ref? by val?
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "", Serializer& s = SQLSerializer::It) const {
		return std::string() + "REGEX(" + text->toString(pad, parentPrec, driver, s) + ", " + pattern->toString() + ")";
	    }
	};

	class CastConstraint : public Expression {
	    const Expression* exp;
	    DataType type;
	    int precision;
	public:
	    CastConstraint (const Expression* exp, DataType type, int precision) : Expression(), exp(exp), type(type), precision(precision) {  }
	    virtual Expression* clone () const {
		return new CastConstraint(exp->clone(), type, precision);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalMapsTo (const CastConstraint& l, AliasMapping::List& map) const {
		return l.type == type && l.precision == precision && l.exp->mapsTo(*exp, map);
	    }
	    virtual bool mapsTo (const Expression& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const CastConstraint& l) const {
		return l.type == type && l.precision == precision && l.exp == exp; // @@ does this compare by ref? by val?
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual std::string toString (std::string /* pad */ = "", e_PREC /* parentPrec */ = PREC_High, std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		return std::string()
		    + "CAST(" + exp->toString()
		    + " AS " + s.typeString(type, precision)
		    + ")";
	    }
	};

	class TableJoin;
	class SubqueryJoin;
	class Join {
	    RelVar alias;
	    bool optional;
	    ConstraintList constraints;
	public:
	    Join (RelVar alias, bool optional) : alias(alias), optional(optional) {  }
	    virtual ~Join () {
		for (ConstraintList::iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    delete *it;
	    }
	    std::string debug_getAlias () { return alias; }
	    virtual std::string getRelationText (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const = 0;

	    // dupes from Expression
	    bool logNotMappable (const Join& r) const {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << toString() << "\ndoesn't map to" << r.toString();
		return false;
	    }
	    bool logNotEqual (const Join& r) const {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << toString() << " != " << r.toString();
		return false;
	    }

	    virtual bool baseMapsTo(const Join& r, AliasMapping::List& map) const {
		if (!map.matches(alias, r.alias))
		    return false;
		if (optional != r.optional) {
		    logNotMappable(r);
		    return map.fail();
		}
		return map.permute(std::set<const Expression*>(  constraints.begin(),   constraints.end()),
				   std::set<const Expression*>(r.constraints.begin(), r.constraints.end()));
	    }
	    virtual bool finalMapsTo (const TableJoin&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool finalMapsTo (const SubqueryJoin&, AliasMapping::List& map) const { return map.fail(); }
	    virtual bool mapsTo(const Join&, AliasMapping::List&) const = 0;
	    bool baseEq (const Join& r) const {
		return alias == r.alias
		    && optional == r.optional
		    && ptrequal(constraints.begin(), constraints.end(), r.constraints.begin());
	    }
	    virtual bool finalEq (const TableJoin&) const { return false; }
	    virtual bool finalEq (const SubqueryJoin&) const { return false; }
	    virtual bool operator==(const Join& ref) const = 0;
	    std::string str () const { return toString(); } // for debugger invocation
	    std::string toString (ConstraintList* captureConstraints = NULL, std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		if (captureConstraints == NULL) ss << std::endl << pad << "            " << (optional ? "LEFT OUTER JOIN " : "INNER JOIN ");
		if (driver.find("oracle") == 0)
		    ss << getRelationText(pad, driver, s) << " " << alias;
		else
		    ss << getRelationText(pad, driver, s) << " " << s.as() << alias;

		if (captureConstraints != NULL)
		    std::copy(constraints.begin(), constraints.end(), std::back_inserter(*captureConstraints));

		else 
		    for (ConstraintList::const_iterator it = constraints.begin();
			 it != constraints.end(); ++it)
			ss << (it == constraints.begin() ? " ON " : " AND ")
			   << (*it)->toString(pad, PREC_High, driver, s);

		return ss.str();
	    }
	    void addForeignKeyJoinConstraint (Attribute myAttr, RelVar otherAlias, Attribute otherAttr) {
		if (alias != otherAlias || myAttr != otherAttr)
		    constraints.push_back(new BooleanEQ(new AliasAttrConstraint(AliasAttr(alias, myAttr)), 
							new AliasAttrConstraint(AliasAttr(otherAlias, otherAttr))));
	    }
	    void addConstantJoinConstraint (Attribute myAttr, int value) {
		constraints.push_back(new BooleanEQ(new AliasAttrConstraint(AliasAttr(alias, myAttr)), 
						    new IntConstraint(value)));
	    }
	    void addConstantJoinConstraint (Attribute myAttr, std::string value) {
		constraints.push_back(new BooleanEQ(new AliasAttrConstraint(AliasAttr(alias, myAttr)), 
						    new LiteralConstraint(value)));
	    }
	};

	class TableJoin : public Join {
	    RelationName relation;
	protected:
	    virtual std::string getRelationText (std::string /* pad */, std::string /* driver */ = "", Serializer& /* s */ = SQLSerializer::It) const { return relation; }
	public:
	    TableJoin (RelationName relation, RelVar alias, bool optional) : Join(alias, optional), relation(relation) {  }
	    virtual bool finalMapsTo (const TableJoin& l, AliasMapping::List& map) const {
		return l.relation == relation ? true : map.fail();
	    }	    
	    virtual bool mapsTo (const Join& r, AliasMapping::List& map) const {
		return Join::baseMapsTo(r, map) && r.finalMapsTo(*this, map)
		    ? true : logNotMappable(r);
	    }
	    virtual bool finalEq (const TableJoin& l) const {
		return l.relation == relation
		    ? true : l.logNotEqual(*this);
	    }	    
	    virtual bool operator== (const Join& r) const {
		return Join::baseEq(r) && r.finalEq(*this)
		    ? true : logNotEqual(r);
	    }
	    virtual ~TableJoin () {  }
	};

	class AliasedSelect {
	    friend struct EquivSet;
	protected:
	    const Expression* exp;
	    AttrAlias alias;
	public:
	    AliasedSelect (const Expression* exp, AttrAlias alias) : exp(exp), alias(alias) {  }
	    virtual ~AliasedSelect () {
		delete exp;
	    }
	    const Expression* getExpression () const { return exp; }
	    const AttrAlias& getAlias () const { return alias; }
	    virtual bool mapsTo (const AliasedSelect& r, AliasMapping::List& map) const {
		if (exp->mapsTo(*r.exp, map)
		    && (alias == r.alias))
		    return true;
		// dupe from Expression and Join
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << toString() << " doesn't map to " << r.toString();
		return map.fail();
	    }
	    virtual bool operator== (const AliasedSelect& r) const { // virt in case of subclassing
		if (*exp == *r.exp && alias == r.alias)
		    return true;
		// dupe from Expression and Join
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << toString() << " != " << r.toString();
		return false;
	    }
	    std::string str () const { return toString(); } // for debugger invocation
	    virtual std::string toString (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		if (driver.find("oracle") == 0)
		    return exp->toString(pad, PREC_High, driver, s) + " " + alias;
		else
		    return exp->toString(pad, PREC_High, driver, s) + " " + s.as() + alias;
	    }
	};

	class SQLUnion;
	class SQLOptional;
	class SQLQuery { // !!! public SQLQueryBase
	public:

	    struct JoinList : public std::vector<Join*> {
		JoinList () {  }
		JoinList (std::vector<Join*>& joins) : std::vector<Join*>(joins) {  }
		std::ostream& print (std::ostream& os,
				     ConstraintList* captureConstraints = NULL,
				     std::string pad = "", std::string driver = "",
				     Serializer& s = SQLSerializer::It) const;
	    };
	    JoinList joins;

	    ConstraintList  constraints;

	    struct OrderBy : public std::vector<OrderedExpression> {
		~OrderBy () {
		    for (std::vector<OrderedExpression>::iterator iOrderBy = begin();
			 iOrderBy != end(); ++iOrderBy)
			delete iOrderBy->expression;
		}
		std::string toString (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		    std::stringstream ss;
		    print(ss, pad, driver, s);
		    return ss.str();
		}
		std::ostream& print(std::ostream& os, std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const;
	    };
	    OrderBy orderBy;
	    struct Selects : public std::vector<AliasedSelect*> {
		typedef std::vector<AliasedSelect*>::const_iterator const_iterator;
		std::ostream& print(std::ostream& os, std::string pad = "",
				    std::string driver = "", Serializer& s = SQLSerializer::It) const;
		std::ostream& print(const std::vector<DataType>& fieldTypes, std::ostream& os,
				    std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const;
	    };

	    struct MappedEquivalence {
		const SQLQuery& q;
		MappedEquivalence (const SQLQuery& q) : q(q) {  }
		bool operator== (const SQLQuery& r) const {
		    AliasMapping::List m;
		    return q.mapsTo(r, m);
		}
	    };

	    Selects selects;
	    bool distinct;
	    int limit, offset;

	public:
	    SQLQuery () : distinct(false), limit(-1), offset(-1) {  }
	    SQLQuery (std::vector<Join*>* joins) : joins(*joins), distinct(false), limit(-1), offset(-1) {  }
	    virtual ~SQLQuery () {
		// w3c_sw_LINEN << "~TableJoin: " << this
		// 	     << ": " << iterStr<Join*>(joins.begin(), joins.end())
		// 	     << "\n";

		for (std::vector<AliasedSelect*>::iterator iSelects = selects.begin();
		     iSelects != selects.end(); ++iSelects)
		    delete *iSelects;

		for (std::vector<Join*>::iterator iJoins = joins.begin();
		     iJoins != joins.end(); ++iJoins) {
		    delete *iJoins;
		}

		for (ConstraintList::iterator iConstraints = constraints.begin();
		     iConstraints != constraints.end(); ++iConstraints)
		    delete *iConstraints;

		// ~orderBy takes cleans up ->expression
	    }

	    bool finalMapsTo(const SQLQuery& r, AliasMapping::List& map) const;
	    virtual bool finalMapsTo (const SQLUnion& /* r */, AliasMapping::List& /* map */) const { return false; }
	    virtual bool finalMapsTo (const SQLOptional& /* r */, AliasMapping::List& /* map */) const { return false; }
	    virtual bool mapsTo (const SQLQuery& r, AliasMapping::List& map) const {
		return r.finalMapsTo(*this, map);
	    }
	    bool finalEq(const SQLQuery& r) const;
	    virtual bool finalEq (const SQLUnion&) const { return false; }
	    virtual bool finalEq (const SQLOptional&) const { return false; }
	    // virtual bool operator==(const Join& r) const = 0; //!!! for SQLQueryBase
	    virtual bool operator== (const SQLQuery& r) const {
		return r.finalEq(*this);
	    }

	    std::string str () const { // easy to call from debugger.
		return toString();
	    }
	    virtual std::string toString (std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::vector<DataType> fieldTypes;
		return _toString(fieldTypes, false, pad, driver, s);
	    }
	    virtual std::string toString (const std::vector<DataType>& fieldTypes, std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		return _toString(fieldTypes, true, pad, driver, s);
	    }
	    virtual std::string _toString (const std::vector<DataType>& fieldTypes, bool typed, std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		if (driver.find("mssql") == 0 && (offset != -1 || limit != -1)) {
		    ss << pad << ";WITH __RowCounter AS (\n";
		    pad += "    ";
		}
		ss << pad << "SELECT ";
		if (distinct) ss << "DISTINCT ";

		if (typed)
		    selects.print(fieldTypes, ss, pad, driver, s);
		else
		    selects.print(ss, pad, driver, s);

		bool disableOrder = false;
		if (driver.find("mssql") == 0 && (offset != -1 || limit != -1)) {
		    ss << ", ROW_NUMBER() OVER (";
		    if (orderBy.size() > 0) {
			orderBy.print(ss, pad, driver, s);
			disableOrder = true;
		    } else {
			ss << "ORDER BY ";
			for (Selects::const_iterator it = selects.begin(); it != selects.end(); ++it) {
			    if (it != selects.begin())
				ss << ", ";
			    ss << (*it)->getExpression()->toString();
			}
		    }
		    ss << ")-1 AS __RowNumber";
		}
		/* JOINs */
		ConstraintList where;
		joins.print(ss, &where, pad, driver, s);

		/* WHERE */
		std::copy(constraints.begin(), constraints.end(), std::back_inserter(where));
		where.print(ss, pad, driver, s);

		if (!disableOrder)
		    orderBy.print(ss, pad, driver, s);

		if (driver.find("mssql") == 0 && (offset != -1 || limit != -1)) {
		    pad.resize(pad.size()-4);
		    ss << ")\n" << pad << "SELECT ";
		    for (Selects::const_iterator it = selects.begin(); it != selects.end(); ++it) {
			if (it != selects.begin())
			    ss << ", ";
			ss << (*it)->getAlias();
		    }
		    ss << " FROM __RowCounter WHERE ";
		    if (offset != -1)
			ss << "__RowNumber >= " << offset;
		    if (offset != -1 && limit != -1)
			ss << " AND ";
		    if (limit != -1) {
			ss << " __RowNumber < ";
			if (offset != -1)
			    ss << offset << " + ";
			ss << limit;
		    }
		} else if (driver.find("oracle") == 0) {
		    if (offset != -1) ss << std::endl << pad << "rownum > " << offset;
		    if (limit != -1) ss << std::endl << pad << " rownum <= " << limit;
		} else if (driver.find("mssql2012") == 0) {
		    if (offset != -1) ss << std::endl << pad << " OFFSET " << offset << " ROW";
		    if (limit != -1) ss << std::endl << pad << " FETCH NEXT " << limit << " ROWS ONLY";
		} else {
		    if (offset != -1) ss << std::endl << pad << " " << s.offset(offset);
		    if (limit != -1) ss << std::endl << pad << " " << s.limit(limit);
		}

		return ss.str();
	    }

	    void add (Join* join) { joins.push_back(join); }
	};

	inline std::ostream& SQLQuery::Selects::print (std::ostream& os, std::string pad, std::string driver, Serializer& s) const {
	    /* SELECT attributes */
	    for (const_iterator it = begin(); it != end(); ++it) {
		if (it != begin()) os << ", ";
		os << (*it)->toString(pad, driver, s);
	    }
	    if (begin() == end()) os << "NULL";
	    return os;
	}
	inline std::ostream& SQLQuery::Selects::print (const std::vector<DataType>& fieldTypes, std::ostream& os, std::string pad, std::string driver, Serializer& s) const {
	    /* SELECT attributes */
	    std::vector<DataType>::const_iterator field = fieldTypes.begin();
	    for (const_iterator it = begin(); it != end(); ++it) {
		if (field == fieldTypes.end())
		    throw std::runtime_error(std::string()
					     + "no field for "
					     + (*it)->toString(pad, driver, s));
		if (it != begin()) os << ", ";
		os << s.typedValue(*field, (*it)->toString(pad, driver, s));
	    }
	    if (begin() == end()) os << "NULL";
	    return os;
	}
	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::Selects& selects) {
	    return selects.print(os);
	}

	inline std::ostream& SQLQuery::JoinList::print (std::ostream& os, ConstraintList* captureConstraints, std::string pad, std::string driver, Serializer& s) const {
	    for (const_iterator it = begin(); it != end(); ++it)
		if (it == begin())
		    os << std::endl << pad << "       FROM " << (*it)->toString(captureConstraints, pad, driver, s);
		else
		    os << (*it)->toString(NULL, pad, driver, s);
	    return os;
	}
	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::JoinList& joinList) {
	    return joinList.print(os);
	}

	inline std::ostream& ConstraintList::print (std::ostream& os, std::string pad, std::string driver, Serializer& s) const {
	    for (const_iterator it = begin(); it != end(); ++it)
		os << (it == begin() ? " WHERE " : " AND ")
		   <<(*it)->toString(pad, PREC_High, driver, s);
	    return os;
	}
	inline std::ostream& operator<< (std::ostream& os, const ConstraintList& constraints) {
	    return constraints.print(os);
	}

	inline std::ostream& SQLQuery::OrderBy::print (std::ostream& os, std::string pad, std::string driver, Serializer& s) const {
	    /* ORDER BY */
	    if (begin() != end()) {
		os << std::endl << pad << " ORDER BY ";
		for (const_iterator it = begin(); it != end(); ++it) {
		    if (it != begin())
			os << ", ";
		    os << it->toString(pad, PREC_High, driver, s);
		}
	    }
	    return os;
	}
	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::OrderBy& orderBy) {
	    return orderBy.print(os);
	}

	inline bool SQLQuery::finalMapsTo (const SQLQuery& r, AliasMapping::List& map) const {
	    // w3c_sw_LINEN << "map: " << map.str() << "\n";
	    const char* f = "SQL Query non-isomorphism in ";
	    if (!(distinct == r.distinct)) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "distinct: " << distinct << "!=" << r.distinct << "\n";
		map.fail();
		return false;
	    }
	    if (!(limit == r.limit)) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "limit: " << limit << "!=" << r.limit << "\n";
		map.fail();
		return false;
	    }
	    if (!(offset == r.offset)) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "offset: " << offset << "!=" << r.offset << "\n";
		map.fail();
		return false;
	    }
	    // if (!ptrequal(selects.begin(), selects.end(), r.selects.begin())) {
	    if (!map.permute(std::set<const AliasedSelect*>(  selects.begin(),   selects.end()),
			     std::set<const AliasedSelect*>(r.selects.begin(), r.selects.end()))) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "selects:\n" << selects << "\n does not map to \n" << r.selects << "\n";
		return false;
	    }
	    if (!map.orderedMap(joins.begin(), joins.end(), r.joins.begin())) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "joins:\n" << joins << "\n does not map to \n" << r.joins << "\n";
		return false;
	    }
	    if (!map.permute(std::set<const Expression*>(  constraints.begin(),   constraints.end()),
			     std::set<const Expression*>(r.constraints.begin(), r.constraints.end()))) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "constraints:\n" << constraints << "\n does not map to \n" << r.constraints << "\n";
		return false;
	    }
	    {
		std::vector<sql::OrderedExpression>::const_iterator lit = orderBy.begin();
		std::vector<sql::OrderedExpression>::const_iterator end = orderBy.end();
		std::vector<sql::OrderedExpression>::const_iterator rit = r.orderBy.begin();
		for (; lit != end; ++lit, ++rit)
		    if (!((*lit).mapsTo(*rit, map))) {
			BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
			    << f << "orderBy:\n" << orderBy << "\n does not map to \n" << r.orderBy << "\n";
			return false;
		    }
	    }
	    return true;
	}
	inline bool SQLQuery::finalEq (const SQLQuery& r) const { // not needed in SQLQueryBase
	    const char* f = "SQL Query inequivalence in ";
	    if (!(distinct == r.distinct)) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "distinct: " << distinct << "!=" << r.distinct << "\n";
		return false;
	    }
	    if (!(limit == r.limit)) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "limit: " << limit << "!=" << r.limit << "\n";
		return false;
	    }
	    if (!(offset == r.offset)) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
		    << f << "offset: " << offset << "!=" << r.offset << "\n";
		return false;
	    }
	    // if (!ptrequal(selects.begin(), selects.end(), r.selects.begin())) {
	    // if (!EquivSet(selects).sameValues(selects, r.selects)) {
	    {
		dereferencer<AliasedSelect> vld(selects);
		dereferencer<AliasedSelect> vrd(r.selects);
		OnezFine of;
		if (!permute::equals(vld, vrd, of)) {
		    BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
			<< f << "selects:\n" << selects << "\n != \n" << r.selects << "\n";
		    return false;
		}
	    }
	    // if (!ptrequal(joins.begin(), joins.end(), r.joins.begin())) {
	    {
		dereferencer<Join> vld(joins);
		dereferencer<Join> vrd(r.joins);
		OnezFine of;
		if (!permute::equals(vld, vrd, of)) {
		    BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
			<< f << "joins:\n" << joins << "\n != \n" << r.joins << "\n";
		    return false;
		}
	    }
	    // if (!ptrequal(constraints.begin(), constraints.end(), r.constraints.begin())) {
	    {
		dereferencer<const Expression> vld(constraints);
		dereferencer<const Expression> vrd(r.constraints);
		OnezFine of;
		if (!permute::equals(vld, vrd, of)) {
		    BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
			<< f << "constraints:\n" << constraints << "\n != \n" << r.constraints << "\n";
		    return false;
		}
	    }
	    // if (!ptrequal(orderBy.begin(), orderBy.end(), r.orderBy.begin())) {
	    {
		OnezFine of;
		if (!permute::equals(orderBy, r.orderBy, of)) {
		    BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::engineer)
			<< f << "orderBy:\n" << orderBy << "\n != \n" << r.orderBy << "\n";
		    return false;
		}
	    }
	    return true;
	}

	inline std::ostream& operator<< (std::ostream& os, SQLQuery const& my) {
	    return os << my.str();
	}

	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::MappedEquivalence& m) {
	    return os << m.q;
	}

	class SQLDisjoint;
	class SQLUnion : public SQLQuery {
	public:
	    std::vector<SQLQuery*> disjoints;
	public:
	    SQLUnion () {  }
	    SQLUnion (std::vector<sql::SQLQuery*>::const_iterator start,
		      std::vector<sql::SQLQuery*>::const_iterator end) : disjoints(start, end)
	    {  }
	    virtual ~SQLUnion () {
		for (std::vector<SQLQuery*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it)
		    delete *it;
	    }
	    virtual bool finalMapsTo (const SQLUnion& l, AliasMapping::List& map) const {
		return map.orderedMap(l.disjoints.begin(), l.disjoints.end(), disjoints.begin());
	    }	    
	    virtual bool mapsTo (const SQLQuery& r, AliasMapping::List& map) const {
		return SQLQuery::mapsTo(r, map) && r.finalMapsTo(*this, map);
	    }
	    virtual bool finalEq (const SQLUnion& l) const {
		return ptrequal(l.disjoints.begin(), l.disjoints.end(), disjoints.begin());
	    }	    
	    virtual bool operator== (const SQLQuery& r) const {
		return r.finalEq(*this); // !!! no Join::baseEq(r) && 
	    }
	    virtual std::string toString (std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		std::string newPad = pad + "    ";
		for (std::vector<SQLQuery*>::const_iterator it = disjoints.begin();
		     it != disjoints.end(); ++it) {
		    if (it != disjoints.begin())
			ss << std::endl << pad << "  UNION" << std::endl;
		    ss << (*it)->toString(newPad, driver, s);
		}
		return ss.str();
	    }
	    virtual std::string toString (std::vector<DataType>& fieldTypes, std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		std::string newPad = pad + "    ";
		std::vector<DataType>::const_iterator field = fieldTypes.begin();
		for (std::vector<SQLQuery*>::const_iterator it = disjoints.begin();
		     it != disjoints.end(); ++it) {
		    if (field == fieldTypes.end())
			throw std::runtime_error(std::string()
						 + "no field for "
						 + (*it)->toString(newPad, driver, s));
		    if (it != disjoints.begin())
			ss << std::endl << pad << "  UNION" << std::endl;
		    ss << s.typedValue(*field, (*it)->toString(newPad, driver, s));
		}
		return ss.str();
	    }

	};

	class SubqueryJoin : public Join {
	    SQLQuery* subquery;
	protected:
	    virtual std::string getRelationText (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		ss << "(" << std::endl << subquery->toString(pad, driver, s) << std::endl << pad << "             )";
		return ss.str();
	    }
	public:
	    SubqueryJoin (SQLQuery* subquery, RelVar alias, bool optional) : Join(alias, optional), subquery(subquery) {  }
	    virtual bool finalMapsTo (const SubqueryJoin& l, AliasMapping::List& map) const {
		return l.subquery->mapsTo(*subquery, map) ? true : map.fail();
	    }	    
	    virtual bool mapsTo (const Join& r, AliasMapping::List& map) const {
		return Join::baseMapsTo(r, map) && r.finalMapsTo(*this, map);
	    }
	    virtual bool finalEq (const SubqueryJoin& l) const {
		return *l.subquery == *subquery;
	    }	    
	    virtual bool operator== (const Join& r) const {
		return Join::baseEq(r) && r.finalEq(*this);
	    }
	    virtual ~SubqueryJoin () { delete subquery; }
	};

	class SQLOptional : public SQLQuery {
	public:
	    SQLOptional () {  }
	    virtual ~SQLOptional () {  }
	    virtual bool finalEq (const SQLUnion& /* l */) const { // !!! contains a what?
		return true;
	    }	    
	    virtual bool operator== (const SQLQuery& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::string newPad = pad + "    ";
		return SQLQuery::toString(newPad, driver, s);
	    }
	    virtual std::string toString (std::vector<DataType>& fieldTypes, std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::string newPad = pad + "    ";
		return SQLQuery::toString(fieldTypes, newPad, driver, s);
	    }
	};


	/**
	 * SQL Schema (derived from DDL)
	 */
	namespace schema {

	    struct FieldOrKey {
		int i;
		FieldOrKey () : i(7) {  }
		virtual ~FieldOrKey () {  }
		virtual bool operator==(const FieldOrKey& r) const = 0;
		virtual std::string toString(std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const = 0;
	    };

//	    I don't know what the prob was, but calling this got oddly circular:
// 	    inline std::ostream& operator<< (std::ostream& ostr, FieldOrKey const& ref) {
// 		std::cerr << ref << ".i = " << ref.i << "\n";
// 		return ostr << ref.str();
// 	    }

	    class Key : public FieldOrKey {
		std::vector<Attribute>* attrs;

	    public:
		Key (std::vector<Attribute>* attrs) : attrs(attrs)
		{  }
		virtual ~Key () { delete attrs; }
		bool operator== (const Key& ref) const {
		    std::vector<Attribute>::const_iterator left = attrs->begin();
		    std::vector<Attribute>::const_iterator right = ref.attrs->begin();
		    for (;
			 left != attrs->end(); ++left, ++right)
			if (*left != *right)
			    return false;
		    return true;
		}
		bool Key_equals (const FieldOrKey& ref) const {
		    const Key* refp = dynamic_cast<const Key*>(&ref);
		    if (refp == NULL
			|| attrs->size() != refp->attrs->size())
			return false;
		    std::vector<Attribute>::const_iterator left = attrs->begin();
		    std::vector<Attribute>::const_iterator right = refp->attrs->begin();
		    for (;
			 left != attrs->end(); ++left, ++right)
			if (*left != *right)
			    return false;
		    return true;
		}
		std::vector<Attribute>::iterator begin () { return attrs->begin(); }
		std::vector<Attribute>::iterator end () { return attrs->end(); }
		std::vector<Attribute>::const_iterator begin () const { return attrs->begin(); }
		std::vector<Attribute>::const_iterator end () const { return attrs->end(); }
		size_t size () const { return attrs->size(); }
		const Attribute& at (size_t i) const { return attrs->at(i); }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const Key* refp = dynamic_cast<const Key*>(&ref);
		    return (refp != NULL && Key_equals(ref));
		}
		virtual std::string toString (std::string /* pad */ = "", std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		    std::stringstream ss;
		    ss << "UNIQUE (";
		    for (std::vector<Attribute>::const_iterator it = begin();
			 it != end(); ++it) {
			if (it != begin())
			    ss << ", ";
			ss << s.name(*it);
		    }
		    ss << ")";
		    return ss.str();
		}
	    };

	    struct PrimaryKey : public Key {
		PrimaryKey (std::vector<Attribute>* attrs) : Key(attrs)
		{  }
		virtual ~PrimaryKey () {  }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const PrimaryKey* refp = dynamic_cast<const PrimaryKey*>(&ref);
		    return (refp != NULL && Key_equals(ref));
		}
		virtual std::string toString (std::string /* pad */ = "", std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		    std::stringstream ss;
		    ss << "PRIMARY KEY (";
		    for (std::vector<Attribute>::const_iterator it = begin();
			 it != end(); ++it) {
			if (it != begin())
			    ss << ", ";
			ss << s.name(*it);
		    }
		    ss << ")";
		    return ss.str();
		}
	    };

	    struct ForeignKey : public Key {
		RelationName targetRel;
		Key* relAttrs;
		ForeignKey (std::vector<Attribute>* myAttrs,
			    RelationName targetRel,
			    Key* relAttrs)
		    : Key(myAttrs), targetRel(targetRel), relAttrs(relAttrs)
		{  }
		virtual ~ForeignKey () { delete relAttrs; }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const ForeignKey* refp = dynamic_cast<const ForeignKey*>(&ref);
		    if (refp == NULL
			|| targetRel != refp->targetRel
			|| !Key_equals(ref))
			return false;
		    std::vector<Attribute>::const_iterator left = relAttrs->begin();
		    std::vector<Attribute>::const_iterator right = refp->relAttrs->begin();
		    for (;
			 left != relAttrs->end(); ++left, ++right)
			if (*left != *right)
			    return false;
		    return true;
		}
		virtual std::string toString (std::string /* pad */ = "", std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		    std::stringstream ss;
		    ss << "FOREIGN KEY (";
		    for (std::vector<Attribute>::const_iterator it = begin();
			 it != end(); ++it) {
			if (it != begin())
			    ss << ", ";
			ss << s.name(*it);
		    }
		    ss << ") REFERENCES " << s.name(targetRel) << "(";
		    for (std::vector<Attribute>::const_iterator it = relAttrs->begin();
			 it != relAttrs->end(); ++it) {
			if (it != relAttrs->begin())
			    ss << ", ";
			ss << s.name(*it);
		    }
		    ss << ")";
		    return ss.str();
		}
	    };

	    struct Field : public FieldOrKey {
		struct Participation {
		    size_t position;
		    Participation (size_t position) : position(position) {  }
		};

		struct KeyParticipation : public Participation {
		    const Key* key;
		    KeyParticipation (Key* key, size_t position)
			: Participation(position), key(key)
		    {  }
		};

		struct PKParticipation : public Participation {
		    const PrimaryKey* key;
		    PKParticipation (PrimaryKey* key, size_t position)
			: Participation(position), key(key)
		    {  }
		};

		struct FKParticipation : public Participation {
		    const ForeignKey* key;
		    FKParticipation (ForeignKey* key, size_t position)
			: Participation(position), key(key)
		    {  }
		};

		struct Keys : public std::map<const Key*, KeyParticipation> {
		    void addUniqueKey(Key* uniqueKey, size_t posn) {
			iterator fk = find(uniqueKey);
			if (fk != end())
			    throw std::string() + "Unique key already assigned.";
			insert(std::make_pair(uniqueKey, KeyParticipation(uniqueKey, posn)));
		    }
		};

		struct FKs : public std::map<const ForeignKey*, FKParticipation> {
		    void addForeignKey(ForeignKey* foreignKey, size_t posn) {
			iterator fk = find(foreignKey);
			if (fk != end())
			    throw std::string() + "Foreign key already assigned.";
			insert(std::make_pair(foreignKey, FKParticipation(foreignKey, posn)));
		    }
		};

		Attribute name;
		DataType type;
		int precision;
	    protected: // manage this stuff via the method calls.
		boost::optional<PKParticipation> pk;
		Keys keys;
		FKs fks;

	    public:

		Field (Attribute name, DataType type, int precision)
		    : name(name), type(type), precision(precision)
		{  }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const Field* refp = dynamic_cast<const Field*>(&ref);
		    if (refp == NULL)
			return false;
		    return name == refp->name
			&& type == refp->type;
		}

		void setPkPosition (PrimaryKey* primaryKey, size_t posn) {
		    pk = PKParticipation(primaryKey, posn);
		}

		void addUniqueKey (Key* uniqueKey, size_t posn) {
		    keys.addUniqueKey(uniqueKey, posn);
		}

		void addForeignKey (ForeignKey* foreignKey, size_t posn) {
		    fks.addForeignKey(foreignKey, posn);
		}

		virtual std::string toString (std::string /* pad */ = "", std::string /* driver */ = "", Serializer& s = SQLSerializer::It) const {
		    return s.name(name) + " " + s.typeString(type, precision);
		}
	    };

// #ifndef w3c_sw_sql_schema_PRECISION_unspecified
// 	    const int Field::PRECISION_unspecified = -1;
//   #define w3c_sw_sql_schema_PRECISION_unspecified
// #endif /* w3c_sw_sql_schema_PRECISION_unspecified */


	    struct Relation {

		RelationName name;
		std::vector<const FieldOrKey*> orderedFields;
		const PrimaryKey* primaryKey;
		std::set<const Key*> keys;
		struct Fields : public std::map<Attribute, Field> {
		    void addPrimaryKey(Attribute attr, PrimaryKey* primaryKey, size_t posn) {
			iterator f = find(attr);
			f->second.setPkPosition(primaryKey, posn);
		    }
		    void addUniqueKey(Attribute attr, Key* uniqueKey, size_t posn) {
			iterator f = find(attr);
			f->second.addUniqueKey(uniqueKey, posn);
		    }
		    void addForeignKey(Attribute attr, ForeignKey* foreignKey, size_t posn) {
			iterator f = find(attr);
			f->second.addForeignKey(foreignKey, posn);
		    }
		};
		Fields fields;

		Relation (RelationName name) : name(name), primaryKey(NULL)
		{  }

		~Relation () {
		    for (std::vector<const FieldOrKey*>::iterator it = begin();
			 it != end(); ++it)
			delete *it;
		    orderedFields.clear();
		    fields.clear();
		    // The primaryKey was already deleted with orderedFields.
		}

		bool operator== (const Relation& ref) const {
		    if (name != ref.name
			|| size() != ref.size()
			|| fields.size() != ref.fields.size())
			return false;
		    std::vector<const FieldOrKey*>::const_iterator left = begin();
		    std::vector<const FieldOrKey*>::const_iterator right = ref.begin();
		    for (;
			 left != end(); ++left, ++right)
			if (!(**left == **right))
			    return false;
		    return true;
		}

		std::vector<const FieldOrKey*>::iterator begin () {
		    return orderedFields.begin();
		}
		std::vector<const FieldOrKey*>::const_iterator begin () const {
		    return orderedFields.begin();
		}
		std::vector<const FieldOrKey*>::iterator end () {
		    return orderedFields.end();
		}
		std::vector<const FieldOrKey*>::const_iterator end () const {
		    return orderedFields.end();
		}
		size_t size () const {
		    return orderedFields.size();
		}

		std::string toString (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		    std::stringstream ss;
		    ss << "CREATE TABLE " << s.name(name) << " (\n";
		    for (std::vector<const FieldOrKey*>::const_iterator it = begin();
			 it != end(); ++it) {
			if (it != begin())
			    ss << ",\n";
			ss << "  " << (*it)->toString(pad, driver, s);
		    }
		    ss << "\n)";
		    return ss.str();
		}

		void addField (const Field* field) {
		    orderedFields.push_back(field);
		    fields.insert(std::make_pair(field->name, *field)); // @@ reference instead of copy?
		}

		void setPrimaryKey (PrimaryKey* primaryKey) {
		    orderedFields.push_back(primaryKey);
		    this->primaryKey = primaryKey;
		    size_t posn = 0;
		    for (std::vector<Attribute>::const_iterator attr = primaryKey->begin();
			 attr != primaryKey->end(); ++attr, ++posn)
			fields.addPrimaryKey(*attr, primaryKey, posn);
		}

		void addUniqueKey (Key* uniqueKey) {
		    orderedFields.push_back(uniqueKey);
		    keys.insert(uniqueKey);
		    size_t posn = 0;
		    for (std::vector<Attribute>::const_iterator attr = uniqueKey->begin();
			 attr != uniqueKey->end(); ++attr, ++posn)
			fields.addUniqueKey(*attr, uniqueKey, posn);
		}

		void addForeignKey (ForeignKey* foreignKey) {
		    orderedFields.push_back(foreignKey);
		    size_t posn = 0;
		    for (std::vector<Attribute>::const_iterator attr = foreignKey->begin();
			 attr != foreignKey->end(); ++attr, ++posn)
			fields.addForeignKey(*attr, foreignKey, posn);
		}

	    };

	    inline std::ostream& operator<< (std::ostream& ostr, Relation const& ref) {
		return ostr << ref.toString();
	    }

	    struct Database : public std::map<RelationName, Relation*> {

		void clear () {
		    for (iterator it = begin(); it != end(); ++it)
			delete it->second;
		    std::map<RelationName, Relation*>::clear();
		}

		bool operator== (const Database& ref) const {
		    if (size() != ref.size())
			return false;
		    const_iterator left = begin();
		    const_iterator right = ref.begin();
		    for (; left != end(); ++left, ++right)
			if (left->first != right->first
			    || !(*left->second == *right->second))
			    return false;
		    return true;
		}

		std::string toString (std::string pad = "", std::string driver = "", Serializer& s = SQLSerializer::It) const {
		    std::stringstream ss;
		    for (const_iterator it = begin();
			 it != end(); ++it)
			ss << it->second->toString(pad, driver, s) << ";\n";
		    return ss.str();
		}
	    };

	    inline std::ostream& operator<< (std::ostream& ostr, Database const& ref) {
		return ostr << ref.toString();
	    }

	} // namespace schema

	struct RValue {
	    virtual std::string toString(std::string pad = "",
					 std::string driver = "", Serializer& s = SQLSerializer::It) const = 0;
	    virtual std::string toString(const std::vector<DataType>& fieldTypes, std::string pad = "",
					 std::string driver = "", Serializer& s = SQLSerializer::It) const = 0;
	};
	struct RSelection : public RValue {
	    SQLQuery* select;
	    RSelection (SQLQuery* select) : select(select) {  }
	    virtual std::string toString (std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		return select->toString(pad, driver, s);
	    }
	    virtual std::string toString (const std::vector<DataType>& fieldTypes, std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		return select->toString(fieldTypes, pad, driver, s);
	    }
	};
	struct RConstants : public RValue {
	    std::vector<const sql::Expression*>* constants;
	    RConstants (std::vector<const sql::Expression*>* constants) : constants(constants) {  }
	    virtual std::string toString (std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		for (std::vector<const sql::Expression*>::const_iterator it = constants->begin();
		     it != constants->end(); ++it) {
		    if (it != constants->begin())
			ss << ", ";
		    ss << (*it)->toString(pad, PREC_High, driver, s);
		}
		return ss.str();
	    }
	    virtual std::string toString (const std::vector<DataType>& fieldTypes, std::string pad = "",
					  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		std::vector<DataType>::const_iterator field = fieldTypes.begin();
		for (std::vector<const sql::Expression*>::const_iterator it = constants->begin();
		     it != constants->end(); ++it) {
		    if (field == fieldTypes.end())
			throw std::runtime_error(std::string()
						 + "no field for "
						 + (*it)->toString(pad, PREC_High, driver, s));
		    if (it != constants->begin())
			ss << ", ";
		    ss << s.typedValue(*field, (*it)->toString(pad, PREC_High, driver, s));
		    ++field;
		}
		return ss.str();
	    }
	};
	struct Insert {
	    sql::RelationName relName;
	    std::vector<Attribute>* attributes;
	    RValue* rvalue;
	    Insert (RelationName relName, std::vector<sql::Attribute>* attributes, RValue* rvalue)
		: relName(relName), attributes(attributes), rvalue(rvalue)
	    {  }

	    std::string toString (std::string pad = "",
				  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::stringstream ss;
		ss << "INSERT INTO " << s.name(relName) << " (";
		for (std::vector<Attribute>::const_iterator it = attributes->begin();
		     it != attributes->end(); ++it) {
		    if (it != attributes->begin())
			ss << ", ";
		    ss << s.name(*it);
		}
		ss << ") VALUES (" << rvalue->toString(pad, driver, s) << ")";
		return ss.str();
	    }
	    std::string toString (const schema::Database& db, std::string pad = "",
				  std::string driver = "", Serializer& s = SQLSerializer::It) const {
		std::vector<DataType> fieldTypes;
		std::stringstream ss;
		ss << "INSERT INTO " << s.name(relName) << " (";
		for (std::vector<Attribute>::const_iterator it = attributes->begin();
		     it != attributes->end(); ++it) {
		    if (it != attributes->begin())
			ss << ", ";
		    ss << s.name(*it);
		    fieldTypes.push_back(db.find(relName)->second->fields.find(*it)->second.type);
		}
		ss << ") VALUES (" << rvalue->toString(fieldTypes, pad, driver, s) << ")";
		return ss.str();
	    }
	};

	inline std::ostream& operator<< (std::ostream& ostr, Insert const& ref) {
	    return ostr << ref.toString();
	}

    } // namespace sql
} // namespace w3c_sw

#endif /* !INCLUDE_SQL_HPP */
