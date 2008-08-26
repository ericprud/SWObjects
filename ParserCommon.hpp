/* ParserCommon.hpp - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.hpp,v 1.1 2008-08-26 05:30:47 jnorthru Exp $
 */

#ifndef PARSER_COMMON_HH
# define PARSER_COMMON_HH

#include "SWObjects.hpp"

void stop(size_t line);

namespace yacker {

class Driver
{
    /// type of the namespace storage
    typedef std::map<std::string, SPARQLfedNS::URI*> namespacemap_type;
protected:
    SPARQLfedNS::POSFactory * const posFactory;
    namespacemap_type	namespaces;
    SPARQLfedNS::URI*		base;
    bool ignorePrefixFlag;

public:
    /// construct a new parser driver context
    Driver(SPARQLfedNS::POSFactory* posFactory);
    Driver(std::string baseURI, SPARQLfedNS::POSFactory* posFactory);
    virtual ~Driver () {  }

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
    void error(const class SPARQLfedNS::location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

    /** Need a pointer to the current lexer instance, used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    //class MyScanner* lexer;

    void setBase (SPARQLfedNS::URI* b) { /* base is centrally managed -- don't delete */ base = b; }
    void addPrefix (std::string prefix, SPARQLfedNS::URI* namespaceURI) { namespaces[prefix] = namespaceURI; }
    void ignorePrefix (bool ignore) { ignorePrefixFlag = ignore; }
    bool ignorePrefix () { return ignorePrefixFlag; }


    SPARQLfedNS::URI* getNamespace (std::string prefix) {
	namespacemap_type::const_iterator vi = namespaces.find(prefix);
	if (vi == namespaces.end())
	    throw(std::runtime_error("Unknown prefix."));
	else
	    return vi->second;
    }
    SPARQLfedNS::URI* getBase () { return base; }


    /* POSFactory relay. */
    SPARQLfedNS::Variable* getVariable (std::string name) { return posFactory->getVariable(name); }
    SPARQLfedNS::URI* getURI (std::string name) { return posFactory->getURI(name); }
    SPARQLfedNS::URI* getAbsoluteURI(std::string name);
    SPARQLfedNS::BNode* createBNode () { return posFactory->createBNode(); }
    SPARQLfedNS::BNode* getBNode (std::string name) { return posFactory->getBNode(name); }
    SPARQLfedNS::RDFLiteral* getRDFLiteral (std::string p_String, SPARQLfedNS::URI* p_URI, SPARQLfedNS::LANGTAG* p_LANGTAG) { return posFactory->getRDFLiteral(p_String, p_URI, p_LANGTAG); }

    SPARQLfedNS::IntegerRDFLiteral* getNumericRDFLiteral (std::string p_String, int p_value) { return posFactory->getNumericRDFLiteral(p_String, p_value); }
    SPARQLfedNS::DecimalRDFLiteral* getNumericRDFLiteral (std::string p_String, float p_value) { return posFactory->getNumericRDFLiteral(p_String, p_value); }
    SPARQLfedNS::DoubleRDFLiteral* getNumericRDFLiteral (std::string p_String, double p_value) { return posFactory->getNumericRDFLiteral(p_String, p_value); }

    SPARQLfedNS::BooleanRDFLiteral* getBooleanRDFLiteral (std::string p_String, bool p_value) { return posFactory->getBooleanRDFLiteral(p_String, p_value); }
    SPARQLfedNS::NULLpos* getNULL  () { return posFactory->getNULL(); }

};

} //namespace yacker

#endif /* ! defined PARSER_COMMON_HH */

