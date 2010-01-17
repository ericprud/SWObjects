/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef SWOBJECTS_HH
# define SWOBJECTS_HH

/* Handy debugging from Curtis Krauskopf
 * http://www.decompile.com/cpp/faq/file_and_line_error_string.htm

 * debugging tips:
 *   echo filename(lineno):
 *     LINE;
 *     LINE << "about to foo the bar." << std::endl; // outputs your text.
 */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define LINE std::cerr << __FILE__ "(" TOSTRING(__LINE__) "): warning LINE\n"

/* defines for controlling includes from utils */
#include "config.h"

/* non-portable debug messages */
#ifdef _MSC_VER
#define FUNCTION_STRING __FUNCSIG__ // __FUNCDNAME__ || __FUNCTION__ -- http://msdn.microsoft.com/en-us/library/b0084kay(VS.80).aspx

#else /* !_MSC_VER */
#ifdef __GNUC__
#define FUNCTION_STRING __PRETTY_FUNCTION__

#else /* !__GNUC__ */
#define FUNCTION_STRING "define a function name macro"

#endif /* !__GNUC__ */
#endif /* !_MSC_VER */

#include <ctype.h>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <exception>

#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <typeinfo>

#if REGEX_LIB == SWOb_BOOST
  #include <boost/regex.hpp>
#endif /* REGEX_LIB == SWOb_BOOST */

#include <boost/optional.hpp>
#include <boost/none.hpp>

namespace w3c_sw {

    extern const char* NS_xml;
    extern const char* NS_xsd;
    extern const char* NS_rdf;
    extern const char* NS_rdfs;
    extern const char* NS_srx;
    extern const char* NS_dc;
    extern const char* NS_sadl;

class StringException : public std::exception {
public:
    char const* str;
    static std::map<StringException*, std::string> strs;

    StringException (std::string m) : str(m.c_str()) {
	strs[this] = m;
    }
    // !!! needs copy constructor in MS compilations, but
    //     haven't got UnknownPrefixException working in g++
#ifdef WIN32
    StringException (StringException& orig) {
	strs[this] = strs[&orig];
	str = strs[this].c_str();
    }
#endif
    virtual ~StringException () throw() { strs.erase(this); }
    char const* what() const throw() { 	return str; }
};

class SafeEvaluationError : public std::exception {
public:
    std::string msg;
    SafeEvaluationError (std::string msg) : msg(msg) {  }
    virtual ~SafeEvaluationError () throw() {   }
    char const* what() const throw() { 	return msg.c_str(); }
};

class NotImplemented : public SafeEvaluationError {
public:
    NotImplemented (std::string msg) : SafeEvaluationError(msg + " not implemented") {  }
    virtual ~NotImplemented () throw() {   }
    char const* what() const throw() { 	return msg.c_str(); }
};

class TypeError : public SafeEvaluationError {
public:
    TypeError (std::string type, std::string context) : SafeEvaluationError(type + " not expected in " + context) {  }
    virtual ~TypeError () throw() {   }
    char const* what() const throw() { 	return msg.c_str(); }
};

#if (defined(_MSC_VER) && _MSC_VER < 1500)
class OptString {
    bool m_initialized;
    std::string m_str;
    std::string m_emptyString;

public:
    OptString (std::string p_emptyString = "")
	: m_initialized(false), m_emptyString(p_emptyString) {  }
    OptString (const char* p_str, std::string p_emptyString = "")
	: m_initialized(false), m_emptyString(p_emptyString) {
	assign(p_str);
    }
    void operator= (const char* p_str) {
	assign(p_str);
    }
    void assign (const char* p_str) {
	if (p_str == NULL) {
	    m_initialized = false;
	    m_str = "uninitialized OptString";
	} else {
	    m_initialized = true;
	    m_str = p_str;
	}
    }
    std::string toString () {
	return m_initialized ? m_str : m_emptyString;
    }
    const char* c_str () {
	return m_initialized ? m_str.c_str() : NULL;
    }
    bool match (const char* match) {
	return (m_initialized && !strncmp(c_str(), match, strlen(match)));
    }
    std::string get() const { BOOST_ASSERT(m_initialized) ; return m_str; }
    std::string operator *() const { return this->get() ; }
    typedef bool (OptString::*unspecified_bool_type)() const;
    bool is_initialized() const { return m_initialized ; }
    operator unspecified_bool_type() const {
	return m_initialized ? &OptString::is_initialized : 0 ;
    }
};
#else /* !(defined(_MSC_VER) && _MSC_VER < 1500) */
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
#endif /* !(defined(_MSC_VER) && _MSC_VER < 1500) */

class MediaType : public OptString {
public:
    MediaType ()
	: OptString(std::string("-no media type-")) {  }
    MediaType (const char* p_str)
	: OptString(p_str, std::string("-no media type-")) {  }
    void operator= (const char* p_str) {
	assign(p_str);
    }
};

struct MediaTypeMap : public std::map<const std::string, const char*> {
    typedef std::map<const std::string, const char*>::const_iterator const_iterator;
    typedef std::pair<const std::string, const char*> pair;
    MediaTypeMap () {
	insert(pair("html", "text/html"));
	insert(pair("rdf" , "text/rdf+xml"));
	insert(pair("xml" , "text/rdf+xml"));
	insert(pair("ttl" , "text/turtle"));
	insert(pair("trig", "text/trig"));
	insert(pair("srx" , "application/sparql-results+xml"));
	insert(pair("srt" , "text/sparql-results"));
	insert(pair("rq"  , "text/sparql-query"));
    }
};

class Expressor;
class RecursiveExpressor;

class Base {
public:
    Base () { }
    virtual ~Base() { }
    virtual void express(Expressor* p_expressor) const;
};

template <typename T> class ProductionVector : public Base {
protected:
    std::vector<T> data;
public:
    ProductionVector () {  }
    ProductionVector (T v) { push_back(v); }
    virtual ~ProductionVector () {
	for (typename std::vector<T>::iterator it = ProductionVector<T>::begin(); 
	     it != ProductionVector<T>::end(); ++it)
	    delete *it;
    }

    void push_back(T v) {
	assert(v != NULL); // @DEBUG
	data.push_back(v);
    }
    size_t size () const { return data.size(); }
    virtual T operator [] (size_t i) const { return data[i]; }
    virtual T at (size_t i) const { return data.at(i); }
    virtual T back () const { return data.back(); }
    void clear () { data.clear(); }
    void pop_back () { data.pop_back(); }
    virtual void express(Expressor* p_expressor) const {
	for (size_t i = 0; i < data.size(); i++)
	    data[i]->express(p_expressor);
    }
    typename std::vector<T>::iterator begin () { return data.begin(); }
    typename std::vector<T>::const_iterator begin () const { return data.begin(); }
    typename std::vector<T>::iterator end () { return data.end(); }
    typename std::vector<T>::const_iterator end () const { return data.end(); }
    typename std::vector<T>::iterator erase (typename std::vector<T>::iterator it) { return data.erase(it); }
    void sort (bool (*comp)(T, T)) {
	std::list<T> l;
	for (typename std::vector<T>::iterator it = begin(); it != end(); ++it)
	    l.push_back(*it);
	l.sort(comp);
	data.clear();
	for (typename std::list<T>::iterator it = l.begin(); it != l.end(); ++it)
	    data.push_back(*it);
    }
    bool operator== (const ProductionVector<T>& ref) const {
	if (size() != ref.size())
	    return false;

	/* Compare unordered; sort of a cheat. */
	std::set<T> mine(begin(), end());
	for (typename std::vector<T>::const_iterator it = ref.begin();
	     it != ref.end(); ++it)
	    if (!mine.erase(*it))
		return false;
	if (mine.size() > 0)
	    return false;
	return true;
    }
#if 0
    class iterator;
    iterator begin() { return iterator(data.begin(), this); }
    iterator end() { return iterator(data.end(), this); }
#endif
};
template <typename T> std::ostream& operator<<(std::ostream& os, ProductionVector<T> const& my) {
    os << "{\n";
    for (typename std::vector<T>::const_iterator it = my.begin(); it != my.end(); ++it)
	os << **it;
    return os << "}\n";
}

template <typename T> class NoDelProductionVector : public ProductionVector<T> {
public:
    NoDelProductionVector () {  }
    NoDelProductionVector (T v) : ProductionVector<T>(v) {  }
    virtual ~NoDelProductionVector () { ProductionVector<T>::clear(); }
    void operator= (const ProductionVector<T>& ref) {
	for (typename std::vector<T>::iterator it = ref.begin(); it != ref.end(); ++it) {
	    push_back(*it);
	}
    }
};
#if 0
template <class T> class ProductionVector<T>::iterator:
public std::iterator<std::forward_iterator_tag, void, void, void, void> {
private:
    ProductionVector<T> * whence;
protected:
    typename vector<T>::iterator i;
public:
    iterator () {}
    iterator (typename vector<T>::iterator i_, ProductionVector<T> * w): i(i_), whence(w) {  }
    bool operator==(const iterator & z) { return i == z.i; }
    bool operator!=(const iterator & z) { return i != z.i; }
    void operator++() { ++i; }
    T operator*() { return *i; }
};
#endif

class Terminal : public Base {
protected:
    std::string terminal;
    Terminal (std::string p) : Base(), terminal(p) {  }
    Terminal (std::string p, bool gensym) : Base() {
	std::stringstream name;
	name << p;
	if (gensym)
	    name << this;
	terminal = name.str();
    }
    ~Terminal () {  }
public:
    std::string getLexicalValue () const { return terminal; }
};

} // namespace w3c_sw

namespace w3c_sw {

class ResultSet;
class Result;
class RdfDB;

    class LANGTAG : public Terminal { // @@@ should become an RDFLiteral.
public:
    LANGTAG(std::string p_LANGTAG) : Terminal(p_LANGTAG) {  }
};

class Operation : public Base {
protected:
    Operation () : Base() {  }
public:
    virtual void express(Expressor* p_expressor) const = 0;
    virtual ResultSet* execute(RdfDB*, ResultSet* = NULL) const { throw(std::runtime_error(typeid(*this).name())); }
    virtual bool operator==(const Operation& ref) const = 0;
    std::string toString() const;
};

class BNode;
class BNodeEvaluator;
class POSFactory;

/* START Parts Of Speach */
class POS : public Terminal {
    friend struct POSsorter;
protected:
    POS (std::string matched) : Terminal(matched) {  }
    POS (std::string matched, bool gensym) : Terminal(matched, gensym) { }
    //    virtual int compareType (POS* to) = 0;
public:
    virtual bool isConstant () const { return true; } // Override for variable types.
    static bool orderByType (const POS*, const POS*) { throw(std::runtime_error(FUNCTION_STRING)); }
    virtual int compare (POS* to, Result*) const {
	bool same = typeid(*to) == typeid(*this);
	return same ? getLexicalValue() != to->getLexicalValue() : orderByType(this, to);
    }
    virtual const POS* evalPOS (const Result*, BNodeEvaluator* /* evaluator */) const { return this; }
    bool bindVariable (const POS* p, ResultSet* rs, Result* provisional, bool weaklyBound) const;
    virtual void express(Expressor* p_expressor) const = 0;
    virtual std::string getBindingAttributeName() const = 0;
    struct BNode2string : public std::map<const BNode*, std::string> {
	std::string get(const BNode* bnode);
    };
    struct String2BNode : public std::map<std::string, const BNode*> {
	const BNode* get(std::string bnode);
    };
    virtual std::string toXMLResults(BNode2string*) const = 0;
    virtual std::string toString() const = 0;
    std::string substitutedString (Result* row, BNodeEvaluator* evaluator) const {
	const POS* subd = evalPOS(row, evaluator); /* re-uses atoms -- doesn't create them */
	if (subd != NULL)
	    return subd->toString();
	std::stringstream s;
	s << '[' << toString() << ']';
	return s.str();
    }
};

class URI : public POS {
    friend class POSFactory;
private:
    URI (std::string str) : POS(str) {  }
public:
    ~URI () { }
    virtual const char * getToken () { return "-POS-"; }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string toXMLResults (BNode2string*) const { return std::string("<uri>") + terminal + "</uri>";  }
    virtual std::string toString () const { return std::string("<") + terminal + ">"; }
    virtual std::string getBindingAttributeName () const { return "uri"; }
    bool matches (std::string toMatch) const { return terminal == toMatch; } // !!! added for SPARQLSerializer::functionCall
};

class Bindable : public POS {
protected:
    Bindable (std::string str) : POS(str) {  }
    Bindable (std::string str, bool gensym) : POS(str, gensym) {  }
public:
    virtual bool isConstant () const { return false; }
};

class Variable : public Bindable {
    friend class POSFactory;
private:
    Variable (std::string str) : Bindable(str) {  }
public:
    virtual std::string toXMLResults (POS::BNode2string*) const {
	return std::string("<variable>") + terminal + "</variable> <!-- should not appear in XML Results -->";
    }
    virtual std::string toString () const { std::stringstream s; s << "?" << terminal; return s.str(); }
    virtual const char * getToken () { return "-Variable-"; }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* evalPOS(const Result* r, BNodeEvaluator* evaluator) const;
    virtual std::string getBindingAttributeName () const { return "name"; }
};

class BNode;
class BNodeEvaluator {
    friend class BNode;
protected:
    virtual ~BNodeEvaluator () {  }
    virtual const POS* evaluate(const BNode* node, const Result* r) = 0;
};
class BNode : public Bindable {
    friend class POSFactory;
private:
    BNode (std::string str) : Bindable(str) {  }
    BNode () : Bindable("b", true) {  }
public:
    virtual std::string toXMLResults (POS::BNode2string* map) const {
	return std::string("<bnode>") + map->get(this) + "</bnode>";
    }
    virtual std::string toString () const { std::stringstream s; s << "_:" << terminal; return s.str(); }
    virtual const char * getToken () { return "-BNode-"; }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* evalPOS(const Result* r, BNodeEvaluator* evaluator) const;
    virtual std::string getBindingAttributeName () const { return "bnode"; }
};
inline std::string POS::BNode2string::get (const BNode* bnode) {
    BNode2string::const_iterator it = find(bnode);
    if (it == end()) {
	std::stringstream s;
	s << size();
	it = insert(std::pair<const BNode*, std::string>(bnode, std::string("r") + s.str())).first;
    }
    return it->second;
}

class RDFLiteral : public POS {
    friend class POSFactory;
private:
    const URI* datatype;
    LANGTAG* m_LANGTAG;

protected:
    RDFLiteral (std::string p_String, const URI* p_URI, LANGTAG* p_LANGTAG) : POS(p_String) {
	datatype = p_URI;
	m_LANGTAG = p_LANGTAG;
    }

    ~RDFLiteral () {
	delete m_LANGTAG;
    }
public:
    const URI* getDatatype () const { return datatype; }
    const LANGTAG* getLangtag () const { return m_LANGTAG; }
    virtual std::string toXMLResults (POS::BNode2string*) const {
	std::stringstream s;
	s << "<literal";
	if (datatype) 
	    s << " datatype=\"" << datatype->getLexicalValue() << "\"";
	if (m_LANGTAG) 
	    s << " xml:lang=\"" << m_LANGTAG->getLexicalValue() << "\"";
	s << ">";
	for (std::string::const_iterator ch = terminal.begin(); ch != terminal.end(); ++ch)
	    switch (*ch) {
	    case '<':
		s << "&lt;";
		break;
	    case '>':
		s << "&gt;";
		break;
	    default:
		s << *ch;
	    }
	s << "</literal>";
	return s.str();
    }
    virtual std::string toString () const {
	std::stringstream s;
	/* Could just print terminal here. */
	s << '"' << terminal << '"';
	if (datatype) s << "^^" << datatype->toString();
	if (m_LANGTAG) s << "@" << m_LANGTAG->getLexicalValue();
	return s.str();
    }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string getBindingAttributeName () const { return "literal"; }
};
class CanonicalRDFLiteral : public RDFLiteral {
    friend class POSFactory;
protected:
    CanonicalRDFLiteral (std::string p_String, const URI* p_URI) : RDFLiteral(p_String, p_URI, NULL) {  }
    ~CanonicalRDFLiteral () {  }
public:
    typedef enum {CANON_brief, CANON_roundTrip, CANON_icalize} e_CANON;
    static e_CANON format;
    std::string nonCanonicalString () const {
	if (CanonicalRDFLiteral::format == CANON_brief)
	    return getLexicalValue();
	return RDFLiteral::toString();
    }
};
class NumericRDFLiteral : public CanonicalRDFLiteral {
    friend class POSFactory;
protected:
    NumericRDFLiteral (std::string p_String, const URI* p_URI) : CanonicalRDFLiteral(p_String, p_URI) {  }
    ~NumericRDFLiteral () {  }
public:
    virtual int getInt() const = 0;
    virtual float getFloat() const = 0;
    virtual double getDouble() const = 0;
    virtual void express(Expressor* p_expressor) const = 0;
};
class IntegerRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    int m_value;
    IntegerRDFLiteral (std::string p_String, const URI* p_URI, int p_value) : NumericRDFLiteral(p_String, p_URI), m_value(p_value) {  }
    ~IntegerRDFLiteral () {  }
public:
    int getValue () const { return m_value; }
    virtual int getInt () const { return m_value; }
    virtual float getFloat () const { return (float)m_value; }
    virtual double getDouble () const  { return (double)m_value; }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string toString () const {
	if (CanonicalRDFLiteral::format == CANON_icalize) {
	    std::stringstream canonical;
	    canonical << m_value;
	    return canonical.str();
	}
	return CanonicalRDFLiteral::nonCanonicalString();
    }
};
class FloatRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    float m_value;
    FloatRDFLiteral (std::string p_String, const URI* p_URI, float p_value) : NumericRDFLiteral(p_String, p_URI), m_value(p_value) {  }
    ~FloatRDFLiteral () {  }
public:
    float getValue () const { return m_value; }
    virtual int getInt () const { throw TypeError(std::string("(float)") + toString(), "getInt()"); }
    virtual float getFloat () const { return m_value; }
    virtual double getDouble () const { return (double)m_value; }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string toString () const {
	if (CanonicalRDFLiteral::format == CANON_icalize) {
	    std::stringstream canonical;
	    canonical << std::fixed << m_value;
	    return canonical.str();
	}
	return CanonicalRDFLiteral::nonCanonicalString();
    }
};
class DecimalRDFLiteral : public FloatRDFLiteral {
    friend class POSFactory;
protected:
    DecimalRDFLiteral (std::string p_String, const URI* p_URI, float p_value) : FloatRDFLiteral(p_String, p_URI, p_value) {  }
public:
    virtual int getInt () const { throw TypeError(std::string("(decimal)") + toString(), "getInt()"); }
    virtual void express(Expressor* p_expressor) const;
};
class DoubleRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    double m_value;
    DoubleRDFLiteral (std::string p_String, const URI* p_URI, double p_value) : NumericRDFLiteral(p_String, p_URI), m_value(p_value) {  }
    ~DoubleRDFLiteral () {  }
public:
    double getValue () const { return m_value; }
    virtual int getInt () const { throw TypeError(std::string("(double)") + toString(), "getInt()"); }
    virtual float getFloat () const { throw TypeError(std::string("(double)") + toString(), "getFloat"); }
    virtual double getDouble () const { return m_value; }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string toString () const {
	if (CanonicalRDFLiteral::format == CANON_icalize) {
	    std::stringstream canonical;
	    canonical << std::scientific << m_value;
	    return canonical.str();
	}
	return CanonicalRDFLiteral::nonCanonicalString();
    }
};
class BooleanRDFLiteral : public CanonicalRDFLiteral {
    friend class POSFactory;
protected:
    bool m_value;
    BooleanRDFLiteral (std::string p_String, const URI* p_URI, bool p_value) : CanonicalRDFLiteral(p_String, p_URI), m_value(p_value) {  }
public:
    bool getValue () const { return m_value; }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string toString () const {
	if (CanonicalRDFLiteral::format == CANON_icalize) {
	    std::stringstream canonical;
	    canonical << std::boolalpha << m_value;
	    return canonical.str();
	}
	return CanonicalRDFLiteral::nonCanonicalString();
    }
};
class NULLpos : public POS {
    friend class POSFactory;
private:
    NULLpos () : POS("NULL", "") {  }
    ~NULLpos () {  }
public:
    virtual const char * getToken () { return "-NULL-"; }
    virtual std::string toXMLResults (POS::BNode2string*) const { return std::string("<null/> <!-- should not appear in XML Results -->"); }
    virtual std::string toString () const { std::stringstream s; s << "NULL"; return s.str(); }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string getBindingAttributeName () const { throw(std::runtime_error(FUNCTION_STRING)); }
};

class BasicGraphPattern;
class NamespaceMap;

class TriplePattern : public Base {
    friend class POSFactory;
private:
    const POS* m_s; const POS* m_p; const POS* m_o;
    bool weaklyBound;
    TriplePattern (const POS* p_s, const POS* p_p, const POS* p_o) : Base(), m_s(p_s), m_p(p_p), m_o(p_o), weaklyBound(false) {  }
    TriplePattern (TriplePattern const& copy, bool weaklyBound) : Base(), m_s(copy.m_s), m_p(copy.m_p), m_o(copy.m_o), weaklyBound(weaklyBound) {  }
public:
    ~TriplePattern () {  }
    const POS* getS () const { return m_s; }
    const POS* getP () const { return m_p; }
    const POS* getO () const { return m_o; }
    static bool lt (TriplePattern* l, TriplePattern* r) {
	if (l->m_s != r->m_s) return l->m_s < r->m_s;
	if (l->m_p != r->m_p) return l->m_p < r->m_p;
	if (l->m_o != r->m_o) return l->m_o < r->m_o;
	return 0;
    }    
    static bool gt (TriplePattern* l, TriplePattern* r) {
	if (l->m_s != r->m_s) return l->m_s > r->m_s;
	if (l->m_p != r->m_p) return l->m_p > r->m_p;
	if (l->m_o != r->m_o) return l->m_o > r->m_o;
	return 0;
    }    
    std::string toString(MediaType mediaType = MediaType(), NamespaceMap* namespaces = NULL) const;
    std::string toString (Result* row) const {
	std::stringstream s;
	s << 
	    "{" << m_s->substitutedString(row, false) << 
	    " " << m_p->substitutedString(row, false) << 
	    " " << m_o->substitutedString(row, false) << "}";
	return s.str();
    }
    virtual void express(Expressor* p_expressor) const;
    bool bindVariables (const TriplePattern* tp, bool, ResultSet* rs, const POS* graphVar, Result* provisional, const POS* graphName) const {
	return
	    (graphVar == NULL || graphVar->bindVariable(graphName, rs, provisional, weaklyBound)) &&
	    m_p->bindVariable(tp->m_p, rs, provisional, weaklyBound) && 
	    m_s->bindVariable(tp->m_s, rs, provisional, weaklyBound) && 
	    m_o->bindVariable(tp->m_o, rs, provisional, weaklyBound);
    }
    bool construct(BasicGraphPattern* target, const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const;
};

class DefaultGraphPattern;
class Expression;
class POSFactory {
public:
//     typedef std::map<const BNode*, std::string> BNode2string;
//     typedef std::map<std::string, const BNode*> String2BNode;
protected:
    typedef std::set<const BNode*> BNodeSet;
    typedef std::map<std::string, const Variable*> VariableMap;
    typedef std::map<std::string, const URI*> URIMap;
    typedef std::map<std::string, const RDFLiteral*> RDFLiteralMap;
    typedef std::map<std::string, const TriplePattern*> TriplePatternMap; // I don't know what the key should be. string for now...
    class MakeNumericRDFLiteral {
    public:
	virtual ~MakeNumericRDFLiteral () {  }
	virtual const NumericRDFLiteral* makeIt(std::string p_String, const URI* p_URI) = 0;
    };

protected:
    VariableMap		variables;
    BNodeSet		bnodes;
    URIMap		uris;
    RDFLiteralMap	rdfLiterals;
    TriplePatternMap	triples;
    NULLpos		nullPOS;
    const BooleanRDFLiteral* litFalse;
    const BooleanRDFLiteral* litTrue;
    const NumericRDFLiteral* getNumericRDFLiteral(std::string p_String, const char* type, MakeNumericRDFLiteral* maker);
public:
    typedef enum { DT_Err, DT_BNode, DT_URI, DT_Literal, 
		  DT_Integer, DT_Decimal, DT_Float, DT_Double, 
		  DT_Boolean} DT_Numeric;
protected:
    typedef std::map<const std::string, DT_Numeric> TypeOrder;
    TypeOrder typeOrder;

#if REGEX_LIB == SWOb_BOOST
    enum {RANGE_unlimited = -2} Range;
    struct Validator {
	boost::regex pattern;
	long long intmin, intmax; // could be bignums from http://gmplib.org/
	long double floatmin, floatmax;
	Validator(const char* pattern) : 
	    pattern(pattern), 
	    intmin(RANGE_unlimited), intmax(RANGE_unlimited), 
	    floatmin(RANGE_unlimited), floatmax(RANGE_unlimited)
	{  }
	Validator(const char* pattern, long long min, long long max) : 
	    pattern(pattern), 
	    intmin(min), intmax(max), 
	    floatmin(RANGE_unlimited), floatmax(RANGE_unlimited)
	{  }
	Validator(const char* pattern, long double min, long double max) : 
	    pattern(pattern), 
	    intmin(RANGE_unlimited), intmax(RANGE_unlimited), 
	    floatmin(min), floatmax(max)
	{  }
    };
    typedef std::map<std::string, Validator> ValidatorSet;
    typedef std::pair<std::string, Validator> ValidatorElt;
    ValidatorSet validators;
    void validate(std::string value, std::string datatype);
#endif /* REGEX_LIB == SWOb_BOOST */

public:
    std::ostream** debugStream;
    POSFactory () :
	litFalse(getBooleanRDFLiteral("false", false)), 
	litTrue(getBooleanRDFLiteral("true", true)) {

	typeOrder[typeid(BNode).name()] = DT_BNode;
	typeOrder[typeid(URI).name()] = DT_URI;
	typeOrder[typeid(RDFLiteral).name()] = DT_Literal;
	typeOrder[typeid(IntegerRDFLiteral).name()] = DT_Integer;
	typeOrder[typeid(DecimalRDFLiteral).name()] = DT_Decimal;
	typeOrder[typeid(FloatRDFLiteral).name()] = DT_Float;
	typeOrder[typeid(DoubleRDFLiteral).name()] = DT_Double;
	typeOrder[typeid(BooleanRDFLiteral).name()] = DT_Boolean;

#if REGEX_LIB == SWOb_BOOST
	using std::numeric_limits;
  #define _VAL1(T, P) validators.insert(ValidatorElt("http://www.w3.org/2001/XMLSchema#" T, Validator(P)))
  #define _VALL(T, P, L, U) validators.insert(ValidatorElt("http://www.w3.org/2001/XMLSchema#" T, Validator(P, (long long)L, (long long)U)))
  #define _VALD(T, P, L, U) validators.insert(ValidatorElt("http://www.w3.org/2001/XMLSchema#" T, Validator(P, (long double)L, (long double)U)))
  #define _MIND RANGE_unlimited /* -numeric_limits<long double>::max() */
  #define _MAXD RANGE_unlimited /* numeric_limits<long double>::max() */
  #define _MINL RANGE_unlimited /* numeric_limits<long long>::min() */
  #define _MAXL RANGE_unlimited /* numeric_limits<long long>::max() */

	const char* longPattern =    "^[-+]?[0-9]+$";
	const char* decimalPattern = "^[+\\-]?[0-9]+(\\.[0-9]+)?$";
	const char* floatPattern =   "^[+\\-]?[0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?$";
	_VAL1("integer", 	    longPattern);
	_VAL1("decimal", 	    decimalPattern);
	_VALD("float", 		    floatPattern, _MIND, _MAXD); // -149E16777216, 104E16777216);
	_VALL("double", 	    floatPattern, _MIND, _MAXD); // -1075E2251799813685248, 970E2251799813685248);
	_VAL1("string", 	    ".*");
	_VAL1("boolean", 	    "^(true|false|1|0)$");
	_VAL1("dateTime", "^("
	      "([\\-+]?)"	// optional sign @@ perhaps not supported by time(2)
	      "(\\d{4,})"	// 2004
	      "-(\\d{2})"	//     -12
	      "-(\\d{2})"	//        -31
	      "T(\\d{2})"	//           T19
	      ":(\\d{2})"	//              :01
	      "(?::(\\d{2}))?"	//                 :00
	      "(?:Z|"		//                    Z
	       "(?:([+\\-])"	//                    -
	        "(\\d{2})"	//                     05
	        ":(\\d{2})"	//                       :00
	        "))" ")$");		// 2004-12-31T19:01:00-05:00

	    //derived numerics

	_VAL1("nonPositiveInteger", "^\\+?0+|-[0-9]+$");
	_VALL("negativeInteger",    "^-[0-9]+$", RANGE_unlimited, -1);
	_VALL("long", 		    longPattern, _MINL, _MAXL); // -9223372036854775808, 9223372036854775807);
	_VALL("int", 		    longPattern, _MINL, _MAXL); // -2147483648, 2147483647);
	_VALL("short", 		    longPattern, -32768, 32767);
	_VALL("byte",		    longPattern, -128, 127);
	_VALL("nonNegativeInteger", longPattern, 0, RANGE_unlimited);
	_VALL("unsignedLong", 	    longPattern, 0, _MAXL); // 18446744073709551615);
	_VALL("unsignedInt", 	    longPattern, 0, _MAXL); // 4294967295);
	_VALL("unsignedShort", 	    longPattern, 0, 65535);
	_VALL("unsignedByte", 	    longPattern, 0, 255);
	_VALL("positiveInteger",    longPattern, 1, RANGE_unlimited);

  #undef _VAL1
  #undef _VALL
  #undef _VALD
  #undef _MINL
  #undef _MAXL
  #undef _MIND
  #undef _MAXD
#endif /* REGEX_LIB == SWOb_BOOST */
    }
    ~POSFactory();
    const Variable* getVariable(std::string name);
    const BNode* createBNode();
    const BNode* getBNode(std::string name, POS::String2BNode& nodeMap);
    const URI* getURI(std::string name);
    const POS* getPOS(std::string posStr, POS::String2BNode& nodeMap);
    const RDFLiteral* getRDFLiteral(std::string p_String, const URI* p_URI = NULL, LANGTAG* p_LANGTAG = NULL, bool validate = false);

    const IntegerRDFLiteral* getNumericRDFLiteral(std::string p_String, int p_value);
    const DecimalRDFLiteral* getNumericRDFLiteral(std::string p_String, float p_value);
    const FloatRDFLiteral* getNumericRDFLiteral(std::string p_String, float p_value, bool floatness);
    const DoubleRDFLiteral* getNumericRDFLiteral(std::string p_String, double p_value);

    const BooleanRDFLiteral* getBooleanRDFLiteral(std::string p_String, bool p_value);
    const BooleanRDFLiteral* getFalse () { return litFalse; }
    const BooleanRDFLiteral* getTrue () { return litTrue; }
    const NULLpos* getNULL () { return &nullPOS; }

    /* getTriple(s) interface: */
    const TriplePattern* getTriple (const TriplePattern* p, bool weaklyBound) {
	return getTriple(p->getS(), p->getP(), p->getO(), weaklyBound);
    }
    const TriplePattern* getTriple(const POS* s, const POS* p, const POS* o, bool weaklyBound = false);
    const TriplePattern* getTriple (std::string s, std::string p, std::string o, POS::String2BNode& nodeMap) {
	return getTriple(getPOS(s, nodeMap), 
			 getPOS(p, nodeMap), 
			 getPOS(o, nodeMap), false);
    }
#if REGEX_LIB == SWOb_BOOST
    const TriplePattern* getTriple (std::string spo, POS::String2BNode& nodeMap) {
	const boost::regex expression("[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))[[:space:]]*\\.");
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	if (!regex_search(spo, what, expression, flags))
	    return NULL;
	std::string s(what[1].first, what[1].second);
	return getTriple(getPOS(std::string(what[1].first, what[1].second), nodeMap), 
			 getPOS(std::string(what[2].first, what[2].second), nodeMap), 
			 getPOS(std::string(what[3].first, what[3].second), nodeMap), false);
    }
#endif /* REGEX_LIB == SWOb_BOOST */
    void parseTriples (BasicGraphPattern* g, std::string spo, POS::String2BNode& nodeMap);

    /* EBV (Better place for this?) */
    const POS* ebv(const POS* pos);

    struct Functor {
	const Result* res;
	POSFactory* posFactory;
	BNodeEvaluator* evaluator;

	Functor (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) : 
	    res(res), posFactory(posFactory), evaluator(evaluator) {  }
	virtual ~Functor () {  }
    };
    struct UnaryFunctor : public Functor {

	UnaryFunctor (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) : 
	    Functor(res, posFactory, evaluator) {  }
	virtual int eval(int v) = 0;
	virtual float eval(float v) = 0;
	virtual double eval(double v) = 0;
    };
    struct NaryFunctor : public Functor {

	NaryFunctor (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) : 
	    Functor(res, posFactory, evaluator) {  }
	virtual int eval(int l, int r) = 0;
	virtual float eval(float l, float r) = 0;
	virtual double eval(double l, double r) = 0;
    };
    const POS* applyCommonNumeric(const Expression* arg, UnaryFunctor* func);
    const POS* applyCommonNumeric(std::vector<const Expression*> args, NaryFunctor* func);

    void _validateNumeric (std::string str) {
#ifdef HAVE_STRTOLD
	const char* s = str.c_str();
	char* end;
	::strtold(s, &end);
	if (*end)
	    throw TypeError(s, "validate numeric");
#else
	if (str.find_first_not_of("0123456789+-Ee.") != str.npos)
	    throw TypeError(str, "validate numeric");
#endif
    }
    void _validateBoolean (std::string s) {
	if (s != "false" || s != "0" || 
	    s != "true"  || s != "1")
	    throw TypeError(s, "validate boolean");
    }
    void _validateDateTime (std::string s) {
	/* '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
	 * per <http://www.w3.org/TR/2004/REC-xmlschema-2-20041028/#dateTime-lexical-representation>
	 */
	const char* ptr = s.c_str();
	char* end;
	long int l;
	if (*ptr == '-')
	    ++ptr;

	l = strtol(ptr, &end, 10);
	if (l == 0 || end != ptr+4)
		throw TypeError(s, "xsd:datetime year");
	ptr += 4;
	if (*ptr++ != '-')
	    throw TypeError(s, "xsd:datetime year-month separator");

	l = strtol(ptr, &end, 10);
	if (l < 1 || l > 12 || end != ptr+2)
		throw TypeError(s, "xsd:datetime month");
	ptr += 2;
	if (*ptr++ != '-')
	    throw TypeError(s, "xsd:datetime year-month separator");

	l = strtol(ptr, &end, 10);
	if (l < 1 || l > 31 || end != ptr+2)
		throw TypeError(s, "xsd:datetime date");
	ptr += 2;
	if (*ptr++ != 'T')
	    throw TypeError(s, "xsd:datetime date-hour separator");

	l = strtol(ptr, &end, 10);
	if (l < 0 || l > 23 || end != ptr+2)
		throw TypeError(s, "xsd:datetime hour");
	ptr += 2;
	if (*ptr++ != ':')
	    throw TypeError(s, "xsd:datetime hour-minute separator");

	l = strtol(ptr, &end, 10);
	if (l < 0 || l > 59 || end != ptr+2)
		throw TypeError(s, "xsd:datetime minute");
	ptr += 2;
	if (*ptr++ != ':')
	    throw TypeError(s, "xsd:datetime minute-second separator");

	l = strtol(ptr, &end, 10);
	if (l < 0 || l > 59 || end != ptr+2)
		throw TypeError(s, "xsd:datetime second");
	ptr += 2;

	if (*ptr == '.') {
	    ++ptr;
	    l = strtol(ptr, &end, 10);
	    if (l < 0 || end == ptr)
		throw TypeError(s, "xsd:datetime decimal seconds");
	    ptr = end;
	}

	if (*ptr == '+' || *ptr == '-') {
	    l = strtol(ptr, &end, 10);
	    if (l < 0 || l > 23 || end != ptr+2)
		throw TypeError(s, "xsd:datetime timezone hour");
	    ptr += 2;
	    if (*ptr++ != ':')
		throw TypeError(s, "xsd:datetime timezone hour-minute separator");

	    l = strtol(ptr, &end, 10);
	    if (l < 0 || l > 59 || end != ptr+2)
		throw TypeError(s, "xsd:datetime timezone minute");
	    ptr += 2;
	} else if (*ptr != 'Z')
	    throw TypeError(s, "xsd:datetime timezone");

	if (*ptr)
	    throw TypeError(s, "xsd:datetime (garbage at end)");
    }
    int cmp (const POS* lpos, const POS* rpos) {
	/* Compare URIs lexically */
	const URI* luri = dynamic_cast<const URI*> (lpos);
	const URI* ruri = dynamic_cast<const URI*> (rpos);
	if (luri != NULL && ruri != NULL)
	    return luri->getLexicalValue().compare(ruri->getLexicalValue());

	/* Compare literals. */
	const RDFLiteral* l = dynamic_cast<const RDFLiteral*> (lpos);
	const RDFLiteral* r = dynamic_cast<const RDFLiteral*> (rpos);
	if (l == NULL || r == NULL)
	    throw TypeError(lpos ? lpos->toString() : "NULL", rpos ? rpos->toString() : "NULL");

	const URI* ldt = l->getDatatype();
	const URI* rdt = r->getDatatype();
	if (dynamic_cast<const NumericRDFLiteral*>(l) && 
	    dynamic_cast<const NumericRDFLiteral*>(r)) {
	    if (dynamic_cast<const DoubleRDFLiteral*>(l) || 
		dynamic_cast<const DoubleRDFLiteral*>(r)) {
		double dl = 
		    dynamic_cast<const DoubleRDFLiteral*> (l) ?         dynamic_cast<const DoubleRDFLiteral*> (l)->getValue() : 
		    dynamic_cast<const DecimalRDFLiteral*>(l) ? (double)dynamic_cast<const DecimalRDFLiteral*>(l)->getValue() : 
		    dynamic_cast<const FloatRDFLiteral*>  (l) ? (double)dynamic_cast<const FloatRDFLiteral*>  (l)->getValue() : 
		    dynamic_cast<const IntegerRDFLiteral*>(l) ? (double)dynamic_cast<const IntegerRDFLiteral*>(l)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		double dr = 
		    dynamic_cast<const DoubleRDFLiteral*> (r) ?         dynamic_cast<const DoubleRDFLiteral*> (r)->getValue() : 
		    dynamic_cast<const DecimalRDFLiteral*>(r) ? (double)dynamic_cast<const DecimalRDFLiteral*>(r)->getValue() : 
		    dynamic_cast<const FloatRDFLiteral*>  (r) ? (double)dynamic_cast<const FloatRDFLiteral*>  (r)->getValue() : 
		    dynamic_cast<const IntegerRDFLiteral*>(r) ? (double)dynamic_cast<const IntegerRDFLiteral*>(r)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		_validateNumeric(l->getLexicalValue());
		_validateNumeric(r->getLexicalValue());
		return
		    dl < dr ? -1 : 
		    dl > dr ?  1 : 
		    0;
	    } else if (dynamic_cast<const FloatRDFLiteral*>(l) || 
		       dynamic_cast<const FloatRDFLiteral*>(r)) {
		float dl = 
		    dynamic_cast<const FloatRDFLiteral*>  (l) ? (float) dynamic_cast<const FloatRDFLiteral*>  (l)->getValue() : 
		    dynamic_cast<const IntegerRDFLiteral*>(l) ? (float) dynamic_cast<const IntegerRDFLiteral*>(l)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		float dr = 
		    dynamic_cast<const FloatRDFLiteral*>  (r) ? (float) dynamic_cast<const FloatRDFLiteral*>  (r)->getValue() : 
		    dynamic_cast<const IntegerRDFLiteral*>(r) ? (float) dynamic_cast<const IntegerRDFLiteral*>(r)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		_validateNumeric(l->getLexicalValue());
		_validateNumeric(r->getLexicalValue());
		return
		    dl < dr ? -1 : 
		    dl > dr ?  1 : 
		    0;
	    } else if (dynamic_cast<const DecimalRDFLiteral*>(l) || 
		       dynamic_cast<const DecimalRDFLiteral*>(r)) {
		float dl = 
		    dynamic_cast<const DecimalRDFLiteral*>(l) ? (float) dynamic_cast<const DecimalRDFLiteral*>(l)->getValue() : 
		    dynamic_cast<const IntegerRDFLiteral*>(l) ? (float) dynamic_cast<const IntegerRDFLiteral*>(l)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		float dr = 
		    dynamic_cast<const DecimalRDFLiteral*>(r) ? (float) dynamic_cast<const DecimalRDFLiteral*>(r)->getValue() : 
		    dynamic_cast<const IntegerRDFLiteral*>(r) ? (float) dynamic_cast<const IntegerRDFLiteral*>(r)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		_validateNumeric(l->getLexicalValue());
		_validateNumeric(r->getLexicalValue());
		return
		    dl < dr ? -1 : 
		    dl > dr ?  1 : 
		    0;
	    } else if (dynamic_cast<const IntegerRDFLiteral*>(l) || 
		       dynamic_cast<const IntegerRDFLiteral*>(r)) {
		int dl = 
		    dynamic_cast<const IntegerRDFLiteral*>(l) ? (int)   dynamic_cast<const IntegerRDFLiteral*>(l)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		int dr = 
		    dynamic_cast<const IntegerRDFLiteral*>(r) ? (int)   dynamic_cast<const IntegerRDFLiteral*>(r)->getValue() : 
		    throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
		_validateNumeric(l->getLexicalValue());
		_validateNumeric(r->getLexicalValue());
		return
		    dl < dr ? -1 : 
		    dl > dr ?  1 : 
		    0;
	    } else {
		throw TypeError(ldt->getLexicalValue(), rdt->getLexicalValue());
	    }
	} else if (ldt == NULL && 
		   rdt == NULL) {
	    return l->getLexicalValue().compare(r->getLexicalValue());
	} else if (ldt == getURI("http://www.w3.org/2001/XMLSchema#string") && 
		   rdt == getURI("http://www.w3.org/2001/XMLSchema#string")) {
	    return l->getLexicalValue().compare(r->getLexicalValue());
	} else if (dynamic_cast<const BooleanRDFLiteral*>(l) && 
		   dynamic_cast<const BooleanRDFLiteral*>(r)) {
	    bool bl = dynamic_cast<const BooleanRDFLiteral*>(l)->getValue();
	    bool br = dynamic_cast<const BooleanRDFLiteral*>(r)->getValue();
	    _validateBoolean(l->getLexicalValue());
	    _validateBoolean(r->getLexicalValue());
	    return 
		!bl && br ? -1 : 
		bl && !br ?  1 : 
		0;
	} else if (ldt == getURI("http://www.w3.org/2001/XMLSchema#dateTime") && 
		   rdt == getURI("http://www.w3.org/2001/XMLSchema#dateTime")) {
	    _validateDateTime(l->getLexicalValue());
	    _validateDateTime(r->getLexicalValue());
	    return l->getLexicalValue().compare(r->getLexicalValue()); // luv dem isodates
	} else {
	    throw TypeError(ldt ? ldt->getLexicalValue() : "simple literal", rdt ? rdt->getLexicalValue() : "simple literal");
	}
    }

    bool lessThan (const POS* lhs, const POS* rhs) {
	if (rhs == NULL)
	    return false;
	if (lhs == NULL)
	    return true;
	try {
	    int ret = cmp(lhs, rhs);
	    if (ret != 0)
		return ret < 0;
	} catch (SafeEvaluationError&) {
	}

	const std::string lt = typeid(*lhs).name();
	const std::string rt = typeid(*rhs).name();
	if (lt != rt) {
	    if (typeOrder.find(lt) != typeOrder.end() && 
		typeOrder.find(rt) != typeOrder.end()) {
		const int li = typeOrder[lt];
		const int ri = typeOrder[rt];
		if (li < ri)
		    return true;
		if (li > ri)
		    return false;
	    }
	}
	const RDFLiteral* llit = dynamic_cast<const RDFLiteral*>(lhs);
	const RDFLiteral* rlit = dynamic_cast<const RDFLiteral*>(rhs);
	if (llit != NULL && rlit != NULL) {
	    /* Sort literals first by datatype... */
	    if (llit->getDatatype() != NULL) {
		if (rlit->getDatatype() != NULL) {
		    const std::string lt = llit->getDatatype()->getLexicalValue();
		    const std::string rt = rlit->getDatatype()->getLexicalValue();
		    int lex = lt.compare(rt);
		    if (lex != 0)
			return lex < 0;
		} else {
		    return false; // "5"^^my:int > "5"
		}
	    } else {
		if (rlit->getDatatype() != NULL) {
		    return true; // "5" < "5"^^my:int
		}
	    }

	    /* ... then by langtag. */
	    if (llit->getLangtag() != NULL) {
		if (rlit->getLangtag() != NULL) {
		    const std::string lt = llit->getLangtag()->getLexicalValue();
		    const std::string rt = rlit->getLangtag()->getLexicalValue();
		    int lex = lt.compare(rt);
		    if (lex != 0)
			return lex < 0;
		} else {
		    return false; // "5"@en > "5"
		}
	    } else {
		if (rlit->getLangtag() != NULL) {
		    return true; // "5" < "5"@en
		}
	    }
	}
	int lex = lhs->getLexicalValue().compare(rhs->getLexicalValue());
	if (lex != 0)
	    return lex < 0;
	throw std::string("unexpected partial ordering(") + lhs->toString() + ", " + rhs->toString() + ")";
    }
    bool eval(const Expression* expression, const Result* row);
};

    /* Sorter for the POSs. */
struct POSsorter;
extern POSsorter* ThePOSsorter;

struct POSsorter {
public:
    std::map<const std::string, int> typeOrder;
    POSsorter () {
	//typeOrder.insert(make_pair(typeid(BNode).name(), 2));
	typeOrder[typeid(BNode).name()] = 2;
	typeOrder[typeid(URI).name()] = 3;
	typeOrder[typeid(RDFLiteral).name()] = 4;
	ThePOSsorter = this;
    }
    bool operator() (const POS* lhs, const POS* rhs) {
	const std::string lt = typeid(*lhs).name();
	const std::string rt = typeid(*rhs).name();
	const int li = typeOrder[lt];
	const int ri = typeOrder[rt];
	if (li < ri)
	    return true;
	return lhs->getLexicalValue().compare(rhs->getLexicalValue()) < 0;
    }
};

/* END Parts Of Speach */

class Expression : public Base {
private:
public:
    Expression () : Base() { }
    ~Expression () {  }
    virtual void express(Expressor* p_expressor) const = 0;
    virtual const POS* eval(const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const = 0;
    virtual bool operator==(const Expression&) const = 0;
};
typedef ProductionVector<const Expression*> ExprSet;

inline bool POSFactory::eval (const Expression* expression, const Result* row) {
    bool ret;
    try {
	ret = ebv(expression->eval(row, this, NULL)) == getTrue();
    } catch (SafeEvaluationError&) {
	ret = false;
    }
    return ret;
}

typedef enum {DIST_all, DIST_distinct, DIST_reduced} e_distinctness;
typedef enum {LIST_exact, LIST_members, LIST_starts, LIST_ends, LIST_any, LIST_unordered} e_listModifier;
typedef enum { ORDER_Asc, ORDER_Desc } e_ASCorDESC;
#define LIMIT_None -1
#define OFFSET_None -1
typedef struct {e_ASCorDESC ascOrDesc; const Expression* expression;} s_OrderConditionPair;
typedef enum { SILENT_Yes, SILENT_No } e_Silence;

/*
TableOperation class hierarchy:               Base
                                               |
                             ___________TableOperation_____________
            ________________/                  |                   \__________________
     TableJunction                    BasicGraphPattern                     TableOperationOnOperation
        /        \                       /          \                           /               \
T*Conjunction T*Disjunction   NamedGraphPattern  DefaultGraphPattern  GraphGraphPattern  OptionalGraphPattern


related Expressor operations:   base(Base* self, std::string productionName)
                                               |
                             __________[TableOperation]____________
            ________________/                  |                   \__________________
    [TableJunction]                  [BasicGraphPattern]                   [TableOperationOnOperation]
        /        \                       /          \                           /               \
t*Conjunction t*Disjunction   namedGraphPattern  defaultGraphPattern  graphGraphPattern  optionalGraphPattern

*/

class TableOperation : public Base {
protected:
    TableOperation () : Base() {  }
    TableOperation(const TableOperation& ref);
public:
    virtual void bindVariables(RdfDB*, ResultSet*) const = 0; //{ throw(std::runtime_error(FUNCTION_STRING)); }
    virtual void construct(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const = 0;
    virtual void deletePattern(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const = 0;
    virtual void express(Expressor* p_expressor) const = 0;
    virtual TableOperation* getDNF() const = 0;
    virtual bool operator==(const TableOperation& ref) const = 0;
    virtual std::string toString(MediaType mediaType = MediaType(NULL), NamespaceMap* namespaces = NULL) const;
};
class TableJunction : public TableOperation {
protected:
    ProductionVector<const TableOperation*> m_TableOperations;
public:
    TableJunction () : TableOperation(), m_TableOperations() {  }

    bool operator== (const TableJunction& ref) const {
	if (m_TableOperations.size() != ref.m_TableOperations.size())
	    return false;
	std::vector<const TableOperation*>::const_iterator mit = begin();
	std::vector<const TableOperation*>::const_iterator rit = ref.begin();
	for ( ; mit != end(); ++mit, ++rit)
	    if ( !(**mit == **rit) )
		return false;
	return true;
    }
    virtual void addTableOperation(const TableOperation* tableOp, bool flatten);
    std::vector<const TableOperation*>::iterator begin () { return m_TableOperations.begin(); }
    std::vector<const TableOperation*>::const_iterator begin () const { return m_TableOperations.begin(); }
    std::vector<const TableOperation*>::iterator end () { return m_TableOperations.end(); }
    std::vector<const TableOperation*>::const_iterator end () const { return m_TableOperations.end(); }
    void clear () { m_TableOperations.clear(); }
    std::vector<const TableOperation*>::iterator erase (std::vector<const TableOperation*>::iterator it) { return m_TableOperations.erase(it); }
    size_t size () const { return m_TableOperations.size(); }
    /* simplify lies -- it modifies otherwise unmodifiable TableOperations. */
    TableOperation* simplify () {
	TableOperation* ret;
	if (size() == 0 || size() == 1) {
	    ret = size() == 0 ? NULL : (TableOperation*)*begin(); /* LIES */
	    clear();
	    delete this;
	} else
	    ret = this;
	return ret;
    }
};
class TableConjunction : public TableJunction { // ⊍
public:
    TableConjunction () : TableJunction() {  }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const TableConjunction* pref = dynamic_cast<const TableConjunction*>(&ref);
	return pref == NULL ? false : TableJunction::operator==(*pref);
    }
    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual void construct(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual void deletePattern(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual TableOperation* getDNF() const;
};
class TableDisjunction : public TableJunction { // ⊎
public:
    TableDisjunction () : TableJunction() {  }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const TableDisjunction* pref = dynamic_cast<const TableDisjunction*>(&ref);
	return pref == NULL ? false : TableJunction::operator==(*pref);
    }
    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual void construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw NotImplemented("CONSTRUCT{{?s?p?o}UNION{?s?p?o}}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw NotImplemented("DELETEPATTERN{{?s?p?o}UNION{?s?p?o}}");
    }
    virtual TableOperation* getDNF() const;
};
class BasicGraphPattern : public TableOperation { // ⊌⊍
    typedef std::multimap<const POS*, const TriplePattern*> idx_type;
    typedef std::pair<const POS*, const TriplePattern*> idx_pair;
    typedef std::pair<idx_type::const_iterator, idx_type::const_iterator> idx_range;

protected:

    // make sure we don't delete the TriplePatterns
    NoDelProductionVector<const TriplePattern*> m_TriplePatterns;
    idx_type idx;
    bool allOpts;
    BasicGraphPattern (bool allOpts) : TableOperation(), m_TriplePatterns(), allOpts(allOpts) {  }
    BasicGraphPattern (const BasicGraphPattern& ref) :
	TableOperation(ref), m_TriplePatterns(ref.m_TriplePatterns), // idx(ref.idx), 
	allOpts(ref.allOpts) {  }

    /* Misc helper functions: */
    static const POS* _cOrN(const POS* pos, const NULLpos* n);
    /* wrapper function pushed into .cpp because RdfDB is incomplete. */
    void _bindVariables(RdfDB* db, ResultSet* rs, const POS* p_name) const;

public:

    bool operator==(const BasicGraphPattern& ref) const;
    /* Controls for operator==(BasicGraphPatter&)
     */
    static std::ostream* DiffStream;	// << diff strings to DiffStream .
    static bool CompareVars;		// Whether ?x == ?y .

    void addTriplePattern (const TriplePattern* p) {
	idx_range range = idx.equal_range (p->getP());
	for ( ; range.first != range.second; ++range.first)
	    if ((*range.first).second == p)
		return;
	m_TriplePatterns.push_back(p);
	idx.insert(idx_pair(p->getP(), p));
    }
    virtual void bindVariables(RdfDB* db, ResultSet* rs) const = 0;
    void bindVariables(ResultSet* rs, const POS* graphVar, const BasicGraphPattern* toMatch, const POS* graphName) const;
    void construct(BasicGraphPattern* target, const ResultSet* rs, BNodeEvaluator* evaluator) const;
    virtual void construct(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual void deletePattern(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    size_t size () const { return m_TriplePatterns.size(); }
    std::vector<const TriplePattern*>::iterator begin () { return m_TriplePatterns.begin(); }
    std::vector<const TriplePattern*>::const_iterator begin () const { return m_TriplePatterns.begin(); }
    std::vector<const TriplePattern*>::iterator end () { return m_TriplePatterns.end(); }
    std::vector<const TriplePattern*>::const_iterator end () const { return m_TriplePatterns.end(); }
    std::vector<const TriplePattern*>::iterator erase (std::vector<const TriplePattern*>::iterator it) { return m_TriplePatterns.erase(it); }
    void sort (bool (*comp)(const TriplePattern*, const TriplePattern*)) { m_TriplePatterns.sort(comp); }
    void clearTriples () { m_TriplePatterns.clear(); }
    virtual void express(Expressor* p_expressor) const = 0;
    virtual bool operator==(const TableOperation& ref) const = 0;
    virtual std::string toString(MediaType mediaType = MediaType((const char*)NULL), NamespaceMap* namespaces = NULL) const;
};

class NamedGraphPattern : public BasicGraphPattern {
private:
    const POS* m_name;

public:
    NamedGraphPattern (const POS* p_name, bool allOpts = false) : BasicGraphPattern(allOpts), m_name(p_name) {  }
    NamedGraphPattern (const NamedGraphPattern& ref) : BasicGraphPattern(ref), m_name(ref.m_name) {  }
    virtual TableOperation* getDNF () const { return new NamedGraphPattern(*this); }
    virtual void express(Expressor* p_expressor) const;
    virtual void bindVariables (RdfDB* db, ResultSet* rs) const {
	_bindVariables(db, rs, m_name); /* RdfDB is incomplete. */
    }
    virtual bool operator== (const TableOperation& ref) const {
	const NamedGraphPattern* pref = dynamic_cast<const NamedGraphPattern*>(&ref);
	return pref == NULL ? false : 
	    m_name == pref->m_name &&
	    BasicGraphPattern::operator==(*pref);
    }
};
class DefaultGraphPattern : public BasicGraphPattern {
public:
    DefaultGraphPattern (bool allOpts = false) : BasicGraphPattern(allOpts) {  }
    DefaultGraphPattern (const DefaultGraphPattern& ref) : BasicGraphPattern(ref) {  }
    virtual TableOperation* getDNF () const { return new DefaultGraphPattern(*this); }
    virtual void express(Expressor* p_expressor) const;
    virtual void bindVariables (RdfDB* db, ResultSet* rs) const {
	_bindVariables(db, rs, NULL); /* RdfDB is incomplete. */
    }
    virtual bool operator== (const TableOperation& ref) const {
	const DefaultGraphPattern* pref = dynamic_cast<const DefaultGraphPattern*>(&ref);
	return pref == NULL ? false :
	    BasicGraphPattern::operator==(*pref);
    }
};
class TableOperationOnOperation : public TableOperation {
protected:
    const TableOperation* m_TableOperation;
    TableOperationOnOperation (const TableOperation* p_TableOperation) : TableOperation(), m_TableOperation(p_TableOperation) {  }
    ~TableOperationOnOperation() { delete m_TableOperation; }
    virtual TableOperationOnOperation* makeANewThis(const TableOperation* p_TableOperation) const = 0;
public:
    virtual TableOperation* getDNF() const;
};
class Filter : public TableOperationOnOperation {
protected:
    ProductionVector<const Expression*> m_Expressions;

public:
    Filter (const TableOperation* op) : TableOperationOnOperation(op) {  }
    ~Filter () {  }

    //size_t filters () { return m_Filters.size(); }
    void addExpression (const Expression* expression) {
	m_Expressions.push_back(expression);
    }

    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual void construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw NotImplemented("CONSTRUCT{FILTER(...)}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw NotImplemented("DELETEPATTERN{FILTER(...)}");
    }
    virtual void express(Expressor* p_expressor) const;
    bool operator== (const Filter& ref) const {
	if ( !(*m_TableOperation == *ref.m_TableOperation) )
	    return false;
	std::vector<const Expression*>::const_iterator mit = m_Expressions.begin();
	std::vector<const Expression*>::const_iterator rit = ref.m_Expressions.begin();
	for ( ; mit != m_Expressions.end(); ++mit, ++rit)
	    if ( !(**mit == **rit) )
		return false;
	return true;
    }
    bool operator== (const TableOperation& ref) const {
	const Filter* pref = dynamic_cast<const Filter*>(&ref);
	return pref == NULL ? false : operator==(*pref);
    }
    virtual TableOperationOnOperation* makeANewThis(const TableOperation* p_TableOperation) const;
};
/* GraphGraphPattern: pass-through class that's just used to reproduce verbatim SPARQL queries
 */
class GraphGraphPattern : public TableOperationOnOperation {
private:
    const POS* m_VarOrIRIref;
public:
    GraphGraphPattern (const POS* p_POS, const TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern), m_VarOrIRIref(p_POS) {  }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const GraphGraphPattern* pref = dynamic_cast<const GraphGraphPattern*>(&ref);
	return pref == NULL ? false : 
	    m_VarOrIRIref == pref->m_VarOrIRIref &&
	    *m_TableOperation == *pref->m_TableOperation;
    }
    virtual void bindVariables (RdfDB* db, ResultSet* rs) const {
	m_TableOperation->bindVariables(db, rs);
    }
    virtual void construct(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual void deletePattern(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual TableOperationOnOperation* makeANewThis (const TableOperation* p_TableOperation) const { return new GraphGraphPattern(m_VarOrIRIref, p_TableOperation); }
};
/* ServiceGraphPattern: pass-through class that's just used to reproduce verbatim SPARQL queries
 */
class ServiceGraphPattern : public TableOperationOnOperation {
private:
    const POS* m_VarOrIRIref;
    POSFactory* posFactory;
    bool lexicalCompare;
public:
    ServiceGraphPattern (const POS* p_POS, const TableOperation* p_GroupGraphPattern, POSFactory* posFactory, bool lexicalCompare) : 
	TableOperationOnOperation(p_GroupGraphPattern), 
	m_VarOrIRIref(p_POS), posFactory(posFactory), 
	lexicalCompare(lexicalCompare) // use STR(?foo) = ?bar instead of ?foo = ?bar
    {  }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const ServiceGraphPattern* pref = dynamic_cast<const ServiceGraphPattern*>(&ref);
	return pref == NULL ? false : 
	    m_VarOrIRIref == pref->m_VarOrIRIref &&
	    *m_TableOperation == *pref->m_TableOperation;
    }
    virtual void bindVariables(RdfDB* db, ResultSet* rs) const;
    virtual void construct(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual void deletePattern(RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const;
    virtual TableOperationOnOperation* makeANewThis (const TableOperation* p_TableOperation) const { return new ServiceGraphPattern(m_VarOrIRIref, p_TableOperation, posFactory, lexicalCompare); }
};
class OptionalGraphPattern : public TableOperationOnOperation {
protected:
    ProductionVector<const Expression*> m_Expressions;

public:
    OptionalGraphPattern (const TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern) {  }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const OptionalGraphPattern* pref = dynamic_cast<const OptionalGraphPattern*>(&ref);
	return pref == NULL ? false : 
	    *m_TableOperation == *pref->m_TableOperation;
    }
    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual void construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw NotImplemented("CONSTRUCT{OPTIONAL{?s?p?o}}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw NotImplemented("DELETEPATTERN{OPTIONAL{?s?p?o}}");
    }
    virtual TableOperationOnOperation* makeANewThis (const TableOperation* p_TableOperation) const { return new OptionalGraphPattern(p_TableOperation); }

    void addExpression (const Expression* expression) {
	m_Expressions.push_back(expression);
    }
};

class VarSet : public Base {
protected:
    VarSet () : Base() { }
public:
    virtual void express(Expressor* p_expressor) const = 0;
    virtual bool operator==(const VarSet& ref) const = 0;
    virtual void project(ResultSet* rs) const = 0;
};

class POSList : public VarSet {
private:
    ProductionVector<const POS*> m_POSs;
public:
    POSList () : VarSet(), m_POSs() {  }
    ~POSList () { m_POSs.clear(); }
    void push_back(const POS* v) { m_POSs.push_back(v); }
    virtual void express(Expressor* p_expressor) const;
    std::vector<const POS*>::iterator begin () { return m_POSs.begin(); }
    std::vector<const POS*>::const_iterator begin () const { return m_POSs.begin(); }
    std::vector<const POS*>::iterator end () { return m_POSs.end(); }
    std::vector<const POS*>::const_iterator end () const { return m_POSs.end(); }
    virtual bool operator== (const VarSet& ref) const {
	const POSList* pref = dynamic_cast<const POSList*>(&ref);
	return pref == NULL ? false : m_POSs == pref->m_POSs;
    }
    virtual void project (ResultSet* rs) const;
};
class StarVarSet : public VarSet {
private:
public:
    StarVarSet () : VarSet() {  }
    size_t size() { return 0; }
    POS* operator [] (size_t) { return NULL; }
    POS* getElement (size_t) { return NULL; }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const VarSet& ref) const {
	const StarVarSet* pref = dynamic_cast<const StarVarSet*>(&ref);
	return pref == NULL ? false : true;
    }
    virtual void project (ResultSet* rs) const;
};

class DatasetClause : public Base {
protected:
    const POS* m_IRIref;
    POSFactory* m_posFactory;
public:
    DatasetClause (const POS* p_IRIref, POSFactory* p_posFactory) : Base(), m_IRIref(p_IRIref), m_posFactory(p_posFactory) {  }
    ~DatasetClause () { /* m_IRIref is centrally managed */ }
    void loadGraph(RdfDB* db, const POS* name, BasicGraphPattern* target) const;
    virtual void loadData(RdfDB*) const = 0;
    virtual void express(Expressor* p_expressor) const = 0;
};
class DefaultGraphClause : public DatasetClause {
private:
public:
    DefaultGraphClause (const POS* p_IRIref, POSFactory* p_posFactory) : DatasetClause(p_IRIref, p_posFactory) { }
    ~DefaultGraphClause () {  }
    virtual void express(Expressor* p_expressor) const;
    virtual void loadData(RdfDB*) const;
};
class NamedGraphClause : public DatasetClause {
private:
public:
    NamedGraphClause (const POS* p_IRIref, POSFactory* p_posFactory) : DatasetClause(p_IRIref, p_posFactory) { }
    ~NamedGraphClause () {  }
    virtual void express(Expressor* p_expressor) const;
    virtual void loadData(RdfDB*) const;
};

    /* SolutionModifiers */
class SolutionModifier : public Base {
private:
    std::vector<s_OrderConditionPair>* m_OrderConditions;
public:
    int m_limit;
    int m_offset;
    SolutionModifier (std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) : Base(), m_OrderConditions(p_OrderConditions), m_limit(p_limit), m_offset(p_offset) {  }
    ~SolutionModifier () {
	if (m_OrderConditions != NULL)
	    for (size_t i = 0; i < m_OrderConditions->size(); i++)
		delete m_OrderConditions->at(i).expression;
	delete m_OrderConditions;
    }
    void order(ResultSet* rs);
    virtual void express(Expressor* p_expressor) const;
    bool operator== (const SolutionModifier& ref) const {
	if (m_limit != ref.m_limit ||
	    m_offset != ref.m_offset)
	    return false;
	if (m_OrderConditions && ref.m_OrderConditions) {
	    if (m_OrderConditions->size() != ref.m_OrderConditions->size())
		return false;
	    std::vector<s_OrderConditionPair>::const_iterator mit = 
		m_OrderConditions->begin();
	    std::vector<s_OrderConditionPair>::const_iterator rit = 
		ref.m_OrderConditions->begin();
	    for ( ; mit != m_OrderConditions->end(); ++mit, ++rit)
		if ( !(mit->ascOrDesc == rit->ascOrDesc) ||
		     !(*mit->expression == *rit->expression))
		    return false;
	}
	return m_OrderConditions == ref.m_OrderConditions;
    }
};
class Binding : public ProductionVector<const POS*> {
private:
public:
    Binding () : ProductionVector<const POS*>() {  }
    ~Binding () { clear(); /* atoms in vector are centrally managed */ }
    virtual void express(Expressor* p_expressor) const;
    void bindVariables(RdfDB* db, ResultSet* rs, Result* r, POSList* p_Vars) const;
};
class BindingClause : public ProductionVector<const Binding*> {
private:
    POSList* m_Vars;
public:
    BindingClause (POSList* p_Vars) : ProductionVector<const Binding*>(), m_Vars(p_Vars) {  }
    ~BindingClause () { delete m_Vars; }
    virtual void express(Expressor* p_expressor) const;
    void bindVariables(RdfDB* db, ResultSet* rs) const;
};
class WhereClause : public Base {
private:
    const TableOperation* m_GroupGraphPattern;
    const BindingClause* m_BindingClause;
public:
    WhereClause (const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) : Base(), m_GroupGraphPattern(p_GroupGraphPattern), m_BindingClause(p_BindingClause) {  }
    ~WhereClause () {
	delete m_GroupGraphPattern;
	delete m_BindingClause;
    }
    virtual void express(Expressor* p_expressor) const;
    void bindVariables(RdfDB* db, ResultSet* rs) const;
    bool operator== (const WhereClause& ref) const {
	return
	    *m_GroupGraphPattern == *ref.m_GroupGraphPattern &&
	    ( m_BindingClause && ref.m_BindingClause ? 
	      *m_BindingClause == *ref.m_BindingClause : 
	      m_BindingClause == ref.m_BindingClause );
    }
};

class Select : public Operation {
private:
    e_distinctness m_distinctness;
    VarSet* m_VarSet;
    ProductionVector<const DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
    SolutionModifier* m_SolutionModifier;
public:
    Select (e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) : Operation(), m_distinctness(p_distinctness), m_VarSet(p_VarSet), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause), m_SolutionModifier(p_SolutionModifier) {  }
    ~Select () {
	delete m_VarSet;
	delete m_DatasetClauses;
	delete m_WhereClause;
	delete m_SolutionModifier;
    }
    virtual void express(Expressor* p_expressor) const;
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL) const;
    virtual bool operator== (const Operation& ref) const {
	const Select* pSel = dynamic_cast<const Select*>(&ref);
	if (pSel == NULL)
	    return false;
	return
	    *m_VarSet == *pSel->m_VarSet && 
	    *m_DatasetClauses == *pSel->m_DatasetClauses && // !!! need to look deeper
	    *m_WhereClause == *pSel->m_WhereClause && 
	    *m_SolutionModifier == *pSel->m_SolutionModifier;
    }
};
class Construct : public Operation {
protected:
    DefaultGraphPattern* m_ConstructTemplate;
    ProductionVector<const DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
    SolutionModifier* m_SolutionModifier;
    DefaultGraphPattern* resultGraph;

public:
    Construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) : 
	Operation(), m_ConstructTemplate(p_ConstructTemplate), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause), m_SolutionModifier(p_SolutionModifier), resultGraph(new DefaultGraphPattern()) {  }
    ~Construct () {
	delete m_ConstructTemplate;
	delete m_DatasetClauses;
	delete m_WhereClause;
	delete m_SolutionModifier;
	delete resultGraph;
    }
    virtual void express(Expressor* p_expressor) const;
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL) const;
    WhereClause* getWhereClause () { return m_WhereClause; }
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Describe : public Operation {
private:
    VarSet* m_VarSet;
    ProductionVector<const DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
    SolutionModifier* m_SolutionModifier;
public:
    Describe (VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) : Operation(), m_VarSet(p_VarSet), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause), m_SolutionModifier(p_SolutionModifier) {  }
    ~Describe () {
	delete m_VarSet;
	delete m_DatasetClauses;
	delete m_WhereClause;
	delete m_SolutionModifier;
    }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Ask : public Operation {
private:
    ProductionVector<const DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
public:
    Ask (ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) : Operation(), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause) {  }
    ~Ask () {
	delete m_DatasetClauses;
	delete m_WhereClause;
    }
    virtual void express(Expressor* p_expressor) const;
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL) const;
    virtual bool operator== (const Operation& ref) const {
	const Ask* pSel = dynamic_cast<const Ask*>(&ref);
	if (pSel == NULL)
	    return false;
	return
	    *m_DatasetClauses == *pSel->m_DatasetClauses && // !!! need to look deeper
	    *m_WhereClause == *pSel->m_WhereClause;
    }
};
class Replace : public Operation {
private:
    WhereClause* m_WhereClause;
    TableOperation* m_GraphTemplate;
public:
    Replace (WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) : Operation(), m_WhereClause(p_WhereClause), m_GraphTemplate(p_GraphTemplate) {  }
    ~Replace () { delete m_WhereClause; delete m_GraphTemplate; }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Insert : public Operation {
private:
    TableOperation* m_GraphTemplate;
    WhereClause* m_WhereClause;
public:
    Insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) : Operation(), m_GraphTemplate(p_GraphTemplate), m_WhereClause(p_WhereClause) {  }
    ~Insert () { delete m_GraphTemplate; delete m_WhereClause; }
    virtual void express(Expressor* p_expressor) const;
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Delete : public Operation {
private:
    TableOperation* m_GraphTemplate;
    WhereClause* m_WhereClause;
public:
    Delete (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) : Operation(), m_GraphTemplate(p_GraphTemplate), m_WhereClause(p_WhereClause) {  }
    ~Delete () { delete m_GraphTemplate; delete m_WhereClause; }
    virtual void express(Expressor* p_expressor) const;
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Load : public Operation {
private:
    ProductionVector<const URI*>* m_IRIrefs;
    const URI* m_into;
public:
    Load (ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) : Operation(), m_IRIrefs(p_IRIrefs), m_into(p_into) {  }
    ~Load () { delete m_IRIrefs; delete m_into; }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Clear : public Operation {
private:
    const URI* m__QGraphIRI_E_Opt;
public:
    Clear (const URI* p__QGraphIRI_E_Opt) : Operation(), m__QGraphIRI_E_Opt(p__QGraphIRI_E_Opt) { }
    ~Clear () { delete m__QGraphIRI_E_Opt; }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Create : public Operation {
private:
    e_Silence m_Silence;
    const URI* m_GraphIRI;
public:
    Create (e_Silence p_Silence, const URI* p_GraphIRI) : Operation(), m_Silence(p_Silence), m_GraphIRI(p_GraphIRI) {  }
    ~Create () { /* m_GraphIRI is centrally managed */ }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};
class Drop : public Operation {
private:
    e_Silence m_Silence;
    const URI* m_GraphIRI;
public:
    Drop (e_Silence p_Silence, const URI* p_GraphIRI) : Operation(), m_Silence(p_Silence), m_GraphIRI(p_GraphIRI) {  }
    ~Drop () { /* m_GraphIRI is centrally managed */ }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const Operation&) const {
	return false;
    }
};

/* kinds of Expressions */
class POSExpression : public Expression {
private:
    const POS* m_POS;
public:
    POSExpression (const POS* p_POS) : Expression(), m_POS(p_POS) {  }
    ~POSExpression () { /* m_POS is centrally managed */ }
    const POS* getPOS () const { return m_POS; }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* r, POSFactory* /* posFactory */, BNodeEvaluator* evaluator) const {
	return m_POS->evalPOS(r, evaluator);
    }
    virtual bool operator== (const Expression& ref) const {
	const POSExpression* pref = dynamic_cast<const POSExpression*>(&ref);
	return pref == NULL ? false : m_POS == pref->m_POS;
    }
};

class ArgList : public Base {
private:
    ProductionVector<const Expression*>* expressions;
public:
    typedef std::vector<const Expression*> Args;
    typedef Args::iterator ArgIterator;
    ArgList (ProductionVector<const Expression*>* expressions) : Base(), expressions(expressions) {  }
    ~ArgList () { delete expressions; }
    ArgIterator begin () const { return expressions->begin(); }
    ArgIterator end () const { return expressions->end(); }
    size_t size () const { return expressions->size(); }
    virtual void express(Expressor* p_expressor) const;
};
class FunctionCall : public Base {
private:
    const URI* m_IRIref;
    const ArgList* m_ArgList;
public:
    FunctionCall (const URI* p_IRIref, const ArgList* p_ArgList) : Base(), m_IRIref(p_IRIref), m_ArgList(p_ArgList) {  }
    FunctionCall (const URI* p_IRIref, Expression* arg1, Expression* arg2, Expression* arg3) : Base() {
	m_IRIref = p_IRIref;
	ProductionVector<const Expression*>* args = new ProductionVector<const Expression*>();
	if (arg1) args->push_back(arg1);
	if (arg2) args->push_back(arg2);
	if (arg3) args->push_back(arg3);
	m_ArgList = new ArgList(args);
    }
    ~FunctionCall () { delete m_ArgList; }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	std::vector<const POS*> subd;
	for (ArgList::ArgIterator it = m_ArgList->begin(); it != m_ArgList->end(); ++it)
	    subd.push_back((*it)->eval(r, posFactory, evaluator));

	/* Write down the first 3 for convenience. */
	std::vector<const POS*>::const_iterator it = subd.begin();
	const POS* first = it == subd.end() ? NULL : *it++;
	std::string func = m_IRIref->getLexicalValue();

	/* casts */
	if (func == "http://www.w3.org/2001/XMLSchema#float"    || 
	    func == "http://www.w3.org/2001/XMLSchema#double"   || 
	    func == "http://www.w3.org/2001/XMLSchema#decimal"  || 
	    func == "http://www.w3.org/2001/XMLSchema#integer"  || 
	    func == "http://www.w3.org/2001/XMLSchema#boolean"    ) {
	    const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(first);
	    if (s != NULL) {
		const URI* dt = s->getDatatype();
		std::string dtl = dt ? dt->getLexicalValue() : ":noDT";
		if (dt == NULL || 
		    dtl == "http://www.w3.org/2001/XMLSchema#string"  || 
		    dtl == "http://www.w3.org/2001/XMLSchema#float"   || 
		    dtl == "http://www.w3.org/2001/XMLSchema#double"  || 
		    dtl == "http://www.w3.org/2001/XMLSchema#decimal" || // check
		    dtl == "http://www.w3.org/2001/XMLSchema#integer" || // check
		    dtl == "http://www.w3.org/2001/XMLSchema#boolean"   )// adjust
		    return posFactory->getRDFLiteral(first->getLexicalValue(), m_IRIref, NULL, true);
	    }
	}

	if (func == "http://www.w3.org/2001/XMLSchema#dateTime"   ) {
	    const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(first);
	    if (s != NULL) {
		const URI* dt = s->getDatatype();
		std::string dtl = dt ? dt->getLexicalValue() : ":noDT";
		if (dt == NULL || 
		    dtl == "http://www.w3.org/2001/XMLSchema#dateTime"  )// adjust
		    return posFactory->getRDFLiteral(first->getLexicalValue(), m_IRIref, NULL, true);
	    }
	}

	if (func == "http://www.w3.org/2001/XMLSchema#string"   ) {
	    return posFactory->getRDFLiteral(first->getLexicalValue(), m_IRIref, NULL, true);
	}

	/* operators */
	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound") && 
	    subd.size() == 1)
	    return first == NULL ? posFactory->getFalse() : posFactory->getTrue();

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI") && 
	    subd.size() == 1)
	    return dynamic_cast<const URI*>(first) == NULL ? posFactory->getFalse() : posFactory->getTrue();

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank") && 
	    subd.size() == 1)
	    return dynamic_cast<const BNode*>(first) == NULL ? posFactory->getFalse() : posFactory->getTrue();

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral") && 
	    subd.size() == 1)
	    return dynamic_cast<const RDFLiteral*>(first) == NULL ? posFactory->getFalse() : posFactory->getTrue();

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str") && // STR(RDFLiteral)
	    subd.size() == 1 && dynamic_cast<const RDFLiteral*>(first) != NULL)
	    return posFactory->getRDFLiteral(first->getLexicalValue());

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str") && // STR(URI)
	    subd.size() == 1 && dynamic_cast<const URI*>(first) != NULL)
	    return posFactory->getRDFLiteral(first->getLexicalValue());

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang") && 
	    subd.size() == 1 && dynamic_cast<const RDFLiteral*>(first) != NULL) {
	    const LANGTAG* t = dynamic_cast<const RDFLiteral*>(first)->getLangtag();
	    return posFactory->getRDFLiteral(t ? t->getLexicalValue() : "");
	}

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype") && 
	    subd.size() == 1 && dynamic_cast<const RDFLiteral*>(first) != NULL && 
	    dynamic_cast<const RDFLiteral*>(first)->getLangtag() == NULL) {
	    const URI* dt = dynamic_cast<const RDFLiteral*>(first)->getDatatype();
	    return dt ? dt : posFactory->getURI("http://www.w3.org/2001/XMLSchema#string");
	}

	const POS* second = it == subd.end() ? NULL : *it++;

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm") && 
	    subd.size() == 2) {
	    return first == second && first != NULL ? posFactory->getTrue() : posFactory->getFalse();
	}

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches") && 
	    subd.size() == 2 && 
	    dynamic_cast<const RDFLiteral*>(first) != NULL && 
	    dynamic_cast<const RDFLiteral*>(second) != NULL) {

	    /* knock off the easy ones... */
	    if (first == second)
		return posFactory->getTrue();
	    std::string tag = dynamic_cast<const RDFLiteral*>(first)->getLexicalValue();
	    std::string range = dynamic_cast<const RDFLiteral*>(second)->getLexicalValue();
	    if (range == "*")
		return tag.empty() ? posFactory->getFalse() : posFactory->getTrue();

	    std::string::iterator t = tag.begin();
	    std::string::iterator te = tag.end();
	    std::string::iterator r = range.begin();
	    std::string::iterator re = range.end();

	    while (t != te && r != re)
		if (::tolower(*t++) != ::tolower(*r++))
		    return posFactory->getFalse();

	    if (r == re && 
		(t == te || *t == '-'))
		return posFactory->getTrue();

	    return posFactory->getFalse();
	}

	const POS* third = it == subd.end() ? NULL : *it++;
	const RDFLiteral* firstLit = dynamic_cast<const RDFLiteral*>(first);
	const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(second);
	const RDFLiteral* thirdLit = dynamic_cast<const RDFLiteral*>(third);

	if (m_IRIref == posFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex") && 
	    ( subd.size() == 2 || subd.size() == 3 ) && 
	    firstLit != NULL && firstLit->getDatatype() == NULL && firstLit->getLangtag() == NULL && 
	    secondLit != NULL && secondLit->getDatatype() == NULL && secondLit->getLangtag() == NULL && 
	    ( subd.size() == 2 || 
	      (thirdLit != NULL && thirdLit->getDatatype() == NULL && thirdLit->getLangtag() == NULL))) {
#if REGEX_LIB == SWOb_DISABLED
	    throw std::string("no regular expression library was linked in");
#else
	    boost::match_results<std::string::const_iterator> what;
	    boost::match_flag_type flags = boost::match_default;
	    unsigned l_flags = boost::regex::basic | boost::regex::no_mod_m | boost::regex::no_mod_s;
	    if (thirdLit != NULL) {
		std::string smix = thirdLit->getLexicalValue();
		if (smix.find_first_of('s') != std::string::npos)
		    l_flags &= ~boost::regex::no_mod_s;
		if (smix.find_first_of('m') != std::string::npos)
		    l_flags &= ~boost::regex::no_mod_m;
		if (smix.find_first_of('i') != std::string::npos)
		    l_flags |= boost::regex::icase;
		if (smix.find_first_of('x') != std::string::npos)
		    l_flags |= boost::regex::mod_x;
	    }
	    const boost::regex pattern(secondLit->getLexicalValue(), l_flags);
	    return regex_search(firstLit->getLexicalValue(), what, pattern, flags) ? posFactory->getTrue() : posFactory->getFalse();
#endif
	}

	std::stringstream s;
	s << m_IRIref->toString() << '(';
	for (std::vector<const POS*>::iterator it = subd.begin(); it != subd.end(); ++it) {
	    if (it != subd.begin())
		s << ", ";
	    if (*it)
		s << (*it)->toString();
	    else
		s << "NULL";
	}
	s << ')';
	throw NotImplemented(s.str());
    }
    bool operator== (const FunctionCall& ref) const {
	if (m_IRIref != ref.m_IRIref)
	    return false;
	if (m_ArgList->size() != ref.m_ArgList->size())
	    return false;
	ArgList::ArgIterator mit = m_ArgList->begin();
	ArgList::ArgIterator rit = ref.m_ArgList->begin();
	for ( ; mit != m_ArgList->end(); ++mit, ++rit)
	    if ( !(**mit == **rit) )
		return false;
	return true;
    }
};
class FunctionCallExpression : public Expression {
private:
    FunctionCall* m_FunctionCall;
public:
    FunctionCallExpression (FunctionCall* p_FunctionCall) : Expression(), m_FunctionCall(p_FunctionCall) {  }
    ~FunctionCallExpression () { delete m_FunctionCall; }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	return m_FunctionCall->eval(r, posFactory, evaluator);
    }
    virtual bool operator== (const Expression& ref) const {
	const FunctionCallExpression* pref = dynamic_cast<const FunctionCallExpression*>(&ref);
	return pref == NULL ? false : *m_FunctionCall == *pref->m_FunctionCall;
    }
};

/* Expressions */
/* Logical connectives: or and */
class UnaryExpression : public Expression {
protected:
    const Expression* m_Expression;
public:
    UnaryExpression (const Expression* p_Expression) : Expression(), m_Expression(p_Expression) {  }
    ~UnaryExpression () { delete m_Expression; }
    virtual const char* getUnaryOperator() = 0;
};
class NaryExpression : public Expression {
protected:
    ProductionVector<const Expression*> m_Expressions;
public:
    NaryExpression (ProductionVector<const Expression*>* p_Expressions) : Expression(), m_Expressions(*p_Expressions) {  }
    NaryExpression (const Expression* p_Expression, ProductionVector<const Expression*>* p_Expressions) : Expression(), m_Expressions() {
	m_Expressions.push_back(p_Expression);
	for (std::vector<const Expression*>::iterator it = p_Expressions->begin();
	     it != p_Expressions->end(); ++it)
	    m_Expressions.push_back(*it);
    }
    bool operator== (const NaryExpression& ref) const {
	if (m_Expressions.size() != ref.m_Expressions.size())
	    return false;
	std::vector<const Expression*>::const_iterator mit = m_Expressions.begin();
	std::vector<const Expression*>::const_iterator rit = ref.m_Expressions.begin();
	for ( ; mit != m_Expressions.end(); ++mit, ++rit)
	    if ( !(**mit == **rit) )
		return false;
	return true;
    }
    virtual const char* getInfixNotation() = 0;
};
class BooleanJunction : public NaryExpression {
public:
    BooleanJunction (ProductionVector<const Expression*>* p_Expressions) : NaryExpression(p_Expressions) { }
    BooleanJunction (const Expression* p_Expression, ProductionVector<const Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) { }
};
class BooleanConjunction : public BooleanJunction { // ⋀
public:
    BooleanConjunction (ProductionVector<const Expression*>* p_Expressions) : BooleanJunction(p_Expressions) {  }
    BooleanConjunction (const Expression* p_Expression, ProductionVector<const Expression*>* p_Expressions) : BooleanJunction(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "&&"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	SafeEvaluationError lastError("no error");
	int errorCount = 0;
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin(); it != m_Expressions.end(); ++it) {
	    try {
		const POS* ret = posFactory->ebv((*it)->eval(r, posFactory, evaluator));
		if (ret != posFactory->getTrue())
		    return ret;
	    } catch (SafeEvaluationError& e) {
		lastError = e;
		++errorCount;
	    }
	}
	if (errorCount > 0)
	    throw lastError;
	return posFactory->getTrue();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanConjunction* pref = dynamic_cast<const BooleanConjunction*>(&ref);
	return pref == NULL ? false : NaryExpression::operator==(*pref);
    }
};
class BooleanDisjunction : public BooleanJunction { // ⋁
public:
    BooleanDisjunction (ProductionVector<const Expression*>* p_Expressions) : BooleanJunction(p_Expressions) {  }
    BooleanDisjunction (const Expression* p_Expression, ProductionVector<const Expression*>* p_Expressions) : BooleanJunction(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "||"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	SafeEvaluationError lastError("no error");
	int errorCount = 0;
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin(); it != m_Expressions.end(); ++it) {
	    try {
		const POS* ret = posFactory->ebv((*it)->eval(r, posFactory, evaluator));
		if (ret != posFactory->getFalse())
		    return ret;
	    } catch (SafeEvaluationError& e) {
		lastError = e;
		++errorCount;
	    }
	}
	if (errorCount > 0)
	    throw lastError;
	return posFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanConjunction* pref = dynamic_cast<const BooleanConjunction*>(&ref);
	return pref == NULL ? false : NaryExpression::operator==(*pref);
    }
};

class BooleanComparator : public Expression {
protected:
    const Expression* left;
    const Expression* right;
public:
    BooleanComparator (const Expression* p_Expression) : Expression(), right(p_Expression) {  }
    BooleanComparator (const Expression* left, const Expression* right) : Expression(), left(left), right(right) {  }
    ~BooleanComparator () { delete left; delete right; }
    virtual void setLeftParm (const Expression* p_left) { left = p_left; }

    virtual const char* getComparisonNotation() = 0;
    virtual void express(Expressor* p_expressor) const = 0;
};
class BooleanEQ : public BooleanComparator {
public:
    BooleanEQ (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    BooleanEQ (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
    virtual const char* getComparisonNotation () { return "="; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* l = left->eval(res, posFactory, evaluator);
	const POS* r = right->eval(res, posFactory, evaluator);
	return l == r || posFactory->cmp(l, r) == 0 ? posFactory->getTrue() : posFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanEQ* pref = dynamic_cast<const BooleanEQ*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class BooleanNE : public BooleanComparator {
public:
    BooleanNE (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "!="; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* l = left->eval(res, posFactory, evaluator);
	const POS* r = right->eval(res, posFactory, evaluator);
	return l == r || posFactory->cmp(l, r) == 0 ? posFactory->getFalse() : posFactory->getTrue();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanNE* pref = dynamic_cast<const BooleanNE*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class BooleanLT : public BooleanComparator {
public:
    BooleanLT (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "<"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* l = left->eval(res, posFactory, evaluator);
	const POS* r = right->eval(res, posFactory, evaluator);
	return posFactory->cmp(l, r) < 0 ? posFactory->getTrue() : posFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanLT* pref = dynamic_cast<const BooleanLT*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class BooleanGT : public BooleanComparator {
public:
    BooleanGT (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return ">"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* l = left->eval(res, posFactory, evaluator);
	const POS* r = right->eval(res, posFactory, evaluator);
	return posFactory->cmp(l, r) > 0 ? posFactory->getTrue() : posFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanGT* pref = dynamic_cast<const BooleanGT*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class BooleanLE : public BooleanComparator {
public:
    BooleanLE (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "<="; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* l = left->eval(res, posFactory, evaluator);
	const POS* r = right->eval(res, posFactory, evaluator);
	return posFactory->cmp(l, r) <= 0 ? posFactory->getTrue() : posFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanLE* pref = dynamic_cast<const BooleanLE*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class BooleanGE : public BooleanComparator {
public:
    BooleanGE (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return ">="; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* l = left->eval(res, posFactory, evaluator);
	const POS* r = right->eval(res, posFactory, evaluator);
	return posFactory->cmp(l, r) >= 0 ? posFactory->getTrue() : posFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanGE* pref = dynamic_cast<const BooleanGE*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class ComparatorExpression : public Expression {
private:
    const BooleanComparator* m_BooleanComparator;
public:
    ComparatorExpression (const BooleanComparator* p_BooleanComparator) : Expression(), m_BooleanComparator(p_BooleanComparator) {  }
    ~ComparatorExpression () { delete m_BooleanComparator; }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	return m_BooleanComparator->eval(r, posFactory, evaluator);
    }
    virtual bool operator== (const Expression& ref) const {
	const ComparatorExpression* pref = dynamic_cast<const ComparatorExpression*>(&ref);
	return pref == NULL ? false : *m_BooleanComparator == *pref->m_BooleanComparator;
    }
};
class BooleanNegation : public UnaryExpression {
public:
    BooleanNegation (const Expression* p_PrimaryExpression) : UnaryExpression(p_PrimaryExpression) {  }
    ~BooleanNegation () {  }
    virtual const char* getUnaryOperator () { return "!"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	const POS* v = posFactory->ebv(m_Expression->eval(res, posFactory, evaluator));
	return v == posFactory->getTrue() ? posFactory->getFalse() : posFactory->getTrue();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanNegation* pref = dynamic_cast<const BooleanNegation*>(&ref);
	return pref == NULL ? false : *m_Expression == *pref->m_Expression;
    }
};
class ArithmeticSum : public NaryExpression {
public:
    ArithmeticSum (ProductionVector<const Expression*>* p_Expressions) : NaryExpression(p_Expressions) {  }
    ArithmeticSum (const Expression* p_Expression, ProductionVector<const Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "+"; };    
    virtual void express(Expressor* p_expressor) const;
    struct NaryAdder : public POSFactory::NaryFunctor {
	/* Do not place in eval() per http://www.eggheadcafe.com/conversation.aspx?messageid=32706692&threadid=32706692 */
	NaryAdder (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) : 
	    POSFactory::NaryFunctor(res, posFactory, evaluator) {  }
	virtual int eval (int l, int r) { return l + r; }
	virtual float eval (float l, float r) { return l + r; }
	virtual double eval (double l, double r) { return l + r; }
    };
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	NaryAdder f(res, posFactory, evaluator);
	return posFactory->applyCommonNumeric(std::vector<const Expression*>(m_Expressions.begin(), m_Expressions.end()), &f);
    }
    virtual bool operator== (const Expression& ref) const {
	const ArithmeticSum* pref = dynamic_cast<const ArithmeticSum*>(&ref);
	return pref == NULL ? false : NaryExpression::operator==(*pref);
    }
};
class ArithmeticNegation : public UnaryExpression {
public:
    ArithmeticNegation (const Expression* p_MultiplicativeExpression) : UnaryExpression(p_MultiplicativeExpression) {  }
    ~ArithmeticNegation () {  }
    virtual const char* getUnaryOperator () { return "-"; };
    virtual void express(Expressor* p_expressor) const;
    struct UnaryNegator : public POSFactory::UnaryFunctor {
	/* Do not place in eval() per http://www.eggheadcafe.com/conversation.aspx?messageid=32706692&threadid=32706692 */
	UnaryNegator (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) : 
	    POSFactory::UnaryFunctor(res, posFactory, evaluator) {  }
	virtual int eval (int v) { return -v; }
	virtual float eval (float v) { return -v; }
	virtual double eval (double v) { return -v; }
    };
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	UnaryNegator f(res, posFactory, evaluator);
	return posFactory->applyCommonNumeric(m_Expression, &f);
    }
    virtual bool operator== (const Expression& ref) const {
	const ArithmeticNegation* pref = dynamic_cast<const ArithmeticNegation*>(&ref);
	return pref == NULL ? false : *m_Expression == *pref->m_Expression;
    }
};
class NumberExpression : public Expression {
private:
    const NumericRDFLiteral* m_NumericRDFLiteral;
public:
    NumberExpression (const NumericRDFLiteral* p_NumericRDFLiteral) : Expression(), m_NumericRDFLiteral(p_NumericRDFLiteral) {  }
    ~NumberExpression () { /* m_NumericRDFLiteral is centrally managed */ }
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* /* posFactory */, BNodeEvaluator* evaluator) const {
	return m_NumericRDFLiteral->evalPOS(res, evaluator);
    }
    virtual bool operator== (const Expression& ref) const {
	const NumberExpression* pref = dynamic_cast<const NumberExpression*>(&ref);
	return pref == NULL ? false : m_NumericRDFLiteral == pref->m_NumericRDFLiteral;
    }
};
class ArithmeticProduct : public NaryExpression {
public:
    ArithmeticProduct (ProductionVector<const Expression*>* p_Expressions) : NaryExpression(p_Expressions) {  }
    ArithmeticProduct (const Expression* p_Expression, ProductionVector<const Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "+"; };    
    virtual void express(Expressor* p_expressor) const;
    struct NaryMultiplier : public POSFactory::NaryFunctor {
	/* Do not place in eval() per http://www.eggheadcafe.com/conversation.aspx?messageid=32706692&threadid=32706692 */
	NaryMultiplier (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) : 
	    POSFactory::NaryFunctor(res, posFactory, evaluator) {  }
	virtual int eval (int l, int r) { return l * r; }
	virtual float eval (float l, float r) { return l * r; }
	virtual double eval (double l, double r) { return l * r; }
    };
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	NaryMultiplier f(res, posFactory, evaluator);
	return posFactory->applyCommonNumeric(std::vector<const Expression*>(m_Expressions.begin(), m_Expressions.end()), &f);
    }
    virtual bool operator== (const Expression& ref) const {
	const ArithmeticProduct* pref = dynamic_cast<const ArithmeticProduct*>(&ref);
	return pref == NULL ? false : NaryExpression::operator==(*pref);
    }
};
class ArithmeticInverse : public UnaryExpression {
public:
    ArithmeticInverse (const Expression* p_UnaryExpression) : UnaryExpression(p_UnaryExpression) {  }
    ~ArithmeticInverse () {  }
    virtual const char* getUnaryOperator () { return "1/"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const POS* eval (const Result* res, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	std::stringstream s;
	s << "(/ 1 " << m_Expression->eval(res, posFactory, evaluator) <<
	    ')' << " not implemented";
	throw s.str();
    }
    virtual bool operator== (const Expression& ref) const {
	const ArithmeticInverse* pref = dynamic_cast<const ArithmeticInverse*>(&ref);
	return pref == NULL ? false : *m_Expression == *pref->m_Expression;
    }
};

} // namespace w3c_sw
/* END ClassBlock */
#include <iostream>
namespace libwww {

/* URI parsing stuff stolen from libwww
 *
 */
class DummyHTURI {
private:
public:
    DummyHTURI () {  }
    virtual ~DummyHTURI () {  }
    virtual bool hasScheme () { return false; }
    virtual std::string getScheme () { throw(std::runtime_error("illegal call to DummyHTURI::getScheme")); }
    virtual void clearScheme () { throw(std::runtime_error("illegal call to DummyHTURI::clearScheme")); }
    virtual bool hasHost () { return false; }
    virtual std::string getHost () { throw(std::runtime_error("illegal call to DummyHTURI::getHost")); }
    virtual void clearHost () { throw(std::runtime_error("illegal call to DummyHTURI::clearHost")); }
    virtual bool hasAbsolute () { return false; }
    virtual std::string getAbsolute () { throw(std::runtime_error("illegal call to DummyHTURI::getAbsolute")); }
    virtual void clearAbsolute () { throw(std::runtime_error("illegal call to DummyHTURI::clearAbsolute")); }
    virtual bool hasRelative () { return false; }
    virtual std::string getRelative () { throw(std::runtime_error("illegal call to DummyHTURI::getRelative")); }
    virtual void clearRelative () { throw(std::runtime_error("illegal call to DummyHTURI::clearRelative")); }
    virtual bool hasFragment () { return false; }
    virtual std::string getFragment () { throw(std::runtime_error("illegal call to DummyHTURI::getFragment")); }
    virtual void clearFragment () { throw(std::runtime_error("illegal call to DummyHTURI::clearFragment")); }
};
class HTURI : public DummyHTURI {
private:
    std::string scheme;   bool schemeP;
    std::string host;	  bool hostP;
    std::string absolute; bool absoluteP;
    std::string relative; bool relativeP;
    std::string fragment; bool fragmentP;
public:
    HTURI(std::string);
    virtual bool hasScheme () { return schemeP; }
    virtual std::string getScheme () { return scheme; }
    virtual void clearScheme () { scheme.clear(); schemeP = false; }
    virtual bool hasHost () { return hostP; }
    virtual std::string getHost () { return host; }
    virtual void clearHost () { host.clear(); hostP = false; }
    virtual bool hasAbsolute () { return absoluteP; }
    virtual std::string getAbsolute () { return absolute; }
    virtual void clearAbsolute () { absolute.clear(); absoluteP = false; }
    virtual bool hasRelative () { return relativeP; }
    virtual std::string getRelative () { return relative; }
    virtual void clearRelative () { relative.clear(); relativeP = false; }
    virtual bool hasFragment () { return fragmentP; }
    virtual std::string getFragment () { return fragment; }
    virtual void clearFragment () { fragment.clear(); fragmentP = false; }
};
typedef enum {
    PARSE_scheme =		16,	/* Access scheme, e.g. "HTTP" */
    PARSE_host =		 8,	/* Host name, e.g. "www.w3.org" */
    PARSE_path =		 4,	/* URL Path, e.g. "pub/WWW/TheProject.html" */

    PARSE_view =                 2,      /* Fragment identifier, e.g. "news" */
    PARSE_fragment =             PARSE_view,
    PARSE_anchor =		 PARSE_view,

    PARSE_punctuation =	         1,	/* Include delimiters, e.g, "/" and ":" */
    PARSE_all =		        31
} e_PARSE_opts;

std::string HTParse(std::string name, const std::string* rel, e_PARSE_opts wanted);

} // namespace libwww

namespace w3c_sw {

class SWWEBagent;
struct StreamContext {
    typedef enum {
	NONE =		0,	/* don't do nuthin */
	STRING =	1,	/* nameStr is the contents */
	STDIN =		2,	/* '-' means stdin */
	STDOUT =	2,	/* '-' also means stdout */
	FILE =		4,	/* must be a file */
    } e_opts;
    std::string nameStr;
    MediaType mediaType;
    bool malloced;

    StreamContext (std::string nameStr) : nameStr(nameStr) {  }

    static MediaTypeMap MediaTypes;

    void guessMediaType () {
	size_t dot = nameStr.find_last_of('.');
	if (dot != std::string::npos) {
	    const std::string sub(nameStr.substr(dot+1, nameStr.size()));
	    MediaTypeMap::const_iterator it = MediaTypes.find(sub);
	    if (it != MediaTypes.end())
		mediaType = it->second;
	}
    }
};

struct IStreamContext : public StreamContext {
    std::istream* p;
    IStreamContext(std::string nameStr, e_opts = NONE,
	       SWWEBagent* webAgent = NULL, std::ostream** debugStream = NULL);
    ~IStreamContext () { if (malloced) delete p; }
    std::istream& operator* () { return *p; }

};

struct OStreamContext : public StreamContext {
    std::ostream* p;
    bool malloced;
    OStreamContext(std::string nameStr, const char* p_mediaType = NULL, e_opts = NONE,
	      SWWEBagent* webAgent = NULL, std::ostream** debugStream = NULL);
    ~OStreamContext();
    std::ostream& operator* () { return *p; }
};

class NamespaceMap {
protected:
    std::map<std::string, const URI*> ns;
public:

    struct UnknownPrefixException : StringException {
	std::string prefix;
	UnknownPrefixException (std::string prefix) : 
	    StringException(make(prefix)), prefix(prefix) {  }
	virtual ~UnknownPrefixException () throw() {  }
    protected:
	std::string make (std::string prefix) {
	    std::stringstream s;
	    s << "unknown prefix \"" << prefix << "\"";
	    return s.str();
	}
    };

    virtual ~NamespaceMap () {  }
    virtual void clear () { ns.clear(); }
    // const URI*& operator[] (std::string prefix) { return ns[prefix]; }
    virtual const URI* get (std::string prefix, bool returnNull = false) {
	NamespaceMap::const_iterator vi = ns.find(prefix);
	if (vi == ns.end()) {
	    if (returnNull)
		return NULL;
	    NamespaceMap::UnknownPrefixException e(prefix);
	    throw(e);
	} else
	    return vi->second;
    }
    virtual void set (std::string prefix, const URI* uri) { ns[prefix] = uri; }
    virtual std::string unmap (std::string mapped);

    typedef std::map<std::string, const URI*>::iterator iterator;
    typedef std::map<std::string, const URI*>::const_iterator const_iterator;

    iterator begin () { return ns.begin(); }
    const_iterator begin () const { return ns.begin(); }
    iterator end () { return ns.end(); }
    const_iterator end () const { return ns.end(); }
    iterator find (std::string prefix) { return ns.find(prefix); }

};

class Expressor {
public:
    virtual ~Expressor () {  }

    virtual void base(const Base* const self, std::string productionName) = 0;

    virtual void uri(const URI* const self, std::string lexicalValue) = 0;
    virtual void variable(const Variable* const self, std::string lexicalValue) = 0;
    virtual void bnode(const BNode* const self, std::string lexicalValue) = 0;
    virtual void rdfLiteral(const RDFLiteral* const self, std::string lexicalValue, const URI* datatype, LANGTAG* p_LANGTAG) = 0;
    virtual void rdfLiteral(const NumericRDFLiteral* const self, int p_value) = 0;
    virtual void rdfLiteral(const NumericRDFLiteral* const self, float p_value) = 0;
    virtual void rdfLiteral(const NumericRDFLiteral* const self, double p_value) = 0;
    virtual void rdfLiteral(const BooleanRDFLiteral* const self, bool p_value) = 0;
    virtual void nullpos(const NULLpos* const self) = 0;
    virtual void triplePattern(const TriplePattern* const self, const POS* p_s, const POS* p_p, const POS* p_o) = 0;
    virtual void filter(const Filter* const self, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) = 0;
    virtual void namedGraphPattern(const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
    virtual void defaultGraphPattern(const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
    virtual void tableConjunction(const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
    virtual void tableDisjunction(const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
    virtual void optionalGraphPattern(const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) = 0;
    virtual void graphGraphPattern(const GraphGraphPattern* const self, const POS* p_POS, const TableOperation* p_GroupGraphPattern) = 0;
    virtual void serviceGraphPattern(const ServiceGraphPattern* const self, const POS* p_POS, const TableOperation* p_GroupGraphPattern, POSFactory* posFactory, bool lexicalCompare) = 0;
    virtual void posList(const POSList* const self, const ProductionVector<const POS*>* p_POSs) = 0;
    virtual void starVarSet(const StarVarSet* const self) = 0;
    virtual void defaultGraphClause(const DefaultGraphClause* const self, const POS* p_IRIref) = 0;
    virtual void namedGraphClause(const NamedGraphClause* const self, const POS* p_IRIref) = 0;
    virtual void solutionModifier(const SolutionModifier* const self, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) = 0;
    virtual void binding(const Binding* const self, const ProductionVector<const POS*>* values) = 0;
    virtual void bindingClause(const BindingClause* const self, POSList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) = 0;
    virtual void whereClause(const WhereClause* const self, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) = 0;
    virtual void select(const Select* const self, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) = 0;
    virtual void construct(const Construct* const self, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) = 0;
    virtual void describe(const Describe* const self, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) = 0;
    virtual void ask(const Ask* const self, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) = 0;
    virtual void replace(const Replace* const self, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) = 0;
    virtual void insert(const Insert* const self, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) = 0;
    virtual void del(const Delete* const self, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) = 0;
    virtual void load(const Load* const self, ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) = 0;
    virtual void clear(const Clear* const self, const URI* p__QGraphIRI_E_Opt) = 0;
    virtual void create(const Create* const self, e_Silence p_Silence, const URI* p_GraphIRI) = 0;
    virtual void drop(const Drop* const self, e_Silence p_Silence, const URI* p_GraphIRI) = 0;
    virtual void posExpression(const POSExpression* const self, const POS* p_POS) = 0;
    virtual void argList(const ArgList* const self, ProductionVector<const Expression*>* expressions) = 0;
    virtual void functionCall(const FunctionCall* const self, const URI* p_IRIref, const ArgList* p_ArgList) = 0;
    virtual void functionCallExpression(const FunctionCallExpression* const self, FunctionCall* p_FunctionCall) = 0;
/* Expressions */
    virtual void booleanNegation(const BooleanNegation* const self, const Expression* p_Expression) = 0;
    virtual void arithmeticNegation(const ArithmeticNegation* const self, const Expression* p_Expression) = 0;
    virtual void arithmeticInverse(const ArithmeticInverse* const self, const Expression* p_Expression) = 0;
    virtual void booleanConjunction(const BooleanConjunction* const self, const ProductionVector<const Expression*>* p_Expressions) = 0;
    virtual void booleanDisjunction(const BooleanDisjunction* const self, const ProductionVector<const Expression*>* p_Expressions) = 0;
    virtual void arithmeticSum(const ArithmeticSum* const self, const ProductionVector<const Expression*>* p_Expressions) = 0;
    virtual void arithmeticProduct(const ArithmeticProduct* const self, const ProductionVector<const Expression*>* p_Expressions) = 0;
    virtual void booleanEQ(const BooleanEQ* const self, const Expression* p_left, const Expression* p_right) = 0;
    virtual void booleanNE(const BooleanNE* const self, const Expression* p_left, const Expression* p_right) = 0;
    virtual void booleanLT(const BooleanLT* const self, const Expression* p_left, const Expression* p_right) = 0;
    virtual void booleanGT(const BooleanGT* const self, const Expression* p_left, const Expression* p_right) = 0;
    virtual void booleanLE(const BooleanLE* const self, const Expression* p_left, const Expression* p_right) = 0;
    virtual void booleanGE(const BooleanGE* const self, const Expression* p_left, const Expression* p_right) = 0;
    virtual void comparatorExpression(const ComparatorExpression* const self, const BooleanComparator* p_BooleanComparator) = 0;
    virtual void numberExpression(const NumberExpression* const self, const NumericRDFLiteral* p_NumericRDFLiteral) = 0;
};


/* ExpressorSerializer - provide a common str() interface.
 * Derive serializers (SPARQLSerializer, XMLQueryExpressor) from this.
 */
class ExpressorSerializer : public Expressor {
public:
    virtual std::string str() = 0;
};


/* RecursiveExpressor - default actions for expressor.
 * Use this Expressor when you don't feel like supplying all of the methods.
 */
class RecursiveExpressor : public Expressor {
public:
    virtual void uri (const URI* const, std::string) {  }
    virtual void variable (const Variable* const, std::string) {  }
    virtual void bnode (const BNode* const, std::string) {  }
    virtual void rdfLiteral (const RDFLiteral* const, std::string, const URI* datatype, LANGTAG* p_LANGTAG) {
	if (datatype) datatype->express(this);
	if (p_LANGTAG) p_LANGTAG->express(this);
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, int) {  }
    virtual void rdfLiteral (const NumericRDFLiteral* const, float) {  }
    virtual void rdfLiteral (const NumericRDFLiteral* const, double) {  }
    virtual void rdfLiteral (const BooleanRDFLiteral* const, bool) {  }
    virtual void nullpos (const NULLpos* const) {  }
    virtual void triplePattern (const TriplePattern* const, const POS* p_s, const POS* p_p, const POS* p_o) {
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
    }
    virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
	p_op->express(this);
	p_Constraints->express(this);
    }
    virtual void namedGraphPattern (const NamedGraphPattern* const, const POS* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	p_name->express(this);
	p_TriplePatterns->express(this);
    }
    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	p_TriplePatterns->express(this);
    }
    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	p_TableOperations->express(this);
    }
    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	p_TableOperations->express(this);
    }
    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
	p_GroupGraphPattern->express(this);
	p_Expressions->express(this);
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const, const POS* p_POS, const TableOperation* p_GroupGraphPattern) {
	p_POS->express(this);
	p_GroupGraphPattern->express(this);
    }
    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const POS* p_POS, const TableOperation* p_GroupGraphPattern, POSFactory* /* posFactory */, bool /* lexicalCompare */) {
	p_POS->express(this);
	p_GroupGraphPattern->express(this);
    }
    virtual void posList (const POSList* const, const ProductionVector<const POS*>* p_POSs) {
	p_POSs->express(this);
    }
    virtual void starVarSet (const StarVarSet* const) {  }
    virtual void defaultGraphClause (const DefaultGraphClause* const, const POS* p_IRIref) {
	p_IRIref->express(this);
    }
    virtual void namedGraphClause (const NamedGraphClause* const, const POS* p_IRIref) {
	p_IRIref->express(this);
    }
    virtual void solutionModifier (const SolutionModifier* const, std::vector<s_OrderConditionPair>* p_OrderConditions, int, int) {
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++)
		p_OrderConditions->at(i).expression->express(this);
    }
    virtual void binding (const Binding* const, const ProductionVector<const POS*>* values) {//!!!
	for (std::vector<const POS*>::const_iterator it = values->begin();
	     it != values->end(); ++it)
	    (*it)->express(this);
    }
    virtual void bindingClause (const BindingClause* const, POSList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) {
	p_Vars->express(this);
	p_Bindings->ProductionVector<const Binding*>::express(this);
    }
    virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
    }
    virtual void select (const Select* const, e_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void describe (const Describe* const, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
    }
    virtual void replace (const Replace* const, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
    }
    virtual void insert (const Insert* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
    }
    virtual void del (const Delete* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
    }
    virtual void load (const Load* const, ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) {
	p_IRIrefs->express(this);
	p_into->express(this);
    }
    virtual void clear (const Clear* const, const URI* p__QGraphIRI_E_Opt) {
	p__QGraphIRI_E_Opt->express(this);
    }
    virtual void create (const Create* const, e_Silence, const URI* p_GraphIRI) {
	p_GraphIRI->express(this);
    }
    virtual void drop (const Drop* const, e_Silence, const URI* p_GraphIRI) {
	p_GraphIRI->express(this);
    }
    virtual void posExpression (const POSExpression* const, const POS* p_POS) {
	p_POS->express(this);
    }
    virtual void argList (const ArgList* const, ProductionVector<const Expression*>* expressions) {
	expressions->express(this);
    }
    virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {
	p_IRIref->express(this);
	p_ArgList->express(this);
    }
    virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
    }
/* Expressions */
    virtual void booleanNegation (const BooleanNegation* const, const Expression* p_Expression) {
	p_Expression->express(this);
    }
    virtual void arithmeticNegation (const ArithmeticNegation* const, const Expression* p_Expression) {
	p_Expression->express(this);
    }
    virtual void arithmeticInverse (const ArithmeticInverse* const, const Expression* p_Expression) {
	p_Expression->express(this);
    }
    virtual void booleanConjunction (const BooleanConjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void arithmeticSum (const ArithmeticSum* const, const ProductionVector<const Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void arithmeticProduct (const ArithmeticProduct* const, const ProductionVector<const Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void arithmeticInverse (const ArithmeticInverse* const, ProductionVector<const Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void booleanEQ (const BooleanEQ* const, const Expression* p_left, const Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanNE (const BooleanNE* const, const Expression* p_left, const Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanLT (const BooleanLT* const, const Expression* p_left, const Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanGT (const BooleanGT* const, const Expression* p_left, const Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanLE (const BooleanLE* const, const Expression* p_left, const Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanGE (const BooleanGE* const, const Expression* p_left, const Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void comparatorExpression (const ComparatorExpression* const, const BooleanComparator* p_BooleanComparator) {
	p_BooleanComparator->express(this);
    }
    virtual void numberExpression (const NumberExpression* const, const NumericRDFLiteral* p_NumericRDFLiteral) {
	p_NumericRDFLiteral->express(this);
    }
};
class TestExpressor : public RecursiveExpressor {
    virtual void base (Base*, std::string) { throw(std::runtime_error("hit base in TestExpressor")); }
};

    std::ostream& operator<<(std::ostream& os, BasicGraphPattern const& my);
    std::ostream& operator<<(std::ostream& os, TableOperation const& my);
    std::ostream& operator<<(std::ostream& os, WhereClause const& my);

} //namespace w3c_sw



#endif /* ! defined SWOBJECTS_HH */
