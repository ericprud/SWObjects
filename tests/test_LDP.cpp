/* test_LDP.hpp -- 
 *
 * Test the LDP server built in to ../bin/sparql and LDP interactions built
 * into the SPARQLfed language.
 *
 * $Id: test_Ldp.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE LDP

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <boost/lexical_cast.hpp>
#define NEEDDEF_W3C_SW_SAXPARSER
#define NEEDDEF_W3C_SW_WEBAGENT
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TrigSParser/TrigSParser.hpp"
#include "ServerInteraction.hpp"

#if HTTP_CLIENT != SWOb_DISABLED
  W3C_SW_WEBAGENT<> WebClient;
#else /* HTTP_CLIENT == SWOb_DISABLED */
  #warning unable to test RDFa over HTTP
#endif /* HTTP_CLIENT == SWOb_DISABLED */

#if XML_PARSER != SWOb_DISABLED
  W3C_SW_SAXPARSER P;
#else
  #error RDFa tests require an XML parser
#endif

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,GraphMatch:3"
w3c_sw_DEBUGGING_FUNCTIONS();

w3c_sw::AtomFactory F;

// Allocate distinct server port ranges to prevent conflicts in simultaneous tests.
// test_SPARQL: 9000-90ff, test_SADI: 9100-91ff, test_LWP: 9200-92ff
#define LOWPORT 0x9200
#define HIPORT  0x92ff

/** CurlPOSTtoLDPservice - invoke curl with parameters used in the server
 *  invocation.
 */
struct CurlPOSTtoLDPservice : w3c_sw::ClientServerInteraction {
    CurlPOSTtoLDPservice (std::string serverParams, std::string serverPath, std::string data, const char* media)
	: ClientServerInteraction(serverParams, serverPath, LOWPORT, HIPORT)
    {
	invoke(std::string()
	       + "curl -s -X POST -H 'Content-Type: "+media+"' "+serverURL+"  -d ' "+data+"'");
	/* Note that in this [[ -d ' "+data+"' ]], the space after the -d
	   prevents curl from interpreting a leading '@' as a marker for file
	   from which to get the data.*/
    }
};

/** ParsedResultSet - result set from a text string.
 */
struct ParsedResultSet : public w3c_sw::ResultSet {
    ParsedResultSet (std::string srt) : 
	ResultSet(&F) {
	delete *begin();
	erase(begin());
	w3c_sw::IStreamContext sptr(srt.c_str(), w3c_sw::IStreamContext::STRING, "text/sparql-results");
	w3c_sw::TTerm::String2BNode bnodeMap;
	parseTable(sptr, false, bnodeMap);
    }
};

/** EvaluatedPOSTresponseResultSet - result set from an executed query.
 */
struct EvaluatedPOSTresponseResultSet : public w3c_sw::ResultSet {
    std::string query;
    w3c_sw::RdfDB d;

    EvaluatedPOSTresponseResultSet (std::string service, std::string postData, std::string query)
	: ResultSet(&F), query(query), d(&WebClient, &P)
    {
	{
	    boost::shared_ptr<w3c_sw::IStreamContext> istr;
	    istr = d.webAgent->post(service.c_str(), "text/turtle", postData.c_str());
	    if (w3c_sw::Logger::Logging(w3c_sw::Logger::IOLog_level, w3c_sw::Logger::info)) {
		std::stringstream o;
		o << "POSTing text/turtle [[\n" << postData.c_str() << "]] to " << service;
		o << " yielded  media type " << *istr->mediaType;
		o << ".\n";
		BOOST_LOG_SEV(w3c_sw::Logger::IOLog::get(), w3c_sw::Logger::info) << o.str();
	    }
	    d.loadData(d.ensureGraph(w3c_sw::DefaultGraph), *istr, service, service, &F);
	}

	{
	    w3c_sw::IStreamContext istr(query, w3c_sw::IStreamContext::STRING);
	    w3c_sw::SPARQLfedDriver sparqlParser("", &F);
	    w3c_sw::Operation* op = sparqlParser.parse(istr);
	    sparqlParser.clear(""); // clear out namespaces and base URI.
	    op->execute(&d, this);
	    delete op;
	}
    }

    std::ostream& print (std::ostream& os) const {
	os
	    << "Data: \n" << d
	    << "Query: \n" << query << "\n"
	    << "Results:\n";
	operator<<(os, (w3c_sw::ResultSet&)*this);
	return os;
    }
};

std::ostream& operator<< (std::ostream& os, const EvaluatedPOSTresponseResultSet& ref) {
    return ref.print(os);
}

/** RdfDBFromTrig - initialize an RDF DB from a trig string.
 */
struct RdfDBFromTrig : public w3c_sw::RdfDB {
    RdfDBFromTrig (std::string trig) {
	w3c_sw::IStreamContext istr(trig, w3c_sw::IStreamContext::STRING);
	w3c_sw::TrigSDriver trigParser("", &F);
	trigParser.parse(istr, this);
    }
};


/** OperationOnInvokedServer - client interactions with the server built into
 *  the bin/sparql binary.
 */
struct OperationOnInvokedServer : w3c_sw::SPARQLServerInteraction {
    EvaluatedPOSTresponseResultSet got;
    ParsedResultSet expected;
    RdfDBFromTrig endState;
    RdfDBFromTrig expectedState;

    OperationOnInvokedServer (std::string serverParams, std::string serverPath, std::string postData, std::string query, std::string expect, std::string expectedState)
	: w3c_sw::SPARQLServerInteraction(serverParams, serverPath, LOWPORT, HIPORT),
	  got("http://localhost:" + boost::lexical_cast<std::string>(port) + serverPath,
	      postData, w3c_sw::substituteQueryVariables(query, port)),
	  expected(expect), endState(readServerState()), expectedState(expectedState)
    {  }
    std::string readServerState () {
	serverS.clear();
	readToExhaustion(serverPipe, serverS);
	return serverS;
    }
};


//BOOST_AUTO_TEST_SUITE( local )

BOOST_AUTO_TEST_CASE( bugz_curl ) {
    CurlPOSTtoLDPservice i
	(// Server invocation -- construct a pattern from supplied graph.
	 "--LDP 'PREFIX : <http://bugs.example/ns#>\n"
	 "       PREFIX ldp: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#>\n"
	 "       INSERT { GRAPH ?bug { ?bug a :Bug ; :whiner ?whiner ; :whatNow ?desc } }\n"
	 "    CONSTRUCT { ?bug a :Bug }\n"
	 "        WHERE { ?s :whiner ?whiner ; :whatNow ?desc\n"
	 "                BIND (ldp:newObj(</bugz/>) AS ?bug) }' --once",
	 // interface path:
	 "/createBug",

	 // Curl this data and media type to verify the server response.
	 "@prefix : <http://bugs.example/ns#> .\n"
	 "_:myBug :whiner \"me\" ; :whatNow \"badly b0rked\" .", "text/turtle");
    BOOST_CHECK_EQUAL("{\n  </bugz/1> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://bugs.example/ns#Bug> .\n}\n", i.clientS);
}

BOOST_AUTO_TEST_CASE( bugz_client ) {
    OperationOnInvokedServer i
	(// Server invocation -- construct a pattern from supplied graph:
	 "--LDP 'PREFIX : <http://bugs.example/ns#>\n"
	 "       PREFIX ldp: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#>\n"
	 "       INSERT { GRAPH ?bug { ?bug a :Bug ; :whiner ?whiner ; :whatNow ?desc } }\n"
	 "    CONSTRUCT { ?bug a :Bug }\n"
	 "        WHERE { ?s :whiner ?whiner ; :whatNow ?desc\n"
	 "                BIND (ldp:newObj(</bugz/>) AS ?bug) }' --once",
	 // interface path:
	 "/createBug",

	 // Client graph to POST to service:
	 "@prefix : <http://bugs.example/ns#> .\n"
	 "_:myBug :whiner 'me' ; :whatNow 'badly b0rked' .",

	 // Client SPARQL query to validate the response:
	 "SELECT ?type\n"
	 " WHERE { ?s a ?type\n"
	 //	 "         FILTER (STRSTARTS(STR(?s), 'http://localhost:%p/bugz/'))\n"
	 "}",

	 // Expected validation results:
	 "+------------------------------+\n"
	 "| ?type                        |\n"
	 "| <http://bugs.example/ns#Bug> |\n"
	 "+------------------------------+",

	 // Service database endstate:
	 "@prefix bug: <http://bugs.example/ns#> .\n"
	 "</bugz/1> {\n"
	 "  </bugz/1> a bug:Bug .\n"
	 "  </bugz/1> bug:whiner 'me'  .\n"
	 "  </bugz/1> bug:whatNow 'badly b0rked'  .\n"
	 "}");
    BOOST_CHECK_EQUAL(i.got, i.expected);
}


namespace LDBPexamples {
    static std::string turtlePrefix_o =
	"@prefix o: <http://example.org/ontology/> .\n";

    static std::string turtlePrefix_xsd =
	"@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n";

    static std::string turtlePrefix_dcterms =
	"@prefix dcterms: <http://purl.org/dc/terms/> .\n";

    static std::string turtlePrefixes =
	"@prefix container: <http://example.org/netWorth/nw1/assetContainer> .\n"
	"@prefix page: <http://example.org/netWorth/nw1/assetContainer?p=> .\n"
	"@prefix membership: <http://example.org/netWorth/nw1> .\n"
	"@prefix asset: <http://example.org/netWorth/nw1/assetContainer/> .\n"
	"@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>.\n"
	"@prefix bp: <http://open-services.net/ns/basicProfile#>.\n" +
	turtlePrefix_dcterms +
	turtlePrefix_xsd +
	turtlePrefix_o
	;

    static std::string sparqlPrefixes =
	"PREFIX ldp: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#>\n"
	"PREFIX container: <http://example.org/netWorth/nw1/assetContainer>\n"
	"PREFIX page: <http://example.org/netWorth/nw1/assetContainer?p=>\n"
	"PREFIX membership: <http://example.org/netWorth/nw1>\n"
	"PREFIX asset: <http://example.org/netWorth/nw1/assetContainer/>\n"
	"PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\n"
	"PREFIX dcterms: <http://purl.org/dc/terms/>\n"
	"PREFIX bp: <http://open-services.net/ns/basicProfile#>\n"
	"PREFIX o: <http://example.org/ontology/>\n"
	"PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>\n"
	;

    static std::string container =
	"    container: a bp:Container ;\n"
	"        dcterms:title \"The assets of JohnZSmith\" ;\n"
	"        bp:membershipSubject membership: ;\n"
	"        bp:membershipPredicate o:asset .\n"
	;

    std::string post_1 =
	LDBPexamples::turtlePrefix_o +
	LDBPexamples::turtlePrefix_xsd +
	LDBPexamples::turtlePrefix_dcterms +
	"[] a o:Stock ; dcterms:title \"IBM\" ;\n"
	"   o:value 100.00 ; dcterms:date \"2012-01-01\"^^xsd:date .\n";
    static std::string member1 =
	"    membership: o:asset asset:a1 .\n"
	"    asset:a1 a o:Stock ; dcterms:title \"IBM\" ; o:value 100.00 .\n";
    static std::string asset1 =
	"asset:a1 { asset:a1 a o:Stock ; o:value 100.00 ; dcterms:title \"IBM\" ; dcterms:date \"2012-01-01\"^^xsd:date }\n";

    static std::string member2 =
	"    membership: o:asset asset:a2 .\n"
	"    asset:a2 a o:Cash  ; o:value  50.00 .\n";
    static std::string asset2 =
	"asset:a2 { asset:a2 a o:Cash  ; o:value  50.00 ; dcterms:date \"2012-01-02\"^^xsd:date }\n";

    static std::string member3 =
	"    membership: o:asset asset:a3 .\n"
	"    asset:a3 a o:Bribe ; o:value  10.00 .\n";
    static std::string asset3 =
	"asset:a3 { asset:a3 a o:Bribe ; o:value  10.00 ; dcterms:date \"2012-01-03\"^^xsd:date }\n";

    std::string post_4 =
	LDBPexamples::turtlePrefix_o +
	LDBPexamples::turtlePrefix_xsd +
	LDBPexamples::turtlePrefix_dcterms +
	"[] a o:House ; dcterms:title \"Home\" ;\n"
	"   o:value 1.00 ; dcterms:date \"2012-01-04\"^^xsd:date .\n";
    static std::string member4 =
	"    membership: o:asset asset:a4 .\n"
	"    asset:a4 a o:House ; dcterms:title \"Home\" ; o:value   1.00 .\n";
    static std::string asset4 =
	"asset:a4 { asset:a4 a o:House ; o:value   1.00 ; dcterms:title \"Home\" ; dcterms:date \"2012-01-04\"^^xsd:date }\n";

    std::string post_5 =
	LDBPexamples::turtlePrefix_o +
	LDBPexamples::turtlePrefix_xsd +
	LDBPexamples::turtlePrefix_dcterms +
	"[] a o:Stock ; dcterms:title \"Big Co.\" ;\n"
	"   o:value 200.02 ; dcterms:date \"2012-01-05\"^^xsd:date .\n";
    static std::string member5 =
	"    membership: o:asset asset:a5 .\n"
	"    asset:a5 a o:Stock ; dcterms:title \"Big Co.\" ; o:value 200.02 .\n";
    static std::string asset5 =
	"asset:a5 { asset:a5 a o:Stock ; o:value 200.02 ; dcterms:title \"Big Co.\" ; dcterms:date \"2012-01-05\"^^xsd:date }\n";

    static std::string modify =
	sparqlPrefixes + 
	"DELETE    { GRAPH ?LastTail { ?LastTail bp:nextPage ?NewNil } }\n"
	"INSERT    {\n"
	"  GRAPH ?LastTail { ?LastTail bp:nextPage ?NewTail }\n"
	"  GRAPH ?NewTail {\n"
	+      container +
	"      ?NewTail a bp:Page ; bp:pageOf container: .\n"
	"  }\n"
	"  GRAPH ?CurTail {\n"
	"      ?CurTail bp:nextPage rdf:nil .\n"
	"      membership: a o:NetWorth ; o:asset ?NewObj .\n"
	"      ?NewObj a ?type ; dcterms:title ?title ; o:value ?value\n"
	"  }\n"
	"  GRAPH ?NewObj { ?NewObj a ?type ; dcterms:title ?title ; o:value ?value ; dcterms:date ?date }\n"
	"}\n"
	"CONSTRUCT { ?NewObj a ?type }\n"
	"WHERE     {\n"
	"  ?oldObj a ?type ; dcterms:title ?title ; o:value ?value ; dcterms:date ?date\n"
	"  BIND (ldp:lastTail(container:, membership:, o:asset, 4) AS ?LastTail)\n"
	"  BIND (ldp:newTail (container:, membership:, o:asset, 4) AS ?NewTail)\n"
	"  BIND (ldp:newNil  (container:, membership:, o:asset, 4) AS ?NewNil)\n"
	"  BIND (ldp:curTail (container:, membership:, o:asset, 4) AS ?CurTail)\n"
	"  BIND (ldp:newObj  (asset:a) AS ?NewObj)\n"
	"}\n";

    /* var         <4 on last page   4 on last page
       ?Container  <...>             <...>
       ?LastTail   <?p=1>            <?p=1>
       ?NewTail    NULL              <...?p=2>
       ?NewNil     rdf:nil           NULL
       ?CurTail    <...?p=1>         <...?p=2>
       ?NewObj     <.../a5>          <.../a5>

       hardcodable with:
       "  BIND (page:1 AS ?LastTail)\n"
       "  BIND (page:2  AS ?NewTail)\n"
       "  BIND (rdf:nil   AS ?NewNil)\n"
       "  BIND (page:2  AS ?CurTail)\n"
       "  BIND (asset:a5   AS ?NewObj)\n"
    */


}; // namespace LDBPexamples


BOOST_AUTO_TEST_CASE( LDBP_pagingExample_5_4_curl ) {
    CurlPOSTtoLDPservice i
	(// Server invocation -- construct a pattern from supplied graph.
	 std::string() + "--LDP '" + LDBPexamples::modify + "' --once",

	 // interface path:
	 "/moreMoney",

	 // Client graph to POST to service:
	 LDBPexamples::post_5, "text/turtle");

    BOOST_CHECK_EQUAL("{\n  <http://example.org/netWorth/nw1/assetContainer/a1> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://example.org/ontology/Stock> .\n}\n", i.clientS);
}


struct WriteFile {
    std::ofstream f;
    WriteFile (const char* filename, std::string contents)
	: f(filename)
    {
	f << contents;
	f.close();
    }
};


BOOST_AUTO_TEST_CASE( LDBP_pagingExample_1_4_client ) {
    std::string before =
	LDBPexamples::turtlePrefixes
	;

    { WriteFile t("LDP/LDBP_pagingExample_1_4_client-before.trig", before); }

    std::string after =
	LDBPexamples::turtlePrefixes +
	"page:1 {\n"
	+    LDBPexamples::container +
	"    page:1 a bp:Page ;\n"
	"        bp:pageOf container: ;\n"
	"        bp:nextPage rdf:nil .\n"
	"    membership: a o:NetWorth .\n"
	+    LDBPexamples::member1
	+ "}\n"
	+ LDBPexamples::asset1
	;

    OperationOnInvokedServer i
	(// Server invocation -- construct a pattern from supplied graph:
	 "-d LDP/LDBP_pagingExample_1_4_client-before.trig --LDP '"
	 + LDBPexamples::modify + "' --server-no-description --once",

	 // interface path:
	 "/moreMoney",

	 // Client graph to POST to service:
	 LDBPexamples::post_1,

	 // Client SPARQL query to validate the response:
	 LDBPexamples::sparqlPrefixes +
	 "SELECT ?s ?type\n"
	 " WHERE {\n"
	 "    ?s a ?type\n"
	 "}",

	 // Expected validation results:
	 "+-----------------------------------------------------+-------------------------------------+\n"
	 "| ?s                                                  | ?type                               |\n"
	 "| <http://example.org/netWorth/nw1/assetContainer/a1> | <http://example.org/ontology/Stock> |\n"
	 "+-----------------------------------------------------+-------------------------------------+\n",

	 // Service database endstate:
	 after);

    BOOST_CHECK_EQUAL(i.got, i.expected);
    BOOST_CHECK_EQUAL(i.endState, i.expectedState);
}


BOOST_AUTO_TEST_CASE( LDBP_pagingExample_4_4_client ) {
    std::string before =
	LDBPexamples::turtlePrefixes +
	"page:1 {\n"
	+    LDBPexamples::container +
	"    page:1 a bp:Page ;\n"
	"        bp:pageOf container: ;\n"
	"        bp:nextPage rdf:nil .\n"
	"    membership: a o:NetWorth .\n"
	+    LDBPexamples::member1
	+    LDBPexamples::member2
	+    LDBPexamples::member3
	+ "}\n"
	+ LDBPexamples::asset1
	+ LDBPexamples::asset2
	+ LDBPexamples::asset3
	;

    { WriteFile t("LDP/LDBP_pagingExample_4_4_client-before.trig", before); }

    std::string after =
	LDBPexamples::turtlePrefixes +
	"page:1 {\n"
	+    LDBPexamples::container +
	"    page:1 a bp:Page ;\n"
	"        bp:pageOf container: ;\n"
	"        bp:nextPage rdf:nil .\n"
	"    membership: a o:NetWorth .\n"
	+    LDBPexamples::member1
	+    LDBPexamples::member2
	+    LDBPexamples::member3
	+    LDBPexamples::member4
	+ "}\n"
	+ LDBPexamples::asset1
	+ LDBPexamples::asset2
	+ LDBPexamples::asset3
	+ LDBPexamples::asset4
	;

    OperationOnInvokedServer i
	(// Server invocation -- construct a pattern from supplied graph:
	 "-d LDP/LDBP_pagingExample_4_4_client-before.trig --LDP '"
	 + LDBPexamples::modify + "' --server-no-description --once",

	 // interface path:
	 "/moreMoney",

	 // Client graph to POST to service:
	 LDBPexamples::post_4,

	 // Client SPARQL query to validate the response:
	 LDBPexamples::sparqlPrefixes +
	 "SELECT ?s ?type\n"
	 " WHERE {\n"
	 "    ?s a ?type\n"
	 "}",

	 // Expected validation results:
	 "+-----------------------------------------------------+-------------------------------------+\n"
	 "| ?s                                                  | ?type                               |\n"
	 "| <http://example.org/netWorth/nw1/assetContainer/a4> | <http://example.org/ontology/House> |\n"
	 "+-----------------------------------------------------+-------------------------------------+\n",

	 // Service database endstate:
	 after);

    BOOST_CHECK_EQUAL(i.got, i.expected);
    BOOST_CHECK_EQUAL(i.endState, i.expectedState);
}


BOOST_AUTO_TEST_CASE( LDBP_pagingExample_5_4_client ) {
    std::string before =
	LDBPexamples::turtlePrefixes +
	"page:1 {\n"
	+    LDBPexamples::container +
	"    page:1 a bp:Page ;\n"
	"        bp:pageOf container: ;\n"
	"        bp:nextPage rdf:nil .\n"
	"    membership: a o:NetWorth .\n"
	+    LDBPexamples::member1
	+    LDBPexamples::member2
	+    LDBPexamples::member3
	+    LDBPexamples::member4
	+ "}\n"
	+ LDBPexamples::asset1
	+ LDBPexamples::asset2
	+ LDBPexamples::asset3
	+ LDBPexamples::asset4
	;

    { WriteFile t("LDP/LDBP_pagingExample_5_4_client-before.trig", before); }

    std::string after =
	LDBPexamples::turtlePrefixes +
	"page:1 {\n"
	+    LDBPexamples::container +
	"    page:1 a bp:Page ;\n"
	"        bp:pageOf container: ;\n"
	"        bp:nextPage page:2 .\n"
	"    membership: a o:NetWorth .\n"
	+    LDBPexamples::member1
	+    LDBPexamples::member2
	+    LDBPexamples::member3
	+    LDBPexamples::member4
	+ "}\n"
	+ LDBPexamples::asset1
	+ LDBPexamples::asset2
	+ LDBPexamples::asset3
	+ LDBPexamples::asset4
	+ "page:2 {\n"
	+    LDBPexamples::container +
	"    page:2 a bp:Page ;\n"
	"        bp:pageOf container: ;\n"
	"        bp:nextPage rdf:nil .\n"
	"    membership: a o:NetWorth .\n"
	+    LDBPexamples::member5
	+ "}\n"
	+ LDBPexamples::asset5
	;

    OperationOnInvokedServer i
	(// Server invocation -- construct a pattern from supplied graph:
	 "-d LDP/LDBP_pagingExample_5_4_client-before.trig --LDP '"
	 + LDBPexamples::modify + "' --server-no-description --once",

	 // interface path:
	 "/moreMoney",

	 // Client graph to POST to service:
	 LDBPexamples::post_5,

	 // Client SPARQL query to validate the response:
	 LDBPexamples::sparqlPrefixes +
	 "SELECT ?s ?type\n"
	 " WHERE {\n"
	 "    ?s a ?type\n"
	 "}",

	 // Expected validation results:
	 "+-----------------------------------------------------+-------------------------------------+\n"
	 "| ?s                                                  | ?type                               |\n"
	 "| <http://example.org/netWorth/nw1/assetContainer/a5> | <http://example.org/ontology/Stock> |\n"
	 "+-----------------------------------------------------+-------------------------------------+\n",

	 // Service database endstate:
	 after);

    BOOST_CHECK_EQUAL(i.got, i.expected);
    BOOST_CHECK_EQUAL(i.endState, i.expectedState);
}

//BOOST_AUTO_TEST_SUITE_END(/* local */)

