/* BNodeResolver.cpp - told-bnode emulation (see BNodeResolver.hpp). */

#include "BNodeResolver.hpp"
#include "SPARQLParser.hpp"
#include "ResultSet.hpp"

#include <algorithm>
#include <sstream>

namespace w3c_sw {
namespace bnr {

    /* ---------------------------------------------------- local test double --- */

    Table RelabelingLocalClient::select (const std::string& query) {
	++queriesServed;
	SPARQLDriver driver("", F);
	IStreamContext istr(query, IStreamContext::STRING);
	Operation* op = driver.parse(istr);
	ResultSet rs(F);
	op->execute(db, &rs);
	delete op;

	Table ret;
	std::map<const TTerm*, const TTerm*> relabel; // per-RESPONSE bnode renaming
	for (ResultSetConstIterator r = rs.begin(); r != rs.end(); ++r) {
	    Row row;
	    for (BindingSetConstIterator b = (*r)->begin(); b != (*r)->end(); ++b) {
		const TTerm* v = b->second.tterm;
		if (dynamic_cast<const BNode*>(v) != NULL) {
		    const TTerm*& nw = relabel[v];
		    if (nw == NULL)
			nw = F->createBNode();
		    v = nw;
		}
		row[b->first->getLexicalValue()] = v;
	    }
	    ret.push_back(row);
	}
	return ret;
    }

    /* ------------------------------------------------------- serialization --- */

    std::string sparqlTerm (const TTerm* t) {
	if (const URI* u = dynamic_cast<const URI*>(t))
	    return "<" + u->getLexicalValue() + ">";
	if (const RDFLiteral* l = dynamic_cast<const RDFLiteral*>(t)) {
	    std::string lex = l->getLexicalValue();
	    std::string esc;
	    for (size_t i = 0; i < lex.size(); ++i) {
		if (lex[i] == '"' || lex[i] == '\\') esc += '\\';
		if (lex[i] == '\n') { esc += "\\n"; continue; }
		esc += lex[i];
	    }
	    std::string ret = "\"" + esc + "\"";
	    if (l->getLangtag() != NULL)
		ret += "@" + l->getLangtag()->getLexicalValue();
	    else if (l->getDatatype() != NULL)
		ret += "^^<" + l->getDatatype()->getLexicalValue() + ">";
	    return ret;
	}
	throw std::string("sparqlTerm: cannot serialize ") + t->toString()
	    + " (blank nodes need mention())";
    }

    std::string BNodeResolver::fragmentWhere (const Fragment& frag,
					      const std::string& holeVar,
					      size_t& varCtr) const {
	std::string where;
	for (std::vector<Arc>::const_iterator a = frag.arcs.begin(); a != frag.arcs.end(); ++a) {
	    std::string other = isProxy(a->other)
		? mention(a->other, where, varCtr)
		: sparqlTerm(a->other);
	    if (a->holeAtSubject)
		where += "?" + holeVar + " " + sparqlTerm(a->p) + " " + other + " . ";
	    else
		where += other + " " + sparqlTerm(a->p) + " ?" + holeVar + " . ";
	}
	return where;
    }

    std::string BNodeResolver::mention (const TTerm* t, std::string& where,
					size_t& varCtr) const {
	std::map<const TTerm*, Fragment>::const_iterator f = fragments.find(t);
	if (f == fragments.end())
	    return sparqlTerm(t);
	std::ostringstream var;
	var << "bnrM" << varCtr++;
	where += fragmentWhere(f->second, var.str(), varCtr);
	return "?" + var.str();
    }

    /* ---------------------------------------------------------- resolution --- */

    Table BNodeResolver::raw (const std::string& query) {
	++queriesIssued;
	return client->select(query);
    }

    bool BNodeResolver::uniquelyIdentifies (const Fragment& frag) {
	size_t ctr = 0;
	std::string q = "SELECT ?bnrU9 WHERE { " + fragmentWhere(frag, "bnrU9", ctr) + "}";
	Table t = raw(q);
	std::set<const TTerm*> distinct; // one response: labels comparable
	for (Table::const_iterator r = t.begin(); r != t.end(); ++r) {
	    Row::const_iterator b = r->find("bnrU9");
	    if (b != r->end())
		distinct.insert(b->second);
	}
	return distinct.size() == 1;
    }

    const TTerm* BNodeResolver::internFragment (const Fragment& frag0) {
	Fragment frag = frag0;
	/* canonical key: sorted arc serializations (proxies by their keys) */
	std::vector<std::string> parts;
	for (std::vector<Arc>::const_iterator a = frag.arcs.begin(); a != frag.arcs.end(); ++a) {
	    std::map<const TTerm*, Fragment>::const_iterator nested = fragments.find(a->other);
	    std::string other = nested != fragments.end()
		? "{" + nested->second.key + "}"
		: sparqlTerm(a->other);
	    parts.push_back((a->holeAtSubject ? ">" : "<") + sparqlTerm(a->p) + " " + other);
	}
	std::sort(parts.begin(), parts.end());
	std::string key;
	for (std::vector<std::string>::const_iterator it = parts.begin(); it != parts.end(); ++it)
	    key += *it + ";";
	frag.key = key;

	std::map<std::string, const TTerm*>::const_iterator hit = byKey.find(key);
	if (hit != byKey.end())
	    return hit->second;
	const TTerm* proxy = F->createBNode();
	byKey[key] = proxy;
	fragments[proxy] = frag;
	return proxy;
    }

    namespace {
	/** ground-other arcs before bnode-other (recursion is the expensive
	 * path); among ground, out-arcs before in-arcs */
	struct ArcOrder {
	    bool operator() (const Arc& a, const Arc& b) const {
		bool ag = dynamic_cast<const BNode*>(a.other) == NULL;
		bool bg = dynamic_cast<const BNode*>(b.other) == NULL;
		if (ag != bg) return ag;
		if (a.holeAtSubject != b.holeAtSubject) return a.holeAtSubject;
		return false;
	    }
	};
    }

    std::vector<const TTerm*> BNodeResolver::resolveBNode (const std::string& pinWhere,
							   std::set<std::string>& inFlight,
							   size_t depth) {
	if (depth > maxDepth)
	    throw std::string("BNodeResolver: identification recursion exceeded depth ")
		+ boost::lexical_cast<std::string>(maxDepth);
	if (inFlight.find(pinWhere) != inFlight.end())
	    throw std::string("BNodeResolver: cyclic bnode identification for { ")
		+ pinWhere + "}";
	inFlight.insert(pinWhere);

	/* interrogate arcs in and out of the pinned hole, one round trip */
	std::string q = "SELECT ?bnrH9 ?bnrD9 ?bnrP9 ?bnrX9 WHERE { { " + pinWhere + " } "
	    "{ BIND(1 AS ?bnrD9) ?bnrH9 ?bnrP9 ?bnrX9 } UNION "
	    "{ BIND(2 AS ?bnrD9) ?bnrX9 ?bnrP9 ?bnrH9 } }";
	Table t = raw(q);

	/* partition arcs per candidate (labels are consistent WITHIN one
	 * response); candidates beyond the first are structurally
	 * indistinguishable through this pin - any witness serves */
	std::map<const TTerm*, std::vector<Arc> > candidates;
	std::vector<const TTerm*> order;
	for (Table::const_iterator r = t.begin(); r != t.end(); ++r) {
	    Row::const_iterator h = r->find("bnrH9"), d = r->find("bnrD9"),
		p = r->find("bnrP9"), x = r->find("bnrX9");
	    if (h == r->end() || d == r->end() || p == r->end() || x == r->end())
		continue;
	    if (candidates.find(h->second) == candidates.end())
		order.push_back(h->second);
	    bool out = d->second->getLexicalValue() == "1";
	    candidates[h->second].push_back(Arc(out, p->second, x->second));
	}
	if (order.empty())
	    throw std::string("BNodeResolver: pin context matched no node: { ")
		+ pinWhere + "}";

	/* identify EVERY candidate: an ambiguous pin (e.g. a group with two
	 * anonymous memberships and no discriminating co-binding) still told
	 * us there are N nodes - collapsing to one witness would lose the
	 * others. Distinct candidates get distinct proxies; structurally
	 * identical ones dedup onto one witness via the fragment key. */
	std::vector<const TTerm*> proxies;
	for (std::vector<const TTerm*>::const_iterator cand = order.begin();
	     cand != order.end(); ++cand) {
	    std::vector<Arc>& arcs = candidates[*cand];

	    /* greedy minimal fragment: ground-other arcs first, then recursive */
	    std::stable_sort(arcs.begin(), arcs.end(), ArcOrder());
	    Fragment frag;
	    bool identified = false;
	    for (std::vector<Arc>::const_iterator a = arcs.begin(); a != arcs.end(); ++a) {
		Arc arc = *a;
		if (dynamic_cast<const BNode*>(arc.other) != NULL) {
		    /* neighbor bnode: identify it through its link to the hole */
		    std::string nbrPin = pinWhere
			+ (arc.holeAtSubject
			   ? "?bnrH9 " + sparqlTerm(arc.p) + " ?bnrHn9 . "
			   : "?bnrHn9 " + sparqlTerm(arc.p) + " ?bnrH9 . ");
		    /* re-pin with the neighbor as the new hole */
		    std::string renamed;
		    for (size_t i = 0; i < nbrPin.size(); ) {
			if (nbrPin.compare(i, 7, "?bnrHn9") == 0) { renamed += "?bnrH9"; i += 7; }
			else if (nbrPin.compare(i, 6, "?bnrH9") == 0) { renamed += "?bnrPrev9"; i += 6; }
			else renamed += nbrPin[i++];
		    }
		    arc.other = resolveBNode(renamed, inFlight, depth + 1)[0];
		}
		frag.arcs.push_back(arc);
		if (uniquelyIdentifies(frag)) {
		    identified = true;
		    break;
		}
	    }
	    /* an exhausted arc set means this candidate is structurally
	     * indistinguishable from a sibling; its final fragment is still
	     * its best identity and dedups onto the sibling's proxy */
	    if (!identified && frag.arcs.empty())
		throw std::string("BNodeResolver: no arcs to identify bnode pinned by { ")
		    + pinWhere + "}";
	    proxies.push_back(internFragment(frag));
	}
	inFlight.erase(pinWhere);
	return proxies;
    }

    Table BNodeResolver::select (const std::string& query,
				 const std::string& contextWhere) {
	Table rows = raw(query);
	std::map<const TTerm*, const TTerm*> resolved; // response label -> proxy
	/* pools of identified candidates per pin: distinct response labels
	 * sharing an ambiguous pin take successive candidates (a bijection -
	 * correct up to graph isomorphism) */
	std::map<std::string, std::pair<std::vector<const TTerm*>, size_t> > pools;
	for (Table::iterator r = rows.begin(); r != rows.end(); ++r) {
	    for (Row::iterator b = r->begin(); b != r->end(); ++b) {
		if (dynamic_cast<const BNode*>(b->second) == NULL || isProxy(b->second))
		    continue;
		std::map<const TTerm*, const TTerm*>::const_iterator hit = resolved.find(b->second);
		if (hit != resolved.end()) {
		    b->second = hit->second;
		    continue;
		}
		/* pin: the query context with the bnode's variable renamed to
		 * the hole, plus the row's ground co-bindings as filters */
		std::string pin;
		{
		    const std::string target = "?" + b->first;
		    for (size_t i = 0; i < contextWhere.size(); ) {
			bool hit = contextWhere.compare(i, target.size(), target) == 0;
			if (hit) {
			    size_t after = i + target.size();
			    if (after < contextWhere.size()
				&& (isalnum((unsigned char)contextWhere[after])
				    || contextWhere[after] == '_'))
				hit = false;
			}
			if (hit) {
			    pin += "?bnrH9";
			    i += target.size();
			} else
			    pin += contextWhere[i++];
		    }
		}
		for (Row::const_iterator o = r->begin(); o != r->end(); ++o)
		    if (o->first != b->first
			&& dynamic_cast<const BNode*>(o->second) == NULL
			&& !isProxy(o->second))
			pin += "FILTER (?" + o->first + " = " + sparqlTerm(o->second) + ") ";
		if (pools.find(pin) == pools.end()) {
		    std::set<std::string> inFlight;
		    pools[pin] = std::make_pair(resolveBNode(pin, inFlight, 0), (size_t)0);
		}
		std::pair<std::vector<const TTerm*>, size_t>& pool = pools[pin];
		const TTerm* proxy = pool.first[std::min(pool.second, pool.first.size() - 1)];
		++pool.second;
		resolved[b->second] = proxy;
		b->second = proxy;
	    }
	}
	return rows;
    }

    /* -------------------------------------------------- materializing cache --- */

    bool RemoteGraphProvider::subsumed (const TTerm* s, const TTerm* p, const TTerm* o) const {
	for (std::vector<Pat>::const_iterator it = fetched.begin(); it != fetched.end(); ++it)
	    if ((it->s == NULL || it->s == s) &&
		(it->p == NULL || it->p == p) &&
		(it->o == NULL || it->o == o))
		return true;
	return false;
    }

    void RemoteGraphProvider::ensurePattern (const TTerm* s, const TTerm* p, const TTerm* o) {
	if (subsumed(s, p, o))
	    return; // the cache already answers this pattern
	Pat pat = { s, p, o };
	fetched.push_back(pat);

	/* patterns no RDF triple can match need no round trip (a literal in
	 * subject or predicate position is also a SPARQL syntax error) */
	if ((s != NULL && dynamic_cast<const RDFLiteral*>(s) != NULL) ||
	    (p != NULL && dynamic_cast<const RDFLiteral*>(p) != NULL) ||
	    (p != NULL && dynamic_cast<const BNode*>(p) != NULL))
	    return;

	std::string where;
	size_t ctr = 0;
	std::string st = s == NULL ? "?bnrS" : resolver.mention(s, where, ctr);
	std::string pt = p == NULL ? "?bnrPP" : resolver.mention(p, where, ctr);
	std::string ot = o == NULL ? "?bnrO" : resolver.mention(o, where, ctr);
	where += st + " " + pt + " " + ot + " . ";
	std::string q = "SELECT * WHERE { " + where + "}";

	Table rows = resolver.select(q, where);
	for (Table::const_iterator r = rows.begin(); r != rows.end(); ++r) {
	    const TTerm* rs = s; const TTerm* rp = p; const TTerm* ro = o;
	    Row::const_iterator it;
	    if (rs == NULL) { it = r->find("bnrS"); if (it == r->end()) continue; rs = it->second; }
	    if (rp == NULL) { it = r->find("bnrPP"); if (it == r->end()) continue; rp = it->second; }
	    if (ro == NULL) { it = r->find("bnrO"); if (it == r->end()) continue; ro = it->second; }
	    cache->addTriplePattern(resolver.F->getTriple(rs, rp, ro));
	}
    }

} // namespace bnr
} // namespace w3c_sw
