/* test graph-matching.
 *
 * $Id: test_GraphMatch.cpp,v 1.1 2008-12-01 21:18:00 eric Exp $
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
    w3c_sw::ResultSet rs;
    rs.erase(rs.begin());
    for (int i = 0; i < count; ++i) {
	w3c_sw::Result* r = new w3c_sw::Result(&rs);
	rs.insert(rs.end(), r);
	B* bindings = rows[i].bindings;
	for (int j = 0; j < rows[i].count; ++j)
	    rs.set(r, f.getPOS(bindings[j].bound), f.getPOS(bindings[j].to), false);
    }
    return rs;
}

BOOST_AUTO_TEST_CASE( bgp )
{
    DefaultGraphPattern data, pattern;
    data.addTriplePattern(f.getTriple("<n1>", "<p1>", "<n2>"));
    pattern.addTriplePattern(f.getTriple("?n1", "<p1>", "_:n2"));
    ResultSet r;
    data.BasicGraphPattern::bindVariables(&r, NULL, &pattern, NULL);
    // {map<string, int> stuff {{"one",1}, {"two",2},{"three",3}}; cout <<stuff;}
    //std::map<std::string, std::string> m {{"?n1", "<n1>"}};
    {
	B _r1[] = {B("?n1", "<n11>"), B("?n2", "<n12>")}; R r1 = row(_r1);
	B _r2[] = {B("?n1", "<n21>"), B("?n2", "<n22>"), B("?n3", "<n23>")}; R r2 = row(_r2);
	R rows[] = { r1, r2 };
	ResultSet rs = RS(rows);
	std::cout << rs.toString();
	//Result r1(B("?n1", "<n1>"), B("?n1", "<n1>"));
    }
    //RS rs( r1, r2 );
    int iz[] = {0, 1, 2};
    std::vector<int> v(iz, iz + sizeof(iz)/sizeof(iz[0]));
    
    B _bz[] = {B("?n1", "<n1>")}; R r1 = row(_bz);
    R rows[] = { r1 };
    BOOST_REQUIRE(r == RS(rows));
    //BOOST_CHECK_EQUAL(r, R(rows));
    BOOST_CHECK_EQUAL(1,0);
    BOOST_CHECK_EQUAL(1,1);
    BOOST_CHECK_EQUAL(1,2);
}

