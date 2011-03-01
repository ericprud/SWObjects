/* RDFaParser - SWSaxHandler to parse RDF/XML
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef RDFA_PARSER_H
#define RDFA_PARSER_H

#include "RdfDB.hpp"
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class RDFaParser : public ParserDriver { // !!! doesn't respect setBase API
	class RDFaSaxHandler : public SWSAXhandler {
	protected:
	    struct State {
		bool inHead;
		std::string baseURI;
		const TTerm* about;
		const TTerm* rel;
		const TTerm* property;
		const URI* datatype;
		std::string langtag;
		State () : inHead(false), baseURI(""), about(NULL), rel(NULL), property(NULL), datatype(NULL), langtag("") {  }
		std::string toString () const {
		    std::stringstream ret;
		    ret << 
			"{ " << 
			"	baseURI: "  <<                              baseURI               << 
			"	about: "    << (about	 == NULL ? "NULL" : about   ->toString()) << 
			"	rel: "	    << (rel	 == NULL ? "NULL" : rel	    ->toString()) << 
			"	property: " << (property == NULL ? "NULL" : property->toString()) << 
			"	datatype: " << (datatype == NULL ? "NULL" : datatype->toString()) << 
			"	langtag: "  <<                              langtag               << 
			"}" << std::endl;
		    return ret.str();
		}
	    };

	    BasicGraphPattern* bgp;
	    AtomFactory* atomFactory;
	    std::string chars;
	    std::stack<State> stack;
	    GRDDLmap* grddlMap;

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

	    const URI* _relativeURI (std::string rel, std::string base) {
		std::string abs(libwww::HTParse(rel, base.empty() ? NULL : &base, libwww::PARSE_all));
		return atomFactory->getURI(abs.c_str());
	    }

	    const URI* _QnameToURI (std::string qname, NSmap& map) {
		return atomFactory->getURI(QName(qname, map).asURI());
	    }

	public:
	    RDFaSaxHandler (BasicGraphPattern* bgp, AtomFactory* atomFactory, std::string baseURI = "", GRDDLmap* grddlMap = NULL) : 
		bgp(bgp), atomFactory(atomFactory), chars(""), grddlMap(grddlMap) {
		State topState;
		topState.baseURI = baseURI;
		stack.push(topState);
	    }

	    virtual void startElement (std::string uri,
				       std::string localName,
				       std::string /* qName */,
				       Attributes* attrs, 
				       NSmap& nsz) {
		State parent = stack.top();
		State nested;
		nested.inHead = localName == "head";
		nested.rel = parent.rel;

		std::string t;

		if (grddlMap != NULL)
		    grddlMap->maybeChangeMediaType(uri, localName);
		std::string trans = attrs->getValue(NS_grddl, "transformation");
		if (!trans.empty()) {
		    std::vector<std::string> args;
		    args.push_back(trans);
		    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
			<< "GRDDL attribute transformation encountered -- GRDDLing with stylesheet \""
			<< trans << "\".";
		    throw ChangeMediaTypeException("application/rdf+xml", args);
		}
		if (stack.top().inHead && localName == "link" && attrs->getValue("", "rel") == "transformation") {
		    std::vector<std::string> args;
		    args.push_back(attrs->getValue("", "href"));
		    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
			<< "GRDDL link header rel=\"transformation\" encountered -- GRDDLing with stylesheet \""
			<< attrs->getValue("", "href") << "\".";
		    throw ChangeMediaTypeException("application/rdf+xml", args);
		    bgp->addTriplePattern(atomFactory->
					  getTriple(atomFactory->getURI(nested.baseURI), 
						    atomFactory->getURI(std::string(NS_dc) + "TRANS"), 
						    atomFactory->getRDFLiteral(attrs->getValue("", "href"), 
									      NULL, 
									      nested.langtag.empty() ? NULL : 
									      new LANGTAG(nested.langtag))));
		}

		t = attrs->getValue("", "lang");
		if (t.empty())
		    t = attrs->getValue(NS_xml, "lang");
		nested.langtag = 
		    t.empty() ? parent.langtag : t;

		t = attrs->getValue("", "base");
		if (t.empty())
		    t = attrs->getValue(NS_xml, "base");
		nested.baseURI = 
		    t.empty() ? parent.baseURI : t;

		t = attrs->getValue("", "datatype");
		nested.datatype = t.empty() ? NULL : _QnameToURI(t, nsz);

		t = attrs->getValue("", "about");
		if (!t.empty())
		    nested.about = _relativeURI(t, nested.baseURI);

		t = attrs->getValue("", "typeof");
		if (!t.empty()) {
		    if (nested.about == NULL)
			nested.about = atomFactory->createBNode();
		    bgp->addTriplePattern(atomFactory->getTriple(nested.about, 
				atomFactory->getURI(std::string(NS_rdf) + "type"), 
								_QnameToURI(t, nsz)));
		}

		t = attrs->getValue("", "rel");
		if (!t.empty() && localName != "link") {  // link tags have a conflicting semantics for @rel.
		    nested.rel = _QnameToURI(t, nsz);
		    t = attrs->getValue("", "href");
		    if (!t.empty()) {
			if (parent.about)
			    bgp->addTriplePattern(atomFactory->getTriple(parent.about, 
									nested.rel, 
									_relativeURI(t, nested.baseURI)));
			nested.rel = NULL;
		    }
		}

		if (nested.about == NULL)
		    nested.about = parent.about;
		else if (parent.about != NULL && 
			 parent.rel != NULL)
		    bgp->addTriplePattern(atomFactory->getTriple(parent.about, 
								parent.rel, 
								nested.about));

		t = attrs->getValue("", "property");
		if (!t.empty()) {
		    nested.property = _QnameToURI(t, nsz);
		    t = attrs->getValue("", "content");
		    if (!t.empty()) {
			bgp->addTriplePattern(atomFactory->
				getTriple(parent.about, 
					  nested.property, 
					  atomFactory->getRDFLiteral(t, 
					    nested.datatype, 
					    nested.langtag.empty() ? NULL : 
					    new LANGTAG(nested.langtag))));
			nested.property = NULL;
		    }
		}

		stack.push(nested);
		chars = "";
		//std::cout << "<" << qName.c_str() << ">" << std::endl << dumpStack();
	    }
	    virtual void endElement (std::string,
				     std::string localName,
				     std::string, 
				     NSmap& /* nsz */) {
		State nested = stack.top();
		stack.pop();
		if (stack.top().inHead && localName == "title")
		    bgp->addTriplePattern(atomFactory->
				getTriple(atomFactory->getURI(nested.baseURI), 
					  atomFactory->getURI(std::string(NS_dc) + "title"), 
					  atomFactory->getRDFLiteral(chars, 
					    NULL, 
					    nested.langtag.empty() ? NULL : 
					    new LANGTAG(nested.langtag))));

		else if (nested.property) {
		    const TTerm* o = atomFactory->getRDFLiteral(chars, 
							     nested.datatype, 
							     nested.langtag.empty() ? NULL : new LANGTAG(nested.langtag));
		    chars = "";
		    bgp->addTriplePattern(atomFactory->getTriple(nested.about, nested.property, o));
		}
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
	AtomFactory* atomFactory;
	SWSAXparser* saxParser;
	GRDDLmap* grddlMap;

    public:
	RDFaParser (std::string baseURI, AtomFactory* atomFactory, SWSAXparser* saxParser, GRDDLmap* grddlMap = NULL) : 
	    ParserDriver(baseURI), atomFactory(atomFactory), saxParser(saxParser), grddlMap(grddlMap) {  }

	bool parse (BasicGraphPattern* bgp, IStreamContext& sptr) {
	    RDFaSaxHandler handler(bgp, atomFactory, this->baseURI, grddlMap);
	    return saxParser->parse(sptr, &handler);
	}

    };

} // namespace w3c_sw

#endif // !RDFA_PARSER_H

