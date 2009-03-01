/* ParserCommon.cc - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.cpp,v 1.3 2008-10-10 11:52:37 eric Exp $
 */

#include "SWObjects.hpp"
#include "location.hh"
#include "ParserCommon.hpp"
#include <fstream>
#include <iostream> // for cerr

namespace w3c_sw {

    Driver::Driver (POSFactory* posFactory)
	: posFactory(posFactory), namespaces(), base(NULL), ignorePrefixFlag(false), trace_scanning(false), trace_parsing(false) {  }

    Driver::Driver (std::string baseURI, POSFactory* posFactory)
	: posFactory(posFactory), namespaces(), base(getURI(baseURI)), ignorePrefixFlag(false), trace_scanning(false), trace_parsing(false) {  }

    bool Driver::parse_file (const std::string &filename) {
	std::ifstream in(filename.c_str());
	return parse_stream(in, filename);
    }

    bool Driver::parse_string (const std::string &input, const std::string& sname) {
	std::istringstream iss(input);
	return parse_stream(iss, sname);
    }

    void Driver::error (const class location& l,
			const std::string& m) {
	std::cerr << l << ": " << m << std::endl;
    }

    void Driver::error (const std::string& m) {
	std::cerr << m << std::endl;
    }

    URI* Driver::getAbsoluteURI (std::string name) {
	std::string str = base ? base->getTerminal() : "";
	std::string abs(libwww::HTParse(name, base ? &str : NULL, libwww::PARSE_all));
	return posFactory->getURI(abs.c_str());
    }

} //namespace w3c_sw

void stop (size_t line) {
    std::cerr << "should have stopped with a " << line << std::endl;
}

