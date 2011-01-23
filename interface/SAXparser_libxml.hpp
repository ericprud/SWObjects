/* SAXparser_libxml.hpp: implementation of SWSAXparser for libxml.
 * interface per http://xmlsoft.org/html/libxml-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once
#include <string.h>
#include <map>
#include <libxml/parser.h>
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class SAXparser_libxml : public NSdInsulatedSAXparser {
    protected:
	struct NsSet {
	    const char* namespaceURI;
	    const char* localName;
	    const char* prefix;
	    NsSet (const char* namespaceURI, const char* localName, const char* prefix) :
		namespaceURI(namespaceURI), localName(localName), prefix(prefix) {  }
	};
	class Attributes_libxml : public SWSAXhandler::Attributes {
	protected:
	    const xmlChar ** attrs;
	    size_t attrCount;
	    std::vector<NsSet> byIndex;
	    std::map<std::string, std::map<std::string, std::string> > byNS_localName;
	    bool initialized;
	    void init () {
		unsigned int index = 0;
		for (size_t i = 0; i < attrCount; ++i, index += 5) {
		    const char* lname = (const char*)attrs[index];
		    const char* prefix = (const char*)attrs[index+1];
		    const char* namespaceURI = (const char*)attrs[index+2];
		    std::string value((const char *)attrs[index+3], (const char *)attrs[index+4]);

		    byIndex.push_back(NsSet(namespaceURI ? namespaceURI : "", lname, prefix ? prefix : ""));
		    byNS_localName[namespaceURI ? namespaceURI : ""][lname] = value;
		}
		initialized = true;
	    }
	public:
	    Attributes_libxml (const xmlChar ** attrs, size_t attrCount) : 
		attrs(attrs), attrCount(attrCount), initialized(false) {  }
	    virtual size_t getLength () { if (!initialized) init(); return byIndex.size(); }
	    virtual std::string getURI (size_t i) { if (!initialized) init(); return byIndex[i].namespaceURI; }
	    virtual std::string getLocalName (size_t i) { if (!initialized) init(); return byIndex[i].localName; }
	    virtual std::string getQName (size_t i) { if (!initialized) init(); return SWSAXhandler::qName(byIndex[i].prefix, byIndex[i].localName); }
	    virtual std::string getValue (std::string uri, std::string localName) { if (!initialized) init(); return byNS_localName[uri][localName]; }
	};

	::xmlSAXHandler libXMLhandler; // http://xmlsoft.org/html/libxml-tree.html#xmlSAXHandler
	
	/* @TODO
	virtual void handleError (std::string& e) {
	    InsulatedSAXparser::handleError(e);
	    xmlStopParser(contxt);
	}

	  xml_context = xmlCreateFileParserCtxt(filename.c_str());
	  xmlSAXHandlerPtr old_sax = xml_context->sax;
	  xml_context->sax = &xml_handler;
	  xml_context->userData = this;
	
	  bool ret = true;
	  if (xmlParseDocument(xml_context) < 0 || errnum == aiml::AIMLERR_AIML_PARSE) {
	    set_error(aiml::AIMLERR_AIML_PARSE);
	    // watch if runtime_error is set and deal accordingly
	    ret = false;
	  }
	
	  // and reset stuff
	  xml_context->sax = old_sax;
	  if (xml_context->myDoc) xmlFreeDoc(xml_context->myDoc);
	  xmlFreeParserCtxt(xml_context);

	  ...
	  set_error(aiml::AIMLERR_AIML_PARSE);
	  xmlStopParser(xml_context);

	   https://opensvn.csie.org/traccgi/libaiml/browser/src/aiml_parser.cpp?rev=130 line 85


	  void        xmlStopParser                   (xmlParserCtxtPtr ctxt);

	   http://www.opensource.apple.com/darwinsource/10.3/libxml2-4/libxml2/doc/html/libxml-parser.html
	 */

    public:
	SAXparser_libxml () {
	    ::memset(&libXMLhandler, 0, sizeof(libXMLhandler));
	    libXMLhandler.initialized = XML_SAX2_MAGIC;  // so we do this to force parsing as SAX2.
	    libXMLhandler.startElementNs = &startElementNs;
	    libXMLhandler.endElementNs = &endElementNs;
	    libXMLhandler.characters = &characters;
	    libXMLhandler.warning = &mywarning;
	    libXMLhandler.error = &myerror;
	}
	virtual ~SAXparser_libxml () {
	    ::xmlCleanupParser();
	    ::xmlMemoryDump();
	}

	std::string locationStr (/* XML_Parser parser */) {
	    std::stringstream ret;
	    ret << ":" << 0 // XML_GetCurrentLineNumber(parser)
		<< ":" << 0 // XML_GetCurrentColumnNumber(parser)
		<< "(" << 0 // XML_GetCurrentByteIndex(parser)
		<< ") SAXparser_libxml ";
	    return ret.str();
	}

// #ifndef LIBXML2_BUFFER_SIZE
//  #define LIBXML2_BUFFER_SIZE 8192
// #endif /* LIBXML2_BUFFER_SIZE */

	/* I haven't found a stream-based libxml parse function so we have to
	 * read all of the istr into a string. LIBXML2_BUFFER_SIZE would be
	 * useful for a stream buffer. */
	virtual bool parse (IStreamContext& istr, SWSAXhandler* saxHandler) {
	    SAXhandlerInsulator insulator(this, saxHandler);

	    std::istreambuf_iterator<char> i(*istr.p), e;
	    std::string s(i, e);

	    ::xmlSubstituteEntitiesDefault(1);
	    bool failed =
		::xmlSAXUserParseMemory(&libXMLhandler, this, s.c_str(), s.size()) != 0;
	    testAbort("SAXparser_libxml");
	    if (failed) {
		throw locationStr(/* parser */) + "error " + 
		    // XML_ErrorString(XML_GetErrorCode(parser)) + 
		    " parsing document [[" + s.substr(0, 50) + "]].\n";
	    }
	    return false;
	}

	static void startElementNs (void * voidSelf, 
				    const xmlChar * localname, 
				    const xmlChar * prefix, 
				    const xmlChar * URI, 
				    int nb_namespaces, 
				    const xmlChar ** namespaces, 
				    int nb_attributes, 
				    int ,//nb_defaulted, 
				    const xmlChar ** attributes )
	{
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    NSmapImpl nsframe(self.nsz.top());
	    self.nsz.push(nsframe);
	    for (int i = 0; i < nb_namespaces; ++i)
		self.nsz.top()[namespaces[2*i] ? (char*)namespaces[2*i] : ""] = (char*)namespaces[2*i+1];

 	    Attributes_libxml attrs(attributes, nb_attributes);
	    SimpleNsMap nsMap(self.nsz.top());
 	    self.insulator->startElement((const char*)URI, 
					  (const char*)localname, 
					  SWSAXhandler::qName((const char*)prefix, (const char*)localname), 
					 &attrs, nsMap);
	}

	static void endElementNs (void * voidSelf, 
				  const xmlChar * localname, 
				  const xmlChar * prefix, 
				  const xmlChar * URI )
	{
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    SimpleNsMap nsMap(self.nsz.top());
 	    self.insulator->endElement((const char*)URI, 
				       (const char*)localname, 
				       SWSAXhandler::qName((const char*)prefix, (const char*)localname), nsMap);
	    self.nsz.pop();
	}

	static void characters (void * voidSelf,
				const xmlChar * ch,
				int len) {
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    SimpleNsMap nsMap(self.nsz.top());
 	    self.insulator->characters((const char*)ch, 0, len, nsMap);
	}

	static void myerror( void * voidSelf, const char * msg, ... ) {
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    va_list args;
	    va_start(args, msg);
	    self.insulator->error(msg, args);
	    va_end(args);
	}

	static void mywarning( void * voidSelf, const char * msg, ... ) {
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    va_list args;
	    va_start(args, msg);
	    self.insulator->warning(msg, args);
	    va_end(args);
	}
    };

#ifdef NEEDDEF_SAXPARSER
  #define SAXPARSER SAXparser_libxml
  #undef NEEDDEF_SAXPARSER
#endif /* NEEDDEF_SAXPARSER */

}

