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

// BOOST_AUTO_TEST_SUITE( coverage )
// BOOST_AUTO_TEST_CASE( olist ) {
//     const char* defaultGraph( "generators/olist.ttl");
//     const char** namedGraphs = NULL;
//     const URI** requires = NULL;
//     DAWG_TEST("generators/olist.rq", "generators/olist.srt", 0, 0);
// }
// BOOST_AUTO_TEST_SUITE_END(/* coverage */)

BOOST_AUTO_TEST_SUITE( turtle_eval )
#define TURTLE_TEST(TEST, TESTME, EXPECT)				       \
    try {								       \
	AtomFactory::validations = AtomFactory::VALIDATE_all;		       \
	ReferenceDB tested(TESTME, NULL, 0, "http://example/base/turtle-subm-01.ttl", true);	\
	ReferenceDB expect(EXPECT, NULL, 0, "http://example/base/");			       \
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

BOOST_AUTO_TEST_CASE( eval_struct_01 ) { TURTLE_TEST("eval-struct-01", "tests-ttl/turtle-eval-struct-01.ttl", "tests-ttl/turtle-eval-struct-01.nt"); }
BOOST_AUTO_TEST_CASE( eval_struct_02 ) { TURTLE_TEST("eval-struct-02", "tests-ttl/turtle-eval-struct-02.ttl", "tests-ttl/turtle-eval-struct-02.nt"); }

BOOST_AUTO_TEST_CASE( subm_01 ) { TURTLE_TEST("subm-01", "tests-ttl/turtle-subm-01.ttl", "tests-ttl/turtle-subm-01.nt"); }
BOOST_AUTO_TEST_CASE( subm_02 ) { TURTLE_TEST("subm-02", "tests-ttl/turtle-subm-02.ttl", "tests-ttl/turtle-subm-02.nt"); }
BOOST_AUTO_TEST_CASE( subm_03 ) { TURTLE_TEST("subm-03", "tests-ttl/turtle-subm-03.ttl", "tests-ttl/turtle-subm-03.nt"); }
BOOST_AUTO_TEST_CASE( subm_04 ) { TURTLE_TEST("subm-04", "tests-ttl/turtle-subm-04.ttl", "tests-ttl/turtle-subm-04.nt"); }
BOOST_AUTO_TEST_CASE( subm_05 ) { TURTLE_TEST("subm-05", "tests-ttl/turtle-subm-05.ttl", "tests-ttl/turtle-subm-05.nt"); }
BOOST_AUTO_TEST_CASE( subm_06 ) { TURTLE_TEST("subm-06", "tests-ttl/turtle-subm-06.ttl", "tests-ttl/turtle-subm-06.nt"); }
BOOST_AUTO_TEST_CASE( subm_07 ) { TURTLE_TEST("subm-07", "tests-ttl/turtle-subm-07.ttl", "tests-ttl/turtle-subm-07.nt"); }
BOOST_AUTO_TEST_CASE( subm_08 ) { TURTLE_TEST("subm-08", "tests-ttl/turtle-subm-08.ttl", "tests-ttl/turtle-subm-08.nt"); }
BOOST_AUTO_TEST_CASE( subm_09 ) { TURTLE_TEST("subm-09", "tests-ttl/turtle-subm-09.ttl", "tests-ttl/turtle-subm-09.nt"); }
BOOST_AUTO_TEST_CASE( subm_10 ) { TURTLE_TEST("subm-10", "tests-ttl/turtle-subm-10.ttl", "tests-ttl/turtle-subm-10.nt"); }
BOOST_AUTO_TEST_CASE( subm_11 ) { TURTLE_TEST("subm-11", "tests-ttl/turtle-subm-11.ttl", "tests-ttl/turtle-subm-11.nt"); }
BOOST_AUTO_TEST_CASE( subm_12 ) { TURTLE_TEST("subm-12", "tests-ttl/turtle-subm-12.ttl", "tests-ttl/turtle-subm-12.nt"); }
BOOST_AUTO_TEST_CASE( subm_13 ) { TURTLE_TEST("subm-13", "tests-ttl/turtle-subm-13.ttl", "tests-ttl/turtle-subm-13.nt"); }
BOOST_AUTO_TEST_CASE( subm_14 ) { TURTLE_TEST("subm-14", "tests-ttl/turtle-subm-14.ttl", "tests-ttl/turtle-subm-14.nt"); }
BOOST_AUTO_TEST_CASE( subm_15 ) { TURTLE_TEST("subm-15", "tests-ttl/turtle-subm-15.ttl", "tests-ttl/turtle-subm-15.nt"); }
BOOST_AUTO_TEST_CASE( subm_16 ) { TURTLE_TEST("subm-16", "tests-ttl/turtle-subm-16.ttl", "tests-ttl/turtle-subm-16.nt"); }
BOOST_AUTO_TEST_CASE( subm_17 ) { TURTLE_TEST("subm-17", "tests-ttl/turtle-subm-17.ttl", "tests-ttl/turtle-subm-17.nt"); }
BOOST_AUTO_TEST_CASE( subm_18 ) { TURTLE_TEST("subm-18", "tests-ttl/turtle-subm-18.ttl", "tests-ttl/turtle-subm-18.nt"); }
BOOST_AUTO_TEST_CASE( subm_19 ) { TURTLE_TEST("subm-19", "tests-ttl/turtle-subm-19.ttl", "tests-ttl/turtle-subm-19.nt"); }
BOOST_AUTO_TEST_CASE( subm_20 ) { TURTLE_TEST("subm-20", "tests-ttl/turtle-subm-20.ttl", "tests-ttl/turtle-subm-20.nt"); }
BOOST_AUTO_TEST_CASE( subm_21 ) { TURTLE_TEST("subm-21", "tests-ttl/turtle-subm-21.ttl", "tests-ttl/turtle-subm-21.nt"); }
BOOST_AUTO_TEST_CASE( subm_22 ) { TURTLE_TEST("subm-22", "tests-ttl/turtle-subm-22.ttl", "tests-ttl/turtle-subm-22.nt"); }
BOOST_AUTO_TEST_CASE( subm_23 ) { TURTLE_TEST("subm-23", "tests-ttl/turtle-subm-23.ttl", "tests-ttl/turtle-subm-23.nt"); }
BOOST_AUTO_TEST_CASE( subm_24 ) { TURTLE_TEST("subm-24", "tests-ttl/turtle-subm-24.ttl", "tests-ttl/turtle-subm-24.nt"); }
BOOST_AUTO_TEST_CASE( subm_25 ) { TURTLE_TEST("subm-25", "tests-ttl/turtle-subm-25.ttl", "tests-ttl/turtle-subm-25.nt"); }
BOOST_AUTO_TEST_CASE( subm_26 ) { TURTLE_TEST("subm-26", "tests-ttl/turtle-subm-26.ttl", "tests-ttl/turtle-subm-26.nt"); }
BOOST_AUTO_TEST_CASE( subm_27 ) { TURTLE_TEST("subm-27", "tests-ttl/turtle-subm-27.ttl", "tests-ttl/turtle-subm-27.nt"); }
BOOST_AUTO_TEST_SUITE_END(/* turtle_eval */)

BOOST_AUTO_TEST_SUITE( turtle_syntax_positive )
#define POSITIVE_SYNTAX_TEST(TEST, TESTME)			\
    std::string baseURI(TESTME);				\
    AtomFactory::validations = AtomFactory::VALIDATE_all;	\
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

BOOST_AUTO_TEST_CASE( syntax_base_01 ) { POSITIVE_SYNTAX_TEST("syntax-base-01", "tests-ttl/turtle-syntax-base-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_base_02 ) { POSITIVE_SYNTAX_TEST("syntax-base-02", "tests-ttl/turtle-syntax-base-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_base_03 ) { POSITIVE_SYNTAX_TEST("syntax-base-03", "tests-ttl/turtle-syntax-base-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_base_04 ) { POSITIVE_SYNTAX_TEST("syntax-base-04", "tests-ttl/turtle-syntax-base-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_01 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-01", "tests-ttl/turtle-syntax-bnode-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_02 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-02", "tests-ttl/turtle-syntax-bnode-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_03 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-03", "tests-ttl/turtle-syntax-bnode-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_04 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-04", "tests-ttl/turtle-syntax-bnode-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_05 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-05", "tests-ttl/turtle-syntax-bnode-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_06 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-06", "tests-ttl/turtle-syntax-bnode-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_07 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-07", "tests-ttl/turtle-syntax-bnode-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_08 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-08", "tests-ttl/turtle-syntax-bnode-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_09 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-09", "tests-ttl/turtle-syntax-bnode-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bnode_10 ) { POSITIVE_SYNTAX_TEST("syntax-bnode-10", "tests-ttl/turtle-syntax-bnode-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_datatypes_01 ) { POSITIVE_SYNTAX_TEST("syntax-datatypes-01", "tests-ttl/turtle-syntax-datatypes-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_datatypes_02 ) { POSITIVE_SYNTAX_TEST("syntax-datatypes-02", "tests-ttl/turtle-syntax-datatypes-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_file_01 ) { POSITIVE_SYNTAX_TEST("syntax-file-01", "tests-ttl/turtle-syntax-file-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_file_02 ) { POSITIVE_SYNTAX_TEST("syntax-file-02", "tests-ttl/turtle-syntax-file-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_file_03 ) { POSITIVE_SYNTAX_TEST("syntax-file-03", "tests-ttl/turtle-syntax-file-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_kw_01 ) { POSITIVE_SYNTAX_TEST("syntax-kw-01", "tests-ttl/turtle-syntax-kw-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_kw_02 ) { POSITIVE_SYNTAX_TEST("syntax-kw-02", "tests-ttl/turtle-syntax-kw-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_kw_03 ) { POSITIVE_SYNTAX_TEST("syntax-kw-03", "tests-ttl/turtle-syntax-kw-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_01 ) { POSITIVE_SYNTAX_TEST("syntax-lists-01", "tests-ttl/turtle-syntax-lists-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_02 ) { POSITIVE_SYNTAX_TEST("syntax-lists-02", "tests-ttl/turtle-syntax-lists-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_03 ) { POSITIVE_SYNTAX_TEST("syntax-lists-03", "tests-ttl/turtle-syntax-lists-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_04 ) { POSITIVE_SYNTAX_TEST("syntax-lists-04", "tests-ttl/turtle-syntax-lists-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_lists_05 ) { POSITIVE_SYNTAX_TEST("syntax-lists-05", "tests-ttl/turtle-syntax-lists-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_01 ) { POSITIVE_SYNTAX_TEST("syntax-number-01", "tests-ttl/turtle-syntax-number-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_02 ) { POSITIVE_SYNTAX_TEST("syntax-number-02", "tests-ttl/turtle-syntax-number-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_03 ) { POSITIVE_SYNTAX_TEST("syntax-number-03", "tests-ttl/turtle-syntax-number-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_04 ) { POSITIVE_SYNTAX_TEST("syntax-number-04", "tests-ttl/turtle-syntax-number-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_05 ) { POSITIVE_SYNTAX_TEST("syntax-number-05", "tests-ttl/turtle-syntax-number-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_06 ) { POSITIVE_SYNTAX_TEST("syntax-number-06", "tests-ttl/turtle-syntax-number-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_07 ) { POSITIVE_SYNTAX_TEST("syntax-number-07", "tests-ttl/turtle-syntax-number-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_08 ) { POSITIVE_SYNTAX_TEST("syntax-number-08", "tests-ttl/turtle-syntax-number-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_09 ) { POSITIVE_SYNTAX_TEST("syntax-number-09", "tests-ttl/turtle-syntax-number-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_10 ) { POSITIVE_SYNTAX_TEST("syntax-number-10", "tests-ttl/turtle-syntax-number-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_number_11 ) { POSITIVE_SYNTAX_TEST("syntax-number-11", "tests-ttl/turtle-syntax-number-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_pname_esc_01 ) { POSITIVE_SYNTAX_TEST("syntax-pname-esc-01", "tests-ttl/turtle-syntax-pname-esc-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_pname_esc_02 ) { POSITIVE_SYNTAX_TEST("syntax-pname-esc-02", "tests-ttl/turtle-syntax-pname-esc-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_pname_esc_03 ) { POSITIVE_SYNTAX_TEST("syntax-pname-esc-03", "tests-ttl/turtle-syntax-pname-esc-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_01 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-01", "tests-ttl/turtle-syntax-prefix-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_02 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-02", "tests-ttl/turtle-syntax-prefix-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_03 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-03", "tests-ttl/turtle-syntax-prefix-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_04 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-04", "tests-ttl/turtle-syntax-prefix-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_05 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-05", "tests-ttl/turtle-syntax-prefix-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_06 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-06", "tests-ttl/turtle-syntax-prefix-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_07 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-07", "tests-ttl/turtle-syntax-prefix-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_08 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-08", "tests-ttl/turtle-syntax-prefix-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_prefix_09 ) { POSITIVE_SYNTAX_TEST("syntax-prefix-09", "tests-ttl/turtle-syntax-prefix-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_str_esc_01 ) { POSITIVE_SYNTAX_TEST("syntax-str-esc-01", "tests-ttl/turtle-syntax-str-esc-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_str_esc_02 ) { POSITIVE_SYNTAX_TEST("syntax-str-esc-02", "tests-ttl/turtle-syntax-str-esc-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_str_esc_03 ) { POSITIVE_SYNTAX_TEST("syntax-str-esc-03", "tests-ttl/turtle-syntax-str-esc-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_01 ) { POSITIVE_SYNTAX_TEST("syntax-string-01", "tests-ttl/turtle-syntax-string-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_02 ) { POSITIVE_SYNTAX_TEST("syntax-string-02", "tests-ttl/turtle-syntax-string-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_03 ) { POSITIVE_SYNTAX_TEST("syntax-string-03", "tests-ttl/turtle-syntax-string-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_04 ) { POSITIVE_SYNTAX_TEST("syntax-string-04", "tests-ttl/turtle-syntax-string-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_05 ) { POSITIVE_SYNTAX_TEST("syntax-string-05", "tests-ttl/turtle-syntax-string-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_06 ) { POSITIVE_SYNTAX_TEST("syntax-string-06", "tests-ttl/turtle-syntax-string-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_07 ) { POSITIVE_SYNTAX_TEST("syntax-string-07", "tests-ttl/turtle-syntax-string-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_08 ) { POSITIVE_SYNTAX_TEST("syntax-string-08", "tests-ttl/turtle-syntax-string-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_09 ) { POSITIVE_SYNTAX_TEST("syntax-string-09", "tests-ttl/turtle-syntax-string-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_10 ) { POSITIVE_SYNTAX_TEST("syntax-string-10", "tests-ttl/turtle-syntax-string-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_string_11 ) { POSITIVE_SYNTAX_TEST("syntax-string-11", "tests-ttl/turtle-syntax-string-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_01 ) { POSITIVE_SYNTAX_TEST("syntax-struct-01", "tests-ttl/turtle-syntax-struct-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_02 ) { POSITIVE_SYNTAX_TEST("syntax-struct-02", "tests-ttl/turtle-syntax-struct-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_03 ) { POSITIVE_SYNTAX_TEST("syntax-struct-03", "tests-ttl/turtle-syntax-struct-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_04 ) { POSITIVE_SYNTAX_TEST("syntax-struct-04", "tests-ttl/turtle-syntax-struct-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_struct_05 ) { POSITIVE_SYNTAX_TEST("syntax-struct-05", "tests-ttl/turtle-syntax-struct-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_01 ) { POSITIVE_SYNTAX_TEST("syntax-uri-01", "tests-ttl/turtle-syntax-uri-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_02 ) { POSITIVE_SYNTAX_TEST("syntax-uri-02", "tests-ttl/turtle-syntax-uri-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_03 ) { POSITIVE_SYNTAX_TEST("syntax-uri-03", "tests-ttl/turtle-syntax-uri-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_uri_04 ) { POSITIVE_SYNTAX_TEST("syntax-uri-04", "tests-ttl/turtle-syntax-uri-04.ttl"); }
BOOST_AUTO_TEST_SUITE_END(/* turtle_syntax_positive */)

BOOST_AUTO_TEST_SUITE( turtle_syntax_negative )
#define NEGATIVE_SYNTAX_TEST(TEST, TESTME)			\
    std::string baseURI(TESTME);				\
    AtomFactory::validations = AtomFactory::VALIDATE_all;	\
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

BOOST_AUTO_TEST_CASE( eval_bad_01 ) { NEGATIVE_SYNTAX_TEST("eval-bad-01", "tests-ttl/turtle-eval-bad-01.ttl"); }
BOOST_AUTO_TEST_CASE( eval_bad_02 ) { NEGATIVE_SYNTAX_TEST("eval-bad-02", "tests-ttl/turtle-eval-bad-02.ttl"); }
BOOST_AUTO_TEST_CASE( eval_bad_03 ) { NEGATIVE_SYNTAX_TEST("eval-bad-03", "tests-ttl/turtle-eval-bad-03.ttl"); }
BOOST_AUTO_TEST_CASE( eval_bad_04 ) { NEGATIVE_SYNTAX_TEST("eval-bad-04", "tests-ttl/turtle-eval-bad-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_base_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-base-01", "tests-ttl/turtle-syntax-bad-base-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_base_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-base-02", "tests-ttl/turtle-syntax-bad-base-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_base_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-base-03", "tests-ttl/turtle-syntax-bad-base-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-01", "tests-ttl/turtle-syntax-bad-esc-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-02", "tests-ttl/turtle-syntax-bad-esc-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-03", "tests-ttl/turtle-syntax-bad-esc-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_esc_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-esc-04", "tests-ttl/turtle-syntax-bad-esc-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-01", "tests-ttl/turtle-syntax-bad-kw-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-02", "tests-ttl/turtle-syntax-bad-kw-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-03", "tests-ttl/turtle-syntax-bad-kw-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-04", "tests-ttl/turtle-syntax-bad-kw-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_kw_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-kw-05", "tests-ttl/turtle-syntax-bad-kw-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_lang_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-lang-01", "tests-ttl/turtle-syntax-bad-lang-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-01", "tests-ttl/turtle-syntax-bad-n3-extras-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-02", "tests-ttl/turtle-syntax-bad-n3-extras-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-03", "tests-ttl/turtle-syntax-bad-n3-extras-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-04", "tests-ttl/turtle-syntax-bad-n3-extras-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-05", "tests-ttl/turtle-syntax-bad-n3-extras-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_06 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-06", "tests-ttl/turtle-syntax-bad-n3-extras-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_07 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-07", "tests-ttl/turtle-syntax-bad-n3-extras-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_08 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-08", "tests-ttl/turtle-syntax-bad-n3-extras-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_09 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-09", "tests-ttl/turtle-syntax-bad-n3-extras-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_10 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-10", "tests-ttl/turtle-syntax-bad-n3-extras-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_11 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-11", "tests-ttl/turtle-syntax-bad-n3-extras-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_12 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-12", "tests-ttl/turtle-syntax-bad-n3-extras-12.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_n3_extras_13 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-n3-extras-13", "tests-ttl/turtle-syntax-bad-n3-extras-13.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-01", "tests-ttl/turtle-syntax-bad-num-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-02", "tests-ttl/turtle-syntax-bad-num-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-03", "tests-ttl/turtle-syntax-bad-num-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-04", "tests-ttl/turtle-syntax-bad-num-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_num_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-num-05", "tests-ttl/turtle-syntax-bad-num-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_pname_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-pname-01", "tests-ttl/turtle-syntax-bad-pname-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_pname_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-pname-02", "tests-ttl/turtle-syntax-bad-pname-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_pname_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-pname-03", "tests-ttl/turtle-syntax-bad-pname-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-01", "tests-ttl/turtle-syntax-bad-prefix-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-02", "tests-ttl/turtle-syntax-bad-prefix-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-03", "tests-ttl/turtle-syntax-bad-prefix-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-04", "tests-ttl/turtle-syntax-bad-prefix-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_prefix_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-prefix-05", "tests-ttl/turtle-syntax-bad-prefix-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-01", "tests-ttl/turtle-syntax-bad-string-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-02", "tests-ttl/turtle-syntax-bad-string-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-03", "tests-ttl/turtle-syntax-bad-string-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-04", "tests-ttl/turtle-syntax-bad-string-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-05", "tests-ttl/turtle-syntax-bad-string-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_06 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-06", "tests-ttl/turtle-syntax-bad-string-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_string_07 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-string-07", "tests-ttl/turtle-syntax-bad-string-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-01", "tests-ttl/turtle-syntax-bad-struct-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-02", "tests-ttl/turtle-syntax-bad-struct-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-03", "tests-ttl/turtle-syntax-bad-struct-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-04", "tests-ttl/turtle-syntax-bad-struct-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-05", "tests-ttl/turtle-syntax-bad-struct-05.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_06 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-06", "tests-ttl/turtle-syntax-bad-struct-06.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_07 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-07", "tests-ttl/turtle-syntax-bad-struct-07.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_08 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-08", "tests-ttl/turtle-syntax-bad-struct-08.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_09 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-09", "tests-ttl/turtle-syntax-bad-struct-09.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_10 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-10", "tests-ttl/turtle-syntax-bad-struct-10.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_11 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-11", "tests-ttl/turtle-syntax-bad-struct-11.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_12 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-12", "tests-ttl/turtle-syntax-bad-struct-12.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_13 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-13", "tests-ttl/turtle-syntax-bad-struct-13.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_14 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-14", "tests-ttl/turtle-syntax-bad-struct-14.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_15 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-15", "tests-ttl/turtle-syntax-bad-struct-15.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_16 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-16", "tests-ttl/turtle-syntax-bad-struct-16.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_struct_17 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-struct-17", "tests-ttl/turtle-syntax-bad-struct-17.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_01 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-01", "tests-ttl/turtle-syntax-bad-uri-01.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_02 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-02", "tests-ttl/turtle-syntax-bad-uri-02.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_03 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-03", "tests-ttl/turtle-syntax-bad-uri-03.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_04 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-04", "tests-ttl/turtle-syntax-bad-uri-04.ttl"); }
BOOST_AUTO_TEST_CASE( syntax_bad_uri_05 ) { NEGATIVE_SYNTAX_TEST("syntax-bad-uri-05", "tests-ttl/turtle-syntax-bad-uri-05.ttl"); }

BOOST_AUTO_TEST_SUITE_END(/* turtle_syntax_negative */)

// EOF

