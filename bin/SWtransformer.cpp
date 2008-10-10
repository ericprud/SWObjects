/* SWtransformer — transform interface SPARQL queries to proprietary
 * queries or SQL queries.
 *
 * $Id: SWtransformer.cpp,v 1.16 2008-10-10 21:22:14 eric Exp $
 */

/* START main */

#include <stdio.h>
#include "SPARQLfedParser.hpp"
#include "TurtleSParser.hpp"
#include "XMLQueryExpressor.hpp"
#include "RdfQueryDB.hpp"
#include "QueryMapper.hpp"
#include "SPARQLSerializer.hpp"
#include "SQLizer.hpp"

#include <stdlib.h>
#include <ostream>
#include <fstream>

using namespace std;

const char* BaseURI = "http://example.org/";
const char* StemURI = NULL;
std::ostream* DebugStream = NULL;
SPARQLSerializer::e_DEBUG SerializereDebugFlags = SPARQLSerializer::DEBUG_none;
bool Quiet = false;

void usage (const char* exe) {
    cerr << "USAGE: " << exe << " [-d] [-q] [-bbase|-b base] [-sstem|-s stem] <query file or '-' for stdin> <SPARQL CONSTRUCT rule file>*" << endl;
}

bool option (int argc, char** argv, int* iArg) {
    if (argv[*iArg][0] == '-' && (argv[*iArg][1] == 'd')) {
	DebugStream = &std::cerr;
	SerializereDebugFlags = SPARQLSerializer::DEBUG_graphs;
	return true;
    } else if (argv[*iArg][0] == '-' && (argv[*iArg][1] == 'q')) {
	Quiet = true;
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
    w3c_sw::TurtleSDriver turtleParser(BaseURI, &posFactory);
    w3c_sw::QueryMapper queryMapper(&posFactory, DebugStream);

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
		inputId = "- standard input -";
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
		Operation* o;
		if (queryMapper.getRuleCount() > 0) {

		    query->express(&queryMapper);
		    o = queryMapper.getCopy();
		    delete query;
		} else
		    o = query;

// 		XMLQueryExpressor xmlizer("  ", false);
// 		o->express(&xmlizer);
// 		cout << "post-rule query (XML):" << endl << xmlizer.getXMLstring() << endl;

		SPARQLSerializer sparqlizer("  ", StemURI == NULL ? SPARQLSerializer::DEBUG_none : SerializereDebugFlags);
		o->express(&sparqlizer);
		if (!Quiet)
		    cout << "post-rule query (SPARQL):" << endl;
		if (!Quiet || StemURI == NULL)
		    cout << sparqlizer.getSPARQLstring() << endl;

		if (StemURI != NULL) {
		    char predicateDelims[]={'#',' ',' '};
		    char nodeDelims[]={'/','.',' '};
		    SQLizer s2(StemURI, predicateDelims, nodeDelims, DebugStream);
		    o->express(&s2);
		    if (!Quiet)
			cout << "Transformed query: " << endl;
		    cout << s2.getSPARQLstring() << endl;
		}
		delete o;
	    } catch (runtime_error& e) {
		cerr << "Serialization problem:" << e.what() << endl;
		throw(e);
	    } catch (exception& e) {
		cerr << "Serialization problem:" << e.what() << endl;
		throw(e);
	    }
	}

	return result;

    } catch (runtime_error& e) {
	cerr << "Runtime error: " << e.what() << endl;
    } catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
    }
    return -1;
}

/* END main */

