/* ShExMap.cpp - variable binding, lift/lower functions and the trivial
 * materializer, ported from shex.js's @shexjs/extension-map. */

#include "ShExMap.hpp"
#include "MiniJSON.hpp"

#include <boost/regex.hpp>

namespace w3c_sw {
namespace ShExMap {

    const char* Name = "http://shex.io/extensions/Map/#";

    static std::string trim (const std::string& s) {
	size_t b = s.find_first_not_of(" \t\r\n");
	if (b == std::string::npos)
	    return "";
	size_t e = s.find_last_not_of(" \t\r\n");
	return s.substr(b, e - b + 1);
    }

    std::string Bindings::str () const {
	std::stringstream ss;
	for (std::map<std::string, std::deque<const TTerm*> >::const_iterator it = queues.begin();
	     it != queues.end(); ++it) {
	    ss << it->first << ":";
	    for (std::deque<const TTerm*>::const_iterator v = it->second.begin();
		 v != it->second.end(); ++v)
		ss << " " << (*v)->toString();
	    ss << "\n";
	}
	for (std::map<std::string, const TTerm*>::const_iterator it = statics.begin();
	     it != statics.end(); ++it)
	    ss << it->first << " (static): " << it->second->toString() << "\n";
	return ss.str();
    }

    std::string parseVariable (const std::string& code,
			       const std::map<std::string, std::string>& prefixes) {
	// ^ *(?:<([^>]*)>|([^:]*):([^ ]*)) *$
	std::string t = trim(code);
	if (t.empty())
	    return "";
	if (t[0] == '<') {
	    if (t[t.size()-1] != '>')
		return "";
	    return t.substr(1, t.size() - 2);
	}
	size_t colon = t.find(':');
	if (colon == std::string::npos || t.find(' ') != std::string::npos)
	    return "";
	std::string prefix = t.substr(0, colon);
	std::string local = t.substr(colon + 1);
	std::map<std::string, std::string>::const_iterator p = prefixes.find(prefix);
	if (p == prefixes.end())
	    throw MapError("unknown prefix \"" + prefix + ":\" in \"" + code + "\"");
	return p->second + local;
    }

    /* ------------------------------------------------------- lift / lower */

    namespace {

	struct FuncCall {
	    std::string name;
	    std::string args;
	    bool matched;
	};

	FuncCall parseFuncCall (const std::string& code) {
	    FuncCall ret;
	    ret.matched = false;
	    std::string t = trim(code);
	    size_t open = t.find('(');
	    size_t close = t.rfind(')');
	    if (open == std::string::npos || close != t.size() - 1 || close <= open)
		return ret;
	    ret.name = trim(t.substr(0, open));
	    if (ret.name.empty()
		|| ret.name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
		   != std::string::npos)
		return ret;
	    ret.args = t.substr(open + 1, close - open - 1);
	    ret.matched = true;
	    return ret;
	}

	/** Strip the /.../ around a regex argument. */
	std::string trimPattern (const std::string& args) {
	    std::string t = trim(args);
	    if (t.size() >= 2 && t[0] == '/' && t[t.size()-1] == '/')
		return t.substr(1, t.size() - 2);
	    return t;
	}

	std::string unescapeMetaChars (const std::string& s) {
	    // s.replace(/\\([\/^$])/g, "$1")
	    std::string ret;
	    for (size_t i = 0; i < s.size(); ++i) {
	        if (s[i] == '\\' && i + 1 < s.size()
		    && (s[i+1] == '/' || s[i+1] == '^' || s[i+1] == '$')) {
		    ret += s[++i];
		} else
		    ret += s[i];
	    }
	    return ret;
	}

	std::string collapseSpaces (const std::string& s) {
	    std::string ret;
	    for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == ' ' && !ret.empty() && ret[ret.size()-1] == ' ')
		    continue;
		ret += s[i];
	    }
	    return ret;
	}

	/** Split a regex pattern with ShExMap named groups "(?<pfx:local>"
	 * into a plain pattern plus the expanded group variable names. */
	struct NamedGroupPattern {
	    std::string pattern; // named markers removed
	    std::vector<std::string> vars; // in group order
	};

	NamedGroupPattern parseNamedGroups (const std::string& pattern,
					    const std::map<std::string, std::string>& prefixes) {
	    NamedGroupPattern ret;
	    for (size_t i = 0; i < pattern.size(); ++i) {
		if (pattern.compare(i, 2, "?<") == 0
		    && (i == 0 || pattern[i-1] == '(')) {
		    size_t close = pattern.find('>', i + 2);
		    // allow <iri> group names: "?<<http://...>>"
		    if (close != std::string::npos && pattern[i+2] == '<') {
			close = pattern.find('>', close + 1);
		    }
		    if (close == std::string::npos)
			throw MapError("unterminated named group in /" + pattern + "/");
		    std::string name = pattern.substr(i + 2, close - i - 2);
		    ret.vars.push_back(parseVariable(unescapeMetaChars(name), prefixes));
		    i = close; // skip the marker; the '(' stays
		} else
		    ret.pattern += pattern[i];
	    }
	    return ret;
	}
    } // namespace

    std::map<std::string, std::string> lift (const std::string& code,
					     const std::string& input,
					     const std::map<std::string, std::string>& prefixes) {
	FuncCall f = parseFuncCall(code);
	if (!f.matched)
	    throw MapError("invalid extension function: " + code);
	std::map<std::string, std::string> ret;

	if (f.name == "regex") {
	    NamedGroupPattern ngp = parseNamedGroups(trimPattern(f.args), prefixes);
	    if (ngp.vars.empty())
		throw MapError("found no capture variable in " + code);
	    boost::regex re(ngp.pattern, boost::regex::perl);
	    boost::smatch what;
	    if (!boost::regex_search(input, what, re))
		throw MapError(code + " found no match for input \"" + input + "\"");
	    for (size_t i = 1; i < what.size() && i - 1 < ngp.vars.size(); ++i)
		ret[ngp.vars[i-1]] = what[(int)i].str();
	    return ret;
	}

	if (f.name == "hashmap") {
	    size_t comma = f.args.find(',');
	    if (comma == std::string::npos)
		throw MapError("hashmap needs a variable and a map: " + code);
	    std::string var = parseVariable(trim(f.args.substr(0, comma)), prefixes);
	    MiniJSON::Value map = MiniJSON::parse(trim(f.args.substr(comma + 1)));
	    if (!map.isObject() || map.object.empty())
		throw MapError("hashmap needs a non-empty JSON object: " + code);
	    const MiniJSON::Value* hit = map.get(input);
	    if (hit == NULL || !hit->isString())
		throw MapError("hashmap has no mapping for \"" + input + "\"");
	    ret[var] = hit->string;
	    return ret;
	}

	if (f.name == "test")
	    return ret;

	throw MapError("unknown extension: " + code);
    }

    const TTerm* lower (const std::string& code, Bindings& bindings,
			AtomFactory& atomFactory,
			const std::map<std::string, std::string>& prefixes) {
	FuncCall f = parseFuncCall(code);
	if (!f.matched)
	    throw MapError("invalid extension function: " + code);

	if (f.name == "regex") {
	    // Replace each full named group "(?<name>...)" with the binding's
	    // lexical value; the remaining pattern text supplies the joins.
	    std::string pattern = trimPattern(f.args);
	    std::string result;
	    bool matched = false;
	    for (size_t i = 0; i < pattern.size(); ++i) {
		if (pattern[i] == '(' && pattern.compare(i + 1, 2, "?<") == 0) {
		    size_t nameClose = pattern.find('>', i + 3);
		    if (nameClose != std::string::npos && pattern[i+3] == '<')
			nameClose = pattern.find('>', nameClose + 1);
		    size_t groupClose = nameClose == std::string::npos
			? std::string::npos : pattern.find(')', nameClose);
		    if (nameClose == std::string::npos || groupClose == std::string::npos)
			throw MapError("unterminated named group in /" + pattern + "/");
		    std::string name = pattern.substr(i + 3, nameClose - i - 3);
		    std::string var = parseVariable(unescapeMetaChars(name), prefixes);
		    const TTerm* val = bindings.get(var);
		    if (val == NULL)
			throw MapError("unable to process " + code + " because variable \""
				       + var + "\" was not found");
		    result += val->getLexicalValue();
		    matched = true;
		    i = groupClose;
		} else
		    result += pattern[i];
	    }
	    if (!matched)
		throw MapError("found no capture variable in " + code);
	    return atomFactory.getRDFLiteral(unescapeMetaChars(collapseSpaces(result)),
					     NULL, NULL);
	}

	if (f.name == "hashmap") {
	    size_t comma = f.args.find(',');
	    if (comma == std::string::npos)
		throw MapError("hashmap needs a variable and a map: " + code);
	    std::string var = parseVariable(trim(f.args.substr(0, comma)), prefixes);
	    MiniJSON::Value map = MiniJSON::parse(trim(f.args.substr(comma + 1)));
	    const TTerm* bound = bindings.get(var);
	    if (bound == NULL)
		throw MapError("unable to find mapped value for " + var);
	    std::string value = bound->getLexicalValue();
	    for (std::vector<std::pair<std::string, MiniJSON::Value> >::const_iterator it
		     = map.object.begin(); it != map.object.end(); ++it)
		if (it->second.isString() && it->second.string == value)
		    return atomFactory.getRDFLiteral(collapseSpaces(it->first), NULL, NULL);
	    throw MapError("hashmap was unable to invert the value \"" + value + "\"");
	}

	if (f.name == "test")
	    return NULL;

	throw MapError("unknown extension: " + code);
    }

    /* --------------------------------------------------- binding collection */

    bool BindingCollector::evaluate (const ShEx::SemAct& act, const ShEx::SemActContext& ctx) {
	if (act.name->getLexicalValue() != Name || !act.hasCode)
	    return true;
	try {
	    std::string var = parseVariable(act.code, prefixes);
	    if (!var.empty()) {
		const TTerm* value = NULL;
		if (ctx.tc != NULL && ctx.triples != NULL && !ctx.triples->empty())
		    value = ctx.tc->inverse
			? (*ctx.triples)[0]->getS()
			: (*ctx.triples)[0]->getO();
		else if (ctx.node != NULL)
		    value = ctx.node;
		if (value != NULL)
		    out.bind(var, value);
		return true;
	    }
	    FuncCall f = parseFuncCall(act.code);
	    if (f.matched) {
		if (ctx.triples == NULL || ctx.triples->empty())
		    return true; // nothing matched: nothing to lift
		const TTerm* value = ctx.tc != NULL && ctx.tc->inverse
		    ? (*ctx.triples)[0]->getS()
		    : (*ctx.triples)[0]->getO();
		std::map<std::string, std::string> results
		    = lift(act.code, value->getLexicalValue(), prefixes);
		for (std::map<std::string, std::string>::const_iterator it = results.begin();
		     it != results.end(); ++it)
		    out.bind(it->first, atomFactory->getRDFLiteral(it->second, NULL, NULL));
		return true;
	    }
	    throw MapError("code \"" + act.code + "\" is neither a variable nor a function");
	} catch (MapError&) {
	    return false; // a failed Map action fails the solution
	}
    }

    /* ------------------------------------------------------- materialization */

    namespace {

	static const long MAX_MAX_CARD = 50; // don't repeat forever

	struct Materializer {
	    const ShEx::Schema& schema;
	    Bindings& bindings;
	    AtomFactory& F;
	    // Triples accumulate here so unproductive repetitions can be
	    // rolled back; flush() copies them to the output graph.
	    std::vector<const TriplePattern*> acc;
	    std::set<const ShEx::ShapeExpr*> visiting;

	    Materializer (const ShEx::Schema& schema, Bindings& bindings,
			  AtomFactory& F)
		: schema(schema), bindings(bindings), F(F) {  }

	    void add (const TTerm* s, const TTerm* p, const TTerm* o) {
		acc.push_back(F.getTriple(s, p, o));
	    }

	    void flush (BasicGraphPattern* out) {
		for (std::vector<const TriplePattern*>::const_iterator it = acc.begin();
		     it != acc.end(); ++it)
		    out->addTriplePattern(*it);
	    }

	    void shapeExpr (const ShEx::ShapeExpr* e, const TTerm* subject) {
		if (e == NULL || !visiting.insert(e).second)
		    return;
		if (const ShEx::ShapeJunction* j = dynamic_cast<const ShEx::ShapeJunction*>(e)) {
		    for (std::vector<const ShEx::ShapeExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			shapeExpr(*it, subject);
		} else if (const ShEx::Shape* s = dynamic_cast<const ShEx::Shape*>(e)) {
		    tripleExpr(s->expression, subject);
		} else if (const ShEx::ShapeExprRef* r = dynamic_cast<const ShEx::ShapeExprRef*>(e)) {
		    shapeExpr(schema.getShapeExpr(r->label), subject);
		}
		// ShapeNot, NodeConstraint, ShapeExternal: nothing to emit
		visiting.erase(e);
	    }

	    void tripleExpr (const ShEx::TripleExpr* e, const TTerm* subject) {
		if (e == NULL)
		    return;
		if (const ShEx::TripleExprJunction* j = dynamic_cast<const ShEx::TripleExprJunction*>(e)) {
		    for (std::vector<const ShEx::TripleExpr*>::const_iterator it = j->exprs.begin();
			 it != j->exprs.end(); ++it)
			tripleExpr(*it, subject);
		    return;
		}
		if (const ShEx::TripleExprCardinality* c = dynamic_cast<const ShEx::TripleExprCardinality*>(e)) {
		    if (const ShEx::TripleConstraint* tc
			= dynamic_cast<const ShEx::TripleConstraint*>(c->expr))
			tripleConstraint(tc, subject, c->card);
		    else
			tripleExpr(c->expr, subject); // group cardinality: emit once
		    return;
		}
		if (const ShEx::TripleExprRef* r = dynamic_cast<const ShEx::TripleExprRef*>(e)) {
		    tripleExpr(schema.getTripleExpr(r->label), subject);
		    return;
		}
		if (const ShEx::TripleConstraint* tc = dynamic_cast<const ShEx::TripleConstraint*>(e))
		    tripleConstraint(tc, subject, ShEx::Cardinality(1, 1));
	    }

	    const ShEx::ValueSetValue* singleValue (const ShEx::ShapeExpr* valueExpr) {
		const ShEx::NodeConstraint* nc
		    = dynamic_cast<const ShEx::NodeConstraint*>(valueExpr);
		if (nc == NULL)
		    return NULL;
		for (std::vector<const ShEx::NCComponent*>::const_iterator it
			 = nc->components.begin(); it != nc->components.end(); ++it)
		    if (const ShEx::ValuesC* v = dynamic_cast<const ShEx::ValuesC*>(*it))
			if (v->values.size() == 1)
			    return v->values[0];
		return NULL;
	    }

	    void tripleConstraint (const ShEx::TripleConstraint* tc, const TTerm* subject,
				   ShEx::Cardinality card) {
		// 1. %Map:{...%} actions: emit the bound / lowered values
		std::vector<const ShEx::SemAct*> mapActs;
		for (std::vector<ShEx::SemAct>::const_iterator it = tc->semActs.begin();
		     it != tc->semActs.end(); ++it)
		    if (it->name->getLexicalValue() == Name && it->hasCode)
			mapActs.push_back(&*it);
		if (!mapActs.empty()) {
		    for (std::vector<const ShEx::SemAct*>::const_iterator it = mapActs.begin();
			 it != mapActs.end(); ++it) {
			const TTerm* object = NULL;
			std::string var = parseVariable((*it)->code, schema.prefixes);
			if (!var.empty())
			    object = bindings.get(var);
			else {
			    FuncCall f = parseFuncCall((*it)->code);
			    if (f.matched)
				object = lower((*it)->code, bindings, F, schema.prefixes);
			}
			if (object == NULL)
			    continue; // not in bindings
			if (tc->inverse)
			    add(object, tc->predicate, subject);
			else
			    add(subject, tc->predicate, object);
		    }
		    return;
		}

		// 2. a single-valued value set emits its constant
		if (const ShEx::ValueSetValue* v = singleValue(tc->valueExpr)) {
		    if (const ShEx::TermValue* t = dynamic_cast<const ShEx::TermValue*>(v)) {
			if (tc->inverse)
			    add(t->term, tc->predicate, subject);
			else
			    add(subject, tc->predicate, t->term);
			return;
		    }
		}

		// 3. otherwise: fresh bnode(s), recursing into the value
		//    expression. Repetitions beyond the first happen only
		//    while they consume (multi-valued) bindings.
		long maxAdd = card.max == ShEx::Unbounded ? MAX_MAX_CARD
		    : card.max > MAX_MAX_CARD ? MAX_MAX_CARD : card.max;
		for (long rep = 0; rep < maxAdd; ++rep) {
		    size_t before = bindings.consumed;
		    size_t sizeBefore = acc.size();
		    const TTerm* b = F.createBNode();
		    if (tc->inverse)
			add(b, tc->predicate, subject);
		    else
			add(subject, tc->predicate, b);
		    if (tc->valueExpr != NULL)
			shapeExpr(tc->valueExpr, b);
		    if (rep > 0 && bindings.consumed == before) {
			// nothing consumed: undo this repetition and stop
			acc.resize(sizeBefore);
			break;
		    }
		    if (bindings.consumed == before)
			break; // single shot: nothing repeatable inside
		}
	    }
	};
    } // namespace

    void materialize (const ShEx::Schema& target, Bindings& bindings,
		      AtomFactory& atomFactory, BasicGraphPattern* out,
		      const TTerm* root, const TTerm* shapeLabel) {
	const ShEx::ShapeExpr* expr = shapeLabel != NULL
	    ? target.getShapeExpr(shapeLabel)
	    : target.start;
	if (expr == NULL)
	    throw MapError(shapeLabel != NULL
			   ? "no shape " + shapeLabel->toString() + " in target schema"
			   : "target schema has no start shape");
	// start = @<X> is a common idiom; deref for clarity of the visit
	if (const ShEx::ShapeExprRef* r = dynamic_cast<const ShEx::ShapeExprRef*>(expr)) {
	    const ShEx::ShapeExpr* deref = target.getShapeExpr(r->label);
	    if (deref != NULL)
		expr = deref;
	}
	Materializer m(target, bindings, atomFactory);
	m.shapeExpr(expr, root != NULL ? root : atomFactory.createBNode());
	m.flush(out);
    }

} // namespace ShExMap
} // namespace w3c_sw
