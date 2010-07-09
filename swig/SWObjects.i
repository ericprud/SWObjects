%module SWObjects
%{
#if defined(SWIGJAVA) || defined(SWIGPERL)
    struct pointer_category { };
    namespace swig {
	template <class Type> struct traits { };
    }
#endif /* defined(SWIGJAVA) || defined(SWIGPERL) */
%}
%include <std_map.i>
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
#include "SWObjects.cpp"
#include "ResultSet.cpp"
#include "ParserCommon.hpp"
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
%include "ParserCommon.hpp"
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
typedef w3c_sw::location location; // I don't know why _wrap_YaccDriver_error__SWIG_0 references ::location.
%}

namespace w3c_sw {
    class SPARQLfedDriver : public YaccDriver {
    public:
	SPARQLfedDriver(std::string baseURI, POSFactory* posFactory) {  }
	virtual bool parse(IStreamContext& in) { return false; }
	Operation* root;
    };
}

