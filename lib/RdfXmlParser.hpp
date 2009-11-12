/* RdfXmlParser - SWSaxHandler to parse RDF/XML
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_XML_PARSER_H
#define RDF_XML_PARSER_H

#include "RdfDB.hpp"
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class RdfXmlParser : public ParserDriver { // !!! doesn't respect setBase API
	class RdfXmlSaxHandler : public SWSAXhandler {
	protected:
	    enum Expect {DOCUMENT, SUBJECT, PROPERTY, COLLECTION, s_ERROR};
	    struct State {
		enum Expect expect;
		const POS* s;
		const POS* p;
		const char* stateStr () const {
		    static const char* stateStrs[] =
			{"document", "subject", "property", "collection", "huh?"};
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
	    POSFactory* posFactory;
	    std::string baseURI;
	    std::string chars;
	    const URI* datatype;
	    LANGTAG* langtag;
	    std::stack<State> stack;

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
	    RdfXmlSaxHandler (BasicGraphPattern* bgp, POSFactory* posFactory, std::string baseURI = "") : 
		bgp(bgp), posFactory(posFactory), baseURI(baseURI), chars("") {
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
			    if (subject.empty())
				newState.s = posFactory->createBNode();
			    else
				newState.s = posFactory->getURI(baseURI + "#" + subject);
			} else
			    newState.s = posFactory->getURI(subject);
		    }

		    /* Subject elements nested inside a predicate element are
		     * objects of that predicate.
		     */
		    const POS* p = stack.top().p;
		    if (p != NULL) {
			State parentState = stack.top();
			const POS* s = parentState.s;

			stack.pop(); // we will re-push with a new predicate.
			if (stack.top().expect == COLLECTION) {
			    const POS* b = posFactory->createBNode();

			    /* Subsequent entries will be rests. */
			    parentState.p = posFactory->getURI( std::string(NS_rdf) + "rest");
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
			    const POS* f = posFactory->getURI(std::string(NS_rdf) + "first");
			    const POS* t = posFactory->getURI(std::string(NS_rdf) + "type");
			    const POS* c = posFactory->getURI(std::string(NS_rdf) + "Collection");
			    bgp->addTriplePattern(posFactory->getTriple(s, p, b));
			    bgp->addTriplePattern(posFactory->getTriple(b, t, c));
			    bgp->addTriplePattern(posFactory->getTriple(b, f, newState.s));
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
			    bgp->addTriplePattern(posFactory->getTriple(s, p, newState.s));
			}
		    }

		    /* Add type arc for typed nodes. */
		    if ( !(uri == NS_rdf && localName == "RDF") ) {
			const POS* p = posFactory->getURI(std::string(NS_rdf) + "type");
			const POS* t = posFactory->getURI(uri + localName);
			bgp->addTriplePattern(posFactory->getTriple(newState.s, p, t));
		    }
		    break;
		}
		case PROPERTY: {
		    std::string t; // used a couple times below
		    newState.p = posFactory->getURI(uri + localName);
		    std::string parseType = attrs->getValue(NS_rdf, "parseType");

		    /* rdf:parseType or rdf:resource attributes imply a new node.
		     * Otherwise, may be a:
		     *   literal - expect chars).
		     *   Collection - may be nil for an empty Collection.
		     *   node with predicate attributes - handled below.
		     */
		    t = attrs->getValue(NS_rdf, "resource");
		    if ( !t.empty() )
			newState.s = posFactory->getURI(t);
		    else if ( !parseType.empty() )
			newState.s = posFactory->createBNode();
		    if (newState.s != NULL)
			bgp->addTriplePattern(posFactory->getTriple(stack.top().s, 
							    newState.p, newState.s));

		    /* Grab xsd:datatype and xml:lang.
		     * These are non-recursive (a literal predicate can't
		     * contain another predicate) so we leave them out of the
		     * stack state.
		     */
		    t = attrs->getValue(NS_rdf, "datatype");
		    datatype = t.empty() ? NULL : posFactory->getURI(t);
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
				newState.s = posFactory->createBNode();
				bgp->addTriplePattern(posFactory->getTriple(stack.top().s, 
									    newState.p, newState.s));
			    }

			    /* newState.s -[attribute]-> [value] . */
			    const POS* predicate = posFactory->getURI(attrURI + attrLName);
			    std::string value = attrs->getValue(attrURI, attrLName);
			    const POS* object = posFactory->getRDFLiteral(value, NULL, NULL);
			    bgp->addTriplePattern(posFactory->getTriple(newState.s, predicate, object));
			}
		    }

		    /* Nested state depends souly on parseType. */
		    newState.expect = 
			parseType == "Collection" ? COLLECTION : 
			parseType == "Resource" ? PROPERTY : 
			SUBJECT;

		    break;
		}
		default:
		    varError("unexpected element %s within %s", qName.c_str(), stack.top().stateStr());
		}
		if (newState.expect == s_ERROR)
		    varError("unexpected element %s within %s", qName.c_str(), stack.top().stateStr());
		stack.push(newState);
		chars = "";
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
		    if (nestedState.p != NULL && nestedState.s == NULL) {
			/* We were expecting a literal node. */
			const POS* o = posFactory->getRDFLiteral(chars, datatype, langtag);
			chars = "";
			bgp->addTriplePattern(posFactory->getTriple(stack.top().s, nestedState.p, o));
		    }
		    break;
		case COLLECTION: {
		    /* Tack on trailing nil to current predicate (rdf:rest,
		     * except when parsing an empty Collection).
		     */
		    const POS* n = posFactory->getURI(std::string(NS_rdf) + "nil");
		    bgp->addTriplePattern(posFactory->getTriple(stack.top().s, stack.top().p, n));
		}
		    break;
		case PROPERTY:
		    break;
		default:
		    varError("unexpected state %d", stack.top().expect);
		}
		if (chars.size() > 0 && chars.find_first_not_of(" \t\n") != std::string::npos)
		    varError("unexpected characters \"%s\" within %s (nested state: %s)", chars.c_str(), qName.c_str(), stack.top().stateStr());
		//std::cout << "</" << qName.c_str() << ">" << std::endl << dumpStack();
	    }
	    virtual void characters (const char ch[],
				     int start,
				     int length, 
				     NSmap& /* nsz */) {
		chars += std::string(ch + start, length);
	    }
	};

    protected:
	POSFactory* posFactory;
	SWSAXparser* saxParser;

    public:
	RdfXmlParser (POSFactory* posFactory, SWSAXparser* saxParser) : ParserDriver(""), posFactory(posFactory), saxParser(saxParser) {  }
	void parse (BasicGraphPattern* bgp, StreamPtr* sptr) {
	    RdfXmlSaxHandler handler(bgp, posFactory);
	    saxParser->parse(sptr, &handler);
	}
	void parse (BasicGraphPattern* bgp, std::istream& istr) {
	    RdfXmlSaxHandler handler(bgp, posFactory);
	    saxParser->parse(istr, &handler);
	}

    };

} // namespace w3c_sw

#endif // !RDF_XML_PARSER_H

