/* test query-mapping.
 *
 * $Id: test_QueryMap.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE QueryMap

#include <map>
#include <vector>
#include <fstream>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "MapSetParser/MapSetParser.hpp"
#include "SQLParser/SQLParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "ChainingMapper.hpp"
#include "SQLizer.hpp"

#ifndef MANUAL_TEST
  #include <boost/test/unit_test.hpp>
#endif

using namespace w3c_sw;

AtomFactory f;
SPARQLfedDriver sparqlParser("", &f);
MapSetDriver mapSetParser("", &f);
std::ostream* DebugStream = NULL; // &std::cerr;
ChainingMapper queryMapper(&f, &DebugStream);


struct EqualsTest {
    Operation* left, * right;
    bool (*mapper)(const TTerm*);
    EqualsTest (const char* leftString, const char* rightString) {

	/* Parse left. */
	IStreamContext lstream(leftString, IStreamContext::STRING);
	if (sparqlParser.parse(lstream)) {
	    std::string msg = std::string("failed to parse left \"") + 
		leftString + std::string("\".");
	    throw msg;
	}
	left = sparqlParser.root;

	/* Parse right. */
	IStreamContext rstream(rightString, IStreamContext::STRING);
	if (sparqlParser.parse(rstream)) {
	    std::string msg = std::string("failed to parse right \"") + 
		rightString + std::string("\".");
	    throw msg;
	}
	right = sparqlParser.root;
	mapper = BasicGraphPattern::MappableTerm;
	BasicGraphPattern::MappableTerm = BasicGraphPattern::MapBNodes;
    }
    ~EqualsTest () {
	BasicGraphPattern::MappableTerm = mapper;
	delete left;
	delete right;
    }
};

BOOST_AUTO_TEST_SUITE( op_equals )

BOOST_AUTO_TEST_SUITE( bgp )
BOOST_AUTO_TEST_CASE( case_and_space_sensitivity ) {
    BOOST_TEST_CHECKPOINT( "executing BGP tests" );
    EqualsTest t("SELECT * WHERE { ?s ?p ?o }", 
		 "select*{?s?p?o}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( question_dollar_vars ) {
    EqualsTest t("SELECT ?s ?p ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p $o { ?s ?p ?o}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( respect_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p ?o { ?s ?p ?o}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( observe_triple_order ) {
    EqualsTest t("SELECT ?s ?p ?o { ?s ?p ?o }", 
		 "SELECT ?s ?p $o { ?s ?o ?p}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( equiv_filter ) {
    EqualsTest t("SELECT * { FILTER(1*(2+3)=?x) }", 
		 "SELECT * { FILTER(1*(2+3)=$x) }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( different_vars_in_filter ) {
    EqualsTest t("SELECT * { FILTER( ?x ) }", 
		 "SELECT * { FILTER( ?y ) }");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( nested )
BOOST_AUTO_TEST_CASE( nested_case_and_space_sensitivity ) {
    BOOST_TEST_CHECKPOINT( "executing nested tests" );
    EqualsTest t("SELECT * WHERE { { ?s ?p ?o } }", 
		 "select*{{?s?p?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_question_dollar_vars ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {{ ?s ?p ?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_respect_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( nested_observe_triple_order ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {{ ?s ?o ?p}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( nested_equiv_filter ) {
    EqualsTest t("SELECT * {{ FILTER(1*(2+3)=?x) }}", 
		 "SELECT * {{ FILTER(1*(2+3)=$x) }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( nested_different_vars_in_filter ) {
    EqualsTest t("SELECT * {{ FILTER( ?x ) }}", 
		 "SELECT * {{ FILTER( ?y ) }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( named )
BOOST_AUTO_TEST_CASE( named_case_and_space_sensitivity ) {
    BOOST_TEST_CHECKPOINT( "executing named graph tests" );
    EqualsTest t("SELECT * WHERE { GRAPH<x> { ?s ?p ?o } }", 
		 "select*{graph<x>{?s?p?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_question_dollar_vars ) {
    EqualsTest t("SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {GRAPH<x>{ ?s ?p ?o}}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_respect_select_order ) {
    EqualsTest t("SELECT ?p ?s ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( named_observe_triple_order ) {
    EqualsTest t("SELECT ?s ?p ?o {GRAPH<x>{ ?s ?p ?o }}", 
		 "SELECT ?s ?p $o {GRAPH<x>{ ?s ?o ?p}}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( named_equiv_filter ) {
    EqualsTest t("SELECT * {GRAPH<x>{ FILTER(1*(2+3)=?x) }}", 
		 "SELECT * {GRAPH<x>{ FILTER(1*(2+3)=$x) }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( named_different_vars_in_filter ) {
    EqualsTest t("SELECT * {GRAPH<x>{ FILTER( ?x ) }}", 
		 "SELECT * {GRAPH<x>{ FILTER( ?y ) }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( conjuncts )
BOOST_AUTO_TEST_CASE( conjunct_positive ) {
    EqualsTest t("SELECT ?s ?p ?o ?o2 {{ ?s ?p ?o } { ?s ?p ?o2 }}", 
		 "SELECT ?s ?p ?o ?o2 {{ ?s ?p ?o } { ?s ?p ?o2 }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( conjunct_negative ) {
    EqualsTest t("SELECT $p ?s $o {{ ?s ?p ?o } { ?s ?p ?o }}", 
		 "SELECT $s ?p ?o {{ ?s ?p ?o } { ?s ?o ?p }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( conjunct_equiv_filter ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER(1*(2+3)=?x)}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( conjunct_different_vars_in_filter ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER( ?x )}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } { ?s ?p ?o } FILTER( ?y )}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( unions )
BOOST_AUTO_TEST_CASE( union_positive ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o }}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o }}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( union_negative ) {
    EqualsTest t("SELECT $p ?s $o {{ ?s ?p ?o } UNION { ?s ?p ?o }}", 
		 "SELECT $s ?p ?o {{ ?s ?p ?o } UNION { ?s ?o ?p }}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_CASE( union_equiv_filter ) {
    EqualsTest t("SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( union_different_vars_in_filter ) {
    EqualsTest t("SELECT ?p ?s ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER( ?x )}", 
		 "SELECT ?s ?p ?o {{ ?s ?p ?o } UNION { ?s ?p ?o } FILTER( ?y )}");
    BOOST_CHECK_MESSAGE( !(*t.left == *t.right), *t.left << " == " << *t.right );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct DNFtest : public EqualsTest {
    const TableOperation* dnf;
    const TableOperation* ref;
    struct GetRootOp : public RecursiveExpressor {
	const TableOperation* rootOp;
	virtual void base (const w3c_sw::Base* const, std::string) {  }
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause*) {
	    rootOp = p_GroupGraphPattern;
	}
    };
    DNFtest (const char* leftString, const char* rightString) : 
	EqualsTest (leftString, rightString) {
	GetRootOp g;
	left->express(&g);
	dnf = g.rootOp->getDNF();

	right->express(&g);
	ref = g.rootOp;
    }
    ~DNFtest () {
	delete dnf;
    }
};

BOOST_AUTO_TEST_SUITE( DNFtests )

BOOST_AUTO_TEST_SUITE( unions )
BOOST_AUTO_TEST_CASE( A_or_B ) {
    DNFtest t("ASK {{ ?s1 ?p1 ?o1 } UNION { ?s2 ?p2 ?o2 }}", 
	      "ASK {{ ?s1 ?p1 ?o1 } UNION { ?s2 ?p2 ?o2 }}");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( A_or_B_and_C ) {
    DNFtest t("ASK { { { ?s1 ?p1 ?o1 } UNION { ?s2 ?p2 ?o2 } } { ?s3 ?p3 ?o3 } }", 
	      "ASK { { { ?s1 ?p1 ?o1 } { ?s3 ?p3 ?o3 } } UNION { { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } } }");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( A_and_B_or_C ) {
    DNFtest t("ASK { { ?s1 ?p1 ?o1 } { { ?s2 ?p2 ?o2 } UNION { ?s3 ?p3 ?o3 } } }", 
	      "ASK { { { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } } UNION  { { ?s1 ?p1 ?o1 } { ?s3 ?p3 ?o3 } } }");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( union_equiv_filter_positive ) {
    DNFtest t("ASK { { ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
	      "ASK { { { ?s ?p ?o FILTER(1*(2+3)=?x) } } UNION { { ?s ?p ?o FILTER(1*(2+3)=?x) } } }");
    BOOST_CHECK_EQUAL(*t.dnf, *t.ref);
}
BOOST_AUTO_TEST_CASE( union_different_vars_in_filter ) {
    DNFtest t("ASK { { ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}", 
	      "ASK { { ?s ?p ?o } UNION { ?s ?p ?o } FILTER(1*(2+3)=?x)}");
    BOOST_CHECK_MESSAGE( !(*t.dnf == *t.ref), *t.dnf << " == " << *t.ref );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct SimplifiedBGPtest : public EqualsTest {
    SimplifiedBGPtest (const char* leftString, const char* rightString) : 
	EqualsTest (leftString, rightString) {
	BGPSimplifier s(&f);
	left->express(&s);
	delete left;
	left = const_cast<Operation*>(s.last.operation);
    }
};

BOOST_AUTO_TEST_SUITE( SimplifiedBGPtests )

BOOST_AUTO_TEST_SUITE( unions )
BOOST_AUTO_TEST_CASE( A_and_B ) {
    SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } }", 
			"ASK { ?s1 ?p1 ?o1 . ?s2 ?p2 ?o2 }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( Y_and_Y ) {
    SimplifiedBGPtest t("SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			"           SERVICE <S3> { ?qs <p3> ?qo } }",
			"SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			"           SERVICE <S3> { ?qs <p3> ?qo } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}

BOOST_AUTO_TEST_CASE( A_and_C_or_B_and_C ) {
    SimplifiedBGPtest t("ASK { { { ?s1 ?p1 ?o1 } { ?s3 ?p3 ?o3 } } UNION { { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } } }", 
			"ASK { {   ?s1 ?p1 ?o1  .  ?s3 ?p3 ?o3 }   UNION {   ?s2 ?p2 ?o2  .  ?s3 ?p3 ?o3 }   }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( A_and__B_and_C ) {
    SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } } }", 
			"ASK { ?s1 ?p1 ?o1    .    ?s2 ?p2 ?o2  .  ?s3 ?p3 ?o3 }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( A_and__B_minus_C ) {
    SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { { ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } } }", 
			"ASK { { ?s1 ?p1 ?o1  .    ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( optional_A_B ) {
    SimplifiedBGPtest t("ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } }", 
			"ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
BOOST_AUTO_TEST_CASE( optional_A_B_C ) {
    SimplifiedBGPtest t("ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } { ?s3 ?p3 ?o3 } }", 
			"ASK { OPTIONAL { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2  .  ?s3 ?p3 ?o3 } }");
    BOOST_CHECK_EQUAL(*t.left, *t.right);
}
// BOOST_AUTO_TEST_CASE( A_B_minus_C_D_E ) {
//     SimplifiedBGPtest t("ASK { { ?s1 ?p1 ?o1 } { ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } { ?s4 ?p4 ?o4 } { ?s5 ?p5 ?o5 } }", 
// 			"ASK { { ?s1 ?p1 ?o1  .  ?s2 ?p2 ?o2 } MINUS { ?s3 ?p3 ?o3 } { ?s4 ?p4 ?o4  .  ?s5 ?p5 ?o5 } }");
//     BOOST_CHECK_EQUAL(*t.left, *t.right);
// }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


    struct SWObjectCanonicalizer : public SWObjectDuplicator {
	SWObjectCanonicalizer (AtomFactory* atomFactory)
	    : SWObjectDuplicator(atomFactory) {  }

	struct Root {
	    unsigned depth;
	    std::set<const TTerm*> peers;
	    Root () : depth(-1) {  }

	    void consider (const TTerm* peer, unsigned peerDepth) {
		if (peers.size() == 0 || depth >= peerDepth) {
		    if (depth > peerDepth)
			peers.clear();
		    depth = peerDepth;
		    peers.insert(peer);
		}
	    }
	    void consider (const Root& candidateRoot) {
		if (peers.size() == 0 || depth >= candidateRoot.depth) {
		    if (depth > candidateRoot.depth)
			peers.clear();
		    depth = candidateRoot.depth;
		    for (std::set<const TTerm*>::const_iterator peer = candidateRoot.peers.begin();
			 peer != candidateRoot.peers.end(); ++peer)
			peers.insert(*peer);
		}
	    }
	};

	struct DepthList {
	    Root root;
	    std::map<const TTerm*, unsigned> leads;
	    std::map<const TTerm*, unsigned> touched;
	    void print (std::ostream& os) const {
		//assert(leads.size()>1 || root.peers.size()>1);
		if (root.peers.size() > 0) {
		    os << "roots: ";
		    for (std::set<const TTerm*>::const_iterator it = root.peers.begin();
			 it != root.peers.end(); ++it)
			os << (*it)->toString();
		    os << "@" << root.depth;
		}
		if (leads.size() > 0) {
		    os << "leads: ";
		    for (std::map<const TTerm*, unsigned>::const_iterator via = leads.begin();
			 via != leads.end(); ++via) {
			if (via != leads.begin())
			    os << "|";
			os << via->first->toString() << "@" << via->second;
		    }
		}
		if (touched.size() > 0) {
		    os << " touched: ";
		    for (std::map<const TTerm*, unsigned>::const_iterator touch = touched.begin();
			 touch != touched.end(); ++touch) {
			if (touch != touched.begin())
			    os << ",";
			os << touch->first->toString() << "@" << touch->second;
		    }
		}
	    }
	};

	struct ObjectOf : public std::map<const TTerm*, DepthList> {
	    void print (std::ostream& os) const {
		for (ObjectOf::const_iterator it = begin();
		     it != end(); ++it) {
		    os << it->first->toString() << ": ";
		    it->second.print(os);
		    os << std::endl;
		}
	    }
	    unsigned depthOf (const TTerm* t) const {
		ObjectOf::const_iterator it = find(t);
		return it == end() ? 0 : it->second.root.depth;
	    }
	};

	struct DepthTriple {
	    unsigned depth;
	    const TriplePattern* triple;
	    const ObjectOf& oo;
	    AtomFactory* atomFactory;
	    DepthTriple(const TriplePattern* triple, const ObjectOf& oo, AtomFactory* atomFactory)
		: depth(oo.depthOf(triple->getS())), triple(triple), oo(oo), atomFactory(atomFactory) {  }
	    bool operator< (const DepthTriple& ref) const {
		if (depth != ref.depth)
		    return depth < ref.depth;
		return triple < ref.triple;
	    }
	};

	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const ProductionVector<const TriplePattern*>* p_TriplePatterns, BasicGraphPattern* p) {
	    /*
	     * A → B   D
	     * ↓ ↖ ↓   ↓
	     * F   C → E
	     */
	    ObjectOf work;
	    std::set<const TTerm*> subjects;
	    size_t pendingLeads = 0;

	    for (std::vector<const TriplePattern*>::const_iterator t = p_TriplePatterns->begin();
		 t != p_TriplePatterns->end(); ++t) {
		work[(*t)->getO()].leads[(*t)->getS()] = 1;
		++pendingLeads;
		subjects.erase((*t)->getO());
		if (work.find((*t)->getS()) == work.end())
		    subjects.insert((*t)->getS());
		/* !!! <s> <p> <s> . */
	    }

	    /* A: C
	     * B: A
	     * F: A|C
	     * C: B
	     * E: C+D
	     */
	    for (unsigned gen = 1; pendingLeads > 0 && gen < 5; ++gen) {
		pendingLeads = 0;
		// work.print(std::cerr);
		for (ObjectOf::iterator oo = work.begin();
		     oo != work.end(); ) {
		    /* A		 * B		 * F		 * C		 * E		 */
		    const TTerm* goal = oo->first;
		    // std::cerr << *goal;

		    std::map<const TTerm*, unsigned> nextLeads;
		    Root candidateRoot;
		    /* (C)		 * (A)		 * (AC)		 * (B)		 * (CD)		 */
		    for (std::map<const TTerm*, unsigned>::const_iterator leads = oo->second.leads.begin();
			 leads != oo->second.leads.end(); ++leads) {
			const TTerm* lead = leads->first;
			unsigned curDistance = leads->second;
			ObjectOf::const_iterator follow = work.find(lead);
			oo->second.touched[lead] = gen;
			if (follow == work.end()) {
			    // std::cerr << " finished with " << *lead << " in " << gen << " generations\n";
			    candidateRoot.consider(lead, gen);
			} else {
			    /* C:1		 * A:1		 * A:1,C:1	 * B:1		 * C:1,D:1	 */
			    // if (leads != oo->second.leads.begin())
			    //     std::cerr << "   ";
			    // std::cerr << " following " << *lead << " to (";
			    /* (B)		 * (A)		 * (AC)		 * (B)		 * (CD)		 */
			    for (std::map<const TTerm*, unsigned>::const_iterator followLead = follow->second.leads.begin();
				 followLead != follow->second.leads.end(); ++followLead) {
				const TTerm* gp = followLead->first;
				unsigned nextDepth = curDistance + followLead->second;
				if (gp == goal) {
				    // std::cerr << "!";
				    oo->second.touched[gp] = nextDepth;
				    candidateRoot.consider(gp, nextDepth);
				} else
				    nextLeads[gp] = nextDepth;
				// std::cerr << *gp << "@" << curDistance + followLead->second;
			    }
			    if (follow->second.leads.size() == 0 && follow->second.root.peers.size() > 0 && nextLeads.size() == 0) {
				Root followedRoot(follow->second.root);
				++followedRoot.depth;
				candidateRoot.consider(followedRoot);
			    }
			    for (std::map<const TTerm*, unsigned>::const_iterator t = follow->second.touched.begin();
				 t != follow->second.touched.end(); ++t)
				if (oo->second.touched.find(t->first) != oo->second.touched.end()) {
				    std::stringstream ss;
				    // ss << t->first->toString() << "[" << oo->second.touched[t->first] << "]/" << t->first->toString() << "[" << t->second + gen << "] ";
				    // std::cerr << ss.str();
				} else {
				    if (t->first == goal) {
					// std::cerr << "^";
					candidateRoot.consider(t->first, t->second + gen);
				    }
				    oo->second.touched[t->first] = t->second + gen;
				}
			    // std::cerr << ")" << std::endl;
			}
		    }
		    if (nextLeads.size() == 0 && candidateRoot.peers.size() > 0)
			oo->second.root.consider(candidateRoot);
		    oo->second.leads = nextLeads;
		    pendingLeads += nextLeads.size();
		    // std::cerr << *goal << "-";
		    // oo->second.print(std::cerr);
		    // std::cerr << std::endl;
		    ++oo;
		}
	    }
	    // work.print(std::cerr);

	    std::set<DepthTriple> ordered; // @@@ would like const DepthTriple
	    for (std::vector<const TriplePattern*>::const_iterator t = p_TriplePatterns->begin();
		 t != p_TriplePatterns->end(); ++t) {
		const DepthTriple dt(*t, work, atomFactory);
		ordered.insert(dt);
		//	    *ret += (*t)->copy();
	    }
	    for (std::set<DepthTriple>::const_iterator it = ordered.begin();
		 it != ordered.end(); ++it)
		p->addTriplePattern(it->triple);
	}

	struct TableOperationSorter {

	    typedef enum { DT_Err, DT_DefaultGraphPattern, DT_NamedGraphPattern, 
			   DT_GraphGraphPattern, DT_ServiceGraphPattern,
			   DT_TableConjunction, DT_TableDisjunction,
			   DT_Filter, DT_OptionalGraphPattern,
			   DT_MinusGraphPattern} DT_TableOperationSortOrder;

	    AtomFactory* atomFactory;
	    TableOperationSorter (AtomFactory* atomFactory)
		: atomFactory(atomFactory) {  }
	    struct OperationSorter : public RecursiveExpressor {
		struct RHSslave : public RecursiveExpressor {
		    AtomFactory* atomFactory;
		    e_SORT ret;
		    RHSslave (AtomFactory* atomFactory) : atomFactory(atomFactory), ret(SORT_error) {  }
		    virtual void base (const Base* const, std::string) { throw "OperationSorter::RHSslave::base should not be called.";}
		    virtual void defaultGraphPattern(const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
		    virtual void namedGraphPattern(const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) = 0;
		    virtual void graphGraphPattern(const GraphGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) = 0;
		    virtual void serviceGraphPattern(const ServiceGraphPattern* const self, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) = 0;
		    virtual void optionalGraphPattern(const OptionalGraphPattern* const self, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) = 0;
		    virtual void minusGraphPattern(const MinusGraphPattern* const self, const TableOperation* p_GroupGraphPattern) = 0;
		    virtual void filter(const Filter* const self, const TableOperation* p_op, const ProductionVector<const w3c_sw::Expression*>* p_Constraints) = 0;
		    virtual void tableConjunction(const TableConjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
		    virtual void tableDisjunction(const TableDisjunction* const self, const ProductionVector<const TableOperation*>* p_TableOperations) = 0;
		    virtual void operationSet(const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) = 0;
		};

		/* BasicGraphPattern-derived types: DefaultGraphPattern, NamedGraphPattern */
		struct _BasicGraphPattern : public RHSslave {
		    const ProductionVector<const TriplePattern*>* lhs;
		    _BasicGraphPattern (AtomFactory* atomFactory, const ProductionVector<const TriplePattern*>* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    e_SORT _basicGraphPattern (const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
			std::vector<const TriplePattern*>::const_iterator ltriple = lhs->begin();
			std::vector<const TriplePattern*>::const_iterator rtriple = p_TriplePatterns->begin();
			while (ltriple != lhs->end() && rtriple != p_TriplePatterns->end()) {
			    if (*ltriple != *rtriple)
				return (*ltriple)->safeCmp(**rtriple);
			    ++ltriple;
			    ++rtriple;
			}
			return SORT_eq;
		    }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_lt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_lt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>*) { ret = SORT_lt; }
		};
		struct RHS_defaultGraphPattern : public _BasicGraphPattern {
		    bool l_allOpts;
		    RHS_defaultGraphPattern (AtomFactory* atomFactory, bool l_allOpts, const ProductionVector<const TriplePattern*>* l_TriplePatterns)
			: _BasicGraphPattern(atomFactory, l_TriplePatterns), l_allOpts(l_allOpts) {  }
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
			ret = _basicGraphPattern(p_TriplePatterns);
		    }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_lt; }
		};
		struct RHS_namedGraphPattern : public _BasicGraphPattern {
		    const TTerm* l_name;
		    bool l_allOpts;
		    RHS_namedGraphPattern (AtomFactory* atomFactory, const TTerm* l_name, bool l_allOpts, const ProductionVector<const TriplePattern*>* l_TriplePatterns)
			: _BasicGraphPattern(atomFactory, l_TriplePatterns), l_name(l_name), l_allOpts(l_allOpts) {  }
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
			ret = l_name != p_name ? TTerm::cmp(l_name, p_name) : _basicGraphPattern(p_TriplePatterns);
		    }
		};


		/* TableOperationOnOperation-derived types: Filter ServiceGraphPattern GraphGraphPattern OptionalGraphPattern MinusGraphPattern */
		struct _TableOperationOnOperation : public RHSslave {
		    const TableOperation* lhs;
		    _TableOperationOnOperation (AtomFactory* atomFactory, const TableOperation* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    e_SORT _tableOperationOnOperation(const TableOperation* p_TableOperation);
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }

		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>*) { ret = SORT_lt; }
		};
		struct RHS_graphGraphPattern : public _TableOperationOnOperation {
		    const TTerm* l_TTerm;
		    RHS_graphGraphPattern (AtomFactory* atomFactory, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_TTerm(p_TTerm) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
			ret = l_TTerm != p_TTerm ? TTerm::cmp(l_TTerm, p_TTerm) : _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_lt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_serviceGraphPattern : public _TableOperationOnOperation {
		    const TTerm* l_TTerm;
		    RHS_serviceGraphPattern (AtomFactory* atomFactory, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, bool)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_TTerm(p_TTerm) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory*, bool) {
			ret = l_TTerm != p_TTerm ? TTerm::cmp(l_TTerm, p_TTerm) : _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_optionalGraphPattern : public _TableOperationOnOperation {
		    const ProductionVector<const w3c_sw::Expression*>* l_Expressions;
		    RHS_optionalGraphPattern (AtomFactory* atomFactory, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_Expressions(p_Expressions) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>*) {
			// !!! ret = l_Expressions != p_TTerm ? atomFactory->cmp(l_Expressions, p_TTerm) : 
			ret = _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_lt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_minusGraphPattern : public _TableOperationOnOperation {
		    RHS_minusGraphPattern (AtomFactory* atomFactory, const TableOperation* p_GroupGraphPattern)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
			ret = _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_lt; }
		};
		struct RHS_filter : public _TableOperationOnOperation {
		    const ProductionVector<const w3c_sw::Expression*>* l_Expressions;
		    RHS_filter (AtomFactory* atomFactory, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions)
			: _TableOperationOnOperation(atomFactory, p_GroupGraphPattern), l_Expressions(p_Expressions) {  }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_gt; }
		    virtual void filter (const Filter* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>*) {
			// !!! ret = l_Expressions != p_TTerm ? atomFactory->cmp(l_Expressions, p_TTerm) : 
			ret = _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		};

		/* TableJunction-derived types: TableConjunction, TableDisjunction */
		struct _TableJunction : public RHSslave {
		    const ProductionVector<const TableOperation*>* lhs;
		    _TableJunction (AtomFactory* atomFactory, const ProductionVector<const TableOperation*>* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    e_SORT _tableJunction(const ProductionVector<const TableOperation*>* p_TableOperations);
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_gt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }

		    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>*) { ret = SORT_lt; }
		};
		struct RHS_tableConjunction : public _TableJunction {
		    RHS_tableConjunction (AtomFactory* atomFactory, const ProductionVector<const TableOperation*>* p_TableOperations)
			: _TableJunction(atomFactory, p_TableOperations) {  }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
			ret = _tableJunction(p_TableOperations);
		    }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		};
		struct RHS_tableDisjunction : public _TableJunction {
		    RHS_tableDisjunction (AtomFactory* atomFactory, const ProductionVector<const TableOperation*>* p_TableOperations)
			: _TableJunction(atomFactory, p_TableOperations) {  }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_gt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
			ret = _tableJunction(p_TableOperations);
		    }
		};

		struct RHS_operationSet : public RHSslave {
		    const ProductionVector<const Operation*>* lhs;
		    RHS_operationSet (AtomFactory* atomFactory, const ProductionVector<const Operation*>* lhs)
			: RHSslave(atomFactory), lhs(lhs) {  }
		    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm*, bool, const ProductionVector<const TriplePattern*>*) { ret = SORT_gt; }
		    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm*, const TableOperation*) { ret = SORT_gt; }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm*, const TableOperation*, AtomFactory*, bool) { ret = SORT_gt; }
		    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation*) { ret = SORT_gt; }
		    virtual void filter (const Filter* const, const TableOperation*, const ProductionVector<const w3c_sw::Expression*>*) { ret = SORT_gt; }
		    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>*) { ret = SORT_lt; }
		    virtual void operationSet(const OperationSet* const, const ProductionVector<const Operation*>*);
		};
		/* END of slave sorters */


		AtomFactory* atomFactory;
		const TableOperation* rhs;
		e_SORT ret;
		OperationSorter (AtomFactory* atomFactory, const TableOperation* rhs)
		    : atomFactory(atomFactory), rhs(rhs), ret(SORT_error) {  }
		virtual void base (const Base* const, std::string) { throw "OperationSorter::base should not be called.";}
		virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		    RHS_defaultGraphPattern slave(atomFactory, p_allOpts, p_TriplePatterns);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		    RHS_namedGraphPattern slave(atomFactory, p_name, p_allOpts, p_TriplePatterns);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
		    RHS_graphGraphPattern slave(atomFactory, p_TTerm, p_GroupGraphPattern);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) {
		    RHS_serviceGraphPattern slave(atomFactory, p_TTerm, p_GroupGraphPattern, lexicalCompare);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
		    RHS_optionalGraphPattern slave(atomFactory, p_GroupGraphPattern, p_Expressions);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
		    RHS_minusGraphPattern slave(atomFactory, p_GroupGraphPattern);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void filter (const Filter* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Constraints) {
		    RHS_filter slave(atomFactory, p_GroupGraphPattern, p_Constraints);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
		    RHS_tableConjunction slave(atomFactory, p_TableOperations);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
		    RHS_tableDisjunction slave(atomFactory, p_TableOperations);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
		    RHS_operationSet slave(atomFactory, p_Operations);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		
	    };
	    bool operator () (const TableOperation* lhs, const TableOperation* rhs) {
		OperationSorter os(atomFactory, rhs);
		lhs->express(&os);
		return os.ret == SORT_lt;
	    }
	};


	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (const ProductionVector<const TableOperation*>* p_TableOperations, TableJunction* j) {
	    ProductionVector<const TableOperation*> ops;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
	    	 it != p_TableOperations->end(); it++) {
	    	(*it)->express(this);
	    	ops.push_back(last.tableOperation);
	    }
	    std::sort(ops.begin(), ops.end(), TableOperationSorter(atomFactory));
	    for (std::vector<const TableOperation*>::const_iterator it = ops.begin();
	    	 it != ops.end(); it++)
		j->addTableOperation(*it, false);
	    ops.clear(); // don't delete members.
	}
    };

inline e_SORT SWObjectCanonicalizer::TableOperationSorter::OperationSorter::_TableOperationOnOperation::_tableOperationOnOperation (const TableOperation* p_TableOperation) {
    OperationSorter s(atomFactory, lhs);
    p_TableOperation->express(&s);
    return s.ret;
}

inline e_SORT SWObjectCanonicalizer::TableOperationSorter::OperationSorter::_TableJunction::_tableJunction (const ProductionVector<const TableOperation*>* p_TableOperations) {
    std::vector<const TableOperation*>::const_iterator lop = lhs->begin();
    std::vector<const TableOperation*>::const_iterator rop = p_TableOperations->begin();
    while (lop != lhs->end() && rop != p_TableOperations->end()) {
	OperationSorter s(atomFactory, *lop);
	(*rop)->express(&s);
	if (s.ret != SORT_eq)
	    return s.ret;
	++lop;
	++rop;
    }
    return SORT_eq;
}

inline void SWObjectCanonicalizer::TableOperationSorter::OperationSorter::RHS_operationSet::operationSet(const OperationSet* const, const ProductionVector<const Operation*>*) {
    w3c_sw_NEED_IMPL("extend sorter to sort Operations");
}


struct RuleMapTest {
    bool (*bgpMappableTerm)(const TTerm*);
    const Operation* transformed;
    const Operation* mapResults;
    const Operation* transformedNorm;
    const Operation* mapResultsNorm;

    RuleMapTest (const char* queryFile, const char* mapFile, 
		 const char* mapResultsFile,
		 IStreamContext::e_opts type = IStreamContext::FILE) :
	bgpMappableTerm(BasicGraphPattern::MappableTerm) {

	/* Parse query. */
	IStreamContext qstr(queryFile, type);
	if (sparqlParser.parse(qstr)) {
	    std::string msg = std::string("failed to parse query \"") + 
		queryFile + std::string("\".");
	    throw msg;
	}
	Operation* query = sparqlParser.root;

	/* Parse map. */
	IStreamContext mstr(mapFile, type);
	if (mapSetParser.parse(mstr)) {
	    std::string msg = std::string("failed to parse map \"") + 
		mapFile + std::string("\".");
	    throw msg;
	}
	MapSet* ms = mapSetParser.root;
	queryMapper.sharedVars = ms->sharedVars;
	for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
	     it != ms->maps.end(); ++it)
	    queryMapper.addRule(it->constr, it->label);
	queryMapper.nodeShare = ms->nodeShare;
	delete mapSetParser.root;

	try {
	    transformed = queryMapper.map(query);
	} catch (RuleMatchingException e) { // !! should catch whatever
	    delete query;
	    queryMapper.clear();
	    //std::string m(e.what());
	    //throw m;
	    throw e;
	}
	delete query;
	transformedNorm = canonicalize(transformed);

	/* Parse map results. */
	IStreamContext rstr(mapResultsFile, type);
	if (sparqlParser.parse(rstr)) {
	    std::string msg = std::string("failed to parse map results \"") + 
		mapResultsFile + std::string("\".");
	    throw msg;
	}
	mapResults = sparqlParser.root;
	mapResultsNorm = canonicalize(mapResults);

	BasicGraphPattern::MappableTerm = &BasicGraphPattern::MapVarsAndBNodes;
    }
    const Operation* canonicalize (const Operation* op) {
	SWObjectCanonicalizer canon(&f);
	op->express(&canon);
	return canon.last.operation;
    }
    ~RuleMapTest () {
	BasicGraphPattern::MappableTerm = bgpMappableTerm;
	queryMapper.clear();
	delete mapResults;
	delete transformed;
	delete mapResultsNorm;
	delete transformedNorm;
    }
};

struct SQLizerTest {
    //std::iostream* sqlErrorStream;
    sqlContext context;
    SQLDriver sqlParser;
    sql::SQLQuery* transformed;
    sql::SQLQuery* ref;
    Operation* deleteOperation;
    SQLizerTest (const char* queryFile, 
		 const char* stemURI, const char* sqlResultsFile)
	: sqlParser(context), deleteOperation(NULL)
	//: sqlErrorStream(SQLizer::ErrorStream)
    {
	//SQLizer::ErrorStream = &std::cerr;
	IStreamContext qstr(queryFile, IStreamContext::FILE);
	if (sparqlParser.parse(qstr)) {
	    std::string msg = std::string("failed to parse query \"") + 
		queryFile + std::string("\".");
	    throw msg;
	}
	deleteOperation = sparqlParser.root;
	_init(deleteOperation, stemURI, sqlResultsFile);
    }
    SQLizerTest (const Operation* sparqlQuery, 
		 const char* stemURI, const char* sqlResultsFile)
	: sqlParser(context), deleteOperation(NULL)
	//: sqlErrorStream(SQLizer::ErrorStream)
    { _init(sparqlQuery, stemURI, sqlResultsFile); }
    void _init (const Operation* sparqlQuery, 
		const char* stemURI, const char* sqlResultsFile)
    {
	//SQLizer::ErrorStream = &std::cerr;

	/* map SPARQLquery to SQL. */
	char predicateDelims[]={'#',' ',' '};
	char nodeDelims[]={'/','.',' '};
	SQLizer s(stemURI, predicateDelims, nodeDelims, "id", KeyMap(), &DebugStream);
	sparqlQuery->express(&s);
	IStreamContext generated(s.getSQLstring(), IStreamContext::STRING);
	try {
	    BOOST_CHECK_EQUAL(0, sqlParser.parse(generated));
	    transformed = sqlParser.root;
	    //std::cout << s.getSQLstring() << endl;

	    /* Read reference SQL. */
	    IStreamContext parsed(sqlResultsFile, IStreamContext::FILE);
	    try {
		BOOST_CHECK_EQUAL(0, sqlParser.parse(parsed));
		ref = sqlParser.root;
	    } catch (std::string e) {
		std::cerr << e;
		ref = NULL;
	    }
	} catch (std::string e) {
	    std::cerr << e;
	    transformed = NULL;
	}
    }
    ~SQLizerTest () {
	delete transformed;
	delete ref;
	//SQLizer::ErrorStream = sqlErrorStream;
    }
};

BOOST_AUTO_TEST_SUITE( healthCare )
    BOOST_AUTO_TEST_SUITE( simple )
	BOOST_AUTO_TEST_CASE( order ) {
	    RuleMapTest t("SELECT * { ?q1 <p2> ?q2 ; <p3> ?q3 }",
			  "'p2' CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S2> { ?rs <p2> ?ro } }\n"
			  "'p3' CONSTRUCT { ?rs <p3> ?ro } { SERVICE <S3> { ?rs <p3> ?ro } }",
			  "SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			  "           SERVICE <S3> { ?qs <p3> ?qo } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}

#if PARSER_BUG && SERVICE_MERGING
	BOOST_AUTO_TEST_CASE( by_P_by_S ) {
	    RuleMapTest t("SELECT * { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town}",
			  "'presidents' CONSTRUCT { ?pres <inauguration> ?inaug ; <impeachment> ?inpech } { SERVICE <presidents> { ?pres <inauguration> ?inaug ; <impeachment> ?inpech } }\n"
			  "'nixonzpage' CONSTRUCT { <nixon> ?p ?o } { SERVICE <nixonzpage> { <nixon> ?p ?o } }",
			  "SELECT * { { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech }\n"
			  "             SERVICE <nixonzpage> { <nixon> <hometown> ?town } }\n"
			  "           UNION\n"
			  "           { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?_presidents_1_inpech }\n"
			  "             SERVICE <nixonzpage> { <nixon> <impeachment> ?impech ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "           { SERVICE <presidents> { <nixon> <inauguration> ?_presidents_2_inaug ; <impeachment> ?impech }\n"
			  "             SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "           { SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town } } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
#endif /* PARSER_BUG && SERVICE_MERGING */

#if PARSER_BUG && SERVICE_MERGING
	BOOST_AUTO_TEST_CASE( by_P_by_S_msr ) {
	    RuleMapTest t("SELECT * { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town}",
			  "'inaug'      CONSTRUCT { ?pres <inauguration> ?inaug } { SERVICE <presidents> { ?pres <inauguration> ?inaug } }\n"
			  "'impeach'    CONSTRUCT { ?pres <impeachment> ?inpech } { SERVICE <presidents> { ?pres <impeachment> ?inpech } }\n"
			  "'nixonzpage' CONSTRUCT { <nixon> ?p ?o } { SERVICE <nixonzpage> { <nixon> ?p ?o } }",
			  "SELECT * { { SERVICE <presidents> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech }\n"
			  "               SERVICE <nixonzpage> { <nixon> <hometown> ?town } }\n"
			  "           UNION\n"
			  "             { SERVICE <presidents> { <nixon> <inauguration> ?inaug }\n"
			  "               SERVICE <nixonzpage> { <nixon> <impeachment> ?impech ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "             { SERVICE <presidents> { <nixon> <impeachment> ?impech }\n"
			  "               SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <hometown> ?town } }\n"
			  "           UNION\n"
			  "             { SERVICE <nixonzpage> { <nixon> <inauguration> ?inaug ; <impeachment> ?impech ; <hometown> ?town } } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
#endif /* PARSER_BUG && SERVICE_MERGING */

	BOOST_AUTO_TEST_CASE( p1_p2 ) {
	    RuleMapTest t("SELECT * { ?qs <p2> ?qo }",
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro }",
			  "SELECT * { ?qs <p1> ?qo }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( p01_p2 ) {
	    RuleMapTest t("SELECT * { ?qs <p2> ?qo }",
			  "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro ; <p0> 'x' }",
			  "SELECT * { ?qs <p1> ?qo ; <p0> 'x' }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( p3 ) {
	    BOOST_CHECK_THROW
		(RuleMapTest("SELECT * { ?qs <p3> ?qo }",
			     "CONSTRUCT { ?rs <p2> ?ro } { ?rs <p1> ?ro }",
			     "",
			     IStreamContext::STRING),
		 RuleMatchingException);
	}
	BOOST_AUTO_TEST_CASE( p1_S1_p2 ) {
	    RuleMapTest t("SELECT * { ?qs <p2> ?qo }",
			  "'p1_S1_p2' CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S1> { ?rs <p1> ?ro } }",
			  "SELECT * { SERVICE <S1> { ?qs <p1> ?qo } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( p1_S2_p2_S3_p3 ) {
	    RuleMapTest t("SELECT * { ?q1 <p2> ?q2 ; <p3> ?q3}",
			  "CONSTRUCT { ?rs <p2> ?ro } { SERVICE <S2> { ?rs <p2> ?ro } }\n"
			  "CONSTRUCT { ?rs <p3> ?ro } { SERVICE <S3> { ?rs <p3> ?ro } }",
			  "SELECT * { SERVICE <S2> { ?qs <p2> ?qo }\n"
			  "           SERVICE <S3> { ?qs <p3> ?qo } }",
			  IStreamContext::STRING);
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( hl7_sdtm ) {
	    RuleMapTest t("healthCare/simple/sdtm.rq", "healthCare/simple/hl7-sdtm.rq", "healthCare/simple/hl7.rq");
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
	BOOST_AUTO_TEST_CASE( sdtm_db ) { // !! leaky
	    RuleMapTest t("healthCare/simple/hl7.rq", "healthCare/simple/db-hl7.rq", "healthCare/simple/db.rq");
	    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
		std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
		BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	    SQLizerTest s(t.mapResults, "http://hospital.example/DB/", "healthCare/simple/db.sql");
	    BOOST_CHECK_EQUAL(*s.transformed, *s.ref);
	}
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE( notBound )
	BOOST_AUTO_TEST_CASE( lists_notBound ) {
	    RuleMapTest t("healthCare/lists-notBound/hl7.rq", "healthCare/lists-notBound/db-hl7.rq", "healthCare/lists-notBound/db.rq");
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	    SQLizerTest s(t.mapResults, "http://hospital.example/DB/", "healthCare/lists-notBound/db.sql");
	    BOOST_CHECK_EQUAL(*s.transformed, *s.ref);
        }
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE( cabig )
	BOOST_AUTO_TEST_CASE( bg_hl7 ) {
	    RuleMapTest t("healthCare/cabig/twoWayBGQuery.rq", "healthCare/cabig/twoWayHL7-BGMap.rq", "healthCare/cabig/twoWayHL7Query.rq");
	    BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
	}
    BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()

#if 0
BOOST_AUTO_TEST_CASE( refree ) { // !! leaky
    namespace tst = boost::unit_test::framework;
    std::string stem = "http://someClinic.exampe/DB/";
    for (int i = 1; i < tst::master_test_suite().argc; ++i) {
	std::string s = tst::master_test_suite().argv[i];
	if (s.find_first_of("stem=") == 0)
	    stem = s.substr(5, s.size()-5);
    }
    SQLizerTest s("toy.rq", stem.c_str(), "healthCare/simple/db.sql");
    BOOST_CHECK_EQUAL(s.transformed, s.ref);
}

BOOST_AUTO_TEST_CASE( bsbm_1 ) {
    RuleMapTest t("bsbm/q1.rq", "bsbm/ruleMap.rq", "bsbm/q1-db.rq");
    if (boost::unit_test::framework::master_test_suite().argc > 1 && 
	std::string("all") == boost::unit_test::framework::master_test_suite().argv[1])
	BOOST_CHECK_EQUAL(*t.transformedNorm, *t.mapResultsNorm);
}
#endif

