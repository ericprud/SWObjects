%module SWObjects
%{
#if defined(SWIGJAVA) || defined(SWIGPERL) || defined(SWIGLUA) || defined(SWIGPHP)
    struct pointer_category { };
    namespace swig {
	template <class Type> struct traits { };
    }
#endif /* defined(SWIGJAVA) || defined(SWIGPERL) || defined(SWIGLUA) || defined(SWIGPHP) */
%}
%include <std_string.i>
%include <std_map.i>
%include <std_vector.i>
%include <exception.i>
%include <typemaps.i>

#if defined(SWIGJAVA)
    %rename(equals)		     *::operator==;
#endif /* defined(SWIGJAVA) */

%exception {
    try {
	$action
    } catch(std::string e) {
	SWIG_exception(SWIG_ValueError, e.c_str());
    } catch(const char* e) {
	SWIG_exception(SWIG_ValueError, e);
    } catch(std::exception& e) {
	SWIG_exception(SWIG_ValueError, e.what());
    } catch(...) {
	SWIG_exception(SWIG_RuntimeError, "runtime error");
    }
}

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
	class TTerm;
	class BNode;
	class BasicGraphPattern;
	class Binding;
	class TableOperation;
    }
%}

namespace std {
    %template(mapBNodestarstring) map<const w3c_sw::BNode*, std::string>;
    %template(mapstringBNodestar) map<std::string, const w3c_sw::BNode*>;
    %template(mapstrcharstar) map<const std::string, const char*>;
};

%{
namespace swig {
    template <>  struct traits<w3c_sw::TTerm> {
	typedef pointer_category category;
	static const char* type_name() { return"w3c_sw::TTerm *"; }
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
%nestedworkaround w3c_sw::TTerm::BNode2string;
%nestedworkaround w3c_sw::TTerm::String2BNode;

    struct UnknownPrefixException : w3c_sw::StringException {
	std::string prefix;
	UnknownPrefixException (std::string prefix) : 
	    StringException(make(prefix)), prefix(prefix) {  }
	virtual ~UnknownPrefixException () throw() {  }
    protected:
	std::string make (std::string prefix) {
	    std::stringstream s;
	    s << "unknown prefix \"" << prefix << "\"";
	    return s.str();
	}
    };
%nestedworkaround w3c_sw::NamespaceMap::UnknownPrefixException;

	class NSmap {
	public:
	    virtual ~NSmap () {  }
	    virtual std::string operator[](std::string prefix) = 0;
	};
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
%nestedworkaround w3c_sw::SWSAXhandler::NSmap;
%nestedworkaround w3c_sw::SWSAXhandler::Attributes;

	struct HandlerSet {
	    virtual ~HandlerSet () {  }
	    virtual bool parse (std::string mediaType, std::vector<std::string> args,
				w3c_sw::BasicGraphPattern* /* target */, w3c_sw::IStreamContext& /* istr */,
				std::string /* nameStr */, std::string /* baseURI */,
				w3c_sw::AtomFactory* /* atomFactory */, w3c_sw::NamespaceMap* /* nsMap */) {
		throw std::string("no handler for ") + mediaType + "(" + args[0] + ")";
	    }
	};
%nestedworkaround w3c_sw::RdfDB::HandlerSet;


 	struct NonConjunctionState {
	    bool inConj;
	    w3c_sw::TableConjunction* nestingConj;
	    NonConjunctionState (bool inConj, w3c_sw::TableConjunction* nestingConj)
		: inConj(inConj), nestingConj(nestingConj) {  }
	};

%nestedworkaround w3c_sw::BGPSimplifier::NonConjunctionState;

struct ConnectSet : std::set<RuleTerm> {
	};

%nestedworkaround w3c_sw::NodeShare::ConnectSet;

/* %typemap(varin) const char * { */
/*     SWIG_Error(SWIG_AttributeError,"Variable $symname is read-only."); */
/*     SWIG_fail; */
/* } */

%{
#include "SWObjects.cpp"
#include "SWObjectDuplicator.hpp"
#include "ResultSet.cpp"
#include "ParserCommon.hpp"
#include "SAXparser.hpp"
#include "XMLSerializer.hpp"
#include "RdfDB.cpp"
#include "SPARQLSerializer.hpp"
#include "RuleInverter.hpp"
#include "QueryMapper.hpp"
#include "ChainingMapper.hpp"
#include "MapSetParser/MapSetParser.hpp"
#include "interface/WEBagent_boostASIO.hpp"
#include "interface/SAXparser_expat.hpp"
  //#include "ServiceOptimizer.hpp"
    typedef w3c_sw::TTerm::BNode2string BNode2string;
    typedef w3c_sw::TTerm::String2BNode String2BNode;

    typedef w3c_sw::NamespaceMap::UnknownPrefixException UnknownPrefixException;

    typedef w3c_sw::SWSAXhandler::NSmap NSmap;
    typedef w3c_sw::SWSAXhandler::Attributes Attributes;

    typedef w3c_sw::RdfDB::HandlerSet HandlerSet;
    typedef w3c_sw::BGPSimplifier::NonConjunctionState NonConjunctionState;
    typedef w3c_sw::NodeShare::ConnectSet ConnectSet;
%}
%include "config.h"
%include "SWObjects.hpp"
%include "SWObjectDuplicator.hpp"
%include "ParserCommon.hpp"
%include "SAXparser.hpp"
%include "XMLSerializer.hpp"
%include "ResultSet.hpp"
%include "ResultSet.cpp"
%include "RdfDB.hpp"
%include "SWObjects.cpp"
%include "SPARQLSerializer.hpp"
%include "RuleInverter.hpp"
%include "QueryMapper.hpp"
%include "ChainingMapper.hpp"
 //%include "ServiceOptimizer.hpp"
namespace w3c_sw {
    class SPARQLfedScanner;
    class MapSetScanner;
    class TurtleSScanner;
    class TrigSScanner;
}
%include "SPARQLfedParser/SPARQLfedParser.hpp"
%include "MapSetParser/MapSetParser.hpp"
%include "TurtleSParser/TurtleSParser.hpp"
%include "TrigSParser/TrigSParser.hpp"
%include "interface/WEBagent.hpp"
%include "interface/WEBagent_boostASIO.hpp"
%include "interface/SAXparser.hpp"
%include "interface/SAXparser_expat.hpp"


namespace w3c_sw {
    %template(StreamContextIstream) StreamContext<std::istream>;
    %template(StreamContextOstream) StreamContext<std::ostream>;
};

%{
w3c_sw::SWSAXparser* w3c_sw::SWSAXparser::makeSAXparser () { return NULL; }
typedef w3c_sw::location location; // I don't know why _wrap_YaccDriver_error__SWIG_0 references ::location.
%}

//vector iterator stuff

%inline %{
//! Thin wrapper for ONLY the increment operator
//void _ConstructList_incr( std::vector<LabeledConstruct>::const_iterator* iter )
  void _ConstructList_incr( w3c_sw::MapSet::ConstructList::const_iterator* iter )
{
    // increment the iterator
    ++(*iter);
}
%}

%extend w3c_sw::MapSet {
#if defined(SWIGPYTHON)
%insert("python") %{
    def left_maps(self):
      constructlist = self.maps
      print "constructlist: ", constructlist
    #"A generator to iterate through maps." 
      ConstructListIter = self._begin(constructlist)
      keepLooping = True
      while keepLooping == True:
          element = self._ConstructList_dereference_Left(constructlist, ConstructListIter)
          if element:
             _ConstructList_incr( ConstructListIter )
             yield element
          else:
             keepLooping = False
%} //end insert
#endif /* defined(SWIGPYTHON) */

w3c_sw::MapSet::ConstructList::const_iterator* _begin(w3c_sw::MapSet::ConstructList* maps)
{
  return new w3c_sw::MapSet::ConstructList::const_iterator((maps->begin()));
}

//! dereference the iterator; return NULL if at the end
const w3c_sw::LabeledConstruct* _ConstructList_dereference_Left(w3c_sw::MapSet::ConstructList* maps, w3c_sw::MapSet::ConstructList::const_iterator* iter)
{
    // if at the end, return NULL
  if (*iter == (maps->end()) ) {
        return NULL;
    }
    // otherwise, return the map to which this iterator points
  return &**iter;
}
}
//end vector iterator stuff
