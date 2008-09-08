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

void usage (const char* exe) {
    cerr << "USAGE: " << exe << " [-sstem|-s stem] [-bbase|-s base] <query file> <SPARQL CONSTRUCT rule file>*" << endl;
}

bool option (int argc, char** argv, int* iArg) {
    if (argv[*iArg][0] == '-' && (argv[*iArg][1] == 'b' || argv[*iArg][1] == 's')) {
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
    w3c_sw::QueryMapper queryMapper(&posFactory);

    int result;
    w3c_sw::Operation* query = NULL;
    try {
	char* inputId;
	try {
	    int iArg = 1;
	    while (iArg < argc && option(argc, argv, &iArg))
		++iArg;
	    result = sparqlParser.parse_file(inputId = argv[iArg++]);
	    query = sparqlParser.root;

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
		    cerr << "Rule file " << (queryMapper.getRuleCount() + 1) << ": " << inputId << " was not a SPARQL CONSTRUCT.";
		    usage(argv[0]);
		    return 1;
		}
	    }
	} catch (runtime_error& e) {
	    cout << "Parsing problem runtime_error:" << e.what() << endl;
	    throw(e);
	} catch (exception& e) {
	    cout << "Parsing problem exception:" << e.what() << endl;
	    throw(e);
	}


	if (result)
	    cerr << "Error: " << inputId << " did not contain a valid SPARQLfed string." << endl;
	else {
	    try {
		Operation* o;
		if (queryMapper.getRuleCount() > 0) {
		    o = query->express(&queryMapper);
		    delete query;
		} else
		    o = query;

// 		XMLQueryExpressor xmlizer("  ", false);
// 		o->express(&xmlizer);
// 		cout << "post-rule query (XML):" << endl << xmlizer.getXMLstring() << endl;

		SPARQLSerializer sparqlizer("  ");
		o->express(&sparqlizer);
		cout << "post-rule query (SPARQL):" << endl << sparqlizer.getSPARQLstring() << endl;

		if (StemURI) {
		    char predicateDelims[]={'#',' ',' '};
		    char nodeDelims[]={'/','.',' '};
		    SQLizer s2(StemURI, predicateDelims, nodeDelims);
		    o->express(&s2);
		    cout << "Transformed query: " << endl << s2.getSPARQLstring() << endl;
		}
		delete o;
	    } catch (runtime_error& e) {
		cout << "Serialization problem:" << e.what() << endl;
		throw(e);
	    } catch (exception& e) {
		cout << "Serialization problem:" << e.what() << endl;
		throw(e);
	    }
	}

	return result;

    } catch (runtime_error& e) {
	cout << "Runtime error: " << e.what() << endl;
    } catch (exception& e) {
	cout << "Exception: " << e.what() << endl;
    }
    return -1;
};

/* END main */

