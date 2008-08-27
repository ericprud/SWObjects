/* START main */

#include <stdio.h>
#include "SPARQLfedParser.hpp"
#include "TurtleSParser.hpp"
#include "XMLQueryExpressor.hpp"
#include "RdfQueryDB.hpp"
#include "QueryMapper.hpp"
#include "SPARQLSerializer.hpp"
//#include "SQLizer.hh"

#include <stdlib.h>
#include <ostream>
#include <fstream>

using namespace std;

int main(int argc,char** argv) {
    const char* baseURI = "http://example.org/";

    if (argc < 1) {
	cerr << "USAGE: " << argv[0] << " <query file> <SPARQL CONSTRUCT rule file>*" << endl;
	return 1;
    }

    /* Tools we'll need for this demo: */
    w3c_sw::POSFactory posFactory;
    w3c_sw::SPARQLfedDriver sparqlParser("", &posFactory);
    w3c_sw::TurtleSDriver turtleParser(baseURI, &posFactory);
    w3c_sw::QueryMapper d(&posFactory);

    int result;
    w3c_sw::Operation* query = NULL;
    try {
	char* inputId;
	try {
	    result = sparqlParser.parse_file(inputId = argv[1]);
	    query = sparqlParser.root;

	    for (int i = 2; i < argc && !result; i++) {
		result = sparqlParser.parse_file(inputId = argv[i]);
		Operation* rule = sparqlParser.root;
		Construct* c;
		if ((c = dynamic_cast<Construct*>(rule)) != NULL) {
		    d.addRule(c);
		    delete rule;
		} else {
		    cerr << "Rule file " << i - 2 << ": " << inputId << " was not a SPARQL CONSTRUCT.";
		    cerr << "USAGE: " << argv[0] << " <query file> <SPARQL CONSTRUCT rule file>*" << endl;
		    return 1;
		}
	    }
	} catch (runtime_error& e) {
	    cout << "Parsing problem runtime_error:" << endl;
	    throw(e);
	} catch (exception& e) {
	    cout << "Parsing problem exception:" << endl;
	    throw(e);
	}


	if (result)
	    cerr << "Error: " << inputId << " did not contain a valid SPARQLfed string." << endl;
	else {
	    try {
		if (query) {
		    XMLQueryExpressor xmlizer("  ", false);
		    query->express(&xmlizer);
		    cout << "input query (XML):" << endl << xmlizer.getXMLstring() << endl;

		    SPARQLSerializer sparqlizer("  ");
		    query->express(&sparqlizer);
		    cout << "input query (SPARQL):" << endl << sparqlizer.getSPARQLstring() << endl;

#if 1
		    Operation* o = query->express(&d);
		    SPARQLSerializer s2;
		    o->express(&s2);
		    delete o;
		    cout << "Transformed query: " << s2.getSPARQLstring() << endl;
#endif
#if 0
		    Operation* o = query->express(&d);
		    SQLizer s2("http://myCo.exampe/DB/");
		    o->express(&s2);
		    delete o;
		    cout << "Transformed query: " << s2.getSPARQLstring() << endl;
#endif
		    delete query;
		}

	    } catch (runtime_error& e) {
		cout << "Serialization problem:" << endl;
		throw(e);
	    } catch (exception& e) {
		cout << "Serialization problem:" << endl;
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

