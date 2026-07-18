/* ShExSchema - ShEx2 schema AST and validator for RDF graphs.
 *
 * The AST mirrors ShExJ <http://shex.io/shex-semantics/#shexj>:
 *   Schema { imports, startActs, start, shapeDecls, tripleExprLabels }
 *   shapeExpr = ShapeAnd | ShapeOr | ShapeNot | NodeConstraint | Shape
 *             | ShapeExprRef | ShapeExternal
 *   tripleExpr = EachOf | OneOf | TripleConstraint | TripleExprRef
 *              | TripleExprCardinality (wrapper, as in jena-shex)
 *
 * The validation algorithm follows jena-shex (interval-based matching over
 * SORBE-normalized triple expressions, after Boneva, Labra Gayo & Prud'hommeaux,
 * "Semantics and Validation of Shapes Schemas for RDF"), including the
 * EXTENDS/ABSTRACT type hierarchy of ShEx 2.1.
 */

#ifndef SWOBJ_SHEX_SCHEMA_H
#define SWOBJ_SHEX_SCHEMA_H

#include "SWObjects.hpp"

#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <typeinfo>

namespace w3c_sw {
namespace ShEx {

    static const int Unbounded = -1;

    struct Cardinality {
	int min, max; // max == Unbounded for '*'
	Cardinality (int min = 1, int max = 1) : min(min), max(max) {  }
	bool operator== (const Cardinality& r) const { return min == r.min && max == r.max; }
	std::string str () const {
	    std::stringstream ss;
	    ss << "{" << min << ",";
	    if (max == Unbounded) ss << "*"; else ss << max;
	    ss << "}";
	    return ss.str();
	}
    };

    struct SemAct {
	const URI* name;
	bool hasCode;
	std::string code;
	SemAct (const URI* name) : name(name), hasCode(false) {  }
	SemAct (const URI* name, std::string code) : name(name), hasCode(true), code(code) {  }
    };

    struct Annotation {
	const TTerm* predicate;
	const TTerm* object;
	Annotation (const TTerm* predicate, const TTerm* object)
	    : predicate(predicate), object(object) {  }
    };

    /* ---------------------------------------------------------- value sets */

    /** One member of a NodeConstraint value set: a term, a stem, a stem
     * range with exclusions, a language, or a wildcard with exclusions. */
    struct ValueSetValue {
	virtual ~ValueSetValue () {  }
	virtual bool matches (const TTerm* term) const = 0;
	virtual std::string str () const = 0;
    };

    struct TermValue : public ValueSetValue {
	const TTerm* term;
	TermValue (const TTerm* term) : term(term) {  }
	virtual bool matches (const TTerm* test) const;
	virtual std::string str () const { return term->toString(); }
    };

    /** IriStem / LiteralStem / LanguageStem and their ...Range variants plus
     * the wildcard ranges share one representation:
     *   wildcard == false: match any value whose key starts with @stem
     *   wildcard == true:  match any value of this family
     * minus any exclusions (each exclusion again a single value or a stem). */
    struct StemRangeValue : public ValueSetValue {
	enum Family { IRI_family, Literal_family, Language_family };
	struct Exclusion {
	    bool isStem;
	    std::string value;
	    Exclusion (bool isStem, std::string value) : isStem(isStem), value(value) {  }
	};
	Family family;
	bool wildcard;
	std::string stem;
	std::vector<Exclusion> exclusions;
	/** "@en" in a value set is an exact (case-insensitive) language match;
	 * "@en~" is a language stem (extended filtering). */
	bool isExactLanguage;

	StemRangeValue (Family family, std::string stem)
	    : family(family), wildcard(false), stem(stem), isExactLanguage(false) {  }
	StemRangeValue (Family family) // wildcard
	    : family(family), wildcard(true), isExactLanguage(false) {  }

	static bool languageMatches (const std::string& tag, const std::string& range);
	bool keyFor (const TTerm* term, std::string& key) const; // false if wrong family
	bool stemMatches (const std::string& key, const std::string& stem) const;
	virtual bool matches (const TTerm* test) const;
	virtual std::string str () const;
    };

    /* --------------------------------------------- node constraint components */

    struct NCComponent {
	virtual ~NCComponent () {  }
	virtual std::string str () const = 0;
    };

    struct NodeKindC : public NCComponent {
	enum Kind { IRI_kind, BNode_kind, Literal_kind, NonLiteral_kind };
	Kind kind;
	NodeKindC (Kind kind) : kind(kind) {  }
	virtual std::string str () const {
	    switch (kind) {
	    case IRI_kind: return "IRI";
	    case BNode_kind: return "BNODE";
	    case Literal_kind: return "LITERAL";
	    default: return "NONLITERAL";
	    }
	}
    };

    struct DatatypeC : public NCComponent {
	const URI* datatype;
	DatatypeC (const URI* datatype) : datatype(datatype) {  }
	virtual std::string str () const { return datatype->toString(); }
    };

    struct StrLengthC : public NCComponent {
	enum Kind { Length, MinLength, MaxLength };
	Kind kind;
	size_t length;
	StrLengthC (Kind kind, size_t length) : kind(kind), length(length) {  }
	virtual std::string str () const {
	    std::stringstream ss;
	    ss << (kind == Length ? "LENGTH" : kind == MinLength ? "MINLENGTH" : "MAXLENGTH")
	       << " " << length;
	    return ss.str();
	}
    };

    struct PatternC : public NCComponent {
	std::string pattern; // already regex-unescaped
	std::string flags;   // subset of "smix"
	PatternC (std::string pattern, std::string flags)
	    : pattern(pattern), flags(flags) {  }
	virtual std::string str () const { return "/" + pattern + "/" + flags; }
    };

    struct NumRangeC : public NCComponent {
	enum Kind { MinInclusive, MinExclusive, MaxInclusive, MaxExclusive };
	Kind kind;
	const TTerm* value; // a numeric literal
	NumRangeC (Kind kind, const TTerm* value) : kind(kind), value(value) {  }
	virtual std::string str () const {
	    static const char* names[] = {"MININCLUSIVE", "MINEXCLUSIVE", "MAXINCLUSIVE", "MAXEXCLUSIVE"};
	    return std::string(names[kind]) + " " + value->toString();
	}
    };

    struct NumLengthC : public NCComponent {
	enum Kind { TotalDigits, FractionDigits };
	Kind kind;
	size_t length;
	NumLengthC (Kind kind, size_t length) : kind(kind), length(length) {  }
	virtual std::string str () const {
	    std::stringstream ss;
	    ss << (kind == TotalDigits ? "TOTALDIGITS" : "FRACTIONDIGITS") << " " << length;
	    return ss.str();
	}
    };

    struct ValuesC : public NCComponent {
	std::vector<const ValueSetValue*> values;
	virtual ~ValuesC () {
	    for (std::vector<const ValueSetValue*>::const_iterator it = values.begin();
		 it != values.end(); ++it)
	    	delete *it;
	}
	virtual std::string str () const;
    };

    /* ------------------------------------------------------- shape exprs */

    struct ShapeExprVisitor;

    struct ShapeExpr {
	std::vector<SemAct> semActs;
	std::vector<Annotation> annotations;
	virtual ~ShapeExpr () {  }
	virtual void accept (ShapeExprVisitor& v) const = 0;
	virtual std::string str () const = 0;
    };

    struct ShapeJunction : public ShapeExpr { // common base of ShapeAnd/ShapeOr
	std::vector<const ShapeExpr*> exprs;
	virtual ~ShapeJunction () {
	    for (std::vector<const ShapeExpr*>::const_iterator it = exprs.begin();
		 it != exprs.end(); ++it)
		delete *it;
	}
	std::string _str (const char* op) const;
    };

    struct ShapeAnd : public ShapeJunction {
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const { return _str(" AND "); }
    };

    struct ShapeOr : public ShapeJunction {
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const { return _str(" OR "); }
    };

    struct ShapeNot : public ShapeExpr {
	const ShapeExpr* expr;
	ShapeNot (const ShapeExpr* expr) : expr(expr) {  }
	virtual ~ShapeNot () { delete expr; }
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const { return "NOT (" + expr->str() + ")"; }
    };

    struct NodeConstraint : public ShapeExpr {
	std::vector<const NCComponent*> components;
	virtual ~NodeConstraint () {
	    for (std::vector<const NCComponent*>::const_iterator it = components.begin();
		 it != components.end(); ++it)
		delete *it;
	}
	/** Merge another NodeConstraint's components into this one (parser
	 * convenience for e.g. "LITERAL MinInclusive 3"). Takes ownership. */
	void absorb (NodeConstraint* other) {
	    components.insert(components.end(), other->components.begin(), other->components.end());
	    other->components.clear();
	    semActs.insert(semActs.end(), other->semActs.begin(), other->semActs.end());
	    annotations.insert(annotations.end(), other->annotations.begin(), other->annotations.end());
	    delete other;
	}
	bool hasFacet (const std::type_info& ti, int kind) const;
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const;
    };

    struct TripleExpr;

    struct Shape : public ShapeExpr {
	const TripleExpr* expression; // may be NULL
	bool closed;
	std::set<const TTerm*> extra;
	std::vector<const ShapeExpr*> extends; // refs (or inline exprs) to extended shapes
	Shape () : expression(NULL), closed(false) {  }
	virtual ~Shape ();
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const;
    };

    struct ShapeExprRef : public ShapeExpr {
	const TTerm* label;
	ShapeExprRef (const TTerm* label) : label(label) {  }
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const { return "@" + label->toString(); }
    };

    struct ShapeExternal : public ShapeExpr {
	virtual void accept (ShapeExprVisitor& v) const;
	virtual std::string str () const { return "EXTERNAL"; }
    };

    struct ShapeExprVisitor {
	virtual ~ShapeExprVisitor () {  }
	virtual void visit (const ShapeAnd& e) = 0;
	virtual void visit (const ShapeOr& e) = 0;
	virtual void visit (const ShapeNot& e) = 0;
	virtual void visit (const NodeConstraint& e) = 0;
	virtual void visit (const Shape& e) = 0;
	virtual void visit (const ShapeExprRef& e) = 0;
	virtual void visit (const ShapeExternal& e) = 0;
    };

    /* ------------------------------------------------------ triple exprs */

    struct TripleExprVisitor;

    struct TripleExpr {
	const TTerm* id; // optional $label, NULL if none
	std::vector<SemAct> semActs;
	std::vector<Annotation> annotations;
	TripleExpr () : id(NULL) {  }
	virtual ~TripleExpr () {  }
	virtual void accept (TripleExprVisitor& v) const = 0;
	virtual std::string str () const = 0;
    };

    struct TripleExprJunction : public TripleExpr {
	std::vector<const TripleExpr*> exprs;
	virtual ~TripleExprJunction () {
	    for (std::vector<const TripleExpr*>::const_iterator it = exprs.begin();
		 it != exprs.end(); ++it)
		delete *it;
	}
	std::string _str (const char* op) const;
    };

    struct EachOf : public TripleExprJunction {
	virtual void accept (TripleExprVisitor& v) const;
	virtual std::string str () const { return _str("; "); }
    };

    struct OneOf : public TripleExprJunction {
	virtual void accept (TripleExprVisitor& v) const;
	virtual std::string str () const { return _str(" | "); }
    };

    struct TripleConstraint : public TripleExpr {
	bool inverse;
	const TTerm* predicate;
	const ShapeExpr* valueExpr; // owned; may be NULL (matches anything)
	/** SORBE copies share the original's value expression without owning
	 * it (see SorbeExpr::clone). */
	const ShapeExpr* sharedValueExpr;
	TripleConstraint (bool inverse, const TTerm* predicate, const ShapeExpr* valueExpr)
	    : inverse(inverse), predicate(predicate), valueExpr(valueExpr),
	      sharedValueExpr(NULL) {  }
	virtual ~TripleConstraint () { delete valueExpr; }
	const ShapeExpr* effectiveValueExpr () const {
	    return valueExpr != NULL ? valueExpr : sharedValueExpr;
	}
	virtual void accept (TripleExprVisitor& v) const;
	virtual std::string str () const {
	    return (inverse ? "^" : "") + predicate->toString()
		+ " " + (valueExpr == NULL ? std::string(".") : valueExpr->str());
	}
    };

    struct TripleExprRef : public TripleExpr {
	const TTerm* label;
	TripleExprRef (const TTerm* label) : label(label) {  }
	virtual void accept (TripleExprVisitor& v) const;
	virtual std::string str () const { return "&" + label->toString(); }
    };

    struct TripleExprCardinality : public TripleExpr {
	const TripleExpr* expr;
	Cardinality card;
	TripleExprCardinality (const TripleExpr* expr, Cardinality card)
	    : expr(expr), card(card) {  }
	virtual ~TripleExprCardinality () { delete expr; }
	virtual void accept (TripleExprVisitor& v) const;
	virtual std::string str () const { return "(" + expr->str() + ")" + card.str(); }
    };

    struct TripleExprVisitor {
	virtual ~TripleExprVisitor () {  }
	virtual void visit (const EachOf& e) = 0;
	virtual void visit (const OneOf& e) = 0;
	virtual void visit (const TripleConstraint& e) = 0;
	virtual void visit (const TripleExprRef& e) = 0;
	virtual void visit (const TripleExprCardinality& e) = 0;
    };

    /* ------------------------------------------------------------ schema */

    struct ShapeDecl {
	const TTerm* label;
	bool isAbstract;
	std::vector<const ShapeExpr*> restricts;
	const ShapeExpr* expr;
	ShapeDecl (const TTerm* label, bool isAbstract, const ShapeExpr* expr)
	    : label(label), isAbstract(isAbstract), expr(expr) {  }
	~ShapeDecl () {
	    delete expr;
	    for (std::vector<const ShapeExpr*>::const_iterator it = restricts.begin();
		 it != restricts.end(); ++it)
		delete *it;
	}
    };

    struct StructureError : public std::runtime_error {
	StructureError (std::string what) : std::runtime_error(what) {  }
    };

    struct Schema {
	std::vector<const URI*> imports;
	std::vector<SemAct> startActs;
	const ShapeExpr* start;
	std::vector<ShapeDecl*> decls; // in declaration order; owns
	std::map<const TTerm*, ShapeDecl*> declIndex;
	std::map<const TTerm*, const TripleExpr*> tripleExprIndex; // non-owning
	/** The document's prefix declarations; semantic-action languages
	 * (e.g. ShExMap) resolve prefixed names in their code against them. */
	std::map<std::string, std::string> prefixes;

	Schema () : start(NULL) {  }
	~Schema () {
	    delete start;
	    for (std::vector<ShapeDecl*>::const_iterator it = decls.begin();
		 it != decls.end(); ++it)
		delete *it;
	}

	void addShape (const TTerm* label, bool isAbstract, const ShapeExpr* expr) {
	    if (declIndex.find(label) != declIndex.end())
		throw StructureError("shape " + label->toString() + " defined more than once");
	    ShapeDecl* decl = new ShapeDecl(label, isAbstract, expr);
	    decls.push_back(decl);
	    declIndex[label] = decl;
	}

	void addTripleExprLabel (const TTerm* label, const TripleExpr* expr) {
	    if (tripleExprIndex.find(label) != tripleExprIndex.end())
		throw StructureError("triple expression " + label->toString() + " defined more than once");
	    tripleExprIndex[label] = expr;
	}

	const ShapeExpr* getShapeExpr (const TTerm* label) const {
	    std::map<const TTerm*, ShapeDecl*>::const_iterator it = declIndex.find(label);
	    return it == declIndex.end() ? NULL : it->second->expr;
	}
	const TripleExpr* getTripleExpr (const TTerm* label) const {
	    std::map<const TTerm*, const TripleExpr*>::const_iterator it = tripleExprIndex.find(label);
	    return it == tripleExprIndex.end() ? NULL : it->second;
	}

	/** Post-parse checks: all references defined, no negated cycles,
	 * EXTENDS targets are extendable. Throws StructureError. */
	void checkStructure () const;

	std::string str () const;
    };

    /* --------------------------------------------------------- validation */

    /** A triple in the data graph, as (subject, predicate, object) TTerms. */
    typedef const TriplePattern* DataTriple;

    /** What a semantic action can see when it is dispatched. */
    struct SemActContext {
	const TTerm* node;                     // focus node, when meaningful
	const TripleConstraint* tc;            // for triple-constraint actions
	const std::vector<DataTriple>* triples; // triples matched to the expression
	SemActContext (const TTerm* node = NULL, const TripleConstraint* tc = NULL,
		       const std::vector<DataTriple>* triples = NULL)
	    : node(node), tc(tc), triples(triples) {  }
    };

    /** Callback for semantic-action languages (e.g. ShExMap's variable
     * binding). Called for every SemAct in addition to the built-in
     * http://shex.io/extensions/Test/ handling; returning false makes the
     * current solution fail.
     *
     * The validator explores subtrees that end up failing; mark()/rollback()
     * let a stateful handler discard whatever those attempts recorded. */
    struct SemActHandler {
	virtual ~SemActHandler () {  }
	virtual bool evaluate (const SemAct& act, const SemActContext& ctx) = 0;
	virtual size_t mark () { return 0; }
	virtual void rollback (size_t) {  }
    };

    /** Supplies definitions for shapes declared EXTERNAL, keyed by the
     * label of the EXTERNAL declaration. */
    struct ExternalResolver {
	virtual ~ExternalResolver () {  }
	/** Return the external definition of label, or NULL if unknown. The
	 * returned expression stays owned by the resolver. */
	virtual const ShapeExpr* resolveExternal (const TTerm* label) = 0;
    };

    /** Resolves EXTERNAL declarations against another Schema (e.g. a
     * .shextern document) by looking up the same label. */
    struct SchemaExternalResolver : public ExternalResolver {
	const Schema& externs;
	SchemaExternalResolver (const Schema& externs) : externs(externs) {  }
	virtual const ShapeExpr* resolveExternal (const TTerm* label) {
	    return externs.getShapeExpr(label);
	}
    };

    class Validator {
    public:
	Validator (const Schema& schema, const BasicGraphPattern& data)
	    : schema(schema), data(data) {  }

	/** Validate node against the shape labelled label (or the start
	 * shape if label is NULL). */
	bool validate (const TTerm* node, const TTerm* label);

	/** Errors from the last validate() call (best-effort diagnostics). */
	std::string lastError;

	/** For the "lexical bnode" facets: the source labels of the data
	 * graph's blank nodes (the AtomFactory may have renamed them). */
	void setBNodeLabels (const std::map<const TTerm*, std::string>* labels) {
	    bnodeLabels = labels;
	}

	/** Wire in resolution of EXTERNAL shape declarations. */
	void setExternalResolver (ExternalResolver* resolver) {
	    externalResolver = resolver;
	}

	/** Wire in a semantic-action language handler. */
	void setSemActHandler (SemActHandler* handler) {
	    semActHandler = handler;
	}

    private:
	friend struct ShapeExprEval;
	const Schema& schema;
	const BasicGraphPattern& data;
	const std::map<const TTerm*, std::string>* bnodeLabels = NULL;
	ExternalResolver* externalResolver = NULL;
	SemActHandler* semActHandler = NULL;
	/** Label of the declaration currently being validated; EXTERNAL
	 * resolves through it. */
	const TTerm* currentDeclLabel = NULL;

	/** The string the string facets apply to: literal lexical form, IRI,
	 * or (source) blank node label. */
	std::string termString (const TTerm* node) const;

	/** Evaluate semantic actions: the built-in
	 * http://shex.io/extensions/Test/ language (its "fail(...)" code
	 * fails) plus any registered handler. */
	bool evalSemActs (const std::vector<SemAct>& semActs, const SemActContext& ctx) const;
	typedef std::map<const TripleConstraint*, std::vector<DataTriple> > TCMatches;
	bool tripleExprSemActsPass (const TripleExpr* e, const TTerm* node,
				    const TCMatches& matches,
				    std::vector<DataTriple>& collected,
				    std::set<const TripleExpr*>& seen) const;

	/** (node, shapeLabel) pairs currently being validated; assumed
	 * conformant when re-encountered (cyclic schemas). */
	std::set<std::pair<const TTerm*, const TTerm*> > inProgress;

	/** The EXTENDS hierarchy: label -> labels it (transitively) extends /
	 * is extended by. Computed on first use. */
	bool hierarchyComputed = false;
	std::map<const TTerm*, std::vector<const TTerm*> > supertypes; // reflexive, ordered
	std::map<const TTerm*, std::vector<const TTerm*> > subtypes;   // reflexive, ordered
	void computeHierarchy ();
	std::vector<const TTerm*> nonAbstractDescendants (const TTerm* label);
	const std::vector<const TTerm*>& getSupertypes (const TTerm* label);
	bool mainShapeAndConstraints (const ShapeExpr* defn, const Shape*& mainShape,
				      std::vector<const ShapeExpr*>& constrs);

	bool satisfiesLabel (const TTerm* node, const TTerm* label);
	bool satisfies (const TTerm* node, const ShapeExpr* expr,
			const std::vector<DataTriple>* neigh);
	bool satisfiesShape (const TTerm* node, const Shape* shape,
			     const std::vector<DataTriple>* neigh);
	bool satisfiesNodeConstraint (const TTerm* node, const NodeConstraint* nc);
    };

} // namespace ShEx
} // namespace w3c_sw

#endif // !SWOBJ_SHEX_SCHEMA_H
