/* SAXparser.hpp: SAXparser interface object for SWObjects.
 * I needed to abstract the different parsers, so why not use a popular
 * interface?

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $

 * SWSAXparser and SWSAXhandler are prefixed with SW to avoid collisions with
 * implementation names.
 */

#ifndef INCLUDED_interface_SAXparser_hpp
 #define INCLUDED_interface_SAXparser_hpp

#include <stack>
#include "SWObjects.hpp"

namespace w3c_sw {

    class SWSAXhandler {
    public:
	class NSmap {
	public:
	    virtual ~NSmap () {  }
	    virtual std::string operator[](std::string prefix) = 0;
	    virtual std::set<std::string> keys () = 0;
	};

	struct QName {
	    std::string ns;
	    std::string local;
	    bool _initialized;
	    QName ()
		: ns("UNINTIALIZED"), local("UNINTIALIZED"), _initialized(false)
	    {  }
	    QName (std::string ns, std::string local)
		: ns(ns), local(local), _initialized(true)
	    {  }
	    QName (const QName& ref)
		: ns(ref.ns), local(ref.local), _initialized(ref._initialized)
	    {  }
	    QName (std::string qname, NSmap& map)
		: ns("UNINTIALIZED"), local("UNINTIALIZED"), _initialized(false)
	    {
		size_t f = qname.find_first_of(":");
		if (f == std::string::npos)
		    throw std::string("':' expected in QName \"") + qname + "\""; // be conservative and throw 'till we have use cases which motivate the flexibility below.
		std::string prefix = f == std::string::npos ? "" : qname.substr(0, f);
		local = f == std::string::npos ? qname : qname.substr(f + 1);
		ns = map[prefix];
		_initialized = true;
	    }
	    void reset () {
		ns = "UNINTIALIZED";
		local = "UNINTIALIZED";
		_initialized = false;
	    }
	    void _test () const {
		if (!_initialized)
		    throw std::string("unintialized QName");
	    }
	    bool operator== (const QName& ref) const {
		_test();
		return ns == ref.ns && local == ref.local;
	    }
	    bool operator< (const QName& ref) const {
		_test();
		return ns < ref.ns || local < ref.local;
	    }
	    std::string asURI (std::string separator = "") {
		_test();
		return ns + separator + local;
	    }
	};

	/** qName: get some preverse serialization of a QName.
	 * used only for debugging?
	 */
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
	    // throw("program flow exception");
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

    inline std::ostream& operator<< (std::ostream& os, const SWSAXhandler::QName& ref) {
	os << '{' + ref.ns +'}' + ref.local;
	return os;
    }

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
	virtual bool parse(IStreamContext& istr, SWSAXhandler* handler) = 0;
	void test (std::string testStr = "<root xmlns=\"http://ns.example/\"><el attr=\"value\"/>text</root>") {
	    SAXserializer handler(std::cout);
	    IStreamContext istr(testStr, IStreamContext::STRING);
	    parse(istr, &handler);
	}
	static SWSAXparser* makeSAXparser();
    };


    struct ChangeMediaTypeException : public std::exception {
	std::string mediaType;
	std::vector<std::string> args;
	ChangeMediaTypeException (std::string mediaType, std::vector<std::string> args)
	    : mediaType(mediaType), args(args) {  }
	~ChangeMediaTypeException() throw () {  }
    };

	struct Entry {
	    std::string transform;
	    std::string mediaType;
	    Entry (std::string transform, std::string mediaType)
		: transform(transform), mediaType(mediaType)
	    {  }
	};

    struct GRDDLmap {
	std::map<std::string, Entry> map;

	void insert (std::string uri, std::string localName,
		     std::string transform, std::string mediaType) {
	    map.insert(std::pair<std::string, Entry>(makeKey(uri, localName), Entry(transform, mediaType)));
	}

	void maybeChangeMediaType(std::string uri, std::string localName) {
	    std::map<std::string, Entry>::const_iterator it = map.find(makeKey(uri, localName));
	    if (it != map.end()) {
		std::vector<std::string> args;
		args.push_back(it->second.transform);
		BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
		    << "GRDDL link header rel=\"transformation\" encountered -- \""
		    << it->second.transform << "\" transforms to \"" << it->second.mediaType << "\".";
		throw ChangeMediaTypeException(it->second.mediaType, args);
	    }
	}
	std::string makeKey (std::string uri, std::string localName) {
	    return std::string("{") + uri + std::string("}") + localName;
	}
    };

    class SAXhandlerInsulator;
    class InsulatedSAXparser : public SWSAXparser {
	friend class SAXhandlerInsulator;
    protected:
	// hack until i work out how to call analog of ::xmlStopParser in all parsers
	enum {ERROR_none, ERROR_string, ERROR_changeHandler} errorMode;
	ChangeMediaTypeException exceptionChangeMediaType;
	std::string exceptionString;
	SAXhandlerInsulator* insulator;

	/* SAXhandlerInsulator reports errors here.
	 * feel free to overload with e.g. xmlStopParser.
	 */

	/* For derivatives of InsulatedSAXparser where we don't
	 *  know how to stop the parser, we may recieve
	 *  e.g. encoding errors after the first error. We record
	 *  only the first one.
	 */
	virtual void exception_std_string (std::string& e) {
	    if (errorMode == ERROR_none) { errorMode = ERROR_string; exceptionString = e; }
	}
	virtual void exception_ChangeMediaType (ChangeMediaTypeException& e) {
	    if (errorMode == ERROR_none) { errorMode = ERROR_changeHandler; exceptionChangeMediaType = e; }
	}
	void testAbort(std::string locationStr) {
	    switch (errorMode) {
	    case ERROR_string:
		errorMode = ERROR_none;
		throw locationStr + ": " + exceptionString;
	    case ERROR_changeHandler:
		errorMode = ERROR_none;
		throw exceptionChangeMediaType;
	    case ERROR_none:
		break;
	    }
	}

    public:
	InsulatedSAXparser ()
	    : errorMode(ERROR_none), exceptionChangeMediaType("no media type", std::vector<std::string>())
	{  }
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
	    if (parser->errorMode != InsulatedSAXparser::ERROR_none) return;
	    try {
		handler->startElement(uri, localName, qName, attrs, nsz);
	    }
	    catch (std::string& e) { parser->exception_std_string(e); }
	    catch (ChangeMediaTypeException& e) { parser->exception_ChangeMediaType(e); }
	}
	virtual void endElement (std::string uri,
				 std::string localName,
				 std::string qName, 
				 NSmap& nsz) {
	    if (parser->errorMode != InsulatedSAXparser::ERROR_none) return;
	    try {
		handler->endElement(uri, localName, qName, nsz);
	    }
	    catch (std::string& e) { parser->exception_std_string(e); }
	    catch (ChangeMediaTypeException& e) { parser->exception_ChangeMediaType(e); }
	}
	virtual void characters (const char ch[],
				 int start,
				 int length, 
				 NSmap& nsz) {
	    if (parser->errorMode != InsulatedSAXparser::ERROR_none) return;
	    try {
		handler->characters(ch, start, length, nsz);
	    }
	    catch (std::string& e) { parser->exception_std_string(e); }
	    catch (ChangeMediaTypeException& e) { parser->exception_ChangeMediaType(e); }
	}
	virtual void error(const char* msg, va_list args) {
	    try {
		handler->error(msg, args);
	    }
	    catch (std::string& e) { parser->exception_std_string(e); }
	    catch (ChangeMediaTypeException& e) { parser->exception_ChangeMediaType(e); }
	}
	virtual void warning(const char* msg, va_list args) {
	    try {
		handler->warning(msg, args);
	    }
	    catch (std::string& e) { parser->exception_std_string(e); }
	    catch (ChangeMediaTypeException& e) { parser->exception_ChangeMediaType(e); }
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
	    virtual std::set<std::string> keys () {
		std::set<std::string> ret;
		for (NSmapImpl::const_iterator it = map.begin();
		     it != map.end(); ++it)
		    ret.insert(it->first);
		return ret;
	    }
	};

	std::stack< NSmapImpl > nsz;

	NSdInsulatedSAXparser () {
	    NSmapImpl aboveRoot;
	    aboveRoot["xml"] = NS_xml;
	    nsz.push(aboveRoot);
	};
    };

}

#if XML_PARSER == SWOb_LIBXML2
  #include "../interface/SAXparser_libxml.hpp"
#elif XML_PARSER == SWOb_EXPAT1
  #include "../interface/SAXparser_expat.hpp"
#elif XML_PARSER == SWOb_MSXML3
  #include "../interface/SAXparser_msxml3.hpp"
#else
  #warning No XML parser to include
#endif

#endif /* INCLUDED_interface_SAXparser_hpp */
