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

#define NS_wsdl11 "http://schemas.xmlsoap.org/wsdl/"
#define NS_wsdlsoap "http://schemas.xmlsoap.org/wsdl/soap/"
#define NS_wsdlhttp "http://schemas.xmlsoap.org/wsdl/http/"
#define NS_spdl "http://dev.w3.org/cvsweb/perl/modules/W3C/SPDL/"

namespace w3c_sw {

    struct ServiceDescription { // 2.0 model:
	typedef SWSAXhandler::QName QName;
	typedef enum {M_GET, M_POST, M_PUT, M_DELETE} HTTPmethod;
	typedef enum {S_LITERAL, S_urlencoded} Encoding;
	typedef enum {P_InOut} Pattern;
	typedef enum {SOAP_10, SOAP_11} Protocol;
	struct Endpoint {
	    QName service, binding, operation;
	    std::string endpoint;
	    Endpoint (QName service, QName binding, QName operation, std::string endpoint)
		: service(service), binding(binding), operation(operation), endpoint(endpoint)
	    {  }
	    virtual bool operator==(const Endpoint& ref) const = 0;
	    bool _eq (const Endpoint* p) const {
		return service == p->service
		    && binding == p->binding
		    && operation == p->operation
		    && endpoint == p->endpoint;
	    }
	    std::string _toString () const {
		std::stringstream ss;
		ss
		    << "service: " << service
		    << " binding: " << binding
		    << " operation: " << operation
		    << " endpoint: " << endpoint;
		return ss.str();
	    }
	    virtual std::string toString() const = 0;
	};
	struct HTTPEndpoint : public Endpoint {
	    std::string methodDefault;
	    std::map<HTTPmethod, Encoding> inputSerializations;
	    HTTPEndpoint (QName service, QName binding, QName operation, std::string endpoint, std::string methodDefault)
		: Endpoint(service, binding, operation, endpoint), methodDefault(methodDefault)
	    {  }
	    virtual bool operator== (const Endpoint& ref) const {
		const HTTPEndpoint* p = dynamic_cast<const HTTPEndpoint*>(&ref);
		if (p == NULL)
		    return false;
		return Endpoint::_eq(p) && methodDefault == p->methodDefault;
	    }
	    virtual std::string toString () const {
		return _toString() + " methodDefault: " + methodDefault;
	    }
	};
	struct SoapEndpoint : public Endpoint {
	    Protocol protocol;
	    SoapEndpoint (QName service, QName binding, QName operation, std::string endpoint, Protocol protocol)
		: Endpoint(service, binding, operation, endpoint), protocol(protocol)
	    {  }
	    virtual bool operator== (const Endpoint& ref) const {
		const SoapEndpoint* p = dynamic_cast<const SoapEndpoint*>(&ref);
		if (p == NULL)
		    return false;
		return Endpoint::_eq(p) && protocol == p->protocol;
	    }
	    virtual std::string toString () const {
		std::stringstream ss;
		ss << _toString() << " protocol: " << protocol;
		return ss.str();
	    }
	};
	struct Operation {
// 	    struct IO {
// 		QName label, element;
// 		IO (QName label, QName element)
// 		    : label(label), element(element)
// 		{  }
// 	    };
// 	    Ignore the label for now. (What would we do with it?)
	    QName name;
	    Pattern pattern;
// 	    IO in, out;
	    QName in, out;
	    QName interface;
	    std::set<boost::shared_ptr<Endpoint> > endpoints;
	    Operation (QName name, Pattern pattern, QName in, QName out, QName interface)
		: name(name), pattern(pattern), in(in), out(out), interface(interface)
	    {  }
	    bool operator== (const Operation& ref) const {
		if (!(name == ref.name &&
		      pattern == ref.pattern &&
		      in == ref.in &&
		      out == ref.out &&
		      interface == ref.interface))
		    return false;

		if (endpoints.size() != ref.endpoints.size())
		    return false;
		std::set<boost::shared_ptr<Endpoint> >::const_iterator mit = endpoints.begin();
		std::set<boost::shared_ptr<Endpoint> >::const_iterator rit = ref.endpoints.begin();
		for ( ; mit != endpoints.end(); ++mit, ++rit)
		    if ( !(**mit == **rit))
			return false;
		return true;
	    }
	    std::string toString () const {
		std::stringstream ss;
		ss
		    << "name: " << name
		    << " pattern: " << pattern
		    << " in: " << in
		    << " out: " << out
		    << " interface: " << interface
		    << std::endl;
		for (std::set<boost::shared_ptr<Endpoint> >::const_iterator it = endpoints.begin();
		     it != endpoints.end(); ++it)
		    ss << "  " << (*it)->toString() << std::endl;
		return ss.str();
	    }
	};

	MapSet* ms;
	typedef std::map<QName, Operation> OperationMap;
	OperationMap operations;
	bool operator== (const ServiceDescription& ref) const {
	    if (ms && ref.ms) {
		if (ms && !(*ms == *ref.ms))
		    return false;
	    } else if (ms != ref.ms)
		return false;
	    if (operations.size() != ref.operations.size())
		return false;
	    OperationMap::const_iterator mit = operations.begin();
	    OperationMap::const_iterator rit = ref.operations.begin();
	    for ( ; mit != operations.end(); ++mit, ++rit)
		if ( !(*mit == *rit))
		    return false;
	    return true;
	}
	std::string toString () const {
	    std::stringstream ss;
	    ss << ms->toString();
	    for (OperationMap::const_iterator it = operations.begin();
		 it != operations.end(); ++it)
		ss << it->first << " -> {" << it->second.toString() << "}\n";
	    return ss.str();
	}
	void addOperation (QName name, Pattern pattern, QName in, QName out, QName interface) {
	    operations.insert
		(std::pair<QName, ServiceDescription::Operation>
		 (name, ServiceDescription::Operation
		  (name, pattern, in, out, interface)));
	}
	void addEndpoint (boost::shared_ptr<ServiceDescription::Endpoint> endpoint) {
	    QName key = endpoint->operation;
	    OperationMap::iterator it
		= operations.find(key);
	    if (it == operations.end()) {
		std::stringstream ss;
		ss << "failed to find " << key << " in ";
		for (OperationMap::const_iterator it = operations.begin();
		     it != operations.end(); ++it)
		    ss << it->first << "->" << it->second.toString() << std::endl;
		ss << "\n";
		throw ss.str();
	    }
	    it->second.endpoints.insert(endpoint);
	}
	void addHTTPEndpoint (QName service, QName binding, QName operation,
			      std::string endpoint, std::string methodDefault) {
	    addEndpoint
		(
		 boost::make_shared<ServiceDescription::HTTPEndpoint>
		 (ServiceDescription::HTTPEndpoint
		  (service, binding, operation, endpoint, methodDefault
		   )));
	}
	void addSoapEndpoint (QName service, QName binding, QName operation,
			      std::string endpoint, Protocol protocol) {
	    addEndpoint
		(
		 boost::make_shared<ServiceDescription::SoapEndpoint>
		 (ServiceDescription::SoapEndpoint
		  (service, binding, operation, endpoint, protocol
		   )));
	}
    };
    inline std::ostream& operator<< (std::ostream& os, const ServiceDescription& my) {
	os << my.toString();
	return os;
    }

    // 1.1 parser (so far)
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
			   S_definitions, S_documentation, S_types, 
			   S_message, S_portType, S_portType_operation,
			   S_binding, S_binding_operation,
			   S_operationInput, S_operationOutput,
			   S_service, S_service_port};
	    struct State {
		enum NestedIn nestedIn;
		const char* stateStr () const {
		    static const char* stateStrs[] =
			{"ERROR", "EMPTY", "DOCUMENT",
			 "definitions", "documentation", "types", 
			 "message", "portType", "portType/operation",
			 "binding", "binding/operation",
			 "binding/operation/input", "binding/operation/output",
			 "service", "service/port"};
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
	    std::stack<State> stack;
	    std::string head, body, targetNamespace;
	    QName opName;
	    QName inMessage;

	    struct M2E : public std::map<QName, QName> {
		typedef std::pair<QName, QName> Pair;
		void insert1 (QName m, QName e) {
		    insert(Pair(m, e));
		}
		std::map<QName, QName>::const_iterator find1 (QName key) {
		    std::map<QName, QName>::const_iterator ret = find(key);
		    if ((ret == end())) {
			std::stringstream ss;
			ss << "failed to find " << key << " in ";
			for (M2E::const_iterator it = begin();
			     it != end(); ++it)
			    ss << it->first << "->" << it->second << std::endl;
			ss << "\n";
			throw ss.str();
		    }
		    return ret;
		}
	    };
	    M2E message2element;
	    QName ifaceName, inputMessage, outputMessage, bindingName;;

	    struct BindingInfo {
		QName operation;
		typedef enum {T_UNKNOWN, T_HTTP, T_SOAP} Type;
		// http://www.w3.org/ns/wsdl/http
		// http://www.w3.org/ns/wsdl/soap
		Type type;
		std::string soapProtocol;
	    };
	    std::map<QName, BindingInfo> bindings;
	    QName serviceName, portName;

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
				       NSmap& nsz) {
		State newState = {S_ERROR};
		NestedIn p = stack.top().nestedIn;
		QName c(uri, localName);
		if (p == S_DOCUMENT && c == QName(NS_wsdl11, "definitions")) {
		    targetNamespace = attrs->getValue("", "targetNamespace");
		    newState.nestedIn = S_definitions;
		} else if (p == S_definitions && c == QName(NS_wsdl11, "documentation")) {
		    newState.nestedIn = S_documentation;
		} else if (p == S_definitions && c == QName(NS_wsdl11, "types")) {
		    std::cerr << std::string("Write a bridge to the schema parser, slacker!");
		    newState.nestedIn = S_types;
		} else if (p == S_types) {
		    newState.nestedIn = S_types;
		} else if (p == S_definitions && c == QName(NS_wsdl11, "message")) {
		    inMessage = QName(targetNamespace, attrs->getValue("", "name"));
		    newState.nestedIn = S_message;
		} else if (p == S_message && c == QName(NS_wsdl11, "part")) {
		    message2element.insert1(inMessage, QName(attrs->getValue("", "element"), nsz));
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_definitions && c == QName(NS_wsdl11, "portType")) {
		    ifaceName = QName(targetNamespace, attrs->getValue("", "name"));
		    newState.nestedIn = S_portType;
		} else if (p == S_portType && c == QName(NS_wsdl11, "operation")) {
		    opName = QName(targetNamespace, attrs->getValue("", "name"));
		    newState.nestedIn = S_portType_operation;
		} else if (p == S_portType_operation && c == QName(NS_wsdl11, "input")) {
		    inputMessage = QName(attrs->getValue("", "message"), nsz);
		    body = attrs->getValue(NS_spdl, "SPAT");
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_portType_operation && c == QName(NS_wsdl11, "output")) {
		    outputMessage = QName(attrs->getValue("", "message"), nsz);
		    head = attrs->getValue(NS_spdl, "SPAT");
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_definitions && c == QName(NS_wsdl11, "binding")) {
		    bindingName = QName(targetNamespace, attrs->getValue("", "name"));
		    bindings[bindingName].type = BindingInfo::T_UNKNOWN;
		    bindings[bindingName].soapProtocol = "~http~";
		    newState.nestedIn = S_binding;
		} else if (p == S_binding && c == QName(NS_wsdlsoap, "binding")) {
		    bindings[bindingName].type = BindingInfo::T_SOAP;
		    std::string p = attrs->getValue("", "transport");
		    bindings[bindingName].soapProtocol
			= p == "http://schemas.xmlsoap.org/soap/http"
			? "http://www.w3.org/2006/01/soap11/bindings/HTTP/"
			: p;
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding && c == QName(NS_wsdlhttp, "binding")) {
		    bindings[bindingName].type = BindingInfo::T_HTTP;
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding && c == QName(NS_wsdl11, "operation")) {
		    bindings[bindingName].operation = QName(targetNamespace, attrs->getValue("", "name"));
		    newState.nestedIn = S_binding_operation;
		} else if (p == S_binding_operation && c == QName(NS_wsdlsoap, "operation")) {
		    // What would we do with @soapAction ?
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding_operation && c == QName(NS_wsdl11, "input")) {
		    newState.nestedIn = S_operationInput;
		} else if (p == S_operationInput && c == QName(NS_wsdlsoap, "body")) {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_binding_operation && c == QName(NS_wsdl11, "output")) {
		    newState.nestedIn = S_operationOutput;
		} else if (p == S_operationOutput && c == QName(NS_wsdlsoap, "body")) {
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_definitions && c == QName(NS_wsdl11, "service")) {
		    serviceName = QName(targetNamespace, attrs->getValue("", "name"));
		    newState.nestedIn = S_service;
		} else if (p == S_service && c == QName(NS_wsdl11, "port")) {
		    portName = QName(targetNamespace, attrs->getValue("", "name"));
		    bindingName = QName(attrs->getValue("", "binding"), nsz);
		    newState.nestedIn = S_service_port;
		} else if (p == S_service_port && c == QName(NS_wsdlsoap, "address")) {
		    assert(bindings[bindingName].type = BindingInfo::T_SOAP);
		    std::string address = attrs->getValue("", "location");
		    // What do we do with bindings[bindingName].soapProtocol ? 
		    sd->addSoapEndpoint(serviceName, bindingName,
					bindings[bindingName].operation,
					address, ServiceDescription::SOAP_11);
		    newState.nestedIn = S_EMPTY;
		} else if (p == S_service_port && c == QName(NS_wsdlhttp, "@@??")) {
		    /** Still need to suss out WSDL 1.0 structure for HTTP bindings. */
		    assert(bindings[bindingName].type = BindingInfo::T_HTTP);
		    std::string address = attrs->getValue("", "@@location");
		    sd->addHTTPEndpoint(serviceName, bindingName,
					bindings[bindingName].operation,
					address, "@@methodDefault");
		    newState.nestedIn = S_EMPTY;
		} else
		    varError("unexpected %s within %s", c.asURI().c_str(), stack.top().stateStr());
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
		    /**
		     * Work through the above states in reverse order to follow the order that tags are closed.
		     */
		case S_service_port:
		    portName.reset();
		    break;
		case S_service:
		    serviceName.reset();
		    break;
		case S_binding:
		    bindingName.reset();
		    break;
		case S_portType_operation: {

		    QName inElt = message2element.find1(inputMessage)->second;
		    QName outElt = message2element.find1(outputMessage)->second;
		    sd->operations.insert(std::pair<QName, ServiceDescription::Operation>
					  (opName, ServiceDescription::Operation(opName, ServiceDescription::P_InOut, inElt, outElt, ifaceName)));
		    if (!head.empty() || !body.empty()) {
			std::stringstream ss;
			ss << "LABEL <" << opName.asURI() << "> CONSTRUCT {" << head << "} WHERE {" << body << "}";
			std::set<std::string> prefixes = nsz.keys();
			MapSetDriver sp(baseURI, atomFactory);
			for (std::set<std::string>::const_iterator it = prefixes.begin();
			     it != prefixes.end(); ++it)
			    sp.addPrefix(*it, atomFactory->getURI(nsz[*it]));
			sp.parse(ss.str());
			sd->ms = dynamic_cast<MapSet*>(sp.root);
		    }
		    ifaceName.reset();
		}
		case S_portType:
		    ifaceName.reset();
		    break;
		case S_message:
		    inMessage.reset();
		    break;
		case S_documentation:
		    chars.resize(0);
		    break;
		default:
		    break;
		    // varError("unexpected state %d", stack.top().nestedIn);
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

