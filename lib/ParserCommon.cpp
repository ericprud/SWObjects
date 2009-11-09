/* ParserCommon.cc - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.cpp,v 1.3 2008-10-10 11:52:37 eric Exp $
 */

#include "SWObjects.hpp"
#include "location.hpp"
#include "ParserCommon.hpp"
#include <fstream>
#include <iostream> // for cerr

namespace w3c_sw {

    /* Base class for all parsers. */
    ParserDriver::ParserDriver ()
	: baseURI("") {  }

    ParserDriver::ParserDriver (std::string baseURI)
	: baseURI(baseURI) {  }


    /* Base class for Yacc parsers. */
    YaccDriver::YaccDriver (POSFactory* posFactory)
	: ParserDriver(), posFactory(posFactory), namespaces(), ignorePrefixFlag(false), trace_scanning(false), trace_parsing(false) {  }

    YaccDriver::YaccDriver (std::string baseURI, POSFactory* posFactory)
	: ParserDriver(baseURI), posFactory(posFactory), namespaces(), ignorePrefixFlag(false), trace_scanning(false), trace_parsing(false) {  }

    bool YaccDriver::parse_file (const std::string &filename) {
	std::ifstream in(filename.c_str());
	if (!in.is_open())
	    throw std::string("unable to open file \"") + filename + "\"";
	return parse_stream(in, filename);
    }

    bool YaccDriver::parse_string (const std::string &input, const std::string& sname) {
	std::istringstream iss(input);
	return parse_stream(iss, sname);
    }

    void YaccDriver::error (const class location& l,
			const std::string& m) {
	std::cerr << l << ": " << m << std::endl;
    }

    void YaccDriver::error (const std::string& m) {
	std::cerr << m << std::endl;
    }

    const URI* YaccDriver::getAbsoluteURI (std::string name) {
	std::string abs(libwww::HTParse(name, &baseURI, libwww::PARSE_all));
	return posFactory->getURI(abs.c_str());
    }

} //namespace w3c_sw

void stop (size_t line) {
    std::cerr << "should have stopped with a " << line << std::endl;
}

