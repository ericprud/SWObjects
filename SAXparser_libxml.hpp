/* SAXparser_libxml.hpp: implementation of SAXparser for libxml.
 * interface per http://xmlsoft.org/html/libxml-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once
#include <map>
#include "SAXparser.hpp"

namespace w3c_sw {

    class SAXparser_libxml : public SWSAXparser {
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
	    virtual std::string getValue (std::string uri, std::string localName) { return byNS_localName[uri][localName]; }
	};
	::xmlSAXHandler handle; // http://xmlsoft.org/html/libxml-tree.html#xmlSAXHandler
	SWSAXhandler* handler;
    public:
	SAXparser_libxml () {
	    //memset(&handle, 0, sizeof(handle));
	    handle.initialized = XML_SAX2_MAGIC;  // so we do this to force parsing as SAX2.
	    handle.startElementNs = &startElementNs;
	    handle.endElementNs = &endElementNs;
	    handle.characters = &characters;
	    handle.warning = &mywarning;
	    handle.error = &myerror;
	}
	virtual ~SAXparser_libxml () {
	    ::xmlCleanupParser();
	    ::xmlMemoryDump();
	}

	virtual void parse (const char* file, SWSAXhandler* handler) {
	    this->handler = handler;
	    if (::xmlSAXUserParseFile(&handle, this, file) != 0)
		throw( "Failed to parse document.\n" );
	}

	static void startElementNs (void * voidSelf, 
				    const xmlChar * localname, 
				    const xmlChar * prefix, 
				    const xmlChar * URI, 
				    int ,//nb_namespaces, 
				    const xmlChar ** ,//namespaces, 
				    int nb_attributes, 
				    int ,//nb_defaulted, 
				    const xmlChar ** attributes )
	{
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
 	    Attributes_libxml attrs(attributes, nb_attributes);
 	    self.handler->startElement((const char*)URI, 
				       (const char*)localname, 
				       SWSAXhandler::qName((const char*)prefix, (const char*)localname), 
				       &attrs);
	}

	static void endElementNs (void * voidSelf, 
				  const xmlChar * localname, 
				  const xmlChar * prefix, 
				  const xmlChar * URI )
	{
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
 	    self.handler->endElement((const char*)URI, 
				     (const char*)localname, 
				     SWSAXhandler::qName((const char*)prefix, (const char*)localname));
	}

	static void characters (void * voidSelf,
				const xmlChar * ch,
				int len) {
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
 	    self.handler->characters((const char*)ch, 0, len);
	}

	static void myerror( void * voidSelf, const char * msg, ... ) {
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    va_list args;
	    va_start(args, msg);
	    self.handler->error(msg, args);
	    va_end(args);
	}

	static void mywarning( void * voidSelf, const char * msg, ... ) {
	    SAXparser_libxml &self = *( static_cast<SAXparser_libxml*>(voidSelf) );
	    va_list args;
	    va_start(args, msg);
	    self.handler->warning(msg, args);
	    va_end(args);
	}
    };

}

