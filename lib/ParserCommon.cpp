/* ParserCommon.cc - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.cpp,v 1.3 2008-10-10 11:52:37 eric Exp $
 */

#include "SWObjects.hpp"
#include "location.hpp"
#include "ParserCommon.hpp"
#include <fstream>
#include <iostream> // for cerr

namespace w3c_sw {

    /* Base class for Yacc parsers. */
    YaccDriver::YaccDriver (AtomFactory* atomFactory, size_t abortErrorCount)
	: ParserDriver(), atomFactory(atomFactory),
	  ignorePrefixFlag(false), abortErrorCount(abortErrorCount),
	  trace_scanning(false), trace_parsing(false) {  }

    YaccDriver::YaccDriver (std::string baseURI, AtomFactory* atomFactory, size_t abortErrorCount)
	: ParserDriver(baseURI), atomFactory(atomFactory),
	  ignorePrefixFlag(false), abortErrorCount(abortErrorCount),
	  trace_scanning(false), trace_parsing(false) {  }

    void YaccDriver::error (const std::string& m) {
	throw m;
    }

    const URI* YaccDriver::getAbsoluteURI (std::string name) {
	return atomFactory->getURI(libwww::GetAbsoluteURIstring(name, baseURI));
    }

} //namespace w3c_sw

void stop (size_t line) {
    std::cerr << "should have stopped with a " << line << std::endl;
}

