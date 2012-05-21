/* JSONSerializer.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: JSONSerializer.hpp,v 1.1 2008-08-26 05:30:49 jnorthru Exp $
 */

#ifndef JSONSerializer_H
#define JSONSerializer_H

#include <stack>

namespace w3c_sw {

    class JSONSerializer {
    public:
	typedef enum {Container_Error, Container_Map, Container_List} e_Container;
    protected:
	std::ostream& ret;
	const char* tab;
	size_t depth;
	std::stack<e_Container> tags;
	bool needsComma;

	void checkNesting (e_Container container, std::string func, std::string tag) {
	    if (tags.top() != container)
		throw std::runtime_error(std::string("@@") + func + tag);
	}
	void checkNesting (e_Container container, std::string func) {
	    if (tags.top() != container)
		throw std::runtime_error(std::string("@@") + func);
	}
    public:
	struct Attributes : public std::map<std::string, std::string> {  };
	static std::string escapeQuotedData (std::string ret) {
	    for (size_t p = ret.find_first_of("\""); 
		 p != std::string::npos; p = ret.find_first_of("\"", p + 2))
		ret.replace(p, 1, "\\\"");
	    return ret;
	}

	void lead () {
	    ret << std::endl;
	    for (size_t i = 0; i < depth; i++)
		ret << tab;
	}
	void comma () {
	    if (needsComma)
		ret << ",";
	    needsComma = true;
	    lead();
	}
	void literal (std::string val) {
	    checkNesting(Container_List, "literal");
	    comma();
	    ret << "\"" << escapeQuotedData(val) << "\"";
	}
	void literal (const char* val) {
	    checkNesting(Container_List, "literal");
	    comma();
	    ret << "\"" << escapeQuotedData(val) << "\"";
	}
	void literal (std::string attr, std::string val) {
	    checkNesting(Container_Map, "literal", attr);
	    comma();
	    ret << "\"" << attr << "\": \"" << escapeQuotedData(val) << "\"";
	}
	void literal (const char* attr, const char* val) {
	    checkNesting(Container_Map, "literal", attr);
	    comma();
	    ret << "\"" << attr << "\": \"" << escapeQuotedData(val) << "\"";
	}
	void literal (int val) {
	    checkNesting(Container_List, "literal");
	    comma();
	    ret << "\"" << val << "\"";
	}
	void literal (std::string attr, int val) {
	    checkNesting(Container_Map, "literal", attr);
	    comma();
	    ret << " " << attr << "=\"" << val << "\"";
	}
	void literal (float val) {
	    checkNesting(Container_List, "literal");
	    comma();
	    ret << "\"" << val << "\"";
	}
	void literal (std::string attr, float val) {
	    checkNesting(Container_Map, "literal", attr);
	    comma();
	    ret << " " << attr << "=\"" << val << "\"";
	}
	void literal (double val) {
	    checkNesting(Container_List, "literal");
	    comma();
	    ret << "\"" << val << "\"";
	}
	void literal (std::string attr, double val) {
	    checkNesting(Container_Map, "literal", attr);
	    comma();
	    ret << " " << attr << "=\"" << val << "\"";
	}
	void literal (bool val) {
	    checkNesting(Container_List, "literal");
	    comma();
	    ret << "\"" << val << "\"";
	}
	void literal (std::string attr, bool val) {
	    checkNesting(Container_Map, "literal", attr);
	    comma();
	    ret << " " << attr << "=\"" << val << "\"";
	}

	void openMap () {
	    checkNesting(Container_List, "openMap");
	    comma();
	    needsComma = false;
	    ret << "{";
	    tags.push(Container_Map);
	    depth++;
	}
	void openMap (std::string tag) {
	    checkNesting(Container_Map, "openMap", tag);
	    comma();
	    needsComma = false;
	    ret << "\"" << tag << "\": {";
	    tags.push(Container_Map);
	    depth++;
	}
	void openList () {
	    checkNesting(Container_List, "openList");
	    comma();
	    needsComma = false;
	    ret << "[";
	    tags.push(Container_List);
	    depth++;
	}
	void openList (std::string tag) {
	    checkNesting(Container_Map, "openList", tag);
	    comma();
	    needsComma = false;
	    ret << "\"" << tag << "\": [";
	    tags.push(Container_List);
	    depth++;
	}

	void closeMap () {
	    checkNesting(Container_Map, "closeMap");
	    --depth;
	    tags.pop();
	    lead();
	    needsComma = true;
	    ret << "}";
	}
	void closeList () {
	    checkNesting(Container_List, "closeList");
	    --depth;
	    tags.pop();
	    lead();
	    needsComma = true;
	    ret << "]";
	}
    public:
	JSONSerializer (std::ostream& ret, e_Container container, const char* p_tab = "    ") : 
	    ret(ret), tab(p_tab), depth(1), needsComma(false) {
	    ret << (container == Container_Map ? "{" : "["); // "]" "}"
	    tags.push(container);
	}
    };

} // namespace w3c_sw

#endif // JSONSerializer_H

