/* XMLSerializer.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: XMLSerializer.hpp,v 1.1 2008-08-26 05:30:49 jnorthru Exp $
 */

#ifndef XMLSerializer_H
#define XMLSerializer_H

#include <stack>

class XMLSerializer {
protected:
    std::stringstream ret;
    const char* tab;
    size_t depth;
    std::stack<std::string> tags;
    std::string needs;
public:
    void lead () {
	if (needs.size())
	    ret << needs << std::endl;
	needs = "";
	for (size_t i = 0; i < depth; i++)
	    ret << tab;
    }
    void open (std::string tag) {
	lead();
	ret << "<" << tag;
	needs = ">";
	tags.push(tag);
	depth++;
    }
    void attribute (std::string attr, std::string val) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	ret << " " << attr << "=\"" << val << "\"";
    }
    void attribute (std::string attr, int val) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	ret << " " << attr << "=\"" << val << "\"";
    }
    void attribute (std::string attr, void* ptr) {
	if (!needs.size())
	    throw(std::runtime_error("no open tag to recieve attribute"));
	ret << " " << attr << "=\"" << ptr << "\"";
    }
    void empty (std::string tag) {
	lead();
	ret << "<" << tag;
	needs = "/>";
    }
    void leaf (std::string tag, std::string contents) {
	lead();
	ret << "<" << tag;
	needs = ">" + contents + "</" + tag + ">";
    }
    void leaf (std::string tag, int p_value) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << p_value;
	needs = ">" + tmp.str() + "</" + tag + ">";
    }
    void leaf (std::string tag, float p_value) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << p_value;
	needs = ">" + tmp.str() + "</" + tag + ">";
    }
    void leaf (std::string tag, double p_value) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << p_value;
	needs = ">" + tmp.str() + "</" + tag + ">";
    }
    void leaf (std::string tag, bool p_value) {
	lead();
	ret << "<" << tag;
	std::stringstream tmp;
	tmp << (p_value ? "true" : "false");
	needs = ">" + tmp.str() + "</" + tag + ">";
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
    std::string getString () { return ret.str(); }
};

#endif // XMLSerializer_H

