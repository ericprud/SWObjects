/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef SWOBJECTS_HH
# define SWOBJECTS_HH

#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

#include <cstdarg>
#include <cassert>
#include <typeinfo>
#include <boost/regex.hpp>

#define TAB "  "
#define ns "\n xmlns=\"http://www.w3.org/2005/01/yacker/uploads/SPARQLfed/\"\n xmlns:yacker=\"http://www.w3.org/2005/01/yacker/\""

namespace w3c_sw {

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

class Expressor;
class RecursiveExpressor;

class Base {
public:
    Base () { }
    virtual ~Base() { }
    virtual void express(Expressor* p_expressor);
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
    virtual T operator [] (size_t i) { return data[i]; }
    virtual T at (size_t i) { return data.at(i); }
    void clear () { data.clear(); }
    void pop_back () { data.pop_back(); }
    virtual void express(Expressor* p_expressor) {
	for (size_t i = 0; i < data.size(); i++)
	    data[i]->express(p_expressor);
    }
    typename std::vector<T>::iterator begin () { return data.begin(); }
    typename std::vector<T>::const_iterator begin () const { return data.begin(); }
    typename std::vector<T>::iterator end () { return data.end(); }
    typename std::vector<T>::const_iterator end () const { return data.end(); }
    void erase (typename std::vector<T>::iterator it) { data.erase(it); }
    void sort (bool (*comp)(T, T)) {
	std::list<T> l;
	for (typename std::vector<T>::iterator it = begin(); it != end(); ++it)
	    l.push_back(*it);
	l.sort(comp);
	data.clear();
	for (typename std::list<T>::iterator it = l.begin(); it != l.end(); ++it)
	    data.push_back(*it);
    }
#if 0
    class iterator;
    iterator begin() { return iterator(data.begin(), this); }
    iterator end() { return iterator(data.end(), this); }
#endif
};
template <typename T> class NoDelProductionVector : public ProductionVector<T> {
public:
    NoDelProductionVector () {  }
    NoDelProductionVector (T v) : ProductionVector<T>(v) {  }
    virtual ~NoDelProductionVector () { ProductionVector<T>::clear(); }
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
    std::string getTerminal () const { return terminal; }
};

} // namespace w3c_sw

namespace w3c_sw {

class ResultSet;
class Result;
typedef std::list<Result*>::iterator ResultSetIterator;
class RdfDB;

class LANGTAG : public Terminal {
public:
    LANGTAG(std::string p_LANGTAG) : Terminal(p_LANGTAG) {  }
};

class Operation : public Base {
protected:
    Operation () : Base() {  }
public:
    virtual ResultSet* execute(RdfDB*, ResultSet* = NULL) { throw(std::runtime_error(typeid(*this).name())); }
    virtual void express(Expressor* p_expressor) = 0;
};

/* Eval interface */
class EvalInterface {
public:
    EvalInterface () {  }
};

/* START Parts Of Speach */
class POS : public Terminal, public EvalInterface {
    friend class POSsorter;
protected:
    POS (std::string matched) : Terminal(matched) {  }
    POS (std::string matched, bool gensym) : Terminal(matched, gensym) { }
    //    virtual int compareType (POS* to) = 0;
public:
    virtual bool isConstant () { return true; } // Override for variable types.
    static bool orderByType (const POS*, const POS*) { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
    virtual int compare (POS* to, Result*) const {
	bool same = typeid(*to) == typeid(*this);
	return same ? getTerminal() != to->getTerminal() : orderByType(this, to);
    }
    virtual POS* eval (Result*, bool) { return this; }
    virtual void express(Expressor* p_expressor) = 0;
    virtual std::string getBindingAttributeName() = 0;
    virtual std::string toString() const = 0;
    std::string substitutedString (Result* row, bool bNodesGenSymbols) {
	POS* subd = eval(row, bNodesGenSymbols);
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
    virtual void express(Expressor* p_expressor);
    virtual std::string toString () const { std::stringstream s; s << "<" << terminal << ">"; return s.str(); }
    virtual std::string getBindingAttributeName () { return "uri"; }
    bool matches (std::string toMatch) { return terminal == toMatch; } // !!! added for SPARQLSerializer::functionCall
};

class Bindable : public POS {
protected:
    Bindable (std::string str) : POS(str) {  }
    Bindable (std::string str, bool gensym) : POS(str, gensym) {  }
public:
    virtual bool isConstant () { return false; }
};

struct URImap {
    boost::regex ifacePattern;
    std::string localPattern;
};

class POSFactory;
class Variable : public Bindable {
    friend class POSFactory;
protected:
    std::vector<URImap> uriMaps;
    POSFactory* posFactory;
private:
    Variable (std::string str) : Bindable(str) {  }
public:
    virtual std::string toString () const { std::stringstream s; s << "?" << terminal; return s.str(); }
    virtual const char * getToken () { return "-Variable-"; }
    virtual void express(Expressor* p_expressor);
    virtual POS* eval(Result* r, bool bNodesGenSymbols);
    virtual std::string getBindingAttributeName () { return "name"; }
    void setMaps (std::vector<URImap> maps, POSFactory* factory) { uriMaps = maps; posFactory = factory; }
};

class BNode : public Bindable {
    friend class POSFactory;
private:
    BNode (std::string str) : Bindable(str) {  }
    BNode () : Bindable("b", true) {  }
public:
    virtual std::string toString () const { std::stringstream s; s << "_:" << terminal; return s.str(); }
    virtual const char * getToken () { return "-BNode-"; }
    virtual void express(Expressor* p_expressor);
    virtual POS* eval(Result* r, bool bNodesGenSymbols);
    virtual std::string getBindingAttributeName () { return "bnode"; }
};

class RDFLiteral : public POS {
    friend class POSFactory;
private:
    std::string m_String;
    URI* datatype;
    LANGTAG* m_LANGTAG;

protected:
    RDFLiteral (std::string p_String, URI* p_URI, LANGTAG* p_LANGTAG, std::string matched) : POS(matched), m_String(p_String) {
	datatype = p_URI;
	m_LANGTAG = p_LANGTAG;
    }

    ~RDFLiteral () {
	delete m_LANGTAG;
    }
public:
    virtual std::string toString () const {
	std::stringstream s;
	s << terminal;
	if (datatype) s << datatype->toString();
	if (m_LANGTAG) s << m_LANGTAG->getTerminal();
	return s.str();
    }
    virtual void express(Expressor* p_expressor);
    virtual std::string getBindingAttributeName () { return "literal"; }
    std::string getString () { return m_String; }
};
class NumericRDFLiteral : public RDFLiteral {
    friend class POSFactory;
protected:
    NumericRDFLiteral (std::string p_String, URI* p_URI, std::string matched) : RDFLiteral(p_String, p_URI, NULL, matched) {  }
    ~NumericRDFLiteral () {  }
public:
    virtual void express(Expressor* p_expressor) = 0;
};
class IntegerRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    int m_value;
    IntegerRDFLiteral (std::string p_String, URI* p_URI, std::string matched, int p_value) : NumericRDFLiteral(p_String, p_URI, matched), m_value(p_value) {  }
    ~IntegerRDFLiteral () {  }
public:
    int getValue () { return m_value; }
    virtual std::string toString () const { std::stringstream s; s << m_value; return s.str(); }
    virtual void express(Expressor* p_expressor);
};
class DecimalRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    float m_value;
    DecimalRDFLiteral (std::string p_String, URI* p_URI, std::string matched, float p_value) : NumericRDFLiteral(p_String, p_URI, matched), m_value(p_value) {  }
    ~DecimalRDFLiteral () {  }
    virtual void express(Expressor* p_expressor);
public:
    virtual std::string toString () const { std::stringstream s; s << m_value; return s.str(); }
};
class DoubleRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    double m_value;
    DoubleRDFLiteral (std::string p_String, URI* p_URI, std::string matched, double p_value) : NumericRDFLiteral(p_String, p_URI, matched), m_value(p_value) {  }
    ~DoubleRDFLiteral () {  }
    virtual void express(Expressor* p_expressor);
};
class BooleanRDFLiteral : public RDFLiteral {
    friend class POSFactory;
protected:
    bool m_value;
    BooleanRDFLiteral (std::string p_String, std::string matched, bool p_value) : RDFLiteral(p_String, NULL, NULL, matched), m_value(p_value) {  }
public:
    virtual std::string toString () const { std::stringstream s; s << (m_value ? "true" : "false"); return s.str(); }
    virtual void express(Expressor* p_expressor);
};
class NULLpos : public POS {
    friend class POSFactory;
private:
    NULLpos () : POS("NULL", "") {  }
    ~NULLpos () {  }
public:
    virtual const char * getToken () { return "-NULL-"; }
    virtual std::string toString () const { std::stringstream s; s << "NULL"; return s.str(); }
    virtual void express(Expressor* p_expressor);
    virtual std::string getBindingAttributeName () { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
};

class BasicGraphPattern;

class TriplePattern : public Base {
    friend class POSFactory;
private:
    POS* m_s; POS* m_p; POS* m_o;
    bool weaklyBound;
    static bool _bindVariable(POS* it, const POS* p, ResultSet* rs, Result* provisional, bool weaklyBound);
    TriplePattern (POS* p_s, POS* p_p, POS* p_o) : Base(), m_s(p_s), m_p(p_p), m_o(p_o), weaklyBound(false) {  }
    TriplePattern (TriplePattern const& copy, bool weaklyBound) : Base(), m_s(copy.m_s), m_p(copy.m_p), m_o(copy.m_o), weaklyBound(weaklyBound) {  }
public:
    ~TriplePattern () {  }
    POS* getS () { return m_s; }
    POS* getP () { return m_p; }
    POS* getO () { return m_o; }
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
    std::string toString () const {
	std::stringstream s;
	s << "{" << m_s->toString() << " " << m_p->toString() << " " << m_o->toString() << "}";
	return s.str();
    }
    std::string toString (Result* row) const {
	std::stringstream s;
	s << 
	    "{" << m_s->substitutedString(row, false) << 
	    " " << m_p->substitutedString(row, false) << 
	    " " << m_o->substitutedString(row, false) << "}";
	return s.str();
    }
    virtual void express(Expressor* p_expressor);
    bool bindVariables (TriplePattern* tp, bool, ResultSet* rs, POS* graphVar, Result* provisional, POS* graphName) {
	return
	    _bindVariable(graphVar, graphName, rs, provisional, weaklyBound) &&
	    _bindVariable(tp->m_s, m_s, rs, provisional, weaklyBound) && 
	    _bindVariable(tp->m_p, m_p, rs, provisional, weaklyBound) && 
	    _bindVariable(tp->m_o, m_o, rs, provisional, weaklyBound);
    }
    bool construct(BasicGraphPattern* target, Result* r, POSFactory* posFactory, bool bNodesGenSymbols = true);
};

class DefaultGraphPattern;
class POSFactory {
    typedef std::map<std::string, Variable*> VariableMap;
    typedef std::map<std::string, BNode*> BNodeMap;
    typedef std::map<std::string, URI*> URIMap;
    typedef std::map<std::string, RDFLiteral*> RDFLiteralMap;
    typedef std::map<std::string, TriplePattern*> TriplePatternMap; // i don't know what the key should be. string for now...
    class MakeNumericRDFLiteral {
    public:
	virtual ~MakeNumericRDFLiteral () {  }
	virtual NumericRDFLiteral* makeIt(std::string p_String, URI* p_URI, std::string matched) = 0;
    };

protected:
    VariableMap		variables;
    BNodeMap		bnodes;
    URIMap		uris;
    RDFLiteralMap	rdfLiterals;
    TriplePatternMap	triples;
    NULLpos		nullPOS;
    NumericRDFLiteral* getNumericRDFLiteral(std::string p_String, const char* type, MakeNumericRDFLiteral* maker);

public:
    POSFactory () {  }
    ~POSFactory();
    Variable* getVariable(std::string name);
    BNode* createBNode();
    BNode* getBNode(std::string name);
    URI* getURI(std::string name);
    POS* getPOS(std::string posStr);
    RDFLiteral* getRDFLiteral(std::string p_String, URI* p_URI, LANGTAG* p_LANGTAG);

    IntegerRDFLiteral* getNumericRDFLiteral(std::string p_String, int p_value);
    DecimalRDFLiteral* getNumericRDFLiteral(std::string p_String, float p_value);
    DoubleRDFLiteral* getNumericRDFLiteral(std::string p_String, double p_value);

    BooleanRDFLiteral* getBooleanRDFLiteral(std::string p_String, bool p_value);
    NULLpos* getNULL () { return &nullPOS; }

    /* getTriple(s) interface: */
    TriplePattern* getTriple (TriplePattern* p, bool weaklyBound) {
	return getTriple(p->getS(), p->getP(), p->getO(), weaklyBound);
    }
    TriplePattern* getTriple(POS* s, POS* p, POS* o, bool weaklyBound = false);
    TriplePattern* getTriple (std::string s, std::string p, std::string o) {
	return getTriple(getPOS(s), getPOS(p), getPOS(o), false);
    }
    TriplePattern* getTriple (std::string spo) {
	const boost::regex expression("[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))[[:space:]]*\\.");
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	if (!regex_search(spo, what, expression, flags))
	    return NULL;
	std::string s(what[1].first, what[1].second);
	return getTriple(getPOS(std::string(what[1].first, what[1].second)), 
			 getPOS(std::string(what[2].first, what[2].second)), 
			 getPOS(std::string(what[3].first, what[3].second)), false);
    }
    void parseTriples (BasicGraphPattern* g, std::string spo);

};

    /* Sorter for the POSs. */
class POSsorter;
extern POSsorter* ThePOSsorter;

class POSsorter {
public:
    std::map<const std::string, int> typeOrder;
    POSsorter () {
	//typeOrder.insert(make_pair(typeid(BNode).name(), 2));
	typeOrder[typeid(BNode).name()] = 2;
	typeOrder[typeid(URI).name()] = 3;
	typeOrder[typeid(RDFLiteral).name()] = 4;
	ThePOSsorter = this;
    }
    bool sort (const POS* lhs, const POS* rhs) {
	const std::string lt = typeid(*lhs).name();
	const std::string rt = typeid(*rhs).name();
	const int li = typeOrder[lt];
	const int ri = typeOrder[rt];
	if (li < ri)
	    return true;
	return lhs->getTerminal().compare(rhs->getTerminal()) < 0;
    }
};

/* END Parts Of Speach */

class Expression : public Base, public EvalInterface {
private:
public:
    Expression () : Base() { }
    ~Expression () {  }
    virtual void express(Expressor* p_expressor) = 0;
};

typedef enum {DIST_all, DIST_distinct, DIST_reduced} e_distinctness;
typedef enum { ORDER_Asc, ORDER_Desc } e_ASCorDESC;
#define LIMIT_None -1
#define OFFSET_None -1
typedef struct {e_ASCorDESC ascOrDesc; Expression* expression;} s_OrderConditionPair;
typedef enum { SILENT_Yes, SILENT_No } e_Silence;

class Filter : public Base {
private:
    Expression* m_Constraint;
public:
    Filter (Expression* p_Constraint) : Base(), m_Constraint(p_Constraint) {  }
    ~Filter () { delete m_Constraint; }
    virtual void express(Expressor* p_expressor);
};

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
    ProductionVector<Filter*> m_Filters;
    TableOperation () : Base(), m_Filters() { }
public:
    //size_t filters () { return m_Filters.size(); }
    void addFilter (Filter* filter) {
	m_Filters.push_back(filter);
    }
    virtual void bindVariables(RdfDB*, ResultSet*) = 0; //{ throw(std::runtime_error(__PRETTY_FUNCTION__)); }
    virtual void express(Expressor*) = 0;
    virtual TableOperation* getDNF() = 0;
};
class TableJunction : public TableOperation {
protected:
    ProductionVector<TableOperation*> m_TableOperations;
public:
    TableJunction () : TableOperation(), m_TableOperations() {  }

    virtual void addTableOperation(TableOperation* tableOp);
    std::vector<TableOperation*>::iterator begin () { return m_TableOperations.begin(); }
    std::vector<TableOperation*>::iterator end () { return m_TableOperations.end(); }
    void clear () { m_TableOperations.clear(); }
    void erase (std::vector<TableOperation*>::iterator it) { m_TableOperations.erase(it); }
    size_t size () const { return m_TableOperations.size(); }
    TableOperation* simplify () {
	TableOperation* ret;
	if (size() == 0 || size() == 1) {
	    ret = size() == 0 ? NULL : *begin();
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
    virtual void express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB*, ResultSet* rs);
    virtual TableOperation* getDNF();
};
class TableDisjunction : public TableJunction { // ⊎
public:
    TableDisjunction () : TableJunction() {  }
    virtual void express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB*, ResultSet* rs);
    virtual TableOperation* getDNF();
};
class DontDeleteThisBGP;
class BasicGraphPattern : public TableOperation { // ⊌⊍
protected:
    // make sure we don't delete the TriplePatterns
    NoDelProductionVector<TriplePattern*> m_TriplePatterns;
    bool allOpts;
    BasicGraphPattern (bool allOpts) : TableOperation(), m_TriplePatterns(), allOpts(allOpts) {  }

public:
    void addTriplePattern (TriplePattern* p) {
	for (std::vector<TriplePattern*>::iterator it = m_TriplePatterns.begin();
	     it != m_TriplePatterns.end(); ++it)
	    if (*it == p)
		return;
	m_TriplePatterns.push_back(p);
    }
    virtual void bindVariables(RdfDB* db, ResultSet* rs) = 0;
    void bindVariables(ResultSet* rs, POS* graphVar, BasicGraphPattern* toMatch, POS* graphName);
    void construct(BasicGraphPattern* target, ResultSet* rs);
    size_t size () const { return m_TriplePatterns.size(); }
    std::vector<TriplePattern*>::iterator begin () { return m_TriplePatterns.begin(); }
    std::vector<TriplePattern*>::const_iterator begin () const { return m_TriplePatterns.begin(); }
    std::vector<TriplePattern*>::iterator end () { return m_TriplePatterns.end(); }
    std::vector<TriplePattern*>::const_iterator end () const { return m_TriplePatterns.end(); }
    void erase (std::vector<TriplePattern*>::iterator it) { m_TriplePatterns.erase(it); }
    void sort (bool (*comp)(TriplePattern*, TriplePattern*)) { m_TriplePatterns.sort(comp); }
    void clearTriples () { m_TriplePatterns.clear(); }
    virtual TableOperation* getDNF ();
    virtual void express(Expressor* p_expressor) = 0;
};
class DontDeleteThisBGP : public TableOperation {
protected: BasicGraphPattern* bgp;
public:
    DontDeleteThisBGP (BasicGraphPattern* bgp) : bgp(bgp) {  }
    ~DontDeleteThisBGP () { /* Leave bgp alone. */ }
    virtual void bindVariables(RdfDB* db, ResultSet* rs) { bgp->bindVariables(db, rs); }
    virtual TableOperation* getDNF () { return new DontDeleteThisBGP(bgp); }
    virtual void express (Expressor* p_expressor) { bgp->express(p_expressor); }
};

class NamedGraphPattern : public BasicGraphPattern {
private:
    POS* m_name;

public:
    NamedGraphPattern (POS* p_name, bool allOpts = false) : BasicGraphPattern(allOpts), m_name(p_name) {  }
    virtual void express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB* db, ResultSet* rs);
};
class DefaultGraphPattern : public BasicGraphPattern {
public:
    DefaultGraphPattern (bool allOpts = false) : BasicGraphPattern(allOpts) {  }
    virtual void express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB* db, ResultSet* rs);
    bool operator== (const DefaultGraphPattern & ref) const {
	if (m_TriplePatterns.size() != ref.m_TriplePatterns.size())
	    return false;

	std::set<TriplePattern*> refs;
	for (std::vector<TriplePattern*>::const_iterator it = ref.m_TriplePatterns.begin();
	     it != ref.m_TriplePatterns.end(); ++it)
	    refs.insert(*it);

	for (std::vector<TriplePattern*>::const_iterator it = m_TriplePatterns.begin();
	     it != m_TriplePatterns.end(); ++it)
	    if (refs.erase(*it) == 0)
		return false;
	return true;
    }
};
class TableOperationOnOperation : public TableOperation {
protected:
    TableOperation* m_TableOperation;
    TableOperationOnOperation (TableOperation* p_TableOperation) : TableOperation(), m_TableOperation(p_TableOperation) {  }
    ~TableOperationOnOperation() { delete m_TableOperation; }
    virtual TableOperationOnOperation* makeANewThis(TableOperation* p_TableOperation) = 0;
public:
    virtual TableOperation* getDNF();
};
/* GraphGraphPattern: pass-through class that's just used to reproduce verbatim SPARQL queries
 */
class GraphGraphPattern : public TableOperationOnOperation {
private:
    POS* m_VarOrIRIref;
public:
    GraphGraphPattern (POS* p_POS, TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern), m_VarOrIRIref(p_POS) {  }
    virtual void express(Expressor* p_expressor);
    virtual void bindVariables (RdfDB* db, ResultSet* rs) {
	m_TableOperation->bindVariables(db, rs);
    }
    virtual TableOperationOnOperation* makeANewThis (TableOperation* p_TableOperation) { return new GraphGraphPattern(m_VarOrIRIref, p_TableOperation); }
};
class OptionalGraphPattern : public TableOperationOnOperation {
public:
    OptionalGraphPattern (TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern) {  }
    virtual void express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB*, ResultSet* rs);
    virtual TableOperationOnOperation* makeANewThis (TableOperation* p_TableOperation) { return new OptionalGraphPattern(p_TableOperation); }
};

class VarSet : public Base {
protected:
    VarSet () : Base() { }
public:
    virtual void express(Expressor*) = 0;
};

class POSList : public VarSet {
private:
    ProductionVector<POS*> m_POSs;
public:
    POSList () : VarSet(), m_POSs() {  }
    ~POSList () { m_POSs.clear(); }
    void push_back(POS* v) { m_POSs.push_back(v); }
    virtual void express(Expressor* p_expressor);
    std::vector<POS*>::iterator begin () { return m_POSs.begin(); }
    std::vector<POS*>::iterator end () { return m_POSs.end(); }
};
class StarVarSet : public VarSet {
private:
public:
    StarVarSet () : VarSet() {  }
    size_t size() { return 0; }
    POS* operator [] (size_t) { return NULL; }
    POS* getElement (size_t) { return NULL; }
    virtual void express(Expressor* p_expressor);
};

class DatasetClause : public Base {
protected:
    POS* m_IRIref;
    POSFactory* m_posFactory;
public:
    DatasetClause (POS* p_IRIref, POSFactory* p_posFactory) : Base(), m_IRIref(p_IRIref), m_posFactory(p_posFactory) {  }
    ~DatasetClause () { /* m_IRIref is centrally managed */ }
    virtual void loadData(RdfDB*) = 0;
    void _loadData(BasicGraphPattern*);
    virtual void express(Expressor* p_expressor) = 0;
};
class DefaultGraphClause : public DatasetClause {
private:
public:
    DefaultGraphClause (POS* p_IRIref, POSFactory* p_posFactory) : DatasetClause(p_IRIref, p_posFactory) { }
    ~DefaultGraphClause () {  }
    virtual void express(Expressor* p_expressor);
    virtual void loadData(RdfDB*);
};
class NamedGraphClause : public DatasetClause {
private:
public:
    NamedGraphClause (POS* p_IRIref, POSFactory* p_posFactory) : DatasetClause(p_IRIref, p_posFactory) { }
    ~NamedGraphClause () {  }
    virtual void express(Expressor* p_expressor);
    virtual void loadData(RdfDB*);
};

    /* SolutionModifiers */
class SolutionModifier : public Base {
private:
    std::vector<s_OrderConditionPair>* m_OrderConditions;
    int m_limit;
    int m_offset;
public:
    SolutionModifier (std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) : Base(), m_OrderConditions(p_OrderConditions), m_limit(p_limit), m_offset(p_offset) {  }
    ~SolutionModifier () {
	if (m_OrderConditions != NULL)
	    for (size_t i = 0; i < m_OrderConditions->size(); i++)
		delete m_OrderConditions->at(i).expression;
	delete m_OrderConditions;
    }
    virtual void express(Expressor* p_expressor);
};
class Binding : public ProductionVector<POS*> {
private:
public:
    Binding () : ProductionVector<POS*>() {  }
    ~Binding () { clear(); /* atoms in vector are centrally managed */ }
    virtual void express(Expressor* p_expressor);
    void bindVariables(RdfDB* db, ResultSet* rs, Result* r, POSList* p_Vars);
};
class BindingClause : public ProductionVector<Binding*> {
private:
    POSList* m_Vars;
public:
    BindingClause (POSList* p_Vars) : ProductionVector<Binding*>(), m_Vars(p_Vars) {  }
    ~BindingClause () { delete m_Vars; }
    virtual void express(Expressor* p_expressor);
    void bindVariables(RdfDB* db, ResultSet* rs);
};
class WhereClause : public Base {
private:
    TableOperation* m_GroupGraphPattern;
    BindingClause* m_BindingClause;
public:
    WhereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) : Base(), m_GroupGraphPattern(p_GroupGraphPattern), m_BindingClause(p_BindingClause) {  }
    ~WhereClause () {
	delete m_GroupGraphPattern;
	delete m_BindingClause;
    }
    virtual void express(Expressor* p_expressor);
    void bindVariables(RdfDB* db, ResultSet* rs);
};

class Select : public Operation {
private:
    e_distinctness m_distinctness;
    VarSet* m_VarSet;
    ProductionVector<DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
    SolutionModifier* m_SolutionModifier;
public:
    Select (e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) : Operation(), m_distinctness(p_distinctness), m_VarSet(p_VarSet), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause), m_SolutionModifier(p_SolutionModifier) {  }
    ~Select () {
	delete m_VarSet;
	delete m_DatasetClauses;
	delete m_WhereClause;
	delete m_SolutionModifier;
    }
    virtual void express(Expressor* p_expressor);
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL);
};
class Construct : public Operation {
protected:
    DefaultGraphPattern* m_ConstructTemplate;
    ProductionVector<DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
    SolutionModifier* m_SolutionModifier;
public:
    Construct (DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) : Operation(), m_ConstructTemplate(p_ConstructTemplate), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause), m_SolutionModifier(p_SolutionModifier) {  }
    ~Construct () {
	delete m_ConstructTemplate;
	delete m_DatasetClauses;
	delete m_WhereClause;
	delete m_SolutionModifier;
    }
    virtual void express(Expressor* p_expressor);
    virtual ResultSet* execute(RdfDB* db, ResultSet* rs = NULL);
    WhereClause* getWhereClause () { return m_WhereClause; }
};
class Describe : public Operation {
private:
    VarSet* m_VarSet;
    ProductionVector<DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
    SolutionModifier* m_SolutionModifier;
public:
    Describe (VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) : Operation(), m_VarSet(p_VarSet), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause), m_SolutionModifier(p_SolutionModifier) {  }
    ~Describe () {
	delete m_VarSet;
	delete m_DatasetClauses;
	delete m_WhereClause;
	delete m_SolutionModifier;
    }
    virtual void express(Expressor* p_expressor);
};
class Ask : public Operation {
private:
    ProductionVector<DatasetClause*>* m_DatasetClauses;
    WhereClause* m_WhereClause;
public:
    Ask (ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) : Operation(), m_DatasetClauses(p_DatasetClauses), m_WhereClause(p_WhereClause) {  }
    ~Ask () {
	delete m_DatasetClauses;
	delete m_WhereClause;
    }
    virtual void express(Expressor* p_expressor);
};
class Replace : public Operation {
private:
    WhereClause* m_WhereClause;
    TableOperation* m_GraphTemplate;
public:
    Replace (WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) : Operation(), m_WhereClause(p_WhereClause), m_GraphTemplate(p_GraphTemplate) {  }
    ~Replace () { delete m_WhereClause; delete m_GraphTemplate; }
    virtual void express(Expressor* p_expressor);
};
class Insert : public Operation {
private:
    TableOperation* m_GraphTemplate;
    WhereClause* m_WhereClause;
public:
    Insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) : Operation(), m_GraphTemplate(p_GraphTemplate), m_WhereClause(p_WhereClause) {  }
    ~Insert () { delete m_GraphTemplate; delete m_WhereClause; }
    virtual void express(Expressor* p_expressor);
};
class Delete : public Operation {
private:
    TableOperation* m_GraphTemplate;
    WhereClause* m_WhereClause;
public:
    Delete (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) : Operation(), m_GraphTemplate(p_GraphTemplate), m_WhereClause(p_WhereClause) {  }
    ~Delete () { delete m_GraphTemplate; delete m_WhereClause; }
    virtual void express(Expressor* p_expressor);
};
class Load : public Operation {
private:
    ProductionVector<URI*>* m_IRIrefs;
    URI* m_into;
public:
    Load (ProductionVector<URI*>* p_IRIrefs, URI* p_into) : Operation(), m_IRIrefs(p_IRIrefs), m_into(p_into) {  }
    ~Load () { delete m_IRIrefs; delete m_into; }
    virtual void express(Expressor* p_expressor);
};
class Clear : public Operation {
private:
    URI* m__QGraphIRI_E_Opt;
public:
    Clear (URI* p__QGraphIRI_E_Opt) : Operation(), m__QGraphIRI_E_Opt(p__QGraphIRI_E_Opt) { }
    ~Clear () { delete m__QGraphIRI_E_Opt; }
    virtual void express(Expressor* p_expressor);
};
class Create : public Operation {
private:
    e_Silence m_Silence;
    URI* m_GraphIRI;
public:
    Create (e_Silence p_Silence, URI* p_GraphIRI) : Operation(), m_Silence(p_Silence), m_GraphIRI(p_GraphIRI) {  }
    ~Create () { /* m_GraphIRI is centrally managed */ }
    virtual void express(Expressor* p_expressor);
};
class Drop : public Operation {
private:
    e_Silence m_Silence;
    URI* m_GraphIRI;
public:
    Drop (e_Silence p_Silence, URI* p_GraphIRI) : Operation(), m_Silence(p_Silence), m_GraphIRI(p_GraphIRI) {  }
    ~Drop () { /* m_GraphIRI is centrally managed */ }
    virtual void express(Expressor* p_expressor);
};

/* kinds of Expressions */
class VarExpression : public Expression {
private:
    Variable* m_Variable;
public:
    VarExpression (Variable* p_Variable) : Expression(), m_Variable(p_Variable) {  }
    ~VarExpression () { /* m_Variable is centrally managed */ }
    Variable* getVariable () { return m_Variable; }
    virtual void express(Expressor* p_expressor);
};
class LiteralExpression : public Expression {
private:
    RDFLiteral* m_RDFLiteral;
public:
    LiteralExpression (RDFLiteral* p_RDFLiteral) : Expression(), m_RDFLiteral(p_RDFLiteral) {  }
    ~LiteralExpression () { /* m_RDFLiteral is centrally managed */ }
    RDFLiteral* getLiteral () { return m_RDFLiteral; }
    virtual void express(Expressor* p_expressor);
};
class BooleanExpression : public Expression {
private:
    BooleanRDFLiteral* m_BooleanRDFLiteral;
public:
    BooleanExpression (BooleanRDFLiteral* p_BooleanRDFLiteral) : Expression(), m_BooleanRDFLiteral(p_BooleanRDFLiteral) {  }
    ~BooleanExpression () { /* m_BooleanRDFLiteral is centrally managed */ }
    virtual void express(Expressor* p_expressor);
};
class URIExpression : public Expression {
private:
    URI* m_URI;
public:
    URIExpression (URI* p_URI) : Expression(), m_URI(p_URI) {  }
    ~URIExpression () { /* m_URI is centrally managed */ }
    virtual void express(Expressor* p_expressor);
};

class ArgList : public Base {
private:
    ProductionVector<Expression*>* expressions;
public:
    ArgList (ProductionVector<Expression*>* expressions) : Base(), expressions(expressions) {  }
    ~ArgList () { delete expressions; }
    std::vector<Expression*>::iterator begin () { return expressions->begin(); }
    std::vector<Expression*>::iterator end () { return expressions->end(); }
    size_t size () { return expressions->size(); }
    virtual void express(Expressor* p_expressor);
};
class FunctionCall : public Base {
private:
    URI* m_IRIref;
    ArgList* m_ArgList;
public:
    FunctionCall (URI* p_IRIref, ArgList* p_ArgList) : Base(), m_IRIref(p_IRIref), m_ArgList(p_ArgList) {  }
    FunctionCall (URI* p_IRIref, Expression* arg1, Expression* arg2, Expression* arg3) : Base() {
	m_IRIref = p_IRIref;
	ProductionVector<Expression*>* args = new ProductionVector<Expression*>();
	if (arg1) args->push_back(arg1);
	if (arg2) args->push_back(arg2);
	if (arg3) args->push_back(arg3);
	m_ArgList = new ArgList(args);
    }
    ~FunctionCall () { delete m_ArgList; }
    virtual void express(Expressor* p_expressor);
};
class FunctionCallExpression : public Expression {
private:
    FunctionCall* m_FunctionCall;
public:
    FunctionCallExpression (FunctionCall* p_FunctionCall) : Expression(), m_FunctionCall(p_FunctionCall) {  }
    ~FunctionCallExpression () { delete m_FunctionCall; }
    virtual void express(Expressor* p_expressor);
};

/* Expressions */
/* Logical connectives: or and */
class UnaryExpression : public Expression {
protected:
    Expression* m_Expression;
public:
    UnaryExpression (Expression* p_Expression) : Expression(), m_Expression(p_Expression) {  }
    ~UnaryExpression () { delete m_Expression; }
    virtual const char* getUnaryOperator() = 0;
};
class NaryExpression : public Expression {
protected:
    ProductionVector<Expression*> m_Expressions;
public:
    NaryExpression (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : Expression(), m_Expressions() {
	m_Expressions.push_back(p_Expression);
	for (size_t i = 0; i < p_Expressions->size(); i++)
	    m_Expressions.push_back(p_Expressions->at(i));
    }

    virtual const char* getInfixNotation() = 0;
};
class BooleanJunction : public NaryExpression {
public:
    BooleanJunction (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) { }
};
class BooleanConjunction : public BooleanJunction { // ⋀
public:
    BooleanConjunction (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : BooleanJunction(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "&&"; };
    virtual void express(Expressor* p_expressor);
};
class BooleanDisjunction : public BooleanJunction { // ⋁
public:
    BooleanDisjunction (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : BooleanJunction(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "||"; };
    virtual void express(Expressor* p_expressor);
};

class BooleanComparator : public Expression {
protected:
    Expression* left;
    Expression* right;
public:
    BooleanComparator (Expression* p_Expression) : Expression(), right(p_Expression) {  }
    ~BooleanComparator () { delete left; delete right; }
    virtual void setLeftParm (Expression* p_left) { left = p_left; }

    virtual const char* getComparisonNotation() = 0;
    virtual void express(Expressor* p_expressor) = 0;
};
class BooleanEQ : public BooleanComparator {
public:
    BooleanEQ (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "="; };
    virtual void express(Expressor* p_expressor);
};
class BooleanNE : public BooleanComparator {
public:
    BooleanNE (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "!="; };
    virtual void express(Expressor* p_expressor);
};
class BooleanLT : public BooleanComparator {
public:
    BooleanLT (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "<"; };
    virtual void express(Expressor* p_expressor);
};
class BooleanGT : public BooleanComparator {
public:
    BooleanGT (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return ">"; };
    virtual void express(Expressor* p_expressor);
};
class BooleanLE : public BooleanComparator {
public:
    BooleanLE (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "<="; };
    virtual void express(Expressor* p_expressor);
};
class BooleanGE : public BooleanComparator {
public:
    BooleanGE (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return ">="; };
    virtual void express(Expressor* p_expressor);
};
class ComparatorExpression : public Expression {
private:
    BooleanComparator* m_BooleanComparator;
public:
    ComparatorExpression (BooleanComparator* p_BooleanComparator) : Expression(), m_BooleanComparator(p_BooleanComparator) {  }
    ~ComparatorExpression () { delete m_BooleanComparator; }
    virtual void express(Expressor* p_expressor);
};
class BooleanNegation : public UnaryExpression {
public:
    BooleanNegation (Expression* p_PrimaryExpression) : UnaryExpression(p_PrimaryExpression) {  }
    ~BooleanNegation () {  }
    virtual const char* getUnaryOperator () { return "!"; };
    virtual void express(Expressor* p_expressor);
};
class ArithmeticSum : public NaryExpression {
public:
    ArithmeticSum (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "+"; };    
    virtual void express(Expressor* p_expressor);
};
class ArithmeticNegation : public UnaryExpression {
public:
    ArithmeticNegation (Expression* p_MultiplicativeExpression) : UnaryExpression(p_MultiplicativeExpression) {  }
    ~ArithmeticNegation () {  }
    virtual const char* getUnaryOperator () { return "-"; };
    virtual void express(Expressor* p_expressor);
};
class NumberExpression : public Expression {
private:
    NumericRDFLiteral* m_NumericRDFLiteral;
public:
    NumberExpression (NumericRDFLiteral* p_NumericRDFLiteral) : Expression(), m_NumericRDFLiteral(p_NumericRDFLiteral) {  }
    ~NumberExpression () { /* m_NumericRDFLiteral is centrally managed */ }
    virtual void express(Expressor* p_expressor);
};
class ArithmeticProduct : public NaryExpression {
public:
    ArithmeticProduct (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "+"; };    
    virtual void express(Expressor* p_expressor);
};
class ArithmeticInverse : public UnaryExpression {
public:
    ArithmeticInverse (Expression* p_UnaryExpression) : UnaryExpression(p_UnaryExpression) {  }
    ~ArithmeticInverse () {  }
    virtual const char* getUnaryOperator () { return "1/"; };
    virtual void express(Expressor* p_expressor);
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
    using namespace w3c_sw;
class Expressor {
public:
    virtual ~Expressor () {  }

    virtual void base(Base* self, std::string productionName) = 0;

    virtual void uri(URI* self, std::string terminal) = 0;
    virtual void variable(Variable* self, std::string terminal) = 0;
    virtual void bnode(BNode* self, std::string terminal) = 0;
    virtual void rdfLiteral(RDFLiteral* self, std::string terminal, w3c_sw::URI* datatype, w3c_sw::LANGTAG* p_LANGTAG) = 0;
    virtual void rdfLiteral(NumericRDFLiteral* self, int p_value) = 0;
    virtual void rdfLiteral(NumericRDFLiteral* self, float p_value) = 0;
    virtual void rdfLiteral(NumericRDFLiteral* self, double p_value) = 0;
    virtual void rdfLiteral(BooleanRDFLiteral* self, bool p_value) = 0;
    virtual void nullpos(NULLpos* self) = 0;
    virtual void triplePattern(TriplePattern* self, w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) = 0;
    virtual void filter(Filter* self, w3c_sw::Expression* p_Constraint) = 0;
    virtual void namedGraphPattern(NamedGraphPattern* self, w3c_sw::POS* p_name, bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual void defaultGraphPattern(DefaultGraphPattern* self, bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual void tableConjunction(TableConjunction* self, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual void tableDisjunction(TableDisjunction* self, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual void optionalGraphPattern(OptionalGraphPattern* self, w3c_sw::TableOperation* p_GroupGraphPattern) = 0;
    virtual void graphGraphPattern(GraphGraphPattern* self, w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) = 0;
    virtual void posList(POSList* self, ProductionVector<w3c_sw::POS*>* p_POSs) = 0;
    virtual void starVarSet(StarVarSet* self) = 0;
    virtual void defaultGraphClause(DefaultGraphClause* self, w3c_sw::POS* p_IRIref) = 0;
    virtual void namedGraphClause(NamedGraphClause* self, w3c_sw::POS* p_IRIref) = 0;
    virtual void solutionModifier(SolutionModifier* self, std::vector<w3c_sw::s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) = 0;
    virtual void binding(Binding* self, ProductionVector<w3c_sw::POS*>* values) = 0;//!!!
    virtual void bindingClause(BindingClause* self, w3c_sw::POSList* p_Vars, ProductionVector<w3c_sw::Binding*>* p_Bindings) = 0;
    virtual void whereClause(WhereClause* self, w3c_sw::TableOperation* p_GroupGraphPattern, w3c_sw::BindingClause* p_BindingClause) = 0;
    virtual void select(Select* self, w3c_sw::e_distinctness p_distinctness, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) = 0;
    virtual void construct(Construct* self, w3c_sw::DefaultGraphPattern* p_ConstructTemplate, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) = 0;
    virtual void describe(Describe* self, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) = 0;
    virtual void ask(Ask* self, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause) = 0;
    virtual void replace(Replace* self, w3c_sw::WhereClause* p_WhereClause, w3c_sw::TableOperation* p_GraphTemplate) = 0;
    virtual void insert(Insert* self, w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) = 0;
    virtual void del(Delete* self, w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) = 0;
    virtual void load(Load* self, ProductionVector<w3c_sw::URI*>* p_IRIrefs, w3c_sw::URI* p_into) = 0;
    virtual void clear(Clear* self, w3c_sw::URI* p__QGraphIRI_E_Opt) = 0;
    virtual void create(Create* self, w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) = 0;
    virtual void drop(Drop* self, w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) = 0;
    virtual void varExpression(VarExpression* self, w3c_sw::Variable* p_Variable) = 0;
    virtual void literalExpression(LiteralExpression* self, w3c_sw::RDFLiteral* p_RDFLiteral) = 0;
    virtual void booleanExpression(BooleanExpression* self, w3c_sw::BooleanRDFLiteral* p_BooleanRDFLiteral) = 0;
    virtual void uriExpression(URIExpression* self, w3c_sw::URI* p_URI) = 0;
    virtual void argList(ArgList* self, ProductionVector<w3c_sw::Expression*>* expressions) = 0;
    virtual void functionCall(FunctionCall* self, w3c_sw::URI* p_IRIref, w3c_sw::ArgList* p_ArgList) = 0;
    virtual void functionCallExpression(FunctionCallExpression* self, w3c_sw::FunctionCall* p_FunctionCall) = 0;
/* Expressions */
    virtual void booleanNegation(BooleanNegation* self, w3c_sw::Expression* p_Expression) = 0;
    virtual void arithmeticNegation(ArithmeticNegation* self, w3c_sw::Expression* p_Expression) = 0;
    virtual void arithmeticInverse(ArithmeticInverse* self, w3c_sw::Expression* p_Expression) = 0;
    virtual void booleanConjunction(BooleanConjunction* self, ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual void booleanDisjunction(BooleanDisjunction* self, ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual void arithmeticSum(ArithmeticSum* self, ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual void arithmeticProduct(ArithmeticProduct* self, ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual void booleanEQ(BooleanEQ* self, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual void booleanNE(BooleanNE* self, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual void booleanLT(BooleanLT* self, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual void booleanGT(BooleanGT* self, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual void booleanLE(BooleanLE* self, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual void booleanGE(BooleanGE* self, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual void comparatorExpression(ComparatorExpression* self, w3c_sw::BooleanComparator* p_BooleanComparator) = 0;
    virtual void numberExpression(NumberExpression* self, w3c_sw::NumericRDFLiteral* p_NumericRDFLiteral) = 0;
};
/* RecursiveExpressor - default actions for expressor.
 * Use this Expressor when you don't feel like supplying all of the methods.
 */
class RecursiveExpressor : public Expressor {
public:
    virtual void uri (URI*, std::string) {  }
    virtual void variable (Variable*, std::string) {  }
    virtual void bnode (BNode*, std::string) {  }
    virtual void rdfLiteral (RDFLiteral*, std::string, w3c_sw::URI* datatype, w3c_sw::LANGTAG* p_LANGTAG) {
	if (datatype) datatype->express(this);
	if (p_LANGTAG) p_LANGTAG->express(this);
    }
    virtual void rdfLiteral (NumericRDFLiteral*, int) {  }
    virtual void rdfLiteral (NumericRDFLiteral*, float) {  }
    virtual void rdfLiteral (NumericRDFLiteral*, double) {  }
    virtual void rdfLiteral (BooleanRDFLiteral*, bool) {  }
    virtual void nullpos (NULLpos*) {  }
    virtual void triplePattern (TriplePattern*, w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) {
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
    }
    virtual void filter (Filter*, w3c_sw::Expression* p_Constraint) {
	p_Constraint->express(this);
    }
    virtual void namedGraphPattern (NamedGraphPattern*, w3c_sw::POS* p_name, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_name->express(this);
	p_TriplePatterns->express(this);
	p_Filters->express(this);
    }
    virtual void defaultGraphPattern (DefaultGraphPattern*, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_TriplePatterns->express(this);
	p_Filters->express(this);
    }
    virtual void tableConjunction (TableConjunction*, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_TableOperations->express(this);
	p_Filters->express(this);
    }
    virtual void tableDisjunction (TableDisjunction*, ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_TableOperations->express(this);
	p_Filters->express(this);
    }
    virtual void optionalGraphPattern (OptionalGraphPattern*, w3c_sw::TableOperation* p_GroupGraphPattern) {
	p_GroupGraphPattern->express(this);
    }
    virtual void graphGraphPattern (GraphGraphPattern*, w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
	p_POS->express(this);
	p_GroupGraphPattern->express(this);
    }
    virtual void posList (POSList*, ProductionVector<w3c_sw::POS*>* p_POSs) {
	p_POSs->express(this);
    }
    virtual void starVarSet (StarVarSet*) {  }
    virtual void defaultGraphClause (DefaultGraphClause*, w3c_sw::POS* p_IRIref) {
	p_IRIref->express(this);
    }
    virtual void namedGraphClause (NamedGraphClause*, w3c_sw::POS* p_IRIref) {
	p_IRIref->express(this);
    }
    virtual void solutionModifier (SolutionModifier*, std::vector<w3c_sw::s_OrderConditionPair>* p_OrderConditions, int, int) {
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++)
		p_OrderConditions->at(i).expression->express(this);
    }
    virtual void binding (Binding*, ProductionVector<w3c_sw::POS*>* values) {//!!!
	for (size_t i = 0; i < values->size(); i++)
	    values->at(i)->express(this);
    }
    virtual void bindingClause (BindingClause*, w3c_sw::POSList* p_Vars, ProductionVector<w3c_sw::Binding*>* p_Bindings) {
	p_Vars->express(this);
	p_Bindings->ProductionVector<w3c_sw::Binding*>::express(this);
    }
    virtual void whereClause (WhereClause*, w3c_sw::TableOperation* p_GroupGraphPattern, w3c_sw::BindingClause* p_BindingClause) {
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
    }
    virtual void select (Select*, w3c_sw::e_distinctness, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void construct (Construct*, w3c_sw::DefaultGraphPattern* p_ConstructTemplate, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void describe (Describe*, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    }
    virtual void ask (Ask*, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause) {
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
    }
    virtual void replace (Replace*, w3c_sw::WhereClause* p_WhereClause, w3c_sw::TableOperation* p_GraphTemplate) {
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
    }
    virtual void insert (Insert*, w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
    }
    virtual void del (Delete*, w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
    }
    virtual void load (Load*, ProductionVector<w3c_sw::URI*>* p_IRIrefs, w3c_sw::URI* p_into) {
	p_IRIrefs->express(this);
	p_into->express(this);
    }
    virtual void clear (Clear*, w3c_sw::URI* p__QGraphIRI_E_Opt) {
	p__QGraphIRI_E_Opt->express(this);
    }
    virtual void create (Create*, w3c_sw::e_Silence, w3c_sw::URI* p_GraphIRI) {
	p_GraphIRI->express(this);
    }
    virtual void drop (Drop*, w3c_sw::e_Silence, w3c_sw::URI* p_GraphIRI) {
	p_GraphIRI->express(this);
    }
    virtual void varExpression (VarExpression*, w3c_sw::Variable* p_Variable) {
	p_Variable->express(this);
    }
    virtual void literalExpression (LiteralExpression*, w3c_sw::RDFLiteral* p_RDFLiteral) {
	p_RDFLiteral->express(this);
    }
    virtual void booleanExpression (BooleanExpression*, w3c_sw::BooleanRDFLiteral* p_BooleanRDFLiteral) {
	p_BooleanRDFLiteral->express(this);
    }
    virtual void uriExpression (URIExpression*, w3c_sw::URI* p_URI) {
	p_URI->express(this);
    }
    virtual void argList (ArgList*, ProductionVector<w3c_sw::Expression*>* expressions) {
	expressions->express(this);
    }
    virtual void functionCall (FunctionCall*, w3c_sw::URI* p_IRIref, w3c_sw::ArgList* p_ArgList) {
	p_IRIref->express(this);
	p_ArgList->express(this);
    }
    virtual void functionCallExpression (FunctionCallExpression*, w3c_sw::FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
    }
/* Expressions */
    virtual void booleanNegation (BooleanNegation*, w3c_sw::Expression* p_Expression) {
	p_Expression->express(this);
    }
    virtual void arithmeticNegation (ArithmeticNegation*, w3c_sw::Expression* p_Expression) {
	p_Expression->express(this);
    }
    virtual void arithmeticInverse (ArithmeticInverse*, w3c_sw::Expression* p_Expression) {
	p_Expression->express(this);
    }
    virtual void booleanConjunction (BooleanConjunction*, ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void booleanDisjunction (BooleanDisjunction*, ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void booleanNegation (BooleanNegation*, ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void arithmeticSum (ArithmeticSum*, ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void arithmeticProduct (ArithmeticProduct*, ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void arithmeticInverse (ArithmeticInverse*, ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    }
    virtual void booleanEQ (BooleanEQ*, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanNE (BooleanNE*, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanLT (BooleanLT*, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanGT (BooleanGT*, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanLE (BooleanLE*, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }
    virtual void booleanGE (BooleanGE*, w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    }    virtual void comparatorExpression (ComparatorExpression*, w3c_sw::BooleanComparator* p_BooleanComparator) {
	p_BooleanComparator->express(this);
    }
    virtual void numberExpression (NumberExpression*, w3c_sw::NumericRDFLiteral* p_NumericRDFLiteral) {
	p_NumericRDFLiteral->express(this);
    }
};
class TestExpressor : public RecursiveExpressor {
    virtual void base (Base*, std::string) { throw(std::runtime_error("hit base in TestExpressor")); }
};

} //namespace w3c_sw



#endif /* ! defined SWOBJECTS_HH */
