/* perform Shape Expression tests
 * call from: ..
 * files: <tests>/sparql11
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE SWSex_tests
#include "tests/SPARQLTest.hpp"
#include "SWSexParser/SWSexParser.hpp"
#include "SWSexSchema.hpp"
#include <ctype.h>

w3c_sw_DEBUGGING_FUNCTIONS(); // still reachable: 680 bytes in 7 blocks from logger

using namespace w3c_sw;

SWSexDriver swsexParser("", &F);

BOOST_AUTO_TEST_CASE( manual ) {
    SWSexSchema::AtomicRule::ValueSet* t =
	new SWSexSchema::AtomicRule::ValueSet();
    t->tterms.push_back(F.getNumericRDFLiteral
			("1", 1, TTerm::URI_xsd_integer));
    SWSexSchema* s = new SWSexSchema();
    s->ruleMap.insert(std::make_pair
		      (F.createBNode(),
		       new SWSexSchema::AtomicRule
		       (new SWSexSchema::AtomicRule::NameTerm
			(F.getURI("asdf")), t, 1, 1)));
    delete s;
}

/* BNodeLabelNormalizer - traverses a string, transforming all bnodes
 * (marked by _: followed by alphanumerics) to bnodes labeled with
 * sequential integers starting from 0.
 *
 * @bugs: should use isalnum OR !isgraph.
 */
struct BNodeLabelNormalizer {
    std::map<std::string, std::string> m;
    std::string operator()(const std::string& str) {
	std::string ret(str);
	size_t pos = 0;
	while((pos = ret.find("_:", pos)) != std::string::npos) {
	    pos += 2;
	    size_t len = 0;
	    while (pos+len < ret.size() && isalnum(ret[pos + len]))
		++len;
	    std::string old = ret.substr(pos, len);
	    if (m.find(old) == m.end())
		m[old] = 'b' + boost::lexical_cast<std::string>(m.size());
	    std::string n = m[old];
	    ret.replace(pos, len, n);
	    pos += n.length();
	}
	return ret;
    }
};

struct ParseTest {
    const SWSexSchema* sex;
    const std::string expected;
    const std::string serialized;
    ParseTest (const char* parseMe, const char* goal)
	: sex(parse(parseMe)), expected(read(goal)), serialized(serialize(sex)) {  }
    ~ParseTest () {
	delete sex;
	sex = NULL;
    }

    static SWSexSchema* parse (const char* parseMe) {
	IStreamContext aistr(parseMe, IStreamContext::FILE);
	SWSexSchema* sex = swsexParser.parse(aistr, new SWSexSchema());
	swsexParser.clear(); // clear out namespaces and base URI.
	return sex;
    }

    static std::string read (const char* goal) {
	std::ifstream ifs(goal);
	return std::string((std::istreambuf_iterator<char>(ifs)),
			   std::istreambuf_iterator<char>());
    }

    static std::string serialize (const SWSexSchema* sex) {
	std::ostringstream ss;
	ss << *sex << '\n';
	return ss.str();
    }
};

struct NormalizeTest : public ParseTest {
    const std::string normalized;

    NormalizeTest (const char* parseMe, const char* goal)
	: ParseTest(parseMe, goal), normalized(normalize(serialized)) {
	w3c_sw_LINEN << "serialized: " << serialized << "\n";
  }

    static std::string normalize (const std::string serialized) {
	BNodeLabelNormalizer r;
	return r(serialized);
    }
};

BOOST_AUTO_TEST_CASE( expressivity1 ) {
    ParseTest n("SWSex/expressivity1.ssx", "SWSex/expressivity1-normalized.ssx");
    BOOST_CHECK_EQUAL(n.serialized, n.expected);
    // NormalizeTest n("SWSex/expressivity1.ssx", "SWSex/expressivity1-normalized.ssx");
    // BOOST_CHECK_EQUAL(n.normalized, n.expected);
    // ParseTest p("SWSex/expressivity1-normalized.ssx", "SWSex/expressivity1-normalized.ssx");
    // BOOST_CHECK_EQUAL(p.serialized, p.expected);
}

BOOST_AUTO_TEST_CASE( simple1 ) {
    SWSexSchema sex;
    IStreamContext sexstr("SWSex/simple1.ssx", IStreamContext::FILE);
    swsexParser.parse(sexstr, &sex);
    swsexParser.clear(); // clear out namespaces and base URI.

    {
	DefaultGraphPattern data;
	IStreamContext ttlstr("SWSex/simple1-good.ttl", IStreamContext::FILE);
	turtleParser.setGraph(&data);
	turtleParser.parse(ttlstr);
	turtleParser.clear(BASE_URI);
	BOOST_CHECK_EQUAL(sex.validate(data, F.getURI("")), true);
    }

    {
	DefaultGraphPattern data;
	IStreamContext ttlstr("SWSex/simple1-bad.ttl", IStreamContext::FILE);
	turtleParser.setGraph(&data);
	turtleParser.parse(ttlstr);
	turtleParser.clear(BASE_URI);
	BOOST_CHECK_EQUAL(sex.validate(data, F.getURI("")), false);
    }
}

BOOST_AUTO_TEST_CASE( issue1 ) {
    SWSexSchema sex;
    IStreamContext sexstr("SWSex/issue1.ssx", IStreamContext::FILE);
    swsexParser.parse(sexstr, &sex);
    swsexParser.clear(); // clear out namespaces and base URI.

    {
	DefaultGraphPattern data;
	IStreamContext ttlstr("SWSex/issue1-good.ttl", IStreamContext::FILE);
	turtleParser.setGraph(&data);
	turtleParser.parse(ttlstr);
	turtleParser.clear(BASE_URI);
	BOOST_CHECK_EQUAL(sex.validate(data, F.getURI("issue7")), true);
    }

    {
	DefaultGraphPattern data;
	IStreamContext ttlstr("SWSex/issue1-bad.ttl", IStreamContext::FILE);
	turtleParser.setGraph(&data);
	turtleParser.parse(ttlstr);
	turtleParser.clear(BASE_URI);
	BOOST_CHECK_EQUAL(sex.validate(data, F.getURI("issue7")), false);
    }
}
// EOF

