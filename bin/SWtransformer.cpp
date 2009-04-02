/* SWtransformer — transform interface SPARQL queries to proprietary
 * queries or SQL queries.
 *
 * $Id: SWtransformer.cpp,v 1.21 2008-11-05 22:12:52 eric Exp $
 */

/* START main */

#include <stdio.h>  // -\_for strcmp
#include <string.h> // -/
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "XMLQueryExpressor.hpp"
#include "QueryMapper.hpp"
#include "SPARQLSerializer.hpp"
#include "SQLizer.hpp"

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
#elif XML_PARSER == SWOb_MSXML3
  #include "../interface/SAXparser_msxml3.hpp"
#else
  #ifdef _MSC_VER
    #pragma message ("query federation requires an XML parser")
  #else /* !_MSC_VER */
    #warning query federation requires an XML parser
  #endif /* !_MSC_VER */
#endif

#if HTTP_CLIENT == SWOb_ASIO
  #include "RdfRemoteDB.hpp"
  #include "../interface/WEBagent_boostASIO.hpp"
#endif /* HTTP_CLIENT == SWOb_ASIO */

#include <stdlib.h>
#include <ostream>
#include <fstream>

using namespace std;

const char* BaseURI = "http://example.org/";
const char* StemURI = NULL;
const char* PkAttr = "id";
std::ostream* DebugStream = NULL;
SPARQLSerializer::e_DEBUG SerializereDebugFlags = SPARQLSerializer::DEBUG_none;
bool Quiet = false;
#if XML_PARSER != SWOb_DISABLED && HTTP_CLIENT != SWOb_DISABLED
  bool ExecuteQuery = false;
#endif
std::vector<const char*>SparqlEndpointPatterns;

void usage (const char* exe) {
    cerr << "USAGE: " << exe << " [-d] [-q] [-bbase|-b base] [-sstem|-s stem] <query file or '-' for stdin> <SPARQL CONSTRUCT rule file>*" << endl;
}

bool option (int argc, char** argv, int* iArg) {
    if (!::strcmp(argv[*iArg], "-d")) {
	DebugStream = &std::cerr;
	SerializereDebugFlags = SPARQLSerializer::DEBUG_graphs;
	return true;
    } else if (!::strcmp(argv[*iArg], "-q")) {
	Quiet = true;
	return true;
    } else if (!::strcmp(argv[*iArg], "-x")) {
#if XML_PARSER == SWOb_DISABLED || HTTP_CLIENT == SWOb_DISABLED
	throw "SWtransformer cannot execute federation queries as it was not compiled with an XML parser.";
#else /* ! XML_PARSER == SWOb_DISABLED || HTTP_CLIENT == SWOb_DISABLED */
	ExecuteQuery = true;
#endif /* ! XML_PARSER == SWOb_DISABLED || HTTP_CLIENT == SWOb_DISABLED */
	return true;
    } else if (argv[*iArg][0] == '-' && (argv[*iArg][1] == 'b' || argv[*iArg][1] == 's')) {
	const char** target = argv[*iArg][1] == 'b' ? &BaseURI : &StemURI;
	if (argv[*iArg][2] == '\0')
	    if (*iArg > argc - 2)
		usage(argv[0]);
	    else
		*target = argv[++(*iArg)];
	else
	    *target = argv[*iArg]+2;
	return true;
    } else if (!::strncmp(argv[*iArg], "-p", 2)) {
	if (argv[*iArg][2] == '\0')
	    if (*iArg > argc - 2)
		usage(argv[0]);
	    else
		PkAttr = argv[++(*iArg)];
	else
	    PkAttr = argv[*iArg]+2;
	return true;
    } else if (!::strncmp(argv[*iArg], "--sparql-pattern", 16)) {
	if (argv[*iArg][16] == '\0')
	    if (*iArg > argc - 2)
		usage(argv[0]);
	    else
		SparqlEndpointPatterns.push_back(argv[++(*iArg)]);
	else
	    SparqlEndpointPatterns.push_back(argv[*iArg]+2);
	return true;
    }
    return false;
}

int main(int argc,char** argv) {
    if (argc < 1) {
	usage(argv[0]);
	return 1;
    }

    /* Tools we'll need for this demo: */
    w3c_sw::POSFactory posFactory;
    w3c_sw::SPARQLfedDriver sparqlParser("", &posFactory);
    //w3c_sw::TurtleSDriver turtleParser(BaseURI, &posFactory);
    w3c_sw::QueryMapper queryMapper(&posFactory, &DebugStream);

    int result;
    w3c_sw::Operation* query = NULL;
    try {
	char* inputId;
	try {
	    int iArg = 1;
	    while (iArg < argc && option(argc, argv, &iArg))
		++iArg;
	    if (iArg == argc) {
		cerr << "No query specified." << endl;
		usage(argv[0]);
		return 1;
	    }

	    /* Parse input query. */
	    inputId = argv[iArg++];
	    if (inputId[0] == '-' && inputId[1] == '\0') {
		inputId = (char*)"- standard input -";
		result = sparqlParser.parse_stream(cin);
	    } else
		result = sparqlParser.parse_file(inputId);
	    query = sparqlParser.root;

	    /* Parse deduction rules. */
	    for (; iArg < argc && !result; ++iArg) {
		if (option(argc, argv, &iArg))
		    continue;
		result = sparqlParser.parse_file(inputId = argv[iArg]);
		Operation* rule = sparqlParser.root;
		Construct* c;
		if ((c = dynamic_cast<Construct*>(rule)) != NULL) {
		    queryMapper.addRule(c);
		    delete rule;
		} else {
		    cerr << "Rule file " << (queryMapper.getRuleCount() + 1) << ": " << inputId << " was not a SPARQL CONSTRUCT." << endl;
		    usage(argv[0]);
		    return 1;
		}
	    }
	} catch (runtime_error& e) {
	    cerr << "Parsing problem runtime_error:" << e.what() << endl;
	    throw(e);
	} catch (exception& e) {
	    cerr << "Parsing problem exception:" << e.what() << endl;
	    throw(e);
	}


	if (result)
	    cerr << "Error: " << inputId << " did not contain a valid SPARQLfed string." << endl;
	else {
	    try {
		const Operation* o;
		if (queryMapper.getRuleCount() > 0) {
		    if (DebugStream != NULL)
			*DebugStream << "Transforming user query by applying " << queryMapper.getRuleCount() << " rule maps." << std::endl;
		    query->express(&queryMapper);
		    o = queryMapper.last.operation;
		    delete query;
		} else
		    o = query;

// 		XMLQueryExpressor xmlizer("  ", false);
// 		o->express(&xmlizer);
// 		cout << "post-rule query (XML):" << endl << xmlizer.getString() << endl;

		{
		    SPARQLSerializer sparqlizer("  ", StemURI == NULL ? SPARQLSerializer::DEBUG_none : SerializereDebugFlags);
		    o->express(&sparqlizer);
		    if (!Quiet)
			cout << "post-rule query (SPARQL):" << endl;
		    if (!Quiet || StemURI == NULL)
			cout << sparqlizer.getString() << endl;
		}

		if (StemURI != NULL) {
		    char predicateDelims[]={'#',' ',' '};
		    char nodeDelims[]={'/','.',' '};
		    SQLizer s2(StemURI, predicateDelims, nodeDelims, PkAttr, &DebugStream);
		    o->express(&s2);
		    if (!Quiet)
			cout << "Transformed query: " << endl;
		    cout << s2.getSQLstring() << endl;
		}
#if XML_PARSER != SWOb_DISABLED && HTTP_CLIENT != SWOb_DISABLED
		else if (ExecuteQuery) {
		    SWSAXparser* p = SWSAXparser::makeSAXparser();
		    WEBagent_boostASIO client;
		    RdfRemoteDB db(SparqlEndpointPatterns, p, &client);
		    ResultSet rs(&posFactory);
		    o->execute(&db, &rs);
		    delete p;
		    std::cout << rs; // show results
		}
#endif /* XML_PARSER != SWOb_DISABLED && HTTP_CLIENT != SWOb_DISABLED */
		delete o;
	    } catch (runtime_error& e) {
		cerr << "Serialization problem:" << e.what() << endl;
		return -1;
	    } catch (exception& e) {
		cerr << "Serialization problem:" << e.what() << endl;
		return -1;
	    } catch (std::string& e) {
		cerr << "Serialization problem:" << e << endl;
		return -1;
	    }
	}

	return result;

    } catch (runtime_error& e) {
	cerr << "runtime_error: " << e.what() << endl;
    } catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
    } catch (std::string& e) {
	cerr << "std::string exception: " << e << endl;
    }
    return -1;
}

/* END main */

