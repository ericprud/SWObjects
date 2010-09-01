/* XMLSerializer.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: XMLSerializer.hpp,v 1.1 2008-08-26 05:30:49 jnorthru Exp $
 */

#ifndef XMLSerializer_H
#define XMLSerializer_H

#include <stack>

namespace w3c_sw {

class XMLSerializer {
protected:
    std::stringstream ret;
    const char* tab;
    size_t depth;
    std::stack<std::string> tags;
    std::string needs;
public:
    struct Attributes : public std::map<std::string, std::string> {
	// I'm not convinced these are useful:
// 	Attributes () : std::map<std::string, std::string>()
// 	{  }
// 	Attributes (std::string attr, std::string value) : std::map<std::string, std::string>() {
// 	    insert(std::pair<std::string, std::string>(attr, value));
// 	}
// 	Attributes& operator += (std::pair<const char*, const char*> p) {
// 	    insert(std::pair<std::string, std::string>(p.first, p.second));
// 	    return *this;
// 	}
    };
    static std::string escapeCharData (std::string escapeMe) {
	std::string ret = escapeMe;
	for (size_t p = ret.find_first_of("&<>"); 
	     p != std::string::npos; p = ret.find_first_of("&<>", p + 1))
	    ret.replace(p, 1, 
			ret[p] == '&' ? "&amp;" : 
			ret[p] == '<' ? "&lt;" : 
			ret[p] == '>' ? "&gt;" : "huh??");
	return ret;
    }
    static std::string escapeQuoteData (std::string escapeMe) {
	std::string ret = escapeCharData(escapeMe);
	for (size_t p = ret.find_first_of("\""); 
	     p != std::string::npos; p = ret.find_first_of("\"", p + 1))
	    ret.replace(p, 1, "&quot;");
	return ret;
    }

    void lead () {
	if (needs.size())
	    ret << needs << std::endl;
	needs = "";
	for (size_t i = 0; i < depth; i++)
	    ret << tab;
    }
    void attribute (std::string attr, std::string val) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	ret << " " << attr << "=\"" << escapeQuoteData(val) << "\"";
    }
    void attribute (std::string attr, int val) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	ret << " " << attr << "=\"" << val << "\"";
    }
    /** attributePtr - for debug messages.
     * Calling this attribute(string, void*) cause MSVC to call the void*
     * variant with strings and ints (the declarations above).
     */
    void attributePtr (std::string attr, void* ptr) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	ret << " " << attr << "=\"" << ptr << "\"";
    }
    void attributes (Attributes attrs) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	for (Attributes::const_iterator attr = attrs.begin();
	     attr != attrs.end(); ++attr)
	    attribute(attr->first, attr->second);
    }

    void open (std::string tag, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	needs = ">";
	attributes(attrs);
	tags.push(tag);
	depth++;
    }
    void empty (std::string tag, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	needs = "/>";
	attributes(attrs);
    }
    void charData (std::string contents) {
	if (needs.size())
	    ret << needs << std::endl;
	needs = "";
	ret << escapeCharData(contents);
    }
    void leaf (std::string tag, std::string contents, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	needs = ">" + escapeCharData(contents) + "</" + tag + ">";
	attributes(attrs);
    }
    void leaf (std::string tag, int p_value, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << p_value;
	needs = ">" + tmp.str() + "</" + tag + ">";
	attributes(attrs);
    }
    void leaf (std::string tag, float p_value, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << p_value;
	needs = ">" + tmp.str() + "</" + tag + ">";
	attributes(attrs);
    }
    void leaf (std::string tag, double p_value, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << p_value;
	needs = ">" + tmp.str() + "</" + tag + ">";
	attributes(attrs);
    }
    void leaf (std::string tag, bool p_value, Attributes attrs = Attributes()) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << (p_value ? "true" : "false");
	needs = ">" + tmp.str() + "</" + tag + ">";
	attributes(attrs);
    }
    void close () {
	--depth;
	std::string tag = tags.top();
	tags.pop();
	lead();
	ret << "</" << tag << ">" << std::endl;
    }
public:
    XMLSerializer (const char* p_tab = "  ") : 
	tab(p_tab), depth(0), needs("") {  }
    std::string str () {
	ret << needs;
	return ret.str();
    }
    void str (std::string seed) {
	ret << needs;
	ret.str(seed);
    }
};

}

#endif // XMLSerializer_H

