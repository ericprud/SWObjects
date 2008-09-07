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

bool option (int argc, char** argv, int* iArg, const char** stemURI) {
    if (argv[*iArg][0] == '-' && argv[*iArg][1] == 's') {
	if (argv[*iArg][2] == '\0') {
	    if (*iArg > argc - 2) {
		cerr << "USAGE: " << argv[0] << " [-sstem|-s stem] <query file> <SPARQL CONSTRUCT rule file>*" << endl;
		return false;
	    }
	    *stemURI = argv[++(*iArg)];
	} else {
	    *stemURI = argv[*iArg]+2;
	}
	return true;
    }
    return false;
}

int main(int argc,char** argv) {
    const char* baseURI = "http://example.org/";
    const char* stemURI = "http://myCo.exampe/DB/";

    if (argc < 1) {
	cerr << "USAGE: " << argv[0] << " [-sstem|-s stem] <query file> <SPARQL CONSTRUCT rule file>*" << endl;
	return 1;
    }

    /* Tools we'll need for this demo: */
    w3c_sw::POSFactory posFactory;
    w3c_sw::SPARQLfedDriver sparqlParser("", &posFactory);
    w3c_sw::TurtleSDriver turtleParser(baseURI, &posFactory);
    w3c_sw::QueryMapper queryMapper(&posFactory);

    int result;
    w3c_sw::Operation* query = NULL;
    try {
	char* inputId;
	try {
	    int iArg = 1;
	    while (iArg < argc && option(argc, argv, &iArg, &stemURI))
		++iArg;
	    result = sparqlParser.parse_file(inputId = argv[iArg++]);
	    query = sparqlParser.root;

	    for (; iArg < argc && !result; ++iArg) {
		if (option(argc, argv, &iArg, &stemURI))
		    continue;
		result = sparqlParser.parse_file(inputId = argv[iArg]);
		Operation* rule = sparqlParser.root;
		Construct* c;
		if ((c = dynamic_cast<Construct*>(rule)) != NULL) {
		    queryMapper.addRule(c);
		    delete rule;
		} else {
		    cerr << "Rule file " << (queryMapper.getRuleCount() + 1) << ": " << inputId << " was not a SPARQL CONSTRUCT.";
		    cerr << "USAGE: " << argv[0] << " <query file> <SPARQL CONSTRUCT rule file>*" << endl;
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

		char predicateDelims[]={'#',' ',' '};
		char nodeDelims[]={'/','.',' '};
		SQLizer s2(stemURI, predicateDelims, nodeDelims);
		o->express(&s2);
		delete o;
		cout << "Transformed query: " << endl << s2.getSPARQLstring() << endl;

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

