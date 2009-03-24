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
RdfXmlParser GRdfXmlParser(&F, &P);


struct SparqlQueryTestResultSet : public ResultSet {
    RdfDB d;
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
	sparqlParser.root->execute(&d, this);
    }
};

std::ostream& operator<< (std::ostream& os, SparqlQueryTestResultSet const& my) {
    os << "Database: " << my.d;
    os << "query: " << *sparqlParser.root;
    os << "result: ";
    operator<<(os, (ResultSet)my);
    return os;
}

