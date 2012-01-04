/** @file test_BackChain.cpp - test BackwardChainingRdfDB.hpp
 *
 * $Id: test_BackChain.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE BackChain

#include <map>
#include <vector>
#include "SWObjects.hpp"
#include "MapSetParser/MapSetParser.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "BackwardChainingRdfDB.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#include <boost/test/unit_test.hpp>
w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,IO,Rewrite:3"

namespace sw = w3c_sw;

sw::AtomFactory F;
sw::MapSetDriver mapSetParser("", &F);

typedef sw::SWSAXhandler::QName QName;

const std::string Piqflow = "http://www.semanticbits.com/piq-workflow/";

/**
 * Enable copious logging.
 */
void logAllAt3 () {
    boost::shared_ptr< sw::Logger::Sink_t > sink = sw::Logger::prepare();
    sw::Logger::addStream(sink, boost::shared_ptr< std::ostream >(&std::clog, boost::log::empty_deleter()));
    for (std::vector<const char*>::const_iterator it = sw::Logger::Labels.begin();
	 it != sw::Logger::Labels.end(); ++it)
	sw::Logger::getLabelLevel(*it) = sw::Logger::severity_level(3);
}

BOOST_AUTO_TEST_CASE( backwardChainOne ) {
    sw::TurtleSDriver tparser("", &F);
    sw::SPARQLfedDriver sparser("", &F);

    // The rules:
    sw::MapSet* ms = mapSetParser.parse("\
PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>\n\
LABEL <x-sub-z>\n\
CONSTRUCT { ?x rdfs:subClassOf ?z }\n\
    WHERE { ?x rdfs:subClassOf ?y . ?y rdfs:subClassOf ?z }\n\
LABEL <x-a-z>\n\
CONSTRUCT { ?x a ?z }\n\
    WHERE { ?x a ?y . ?y rdfs:subClassOf ?z }\n\
");
    sw::BackwardChainingRdfDB db(&F, ms);

    tparser.parse("\
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n\
<fido> a <Dog> .\n\
<fluffy> a <Cat> .\n\
<Dog> rdfs:subClassOf <Mammal> .\n\
", &db);
    sw::ResultSet rs(&F);

    sw::Operation* q = sparser.parse("\
SELECT ?e WHERE { ?e a <Mammal> }\n\
");

    q->execute(&db, &rs);

    sw::TTerm::String2BNode bnodeMap;
    sw::ResultSet ref(&F,
		      "?e\n"
		      "<fido>", false, bnodeMap);

    BOOST_CHECK_EQUAL(rs, ref);
}


