/* WEBagent - abstract inferface for WEB clients and servers

 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $

 * SWWEBagent is prefixed with SW to avoid collisions with
 * implementation names.
 */

#ifndef INCLUDED_interface_WEBagent_hpp
 #define INCLUDED_interface_WEBagent_hpp

#include <string>
#include "SWObjects.hpp"

namespace w3c_sw {

    class SWWEBagent {
    protected:
	std::string mediaType;
    public:

	static std::string base64_encode(std::string encodeMe);
	static std::string base64_decode(std::string const& encoded_string);
	SWWEBagent () {  }
	virtual ~SWWEBagent () {  }
	std::string getMediaType () { return mediaType; }
	struct ParameterList : public std::multimap<std::string, std::string> {
	    ParameterList::iterator set(std::string key, std::string value) {
		return insert(std::pair<std::string, std::string>(key, value));
	    }
	    std::string str () const {
		std::stringstream ss;
		for (ParameterList::const_iterator it = begin();
		     it != end(); ++it) {
		    if (it != begin())
			ss << "&";
		    ss << urlEncode(it->first) << "=" << urlEncode(it->second);
		}
		return ss.str();
	    }
	};
	virtual boost::shared_ptr<IStreamContext> _execute(std::string method,
#if REGEX_LIB == SWOb_DISABLED
				 std::string host, std::string port, std::string path
#else /* !REGEX_LIB == SWOb_BOOST */
				 std::string url
#endif /* !REGEX_LIB == SWOb_BOOST */
				     , std::string urlParms, std::string body, const char* reqMediaType = "application/x-www-form-urlencoded"
				     ) = 0;

	virtual boost::shared_ptr<IStreamContext> get (
#if REGEX_LIB == SWOb_DISABLED
				 std::string host, std::string port, std::string path
#else /* !REGEX_LIB == SWOb_BOOST */
				 const char* url
#endif /* !REGEX_LIB == SWOb_BOOST */
				 , const ParameterList p = ParameterList()
				 ) {
	    if (!::strncmp(url, "data:", 5)) {
		std::string re;
		boost::cmatch matches;

		re = "data:(.*?)(;base64)?,(.*)"; // tried \\` and \\A to avoid matching "data:data:..."; didn't work.
		if (!boost::regex_match(url, matches, boost::regex(re))) // i don't recall why i added this: + "\\'"
		    throw std::string("Invalid data URL: \"") + url + "\" -- didn't match \"" + re + "\".";
		mediaType = std::string(matches[1].first, matches[1].second);
		std::string s(matches[3].first, matches[3].second); // "%3CX%3E%20%7B%20%3CI%3E%20%3Cwrite%3E%20%22%E7%85%AE%E6%9C%AC%E8%AA%9Ecd%22%20.%20%7D");
		std::string ret;
		for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)  {
		    if (*it == '%' && it+2 < s.end()) {
			std::stringstream ss(std::string(it+1, it+3));
			int i;
			ss >> std::hex >> i;
			std::stringstream t;
			// t << (char)i;
			// *p << t.str();
			ret += (char)i;
			it += 2;
		    } else {
			ret += *it;
		    }
		}
		if (matches[2].matched)
		    ret = base64_decode(ret);
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info)
		    << "data: URL percent-unescaped "
		    << (matches[2].matched ? "and base64-decoded " : "")
		    << "as \"" << ret << "\".\n";
		return boost::shared_ptr<IStreamContext>(new IStreamContext(ret, IStreamContext::STRING, mediaType.c_str()));
	    } else
		return _execute ("GET",
#if REGEX_LIB == SWOb_DISABLED
				 host, port, path
#else /* !REGEX_LIB == SWOb_BOOST */
				 url
#endif /* !REGEX_LIB == SWOb_BOOST */
				 , p.str().c_str(), "");
	}
	virtual boost::shared_ptr<IStreamContext> post (
#if REGEX_LIB == SWOb_DISABLED
				 std::string host, std::string port, std::string path
#else /* !REGEX_LIB == SWOb_BOOST */
				 const char* url
#endif /* !REGEX_LIB == SWOb_BOOST */
				 , const ParameterList p
				 ) {
	    return _execute("POST",
#if REGEX_LIB == SWOb_DISABLED
				 host, port, path
#else /* !REGEX_LIB == SWOb_BOOST */
				 url
#endif /* !REGEX_LIB == SWOb_BOOST */
				 , "", p.str().c_str());
	}

	virtual boost::shared_ptr<IStreamContext> post (
#if REGEX_LIB == SWOb_DISABLED
				 std::string host, std::string port, std::string path
#else /* !REGEX_LIB == SWOb_BOOST */
				 const char* url
#endif /* !REGEX_LIB == SWOb_BOOST */
				 , const char* mediaType, const char* payload
				 ) {
	    return _execute("POST",
#if REGEX_LIB == SWOb_DISABLED
				 host, port, path
#else /* !REGEX_LIB == SWOb_BOOST */
				 url
#endif /* !REGEX_LIB == SWOb_BOOST */
			    , "", payload, mediaType);
	}

	static std::string urlEncode (std::string encodeMe) {
	    std::stringstream s;
	    s.setf(std::ios::hex, std::ios::basefield);
	    s.setf(std::ios::uppercase);
	    for (std::string::const_iterator it = encodeMe.begin(); it != encodeMe.end(); ++it) {
		if (*it == ' ')
		    s << '+';
		else if ((*it >= 'a' && *it <= 'z') || 
			 (*it >= 'A' && *it <= 'Z') || 
			 (*it >= '0' && *it <= '9') || 
			 *it == '.' || *it == '-' || *it == '_')
		    s << *it;
		else if (*it < 0x10)
		    s << "%0" << (unsigned)*it;
		else
		    s << '%' << (unsigned)*it;
	    }
	    return s.str();
	}

	static std::string base64encode (std::string encodeMe) {
	    static const std::string base64_chars = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";

	    unsigned char const* bytes_to_encode = (const unsigned char*)encodeMe.c_str();
	    size_t in_len = encodeMe.size();
	    std::string ret;
	    int i = 0;
	    int j = 0;
	    unsigned char char_array_3[3];
	    unsigned char char_array_4[4];

	    while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
		    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		    char_array_4[3] = char_array_3[2] & 0x3f;

		    for(i = 0; (i <4) ; i++)
			ret += base64_chars[char_array_4[i]];
		    i = 0;
		}
	    }

	    if (i)
		{
		    for(j = i; j < 3; j++)
			char_array_3[j] = '\0';

		    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		    char_array_4[3] = char_array_3[2] & 0x3f;

		    for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		    while((i++ < 3))
			ret += '=';

		}

	    return ret;

	}



    };

    inline std::ostream& operator<< (std::ostream& os, const SWWEBagent::ParameterList& p) {
	os << p.str();
	return os;
    }

    /** base64 encode and decode functions
     * from <http://www.adp-gmbh.ch/cpp/common/base64.html>
     */
    inline std::string SWWEBagent::base64_encode (std::string encodeMe) {
	static const std::string base64_chars = 
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	    "abcdefghijklmnopqrstuvwxyz"
	    "0123456789+/";

	char const* bytes_to_encode = &encodeMe[0];
	unsigned int in_len = encodeMe.size();

	std::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--) {
	    char_array_3[i++] = *(bytes_to_encode++);
	    if (i == 3) {
		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for(i = 0; (i <4) ; i++)
		    ret += base64_chars[char_array_4[i]];
		i = 0;
	    }
	}

	if (i)
	    {
		for(j = i; j < 3; j++)
		    char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
		    ret += base64_chars[char_array_4[j]];

		while((i++ < 3))
		    ret += '=';

	    }

	return ret;
    }

    static inline bool is_base64 (unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
    }

    inline std::string SWWEBagent::base64_decode(std::string const& encoded_string) {
	// http://www.adp-gmbh.ch/cpp/common/base64.html
	static const std::string base64_chars = 
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	    "abcdefghijklmnopqrstuvwxyz"
	    "0123456789+/";
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;

	while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
	    char_array_4[i++] = encoded_string[in_]; in_++;
	    if (i ==4) {
		for (i = 0; i <4; i++)
		    char_array_4[i] = base64_chars.find(char_array_4[i]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (i = 0; (i < 3); i++)
		    ret += char_array_3[i];
		i = 0;
	    }
	}

	if (i) {
	    for (j = i; j <4; j++)
		char_array_4[j] = 0;

	    for (j = 0; j <4; j++)
		char_array_4[j] = base64_chars.find(char_array_4[j]);

	    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
	    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
	    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

	    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
    }

} // namespace w3c_sw

#if HTTP_CLIENT == SWOb_ASIO
  #include "../interface/WEBagent_boostASIO.hpp"
#else
  #warning No web client to include.
#endif

#endif /* !INCLUDED_interface_WEBagent_hpp */
