/*
 g++ -o examples/simple examples/simple.cpp -I. -Ilib -Llib -lSWObjects -lboost_regex-mt && ./examples/simple
 */

#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "RdfDB.hpp"
#include "ResultSet.hpp"

#define BASE_URI ""

using namespace w3c_sw;

int main () {

    POSFactory f;
    RdfDB db;
    SPARQLfedDriver sparqlParser(BASE_URI, &f);
    TurtleSDriver turtleParser(BASE_URI, &f);
    ResultSet rs(&f);

    IStreamContext q("select*{?s?p?o}", IStreamContext::STRING);
    if (sparqlParser.parse(q))
	throw std::string("failed to parse query string \"") + q.nameStr +"\".";

    turtleParser.setGraph(db.assureGraph(NULL));
    IStreamContext ttl("<s1> <p1> <o1> ."
		       "<s1> <p1> <o1> ." // identical to first statement.
		       "<s1> <p1> <o2> .", IStreamContext::STRING);
    turtleParser.parse(ttl);

    sparqlParser.root->execute(&db, &rs);
    /* Print something about the result set. */
    std::cout << "rs has " << rs.size() << " rows" << std::endl;
    /* toString the result set. */
    std::cout << rs;
    /* Iterate across the result set. */
    for (ResultSetConstIterator row = rs.begin();
	 row != rs.end(); ++row) {
	for (BindingSetIterator b = (*row)->begin(); b != (*row)->end(); ++b) {
	    if (b != (*row)->begin())
		std::cout << ", ";
	    const POS* var = b->first;
	    const POS* val = b->second.pos;
	    std::cout << var->toString() << ":" << val->toString();
	}
	std::cout << std::endl;
    }
    return 0;
}

