/* RdfXmlParser - SWSaxHandler to parse RDF/XML
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_XML_PARSER_H
#define RDF_XML_PARSER_H

#include "RdfDB.hpp"
#include "ParserCommon.hpp"
#include "../interface/SAXparser.hpp"
#define AS_STRING(A) boost::lexical_cast<std::string>(A)

namespace w3c_sw {

    class RdfXmlParser : public ParserDriver { // !!! doesn't respect setBase API
	class RdfXmlSaxHandler : public SWSAXhandler {
	protected:
	    enum Expect {DOCUMENT, SUBJECT, PROPERTY, COLLECTION, XMLLITERAL, s_ERROR};
	    struct State {
		enum Expect expect;
		const TTerm* s;
		const TTerm* p;
		unsigned int ordinal;
		std::string reifyID;
		LANGTAG* langtag;

		State () : expect(s_ERROR), s(NULL), p(NULL), ordinal(0), langtag(NULL)
		{  }
		const char* stateStr () const {
		    static const char* stateStrs[] =
			{"document", "subject", "property", "collection", "XMLliteral", "huh?"};
		    return stateStrs[expect];
		}
		std::string toString () const {
		    std::stringstream ret;
		    ret << 
			"{ " << stateStr() << 
			"	" << (s == NULL ? "NULL" : s->toString()) << 
			"	" << (p == NULL ? "NULL" : p->toString()) << 
			"	" << ordinal << 
			"	" << reifyID << 
			"	" << (langtag == NULL ? "NULL" : langtag->getLexicalValue()) << 
			"}" << std::endl;
		    return ret.str();
		}
	    };

	    BasicGraphPattern* bgp;
	    AtomFactory* atomFactory;
	    std::string baseURI;
	    std::string chars;
	    bool expectCharData;
	    const URI* datatype;
	    std::stack<State> stack;
	    TTerm::String2BNode bnodeMap;
	    std::set<std::string> IDs;

	    void reify (const TriplePattern* triple, std::string reifID) {
		const TTerm* reifS = atomFactory->getURI(baseURI + "#" + reifID);
		bgp->addTriplePattern(atomFactory->getTriple
				      (reifS, 
				       atomFactory->getURI(std::string(NS_rdf) + "type"),
				       atomFactory->getURI(std::string(NS_rdf) + "Statement")));
		bgp->addTriplePattern(atomFactory->getTriple
				      (reifS, 
				       atomFactory->getURI(std::string(NS_rdf) + "subject"),
				       triple->getS()));
		bgp->addTriplePattern(atomFactory->getTriple
				      (reifS, 
				       atomFactory->getURI(std::string(NS_rdf) + "predicate"),
				       triple->getP()));
		bgp->addTriplePattern(atomFactory->getTriple
				      (reifS, 
				       atomFactory->getURI(std::string(NS_rdf) + "object"),
				       triple->getO()));
	    }

	    std::string dumpStack () {
		std::vector<State> copy;
		for ( ; !stack.empty(); stack.pop())
		    copy.insert(copy.begin(), stack.top());

		std::stringstream ret;
		for (std::vector<State>::const_iterator it = copy.begin();
		     it != copy.end(); ++it) {
		    stack.push(*it);
		    ret << it->toString();
		}
		return ret.str();
	    }

/*
<http://www.w3.org/TR/xml-names11/#NT-NCName> :
[4]   	NCName	   ::=   	NCNameStartChar NCNameChar*	# An XML Name, minus the ":"
[5]   	NCNameChar	   ::=   	NameChar - ':'
[6]   	NCNameStartChar	   ::=   	NameStartChar - ':'

<http://www.w3.org/TR/xml11/#NT-NameStartChar> :
[4]   	NameStartChar	   ::=   	":" | [A-Z] | "_" | [a-z] | [#xC0-#xD6] | [#xD8-#xF6] | [#xF8-#x2FF] | [#x370-#x37D] | [#x37F-#x1FFF] | [#x200C-#x200D] | [#x2070-#x218F] | [#x2C00-#x2FEF] | [#x3001-#xD7FF] | [#xF900-#xFDCF] | [#xFDF0-#xFFFD] | [#x10000-#xEFFFF]
[4a]   	NameChar	   ::=   	NameStartChar | "-" | "." | [0-9] | #xB7 | [#x0300-#x036F] | [#x203F-#x2040]
[5]   	Name	   ::=   	NameStartChar (NameChar)*
*/
	    static int UTF8_firstNonIDChar (std::string ID) {
		size_t charPos = 0;
		for (size_t i = 0; i < ID.length(); ++i, ++charPos) {
		    unsigned char c0, c1, c2, c3;
		    c0 = ID[i];
		    if (c0 >= 0x80) {
			assert(++i <= ID.length());
			c1 = ID[i];
			if (c0 >= 0xE0) {
			    assert(++i <= ID.length());
			    c2 = ID[i];
			    if (c0 >= 0xF0) {
				assert(++i <= ID.length());
				c3 = ID[i];
			    }
			}
		    }
		    if (!((c0 >= 'A' && c0 <= 'Z') || c0 == '_' || (c0 >= 'a' && c0 <= 'z') || // [A-Z] | "_" | [a-z]
			  (c0 == 0xC3 && 
			   ((c1 >= 0x80 && c1 <= 0x96) || // [#xC0-#xD6] 0xC3 0x80 - 0xC3 0x96
			    (c1 >= 0x98 && c1 <= 0xB6) || // [#xD8-#xF6] 0xC3 0x98 - 0xC3 0xB6
			    (c1 >= 0xB8))) || 
			  (c0 >= 0xC4 && c0 <= 0xCA) || (c0 == 0xCB && c1 <= 0xBF) || // [#xF8-#x2FF] 0xC3 0xB8 - 0xCB 0xBF
			  (c0 == 0xCD && 
			   ((c1 >= 0xB0 && c1 <= 0xBD) || // [#x370-#x37D] 0xCD 0xB0 - 0xCD 0xBD
			    (c1 >= 0xBF))) || 
			  (c0 >= 0xCE && c0 <= 0xE0) || (c0 == 0xE1 && (c1 <= 0xBE || (c1 == 0xBF && c2 <= 0xBF))) || // [#x37F-#x1FFF] 0xCD 0xBF - 0xE1 0xBF 0xBF
			  (c0 == 0xE2 && 
			   ((c2 >= 0x8C && c2 <= 0x8D) || // [#x200C-#x200D] 0xE2 0x80 0x8C - 0xE2 0x80 0x8D
			    ((c1 == 0x81 && c2 >= 0xB0) || (c1 >= 0x82 && c1 <= 0x85) || (c1 == 0x86 && c2 <= 0x8F)) || // [#x2070-#x218F] 0xE2 0x81 0xB0 - 0xE2 0x86 0x8F
			    ((c1 == 0xB0 && c2 >= 0x80) || (c1 >= 0xB1 && c1 <= 0xBE) || (c1 == 0xBF && c2 <= 0xAF)))) || // [#x2C00-#x2FEF] 0xE2 0xB0 0x80 - 0xE2 0xBF 0xAF
			  (c0 == 0xE3 && c1 == 0x80 && c2 >= 0x81) || (c0 >= 0xE4 && c0 <= 0xEC) || (c0 == 0xED && (c1 <= 0x9E || (c1 == 0x9F && c2 <= 0xBF))) || // [#x3001-#xD7FF] 0xE3 0x80 0x81 - 0xED 0x9F 0xBF
			  (c0 == 0xEF && 
			   (((c1 == 0xA4 && c2 >= 0x80) || (c1 >= 0xA5 && c1 <= 0xB6) || (c1 == 0xB7 && c2 <= 0x8F)) || // [#xF900-#xFDCF] 0xEF 0xA4 0x80 - 0xEF 0xB7 0x8F
			    ((c1 == 0xB7 && c2 >= 0xB0) || (c1 >= 0xB8 && c1 <= 0xBE) || (c1 == 0xBF && c2 <= 0xBD)))) || // [#xFDF0-#xFFFD] 0xEF 0xB7 0xB0 - 0xEF 0xBF 0xBD
			  (c0 == 0xF0 && c1 == 0x90) || (c0 >= 0xF1 && c0 <= 0xF2) || (c0 == 0xF3 && (c1 <= 0xAE || (c1 == 0xAF && (c2 <= 0xBE || (c2 == 0xBF && c3 <= 0xBF))))) // [#x10000-#xEFFFF] 0xF0 0x90 0x80 0x80 - 0xF3 0xAF 0xBF 0xBF
			  )
			&& !(charPos >= 1 &&
			     (c0 == '-' || 
			      c0 == '.' ||
			      (c0 >= '0' && c0 <= '9') || 
			      (c0 == 0xC2 && c1 == 0xB7) || 
			      (c0 == 0xCC) || (c0 == 0xCD && c1 <= 0xAF) || 
			      (c0 == 0xE2 && ((c1 == 0x80 && c2 == 0xBF) || (c1 == 0x81 && c2 == 0x80))) ||
			      false
			      )))
			return charPos;
		}
		return -1;
	    }

#if 0
std::string bytes (std::string s) {
    std::ostringstream ret;
    for (size_t i = 0; i < s.size(); ++i)
	ret << std::hex << (int)(unsigned char)s[i] << " ";
    return ret.str();
}

int main (int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
	std::string test = argv[i];
	if (test == "-") {
	    test = "";
	    std::istream_iterator<char> isi(std::cin), isiend;
	    std::copy(isi, isiend, std::insert_iterator<std::string>(test, test.begin()));
	}
	std::cout << test << "(" << bytes(test) << "): " << UTF8_firstNonIDChar(test) << "\n";
    }
    return 0;
}
#endif /* 0 */

	public:
	    RdfXmlSaxHandler (BasicGraphPattern* bgp, std::string baseURI, AtomFactory* atomFactory) : 
		bgp(bgp), atomFactory(atomFactory), baseURI(baseURI), chars(""), expectCharData(false) {
		State newState;
		newState.expect = DOCUMENT;
		stack.push(newState);
	    }

	    virtual void setBase (std::string base) { baseURI = base; }

	    virtual void startElement (std::string uri,
				       std::string localName,
				       std::string qName,
				       Attributes* attrs, 
				       NSmap& /* nsz */) {
		State newState;
		switch (stack.top().expect) {
		case DOCUMENT:
		    if (uri == NS_rdf && localName == "RDF") {
			newState.expect = SUBJECT;
			break;
		    }
		case SUBJECT:
		case COLLECTION: { // 
		    if (uri == NS_rdf && (localName == "nodeID" || localName == "resource" || localName == "parseType" || localName == "about" || localName == "ID" || localName == "RDF" || localName == "aboutEach" || localName == "aboutEachPrefix" || localName == "bagID"))
			varError("RDF nodeID, resource, parseType, about, ID, RDF, Description, aboutEach, aboutEachPrefix and bagID are not permitted as a subject type name. seen in %s", stack.top().stateStr());
		    if (uri == NS_rdf && localName == "li")
			varError("unexpected element rdf:li within %s", stack.top().stateStr());
		    std::string t;
		    newState.langtag = attrs->value(NS_xml, "lang", &t)
			? new LANGTAG(t.c_str())
			: stack.top().langtag;

		    newState.expect = PROPERTY;

		    /* Each subject element represents a node.
		     */
		    {
			/* subject comes from about or ID or is a BNode. */
			std::string subject;
			if (attrs->value(NS_rdf, "about", &subject))
			    newState.s = atomFactory->getURI
				(libwww::HTParse(subject, &baseURI, libwww::PARSE_all).c_str());
			if (attrs->value(NS_rdf, "ID", &subject)) {
			    if (newState.s)
				varError("RDF ID attribute inconsistent with other attributes in %s", stack.top().stateStr());
			    else if (UTF8_firstNonIDChar(subject) != -1)
				varError("malformed RDF ID in %s", stack.top().stateStr());
			    else if (IDs.find(subject) != IDs.end())
				varError("duplicate RDF ID %s in %s", subject.c_str(), stack.top().stateStr());
			    else {
				IDs.insert(subject);
				newState.s = atomFactory->getURI(baseURI + "#" + subject);
			    }
			}
			if (attrs->value(NS_rdf, "nodeID", &subject)) {
			    if (newState.s)
				varError("RDF nodeID attribute inconsistent with other attributes in %s", stack.top().stateStr());
			    else if (UTF8_firstNonIDChar(subject) != -1)
				varError("malformed RDF nodeID in %s", stack.top().stateStr());
			    else
				newState.s = atomFactory->getBNode(subject, &bnodeMap);
			}
			if (newState.s == NULL)
			    newState.s = atomFactory->createBNode();

			std::string t;
			if (attrs->value(NS_rdf, "bagID", &t) && UTF8_firstNonIDChar(t) != -1)
				varError("malformed RDF bagID (which was removed from the langugae anyways) in %s", stack.top().stateStr());
		    }

		    /* Create statements for subject's literalPropertyElt. */
		    for (size_t i = 0; i < attrs->getLength(); ++i) {
			std::string attrURI = attrs->getURI(i);
			std::string attrLName = attrs->getLocalName(i);
			if (attrURI == NS_rdf) {
			    if (attrLName == "ID" ||
				attrLName == "about" ||
				attrLName == "parseType" ||
				attrLName == "resource" ||
				attrLName == "nodeID" ||
				attrLName == "datatype" ||
				attrLName == "Description" ||
				attrLName == "bagID") {
				goto next_subject_attr;
			    } else if (attrLName == "li" ||
				       attrLName == "aboutEach" ||
				       attrLName == "aboutEachPrefix") {
				varError("unexpected attr %s within %s", attrs->getQName(i).c_str(), stack.top().stateStr());
			    }
			} else if (attrs->getQName(i).substr(0, 3) == "xml") {
			    // ignore XML directives.
			    goto next_subject_attr;
			}
			{
			    /* newState.s -[attribute]-> [value] . */
			    const TTerm* predicate = atomFactory->getURI(attrURI + attrLName);
			    std::string value; attrs->value(attrURI, attrLName, &value);
			    const TTerm* object = (attrURI == NS_rdf && attrLName == "type")
				? (const TTerm*)atomFactory->getURI(libwww::HTParse(value, &baseURI, libwww::PARSE_all).c_str())
				: (const TTerm*)atomFactory->getRDFLiteral(value, NULL, newState.langtag);
			    bgp->addTriplePattern(atomFactory->getTriple(newState.s, predicate, object));
			}
		    next_subject_attr:
			;
		    }

		    /* Subject elements nested inside a predicate element are
		     * objects of that predicate.
		     */
		    const TTerm* p = stack.top().p;
		    if (p != NULL) {
			State parentState = stack.top();
			const TTerm* s = parentState.s;

			stack.pop(); // we will re-push with a new predicate.
			if (parentState.expect == COLLECTION) {
			    const TTerm* b = atomFactory->createBNode();

			    /* Subsequent entries will be rests. */
			    parentState.p = atomFactory->getURI( std::string(NS_rdf) + "rest");
			    /* Subsequent entries will append the tail of the list. */
			    parentState.s = b;
			    stack.push(parentState);
			    std::stringstream ss;
			    ss << "<" << qName.c_str() << ">" << std::endl << dumpStack();
			    // w3c_sw_LINEN << ss;

			    /*
			     *	    s
			     *	     \p [was rest if nth in a Collection]
			     *	      \
			     *	       b _type_ rdf:Collection
			     *	      /	\
			     *	first/   \rest
			     *	    /	  \
			     *	 node      [another list or rdf:Nil]
			     */
			    const TTerm* f = atomFactory->getURI(std::string(NS_rdf) + "first");
			    const TTerm* t = atomFactory->getURI(std::string(NS_rdf) + "type");
			    // const TTerm* c = atomFactory->getURI(std::string(NS_rdf) + "Collection");
			    bgp->addTriplePattern(atomFactory->getTriple(s, p, b));
			    // bgp->addTriplePattern(atomFactory->getTriple(b, t, c));
			    bgp->addTriplePattern(atomFactory->getTriple(b, f, newState.s));
			} else if (parentState.expect == -999) {
			    std::string ordStr = AS_STRING(parentState.ordinal++);
			    parentState.p = atomFactory->getURI(std::string(NS_rdf) + "_"+ordStr);
			    stack.push(parentState);
			    bgp->addTriplePattern(atomFactory->getTriple(s, p, newState.s));
			} else {
			    /* Only one nested subject allowed. */
			    parentState.p = NULL;
			    stack.push(parentState);

			    /*
			     *	    s
			     *	     \p
			     *	      \
			     *	      node
			     */
			    bgp->addTriplePattern(atomFactory->getTriple(s, p, newState.s));
			}
		    }

		    /* Add type arc for typed nodes. */
		    if ( stack.top().expect != -999 && !(uri == NS_rdf && localName == "Description") ) {
			const TTerm* p = atomFactory->getURI(std::string(NS_rdf) + "type");
			const TTerm* t = atomFactory->getURI(uri + localName);
			bgp->addTriplePattern(atomFactory->getTriple(newState.s, p, t));
		    }
		    break;
		}
		case PROPERTY: {
		    if (uri == NS_rdf && (localName == "nodeID" || localName == "resource" || localName == "parseType" || localName == "about" || localName == "ID" || localName == "RDF" || localName == "Description" || localName == "aboutEach" || localName == "aboutEachPrefix" || localName == "bagID"))
			varError("RDF nodeID, resource, parseType, about, ID, RDF, Description, aboutEach, aboutEachPrefix and bagID are not permitted as a property name. seen in %s", stack.top().stateStr());
		    if (uri == NS_rdf && (localName == "aboutEach" || localName == "aboutEachPrefix"))
			varError("RDF aboutEach and aboutEachPrefix have been removed from RDF/XML. seen in %s", stack.top().stateStr());
		    std::string t; // used a couple times below

		    /* Grab xsd:datatype and xml:lang.
		     * These are non-recursive (a literal predicate can't
		     * contain another predicate) so we leave them out of the
		     * stack state.
		     */
		    datatype = attrs->value(NS_rdf, "datatype", &t) ? atomFactory->getURI(t) : NULL;
		    newState.langtag = attrs->value(NS_xml, "lang", &t) ?
			new LANGTAG(t.c_str()) :
			stack.top().langtag;

		    if (uri == NS_rdf && localName == "li") {
			State parentState = stack.top();
			stack.pop(); // we will re-push with a new predicate.
			std::string ordStr = AS_STRING(++parentState.ordinal);
			stack.push(parentState);
			newState.p = atomFactory->getURI(std::string(NS_rdf) + "_"+ordStr);
			// newState.expect = PROPERTY;
		    /* Nested state depends solely on localName. */ // !! try moving to bottom
		    } else
			newState.p = atomFactory->getURI(uri + localName);
		    std::string parseType;
		    std::string nodeID; ;

		    /* rdf:parseType or rdf:resource attributes imply a new node.
		     * Otherwise, may be a:
		     *   literal - expect chars).
		     *   Collection - may be nil for an empty Collection.
		     *   node with predicate attributes - handled below.
		     */
		    expectCharData = false;
		    if (attrs->value(NS_rdf, "resource", &t))
			newState.s = atomFactory->getURI(libwww::HTParse(t, &baseURI, libwww::PARSE_all).c_str());
		    if (attrs->value(NS_rdf, "parseType", &parseType)) {
			if (newState.s)
			    varError("RDF parseType attribute inconsistent with other attributes in %s", stack.top().stateStr());
			else if (parseType == "Resource")
			    newState.s = atomFactory->createBNode();
		    }
		    if (attrs->value(NS_rdf, "nodeID", &t)) {
			if (newState.s)
			    varError("RDF nodeID attribute inconsistent with other attributes in %s", stack.top().stateStr());
			else if (UTF8_firstNonIDChar(t) != -1)
			    varError("malformed RDF ID in %s", stack.top().stateStr());
			else
			    newState.s = atomFactory->getBNode(t, &bnodeMap);
		    }
		    if (newState.s == NULL)
			expectCharData = true;

		    if (attrs->value(NS_rdf, "ID", &t)) {
			if (UTF8_firstNonIDChar(t) != -1)
			    varError("RDF parseType attribute inconsistent with other attributes in %s", stack.top().stateStr());
			else if (IDs.find(t) != IDs.end())
			    varError("duplicate RDF ID %s in %s", t.c_str(), stack.top().stateStr());
			else
			    newState.reifyID = t;
		    }

		    if (newState.s != NULL) {
			const TriplePattern* triple =
			    atomFactory->getTriple(stack.top().s,newState.p, newState.s);
			bgp->addTriplePattern(triple);
			if (newState.reifyID.size())
			    reify(triple, newState.reifyID);
		    }

		    /* Create statements for predicate attributes. */
		    for (size_t i = 0; i < attrs->getLength(); ++i) {
			std::string attrURI = attrs->getURI(i);
			std::string attrLName = attrs->getLocalName(i);
			if (attrURI == NS_rdf) {
			    if (attrLName == "parseType" ||
				attrLName == "resource" ||
				attrLName == "datatype" ||
				attrLName == "ID" ||
				attrLName == "nodeID") {
				// allowed attrs
				goto next_property_attr;
			    } else if (attrLName != "aboutEach" &&
				       attrLName != "aboutEachPrefix") {
				varError("unexpected attr %s within %s", attrs->getQName(i).c_str(), stack.top().stateStr());
			    // attrLName != "type" &&
			    // attrLName != "Seq" &&
			    // attrLName != "Alt" &&
			    // attrLName != "Bag")

			    }
			} else if (attrs->getQName(i).substr(0, 3) == "xml") {
			    // ignore XML directives.
			    goto next_property_attr;
			}
			{
			    /* We must have a current node. */
			    if (newState.s == NULL) {
				newState.s = atomFactory->createBNode();
				const TriplePattern* triple =
				    atomFactory->getTriple(stack.top().s, newState.p, newState.s);
				bgp->addTriplePattern(triple);
				if (newState.reifyID.size())
				    reify(triple, newState.reifyID);
			    }

			    /* newState.s -[attribute]-> [value] . */
			    const TTerm* predicate = atomFactory->getURI(attrURI + attrLName);
			    attrs->value(attrURI, attrLName, &t);
			    const TTerm* object = atomFactory->getRDFLiteral(t, NULL, newState.langtag);
			    bgp->addTriplePattern(atomFactory->getTriple(newState.s, predicate, object));
			    expectCharData = false;
			}
		    next_property_attr:
			;
		    }

		    /* Nested state depends solely on parseType. */
		    newState.expect = 
			parseType == "Collection" ? COLLECTION : 
			parseType == "Resource" ? PROPERTY : 
			parseType == "Literal" ? XMLLITERAL : 
			SUBJECT;

		    if (newState.s == NULL)
			newState.s = stack.top().s;
		    break;
		}
		case XMLLITERAL: {
		    /* Create statements for predicate attributes. */
		    chars += "<" + qName;
		    for (size_t i = 0; i < attrs->getLength(); ++i) {
			std::string attrURI = attrs->getURI(i);
			std::string attrLName = attrs->getLocalName(i);
			std::string value; attrs->value(attrs->getURI(i), attrs->getLocalName(i), &value);
			chars += " " + attrs->getQName(i) + "=\"" + value + "\"";
		    }
		    chars += ">";

		    /* Nested state depends solely on parseType. */
		    newState.expect = XMLLITERAL;
		    break;
		}
		default:
		    varError("unexpected element %s within %s", qName.c_str(), stack.top().stateStr());
		}
		if (newState.expect == s_ERROR)
		    varError("unexpected element %s within %s", qName.c_str(), stack.top().stateStr());
		if (stack.top().expect != XMLLITERAL)
		    chars = "";  // @@ needed?
		stack.push(newState);
		//std::cout << "<" << qName.c_str() << ">" << std::endl << dumpStack();
	    }
	    virtual void endElement (std::string,
				     std::string,
				     std::string qName, 
				     NSmap& /* nsz */) {
		State nestedState = stack.top();
		stack.pop();
		switch (nestedState.expect) {
		case DOCUMENT:
		    break;
		case SUBJECT:
		    if (nestedState.p != NULL && expectCharData == true) {
			/* We were expecting a literal node. */
			const TTerm* o = atomFactory->getRDFLiteral(chars, datatype, nestedState.langtag);
			chars = "";
			const TriplePattern* triple = atomFactory->getTriple(stack.top().s, nestedState.p, o);
			bgp->addTriplePattern(triple);
			if (nestedState.reifyID.size())
			    reify(triple, nestedState.reifyID);
		    }
		    break;
		case COLLECTION: {
		    /* Tack on trailing nil to current predicate (rdf:rest,
		     * except when parsing an empty Collection).
		     */
		    const TTerm* n = atomFactory->getURI(std::string(NS_rdf) + "nil");
		    bgp->addTriplePattern(atomFactory->getTriple(nestedState.s, nestedState.p, n));
		}
		    break;
		case PROPERTY:
		    break;
		case XMLLITERAL:
		    if (stack.top().expect == XMLLITERAL) {
			chars += "</" + qName + ">";
		    } else {
			/* RDF XMLLiteral */
			const TTerm* o = atomFactory->getRDFLiteral(chars, atomFactory->getURI(std::string(NS_rdf) + "XMLLiteral"), NULL);
			chars = "";
			bgp->addTriplePattern(atomFactory->getTriple(stack.top().s, nestedState.p, o));
		    }
		    break;
		default:
		    varError("unexpected state %d", nestedState.expect); // @@ was: stack.top().expect...
		}
		if (chars.size() > 0 && chars.find_first_not_of(" \t\n") != std::string::npos
		    && nestedState.expect != XMLLITERAL)
		    varError("unexpected characters \"%s\" within %s state: %s (inside: %s)", chars.c_str(), qName.c_str(), nestedState.stateStr(), stack.top().stateStr());
		//std::cout << "</" << qName.c_str() << ">" << std::endl << dumpStack();
		expectCharData = false;
	    }
	    virtual void characters (const char ch[],
				     int start,
				     int length, 
				     NSmap& /* nsz */) {
		chars += std::string(ch + start, length);
	    }
	};

    protected:
	AtomFactory* atomFactory;
	SWSAXparser* saxParser;

    public:
	RdfXmlParser (std::string baseURI, AtomFactory* atomFactory, SWSAXparser* saxParser)
	    : ParserDriver(baseURI), atomFactory(atomFactory), saxParser(saxParser) {  }
	bool parse (BasicGraphPattern* bgp, IStreamContext& sptr) {
	    RdfXmlSaxHandler handler(bgp, baseURI, atomFactory);
	    return saxParser->parse(sptr, &handler);
	}

    };

} // namespace w3c_sw

#endif // !RDF_XML_PARSER_H

