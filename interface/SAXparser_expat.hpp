/* SAXparser_expat.hpp: implementation of SWSAXparser for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once
#include <fstream>
#include <stack>
#include <map>
#ifdef _MSC_VER
  #include "xmlparse.h"
#else /* !_MSC_VER */
  #include "expat.h"
#endif /* !_MSC_VER */
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class SAXparser_expat : public InsulatedSAXparser {
    protected:
	typedef std::map< std::string, std::string > NSmapImpl;
	class NSmapWrapper : public SWSAXhandler::NSmap {
	    NSmapImpl& map;
	public:
	    NSmapWrapper (NSmapImpl& map) : map(map) {  }
	    virtual std::string operator[] (std::string prefix) { return map[prefix]; }
	};

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

	std::stack< NSmapImpl > nsz;

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
	SAXparser_expat () {
	    NSmapImpl aboveRoot;
	    aboveRoot["xml"] = NS_xml;
	    nsz.push(aboveRoot);
	}
	virtual ~SAXparser_expat () {  }

	virtual void parse (std::string::iterator start, std::string::iterator finish, SWSAXhandler* saxHandler) {
	    SAXhandlerInsulator insulator(this, saxHandler);
	    std::string buf(start, finish);

	    XML_Parser parser = ::XML_ParserCreate(NULL);
	    ::XML_SetUserData(parser, this);
	    ::XML_SetElementHandler(parser, &startEl, &endEl);
	    ::XML_SetCharacterDataHandler(parser, &chars);

	    bool failed = 
#ifdef _MSC_VER
		XML_Parse(parser, buf.c_str(), (int)buf.size(), true) == 0;
#else /* !_MSC_VER */
		XML_Parse(parser, buf.c_str(), buf.size(), true) == XML_STATUS_ERROR;
#endif /* !_MSC_VER */
	    ::XML_ParserFree(parser);
	    if (aborted) {
		aborted = false;
		throw std::string("SAXparser_expat: ") + exceptionString;
	    }
	    if (failed)
		throw(std::string("SAXparser_expat: Error ") + 
		      XML_ErrorString(XML_GetErrorCode(parser)) + 
		      " parsing document [[" + 
		      buf.substr(0, 100) + "]].\n" );
	}
	virtual void parse (const char* file, SWSAXhandler* saxHandler) {
	    std::string buf = readFile(file, "XML");
	    parse(buf.begin(), buf.end(), saxHandler);
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
		    *elNs = nsz.top()[""].c_str();
		else // don't whine about non-namespaced docs.
		    *elNs = NULL;
	    } else {
		++*elLname;
		if (nsz.top().find(elPrefix) != nsz.top().end())
		    *elNs = nsz.top()[elPrefix].c_str();
		else
		    insulator->error("namespace prefix \"%s\" not found", (char*)elPrefix);
	    }
	}
	void __dumpNsz (const char* sit) {
	    std::cerr << sit << "\n";
	    for (NSmapImpl::const_iterator it = nsz.top().begin();
		 it != nsz.top().end(); ++it)
		std::cerr << "    xmlns:" << it->first << "=\"" << it->second << "\"\n";
	}
	static void startEl (void *voidSelf,
			     const XML_Char *name,
			     const XML_Char **atts) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    NSmapImpl nsframe(self.nsz.top());
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
		    } else
			++lname;
		    if (!strncmp(prefix[0] ? prefix : lname, "xmlns", 5)) {
			self.nsz.top()[prefix[0] ? lname : ""] = value;
		    } else if (prefix[0]) {
			size_t len = lname - prefix - 1;
			char* dup = new char[len + 1];
			strncpy(dup, prefix, len);
			dup[len] = 0;
			attrs.byIndex.push_back(NsSet(lname, dup, value));
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
		    if (nss.prefix[0] == '\0') {
			nss.namespaceURI = "";
			attrs.byNS_localName[""][nss.localName] = nss.value;
		    } else if (self.nsz.top().find(nss.prefix) != self.nsz.top().end()) {
			nss.namespaceURI = self.nsz.top()[nss.prefix].c_str();
			attrs.byNS_localName[nss.namespaceURI][nss.localName] = nss.value;
		    } else
			self.insulator->error("namespace prefix \"%s\" not found", (char*)nss.prefix);
		}
	    }
	    NSmapWrapper wrap(self.nsz.top());
 	    self.insulator->startElement(elNs, elLname, name, &attrs, wrap);
	}

	static void endEl (void *voidSelf,
			   const XML_Char *name) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    const char* elLname;
	    const char* elNs;
	    self._crackQName(name, &elLname, &elNs);
	    NSmapWrapper wrap(self.nsz.top());
 	    self.insulator->endElement(elNs, elLname, (const char*)name, wrap);
	    self.nsz.pop();
	}

	static void chars (void *voidSelf,
			   const XML_Char *s,
			   int len) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    NSmapWrapper wrap(self.nsz.top());
 	    self.insulator->characters((const char*)s, 0, len, wrap);
	}
    };

#ifdef NEEDDEF_makeSAXparser
    inline SWSAXparser* SWSAXparser::makeSAXparser () {
	return new SAXparser_expat();
    }
  #undef NEEDDEF_makeSAXparser
#endif /* NEEDDEF_makeSAXparser */

}

