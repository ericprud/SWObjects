/* test graph-matching.
 *
 * $Id: test_GraphMatch.cpp,v 1.5.2.1 2008-12-05 00:39:24 eric Exp $
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
#define RS(X) makeResultSet(X, sizeof(X)/sizeof(X[0]))

ResultSet makeResultSet (R rows[], int count) {
    ResultSet rs;
    rs.erase(rs.begin());
    for (int i = 0; i < count; ++i) {
	Result* r = new Result(&rs);
	rs.insert(rs.end(), r);
	B* bindings = rows[i].bindings;
	for (int j = 0; j < rows[i].count; ++j)
	    rs.set(r, f.getPOS(bindings[j].bound), f.getPOS(bindings[j].to), false);
    }
    return rs;
}

BOOST_AUTO_TEST_CASE( BGP_Basics ) {
    DefaultGraphPattern data, pattern;
    data.addTriplePattern(f.getTriple("<n1> <p1> <n2> ."));

    /* Verify NTriples input, which will be used in remaining tests. */ {
	DefaultGraphPattern d2;
	d2.addTriplePattern(f.getTriple("<n1>", "<p1>", "<n2>"));
	BOOST_REQUIRE(data.size() == 1);
	BOOST_REQUIRE(data == d2);
    }

    pattern.addTriplePattern(f.getTriple("?n1", "<p1>", "_:n2"));

    /* 1 datum, 1 pattern */ {
	B _bz1[] = {B("?n1", "<n1>"), B("_:n2", "<n2>")}; R r1 = row(_bz1);
	R rows[] = { r1 };
	ResultSet ref = RS(rows);

	ResultSet expected(&f, 
			   "?n1  _:n2\n"
			   "<n1> <n2>");

	BOOST_CHECK_EQUAL(RS(rows), expected);

	ResultSet r;
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, expected);
    }

    /* Redundant triples don't change BGP size. */ {
	data.addTriplePattern(f.getTriple("<n1> <p1> <n2> ."));
	BOOST_CHECK_EQUAL(data.size(), 1);
    }

    /* parseTriples */ {
	f.parseTriples(&data, 
		       "<n1> <p1> \"l1\" ."
		       "<n2> <p1> <n3> .");
	BOOST_CHECK_EQUAL(data.size(), 3);

	ResultSet r;
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, ResultSet(&f, 
				       "?n1  _:n2\n"
				       "<n1> <n2>\n"
				       "<n1> \"l1\"\n"
				       "<n2> <n3>"
				       ));
    }

    pattern.addTriplePattern(f.getTriple("_:n2 <p1> ?n3 ."));

    {
	ResultSet r;
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, ResultSet(&f, 
				       "?n1  _:n2 ?n3 \n"
				       "<n1> <n2> <n3>"
				       ));
    }

    data.addTriplePattern(f.getTriple("<n2> <p1> <n4> ."));

    /* <n1> <p1> <n2> . <n2> <p1> <n3>,<n4> . */ {
	ResultSet r;
	data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
	BOOST_CHECK_EQUAL(r, ResultSet(&f, 
				       "?n1  _:n2 ?n3 \n"
				       "<n1> <n2> <n3>\n"
				       "<n1> <n2> <n4>"
				       ));
    }
}


/* Test a subset of BSBM q1. */
BOOST_AUTO_TEST_CASE( Subset_BSBM ) {

    DefaultGraphPattern d;
    f.parseTriples(&d, 
		   "?product     <label>   ?label ."
		   "?product     <feature> <feature1> ."
		   "?product     <feature> \"feature2\" .");
    DefaultGraphPattern p;
    f.parseTriples(&p, 
		   "?ruleProduct <label>   ?ruleLabel ."
		   "?ruleProduct <feature> ?ruleFeature .");
    ResultSet tested;
    d.BasicGraphPattern::bindVariables(&tested, NULL, &p, NULL);
    ResultSet expected(&f, 
		       "?ruleProduct ?ruleLabel ?ruleFeature \n"
		       "?product     ?label     <feature1> \n"
		       "?product     ?label     \"feature2\"");
    BOOST_CHECK_EQUAL(tested, expected);
}


/* Inverted (mapping) semantics, see how a query matches rule heads.
 * Note that inverted matches bind the variables in the data to variables 
 * in the pattern. */
BOOST_AUTO_TEST_CASE( Inverted_BSBM ) {

    DefaultGraphPattern d(BasicGraphPattern::MatchSemantics(true, false));
    f.parseTriples(&d, 
		   "?product     <label>   ?label ."
		   "?product     <feature> <feature1> ."
		   "?product     <feature> \"feature2\" .");
    DefaultGraphPattern p(BasicGraphPattern::MatchSemantics(false, true));
    f.parseTriples(&p, 
		   "?ruleProduct <label>   ?ruleLabel ."
		   "?ruleProduct <feature> ?ruleFeature ."
		   "?ruleProduct <extra>   ?extra .");
    ResultSet tested;
    p.BasicGraphPattern::bindVariables(&tested, NULL, &d, NULL);
    ResultSet expected(&f, 
		       "?ruleProduct ?ruleLabel ?ruleFeature \n"
		       "?product     ?label     <feature1> \n"
		       "?product     ?label     \"feature2\"");
    BOOST_CHECK_EQUAL(tested, expected);
}

