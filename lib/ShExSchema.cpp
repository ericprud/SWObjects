/* ShExSchema.cpp - ShEx2 AST plumbing and validator.
 *
 * The validation algorithm is ported from jena-shex (see ShExSchema.hpp):
 * predicate-based pre-matching, eager recursive valueExpr filtering, iteration
 * over matchings, and acceptance via interval computation over the SORBE form
 * of each triple expression, plus the ShEx 2.1 EXTENDS/ABSTRACT hierarchy.
 */

#include "ShExSchema.hpp"

#include <boost/regex.hpp>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <climits>
#include <typeinfo>
#include "utf8.h"

namespace w3c_sw {
namespace ShEx {

    /* ------------------------------------------------------------ accept() */

    void ShapeAnd::accept (ShapeExprVisitor& v) const { v.visit(*this); }
    void ShapeOr::accept (ShapeExprVisitor& v) const { v.visit(*this); }
    void ShapeNot::accept (ShapeExprVisitor& v) const { v.visit(*this); }
    void NodeConstraint::accept (ShapeExprVisitor& v) const { v.visit(*this); }
    void Shape::accept (ShapeExprVisitor& v) const { v.visit(*this); }
    void ShapeExprRef::accept (ShapeExprVisitor& v) const { v.visit(*this); }
    void ShapeExternal::accept (ShapeExprVisitor& v) const { v.visit(*this); }

    void EachOf::accept (TripleExprVisitor& v) const { v.visit(*this); }
    void OneOf::accept (TripleExprVisitor& v) const { v.visit(*this); }
    void TripleConstraint::accept (TripleExprVisitor& v) const { v.visit(*this); }
    void TripleExprRef::accept (TripleExprVisitor& v) const { v.visit(*this); }
    void TripleExprCardinality::accept (TripleExprVisitor& v) const { v.visit(*this); }

    Shape::~Shape () {
	delete expression;
	for (std::vector<const ShapeExpr*>::const_iterator it = extends.begin();
	     it != extends.end(); ++it)
	    delete *it;
    }

    /* ---------------------------------------------------------------- str() */

    std::string ShapeJunction::_str (const char* op) const {
	std::stringstream ss;
	ss << "(";
	for (std::vector<const ShapeExpr*>::const_iterator it = exprs.begin();
	     it != exprs.end(); ++it) {
	    if (it != exprs.begin()) ss << op;
	    ss << (*it)->str();
	}
	ss << ")";
	return ss.str();
    }

    std::string TripleExprJunction::_str (const char* op) const {
	std::stringstream ss;
	ss << "(";
	for (std::vector<const TripleExpr*>::const_iterator it = exprs.begin();
	     it != exprs.end(); ++it) {
	    if (it != exprs.begin()) ss << op;
	    ss << (*it)->str();
	}
	ss << ")";
	return ss.str();
    }

    std::string NodeConstraint::str () const {
	std::stringstream ss;
	for (std::vector<const NCComponent*>::const_iterator it = components.begin();
	     it != components.end(); ++it) {
	    if (it != components.begin()) ss << " ";
	    ss << (*it)->str();
	}
	return ss.str();
    }

    std::string ValuesC::str () const {
	std::stringstream ss;
	ss << "[";
	for (std::vector<const ValueSetValue*>::const_iterator it = values.begin();
	     it != values.end(); ++it)
	    ss << " " << (*it)->str();
	ss << " ]";
	return ss.str();
    }

    std::string Shape::str () const {
	std::stringstream ss;
	if (closed) ss << "CLOSED ";
	if (!extra.empty()) {
	    ss << "EXTRA";
	    for (std::set<const TTerm*>::const_iterator it = extra.begin();
		 it != extra.end(); ++it)
		ss << " " << (*it)->toString();
	    ss << " ";
	}
	for (std::vector<const ShapeExpr*>::const_iterator it = extends.begin();
	     it != extends.end(); ++it)
	    ss << "EXTENDS " << (*it)->str() << " ";
	ss << "{" << (expression == NULL ? "" : " " + expression->str() + " ") << "}";
	return ss.str();
    }

    std::string Schema::str () const {
	std::stringstream ss;
	if (start != NULL)
	    ss << "start = " << start->str() << "\n";
	for (std::vector<ShapeDecl*>::const_iterator it = decls.begin();
	     it != decls.end(); ++it) {
	    if ((*it)->isAbstract) ss << "ABSTRACT ";
	    ss << (*it)->label->toString() << " " << (*it)->expr->str() << "\n";
	}
	return ss.str();
    }

    bool NodeConstraint::hasFacet (const std::type_info& ti, int kind) const {
	for (std::vector<const NCComponent*>::const_iterator it = components.begin();
	     it != components.end(); ++it)
	    if (typeid(**it) == ti) {
		if (const StrLengthC* f = dynamic_cast<const StrLengthC*>(*it)) {
		    if ((int)f->kind == kind) return true;
		} else
		    return true;
	    }
	return false;
    }

    /* -------------------------------------------------------- value matching */

    bool TermValue::matches (const TTerm* test) const {
	return test == term;
    }

    static std::string lowercase (const std::string& s) {
	std::string ret = s;
	std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
	return ret;
    }

    bool StemRangeValue::languageMatches (const std::string& tag, const std::string& range) {
	// BCP47 extended filtering on subtag boundaries, case-insensitive.
	if (range.empty())
	    return !tag.empty();
	std::string t = lowercase(tag), r = lowercase(range);
	if (t == r)
	    return true;
	return t.size() > r.size() && t.compare(0, r.size(), r) == 0 && t[r.size()] == '-';
    }

    bool StemRangeValue::keyFor (const TTerm* term, std::string& key) const {
	switch (family) {
	case IRI_family: {
	    const URI* u = dynamic_cast<const URI*>(term);
	    if (u == NULL) return false;
	    key = u->getLexicalValue();
	    return true;
	}
	case Literal_family: {
	    const RDFLiteral* l = dynamic_cast<const RDFLiteral*>(term);
	    if (l == NULL) return false;
	    key = l->getLexicalValue();
	    return true;
	}
	default: { // Language_family
	    const RDFLiteral* l = dynamic_cast<const RDFLiteral*>(term);
	    if (l == NULL || l->getLangtag() == NULL) return false;
	    key = l->getLangtag()->getLexicalValue();
	    return true;
	}
	}
    }

    bool StemRangeValue::stemMatches (const std::string& key, const std::string& stem) const {
	if (family == Language_family)
	    return languageMatches(key, stem);
	return key.size() >= stem.size() && key.compare(0, stem.size(), stem) == 0;
    }

    bool StemRangeValue::matches (const TTerm* test) const {
	std::string key;
	if (!keyFor(test, key))
	    return false;
	if (isExactLanguage) {
	    if (lowercase(key) != lowercase(stem))
		return false;
	} else if (!wildcard && !stemMatches(key, stem))
	    return false;
	for (std::vector<Exclusion>::const_iterator it = exclusions.begin();
	     it != exclusions.end(); ++it) {
	    if (it->isStem) {
		if (stemMatches(key, it->value))
		    return false;
	    } else {
		if (family == Language_family
		    ? lowercase(key) == lowercase(it->value)
		    : key == it->value)
		    return false;
	    }
	}
	return true;
    }

    std::string StemRangeValue::str () const {
	std::stringstream ss;
	if (wildcard) ss << ".";
	else {
	    if (family == Language_family) ss << "@";
	    ss << stem;
	    if (!isExactLanguage) ss << "~";
	}
	for (std::vector<Exclusion>::const_iterator it = exclusions.begin();
	     it != exclusions.end(); ++it) {
	    ss << " - " << it->value;
	    if (it->isStem) ss << "~";
	}
	return ss.str();
    }

    /* ------------------------------------------------------- structure check */

    namespace {
	/** Walks the reference graph enforcing the ShEx structure rules:
	 *  - references must be defined;
	 *  - a reference cycle must traverse a triple constraint;
	 *  - a reference cycle must not traverse a negation (at any parity);
	 *  - a reference cycle must not traverse a triple constraint whose
	 *    predicate is EXTRA in the enclosing shape (behaves like negation).
	 */
	struct RefWalk {
	    struct State { int neg; int tc; };
	    const Schema& schema;
	    std::map<const TTerm*, State> visiting; // state at entry
	    std::set<const TTerm*> done;
	    int neg, tc;

	    RefWalk (const Schema& schema) : schema(schema), neg(0), tc(0) {  }

	    void shapeExpr (const ShapeExpr* e) {
		if (const ShapeJunction* j = dynamic_cast<const ShapeJunction*>(e)) {
		    for (std::vector<const ShapeExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			shapeExpr(*it);
		} else if (const ShapeNot* n = dynamic_cast<const ShapeNot*>(e)) {
		    ++neg;
		    shapeExpr(n->expr);
		    --neg;
		} else if (const Shape* s = dynamic_cast<const Shape*>(e)) {
		    if (s->expression != NULL)
			tripleExpr(s->expression, s);
		    for (std::vector<const ShapeExpr*>::const_iterator it = s->extends.begin();
			 it != s->extends.end(); ++it)
			shapeExpr(*it);
		} else if (const ShapeExprRef* r = dynamic_cast<const ShapeExprRef*>(e)) {
		    label(r->label);
		}
		// NodeConstraint, ShapeExternal: no references
	    }

	    void tripleExpr (const TripleExpr* e, const Shape* enclosing) {
		if (const TripleExprJunction* j = dynamic_cast<const TripleExprJunction*>(e)) {
		    for (std::vector<const TripleExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			tripleExpr(*it, enclosing);
		} else if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e)) {
		    tripleExpr(c->expr, enclosing);
		} else if (const TripleConstraint* tcon = dynamic_cast<const TripleConstraint*>(e)) {
		    if (tcon->valueExpr != NULL) {
			bool isExtra = enclosing != NULL
			    && enclosing->extra.find(tcon->predicate) != enclosing->extra.end();
			++tc;
			if (isExtra) ++neg; // an EXTRA'd constraint can act negated
			shapeExpr(tcon->valueExpr);
			if (isExtra) --neg;
			--tc;
		    }
		} else if (const TripleExprRef* r = dynamic_cast<const TripleExprRef*>(e)) {
		    const TripleExpr* defn = schema.getTripleExpr(r->label);
		    if (defn == NULL)
			throw StructureError("undefined triple expression reference "
					     + r->label->toString());
		    // walk the inclusion in place to track cycles through it
		    if (inclusions.insert(r->label).second) {
			tripleExpr(defn, enclosing);
			inclusions.erase(r->label);
		    }
		}
	    }
	    std::set<const TTerm*> inclusions;

	    void label (const TTerm* l) {
		std::map<const TTerm*, ShapeDecl*>::const_iterator decl
		    = schema.declIndex.find(l);
		if (decl == schema.declIndex.end())
		    throw StructureError("undefined shape reference " + l->toString());
		if (done.find(l) != done.end())
		    return;
		std::map<const TTerm*, State>::const_iterator v = visiting.find(l);
		if (v != visiting.end()) {
		    if (v->second.neg != neg)
			throw StructureError("negation cycle through " + l->toString());
		    if (v->second.tc == tc)
			throw StructureError("circular shape reference " + l->toString());
		    return;
		}
		State s; s.neg = neg; s.tc = tc;
		visiting[l] = s;
		shapeExpr(decl->second->expr);
		visiting.erase(l);
		// A shape may participate in several cycles at different
		// polarities; only cache fully-clean completions at top level.
		if (neg == 0 && tc == 0)
		    done.insert(l);
	    }
	};
    }

    void Schema::checkStructure () const {
	// a label may not name both a shape expression and a triple expression
	for (std::map<const TTerm*, const TripleExpr*>::const_iterator it
		 = tripleExprIndex.begin(); it != tripleExprIndex.end(); ++it)
	    if (declIndex.find(it->first) != declIndex.end())
		throw StructureError("label " + it->first->toString()
				     + " names both a shape and a triple expression");
	RefWalk walk(*this);
	if (start != NULL)
	    walk.shapeExpr(start);
	for (std::vector<ShapeDecl*>::const_iterator it = decls.begin();
	     it != decls.end(); ++it)
	    walk.label((*it)->label);
    }

    /* ============================================================ validation */

    static const char* XSD = "http://www.w3.org/2001/XMLSchema#";

    /** XSD lexical-form validation for the datatypes the test suite uses. */
    namespace xsdval {

	static bool checkedInteger (const std::string& lex, long long min, long long max,
				    bool hasMin, bool hasMax) {
	    static const boost::regex intPat("[+-]?[0-9]+");
	    if (!boost::regex_match(lex, intPat))
		return false;
	    if (!hasMin && !hasMax)
		return true;
	    errno = 0;
	    long long v = strtoll(lex.c_str(), NULL, 10);
	    if (errno == ERANGE)
		return false;
	    return (!hasMin || v >= min) && (!hasMax || v <= max);
	}

	static bool valid (const std::string& lex, const std::string& dt) {
	    if (dt.compare(0, strlen(XSD), XSD) != 0)
		return true; // unknown datatypes are not checked
	    std::string local = dt.substr(strlen(XSD));
	    static const long long i8min = -128, i8max = 127,
		i16min = -32768, i16max = 32767,
		i32min = -2147483647LL - 1, i32max = 2147483647LL;
	    if (local == "integer") return checkedInteger(lex, 0, 0, false, false);
	    if (local == "long") return checkedInteger(lex, LLONG_MIN, LLONG_MAX, true, true);
	    if (local == "int") return checkedInteger(lex, i32min, i32max, true, true);
	    if (local == "short") return checkedInteger(lex, i16min, i16max, true, true);
	    if (local == "byte") return checkedInteger(lex, i8min, i8max, true, true);
	    if (local == "nonNegativeInteger") return checkedInteger(lex, 0, 0, true, false);
	    if (local == "positiveInteger") return checkedInteger(lex, 1, 0, true, false);
	    if (local == "nonPositiveInteger") return checkedInteger(lex, 0, 0, false, true);
	    if (local == "negativeInteger") return checkedInteger(lex, 0, -1, false, true);
	    if (local == "unsignedLong") return checkedInteger(lex, 0, 0, true, false);
	    if (local == "unsignedInt") return checkedInteger(lex, 0, 4294967295LL, true, true);
	    if (local == "unsignedShort") return checkedInteger(lex, 0, 65535, true, true);
	    if (local == "unsignedByte") return checkedInteger(lex, 0, 255, true, true);
	    if (local == "decimal") {
		static const boost::regex pat("[+-]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)");
		return boost::regex_match(lex, pat);
	    }
	    if (local == "float" || local == "double") {
		// XSD allows INF and -INF but not +INF.
		static const boost::regex pat("[+-]?([0-9]+(\\.[0-9]*)?|\\.[0-9]+)([Ee][+-]?[0-9]+)?|-?INF|NaN");
		return boost::regex_match(lex, pat);
	    }
	    if (local == "boolean")
		return lex == "true" || lex == "false" || lex == "0" || lex == "1";
	    if (local == "dateTime") {
		static const boost::regex pat("-?([1-9][0-9]{3,}|0[0-9]{3})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])"
					      "T(([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9](\\.[0-9]+)?|(24:00:00(\\.0+)?))"
					      "(Z|(\\+|-)((0[0-9]|1[0-3]):[0-5][0-9]|14:00))?");
		return boost::regex_match(lex, pat);
	    }
	    return true; // other xsd types: unchecked
	}

	/** Is this a datatype to which the ShEx numeric facets can apply? */
	static bool numericDatatype (const std::string& dt) {
	    if (dt.compare(0, strlen(XSD), XSD) != 0)
		return false;
	    std::string local = dt.substr(strlen(XSD));
	    static const char* numerics[] = {
		"integer", "decimal", "float", "double",
		"nonPositiveInteger", "negativeInteger", "long", "int", "short",
		"byte", "nonNegativeInteger", "unsignedLong", "unsignedInt",
		"unsignedShort", "unsignedByte", "positiveInteger"
	    };
	    for (size_t i = 0; i < sizeof(numerics)/sizeof(numerics[0]); ++i)
		if (local == numerics[i])
		    return true;
	    return false;
	}
    }

    /* ----------------------------------------------------- interval algebra */

    namespace {

	struct Interval {
	    long min, max; // max == Unbounded for ∞
	    Interval (long min, long max) : min(min), max(max) {  }
	    bool contains1 () const {
		return min <= 1 && (max == Unbounded || 1 <= max);
	    }
	};
	static const Interval ZERO_INTERVAL(0, 0);
	static const Interval EMPTY_INTERVAL(2, 1);
	static const Interval STAR_INTERVAL(0, Unbounded);
	static const Interval PLUS_INTERVAL(1, Unbounded);

	static bool isEmptyIvl (const Interval& i) {
	    return i.max != Unbounded && i.min > i.max;
	}

	static Interval addIvl (const Interval& a, const Interval& b) {
	    if (isEmptyIvl(a) || isEmptyIvl(b))
		return EMPTY_INTERVAL;
	    return Interval(a.min + b.min,
			    (a.max == Unbounded || b.max == Unbounded)
			    ? Unbounded : a.max + b.max);
	}

	static Interval interIvl (const Interval& a, const Interval& b) {
	    long max = a.max == Unbounded ? b.max
		: b.max == Unbounded ? a.max
		: std::min(a.max, b.max);
	    return Interval(std::max(a.min, b.min), max);
	}

	static Interval divIvl (long nbOcc, const Cardinality& card) {
	    if (card.min == 0 && card.max == 0)
		return nbOcc == 0 ? STAR_INTERVAL : EMPTY_INTERVAL;
	    long imin, imax;
	    if (card.max == Unbounded)
		imin = nbOcc == 0 ? 0 : 1;
	    else
		imin = nbOcc % card.max == 0 ? nbOcc / card.max : nbOcc / card.max + 1;
	    imax = card.min == 0 ? Unbounded : nbOcc / card.min;
	    return Interval(imin, imax);
	}

	typedef std::map<const TripleConstraint*, long> Bag;
    } // namespace

    namespace detail {
	/** SORBE form of a triple expression plus origin bookkeeping (see
	 * jena-shex TripleExprForValidation). */
	struct SorbeExpr {
	    const Schema& schema;
	    const TripleExpr* original;
	    const TripleExpr* sorbe; // owned iff != original
	    std::vector<const TripleConstraint*> allTCs;
	    std::map<const TTerm*, std::vector<const TripleConstraint*> > byPredicate[2]; // [inverse]
	    std::map<const TripleExpr*, std::vector<const TripleConstraint*> > subExprTCs;
	    // sorbe copy -> the original triple constraint it was cloned from
	    std::map<const TripleConstraint*, const TripleConstraint*> origin;

	    SorbeExpr (const Schema& schema, const TripleExpr* expr)
		: schema(schema), original(expr) {
		sorbe = isSorbe(expr) ? expr : makeSorbe(expr);
		collectTCs(relevant(), allTCs);
		for (std::vector<const TripleConstraint*>::const_iterator it = allTCs.begin();
		     it != allTCs.end(); ++it)
		    byPredicate[(*it)->inverse ? 1 : 0][(*it)->predicate].push_back(*it);
	    }
	    ~SorbeExpr () {
		if (sorbe != original)
		    delete sorbe;
	    }

	    const TripleExpr* relevant () const { return sorbe; }

	    /* -- SORBE detection/construction -- */

	    bool containsEmpty (const TripleExpr* e) const {
		if (dynamic_cast<const TripleConstraint*>(e))
		    return false;
		if (const EachOf* eo = dynamic_cast<const EachOf*>(e)) {
		    for (std::vector<const TripleExpr*>::const_iterator it = eo->exprs.begin();
			 it != eo->exprs.end(); ++it)
			if (!containsEmpty(*it))
			    return false;
		    return true;
		}
		if (const OneOf* oo = dynamic_cast<const OneOf*>(e)) {
		    for (std::vector<const TripleExpr*>::const_iterator it = oo->exprs.begin();
			 it != oo->exprs.end(); ++it)
			if (containsEmpty(*it))
			    return true;
		    return false;
		}
		if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e))
		    return c->card.min == 0 || containsEmpty(c->expr);
		if (const TripleExprRef* r = dynamic_cast<const TripleExprRef*>(e))
		    return containsEmpty(schema.getTripleExpr(r->label));
		return true; // "empty" expression
	    }

	    bool isSorbe (const TripleExpr* e) const {
		if (dynamic_cast<const TripleExprRef*>(e))
		    return false;
		if (const TripleExprJunction* j = dynamic_cast<const TripleExprJunction*>(e)) {
		    for (std::vector<const TripleExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			if (!isSorbe(*it))
			    return false;
		    return true;
		}
		if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e)) {
		    if (!isSorbe(c->expr))
			return false;
		    if (dynamic_cast<const TripleConstraint*>(c->expr))
			return true;
		    const Cardinality& card = c->card;
		    if (card.min == 1 && card.max == Unbounded && containsEmpty(c->expr))
			return false; // PLUS over nullable
		    return (card.min == 0 && card.max == Unbounded) // *
			|| (card.min == 1 && card.max == Unbounded) // +
			|| (card.min == 0 && card.max == 1)         // ?
			|| (card.min == 0 && card.max == 0);        // {0,0}
		}
		return true; // TripleConstraint
	    }

	    const TripleExpr* clone (const TripleExpr* e) {
		if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(e)) {
		    // The valueExpr stays SHARED with the original constraint:
		    // the copy is only used for counting, so it must not own
		    // (and later delete) the value expression.
		    TripleConstraint* copy = new TripleConstraint(tc->inverse, tc->predicate, NULL);
		    copy->sharedValueExpr = tc->effectiveValueExpr();
		    origin[copy] = tc;
		    return copy;
		}
		if (const EachOf* eo = dynamic_cast<const EachOf*>(e)) {
		    EachOf* ret = new EachOf();
		    for (std::vector<const TripleExpr*>::const_iterator it = eo->exprs.begin();
			 it != eo->exprs.end(); ++it)
			ret->exprs.push_back(clone(*it));
		    return ret;
		}
		if (const OneOf* oo = dynamic_cast<const OneOf*>(e)) {
		    OneOf* ret = new OneOf();
		    for (std::vector<const TripleExpr*>::const_iterator it = oo->exprs.begin();
			 it != oo->exprs.end(); ++it)
			ret->exprs.push_back(clone(*it));
		    return ret;
		}
		if (const TripleExprRef* r = dynamic_cast<const TripleExprRef*>(e))
		    return clone(schema.getTripleExpr(r->label));
		const TripleExprCardinality* c = static_cast<const TripleExprCardinality*>(e);
		Cardinality card = c->card;
		if (dynamic_cast<const TripleConstraint*>(c->expr) != NULL)
		    return new TripleExprCardinality(clone(c->expr), card);
		if (card.min == 1 && card.max == Unbounded && containsEmpty(c->expr))
		    return new TripleExprCardinality(clone(c->expr), Cardinality(0, Unbounded));
		if ((card.min == 0 && card.max == Unbounded)
		    || (card.min == 1 && card.max == Unbounded)
		    || (card.min == 0 && card.max == 1)
		    || (card.min == 0 && card.max == 0))
		    return new TripleExprCardinality(clone(c->expr), card);
		// non-standard cardinality on a group: unfold into copies
		long nbClones, nbOptClones;
		const TripleExpr* remainder = NULL;
		if (card.max == Unbounded) {
		    nbClones = card.min - 1;
		    nbOptClones = 0;
		    remainder = new TripleExprCardinality(clone(c->expr), Cardinality(1, Unbounded));
		} else {
		    nbClones = card.min;
		    nbOptClones = card.max - card.min;
		}
		EachOf* ret = new EachOf();
		for (long i = 0; i < nbClones; ++i)
		    ret->exprs.push_back(clone(c->expr));
		for (long i = 0; i < nbOptClones; ++i)
		    ret->exprs.push_back(new TripleExprCardinality(clone(c->expr), Cardinality(0, 1)));
		if (remainder != NULL)
		    ret->exprs.push_back(remainder);
		if (ret->exprs.empty()) {
		    // card was {0,0}: handled above, but keep a safe fallback
		    delete ret;
		    return new TripleExprCardinality(clone(c->expr), card);
		}
		return ret;
	    }

	    const TripleExpr* makeSorbe (const TripleExpr* e) {
		return clone(e);
	    }

	    static void collectTCs (const TripleExpr* e, std::vector<const TripleConstraint*>& into) {
		if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(e)) {
		    into.push_back(tc);
		    return;
		}
		if (const TripleExprJunction* j = dynamic_cast<const TripleExprJunction*>(e)) {
		    for (std::vector<const TripleExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			collectTCs(*it, into);
		    return;
		}
		if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e))
		    collectTCs(c->expr, into);
		// TripleExprRef cannot appear in a SORBE form
	    }

	    /** Upper bound on how many triples each TC can absorb: the product
	     * of the enclosing cardinality maxima (Unbounded when any is
	     * unbounded). A necessary condition on bags, used to prune the
	     * matching enumeration. */
	    static void maxCounts (const TripleExpr* e, long mult,
				   std::map<const TripleConstraint*, long>& into) {
		if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(e)) {
		    into[tc] = mult;
		    return;
		}
		if (const TripleExprJunction* j = dynamic_cast<const TripleExprJunction*>(e)) {
		    for (std::vector<const TripleExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			maxCounts(*it, mult, into);
		    return;
		}
		if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e)) {
		    long inner = (mult == Unbounded || c->card.max == Unbounded)
			? (long)Unbounded : mult * c->card.max;
		    maxCounts(c->expr, inner, into);
		}
	    }

	    const std::vector<const TripleConstraint*>& tcsOfSubExpr (const TripleExpr* e) {
		std::map<const TripleExpr*, std::vector<const TripleConstraint*> >::iterator it
		    = subExprTCs.find(e);
		if (it == subExprTCs.end()) {
		    std::vector<const TripleConstraint*> tcs;
		    collectTCs(e, tcs);
		    it = subExprTCs.insert(std::make_pair(e, tcs)).first;
		}
		return it->second;
	    }

	    bool isEmptySubbag (const Bag& bag, const TripleExpr* e) {
		const std::vector<const TripleConstraint*>& tcs = tcsOfSubExpr(e);
		for (std::vector<const TripleConstraint*>::const_iterator it = tcs.begin();
		     it != tcs.end(); ++it) {
		    Bag::const_iterator b = bag.find(*it);
		    if (b != bag.end() && b->second != 0)
			return false;
		}
		return true;
	    }

	    Interval interval (const TripleExpr* e, const Bag& bag) {
		if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(e)) {
		    Bag::const_iterator b = bag.find(tc);
		    long n = b == bag.end() ? 0 : b->second;
		    return Interval(n, n);
		}
		if (const OneOf* oo = dynamic_cast<const OneOf*>(e)) {
		    Interval res = ZERO_INTERVAL;
		    for (std::vector<const TripleExpr*>::const_iterator it = oo->exprs.begin();
			 it != oo->exprs.end(); ++it)
			res = addIvl(res, interval(*it, bag));
		    return res;
		}
		if (const EachOf* eo = dynamic_cast<const EachOf*>(e)) {
		    Interval res = STAR_INTERVAL;
		    for (std::vector<const TripleExpr*>::const_iterator it = eo->exprs.begin();
			 it != eo->exprs.end(); ++it)
			res = interIvl(res, interval(*it, bag));
		    return res;
		}
		const TripleExprCardinality* c = static_cast<const TripleExprCardinality*>(e);
		const Cardinality& card = c->card;
		if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(c->expr)) {
		    Bag::const_iterator b = bag.find(tc);
		    long n = b == bag.end() ? 0 : b->second;
		    return divIvl(n, card);
		}
		if (card.min == 0 && card.max == Unbounded) { // * on group
		    if (isEmptySubbag(bag, c))
			return STAR_INTERVAL;
		    Interval sub = interval(c->expr, bag);
		    return isEmptyIvl(sub) ? EMPTY_INTERVAL : PLUS_INTERVAL;
		}
		if (card.min == 1 && card.max == Unbounded) { // + on group
		    if (isEmptySubbag(bag, c))
			return ZERO_INTERVAL;
		    Interval sub = interval(c->expr, bag);
		    return isEmptyIvl(sub) ? EMPTY_INTERVAL : Interval(1, sub.max);
		}
		if (card.min == 0 && card.max == 1) // ? on group
		    return addIvl(interval(c->expr, bag), STAR_INTERVAL);
		if (card.min == 0 && card.max == 0) // {0,0}
		    return isEmptySubbag(bag, c) ? STAR_INTERVAL : EMPTY_INTERVAL;
		// unreachable for SORBE forms
		return EMPTY_INTERVAL;
	    }

	    bool acceptsBag (const Bag& bag) {
		return interval(relevant(), bag).contains1();
	    }
	};
    } // namespace detail
    using detail::SorbeExpr;

    namespace {
	/** Iteration over triple -> candidate-TC choices: a DFS that
	 * backtracks as soon as a partial assignment gives some TC more
	 * triples than its cardinality maxima allow (SorbeExpr::maxCounts),
	 * so infeasible cartesian subtrees are never expanded. */
	struct Matchings {
	    std::vector<DataTriple> triples;
	    std::vector<const std::vector<const TripleConstraint*>*> options;
	    const std::map<const TripleConstraint*, long>& bounds;
	    std::vector<size_t> idx;
	    std::map<const TripleConstraint*, long> counts;
	    size_t pos;      // levels [0, pos) are chosen and counted
	    bool fresh;      // no assignment emitted yet
	    bool exhausted;

	    Matchings (const std::map<DataTriple, std::vector<const TripleConstraint*> >& preMatching,
		       const std::map<const TripleConstraint*, long>& bounds)
		: bounds(bounds), pos(0), fresh(true), exhausted(false) {
		for (std::map<DataTriple, std::vector<const TripleConstraint*> >::const_iterator it
			 = preMatching.begin(); it != preMatching.end(); ++it) {
		    triples.push_back(it->first);
		    options.push_back(&it->second);
		    idx.push_back(0);
		    if (it->second.empty())
			exhausted = true; // no way to match this triple
		}
	    }

	    bool fits (const TripleConstraint* tc) const {
		std::map<const TripleConstraint*, long>::const_iterator b = bounds.find(tc);
		if (b == bounds.end() || b->second == Unbounded)
		    return true;
		std::map<const TripleConstraint*, long>::const_iterator c = counts.find(tc);
		return (c == counts.end() ? 0 : c->second) < b->second;
	    }

	    bool next (std::map<DataTriple, const TripleConstraint*>& matching) {
		if (exhausted)
		    return false;
		if (triples.empty()) {
		    exhausted = true; // the single empty matching
		    matching.clear();
		    return true;
		}
		if (!fresh) {
		    // resume: back out of the last emitted assignment
		    --pos;
		    --counts[(*options[pos])[idx[pos]]];
		    ++idx[pos];
		}
		fresh = false;
		while (true) {
		    if (pos == triples.size()) {
			matching.clear();
			for (size_t i = 0; i < triples.size(); ++i)
			    matching[triples[i]] = (*options[i])[idx[i]];
			return true;
		    }
		    if (idx[pos] >= options[pos]->size()) {
			if (pos == 0) {
			    exhausted = true;
			    return false;
			}
			idx[pos] = 0;
			--pos;
			--counts[(*options[pos])[idx[pos]]];
			++idx[pos];
			continue;
		    }
		    const TripleConstraint* tc = (*options[pos])[idx[pos]];
		    if (!fits(tc)) {
			++idx[pos]; // prune: this TC cannot absorb another triple
			continue;
		    }
		    ++counts[tc];
		    ++pos;
		}
	    }
	};
    } // namespace

    /* ------------------------------------------------------------- Validator */

    struct ShapeExprEval : public ShapeExprVisitor {
	Validator& v;
	const TTerm* node;
	const std::vector<DataTriple>* neigh;
	bool result;

	ShapeExprEval (Validator& v, const TTerm* node, const std::vector<DataTriple>* neigh)
	    : v(v), node(node), neigh(neigh), result(false) {  }

	virtual void visit (const ShapeAnd& e) {
	    for (std::vector<const ShapeExpr*>::const_iterator it = e.exprs.begin();
		 it != e.exprs.end(); ++it)
		if (!v.satisfies(node, *it, neigh)) {
		    result = false;
		    return;
		}
	    result = true;
	}
	virtual void visit (const ShapeOr& e) {
	    for (std::vector<const ShapeExpr*>::const_iterator it = e.exprs.begin();
		 it != e.exprs.end(); ++it)
		if (v.satisfies(node, *it, neigh)) {
		    result = true;
		    return;
		}
	    result = false;
	}
	virtual void visit (const ShapeNot& e) {
	    result = !v.satisfies(node, e.expr, neigh);
	}
	virtual void visit (const NodeConstraint& e) {
	    result = v.satisfiesNodeConstraint(node, &e);
	}
	virtual void visit (const Shape& e) {
	    result = v.satisfiesShape(node, &e, neigh);
	}
	virtual void visit (const ShapeExprRef& e) {
	    if (neigh == NULL) {
		result = v.satisfiesLabel(node, e.label);
		return;
	    }
	    // Validating a fixed set of triples against a reference: consider
	    // the non-abstract descendants (EXTENDS).
	    std::vector<const TTerm*> descendants = v.nonAbstractDescendants(e.label);
	    for (std::vector<const TTerm*>::const_iterator it = descendants.begin();
		 it != descendants.end(); ++it) {
		const ShapeExpr* defn = v.schema.getShapeExpr(*it);
		if (defn == NULL)
		    continue;
		const TTerm* outerDeclLabel = v.currentDeclLabel;
		v.currentDeclLabel = *it;
		bool ok = v.satisfies(node, defn, neigh);
		v.currentDeclLabel = outerDeclLabel;
		if (ok) {
		    result = true;
		    return;
		}
	    }
	    result = false;
	}
	virtual void visit (const ShapeExternal& e) {
	    (void)e;
	    if (v.externalResolver != NULL && v.currentDeclLabel != NULL) {
		const ShapeExpr* resolved
		    = v.externalResolver->resolveExternal(v.currentDeclLabel);
		if (resolved != NULL) {
		    result = v.satisfies(node, resolved, neigh);
		    return;
		}
	    }
	    result = false; // EXTERNAL without a resolution
	}
    };

    Validator::~Validator () {
	for (std::map<const TripleExpr*, detail::SorbeExpr*>::iterator it = sorbeCache.begin();
	     it != sorbeCache.end(); ++it)
	    delete it->second;
    }

    detail::SorbeExpr* Validator::getSorbe (const TripleExpr* expr) {
	std::map<const TripleExpr*, detail::SorbeExpr*>::const_iterator hit
	    = sorbeCache.find(expr);
	if (hit != sorbeCache.end())
	    return hit->second;
	detail::SorbeExpr* made = new detail::SorbeExpr(schema, expr);
	sorbeCache[expr] = made;
	return made;
    }

    bool Validator::satisfies (const TTerm* node, const ShapeExpr* expr,
			       const std::vector<DataTriple>* neigh) {
	size_t mark = semActHandler != NULL ? semActHandler->mark() : 0;
	ShapeExprEval eval(*this, node, neigh);
	expr->accept(eval);
	bool ok = eval.result
	    && evalSemActs(expr->semActs, SemActContext(node));
	if (!ok && semActHandler != NULL)
	    semActHandler->rollback(mark); // failed subtrees leave no bindings
	return ok;
    }

    std::string Validator::termString (const TTerm* node) const {
	if (bnodeLabels != NULL && dynamic_cast<const BNode*>(node) != NULL) {
	    std::map<const TTerm*, std::string>::const_iterator it = bnodeLabels->find(node);
	    if (it != bnodeLabels->end())
		return it->second;
	}
	return node->getLexicalValue();
    }

    bool Validator::evalSemActs (const std::vector<SemAct>& semActs,
				 const SemActContext& ctx) const {
	for (std::vector<SemAct>::const_iterator it = semActs.begin();
	     it != semActs.end(); ++it) {
	    if (semActHandler != NULL && !semActHandler->evaluate(*it, ctx))
		return false;
	    if (it->name->getLexicalValue() != "http://shex.io/extensions/Test/")
		continue; // other extension languages: only the handler sees them
	    if (!it->hasCode)
		continue;
	    std::string code = it->code;
	    size_t start = code.find_first_not_of(" \t\r\n");
	    if (start != std::string::npos && code.compare(start, 4, "fail") == 0)
		return false;
	}
	return true;
    }

    /** Dispatch the semantic actions in a triple expression tree, giving each
     * expression the triples the accepted matching assigned within it.
     * Appends this subtree's matched triples to collected. */
    bool Validator::tripleExprSemActsPass (const TripleExpr* e, const TTerm* node,
					   const TCMatches& matches,
					   std::vector<DataTriple>& collected,
					   std::set<const TripleExpr*>& seen) const {
	if (e == NULL || !seen.insert(e).second)
	    return true;
	std::vector<DataTriple> mine;
	bool ok = true;
	if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(e)) {
	    TCMatches::const_iterator hit = matches.find(tc);
	    if (hit != matches.end())
		mine = hit->second;
	    ok = evalSemActs(e->semActs, SemActContext(node, tc, &mine));
	} else {
	    if (const TripleExprJunction* j = dynamic_cast<const TripleExprJunction*>(e)) {
		for (std::vector<const TripleExpr*>::const_iterator it = j->exprs.begin();
		     ok && it != j->exprs.end(); ++it)
		    ok = tripleExprSemActsPass(*it, node, matches, mine, seen);
	    } else if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e)) {
		ok = tripleExprSemActsPass(c->expr, node, matches, mine, seen);
	    } else if (const TripleExprRef* r = dynamic_cast<const TripleExprRef*>(e)) {
		ok = tripleExprSemActsPass(schema.getTripleExpr(r->label), node, matches, mine, seen);
	    }
	    if (ok)
		ok = evalSemActs(e->semActs, SemActContext(node, NULL, &mine));
	}
	collected.insert(collected.end(), mine.begin(), mine.end());
	return ok;
    }

    /** Split an extendable shape declaration into its main Shape (the one
     * carrying the triple expression and EXTENDS) and the remaining
     * constraints. The main Shape need not be the first conjunct. */
    bool Validator::mainShapeAndConstraints (const ShapeExpr* defn,
					     const Shape*& mainShape,
					     std::vector<const ShapeExpr*>& constrs) {
	mainShape = dynamic_cast<const Shape*>(defn);
	if (mainShape != NULL)
	    return true;
	const ShapeAnd* a = dynamic_cast<const ShapeAnd*>(defn);
	if (a == NULL)
	    return false;
	for (std::vector<const ShapeExpr*>::const_iterator it = a->exprs.begin();
	     it != a->exprs.end(); ++it) {
	    const ShapeExpr* deref = *it;
	    std::set<const ShapeExpr*> seen;
	    while (const ShapeExprRef* r = dynamic_cast<const ShapeExprRef*>(deref)) {
		if (!seen.insert(deref).second)
		    break;
		deref = schema.getShapeExpr(r->label);
		if (deref == NULL)
		    break;
	    }
	    const Shape* asShape = dynamic_cast<const Shape*>(deref);
	    if (asShape != NULL && mainShape == NULL)
		mainShape = asShape;
	    else
		constrs.push_back(*it);
	}
	return mainShape != NULL;
    }

    void Validator::computeHierarchy () {
	if (hierarchyComputed)
	    return;
	hierarchyComputed = true;
	// direct edges: sub -> supers, via each decl's main shape's EXTENDS refs
	std::map<const TTerm*, std::vector<const TTerm*> > directSupers;
	for (std::vector<ShapeDecl*>::const_iterator it = schema.decls.begin();
	     it != schema.decls.end(); ++it) {
	    const Shape* mainShape;
	    std::vector<const ShapeExpr*> constrs;
	    if (!mainShapeAndConstraints((*it)->expr, mainShape, constrs))
		continue;
	    for (std::vector<const ShapeExpr*>::const_iterator x = mainShape->extends.begin();
		 x != mainShape->extends.end(); ++x)
		if (const ShapeExprRef* r = dynamic_cast<const ShapeExprRef*>(*x))
		    directSupers[(*it)->label].push_back(r->label);
	}
	// transitive closures (BFS, self first)
	for (std::vector<ShapeDecl*>::const_iterator it = schema.decls.begin();
	     it != schema.decls.end(); ++it) {
	    const TTerm* start = (*it)->label;
	    std::vector<const TTerm*>& supers = supertypes[start];
	    std::set<const TTerm*> seen;
	    std::vector<const TTerm*> queue(1, start);
	    while (!queue.empty()) {
		const TTerm* cur = queue.front();
		queue.erase(queue.begin());
		if (!seen.insert(cur).second)
		    continue;
		supers.push_back(cur);
		std::map<const TTerm*, std::vector<const TTerm*> >::const_iterator d
		    = directSupers.find(cur);
		if (d != directSupers.end())
		    queue.insert(queue.end(), d->second.begin(), d->second.end());
	    }
	}
	// subtypes: invert
	for (std::map<const TTerm*, std::vector<const TTerm*> >::const_iterator s
		 = supertypes.begin(); s != supertypes.end(); ++s)
	    for (std::vector<const TTerm*>::const_iterator sup = s->second.begin();
		 sup != s->second.end(); ++sup)
		if (*sup != s->first)
		    subtypes[*sup].push_back(s->first);
    }

    std::vector<const TTerm*> Validator::nonAbstractDescendants (const TTerm* label) {
	computeHierarchy();
	std::vector<const TTerm*> ret;
	std::map<const TTerm*, ShapeDecl*>::const_iterator decl = schema.declIndex.find(label);
	bool rootAbstract = decl != schema.declIndex.end() && decl->second->isAbstract;
	if (!rootAbstract)
	    ret.push_back(label);
	std::map<const TTerm*, std::vector<const TTerm*> >::const_iterator subs
	    = subtypes.find(label);
	if (subs != subtypes.end())
	    for (std::vector<const TTerm*>::const_iterator it = subs->second.begin();
		 it != subs->second.end(); ++it) {
		std::map<const TTerm*, ShapeDecl*>::const_iterator d = schema.declIndex.find(*it);
		if (d != schema.declIndex.end() && !d->second->isAbstract
		    && std::find(ret.begin(), ret.end(), *it) == ret.end())
		    ret.push_back(*it);
	    }
	if (ret.empty())
	    ret.push_back(label); // abstract with no concrete descendants: still try it
	return ret;
    }

    const std::vector<const TTerm*>& Validator::getSupertypes (const TTerm* label) {
	computeHierarchy();
	return supertypes[label];
    }

    bool Validator::satisfiesLabel (const TTerm* node, const TTerm* label) {
	std::pair<const TTerm*, const TTerm*> key(node, label);
	if (inProgress.find(key) != inProgress.end()) {
	    ++assumedCount;
	    return true; // cyclic: assume conformant
	}
	// Completed results can be reused when no handler is watching. Only
	// results computed without any assumption on the stack are cached.
	bool cacheable = semActHandler == NULL;
	if (cacheable) {
	    std::map<std::pair<const TTerm*, const TTerm*>, bool>::const_iterator hit
		= memo.find(key);
	    if (hit != memo.end())
		return hit->second;
	}
	std::map<const TTerm*, ShapeDecl*>::const_iterator decl = schema.declIndex.find(label);
	if (decl == schema.declIndex.end()) {
	    lastError = "undefined shape " + label->toString();
	    return false;
	}
	size_t assumedBefore = assumedCount;
	std::vector<const TTerm*> descendants = nonAbstractDescendants(label);
	bool ret = false;
	for (std::vector<const TTerm*>::const_iterator it = descendants.begin();
	     !ret && it != descendants.end(); ++it) {
	    const ShapeExpr* expr = schema.getShapeExpr(*it);
	    if (expr == NULL)
		continue;
	    std::pair<const TTerm*, const TTerm*> dkey(node, *it);
	    inProgress.insert(key);
	    inProgress.insert(dkey);
	    const TTerm* outerDeclLabel = currentDeclLabel;
	    currentDeclLabel = *it;
	    ret = satisfies(node, expr, NULL);
	    currentDeclLabel = outerDeclLabel;
	    inProgress.erase(dkey);
	    inProgress.erase(key);
	}
	if (cacheable && assumedCount == assumedBefore)
	    memo[key] = ret; // independent of any cyclic assumption
	return ret;
    }

    bool Validator::validate (const TTerm* node, const TTerm* label) {
	lastError.clear();
	inProgress.clear();
	if (!evalSemActs(schema.startActs, SemActContext()))
	    return false;
	if (label == NULL) {
	    if (schema.start == NULL) {
		lastError = "schema has no start shape";
		return false;
	    }
	    return satisfies(node, schema.start, NULL);
	}
	return satisfiesLabel(node, label);
    }

    /* ---------------------------------------------------------- shape eval */

    namespace {
	/** Collect the fwd/inv predicates of the triple constraints reachable
	 * from a triple expression (following references). */
	static void collectPredicates (const Schema& schema, const TripleExpr* e,
				       std::set<const TTerm*>& fwd, std::set<const TTerm*>& inv,
				       std::set<const TripleExpr*>& seen) {
	    if (e == NULL || !seen.insert(e).second)
		return;
	    if (const TripleConstraint* tc = dynamic_cast<const TripleConstraint*>(e)) {
		(tc->inverse ? inv : fwd).insert(tc->predicate);
		return;
	    }
	    if (const TripleExprJunction* j = dynamic_cast<const TripleExprJunction*>(e)) {
		for (std::vector<const TripleExpr*>::const_iterator it = j->exprs.begin();
		     it != j->exprs.end(); ++it)
		    collectPredicates(schema, *it, fwd, inv, seen);
		return;
	    }
	    if (const TripleExprCardinality* c = dynamic_cast<const TripleExprCardinality*>(e)) {
		collectPredicates(schema, c->expr, fwd, inv, seen);
		return;
	    }
	    if (const TripleExprRef* r = dynamic_cast<const TripleExprRef*>(e))
		collectPredicates(schema, schema.getTripleExpr(r->label), fwd, inv, seen);
	}
    }

    bool Validator::satisfiesShape (const TTerm* node, const Shape* shape,
				    const std::vector<DataTriple>* neighIn) {
	// 1. Collect the triple expressions of the EXTENDS hierarchy.
	//    Index 0 is the shape's own expression.
	std::vector<const TTerm*> hierarchyLabels; // parallel to exprs; [0] is NULL
	std::vector<const TripleExpr*> exprs;
	std::vector<std::vector<const ShapeExpr*> > constraints; // per hierarchy member
	hierarchyLabels.push_back(NULL);
	exprs.push_back(shape->expression);
	constraints.push_back(std::vector<const ShapeExpr*>());
	for (std::vector<const ShapeExpr*>::const_iterator x = shape->extends.begin();
	     x != shape->extends.end(); ++x) {
	    const ShapeExprRef* r = dynamic_cast<const ShapeExprRef*>(*x);
	    if (r == NULL)
		continue;
	    const std::vector<const TTerm*>& supers = getSupertypes(r->label);
	    std::vector<const TTerm*> supersOrSelf = supers;
	    if (supersOrSelf.empty())
		supersOrSelf.push_back(r->label);
	    for (std::vector<const TTerm*>::const_iterator s = supersOrSelf.begin();
		 s != supersOrSelf.end(); ++s) {
		if (std::find(hierarchyLabels.begin(), hierarchyLabels.end(), *s)
		    != hierarchyLabels.end())
		    continue;
		const ShapeExpr* defn = schema.getShapeExpr(*s);
		if (defn == NULL)
		    continue;
		// split into main shape and constraints
		const Shape* mainShape;
		std::vector<const ShapeExpr*> constrs;
		if (!mainShapeAndConstraints(defn, mainShape, constrs))
		    continue;
		hierarchyLabels.push_back(*s);
		exprs.push_back(mainShape->expression);
		constraints.push_back(constrs);
	    }
	}

	// 2. Relevant neighbourhood.
	std::set<const TTerm*> fwdPreds, invPreds;
	{
	    std::set<const TripleExpr*> seen;
	    for (std::vector<const TripleExpr*>::const_iterator it = exprs.begin();
		 it != exprs.end(); ++it)
		collectPredicates(schema, *it, fwdPreds, invPreds, seen);
	}
	std::vector<DataTriple> matchables, nonMatchables;
	if (neighIn == NULL) {
	    // the SP/PO indexes make this linear in the neighbourhood
	    // instead of the graph
	    const BasicGraphPattern::triple_iterator end;
	    for (BasicGraphPattern::triple_iterator ti = data.getTripleIterator(node, NULL, NULL);
		 ti != end; ++ti) {
		if (fwdPreds.find((*ti)->getP()) != fwdPreds.end())
		    matchables.push_back(*ti);
		else
		    nonMatchables.push_back(*ti);
	    }
	    for (std::set<const TTerm*>::const_iterator p = invPreds.begin();
		 p != invPreds.end(); ++p)
		for (BasicGraphPattern::triple_iterator ti = data.getTripleIterator(NULL, *p, node);
		     ti != end; ++ti)
		    matchables.push_back(*ti);
	} else
	    matchables = *neighIn;

	// 3. CLOSED
	if (shape->closed && !nonMatchables.empty())
	    return false;

	// 4. SORBE forms (memoized per triple expression).
	std::vector<SorbeExpr*> sorbes;
	for (std::vector<const TripleExpr*>::const_iterator it = exprs.begin();
	     it != exprs.end(); ++it)
	    sorbes.push_back(*it == NULL ? NULL : getSorbe(*it));

	bool ret = false;
	{
	    // 5. Pre-matching: triple -> candidate TCs (matching predicate and
	    //    orientation, over all hierarchy members).
	    std::map<DataTriple, std::vector<const TripleConstraint*> > preMatching;
	    for (std::vector<DataTriple>::const_iterator t = matchables.begin();
		 t != matchables.end(); ++t) {
		std::vector<const TripleConstraint*>& cands = preMatching[*t];
		for (std::vector<SorbeExpr*>::const_iterator se = sorbes.begin();
		     se != sorbes.end(); ++se) {
		    if (*se == NULL)
			continue;
		    for (int dir = 0; dir < 2; ++dir) {
			std::map<const TTerm*, std::vector<const TripleConstraint*> >::const_iterator
			    found = (*se)->byPredicate[dir].find((*t)->getP());
			if (found == (*se)->byPredicate[dir].end())
			    continue;
			for (std::vector<const TripleConstraint*>::const_iterator tc
				 = found->second.begin(); tc != found->second.end(); ++tc) {
			    bool inverse = (*tc)->inverse;
			    if (!inverse && (*t)->getS() != node)
				continue;
			    if (inverse && (*t)->getO() != node)
				continue;
			    cands.push_back(*tc);
			}
		    }
		}
	    }

	    // 6. Eager recursive filtering: drop (triple, TC) pairs whose
	    //    valueExpr is not satisfied by the opposite node. Runs with
	    //    the semantic-action handler suppressed: candidates that
	    //    validate but are not chosen by the accepted matching must
	    //    not leave bindings, so handler-observed actions fire later
	    //    (step 10) from the accepted matching only.
	    {
		struct SuppressHandler {
		    Validator& v;
		    SemActHandler* saved;
		    SuppressHandler (Validator& v) : v(v), saved(v.semActHandler) { v.semActHandler = NULL; }
		    ~SuppressHandler () { v.semActHandler = saved; }
		} suppress(*this);
		for (std::map<DataTriple, std::vector<const TripleConstraint*> >::iterator
			 pm = preMatching.begin(); pm != preMatching.end(); ++pm) {
		    std::vector<const TripleConstraint*>& cands = pm->second;
		    for (std::vector<const TripleConstraint*>::iterator tc = cands.begin();
			 tc != cands.end(); ) {
			const ShapeExpr* valueExpr = (*tc)->effectiveValueExpr();
			if (valueExpr == NULL) {
			    ++tc;
			    continue;
			}
			const TTerm* opposite = (*tc)->inverse ? pm->first->getS() : pm->first->getO();
			if (satisfies(opposite, valueExpr, NULL))
			    ++tc;
			else
			    tc = cands.erase(tc);
		    }
		}
	    }

	    // 7. Unmatched triples must be allowed by EXTRA (they then no
	    //    longer take part in the matching).
	    bool extraViolation = false;
	    for (std::map<DataTriple, std::vector<const TripleConstraint*> >::iterator
		     pm = preMatching.begin(); pm != preMatching.end(); ) {
		if (pm->second.empty()) {
		    if (shape->extra.find(pm->first->getP()) == shape->extra.end()) {
			extraViolation = true;
			break;
		    }
		    std::map<DataTriple, std::vector<const TripleConstraint*> >::iterator
			dead = pm++;
		    preMatching.erase(dead);
		} else
		    ++pm;
	    }

	    if (!extraViolation) {
		// 8. Iterate matchings; a matching is accepted when every
		//    hierarchy member's expression accepts its bag...
		std::map<const TripleConstraint*, long> tcBounds;
		for (std::vector<SorbeExpr*>::const_iterator se = sorbes.begin();
		     se != sorbes.end(); ++se)
		    if (*se != NULL)
			SorbeExpr::maxCounts((*se)->relevant(), 1, tcBounds);
		Matchings iter(preMatching, tcBounds);
		std::map<DataTriple, const TripleConstraint*> matching;
		while (iter.next(matching)) {
		    // any bindings this matching creates (steps 9 and 10) are
		    // rolled back if the matching is rejected
		    size_t matchMark = semActHandler != NULL ? semActHandler->mark() : 0;
		    bool all = true;
		    for (std::vector<SorbeExpr*>::const_iterator se = sorbes.begin();
			 all && se != sorbes.end(); ++se) {
			if (*se == NULL)
			    continue;
			Bag bag;
			for (std::vector<const TripleConstraint*>::const_iterator tc
				 = (*se)->allTCs.begin(); tc != (*se)->allTCs.end(); ++tc)
			    bag[*tc] = 0;
			for (std::map<DataTriple, const TripleConstraint*>::const_iterator m
				 = matching.begin(); m != matching.end(); ++m) {
			    Bag::iterator b = bag.find(m->second);
			    if (b != bag.end())
				++b->second;
			}
			all = (*se)->acceptsBag(bag);
		    }
		    if (!all)
			continue;

		    // 9. ...and, with EXTENDS, when the split induced by the
		    //    matching also satisfies each member's constraints.
		    bool constraintsOk = true;
		    for (size_t i = 1; constraintsOk && i < hierarchyLabels.size(); ++i) {
			if (constraints[i].empty())
			    continue;
			const std::vector<const TTerm*>& supers = getSupertypes(hierarchyLabels[i]);
			std::set<size_t> relevantMembers;
			relevantMembers.insert(i);
			for (size_t j = 1; j < hierarchyLabels.size(); ++j)
			    if (std::find(supers.begin(), supers.end(), hierarchyLabels[j])
				!= supers.end())
				relevantMembers.insert(j);
			std::vector<DataTriple> split;
			for (std::map<DataTriple, const TripleConstraint*>::const_iterator m
				 = matching.begin(); m != matching.end(); ++m)
			    for (std::set<size_t>::const_iterator rm = relevantMembers.begin();
				 rm != relevantMembers.end(); ++rm)
				if (sorbes[*rm] != NULL
				    && std::find(sorbes[*rm]->allTCs.begin(),
						 sorbes[*rm]->allTCs.end(), m->second)
				    != sorbes[*rm]->allTCs.end()) {
				    split.push_back(m->first);
				    break;
				}
			for (std::vector<const ShapeExpr*>::const_iterator c
				 = constraints[i].begin();
			     constraintsOk && c != constraints[i].end(); ++c)
			    constraintsOk = satisfies(node, *c, &split);
		    }
		    if (!constraintsOk) {
			if (semActHandler != NULL)
			    semActHandler->rollback(matchMark);
			continue;
		    }
		    {
			// 10. Semantic actions run against the accepted
			//     matching only. First fire the nested value
			//     expressions' actions for the chosen (triple,
			//     constraint) pairs (step 6 filtered silently)...
			bool nestedOk = true;
			if (semActHandler != NULL) {
			    for (std::map<DataTriple, const TripleConstraint*>::const_iterator m
				     = matching.begin(); nestedOk && m != matching.end(); ++m) {
				const ShapeExpr* valueExpr = m->second->effectiveValueExpr();
				if (valueExpr == NULL)
				    continue;
				const TTerm* opposite = m->second->inverse
				    ? m->first->getS() : m->first->getO();
				nestedOk = satisfies(opposite, valueExpr, NULL);
			    }
			}
			if (!nestedOk) {
			    if (semActHandler != NULL)
				semActHandler->rollback(matchMark);
			    continue;
			}
			//     ...then the actions on the (original) triple
			//     expressions must not fail. Each original triple
			//     constraint sees the triples this matching
			//     assigned to its SORBE copies.
			TCMatches tcMatches;
			for (std::map<DataTriple, const TripleConstraint*>::const_iterator m
				 = matching.begin(); m != matching.end(); ++m) {
			    const TripleConstraint* orig = m->second;
			    for (std::vector<SorbeExpr*>::const_iterator se = sorbes.begin();
				 se != sorbes.end(); ++se) {
				if (*se == NULL)
				    continue;
				std::map<const TripleConstraint*, const TripleConstraint*>::const_iterator
				    o = (*se)->origin.find(m->second);
				if (o != (*se)->origin.end()) {
				    orig = o->second;
				    break;
				}
			    }
			    tcMatches[orig].push_back(m->first);
			}
			bool semActsOk = true;
			for (std::vector<const TripleExpr*>::const_iterator te = exprs.begin();
			     semActsOk && te != exprs.end(); ++te) {
			    std::set<const TripleExpr*> seen;
			    std::vector<DataTriple> collected;
			    semActsOk = tripleExprSemActsPass(*te, node, tcMatches, collected, seen);
			}
			if (!semActsOk) {
			    if (semActHandler != NULL)
				semActHandler->rollback(matchMark);
			    continue;
			}
			ret = true;
			break;
		    }
		}
	    }
	}

	return ret; // the SORBE forms stay cached on the validator
    }

    /* -------------------------------------------------- node constraint eval */

    namespace {
	static bool numericValue (const TTerm* node, long double& value) {
	    const RDFLiteral* lit = dynamic_cast<const RDFLiteral*>(node);
	    if (lit == NULL || lit->getLangtag() != NULL)
		return false;
	    const URI* dt = lit->getDatatype();
	    if (dt == NULL || !xsdval::numericDatatype(dt->getLexicalValue()))
		return false;
	    if (!xsdval::valid(lit->getLexicalValue(), dt->getLexicalValue()))
		return false;
	    const std::string lex = lit->getLexicalValue();
	    char* end = NULL;
	    value = strtold(lex.c_str(), &end);
	    return end != lex.c_str();
	}
    }

    bool Validator::satisfiesNodeConstraint (const TTerm* node, const NodeConstraint* nc) {
	for (std::vector<const NCComponent*>::const_iterator it = nc->components.begin();
	     it != nc->components.end(); ++it) {
	    const NCComponent* c = *it;

	    if (const NodeKindC* k = dynamic_cast<const NodeKindC*>(c)) {
		bool isLit = dynamic_cast<const RDFLiteral*>(node) != NULL;
		bool isIri = dynamic_cast<const URI*>(node) != NULL;
		bool isBNode = dynamic_cast<const BNode*>(node) != NULL;
		bool ok;
		switch (k->kind) {
		case NodeKindC::IRI_kind: ok = isIri; break;
		case NodeKindC::BNode_kind: ok = isBNode; break;
		case NodeKindC::Literal_kind: ok = isLit; break;
		default: ok = !isLit; break;
		}
		if (!ok) return false;

	    } else if (const DatatypeC* d = dynamic_cast<const DatatypeC*>(c)) {
		const RDFLiteral* lit = dynamic_cast<const RDFLiteral*>(node);
		if (lit == NULL) return false;
		const URI* dt = lit->getDatatype();
		std::string dtStr;
		if (lit->getLangtag() != NULL)
		    dtStr = "http://www.w3.org/1999/02/22-rdf-syntax-ns#langString";
		else if (dt == NULL)
		    dtStr = std::string(XSD) + "string";
		else
		    dtStr = dt->getLexicalValue();
		if (dtStr != d->datatype->getLexicalValue()) return false;
		if (!xsdval::valid(lit->getLexicalValue(), dtStr)) return false;

	    } else if (const StrLengthC* s = dynamic_cast<const StrLengthC*>(c)) {
		// applies to literal lexical forms, IRIs and bnode labels
		std::string str = termString(node);
		size_t len;
		try {
		    len = utf8::distance(str.begin(), str.end());
		} catch (...) {
		    len = str.size();
		}
		switch (s->kind) {
		case StrLengthC::Length: if (len != s->length) return false; break;
		case StrLengthC::MinLength: if (len < s->length) return false; break;
		default: if (len > s->length) return false; break;
		}

	    } else if (const PatternC* p = dynamic_cast<const PatternC*>(c)) {
		std::string str = termString(node);
		std::string pattern = p->pattern;
		boost::regex::flag_type flags = boost::regex::perl;
		std::string inline_mods;
		for (std::string::const_iterator f = p->flags.begin();
		     f != p->flags.end(); ++f)
		    switch (*f) {
		    case 'i': flags |= boost::regex::icase; break;
		    case 's': inline_mods += 's'; break;
		    case 'm': inline_mods += 'm'; break;
		    case 'x': inline_mods += 'x'; break;
		    }
		if (!inline_mods.empty())
		    pattern = "(?" + inline_mods + ")" + pattern;
		try {
		    boost::regex re(pattern, flags);
		    if (!boost::regex_search(str, re))
			return false;
		} catch (boost::regex_error&) {
		    return false;
		}

	    } else if (const NumRangeC* r = dynamic_cast<const NumRangeC*>(c)) {
		long double value, bound;
		if (!numericValue(node, value)) return false;
		if (!numericValue(r->value, bound)) return false;
		switch (r->kind) {
		case NumRangeC::MinInclusive: if (!(value >= bound)) return false; break;
		case NumRangeC::MinExclusive: if (!(value > bound)) return false; break;
		case NumRangeC::MaxInclusive: if (!(value <= bound)) return false; break;
		default: if (!(value < bound)) return false; break;
		}

	    } else if (const NumLengthC* n = dynamic_cast<const NumLengthC*>(c)) {
		const RDFLiteral* lit = dynamic_cast<const RDFLiteral*>(node);
		if (lit == NULL || lit->getLangtag() != NULL) return false;
		const URI* dt = lit->getDatatype();
		if (dt == NULL || !xsdval::numericDatatype(dt->getLexicalValue()))
		    return false;
		std::string dtStr = dt->getLexicalValue();
		// totaldigits/fractiondigits require the decimal value space
		if (dtStr == std::string(XSD) + "float" || dtStr == std::string(XSD) + "double")
		    return false;
		std::string lex = lit->getLexicalValue();
		if (!xsdval::valid(lex, dtStr)) return false;
		size_t N = lex.size();
		size_t idx = lex.find('.');
		if (n->kind == NumLengthC::FractionDigits) {
		    if (idx == std::string::npos)
			continue;
		    size_t after = N - idx - 1;
		    for (size_t i = N; i-- > idx + 1; ) {
			if (lex[i] != '0') break;
			--after;
		    }
		    if (after > n->length) return false;
		} else { // TotalDigits: significant digits in canonical form
		    size_t start = 0;
		    if (lex[0] == '+' || lex[0] == '-') ++start;
		    while (start < N && lex[start] == '0') ++start;
		    size_t finish = N;
		    if (idx != std::string::npos)
			for (size_t i = N; i-- > idx; ) {
			    if (lex[i] != '0' && lex[i] != '.') break;
			    --finish;
			}
		    size_t digits = 0;
		    for (size_t i = start; i < finish; ++i)
			if (lex[i] >= '0' && lex[i] <= '9')
			    ++digits;
		    if (digits == 0) digits = 1; // "0" still has one digit
		    if (digits > n->length) return false;
		}

	    } else if (const ValuesC* v = dynamic_cast<const ValuesC*>(c)) {
		bool found = false;
		for (std::vector<const ValueSetValue*>::const_iterator vs = v->values.begin();
		     !found && vs != v->values.end(); ++vs)
		    found = (*vs)->matches(node);
		if (!found) return false;
	    }
	}
	return true;
    }

} // namespace ShEx
} // namespace w3c_sw
