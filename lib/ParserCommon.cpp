/* ParserCommon.cc - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.cpp,v 1.3 2008-10-10 11:52:37 eric Exp $
 */

#include "SWObjects.hpp"
#include "location.hpp"
#include "ParserCommon.hpp"
#include <fstream>
#include <iostream> // for cerr

namespace w3c_sw {

    const wchar_t nonIRIchars[][2] = {
	{0x00000, 0x00020}, {0x00022, 0x00022}, {0x0003c, 0x0003c}, 
	{0x0003e, 0x0003e}, {0x0005c, 0x0005c}, {0x0005e, 0x0005e},
	{0x00060, 0x00060}, {0x0007b, 0x0007d}, {0x0d800, 0x0dfff},
	{0x0fdd0, 0x0fdef}, {0x0fffe, 0x0ffff}, {0x1fffe, 0x1ffff},
	{0x2fffe, 0x2ffff}, {0x3fffe, 0x3ffff}, {0x4fffe, 0x4ffff},
	{0x5fffe, 0x5ffff}, {0x6fffe, 0x6ffff}, {0x7fffe, 0x7ffff},
	{0x8fffe, 0x8ffff}, {0x9fffe, 0x9ffff}, {0xafffe, 0xaffff},
	{0xbfffe, 0xbffff}, {0xcfffe, 0xcffff}, {0xdfffe, 0xdffff},
	{0xefffe, 0xeffff}, {0xffffe, 0xfffff}, {0x10fffe, 0x7fffffff}};

    const CharacterRange CharacterRange::NonIRI(nonIRIchars, sizeof(nonIRIchars) / sizeof(nonIRIchars[0]));


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

