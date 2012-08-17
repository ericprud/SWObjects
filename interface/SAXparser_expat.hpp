/* SAXparser_expat.hpp: implementation of SWSAXparser for expat.
 * interface per http://xmlsoft.org/html/expat-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef INLCUDED_interface_SAXparser_expat_hpp
 #define INLCUDED_interface_SAXparser_expat_hpp

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

    class SAXparser_expat : public NSdInsulatedSAXparser {
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

	struct DelMes : public std::vector<const char*> {
	    ~DelMes () {
		for (std::vector<const char*>::iterator it = begin(); 
		     it != end(); ++it)
		    delete[] *it;
	    }
	};

    public:
	SAXparser_expat () {  }
	virtual ~SAXparser_expat () {  }

	std::string locationStr (XML_Parser parser) { // @@ seems to report errors at the end of the document.
	    std::stringstream ret;
	    ret << ":" << XML_GetCurrentLineNumber(parser)
		<< ":" << XML_GetCurrentColumnNumber(parser)
		<< "(" << XML_GetCurrentByteIndex(parser)
		<< ") SAXparser_expat ";
	    return ret.str();
	}

#ifndef EXPAT_BUFFER_SIZE
 #define EXPAT_BUFFER_SIZE 8192
#endif /* EXPAT_BUFFER_SIZE */

	virtual bool parse (IStreamContext& istr, SWSAXhandler* saxHandler) {
	    //toy(istr, saxHandler);
	    SAXhandlerInsulator insulator(this, saxHandler);

	    XML_Parser parser = ::XML_ParserCreate(NULL);
	    ::XML_SetUserData(parser, this);
	    ::XML_SetElementHandler(parser, &startEl, &endEl);
	    ::XML_SetCharacterDataHandler(parser, &chars);

	    while (*istr.p) {
		char* buff = (char*)XML_GetBuffer(parser, EXPAT_BUFFER_SIZE);
		if (buff == NULL)
		    throw std::string("SAXparser_expat unable to allocate buffer.");
		istr.p->read(buff, EXPAT_BUFFER_SIZE);
		bool isFinal = *istr.p ? false : true;
		bool failed = 
#ifdef _MSC_VER
		    XML_ParseBuffer(parser, istr.p->gcount(), isFinal) == 0;
#else /* !_MSC_VER */
		    XML_ParseBuffer(parser, istr.p->gcount(), isFinal) == XML_STATUS_ERROR;
#endif /* !_MSC_VER */
		testAbort(istr.nameStr + locationStr(parser));
		if (failed) {
		    buff[istr.p->gcount()] = 0;
		    buff[100] = 0;
		    throw locationStr(parser) + "error " + 
			XML_ErrorString(XML_GetErrorCode(parser)) + 
			" parsing document [[" + buff + "]].\n";
		}
	    }
	    ::XML_ParserFree(parser);
	    return false;
	}

	static void _dumpNsFrame (std::map< const char*, const char* > nsframe) {
	    for (std::map< const char*, const char* >::iterator it = nsframe.begin();
		 it != nsframe.end(); ++it)
		std::cout << "xmlns:" << it->first << "=\"" << it->second << "\"\n";
	}
	bool _crackQName(const char* name, const char** elLname, const char** elNs) {
	    bool ret = true; // set to false for failed parse.
	    const char* elPrefix = name;
	    *elLname = ::strchr(elPrefix, ':');
	    if (*elLname == NULL) {
		*elLname = elPrefix;
		elPrefix = "";
		if (nsz.top().find("") != nsz.top().end())
		    *elNs = nsz.top()[""].c_str();
		else { // don't whine about non-namespaced docs.
		    *elNs = NULL;
		    ret = false;
		}
	    } else {
		std::string prefix(elPrefix, *elLname);
		++*elLname;
		if (nsz.top().find(prefix) != nsz.top().end())
		    *elNs = nsz.top()[prefix].c_str();
		else {
		    insulator->varError("namespace prefix \"%s\" not found", (char*)prefix.c_str());
		    ret = false;
		}
	    }
	    return ret;
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
	    DelMes delmes;
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
#if TODO_setLang_INTERFACE
		    } else if (prefix[0] && !strncmp(prefix, "xml", 3)) {
			if (!strcmp(lname, "base"))
			    self.insulator->setBase(value);
			else if (!strcmp(lname, "lang"))
			    self.insulator->setLang(value); @@ no setLang interface yet
			else
			    self.insulator->varError("unknown xml directive \"%s\"", lname);
#else /* !TODO_setLang_INTERFACE */
		    } else if (prefix[0] && !strncmp(prefix, "xml", 3) && !strcmp(lname, "base")) {
			self.insulator->setBase(value);
#endif /* !TODO_setLang_INTERFACE */
		    } else if (prefix[0]) {
			size_t len = lname - prefix - 1;
			char* dup = new char[len + 1];
			strncpy(dup, prefix, len);
			dup[len] = 0;
			attrs.byIndex.push_back(NsSet(lname, dup, value));
			delmes.push_back(dup);
		    } else {
			attrs.byIndex.push_back(NsSet(lname, "", value));
		    }
		}
	    }

	    const char* elLname;
	    const char* elNs;
	    if (!self._crackQName(name, &elLname, &elNs))
		self.insulator->varError("namespace prefix not found for \"%s\"", name);

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
			self.insulator->varError("namespace prefix \"%s\" not found", (char*)nss.prefix);
		}
	    }
	    SimpleNsMap nsMap(self.nsz.top());
 	    self.insulator->startElement(elNs, elLname, name, &attrs, nsMap);
	}

	static void endEl (void *voidSelf,
			   const XML_Char *name) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    const char* elLname;
	    const char* elNs;
	    self._crackQName(name, &elLname, &elNs);
	    SimpleNsMap nsMap(self.nsz.top());
 	    self.insulator->endElement(elNs, elLname, (const char*)name, nsMap);
	    self.nsz.pop();
	}

	static void chars (void *voidSelf,
			   const XML_Char *s,
			   int len) {
	    SAXparser_expat &self = *( static_cast<SAXparser_expat*>(voidSelf) );
	    SimpleNsMap nsMap(self.nsz.top());
 	    self.insulator->characters((const char*)s, 0, len, nsMap);
	}
    };
#ifdef NEEDDEF_W3C_SW_SAXPARSER
  #undef NEEDDEF_W3C_SW_SAXPARSER
  #define W3C_SW_SAXPARSER w3c_sw::SAXparser_expat
#endif /* NEEDDEF_W3C_SW_SAXPARSER */

}

#endif /* INLCUDED_interface_SAXparser_expat_hpp */
