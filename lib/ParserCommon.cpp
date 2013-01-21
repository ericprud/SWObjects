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
    YaccDriver::YaccDriver (AtomFactory* atomFactory)
	: ParserDriver(), atomFactory(atomFactory),
	  ignorePrefixFlag(false),
	  trace_scanning(false), trace_parsing(false) {  }

    YaccDriver::YaccDriver (std::string baseURI, AtomFactory* atomFactory)
	: ParserDriver(baseURI), atomFactory(atomFactory),
	  ignorePrefixFlag(false),
	  trace_scanning(false), trace_parsing(false) {  }

    void YaccDriver::error (const class location& l,
			    const std::string& m) {
	std::stringstream ss;
	ss << l << ": " << m;
	ParserException p(ParserLocation(l.begin.filename, l.begin.line, l.begin.column),
			  ParserLocation(l.end.filename, l.end.line, l.end.column), ss.str());
	if (false)
	    throw p;
	else
	    errors.push_back(p);
    }

    void YaccDriver::checkErrors () {
	if (errors.size() == 0)
	    return;
	if (errors.size() == 1)
	    throw errors[0];
	throw errors;
	// std::stringstream ss;
	// for (std::vector<ParserException>::const_iterator it = errors.begin();
	//      it != errors.end(); ++it) {
	//     if (it != errors.begin())
	// 	ss << "\n--\n";
	//     ss << it->what();
	// }
	// StringException p(errors[0].begin, errors[0].end, ss.str());
	// errors.clear();
	// throw p;
    }

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

