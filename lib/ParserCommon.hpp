/* ParserCommon.hpp - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.hpp,v 1.4 2008-11-04 15:11:52 eric Exp $
 */

#ifndef PARSER_COMMON_HH
# define PARSER_COMMON_HH

#include "SWObjects.hpp"

void stop(size_t line);

namespace w3c_sw {

class ParserDriver {
protected:
    std::string		baseURI;
    
    ParserDriver();
    ParserDriver(std::string baseURI);

public:
    std::string getBase () const { return baseURI; }
    void setBase (std::string b) { baseURI = b; }
};

class YaccDriver : public ParserDriver {

    class NamespaceMap {
    protected:
	std::map<std::string, const URI*> ns;
    public:
	void clear () { ns.clear(); }
	const URI*& operator[] (std::string prefix) { return ns[prefix]; }

	typedef std::map<std::string, const URI*>::iterator iterator;
	typedef std::map<std::string, const URI*>::const_iterator const_iterator;

	iterator begin () { return ns.begin(); }
	const_iterator begin () const { return ns.begin(); }
	iterator end () { return ns.end(); }
	const_iterator end () const { return ns.end(); }
	iterator find (std::string prefix) { return ns.find(prefix); }

	struct UnknownPrefixException : StringException {
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

    };

protected:
    POSFactory * const posFactory;
    NamespaceMap	namespaces;
    bool		ignorePrefixFlag;
    POS::String2BNode	nodeMap;

public:
    /// construct a new parser driver context
    YaccDriver(POSFactory* posFactory);
    YaccDriver(std::string baseURI, POSFactory* posFactory);
    virtual ~YaccDriver () {  }

    void clear () {
	namespaces.clear();
	nodeMap.clear();
	setBase("");
    }

    void clear (std::string baseURI) {
	namespaces.clear();
	nodeMap.clear();
	setBase(baseURI);
    }

    /// enable debug output in the flex scanner
    bool trace_scanning;

    /// enable debug output in the bison parser
    bool trace_parsing;

    /// stream name (file or input stream) used for error messages.
    std::string streamname;

    /** Invoke the scanner and parser for a stream.
     * @param in	IStreamPtr with input stream and name
     */
    virtual bool parse(IStreamPtr& in) = 0;

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    void error(const class location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

    /** Need a pointer to the current lexer instance, used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    //class MyScanner* lexer;

    void addPrefix (std::string prefix, const URI* namespaceURI) { namespaces[prefix] = namespaceURI; }
    void ignorePrefix (bool ignore) { ignorePrefixFlag = ignore; }
    bool ignorePrefix () { return ignorePrefixFlag; }


    const URI* getNamespace (std::string prefix, bool returnNull = false) { // @@@ is anyone served by an exception here?
	NamespaceMap::const_iterator vi = namespaces.find(prefix);
	if (vi == namespaces.end()) {
	    if (returnNull)
		return NULL;
	    NamespaceMap::UnknownPrefixException e(prefix);
	    throw(e);
	} else
	    return vi->second;
    }


    /* POSFactory relay. */
    const Variable* getVariable (std::string name) { return posFactory->getVariable(name); }
    const URI* getURI (std::string name) { return posFactory->getURI(name); }
    const URI* getAbsoluteURI(std::string name);
    const BNode* createBNode () { return posFactory->createBNode(); }
    const BNode* getBNode (std::string name) { return posFactory->getBNode(name, nodeMap); }
    const RDFLiteral* getRDFLiteral (std::string p_String, const URI* p_URI, LANGTAG* p_LANGTAG) {
	return posFactory->getRDFLiteral(p_String, p_URI, p_LANGTAG);
    }

    const IntegerRDFLiteral* getNumericRDFLiteral (std::string p_String, int p_value) { return posFactory->getNumericRDFLiteral(p_String, p_value); }
    const DecimalRDFLiteral* getNumericRDFLiteral (std::string p_String, float p_value) { return posFactory->getNumericRDFLiteral(p_String, p_value); }
    const DoubleRDFLiteral* getNumericRDFLiteral (std::string p_String, double p_value) { return posFactory->getNumericRDFLiteral(p_String, p_value); }

    const BooleanRDFLiteral* getBooleanRDFLiteral (std::string p_String, bool p_value) { return posFactory->getBooleanRDFLiteral(p_String, p_value); }
    const NULLpos* getNULL  () { return posFactory->getNULL(); }

};

class YaccDataDriver : public YaccDriver {
protected:
    BasicGraphPattern* curBGP;
    YaccDataDriver (POSFactory* posFactory) : YaccDriver(posFactory) {  }
    YaccDataDriver (std::string baseURI, POSFactory* posFactory) : YaccDriver (baseURI, posFactory) {  }

public:
    void setGraph (BasicGraphPattern* bgp) { curBGP = bgp; }
};

} //namespace w3c_sw

#endif /* ! defined PARSER_COMMON_HH */

