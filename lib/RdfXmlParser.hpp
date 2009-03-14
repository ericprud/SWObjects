/* RdfXmlParser - SWSaxHandler to parse RDF/XML
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDF_XML_PARSER_H
#define RDF_XML_PARSER_H

#include "RdfDB.hpp"
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class RdfXmlParser {
	class RdfXmlSaxHandler : public SWSAXhandler {
	protected:
	    enum STATES {DOCUMENT, SUBJECT, PROPERTY, COLLECTION, s_ERROR};

	    BasicGraphPattern* bgp;
	    POSFactory* posFactory;
	    std::string baseURI;
	    std::string chars;
	    const URI* datatype;
	    LANGTAG* langtag;
	    std::stack<enum STATES> stateStack;
	    std::stack<const POS*> subjectStack;
	    std::stack<const POS*> predicateStack;

	    const char* stateStr () {
		static const char* stateStrs[] =
		    {"document", "subject", "property", "collection", "huh?"};
		return stateStrs[stateStack.top()];
	    }

	public:
	    RdfXmlSaxHandler (BasicGraphPattern* bgp, POSFactory* posFactory, std::string baseURI = "") : 
		bgp(bgp), posFactory(posFactory), baseURI(baseURI), chars("") {
		stateStack.push(DOCUMENT);
	    }

	    virtual void startElement (std::string uri,
				       std::string localName,
				       std::string qName,
				       Attributes* attrs) {
		enum STATES newState = s_ERROR;
		switch (stateStack.top()) {
		case DOCUMENT:
		    if (uri == NS_rdf && localName == "RDF") {
			newState = SUBJECT;
			break;
		    }
		case SUBJECT:
		case COLLECTION: {
		    const POS* node;
		    {
			/* subject comes from about or ID or is a BNode. */
			std::string subject;
			subject = attrs->getValue(NS_rdf, "about");
			if (subject.empty()) {
			    subject = attrs->getValue(NS_rdf, "ID");
			    if (subject.empty())
				node = posFactory->createBNode();
			    else
				node = posFactory->getURI(baseURI + "#" + subject);
			} else
			    node = posFactory->getURI(subject);
		    }
		    const POS* p = predicateStack.top();
		    if (p != NULL) {
			const POS* s = subjectStack.top();
			predicateStack.pop(); // replace predicate.
			if (stateStack.top() == COLLECTION) {
			    const POS* b = posFactory->createBNode();
			    const POS* f = posFactory->getURI(std::string(NS_rdf) + "first");
			    const POS* t = posFactory->getURI(std::string(NS_rdf) + "type");
				const POS* c = posFactory->getURI(std::string(NS_rdf) + "Collection");
			    bgp->addTriplePattern(posFactory->getTriple(s, p, b));
			    bgp->addTriplePattern(posFactory->getTriple(b, t, c));
			    bgp->addTriplePattern(posFactory->getTriple(b, f, node));
			    predicateStack.push(
				posFactory->getURI( std::string(NS_rdf) + "rest") );
			} else {
			    bgp->addTriplePattern(posFactory->getTriple(s, p, node));
			    predicateStack.push(NULL);
			}
		    }
		    if ( !(uri == NS_rdf && localName == "RDF") ) {
			const POS* p = posFactory->getURI(std::string(NS_rdf) + "type");
			const POS* t = posFactory->getURI(uri + localName);
			bgp->addTriplePattern(posFactory->getTriple(subjectStack.top(), p, t));
		    }
		    newState = PROPERTY;
		    subjectStack.push(node);
		    break;
		}
		case PROPERTY: {
		    std::string t; // used a couple times below
		    const POS* node = NULL;
		    const POS* pred = posFactory->getURI(uri + localName);
		    std::string parseType = attrs->getValue(NS_rdf, "parseType");

		    /* rdf:parseType or rdf:resource attributes imply a new node. */
		    t = attrs->getValue(NS_rdf, "resource");
		    if ( !t.empty() )
			node = posFactory->getURI(t);
		    else if ( !parseType.empty() )
			node = posFactory->createBNode();
		    if (node != NULL)
			bgp->addTriplePattern(posFactory->getTriple(subjectStack.top(), 
							    pred, node));

		    t = attrs->getValue(NS_xsd, "datatype");
		    datatype = t.empty() ? NULL : posFactory->getURI(t);
		    t = attrs->getValue(NS_xml, "lang");
		    langtag = t.empty() ? NULL : new LANGTAG(t.c_str());

		    for (size_t i = 0; i < attrs->getLength(); ++i) {
			std::string attrURI = attrs->getURI(i);
			std::string attrLName = attrs->getLocalName(i);
			/* Create statements for unknown attributes */
			if ( !(attrURI == NS_rdf && attrLName == "parseType") && 
			     !(attrURI == NS_rdf && attrLName == "resource") && 
			     !(attrURI == NS_xsd && attrLName == "datatype") && 
			     !(attrURI == NS_xml && attrLName == "lang")) {
			    if (node == NULL)
				node = posFactory->createBNode();
			    const POS* predicate = posFactory->getURI(attrURI + attrLName);
			    std::string value = attrs->getValue(attrURI, attrLName);
			    const POS* object = posFactory->getRDFLiteral(value, NULL, NULL);
			    bgp->addTriplePattern(posFactory->getTriple(node, predicate, object));
			}
		    }

		    /* Nested state depends souly on parseType. */
		    newState = 
			parseType == "Collection" ? COLLECTION : 
			parseType == "Resource" ? PROPERTY : 
			SUBJECT;

		    subjectStack.push(node);
		    predicateStack.push(pred);
		    break;
		}
		default:
		    error("unexpected element %s within %s", qName.c_str(), stateStr());
		}
		if (newState == s_ERROR)
		    error("unexpected element %s within %s", qName.c_str(), stateStr());
		stateStack.push(newState);
		chars = "";
	    }
	    virtual void endElement (std::string,
				     std::string,
				     std::string) {
		switch (stateStack.top()) {
		case DOCUMENT:
		case SUBJECT:
		case COLLECTION: {
		    subjectStack.pop();
		    break;
		}
		case PROPERTY: {
		    if ( !chars.empty() ) {
			const POS* s = subjectStack.top();
			const POS* p = predicateStack.top();
			const POS* o = posFactory->getRDFLiteral(chars, datatype, langtag);
			chars = "";
			bgp->addTriplePattern(posFactory->getTriple(s, p, o));
		    }
		    subjectStack.pop();
		    predicateStack.pop();
		    break;
		}
		default:
		    error("unexpected state %d", stateStack.top());
		}
		if (chars.size() > 0 && chars.find_first_not_of(" \t\n") != std::string::npos)
		    error("unexpected characters %s within %s", chars.c_str(), stateStr());
		stateStack.pop();
	    }
	    virtual void characters (const char ch[],
				     int start,
				     int length) {
		chars += std::string(ch + start, length);
	    }
	};

    protected:
	POSFactory* posFactory;
	SWSAXparser* saxParser;

    public:
	RdfXmlParser (POSFactory* posFactory, SWSAXparser* saxParser) : posFactory(posFactory), saxParser(saxParser) {  }
	void parse (BasicGraphPattern* bgp, const char* filename) {
	    RdfXmlSaxHandler handler(bgp, posFactory);
	    saxParser->parse(filename, &handler);
	}
	void parse (BasicGraphPattern* bgp, std::string::iterator begin, std::string::iterator end) {
	    RdfXmlSaxHandler handler(bgp, posFactory);
	    saxParser->parse(begin, end, &handler);
	}

    };

} // namespace w3c_sw

#endif // !RDF_XML_PARSER_H

