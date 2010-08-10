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
 *     w3c_sw_LINE;
 *     w3c_sw_LINE << "about to foo the bar." << std::endl; // outputs your text.
 */
#define w3c_sw_STRINGIFY(x) #x
#define w3c_sw_TOSTRING(x) w3c_sw_STRINGIFY(x)
#define w3c_sw_LINE w3c_sw_LINEN << "LINE\n"
#define w3c_sw_LINEN std::cerr << __FILE__ "(" w3c_sw_TOSTRING(__LINE__) "): warning "
#define w3c_sw_NEED_IMPL(x) throw NotImplemented(__FILE__, w3c_sw_TOSTRING(__LINE__), x)
#define w3c_sw_IF_IMPL(t, x) if (t) {throw NotImplemented(__FILE__, w3c_sw_TOSTRING(__LINE__), x);}

#if NEED_iterStr
template<typename Iterated, class InputIterator>
std::string iterStr (InputIterator first, InputIterator last) {
    std::stringstream ss;
    std::ostream_iterator<Iterated> oi(ss, ", ");
    std::copy(first, last, oi);
    std::string ret(ss.str());
    return first == last ? ret : ret.substr(0, ret.size() - 2);
}
#endif /* NEED_iterStr */


/* defines for controlling includes from utils */
#include "config.h"

#ifdef _MSC_VER
  #define _WINSOCKAPI_	// Don't let windows include winsock.h .
  #include <windows.h>
  #undef _WINSOCKAPI_
  #undef max		// Disable rediculous max macro.
  #include <fcntl.h>
  #include <io.h>
  #include <sys/stat.h>

  #define POSIX_trunkwrite _O_WRONLY | _O_CREAT | _O_TRUNC

  #define POSIX_USER_RW _S_IREAD | _S_IWRITE

  #define POSIX_open ::_open
  #define POSIX_write ::_write
  #define POSIX_close ::_close
  #define POSIX_popen ::_popen
  #define POSIX_pclose ::_pclose
  #define POSIX_unlink ::_unlink
  #ifndef SWIG
    #define POSIX_cat "c:/cygwin/bin/cat"
  #endif
#else /* !_MSC_VER */
  #include <errno.h>

  #define POSIX_trunkwrite O_WRONLY | O_CREAT | O_TRUNC

  #define POSIX_USER_RW S_IRUSR | S_IWUSR

  #define POSIX_open ::open
  #define POSIX_write ::write
  #define POSIX_close ::close
  #define POSIX_popen ::popen
  #define POSIX_pclose ::pclose
  #define POSIX_unlink ::unlink
  #ifndef SWIG
    #define POSIX_cat "/bin/cat"
  #endif
#endif /* !_MSC_VER */

/* non-portable debug messages */
#ifdef _MSC_VER
  #define FUNCTION_STRING __FUNCSIG__ // __FUNCDNAME__ || __FUNCTION__ -- http://msdn.microsoft.com/en-us/library/b0084kay(VS.80).aspx

#else /* !_MSC_VER */
  #ifdef __GNUC__
    #ifndef SWIG
      #define FUNCTION_STRING __PRETTY_FUNCTION__
    #endif
  
  #else /* !__GNUC__ */
    #ifndef SWIG
      #define FUNCTION_STRING "define a function name macro"
    #endif
  
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

#if (!defined(_MSC_VER) || _MSC_VER >= 1500)
  #include <boost/optional.hpp>
#endif /* (!defined(_MSC_VER) || _MSC_VER >= 1500) */

#include <boost/iostreams/categories.hpp>  // source_tag

namespace w3c_sw {

#if defined(SWIG)
    %immutable;
#endif /* defined(SWIG) */
    extern const char* NS_xml;
    extern const char* NS_xsd;
    extern const char* NS_rdf;
    extern const char* NS_rdfs;
    extern const char* NS_srx;
    extern const char* NS_dc;
    extern const char* NS_sadl;
#if defined(SWIG)
    %mutable;
#endif /* defined(SWIG) */

class StringException : public std::exception {
public:
#if defined(SWIG)
    %immutable;
#endif /* defined(SWIG) */
    char const* str;
#if defined(SWIG)
    %mutable;
#endif /* defined(SWIG) */
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
    std::string brief;
    NotImplemented (std::string msg)
	: SafeEvaluationError(msg + " not implemented"), brief(msg)
    {  }
    NotImplemented (std::string file, std::string line, std::string msg)
	: SafeEvaluationError(file + "(" + line + "): error " + msg + " not implemented"), brief(msg)
    {  }
    virtual ~NotImplemented () throw() {   }
    char const* what() const throw() { return msg.c_str(); }
};

class TypeError : public SafeEvaluationError {
public:
    TypeError (std::string type, std::string context) : SafeEvaluationError(type + " not expected in " + context) {  }
    virtual ~TypeError () throw() {   }
    char const* what() const throw() { 	return msg.c_str(); }
};

#if defined SWIG
class OptString {  };
#elif (defined(_MSC_VER) && _MSC_VER < 15000)
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
#endif /* !(defined(_MSC_VER) && _MSC_VER < 1500) */

class MediaType : public OptString {
public:
    MediaType ()
	: OptString(NULL, std::string("-no media type-")) {  }
    MediaType (const char* p_str)
	: OptString(p_str, std::string("-no media type-")) {  }
    MediaType (std::string p_str)
	: OptString(p_str.c_str(), std::string("-no media type-")) {  }
//     void operator= (const char* p_str) {
// 	assign(p_str);
//     }
};

struct MediaTypeMap : public std::map<const std::string, const char*> {
    typedef std::map<const std::string, const char*>::const_iterator const_iterator;
    typedef std::pair<const std::string, const char*> pair;
    MediaTypeMap () {
	insert(pair("html", "text/html"));
	insert(pair("rdf" , "text/rdf+xml"));
	insert(pair("xml" , "text/rdf+xml"));
	insert(pair("nt" ,  "text/ntriples"));
	insert(pair("ttl" , "text/turtle"));
	insert(pair("trig", "text/trig"));
	insert(pair("srx" , "application/sparql-results+xml"));
	insert(pair("srt" , "text/sparql-results"));
	insert(pair("rq"  , "text/sparql-query"));
    }
};

class Expressor;

class Base {
public:
    Base () { }
    virtual ~Base() { }
    virtual void express(Expressor* p_expressor) const;
};


/* ptrequal == algorithm to test equivalence of ptr iteratables. */
template<typename LEFT, typename RIGHT>
inline bool ptrequal(LEFT lit, LEFT end, RIGHT rit) {
    for (; lit != end; ++lit, ++rit)
	if (!(**lit == **rit))
	    return false;
    return true;
}

/* Vector implementing Base. */
template <typename T> struct VectorOps {
  template<typename U> 
  static bool cmp(U a, U b) { return *a == *b; }
};
template <typename T> struct VectorOps<T*> {
  template<typename U> 
  static bool cmp(U a, U b) { return **a == **b; }
};

template <typename T> class ProductionVector : public Base {
protected:
    std::vector<T> data;
public:
    ProductionVector () {  }
    ProductionVector (typename std::vector<T>::const_iterator start,
		      typename std::vector<T>::const_iterator finish)
	: data(start, finish) {  }
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
	typename std::vector<T>::const_iterator mit = begin();
	typename std::vector<T>::const_iterator rit = ref.begin();
	for ( ; mit != end(); ++mit, ++rit)
	    if ( !(VectorOps<T>::cmp(mit, rit)) )
		return false;
	return true;
    }
#if 0
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
#endif
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
    virtual ResultSet* execute(RdfDB*, ResultSet* = NULL) const { throw(std::runtime_error(typeid(*this).name())); } // = 0?
    virtual bool operator==(const Operation& ref) const = 0;
    std::string toString() const;
};

class OperationSet : public Operation {
protected:
    ProductionVector<const Operation*> operations;
public:
    virtual void express(Expressor* /* p_expressor */) const;
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs) const;
    virtual bool operator== (const Operation& ref) const {
	const OperationSet* pref = dynamic_cast<const OperationSet*>(&ref);
	return pref == NULL ? false : operations == pref->operations;
    }
    std::string toString() const {
	std::stringstream ss;
	for (std::vector<const Operation*>::const_iterator it = operations.begin();
	     it != operations.end(); ++it) {
	    if (it != operations.begin())
		ss << " ;\n";
	    ss << (*it)->toString();
	}
	return ss.str();
    }
    void push_back(const Operation* op) {
	operations.push_back(op);
    }
};

class BNode;
class BNodeEvaluator;
class AtomFactory;

/* START Parts Of Speach */
class TTerm : public Terminal {
    friend struct POSsorter;
protected:
    TTerm (std::string matched) : Terminal(matched) {  }
    TTerm (std::string matched, bool gensym) : Terminal(matched, gensym) { }
    //    virtual int compareType (TTerm* to) = 0;
public:
    bool operator== (const TTerm& r) const { return this==&r; }
    virtual bool isConstant () const { return true; } // Override for variable types.
    static bool orderByType (const TTerm*, const TTerm*) { throw(std::runtime_error(FUNCTION_STRING)); }
    virtual int compare (TTerm* to, Result*) const {
	bool same = typeid(*to) == typeid(*this);
	return same ? getLexicalValue() != to->getLexicalValue() : orderByType(this, to);
    }
    virtual const TTerm* evalTTerm (const Result*, BNodeEvaluator* /* evaluator */) const { return this; }
    bool bindVariable (const TTerm* p, ResultSet* rs, Result* provisional, bool weaklyBound) const;
    virtual void express(Expressor* p_expressor) const = 0;
    virtual std::string getBindingAttributeName() const = 0;
    struct BNode2string : public std::map<const BNode*, std::string> {
	std::string getString(const BNode* bnode);
    };
    struct String2BNode : public std::map<std::string, const BNode*> {
	const BNode* getBNode(std::string bnode);
    };
    virtual std::string toXMLResults(BNode2string*) const = 0;
    virtual std::string toString() const = 0;
    std::string substitutedString (Result* row, BNodeEvaluator* evaluator) const {
	const TTerm* subd = evalTTerm(row, evaluator); /* re-uses atoms -- doesn't create them */
	if (subd != NULL)
	    return subd->toString();
	std::stringstream s;
	s << '[' << toString() << ']';
	return s.str();
    }
};

class URI : public TTerm {
    friend class AtomFactory;
private:
    URI (std::string str) : TTerm(str) {  }
public:
    ~URI () { }
    virtual const char * getToken () { return "-TTerm-"; }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string toXMLResults (BNode2string*) const { return std::string("<uri>") + terminal + "</uri>";  }
    virtual std::string toString () const { return std::string("<") + terminal + ">"; }
    virtual std::string getBindingAttributeName () const { return "uri"; }
    bool matches (std::string toMatch) const { return terminal == toMatch; } // !!! added for SPARQLSerializer::functionCall
};

class Bindable : public TTerm {
protected:
    Bindable (std::string str) : TTerm(str) {  }
    Bindable (std::string str, bool gensym) : TTerm(str, gensym) {  }
public:
    virtual bool isConstant () const { return false; }
};

class Variable : public Bindable {
    friend class AtomFactory;
private:
    Variable (std::string str) : Bindable(str) {  }
public:
    virtual std::string toXMLResults (TTerm::BNode2string*) const {
	return std::string("<variable>") + terminal + "</variable> <!-- should not appear in XML Results -->";
    }
    virtual std::string toString () const { std::stringstream s; s << "?" << terminal; return s.str(); }
    virtual const char * getToken () { return "-Variable-"; }
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* evalTTerm(const Result* r, BNodeEvaluator* evaluator) const;
    virtual std::string getBindingAttributeName () const { return "name"; }
};

class BNode;
class BNodeEvaluator {
    friend class BNode;
protected:
    virtual ~BNodeEvaluator () {  }
    virtual const TTerm* evaluate(const BNode* node, const Result* r) = 0;
};
class BNode : public Bindable {
    friend class AtomFactory;
private:
    BNode (std::string str) : Bindable(str) {  }
    BNode () : Bindable("b", true) {  }
public:
    virtual std::string toXMLResults (TTerm::BNode2string* map) const {
	return std::string("<bnode>") + map->getString(this) + "</bnode>";
    }
    virtual std::string toString () const { std::stringstream s; s << "_:" << terminal; return s.str(); }
    virtual const char * getToken () { return "-BNode-"; }
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* evalTTerm(const Result* r, BNodeEvaluator* evaluator) const;
    virtual std::string getBindingAttributeName () const { return "bnode"; }
};
inline std::string TTerm::BNode2string::getString (const BNode* bnode) {
    BNode2string::const_iterator it = find(bnode);
    if (it == end()) {
	std::stringstream s;
	s << size();
	it = insert(std::pair<const BNode*, std::string>(bnode, std::string("r") + s.str())).first;
    }
    return it->second;
}
inline const BNode* TTerm::String2BNode::getBNode (std::string str) {
    String2BNode::const_iterator it = find(str);
    if (it == end()) {
	return NULL;
	// std::stringstream s;
	// s << size();
	// it = insert(std::pair<std::string, const BNode*>(std::string("r") + s.str(), bnode)).first;
    }
    return it->second;
};

class RDFLiteral : public TTerm {
    friend class AtomFactory;
private:
    const URI* datatype;
    LANGTAG* m_LANGTAG;

protected:
    RDFLiteral (std::string p_String, const URI* p_URI, LANGTAG* p_LANGTAG) : TTerm(p_String) {
	datatype = p_URI;
	m_LANGTAG = p_LANGTAG;
    }

    ~RDFLiteral () {
	delete m_LANGTAG;
    }
public:
    const URI* getDatatype () const { return datatype; }
    const LANGTAG* getLangtag () const { return m_LANGTAG; }
    virtual std::string toXMLResults (TTerm::BNode2string*) const {
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
	// s << '"' << terminal << '"';
	s << '"';
	for (std::string::const_iterator it = terminal.begin();
	     it != terminal.end(); ++it)
	    if (*it == '\t')
		s << "\\t";
	    else if (*it == '\n')
		s << "\\n";
	    else if (*it == '\r')
		s << "\\r";
	    else if (*it == '\b')
		s << "\\b";
	    else if (*it == '\f')
		s << "\\f";
	    else if (*it == '\\')
		s << "\\\\";
	    else if (*it == '"')
		s << "\\\"";
	    else
		s << *it;
	s << '"';
	if (datatype) s << "^^" << datatype->toString();
	if (m_LANGTAG) s << "@" << m_LANGTAG->getLexicalValue();
	return s.str();
    }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string getBindingAttributeName () const { return "literal"; }
};
class CanonicalRDFLiteral : public RDFLiteral {
    friend class AtomFactory;
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
    friend class AtomFactory;
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
    friend class AtomFactory;
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
    friend class AtomFactory;
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
    friend class AtomFactory;
protected:
    DecimalRDFLiteral (std::string p_String, const URI* p_URI, float p_value) : FloatRDFLiteral(p_String, p_URI, p_value) {  }
public:
    virtual int getInt () const { throw TypeError(std::string("(decimal)") + toString(), "getInt()"); }
    virtual void express(Expressor* p_expressor) const;
};
class DoubleRDFLiteral : public NumericRDFLiteral {
    friend class AtomFactory;
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
    friend class AtomFactory;
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
class NULLtterm : public TTerm {
    friend class AtomFactory;
private:
    NULLtterm () : TTerm("NULL", "") {  }
    ~NULLtterm () {  }
public:
    virtual const char * getToken () { return "-NULL-"; }
    virtual std::string toXMLResults (TTerm::BNode2string*) const { return std::string("<null/> <!-- should not appear in XML Results -->"); }
    virtual std::string toString () const { std::stringstream s; s << "NULL"; return s.str(); }
    virtual void express(Expressor* p_expressor) const;
    virtual std::string getBindingAttributeName () const { throw(std::runtime_error(FUNCTION_STRING)); }
};

class BasicGraphPattern;
class NamespaceMap;

class TriplePattern : public Base {
    friend class AtomFactory;
private:
    const TTerm* m_s; const TTerm* m_p; const TTerm* m_o;
    bool weaklyBound;
    TriplePattern (const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) : Base(), m_s(p_s), m_p(p_p), m_o(p_o), weaklyBound(false) {  }
    TriplePattern (TriplePattern const& copy, bool weaklyBound) : Base(), m_s(copy.m_s), m_p(copy.m_p), m_o(copy.m_o), weaklyBound(weaklyBound) {  }
public:
    ~TriplePattern () {  }
    const TTerm* getS () const { return m_s; }
    const TTerm* getP () const { return m_p; }
    const TTerm* getO () const { return m_o; }
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
    bool bindVariables (const TriplePattern* tp, bool, ResultSet* rs, const TTerm* graphVar, Result* provisional, const TTerm* graphName) const {
	return
	    (graphVar == NULL || graphVar->bindVariable(graphName, rs, provisional, weaklyBound)) &&
	    m_p->bindVariable(tp->m_p, rs, provisional, weaklyBound) && 
	    m_s->bindVariable(tp->m_s, rs, provisional, weaklyBound) && 
	    m_o->bindVariable(tp->m_o, rs, provisional, weaklyBound);
    }
    bool construct(BasicGraphPattern* target, const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const;
};

class DefaultGraphPattern;
class Expression;
class AtomFactory {
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
    NULLtterm		nullTTerm;
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
    AtomFactory () :
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
    ~AtomFactory();
    const Variable* getVariable(std::string name);
    const BNode* createBNode();
    const BNode* getBNode(std::string name, TTerm::String2BNode& nodeMap);
    const URI* getURI(std::string name);
    const TTerm* getTTerm(std::string posStr, TTerm::String2BNode& nodeMap);
    const RDFLiteral* getRDFLiteral(std::string p_String, const URI* p_URI = NULL, LANGTAG* p_LANGTAG = NULL, bool validate = false);

    const IntegerRDFLiteral* getNumericRDFLiteral(std::string p_String, int p_value);
    const DecimalRDFLiteral* getNumericRDFLiteral(std::string p_String, float p_value);
    const FloatRDFLiteral* getNumericRDFLiteral(std::string p_String, float p_value, bool floatness);
    const DoubleRDFLiteral* getNumericRDFLiteral(std::string p_String, double p_value);

    const BooleanRDFLiteral* getBooleanRDFLiteral(std::string p_String, bool p_value);
    const BooleanRDFLiteral* getFalse () { return litFalse; }
    const BooleanRDFLiteral* getTrue () { return litTrue; }
    const NULLtterm* getNULL () { return &nullTTerm; }

    /* getTriple(s) interface: */
    const TriplePattern* getTriple (const TriplePattern* p, bool weaklyBound) {
	return getTriple(p->getS(), p->getP(), p->getO(), weaklyBound);
    }
    const TriplePattern* getTriple(const TTerm* s, const TTerm* p, const TTerm* o, bool weaklyBound = false);
    const TriplePattern* getTriple (std::string s, std::string p, std::string o, TTerm::String2BNode& nodeMap) {
	return getTriple(getTTerm(s, nodeMap), 
			 getTTerm(p, nodeMap), 
			 getTTerm(o, nodeMap), false);
    }
#if REGEX_LIB == SWOb_BOOST
    const TriplePattern* getTriple (std::string spo, TTerm::String2BNode& nodeMap) {
	const boost::regex expression("[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))[[:space:]]*\\.");
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	if (!regex_search(spo, what, expression, flags))
	    return NULL;
	return getTriple(getTTerm(std::string(what[1].first, what[1].second), nodeMap), 
			 getTTerm(std::string(what[2].first, what[2].second), nodeMap), 
			 getTTerm(std::string(what[3].first, what[3].second), nodeMap), false);
    }
#endif /* REGEX_LIB == SWOb_BOOST */
    void parseTriples (BasicGraphPattern* g, std::string spo, TTerm::String2BNode& nodeMap);

    /* EBV (Better place for this?) */
    const TTerm* ebv(const TTerm* tterm);

    struct Functor {
	const Result* res;
	AtomFactory* atomFactory;
	BNodeEvaluator* evaluator;

	Functor (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) : 
	    res(res), atomFactory(atomFactory), evaluator(evaluator) {  }
	virtual ~Functor () {  }
    };
    struct UnaryFunctor : public Functor {

	UnaryFunctor (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) : 
	    Functor(res, atomFactory, evaluator) {  }
	virtual int eval(int v) = 0;
	virtual float eval(float v) = 0;
	virtual double eval(double v) = 0;
    };
    struct NaryFunctor : public Functor {

	NaryFunctor (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) : 
	    Functor(res, atomFactory, evaluator) {  }
	virtual int eval(int l, int r) = 0;
	virtual float eval(float l, float r) = 0;
	virtual double eval(double l, double r) = 0;
    };
    const TTerm* applyCommonNumeric(const Expression* arg, UnaryFunctor* func);
    const TTerm* applyCommonNumeric(std::vector<const Expression*> args, NaryFunctor* func);

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
    int cmp (const TTerm* ltterm, const TTerm* rtterm) {
	/* Compare URIs lexically */
	const URI* luri = dynamic_cast<const URI*> (ltterm);
	const URI* ruri = dynamic_cast<const URI*> (rtterm);
	if (luri != NULL && ruri != NULL)
	    return luri->getLexicalValue().compare(ruri->getLexicalValue());

	/* Compare literals. */
	const RDFLiteral* l = dynamic_cast<const RDFLiteral*> (ltterm);
	const RDFLiteral* r = dynamic_cast<const RDFLiteral*> (rtterm);
	if (l == NULL || r == NULL)
	    throw TypeError(ltterm ? ltterm->toString() : "NULL", rtterm ? rtterm->toString() : "NULL");

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

    bool lessThan (const TTerm* lhs, const TTerm* rhs) {
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
    bool operator() (const TTerm* lhs, const TTerm* rhs) {
	const std::string lt = typeid(*lhs).name();
	const std::string rt = typeid(*rhs).name();
	const int li = typeOrder[lt];
	const int ri = typeOrder[rt];
	return
	    li < ri ? true : 
	    li > ri ? false : 
	    lhs->getLexicalValue().compare(rhs->getLexicalValue()) < 0;
    }
};

/* END Parts Of Speach */

class Expression : public Base {
private:
public:
    Expression () : Base() { }
    ~Expression () {  }
    virtual void express(Expressor* p_expressor) const = 0;
    virtual const TTerm* eval(const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const = 0;
    virtual bool operator==(const Expression&) const = 0;
};
typedef ProductionVector<const Expression*> ExprSet;

inline bool AtomFactory::eval (const Expression* expression, const Result* row) {
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
    TableJunction (std::vector<const TableOperation*>::const_iterator start,
		   std::vector<const TableOperation*>::const_iterator finish)
	: TableOperation(), m_TableOperations(start, finish) {  }

    bool operator== (const TableJunction& ref) const {
	return m_TableOperations == ref.m_TableOperations;
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
    TableConjunction (std::vector<const TableOperation*>::const_iterator start,
		      std::vector<const TableOperation*>::const_iterator finish)
	: TableJunction(start, finish) {  }

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
    TableDisjunction (std::vector<const TableOperation*>::const_iterator start,
		      std::vector<const TableOperation*>::const_iterator finish)
	: TableJunction(start, finish) {  }

    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const TableDisjunction* pref = dynamic_cast<const TableDisjunction*>(&ref);
	return pref == NULL ? false : TableJunction::operator==(*pref);
    }
    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual void construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("CONSTRUCT{{?s?p?o}UNION{?s?p?o}}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("DELETEPATTERN{{?s?p?o}UNION{?s?p?o}}");
    }
    virtual TableOperation* getDNF() const;
};
class BasicGraphPattern : public TableOperation { // ⊌⊍
    typedef std::multimap<const TTerm*, const TriplePattern*> idx_type;
    typedef std::pair<const TTerm*, const TriplePattern*> idx_pair;
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
    static const TTerm* _cOrN(const TTerm* tterm, const NULLtterm* n);
    /* wrapper function pushed into .cpp because RdfDB is incomplete. */
    void _bindVariables(RdfDB* db, ResultSet* rs, const TTerm* p_name) const;

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
    void bindVariables(ResultSet* rs, const TTerm* graphVar, const BasicGraphPattern* toMatch, const TTerm* graphName) const;
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
public:
    const TTerm* m_name;

    NamedGraphPattern (const TTerm* p_name, bool allOpts = false) : BasicGraphPattern(allOpts), m_name(p_name) {  }
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
	w3c_sw_NEED_IMPL("CONSTRUCT{FILTER(...)}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("DELETEPATTERN{FILTER(...)}");
    }
    virtual void express(Expressor* p_expressor) const;
    bool operator== (const Filter& ref) const {
	return *m_TableOperation == *ref.m_TableOperation
	    && m_Expressions == ref.m_Expressions;
    }
    bool operator== (const TableOperation& ref) const {
	const Filter* pref = dynamic_cast<const Filter*>(&ref);
	return pref == NULL ? false : operator==(*pref); // calls Filter-specific operator==
    }
    virtual TableOperationOnOperation* makeANewThis(const TableOperation* p_TableOperation) const;
};
/* GraphGraphPattern: pass-through class that's just used to reproduce verbatim SPARQL queries
 */
class GraphGraphPattern : public TableOperationOnOperation {
private:
    const TTerm* m_VarOrIRIref;
public:
    GraphGraphPattern (const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern), m_VarOrIRIref(p_TTerm) {  }
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
    const TTerm* m_VarOrIRIref;
    AtomFactory* atomFactory;
    bool lexicalCompare;
public:
    ServiceGraphPattern (const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) : 
	TableOperationOnOperation(p_GroupGraphPattern), 
	m_VarOrIRIref(p_TTerm), atomFactory(atomFactory), 
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
    virtual TableOperationOnOperation* makeANewThis (const TableOperation* p_TableOperation) const { return new ServiceGraphPattern(m_VarOrIRIref, p_TableOperation, atomFactory, lexicalCompare); }
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
	w3c_sw_NEED_IMPL("CONSTRUCT{OPTIONAL{?s?p?o}}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("DELETEPATTERN{OPTIONAL{?s?p?o}}");
    }
    virtual TableOperationOnOperation* makeANewThis (const TableOperation* p_TableOperation) const { return new OptionalGraphPattern(p_TableOperation); }

    void addExpression (const Expression* expression) {
	m_Expressions.push_back(expression);
    }
};
class MinusGraphPattern : public TableOperationOnOperation {
public:
    MinusGraphPattern (const TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern) {  }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const TableOperation& ref) const {
	const MinusGraphPattern* pref = dynamic_cast<const MinusGraphPattern*>(&ref);
	return pref == NULL ? false : 
	    *m_TableOperation == *pref->m_TableOperation;
    }
    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual void construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("CONSTRUCT{MINUS{?s?p?o}}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("DELETEPATTERN{MINUS{?s?p?o}}");
    }
    virtual TableOperationOnOperation* makeANewThis (const TableOperation* p_TableOperation) const { return new MinusGraphPattern(p_TableOperation); }

};

class ExpressionAliasList;
class VarSet : public Base {
protected:
    VarSet () : Base() { }
public:
    virtual void express(Expressor* p_expressor) const = 0;
    virtual bool operator==(const VarSet& ref) const = 0;
    virtual void project(ResultSet* rs, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having) const = 0;
};

class ExpressionAlias : public Base {
public:
    const Expression* expr;
    const Bindable* label;
public:
    ExpressionAlias (const Expression* expr) : expr(expr), label(NULL) {  }
    ExpressionAlias (const Expression* expr, const Bindable* label) : expr(expr), label(label) {  }
    ~ExpressionAlias () { delete expr; }
    // const Bindable* getLabel () const { return label; }
    virtual void express (Expressor* /* p_expressor */) const;
    virtual bool operator== (const ExpressionAlias& ref) const {
	return label == ref.label && *expr == *ref.expr;
    }
};
class ExpressionAliasList : public VarSet {
private:
    ProductionVector<const ExpressionAlias*> m_Expressions;
public:
    ExpressionAliasList () : VarSet(), m_Expressions() {  }
    // ExpressionAliasList (ProductionVector<const ExpressionAlias*> p_Expressions) : VarSet(), m_Expressions(p_Expressions) {  }
    ExpressionAliasList (const ExpressionAlias* expr) : VarSet(), m_Expressions(expr) {  }
    ~ExpressionAliasList () {  }
    void push_back(const ExpressionAlias* v) { m_Expressions.push_back(v); }
    virtual void express(Expressor* p_expressor) const;
    std::vector<const ExpressionAlias*>::iterator begin () { return m_Expressions.begin(); }
    std::vector<const ExpressionAlias*>::const_iterator begin () const { return m_Expressions.begin(); }
    std::vector<const ExpressionAlias*>::iterator end () { return m_Expressions.end(); }
    std::vector<const ExpressionAlias*>::const_iterator end () const { return m_Expressions.end(); }
    size_t size () const { return m_Expressions.size(); }
    virtual bool operator== (const VarSet& ref) const {
	const ExpressionAliasList* pref = dynamic_cast<const ExpressionAliasList*>(&ref);
	return pref == NULL ? false : m_Expressions == pref->m_Expressions;
    }
    virtual void project (ResultSet* rs, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having) const;
};
class StarVarSet : public VarSet {
private:
public:
    StarVarSet () : VarSet() {  }
    size_t size() { return 0; }
    TTerm* operator [] (size_t) { return NULL; }
    TTerm* getElement (size_t) { return NULL; }
    virtual void express(Expressor* p_expressor) const;
    virtual bool operator== (const VarSet& ref) const {
	const StarVarSet* pref = dynamic_cast<const StarVarSet*>(&ref);
	return pref == NULL ? false : true;
    }
    virtual void project (ResultSet* rs, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having) const;
};

class DatasetClause : public Base {
protected:
    const TTerm* m_IRIref;
    AtomFactory* m_atomFactory;
public:
    DatasetClause (const TTerm* p_IRIref, AtomFactory* p_atomFactory) : Base(), m_IRIref(p_IRIref), m_atomFactory(p_atomFactory) {  }
    ~DatasetClause () { /* m_IRIref is centrally managed */ }
    bool operator== (const DatasetClause& ref) const {
	const DatasetClause* pref = dynamic_cast<const DatasetClause*>(&ref);
	return pref == NULL ? false : m_IRIref == ref.m_IRIref && m_atomFactory == ref.m_atomFactory;
    }
    void loadGraph(RdfDB* db, const TTerm* name, BasicGraphPattern* target) const;
    virtual void loadData(RdfDB*) const = 0;
    virtual void express(Expressor* p_expressor) const = 0;
};
class DefaultGraphClause : public DatasetClause {
private:
public:
    DefaultGraphClause (const TTerm* p_IRIref, AtomFactory* p_atomFactory) : DatasetClause(p_IRIref, p_atomFactory) { }
    ~DefaultGraphClause () {  }
    virtual void express(Expressor* p_expressor) const;
    virtual void loadData(RdfDB*) const;
};
class NamedGraphClause : public DatasetClause {
private:
public:
    NamedGraphClause (const TTerm* p_IRIref, AtomFactory* p_atomFactory) : DatasetClause(p_IRIref, p_atomFactory) { }
    ~NamedGraphClause () {  }
    virtual void express(Expressor* p_expressor) const;
    virtual void loadData(RdfDB*) const;
};

    /* SolutionModifiers */
class Select;
class SolutionModifier : public Base {
    friend class Select;
private:
    ExpressionAliasList* groupBy;
    ProductionVector<const Expression*>* having;
    std::vector<s_OrderConditionPair>* m_OrderConditions;
public:
    int m_limit;
    int m_offset;
    SolutionModifier (ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset)
	: Base(), groupBy(groupBy), having(having), m_OrderConditions(p_OrderConditions), m_limit(p_limit), m_offset(p_offset)
    {  }
    ~SolutionModifier () {
	if (m_OrderConditions != NULL)
	    for (size_t i = 0; i < m_OrderConditions->size(); i++)
		delete m_OrderConditions->at(i).expression;
	delete m_OrderConditions;
	delete groupBy;
	delete having;
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

#if I_MAKE_m_OrderConditions_A_ProductionVector
	return m_limit == ref.m_limit
	    && m_offset == ref.m_offset
	    && ( (m_OrderConditions != NULL
		  && ref.m_OrderConditions != NULL
		  && *m_OrderConditions == *ref.m_OrderConditions)
		 || m_OrderConditions == ref.m_OrderConditions);
#endif
    }
};
class TTermList {
private:
    ProductionVector<const TTerm*> m_TTerms;
public:
    TTermList () : m_TTerms() {  }
    virtual ~TTermList () { m_TTerms.clear(); }
    void push_back(const TTerm* v) { m_TTerms.push_back(v); }
    virtual void express(Expressor* p_expressor) const;
    std::vector<const TTerm*>::iterator begin () { return m_TTerms.begin(); }
    std::vector<const TTerm*>::const_iterator begin () const { return m_TTerms.begin(); }
    std::vector<const TTerm*>::iterator end () { return m_TTerms.end(); }
    std::vector<const TTerm*>::const_iterator end () const { return m_TTerms.end(); }
    bool operator== (const VarSet& ref) const {
	const TTermList* pref = dynamic_cast<const TTermList*>(&ref);
	return pref == NULL ? false : m_TTerms == pref->m_TTerms;
    }
    // virtual void project (ResultSet* rs) const;
};

#if defined(SWIG)
    %template(ProductionVector_POSstar) ProductionVector<TTerm const *>;
#endif /* defined(SWIG) */
class Binding : public ProductionVector<const TTerm*> {
private:
public:
    Binding () : ProductionVector<const TTerm*>() {  }
    ~Binding () { clear(); /* atoms in vector are centrally managed */ }
    virtual void express(Expressor* p_expressor) const;
    void bindVariables(RdfDB* db, ResultSet* rs, Result* r, TTermList* p_Vars) const;
};
#if defined(SWIG)
    %template(ProductionVector_Bindingstar) ProductionVector<Binding const *>;
#endif /* defined(SWIG) */
class BindingClause : public ProductionVector<const Binding*> {
private:
    TTermList* m_Vars;
public:
    BindingClause (TTermList* p_Vars) : ProductionVector<const Binding*>(), m_Vars(p_Vars) {  }
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
class SubSelect : public TableOperation {
protected:
    const Select* m_Select;
public:
    SubSelect (const Select* p_Select) : TableOperation(), m_Select(p_Select) {  }
    ~SubSelect() { delete m_Select; }
    virtual void bindVariables(RdfDB*, ResultSet* rs) const;
    virtual TableOperation* getDNF () const {
	w3c_sw_NEED_IMPL("getDNF{SUBSELECT(...)}");
    }
    virtual void construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("CONSTRUCT{SUBSELECT(...)}");
    }
    virtual void deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	w3c_sw_NEED_IMPL("DELETEPATTERN{SUBSELECT(...)}");
    }
    virtual void express(Expressor* /* p_expressor */) const;
    bool operator== (const SubSelect& ref) const {
	return *m_Select == *ref.m_Select;
    }
    bool operator== (const TableOperation& ref) const {
	const SubSelect* pref = dynamic_cast<const SubSelect*>(&ref);
	return pref == NULL ? false : operator==(*pref); // calls SubSelect-specific operator==
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
class TTermExpression : public Expression {
private:
    const TTerm* m_TTerm;
public:
    TTermExpression (const TTerm* p_TTerm) : Expression(), m_TTerm(p_TTerm) {  }
    ~TTermExpression () { /* m_TTerm is centrally managed */ }
    const TTerm* getTTerm () const { return m_TTerm; }
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* eval (const Result* r, AtomFactory* /* atomFactory */, BNodeEvaluator* evaluator) const {
	return m_TTerm->evalTTerm(r, evaluator);
    }
    virtual bool operator== (const Expression& ref) const {
	const TTermExpression* pref = dynamic_cast<const TTermExpression*>(&ref);
	return pref == NULL ? false : m_TTerm == pref->m_TTerm;
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
    bool operator== (const ArgList& ref) const {
	return *expressions == *ref.expressions;
    }
    ArgIterator begin () const { return expressions->begin(); }
    ArgIterator end () const { return expressions->end(); }
    size_t size () const { return expressions->size(); }
    virtual void express(Expressor* p_expressor) const;
};
class FunctionCall : public Base {
protected:
    const URI* m_IRIref;
    const ArgList* m_ArgList;
public:
    FunctionCall (const URI* p_IRIref, const ArgList* p_ArgList) : Base(), m_IRIref(p_IRIref), m_ArgList(p_ArgList) {  }
    FunctionCall (const URI* p_IRIref, const Expression* arg1, const Expression* arg2, const Expression* arg3) : Base() {
	m_IRIref = p_IRIref;
	ProductionVector<const Expression*>* args = new ProductionVector<const Expression*>();
	if (arg1) args->push_back(arg1);
	if (arg2) args->push_back(arg2);
	if (arg3) args->push_back(arg3);
	m_ArgList = new ArgList(args);
    }
    ~FunctionCall () { delete m_ArgList; }
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	std::vector<const TTerm*> subd;
	for (ArgList::ArgIterator it = m_ArgList->begin(); it != m_ArgList->end(); ++it)
	    subd.push_back((*it)->eval(r, atomFactory, evaluator));

	/* Write down the first 3 for convenience. */
	std::vector<const TTerm*>::const_iterator it = subd.begin();
	const TTerm* first = it == subd.end() ? NULL : *it++;
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
		    return atomFactory->getRDFLiteral(first->getLexicalValue(), m_IRIref, NULL, true);
	    }
	}

	if (func == "http://www.w3.org/2001/XMLSchema#dateTime"   ) {
	    const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(first);
	    if (s != NULL) {
		const URI* dt = s->getDatatype();
		std::string dtl = dt ? dt->getLexicalValue() : ":noDT";
		if (dt == NULL || 
		    dtl == "http://www.w3.org/2001/XMLSchema#dateTime"  )// adjust
		    return atomFactory->getRDFLiteral(first->getLexicalValue(), m_IRIref, NULL, true);
	    }
	}

	if (func == "http://www.w3.org/2001/XMLSchema#string"   ) {
	    return atomFactory->getRDFLiteral(first->getLexicalValue(), m_IRIref, NULL, true);
	}

	/* operators */
	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound") && 
	    subd.size() == 1)
	    return first == NULL ? atomFactory->getFalse() : atomFactory->getTrue();

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI") && 
	    subd.size() == 1)
	    return dynamic_cast<const URI*>(first) == NULL ? atomFactory->getFalse() : atomFactory->getTrue();

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank") && 
	    subd.size() == 1)
	    return dynamic_cast<const BNode*>(first) == NULL ? atomFactory->getFalse() : atomFactory->getTrue();

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral") && 
	    subd.size() == 1)
	    return dynamic_cast<const RDFLiteral*>(first) == NULL ? atomFactory->getFalse() : atomFactory->getTrue();

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str") && // STR(RDFLiteral)
	    subd.size() == 1 && dynamic_cast<const RDFLiteral*>(first) != NULL)
	    return atomFactory->getRDFLiteral(first->getLexicalValue());

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str") && // STR(URI)
	    subd.size() == 1 && dynamic_cast<const URI*>(first) != NULL)
	    return atomFactory->getRDFLiteral(first->getLexicalValue());

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang") && 
	    subd.size() == 1 && dynamic_cast<const RDFLiteral*>(first) != NULL) {
	    const LANGTAG* t = dynamic_cast<const RDFLiteral*>(first)->getLangtag();
	    return atomFactory->getRDFLiteral(t ? t->getLexicalValue() : "");
	}

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype") && 
	    subd.size() == 1 && dynamic_cast<const RDFLiteral*>(first) != NULL && 
	    dynamic_cast<const RDFLiteral*>(first)->getLangtag() == NULL) {
	    const URI* dt = dynamic_cast<const RDFLiteral*>(first)->getDatatype();
	    return dt ? dt : atomFactory->getURI("http://www.w3.org/2001/XMLSchema#string");
	}

	const TTerm* second = it == subd.end() ? NULL : *it++;

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm") && 
	    subd.size() == 2) {
	    return first == second && first != NULL ? atomFactory->getTrue() : atomFactory->getFalse();
	}

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches") && 
	    subd.size() == 2 && 
	    dynamic_cast<const RDFLiteral*>(first) != NULL && 
	    dynamic_cast<const RDFLiteral*>(second) != NULL) {

	    /* knock off the easy ones... */
	    if (first == second)
		return atomFactory->getTrue();
	    std::string tag = dynamic_cast<const RDFLiteral*>(first)->getLexicalValue();
	    std::string range = dynamic_cast<const RDFLiteral*>(second)->getLexicalValue();
	    if (range == "*")
		return tag.empty() ? atomFactory->getFalse() : atomFactory->getTrue();

	    std::string::iterator t = tag.begin();
	    std::string::iterator te = tag.end();
	    std::string::iterator r = range.begin();
	    std::string::iterator re = range.end();

	    while (t != te && r != re)
		if (::tolower(*t++) != ::tolower(*r++))
		    return atomFactory->getFalse();

	    if (r == re && 
		(t == te || *t == '-'))
		return atomFactory->getTrue();

	    return atomFactory->getFalse();
	}

	const TTerm* third = it == subd.end() ? NULL : *it++;
	const RDFLiteral* firstLit = dynamic_cast<const RDFLiteral*>(first);
	const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(second);
	const RDFLiteral* thirdLit = dynamic_cast<const RDFLiteral*>(third);

	if (m_IRIref == atomFactory->getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex") && 
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
	    return regex_search(firstLit->getLexicalValue(), what, pattern, flags) ? atomFactory->getTrue() : atomFactory->getFalse();
#endif
	}

	std::stringstream s;
	s << m_IRIref->toString() << '(';
	for (std::vector<const TTerm*>::iterator it = subd.begin(); it != subd.end(); ++it) {
	    if (it != subd.begin())
		s << ", ";
	    if (*it)
		s << (*it)->toString();
	    else
		s << "NULL";
	}
	s << ')';
	w3c_sw_NEED_IMPL(s.str());
    }
    bool operator== (const FunctionCall& ref) const {
	return m_IRIref == ref.m_IRIref && *m_ArgList == *ref.m_ArgList;
	    return false;
    }
};
class AggregateCall : public FunctionCall {
private:
    e_distinctness distinctness;
public:
    AggregateCall (const URI* p_IRIref, e_distinctness distinctness, const Expression* arg1)
	: FunctionCall (p_IRIref, arg1, NULL, NULL), distinctness(distinctness) {  }
    ~AggregateCall () {  }
    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	if (distinctness == DIST_all)
	    return FunctionCall::eval(r, atomFactory, evaluator);
	std::stringstream s;
	s << m_IRIref->toString() << " DISTINCT " << '(';
	std::vector<const TTerm*> subd;
	for (ArgList::ArgIterator it = m_ArgList->begin(); it != m_ArgList->end(); ++it)
	    subd.push_back((*it)->eval(r, atomFactory, evaluator));
	for (std::vector<const TTerm*>::iterator it = subd.begin(); it != subd.end(); ++it) {
	    if (it != subd.begin())
		s << ", ";
	    if (*it)
		s << (*it)->toString();
	    else
		s << "NULL";
	}
	s << ')';
	w3c_sw_NEED_IMPL(s.str());
    }
    bool operator== (const AggregateCall& ref) const {
	if (distinctness != ref.distinctness)
	    return false;
	return this->FunctionCall::operator==(ref);
    }
};
class FunctionCallExpression : public Expression {
private:
    FunctionCall* m_FunctionCall;
public:
    FunctionCallExpression (FunctionCall* p_FunctionCall) : Expression(), m_FunctionCall(p_FunctionCall) {  }
    ~FunctionCallExpression () { delete m_FunctionCall; }
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	return m_FunctionCall->eval(r, atomFactory, evaluator);
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
	return m_Expressions == ref.m_Expressions;
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
    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	SafeEvaluationError lastError("no error");
	int errorCount = 0;
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin(); it != m_Expressions.end(); ++it) {
	    try {
		const TTerm* ret = atomFactory->ebv((*it)->eval(r, atomFactory, evaluator));
		if (ret != atomFactory->getTrue())
		    return ret;
	    } catch (SafeEvaluationError& e) {
		lastError = e;
		++errorCount;
	    }
	}
	if (errorCount > 0)
	    throw lastError;
	return atomFactory->getTrue();
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
    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	SafeEvaluationError lastError("no error");
	int errorCount = 0;
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin(); it != m_Expressions.end(); ++it) {
	    try {
		const TTerm* ret = atomFactory->ebv((*it)->eval(r, atomFactory, evaluator));
		if (ret != atomFactory->getFalse())
		    return ret;
	    } catch (SafeEvaluationError& e) {
		lastError = e;
		++errorCount;
	    }
	}
	if (errorCount > 0)
	    throw lastError;
	return atomFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanDisjunction* pref = dynamic_cast<const BooleanDisjunction*>(&ref);
	return pref == NULL ? false : NaryExpression::operator==(*pref);
    }
};

class GeneralComparator : public Expression {
protected:
    const Expression* left;
public:
    GeneralComparator () : Expression() {  }
    GeneralComparator (const Expression* left) : Expression(), left(left) {  }
    ~GeneralComparator () { delete left; }
    virtual void setLeftParm (const Expression* p_left) { left = p_left; }

    virtual const char* getComparisonNotation() = 0;
    virtual void express(Expressor* p_expressor) const = 0;
};
class BooleanComparator : public GeneralComparator {
protected:
    const Expression* right;
public:
    BooleanComparator (const Expression* p_Expression) : GeneralComparator(), right(p_Expression) {  }
    BooleanComparator (const Expression* left, const Expression* right) : GeneralComparator(left), right(right) {  }
    ~BooleanComparator () { delete right; }
    virtual void express(Expressor* p_expressor) const = 0;
};
class NaryComparator : public GeneralComparator {
protected:
    ProductionVector<const Expression*>* right;
public:
    NaryComparator (ProductionVector<const Expression*>* p_Expressions) : GeneralComparator(), right(p_Expressions) {  }
    NaryComparator (const Expression* left, ProductionVector<const Expression*>* right) : GeneralComparator(left), right(right) {  }
    ~NaryComparator () { delete right; }
    virtual void express(Expressor* p_expressor) const = 0;
};
class BooleanEQ : public BooleanComparator {
public:
    BooleanEQ (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    BooleanEQ (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
    virtual const char* getComparisonNotation () { return "="; };
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	const TTerm* r = right->eval(res, atomFactory, evaluator);
	return l == r || atomFactory->cmp(l, r) == 0 ? atomFactory->getTrue() : atomFactory->getFalse();
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
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	const TTerm* r = right->eval(res, atomFactory, evaluator);
	return l == r || atomFactory->cmp(l, r) == 0 ? atomFactory->getFalse() : atomFactory->getTrue();
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
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	const TTerm* r = right->eval(res, atomFactory, evaluator);
	return atomFactory->cmp(l, r) < 0 ? atomFactory->getTrue() : atomFactory->getFalse();
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
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	const TTerm* r = right->eval(res, atomFactory, evaluator);
	return atomFactory->cmp(l, r) > 0 ? atomFactory->getTrue() : atomFactory->getFalse();
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
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	const TTerm* r = right->eval(res, atomFactory, evaluator);
	return atomFactory->cmp(l, r) <= 0 ? atomFactory->getTrue() : atomFactory->getFalse();
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
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	const TTerm* r = right->eval(res, atomFactory, evaluator);
	return atomFactory->cmp(l, r) >= 0 ? atomFactory->getTrue() : atomFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const BooleanGE* pref = dynamic_cast<const BooleanGE*>(&ref);
	return pref == NULL ? false : *left == *pref->left && *right == *pref->right;
    }
};
class NaryIn : public NaryComparator {
protected:
public:
    NaryIn (ProductionVector<const Expression*>* p_Expressions) : NaryComparator(p_Expressions) {  }
    virtual const char* getComparisonNotation () { return "IN"; };
    virtual void express (Expressor* /* p_expressor */) const { w3c_sw_NEED_IMPL("NaryIn::express"); }
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	for (std::vector<const Expression*>::const_iterator exp = right->begin();
	     exp != right->end(); ++exp) {
	    const TTerm* r = (*exp)->eval(res, atomFactory, evaluator);
	    if (l == r)
	    // if (atomFactory->cmp(l, r) == 0)
		return atomFactory->getTrue();
	}
	return atomFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const NaryIn* pref = dynamic_cast<const NaryIn*>(&ref);
	return pref == NULL ? false : *right == *pref->right;
    }
};
class NaryNotIn : public NaryIn {
protected:
public:
    NaryNotIn (ProductionVector<const Expression*>* p_Expressions) : NaryIn(p_Expressions) {  }
    virtual const char* getComparisonNotation () { return "NOT IN"; };
    virtual void express (Expressor* /* p_expressor */) const { w3c_sw_NEED_IMPL("NaryNotIn::express"); }
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* l = left->eval(res, atomFactory, evaluator);
	for (std::vector<const Expression*>::const_iterator exp = right->begin();
	     exp != right->end(); ++exp) {
	    const TTerm* r = (*exp)->eval(res, atomFactory, evaluator);
	    if (l != r)
	    // if (atomFactory->cmp(l, r) != 0)
		return atomFactory->getTrue();
	}
	return atomFactory->getFalse();
    }
    virtual bool operator== (const Expression& ref) const {
	const NaryNotIn* pref = dynamic_cast<const NaryNotIn*>(&ref);
	return pref == NULL ? false : *right == *pref->right;
    }
};
class ComparatorExpression : public Expression {
private:
    const GeneralComparator* m_GeneralComparator;
public:
    ComparatorExpression (const GeneralComparator* p_GeneralComparator) : Expression(), m_GeneralComparator(p_GeneralComparator) {  }
    ~ComparatorExpression () { delete m_GeneralComparator; }
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	return m_GeneralComparator->eval(r, atomFactory, evaluator);
    }
    virtual bool operator== (const Expression& ref) const {
	const ComparatorExpression* pref = dynamic_cast<const ComparatorExpression*>(&ref);
	return pref == NULL ? false : *m_GeneralComparator == *pref->m_GeneralComparator;
    }
};
class BooleanNegation : public UnaryExpression {
public:
    BooleanNegation (const Expression* p_PrimaryExpression) : UnaryExpression(p_PrimaryExpression) {  }
    ~BooleanNegation () {  }
    virtual const char* getUnaryOperator () { return "!"; };
    virtual void express(Expressor* p_expressor) const;
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	const TTerm* v = atomFactory->ebv(m_Expression->eval(res, atomFactory, evaluator));
	return v == atomFactory->getTrue() ? atomFactory->getFalse() : atomFactory->getTrue();
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
    struct NaryAdder : public AtomFactory::NaryFunctor {
	/* Do not place in eval() per http://www.eggheadcafe.com/conversation.aspx?messageid=32706692&threadid=32706692 */
	NaryAdder (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) : 
	    AtomFactory::NaryFunctor(res, atomFactory, evaluator) {  }
	virtual int eval (int l, int r) { return l + r; }
	virtual float eval (float l, float r) { return l + r; }
	virtual double eval (double l, double r) { return l + r; }
    };
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	NaryAdder f(res, atomFactory, evaluator);
	return atomFactory->applyCommonNumeric(std::vector<const Expression*>(m_Expressions.begin(), m_Expressions.end()), &f);
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
    struct UnaryNegator : public AtomFactory::UnaryFunctor {
	/* Do not place in eval() per http://www.eggheadcafe.com/conversation.aspx?messageid=32706692&threadid=32706692 */
	UnaryNegator (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) : 
	    AtomFactory::UnaryFunctor(res, atomFactory, evaluator) {  }
	virtual int eval (int v) { return -v; }
	virtual float eval (float v) { return -v; }
	virtual double eval (double v) { return -v; }
    };
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	UnaryNegator f(res, atomFactory, evaluator);
	return atomFactory->applyCommonNumeric(m_Expression, &f);
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
    virtual const TTerm* eval (const Result* res, AtomFactory* /* atomFactory */, BNodeEvaluator* evaluator) const {
	return m_NumericRDFLiteral->evalTTerm(res, evaluator);
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
    struct NaryMultiplier : public AtomFactory::NaryFunctor {
	/* Do not place in eval() per http://www.eggheadcafe.com/conversation.aspx?messageid=32706692&threadid=32706692 */
	NaryMultiplier (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) : 
	    AtomFactory::NaryFunctor(res, atomFactory, evaluator) {  }
	virtual int eval (int l, int r) { return l * r; }
	virtual float eval (float l, float r) { return l * r; }
	virtual double eval (double l, double r) { return l * r; }
    };
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	NaryMultiplier f(res, atomFactory, evaluator);
	return atomFactory->applyCommonNumeric(std::vector<const Expression*>(m_Expressions.begin(), m_Expressions.end()), &f);
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
    virtual const TTerm* eval (const Result* res, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	std::stringstream s;
	s << "(/ 1 " << m_Expression->eval(res, atomFactory, evaluator) <<
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

struct StreamContextMediaTypes {
    static MediaTypeMap MediaTypes;
};
template<class T>
struct StreamContext : public StreamContextMediaTypes {
    typedef enum {
	NONE =		0,	/* don't do nuthin */
	STRING =	1,	/* nameStr is the contents */
	STDIO =		2,	/* '-' means stdin */
#if !defined(SWIGPERL) // triggers a SWIG PERL SEGV
	STDIN =		2,	/* '-' means stdin */
	STDOUT =	2,	/* '-' also means stdout */
#endif /* !defined(SWIGPERL) */
	FILE =		4,	/* must be a file */
    } e_opts;
    std::string nameStr;
    MediaType mediaType;
    bool malloced;

    T* p;
    StreamContext(std::string nameStr, T* p, const char* mediaType)
	: nameStr(nameStr), mediaType(mediaType), malloced(false), p(p)
    {  }
    StreamContext(std::string nameStr, T* def, e_opts,
		  const char* p_mediaType, SWWEBagent* webAgent,
		   std::ostream** debugStream);
    virtual ~StreamContext () { if (malloced) delete p; }
    T& operator* () { return *p; }

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

#if defined(SWIG)
    %template(StreamContextIstream) StreamContext<std::istream>;
    %template(StreamContextOstream) StreamContext<std::ostream>;
#endif

struct IStreamContext : public StreamContext<std::istream> {
    IStreamContext(std::string name, std::istream& istr, const char* p_mediaType = NULL)
	: StreamContext<std::istream>(name, &istr, p_mediaType)
    {  }
    IStreamContext(std::string name, e_opts opts = NONE,
		   const char* p_mediaType = NULL, SWWEBagent* webAgent = NULL,
		   std::ostream** debugStream = NULL);
};
struct OStreamContext : public StreamContext<std::ostream> {
    OStreamContext(std::string name, e_opts opts = NONE,
		   const char* p_mediaType = NULL, SWWEBagent* webAgent = NULL,
		   std::ostream** debugStream = NULL);
};

#if !defined SWIG
class StreamRewinder {
    friend class Device;

protected:
    typedef enum {STATE_copy, STATE_replay, STATE_pass} e_state;
    std::string buffer;
    std::string::size_type pos;
    e_state state;

public:
    class Device {
    protected:
	std::istream& istr;
	StreamRewinder& streamRewinder;

    public:
	typedef std::string::value_type  char_type;
	typedef boost::iostreams::source_tag category;

	Device(std::istream& istr, StreamRewinder& streamRewinder)
	    : istr(istr), streamRewinder(streamRewinder)
	{ /* w3c_sw_LINE << "normal constructor: " << toString() << "\n"; */ }
	Device(const Device& ref) 
	    : istr(ref.istr), streamRewinder(ref.streamRewinder)
	{ /* w3c_sw_LINE << "copy constructor: " << toString() << "\n"; */ }

	std::streamsize read(char_type* s, std::streamsize n) {
	    switch (streamRewinder.state) {
	    case STATE_replay: {
		std::streamsize amt = static_cast<std::streamsize>(streamRewinder.buffer.size() - streamRewinder.pos);
		std::streamsize result = (std::min)(n, amt);
		if (result != 0) {
// #pragma warning(push) // technically should stifle MS's unilateral deprecation, but doesn't work in 2008.
// #pragma warning(disable:4996)
		    std::copy( streamRewinder.buffer.begin() + streamRewinder.pos, 
			       streamRewinder.buffer.begin() + streamRewinder.pos + result, 
			       s );
// #pragma warning(pop)
		    streamRewinder.pos += result;
		    // w3c_sw_LINE << "replay: " << toString() << "\n";
		    return result;
		}
		streamRewinder.buffer.clear();
		streamRewinder.state = STATE_pass;
		// fall through to STATE_pass
	    }
	    case STATE_copy:
	    case STATE_pass: {
		istr.read(s, n);
		std::streamsize red = istr.gcount();
		if (streamRewinder.state == STATE_copy)
		    streamRewinder.buffer.append(s, red);
		// w3c_sw_LINE << "read: " << toString() << "\n";
		return red > 0 ? red : -1;
	    }
	    default: throw "program flow exception";
	    }
	}

	std::string toString () {
	    std::stringstream ret;
	    ret << "Device(" << istr << ")";
	    return ret.str();
	}
    };
    Device device;

    StreamRewinder (std::istream& istr)
	// The reference we pass to device is not used before we're constructed.
#ifdef _MSC_VER
#pragma warning(suppress:4355)
	: buffer(""), pos(0), state(STATE_copy), device(istr, *this)
#else
	: buffer(""), pos(0), state(STATE_copy), device(istr, *this)
#endif
    {  }
    void pass () { state = STATE_pass; buffer.clear(); }
    void replay () { state = STATE_replay; pos = 0; }
    std::string toString () {
	std::stringstream ret;
	ret << "Device(" << device.toString() << ", \"" << buffer << "\", " << pos << ", " << state << ")";
	return ret.str();
    }
};

class FileHandleDevice {
protected:
    int fileHandle;
    std::string name;

public:
    typedef std::string::value_type  char_type;
    typedef boost::iostreams::sink_tag category;

    FileHandleDevice (int fileHandle, std::string name)
	: fileHandle(fileHandle), name(name)
    {  }
    FileHandleDevice (const FileHandleDevice& ref) 
	: fileHandle(ref.fileHandle), name(ref.name)
    {  }
    ~FileHandleDevice ()
    {
	//::unlink(name.c_str());
	// @@ can't unlink 'cause this is copy-constructed willy nilly.
	// CERR << "unlinked " << name.c_str() << "\n";
    }

    std::streamsize write (const char_type* s, std::streamsize n) {
	std::string dbg(s, n);
	size_t ret = POSIX_write(fileHandle, s, n);
	if (ret == 0 && n != 0)
	    throw std::string("write returned 0.");
	return (std::streamsize)ret; // n is a streamsize so we won't have written more than that.
    }

    // void close () { // never gets called.
    //     POSIX_close(fileHandle);
    // }

    std::string toString () {
	std::stringstream ret;
	ret << "FileHandleDevice(" << fileHandle << ", " << name << ")";
	return ret.str();
    }
};

class LanguageChange : public std::exception {
public:
    std::string msg;
    std::string mediaType;
    typedef bool (Pipe)(std::istream& istr);
    Pipe* pipe;
    LanguageChange (std::string mediaType, Pipe* pipe)
	: msg(std::string("need to execute ") + "some pipe" /*pipe*/ + " to handle " + mediaType), 
	  mediaType(mediaType), pipe(pipe)
    {  }
    virtual ~LanguageChange () throw() {   }
    char const* what() const throw() { 	return msg.c_str(); }
};
#endif /* !defined SWIG */

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
    virtual void nulltterm(const NULLtterm* const self) = 0;
    virtual void triplePattern(const TriplePattern* const self, const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) = 0;
    virtual void filter(const Filter* const self, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) = 0;
    virtual void namedGraphPattern(const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
    virtual void defaultGraphPattern(const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
    virtual void tableConjunction(const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
    virtual void tableDisjunction(const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
    virtual void optionalGraphPattern(const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) = 0;
    virtual void minusGraphPattern(const MinusGraphPattern* const self, const TableOperation* p_GroupGraphPattern) = 0;
    virtual void graphGraphPattern(const GraphGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) = 0;
    virtual void serviceGraphPattern(const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) = 0;
    virtual void expressionAlias(const ExpressionAlias* const, const Expression* expr, const Bindable* label) = 0;
    virtual void expressionAliasList(const ExpressionAliasList* const self, const ProductionVector<const ExpressionAlias*>* p_Expressions) = 0;
    virtual void posList(const TTermList* const self, const ProductionVector<const TTerm*>* p_TTerms) = 0;
    virtual void starVarSet(const StarVarSet* const self) = 0;
    virtual void defaultGraphClause(const DefaultGraphClause* const self, const TTerm* p_IRIref) = 0;
    virtual void namedGraphClause(const NamedGraphClause* const self, const TTerm* p_IRIref) = 0;
    virtual void solutionModifier(const SolutionModifier* const self, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) = 0;
    virtual void binding(const Binding* const self, const ProductionVector<const TTerm*>* values) = 0;
    virtual void bindingClause(const BindingClause* const self, TTermList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) = 0;
    virtual void whereClause(const WhereClause* const self, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) = 0;
    virtual void operationSet(const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) = 0;
    virtual void select(const Select* const self, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) = 0;
    virtual void subSelect(const SubSelect* const self, const Select* p_Select) = 0;
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
    virtual void posExpression(const TTermExpression* const self, const TTerm* p_TTerm) = 0;
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
    virtual void comparatorExpression(const ComparatorExpression* const self, const GeneralComparator* p_GeneralComparator) = 0;
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
    virtual void nulltterm (const NULLtterm* const) {  }
    virtual void triplePattern (const TriplePattern* const, const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) {
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
    }
    virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
	p_op->express(this);
	p_Constraints->express(this);
    }
    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
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
    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
	p_GroupGraphPattern->express(this);
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	p_TTerm->express(this);
	p_GroupGraphPattern->express(this);
    }
    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* /* atomFactory */, bool /* lexicalCompare */) {
	p_TTerm->express(this);
	p_GroupGraphPattern->express(this);
    }
    virtual void expressionAlias (const ExpressionAlias* const, const Expression* expr, const Bindable* label) {
	expr->express(this);
	label->express(this);
    }
    virtual void expressionAliasList (const ExpressionAliasList* const, const ProductionVector<const ExpressionAlias*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void posList (const TTermList* const, const ProductionVector<const TTerm*>* p_TTerms) {
	p_TTerms->express(this);
    }
    virtual void starVarSet (const StarVarSet* const) {  }
    virtual void defaultGraphClause (const DefaultGraphClause* const, const TTerm* p_IRIref) {
	p_IRIref->express(this);
    }
    virtual void namedGraphClause (const NamedGraphClause* const, const TTerm* p_IRIref) {
	p_IRIref->express(this);
    }
    virtual void solutionModifier (const SolutionModifier* const, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditions, int, int) {
	if (groupBy) {
	    for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		 it != groupBy->end(); ++it)
		(*it)->express(this);
	}
	if (having) {
	    for (std::vector<const Expression*>::const_iterator it = having->begin();
		 it != having->end(); ++it)
		(*it)->express(this);
	}
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++)
		p_OrderConditions->at(i).expression->express(this);
    }
    virtual void binding (const Binding* const, const ProductionVector<const TTerm*>* values) {//!!!
	for (std::vector<const TTerm*>::const_iterator it = values->begin();
	     it != values->end(); ++it)
	    (*it)->express(this);
    }
    virtual void bindingClause (const BindingClause* const, TTermList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) {
	p_Vars->express(this);
	p_Bindings->ProductionVector<const Binding*>::express(this);
    }
    virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
    }
    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
	for (std::vector<const Operation*>::const_iterator it = p_Operations->begin();
	     it != p_Operations->end(); ++it)
	    (*it)->express(this);
    }
    virtual void select (const Select* const, e_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	p_Select->express(this);
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
    virtual void posExpression (const TTermExpression* const, const TTerm* p_TTerm) {
	p_TTerm->express(this);
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
    virtual void comparatorExpression (const ComparatorExpression* const, const GeneralComparator* p_GeneralComparator) {
	p_GeneralComparator->express(this);
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
