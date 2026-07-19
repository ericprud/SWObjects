/* Algae3.cpp - the Algae 3 evaluator: an action pipeline threading a
 * ResultSet (with per-row proof sets) through a dataset, with the two
 * evaluation modes of ../algae3/doc/algae3-spec.md section 6:
 *
 * - top-down (Algae native): eval(R, P . Q) = eval(eval(R, P), Q); `~`, `!`
 *   and scope are CORRELATED - bindings flow in per row (SQL LATERAL).
 * - bottom-up (SPARQL algebra): every operand evaluates from the unit result
 *   set; `.` is Join, `~` is LeftJoin, `!` is Minus (vacuous when domains
 *   are disjoint - the negation-scoped demo); scope isolates a subselect.
 *
 * Interpretation notes (flagged, not silently decided):
 * - `||` (orelse) is set-level in both modes: Q evaluates only if P yielded
 *   no results over the incoming result set.
 * - `|!` (diff) is the strict antijoin of the spec's section 5 table
 *   ("results of P not compatible with any of Q") in both modes; bottom-up
 *   `!P` is SPARQL Minus, which additionally keeps domain-disjoint rows.
 */

#include "Algae3.hpp"
#include "TurtleParser.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace w3c_sw {
namespace a3 {

    const std::vector<const Result*>* Engine::currentGroup = NULL;
    const std::map<const Result*, ProofSet>* Engine::currentProofs = NULL;
    const RdfDB* Engine::currentDB = NULL;
    AtomFactory* Engine::currentFactory = NULL;

    /* ------------------------------------------------------------ helpers --- */

    namespace {

	/** value comparison for ORDER BY and distinct: numerics by value,
	 * else by type rank then lexical form. Unbound sorts first. */
	int cmpTerms (const TTerm* l, const TTerm* r) {
	    if (l == r) return 0;
	    bool lu = (l == NULL || l == TTerm::Unbound), ru = (r == NULL || r == TTerm::Unbound);
	    if (lu || ru) return lu && ru ? 0 : lu ? -1 : 1;
	    const NumericRDFLiteral* ln = dynamic_cast<const NumericRDFLiteral*>(l);
	    const NumericRDFLiteral* rn = dynamic_cast<const NumericRDFLiteral*>(r);
	    if (ln != NULL && rn != NULL) {
		double lv = ln->getDouble(), rv = rn->getDouble();
		return lv < rv ? -1 : lv > rv ? 1 : 0;
	    }
	    int lt = dynamic_cast<const BNode*>(l) ? 0 : dynamic_cast<const URI*>(l) ? 1 : 2;
	    int rt = dynamic_cast<const BNode*>(r) ? 0 : dynamic_cast<const URI*>(r) ? 1 : 2;
	    if (lt != rt) return lt < rt ? -1 : 1;
	    std::string ls = l->getLexicalValue(), rs = r->getLexicalValue();
	    return ls < rs ? -1 : ls > rs ? 1 : 0;
	}

	bool isVarish (const TTerm* t) {
	    return dynamic_cast<const Variable*>(t) != NULL
		|| dynamic_cast<const BNode*>(t) != NULL;
	}

	/** two rows are compatible iff they agree on every shared variable */
	bool compatible (const Result* a, const Result* b) {
	    for (BindingSetConstIterator it = b->begin(); it != b->end(); ++it) {
		const TTerm* av = a->get(it->first);
		if (av != NULL && av != it->second.tterm)
		    return false;
	    }
	    return true;
	}

	bool sameBindings (const Result* a, const Result* b) {
	    return compatible(a, b)
		&& std::distance(a->begin(), a->end()) == std::distance(b->begin(), b->end());
	}

	bool domainsOverlap (const Result* a, const Result* b) {
	    for (BindingSetConstIterator it = b->begin(); it != b->end(); ++it)
		if (a->get(it->first) != NULL)
		    return true;
	    return false;
	}
    } // namespace

    /* ------------------------------------------------------------- engine --- */

    Engine::Engine (AtomFactory* atomFactory, EvalMode mode)
	: atomFactory(atomFactory), mode(mode), lastTest(false), rs(NULL) {
	rs = new ResultSet(atomFactory); // the unit result set
    }

    Engine::~Engine () { delete rs; }

    ResultSet* Engine::unitRS () const { return new ResultSet(atomFactory); }

    /** delete an intermediate result set, dropping its rows' proof entries
     * (proofs are keyed by row pointer; stale keys could collide with later
     * allocations) */
    void Engine::freeRS (ResultSet* dead) {
	if (dead == NULL)
	    return;
	for (ResultSetIterator it = dead->begin(); it != dead->end(); ++it)
	    proofs.erase(*it);
	delete dead;
    }

    void Engine::replaceRS (ResultSet* newRS) {
	/* drop proofs for rows that no longer exist */
	std::set<const Result*> live;
	for (ResultSetIterator it = newRS->begin(); it != newRS->end(); ++it)
	    live.insert(*it);
	for (std::map<const Result*, ProofSet>::iterator it = proofs.begin();
	     it != proofs.end(); ) {
	    if (live.find(it->first) == live.end())
		proofs.erase(it++);
	    else
		++it;
	}
	if (rs != newRS)
	    delete rs;
	rs = newRS;
    }

    void Engine::reset () {
	replaceRS(new ResultSet(atomFactory));
	db.clearTriples();
	asserted.clear();
	lastTest = false;
    }

    /* copy a row (bindings + proofs) into dst */
    static Result* copyRow (ResultSet* dst, const Result* src,
			    std::map<const Result*, ProofSet>& proofs) {
	Result* nw = new Result(dst);
	dst->insert(dst->end(), nw);
	for (BindingSetConstIterator it = src->begin(); it != src->end(); ++it)
	    dst->set(nw, it->first, it->second.tterm, false);
	std::map<const Result*, ProofSet>::const_iterator p = proofs.find(src);
	if (p != proofs.end())
	    proofs[nw] = p->second;
	return nw;
    }

    /** merge rows a+b into dst iff compatible; returns NULL otherwise */
    static Result* mergeRows (ResultSet* dst, const Result* a, const Result* b,
			      std::map<const Result*, ProofSet>& proofs) {
	if (!compatible(a, b))
	    return NULL;
	Result* nw = copyRow(dst, a, proofs);
	for (BindingSetConstIterator it = b->begin(); it != b->end(); ++it)
	    if (nw->get(it->first) == NULL)
		dst->set(nw, it->first, it->second.tterm, false);
	std::map<const Result*, ProofSet>::const_iterator p = proofs.find(b);
	if (p != proofs.end())
	    proofs[nw].insert(p->second.begin(), p->second.end());
	return nw;
    }

    /* ------------------------------------------------------- BGP matching --- */

    namespace {
	struct Binding { const TTerm* var; const TTerm* val; };
    }

    /** recursive per-triple match with substitution (Algae2's declaration
     * evaluation). Query blank nodes match like variables but are dropped
     * from the emitted rows. */
    struct BGPMatcher {
	Engine& e;
	const DeclPattern& decl;
	const BasicGraphPattern* graph;
	const Result* seed;
	ResultSet* out;

	std::vector<Binding> overlay;
	std::vector<const TriplePattern*> matched;

	BGPMatcher (Engine& e, const DeclPattern& decl, const BasicGraphPattern* graph,
		    const Result* seed, ResultSet* out)
	    : e(e), decl(decl), graph(graph), seed(seed), out(out) {  }

	const TTerm* lookup (const TTerm* t) const {
	    if (!isVarish(t))
		return t;
	    if (dynamic_cast<const Variable*>(t) != NULL) {
		const TTerm* b = seed->get(t);
		if (b != NULL)
		    return b;
	    }
	    for (std::vector<Binding>::const_iterator it = overlay.begin();
		 it != overlay.end(); ++it)
		if (it->var == t)
		    return it->val;
	    return NULL; // unbound
	}

	/** materialize seed+overlay as a Result for constraint evaluation */
	bool passesConstraint (const Expression* c) {
	    ResultSet scratch(e.atomFactory);
	    Result* row = *scratch.begin();
	    for (BindingSetConstIterator it = seed->begin(); it != seed->end(); ++it)
		scratch.set(row, it->first, it->second.tterm, false);
	    for (std::vector<Binding>::const_iterator it = overlay.begin();
		 it != overlay.end(); ++it)
		if (dynamic_cast<const Variable*>(it->var) != NULL)
		    scratch.set(row, it->var, it->val, false);
	    return e.atomFactory->eval(c, row, &e.db);
	}

	void match (size_t i) {
	    if (i == decl.triples.size()) {
		Result* nw = copyRow(out, seed, e.proofs);
		for (std::vector<Binding>::const_iterator it = overlay.begin();
		     it != overlay.end(); ++it)
		    if (dynamic_cast<const Variable*>(it->var) != NULL)
			out->set(nw, it->var, it->val, false);
		ProofSet& pf = e.proofs[nw];
		pf.insert(matched.begin(), matched.end());
		return;
	    }
	    const TriplePattern* tp = decl.triples[i];
	    const TTerm* s = lookup(tp->getS());
	    const TTerm* p = lookup(tp->getP());
	    const TTerm* o = lookup(tp->getO());
	    const BasicGraphPattern::triple_iterator end;
	    for (BasicGraphPattern::triple_iterator ti = graph->getTripleIterator(s, p, o);
		 ti != end; ++ti) {
		size_t mark = overlay.size();
		bool ok = true;
		const TTerm* pat[3] = { tp->getS(), tp->getP(), tp->getO() };
		const TTerm* dat[3] = { (*ti)->getS(), (*ti)->getP(), (*ti)->getO() };
		for (int k = 0; k < 3 && ok; ++k) {
		    if (!isVarish(pat[k]))
			continue;
		    const TTerm* cur = lookup(pat[k]);
		    if (cur == NULL) {
			Binding b = { pat[k], dat[k] };
			overlay.push_back(b);
		    } else if (cur != dat[k])
			ok = false; // repeated var/bnode must agree
		}
		if (ok && decl.constraints[i] != NULL)
		    ok = passesConstraint(decl.constraints[i]);
		if (ok) {
		    matched.push_back(*ti);
		    match(i + 1);
		    matched.pop_back();
		}
		overlay.resize(mark);
	    }
	}
    };

    /* --------------------------------------------------------- pattern eval --- */

    struct Evaluator : public PatternVisitor {
	Engine& e;
	ResultSet* in;     // owned unless borrowed flag
	bool ownIn;
	const BasicGraphPattern* graph;
	ResultSet* out;    // result

	Evaluator (Engine& e, ResultSet* in, bool ownIn, const BasicGraphPattern* graph)
	    : e(e), in(in), ownIn(ownIn), graph(graph), out(NULL) {  }
	~Evaluator () { if (ownIn) e.freeRS(in); }

	ResultSet* emptyRS () {
	    ResultSet* r = new ResultSet(e.atomFactory);
	    delete *r->begin();
	    r->erase(r->begin());
	    return r;
	}

	/* evaluate p from a fresh unit result set (bottom-up operand) */
	ResultSet* evalFromUnit (const Pattern& p) {
	    return e.evalPattern(e.unitRS(), p, graph, true);
	}
	/* evaluate p over a single-row result set (correlated operand) */
	ResultSet* evalFromRow (const Result* row, const Pattern& p) {
	    ResultSet* seed = emptyRS();
	    copyRow(seed, row, e.proofs);
	    return e.evalPattern(seed, p, graph, true);
	}

	/** merge duplicate binding-tuples, POOLING their proofs - Algae2's
	 * distinctive merged union */
	ResultSet* munionMerge (ResultSet* mixed) {
	    ResultSet* merged = emptyRS();
	    for (ResultSetIterator it = mixed->begin(); it != mixed->end(); ++it) {
		Result* dup = NULL;
		for (ResultSetIterator mi = merged->begin(); mi != merged->end(); ++mi)
		    if (sameBindings(*mi, *it)) { dup = *mi; break; }
		if (dup == NULL)
		    copyRow(merged, *it, e.proofs);
		else {
		    std::map<const Result*, ProofSet>::const_iterator pf = e.proofs.find(*it);
		    if (pf != e.proofs.end())
			e.proofs[dup].insert(pf->second.begin(), pf->second.end());
		}
	    }
	    e.freeRS(mixed);
	    return merged;
	}

	ResultSet* compatJoin (ResultSet* a, ResultSet* b) {
	    ResultSet* r = emptyRS();
	    for (ResultSetIterator ai = a->begin(); ai != a->end(); ++ai)
		for (ResultSetIterator bi = b->begin(); bi != b->end(); ++bi)
		    mergeRows(r, *ai, *bi, e.proofs);
	    return r;
	}

	virtual void visit (const DeclPattern& p) {
	    out = emptyRS();
	    for (ResultSetIterator it = in->begin(); it != in->end(); ++it) {
		BGPMatcher m(e, p, graph, *it, out);
		m.match(0);
	    }
	}

	virtual void visit (const FilterPattern& p) {
	    out = emptyRS();
	    for (ResultSetIterator it = in->begin(); it != in->end(); ++it)
		if (e.atomFactory->eval(p.expr, *it, &e.db)) // errors eliminate
		    copyRow(out, *it, e.proofs);
	}

	virtual void visit (const UnaryPattern& p) {
	    out = emptyRS();
	    if (e.mode == EVAL_topdown) {
		/* correlated: evaluate the right side once per row, bindings
		 * substituted in */
		for (ResultSetIterator it = in->begin(); it != in->end(); ++it) {
		    ResultSet* ext = evalFromRow(*it, *p.inner);
		    if (p.op == UnaryPattern::Optional) {
			if (ext->size() == 0)
			    copyRow(out, *it, e.proofs);
			else
			    for (ResultSetIterator xi = ext->begin(); xi != ext->end(); ++xi)
				copyRow(out, *xi, e.proofs);
		    } else { // Negation: correlated NOT-EXISTS
			if (ext->size() == 0)
			    copyRow(out, *it, e.proofs);
		    }
		    e.freeRS(ext);
		}
	    } else {
		/* bottom-up: LeftJoin / Minus against an isolated evaluation */
		ResultSet* right = evalFromUnit(*p.inner);
		for (ResultSetIterator it = in->begin(); it != in->end(); ++it) {
		    if (p.op == UnaryPattern::Optional) {
			size_t before = out->size();
			for (ResultSetIterator ri = right->begin(); ri != right->end(); ++ri)
			    mergeRows(out, *it, *ri, e.proofs);
			if (out->size() == before)
			    copyRow(out, *it, e.proofs);
		    } else {
			/* SPARQL Minus: remove rows compatible with some right
			 * row THAT SHARES a bound variable; a right side with
			 * disjoint domain removes nothing (vacuous) */
			bool removed = false;
			for (ResultSetIterator ri = right->begin(); !removed && ri != right->end(); ++ri)
			    if (compatible(*it, *ri) && domainsOverlap(*it, *ri))
				removed = true;
			if (!removed)
			    copyRow(out, *it, e.proofs);
		    }
		}
		e.freeRS(right);
	    }
	}

	virtual void visit (const ConjPattern& p) {
	    /* left-to-right threading; in bottom-up mode each operand's
	     * evaluator joins an isolated evaluation onto the accumulated
	     * rows, so threading realizes Join associativity */
	    ResultSet* cur = in;
	    bool own = false;
	    for (std::vector<const Pattern*>::const_iterator it = p.elts.begin();
		 it != p.elts.end(); ++it) {
		ResultSet* next = e.evalPattern(cur, **it, graph, false);
		if (own)
		    e.freeRS(cur);
		cur = next;
		own = true;
	    }
	    if (own)
		out = cur;
	    else { // empty conjunction: identity
		out = emptyRS();
		for (ResultSetIterator it = in->begin(); it != in->end(); ++it)
		    copyRow(out, *it, e.proofs);
	    }
	}

	virtual void visit (const ConnPattern& p) {
	    if (e.mode == EVAL_bottomup) {
		/* SPARQL group isolation: both sides evaluate from the unit
		 * result set; the combined result then joins the accumulated
		 * rows. This is what strands a correlated negation inside a
		 * union branch (the negation-scoped demo). */
		ResultSet* combined = NULL;
		switch (p.op) {
		case ConnPattern::OrElse: {
		    ResultSet* l = evalFromUnit(*p.l);
		    if (l->size() > 0)
			combined = l;
		    else {
			e.freeRS(l);
			combined = evalFromUnit(*p.r);
		    }
		    break;
		}
		case ConnPattern::Union:
		case ConnPattern::MUnion: {
		    combined = evalFromUnit(*p.l);
		    ResultSet* r = evalFromUnit(*p.r);
		    for (ResultSetIterator it = r->begin(); it != r->end(); ++it)
			copyRow(combined, *it, e.proofs);
		    e.freeRS(r);
		    if (p.op == ConnPattern::MUnion)
			combined = munionMerge(combined);
		    break;
		}
		case ConnPattern::Diff: {
		    ResultSet* l = evalFromUnit(*p.l);
		    ResultSet* r = evalFromUnit(*p.r);
		    combined = emptyRS();
		    for (ResultSetIterator li = l->begin(); li != l->end(); ++li) {
			bool hit = false;
			for (ResultSetIterator ri = r->begin(); !hit && ri != r->end(); ++ri)
			    if (compatible(*li, *ri))
				hit = true;
			if (!hit)
			    copyRow(combined, *li, e.proofs);
		    }
		    e.freeRS(l);
		    e.freeRS(r);
		    break;
		}
		}
		out = compatJoin(in, combined);
		e.freeRS(combined);
		return;
	    }
	    switch (p.op) {
	    case ConnPattern::OrElse: {
		/* shortcut disjunction: Q only where P yielded nothing
		 * (set-level; see file header) */
		ResultSet* l = e.evalPattern(in, *p.l, graph, false);
		if (l->size() > 0)
		    out = l;
		else {
		    e.freeRS(l);
		    out = e.evalPattern(in, *p.r, graph, false);
		}
		break;
	    }
	    case ConnPattern::Union:
	    case ConnPattern::MUnion: {
		ResultSet* l = e.evalPattern(in, *p.l, graph, false);
		ResultSet* r = e.evalPattern(in, *p.r, graph, false);
		out = l;
		for (ResultSetIterator it = r->begin(); it != r->end(); ++it)
		    copyRow(out, *it, e.proofs);
		e.freeRS(r);
		if (p.op == ConnPattern::MUnion)
		    out = munionMerge(out);
		break;
	    }
	    case ConnPattern::Diff: {
		/* strict antijoin: results of P not compatible with any of Q */
		ResultSet* l = e.evalPattern(in, *p.l, graph, false);
		ResultSet* r = e.mode == EVAL_topdown
		    ? e.evalPattern(in, *p.r, graph, false)
		    : evalFromUnit(*p.r);
		out = emptyRS();
		for (ResultSetIterator li = l->begin(); li != l->end(); ++li) {
		    bool hit = false;
		    for (ResultSetIterator ri = r->begin(); !hit && ri != r->end(); ++ri)
			if (compatible(*li, *ri))
			    hit = true;
		    if (!hit)
			copyRow(out, *li, e.proofs);
		}
		e.freeRS(l);
		e.freeRS(r);
		break;
	    }
	    }
	}

	virtual void visit (const InGraphPattern& p) {
	    out = emptyRS();
	    const Variable* gvar = dynamic_cast<const Variable*>(p.graph);
	    std::set<const TTerm*> names = e.db.getGraphNames();
	    for (std::set<const TTerm*>::const_iterator g = names.begin(); g != names.end(); ++g) {
		if (*g == DefaultGraph)
		    continue;
		if (gvar == NULL && *g != p.graph)
		    continue;
		const BasicGraphPattern* bgp = e.db.findGraph(*g);
		if (bgp == NULL)
		    continue;
		/* rows whose ?g binding disagrees don't consult this graph */
		ResultSet* seed = emptyRS();
		for (ResultSetIterator it = in->begin(); it != in->end(); ++it) {
		    const TTerm* bound = gvar == NULL ? NULL : (*it)->get(gvar);
		    if (bound != NULL && bound != *g)
			continue;
		    Result* nw = copyRow(seed, *it, e.proofs);
		    if (gvar != NULL && bound == NULL)
			seed->set(nw, gvar, *g, false);
		}
		ResultSet* sub = e.evalPattern(seed, *p.inner, bgp, true);
		for (ResultSetIterator it = sub->begin(); it != sub->end(); ++it)
		    copyRow(out, *it, e.proofs);
		e.freeRS(sub);
	    }
	}

	virtual void visit (const ScopePattern& p);
	virtual void visit (const ActionPattern& p);
    };

    ResultSet* Engine::evalPattern (ResultSet* in, const Pattern& p,
				    const BasicGraphPattern* graph, bool ownIn) {
	Evaluator v(*this, in, ownIn, graph);
	p.accept(v);
	return v.out;
    }

    /* ---------------------------------------------- scope & inline actions --- */

    /** run a sub-pipeline over a seed result set using a scratch engine that
     * shares this engine's dataset and proofs */
    static ResultSet* runSubPipeline (Engine& e, const std::vector<const Action*>& pipeline,
				      ResultSet* seed) {
	ResultSet* saved = e.rs;
	e.rs = seed;
	for (std::vector<const Action*>::const_iterator it = pipeline.begin();
	     it != pipeline.end(); ++it)
	    e.apply(**it);
	ResultSet* ret = e.rs;
	e.rs = saved;
	return ret;
    }

    void Evaluator::visit (const ScopePattern& p) {
	out = emptyRS();
	if (e.mode == EVAL_topdown) {
	    /* lateral: the enclosing bindings flow in, row by row */
	    for (ResultSetIterator it = in->begin(); it != in->end(); ++it) {
		ResultSet* seed = emptyRS();
		copyRow(seed, *it, e.proofs);
		ResultSet* sub = p.pattern != NULL
		    ? e.evalPattern(seed, *p.pattern, graph, true)
		    : runSubPipeline(e, p.pipeline, seed);
		for (ResultSetIterator si = sub->begin(); si != sub->end(); ++si) {
		    /* export only the shared variables, joined back onto the row */
		    ResultSet shared1(e.atomFactory);
		    Result* proj = *shared1.begin();
		    for (std::vector<const TTerm*>::const_iterator v = p.share.begin();
			 v != p.share.end(); ++v) {
			const TTerm* val = (*si)->get(*v);
			if (val != NULL)
			    shared1.set(proj, *v, val, false);
		    }
		    Result* nw = mergeRows(out, *it, proj, e.proofs);
		    if (nw != NULL) {
			std::map<const Result*, ProofSet>::const_iterator pf = e.proofs.find(*si);
			if (pf != e.proofs.end())
			    e.proofs[nw].insert(pf->second.begin(), pf->second.end());
		    }
		}
		e.freeRS(sub);
	    }
	} else {
	    /* subselect isolation: evaluate from the unit result set */
	    ResultSet* sub = p.pattern != NULL
		? evalFromUnit(*p.pattern)
		: runSubPipeline(e, p.pipeline, e.unitRS());
	    /* project to the shared variables, then compatibility-join */
	    ResultSet* projd = emptyRS();
	    for (ResultSetIterator si = sub->begin(); si != sub->end(); ++si) {
		Result* nw = new Result(projd);
		projd->insert(projd->end(), nw);
		for (std::vector<const TTerm*>::const_iterator v = p.share.begin();
		     v != p.share.end(); ++v) {
		    const TTerm* val = (*si)->get(*v);
		    if (val != NULL)
			projd->set(nw, *v, val, false);
		}
		std::map<const Result*, ProofSet>::const_iterator pf = e.proofs.find(*si);
		if (pf != e.proofs.end())
		    e.proofs[nw] = pf->second;
	    }
	    e.freeRS(sub);
	    ResultSet* joined = compatJoin(in, projd);
	    e.freeRS(projd);
	    e.freeRS(out);
	    out = joined;
	}
    }

    void Evaluator::visit (const ActionPattern& p) {
	/* inline let / bindings: apply the action to the incoming rows */
	ResultSet* seed = emptyRS();
	for (ResultSetIterator it = in->begin(); it != in->end(); ++it)
	    copyRow(seed, *it, e.proofs);
	ResultSet* saved = e.rs;
	e.rs = seed;
	e.apply(*p.action);
	out = e.rs;
	e.rs = saved;
    }

    /* ------------------------------------------------------------ actions --- */

    struct Applier : public ActionVisitor {
	Engine& e;
	Applier (Engine& e) : e(e) {  }

	virtual void visit (const Load& a) {
	    std::string path = a.iri->getLexicalValue();
	    if (path.compare(0, 7, "file://") == 0)
		path = path.substr(7);
	    else if (path.compare(0, 5, "file:") == 0)
		path = path.substr(5);
	    if (!path.empty() && path[0] != '/' && !e.baseDir.empty())
		path = e.baseDir + "/" + path;
	    std::ifstream check(path.c_str());
	    if (!check.good() && path[0] == '/' && !e.baseDir.empty()) {
		/* a bare `file:` base yields pseudo-absolute /rel paths;
		 * retry relative to the script directory */
		std::string rel = e.baseDir + path;
		std::ifstream retry(rel.c_str());
		if (retry.good())
		    path = rel;
	    }
	    std::ifstream check2(path.c_str());
	    if (!check2.good())
		throw std::string("load: cannot open \"") + path + "\"";
	    IStreamContext istr(path, IStreamContext::FILE);
	    /* a fresh driver per load: its private bnode map standardizes
	     * blank nodes apart, making load a graph MERGE; `as` leaves the
	     * working graph untouched */
	    TurtleDriver turtleParser("", e.atomFactory);
	    turtleParser.parse(istr, a.as == NULL
			       ? e.db.ensureGraph(DefaultGraph)
			       : e.db.ensureGraph(a.as));
	}

	virtual void visit (const Attach& a) {
	    throw std::string("attach (external database \"") + a.name
		+ "\") is parsed for Algae2 compatibility but not evaluable here";
	}

	virtual void visit (const Ask& a) { e.ask(*a.pattern); }

	virtual void visit (const Test& a) {
	    ResultSet* copy = new ResultSet(e.atomFactory);
	    delete *copy->begin();
	    copy->erase(copy->begin());
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it)
		copyRow(copy, *it, e.proofs);
	    ResultSet* matched = e.evalPattern(copy, *a.pattern,
					       e.db.ensureGraph(DefaultGraph), true);
	    e.lastTest = matched->size() > 0;
	    e.freeRS(matched); // result set unchanged
	}

	/** collect the template triples of an assert pattern */
	static void templateTriples (const Pattern& p, std::vector<const TriplePattern*>& into) {
	    if (const DeclPattern* d = dynamic_cast<const DeclPattern*>(&p)) {
		into.insert(into.end(), d->triples.begin(), d->triples.end());
		return;
	    }
	    if (const ConjPattern* c = dynamic_cast<const ConjPattern*>(&p)) {
		for (std::vector<const Pattern*>::const_iterator it = c->elts.begin();
		     it != c->elts.end(); ++it)
		    templateTriples(**it, into);
		return;
	    }
	    throw std::string("assert template must be a conjunction of declarations");
	}

	void instantiate (const std::vector<const TriplePattern*>& tmpl,
			  const Result* row, BasicGraphPattern* target) {
	    std::map<const TTerm*, const TTerm*> bnodeRenames; // fresh per row
	    for (std::vector<const TriplePattern*>::const_iterator it = tmpl.begin();
		 it != tmpl.end(); ++it) {
		const TTerm* spo[3] = { (*it)->getS(), (*it)->getP(), (*it)->getO() };
		bool ok = true;
		for (int k = 0; k < 3 && ok; ++k) {
		    if (dynamic_cast<const Variable*>(spo[k]) != NULL) {
			const TTerm* v = row->get(spo[k]);
			if (v == NULL)
			    ok = false; // CONSTRUCT semantics: skip the triple
			else
			    spo[k] = v;
		    } else if (dynamic_cast<const BNode*>(spo[k]) != NULL) {
			const TTerm*& fresh = bnodeRenames[spo[k]];
			if (fresh == NULL)
			    fresh = e.atomFactory->createBNode();
			spo[k] = fresh;
		    }
		}
		if (!ok)
		    continue;
		const TriplePattern* t = e.atomFactory->getTriple(spo[0], spo[1], spo[2]);
		size_t before = target->size();
		target->addTriplePattern(t); // ignores duplicates
		if (target->size() > before)
		    e.asserted.push_back(t);
	    }
	}

	virtual void visit (const AssertAction& a) {
	    std::vector<const TriplePattern*> tmpl;
	    templateTriples(*a.tmplt, tmpl);
	    BasicGraphPattern* target = a.into == NULL
		? e.db.ensureGraph(DefaultGraph) : e.db.ensureGraph(a.into);
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it) {
		instantiate(tmpl, *it, target);
		/* asserted triples are both output and proof */
		ProofSet& pf = e.proofs[*it];
		pf.insert(e.asserted.begin(), e.asserted.end());
	    }
	}

	virtual void visit (const FwRule& a) {
	    /* forward rule to fixpoint: whenever P matches, T holds */
	    std::vector<const TriplePattern*> tmpl;
	    templateTriples(*a.assrt->tmplt, tmpl);
	    BasicGraphPattern* target = a.assrt->into == NULL
		? e.db.ensureGraph(DefaultGraph) : e.db.ensureGraph(a.assrt->into);
	    size_t before;
	    do {
		before = target->size();
		ResultSet* matches = e.evalPattern(e.unitRS(), *a.ask->pattern,
						   e.db.ensureGraph(DefaultGraph), true);
		for (ResultSetIterator it = matches->begin(); it != matches->end(); ++it)
		    instantiate(tmpl, *it, target);
		e.freeRS(matches);
	    } while (target->size() > before);
	}

	virtual void visit (const Let& a) {
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it) {
		if ((*it)->get(a.var) != NULL)
		    continue; // already bound: SPARQL BIND would error; keep
		const TTerm* val = NULL;
		try {
		    val = a.expr->eval(*it, e.atomFactory, NULL, NULL, &e.db);
		} catch (SafeEvaluationError&) {
		} catch (TypeError&) {
		}
		if (val != NULL && val != TTerm::Unbound)
		    e.rs->set(*it, a.var, val, false);
	    }
	}

	virtual void visit (const BindingsAction& a) {
	    ResultSet* table = new ResultSet(e.atomFactory);
	    delete *table->begin();
	    table->erase(table->begin());
	    for (size_t r = 0; r < a.rows.size(); ++r) {
		Result* nw = new Result(table);
		table->insert(table->end(), nw);
		for (size_t c = 0; c < a.vars.size(); ++c)
		    if (a.rows[r][c] != NULL) // UNDEF leaves the cell unbound
			table->set(nw, a.vars[c], a.rows[r][c], false);
	    }
	    ResultSet* joined = new ResultSet(e.atomFactory);
	    delete *joined->begin();
	    joined->erase(joined->begin());
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it)
		for (ResultSetIterator ti = table->begin(); ti != table->end(); ++ti)
		    mergeRows(joined, *it, *ti, e.proofs);
	    e.freeRS(table);
	    e.replaceRS(joined);
	}

	virtual void visit (const Collect& a);
	virtual void visit (const FilterAction& a) {
	    ResultSet* kept = new ResultSet(e.atomFactory);
	    delete *kept->begin();
	    kept->erase(kept->begin());
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it)
		if (e.atomFactory->eval(a.expr, *it, &e.db))
		    copyRow(kept, *it, e.proofs);
	    e.replaceRS(kept);
	}
    };

    /* --------------------------------------------------------- aggregation --- */

    void AggregateExpr::express (Expressor* p_expressor) const {
	/* present as a SPARQL AggregateCall so serializers (toString, the
	 * --algebra dump) can walk it */
	const URI* name =
	    func == Sum ? TTerm::FUNC_sum :
	    func == Min ? TTerm::FUNC_min :
	    func == Max ? TTerm::FUNC_max :
	    func == Avg ? TTerm::FUNC_avg :
	    func == Sample ? TTerm::FUNC_sample :
	    func == GroupConcat ? TTerm::FUNC_group_concat :
	    TTerm::FUNC_count;
	ProductionVector<const Expression*>* args = new ProductionVector<const Expression*>();
	if (arg != NULL)
	    args->push_back(arg); // borrowed for the walk; released below
	AggregateCall::ScalarVals sv;
	if (func == GroupConcat)
	    sv["separator"] = separator;
	{
	    AggregateCall call(name, distinct ? DIST_distinct : DIST_all, new ArgList(args), sv);
	    call.express(p_expressor);
	    args->clear(); // the temporary must not free the borrowed argument
	}
    }

    const TTerm* AggregateExpr::eval (const Result* /* r */, AtomFactory* atomFactory,
				      BNodeEvaluator* /* evaluator */,
				      TTerm::String2BNode* /* bnodeMap */,
				      const RdfDB* db) const {
	const std::vector<const Result*>* group = Engine::currentGroup;
	if (group == NULL)
	    throw SafeEvaluationError("aggregate evaluated outside a collect group");

	std::vector<const TTerm*> vals;
	for (std::vector<const Result*>::const_iterator it = group->begin();
	     it != group->end(); ++it) {
	    if (arg == NULL) { // count(*)
		vals.push_back(TTerm::BOOL_true);
		continue;
	    }
	    try {
		const TTerm* v = arg->eval(*it, atomFactory, NULL, NULL, db);
		if (v != NULL && v != TTerm::Unbound)
		    vals.push_back(v);
	    } catch (SafeEvaluationError&) {
	    } catch (TypeError&) {
	    }
	}
	if (distinct) {
	    std::vector<const TTerm*> uniq;
	    for (std::vector<const TTerm*>::const_iterator it = vals.begin(); it != vals.end(); ++it)
		if (std::find(uniq.begin(), uniq.end(), *it) == uniq.end())
		    uniq.push_back(*it);
	    vals.swap(uniq);
	}

	switch (func) {
	case Count:
	case CountStar:
	    return atomFactory->getNumericRDFLiteral(
		boost::lexical_cast<std::string>(vals.size()).c_str(),
		(int)vals.size(), TTerm::URI_xsd_integer);
	case GroupConcat: {
	    std::string acc;
	    for (size_t i = 0; i < vals.size(); ++i) {
		if (i) acc += separator;
		acc += vals[i]->getLexicalValue();
	    }
	    return atomFactory->getRDFLiteral(acc, NULL, NULL);
	}
	case Sample:
	    return vals.empty() ? TTerm::Unbound : vals[0];
	case Min:
	case Max: {
	    if (vals.empty()) return TTerm::Unbound;
	    const TTerm* best = vals[0];
	    for (size_t i = 1; i < vals.size(); ++i) {
		int c = cmpTerms(vals[i], best);
		if (func == Min ? c < 0 : c > 0)
		    best = vals[i];
	    }
	    return best;
	}
	case Sum:
	case Avg: {
	    double acc = 0;
	    size_t n = 0;
	    for (size_t i = 0; i < vals.size(); ++i) {
		const NumericRDFLiteral* num = dynamic_cast<const NumericRDFLiteral*>(vals[i]);
		if (num == NULL)
		    throw SafeEvaluationError("aggregating a non-numeric value");
		acc += num->getDouble();
		++n;
	    }
	    if (func == Avg && n > 0)
		acc /= n;
	    std::ostringstream ss;
	    ss << acc;
	    return atomFactory->getNumericRDFLiteral(ss.str().c_str(), acc, TTerm::URI_xsd_double);
	}
	}
	throw SafeEvaluationError("unhandled aggregate");
    }

    void Applier::visit (const Collect& a) {
	Engine::currentProofs = &e.proofs;
	Engine::currentDB = &e.db;
	Engine::currentFactory = e.atomFactory;

	/* the projection list; (*) projects every known variable */
	std::vector<Projection> projections;
	if (a.star) {
	    const VariableList* known = e.rs->getKnownVars();
	    for (VariableListConstIterator it = known->begin(); it != known->end(); ++it)
		projections.push_back(Projection(*it, NULL));
    } else
	    projections = a.projections;

	ResultSet* outRS = new ResultSet(e.atomFactory);
	delete *outRS->begin();
	outRS->erase(outRS->begin());
	std::map<const Result*, ProofSet> outProofs;

	bool grouped = !a.groupBy.empty();
	if (!grouped)
	    for (std::vector<Projection>::const_iterator pr = projections.begin();
		 !grouped && pr != projections.end(); ++pr)
		if (pr->expr != NULL && dynamic_cast<const AggregateExpr*>(pr->expr) != NULL)
		    grouped = true; // aggregate without `by`: one implicit group
	if (grouped) {
	    /* group rows by the `by` variables (order of first appearance) */
	    std::vector<std::vector<const Result*> > groups;
	    std::vector<const Result*> keys;
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it) {
		size_t g = 0;
		for (; g < keys.size(); ++g) {
		    bool same = true;
		    for (std::vector<const TTerm*>::const_iterator v = a.groupBy.begin();
			 same && v != a.groupBy.end(); ++v)
			if (keys[g]->get(*v) != (*it)->get(*v))
			    same = false;
		    if (same)
			break;
		}
		if (g == keys.size()) {
		    keys.push_back(*it);
		    groups.push_back(std::vector<const Result*>());
		}
		groups[g].push_back(*it);
	    }
	    for (size_t g = 0; g < groups.size(); ++g) {
		Engine::currentGroup = &groups[g];
		Result* nw = new Result(outRS);
		outRS->insert(outRS->end(), nw);
		ProofSet pf;
		for (std::vector<const Result*>::const_iterator it = groups[g].begin();
		     it != groups[g].end(); ++it) {
		    std::map<const Result*, ProofSet>::const_iterator p = e.proofs.find(*it);
		    if (p != e.proofs.end())
			pf.insert(p->second.begin(), p->second.end());
		}
		const Result* rep = groups[g][0];
		for (std::vector<Projection>::const_iterator pr = projections.begin();
		     pr != projections.end(); ++pr) {
		    const TTerm* val = NULL;
		    if (pr->expr == NULL)
			val = rep->get(pr->var);
		    else {
			try {
			    val = pr->expr->eval(rep, e.atomFactory, NULL, NULL, &e.db);
			} catch (SafeEvaluationError&) {
			} catch (TypeError&) {
			}
		    }
		    if (val != NULL && val != TTerm::Unbound)
			outRS->set(nw, pr->var, val, false);
		}
		outProofs[nw] = pf;
		Engine::currentGroup = NULL;
	    }
	} else {
	    for (ResultSetIterator it = e.rs->begin(); it != e.rs->end(); ++it) {
		/* an ungrouped collect whose projections aggregate treats the
		 * whole result set as one group - handled by the grouped path
		 * below via a single group */
		Result* nw = new Result(outRS);
		outRS->insert(outRS->end(), nw);
		std::vector<const Result*> self(1, *it);
		Engine::currentGroup = &self; // sample/count over a single row
		for (std::vector<Projection>::const_iterator pr = projections.begin();
		     pr != projections.end(); ++pr) {
		    const TTerm* val = NULL;
		    if (pr->expr == NULL)
			val = (*it)->get(pr->var);
		    else {
			try {
			    val = pr->expr->eval(*it, e.atomFactory, NULL, NULL, &e.db);
			} catch (SafeEvaluationError&) {
			} catch (TypeError&) {
			}
		    }
		    if (val != NULL && val != TTerm::Unbound)
			outRS->set(nw, pr->var, val, false);
		}
		Engine::currentGroup = NULL;
		std::map<const Result*, ProofSet>::const_iterator p = e.proofs.find(*it);
		if (p != e.proofs.end())
		    outProofs[nw] = p->second;
	    }
	}

	/* distinct: drop duplicate binding-tuples, pooling proofs */
	if (a.distinct) {
	    ResultSet* uniq = new ResultSet(e.atomFactory);
	    delete *uniq->begin();
	    uniq->erase(uniq->begin());
	    std::map<const Result*, ProofSet> uniqProofs;
	    for (ResultSetIterator it = outRS->begin(); it != outRS->end(); ++it) {
		Result* dup = NULL;
		for (ResultSetIterator ui = uniq->begin(); ui != uniq->end(); ++ui)
		    if (sameBindings(*ui, *it)) { dup = *ui; break; }
		if (dup == NULL) {
		    Result* nw = new Result(uniq);
		    uniq->insert(uniq->end(), nw);
		    for (BindingSetConstIterator b = (*it)->begin(); b != (*it)->end(); ++b)
			uniq->set(nw, b->first, b->second.tterm, false);
		    uniqProofs[nw] = outProofs[*it];
		} else
		    uniqProofs[dup].insert(outProofs[*it].begin(), outProofs[*it].end());
	    }
	    delete outRS;
	    outRS = uniq;
	    outProofs.swap(uniqProofs);
	}

	/* order by */
	if (!a.order.empty()) {
	    std::vector<Result*> rows(outRS->begin(), outRS->end());
	    struct Cmp {
		const std::vector<OrderCond>& conds;
		Engine& e;
		Cmp (const std::vector<OrderCond>& conds, Engine& e) : conds(conds), e(e) {  }
		bool operator() (const Result* x, const Result* y) const {
		    for (std::vector<OrderCond>::const_iterator c = conds.begin();
			 c != conds.end(); ++c) {
			const TTerm *xv = NULL, *yv = NULL;
			try { xv = c->expr->eval(x, e.atomFactory, NULL, NULL, &e.db); }
			catch (SafeEvaluationError&) {} catch (TypeError&) {}
			try { yv = c->expr->eval(y, e.atomFactory, NULL, NULL, &e.db); }
			catch (SafeEvaluationError&) {} catch (TypeError&) {}
			int cv = cmpTerms(xv, yv);
			if (cv != 0)
			    return c->descending ? cv > 0 : cv < 0;
		    }
		    return false;
		}
	    };
	    std::stable_sort(rows.begin(), rows.end(), Cmp(a.order, e));
	    ResultSet* sorted = new ResultSet(e.atomFactory);
	    delete *sorted->begin();
	    sorted->erase(sorted->begin());
	    std::map<const Result*, ProofSet> sortedProofs;
	    for (std::vector<Result*>::const_iterator it = rows.begin(); it != rows.end(); ++it) {
		Result* nw = new Result(sorted);
		sorted->insert(sorted->end(), nw);
		for (BindingSetConstIterator b = (*it)->begin(); b != (*it)->end(); ++b)
		    sorted->set(nw, b->first, b->second.tterm, false);
		sortedProofs[nw] = outProofs[*it];
	    }
	    delete outRS;
	    outRS = sorted;
	    outProofs.swap(sortedProofs);
	}

	/* offset / limit */
	if (a.offset > 0 || a.limit >= 0) {
	    long i = 0;
	    for (ResultSetIterator it = outRS->begin(); it != outRS->end(); ) {
		bool keep = i >= a.offset && (a.limit < 0 || i < a.offset + a.limit);
		++i;
		if (keep)
		    ++it;
		else {
		    outProofs.erase(*it);
		    delete *it;
		    it = outRS->erase(it);
		}
	    }
	}

	e.replaceRS(outRS);
	e.proofs.swap(outProofs);
	Engine::currentGroup = NULL;
    }

    /* -------------------------------------------------------------- driver --- */

    void Engine::apply (const Action& a) {
	Applier v(*this);
	a.accept(v);
    }

    void Engine::ask (const Pattern& p) {
	ResultSet* seed = rs;
	rs = NULL; // evalPattern owns and frees seed
	rs = evalPattern(seed, p, db.ensureGraph(DefaultGraph), true);
    }

    void Engine::run (const Query& q) {
	mode = q.mode;
	for (std::vector<const Action*>::const_iterator it = q.actions.begin();
	     it != q.actions.end(); ++it)
	    apply(**it);
    }

    std::pair<size_t, size_t> Engine::tryMatch (const Pattern& p) {
	/* speculative: evaluate over a COPY, count, discard */
	ResultSet* copy = new ResultSet(atomFactory);
	delete *copy->begin();
	copy->erase(copy->begin());
	const std::map<const Result*, ProofSet> savedProofs = proofs;
	size_t before = rs->size();
	for (ResultSetIterator it = rs->begin(); it != rs->end(); ++it)
	    copyRow(copy, *it, proofs);
	ResultSet* result = evalPattern(copy, p, db.ensureGraph(DefaultGraph), true);
	size_t after = result->size();
	freeRS(result);
	proofs = savedProofs; // discard all speculative proof entries
	size_t extended = after > before ? after - before : 0;
	size_t dropped = after < before ? before - after : 0;
	return std::make_pair(extended, dropped);
    }

    std::string Engine::renderTable (size_t maxRows, bool showProofs) const {
	std::string table = rs->toString();
	std::ostringstream ss;
	if (maxRows > 0 && rs->size() > maxRows) {
	    /* trim the rendered table to the header + maxRows rows */
	    std::istringstream lines(table);
	    std::string line;
	    size_t emitted = 0, dataRows = 0;
	    while (std::getline(lines, line)) {
		ss << line << "\n";
		++emitted;
		if (emitted > 2 && ++dataRows >= maxRows)
		    break;
	    }
	    ss << "... (" << rs->size() << " rows)\n";
	} else
	    ss << table;
	if (showProofs) {
	    size_t i = 0;
	    for (ResultSetConstIterator it = rs->begin(); it != rs->end(); ++it, ++i) {
		if (maxRows > 0 && i >= maxRows)
		    break;
		ss << "row " << i << " proofs:";
		std::map<const Result*, ProofSet>::const_iterator p = proofs.find(*it);
		if (p == proofs.end() || p->second.empty())
		    ss << " (none)";
		else
		    for (ProofSet::const_iterator t = p->second.begin(); t != p->second.end(); ++t)
			ss << "\n  " << (*t)->toString();
		ss << "\n";
	    }
	}
	return ss.str();
    }

    /* ------------------------------------------------------ pattern printing --- */

    namespace {
	const char* conjName (EvalMode m) { return m == EVAL_topdown ? "djoin" : "join"; }
	const char* optName (EvalMode m) { return m == EVAL_topdown ? "optjoin" : "leftjoin"; }
	const char* negName (EvalMode m) { return m == EVAL_topdown ? "notexists" : "minus"; }
    }

    void DeclPattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void FilterPattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void UnaryPattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void ConjPattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void ConnPattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void InGraphPattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void ScopePattern::accept (PatternVisitor& v) const { v.visit(*this); }
    void ActionPattern::accept (PatternVisitor& v) const { v.visit(*this); }

    ScopePattern::~ScopePattern () {
	delete pattern;
	for (std::vector<const Action*>::const_iterator it = pipeline.begin();
	     it != pipeline.end(); ++it)
	    delete *it;
    }
    ActionPattern::~ActionPattern () { delete action; }

    std::string DeclPattern::str (EvalMode) const {
	std::ostringstream ss;
	ss << "(bgpmatch";
	for (size_t i = 0; i < triples.size(); ++i) {
	    ss << " (t " << triples[i]->getS()->toString()
	       << " " << triples[i]->getP()->toString()
	       << " " << triples[i]->getO()->toString();
	    if (constraints[i] != NULL)
		ss << " (where " << constraints[i]->str() << ")";
	    ss << ")";
	}
	ss << ")";
	return ss.str();
    }
    std::string FilterPattern::str (EvalMode) const {
	return "(filter " + expr->str() + ")";
    }
    std::string UnaryPattern::str (EvalMode m) const {
	return std::string("(") + (op == Optional ? optName(m) : negName(m))
	    + " " + inner->str(m) + ")";
    }
    std::string ConjPattern::str (EvalMode m) const {
	std::string ret = std::string("(") + conjName(m);
	for (std::vector<const Pattern*>::const_iterator it = elts.begin(); it != elts.end(); ++it)
	    ret += " " + (*it)->str(m);
	return ret + ")";
    }
    std::string ConnPattern::str (EvalMode m) const {
	const char* n = op == OrElse ? "orelse" : op == Union ? "union"
	    : op == MUnion ? "munion" : "diff";
	return std::string("(") + n + " " + l->str(m) + " " + r->str(m) + ")";
    }
    std::string InGraphPattern::str (EvalMode m) const {
	return "(ingraph " + graph->toString() + " " + inner->str(m) + ")";
    }
    std::string ScopePattern::str (EvalMode m) const {
	std::string body;
	if (pattern != NULL)
	    body = pattern->str(m);
	else {
	    body = "(pipeline";
	    for (std::vector<const Action*>::const_iterator it = pipeline.begin();
		 it != pipeline.end(); ++it)
		body += " " + (*it)->str(m);
	    body += ")";
	}
	std::string sh = "(share";
	for (std::vector<const TTerm*>::const_iterator it = share.begin(); it != share.end(); ++it)
	    sh += " " + (*it)->toString();
	return "(scope " + body + " " + sh + "))";
    }
    std::string ActionPattern::str (EvalMode m) const { return action->str(m); }

    std::string Load::str (EvalMode) const {
	return "(load " + iri->toString() + (as ? " (as " + as->toString() + ")" : "") + ")";
    }
    std::string Attach::str (EvalMode) const { return "(attach " + driver->toString() + " " + name + ")"; }
    std::string Ask::str (EvalMode m) const { return "(ask " + pattern->str(m) + ")"; }
    std::string Test::str (EvalMode m) const { return "(test " + pattern->str(m) + ")"; }
    std::string AssertAction::str (EvalMode m) const {
	return "(assert" + std::string(into ? " (into " + into->toString() + ")" : "")
	    + " " + tmplt->str(m) + ")";
    }
    std::string FwRule::str (EvalMode m) const {
	return "(fwrule " + ask->str(m) + " " + assrt->str(m) + ")";
    }
    std::string Let::str (EvalMode) const {
	return "(let " + var->toString() + " " + expr->str() + ")";
    }
    std::string BindingsAction::str (EvalMode) const {
	std::string ret = "(bindings (";
	for (size_t i = 0; i < vars.size(); ++i)
	    ret += (i ? " " : "") + vars[i]->toString();
	ret += ") (";
	for (size_t r = 0; r < rows.size(); ++r) {
	    ret += r ? " (" : "(";
	    for (size_t c = 0; c < rows[r].size(); ++c)
		ret += (c ? " " : "") + (rows[r][c] ? rows[r][c]->toString() : std::string("UNDEF"));
	    ret += ")";
	}
	return ret + "))";
    }
    std::string Collect::str (EvalMode) const {
	std::ostringstream ss;
	ss << "(collect (project";
	if (star)
	    ss << " *";
	for (std::vector<Projection>::const_iterator it = projections.begin();
	     it != projections.end(); ++it)
	    if (it->expr == NULL)
		ss << " " << it->var->toString();
	    else
		ss << " (as " << it->expr->str() << " " << it->var->toString() << ")";
	ss << ")";
	if (distinct) ss << " (distinct)";
	if (!groupBy.empty()) {
	    ss << " (groupby";
	    for (std::vector<const TTerm*>::const_iterator it = groupBy.begin();
		 it != groupBy.end(); ++it)
		ss << " " << (*it)->toString();
	    ss << ")";
	}
	if (!order.empty()) {
	    ss << " (orderby";
	    for (std::vector<OrderCond>::const_iterator it = order.begin(); it != order.end(); ++it)
		ss << " (" << (it->descending ? "desc" : "asc") << " " << it->expr->str() << ")";
	    ss << ")";
	}
	if (limit >= 0) ss << " (limit " << limit << ")";
	if (offset > 0) ss << " (offset " << offset << ")";
	ss << ")";
	return ss.str();
    }
    std::string FilterAction::str (EvalMode) const { return "(filter " + expr->str() + ")"; }

    std::string Query::str () const {
	std::string ret = "(algae3";
	for (std::vector<const Action*>::const_iterator it = actions.begin();
	     it != actions.end(); ++it)
	    ret += "\n  " + (*it)->str(mode);
	return ret + ")";
    }

    void inScopeVars (const Pattern& p, std::vector<const TTerm*>& into) {
	struct V : public PatternVisitor {
	    std::vector<const TTerm*>& into;
	    V (std::vector<const TTerm*>& into) : into(into) {  }
	    void add (const TTerm* t) {
		if (dynamic_cast<const Variable*>(t) != NULL
		    && std::find(into.begin(), into.end(), t) == into.end())
		    into.push_back(t);
	    }
	    virtual void visit (const DeclPattern& p) {
		for (std::vector<const TriplePattern*>::const_iterator it = p.triples.begin();
		     it != p.triples.end(); ++it) {
		    add((*it)->getS()); add((*it)->getP()); add((*it)->getO());
		}
	    }
	    virtual void visit (const FilterPattern&) {  }
	    virtual void visit (const UnaryPattern& p) { p.inner->accept(*this); }
	    virtual void visit (const ConjPattern& p) {
		for (std::vector<const Pattern*>::const_iterator it = p.elts.begin();
		     it != p.elts.end(); ++it)
		    (*it)->accept(*this);
	    }
	    virtual void visit (const ConnPattern& p) { p.l->accept(*this); p.r->accept(*this); }
	    virtual void visit (const InGraphPattern& p) { add(p.graph); p.inner->accept(*this); }
	    virtual void visit (const ScopePattern& p) {
		for (std::vector<const TTerm*>::const_iterator it = p.share.begin();
		     it != p.share.end(); ++it)
		    add(*it);
	    }
	    virtual void visit (const ActionPattern&) {  }
	} v(into);
	p.accept(v);
    }

} // namespace a3
} // namespace w3c_sw
