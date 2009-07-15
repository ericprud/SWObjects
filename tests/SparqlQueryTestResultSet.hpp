/* Common code for SPARQL query tests.
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#include <boost/test/unit_test.hpp>
//#pragma warning( disable : 4273 )
//#include <boost/test/included/unit_test.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "TrigSParser/TrigSParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "SPARQLSerializer.hpp"
#include "RdfXmlParser.hpp"

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
  w3c_sw::SAXparser_libxml P;
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
  w3c_sw::SAXparser_expat P;
#elif XML_PARSER == SWOb_MSXML3
  #include "../interface/SAXparser_msxml3.hpp"
  w3c_sw::SAXparser_msxml3 P;
#else
  #warning DAWG tests require an XML parser
#endif

using namespace w3c_sw;

POSFactory F;
SPARQLfedDriver sparqlParser("", &F);
TurtleSDriver turtleParser("", &F);
TrigSDriver trigParser("", &F);
RdfXmlParser GRdfXmlParser(&F, &P);


struct SparqlQueryTestResultSet : public ResultSet {
    RdfDB d;
    RdfDB constructed;
    SparqlQueryTestResultSet (const char* defGraph, 
			      const char* namedGraphs[], size_t namedCount, 
			      const URI* requires[], size_t reqsCount, 
			      const char* query) : ResultSet(&F) {
 
	std::string baseStr(query);
	baseStr = baseStr.substr(0, baseStr.find_last_of("/")+1);
	const URI* baseURI = F.getURI(baseStr.c_str());

	/* Parse query. */
	sparqlParser.setBase(baseURI);
	if (sparqlParser.parse_file(query))
	    throw std::string("failed to parse query file \"") + query + "\".";
	sparqlParser.clear(""); // clear out namespaces and base URI.

	/* Parse data. */
	if (defGraph != NULL) {
	    turtleParser.setGraph(d.assureGraph(NULL));
	    turtleParser.setBase(baseURI);
	    turtleParser.parse_file(defGraph);
	    turtleParser.clear(""); // clear out namespaces and base URI.
	}

	for (size_t i = 0; i < namedCount; ++i) {
	    turtleParser.setGraph(d.assureGraph(F.getURI(namedGraphs[i])));
	    turtleParser.setBase(baseURI);
	    turtleParser.parse_file(namedGraphs[i]);
	    turtleParser.clear(""); // clear out namespaces and base URI.
	}

	for (size_t i = 0; i < reqsCount; ++i)
	    std::cerr << "ignoring " << requires[i]->toString() << std::endl;

	/* Exectute query. */
	setRdfDB(&constructed);
	sparqlParser.root->execute(&d, this);
    }

    SparqlQueryTestResultSet (const char* input, const char* query)
	: ResultSet(&F) {
 
	std::string baseStr(query);
	baseStr = baseStr.substr(0, baseStr.find_last_of("/")+1);
	const URI* baseURI = F.getURI(baseStr.c_str());

	/* Parse query. */
	sparqlParser.setBase(baseURI);
	if (sparqlParser.parse_file(query))
	    throw std::string("failed to parse query file \"") + query + "\".";
	sparqlParser.clear(""); // clear out namespaces and base URI.

	/* Parse data. */
	if (input != NULL) {
	    trigParser.setDB(&d);
	    trigParser.setBase(baseURI);
	    trigParser.parse_file(input);
	    trigParser.clear("");
	}
	/* Copy db so we can show the original. */
	constructed = d;

	/* Exectute query. */
	setRdfDB(&constructed);
	sparqlParser.root->execute(&d, this);
    }
};

std::ostream& operator<< (std::ostream& os, SparqlQueryTestResultSet const& my) {
    os << "Database: " << my.d;
    os << "query: " << *sparqlParser.root;
    os << "result: ";
    ResultSet orderedCopy(my);
    orderedCopy.order();
    operator<<(os, orderedCopy);
    return os;
}

/* ExpectedRS attempts to copy the column order from measured.
   Provides only the interfaces needed for the DAWG tests.
 */
struct ExpectedRS {
    ResultSet& measured;
    ResultSet* reference;
    RdfDB rdfDB;

    ExpectedRS (ResultSet& measured, const char* resultFile, 
		POSFactory* posFactory, SWSAXparser* saxParser) : 
	measured(measured) {
	if (resultFile == NULL) {	/* empty result graph */
	    reference = new ResultSet(posFactory, &rdfDB);

	} else {
	    std::string rfs(resultFile);
	    if (rfs.substr(rfs.size()-4, 4) == ".srx") {
		reference = new ResultSet(posFactory, saxParser, rfs.c_str());

	    } else {			/* retults in a graph */
		if (rfs.substr(rfs.size()-4, 4) == ".ttl") {
		    turtleParser.setGraph(rdfDB.assureGraph(NULL));
		    turtleParser.parse_file(rfs.c_str());
		    turtleParser.clear("");
		} else if (rfs.substr(rfs.size()-4, 4) == ".trg") {			       
		    std::string baseStr = rfs.substr(0, rfs.find_last_of("/")+1);
		    const URI* baseURI = F.getURI(baseStr.c_str());
		    trigParser.setBase(baseURI);
		    trigParser.setDB(&rdfDB);		       
		    trigParser.parse_file(rfs.c_str());			       
		    trigParser.clear("");					       
		} else if (rfs.substr(rfs.size()-4, 4) == ".rdf") {
		    GRdfXmlParser.parse(rdfDB.assureGraph(NULL), rfs.c_str());
		} else {
		    throw std::string("unable to parse results file ") + rfs.c_str();
		}

		/* if !RESULT_Graphs, graph is an RDF form of a ResultSet. */
		reference = measured.resultType == ResultSet::RESULT_Graphs ?
		    new ResultSet(posFactory, &rdfDB) :
		    new ResultSet(posFactory, &rdfDB, "");
	    }
	}
	if (measured.resultType == ResultSet::RESULT_Graphs)
	    rdfDB.assureGraphs(measured.getRdfDB()->getGraphNames());
    }
    ~ExpectedRS () { delete reference; }
};


bool operator== (ResultSet const& measured, ExpectedRS const& expected) {
    return measured == *expected.reference;
}


std::ostream& operator<< (std::ostream& os, ExpectedRS const& my) {
    ResultSet orderedCopy(*my.reference);
    const VariableList* t = orderedCopy.getKnownVars();
    std::set<const POS*> referenceVars(t->begin(), t->end());
    const VariableList* measuredVars = my.measured.getKnownVars();

    ProductionVector<const POS*> justVars;

    /* Copy the measuredVars which have corresponding referenceVars
     * into the new order set.
     * Don't put BNodes into the order set.
     */
    for (VariableListConstIterator it = measuredVars->begin();
	 it != measuredVars->end(); ++it)
	if (referenceVars.find(*it) != referenceVars.end()) {
	    if (dynamic_cast<const Variable*>(*it))
		justVars.push_back(*it);
	    referenceVars.erase(*it);
	}

    /* Add any remaining measuredVars into the order set. */
    for (VariableListConstIterator it = referenceVars.begin();
	 it != referenceVars.end(); ++it)
	if (dynamic_cast<const Variable*>(*it))
	    justVars.push_back(*it);

    orderedCopy.project(&justVars);
    justVars.clear();
    operator<<(os, orderedCopy);
    return os;
}

/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 */
#define DAWG_TEST(QUERY_FILE, RESULT_FILE, NGS, REQS)			       \
    try {								       \
	SparqlQueryTestResultSet measured(defaultGraph, namedGraphs, 	       \
					  NGS, requires, REQS, QUERY_FILE);    \
	ExpectedRS expected(measured, RESULT_FILE, &F, &P);		       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::runtime_error& s) {					       \
	BOOST_ERROR ( std::string(s.what()).append(" not implemented") );      \
    }

#define GRAPH_TEST(DATA_FILE, QUERY_FILE, RESULT_FILE)			       \
    try {								       \
	SparqlQueryTestResultSet measured(DATA_FILE, QUERY_FILE);	       \
	ExpectedRS expected(measured, RESULT_FILE, &F, &P);		       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::runtime_error& s) {					       \
	BOOST_ERROR ( std::string(s.what()).append(" not implemented") );      \
    }

