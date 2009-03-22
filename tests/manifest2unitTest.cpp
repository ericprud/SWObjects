/* Parse DAWG manifest files and create unit tests.
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <fstream>
#include <iostream>
#if REGEX_LIB == SWOb_BOOST
  #include "boost/regex.hpp"
#endif
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "RdfDB.hpp"

#define PREFIXES \
	"PREFIX rdf:    <http://www.w3.org/1999/02/22-rdf-syntax-ns#>\n"		\
	"PREFIX rdfs:   <http://www.w3.org/2000/01/rdf-schema#>\n"			\
	"PREFIX dawgt:  <http://www.w3.org/2001/sw/DataAccess/tests/test-dawg#>\n"	\
	"PREFIX mf:     <http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#>\n"	\
	"PREFIX qt:     <http://www.w3.org/2001/sw/DataAccess/tests/test-query#>\n"

using namespace w3c_sw;

POSFactory F;
SPARQLfedDriver sparqlParser("", &F);

std::string sanitize (std::string in) {
    const boost::regex e("[^a-zA-Z0-9]");
    const std::string underbar("_");
    return boost::regex_replace(in, e, underbar, boost::match_default | boost::format_all);
}

void processManifest (const char* manifestFile) {
#if REGEX_LIB == SWOb_BOOST
    boost::regex pathre("(.*?/([^/]+)/)([^/]+)$");
    boost::cmatch matches;
    std::string path;
    std::string group;
    if (boost::regex_match(manifestFile, matches, pathre)) {
	path = std::string(matches[1].first, matches[1].second);
	group = sanitize(std::string(matches[2].first, matches[2].second));
    } else  {
	std::cerr << std::string("unable to find group in path \"") + manifestFile + "\"";
    }
#else /* !REGEX_LIB == SWOb_BOOST */
    std::string path(".");
    std::string group("unknown");
#endif /* !REGEX_LIB == SWOb_BOOST */
    std::cout << "BOOST_AUTO_TEST_SUITE( " << group << " )" << std::endl;

    try {

	std::ifstream manifestStream(manifestFile);
	if (!manifestStream.is_open())
	    throw std::string("Unable to open manifest file \"") + manifestFile + "\".";

	RdfDB d;

	/* Parse the manifest file. */
	TurtleSDriver turtleParser(manifestFile, &F);
	turtleParser.setGraph(d.assureGraph(NULL));
	turtleParser.parse_stream(manifestStream);


	/* Grab the test identifiers. */
	std::stringstream testsQuery(PREFIXES 
			     "SELECT ?test {?manifest mf:entries members(?test) .\n"
				     "      ?test dawgt:approval dawgt:Approved }");
	if (sparqlParser.parse_stream(testsQuery))
	    throw std::string("failed to parse tests query.");
	ResultSet listOfTests(&F);
	sparqlParser.root->execute(&d, &listOfTests);
	sparqlParser.clear("");

	for (ResultSetIterator testRecord = listOfTests.begin(); 
	     testRecord != listOfTests.end(); ++testRecord) {
	    std::string test = (*testRecord)->get(F.getVariable("test"))->toString();
	    try {

		/* Grab attributes of this test. */
		std::stringstream 
		    attrsQuery(PREFIXES "SELECT ?type ?name ?result ?action ?query ?data {\n" + 
			       test + " a ?type ;\n"
			       "        mf:name    ?name ;\n"
			       "#        rdfs:comment    ?comment ;\n"
			       "        mf:result  ?result ;\n"
			       "        mf:action ?action .\n"
			       "OPTIONAL { ?action qt:query     ?query }\n"
			       "OPTIONAL { ?action qt:data      ?data }\n"
			       "}");
		if (sparqlParser.parse_stream(attrsQuery))
		    throw std::string("failed to parse test attributes query.");
		ResultSet listOfAttrs(&F);
		sparqlParser.root->execute(&d, &listOfAttrs);
		sparqlParser.clear("");
// std::cerr << listOfAttrs;
		ResultSetIterator attrsRecord = listOfAttrs.begin();
		const POS* type = (*attrsRecord)->get(F.getVariable("type"));
		std::string name = (*attrsRecord)->get(F.getVariable("name"))->getLexicalValue();
		std::string result = (*attrsRecord)->get(F.getVariable("result"))->getLexicalValue();
		//std::string action = (*attrsRecord)->get(F.getVariable("action"))->toString();
		std::string query = (*attrsRecord)->get(F.getVariable("query"))->getLexicalValue();
		const POS* data_A = (*attrsRecord)->get(F.getVariable("data"));
		std::string data = data_A ? data_A->getLexicalValue() : "";

		std::stringstream 
		    graphsQuery(PREFIXES "SELECT * {\n" + 
				test + " mf:action [ qt:graphData   ?graphData ] }");
		if (sparqlParser.parse_stream(graphsQuery))
		    throw std::string("failed to parse test attributes query.");
		ResultSet listOfGraphs(&F);
		sparqlParser.root->execute(&d, &listOfGraphs);
		sparqlParser.clear("");

		std::stringstream 
		    reqsQuery(PREFIXES "SELECT * {\n" + 
			      test + " mf:requires ?requires }");
		if (sparqlParser.parse_stream(reqsQuery))
		    throw std::string("failed to parse test attributes query.");
		ResultSet listOfReqs(&F);
		sparqlParser.root->execute(&d, &listOfReqs);
		sparqlParser.clear("");

		if (type == 
		    F.getURI("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#QueryEvaluationTest")) {
		    std::string out = sanitize(group + "_" + name);
		    std::cout << "BOOST_AUTO_TEST_CASE( " << out << " ) {" << std::endl;
		    std::cout << "    std::ifstream defaultGraph( \"" << path << data << "\" );" << std::endl;
		    if (listOfGraphs.size() > 0) {
// std::cerr << listOfGraphs;
			std::cout << "    std::ifstream namedGraphs[" << listOfGraphs.size() << "];" << std::endl;
			int i = 0;
			for (ResultSetIterator it = listOfGraphs.begin(); it != listOfGraphs.end(); ++it) {
			    std::string graphData = (*it)->get(F.getVariable("graphData"))->getLexicalValue();
			    std::cout << "    namedGraphs[" << i << "].open(\"" << path << graphData << "\");" << std::endl;
			}
		    } else {
			std::cout << "    std::ifstream* namedGraphs = NULL;" << std::endl;
		    }
		    if (listOfReqs.size() > 0) {
// std::cerr << listOfReqs;
			std::cout << "    const URI* requires[] = {";
			for (ResultSetIterator it = listOfReqs.begin(); it != listOfReqs.end(); ++it) {
			    std::string require = (*it)->get(F.getVariable("requires"))->getLexicalValue();
			    if (it != listOfReqs.begin())
				std::cout << "," << std::endl << "                             ";
			    std::cout << "F->getURI(\"" << require << "\")";
			}
			std::cout << "};" << std::endl;
		    } else {
			std::cout << "    const char** requires = NULL;" << std::endl;
		    }
		    std::cout << "    DEFGRAPH_FILE_TEST(\"" << path << query << "\", \"" << path << result << "\");" << std::endl;
		    std::cout << "}" << std::endl;
		} else {
		    std::cerr << "skipping test " << test << " as it is of type " << type->toString() << std::endl;
		}
	    } catch (std::string s) {
		std::cerr << "test " << test << " got an error: " << s;
	    } catch (const char* s) {
		std::cerr << "test " << test << " got an error: " << s;
	    }
	}
    } catch (std::string s) {
	std::cerr << "manfest file " << manifestFile << " got an error: " << s;
    } catch (const char* s) {
	std::cerr << "manfest file " << manifestFile << " got an error: " << s;
    }
    std::cout << "BOOST_AUTO_TEST_SUITE_END(/* " << group << " */)" << std::endl;
}

int main (int argc, char* argv[]) {
    if (argc < 2)
	throw std::string("Invocation: ") + argv[0] + " <data-r2/basic/manifest.ttl>";
    for (int i = 1; i < argc; ++i)
	processManifest(argv[i]);
    return 0;
}

