%module SWObjects
%include <std_map.i>
%include <std_set.i>
%include <std_string.i>

namespace std {
    class exception {
    public:
	exception();
	exception(const exception& rhs);
	virtual ~exception();
	virtual const char *what(void);
    };
}

namespace w3c_sw {
    class OptString {};
}

%{
    namespace w3c_sw {
	class POS;
	class BNode;
    }
%}

namespace std {
    %template(mapBNodestarstring) map<const w3c_sw::BNode*, std::string>;
    %template(mapstringBNodestar) map<std::string, const w3c_sw::BNode*>;
    %template(mapstrcharstar) map<const std::string, const char*>;
    %template(setPOSstar) set<const w3c_sw::POS*>;
};

%{
namespace swig {
    template <>  struct traits<w3c_sw::POS> {
	typedef pointer_category category;
	static const char* type_name() { return"w3c_sw::POS *"; }
    };
    template <>  struct traits<w3c_sw::BNode> {
	typedef pointer_category category;
	static const char* type_name() { return"w3c_sw::BNode *"; }
    };
    template <>  struct traits<char> {
	typedef pointer_category category;
	static const char* type_name() { return"std::basic_string<char> *"; }
    };
}
%}


class BNode2string : public std::map<const w3c_sw::BNode*, std::string> {
public:
    std::string getString(const w3c_sw::BNode* bnode);
};
class String2BNode : public std::map<std::string, const w3c_sw::BNode*> {
public:
    const w3c_sw::BNode* getBNode(std::string str);
};
%nestedworkaround w3c_sw::POS::BNode2string;
%nestedworkaround w3c_sw::POS::String2BNode;

%{
    #define SWIG_INTERFACE
    typedef enum {
	NONE =		0,	/* don't do nuthin */
	STRING =	1,	/* nameStr is the contents */
	STDIO =		2,	/* '-' means stdin */
	STDIN =		2,	/* '-' means stdin */
	STDOUT =	2,	/* '-' also means stdout */
	FILESTREAM =		4,	/* must be a file */
    } e_opts;
%}

%nestedworkaround StreamContext<std::istream>::e_opts;
%nestedworkaround StreamContext<std::ostream>::e_opts;
%rename IStreamContext::FILE FILESTREAM;


%{
//class BNode;
%}

%{
#include "SWObjects.cpp"
#include "ResultSet.cpp"
#include "SAXparser.hpp"
#include "XMLSerializer.hpp"
#include "RdfDB.cpp"
#include "TurtleSScanner.cpp"
#include "TurtleSParser/TurtleSParser.cpp"
#include "SPARQLSerializer.hpp"
    typedef w3c_sw::POS::BNode2string BNode2string;
    typedef w3c_sw::POS::String2BNode String2BNode;
%}
%include "config.h"
%include "SWObjects.hpp"
%include "SAXparser.hpp"
%include "XMLSerializer.hpp"
%include "ResultSet.hpp"
%include "ResultSet.cpp"
%include "RdfDB.hpp"
%include "SWObjects.cpp"
%include "TurtleSParser/TurtleSParser.hpp"
%include "TurtleSParser/TurtleSParser.cpp"
%include "SPARQLSerializer.hpp"

namespace w3c_sw {
    %template(StreamContextIstream) StreamContext<std::istream>;
    %template(StreamContextOstream) StreamContext<std::ostream>;
};

%{
w3c_sw::SWSAXparser* w3c_sw::SWSAXparser::makeSAXparser () { return NULL; }
typedef w3c_sw::TurtleSScanner TurtleSScanner;
%}

namespace w3c_sw {
    class SPARQLfedDriver : public YaccDriver {
    public:
	SPARQLfedDriver(std::string baseURI, POSFactory* posFactory) {  }
	virtual bool parse(IStreamContext& in) { return false; }
	static Operation* parseString (const char* queryString, POSFactory* posFactory) {
	    SPARQLfedDriver d("", posFactory);
	    IStreamContext qstr(queryString, IStreamContext::STRING);
	    return d.parse(qstr) ? NULL : d.root;
	}
    };
}

