/* BRTparser.hpp - simple SPARQL duplicator for SPARQL compile trees.
 *
 *
 * $Id: BRTparser.hpp,v 1.8 2008-11-21 17:13:29 eric Exp $
 */

#ifndef BRTparser_H
#define BRTparser_H

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#ifndef _MSC_VER
  #include <netinet/in.h>
  #include <arpa/inet.h>
#endif /* !_MSC_VER */

namespace w3c_sw {

struct BRTparser {
#pragma pack(1)
    struct Header {
	char    signature[4]; // 0-3
	unsigned int  version; // 4-7
	unsigned int  columns; // 8-11
    };
#pragma pack()

    // Nice byte-sized enum available only in c++0x:
    // enum RecordTypeMarker: unsigned char { ... };

    typedef enum {
	RT_NULL = 0,
	RT_REPEAT,
	RT_NAMESPACE,
	RT_QNAME,
	RT_URI,
	RT_BNODE,
	RT_PLAIN_LITERAL,
	RT_LANG_LITERAL,
	RT_DATATYPE_LITERAL,
	RT_ERROR = 126,
	RT_TABLE_END = 127
    } RecordTypeMarker;

    AtomFactory* atomFactory;
    ResultSet& rs;

    /* The parsing state is in these three variables:
     *   cur: pointer to current Solution.
     *   last: pointer to last Solution.
     *   var: pointer to next varname to be assigned.
     */
    ResultSetIterator cur;
    ResultSetConstIterator last;
    typedef std::vector<const TTerm*> Vars;
    Vars vars;
    Vars::const_iterator var;
    bool firstRow;

    void _ensureCurSolution () {
	if (var == vars.end()) {
	    var = vars.begin();
	    cur = rs.insert(rs.end(), new Result(&rs));
	    if (!firstRow) {
		last = cur;
		--last;
	    }
	    firstRow = false;
	}
    }

    void _setAndIncrement (const TTerm* v) {
	(*cur)->set(*var++, v, false);
    }

    void set (const TTerm* v) {
	_ensureCurSolution();
	_setAndIncrement(v);
    }

    void setLast () {
	_ensureCurSolution();
	if (firstRow)
	    throw std::runtime_error(std::string() + "REPEAT variable \""
				     + (*var)->toString()
				     + "\" with no previous row");
	BindingSetConstIterator f = (*last)->find(*var);
	if (f == (*last)->end())
	    throw std::runtime_error(std::string() + "REPEAT variable \""
				     + (*var)->toString()
				     + "\" with no value in previous row");
	_setAndIncrement(f->second.tterm);
    }


    // Are namespaces allocated from 0? (Should this be a dense array?)
    std::map<unsigned int, const std::string> namespaces;

    BRTparser (AtomFactory* atomFactory, ResultSet& rs) : atomFactory(atomFactory), rs(rs), firstRow(true)
    {  }


    /**
     * Convenience functions for reading a stream:
     */
    static unsigned int readInt (w3c_sw::IStreamContext& f) {
	unsigned int size;
	(*f).read(reinterpret_cast<char *>(&size), sizeof(size));
	size = ntohl(size);
	return size;
    }

    static std::string readAtom (w3c_sw::IStreamContext& f) {
	unsigned int size = readInt(f);
	std::string s;
	s.resize(size);
	(*f).read(&s[0], size);
	return s;
    }


    /** operator()
     * The parser is invoked like: parser(myStream);
     * f: an input stream from which to read the BRT.
     */
    ResultSet& operator() (w3c_sw::IStreamContext& f, TTerm::String2BNode& nodeMap) {

	// Tell the istream to generate std::ios_base::failure's on failure.
	std::ios_base::iostate excepts = (*f).exceptions();
	(*f).exceptions(std::ifstream::failbit
		     | std::ifstream::badbit | std::ifstream::eofbit);

	// The header gives us some sanity checks and the number of columns.
	Header header;
	(*f).read(reinterpret_cast<char *>(&header), sizeof(Header));
	if (strncmp(header.signature, "BRTR", 4))
	    throw std::runtime_error
		(std::string() + "signature \""
		 + std::string(header.signature, 4) + "\" != \"BRTR\"");
	header.version = ntohl(header.version);
	header.columns = ntohl(header.columns);

	// Read header (a list of variables).
	for (unsigned int i = 0; i < header.columns; ++i) {
	    std::string varName = readAtom(f);
	    // @@ add to RS rs.widths[varName] = varName.size()+1;
	    vars.push_back(atomFactory->getVariable(varName));
	}
	// Update var iterator to point to final end of list.
	var = vars.end();

	// Result type markers from the BRT description:
	RecordTypeMarker recordTypeMarker;

	bool done = false;
	char b;
	while (!done) {

	    // Not using nice byte-sized enum available in c++0x:
	    // (*f).read(reinterpret_cast<char *>(&recordTypeMarker),
	    // 	   sizeof(recordTypeMarker));

	    (*f).read(&b, sizeof(b));
	    recordTypeMarker = (RecordTypeMarker)b;
	    switch (recordTypeMarker) {
	    case RT_NULL:
		// don't put anything into the map
		break;
	    case RT_REPEAT: {
		setLast();
	    } break;
	    case RT_NAMESPACE: {
		unsigned int ord = readInt(f);
		std::string prefix = readAtom(f);
		namespaces.insert(std::pair<unsigned int,
				  const std::string>(ord, prefix));
		// namespaces[ord] = prefix;
	    } break;
	    case RT_QNAME: {
		unsigned int ord = readInt(f);
		std::string localName = readAtom(f);
		set(atomFactory->getURI(namespaces[ord] + localName));
	    } break;
	    case RT_URI: {
		std::string iri = readAtom(f);
		set(atomFactory->getURI(iri));
	    } break;
	    case RT_BNODE: {
		std::string label = readAtom(f);
		set(atomFactory->getBNode(label, nodeMap));
	    } break;
	    case RT_PLAIN_LITERAL: {
		std::string value = readAtom(f);
		set(atomFactory->getRDFLiteral(value));	
	    } break;
	    case RT_LANG_LITERAL: {
		std::string value = readAtom(f);
		std::string lang = readAtom(f);
		set(atomFactory->getRDFLiteral(value, NULL, new LANGTAG(lang)));
	    } break;
	    case RT_DATATYPE_LITERAL: {
		// lexical value
		std::string value = readAtom(f);

		// datatype
		(*f).read(&b, sizeof(b));
		recordTypeMarker = (RecordTypeMarker)b;
		switch (recordTypeMarker) {
		case RT_QNAME: {
		    unsigned int ord = readInt(f);
		    std::string localName = readAtom(f);
		    set(atomFactory->getRDFLiteral(value, atomFactory->getURI(namespaces[ord] + localName)));
		} break;
		case RT_URI: {
		    std::string iri = readAtom(f);
		    set(atomFactory->getRDFLiteral(value, atomFactory->getURI(iri)));
		} break;
		default:
		    throw std::runtime_error("inappropriate atom type");
		}
	    } break;
	    case RT_ERROR: {
		unsigned char errorType;
		(*f).read(reinterpret_cast<char *>(&errorType), sizeof(errorType));
		std::string msg = readAtom(f);
		switch (errorType) {
		case 1:
		    throw std::runtime_error
			(std::string("malformed query error: " + msg));
		case 2:
		    throw std::runtime_error
			(std::string("query evaluation error: " + msg));
		default: 
		    throw std::runtime_error("unknown atom type");
		}
	    } break;
	    case RT_TABLE_END:
		done = true;
		break;
	    default:
		throw std::runtime_error("unknown atom type");
	    }
	}
	(*f).exceptions(excepts);
	return rs;
    }
};

} // namespace w3c_sw

#endif // BRTparser_H

