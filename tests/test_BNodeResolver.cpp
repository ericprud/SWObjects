/* test_BNodeResolver - told-bnode emulation (lib/BNodeResolver.hpp).
 *
 * All tests run against the RelabelingLocalClient, which renames every
 * response blank node freshly per response - anything that works by label
 * luck fails here. Data: the evidence-appraisal fixtures, whose group
 * memberships are blank nodes ([ ex:evidence ev:OBS-2214 ]) shared between
 * groups, so identification genuinely needs instrumentation (the in-arc
 * from the group alone does not discriminate two memberships of one group;
 * the out-arc to the evidence does not discriminate two groups' memberships
 * of the same evidence).
 */

#define BOOST_TEST_MODULE BNodeResolver

#include "SWObjects.hpp"
#include "BNodeResolver.hpp"
#include "TurtleParser.hpp"
#include "ShExSchema.hpp"
#include "ShExCParser.hpp"
#include "Algae3.hpp"
#include "Algae3Parser.hpp"
#include "Logging.hpp"

#include <boost/test/unit_test.hpp>
#include <fstream>
#include <sstream>

namespace sw = w3c_sw;

namespace {
    sw::AtomFactory F;

    std::string readFile (const std::string& path) {
	std::ifstream in(path.c_str(), std::ios::binary);
	BOOST_REQUIRE_MESSAGE(in.good(), "cannot open " + path);
	std::ostringstream ss;
	ss << in.rdbuf();
	return ss.str();
    }

    void loadTurtle (sw::RdfDB& db, const std::string& path) {
	sw::TurtleDriver parser("", &F);
	sw::IStreamContext istr(readFile(path), sw::IStreamContext::STRING);
	parser.parse(istr, db.ensureGraph(sw::DefaultGraph));
    }

    const char* EX = "http://a.example/ns#";
    const char* EVG = "http://a.example/evgrp/";
    const char* EV = "http://a.example/evidence#";

    /** endpoint-side dataset shared by the tests */
    struct Endpoint {
	sw::RdfDB db;
	sw::bnr::RelabelingLocalClient client;
	Endpoint () : client(&F, &db) {
	    loadTurtle(db, "Algae3/data/evidence.ttl");
	    loadTurtle(db, "Algae3/data/evidence-groups.ttl");
	}
    };
}

BOOST_AUTO_TEST_CASE( proxies_stable_across_relabeled_responses ) {
    Endpoint ep;
    sw::bnr::BNodeResolver resolver(&F, &ep.client);
    std::string where = std::string("<") + EVG + "PeerReviewedCohorts> <" + EX + "member> ?m . "
	+ "?m <" + EX + "evidence> ?e . ";
    std::string q = "SELECT ?m ?e WHERE { " + where + "}";

    sw::bnr::Table t1 = resolver.select(q, where);
    BOOST_REQUIRE_EQUAL(t1.size(), 2u);
    const sw::TTerm* m0 = t1[0]["m"];
    const sw::TTerm* m1 = t1[1]["m"];
    BOOST_CHECK(resolver.isProxy(m0));
    BOOST_CHECK(resolver.isProxy(m1));
    BOOST_CHECK(m0 != m1); // two memberships, two identities

    /* the told-bnode property: a SECOND query (bnodes relabeled by the
     * endpoint) resolves to the SAME proxies */
    sw::bnr::Table t2 = resolver.select(q, where);
    std::set<const sw::TTerm*> first, second;
    first.insert(m0); first.insert(m1);
    second.insert(t2[0]["m"]); second.insert(t2[1]["m"]);
    BOOST_CHECK(first == second);

    /* each fragment must include the discriminating out-arc (both
     * memberships share the group in-arc) */
    const sw::bnr::Fragment& f0 = resolver.fragmentOf(m0);
    bool hasEvidenceArc = false;
    for (std::vector<sw::bnr::Arc>::const_iterator a = f0.arcs.begin(); a != f0.arcs.end(); ++a)
	if (a->holeAtSubject && a->p->getLexicalValue() == std::string(EX) + "evidence")
	    hasEvidenceArc = true;
    BOOST_CHECK_MESSAGE(hasEvidenceArc, "fragment lacks the discriminating ex:evidence arc: " + f0.key);
}

BOOST_AUTO_TEST_CASE( mention_rejoins_the_right_bnode ) {
    Endpoint ep;
    sw::bnr::BNodeResolver resolver(&F, &ep.client);
    /* OBS-2214 has memberships in PeerReviewedCohorts AND ConfoundedStudies:
     * same out-arc, different in-arcs - identification needs both sides */
    std::string where = std::string("?g <") + EX + "member> ?m . "
	+ "?m <" + EX + "evidence> <" + EV + "OBS-2214> . ";
    std::string q = "SELECT ?g ?m WHERE { " + where + "}";
    sw::bnr::Table t = resolver.select(q, where);
    /* PeerReviewed + Confounded (bnode memberships) + Recent (an IRI
     * membership node - passes through unresolved) */
    BOOST_REQUIRE_EQUAL(t.size(), 3u);

    /* re-mention each membership: proxies expand to their fragments, the
     * IRI serializes directly; each must return exactly its group */
    for (sw::bnr::Table::const_iterator r = t.begin(); r != t.end(); ++r) {
	const sw::TTerm* g = r->find("g")->second;
	const sw::TTerm* m = r->find("m")->second;
	std::string where2;
	size_t ctr = 0;
	std::string mm = resolver.mention(m, where2, ctr);
	std::string q2 = "SELECT ?gg WHERE { " + where2 + "?gg <" + EX + "member> " + mm + " . }";
	sw::bnr::Table t2 = resolver.select(q2, where2);
	BOOST_REQUIRE_EQUAL(t2.size(), 1u);
	BOOST_CHECK_EQUAL(t2[0].find("gg")->second, g);
    }
}

BOOST_AUTO_TEST_CASE( sibling_neighbors_distinguished_by_recursion ) {
    /* two anonymous neighbors of x:s via the SAME predicate are themselves
     * only distinguishable through THEIR neighbors (a second bnode hop):
     * identification must recurse, and sibling neighbors must draw distinct
     * candidates from the recursive resolution instead of all collapsing
     * onto its first candidate */
    sw::RdfDB db;
    {
	sw::TurtleDriver parser("", &F);
	std::string ttl =
	    "@prefix x: <http://a.example/x#> .\n"
	    "x:s x:p _:n1, _:n2 .\n"
	    "_:n1 x:q _:c1 . _:c1 x:r x:v1 .\n"
	    "_:n2 x:q _:c2 . _:c2 x:r x:v2 .\n";
	sw::IStreamContext istr(ttl, sw::IStreamContext::STRING);
	parser.parse(istr, db.ensureGraph(sw::DefaultGraph));
    }
    sw::bnr::RelabelingLocalClient client(&F, &db);
    sw::bnr::BNodeResolver resolver(&F, &client);

    std::string where = "<http://a.example/x#s> <http://a.example/x#p> ?n . ";
    sw::bnr::Table t = resolver.select("SELECT ?n WHERE { " + where + "}", where);
    BOOST_REQUIRE_EQUAL(t.size(), 2u);
    const sw::TTerm* ns[] = { t[0]["n"], t[1]["n"] };
    BOOST_CHECK(ns[0] != ns[1]); // siblings must not collapse

    /* each proxy re-queries to exactly one node, and between them the two
     * reach both x:r values - the bijection covers both siblings */
    std::set<std::string> vs;
    for (int i = 0; i < 2; ++i) {
	std::string w2;
	size_t ctr = 0;
	std::string m = resolver.mention(ns[i], w2, ctr);
	w2 += m + " <http://a.example/x#q> ?c . ?c <http://a.example/x#r> ?v . ";
	sw::bnr::Table t2 = resolver.select("SELECT ?v WHERE { " + w2 + "}", w2);
	BOOST_REQUIRE_EQUAL(t2.size(), 1u);
	vs.insert(t2[0].find("v")->second->getLexicalValue());
    }
    BOOST_CHECK_EQUAL(vs.size(), 2u);
}

BOOST_AUTO_TEST_CASE( provider_caches_and_subsumes ) {
    Endpoint ep;
    sw::RdfDB cacheDB;
    sw::bnr::RemoteGraphProvider provider(&F, &ep.client, cacheDB.ensureGraph(sw::DefaultGraph));
    const sw::TTerm* group = F.getURI(std::string(EVG) + "PeerReviewedCohorts");

    provider.ensureNode(group);
    size_t after1 = ep.client.queriesServed;
    BOOST_CHECK_GT(after1, 0u);
    /* subsumption: repeating and narrowing cost nothing */
    provider.ensureNode(group);
    provider.ensurePattern(group, F.getURI(std::string(EX) + "member"), NULL);
    BOOST_CHECK_EQUAL(ep.client.queriesServed, after1);

    /* the cache holds the two membership proxies, distinct despite
     * relabeling */
    const sw::BasicGraphPattern::triple_iterator end;
    std::set<const sw::TTerm*> members;
    for (sw::BasicGraphPattern::triple_iterator ti
	     = cacheDB.ensureGraph(sw::DefaultGraph)->getTripleIterator(
		   group, F.getURI(std::string(EX) + "member"), NULL);
	 ti != end; ++ti) {
	members.insert((*ti)->getO());
	BOOST_CHECK(provider.resolver.isProxy((*ti)->getO()));
    }
    BOOST_CHECK_EQUAL(members.size(), 2u);
}

BOOST_AUTO_TEST_CASE( shex_validation_over_endpoint ) {
    /* GroupShape requires every membership (a bnode!) to have exactly one
     * ex:evidence IRI - validating remotely must fetch each membership's
     * neighborhood through its identifying fragment */
    Endpoint ep;
    std::string schemaText = std::string()
	+ "PREFIX ex: <" + EX + ">\n"
	+ "<GroupShape> { ex:name . ; ex:member @<MembershipShape>+ }\n"
	+ "<MembershipShape> { ex:evidence IRI }\n";
    sw::ShEx::Schema schema;
    sw::ShExDriver driver("", &F);
    sw::IStreamContext istr(schemaText, sw::IStreamContext::STRING);
    driver.parse(istr, &schema);
    schema.checkStructure();

    const sw::TTerm* groupShape = F.getURI("GroupShape");
    const sw::TTerm* peer = F.getURI(std::string(EVG) + "PeerReviewedCohorts");
    const sw::TTerm* prereg = F.getURI(std::string(EVG) + "PreregisteredStudies");

    /* local truth */
    bool localPeer, localPrereg;
    {
	sw::RdfDB local;
	loadTurtle(local, "Algae3/data/evidence.ttl");
	loadTurtle(local, "Algae3/data/evidence-groups.ttl");
	sw::ShEx::Validator v(schema, *local.ensureGraph(sw::DefaultGraph));
	localPeer = v.validate(peer, groupShape);
	sw::ShEx::Validator v2(schema, *local.ensureGraph(sw::DefaultGraph));
	localPrereg = v2.validate(prereg, groupShape);
    }
    BOOST_CHECK(localPeer);

    /* remote: empty cache + neighborhood source */
    struct Src : public sw::ShEx::Validator::NeighborhoodSource {
	sw::bnr::RemoteGraphProvider& p;
	Src (sw::bnr::RemoteGraphProvider& p) : p(p) {  }
	virtual void ensure (const sw::TTerm* focus) { p.ensureNode(focus); }
    };
    sw::RdfDB cacheDB;
    sw::bnr::RemoteGraphProvider provider(&F, &ep.client, cacheDB.ensureGraph(sw::DefaultGraph));
    Src src(provider);

    sw::ShEx::Validator rv(schema, *cacheDB.ensureGraph(sw::DefaultGraph));
    rv.neighborhoodSource = &src;
    BOOST_CHECK_EQUAL(rv.validate(peer, groupShape), localPeer);

    sw::ShEx::Validator rv2(schema, *cacheDB.ensureGraph(sw::DefaultGraph));
    rv2.neighborhoodSource = &src;
    BOOST_CHECK_EQUAL(rv2.validate(prereg, groupShape), localPrereg);
}

namespace {
    std::string runA3Sorted (sw::a3::Query& q, sw::a3::Engine& e) {
	e.run(q);
	std::vector<std::string> rows;
	for (sw::ResultSetConstIterator it = e.rs->begin(); it != e.rs->end(); ++it) {
	    std::vector<std::string> cells;
	    for (sw::BindingSetConstIterator b = (*it)->begin(); b != (*it)->end(); ++b)
		cells.push_back(b->first->toString() + "=" + b->second.tterm->toString() + ";");
	    std::sort(cells.begin(), cells.end());
	    std::string row;
	    for (std::vector<std::string>::const_iterator c = cells.begin(); c != cells.end(); ++c)
		row += *c;
	    rows.push_back(row);
	}
	std::sort(rows.begin(), rows.end());
	std::string out;
	for (std::vector<std::string>::const_iterator it = rows.begin(); it != rows.end(); ++it)
	    out += *it + "\n";
	return out;
    }
}

BOOST_AUTO_TEST_CASE( algae3_remote_evidence_dnf ) {
    /* the flagship: evidence-dnf executed REMOTELY - every bgpmatch triple
     * faults through the provider; membership-bnode seeds cross round trips
     * as told bnodes - must equal the local golden. (Its aggregations never
     * join bnodes inside-to-outside, the documented scope limit.) */
    Endpoint ep;
    loadTurtle(ep.db, "Algae3/data/evidence-rules.ttl"); // endpoint holds the rules too

    /* strip the load actions: the dataset lives behind the endpoint */
    std::string script = readFile("Algae3/evidence-dnf.topdown.a3");
    std::string stripped;
    std::istringstream lines(script);
    std::string line;
    while (std::getline(lines, line))
	if (line.compare(0, 5, "load ") != 0)
	    stripped += line + "\n";

    sw::a3::Query q;
    sw::Algae3Driver driver("", &F);
    sw::IStreamContext istr(stripped, sw::IStreamContext::STRING);
    driver.parse(istr, &q);

    sw::a3::Engine e(&F, q.mode);
    sw::bnr::RemoteGraphProvider provider(&F, &ep.client,
					  e.db.ensureGraph(sw::DefaultGraph));
    e.remote = &provider;
    std::string got = runA3Sorted(q, e);

    std::string want = readFile("Algae3/expected/evidence-dnf.expected");
    BOOST_CHECK_EQUAL(got, want);
}
