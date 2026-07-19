/* BNodeResolver.hpp - told-bnode emulation over the SPARQL protocol.
 *
 * SPARQL 1.0 rejected "told bnodes" (mentioning, in a query, a blank node
 * received in an earlier response). Both ShEx validation over an endpoint
 * (repeated neighborhood queries whose focus may be a response bnode) and
 * remote Algae 3 execution (correlated bgpmatch seeds crossing round trips)
 * need exactly that. This library emulates it:
 *
 * - For each SELECT it executes, the BNodeResolver associates every response
 *   blank node with a minimal query FRAGMENT - a set of in/out arcs - that
 *   uniquely re-identifies it, instrumenting the query with extra round
 *   trips interrogating properties in and out of the bnode, recursively
 *   through neighboring bnodes when the ground arcs do not discriminate.
 * - Each identified bnode gets a stable local PROXY term (deduplicated by
 *   fragment); mentioning a proxy in a later query expands to a fresh
 *   variable constrained by its fragment.
 * - The RemoteGraphProvider materializes triple-pattern queries into a local
 *   BasicGraphPattern, acting as a query cache: interrogation results and
 *   earlier fetches subsume later neighborhood requests.
 *
 * Identification is up to the discriminating power of the query context plus
 * the row's ground bindings: structurally indistinguishable bnodes yield one
 * witness, which is substitutable in any query constrained through the same
 * context. Blank nodes emerging from grouped aggregates are out of scope
 * (deferred; the flagship query never joins bnodes across an aggregation).
 */

#ifndef INCLUDED_BNodeResolver
#define INCLUDED_BNodeResolver

#include "SWObjects.hpp"
#include "RdfDB.hpp"

#include <map>
#include <set>
#include <string>
#include <vector>

namespace w3c_sw {

    class SWWEBagent;
    class SWSAXparser;

namespace bnr {

    /** one response row: variable name (no '?') -> term */
    typedef std::map<std::string, const TTerm*> Row;
    typedef std::vector<Row> Table;

    /** Abstract SPARQL protocol client. Response bnode terms are scoped to
     * ONE response; mentioning them in a later query is meaningless - the
     * told-bnode problem this library exists to solve. */
    struct SPARQLClient {
	virtual ~SPARQLClient () {  }
	virtual Table select (const std::string& query) = 0;
    };

    /** Test double: executes against a local RdfDB and RELABELS every
     * response bnode freshly per response, modeling standard endpoint
     * semantics - code that works by bnode-label luck fails against this. */
    class RelabelingLocalClient : public SPARQLClient {
	AtomFactory* F;
	RdfDB* db;
    public:
	size_t queriesServed;
	RelabelingLocalClient (AtomFactory* F, RdfDB* db)
	    : F(F), db(db), queriesServed(0) {  }
	virtual Table select (const std::string& query);
    };

    /** SPARQL protocol client over HTTP: POSTs the query form-urlencoded to
     * the endpoint and parses the application/sparql-results+xml response.
     * Response bnodes come out fresh per response (the XML parser keeps a
     * per-parse bnode map) - exactly the semantics BNodeResolver expects.
     * Plain http only (the ASIO agent does not speak TLS); requires a build
     * with SWOBJ_HTTP_CLIENT=ON (the default) - throws from the constructor
     * otherwise. */
    class HTTPSPARQLClient : public SPARQLClient {
	AtomFactory* F;
	SWWEBagent* agent;      // owned
	SWSAXparser* xmlParser; // owned
	std::string endpoint;
    public:
	size_t queriesServed;
	HTTPSPARQLClient (AtomFactory* F, std::string endpoint);
	virtual ~HTTPSPARQLClient ();
	virtual Table select (const std::string& query);
    };

    /** serialize a ground term in SPARQL syntax */
    std::string sparqlTerm (const TTerm* t);

    /** one identifying arc: the hole (the bnode being identified) sits at
     * the subject if holeAtSubject, else at the object; `other` is ground or
     * another resolved proxy (recursive). */
    struct Arc {
	bool holeAtSubject;
	const TTerm* p;
	const TTerm* other;
	Arc (bool holeAtSubject, const TTerm* p, const TTerm* other)
	    : holeAtSubject(holeAtSubject), p(p), other(other) {  }
    };
    struct Fragment {
	std::vector<Arc> arcs;
	std::string key; // canonical form; identity across responses
    };

    class BNodeResolver {
    public:
	AtomFactory* F;
	SPARQLClient* client;   // borrowed
	size_t queriesIssued;   // total round trips (instrumentation metric)
	size_t maxDepth;        // recursive identification depth cap

	BNodeResolver (AtomFactory* F, SPARQLClient* client)
	    : F(F), client(client), queriesIssued(0), maxDepth(4) {  }

	/** run a SELECT whose text may not mention response bnodes; every
	 * response bnode is replaced by a stable proxy. `contextWhere` is the
	 * query's WHERE-group text (used to pin bnodes during
	 * interrogation). */
	Table select (const std::string& query, const std::string& contextWhere);

	bool isProxy (const TTerm* t) const { return fragments.find(t) != fragments.end(); }
	const Fragment& fragmentOf (const TTerm* proxy) const { return fragments.find(proxy)->second; }

	/** SPARQL text for a term usable in a new query: ground terms
	 * serialize directly; a proxy returns a fresh variable and appends
	 * its identifying triples to `where`. */
	std::string mention (const TTerm* t, std::string& where, size_t& varCtr) const;

    private:
	std::map<std::string, const TTerm*> byKey; // fragment key -> proxy
	std::map<const TTerm*, Fragment> fragments;

	Table raw (const std::string& query); // client->select + count

	/** identify the response bnodes matching a pin: interrogate arcs in
	 * and out of each candidate (one round trip), pick minimal
	 * uniqueness-verified fragments, return their proxies in candidate
	 * order. An ambiguous pin yields several; structurally identical
	 * candidates dedup onto one witness. */
	std::vector<const TTerm*> resolveBNode (const std::string& ctxWhere,
						std::set<std::string>& inFlight, size_t depth);
	const TTerm* internFragment (const Fragment& frag);
	bool uniquelyIdentifies (const Fragment& frag);
	std::string fragmentWhere (const Fragment& frag, const std::string& holeVar,
				   size_t& varCtr) const;
    };

    /** Materializing triple-pattern cache shared by the ShEx neighborhood
     * hook and Algae 3 remote bgpmatch: ensurePattern(s,p,o) (NULL =
     * wildcard) faults matching triples from the endpoint into `cache`,
     * with response bnodes as proxies; subsumed patterns are not re-fetched,
     * so interrogation results answer later neighborhood queries. */
    class RemoteGraphProvider {
    public:
	BNodeResolver resolver;
	BasicGraphPattern* cache; // borrowed; typically the working graph

	RemoteGraphProvider (AtomFactory* F, SPARQLClient* client, BasicGraphPattern* cache)
	    : resolver(F, client), cache(cache) {  }

	void ensurePattern (const TTerm* s, const TTerm* p, const TTerm* o);
	void ensureNode (const TTerm* node) { // ShEx: both directions
	    ensurePattern(node, NULL, NULL);
	    ensurePattern(NULL, NULL, node);
	}

    private:
	struct Pat { const TTerm* s; const TTerm* p; const TTerm* o; };
	std::vector<Pat> fetched;
	bool subsumed (const TTerm* s, const TTerm* p, const TTerm* o) const;
    };

} // namespace bnr
} // namespace w3c_sw

#endif /* INCLUDED_BNodeResolver */
