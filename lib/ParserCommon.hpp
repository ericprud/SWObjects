/* ParserCommon.hpp - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.hpp,v 1.4 2008-11-04 15:11:52 eric Exp $
 */

#ifndef PARSER_COMMON_HH
# define PARSER_COMMON_HH

#include "SWObjects.hpp"
#include "utf8.h"

void stop(size_t line);

namespace w3c_sw {

/* Exactly emulate Bison c++ template's location structure for minimum impedance
 * mismatch between them.  It's hard to use the bison one 'cause each parser
 * generates its own. */
struct ParserLocation {
    std::string *filename;
    size_t line;
    size_t column;
    ParserLocation (std::string *filename, size_t line, size_t column) : filename(filename), line(line-1), column(column-1) {  }
};

struct ParserException : public StringException {
    ParserLocation begin, end;
    ParserException (ParserLocation begin, ParserLocation end, std::string str) : StringException(str), begin(begin), end(end) {  }
};

/* Base class for all parsers. */
class ParserDriver {
protected:
    std::string		baseURI;
    NamespaceMap*	namespaces;
    bool		freeNamespaces;
    TTerm::String2BNode	bnodeMap;
    
    ParserDriver ()
	: baseURI(""), namespaces(new NamespaceMap()), 
	  freeNamespaces(true) {  }

    ParserDriver (std::string baseURI)
	: baseURI(baseURI), namespaces(new NamespaceMap()), 
	  freeNamespaces(true) {  }

    virtual ~ParserDriver () {
	if (freeNamespaces)
	    delete namespaces;
    }

public:

    std::string getBase () const { return baseURI; }
    void setBase (std::string b) { baseURI = b; }

    void clear () {
	namespaces->clear();
	bnodeMap.clear();
	setBase("");
    }

    void clear (std::string baseURI) {
	namespaces->clear();
	bnodeMap.clear();
	setBase(baseURI);
    }


    void setNamespaceMap (NamespaceMap* newMap, bool pFreeNamespaces = false) {
	if (freeNamespaces)
	    delete namespaces;
	namespaces = newMap;
	freeNamespaces = pFreeNamespaces;
    }
};

class YaccDriver : public ParserDriver {

protected:
    AtomFactory * const atomFactory;
    bool		ignorePrefixFlag;

public:
    /// construct a new parser driver context
    YaccDriver(AtomFactory* atomFactory);
    YaccDriver(std::string baseURI, AtomFactory* atomFactory);
    virtual ~YaccDriver () {  }

    /// enable debug output in the flex scanner
    bool trace_scanning;

    /// enable debug output in the bison parser
    bool trace_parsing;

    /// stream name (file or input stream) used for error messages.
    std::string streamname;

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    void error(const class location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

    /** Need a pointer to the current lexer instance, used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    //class MyScanner* lexer;

    void clearPrefixes () { namespaces->clear(); }
    void addPrefix (std::string prefix, const URI* namespaceURI) { namespaces->set(prefix, namespaceURI); }
    void ignorePrefix (bool ignore) { ignorePrefixFlag = ignore; }
    bool ignorePrefix () { return ignorePrefixFlag; }


    const URI* getNamespace (std::string prefix, bool returnNull = false) { // @@@ is anyone served by an exception here?
	return namespaces->get(prefix, returnNull);
    }


    /* AtomFactory relay. */
    const Variable* getVariable (std::string name) { return atomFactory->getVariable(name); }
    const URI* getURI (std::string name) { return atomFactory->getURI(name); }
    const URI* getAbsoluteURI(std::string name);
    const BNode* createBNode () { return atomFactory->createBNode(); }
    const BNode* getBNode (std::string name) { return atomFactory->getBNode(name, &bnodeMap); }
    const RDFLiteral* getRDFLiteral (std::string p_String, const URI* p_URI, const LANGTAG* p_LANGTAG) {
	return atomFactory->getRDFLiteral(p_String, p_URI, p_LANGTAG);
    }

    const IntegerRDFLiteral* getNumericRDFLiteral (std::string p_String, int p_value) { return atomFactory->getNumericRDFLiteral(p_String, p_value, TTerm::URI_xsd_integer); }
    const DecimalRDFLiteral* getNumericRDFLiteral (std::string p_String, float p_value) { return atomFactory->getNumericRDFLiteral(p_String, p_value, TTerm::URI_xsd_decimal); }
    const DoubleRDFLiteral* getNumericRDFLiteral (std::string p_String, double p_value) { return atomFactory->getNumericRDFLiteral(p_String, p_value, TTerm::URI_xsd_double); }

    const BooleanRDFLiteral* getBooleanRDFLiteral (std::string p_String, bool p_value) { return atomFactory->getBooleanRDFLiteral(p_String, p_value); }

    static unsigned short _h2n (char c) {
	return
	    c<='9'?c-'0':
	    c<='F'?c-'A'+10:
	    c<='f'?c-'a'+10:
	    throw;
    }
    template<typename LOC>
    static void unescape (char* yytext, size_t len, std::string* space, LOC& yylloc) {
	for (size_t i = 0; i < len; i++) {
	    if (yytext[i] == '\\') {
		switch (yytext[++i]) {
		case 't': (*space) += '\t'; break;
		case 'n': (*space) += '\n'; break;
		case 'r': (*space) += '\r'; break;
		case 'b': (*space) += '\b'; break;
		case 'f': (*space) += '\f'; break;
		case '"': (*space) += '\"'; break;
		case '\'': (*space) += '\''; break;
		case '\\': (*space) += '\\'; break;
		case 'u':
		    if (i < len-4) {
			wchar_t w[2] = {
			    _h2n(yytext[i+1])<<12 | _h2n(yytext[i+2])<<8 |
			    _h2n(yytext[i+3])<<04 | _h2n(yytext[i+4]),
			    0};
			utf8::utf32to8(w, w+1, back_inserter(*space));
			i += 4;
			break;
		    } else
			throw(new std::exception());
		case 'U':
		    if (i < len-8) {
			wchar_t w[2] = {
			    _h2n(yytext[i+1])<<28 | _h2n(yytext[i+2])<<24|
			    _h2n(yytext[i+3])<<20 | _h2n(yytext[i+4])<<16 |
			    _h2n(yytext[i+5])<<12 | _h2n(yytext[i+6])<<8 |
			    _h2n(yytext[i+7])<<04 | _h2n(yytext[i+8]),
			    0};
			utf8::utf32to8(w, w+1, back_inserter(*space));
			i += 8;
			break;
		    } else
			throw(new std::exception());
		default: throw(new std::exception());
		}
	    } else {
		if ((yytext[i] == '\r' && (i == len -1 || yytext[i+1] != '\n'))
		    || yytext[i] == '\n') {
		    yylloc->end.lines(1);
		}
		(*space) += yytext[i];
	    }
	}
    }
};

class YaccDataDriver : public YaccDriver {
protected:
    BasicGraphPattern* curBGP;
    YaccDataDriver (AtomFactory* atomFactory) : YaccDriver(atomFactory) {  }
    YaccDataDriver (std::string baseURI, AtomFactory* atomFactory) : YaccDriver (baseURI, atomFactory) {  }

public:
    void setGraph (BasicGraphPattern* bgp) { curBGP = bgp; }
};

    class ParserFilter : public Filter {
    public:
	ParserFilter () : Filter(NULL) {  }
	void setOp (const TableOperation* newOp) { m_TableOperation = newOp; }
	void copyExpressionsTo (OptionalGraphPattern* target) {
	    for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
		 it != m_Expressions.end(); ++it)
		target->addExpression(*it);
	    m_Expressions.clear();
	}
    };

} //namespace w3c_sw

#endif /* ! defined PARSER_COMMON_HH */

