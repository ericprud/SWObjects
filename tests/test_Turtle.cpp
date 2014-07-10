/* perform SPARQL 1.1 tests.
 * call from: ..
 * files: <tests>/sparql11
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE Turtle_tests
#include "tests/SPARQLTest.hpp"

#define LG(SOURCE, NAME) LabeledGraph(SOURCE, NAME)
#define SIZE(ARRAY) (sizeof(ARRAY)/sizeof(ARRAY[0]))

w3c_sw_DEBUGGING_FUNCTIONS();

namespace utf8 {

    // from http://en.wikipedia.org/wiki/UTF-8#Description
    int encode(char *dest, u_int32_t ch) {
	//  7  U+0000     U+007F      1  0xxxxxxx
	if (ch < 0x80) {
	    *dest++ = (char)ch;
	    return 1;
	}
	// 11  U+0080     U+07FF      2  110xxxxx  10xxxxxx
	if (ch < 0x800) {
	    *dest++ = ( ch>>6)          | 0xC0;
	    *dest++ = ( ch      & 0x3F) | 0x80;
	    return 2;
	}
	// 16  U+0800     U+FFFF      3  1110xxxx  10xxxxxx  10xxxxxx
	if (ch < 0x10000) {
	    *dest++ = ( ch>>12)         | 0xE0;
	    *dest++ = ((ch>> 6) & 0x3F) | 0x80;
	    *dest++ = ( ch      & 0x3F) | 0x80;
	    return 3;
	}
	// 21  U+10000    U+1FFFFF    4  11110xxx  10xxxxxx  10xxxxxx  10xxxxxx
	if (ch < 0x200000) {
	    *dest++ = ( ch>>18)         | 0xF0;
	    *dest++ = ((ch>>12) & 0x3F) | 0x80;
	    *dest++ = ((ch>> 6) & 0x3F) | 0x80;
	    *dest++ = ( ch      & 0x3F) | 0x80;
	    return 4;
	}
	// 26  U+200000   U+3FFFFFF   5  111110xx  10xxxxxx  10xxxxxx  10xxxxxx  10xxxxxx
	if (ch < 0x4000000) {
	    *dest++ = ( ch>>24)         | 0xF8;
	    *dest++ = ((ch>>18) & 0x3F) | 0x80;
	    *dest++ = ((ch>>12) & 0x3F) | 0x80;
	    *dest++ = ((ch>> 6) & 0x3F) | 0x80;
	    *dest++ = ( ch      & 0x3F) | 0x80;
	    return 5;
	}
	// 31  U+4000000  U+7FFFFFFF  6  1111110x  10xxxxxx  10xxxxxx  10xxxxxx  10xxxxxx  10xxxxxx
	if (ch < 0x80000000) {
	    *dest++ = ( ch>>30)         | 0xFC;
	    *dest++ = ((ch>>24) & 0x3F) | 0x80;
	    *dest++ = ((ch>>18) & 0x3F) | 0x80;
	    *dest++ = ((ch>>12) & 0x3F) | 0x80;
	    *dest++ = ((ch>> 6) & 0x3F) | 0x80;
	    *dest++ = ( ch      & 0x3F) | 0x80;
	    return 6;
	}
	std::ostringstream os;
	os << "0x" << std::hex << ch << " is out of range";
	throw os.str();
    }

    BOOST_AUTO_TEST_CASE( encode_test ) {
	//void encode_test () {
	char s[7];

	s[encode(s, 0x00000000)] = 0; BOOST_REQUIRE(!::strcmp(s, "\x00"));
	s[encode(s, 0x0000007f)] = 0; BOOST_REQUIRE(!::strcmp(s, "\x7f"));

	s[encode(s, 0x00000080)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xc2\x80"));
	s[encode(s, 0x000007ff)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xdf\xbf"));

	s[encode(s, 0x00000800)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xe0\xa0\x80"));
	s[encode(s, 0x0000ffff)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xef\xbf\xbf"));

	s[encode(s, 0x00010000)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xf0\x90\x80\x80"));
	s[encode(s, 0x001fffff)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xf7\xbf\xbf\xbf"));

	s[encode(s, 0x00200000)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xf8\x88\x80\x80\x80"));
	s[encode(s, 0x03ffffff)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xfb\xbf\xbf\xbf\xbf"));

	s[encode(s, 0x04000000)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xfc\x84\x80\x80\x80\x80"));
	s[encode(s, 0x7fffffff)] = 0; BOOST_REQUIRE(!::strcmp(s, "\xfd\xbf\xbf\xbf\xbf\xbf"));

	BOOST_REQUIRE_THROW(encode(s, 0x80000000), std::string);
	BOOST_REQUIRE_THROW(encode(s, 0xF0000000), std::string);
    }
} // namespace utf8

namespace literal {
    char* from_codepoint (u_int32_t value, char test[15]) {
	int size = utf8::encode(test+9, value);
	test[size+9  ] = '\'';
	test[size+9+1] = ' ' ;
	test[size+9+2] = '.' ;
	test[size+9+3] = '\0';
	return test;
    }

    BOOST_AUTO_TEST_CASE( from_codepoint_test ) {
	u_int32_t value = 0x10fffd;
	char test[16] = "<s> <p> '";
	BOOST_CHECK_EQUAL(from_codepoint(value, test), "<s> <p> '\xf4\x8f\xbf\xbd' .");
    }

    bool isTurtle (u_int32_t value) {
	char test[15] = "<s> <p> '";

	from_codepoint(value, test);
	DefaultGraphPattern parsed;
	AtomFactory::validate = AtomFactory::VALIDATE_all;
	IStreamContext testStream(test, IStreamContext::STRING);
	turtleParser.setGraph(&parsed);
	turtleParser.clear(BASE_URI);
	turtleParser.abortErrorCount = 1;
	try {
	    turtleParser.parse(testStream);
	} catch (ParserException& e) {
	    return false;
	}
	return true;
    }

    BOOST_AUTO_TEST_CASE( isTurtle_test ) {
	// encode_test();

	int& argc = boost::unit_test::framework::master_test_suite().argc;
	char** argv = boost::unit_test::framework::master_test_suite().argv;

	for (int i = 1; i < argc; ++i)
	    if (std::string(argv[i]) == "--allchars") {

		for (u_int32_t i = 0x000080; i <= 0x00d7ff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x00d800; i <= 0x00dfff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x00e000; i <= 0x00fdcf; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x00fdd0; i <= 0x00fdef; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x00fdf0; i <= 0x00fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x00fffe; i <= 0x00ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x010000; i <= 0x01fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x01fffe; i <= 0x01ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x020000; i <= 0x02fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x02fffe; i <= 0x02ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x030000; i <= 0x03fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x03fffe; i <= 0x03ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x040000; i <= 0x04fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x04fffe; i <= 0x04ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x050000; i <= 0x05fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x05fffe; i <= 0x05ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x060000; i <= 0x06fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x06fffe; i <= 0x06ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x070000; i <= 0x07fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x07fffe; i <= 0x07ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x080000; i <= 0x08fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x08fffe; i <= 0x08ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x090000; i <= 0x09fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x09fffe; i <= 0x09ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x0a0000; i <= 0x0afffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x0afffe; i <= 0x0affff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x0b0000; i <= 0x0bfffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x0bfffe; i <= 0x0bffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x0c0000; i <= 0x0cfffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x0cfffe; i <= 0x0cffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x0d0000; i <= 0x0dfffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x0dfffe; i <= 0x0dffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x0e0000; i <= 0x0efffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x0efffe; i <= 0x0effff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x0f0000; i <= 0x0ffffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x0ffffe; i <= 0x0fffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
		for (u_int32_t i = 0x100000; i <= 0x10fffd; ++i) BOOST_CHECK_EQUAL(isTurtle(i), true);
		for (u_int32_t i = 0x10fffe; i <= 0x10ffff; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);

		// UTF8 encodings for codepoints above Last (i.e. not within Unicode extensibility)
		for (u_int32_t i = 0x110000; i <= 0x110010; ++i) BOOST_CHECK_EQUAL(isTurtle(i), false);
	    }
    }

}; // namespace literal

BOOST_AUTO_TEST_SUITE( error_recovery )
struct ErrorRecoveryTest {
    DefaultGraphPattern parsed, expected;
    size_t errorCount;
    std::string errorReport, expectedReport;
    ErrorRecoveryTest (const char* testTurtle, std::string expectedReport,
		       const char* expectedTurtle = NULL, size_t maxErrors = 0)
	: errorCount(0), expectedReport(expectedReport)
    {
	AtomFactory::validate = AtomFactory::VALIDATE_all;
	IStreamContext testStream(testTurtle, IStreamContext::STRING);
	turtleParser.setGraph(&parsed);
	turtleParser.clear(BASE_URI);
	turtleParser.abortErrorCount = maxErrors;
	// turtleParser.trace_parsing = true;
	// turtleParser.trace_scanning = true;
	try {
	    turtleParser.parse(testStream);
	} catch (ParserException& e) {
	    errorCount = 1;
	    errorReport = e.what();
	} catch (ParserExceptions& e) {
	    assert(maxErrors != 1); // 1 should only throw a single ParserException.
	    errorCount = e.errors.size();
	    errorReport = e.what();
	}
	// turtleParser.trace_parsing = false;
	// turtleParser.trace_scanning = false;
	// w3c_sw_LINEN << parsed << "\n";
	if (expectedTurtle) {
	    IStreamContext refStream(expectedTurtle, IStreamContext::STRING);
	    turtleParser.setGraph(&expected);
	    turtleParser.parse(refStream);
	    turtleParser.clear(BASE_URI);
	}
    }
};

#define ERROR_RECOVERY_TEST(TEST, EXPECT, GRAPH, MAX, COUNT)	\
    ErrorRecoveryTest t(TEST, EXPECT, GRAPH, MAX);		\
    BOOST_CHECK_EQUAL(t.errorReport, t.expectedReport);		\
    BOOST_CHECK_EQUAL(t.parsed, t.expected);			\
    BOOST_CHECK_EQUAL(t.errorCount, (size_t)COUNT);		\

BOOST_AUTO_TEST_CASE( error_bnode_label_not_greedier_than_bnode_label ) { ERROR_RECOVERY_TEST
	("@prefix : <http://example.com/data/#> .\n"
	 "\n"
	 ":x :p 1, 2, 3, 4 .\n"
	 ":y :p 1, _:b2, 3, 4 .\n"
	 ":z :p 1.0, 2.0, 3.0, 4 .\n",

	 "",

	 "@prefix : <http://example.com/data/#> .\n"
	 "\n"
	 ":x :p 1, 2, 3, 4 .\n"
	 ":y :p 1, _:b2, 3, 4 .\n"
	 ":z :p 1.0, 2.0, 3.0, 4 .\n", 0, 0);
}
BOOST_AUTO_TEST_CASE( no_objects ) { ERROR_RECOVERY_TEST
	("<s> <p> .\n"
	 "<s2> <p2> . ",
	 "<s> <p> .\n"
	 "<s2> <p2> . :1.9: syntax error, unexpected '.'\n"
	 "-- \n"
	 "<s> <p> .\n"
	 "<s2> <p2> . :2.11: syntax error, unexpected '.'",
	 NULL, // no expected triples
	 0, 2);
}
BOOST_AUTO_TEST_CASE( extra_spo_objects ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> 'o2' 'o2bis'. ",
	 "<s> <p> <o><obis>.<s2> <p2> 'o2' 'o2bis'. :1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> 'o2' 'o2bis'. :1.34-40: syntax error, unexpected 'string', expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> 'o2'        . ", 0, 2);
}
BOOST_AUTO_TEST_CASE( _1_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .                                            ", 1, 1);
}
BOOST_AUTO_TEST_CASE( _2_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.29-39: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> <o2>       .                      ", 2, 2);
}
BOOST_AUTO_TEST_CASE( _3_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.29-39: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.51-61: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> <o2>       .<s3> <p3> <o3>       .", 3, 3);
}
BOOST_AUTO_TEST_CASE( _all_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.29-39: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.51-61: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> <o2>       .<s3> <p3> <o3>       .", 0, 3);
}
BOOST_AUTO_TEST_CASE( extra_po_objects_before_comma ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>, <o2>. ",
	 "<s> <p> <o><obis>, <o2>. :1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>, <o2>. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( extra_po_objects_before_semi ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>; <p2> <o2>. ",
	 "<s> <p> <o><obis>; <p2> <o2>. :1.9-17: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>; <p2> <o2>. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( extra_po_objects ) { ERROR_RECOVERY_TEST
	("<s> <p> [ <p2> <o2><o2bis> ]. ",
	 "<s> <p> [ <p2> <o2><o2bis> ]. :1.16-26: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> [ <p2> <o2>        ]. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( extra_po_objects_plus ) { ERROR_RECOVERY_TEST
	("<s> <p> [ <p2> <o2><o2bis> ; <p3> <o3> ]. ",
	 "<s> <p> [ <p2> <o2><o2bis> ; <p3> <o3> ]. :1.16-26: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> [ <p2> <o2>        ; <p3> <o3> ]. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( unterminated_url ) { ERROR_RECOVERY_TEST
	("<s1> <p1> 'o1 . <s2> <p2> <o2>.<s3> <p3> <o3 .",
	 "<s1> <p1> 'o1 . <s2> <p2> <o2>.<s3> <p3> <o3 .:1.11-13: Malformed single-quoted simple literal \"'o1\"\n"
	 "<s1> <p1> 'o1 . <s2> <p2> <o2>.<s3> <p3> <o3 .:1.42-44: Malformed IRI \"<o3\"",
	 "<s1> <p1> 'o1'. <s2> <p2> <o2>.<s3> <p3> <o3>.", 0, 2);
}
BOOST_AUTO_TEST_CASE( commas_and_semis ) { ERROR_RECOVERY_TEST
	("<s1> <p1> 'o1a', 'o1b ; <o2>.",
	 "<s1> <p1> 'o1a', 'o1b ; <o2>.:1.18-21: Malformed single-quoted simple literal \"'o1b\"\n"
	 "<s1> <p1> 'o1a', 'o1b ; <o2>.:1.25-29: syntax error, unexpected '.'", // @@ improving the error grammar should eliminate this.
	 "<s1> <p1> 'o1a', 'o1b';     .", 0, 2);
}
BOOST_AUTO_TEST_CASE( undefined_prefixes ) { ERROR_RECOVERY_TEST
	("PREFIX x: <x#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .",

	 "PREFIX x: <x#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .:2.16-3.4: Unknown prefix: \"y\" (2 more times)\n"
	 "-- \n"
	 "PREFIX x: <x#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .:3.11-13: Unknown prefix: \"\"",

	 "PREFIX x: <x#>\n"
	 "PREFIX y: <unknownPrefix:0#>\n"
	 "PREFIX :  <unknownPrefix:1#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .", 0, 2);
}
BOOST_AUTO_TEST_SUITE_END(/* error_recovery */)

#define TURTLE_TEST(TEST, TESTME, EXPECT)				       \
    try {								       \
	AtomFactory::validate = AtomFactory::VALIDATE_all;		       \
	ReferenceDB tested(TESTME, NULL, 0, "http://www.w3.org/2013/TurtleTests/turtle-subm-01.ttl", true);	\
	ReferenceDB expect(EXPECT, NULL, 0, "http://www.w3.org/2013/TurtleTests/");	       \
	BOOST_CHECK_EQUAL(tested, expect);				       \
	/*G_EARL.report(TEST, tested == expect);*/			       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

/** command-line Turtle tests:

from the web:

semantics tests:
./bin/sparql -d http://www.w3.org/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -d " ?ttl " --compare " ?nt " || echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtleEval ; mf:action ?ttl ; mf:result ?nt ; mf:name ?name } ' -L text/raw | bash

positive syntax tests:
./bin/sparql -d http://www.w3.org/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -d " ?ttl " || echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtlePositiveSyntax ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

negative syntax tests:
./bin/sparql -d http://www.w3.org/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -d " ?ttl " && echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtleNegativeSyntax ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

./bin/sparql -d http://www.w3.org/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql --validation iricharacters -q -d " ?ttl " && echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtleNegativeEval ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash


or from disk:
./bin/sparql -d ../../WWW/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -b " REPLACE(STR(?ttl), "../../WWW/2013/TurtleTests/", "http://www.w3.org/2013/TurtleTests/") " -d " ?ttl " --compare " ?nt " || echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtleEval ; mf:action ?ttl ; mf:result ?nt ; mf:name ?name } ' -L text/raw | bash

./bin/sparql -d ../../WWW/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -b " REPLACE(STR(?ttl), "../../WWW/2013/TurtleTests/", "http://www.w3.org/2013/TurtleTests/") " -d " ?ttl " || echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtlePositiveSyntax ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

./bin/sparql -d ../../WWW/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -b " REPLACE(STR(?ttl), "../../WWW/2013/TurtleTests/", "http://www.w3.org/2013/TurtleTests/") " -d " ?ttl " && echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtleNegativeSyntax ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

./bin/sparql -d ../../WWW/2013/TurtleTests/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql --validation iricharacters -q -b " REPLACE(STR(?ttl), "../../WWW/2013/TurtleTests/", "http://www.w3.org/2013/TurtleTests/") " -d " ?ttl " && echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTurtleNegativeEval ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

Note that [[ -b " ?ttl " ]] fails turtle-subm-01 turtle-subm-27 .
      and [[]] fails turtle-subm-01 turtle-subm-19 turtle-subm-20 turtle-subm-22 turtle-subm-27


see also test_Turtle-WG.sh

 */


BOOST_AUTO_TEST_SUITE( coverage )
BOOST_AUTO_TEST_CASE( IRI_subject ) { TURTLE_TEST("IRI_subject", "TurtleTests/IRI_subject.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( IRI_with_four_digit_numeric_escape ) { TURTLE_TEST("IRI_with_four_digit_numeric_escape", "TurtleTests/IRI_with_four_digit_numeric_escape.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( IRI_with_eight_digit_numeric_escape ) { TURTLE_TEST("IRI_with_eight_digit_numeric_escape", "TurtleTests/IRI_with_eight_digit_numeric_escape.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( IRI_with_all_punctuation ) { TURTLE_TEST("IRI_with_all_punctuation", "TurtleTests/IRI_with_all_punctuation.ttl", "TurtleTests/IRI_with_all_punctuation.nt"); }
BOOST_AUTO_TEST_CASE( bareword_a_predicate ) { TURTLE_TEST("bareword_a_predicate", "TurtleTests/bareword_a_predicate.ttl", "TurtleTests/bareword_a_predicate.nt"); }
BOOST_AUTO_TEST_CASE( old_style_prefix ) { TURTLE_TEST("old_style_prefix", "TurtleTests/old_style_prefix.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( SPARQL_style_prefix ) { TURTLE_TEST("SPARQL_style_prefix", "TurtleTests/SPARQL_style_prefix.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( prefixed_IRI_predicate ) { TURTLE_TEST("prefixed_IRI_predicate", "TurtleTests/prefixed_IRI_predicate.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( prefixed_IRI_object ) { TURTLE_TEST("prefixed_IRI_object", "TurtleTests/prefixed_IRI_object.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( prefix_only_IRI ) { TURTLE_TEST("prefix_only_IRI", "TurtleTests/prefix_only_IRI.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( prefix_with_PN_CHARS_BASE_character_boundaries ) { TURTLE_TEST("prefix_only_IRI", "TurtleTests/prefix_with_PN_CHARS_BASE_character_boundaries.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( default_namespace_IRI ) { TURTLE_TEST("default_namespace_IRI", "TurtleTests/default_namespace_IRI.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( prefix_reassigned_and_used ) { TURTLE_TEST("prefix_reassigned_and_used", "TurtleTests/prefix_reassigned_and_used.ttl", "TurtleTests/prefix_reassigned_and_used.nt"); }
BOOST_AUTO_TEST_CASE( reserved_escaped_localName ) { TURTLE_TEST("reserved_escaped_localName", "TurtleTests/reserved_escaped_localName.ttl", "TurtleTests/reserved_escaped_localName.nt"); }
BOOST_AUTO_TEST_CASE( percent_escaped_localName ) { TURTLE_TEST("percent_escaped_localName", "TurtleTests/percent_escaped_localName.ttl", "TurtleTests/percent_escaped_localName.nt"); }
BOOST_AUTO_TEST_CASE( HYPHEN_MINUS_in_localName ) { TURTLE_TEST("HYPHEN_MINUS_in_localName", "TurtleTests/HYPHEN_MINUS_in_localName.ttl", "TurtleTests/HYPHEN_MINUS_in_localName.nt"); }
BOOST_AUTO_TEST_CASE( underscore_in_localName ) { TURTLE_TEST("underscore_in_localName", "TurtleTests/underscore_in_localName.ttl", "TurtleTests/underscore_in_localName.nt"); }
BOOST_AUTO_TEST_CASE( localname_with_COLON ) { TURTLE_TEST("localname_with_COLON", "TurtleTests/localname_with_COLON.ttl", "TurtleTests/localname_with_COLON.nt"); }

//BOOST_AUTO_TEST_CASE( localName_with_PN_CHARS_BASE_character_boundaries ) { TURTLE_TEST("prefix_only_IRI", "TurtleTests/localName_with_PN_CHARS_BASE_character_boundaries.ttl", "TurtleTests/localName_with_PN_CHARS_BASE_character_boundaries.nt"); }


BOOST_AUTO_TEST_CASE( localName_with_assigned_nfc_bmp_PN_CHARS_BASE_character_boundaries ) { TURTLE_TEST("localName_with_assigned_nfc_bmp_PN_CHARS_BASE_character_boundaries", "TurtleTests/localName_with_assigned_nfc_bmp_PN_CHARS_BASE_character_boundaries.ttl", "TurtleTests/localName_with_assigned_nfc_bmp_PN_CHARS_BASE_character_boundaries.nt") }
BOOST_AUTO_TEST_CASE( localName_with_assigned_nfc_PN_CHARS_BASE_character_boundaries ) { TURTLE_TEST("localName_with_assigned_nfc_PN_CHARS_BASE_character_boundaries", "TurtleTests/localName_with_assigned_nfc_PN_CHARS_BASE_character_boundaries.ttl", "TurtleTests/localName_with_assigned_nfc_PN_CHARS_BASE_character_boundaries.nt") }
BOOST_AUTO_TEST_CASE( localName_with_nfc_PN_CHARS_BASE_character_boundaries ) { TURTLE_TEST("localName_with_nfc_PN_CHARS_BASE_character_boundaries", "TurtleTests/localName_with_nfc_PN_CHARS_BASE_character_boundaries.ttl", "TurtleTests/localName_with_nfc_PN_CHARS_BASE_character_boundaries.nt") }
BOOST_AUTO_TEST_CASE( localName_with_leading_underscore ) { TURTLE_TEST("localName_with_leading_underscore", "TurtleTests/localName_with_leading_underscore.ttl", "TurtleTests/localName_with_leading_underscore.nt") }
BOOST_AUTO_TEST_CASE( localName_with_leading_digit ) { TURTLE_TEST("localName_with_leading_digit", "TurtleTests/localName_with_leading_digit.ttl", "TurtleTests/localName_with_leading_digit.nt") }
BOOST_AUTO_TEST_CASE( localName_with_non_leading_extras ) { TURTLE_TEST("localName_with_non_leading_extras", "TurtleTests/localName_with_non_leading_extras.ttl", "TurtleTests/localName_with_non_leading_extras.nt") }


BOOST_AUTO_TEST_CASE( old_style_base ) { TURTLE_TEST("old_style_base", "TurtleTests/old_style_base.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( SPARQL_style_base ) { TURTLE_TEST("SPARQL_style_base", "TurtleTests/SPARQL_style_base.ttl", "TurtleTests/IRI_spo.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_subject ) { TURTLE_TEST("labeled_blank_node_subject", "TurtleTests/labeled_blank_node_subject.ttl", "TurtleTests/labeled_blank_node_subject.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_object ) { TURTLE_TEST("labeled_blank_node_object", "TurtleTests/labeled_blank_node_object.ttl", "TurtleTests/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_with_PN_CHARS_BASE_character_boundaries ) { TURTLE_TEST("anonymous_blank_node_object", "TurtleTests/labeled_blank_node_with_PN_CHARS_BASE_character_boundaries.ttl", "TurtleTests/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_with_leading_underscore ) { TURTLE_TEST("anonymous_blank_node_object", "TurtleTests/labeled_blank_node_with_leading_underscore.ttl", "TurtleTests/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_with_leading_digit ) { TURTLE_TEST("anonymous_blank_node_object", "TurtleTests/labeled_blank_node_with_leading_digit.ttl", "TurtleTests/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_with_non_leading_extras ) { TURTLE_TEST("anonymous_blank_node_object", "TurtleTests/labeled_blank_node_with_non_leading_extras.ttl", "TurtleTests/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( anonymous_blank_node_subject ) { TURTLE_TEST("anonymous_blank_node_subject", "TurtleTests/anonymous_blank_node_subject.ttl", "TurtleTests/labeled_blank_node_subject.nt"); }
BOOST_AUTO_TEST_CASE( anonymous_blank_node_object ) { TURTLE_TEST("anonymous_blank_node_object", "TurtleTests/anonymous_blank_node_object.ttl", "TurtleTests/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( sole_blankNodePropertyList ) { TURTLE_TEST("sole_blankNodePropertyList", "TurtleTests/sole_blankNodePropertyList.ttl", "TurtleTests/labeled_blank_node_subject.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_as_subject ) { TURTLE_TEST("blankNodePropertyList_as_subject", "TurtleTests/blankNodePropertyList_as_subject.ttl", "TurtleTests/blankNodePropertyList_as_subject.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_as_object ) { TURTLE_TEST("blankNodePropertyList_as_object", "TurtleTests/blankNodePropertyList_as_object.ttl", "TurtleTests/blankNodePropertyList_as_object.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_with_multiple_triples ) { TURTLE_TEST("blankNodePropertyList_with_multiple_triples", "TurtleTests/blankNodePropertyList_with_multiple_triples.ttl", "TurtleTests/blankNodePropertyList_with_multiple_triples.nt"); }
BOOST_AUTO_TEST_CASE( nested_blankNodePropertyLists ) { TURTLE_TEST("nested_blankNodePropertyLists", "TurtleTests/nested_blankNodePropertyLists.ttl", "TurtleTests/nested_blankNodePropertyLists.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_containing_collection ) { TURTLE_TEST("blankNodePropertyList_containing_collection", "TurtleTests/blankNodePropertyList_containing_collection.ttl", "TurtleTests/blankNodePropertyList_containing_collection.nt"); }
BOOST_AUTO_TEST_CASE( collection_subject ) { TURTLE_TEST("collection_subject", "TurtleTests/collection_subject.ttl", "TurtleTests/collection_subject.nt"); }
BOOST_AUTO_TEST_CASE( collection_object ) { TURTLE_TEST("collection_object", "TurtleTests/collection_object.ttl", "TurtleTests/collection_object.nt"); }
BOOST_AUTO_TEST_CASE( empty_collection ) { TURTLE_TEST("empty_collection", "TurtleTests/empty_collection.ttl", "TurtleTests/empty_collection.nt"); }
BOOST_AUTO_TEST_CASE( nested_collection ) { TURTLE_TEST("nested_collection", "TurtleTests/nested_collection.ttl", "TurtleTests/nested_collection.nt"); }
BOOST_AUTO_TEST_CASE( first ) { TURTLE_TEST("first", "TurtleTests/first.ttl", "TurtleTests/first.nt"); }
BOOST_AUTO_TEST_CASE( last ) { TURTLE_TEST("last", "TurtleTests/last.ttl", "TurtleTests/last.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL1 ) { TURTLE_TEST("LITERAL1", "TurtleTests/LITERAL1.ttl", "TurtleTests/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL1_ascii_boundaries ) { TURTLE_TEST("LITERAL1", "TurtleTests/LITERAL1_ascii_boundaries.ttl", "TurtleTests/LITERAL1_ascii_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL1_all_controls ) { TURTLE_TEST("LITERAL1", "TurtleTests/LITERAL1_all_controls.ttl", "TurtleTests/LITERAL1_all_controls.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL1_all_punctuation ) { TURTLE_TEST("LITERAL1", "TurtleTests/LITERAL1_all_punctuation.ttl", "TurtleTests/LITERAL1_all_punctuation.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL1_with_UTF8_boundaries ) { TURTLE_TEST("LITERAL1", "TurtleTests/LITERAL1_with_UTF8_boundaries.ttl", "TurtleTests/LITERAL_with_UTF8_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1 ) { TURTLE_TEST("LITERAL_LONG1", "TurtleTests/LITERAL_LONG1.ttl", "TurtleTests/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1_ascii_boundaries ) { TURTLE_TEST("LITERAL_LONG1", "TurtleTests/LITERAL_LONG1_ascii_boundaries.ttl", "TurtleTests/LITERAL_LONG1_ascii_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1_with_UTF8_boundaries ) { TURTLE_TEST("LITERAL_LONG1", "TurtleTests/LITERAL_LONG1_with_UTF8_boundaries.ttl", "TurtleTests/LITERAL_with_UTF8_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1_with_1_squote ) { TURTLE_TEST("LITERAL_LONG1_with_1_squote", "TurtleTests/LITERAL_LONG1_with_1_squote.ttl", "TurtleTests/LITERAL_LONG1_with_1_squote.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1_with_2_squotes ) { TURTLE_TEST("LITERAL_LONG1_with_2_squotes", "TurtleTests/LITERAL_LONG1_with_2_squotes.ttl", "TurtleTests/LITERAL_LONG1_with_2_squotes.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL2 ) { TURTLE_TEST("LITERAL2", "TurtleTests/LITERAL2.ttl", "TurtleTests/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL2_ascii_boundaries ) { TURTLE_TEST("LITERAL2", "TurtleTests/LITERAL2_ascii_boundaries.ttl", "TurtleTests/LITERAL2_ascii_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL2_with_UTF8_boundaries ) { TURTLE_TEST("LITERAL2", "TurtleTests/LITERAL2_with_UTF8_boundaries.ttl", "TurtleTests/LITERAL_with_UTF8_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2 ) { TURTLE_TEST("LITERAL_LONG2", "TurtleTests/LITERAL_LONG2.ttl", "TurtleTests/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2_ascii_boundaries ) { TURTLE_TEST("LITERAL_LONG2", "TurtleTests/LITERAL_LONG2_ascii_boundaries.ttl", "TurtleTests/LITERAL_LONG2_ascii_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2_with_UTF8_boundaries ) { TURTLE_TEST("LITERAL_LONG2", "TurtleTests/LITERAL_LONG2_with_UTF8_boundaries.ttl", "TurtleTests/LITERAL_with_UTF8_boundaries.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2_with_1_squote ) { TURTLE_TEST("LITERAL_LONG2_with_1_squote", "TurtleTests/LITERAL_LONG2_with_1_squote.ttl", "TurtleTests/LITERAL_LONG2_with_1_squote.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2_with_2_squotes ) { TURTLE_TEST("LITERAL_LONG2_with_2_squotes", "TurtleTests/LITERAL_LONG2_with_2_squotes.ttl", "TurtleTests/LITERAL_LONG2_with_2_squotes.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_CHARACTER_TABULATION ) { TURTLE_TEST("literal_with_CHARACTER_TABULATION", "TurtleTests/literal_with_CHARACTER_TABULATION.ttl", "TurtleTests/literal_with_CHARACTER_TABULATION.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_BACKSPACE ) { TURTLE_TEST("literal_with_BACKSPACE", "TurtleTests/literal_with_BACKSPACE.ttl", "TurtleTests/literal_with_BACKSPACE.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_LINE_FEED ) { TURTLE_TEST("literal_with_LINE_FEED", "TurtleTests/literal_with_LINE_FEED.ttl", "TurtleTests/literal_with_LINE_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_CARRIAGE_RETURN ) { TURTLE_TEST("literal_with_CARRIAGE_RETURN", "TurtleTests/literal_with_CARRIAGE_RETURN.ttl", "TurtleTests/literal_with_CARRIAGE_RETURN.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_FORM_FEED ) { TURTLE_TEST("literal_with_FORM_FEED", "TurtleTests/literal_with_FORM_FEED.ttl", "TurtleTests/literal_with_FORM_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_REVERSE_SOLIDUS ) { TURTLE_TEST("literal_with_REVERSE_SOLIDUS", "TurtleTests/literal_with_REVERSE_SOLIDUS.ttl", "TurtleTests/literal_with_REVERSE_SOLIDUS.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_CHARACTER_TABULATION ) { TURTLE_TEST("literal_with_escaped_CHARACTER_TABULATION", "TurtleTests/literal_with_escaped_CHARACTER_TABULATION.ttl", "TurtleTests/literal_with_CHARACTER_TABULATION.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_BACKSPACE ) { TURTLE_TEST("literal_with_escaped_BACKSPACE", "TurtleTests/literal_with_escaped_BACKSPACE.ttl", "TurtleTests/literal_with_BACKSPACE.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_LINE_FEED ) { TURTLE_TEST("literal_with_escaped_LINE_FEED", "TurtleTests/literal_with_escaped_LINE_FEED.ttl", "TurtleTests/literal_with_LINE_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_CARRIAGE_RETURN ) { TURTLE_TEST("literal_with_escaped_CARRIAGE_RETURN", "TurtleTests/literal_with_escaped_CARRIAGE_RETURN.ttl", "TurtleTests/literal_with_CARRIAGE_RETURN.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_FORM_FEED ) { TURTLE_TEST("literal_with_escaped_FORM_FEED", "TurtleTests/literal_with_escaped_FORM_FEED.ttl", "TurtleTests/literal_with_FORM_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_numeric_escape4 ) { TURTLE_TEST("literal_with_numeric_escape4", "TurtleTests/literal_with_numeric_escape4.ttl", "TurtleTests/literal_with_numeric_escape4.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_numeric_escape8 ) { TURTLE_TEST("literal_with_numeric_escape8", "TurtleTests/literal_with_numeric_escape8.ttl", "TurtleTests/literal_with_numeric_escape4.nt"); }
BOOST_AUTO_TEST_CASE( IRIREF_datatype ) { TURTLE_TEST("IRIREF_datatype", "TurtleTests/IRIREF_datatype.ttl", "TurtleTests/IRIREF_datatype.nt"); }
BOOST_AUTO_TEST_CASE( prefixed_name_datatype ) { TURTLE_TEST("prefixed_name_datatype", "TurtleTests/prefixed_name_datatype.ttl", "TurtleTests/IRIREF_datatype.nt"); }
BOOST_AUTO_TEST_CASE( bareword_integer ) { TURTLE_TEST("bareword_integer", "TurtleTests/bareword_integer.ttl", "TurtleTests/IRIREF_datatype.nt"); }
BOOST_AUTO_TEST_CASE( bareword_decimal ) { TURTLE_TEST("bareword_decimal", "TurtleTests/bareword_decimal.ttl", "TurtleTests/bareword_decimal.nt"); }
BOOST_AUTO_TEST_CASE( bareword_double ) { TURTLE_TEST("bareword_double", "TurtleTests/bareword_double.ttl", "TurtleTests/bareword_double.nt"); }
BOOST_AUTO_TEST_CASE( double_lower_case_e ) { TURTLE_TEST("double_lower_case_e", "TurtleTests/double_lower_case_e.ttl", "TurtleTests/double_lower_case_e.nt"); }
BOOST_AUTO_TEST_CASE( negative_numeric ) { TURTLE_TEST("negative_numeric", "TurtleTests/negative_numeric.ttl", "TurtleTests/negative_numeric.nt"); }
BOOST_AUTO_TEST_CASE( positive_numeric ) { TURTLE_TEST("positive_numeric", "TurtleTests/positive_numeric.ttl", "TurtleTests/positive_numeric.nt"); }
BOOST_AUTO_TEST_CASE( numeric_with_leading_0 ) { TURTLE_TEST("numeric_with_leading_0", "TurtleTests/numeric_with_leading_0.ttl", "TurtleTests/numeric_with_leading_0.nt"); }
BOOST_AUTO_TEST_CASE( literal_true ) { TURTLE_TEST("literal_true", "TurtleTests/literal_true.ttl", "TurtleTests/literal_true.nt"); }
BOOST_AUTO_TEST_CASE( literal_false ) { TURTLE_TEST("literal_false", "TurtleTests/literal_false.ttl", "TurtleTests/literal_false.nt"); }
BOOST_AUTO_TEST_CASE( langtagged_non_LONG ) { TURTLE_TEST("langtagged_non_LONG", "TurtleTests/langtagged_non_LONG.ttl", "TurtleTests/langtagged_non_LONG.nt"); }
BOOST_AUTO_TEST_CASE( langtagged_LONG ) { TURTLE_TEST("langtagged_LONG", "TurtleTests/langtagged_LONG.ttl", "TurtleTests/langtagged_non_LONG.nt"); }
BOOST_AUTO_TEST_CASE( lantag_with_subtag ) { TURTLE_TEST("lantag_with_subtag", "TurtleTests/lantag_with_subtag.ttl", "TurtleTests/lantag_with_subtag.nt"); }
BOOST_AUTO_TEST_CASE( objectList_with_two_objects ) { TURTLE_TEST("objectList_with_two_objects", "TurtleTests/objectList_with_two_objects.ttl", "TurtleTests/objectList_with_two_objects.nt"); }
BOOST_AUTO_TEST_CASE( predicateObjectList_with_two_objectLists ) { TURTLE_TEST("predicateObjectList_with_two_objectLists", "TurtleTests/predicateObjectList_with_two_objectLists.ttl", "TurtleTests/predicateObjectList_with_two_objectLists.nt"); }
BOOST_AUTO_TEST_CASE( repeated_semis_at_end ) { TURTLE_TEST("repeated_semis_at_end", "TurtleTests/repeated_semis_at_end.ttl", "TurtleTests/predicateObjectList_with_two_objectLists.nt"); }
BOOST_AUTO_TEST_CASE( repeated_semis_not_at_end ) { TURTLE_TEST("repeated_semis_not_at_end", "TurtleTests/repeated_semis_not_at_end.ttl", "TurtleTests/repeated_semis_not_at_end.nt"); }

BOOST_AUTO_TEST_CASE( nestedCollections ) { TURTLE_TEST("nestedCollections", "Turtle/nestedCollections.ttl", "Turtle/nestedCollections.nt"); }
BOOST_AUTO_TEST_SUITE_END(/* coverage */)

BOOST_AUTO_TEST_SUITE( turtle_eval )

BOOST_AUTO_TEST_CASE( eval_struct_01 ) { TURTLE_TEST("eval-struct-01", "TurtleTests/turtle-eval-struct-01.ttl", "TurtleTests/turtle-eval-struct-01.nt"); }
BOOST_AUTO_TEST_CASE( eval_struct_02 ) { TURTLE_TEST("eval-struct-02", "TurtleTests/turtle-eval-struct-02.ttl", "TurtleTests/turtle-eval-struct-02.nt"); }

BOOST_AUTO_TEST_CASE( subm_01 ) { TURTLE_TEST("subm-01", "TurtleTests/turtle-subm-01.ttl", "TurtleTests/turtle-subm-01.nt"); }
BOOST_AUTO_TEST_CASE( subm_02 ) { TURTLE_TEST("subm-02", "TurtleTests/turtle-subm-02.ttl", "TurtleTests/turtle-subm-02.nt"); }
BOOST_AUTO_TEST_CASE( subm_03 ) { TURTLE_TEST("subm-03", "TurtleTests/turtle-subm-03.ttl", "TurtleTests/turtle-subm-03.nt"); }
BOOST_AUTO_TEST_CASE( subm_04 ) { TURTLE_TEST("subm-04", "TurtleTests/turtle-subm-04.ttl", "TurtleTests/turtle-subm-04.nt"); }
BOOST_AUTO_TEST_CASE( subm_05 ) { TURTLE_TEST("subm-05", "TurtleTests/turtle-subm-05.ttl", "TurtleTests/turtle-subm-05.nt"); }
BOOST_AUTO_TEST_CASE( subm_06 ) { TURTLE_TEST("subm-06", "TurtleTests/turtle-subm-06.ttl", "TurtleTests/turtle-subm-06.nt"); }
BOOST_AUTO_TEST_CASE( subm_07 ) { TURTLE_TEST("subm-07", "TurtleTests/turtle-subm-07.ttl", "TurtleTests/turtle-subm-07.nt"); }
BOOST_AUTO_TEST_CASE( subm_08 ) { TURTLE_TEST("subm-08", "TurtleTests/turtle-subm-08.ttl", "TurtleTests/turtle-subm-08.nt"); }
BOOST_AUTO_TEST_CASE( subm_09 ) { TURTLE_TEST("subm-09", "TurtleTests/turtle-subm-09.ttl", "TurtleTests/turtle-subm-09.nt"); }
BOOST_AUTO_TEST_CASE( subm_10 ) { TURTLE_TEST("subm-10", "TurtleTests/turtle-subm-10.ttl", "TurtleTests/turtle-subm-10.nt"); }
BOOST_AUTO_TEST_CASE( subm_11 ) { TURTLE_TEST("subm-11", "TurtleTests/turtle-subm-11.ttl", "TurtleTests/turtle-subm-11.nt"); }
BOOST_AUTO_TEST_CASE( subm_12 ) { TURTLE_TEST("subm-12", "TurtleTests/turtle-subm-12.ttl", "TurtleTests/turtle-subm-12.nt"); }
BOOST_AUTO_TEST_CASE( subm_13 ) { TURTLE_TEST("subm-13", "TurtleTests/turtle-subm-13.ttl", "TurtleTests/turtle-subm-13.nt"); }
BOOST_AUTO_TEST_CASE( subm_14 ) { TURTLE_TEST("subm-14", "TurtleTests/turtle-subm-14.ttl", "TurtleTests/turtle-subm-14.nt"); }
BOOST_AUTO_TEST_CASE( subm_15 ) { TURTLE_TEST("subm-15", "TurtleTests/turtle-subm-15.ttl", "TurtleTests/turtle-subm-15.nt"); }
BOOST_AUTO_TEST_CASE( subm_16 ) { TURTLE_TEST("subm-16", "TurtleTests/turtle-subm-16.ttl", "TurtleTests/turtle-subm-16.nt"); }
BOOST_AUTO_TEST_CASE( subm_17 ) { TURTLE_TEST("subm-17", "TurtleTests/turtle-subm-17.ttl", "TurtleTests/turtle-subm-17.nt"); }
BOOST_AUTO_TEST_CASE( subm_18 ) { TURTLE_TEST("subm-18", "TurtleTests/turtle-subm-18.ttl", "TurtleTests/turtle-subm-18.nt"); }
BOOST_AUTO_TEST_CASE( subm_19 ) { TURTLE_TEST("subm-19", "TurtleTests/turtle-subm-19.ttl", "TurtleTests/turtle-subm-19.nt"); }
BOOST_AUTO_TEST_CASE( subm_20 ) { TURTLE_TEST("subm-20", "TurtleTests/turtle-subm-20.ttl", "TurtleTests/turtle-subm-20.nt"); }
BOOST_AUTO_TEST_CASE( subm_21 ) { TURTLE_TEST("subm-21", "TurtleTests/turtle-subm-21.ttl", "TurtleTests/turtle-subm-21.nt"); }
BOOST_AUTO_TEST_CASE( subm_22 ) { TURTLE_TEST("subm-22", "TurtleTests/turtle-subm-22.ttl", "TurtleTests/turtle-subm-22.nt"); }
BOOST_AUTO_TEST_CASE( subm_23 ) { TURTLE_TEST("subm-23", "TurtleTests/turtle-subm-23.ttl", "TurtleTests/turtle-subm-23.nt"); }
BOOST_AUTO_TEST_CASE( subm_24 ) { TURTLE_TEST("subm-24", "TurtleTests/turtle-subm-24.ttl", "TurtleTests/turtle-subm-24.nt"); }
BOOST_AUTO_TEST_CASE( subm_25 ) { TURTLE_TEST("subm-25", "TurtleTests/turtle-subm-25.ttl", "TurtleTests/turtle-subm-25.nt"); }
BOOST_AUTO_TEST_CASE( subm_26 ) { TURTLE_TEST("subm-26", "TurtleTests/turtle-subm-26.ttl", "TurtleTests/turtle-subm-26.nt"); }
BOOST_AUTO_TEST_CASE( subm_27 ) { TURTLE_TEST("subm-27", "TurtleTests/turtle-subm-27.ttl", "TurtleTests/turtle-subm-27.nt"); }
BOOST_AUTO_TEST_SUITE_END(/* turtle_eval */)

BOOST_AUTO_TEST_SUITE( turtle_syntax_positive )
#define POSITIVE_SYNTAX_TEST(TEST, TESTME)			\
    std::string baseURI(TESTME);				\
    AtomFactory::validate = AtomFactory::VALIDATE_all;		\
    baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);	\
    bool parsed = false;					\
    try {							\
	IStreamContext istr(TESTME, IStreamContext::FILE);	\
	turtleParser.setBase(baseURI);				\
	DefaultGraphPattern g;					\
	turtleParser.setGraph(&g);				\
	turtleParser.parse(istr);				\
	turtleParser.clear(BASE_URI);				\
	parsed = true;						\
    } catch (...) {						\
    }								\
    BOOST_CHECK(parsed);					\
    /*G_EARL.report(test, parsed);*/				\

BOOST_AUTO_TEST_CASE( syntax_base_01 ) { POSITIVE_SYNTAX_TEST("syntax-base-01", "TurtleTests/turtle-syntax-base-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_base_02 ) { POSITIVE_SYNTAX_TEST("syntax-base-02", "TurtleTests/turtle-syntax-base-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_base_03 ) { POSITIVE_SYNTAX_TEST("syntax-base-03", "TurtleTests/turtle-syntax-base-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_base_04 ) { POSITIVE_SYNTAX_TEST("syntax-base-04", "TurtleTests/turtle-syntax-base-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_01 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-01", "TurtleTests/turtle-syntax-bnode-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_02 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-02", "TurtleTests/turtle-syntax-bnode-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_03 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-03", "TurtleTests/turtle-syntax-bnode-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_04 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-04", "TurtleTests/turtle-syntax-bnode-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_05 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-05", "TurtleTests/turtle-syntax-bnode-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_06 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-06", "TurtleTests/turtle-syntax-bnode-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_07 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-07", "TurtleTests/turtle-syntax-bnode-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_08 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-08", "TurtleTests/turtle-syntax-bnode-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_09 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-09", "TurtleTests/turtle-syntax-bnode-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_10 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-10", "TurtleTests/turtle-syntax-bnode-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_datatypes_01 ) { POSITIVE_SYNTAX_TEST("syntax-datatypes-01", "TurtleTests/turtle-syntax-datatypes-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_datatypes_02 ) { POSITIVE_SYNTAX_TEST("syntax-datatypes-02", "TurtleTests/turtle-syntax-datatypes-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_file_01 ) { POSITIVE_SYNTAX_TEST("syntax-file-01", "TurtleTests/turtle-syntax-file-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_file_02 ) { POSITIVE_SYNTAX_TEST("syntax-file-02", "TurtleTests/turtle-syntax-file-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_file_03 ) { POSITIVE_SYNTAX_TEST("syntax-file-03", "TurtleTests/turtle-syntax-file-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_kw_01 ) { POSITIVE_SYNTAX_TEST("syntax-kw-01", "TurtleTests/turtle-syntax-kw-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_kw_02 ) { POSITIVE_SYNTAX_TEST("syntax-kw-02", "TurtleTests/turtle-syntax-kw-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_kw_03 ) { POSITIVE_SYNTAX_TEST("syntax-kw-03", "TurtleTests/turtle-syntax-kw-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_01 ) { POSITIVE_SYNTAX_TEST("syntax-lists-01", "TurtleTests/turtle-syntax-lists-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_02 ) { POSITIVE_SYNTAX_TEST("syntax-lists-02", "TurtleTests/turtle-syntax-lists-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_03 ) { POSITIVE_SYNTAX_TEST("syntax-lists-03", "TurtleTests/turtle-syntax-lists-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_04 ) { POSITIVE_SYNTAX_TEST("syntax-lists-04", "TurtleTests/turtle-syntax-lists-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_05 ) { POSITIVE_SYNTAX_TEST("syntax-lists-05", "TurtleTests/turtle-syntax-lists-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_01 ) { POSITIVE_SYNTAX_TEST("syntax-number-01", "TurtleTests/turtle-syntax-number-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_02 ) { POSITIVE_SYNTAX_TEST("syntax-number-02", "TurtleTests/turtle-syntax-number-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_03 ) { POSITIVE_SYNTAX_TEST("syntax-number-03", "TurtleTests/turtle-syntax-number-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_04 ) { POSITIVE_SYNTAX_TEST("syntax-number-04", "TurtleTests/turtle-syntax-number-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_05 ) { POSITIVE_SYNTAX_TEST("syntax-number-05", "TurtleTests/turtle-syntax-number-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_06 ) { POSITIVE_SYNTAX_TEST("syntax-number-06", "TurtleTests/turtle-syntax-number-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_07 ) { POSITIVE_SYNTAX_TEST("syntax-number-07", "TurtleTests/turtle-syntax-number-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_08 ) { POSITIVE_SYNTAX_TEST("syntax-number-08", "TurtleTests/turtle-syntax-number-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_09 ) { POSITIVE_SYNTAX_TEST("syntax-number-09", "TurtleTests/turtle-syntax-number-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_10 ) { POSITIVE_SYNTAX_TEST("syntax-number-10", "TurtleTests/turtle-syntax-number-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_11 ) { POSITIVE_SYNTAX_TEST("syntax-number-11", "TurtleTests/turtle-syntax-number-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_pname_esc_01 ) { POSITIVE_SYNTAX_TEST("syntax-pname-esc-01", "TurtleTests/turtle-syntax-pname-esc-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_pname_esc_02 ) { POSITIVE_SYNTAX_TEST("syntax-pname-esc-02", "TurtleTests/turtle-syntax-pname-esc-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_pname_esc_03 ) { POSITIVE_SYNTAX_TEST("syntax-pname-esc-03", "TurtleTests/turtle-syntax-pname-esc-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_01 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-01", "TurtleTests/turtle-syntax-prefix-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_02 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-02", "TurtleTests/turtle-syntax-prefix-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_03 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-03", "TurtleTests/turtle-syntax-prefix-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_04 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-04", "TurtleTests/turtle-syntax-prefix-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_05 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-05", "TurtleTests/turtle-syntax-prefix-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_06 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-06", "TurtleTests/turtle-syntax-prefix-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_07 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-07", "TurtleTests/turtle-syntax-prefix-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_08 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-08", "TurtleTests/turtle-syntax-prefix-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_09 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-09", "TurtleTests/turtle-syntax-prefix-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_str_esc_01 ) { POSITIVE_SYNTAX_TEST("syntax-str-esc-01", "TurtleTests/turtle-syntax-str-esc-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_str_esc_02 ) { POSITIVE_SYNTAX_TEST("syntax-str-esc-02", "TurtleTests/turtle-syntax-str-esc-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_str_esc_03 ) { POSITIVE_SYNTAX_TEST("syntax-str-esc-03", "TurtleTests/turtle-syntax-str-esc-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_01 ) { POSITIVE_SYNTAX_TEST("syntax-string-01", "TurtleTests/turtle-syntax-string-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_02 ) { POSITIVE_SYNTAX_TEST("syntax-string-02", "TurtleTests/turtle-syntax-string-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_03 ) { POSITIVE_SYNTAX_TEST("syntax-string-03", "TurtleTests/turtle-syntax-string-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_04 ) { POSITIVE_SYNTAX_TEST("syntax-string-04", "TurtleTests/turtle-syntax-string-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_05 ) { POSITIVE_SYNTAX_TEST("syntax-string-05", "TurtleTests/turtle-syntax-string-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_06 ) { POSITIVE_SYNTAX_TEST("syntax-string-06", "TurtleTests/turtle-syntax-string-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_07 ) { POSITIVE_SYNTAX_TEST("syntax-string-07", "TurtleTests/turtle-syntax-string-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_08 ) { POSITIVE_SYNTAX_TEST("syntax-string-08", "TurtleTests/turtle-syntax-string-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_09 ) { POSITIVE_SYNTAX_TEST("syntax-string-09", "TurtleTests/turtle-syntax-string-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_10 ) { POSITIVE_SYNTAX_TEST("syntax-string-10", "TurtleTests/turtle-syntax-string-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_11 ) { POSITIVE_SYNTAX_TEST("syntax-string-11", "TurtleTests/turtle-syntax-string-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_01 ) { POSITIVE_SYNTAX_TEST("syntax-struct-01", "TurtleTests/turtle-syntax-struct-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_02 ) { POSITIVE_SYNTAX_TEST("syntax-struct-02", "TurtleTests/turtle-syntax-struct-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_03 ) { POSITIVE_SYNTAX_TEST("syntax-struct-03", "TurtleTests/turtle-syntax-struct-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_04 ) { POSITIVE_SYNTAX_TEST("syntax-struct-04", "TurtleTests/turtle-syntax-struct-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_05 ) { POSITIVE_SYNTAX_TEST("syntax-struct-05", "TurtleTests/turtle-syntax-struct-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_01 ) { POSITIVE_SYNTAX_TEST("syntax-uri-01", "TurtleTests/turtle-syntax-uri-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_02 ) { POSITIVE_SYNTAX_TEST("syntax-uri-02", "TurtleTests/turtle-syntax-uri-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_03 ) { POSITIVE_SYNTAX_TEST("syntax-uri-03", "TurtleTests/turtle-syntax-uri-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_04 ) { POSITIVE_SYNTAX_TEST("syntax-uri-04", "TurtleTests/turtle-syntax-uri-04.ttl"); }
BOOST_AUTO_TEST_SUITE_END(/* turtle_syntax_positive */)

BOOST_AUTO_TEST_SUITE( turtle_syntax_negative )
#define NEGATIVE_SYNTAX_TEST(TEST, TESTME)			\
    std::string baseURI(TESTME);				\
    AtomFactory::validate = AtomFactory::VALIDATE_all;		\
    baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);	\
    bool parsed = false;					\
    try {							\
	IStreamContext istr(TESTME, IStreamContext::FILE);	\
	turtleParser.setBase(baseURI);				\
	DefaultGraphPattern g;					\
	turtleParser.setGraph(&g);				\
	turtleParser.parse(istr);				\
	turtleParser.clear(BASE_URI);				\
	parsed = true;						\
    } catch (...) {						\
    }								\
    BOOST_CHECK(!parsed);					\
    /*G_EARL.report(TEST, !parsed);*/				\

BOOST_AUTO_TEST_CASE( eval_bad_01 ) { NEGATIVE_SYNTAX_TEST("eval-bad-01", "TurtleTests/turtle-eval-bad-01.ttl"); }
BOOST_AUTO_TEST_CASE( eval_bad_02 ) { NEGATIVE_SYNTAX_TEST("eval-bad-02", "TurtleTests/turtle-eval-bad-02.ttl"); }
BOOST_AUTO_TEST_CASE( eval_bad_03 ) { NEGATIVE_SYNTAX_TEST("eval-bad-03", "TurtleTests/turtle-eval-bad-03.ttl"); }
BOOST_AUTO_TEST_CASE( eval_bad_04 ) { NEGATIVE_SYNTAX_TEST("eval-bad-04", "TurtleTests/turtle-eval-bad-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_base_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-base-01", "TurtleTests/turtle-syntax-bad-base-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_base_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-base-02", "TurtleTests/turtle-syntax-bad-base-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_base_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-base-03", "TurtleTests/turtle-syntax-bad-base-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-01", "TurtleTests/turtle-syntax-bad-esc-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-02", "TurtleTests/turtle-syntax-bad-esc-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-03", "TurtleTests/turtle-syntax-bad-esc-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-04", "TurtleTests/turtle-syntax-bad-esc-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-01", "TurtleTests/turtle-syntax-bad-kw-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-02", "TurtleTests/turtle-syntax-bad-kw-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-03", "TurtleTests/turtle-syntax-bad-kw-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-04", "TurtleTests/turtle-syntax-bad-kw-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-05", "TurtleTests/turtle-syntax-bad-kw-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_lang_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-lang-01", "TurtleTests/turtle-syntax-bad-lang-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-01", "TurtleTests/turtle-syntax-bad-n3-extras-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-02", "TurtleTests/turtle-syntax-bad-n3-extras-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-03", "TurtleTests/turtle-syntax-bad-n3-extras-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-04", "TurtleTests/turtle-syntax-bad-n3-extras-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-05", "TurtleTests/turtle-syntax-bad-n3-extras-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_06 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-06", "TurtleTests/turtle-syntax-bad-n3-extras-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_07 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-07", "TurtleTests/turtle-syntax-bad-n3-extras-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_08 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-08", "TurtleTests/turtle-syntax-bad-n3-extras-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_09 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-09", "TurtleTests/turtle-syntax-bad-n3-extras-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_10 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-10", "TurtleTests/turtle-syntax-bad-n3-extras-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_11 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-11", "TurtleTests/turtle-syntax-bad-n3-extras-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_12 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-12", "TurtleTests/turtle-syntax-bad-n3-extras-12.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_13 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-13", "TurtleTests/turtle-syntax-bad-n3-extras-13.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-01", "TurtleTests/turtle-syntax-bad-num-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-02", "TurtleTests/turtle-syntax-bad-num-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-03", "TurtleTests/turtle-syntax-bad-num-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-04", "TurtleTests/turtle-syntax-bad-num-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-05", "TurtleTests/turtle-syntax-bad-num-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_pname_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-pname-01", "TurtleTests/turtle-syntax-bad-pname-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_pname_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-pname-02", "TurtleTests/turtle-syntax-bad-pname-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_pname_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-pname-03", "TurtleTests/turtle-syntax-bad-pname-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-01", "TurtleTests/turtle-syntax-bad-prefix-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-02", "TurtleTests/turtle-syntax-bad-prefix-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-03", "TurtleTests/turtle-syntax-bad-prefix-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-04", "TurtleTests/turtle-syntax-bad-prefix-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-05", "TurtleTests/turtle-syntax-bad-prefix-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-01", "TurtleTests/turtle-syntax-bad-string-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-02", "TurtleTests/turtle-syntax-bad-string-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-03", "TurtleTests/turtle-syntax-bad-string-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-04", "TurtleTests/turtle-syntax-bad-string-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-05", "TurtleTests/turtle-syntax-bad-string-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_06 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-06", "TurtleTests/turtle-syntax-bad-string-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_07 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-07", "TurtleTests/turtle-syntax-bad-string-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-01", "TurtleTests/turtle-syntax-bad-struct-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-02", "TurtleTests/turtle-syntax-bad-struct-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-03", "TurtleTests/turtle-syntax-bad-struct-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-04", "TurtleTests/turtle-syntax-bad-struct-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-05", "TurtleTests/turtle-syntax-bad-struct-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_06 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-06", "TurtleTests/turtle-syntax-bad-struct-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_07 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-07", "TurtleTests/turtle-syntax-bad-struct-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_08 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-08", "TurtleTests/turtle-syntax-bad-struct-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_09 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-09", "TurtleTests/turtle-syntax-bad-struct-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_10 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-10", "TurtleTests/turtle-syntax-bad-struct-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_11 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-11", "TurtleTests/turtle-syntax-bad-struct-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_12 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-12", "TurtleTests/turtle-syntax-bad-struct-12.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_13 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-13", "TurtleTests/turtle-syntax-bad-struct-13.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_14 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-14", "TurtleTests/turtle-syntax-bad-struct-14.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_15 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-15", "TurtleTests/turtle-syntax-bad-struct-15.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_16 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-16", "TurtleTests/turtle-syntax-bad-struct-16.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_17 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-17", "TurtleTests/turtle-syntax-bad-struct-17.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-01", "TurtleTests/turtle-syntax-bad-uri-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-02", "TurtleTests/turtle-syntax-bad-uri-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-03", "TurtleTests/turtle-syntax-bad-uri-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-04", "TurtleTests/turtle-syntax-bad-uri-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-05", "TurtleTests/turtle-syntax-bad-uri-05.ttl"); }

BOOST_AUTO_TEST_SUITE_END(/* turtle_syntax_negative */)


/** command-line Trig tests:

from the web: no worky 'cause of https and redirects.

or from disk:
./bin/sparql -d ../../WWW/rdf/trig/tests2/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -d " ?ttl " || echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTrigPositiveSyntax ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

./bin/sparql -d ../../WWW/rdf/trig/tests2/manifest.ttl -e 'PREFIX mf: <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#> PREFIX rdft:   <http://www.w3.org/ns/rdftest#> SELECT "./bin/sparql -q -d " ?ttl " && echo fail " ?name "\n" WHERE { ?l mf:entries MEMBERS(?entry) . ?entry a rdft:TestTrigNegativeSyntax ; mf:action ?ttl ; mf:name ?name } ' -L text/raw | bash

 */


// EOF

