/**
 * malloc and free test, best used with Valgrind or some such heap checker.

CPATH= g++ -o bin/parseAndFree bin/parseAndFree.cpp -DSPARQL11_ALL -DYYTEXT_POINTER=1 -fPIC -g -O0 -W -Wall -Wextra -Wnon-virtual-dtor -ansi -std=c++98 -I../libbooost.inst/include/ -I/usr/local/instantclient_11_2/sdk/include/ -I. -I./lib -I./docs -I./SPARQLfedParser -Iboost-log-1.46 -pipe -Wno-empty-body -Wno-missing-field-initializers -Wwrite-strings -Wno-deprecated -Wno-unused -Wno-non-virtual-dtor -Wno-variadic-macros -ftemplate-depth-128 -fno-merge-constants -L./lib -lSWObjects -Lboost-log-1.46/stage/lib -lboost_log-1.46 -lrt -lboost_thread -lboost_filesystem -lboost_system -lboost_date_time -lboost_regex -lpthread -lboost_system -lexpat -lmysqlclient -lz -lpq -lodbc -lltdl -ldl -lboost_unit_test_framework

 */

#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SWObjectDuplicator.hpp"
#include "SPARQLSerializer.hpp"

using namespace w3c_sw;

int main (int argc, char* argv[]) {
    {
	AtomFactory f;
	SPARQLfedDriver sparqlParser("", &f);
	bool duplicate = false;
	bool serialize = false;
	int argno = 1;

	for (; argno < argc; ++argno)
	    if (!::strcmp("--duplicate", argv[argno]))
		duplicate = true;
	    else if (!::strcmp("--serialize", argv[argno]))
		serialize = true;
	    else
		break;

	for (; argno < argc; ++argno) {
	    IStreamContext istr(argv[argno], IStreamContext::FILE);
	    const Operation* op = sparqlParser.parse(istr);
	    if (duplicate) {
		SWObjectDuplicator d(&f);
		op->express(&d);
		delete op;
		op = d.last.operation;
	    }
	    if (serialize) {
		SPARQLSerializer s;
		op->express(&s);
		std::cout << s.str();
	    }
	    delete op;
	}
    }
    return 0;
}
