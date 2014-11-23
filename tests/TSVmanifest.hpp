namespace w3c_sw {
    namespace TSVmanifest {

#include <boost/bind.hpp>
#include <iostream>
#include <fstream>

std::string errorStr (std::string filename, int lineNo) { // cater to emacs's comint mode
    return "                 from " + filename + ":" + boost::lexical_cast<std::string>(lineNo);
}

std::string unescape (std::string s, bool literal) {
    size_t len = s.length();
    char space[len+1];
    ::strncpy(space, s.c_str(), len);
    std::string stripped;
    if (literal)
	YaccDriver::unescapeString(space, len, &stripped, NULL);
    else
	YaccDriver::unescapeNumeric(space, len, &stripped, NULL, NULL);
    return stripped;
}

struct GetTTerm {
    const TTerm* t;
    GetTTerm (std::istream& iss, TTerm::String2BNode* bnodeMap)
	: t(readTerm(iss, bnodeMap))
    {  }
    static const TTerm* readTerm (std::istream& iss, TTerm::String2BNode* bnodeMap) {
	std::ostringstream lex;
	char ch;
	iss >> std::ws >> ch >> std::noskipws;
	switch (ch) {
	case '<':
	    while (iss >> ch && ch != '>')
		lex << ch;
	    return F.getURI(unescape(lex.str(), false));
	case '_':
	    iss >> ch; assert(ch == ':');
	    while (iss >> ch && ch != ' ' && ch != '.')
		lex << ch;
	    return F.getBNode(unescape(lex.str(), false), bnodeMap);
	case '"':
	    while (iss >> ch && ch != '"')
		if (ch == '\\') {
		    lex << ch;
		    iss >> ch;
		    lex << ch; // get past possible '"' or into u0022, or whatever
		} else {
		    lex << ch;
		}
	    {
		const TTerm* datatype = NULL;
		const LANGTAG* langtag = NULL;
		iss >> ch;
		if (ch == '^') {
		    iss >> ch; assert(ch == '^');
		    datatype = readTerm(iss, bnodeMap);
		} else if (ch == '@') {
		    std::string s;
		    iss >> s;
		    langtag = new LANGTAG(s);
		} else if (ch != ' ' && ch != '.')
		    throw std::runtime_error(std::string() + "unexpected character after string: " + ch);
		return F.getRDFLiteral(unescape(lex.str(), true), dynamic_cast<const URI*>(datatype), langtag, false);
	    }
	case '.':
	    return DefaultGraph;
	default:
	    throw std::runtime_error(std::string() + "unexpected delimiter: " + ch);
	}
    }
};

void parseNQuads (RdfDB* db, std::istream& is, std::string filename) {
    TTerm::String2BNode m;
    std::string line;
    int lineNo = 1;
    try {
	while (std::getline(is, line)) {
	    while (isspace(line[0]))
		line.erase(0, 1);
	    if (line.length() == 0 || line.find("#", 0) == 0)
		continue;
	    std::istringstream iss(line);
	    GetTTerm s(iss,&m), p(iss,&m), o(iss,&m), g(iss,&m);
	    BasicGraphPattern* graph = db->ensureGraph(g.t);
	    graph->addTriplePattern(F.getTriple(s.t, p.t, o.t));
	    ++lineNo;
	}
    } catch (std::runtime_error& e) {
	throw std::runtime_error
	    (errorStr("tests/"+filename, lineNo) + std::string(": ")+e.what());
    }
}

typedef enum {Expect, Parse, Fail} Action;
void parseAndCompare (std::string /* name */, std::string testData, std::string nqad,
		      std::string manifestLoc, Action action) {
    boost::unit_test::test_case const& cur = boost::unit_test::framework::current_test_case();
    // std::cerr << cur.p_name << "\n";
    std::string context = errorStr("tests/"+testData, 1) + "\n";
    try {
	AtomFactory::validate = AtomFactory::VALIDATE_all;
	std::string base = std::string("http://www.w3.org/2013/") + testData.c_str();
	ReferenceDB tested(testData.c_str(), base.c_str(), true);
	if (action == Expect) {
	    context = errorStr("tests/"+nqad, 1) + "\n";
	    RdfDB expect;
	    std::ifstream nqstr(nqad.c_str());
	    parseNQuads(&expect, nqstr, nqad);
	    context
		= errorStr("tests/"+testData, 1) + "\n"
		+ errorStr("tests/"+nqad, 1) + "\n";
	    if (!(tested == expect)) {
		std::stringstream l; l << tested;
		std::stringstream r; r << expect;
		BOOST_ERROR ( "\n" + context + manifestLoc + " check tested == expect failed " +
			      "[" + l.str() + " != " + r.str() + "]" );
	    }
	} else if (action == Fail) {
	    BOOST_ERROR ( "\n" + context + manifestLoc + " expected parser to fail." );
	}
	/*G_EARL.report(TEST, tested == expect);*/
    } catch (NotImplemented& e) {
	std::cerr << e.what() << "\n";
	BOOST_ERROR ( "\n" + context + manifestLoc + " " + std::string("require implementation of ") + e.brief );
    } catch (std::string& s) {
	if (action != Fail)
	    BOOST_ERROR ( "\n" + context + manifestLoc + " " + s );
    } catch (std::exception& s) {
	if (action != Fail)
	    BOOST_ERROR ( "\n" + context + manifestLoc + " " + s.what() );
    }
}

void readAndQueue (std::string filename, Action action, boost::unit_test::test_suite* ts) {
    std::ifstream tsv(filename.c_str());
    std::string name, testData, nqad;
    int lineNo = 1;
    while (tsv >> name >> testData) {
	name = name.substr(1,name.length()-2);
	testData = testData.substr(1,testData.length()-2);
	if (action == Expect) {
	    tsv >> nqad;
	    nqad = nqad.substr(1,nqad.length()-2);
	}
	ts->add(boost::unit_test::make_test_case
		(boost::unit_test::callback0<>(boost::bind
					       (&parseAndCompare, name, testData, nqad,
						errorStr("tests/"+filename, lineNo)+":",
						action)),
		 boost::unit_test::const_string(name.c_str(), name.length())));
	++lineNo;
    }
}

    } // namespace TSVmanifest
} // namespace w3c_sw

