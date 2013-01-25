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
	turtleParser.trace_parsing = false;
	turtleParser.trace_scanning = false;
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
	 "<s2> <p2> . :1.8: syntax error, unexpected '.'\n"
	 "-- \n"
	 "<s> <p> .\n"
	 "<s2> <p2> . :2.10: syntax error, unexpected '.'",
	 NULL, // no expected triples
	 0, 2);
}
BOOST_AUTO_TEST_CASE( extra_spo_objects ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> 'o2' 'o2bis'. ",
	 "<s> <p> <o><obis>.<s2> <p2> 'o2' 'o2bis'. :1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> 'o2' 'o2bis'. :1.33-39: syntax error, unexpected 'string', expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> 'o2'        . ", 0, 2);
}
BOOST_AUTO_TEST_CASE( _1_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .                                            ", 1, 1);
}
BOOST_AUTO_TEST_CASE( _2_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.28-38: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> <o2>       .                      ", 2, 2);
}
BOOST_AUTO_TEST_CASE( _3_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.28-38: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.50-60: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> <o2>       .<s3> <p3> <o3>       .", 3, 3);
}
BOOST_AUTO_TEST_CASE( _all_of_3_errors ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.",
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.28-38: syntax error, unexpected IRI, expecting '.' or ';' or ']'\n"
	 "<s> <p> <o><obis>.<s2> <p2> <o2><o2bis>.<s3> <p3> <o3><o3bis>.:1.50-60: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>      .<s2> <p2> <o2>       .<s3> <p3> <o3>       .", 0, 3);
}
BOOST_AUTO_TEST_CASE( extra_po_objects_before_comma ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>, <o2>. ",
	 "<s> <p> <o><obis>, <o2>. :1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>, <o2>. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( extra_po_objects_before_semi ) { ERROR_RECOVERY_TEST
	("<s> <p> <o><obis>; <p2> <o2>. ",
	 "<s> <p> <o><obis>; <p2> <o2>. :1.8-16: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> <o>; <p2> <o2>. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( extra_po_objects ) { ERROR_RECOVERY_TEST
	("<s> <p> [ <p2> <o2><o2bis> ]. ",
	 "<s> <p> [ <p2> <o2><o2bis> ]. :1.15-25: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> [ <p2> <o2>        ]. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( extra_po_objects_plus ) { ERROR_RECOVERY_TEST
	("<s> <p> [ <p2> <o2><o2bis> ; <p3> <o3> ]. ",
	 "<s> <p> [ <p2> <o2><o2bis> ; <p3> <o3> ]. :1.15-25: syntax error, unexpected IRI, expecting '.' or ';' or ']'",
	 "<s> <p> [ <p2> <o2>        ; <p3> <o3> ]. ", 0, 1);
}
BOOST_AUTO_TEST_CASE( unterminated_url ) { ERROR_RECOVERY_TEST
	("<s1> <p1> 'o1 . <s2> <p2> <o2>.<s3> <p3> <o3 .",
	 "<s1> <p1> 'o1 . <s2> <p2> <o2>.<s3> <p3> <o3 .:1.10-12: malformed single-quoted simple literal \"'o1\"\n"
	 "<s1> <p1> 'o1 . <s2> <p2> <o2>.<s3> <p3> <o3 .:1.41-43: malformed IRI \"<o3\"",
	 "<s1> <p1> 'o1'. <s2> <p2> <o2>.<s3> <p3> <o3>.", 0, 2);
}
BOOST_AUTO_TEST_CASE( commas_and_semis ) { ERROR_RECOVERY_TEST
	("<s1> <p1> 'o1a', 'o1b ; <o2>.",
	 "<s1> <p1> 'o1a', 'o1b ; <o2>.:1.17-20: malformed single-quoted simple literal \"'o1b\"\n"
	 "<s1> <p1> 'o1a', 'o1b ; <o2>.:1.24-28: syntax error, unexpected '.'", // @@ improving the error grammar should eliminate this.
	 "<s1> <p1> 'o1a', 'o1b';     .", 0, 2);
}
BOOST_AUTO_TEST_CASE( undefined_prefixes ) { ERROR_RECOVERY_TEST
	("PREFIX x: <x#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .",

	 "PREFIX x: <x#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .:2.15-3.3: Unknown prefix: \"y\" (2 more times)\n"
	 "-- \n"
	 "PREFIX x: <x#>\n"
	 "x:s1 x:p1 x:o1 .\n"
	 "y:s2 y:p2 :o2 .:3.10-12: Unknown prefix: \"\"",

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
	ReferenceDB tested(TESTME, NULL, 0, "http://example/base/turtle-subm-01.ttl", true);	\
	ReferenceDB expect(EXPECT, NULL, 0, "http://example/base/");	       \
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

BOOST_AUTO_TEST_SUITE( coverage )
BOOST_AUTO_TEST_CASE( IRI_subject ) { TURTLE_TEST("IRI_subject", "tests-coverage/IRI_subject.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( IRI_with_four_digit_numeric_escape ) { TURTLE_TEST("IRI_with_four_digit_numeric_escape", "tests-coverage/IRI_with_four_digit_numeric_escape.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( IRI_with_eight_digit_numeric_escape ) { TURTLE_TEST("IRI_with_eight_digit_numeric_escape", "tests-coverage/IRI_with_eight_digit_numeric_escape.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( IRI_with_all_punctuation ) { TURTLE_TEST("IRI_with_all_punctuation", "tests-coverage/IRI_with_all_punctuation.ttl", "tests-coverage/IRI_with_all_punctuation.nt"); }
BOOST_AUTO_TEST_CASE( bareword_a_predicate ) { TURTLE_TEST("bareword_a_predicate", "tests-coverage/bareword_a_predicate.ttl", "tests-coverage/bareword_a_predicate.nt"); }
BOOST_AUTO_TEST_CASE( old_style_prefix ) { TURTLE_TEST("old_style_prefix", "tests-coverage/old_style_prefix.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( SPARQL_style_prefix ) { TURTLE_TEST("SPARQL_style_prefix", "tests-coverage/SPARQL_style_prefix.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( prefixed_IRI_predicate ) { TURTLE_TEST("prefixed_IRI_predicate", "tests-coverage/prefixed_IRI_predicate.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( prefixed_IRI_object ) { TURTLE_TEST("prefixed_IRI_object", "tests-coverage/prefixed_IRI_object.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( prefix_only_IRI ) { TURTLE_TEST("prefix_only_IRI", "tests-coverage/prefix_only_IRI.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( default_namespace_IRI ) { TURTLE_TEST("default_namespace_IRI", "tests-coverage/default_namespace_IRI.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( prefix_reassigned_and_used ) { TURTLE_TEST("prefix_reassigned_and_used", "tests-coverage/prefix_reassigned_and_used.ttl", "tests-coverage/prefix_reassigned_and_used.nt"); }
BOOST_AUTO_TEST_CASE( reserved_escaped_local_name ) { TURTLE_TEST("reserved_escaped_local_name", "tests-coverage/reserved_escaped_local_name.ttl", "tests-coverage/reserved_escaped_local_name.nt"); }
BOOST_AUTO_TEST_CASE( percent_escaped_local_name ) { TURTLE_TEST("percent_escaped_local_name", "tests-coverage/percent_escaped_local_name.ttl", "tests-coverage/percent_escaped_local_name.nt"); }
BOOST_AUTO_TEST_CASE( HYPHEN_MINUS_in_local_name ) { TURTLE_TEST("HYPHEN_MINUS_in_local_name", "tests-coverage/HYPHEN_MINUS_in_local_name.ttl", "tests-coverage/HYPHEN_MINUS_in_local_name.nt"); }
BOOST_AUTO_TEST_CASE( underscore_in_local_name ) { TURTLE_TEST("underscore_in_local_name", "tests-coverage/underscore_in_local_name.ttl", "tests-coverage/underscore_in_local_name.nt"); }
BOOST_AUTO_TEST_CASE( localname_with_COLON ) { TURTLE_TEST("localname_with_COLON", "tests-coverage/localname_with_COLON.ttl", "tests-coverage/localname_with_COLON.nt"); }
BOOST_AUTO_TEST_CASE( old_style_base ) { TURTLE_TEST("old_style_base", "tests-coverage/old_style_base.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( SPARQL_style_base ) { TURTLE_TEST("SPARQL_style_base", "tests-coverage/SPARQL_style_base.ttl", "tests-coverage/IRI_subject.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_subject ) { TURTLE_TEST("labeled_blank_node_subject", "tests-coverage/labeled_blank_node_subject.ttl", "tests-coverage/labeled_blank_node_subject.nt"); }
BOOST_AUTO_TEST_CASE( labeled_blank_node_object ) { TURTLE_TEST("labeled_blank_node_object", "tests-coverage/labeled_blank_node_object.ttl", "tests-coverage/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( anonymous_blank_node_subject ) { TURTLE_TEST("anonymous_blank_node_subject", "tests-coverage/anonymous_blank_node_subject.ttl", "tests-coverage/labeled_blank_node_subject.nt"); }
BOOST_AUTO_TEST_CASE( anonymous_blank_node_object ) { TURTLE_TEST("anonymous_blank_node_object", "tests-coverage/anonymous_blank_node_object.ttl", "tests-coverage/labeled_blank_node_object.nt"); }
BOOST_AUTO_TEST_CASE( sole_blankNodePropertyList ) { TURTLE_TEST("sole_blankNodePropertyList", "tests-coverage/sole_blankNodePropertyList.ttl", "tests-coverage/labeled_blank_node_subject.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_as_subject ) { TURTLE_TEST("blankNodePropertyList_as_subject", "tests-coverage/blankNodePropertyList_as_subject.ttl", "tests-coverage/blankNodePropertyList_as_subject.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_as_object ) { TURTLE_TEST("blankNodePropertyList_as_object", "tests-coverage/blankNodePropertyList_as_object.ttl", "tests-coverage/blankNodePropertyList_as_object.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_with_multiple_triples ) { TURTLE_TEST("blankNodePropertyList_with_multiple_triples", "tests-coverage/blankNodePropertyList_with_multiple_triples.ttl", "tests-coverage/blankNodePropertyList_with_multiple_triples.nt"); }
BOOST_AUTO_TEST_CASE( nested_blankNodePropertyLists ) { TURTLE_TEST("nested_blankNodePropertyLists", "tests-coverage/nested_blankNodePropertyLists.ttl", "tests-coverage/nested_blankNodePropertyLists.nt"); }
BOOST_AUTO_TEST_CASE( blankNodePropertyList_containing_collection ) { TURTLE_TEST("blankNodePropertyList_containing_collection", "tests-coverage/blankNodePropertyList_containing_collection.ttl", "tests-coverage/blankNodePropertyList_containing_collection.nt"); }
BOOST_AUTO_TEST_CASE( collection_subject ) { TURTLE_TEST("collection_subject", "tests-coverage/collection_subject.ttl", "tests-coverage/collection_subject.nt"); }
BOOST_AUTO_TEST_CASE( collection_object ) { TURTLE_TEST("collection_object", "tests-coverage/collection_object.ttl", "tests-coverage/collection_object.nt"); }
BOOST_AUTO_TEST_CASE( empty_collection ) { TURTLE_TEST("empty_collection", "tests-coverage/empty_collection.ttl", "tests-coverage/empty_collection.nt"); }
BOOST_AUTO_TEST_CASE( nested_collection ) { TURTLE_TEST("nested_collection", "tests-coverage/nested_collection.ttl", "tests-coverage/nested_collection.nt"); }
BOOST_AUTO_TEST_CASE( first ) { TURTLE_TEST("first", "tests-coverage/first.ttl", "tests-coverage/first.nt"); }
BOOST_AUTO_TEST_CASE( last ) { TURTLE_TEST("last", "tests-coverage/last.ttl", "tests-coverage/last.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL1 ) { TURTLE_TEST("LITERAL1", "tests-coverage/LITERAL1.ttl", "tests-coverage/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1 ) { TURTLE_TEST("LITERAL_LONG1", "tests-coverage/LITERAL_LONG1.ttl", "tests-coverage/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1_with_1_squote ) { TURTLE_TEST("LITERAL_LONG1_with_1_squote", "tests-coverage/LITERAL_LONG1_with_1_squote.ttl", "tests-coverage/LITERAL_LONG1_with_1_squote.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG1_with_2_squotes ) { TURTLE_TEST("LITERAL_LONG1_with_2_squotes", "tests-coverage/LITERAL_LONG1_with_2_squotes.ttl", "tests-coverage/LITERAL_LONG1_with_2_squotes.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL2 ) { TURTLE_TEST("LITERAL2", "tests-coverage/LITERAL2.ttl", "tests-coverage/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2 ) { TURTLE_TEST("LITERAL_LONG2", "tests-coverage/LITERAL_LONG2.ttl", "tests-coverage/LITERAL1.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2_with_1_squote ) { TURTLE_TEST("LITERAL_LONG2_with_1_squote", "tests-coverage/LITERAL_LONG2_with_1_squote.ttl", "tests-coverage/LITERAL_LONG2_with_1_squote.nt"); }
BOOST_AUTO_TEST_CASE( LITERAL_LONG2_with_2_squotes ) { TURTLE_TEST("LITERAL_LONG2_with_2_squotes", "tests-coverage/LITERAL_LONG2_with_2_squotes.ttl", "tests-coverage/LITERAL_LONG2_with_2_squotes.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_CHARACTER_TABULATION ) { TURTLE_TEST("literal_with_CHARACTER_TABULATION", "tests-coverage/literal_with_CHARACTER_TABULATION.ttl", "tests-coverage/literal_with_CHARACTER_TABULATION.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_BACKSPACE ) { TURTLE_TEST("literal_with_BACKSPACE", "tests-coverage/literal_with_BACKSPACE.ttl", "tests-coverage/literal_with_BACKSPACE.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_LINE_FEED ) { TURTLE_TEST("literal_with_LINE_FEED", "tests-coverage/literal_with_LINE_FEED.ttl", "tests-coverage/literal_with_LINE_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_CARRIAGE_RETURN ) { TURTLE_TEST("literal_with_CARRIAGE_RETURN", "tests-coverage/literal_with_CARRIAGE_RETURN.ttl", "tests-coverage/literal_with_CARRIAGE_RETURN.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_FORM_FEED ) { TURTLE_TEST("literal_with_FORM_FEED", "tests-coverage/literal_with_FORM_FEED.ttl", "tests-coverage/literal_with_FORM_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_REVERSE_SOLIDUS ) { TURTLE_TEST("literal_with_REVERSE_SOLIDUS", "tests-coverage/literal_with_REVERSE_SOLIDUS.ttl", "tests-coverage/literal_with_REVERSE_SOLIDUS.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_CHARACTER_TABULATION ) { TURTLE_TEST("literal_with_escaped_CHARACTER_TABULATION", "tests-coverage/literal_with_escaped_CHARACTER_TABULATION.ttl", "tests-coverage/literal_with_CHARACTER_TABULATION.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_BACKSPACE ) { TURTLE_TEST("literal_with_escaped_BACKSPACE", "tests-coverage/literal_with_escaped_BACKSPACE.ttl", "tests-coverage/literal_with_BACKSPACE.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_LINE_FEED ) { TURTLE_TEST("literal_with_escaped_LINE_FEED", "tests-coverage/literal_with_escaped_LINE_FEED.ttl", "tests-coverage/literal_with_LINE_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_CARRIAGE_RETURN ) { TURTLE_TEST("literal_with_escaped_CARRIAGE_RETURN", "tests-coverage/literal_with_escaped_CARRIAGE_RETURN.ttl", "tests-coverage/literal_with_CARRIAGE_RETURN.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_escaped_FORM_FEED ) { TURTLE_TEST("literal_with_escaped_FORM_FEED", "tests-coverage/literal_with_escaped_FORM_FEED.ttl", "tests-coverage/literal_with_FORM_FEED.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_numeric_escape4 ) { TURTLE_TEST("literal_with_numeric_escape4", "tests-coverage/literal_with_numeric_escape4.ttl", "tests-coverage/literal_with_numeric_escape4.nt"); }
BOOST_AUTO_TEST_CASE( literal_with_numeric_escape8 ) { TURTLE_TEST("literal_with_numeric_escape8", "tests-coverage/literal_with_numeric_escape8.ttl", "tests-coverage/literal_with_numeric_escape4.nt"); }
BOOST_AUTO_TEST_CASE( IRIREF_datatype ) { TURTLE_TEST("IRIREF_datatype", "tests-coverage/IRIREF_datatype.ttl", "tests-coverage/IRIREF_datatype.nt"); }
BOOST_AUTO_TEST_CASE( prefixed_name_datatype ) { TURTLE_TEST("prefixed_name_datatype", "tests-coverage/prefixed_name_datatype.ttl", "tests-coverage/IRIREF_datatype.nt"); }
BOOST_AUTO_TEST_CASE( bareword_integer ) { TURTLE_TEST("bareword_integer", "tests-coverage/bareword_integer.ttl", "tests-coverage/IRIREF_datatype.nt"); }
BOOST_AUTO_TEST_CASE( bareword_decimal ) { TURTLE_TEST("bareword_decimal", "tests-coverage/bareword_decimal.ttl", "tests-coverage/bareword_decimal.nt"); }
BOOST_AUTO_TEST_CASE( bareword_double ) { TURTLE_TEST("bareword_double", "tests-coverage/bareword_double.ttl", "tests-coverage/bareword_double.nt"); }
BOOST_AUTO_TEST_CASE( double_lower_case_e ) { TURTLE_TEST("double_lower_case_e", "tests-coverage/double_lower_case_e.ttl", "tests-coverage/double_lower_case_e.nt"); }
BOOST_AUTO_TEST_CASE( negative_numeric ) { TURTLE_TEST("negative_numeric", "tests-coverage/negative_numeric.ttl", "tests-coverage/negative_numeric.nt"); }
BOOST_AUTO_TEST_CASE( positive_numeric ) { TURTLE_TEST("positive_numeric", "tests-coverage/positive_numeric.ttl", "tests-coverage/positive_numeric.nt"); }
BOOST_AUTO_TEST_CASE( numeric_with_leading_0 ) { TURTLE_TEST("numeric_with_leading_0", "tests-coverage/numeric_with_leading_0.ttl", "tests-coverage/numeric_with_leading_0.nt"); }
BOOST_AUTO_TEST_CASE( literal_true ) { TURTLE_TEST("literal_true", "tests-coverage/literal_true.ttl", "tests-coverage/literal_true.nt"); }
BOOST_AUTO_TEST_CASE( literal_false ) { TURTLE_TEST("literal_false", "tests-coverage/literal_false.ttl", "tests-coverage/literal_false.nt"); }
BOOST_AUTO_TEST_CASE( langtagged_non_LONG ) { TURTLE_TEST("langtagged_non_LONG", "tests-coverage/langtagged_non_LONG.ttl", "tests-coverage/langtagged_non_LONG.nt"); }
BOOST_AUTO_TEST_CASE( langtagged_LONG ) { TURTLE_TEST("langtagged_LONG", "tests-coverage/langtagged_LONG.ttl", "tests-coverage/langtagged_non_LONG.nt"); }
BOOST_AUTO_TEST_CASE( lantag_with_subtag ) { TURTLE_TEST("lantag_with_subtag", "tests-coverage/lantag_with_subtag.ttl", "tests-coverage/lantag_with_subtag.nt"); }
BOOST_AUTO_TEST_CASE( objectList_with_two_objects ) { TURTLE_TEST("objectList_with_two_objects", "tests-coverage/objectList_with_two_objects.ttl", "tests-coverage/objectList_with_two_objects.nt"); }
BOOST_AUTO_TEST_CASE( predicateObjectList_with_two_objectLists ) { TURTLE_TEST("predicateObjectList_with_two_objectLists", "tests-coverage/predicateObjectList_with_two_objectLists.ttl", "tests-coverage/predicateObjectList_with_two_objectLists.nt"); }
BOOST_AUTO_TEST_CASE( repeated_semis_at_end ) { TURTLE_TEST("repeated_semis_at_end", "tests-coverage/repeated_semis_at_end.ttl", "tests-coverage/predicateObjectList_with_two_objectLists.nt"); }
BOOST_AUTO_TEST_CASE( repeated_semis_not_at_end ) { TURTLE_TEST("repeated_semis_not_at_end", "tests-coverage/repeated_semis_not_at_end.ttl", "tests-coverage/repeated_semis_not_at_end.nt"); }

BOOST_AUTO_TEST_CASE( nestedCollections ) { TURTLE_TEST("nestedCollections", "Turtle/nestedCollections.ttl", "Turtle/nestedCollections.nt"); }
BOOST_AUTO_TEST_SUITE_END(/* coverage */)

BOOST_AUTO_TEST_SUITE( turtle_eval )

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

