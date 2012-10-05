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

	    virtual void setBase (std::string base) { stack.top().baseURI = base; }

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
		if (attrs->value(NS_grddl, "transformation", &t)) {
		    std::vector<std::string> args;
		    args.push_back(t);
		    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
			<< "GRDDL attribute transformation encountered -- GRDDLing with stylesheet \""
			<< t << "\".";
		    throw ChangeMediaTypeException("application/rdf+xml", args);
		}
		if (stack.top().inHead && localName == "link" &&
		    attrs->value("", "rel", &t) && t == "transformation") {
		    std::vector<std::string> args;
		    attrs->value("", "href", &t);
		    args.push_back(t);
		    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
			<< "GRDDL link header rel=\"transformation\" encountered -- GRDDLing with stylesheet \""
			<< t << "\".";
		    throw ChangeMediaTypeException("application/rdf+xml", args);
		    attrs->value("", "href", &t);
		    bgp->addTriplePattern(atomFactory->
					  getTriple(atomFactory->getURI(nested.baseURI), 
						    atomFactory->getURI(std::string(NS_dc) + "TRANS"), 
						    atomFactory->getRDFLiteral(t, 
									       NULL, 
									       nested.langtag.empty() ? NULL : 
									       new LANGTAG(nested.langtag))));
		}

		if (!attrs->value("", "lang", &nested.langtag) &&
		    !attrs->value(NS_xml, "lang", &nested.langtag))
		    nested.langtag = parent.langtag;

		if (!attrs->value("", "base", &nested.baseURI) &&
		    !attrs->value(NS_xml, "base", &nested.baseURI))
		    nested.baseURI = parent.baseURI;

		if (attrs->value("", "datatype", &t))
		    nested.datatype = _QnameToURI(t, nsz);
		else
		    nested.datatype = NULL;

		if (attrs->value("", "about", &t))
		    nested.about = _relativeURI(t, nested.baseURI);

		if (attrs->value("", "typeof", &t)) {
		    if (nested.about == NULL)
			nested.about = atomFactory->createBNode();
		    bgp->addTriplePattern(atomFactory->getTriple(nested.about, 
				atomFactory->getURI(std::string(NS_rdf) + "type"), 
								_QnameToURI(t, nsz)));
		}

		if (attrs->value("", "rel", &t) && localName != "link") { 
		    // link tags have a conflicting semantics for @rel.
		    nested.rel = _QnameToURI(t, nsz);
		    if (attrs->value("", "href", &t)) {
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

		if (attrs->value("", "property", &t)) {
		    nested.property = _QnameToURI(t, nsz);
		    if (attrs->value("", "content", &t)) {
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

