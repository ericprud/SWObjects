/* SAXparser_expat.hpp: implementation of SAXparser for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once
#include <stack>
#include <map>
#include "SAXparser.hpp"

namespace w3c_sw {

    class SAXparser_expat : public SWSAXparser {
    protected:
	struct NsSet {
	    const char* namespaceURI;
	    const char* localName;
	    const char* prefix;
	    const char* value;
	    NsSet (const char* localName, const char* prefix, const char* value) :
		namespaceURI(NULL), localName(localName), prefix(prefix), value(value) {  }
	};
	class Attributes_expat : public SWSAXhandler::Attributes {
	    friend class SAXparser_expat;
	protected:
	    std::vector<NsSet> byIndex;
	    std::map<std::string, std::map<std::string, std::string> > byNS_localName;
	public:
	    Attributes_expat ()  {  }
	    virtual size_t getLength () { return byIndex.size(); }
	    virtual std::string getURI (size_t i) { return byIndex[i].namespaceURI; }
	    virtual std::string getLocalName (size_t i) { return byIndex[i].localName; }
	    virtual std::string getQName (size_t i) { return SWSAXhandler::qName(byIndex[i].prefix, byIndex[i].localName); }
	    virtual std::string getValue (std::string uri, std::string localName) { return byNS_localName[uri][localName]; }
	};

	XML_Parser parser;
	SWSAXhandler* handler;
	std::stack< std::map< const char*, const char* > > nsz;

	std::string readFile (const char* filename, const char* type) {
	    std::ifstream dataStream(filename);
	    if (!dataStream.is_open()) {
		std::string msg = std::string("failed to ") + std::string(type) + 
		    std::string(" data \"") + filename + std::string("\".");
		throw msg;
	    }
	    std::istreambuf_iterator<char> i(dataStream), e;
	    std::string ret(i, e);
	    dataStream.close();
	    return ret;
	}

    public:
	SAXparser_expat () : parser(XML_ParserCreate(NULL)) {
	    XML_SetUserData(parser, this);
	    XML_SetElementHandler(parser, &start, &end);
	    XML_SetCharacterDataHandler(parser, &chars);
	    std::map< const char*, const char* > aboveRoot;
	    nsz.push(aboveRoot);
	}
	virtual ~SAXparser_expat () {
	    ::XML_ParserFree(parser);
	}

	virtual void parse (const char* file, SWSAXhandler* handler) {
	    this->handler = handler;
	    std::string buf = readFile(file, "XML");
	    if (XML_Parse(parser, buf.c_str(), buf.size(), true) == XML_STATUS_ERROR)
		throw( "Failed to parse document.\n" );
	}

	static void _dumpNsFrame (std::map< const char*, const char* > nsframe) {
	    for (std::map< const char*, const char* >::iterator it = nsframe.begin();
		 it != nsframe.end(); ++it)
		std::cout << "xmlns:" << it->first << "=\"" << it->second << "\"\n";
	}
	void _crackQName(const char* name, const char** elLname, const char** elNs) {
	    const char* elPrefix = name;
	    *elLname = ::strchr(elPrefix, ':');
	    if (*elLname == NULL) {
		*elLname = elPrefix;
		elPrefix = "";
		if (nsz.top().find("") != nsz.top().end())
		    *elNs = nsz.top()[""];
		else // don't whine about non-namespaced docs.
		    *elNs = NULL;
	    } else {
		++*elLname;
		if (nsz.top().find(elPrefix) != nsz.top().end())
		    *elNs = nsz.top()[elPrefix];
		else
		    handler->error("namespace prefix \"%s\" not found", elPrefix);
	    }
	}
	static void start (void *voidSelf,
			   const XML_Char *name,
			   const XML_Char **atts) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    std::map< const char*, const char* > nsframe(self.nsz.top());
	    self.nsz.push(nsframe);

	    Attributes_expat attrs;
	    { /* Walk attrs. */
		for (const XML_Char** att = atts; *att; ++att) {
		    const char* prefix = *att;
		    const char* value = *++att;
		    const char* lname = ::strchr(prefix, ':');
		    if (lname == NULL) {
			lname = prefix;
			prefix = "";
		    }
		    if (!strncmp(prefix[0] ? prefix : lname, "xmlns", 5)) {
			self.nsz.top()[prefix[0] ? lname+1 : ""] = value;
		    } else if (prefix) {
			char* dup = new char[lname - prefix];
			strncpy(dup, prefix, lname - prefix - 1);
			attrs.byIndex.push_back(NsSet(lname, prefix ? prefix : "", value));
		    } else {
			attrs.byIndex.push_back(NsSet(lname, "", value));
		    }
		}
	    }

	    const char* elLname;
	    const char* elNs;
	    self._crackQName(name, &elLname, &elNs);

	    { /* Fix namespaces on attrs. */
		for (std::vector<NsSet>::iterator it = attrs.byIndex.begin(); 
		     it != attrs.byIndex.end(); ++it) {
		    NsSet& nss = *it;
		    if (self.nsz.top().find(nss.prefix) != self.nsz.top().end()) {
			nss.namespaceURI = self.nsz.top()[nss.prefix];
			attrs.byNS_localName[nss.namespaceURI][nss.localName] = nss.value;
		    } else
			self.handler->error("namespace prefix \"%s\" not found", nss.prefix);
		}
	    }
 	    self.handler->startElement(elNs, elLname, name, &attrs);
	}

	static void end (void *voidSelf,
			 const XML_Char *name) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    const char* elLname;
	    const char* elNs;
	    self._crackQName(name, &elLname, &elNs);
 	    self.handler->endElement(elNs, elLname, (const char*)name);
	    self.nsz.pop();
	}

	static void chars (void *voidSelf,
			   const XML_Char *s,
			   int len) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
 	    self.handler->characters((const char*)s, 0, len);
	}
    };

}

