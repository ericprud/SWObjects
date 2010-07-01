%module SWObjects
%include "std_map.i"
%include <std/std_string.i>

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

namespace std {
    %template(mapstrcharstar) map<const std::string, const char*>;
};

%{
namespace swig {
    template <>  struct traits<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > {
	typedef pointer_category category;
	static const char* type_name() { return"std::basic_string<char, std::char_traits<char>, std::allocator<char> > *"; }
    };
}
%}

class BNode2string {
  public:
    std::string getString(const w3c_sw::BNode* bnode);
};

%nestedworkaround POS::BNode2string;

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
class BNode;
%}

%{
#include "SWObjects.cpp"
#include "ResultSet.cpp"
#include "SAXparser.hpp"
#include "RdfDB.cpp"
#include "TurtleSScanner.cpp"
#include "TurtleSParser/TurtleSParser.cpp"
%}
%include "SWObjects.hpp"
%include "SAXparser.hpp"
%include "RdfDB.hpp"
%include "SWObjects.cpp"
%include "TurtleSParser/TurtleSParser.hpp"
%include "TurtleSParser/TurtleSParser.cpp"

namespace w3c_sw {
    %template(StreamContextIstream) StreamContext<std::istream>;
    %template(StreamContextOstream) StreamContext<std::ostream>;
};

%{
typedef w3c_sw::POS::BNode2string BNode2string;
// typedef w3c_sw::StreamContext<std::istream>::e_opts StreamContextOpts;
// typedef w3c_sw::StreamContext<std::ostream>::e_opts StreamContextOpts;
w3c_sw::SWSAXparser* w3c_sw::SWSAXparser::makeSAXparser () { return NULL; }
typedef w3c_sw::TurtleSScanner TurtleSScanner;
%}

