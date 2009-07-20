/* ParserCommon.hpp - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.hpp,v 1.4 2008-11-04 15:11:52 eric Exp $
 */

#ifndef PARSER_COMMON_HH
# define PARSER_COMMON_HH

#include "SWObjects.hpp"

void stop(size_t line);

namespace w3c_sw {

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


class Driver
{
    /// type of the namespace storage
    typedef std::map<std::string, const URI*> namespacemap_type;
protected:
    POSFactory * const posFactory;
    namespacemap_type	namespaces;
    const URI*		base;
    bool		ignorePrefixFlag;
    POS::String2BNode	nodeMap;

public:
    /// construct a new parser driver context
    Driver(POSFactory* posFactory);
    Driver(std::string baseURI, POSFactory* posFactory);
    virtual ~Driver () {  }

    void clear () {
	namespaces.clear();
	nodeMap.clear();
	base = NULL;
    }

    void clear (std::string baseURI) {
	namespaces.clear();
	nodeMap.clear();
	base = getURI(baseURI);
    }

    /// enable debug output in the flex scanner
    bool trace_scanning;

    /// enable debug output in the bison parser
    bool trace_parsing;

    /// stream name (file or input stream) used for error messages.
    std::string streamname;

    /** Invoke the scanner and parser for a stream.
     * @param in	input stream
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    virtual bool parse_stream(std::istream& in,
			      const std::string& sname = "stream input") = 0;

    /** Invoke the scanner and parser on an input string.
     * @param input	input string
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_string(const std::string& input,
		      const std::string& sname = "string stream");

    /** Invoke the scanner and parser on a file. Use parse_stream with a
     * std::ifstream if detection of file reading errors is required.
     * @param filename	input file name
     * @return		true if successfully parsed
     */
    bool parse_file(const std::string& filename);

    // To demonstrate pure handling of parse errors, instead of
    // simply dumping them on the standard error output, we will pass
    // them to the driver using the following two member functions.

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    void error(const class location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

    /** Need a pointer to the current lexer instance, used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    //class MyScanner* lexer;

    const URI* getBase () const { return base; }
    void setBase (const URI* b) { /* base is centrally managed -- don't delete */ base = b; }
    void addPrefix (std::string prefix, const URI* namespaceURI) { namespaces[prefix] = namespaceURI; }
    void ignorePrefix (bool ignore) { ignorePrefixFlag = ignore; }
    bool ignorePrefix () { return ignorePrefixFlag; }


    const URI* getNamespace (std::string prefix, bool returnNull = false) { // @@@ is anyone served by an exception here?
	namespacemap_type::const_iterator vi = namespaces.find(prefix);
	if (vi == namespaces.end()) {
	    if (returnNull)
		return NULL;
	    UnknownPrefixException e(prefix);
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

} //namespace w3c_sw

#endif /* ! defined PARSER_COMMON_HH */

