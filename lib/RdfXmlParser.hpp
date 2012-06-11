/* RdfXmlParser - SWSaxHandler to parse RDF/XML
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_XML_PARSER_H
#define RDF_XML_PARSER_H

#include "RdfDB.hpp"
#include "ParserCommon.hpp"
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class RdfXmlParser : public ParserDriver { // !!! doesn't respect setBase API
	class RdfXmlSaxHandler : public SWSAXhandler {
	protected:
	    enum Expect {DOCUMENT, SUBJECT, PROPERTY, COLLECTION, XMLLITERAL, s_ERROR};
	    struct State {
		enum Expect expect;
		const TTerm* s;
		const TTerm* p;
		const char* stateStr () const {
		    static const char* stateStrs[] =
			{"document", "subject", "property", "collection", "literal", "huh?"};
		    return stateStrs[expect];
		}
		std::string toString () const {
		    std::stringstream ret;
		    ret << 
			"{ " << stateStr() << 
			"	" << (s == NULL ? "NULL" : s->toString()) << 
			"	" << (p == NULL ? "NULL" : p->toString()) << 
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
	    LANGTAG* langtag;
	    std::stack<State> stack;
	    TTerm::String2BNode bnodeMap;

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

	public:
	    RdfXmlSaxHandler (BasicGraphPattern* bgp, std::string baseURI, AtomFactory* atomFactory) : 
		bgp(bgp), atomFactory(atomFactory), baseURI(baseURI), chars(""), expectCharData(false) {
		State newState = {DOCUMENT, NULL, NULL};
		stack.push(newState);
	    }

	    virtual void startElement (std::string uri,
				       std::string localName,
				       std::string qName,
				       Attributes* attrs, 
				       NSmap& /* nsz */) {
		State newState = {s_ERROR, NULL, NULL};
		switch (stack.top().expect) {
		case DOCUMENT:
		    if (uri == NS_rdf && localName == "RDF") {
			newState.expect = SUBJECT;
			break;
		    }
		case SUBJECT:
		case COLLECTION: {
		    newState.expect = PROPERTY;

		    /* Each subject element represents a node.
		     */
		    {
			/* subject comes from about or ID or is a BNode. */
			std::string subject;
			subject = attrs->getValue(NS_rdf, "about");
			if (subject.empty()) {
			    subject = attrs->getValue(NS_rdf, "ID");
			    if (subject.empty()) {
				subject = attrs->getValue(NS_rdf, "nodeID");
				if (subject.empty())
				    newState.s = atomFactory->createBNode();
				else
				    newState.s = atomFactory->getBNode(subject, bnodeMap);
			    } else
				newState.s = atomFactory->getURI(baseURI + "#" + subject);
			} else
			    newState.s = atomFactory->getURI(libwww::HTParse(subject, &baseURI, libwww::PARSE_all).c_str());
		    }

		    /* Create statements for subject's literalPropertyElt. */
		    for (size_t i = 0; i < attrs->getLength(); ++i) {
			std::string attrURI = attrs->getURI(i);
			std::string attrLName = attrs->getLocalName(i);
			if ( !(attrURI == NS_rdf && attrLName == "RDF") && 
			     !(attrURI == NS_rdf && attrLName == "ID") && 
			     !(attrURI == NS_rdf && attrLName == "about") && 
			     !(attrURI == NS_rdf && attrLName == "parseType") && 
			     !(attrURI == NS_rdf && attrLName == "resource") && 
			     !(attrURI == NS_rdf && attrLName == "nodeID") && 
			     !(attrURI == NS_rdf && attrLName == "datatype") && 
			     !(attrURI == NS_rdf && attrLName == "Description") && 
			     !(attrURI == NS_rdf && attrLName == "aboutEach") && 
			     !(attrURI == NS_rdf && attrLName == "aboutEachPrefix") && 
			     !(attrURI == NS_rdf && attrLName == "bagID") && 
			     !(attrURI == NS_xml)) {

			    /* newState.s -[attribute]-> [value] . */
			    const TTerm* predicate = atomFactory->getURI(attrURI + attrLName);
			    std::string value = attrs->getValue(attrURI, attrLName);
			    const TTerm* object = atomFactory->getRDFLiteral(value, NULL, NULL);
			    bgp->addTriplePattern(atomFactory->getTriple(newState.s, predicate, object));
			}
		    }

		    /* Subject elements nested inside a predicate element are
		     * objects of that predicate.
		     */
		    const TTerm* p = stack.top().p;
		    if (p != NULL) {
			State parentState = stack.top();
			const TTerm* s = parentState.s;

			stack.pop(); // we will re-push with a new predicate.
			if (stack.top().expect == COLLECTION) {
			    const TTerm* b = atomFactory->createBNode();

			    /* Subsequent entries will be rests. */
			    parentState.p = atomFactory->getURI( std::string(NS_rdf) + "rest");
			    /* Subsequent entries will append the tail of the list. */
			    parentState.s = b;
			    stack.push(parentState);

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
			    const TTerm* c = atomFactory->getURI(std::string(NS_rdf) + "Collection");
			    bgp->addTriplePattern(atomFactory->getTriple(s, p, b));
			    bgp->addTriplePattern(atomFactory->getTriple(b, t, c));
			    bgp->addTriplePattern(atomFactory->getTriple(b, f, newState.s));
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
		    if ( !(uri == NS_rdf && localName == "Description") ) {
			const TTerm* p = atomFactory->getURI(std::string(NS_rdf) + "type");
			const TTerm* t = atomFactory->getURI(uri + localName);
			bgp->addTriplePattern(atomFactory->getTriple(newState.s, p, t));
		    }
		    break;
		}
		case PROPERTY: {
		    std::string t; // used a couple times below
		    newState.p = atomFactory->getURI(uri + localName);
		    std::string parseType = attrs->getValue(NS_rdf, "parseType");
		    std::string nodeID = attrs->getValue(NS_rdf, "nodeID");

		    /* rdf:parseType or rdf:resource attributes imply a new node.
		     * Otherwise, may be a:
		     *   literal - expect chars).
		     *   Collection - may be nil for an empty Collection.
		     *   node with predicate attributes - handled below.
		     */
		    t = attrs->getValue(NS_rdf, "resource");
		    if ( !t.empty() )
			newState.s = atomFactory->getURI(libwww::HTParse(t, &baseURI, libwww::PARSE_all).c_str());
		    else if ( !parseType.empty() )
			newState.s = atomFactory->createBNode();
		    else if ( !nodeID.empty() )
			newState.s = atomFactory->getBNode(nodeID, bnodeMap);
		    else
			expectCharData = true;
		    if (newState.s != NULL)
			bgp->addTriplePattern(atomFactory->getTriple(stack.top().s, 
							    newState.p, newState.s));

		    /* Grab xsd:datatype and xml:lang.
		     * These are non-recursive (a literal predicate can't
		     * contain another predicate) so we leave them out of the
		     * stack state.
		     */
		    t = attrs->getValue(NS_rdf, "datatype");
		    datatype = t.empty() ? NULL : atomFactory->getURI(t);
		    t = attrs->getValue(NS_xml, "lang");
		    langtag = t.empty() ? NULL : new LANGTAG(t.c_str());

		    /* Create statements for predicate attributes. */
		    for (size_t i = 0; i < attrs->getLength(); ++i) {
			std::string attrURI = attrs->getURI(i);
			std::string attrLName = attrs->getLocalName(i);
			if ( !(attrURI == NS_rdf && attrLName == "parseType") && 
			     !(attrURI == NS_rdf && attrLName == "resource") && 
			     !(attrURI == NS_rdf && attrLName == "datatype") && 
			     !(attrURI == NS_xml && attrLName == "lang")) {

			    /* We must have a current node. */
			    if (newState.s == NULL) {
				newState.s = atomFactory->createBNode();
				bgp->addTriplePattern(atomFactory->getTriple(stack.top().s, 
									    newState.p, newState.s));
			    }

			    /* newState.s -[attribute]-> [value] . */
			    const TTerm* predicate = atomFactory->getURI(attrURI + attrLName);
			    std::string value = attrs->getValue(attrURI, attrLName);
			    const TTerm* object = atomFactory->getRDFLiteral(value, NULL, NULL);
			    bgp->addTriplePattern(atomFactory->getTriple(newState.s, predicate, object));
			}
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
			chars += " " + attrs->getQName(i) + "=\"" + attrs->getValue(attrs->getURI(i), attrs->getLocalName(i)) + "\"";
		    }
		    chars + ">";

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
			const TTerm* o = atomFactory->getRDFLiteral(chars, datatype, langtag);
			chars = "";
			bgp->addTriplePattern(atomFactory->getTriple(stack.top().s, nestedState.p, o));
		    }
		    break;
		case COLLECTION: {
		    /* Tack on trailing nil to current predicate (rdf:rest,
		     * except when parsing an empty Collection).
		     */
		    const TTerm* n = atomFactory->getURI(std::string(NS_rdf) + "nil");
		    bgp->addTriplePattern(atomFactory->getTriple(stack.top().s, atomFactory->getURI( std::string(NS_rdf) + "rest"), n));
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
		    varError("unexpected characters \"%s\" within %s (nested state: %s)", chars.c_str(), qName.c_str(), stack.top().stateStr());
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

