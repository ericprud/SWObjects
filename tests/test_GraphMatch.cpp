/* test graph-matching.
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_DYN_LINK 1
#define BOOST_TEST_MODULE GraphMatch
#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

#include <map>
#include <vector>
#include "SWObjects.hpp"
#include "ResultSet.hpp"

using namespace w3c_sw;

POSFactory f;

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

ResultSet makeResultSet (R rows[], int count, POS::String2BNode& bnodeMap) {
    ResultSet rs(&f);
    rs.erase(rs.begin());
    for (int i = 0; i < count; ++i) {
	Result* r = new Result(&rs);
	rs.insert(rs.end(), r);
	B* bindings = rows[i].bindings;
	for (int j = 0; j < rows[i].count; ++j)
	    rs.set(r, f.getPOS(bindings[j].bound, bnodeMap), 
		   f.getPOS(bindings[j].to, bnodeMap), false);
    }
    return rs;
}

#if REGEX_LIB == SWOb_DISABLED
#warning REGEX needed for bgp tests.
#else /* ! REGEX_LIB != SWOb_DISABLED */

BOOST_AUTO_TEST_CASE( bgp ) {
    DefaultGraphPattern data, pattern;
    POS::String2BNode bnodeMap;
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
	BOOST_CHECK_EQUAL(data.size(), 1);
    }

    /* parseTriples */ {
	f.parseTriples(&data, 
		       "<n1> <p1> \"l1\" ."
		       "<n2> <p1> <n3> .", bnodeMap);
	BOOST_CHECK_EQUAL(data.size(), 3);

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
	f.parseTriples(&d, 
		       "?product     <label>   ?label ."
 		       "?product     <feature> <feature1> ."
 		       "?product     <feature> \"feature2\" .", bnodeMap);
	DefaultGraphPattern p;
	f.parseTriples(&p, 
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

#endif /* ! REGEX_LIB != SWOb_DISABLED */

