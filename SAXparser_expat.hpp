/* SAXparser_expat.hpp: implementation of SAXparser for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once
#include "SAXparser.hpp"

namespace w3c_sw {

    class SAXparser_expat : public SWSAXparser {
    protected:
	XML_Parser parser;

	std::string readFile (const char* filename, const char* type) {
	    std::ifstream dataStream(filename);
	    if (!dataStream.is_open()) {
		std::string msg = std::string("failed to ") + std::string(type) + 
		    std::string(" data \"") + filename + std::string("\".");
		throw msg;
	    }
	    std::istreambuf_iterator<char> i(dataStream), e;
	    std::string ret(i, e);
	    dataStream.close();
	    return ret;
	}

    public:
	SAXparser_expat () : parser(XML_ParserCreate(NULL)) {
	    XML_SetUserData(parser, this);
	    XML_SetElementHandler(parser, &start, &end);
	    XML_SetCharacterDataHandler(parser, &chars);
	}
	virtual ~SAXparser_expat () {
	    ::XML_ParserFree(parser);
	}

	virtual void parse (const char* file) {
	    std::string buf = readFile(file, "XML");
	    if (XML_Parse(parser, buf.c_str(), buf.size(), true) == XML_STATUS_ERROR)
		throw( "Failed to parse document.\n" );
	}

	static void start (void *userData,
			   const XML_Char *name,
			   const XML_Char **atts) {
	    printf("<%s>\n", name);
	}

	static void end (void *userData,
			 const XML_Char *name) {
	}

	static void chars (void *userData,
			   const XML_Char *s,
			   int len) {
	}
    };

}

