/* SAXparser_libxml.hpp: implementation of SWSAXparser for libxml.
 * interface per http://xmlsoft.org/html/libxml-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#import <msxml3.dll> raw_interfaces_only 
using namespace MSXML2;

#include <iostream>
#include <tchar.h>
#include <map>
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    std::string to8bit (wchar_t __RPC_FAR *wchar, int len) {
	std::wstring wstr(wchar);
	if (len == -1)
	    len = (int)wstr.length();
	std::string str;
	int i = 0;
	for (std::wstring::iterator it = wstr.begin();
	     i < len; ++it, ++i)
	    str += (char)*it;
	return str;
    }

    std::wstring to16bit (const char* p) {
	std::string str(p);
	std::wstring wstr;
	for (std::string::iterator it = str.begin();
	     it != str.end(); ++it)
	    wstr += (wchar_t)*it;
	return wstr;
    }

    class SAXparser_msxml3 : public SWSAXparser {
    protected:
	struct NsSet {
	    std::string namespaceURI;
	    std::string localName;
	    std::string qname;
	    NsSet (std::string namespaceURI, std::string localName, std::string qname) :
		namespaceURI(namespaceURI), localName(localName), qname(qname) {  }
	};

	class Attributes_msxml3 : public SWSAXhandler::Attributes {
	protected:
	    ISAXAttributes * attrs;
	    std::vector<NsSet> byIndex;
	    std::map<std::string, std::map<std::string, std::string> > byNS_localName;
	    bool initialized;
	    void init () {
		int attrCount;
		attrs->getLength(&attrCount);
		for (int i = 0; i < attrCount; ++i) {
		    int llname, lqname, luri, lvalue;
		    unsigned short* lname; attrs->getLocalName(i, &lname, &llname);
		    unsigned short* qname; attrs->getQName(i, &qname, &lqname);
		    unsigned short* namespaceURI; attrs->getURI(i, &namespaceURI, &luri);
		    unsigned short* value; attrs->getValue(i, &value, &lvalue);

		    byIndex.push_back(NsSet(to8bit(namespaceURI, luri), to8bit(lname, llname), to8bit(qname, lqname)));
		    byNS_localName[to8bit(namespaceURI, luri)][to8bit(lname, llname)] = to8bit(value, lvalue);
		}
		initialized = true;
	    }
	public:
	    Attributes_msxml3 (ISAXAttributes __RPC_FAR *pAttributes) : 
		attrs(pAttributes), initialized(false) {  }
	    virtual size_t getLength () { if (!initialized) init(); return byIndex.size(); }
	    virtual std::string getURI (size_t i) { if (!initialized) init(); return byIndex[i].namespaceURI; }
	    virtual std::string getLocalName (size_t i) { if (!initialized) init(); return byIndex[i].localName; }
	    virtual std::string getQName (size_t i) { if (!initialized) init(); return byIndex[i].qname; }
	    virtual std::string getValue (std::string uri, std::string localName) { if (!initialized) init(); return byNS_localName[uri][localName]; }
	};

	class ContentHandler : public ISAXContentHandler {
	    long m_RefCount;
	    SAXparser_msxml3* h;

	public:
	    ContentHandler (SAXparser_msxml3* h) : m_RefCount(0), h(h) {  }
	    long __stdcall QueryInterface(const struct _GUID &riid, void ** ppObj)
	    { 
		if (riid == IID_IUnknown)
		    {
			*ppObj = static_cast<IUnknown*>(this);
		    }
		if (riid == __uuidof(ISAXContentHandler))
		    {
			*ppObj = static_cast<ISAXContentHandler*>(this);
		    }
		else
		    {
			*ppObj = NULL ;
			return E_NOINTERFACE ;
		    }

		AddRef() ;
		return S_OK;
	    }
	    unsigned long __stdcall AddRef(void)
	    {
		return InterlockedIncrement(&m_RefCount);
	    }
	    unsigned long __stdcall Release(void)
	    {
		long nRefCount=0;
		nRefCount=InterlockedDecrement(&m_RefCount) ;
		if (nRefCount == 0) delete this;
		return nRefCount;
	    }

	    virtual HRESULT STDMETHODCALLTYPE putDocumentLocator( 
								 ISAXLocator __RPC_FAR *pLocator)
	    {return S_OK;}

	    virtual HRESULT STDMETHODCALLTYPE startDocument( void)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE endDocument( void)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE startPrefixMapping( 
								 wchar_t __RPC_FAR *pwchPrefix,
								 int cchPrefix,
								 wchar_t __RPC_FAR *pwchUri,
								 int cchUri)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE endPrefixMapping( 
							       wchar_t __RPC_FAR *pwchPrefix,
							       int cchPrefix)
	    {return S_OK;}
        
	    HRESULT STDMETHODCALLTYPE startElement(wchar_t __RPC_FAR *pwchNamespaceUri,
						   int cchNamespaceUri,
						   wchar_t __RPC_FAR *pwchLocalName,
						   int cchLocalName,
						   wchar_t __RPC_FAR *pwchRawName,
						   int cchRawName,
						   ISAXAttributes __RPC_FAR *pAttributes)
	    {
		Attributes_msxml3 attrs(pAttributes);
		h->saxHandler->startElement((const char*)to8bit(pwchNamespaceUri, cchNamespaceUri).c_str(), 
					    (const char*)to8bit(pwchLocalName, cchLocalName).c_str(), 
					    (const char*)to8bit(pwchRawName, cchRawName).c_str(), 
					    &attrs);
		return S_OK;
	    }

	    HRESULT STDMETHODCALLTYPE endElement(wchar_t __RPC_FAR *pwchNamespaceUri,
						 int cchNamespaceUri,
						 wchar_t __RPC_FAR *pwchLocalName,
						 int cchLocalName,
						 wchar_t __RPC_FAR *pwchRawName,
						 int cchRawName)
	    {
		h->saxHandler->endElement((const char*)to8bit(pwchNamespaceUri, cchNamespaceUri).c_str(), 
					  (const char*)to8bit(pwchLocalName, cchLocalName).c_str(), 
					  (const char*)to8bit(pwchRawName, cchRawName).c_str());
		return S_OK;
	    }

	    virtual HRESULT STDMETHODCALLTYPE characters(wchar_t __RPC_FAR *pwchChars,
							 int cchChars)
	    {
		h->saxHandler->characters((const char*)to8bit(pwchChars, cchChars).c_str(), 0, cchChars);
		return S_OK;
	    }

	    virtual HRESULT STDMETHODCALLTYPE ignorableWhitespace( 
								  wchar_t __RPC_FAR *pwchChars,
								  int cchChars)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE processingInstruction( 
								    wchar_t __RPC_FAR *pwchTarget,
								    int cchTarget,
								    wchar_t __RPC_FAR *pwchData,
								    int cchData)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE skippedEntity( 
							    wchar_t __RPC_FAR *pwchName,
							    int cchName)
	    {return S_OK;}
	};

	class ErrorHandler : public ISAXErrorHandler  
	{
	    long m_RefCount;
	    SAXparser_msxml3* h;
	public:
	    ErrorHandler (SAXparser_msxml3* h) : m_RefCount(0), h(h) {  }
	    virtual ~ErrorHandler() {  }

	    long __stdcall QueryInterface(const struct _GUID &riid, void ** ppObj)
	    {
		if (riid == IID_IUnknown)
		    {
			*ppObj = static_cast<IUnknown*>(this);
		    }
		if (riid == __uuidof(ISAXErrorHandler))
		    {
			*ppObj = static_cast<ISAXErrorHandler*>(this);
		    }
		else
		    {
			*ppObj = NULL ;
			return E_NOINTERFACE ;
		    }

		AddRef() ;
		return S_OK;
	    }
	    unsigned long __stdcall AddRef(void)
	    {
		return InterlockedIncrement(&m_RefCount);
	    }
	    unsigned long __stdcall Release(void)
	    {
		long nRefCount=0;
		nRefCount=InterlockedDecrement(&m_RefCount) ;
		if (nRefCount == 0) delete this;
		return nRefCount;
	    }

	    virtual HRESULT STDMETHODCALLTYPE error(ISAXLocator __RPC_FAR *pLocator,
						    unsigned short * pwchErrorMessage,
						    HRESULT errCode) 
	    {
		myerror(to8bit(pwchErrorMessage, -1).c_str());
		return S_OK;
	    }
        
	    virtual HRESULT STDMETHODCALLTYPE fatalError(ISAXLocator __RPC_FAR *pLocator,
							 unsigned short * pwchErrorMessage,
							 HRESULT errCode)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE ignorableWarning(ISAXLocator __RPC_FAR *pLocator,
							       unsigned short * pwchErrorMessage,
							       HRESULT errCode)
	    {return S_OK;}

	    void myerror(const char * msg, ...) {
		va_list args;
		va_start(args, msg);
		h->saxHandler->error(msg, args);
		va_end(args);
	    }

	    void mywarning(const char * msg, ...) {
		va_list args;
		va_start(args, msg);
		h->saxHandler->warning(msg, args);
		va_end(args);
	    }

	};

	SWSAXhandler* saxHandler;
	ISAXXMLReader* pXMLReader;
	long m_RefCount;
    public:
	SAXparser_msxml3 () {
	    CoInitialize(NULL); 
	    pXMLReader = NULL;

	    // create an instance of the XML reader
	    HRESULT hr = CoCreateInstance(__uuidof(SAXXMLReader), 
					  NULL, 
					  CLSCTX_ALL, 
					  __uuidof(ISAXXMLReader), 
					  (void **)&pXMLReader);
	    if(FAILED(hr)) {
		std::stringstream s;
		s << "CoCreateInstance failed: result code: " << hr;
		throw s.str();
// 		throw (std::stringstream("CoCreateInstance failed: result code: ") << hr).str();
	    }

	    // create a new content handler
	    ContentHandler *contentHandler = new ContentHandler(this);
	    // register the content handler with the reader
	    hr = pXMLReader->putContentHandler(contentHandler);
	    // create a new error handler
	    ErrorHandler * errorHandler = new ErrorHandler(this);
	    // register the error handler with the reader
	    hr = pXMLReader->putErrorHandler(errorHandler);
	}
	virtual ~SAXparser_msxml3 () {
	    pXMLReader->Release();
	    CoUninitialize();
	}

	virtual void parse (std::string::iterator start, std::string::iterator finish, SWSAXhandler* saxHandler) {
	    this->saxHandler = saxHandler;
	    std::string str(start, finish);
	    std::wstring wstr(to16bit(str.c_str()));
	    VARIANT data /* !!! (wstr.c_str()) */;
	    VariantInit(&data);
	    HRESULT hr = pXMLReader->parse(data);
	    if(FAILED(hr)) {
		std::stringstream s;
		s << "parse failed: result code: " << hr;
		throw s.str();
// 		throw (std::stringstream("parseURL failed: result code: ") << hr).str();
	    }
	}

	virtual void parse (const char* file, SWSAXhandler* saxHandler) {
	    this->saxHandler = saxHandler;
	    // parse the document
	    HRESULT hr = pXMLReader->parseURL((unsigned short*)to16bit(file).c_str());
	    if(FAILED(hr)) {
		std::stringstream s;
		s << "parseURL failed: result code: " << hr;
		throw s.str();
// 		throw (std::stringstream("parseURL failed: result code: ") << hr).str();
	    }
	}

    };

#ifdef NEEDDEF_makeSAXparser
    inline SWSAXparser* SWSAXparser::makeSAXparser () {
	return new SAXparser_msxml3();
    }
  #undef NEEDDEF_makeSAXparser
#endif /* NEEDDEF_makeSAXparser */

}

