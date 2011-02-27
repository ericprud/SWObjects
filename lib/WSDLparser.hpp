/* WSDLparser - SWSaxHandler to parse WSDL 2
 * $Id: WSDLparser.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef WSDL_PARSER_H
#define WSDL_PARSER_H

#include "RdfDB.hpp"
#include "QueryMapper.hpp"
#include "ParserCommon.hpp"
#include "../interface/SAXparser.hpp"
#include "MapSetParser/MapSetParser.hpp"

namespace w3c_sw {

    struct ServiceDescription {
	MapSet* ms;
    };

    class WSDLparser : public ParserDriver { // !!! doesn't respect setBase API
	class ContentModelSAXhandler : public SWSAXhandler {
// 	protected:
// 	    struct Element {
// 		std::string uri;
// 		std::string localName;
// 		Element (std::string uri, std::string localName)
// 		    : uri(uri), localName(localName)
// 		{  }
// 	    }; 
// 	    class AllowedElements : public std::map<Element, int> {
// 	    };
// 	    class ContentModel : public std::map<Element, AllowedElements> {
// 	    };
// 	    ContentModel& m;
// 	    ContentModelSAXhandler (ContentModel& m) : m(m) {  }
	};
	class WSDLSaxHandler : public ContentModelSAXhandler {
	protected:
	    enum NestedIn {S_ERROR, S_EMPTY, S_DOCUMENT,
			   S_binding, S_binding_operation, S_definitions, S_documentation,
			   S_message, S_operationInput, S_operationOutput,
			   S_portType, S_portType_operation,
			   S_service, S_service_port};
	    struct State {
		enum NestedIn nestedIn;
		const char* stateStr () const {
		    static const char* stateStrs[] =
			{"ERROR", "EMPTY", "DOCUMENT",
			 "binding", "binding_operation", "definitions", "documentation",
			 "message", "operationInput", "operationOutput",
			 "portType", "portType_operation",
			 "service", "service_port"};
		    return stateStrs[nestedIn];
		}
		std::string toString () const {
		    std::stringstream ret;
		    ret << 
			"{ " << stateStr() << 
			"}" << std::endl;
		    return ret.str();
		}
	    };

	    ServiceDescription* sd;
	    AtomFactory* atomFactory;
	    std::string baseURI;
	    std::string chars;
	    bool expectCharData;
	    const URI* datatype;
	    LANGTAG* langtag;
	    std::stack<State> stack;
	    TTerm::String2BNode bnodeMap;
	    std::string head, body, targetNamespace, opName;

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
	    WSDLSaxHandler (ServiceDescription* sd, std::string baseURI, AtomFactory* atomFactory)
		: sd(sd), atomFactory(atomFactory), baseURI(baseURI), chars("") {
		State newState = {S_DOCUMENT};
		stack.push(newState);
	    }

	    virtual void startElement (std::string uri,
				       std::string localName,
				       std::string qName,
				       Attributes* attrs, 
				       NSmap& /* nsz */) {
		State newState = {S_ERROR};
		NestedIn p = stack.top().nestedIn;
		std::string c = uri + ' ' + localName;
		if (p == S_DOCUMENT && c == "http://schemas.xmlsoap.org/wsdl/ definitions") {
		    targetNamespace = attrs->getValue("", "targetNamespace");
		    newState.nestedIn = S_definitions;
		} else if (p == S_definitions && c == "http://schemas.xmlsoap.org/wsdl/ documentation") {
		    newState.nestedIn = S_documentation;
		} else if (p == S_definitions && c == "http://schemas.xmlsoap.org/wsdl/ types") {
		    throw std::string("write a bridge to the schema parser");
		} else if (p == S_definitions && c == "http://schemas.xmlsoap.org/wsdl/ message") {
		    newState.nestedIn = S_message;
		} else if (p == S_message && c == "http://schemas.xmlsoap.org/wsdl/ part") {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_definitions && c == "http://schemas.xmlsoap.org/wsdl/ portType") {
		    newState.nestedIn = S_portType;
		} else if (p == S_portType && c == "http://schemas.xmlsoap.org/wsdl/ operation") {
		    opName = attrs->getValue("", "name");
		    newState.nestedIn = S_portType_operation;
		} else if (p == S_portType_operation && c == "http://schemas.xmlsoap.org/wsdl/ input") {
		    body = attrs->getValue("http://dev.w3.org/cvsweb/perl/modules/W3C/SPDL/", "SPAT");
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_portType_operation && c == "http://schemas.xmlsoap.org/wsdl/ output") {
		    head = attrs->getValue("http://dev.w3.org/cvsweb/perl/modules/W3C/SPDL/", "SPAT");
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_definitions && c == "http://schemas.xmlsoap.org/wsdl/ binding") {
		    newState.nestedIn = S_binding;
		} else if (p == S_binding && c == "http://schemas.xmlsoap.org/wsdl/soap/ binding") {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding && c == "http://schemas.xmlsoap.org/wsdl/ operation") {
		    newState.nestedIn = S_binding_operation;
		} else if (p == S_binding_operation && c == "http://schemas.xmlsoap.org/wsdl/soap/ operation") {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding_operation && c == "http://schemas.xmlsoap.org/wsdl/ input") {
		    newState.nestedIn = S_operationInput;
		} else if (p == S_operationInput && c == "http://schemas.xmlsoap.org/wsdl/soap/ body") {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding_operation && c == "http://schemas.xmlsoap.org/wsdl/ output") {
		    newState.nestedIn = S_operationOutput;
		} else if (p == S_operationOutput && c == "http://schemas.xmlsoap.org/wsdl/soap/ body") {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_definitions && c == "http://schemas.xmlsoap.org/wsdl/ service") {
		    newState.nestedIn = S_service;
		} else if (p == S_service && c == "http://schemas.xmlsoap.org/wsdl/ port") {
		    newState.nestedIn = S_service_port;
		} else if (p == S_service_port && c == "http://schemas.xmlsoap.org/wsdl/soap/ address") {
		    newState.nestedIn = S_EMPTY;
		} else
		    varError("unexpected %s within %s", c.c_str(), stack.top().stateStr());
		stack.push(newState);
		chars = "";
		//std::cout << "<" << qName.c_str() << ">" << std::endl << dumpStack();
	    }

	    virtual void endElement (std::string,
				     std::string,
				     std::string qName, 
				     NSmap& nsz) {
		State nestedState = stack.top();
		stack.pop();
		switch (nestedState.nestedIn) {
		case S_documentation:
		    chars.resize(0);
		    break;
		case S_portType_operation:
		    if (!head.empty() || !body.empty()) {
			std::stringstream ss;
			ss << "LABEL <" << targetNamespace << opName << "> CONSTRUCT {" << head << "} WHERE {" << body << "}";
			std::set<std::string> prefixes = nsz.keys();
			MapSetDriver sp(baseURI, atomFactory);
			for (std::set<std::string>::const_iterator it = prefixes.begin();
			     it != prefixes.end(); ++it)
			    sp.addPrefix(*it, atomFactory->getURI(nsz[*it]));
			sp.parse(ss.str());
			sd->ms = dynamic_cast<MapSet*>(sp.root);
		    }
		default:
		    break;
		    // varError("unexpected state %d", stack.top().nestedIn);
		}
		if (chars.size() > 0 && chars.find_first_not_of(" \t\n") != std::string::npos)
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
	WSDLparser (std::string baseURI, AtomFactory* atomFactory, SWSAXparser* saxParser)
	    : ParserDriver(baseURI), atomFactory(atomFactory), saxParser(saxParser) {  }
	bool parse (ServiceDescription* sd, IStreamContext& sptr) {
	    WSDLSaxHandler handler(sd, baseURI, atomFactory);
	    return saxParser->parse(sptr, &handler);
	}

    };

} // namespace w3c_sw

#endif // !WSDL_PARSER_H

