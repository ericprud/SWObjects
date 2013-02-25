/* ParserCommon.hpp - commonalities between SPARQL/RDF-related parsers
 * $Id: ParserCommon.hpp,v 1.4 2008-11-04 15:11:52 eric Exp $
 */

#ifndef PARSER_COMMON_HH
# define PARSER_COMMON_HH

#include "SWObjects.hpp"
#include "location.hpp"
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
    ParserLocation (std::string *filename, size_t line, size_t column)
	: filename(filename), line(line-1), column(column-1)
    {  }
};

struct ParserException : public StringException {
    std::string msg;
    location l;
    ParserLocation begin, end;
    size_t count;

    ParserException (ParserLocation begin, ParserLocation end, const location& l, const std::string& msg)
	: StringException(msg), msg(msg), l(l), begin(begin), end(end), count(1)
    { prepare(); }
    virtual ~ParserException () throw() {  }
    void prepare () {
	std::stringstream ss;
	ss << l << ": " << msg;
	if (count > 1)
	    ss << " (" << count << " more times)";
	str = ss.str();
    }
    size_t incrementCount () {
	++count;
	prepare();
	return count;
    }
};

inline void operator++ (ParserException& ref, int) {
    ref.incrementCount();
}

struct ParserExceptions : std::exception {
    std::vector<ParserException> errors;
    std::string msg;
    virtual ~ParserExceptions () throw() {  }
    void push_back (ParserException ex) {
	std::string exmsg = ex.what();
	if (errors.size() > 0) {
	    if (exmsg.find_first_of("\n") != std::string::npos)
		msg += "\n-- \n";
	    else
		msg += "\n";
	}
	msg += exmsg;
	errors.push_back(ex);
    }
    void increment (size_t offset) {
	errors[offset]++;
	msg.clear();
	for (std::vector<ParserException>::const_iterator it = errors.begin();
	     it != errors.end(); ++it) {
	    std::string exmsg = it->what();
	    if (it != errors.begin() && errors.size() > 0) {
		if (exmsg.find_first_of("\n") != std::string::npos)
		    msg += "\n-- \n";
		else
		    msg += "\n";
	    }
	    msg += exmsg;
	}
    }
    void clear () { errors.clear(); msg = ""; }
    virtual const char* what() const throw() {
	return msg.c_str();
    }
    size_t size () const { return errors.size(); }
    ParserException& operator[] (size_t i) { return errors[i]; }
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
    ParserExceptions	errors;

    struct PrefixErrorInfo {
	size_t index;
	const URI* nspace;
	PrefixErrorInfo (size_t index, const URI* nspace)
	    : index(index), nspace(nspace)
	{  }
    };
    std::map<std::string, PrefixErrorInfo> prefixErrors;

public:
    /// construct a new parser driver context
    YaccDriver(AtomFactory* atomFactory, size_t abortErrorCount = 1);
    YaccDriver(std::string baseURI, AtomFactory* atomFactory, size_t abortErrorCount = 1);
    virtual ~YaccDriver () {  }
    void reset () { prefixErrors.clear(); errors.clear(); }

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    size_t abortErrorCount;
    size_t error (const location& yylloc, const std::string& m) {
	ParserException p(ParserLocation(yylloc.begin.filename, yylloc.begin.line, yylloc.begin.column),
			  ParserLocation(yylloc.end.filename, yylloc.end.line, yylloc.end.column), yylloc, m);
	if (abortErrorCount == 1)
	    throw p;

	size_t ret = errors.size(); // index of added exception.
	errors.push_back(p);
	if (abortErrorCount != 0 && ret+1 >= abortErrorCount)
	    throw errors;

	return ret;
    }
    const URI* prefixError (std::string prefix, const location& yylloc) {
	const URI* nspace;
	std::map<std::string, YaccDriver::PrefixErrorInfo>::const_iterator lastError
	    = prefixErrors.find(prefix);
	if (lastError == prefixErrors.end()) {
	    std::stringstream ss;
	    ss << "Unknown prefix: \"" << prefix << "\"";
	    nspace = getAbsoluteURI("unknownPrefix:" + boost::lexical_cast<std::string>(prefixErrors.size()) + "#");
	    size_t offset = error(yylloc, ss.str()); // may throw.
	    prefixErrors.insert(std::make_pair(prefix, YaccDriver::PrefixErrorInfo(offset, nspace)));
	} else {
	    nspace = lastError->second.nspace;
	    errors.increment(lastError->second.index);
	}
	return nspace;
    }
    void checkErrors () {
	if (errors.size() == 0)
	    return;
	// if (errors.size() == 1)
	//     throw errors[0];
	if (Global::Force)
	    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::error)
		<< "proceeding despite " << errors.size()
		<< " error" << (errors.size()==1 ? "" : "s")
		// << " from parsing \"" << nameStr << "\""
		<< ":\n" << errors.what();
	else
	    throw errors;
	// std::stringstream ss;
	// for (std::vector<ParserException>::const_iterator it = errors.begin();
	//      it != errors.end(); ++it) {
	//     if (it != errors.begin())
	// 	ss << "\n--\n";
	//     ss << it->what();
	// }
	// StringException p(errors[0].begin, errors[0].end, ss.str());
	// errors.clear();
	// throw p;
    }

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

    /// enable debug output in the flex scanner
    bool trace_scanning;

    /// enable debug output in the bison parser
    bool trace_parsing;

    /// stream name (file or input stream) used for error messages.
    std::string streamname;

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
    static void unescapeNumeric (const char* yytext, size_t len, std::string* space, location* yylloc) {
	for (size_t i = 0; i < len; i++) {
	    if (yytext[i] == '\\') {
		switch (yytext[++i]) {
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
			throw std::runtime_error
			    ("\"" + std::string(yytext, len) + "\""
			     " leaves insufficent space for escape sequence at \""
			     + std::string(yytext+i, len-i) + "\"");
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
			throw std::runtime_error
			    ("\"" + std::string(yytext, len) + "\""
			     " leaves insufficent space for escape sequence at \""
			     + std::string(yytext+i, len-i) + "\"");
		default:
		    throw std::runtime_error
			(std::string() + "unexpected escape character '" + yytext[i] + "' in " + yytext);
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
    static void unescapeString (const char* yytext, size_t len, std::string* space, location* yylloc) {
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
			throw std::runtime_error
			    ("\"" + std::string(yytext, len) + "\""
			     " leaves insufficent space for escape sequence at \""
			     + std::string(yytext+i, len-i) + "\"");
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
			throw std::runtime_error
			    ("\"" + std::string(yytext, len) + "\""
			     " leaves insufficent space for escape sequence at \""
			     + std::string(yytext+i, len-i) + "\"");
		default:
		    throw std::runtime_error
			(std::string() + "unexpected escape character '" + yytext[i] + "' in " + yytext);
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
    static void unescapeReserved (const char* yytext, size_t len, std::string* space, location* yylloc) {
	for (size_t i = 0; i < len; i++) {
	    if (yytext[i] == '\\') {
		switch (yytext[++i]) {
		case '_':
		case '~':
		case '.':
		case '-':
		case '!':
		case '$':
		case '&':
		case '\'':
		case '(':
		case ')':
		case '*':
		case '+':
		case ',':
		case ';':
		case '=':
		case '/':
		case '?':
		case '#':
		case '@':
		case '%':
		    (*space) += yytext[i];
		    break;
		default: throw std::runtime_error
			(std::string() + "unexpected escape character '" + yytext[i] + "' in " + yytext);
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
    YaccDataDriver (AtomFactory* atomFactory, size_t abortErrorCount = 1)
	: YaccDriver(atomFactory, abortErrorCount)
    {  }
    YaccDataDriver (std::string baseURI, AtomFactory* atomFactory, size_t abortErrorCount = 1)
	: YaccDriver (baseURI, atomFactory, abortErrorCount)
    {  }

public:
    void setGraph (BasicGraphPattern* bgp) { curBGP = bgp; }
};

class FilterExpressions {
public:
    std::vector<const Expression*> m_Expressions;
    void addExpression (const Expression* expression) {
	m_Expressions.push_back(expression);
    }
    void copyExpressionsTo (OptionalGraphPattern* target) {
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
	     it != m_Expressions.end(); ++it)
	    target->addExpression(*it);
	m_Expressions.clear();
    }
};

} //namespace w3c_sw

#endif /* ! defined PARSER_COMMON_HH */

