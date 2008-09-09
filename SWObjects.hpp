/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.hpp,v 1.5 2008-09-09 09:37:00 eric Exp $
 */

#ifndef SWOBJECTS_HH
# define SWOBJECTS_HH

#include <map>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

#include <cstdarg>
#include <cassert>
#include <typeinfo>

#define TAB "  "
#define ns "\n xmlns=\"http://www.w3.org/2005/01/yacker/uploads/SPARQLfed/\"\n xmlns:yacker=\"http://www.w3.org/2005/01/yacker/\""

namespace w3c_sw {

class StringException : public std::exception {
public:
    char const* str;
    char const* what() const throw() { return str; }
    static std::map<StringException*, std::string> strs;
    StringException (std::string m) : str(m.c_str()) { strs[this] = m; }
    virtual ~StringException () throw() { strs.erase(this); }
};

class Expressor;
class RecursiveExpressor;

class Base {
public:
    Base () { }
    virtual ~Base() { }
    virtual Base* express(Expressor* p_expressor);
};

template <typename T> class ProductionVector : public Base {
    std::vector<T> data;
public:
    ProductionVector () {  }
    ProductionVector (T v) { data.push_back(v); }
    ~ProductionVector () {
	for (size_t i = 0; i < data.size(); i++)
	    delete data[i];
    }

    void push_back(T v) {
	assert(v != NULL); // @DEBUG
	data.push_back(v);
    }
    size_t size () { return data.size(); }
    virtual T operator [] (size_t i) { return data[i]; }
    virtual T at (size_t i) { return data.at(i); }
    void clear () { data.clear(); }
    void pop_back () { data.pop_back(); }
    virtual Base* express(Expressor* p_expressor) {
	for (size_t i = 0; i < data.size(); i++)
	    data[i]->express(p_expressor);
	return NULL;
    }
    typename std::vector<T>::iterator begin () { return data.begin(); }
    typename std::vector<T>::iterator end () { return data.end(); }
    void erase (typename std::vector<T>::iterator it) { data.erase(it); }
#if 0
    class iterator;
    iterator begin() { return iterator(data.begin(), this); }
    iterator end() { return iterator(data.end(), this); }
#endif
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
    virtual Operation* express(Expressor* p_expressor) = 0;
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
    POS (std::string matched) : Terminal(matched) { }
    POS (std::string matched, bool gensym) : Terminal(matched, gensym) { }
    //    virtual int compareType (POS* to) = 0;
public:
    virtual bool isConstant () { return true; } // Override for variable types.
    static bool orderByType (const POS*, const POS*) { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
    virtual int compare (POS* to, Result*) const {
	bool same = typeid(*to) == typeid(*this);
	return same ? getTerminal() != to->getTerminal() : orderByType(this, to);
    }
    virtual bool bindVariable (const POS* p, ResultSet*, Result*, bool) const {
	return p == this || (typeid(*p) == typeid(*this) && getTerminal() == p->getTerminal());
    }
    virtual POS* eval (Result*) { return this; }
    virtual POS* express(Expressor* p_expressor) = 0;
    virtual std::string getBindingAttributeName() = 0;
    virtual std::string toString() = 0;
};

class URI : public POS {
    friend class POSFactory;
private:
    URI (std::string str) : POS(str) {  }
public:
    ~URI () { }
    virtual const char * getToken () { return "-POS-"; }
    virtual URI* express(Expressor* p_expressor);
    virtual std::string toString () { std::stringstream s; s << "<" << terminal << ">"; return s.str(); }
    virtual std::string getBindingAttributeName () { return "uri"; }
};

class Bindable : public POS {
protected:
    Bindable (std::string str) : POS(str) {  }
    Bindable (std::string str, bool gensym) : POS(str, gensym) {  }
public:
    virtual bool isConstant () { return false; }
    virtual bool bindVariable(const POS* p, ResultSet* rs, Result* provisional, bool weaklyBound) const;
};

class Variable : public Bindable {
    friend class POSFactory;
private:
    Variable (std::string str) : Bindable(str) {  }
public:
    virtual std::string toString () { std::stringstream s; s << "?" << terminal; return s.str(); }
    virtual const char * getToken () { return "-Variable-"; }
    virtual Variable* express(Expressor* p_expressor);
    virtual POS* eval(Result* r);
    virtual std::string getBindingAttributeName () { return "name"; }
};

class BNode : public Bindable {
    friend class POSFactory;
private:
    BNode (std::string str) : Bindable(str) {  }
    BNode () : Bindable("gensym:", true) {  }
public:
    virtual std::string toString () { std::stringstream s; s << "_:" << terminal; return s.str(); }
    virtual const char * getToken () { return "-BNode-"; }
    virtual BNode* express(Expressor* p_expressor);
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
    virtual std::string toString () {
	std::stringstream s;
	s << "\"" << terminal << "\"";
	if (datatype) s << datatype->toString();
	if (m_LANGTAG) s << m_LANGTAG->getTerminal();
	return s.str();
    }
    virtual RDFLiteral* express(Expressor* p_expressor);
    virtual std::string getBindingAttributeName () { return "literal"; }
};
class NumericRDFLiteral : public RDFLiteral {
    friend class POSFactory;
protected:
    NumericRDFLiteral (std::string p_String, URI* p_URI, std::string matched) : RDFLiteral(p_String, p_URI, NULL, matched) {  }
    ~NumericRDFLiteral () {  }
public:
    virtual NumericRDFLiteral* express(Expressor* p_expressor) = 0;
};
class IntegerRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    int m_value;
    IntegerRDFLiteral (std::string p_String, URI* p_URI, std::string matched, int p_value) : NumericRDFLiteral(p_String, p_URI, matched), m_value(p_value) {  }
    ~IntegerRDFLiteral () {  }
public:
    int getValue () { return m_value; }
    virtual std::string toString () { std::stringstream s; s << m_value; return s.str(); }
    virtual NumericRDFLiteral* express(Expressor* p_expressor);
};
class DecimalRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    float m_value;
    DecimalRDFLiteral (std::string p_String, URI* p_URI, std::string matched, float p_value) : NumericRDFLiteral(p_String, p_URI, matched), m_value(p_value) {  }
    ~DecimalRDFLiteral () {  }
    virtual NumericRDFLiteral* express(Expressor* p_expressor);
public:
    virtual std::string toString () { std::stringstream s; s << m_value; return s.str(); }
};
class DoubleRDFLiteral : public NumericRDFLiteral {
    friend class POSFactory;
protected:
    double m_value;
    DoubleRDFLiteral (std::string p_String, URI* p_URI, std::string matched, double p_value) : NumericRDFLiteral(p_String, p_URI, matched), m_value(p_value) {  }
    ~DoubleRDFLiteral () {  }
    virtual NumericRDFLiteral* express(Expressor* p_expressor);
};
class BooleanRDFLiteral : public RDFLiteral {
    friend class POSFactory;
protected:
    bool m_value;
    BooleanRDFLiteral (std::string p_String, std::string matched, bool p_value) : RDFLiteral(p_String, NULL, NULL, matched), m_value(p_value) {  }
public:
    virtual std::string toString () { std::stringstream s; s << (m_value ? "true" : "false"); return s.str(); }
    virtual BooleanRDFLiteral* express(Expressor* p_expressor);
};
class NULLpos : public POS {
    friend class POSFactory;
private:
    NULLpos () : POS("NULL", "") {  }
    ~NULLpos () {  }
public:
    virtual const char * getToken () { return "-NULL-"; }
    virtual std::string toString () { std::stringstream s; s << "NULL"; return s.str(); }
    virtual NULLpos* express(Expressor* p_expressor);
    virtual std::string getBindingAttributeName () { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
};

class POSFactory {
    typedef std::map<std::string, Variable*> VariableMap;
    typedef std::map<std::string, BNode*> BNodeMap;
    typedef std::map<std::string, URI*> URIMap;
    typedef std::map<std::string, RDFLiteral*> RDFLiteralMap;
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
    NULLpos		nullPOS;
    NumericRDFLiteral* getNumericRDFLiteral(std::string p_String, const char* type, MakeNumericRDFLiteral* maker);

public:
    POSFactory () {  }
    ~POSFactory();
    Variable* getVariable(std::string name);
    BNode* createBNode();
    BNode* getBNode(std::string name);
    URI* getURI(std::string name);
    RDFLiteral* getRDFLiteral(std::string p_String, URI* p_URI, LANGTAG* p_LANGTAG);

    IntegerRDFLiteral* getNumericRDFLiteral(std::string p_String, int p_value);
    DecimalRDFLiteral* getNumericRDFLiteral(std::string p_String, float p_value);
    DoubleRDFLiteral* getNumericRDFLiteral(std::string p_String, double p_value);

    BooleanRDFLiteral* getBooleanRDFLiteral(std::string p_String, bool p_value);
    NULLpos* getNULL () { return &nullPOS; }

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

class BasicGraphPattern;

class TriplePattern : public Base {
private:
    POS* m_s; POS* m_p; POS* m_o;
    bool weaklyBound;
public:
    TriplePattern (POS* p_s, POS* p_p, POS* p_o) : Base(), m_s(p_s), m_p(p_p), m_o(p_o), weaklyBound(false) {  }
    TriplePattern (TriplePattern const& copy, bool weaklyBound) : Base(), m_s(copy.m_s), m_p(copy.m_p), m_o(copy.m_o), weaklyBound(weaklyBound) {  }
    ~TriplePattern () {  }
    std::string toString () {
	std::stringstream s;
	s << m_p->toString() << m_p->toString() << m_p->toString();
	return s.str();
    }
    virtual TriplePattern* express(Expressor* p_expressor);
    bool bindVariables(TriplePattern* tp, bool optional, ResultSet* rs, POS* graphVar, ResultSetIterator provisional, POS* graphName);
    bool construct(BasicGraphPattern* target, Result* r);
};
/* END Parts Of Speach */

class Expression : public Base, public EvalInterface {
private:
public:
    Expression () : Base() { }
    ~Expression () {  }
    virtual Expression* express(Expressor* p_expressor) = 0;
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
    virtual Filter* express(Expressor* p_expressor);
};
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
    virtual TableOperation* express(Expressor*) = 0;
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
    size_t size () { return m_TableOperations.size(); }
};
class TableConjunction : public TableJunction { // ⊍
public:
    TableConjunction () : TableJunction() {  }
    virtual TableConjunction* express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB*, ResultSet* rs);
    virtual TableOperation* getDNF();
};
class TableDisjunction : public TableJunction { // ⊎
public:
    TableDisjunction () : TableJunction() {  }
    virtual TableDisjunction* express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB*, ResultSet* rs);
    virtual TableOperation* getDNF();
};
class DontDeleteThisBGP;
class BasicGraphPattern : public TableOperation { // ⊌⊍
protected:
    ProductionVector<TriplePattern*> m_TriplePatterns;
    bool allOpts;
    BasicGraphPattern (bool allOpts) : TableOperation(), m_TriplePatterns(), allOpts(allOpts) {  }

public:
    void addTriplePattern (POS* s, POS* p, POS* o) { m_TriplePatterns.push_back(new TriplePattern(s, p, o)); }
    void addTriplePattern (TriplePattern* p) { m_TriplePatterns.push_back(p); }
    size_t triplePatterns () { return m_TriplePatterns.size(); }
    void bindVariables(ResultSet* rs, POS* graphVar, BasicGraphPattern* toMatch, POS* graphName);
    void construct(BasicGraphPattern* target, ResultSet* rs);
    std::vector<TriplePattern*>::iterator begin () { return m_TriplePatterns.begin(); }
    std::vector<TriplePattern*>::iterator end () { return m_TriplePatterns.end(); }
    void erase (std::vector<TriplePattern*>::iterator it) { m_TriplePatterns.erase(it); }
    void clearTriples () { m_TriplePatterns.clear(); }
    virtual TableOperation* getDNF ();
    virtual BasicGraphPattern* express(Expressor* p_expressor) = 0;
};
class DontDeleteThisBGP : public TableOperation {
protected: BasicGraphPattern* bgp;
public:
    DontDeleteThisBGP (BasicGraphPattern* bgp) : bgp(bgp) {  }
    ~DontDeleteThisBGP () { /* Leave bgp alone. */ }
    virtual void bindVariables(RdfDB*, ResultSet*) { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
    virtual TableOperation* getDNF () { return new DontDeleteThisBGP(bgp); }
    virtual BasicGraphPattern* express (Expressor* p_expressor) { return bgp->express(p_expressor); }
};

class NamedGraphPattern : public BasicGraphPattern {
private:
    POS* m_name;

public:
    NamedGraphPattern (POS* p_name, bool allOpts = false) : BasicGraphPattern(allOpts), m_name(p_name) {  }
    virtual NamedGraphPattern* express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB* db, ResultSet* rs);
};
class DefaultGraphPattern : public BasicGraphPattern {
public:
    DefaultGraphPattern (bool allOpts = false) : BasicGraphPattern(allOpts) {  }
    virtual DefaultGraphPattern* express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB* db, ResultSet* rs);
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
    virtual GraphGraphPattern* express(Expressor* p_expressor);
    virtual void bindVariables (RdfDB* db, ResultSet* rs) {
	m_TableOperation->bindVariables(db, rs);
    }
    virtual TableOperationOnOperation* makeANewThis (TableOperation* p_TableOperation) { return new GraphGraphPattern(m_VarOrIRIref, p_TableOperation); }
};
class OptionalGraphPattern : public TableOperationOnOperation {
public:
    OptionalGraphPattern (TableOperation* p_GroupGraphPattern) : TableOperationOnOperation(p_GroupGraphPattern) {  }
    virtual OptionalGraphPattern* express(Expressor* p_expressor);
    virtual void bindVariables(RdfDB*, ResultSet* rs);
    virtual TableOperationOnOperation* makeANewThis (TableOperation* p_TableOperation) { return new OptionalGraphPattern(p_TableOperation); }
};

class VarSet : public Base {
protected:
    VarSet () : Base() { }
public:
    virtual VarSet* express(Expressor*) = 0;
};

class POSList : public VarSet {
private:
    ProductionVector<POS*> m_POSs;
public:
    POSList () : VarSet(), m_POSs() {  }
    ~POSList () { m_POSs.clear(); }
    void push_back(POS* v) { m_POSs.push_back(v); }
    virtual POSList* express(Expressor* p_expressor);
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
    virtual StarVarSet* express(Expressor* p_expressor);
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
    virtual DatasetClause* express(Expressor* p_expressor) = 0;
};
class DefaultGraphClause : public DatasetClause {
private:
public:
    DefaultGraphClause (POS* p_IRIref, POSFactory* p_posFactory) : DatasetClause(p_IRIref, p_posFactory) { }
    ~DefaultGraphClause () {  }
    virtual DefaultGraphClause* express(Expressor* p_expressor);
    virtual void loadData(RdfDB*);
};
class NamedGraphClause : public DatasetClause {
private:
public:
    NamedGraphClause (POS* p_IRIref, POSFactory* p_posFactory) : DatasetClause(p_IRIref, p_posFactory) { }
    ~NamedGraphClause () {  }
    virtual NamedGraphClause* express(Expressor* p_expressor);
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
    virtual SolutionModifier* express(Expressor* p_expressor);
};
class Binding : public ProductionVector<POS*> {
private:
public:
    Binding () : ProductionVector<POS*>() {  }
    ~Binding () { clear(); /* atoms in vector are centrally managed */ }
    virtual Binding* express(Expressor* p_expressor);
    void bindVariables(RdfDB* db, ResultSet* rs, Result* r, POSList* p_Vars);
};
class BindingClause : public ProductionVector<Binding*> {
private:
    POSList* m_Vars;
public:
    BindingClause (POSList* p_Vars) : ProductionVector<Binding*>(), m_Vars(p_Vars) {  }
    ~BindingClause () { delete m_Vars; }
    virtual BindingClause* express(Expressor* p_expressor);
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
    virtual WhereClause* express(Expressor* p_expressor);
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
    virtual Select* express(Expressor* p_expressor);
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
    virtual Construct* express(Expressor* p_expressor);
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
    virtual Describe* express(Expressor* p_expressor);
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
    virtual Ask* express(Expressor* p_expressor);
};
class Replace : public Operation {
private:
    WhereClause* m_WhereClause;
    TableOperation* m_GraphTemplate;
public:
    Replace (WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) : Operation(), m_WhereClause(p_WhereClause), m_GraphTemplate(p_GraphTemplate) {  }
    ~Replace () { delete m_WhereClause; delete m_GraphTemplate; }
    virtual Replace* express(Expressor* p_expressor);
};
class Insert : public Operation {
private:
    TableOperation* m_GraphTemplate;
    WhereClause* m_WhereClause;
public:
    Insert (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) : Operation(), m_GraphTemplate(p_GraphTemplate), m_WhereClause(p_WhereClause) {  }
    ~Insert () { delete m_GraphTemplate; delete m_WhereClause; }
    virtual Insert* express(Expressor* p_expressor);
};
class Delete : public Operation {
private:
    TableOperation* m_GraphTemplate;
    WhereClause* m_WhereClause;
public:
    Delete (TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) : Operation(), m_GraphTemplate(p_GraphTemplate), m_WhereClause(p_WhereClause) {  }
    ~Delete () { delete m_GraphTemplate; delete m_WhereClause; }
    virtual Delete* express(Expressor* p_expressor);
};
class Load : public Operation {
private:
    ProductionVector<URI*>* m_IRIrefs;
    URI* m_into;
public:
    Load (ProductionVector<URI*>* p_IRIrefs, URI* p_into) : Operation(), m_IRIrefs(p_IRIrefs), m_into(p_into) {  }
    ~Load () { delete m_IRIrefs; delete m_into; }
    virtual Load* express(Expressor* p_expressor);
};
class Clear : public Operation {
private:
    URI* m__QGraphIRI_E_Opt;
public:
    Clear (URI* p__QGraphIRI_E_Opt) : Operation(), m__QGraphIRI_E_Opt(p__QGraphIRI_E_Opt) { }
    ~Clear () { delete m__QGraphIRI_E_Opt; }
    virtual Clear* express(Expressor* p_expressor);
};
class Create : public Operation {
private:
    e_Silence m_Silence;
    URI* m_GraphIRI;
public:
    Create (e_Silence p_Silence, URI* p_GraphIRI) : Operation(), m_Silence(p_Silence), m_GraphIRI(p_GraphIRI) {  }
    ~Create () { /* m_GraphIRI is centrally managed */ }
    virtual Create* express(Expressor* p_expressor);
};
class Drop : public Operation {
private:
    e_Silence m_Silence;
    URI* m_GraphIRI;
public:
    Drop (e_Silence p_Silence, URI* p_GraphIRI) : Operation(), m_Silence(p_Silence), m_GraphIRI(p_GraphIRI) {  }
    ~Drop () { /* m_GraphIRI is centrally managed */ }
    virtual Drop* express(Expressor* p_expressor);
};

/* kinds of Expressions */
class VarExpression : public Expression {
private:
    Variable* m_Variable;
public:
    VarExpression (Variable* p_Variable) : Expression(), m_Variable(p_Variable) {  }
    ~VarExpression () { /* m_Variable is centrally managed */ }
    virtual VarExpression* express(Expressor* p_expressor);
};
class LiteralExpression : public Expression {
private:
    RDFLiteral* m_RDFLiteral;
public:
    LiteralExpression (RDFLiteral* p_RDFLiteral) : Expression(), m_RDFLiteral(p_RDFLiteral) {  }
    ~LiteralExpression () { /* m_RDFLiteral is centrally managed */ }
    virtual LiteralExpression* express(Expressor* p_expressor);
};
class BooleanExpression : public Expression {
private:
    BooleanRDFLiteral* m_BooleanRDFLiteral;
public:
    BooleanExpression (BooleanRDFLiteral* p_BooleanRDFLiteral) : Expression(), m_BooleanRDFLiteral(p_BooleanRDFLiteral) {  }
    ~BooleanExpression () { /* m_BooleanRDFLiteral is centrally managed */ }
    virtual BooleanExpression* express(Expressor* p_expressor);
};
class URIExpression : public Expression {
private:
    URI* m_URI;
public:
    URIExpression (URI* p_URI) : Expression(), m_URI(p_URI) {  }
    ~URIExpression () { /* m_URI is centrally managed */ }
    virtual URIExpression* express(Expressor* p_expressor);
};

class ArgList : public Base {
private:
    ProductionVector<Expression*>* m__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C;
public:
    ArgList (ProductionVector<Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) : Base(), m__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C(p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {  }
    ~ArgList () { delete m__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C; }
    virtual ArgList* express(Expressor* p_expressor);
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
    virtual FunctionCall* express(Expressor* p_expressor);
};
class FunctionCallExpression : public Expression {
private:
    FunctionCall* m_FunctionCall;
public:
    FunctionCallExpression (FunctionCall* p_FunctionCall) : Expression(), m_FunctionCall(p_FunctionCall) {  }
    ~FunctionCallExpression () { delete m_FunctionCall; }
    virtual FunctionCallExpression* express(Expressor* p_expressor);
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
    virtual BooleanConjunction* express(Expressor* p_expressor);
};
class BooleanDisjunction : public BooleanJunction { // ⋁
public:
    BooleanDisjunction (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : BooleanJunction(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "||"; };
    virtual BooleanDisjunction* express(Expressor* p_expressor);
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
    virtual BooleanComparator* express(Expressor* p_expressor) = 0;
};
class BooleanEQ : public BooleanComparator {
public:
    BooleanEQ (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "="; };
    virtual BooleanEQ* express(Expressor* p_expressor);
};
class BooleanNE : public BooleanComparator {
public:
    BooleanNE (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "!="; };
    virtual BooleanNE* express(Expressor* p_expressor);
};
class BooleanLT : public BooleanComparator {
public:
    BooleanLT (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "<"; };
    virtual BooleanLT* express(Expressor* p_expressor);
};
class BooleanGT : public BooleanComparator {
public:
    BooleanGT (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return ">"; };
    virtual BooleanGT* express(Expressor* p_expressor);
};
class BooleanLE : public BooleanComparator {
public:
    BooleanLE (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return "<="; };
    virtual BooleanLE* express(Expressor* p_expressor);
};
class BooleanGE : public BooleanComparator {
public:
    BooleanGE (Expression* p_Expression) : BooleanComparator(p_Expression) {  }
    virtual const char* getComparisonNotation () { return ">="; };
    virtual BooleanGE* express(Expressor* p_expressor);
};
class ComparatorExpression : public Expression {
private:
    BooleanComparator* m_BooleanComparator;
public:
    ComparatorExpression (BooleanComparator* p_BooleanComparator) : Expression(), m_BooleanComparator(p_BooleanComparator) {  }
    ~ComparatorExpression () { delete m_BooleanComparator; }
    virtual ComparatorExpression* express(Expressor* p_expressor);
};
class BooleanNegation : public UnaryExpression {
public:
    BooleanNegation (Expression* p_PrimaryExpression) : UnaryExpression(p_PrimaryExpression) {  }
    ~BooleanNegation () {  }
    virtual const char* getUnaryOperator () { return "!"; };
    virtual BooleanNegation* express(Expressor* p_expressor);
};
class ArithmeticSum : public NaryExpression {
public:
    ArithmeticSum (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "+"; };    
    virtual ArithmeticSum* express(Expressor* p_expressor);
};
class ArithmeticNegation : public UnaryExpression {
public:
    ArithmeticNegation (Expression* p_MultiplicativeExpression) : UnaryExpression(p_MultiplicativeExpression) {  }
    ~ArithmeticNegation () {  }
    virtual const char* getUnaryOperator () { return "-"; };
    virtual ArithmeticNegation* express(Expressor* p_expressor);
};
class NumberExpression : public Expression {
private:
    NumericRDFLiteral* m_NumericRDFLiteral;
public:
    NumberExpression (NumericRDFLiteral* p_NumericRDFLiteral) : Expression(), m_NumericRDFLiteral(p_NumericRDFLiteral) {  }
    ~NumberExpression () { /* m_NumericRDFLiteral is centrally managed */ }
    virtual NumberExpression* express(Expressor* p_expressor);
};
class ArithmeticProduct : public NaryExpression {
public:
    ArithmeticProduct (Expression* p_Expression, ProductionVector<Expression*>* p_Expressions) : NaryExpression(p_Expression, p_Expressions) {  }
    virtual const char* getInfixNotation () { return "+"; };    
    virtual ArithmeticProduct* express(Expressor* p_expressor);
};
class ArithmeticInverse : public UnaryExpression {
public:
    ArithmeticInverse (Expression* p_UnaryExpression) : UnaryExpression(p_UnaryExpression) {  }
    ~ArithmeticInverse () {  }
    virtual const char* getUnaryOperator () { return "1/"; };
    virtual ArithmeticInverse* express(Expressor* p_expressor);
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

    virtual Base* base(std::string productionName) = 0;

    virtual URI* uri(std::string terminal) = 0;
    virtual Variable* variable(std::string terminal) = 0;
    virtual BNode* bnode(std::string terminal) = 0;
    virtual RDFLiteral* rdfLiteral(std::string terminal, w3c_sw::URI* datatype, w3c_sw::LANGTAG* p_LANGTAG) = 0;
    virtual NumericRDFLiteral* rdfLiteral(int p_value) = 0;
    virtual NumericRDFLiteral* rdfLiteral(float p_value) = 0;
    virtual NumericRDFLiteral* rdfLiteral(double p_value) = 0;
    virtual BooleanRDFLiteral* rdfLiteral(bool p_value) = 0;
    virtual NULLpos* nullpos() = 0;
    virtual TriplePattern* triplePattern(w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) = 0;
    virtual Filter* filter(w3c_sw::Expression* p_Constraint) = 0;
    virtual NamedGraphPattern* namedGraphPattern(w3c_sw::POS* p_name, bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual DefaultGraphPattern* defaultGraphPattern(bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual TableConjunction* tableConjunction(ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual TableDisjunction* tableDisjunction(ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) = 0;
    virtual OptionalGraphPattern* optionalGraphPattern(w3c_sw::TableOperation* p_GroupGraphPattern) = 0;
    virtual GraphGraphPattern* graphGraphPattern(w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) = 0;
    virtual POSList* posList(ProductionVector<w3c_sw::POS*>* p_POSs) = 0;
    virtual StarVarSet* starVarSet() = 0;
    virtual DefaultGraphClause* defaultGraphClause(w3c_sw::POS* p_IRIref) = 0;
    virtual NamedGraphClause* namedGraphClause(w3c_sw::POS* p_IRIref) = 0;
    virtual SolutionModifier* solutionModifier(std::vector<w3c_sw::s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) = 0;
    virtual Binding* binding(ProductionVector<w3c_sw::POS*>* values) = 0;//!!!
    virtual BindingClause* bindingClause(w3c_sw::POSList* p_Vars, ProductionVector<w3c_sw::Binding*>* p_Bindings) = 0;
    virtual WhereClause* whereClause(w3c_sw::TableOperation* p_GroupGraphPattern, w3c_sw::BindingClause* p_BindingClause) = 0;
    virtual Select* select(w3c_sw::e_distinctness p_distinctness, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) = 0;
    virtual Construct* construct(w3c_sw::DefaultGraphPattern* p_ConstructTemplate, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) = 0;
    virtual Describe* describe(w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) = 0;
    virtual Ask* ask(ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause) = 0;
    virtual Replace* replace(w3c_sw::WhereClause* p_WhereClause, w3c_sw::TableOperation* p_GraphTemplate) = 0;
    virtual Insert* insert(w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) = 0;
    virtual Delete* del(w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) = 0;
    virtual Load* load(ProductionVector<w3c_sw::URI*>* p_IRIrefs, w3c_sw::URI* p_into) = 0;
    virtual Clear* clear(w3c_sw::URI* p__QGraphIRI_E_Opt) = 0;
    virtual Create* create(w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) = 0;
    virtual Drop* drop(w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) = 0;
    virtual VarExpression* varExpression(w3c_sw::Variable* p_Variable) = 0;
    virtual LiteralExpression* literalExpression(w3c_sw::RDFLiteral* p_RDFLiteral) = 0;
    virtual BooleanExpression* booleanExpression(w3c_sw::BooleanRDFLiteral* p_BooleanRDFLiteral) = 0;
    virtual URIExpression* uriExpression(w3c_sw::URI* p_URI) = 0;
    virtual ArgList* argList(ProductionVector<w3c_sw::Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) = 0;
    virtual FunctionCall* functionCall(w3c_sw::URI* p_IRIref, w3c_sw::ArgList* p_ArgList) = 0;
    virtual FunctionCallExpression* functionCallExpression(w3c_sw::FunctionCall* p_FunctionCall) = 0;
/* Expressions */
    virtual BooleanNegation* booleanNegation(w3c_sw::Expression* p_Expression) = 0;
    virtual ArithmeticNegation* arithmeticNegation(w3c_sw::Expression* p_Expression) = 0;
    virtual ArithmeticInverse* arithmeticInverse(w3c_sw::Expression* p_Expression) = 0;
    virtual BooleanConjunction* booleanConjunction(ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual BooleanDisjunction* booleanDisjunction(ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual ArithmeticSum* arithmeticSum(ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual ArithmeticProduct* arithmeticProduct(ProductionVector<w3c_sw::Expression*>* p_Expressions) = 0;
    virtual BooleanEQ* booleanEQ(w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual BooleanNE* booleanNE(w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual BooleanLT* booleanLT(w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual BooleanGT* booleanGT(w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual BooleanLE* booleanLE(w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual BooleanGE* booleanGE(w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) = 0;
    virtual ComparatorExpression* comparatorExpression(w3c_sw::BooleanComparator* p_BooleanComparator) = 0;
    virtual NumberExpression* numberExpression(w3c_sw::NumericRDFLiteral* p_NumericRDFLiteral) = 0;
};
/* RecursiveExpressor - default actions for expressor.
 * Use this Expressor when you don't feel like supplying all of the methods.
 */
class RecursiveExpressor : public Expressor {
public:
    virtual URI* uri (std::string) { return NULL; }
    virtual Variable* variable (std::string) { return NULL; }
    virtual BNode* bnode (std::string) { return NULL; }
    virtual RDFLiteral* rdfLiteral (std::string, w3c_sw::URI* datatype, w3c_sw::LANGTAG* p_LANGTAG) {
	datatype->express(this);
	p_LANGTAG->express(this);
    return NULL; }
    virtual NumericRDFLiteral* rdfLiteral (int) { return NULL; }
    virtual NumericRDFLiteral* rdfLiteral (float) { return NULL; }
    virtual NumericRDFLiteral* rdfLiteral (double) { return NULL; }
    virtual BooleanRDFLiteral* rdfLiteral (bool) { return NULL; }
    virtual NULLpos* nullpos () { return NULL; }
    virtual TriplePattern* triplePattern (w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) {
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
    return NULL; }
    virtual Filter* filter (w3c_sw::Expression* p_Constraint) {
	p_Constraint->express(this);
    return NULL; }
    virtual NamedGraphPattern* namedGraphPattern (w3c_sw::POS* p_name, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_name->express(this);
	p_TriplePatterns->express(this);
	p_Filters->express(this);
    return NULL; }
    virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_TriplePatterns->express(this);
	p_Filters->express(this);
    return NULL; }
    virtual TableDisjunction* tableDisjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_TableOperations->express(this);
	p_Filters->express(this);
    return NULL; }
    virtual TableConjunction* tableConjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	p_TableOperations->express(this);
	p_Filters->express(this);
    return NULL; }
    virtual OptionalGraphPattern* optionalGraphPattern (w3c_sw::TableOperation* p_GroupGraphPattern) {
	p_GroupGraphPattern->express(this);
    return NULL; }
    virtual GraphGraphPattern* graphGraphPattern (w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
	p_POS->express(this);
	p_GroupGraphPattern->express(this);
    return NULL; }
    virtual POSList* posList (ProductionVector<w3c_sw::POS*>* p_POSs) {
	p_POSs->express(this);
    return NULL; }
    virtual StarVarSet* starVarSet () { return NULL; }
    virtual DefaultGraphClause* defaultGraphClause (w3c_sw::POS* p_IRIref) {
	p_IRIref->express(this);
    return NULL; }
    virtual NamedGraphClause* namedGraphClause (w3c_sw::POS* p_IRIref) {
	p_IRIref->express(this);
    return NULL; }
    virtual SolutionModifier* solutionModifier (std::vector<w3c_sw::s_OrderConditionPair>* p_OrderConditions, int, int) {
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		p_OrderConditions->at(i).expression->express(this);
	    return NULL; }
    return NULL; }
    virtual Binding* binding (ProductionVector<w3c_sw::POS*>* values) {//!!!
	for (size_t i = 0; i < values->size(); i++)
	    values->at(i)->express(this);
    return NULL; }
    virtual BindingClause* bindingClause (w3c_sw::POSList* p_Vars, ProductionVector<w3c_sw::Binding*>* p_Bindings) {
	p_Vars->express(this);
	p_Bindings->ProductionVector<w3c_sw::Binding*>::express(this);
    return NULL; }
    virtual WhereClause* whereClause (w3c_sw::TableOperation* p_GroupGraphPattern, w3c_sw::BindingClause* p_BindingClause) {
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
    return NULL; }
    virtual Select* select (w3c_sw::e_distinctness, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    return NULL; }
    virtual Construct* construct (w3c_sw::DefaultGraphPattern* p_ConstructTemplate, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    return NULL; }
    virtual Describe* describe (w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
    return NULL; }
    virtual Ask* ask (ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause) {
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
    return NULL; }
    virtual Replace* replace (w3c_sw::WhereClause* p_WhereClause, w3c_sw::TableOperation* p_GraphTemplate) {
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
    return NULL; }
    virtual Insert* insert (w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
    return NULL; }
    virtual Delete* del (w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
    return NULL; }
    virtual Load* load (ProductionVector<w3c_sw::URI*>* p_IRIrefs, w3c_sw::URI* p_into) {
	p_IRIrefs->express(this);
	p_into->express(this);
    return NULL; }
    virtual Clear* clear (w3c_sw::URI* p__QGraphIRI_E_Opt) {
	p__QGraphIRI_E_Opt->express(this);
    return NULL; }
    virtual Create* create (w3c_sw::e_Silence, w3c_sw::URI* p_GraphIRI) {
	p_GraphIRI->express(this);
    return NULL; }
    virtual Drop* drop (w3c_sw::e_Silence, w3c_sw::URI* p_GraphIRI) {
	p_GraphIRI->express(this);
    return NULL; }
    virtual VarExpression* varExpression (w3c_sw::Variable* p_Variable) {
	p_Variable->express(this);
    return NULL; }
    virtual LiteralExpression* literalExpression (w3c_sw::RDFLiteral* p_RDFLiteral) {
	p_RDFLiteral->express(this);
    return NULL; }
    virtual BooleanExpression* booleanExpression (w3c_sw::BooleanRDFLiteral* p_BooleanRDFLiteral) {
	p_BooleanRDFLiteral->express(this);
    return NULL; }
    virtual URIExpression* uriExpression (w3c_sw::URI* p_URI) {
	p_URI->express(this);
    return NULL; }
    virtual ArgList* argList (ProductionVector<w3c_sw::Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
    return NULL; }
    virtual FunctionCall* functionCall (w3c_sw::URI* p_IRIref, w3c_sw::ArgList* p_ArgList) {
	p_IRIref->express(this);
	p_ArgList->express(this);
    return NULL; }
    virtual FunctionCallExpression* functionCallExpression (w3c_sw::FunctionCall* p_FunctionCall) {
	p_FunctionCall->express(this);
    return NULL; }
/* Expressions */
    virtual BooleanNegation* booleanNegation (w3c_sw::Expression* p_Expression) {
	p_Expression->express(this);
    return NULL; }
    virtual ArithmeticNegation* arithmeticNegation (w3c_sw::Expression* p_Expression) {
	p_Expression->express(this);
    return NULL; }
    virtual ArithmeticInverse* arithmeticInverse (w3c_sw::Expression* p_Expression) {
	p_Expression->express(this);
    return NULL; }
    virtual BooleanConjunction* booleanConjunction (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    return NULL; }
    virtual BooleanDisjunction* booleanDisjunction (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    return NULL; }
    virtual BooleanNegation* booleanNegation (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    return NULL; }
    virtual ArithmeticSum* arithmeticSum (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    return NULL; }
    virtual ArithmeticProduct* arithmeticProduct (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    return NULL; }
    virtual ArithmeticInverse* arithmeticInverse (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	p_Expressions->express(this);
    return NULL; }
    virtual BooleanEQ* booleanEQ (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    return NULL; }
    virtual BooleanNE* booleanNE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    return NULL; }
    virtual BooleanLT* booleanLT (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    return NULL; }
    virtual BooleanGT* booleanGT (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    return NULL; }
    virtual BooleanLE* booleanLE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    return NULL; }
    virtual BooleanGE* booleanGE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	p_left->express(this);
	p_right->express(this);
    return NULL; }
    virtual ComparatorExpression* comparatorExpression (w3c_sw::BooleanComparator* p_BooleanComparator) {
	p_BooleanComparator->express(this);
    return NULL; }
    virtual NumberExpression* numberExpression (w3c_sw::NumericRDFLiteral* p_NumericRDFLiteral) {
	p_NumericRDFLiteral->express(this);
    return NULL; }
};

} //namespace w3c_sw



#endif /* ! defined SWOBJECTS_HH */
