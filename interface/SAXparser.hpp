/* SAXparser.hpp: SAXparser interface object for SWObjects.
 * I needed to abstract the different parsers, so why not use a popular
 * interface?

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $

 * SWSAXparser and SWSAXhandler are prefixed with SW to avoid collisions with
 * implementation names.
 */

#pragma once
#include <iostream>
#include "SWObjects.hpp"

namespace w3c_sw {

    class SWSAXhandler {
    public:
	static std::string qName (const char* prefix, const char* localName) {
	    return (prefix && prefix[0] ? std::string((const char*)prefix) + '~' : std::string("")) + (const char*)localName;
	}
	class Attributes {
	public:
	    Attributes () {  }
	    virtual ~Attributes () {  }
	    virtual size_t getLength() = 0;
	    virtual std::string getLocalName(size_t i) = 0;
	    virtual std::string getURI(size_t i) = 0;
	    virtual std::string getQName(size_t i) = 0;
	    virtual std::string getValue(std::string uri, std::string localName) = 0;
	    std::string toString (std::string luri = "", std::string llname = "") {
		std::stringstream s;
		for (size_t i = 0; i < getLength(); ++i) {
		    std::string uri = getURI(i);
		    std::string lname = getLocalName(i);
		    std::string qn = getQName(i);
		    std::string val = getValue(uri, lname);
		    s << (uri == luri && lname == llname ? '!' : ' ') << 
			qn << "(" << uri << ")=\"" << val << "\"";
		}
		s << ">\ncheck: |name: " << getValue("", "name") << "\n";
		return s.str();
	    }
	};
	SWSAXhandler () {  }
	virtual ~SWSAXhandler () {  }
	virtual void startElement (std::string uri,
				   std::string localName,
				   std::string qName,
				   Attributes* attrs) {
	    std::cout << "<" << qName << " _:ns=\"" << uri << "|" << localName << "\"";
	    size_t attrCount = attrs->getLength();
	    for (size_t i = 0; i < attrCount; ++i) {
		std::cout << std::endl << "    " << attrs->getQName(i) << "=\"" << attrs->getValue(attrs->getURI(i), attrs->getLocalName(i)) << "\"";
	    }
	    std::cout << ">" << std::endl;
	}
	virtual void endElement (std::string uri,
				 std::string localName,
				 std::string qName) {
	    std::cout << "</" << qName << " _:ns=\"" << uri << "|" << localName << "\">" << std::endl;;
	}
	virtual void characters (const char ch[],
				 int start,
				 int length) {
	    std::cout << std::string(ch, start, length);
	}

	void error(const char * msg, ...) {
	    va_list args;
	    va_start(args, msg);
	    error( msg, args );
	    va_end(args);
	    throw("SWSAX exception");
	}

	virtual void error(const char* msg, va_list args) {
	    vprintf(msg, args);
	    throw("SWSAX exception");
	}

	void warning(const char * msg, ...) {
	    va_list args;
	    va_start(args, msg);
	    warning( msg, args );
	    va_end(args);
	}

	virtual void warnting(const char* msg, va_list args) {
	    vprintf(msg, args);
	}

    };

    class SAXserializer : public SWSAXhandler {
	std::ostream& out;
    public:
	SAXserializer (std::ostream& out = std::cout) : out(out) {  }
	virtual void startElement (std::string uri,
				   std::string localName,
				   std::string qName,
				   Attributes* attrs) {
	    out << "SM<" << qName << " _:ns=\"" << uri << "|" << localName << "\"";
	    size_t attrCount = attrs->getLength();
	    for (size_t i = 0; i < attrCount; ++i) {
		out << std::endl << "    " << attrs->getQName(i) << "=\"" << attrs->getValue(attrs->getURI(i), attrs->getLocalName(i)) << "\"";
	    }
	    out << ">" << std::endl;
	}
	virtual void endElement (std::string uri,
				 std::string localName,
				 std::string qName) {
	    out << "SM</" << qName << " _:ns=\"" << uri << "|" << localName << "\">" << std::endl;;
	}
	virtual void characters (const char ch[],
				 int start,
				 int length) {
	    out << std::string(ch, start, length);
	}
    };

    class SWSAXparser {
    protected:
	static std::string prefix(std::string qname) {
	    size_t f = qname.find(':');
	    if (f == std::string::npos)
		return std::string("");
	    return qname.substr(0, f);
	}
    public:
	SWSAXparser () {  }
	virtual ~SWSAXparser () {  }
	virtual void parse(const char* file, SWSAXhandler* handler) = 0;
	virtual void parse(std::string::iterator start, std::string::iterator finish, SWSAXhandler* handler) = 0;
	void test (std::string testStr = "<root xmlns=\"http://ns.example/\"><el attr=\"value\"/>text</root>") {
	    SAXserializer handler(std::cout);
	    parse(testStr.begin(), testStr.end(), &handler);
	}
	static SWSAXparser* makeSAXparser();
#define NEEDDEF_makeSAXparser 1
    };

}

