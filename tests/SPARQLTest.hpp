/* SPARQLTest.hpp -- Common code for SPARQL query tests.
 *
 * The DAWG and SPARUL tests take input graphs, a query and a reference result
 * set. The MeasuredRS populates its results by executing the query on the input
 * graphs. The ReferenceRS aligns itself with the MeasuredRS to have the minimal
 * differences with the MeasuredRS. The comparison is done with operator== per
 * the boost::test paradigm.
 *
 * $Id: test_GraphMatch.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

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

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,GraphMatch:3"

/* included/unit_test.hpp produces an object that doesn't require linking to
 * boost_unit_test_framework. It's prettier if you disable 4273 in MSVC.
 */
//#pragma warning( disable : 4273 )
//#include <boost/test/included/unit_test.hpp>

using namespace w3c_sw;

#define BASE_URI ""

AtomFactory F;
SPARQLfedDriver sparqlParser(BASE_URI, &F);
TurtleSDriver turtleParser(BASE_URI, &F);
TrigSDriver trigParser(BASE_URI, &F);
RdfXmlParser GRdfXmlParser(BASE_URI, &F, &P);

struct LabeledGraph {
    const char* source;
    const char* name;
    LabeledGraph (const char* source, const char* name)
	: source(source), name(name)
    {  }
};

/* This is like a normal RdfDB except that it prepends file load paths with
 * directory in which the test is located.
 * 
 */
struct MeasuredRS : public ResultSet {
    RdfDB d;
    RdfDB constructed;

    /* DAWG tests consist of:
     *   default graph
     *   a set of named graphs
     *   a set of required features
     *   a query to peform.
     */

    static void read (std::string name, std::string baseURI, RdfDB* db) {
	IStreamContext istr(name, IStreamContext::FILE);
	if (name.substr(name.size()-4, 4) == ".rdf") {
	    GRdfXmlParser.setBase(name);
	    GRdfXmlParser.parse(db->ensureGraph(DefaultGraph), istr);
	    GRdfXmlParser.clear(BASE_URI); // clear out namespaces and base URI.
	} else if (name.substr(name.size()-4, 4) == ".ttl") {
	    turtleParser.setGraph(db->ensureGraph(DefaultGraph));
	    turtleParser.setBase(baseURI);
	    turtleParser.parse(istr);
	    turtleParser.clear(BASE_URI); // clear out namespaces and base URI.
	} else {
	    trigParser.setDB(db);
	    trigParser.setBase(baseURI);
	    trigParser.parse(istr);
	    trigParser.clear(BASE_URI); // clear out namespaces and base URI.
	}
    }

    static void read (std::string name, std::string baseURI, BasicGraphPattern* g) {
	IStreamContext istr(name, IStreamContext::FILE);
	if (name.substr(name.size()-4, 4) == ".rdf") {
	    GRdfXmlParser.setBase(name);
	    GRdfXmlParser.parse(g, istr);
	    GRdfXmlParser.clear(BASE_URI); // clear out namespaces and base URI.
	} else {
	    turtleParser.setGraph(g);
	    turtleParser.setBase(baseURI);
	    turtleParser.parse(istr);
	    turtleParser.clear(BASE_URI); // clear out namespaces and base URI.
	}
    }

    MeasuredRS (const char* defGraph, 
		const char* namedGraphs[], size_t namedCount, 
		const URI* requires[], size_t reqsCount, 
		const char* queryPath) : ResultSet(&F) {

	std::string baseURI(queryPath);
	baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);
	Operation* query;

	/* Parse query. */
	{
	    IStreamContext istr(queryPath, IStreamContext::FILE);
	    sparqlParser.setBase(baseURI);
	    query = sparqlParser.parse(istr);
	    sparqlParser.clear(BASE_URI); // clear out namespaces and base URI.
	}

	/* Parse data. */
	if (defGraph != NULL)
	    read(defGraph, baseURI, d.ensureGraph(NULL));

	for (size_t i = 0; i < namedCount; ++i)
	    read(namedGraphs[i], baseURI, d.ensureGraph(F.getURI(namedGraphs[i])));

	for (size_t i = 0; i < reqsCount; ++i)
	    std::cerr << "assuming support for extension " << requires[i]->toString() << std::endl;

	/* Exectute query. */
	setRdfDB(&constructed);
	query->execute(&d, this);
    }

    MeasuredRS (const char* defGraph, 
		const LabeledGraph namedGraphs[], size_t namedCount, 
		const char* queryPath, bool construct) : ResultSet(&F) {

	std::string baseURI(queryPath);
	baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);
	Operation* query;

	/* Parse query. */
	{
	    IStreamContext istr(queryPath, IStreamContext::FILE);
	    sparqlParser.setBase(baseURI);
	    query = sparqlParser.parse(istr);
	    sparqlParser.clear(BASE_URI); // clear out namespaces and base URI.
	}

	/* Parse data. */
	if (defGraph != NULL)
	    read(defGraph, baseURI, d.ensureGraph(NULL));

	for (size_t i = 0; i < namedCount; ++i)
	    read(namedGraphs[i].source, baseURI, d.ensureGraph(F.getURI(namedGraphs[i].name)));

	/* Exectute query. */
	setRdfDB(construct ? &constructed : &d);
	query->execute(&d, this);
    }

    /* SPARQUL tests consist of:
     *   a trig (set of graphs) for input
     *   a query to perform
     */
    MeasuredRS (const char* input, const char* queryPath)
	: ResultSet(&F) {
 
	std::string baseURI(queryPath);
	baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);
	Operation* query;

	/* Parse query. */
	{
	    sparqlParser.setBase(baseURI);
	    IStreamContext istr(queryPath, IStreamContext::FILE);
	    query = sparqlParser.parse(istr);
	    sparqlParser.clear(BASE_URI); // clear out namespaces and base URI.
	}

	/* Parse data. */
	if (input != NULL) {
	    if (!::strcmp(input+::strlen(input)-4, ".ttl")) {
		turtleParser.setGraph(d.ensureGraph(NULL));
		turtleParser.setBase(baseURI);
		IStreamContext ttl(input, IStreamContext::FILE);
		turtleParser.parse(ttl);
		turtleParser.clear(BASE_URI);
	    } else {
		trigParser.setDB(&d);
		trigParser.setBase(baseURI);
		IStreamContext istr(input, IStreamContext::FILE);
		trigParser.parse(istr);
		trigParser.clear(BASE_URI);
	    }
	}
	/* Copy db so we can show the original. */
	constructed = d;

	/* Exectute query. */
	setRdfDB(&constructed);
	query->execute(&d, this);
    }
    ~MeasuredRS () {
	delete sparqlParser.root;
    }
};

/* Measured result sets are generally printed if there's an error so
 * the diagnostic information includes:
 *   input data
 *   query
 *   the resulting result set.
 */

std::ostream& operator<< (std::ostream& os, MeasuredRS const& my) {
    os << "Database: " << my.d;
    os << "query: " << *sparqlParser.root;
    os << "\nresult:\n";

    if (my.isOrdered())
	return operator<<(os, (ResultSet&)my);

    ResultSet orderedCopy(my);
    orderedCopy.order();
    operator<<(os, orderedCopy);
    return os;
}

/* ReferenceRS represent the expected results of a query on some
 * database. To simplify visual comparison, ReferenceRS emulates the
 * column order from a measured result set. ReferenceRS encapsulates a
 * ResultSet and provides only the interfaces needed for the DAWG
 * tests.
 */
struct ReferenceRS {
    ResultSet& measured;
    ResultSet* reference;
    RdfDB rdfDB;

    ReferenceRS (ResultSet& measured, const char* resultFile, 
		AtomFactory* atomFactory, SWSAXparser* saxParser) : 
	measured(measured) {
	std::string baseURI;
	if (resultFile != NULL) {
	    baseURI = resultFile;
	    baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);
	}

	if (resultFile == NULL) {	/* empty result graph */
	    reference = new ResultSet(atomFactory, &rdfDB);

	} else {
	    std::string rfs(resultFile);
	    IStreamContext istr(resultFile, IStreamContext::FILE);
	    if (rfs.substr(rfs.size()-4, 4) == ".srx" ||
		rfs.substr(rfs.size()-4, 4) == ".srt" ||
		rfs.substr(rfs.size()-4, 4) == ".srj" ||
		rfs.substr(rfs.size()-4, 4) == ".csv" ||
		rfs.substr(rfs.size()-4, 4) == ".tsv") {
		reference = new ResultSet(atomFactory, saxParser, istr);
	    } else {			/* retults in a graph */
		if (rfs.substr(rfs.size()-4, 4) == ".nt" || 
		    rfs.substr(rfs.size()-4, 4) == ".ttl") {
		    turtleParser.setGraph(rdfDB.ensureGraph(NULL));
		    IStreamContext ttl(rfs.c_str(), IStreamContext::FILE);
		    if (resultFile != NULL)
			turtleParser.setBase(baseURI);
		    turtleParser.parse(ttl);
		    turtleParser.clear(BASE_URI);
		} else if (rfs.substr(rfs.size()-5, 5) == ".trig") {			       
		    if (resultFile != NULL)
			trigParser.setBase(baseURI);
		    trigParser.setDB(&rdfDB);
		    IStreamContext trig(rfs.c_str(), IStreamContext::FILE);
		    trigParser.parse(trig);			       
		    trigParser.clear(BASE_URI);					       
		} else if (rfs.substr(rfs.size()-4, 4) == ".rdf") {
		    GRdfXmlParser.parse(rdfDB.ensureGraph(NULL), istr);
		} else {
		    throw std::string("unable to parse results file ") + rfs.c_str();
		}

		/* if !RESULT_Graphs, graph is an RDF form of a ResultSet. */
		reference = measured.resultType == ResultSet::RESULT_Graphs ?
		    new ResultSet(atomFactory, &rdfDB) :
		    new ResultSet(atomFactory, &rdfDB, BASE_URI);
	    }
	}
	if (measured.resultType == ResultSet::RESULT_Graphs)
	    rdfDB.ensureGraphs(measured.getRdfDB()->getGraphNames());
    }
    ~ReferenceRS () { delete reference; }

    /* As with measured ResultSets, reference ResultSets are ordered when
     * serialized if the query constructing the measured ResultSet did not
     * specify an order.
     */

    std::ostream& print (std::ostream& os, MediaType mediaType = MediaType()) const {
	if (reference->isOrdered() == true)
	    return operator<<(os, *reference);

	ResultSet orderedCopy(*reference);
	orderedCopy.leadWithColumns(measured.getOrderedVars());
	orderedCopy.order();
	os << "\n";
	return os << orderedCopy.toString(mediaType);
    }

    std::string toString (MediaType mediaType = MediaType()) const {
	std::stringstream ss;
	print(ss, mediaType);
	return ss.str();
    };
};

/* Compare a measured ResultSet to an encapsulated refrence ResultSet.
 */
bool operator== (ResultSet const& measured, ReferenceRS const& expected) {
    return measured == *expected.reference;
}

std::ostream& operator<< (std::ostream& os, ReferenceRS const& my) {
    return my.print(os);
}

/* Macros for terse test syntax
 * Using macros means that error messages point you to the test invocation (a
 * great help in quicky diagnosing the failure).
 *
 * TEST_ENABLED allows you to turn on and off extension testing by defining
 * TEST_DAWG_EXTENSIONS.
 */

#ifdef TEST_DAWG_EXTENSIONS
  #define TEST_ENABLED(X) true
#else /* !TEST_DAWG_EXTENSIONS */
  #define TEST_ENABLED(X) (X) == 0
#endif /* !TEST_DAWG_EXTENSIONS */

#define DAWG_TEST(QUERY_FILE, RESULT_FILE, NGS, REQS)			       \
    RdfDB::DynamicLoading = false;					       \
    try {								       \
	if (TEST_ENABLED(REQS)) {					       \
	    MeasuredRS measured(defaultGraph, namedGraphs,		       \
				NGS, requires, REQS, QUERY_FILE);	       \
	    ReferenceRS expected(measured, RESULT_FILE, &F, &P);	       \
	    BOOST_CHECK_EQUAL(measured, expected);			       \
	}								       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

#define GRAPH_TEST(DATA_FILE, QUERY_FILE, RESULT_FILE)			       \
    try {								       \
	MeasuredRS measured(DATA_FILE, QUERY_FILE);			       \
	ReferenceRS expected(measured, RESULT_FILE, &F, &P);		       \
	BOOST_CHECK_EQUAL(measured, expected);				       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

#define DAWGSV_TEST(QUERY_FILE, RESULT_FILE, NGS, REQS)			       \
    try {								       \
	if (TEST_ENABLED(REQS)) {					       \
	    MeasuredRS measured(defaultGraph, namedGraphs,		       \
				NGS, requires, REQS, QUERY_FILE);	       \
	    const char* type =						       \
		std::string(RESULT_FILE).substr				       \
		    (::strlen(RESULT_FILE)-4, 4) == ".csv"		       \
		? "text/csv" : "text/tab-separated-values";		       \
	    std::string asCSV = measured.toString(type);		       \
	    /* w3c_sw_LINEN << "as " << type << ":\n" << asCSV; */	       \
	    IStreamContext istr(asCSV, IStreamContext::STRING, type);	       \
	    TTerm::String2BNode bnodeMap;				       \
	    ResultSet parsed(&F, istr, measured.isOrdered(), &bnodeMap);       \
	    ReferenceRS expected(measured, RESULT_FILE, &F, &P);	       \
	    /* w3c_sw_LINEN << "parsed:\n" << parsed.toString("text/sparql-results;datatypes=explicit"); */ \
	    /* w3c_sw_LINEN << "expected:\n" << expected.toString("text/sparql-results;datatypes=explicit"); */ \
	    BOOST_CHECK_EQUAL(parsed, expected);			       \
	}								       \
    } catch (NotImplemented& e) {					       \
	std::cerr << e.what() << "\n";					       \
	BOOST_ERROR ( std::string("require implementation of ") + e.brief );   \
    } catch (std::string& s) {						       \
	BOOST_ERROR ( s );						       \
    } catch (std::exception& s) {					       \
	BOOST_ERROR ( s.what() );					       \
    }

/* ReferenceDB -- loads an RDF db from LabeledGraphs.
 */
struct ReferenceDB : public RdfDB {
    ReferenceDB (const char* defGraph, 
		 const LabeledGraph namedGraphs[], size_t namedCount, 
		 const char* queryPath, bool noTruncate = false)
	: RdfDB() {

	std::string baseURI(queryPath);
	if (!noTruncate)
	    baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);

	/* Parse data. */
	if (defGraph != NULL)
	    MeasuredRS::read(defGraph, baseURI, ensureGraph(NULL));

	for (size_t i = 0; i < namedCount; ++i)
	    MeasuredRS::read(namedGraphs[i].source, baseURI, ensureGraph(F.getURI(namedGraphs[i].name)));
    }

    ReferenceDB (const char* trig, const char* queryPath)
	: RdfDB() {

	std::string baseURI(queryPath);
	baseURI = baseURI.substr(0, baseURI.find_last_of("/")+1);

	/* Parse data. */
	if (trig != NULL)
	    MeasuredRS::read(trig, baseURI, this);
    }
};

// /* Compare a measured ResultSet to an encapsulated refrence ResultSet.
//  */
// bool operator== (ResultSet const& measured, ReferenceDB const& expected) {
//     return measured == *expected.reference;
// }

// std::ostream& operator<< (std::ostream& os, ReferenceDB const& my) {
//     return my.print(os);
// }

