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
#include "SPARQLParser.hpp"
#include "TurtleParser.hpp"
#include "ShExSchema.hpp"
#include "ShExCParser.hpp"
#include "Algae3.hpp"
#include "Algae3Parser.hpp"
#include "Logging.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <thread>

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

namespace {
    /* An in-process SPARQL protocol endpoint: accepts HTTP POSTs of
     * form-urlencoded query=, executes against its RdfDB, answers
     * application/sparql-results+xml. Response bnode labels are only
     * meaningful within one response; the client's XML parse maps them to
     * fresh terms per response - standard endpoint relabeling for free. */
    struct MiniEndpoint {
	sw::RdfDB db;
	boost::asio::io_context io;
	boost::asio::ip::tcp::acceptor acceptor;
	std::thread thread;
	bool stopping;
	size_t queriesServed;

	MiniEndpoint ()
	    : acceptor(io, boost::asio::ip::tcp::endpoint(
			   boost::asio::ip::make_address("127.0.0.1"), 0)),
	      stopping(false), queriesServed(0) {
	    loadTurtle(db, "Algae3/data/evidence.ttl");
	    loadTurtle(db, "Algae3/data/evidence-groups.ttl");
	    loadTurtle(db, "Algae3/data/evidence-rules.ttl");
	    thread = std::thread(&MiniEndpoint::run, this);
	}
	~MiniEndpoint () {
	    stopping = true;
	    boost::system::error_code ec;
	    acceptor.close(ec);
	    if (thread.joinable()) thread.join();
	}
	std::string url () const {
	    std::ostringstream ss;
	    ss << "http://127.0.0.1:" << acceptor.local_endpoint().port() << "/sparql";
	    return ss.str();
	}

	static std::string urlDecode (const std::string& s) {
	    std::string ret;
	    for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '+') ret += ' ';
		else if (s[i] == '%' && i + 2 < s.size()) {
		    ret += (char)strtol(s.substr(i+1, 2).c_str(), NULL, 16);
		    i += 2;
		} else ret += s[i];
	    }
	    return ret;
	}

	void run () {
	    while (!stopping) {
		boost::asio::ip::tcp::socket sock(io);
		boost::system::error_code ec;
		acceptor.accept(sock, ec);
		if (ec) return; // acceptor closed - shut down
		try { handle(sock); } catch (...) {  }
	    }
	}

	void handle (boost::asio::ip::tcp::socket& sock) {
	    boost::asio::streambuf buf;
	    boost::system::error_code ec;
	    boost::asio::read_until(sock, buf, "\r\n\r\n", ec);
	    if (ec) return;
	    std::istream in(&buf);
	    std::string line;
	    size_t contentLength = 0;
	    std::getline(in, line); // request line
	    while (std::getline(in, line) && line != "\r") {
		std::string lower = line;
		std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
		if (lower.compare(0, 15, "content-length:") == 0)
		    contentLength = atoi(line.substr(15).c_str());
	    }
	    std::string body;
	    { std::ostringstream got; got << &buf; body = got.str(); }
	    while (body.size() < contentLength) {
		char chunk[4096];
		size_t n = sock.read_some(boost::asio::buffer(chunk), ec);
		if (ec) break;
		body.append(chunk, n);
	    }

	    /* extract the query= form parameter */
	    std::string query;
	    for (size_t at = 0; at < body.size(); ) {
		size_t amp = body.find('&', at);
		if (amp == std::string::npos) amp = body.size();
		size_t eq = body.find('=', at);
		if (eq != std::string::npos && eq < amp
		    && body.substr(at, eq - at) == "query")
		    query = urlDecode(body.substr(eq + 1, amp - eq - 1));
		at = amp + 1;
	    }

	    std::string respBody, status = "200 OK";
	    try {
		++queriesServed;
		sw::SPARQLDriver driver("", &F);
		sw::IStreamContext istr(query, sw::IStreamContext::STRING);
		sw::Operation* op = driver.parse(istr);
		sw::ResultSet rs(&F);
		op->execute(&db, &rs);
		delete op;
		respBody = rs.toString(sw::MediaType("application/sparql-results+xml"));
	    } catch (...) {
		status = "400 Bad Request";
		respBody = "query failed";
	    }
	    std::ostringstream resp;
	    resp << "HTTP/1.0 " << status << "\r\n"
		 << "Content-Type: application/sparql-results+xml\r\n"
		 << "Content-Length: " << respBody.size() << "\r\n"
		 << "Connection: close\r\n\r\n" << respBody;
	    boost::asio::write(sock, boost::asio::buffer(resp.str()), ec);
	    sock.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
	}
    };

    sw::bnr::SPARQLClient* makeHTTPClient (const std::string& iri, sw::AtomFactory* F) {
	return new sw::bnr::HTTPSPARQLClient(F, iri);
    }
}

BOOST_AUTO_TEST_CASE( http_client_told_bnodes ) {
    /* the resolver machinery over a real HTTP SPARQL protocol round trip:
     * proxies must be stable across separately parsed responses */
    MiniEndpoint ep;
    sw::bnr::HTTPSPARQLClient client(&F, ep.url());
    sw::bnr::BNodeResolver resolver(&F, &client);
    std::string where = std::string("<") + EVG + "PeerReviewedCohorts> <" + EX + "member> ?m . "
	+ "?m <" + EX + "evidence> ?e . ";
    std::string q = "SELECT ?m ?e WHERE { " + where + "}";

    sw::bnr::Table t1 = resolver.select(q, where);
    BOOST_REQUIRE_EQUAL(t1.size(), 2u);
    BOOST_CHECK(resolver.isProxy(t1[0]["m"]));
    BOOST_CHECK(t1[0]["m"] != t1[1]["m"]);

    sw::bnr::Table t2 = resolver.select(q, where);
    std::set<const sw::TTerm*> first, second;
    first.insert(t1[0]["m"]); first.insert(t1[1]["m"]);
    second.insert(t2[0]["m"]); second.insert(t2[1]["m"]);
    BOOST_CHECK(first == second);
    BOOST_CHECK_EQUAL(client.queriesServed, ep.queriesServed);
}

BOOST_AUTO_TEST_CASE( attach_runs_flagship_against_http_endpoint ) {
    /* the full chain the attach action promises: `attach <http://…> ep` in
     * the script -> Engine::attachClientFactory -> HTTPSPARQLClient ->
     * BNodeResolver -> provider fault-in - no local load, golden results */
    MiniEndpoint ep;
    sw::a3::Engine::attachClientFactory = &makeHTTPClient;

    std::string script = readFile("Algae3/evidence-dnf.topdown.a3");
    std::string rewritten;
    std::istringstream lines(script);
    std::string line;
    bool attached = false;
    while (std::getline(lines, line))
	if (line.compare(0, 5, "load ") == 0) {
	    if (!attached) { // first load's position gets the attach
		rewritten += "attach <" + ep.url() + "> ep\n";
		attached = true;
	    }
	} else
	    rewritten += line + "\n";
    BOOST_REQUIRE(attached);

    sw::a3::Query q;
    sw::Algae3Driver driver("", &F);
    sw::IStreamContext istr(rewritten, sw::IStreamContext::STRING);
    driver.parse(istr, &q);

    sw::a3::Engine e(&F, q.mode);
    std::string got = runA3Sorted(q, e);
    sw::a3::Engine::attachClientFactory = NULL;

    BOOST_CHECK_EQUAL(got, readFile("Algae3/expected/evidence-dnf.expected"));
    BOOST_CHECK_GT(ep.queriesServed, 0u);
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
