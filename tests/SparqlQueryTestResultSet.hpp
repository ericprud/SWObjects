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
    void _loadGraphWrapper (const POS* graphName, const char* fileName) {
	turtleParser.setGraph(d.assureGraph(graphName));
	turtleParser.parse_file(fileName);
	turtleParser.clear(""); // clear out namespaces and base URI.
    }
    SparqlQueryTestResultSet (std::istream& defGraph, 
			      const char* namedGraphs[], size_t namedCount, 
			      std::istream& query) : ResultSet(&F) {
 
	/* Parse query. */
	if (sparqlParser.parse_stream(query))
	    throw std::string("failed to parse query.");
	sparqlParser.clear(""); // clear out namespaces and base URI.

	/* Parse data. */
	if (defGraph != NULL) {
	    turtleParser.setGraph(d.assureGraph(NULL));
	    turtleParser.parse_stream(defGraph);
	    turtleParser.clear(""); // clear out namespaces and base URI.
	}

	if (namedGraphs != NULL)
	    for (size_t i = 0; i < namedCount; ++i)
		_loadGraphWrapper(F.getURI(namedGraphs[i]), namedGraphs[i]);

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

