/* Algae3.hpp - AST and evaluator for Algae 3, the modern revision of Algae2
 * (the 2004 W3C RDF query language whose action vocabulary seeded SPARQL's
 * semantics section). Design of record: ../algae3/doc/algae3-spec.md.
 *
 * Terms, triples and constraint expressions reuse the SWObjects families
 * (TTerm interned by the AtomFactory, TriplePattern, Expression); the
 * action-pipeline and pattern-combinator layers - which exceed SPARQL's
 * algebra (proof sets, munion, correlated evaluation, scope/share) - get
 * their own nodes here, as the ShEx layer does.
 */

#ifndef INCLUDED_Algae3
#define INCLUDED_Algae3

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "RdfDB.hpp"

#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace w3c_sw {
namespace bnr { class RemoteGraphProvider; struct SPARQLClient; }
namespace a3 {

    enum EvalMode { EVAL_topdown, EVAL_bottomup };

    /* ---------------------------------------------------------- patterns --- */

    struct PatternVisitor;

    struct Pattern {
	virtual ~Pattern () {  }
	virtual void accept (PatternVisitor& v) const = 0;
	virtual std::string str (EvalMode mode) const = 0;
    };

    /** One declaration: subject + property/object list, flattened to triples.
     * Each triple may carry a brace-constraint on its object (evaluated after
     * that triple matches). Blank nodes in triples match like variables but
     * are never exported. */
    struct DeclPattern : public Pattern {
	std::vector<const TriplePattern*> triples;          // interned; not owned
	std::vector<const Expression*> constraints;         // owned; parallel: may be NULL
	virtual ~DeclPattern () {
	    for (std::vector<const Expression*>::const_iterator it = constraints.begin();
		 it != constraints.end(); ++it)
		delete *it;
	}
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    /** A standalone { expr } constraint. */
    struct FilterPattern : public Pattern {
	const Expression* expr; // owned
	FilterPattern (const Expression* expr) : expr(expr) {  }
	virtual ~FilterPattern () { delete expr; }
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    /** ~P (optjoin/leftjoin) and !P (notexists/minus). */
    struct UnaryPattern : public Pattern {
	enum Op { Optional, Negation } op;
	const Pattern* inner; // owned
	UnaryPattern (Op op, const Pattern* inner) : op(op), inner(inner) {  }
	virtual ~UnaryPattern () { delete inner; }
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    /** P . Q . R - conjunction, evaluated left to right. */
    struct ConjPattern : public Pattern {
	std::vector<const Pattern*> elts; // owned
	virtual ~ConjPattern () {
	    for (std::vector<const Pattern*>::const_iterator it = elts.begin();
		 it != elts.end(); ++it)
		delete *it;
	}
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    /** The four loose connectives. */
    struct ConnPattern : public Pattern {
	enum Op { OrElse, Union, MUnion, Diff } op;
	const Pattern* l; // owned
	const Pattern* r; // owned
	ConnPattern (Op op, const Pattern* l, const Pattern* r) : op(op), l(l), r(r) {  }
	virtual ~ConnPattern () { delete l; delete r; }
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    /** in g ( P ) - match P against a named graph (term or variable). */
    struct InGraphPattern : public Pattern {
	const TTerm* graph; // interned
	const Pattern* inner; // owned
	InGraphPattern (const TTerm* graph, const Pattern* inner) : graph(graph), inner(inner) {  }
	virtual ~InGraphPattern () { delete inner; }
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    struct Action;

    /** scope ( P | sub-pipeline ) share (?v...). Bottom-up: evaluates from
     * the unit result set (SPARQL subselect isolation). Top-down: the
     * enclosing bindings flow in (lateral subquery). */
    struct ScopePattern : public Pattern {
	const Pattern* pattern;               // owned; NULL if pipeline form
	std::vector<const Action*> pipeline;  // owned; empty if pattern form
	std::vector<const TTerm*> share;      // interned
	ScopePattern () : pattern(NULL) {  }
	virtual ~ScopePattern ();
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    /** An action usable in pattern position (inline let / bindings). */
    struct ActionPattern : public Pattern {
	const Action* action; // owned
	ActionPattern (const Action* action) : action(action) {  }
	virtual ~ActionPattern ();
	virtual void accept (PatternVisitor& v) const;
	virtual std::string str (EvalMode mode) const;
    };

    struct PatternVisitor {
	virtual ~PatternVisitor () {  }
	virtual void visit (const DeclPattern&) = 0;
	virtual void visit (const FilterPattern&) = 0;
	virtual void visit (const UnaryPattern&) = 0;
	virtual void visit (const ConjPattern&) = 0;
	virtual void visit (const ConnPattern&) = 0;
	virtual void visit (const InGraphPattern&) = 0;
	virtual void visit (const ScopePattern&) = 0;
	virtual void visit (const ActionPattern&) = 0;
    };

    /* ----------------------------------------------------------- actions --- */

    struct Load; struct Attach; struct Ask; struct Test; struct AssertAction;
    struct FwRule; struct Let; struct BindingsAction; struct Collect;
    struct FilterAction;

    struct ActionVisitor {
	virtual ~ActionVisitor () {  }
	virtual void visit (const Load&) = 0;
	virtual void visit (const Attach&) = 0;
	virtual void visit (const Ask&) = 0;
	virtual void visit (const Test&) = 0;
	virtual void visit (const AssertAction&) = 0;
	virtual void visit (const FwRule&) = 0;
	virtual void visit (const Let&) = 0;
	virtual void visit (const BindingsAction&) = 0;
	virtual void visit (const Collect&) = 0;
	virtual void visit (const FilterAction&) = 0;
    };

    struct Action {
	virtual ~Action () {  }
	virtual void accept (ActionVisitor& v) const = 0;
	virtual std::string str (EvalMode mode) const = 0;
    };

    /** load <iri> [as g]: parse the document, MERGE into the working graph
     * (blank nodes standardized apart); `as` leaves the working graph
     * untouched (the contract sparql-to-algae3.md section 1 fixes). */
    struct Load : public Action {
	const TTerm* iri;   // interned
	const TTerm* as;    // interned; NULL = working graph
	Load (const TTerm* iri, const TTerm* as) : iri(iri), as(as) {  }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** attach: parsed for Algae2 compatibility; evaluation rejects it. */
    struct Attach : public Action {
	const TTerm* driver;
	std::string name;
	Attach (const TTerm* driver, std::string name) : driver(driver), name(name) {  }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    struct Ask : public Action {
	const Pattern* pattern; // owned
	Ask (const Pattern* pattern) : pattern(pattern) {  }
	virtual ~Ask () { delete pattern; }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** test (P): result set unchanged; exposes a boolean (SPARQL ASK). */
    struct Test : public Action {
	const Pattern* pattern; // owned
	Test (const Pattern* pattern) : pattern(pattern) {  }
	virtual ~Test () { delete pattern; }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** assert [into g] (T): per result, instantiate the template triples. */
    struct AssertAction : public Action {
	const TTerm* into;      // NULL = working graph
	const Pattern* tmplt;   // owned; declarations only
	AssertAction (const TTerm* into, const Pattern* tmplt) : into(into), tmplt(tmplt) {  }
	virtual ~AssertAction () { delete tmplt; }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    struct FwRule : public Action {
	const Ask* ask;             // owned
	const AssertAction* assrt;  // owned
	FwRule (const Ask* ask, const AssertAction* assrt) : ask(ask), assrt(assrt) {  }
	virtual ~FwRule () { delete ask; delete assrt; }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** let (?v expr) - SPARQL BIND. */
    struct Let : public Action {
	const TTerm* var;       // interned
	const Expression* expr; // owned
	Let (const TTerm* var, const Expression* expr) : var(var), expr(expr) {  }
	virtual ~Let () { delete expr; }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** bindings (?v...) { (...)... } - SPARQL VALUES; NULL cell = UNDEF. */
    struct BindingsAction : public Action {
	std::vector<const TTerm*> vars;
	std::vector<std::vector<const TTerm*> > rows;
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** One collect projection: a plain variable or (expr as ?v). */
    struct Projection {
	const TTerm* var;       // interned
	const Expression* expr; // owned; NULL for a plain variable
	Projection (const TTerm* var, const Expression* expr) : var(var), expr(expr) {  }
    };

    struct OrderCond {
	bool descending;
	const Expression* expr; // owned
	OrderCond (bool descending, const Expression* expr)
	    : descending(descending), expr(expr) {  }
    };

    struct Collect : public Action {
	bool distinct;
	bool star;                          // collect (*)
	std::vector<Projection> projections;
	std::vector<const TTerm*> groupBy;  // `by (...)`; empty = no grouping
	std::vector<OrderCond> order;
	long limit;   // -1 = none
	long offset;  // 0 = none
	Collect () : distinct(false), star(false), limit(-1), offset(0) {  }
	virtual ~Collect () {
	    for (std::vector<Projection>::const_iterator it = projections.begin();
		 it != projections.end(); ++it)
	        delete it->expr;
	    for (std::vector<OrderCond>::const_iterator it = order.begin();
		 it != order.end(); ++it)
	        delete it->expr;
	}
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /** A standalone { expr } as an action (HAVING when it follows an
     * aggregating collect). */
    struct FilterAction : public Action {
	const Expression* expr; // owned
	FilterAction (const Expression* expr) : expr(expr) {  }
	virtual ~FilterAction () { delete expr; }
	virtual void accept (ActionVisitor& v) const { v.visit(*this); }
	virtual std::string str (EvalMode mode) const;
    };

    /* ------------------------------------------------------------- query --- */

    struct Query {
	EvalMode mode;
	std::vector<std::string> features;   // require IRIs (verbatim)
	std::vector<const Action*> actions;  // owned
	Query () : mode(EVAL_topdown) {  }
	~Query () {
	    for (std::vector<const Action*>::const_iterator it = actions.begin();
		 it != actions.end(); ++it)
		delete *it;
	}
	std::string str () const;
    };

    /* -------------------------------------------------------- aggregates --- */

    /** An aggregate call inside a collect projection expression. Evaluates
     * over Engine::currentGroup - the engine sets the group before evaluating
     * projection expressions, so aggregates nest freely inside ordinary
     * expressions (concat(group_concat(?x, ","), ...)). */
    struct AggregateExpr : public Expression {
	enum Func { Count, CountStar, Sum, Min, Max, Avg, Sample, GroupConcat } func;
	bool distinct;
	const Expression* arg;       // owned; NULL for count(*)
	std::string separator;       // group_concat only
	AggregateExpr (Func func, bool distinct, const Expression* arg, std::string separator)
	    : func(func), distinct(distinct), arg(arg), separator(separator) {  }
	virtual ~AggregateExpr () { delete arg; }
	virtual void express (Expressor*) const;
	virtual const TTerm* eval (const Result* r, AtomFactory* atomFactory,
				   BNodeEvaluator* evaluator, TTerm::String2BNode* bnodeMap,
				   const RdfDB* db) const;
	virtual bool operator== (const Expression&) const { return false; }
    };

    /* ------------------------------------------------------------ engine --- */

    typedef std::set<const TriplePattern*> ProofSet;

    /** The evaluator. Owns a dataset and a result set; each action maps
     * ResultSet -> ResultSet. Proof sets ride in a side table keyed by row. */
    class Engine {
    public:
	AtomFactory* atomFactory;
	RdfDB db;
	EvalMode mode;
	bool lastTest;           // set by `test`
	std::string baseDir;     // directory for resolving load paths

	/** remote execution: when set, bgpmatch faults each substituted
	 * triple pattern through the provider (told-bnode seeds expand to
	 * their identifying fragments) before matching the local cache */
	bnr::RemoteGraphProvider* remote = NULL; // borrowed unless via attach
	/** `attach <endpoint> name` creates a provider over a client from
	 * this factory (tests inject a local relabeling double) */
	static bnr::SPARQLClient* (*attachClientFactory) (const std::string& iri,
							  AtomFactory* atomFactory);
	std::vector<bnr::SPARQLClient*> ownedClients;        // from attach
	std::vector<bnr::RemoteGraphProvider*> ownedProviders;

	/** rows are sw::Results inside an sw::ResultSet (so sw::Expression
	 * evaluation applies natively); proofs keyed by row pointer. */
	ResultSet* rs;           // owned
	std::map<const Result*, ProofSet> proofs;

	/** asserted triples reported by the last assert/fwrule */
	std::vector<const TriplePattern*> asserted;

	/** aggregate evaluation context (see AggregateExpr) */
	static const std::vector<const Result*>* currentGroup;
	static const std::map<const Result*, ProofSet>* currentProofs;
	static const RdfDB* currentDB;
	static AtomFactory* currentFactory;

	Engine (AtomFactory* atomFactory, EvalMode mode);
	~Engine ();

	/** run a whole query (actions in document order) */
	void run (const Query& q);
	/** run one action */
	void apply (const Action& a);
	/** evaluate a pattern over the current result set (the `ask` body) */
	void ask (const Pattern& p);

	/** speculative match: evaluate p over a COPY of the current result
	 * set, report (extended, dropped) row counts, discard everything. */
	std::pair<size_t, size_t> tryMatch (const Pattern& p);

	void reset ();           // back to unit result set + empty dataset
	std::string renderTable (size_t maxRows = 0, bool showProofs = false) const;

	/** delete an intermediate result set, dropping its rows' proof
	 * entries (stale pointer keys could collide with later rows) */
	void freeRS (ResultSet* dead);

	/* evaluation plumbing (public: the Evaluator/Applier visitors and the
	 * debugger use these) */
	ResultSet* evalPattern (ResultSet* in, const Pattern& p,
				const BasicGraphPattern* graph, bool ownIn);
	ResultSet* unitRS () const;
	void replaceRS (ResultSet* newRS);
    };

    /** in-scope (mentioned) variables of a pattern - for collect (*). */
    void inScopeVars (const Pattern& p, std::vector<const TTerm*>& into);

} // namespace a3
} // namespace w3c_sw

#endif /* INCLUDED_Algae3 */
