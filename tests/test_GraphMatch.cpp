/* test graph-matching.
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE GraphMatch

#include <map>
#include <vector>
#include "SWObjects.hpp"
#include "ResultSet.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>

using namespace w3c_sw;

AtomFactory f;

/* Intermediate structures to make it easier to create ResultSets.
 * usage:
	B _r1[] = {B("?n1", "<n11>"), B("?n2", "<n12>")}; R r1 = row(_r1);
	B _r2[] = {B("?n1", "<n21>"), B("?n2", "<n22>"), B("?n3", "<n23>")}; R r2 = row(_r2);
	R rows[] = { r1, r2 };
	ResultSet rs = RS(rows);
	std::cout << rs.toString();

 * TODO: can we do a c++0x thing like this:? {map<string, int> stuff {{"one",1}, {"two",2},{"three",3}}; cout <<stuff;}
 */
struct B {
    std::string bound;
    std::string to;
    B (std::string b, std::string t) : bound(b), to(t) {  }
};
struct R {
    B* bindings;
    int count;
    R (B bindings[], int count) : bindings(bindings), count(count) {  }
};
#define row(X) R(X, sizeof(X)/sizeof(X[0]))
#define RS(X, M) makeResultSet(X, sizeof(X)/sizeof(X[0]), M)

ResultSet makeResultSet (R rows[], int count, TTerm::String2BNode& bnodeMap) {
    ResultSet rs(&f);
    delete *(rs.begin());
    rs.erase(rs.begin());
    for (int i = 0; i < count; ++i) {
	Result* r = new Result(&rs);
	rs.insert(rs.end(), r);
	B* bindings = rows[i].bindings;
	for (int j = 0; j < rows[i].count; ++j)
	    rs.set(r, f.getTTerm(bindings[j].bound, bnodeMap), 
		   f.getTTerm(bindings[j].to, bnodeMap), false);
    }
    return rs;
}

#if REGEX_LIB == SWOb_DISABLED
#warning REGEX needed for bgp tests.
#else /* ! REGEX_LIB != SWOb_DISABLED */

BOOST_AUTO_TEST_CASE( bgp ) {
    DefaultGraphPattern data, pattern;
    TTerm::String2BNode bnodeMap;
    data.addTriplePattern(f.getTriple("<n1> <p1> <n2> .", bnodeMap));

    /* Verify NTriples input, which will be used in remaining tests. */ {
	DefaultGraphPattern d2;
	d2.addTriplePattern(f.getTriple("<n1>", "<p1>", "<n2>", bnodeMap));
	BOOST_REQUIRE(data.size() == 1);
	BOOST_REQUIRE(data == d2);
    }

    pattern.addTriplePattern(f.getTriple("?n1", "<p1>", "_:n2", bnodeMap));

    /* 1 datum, 1 pattern */ {
	B _bz1[] = {B("?n1", "<n1>"), B("_:n2", "<n2>")}; R r1 = row(_bz1);
	R rows[] = { r1 };
	ResultSet ref = RS(rows, bnodeMap);

	ResultSet expected(&f, 
			   "?n1  _:n2\n"
			   "<n1> <n2>", false, bnodeMap);

	BOOST_CHECK_EQUAL(RS(rows, bnodeMap), expected);

	ResultSet r(&f);
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, expected);
    }

    /* Redundant triples don't change BGP size. */ {
	data.addTriplePattern(f.getTriple("<n1> <p1> <n2> .", bnodeMap));
	BOOST_CHECK_EQUAL(data.size(), (size_t)1);
    }

    /* parseTriples */ {
	f.parseNTPatterns(&data, 
			  "<n1> <p1> \"l1\" ."
			  "<n2> <p1> <n3> .", bnodeMap);
	BOOST_CHECK_EQUAL(data.size(), (size_t)3);

	ResultSet r(&f);
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, ResultSet(&f, 
				       "?n1  _:n2\n"
				       "<n1> <n2>\n"
				       "<n1> \"l1\"\n"
				       "<n2> <n3>",
				       false, bnodeMap));
    }

    pattern.addTriplePattern(f.getTriple("_:n2 <p1> ?n3 .", bnodeMap));

    {
	ResultSet r(&f);
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, ResultSet(&f, 
				       "?n1  _:n2 ?n3 \n"
				       "<n1> <n2> <n3>",
				       false, bnodeMap));
    }

    data.addTriplePattern(f.getTriple("<n2> <p1> <n4> .", bnodeMap));

    /* <n1> <p1> <n2> . <n2> <p1> <n3>,<n4> . */ {
	ResultSet r(&f);
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, ResultSet(&f, 
				       "?n1  _:n2 ?n3 \n"
				       "<n1> <n2> <n3>\n"
				       "<n1> <n2> <n4>",
				       false, bnodeMap));
    }

    /* Test a subset of BSBM q1. */ {
	DefaultGraphPattern d;
	f.parseNTPatterns(&d, 
			  "?product     <label>   ?label ."
			  "?product     <feature> <feature1> ."
			  "?product     <feature> \"feature2\" .", bnodeMap);
	DefaultGraphPattern p;
	f.parseNTPatterns(&p, 
			  "?ruleProduct <label>   ?ruleLabel ."
			  "?ruleProduct <feature> ?ruleFeature .", bnodeMap);
	ResultSet tested(&f);
	d.BasicGraphPattern::bindVariables(&tested, NULL, &p, NULL);
	ResultSet expected(&f, 
			   "?ruleProduct ?ruleLabel ?ruleFeature \n"
			   "?product     ?label     <feature1> \n"
			   "?product     ?label     \"feature2\"",
			   false, bnodeMap);
	BOOST_CHECK_EQUAL(tested, expected);
    }

}

BOOST_AUTO_TEST_CASE( RSNoCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSNoCoRefsReversedL ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1 _:b1 _:c1\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSNoCoRefsReversedR ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1 _:b1 _:c1\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSCoRefInLeft ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:b2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}

BOOST_AUTO_TEST_CASE( RSCoRefInRight ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:b2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}

BOOST_AUTO_TEST_CASE( RSCoRefInBoth ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:a2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:b2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}

BOOST_AUTO_TEST_CASE( RSConstsNoCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2   2  _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1 _:c1\n"
		"_:a2   2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSConstsNoCoRefsReversedL ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2   2  _:c2\n"
		"_:a1   1  _:c1\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1 _:c1\n"
		"_:a2   2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSConstsNoCoRefsReversedR ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2   2  _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a2   2 _:c2\n"
		"_:a1   1 _:c1\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSConstsNoCoRefsReversedLR ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2   2  _:c2\n"
		"_:a1   1  _:c1\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a2   2 _:c2\n"
		"_:a1   1 _:c1\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSConstCoRef ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:a2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2 _:b2 _:a2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}

BOOST_AUTO_TEST_CASE( RSOneConstNoCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSOneConstNoCoRefsReversedL ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1   1  _:c1\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSOneConstNoCoRefsReversedR ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b    ?c\n"
		"_:a1   1   _:c1\n"
		"_:a2 _:b2  _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1   1  _:c1\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSOneConstNoCoRefsReversedLR ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2  _:c2\n"
		"_:a1   1   _:c1\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1   1  _:c1\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSOneConstOneCoRef ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2   1  _:a2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}

BOOST_AUTO_TEST_CASE( RSDifferentConstCoRef ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a1   1  _:c1\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"_:a1 _:b1 _:c1\n"
		"_:a2   2  _:a2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}

BOOST_AUTO_TEST_CASE( RSLongOrderedNoCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"  1 \"two\" <thr>\n"
		"_:a1 _:b1 _:c1\n"
		"  4 \"fve\" <six>\n"
		"_:a2 _:b2 _:c2\n"
		"  7 \"ate\" <nyn>\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"  1 \"two\" <thr>\n"
		"_:a1 _:b1 _:c1\n"
		"  4 \"fve\" <six>\n"
		"_:a2 _:b2 _:c2\n"
		"  7 \"ate\" <nyn>\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSLongUnorderedNoCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1 _:b1 _:c1\n"
		"  4 \"fve\" <six>\n"
		"  1 \"two\" <thr>\n"
		"  7 \"ate\" <nyn>\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"  7 \"ate\" <nyn>\n"
		"  1 \"two\" <thr>\n"
		"_:a1 _:b1 _:c1\n"
		"  4 \"fve\" <six>\n"
		"_:a2 _:b2 _:c2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSLongUnorderedCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1 _:b1 _:a1\n"
		"  4 \"fve\" <six>\n"
		"  1 \"two\" <thr>\n"
		"  7 \"ate\" <nyn>\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"  7 \"ate\" <nyn>\n"
		"  1 \"two\" <thr>\n"
		"_:a1 _:b1 _:c1\n"
		"  4 \"fve\" <six>\n"
		"_:a2 _:b2 _:a2\n",
		false, bnodeMap);
    BOOST_CHECK_EQUAL(l, r);
}

BOOST_AUTO_TEST_CASE( RSLongUnorderedMisCoRefs ) {
    TTerm::String2BNode bnodeMap;
    ResultSet l(&f, 
		" ?a   ?b   ?c\n"
		"_:a2 _:b2 _:c2\n"
		"_:a1 _:b1 _:a1\n"
		"  4 \"fve\" <six>\n"
		"  1 \"two\" <thr>\n"
		"  7 \"ate\" <nyn>\n",
		false, bnodeMap);
    ResultSet r(&f, 
		" ?a   ?b   ?c\n"
		"  7 \"ate\" <nyn>\n"
		"  1 \"two\" <thr>\n"
		"_:a1 _:b1 _:c1\n"
		"  4 \"fve\" <six>\n"
		"_:a2 _:b2 _:b2\n",
		false, bnodeMap);
    BOOST_CHECK_MESSAGE(!(l == r), l.toString() + " == " + r.toString());
}


#endif /* ! REGEX_LIB != SWOb_DISABLED */

