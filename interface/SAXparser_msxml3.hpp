/* SAXparser_libxml.hpp: implementation of SWSAXparser for libxml.
 * interface per http://xmlsoft.org/html/libxml-tree.html

 * $Id: SWObjects.hpp,v 1.26 2008-12-04 23:00:15 eric Exp $
 */

#ifndef INLCUDED_interface_SAXparser_msxml3_hpp
 #define INLCUDED_interface_SAXparser_msxml3_hpp

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#import <msxml3.dll> raw_interfaces_only 
using namespace MSXML2;

#include <iostream>
#include <tchar.h>
#include <map>
#include <comutil.h>
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    class SAXparser_msxml3 : public NSdInsulatedSAXparser {
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
	    typedef std::map<std::string, std::string> InnerNSmap;
	    typedef std::map<std::string, InnerNSmap > OuterNSmap;
	    OuterNSmap byNS_localName;
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
	    virtual size_t getLength () const { if (!initialized) const_cast<Attributes_msxml3*>(this)->init(); return byIndex.size(); }
	    virtual std::string getURI (size_t i) const { if (!initialized) const_cast<Attributes_msxml3*>(this)->init(); return byIndex[i].namespaceURI; }
	    virtual std::string getLocalName (size_t i) const { if (!initialized) const_cast<Attributes_msxml3*>(this)->init(); return byIndex[i].localName; }
	    virtual std::string getQName (size_t i) const { if (!initialized) const_cast<Attributes_msxml3*>(this)->init(); return byIndex[i].qname; }
	    virtual bool value (std::string uri, std::string localName, std::string* ptr) const {
		if (!initialized) const_cast<Attributes_msxml3*>(this)->init();
		const OuterNSmap::const_iterator oit = byNS_localName.find(uri);
		if (oit == byNS_localName.end())
		    return false;
		const InnerNSmap& i = oit->second;
		InnerNSmap::const_iterator inner = i.find(localName);
		if (inner == i.end())
		    return false;
		if (ptr != NULL)
		    *ptr = inner->second;
		return true;
		// return byNS_localName[uri][localName];
	    }
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
        
	    virtual HRESULT STDMETHODCALLTYPE startPrefixMapping(unsigned short *pwchPrefix,
								 int cchPrefix,
								 unsigned short *pwchUri,
								 int cchUri) {
		/* Cheasy re-use of std::stack<NSmapImpl>nsz to record single additons to map. */
		NSmapImpl nsframe(h->nsz.top());
		h->nsz.push(nsframe);
		h->nsz.top()[pwchPrefix ? to8bit(pwchPrefix, cchPrefix).c_str() : ""] = to8bit(pwchUri, cchUri).c_str();
		return S_OK;
	    }
        
	    virtual HRESULT STDMETHODCALLTYPE endPrefixMapping(unsigned short *pwchPrefix,
							       int cchPrefix) {
		h->nsz.pop();
		return S_OK;
	    }
        
	    HRESULT STDMETHODCALLTYPE startElement(unsigned short *pwchNamespaceUri,
						   int cchNamespaceUri,
						   unsigned short *pwchLocalName,
						   int cchLocalName,
						   unsigned short *pwchRawName,
						   int cchRawName,
						   ISAXAttributes __RPC_FAR *pAttributes)
	    {
		Attributes_msxml3 attrs(pAttributes);
		SimpleNsMap nsMap(h->nsz.top());
		h->insulator->startElement((const char*)to8bit(pwchNamespaceUri, cchNamespaceUri).c_str(), 
					    (const char*)to8bit(pwchLocalName, cchLocalName).c_str(), 
					    (const char*)to8bit(pwchRawName, cchRawName).c_str(), 
					   &attrs, nsMap);
		return S_OK;
	    }

	    HRESULT STDMETHODCALLTYPE endElement(unsigned short *pwchNamespaceUri,
						 int cchNamespaceUri,
						 unsigned short *pwchLocalName,
						 int cchLocalName,
						 unsigned short *pwchRawName,
						 int cchRawName)
	    {
		SimpleNsMap nsMap(h->nsz.top());
		h->insulator->endElement((const char*)to8bit(pwchNamespaceUri, cchNamespaceUri).c_str(), 
					  (const char*)to8bit(pwchLocalName, cchLocalName).c_str(), 
					 (const char*)to8bit(pwchRawName, cchRawName).c_str(), nsMap);
		return S_OK;
	    }

	    virtual HRESULT STDMETHODCALLTYPE characters(unsigned short *pwchChars,
							 int cchChars)
	    {
		SimpleNsMap nsMap(h->nsz.top());
		h->insulator->characters((const char*)to8bit(pwchChars, cchChars).c_str(), 0, cchChars, nsMap);
		return S_OK;
	    }

	    virtual HRESULT STDMETHODCALLTYPE ignorableWhitespace( 
								  unsigned short *pwchChars,
								  int cchChars)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE processingInstruction( 
								    unsigned short *pwchTarget,
								    int cchTarget,
								    unsigned short *pwchData,
								    int cchData)
	    {return S_OK;}
        
	    virtual HRESULT STDMETHODCALLTYPE skippedEntity( 
							    unsigned short *pwchName,
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
		h->insulator->error(msg, args);
		va_end(args);
	    }

	    void mywarning(const char * msg, ...) {
		va_list args;
		va_start(args, msg);
		h->insulator->warning(msg, args);
		va_end(args);
	    }

	};

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
		s << "SAXparser_msxml3: CoCreateInstance failed: result code: " << hr;
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

	void static to_variant(const std::wstring& str, VARIANT& vt) {
	    _bstr_t bs(str.c_str());
	    reinterpret_cast<_variant_t&>(vt) = bs;
	}

	virtual bool parse (w3c_sw::IStreamContext& istr, SWSAXhandler* saxHandler) {
	    SAXhandlerInsulator insulator(this, saxHandler);

	    std::istreambuf_iterator<char> i(*istr.p), e;
	    std::string s(i, e);

	    std::wstring wstr(to16bit(s.c_str()));
	    _variant_t vt;
	    to_variant(wstr, vt);
	    HRESULT hr = pXMLReader->parse(vt);
	    testAbort("SAXparser_msxml3");
	    if(FAILED(hr)) {
		std::stringstream str;
		str << hr;
		throw std::string("SAXparser_msxml3: Error ") + 
		      str.str() + 
		      " parsing document [[" + 
		      s.substr(0, 100) + "]].\n" ;
	    }
	    return false;
	}

	// virtual void parse (const char* file, SWSAXhandler* saxHandler) {
	//     SAXhandlerInsulator insulator(this, saxHandler);
	//     // parse the document
	//     HRESULT hr = pXMLReader->parseURL((unsigned short*)to16bit(file).c_str());
	//     testAbort("SAXparser_msxml3");
	//     if(FAILED(hr)) {
	// 	std::stringstream s;
	// 	s << hr;
	// 	throw(std::string("SAXparser_msxml3: Error ") + 
	// 	      s.str() + 
	// 	      " parsing file \"" + 
	// 	      file + "\".\n" );
	//     }
	// }

	static std::string to8bit (unsigned short *wchar, int len) {
	    // Cast unsigned short* to LPCWSTR, which is a, i guess, short*.
	    // v-- WC_ERR_INVALID_CHARS
	    int size = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wchar, len, NULL, 0, NULL, NULL);
	    std::string ret;
	    ret.resize(size);
	    WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wchar, len, &ret[0], size, NULL, NULL);
	    return ret;
	}

	static std::wstring to16bit (const char* p) {
	    std::string str(p);
	    std::wstring wstr;
	    for (std::string::iterator it = str.begin();
		 it != str.end(); ++it)
		wstr += (wchar_t)*it;
	    return wstr;
	}

    };

#ifdef NEEDDEF_W3C_SW_SAXPARSER
  #define W3C_SW_SAXPARSER w3c_sw::SAXparser_msxml3
  #undef NEEDDEF_W3C_SW_SAXPARSER
#endif /* NEEDDEF_W3C_SW_SAXPARSER */

}

#endif /* INLCUDED_interface_SAXparser_msxml3_hpp */
