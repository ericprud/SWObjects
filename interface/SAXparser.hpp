/* SAXparser.hpp: SAXparser interface object for SWObjects.
 * I needed to abstract the different parsers, so why not use a popular
 * interface?

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $

 * SWSAXparser and SWSAXhandler are prefixed with SW to avoid collisions with
 * implementation names.
 */

#pragma once
#include "SWObjects.hpp"

namespace w3c_sw {

    class SWSAXhandler {
    public:
	class NSmap {
	public:
	    virtual ~NSmap () {  }
	    virtual std::string operator[](std::string prefix) = 0;
	};

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
				   Attributes* attrs, 
				   NSmap& /* nsz */) {
	    std::cout << "<" << qName << " _:ns=\"" << uri << "|" << localName << "\"";
	    size_t attrCount = attrs->getLength();
	    for (size_t i = 0; i < attrCount; ++i) {
		std::cout << std::endl << "    " << attrs->getQName(i) << "=\"" << attrs->getValue(attrs->getURI(i), attrs->getLocalName(i)) << "\"";
	    }
	    std::cout << ">" << std::endl;
	}
	virtual void endElement (std::string uri,
				 std::string localName,
				 std::string qName, 
				 NSmap& /* nsz */) {
	    std::cout << "</" << qName << " _:ns=\"" << uri << "|" << localName << "\">" << std::endl;;
	}
	virtual void characters (const char ch[],
				 int start,
				 int length, 
				 NSmap& /* nsz */) {
	    std::cout << std::string(ch, start, length);
	}

	void varError(const char * msg, ...) {
	    va_list args;
	    va_start(args, msg);
	    error( msg, args );
	    va_end(args);
	    throw("program flow exception");
	}

	virtual void error(const char* msg, va_list args) {
	    char space[8192];
	    vsnprintf(space, sizeof(space), msg, args);
	    throw std::string("SWSAX exception: ") + space;
	}

	void warning(const char * msg, ...) {
	    va_list args;
	    va_start(args, msg);
	    warning( msg, args );
	    va_end(args);
	}

	virtual void warning(const char* msg, va_list args) {
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
				   Attributes* attrs, 
				   NSmap& /* nsz */) {
	    out << "SM<" << qName << " _:ns=\"" << uri << "|" << localName << "\"";
	    size_t attrCount = attrs->getLength();
	    for (size_t i = 0; i < attrCount; ++i) {
		out << std::endl << "    " << attrs->getQName(i) << "=\"" << attrs->getValue(attrs->getURI(i), attrs->getLocalName(i)) << "\"";
	    }
	    out << ">" << std::endl;
	}
	virtual void endElement (std::string uri,
				 std::string localName,
				 std::string qName, 
				 NSmap& /* nsz */) {
	    out << "SM</" << qName << " _:ns=\"" << uri << "|" << localName << "\">" << std::endl;;
	}
	virtual void characters (const char ch[],
				 int start,
				 int length, 
				 NSmap& /* nsz */) {
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
	virtual void parse(IStreamContext& istr, SWSAXhandler* handler) = 0;
	void test (std::string testStr = "<root xmlns=\"http://ns.example/\"><el attr=\"value\"/>text</root>") {
	    SAXserializer handler(std::cout);
	    IStreamContext istr(testStr, StreamContext::STRING);
	    parse(istr, &handler);
	}
	static SWSAXparser* makeSAXparser();
#define NEEDDEF_SAXPARSER 1
    };


    class SAXhandlerInsulator;
    class InsulatedSAXparser : public SWSAXparser {
	friend class SAXhandlerInsulator;
    protected:
	bool aborted; // hack until i work out how to call analog of ::xmlStopParser in all parsers
	std::string exceptionString;
	SAXhandlerInsulator* insulator;

	/* SAXhandlerInsulator reports errors here.
	 * feel free to overload with e.g. xmlStopParser.
	 */
	virtual void handleError (std::string& e) {
	    /* For derivatives of InsulatedSAXparser where we don't
	     *  know how to stop the parser, we may recieve
	     *  e.g. encoding errors after the first error. We record
	     *  only the first one.
	     */
	    if (!aborted) {
		aborted = true;
		exceptionString = e;
	    }
	}

    public:
	InsulatedSAXparser () : aborted(false) {  }
    };

    class SAXhandlerInsulator : public SWSAXhandler {
    protected:
	InsulatedSAXparser* parser;
	SWSAXhandler* handler;

    public:
	SAXhandlerInsulator (InsulatedSAXparser* parser, SWSAXhandler* handler) : 
	    parser(parser), handler(handler) {
	    parser->insulator = this;
	}
	virtual void startElement (std::string uri,
				   std::string localName,
				   std::string qName,
				   Attributes* attrs, 
				   NSmap& nsz) {
	    if (parser->aborted) return;
	    try {
		handler->startElement(uri, localName, qName, attrs, nsz);
	    }
	    catch (std::string& e) {
		parser->handleError(e);
	    }
	}
	virtual void endElement (std::string uri,
				 std::string localName,
				 std::string qName, 
				 NSmap& nsz) {
	    if (parser->aborted) return;
	    try {
		handler->endElement(uri, localName, qName, nsz);
	    }
	    catch (std::string& e) {
		parser->handleError(e);
	    }
	}
	virtual void characters (const char ch[],
				 int start,
				 int length, 
				 NSmap& nsz) {
	    if (parser->aborted) return;
	    try {
		handler->characters(ch, start, length, nsz);
	    }
	    catch (std::string& e) {
		parser->handleError(e);
	    }
	}
	virtual void error(const char* msg, va_list args) {
	    try {
		handler->error(msg, args);
	    }
	    catch (std::string& e) {
		parser->handleError(e);
	    }
	}
	virtual void warning(const char* msg, va_list args) {
	    try {
		handler->warning(msg, args);
	    }
	    catch (std::string& e) {
		parser->handleError(e);
	    }
	}
    };

    class NSdInsulatedSAXparser : public InsulatedSAXparser {
    protected:
	typedef std::map< std::string, std::string > NSmapImpl;
	class SimpleNsMap : public SWSAXhandler::NSmap {
	    NSmapImpl& map;
	public:
	    SimpleNsMap (NSmapImpl& map) : map(map) {  }
	    virtual std::string operator[] (std::string prefix) { return map[prefix]; }
	};

	std::stack< NSmapImpl > nsz;

	NSdInsulatedSAXparser () {
	    NSmapImpl aboveRoot;
	    aboveRoot["xml"] = NS_xml;
	    nsz.push(aboveRoot);
	};
    };

}

