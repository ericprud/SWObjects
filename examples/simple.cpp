/*
 * g++ -o examples/simple bin/simple.cpp -I/tmp/swobjects-trunk -I/tmp/swobjects-trunk/lib -L/tmp/swobjects-trunk/lib -lSWObjects -lboost_regex-mt && ./bin/simple
 */

#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"

#define BASE_URI ""

using namespace w3c_sw;

int main () {

    POSFactory F;
    SPARQLfedDriver sparqlParser(BASE_URI, &F);
    TurtleSDriver turtleParser(BASE_URI, &F);

    IStreamContext q("select*{?s?p?o}", IStreamContext::STRING);
    if (sparqlParser.parse(q))
	throw std::string("failed to parse query string \"") + q.nameStr + "\".";

    RdfDB db;

    turtleParser.setGraph(db.assureGraph(NULL));
    IStreamContext ttl("<s1> <p1> <o1> .<s1> <p1> <o2> .<s1> <p1> <o1> .", IStreamContext::STRING);
    turtleParser.parse(ttl);

    ResultSet rs(&F);
    sparqlParser.root->execute(&db, &rs);
    std::cout << rs.size() << std::endl;
    return 0;
}

