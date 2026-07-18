/* MiniJSON - a small self-contained JSON reader.
 *
 * Parses UTF-8 JSON text into a Value DOM (object/array/string/number/
 * boolean/null). Used by the ShEx shape-map and manifest readers; not a
 * general-purpose serializer.
 */

#ifndef SWOBJ_MINIJSON_H
#define SWOBJ_MINIJSON_H

#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

namespace w3c_sw {
namespace MiniJSON {

    struct ParseError : public std::runtime_error {
	ParseError (std::string what) : std::runtime_error("JSON: " + what) {  }
    };

    class Value {
    public:
	enum Type { Null_T, Bool_T, Number_T, String_T, Array_T, Object_T };
	Type type;
	bool boolean;
	double number;
	std::string string; // also holds the raw number text
	std::vector<Value> array;
	std::vector<std::pair<std::string, Value> > object; // insertion-ordered

	Value () : type(Null_T), boolean(false), number(0) {  }

	bool isNull () const { return type == Null_T; }
	bool isString () const { return type == String_T; }
	bool isArray () const { return type == Array_T; }
	bool isObject () const { return type == Object_T; }

	const Value* get (const std::string& key) const {
	    for (std::vector<std::pair<std::string, Value> >::const_iterator it = object.begin();
		 it != object.end(); ++it)
		if (it->first == key)
		    return &it->second;
	    return NULL;
	}
	std::string getString (const std::string& key, std::string dflt = "") const {
	    const Value* v = get(key);
	    return v != NULL && v->type == String_T ? v->string : dflt;
	}
    };

    class Parser {
	const std::string& text;
	size_t pos;

    public:
	Parser (const std::string& text) : text(text), pos(0) {  }

	Value parse () {
	    Value ret = parseValue();
	    skipWS();
	    if (pos != text.size())
		throw ParseError("trailing content at offset " + offsetStr());
	    return ret;
	}

    private:
	std::string offsetStr () const {
	    std::stringstream ss;
	    ss << pos;
	    return ss.str();
	}
	void skipWS () {
	    while (pos < text.size() &&
		   (text[pos] == ' ' || text[pos] == '\t' || text[pos] == '\r' || text[pos] == '\n'))
		++pos;
	}
	char peek () {
	    skipWS();
	    if (pos >= text.size())
		throw ParseError("unexpected end of input");
	    return text[pos];
	}
	void expect (char c) {
	    if (peek() != c)
		throw ParseError(std::string("expected '") + c + "' at offset " + offsetStr());
	    ++pos;
	}
	bool tryConsume (char c) {
	    if (pos < text.size() && peek() == c) {
		++pos;
		return true;
	    }
	    return false;
	}

	Value parseValue () {
	    switch (peek()) {
	    case '{': return parseObject();
	    case '[': return parseArray();
	    case '"': {
		Value v;
		v.type = Value::String_T;
		v.string = parseString();
		return v;
	    }
	    case 't': case 'f': return parseKeyword();
	    case 'n': return parseKeyword();
	    default: return parseNumber();
	    }
	}

	Value parseObject () {
	    Value v;
	    v.type = Value::Object_T;
	    expect('{');
	    if (tryConsume('}'))
		return v;
	    do {
		if (peek() != '"')
		    throw ParseError("expected object key at offset " + offsetStr());
		std::string key = parseString();
		expect(':');
		v.object.push_back(std::make_pair(key, parseValue()));
	    } while (tryConsume(','));
	    expect('}');
	    return v;
	}

	Value parseArray () {
	    Value v;
	    v.type = Value::Array_T;
	    expect('[');
	    if (tryConsume(']'))
		return v;
	    do {
		v.array.push_back(parseValue());
	    } while (tryConsume(','));
	    expect(']');
	    return v;
	}

	std::string parseString () {
	    expect('"');
	    std::string ret;
	    while (true) {
		if (pos >= text.size())
		    throw ParseError("unterminated string");
		char c = text[pos++];
		if (c == '"')
		    return ret;
		if (c != '\\') {
		    ret += c;
		    continue;
		}
		if (pos >= text.size())
		    throw ParseError("unterminated escape");
		char e = text[pos++];
		switch (e) {
		case '"': ret += '"'; break;
		case '\\': ret += '\\'; break;
		case '/': ret += '/'; break;
		case 'b': ret += '\b'; break;
		case 'f': ret += '\f'; break;
		case 'n': ret += '\n'; break;
		case 'r': ret += '\r'; break;
		case 't': ret += '\t'; break;
		case 'u': {
		    if (pos + 4 > text.size())
			throw ParseError("truncated \\u escape");
		    unsigned long cp = strtoul(text.substr(pos, 4).c_str(), NULL, 16);
		    pos += 4;
		    // surrogate pairs
		    if (cp >= 0xD800 && cp <= 0xDBFF && pos + 6 <= text.size()
			&& text[pos] == '\\' && text[pos+1] == 'u') {
			unsigned long lo = strtoul(text.substr(pos+2, 4).c_str(), NULL, 16);
			if (lo >= 0xDC00 && lo <= 0xDFFF) {
			    cp = 0x10000 + ((cp - 0xD800) << 10) + (lo - 0xDC00);
			    pos += 6;
			}
		    }
		    // utf-8 encode
		    if (cp < 0x80)
			ret += (char)cp;
		    else if (cp < 0x800) {
			ret += (char)(0xC0 | (cp >> 6));
			ret += (char)(0x80 | (cp & 0x3F));
		    } else if (cp < 0x10000) {
			ret += (char)(0xE0 | (cp >> 12));
			ret += (char)(0x80 | ((cp >> 6) & 0x3F));
			ret += (char)(0x80 | (cp & 0x3F));
		    } else {
			ret += (char)(0xF0 | (cp >> 18));
			ret += (char)(0x80 | ((cp >> 12) & 0x3F));
			ret += (char)(0x80 | ((cp >> 6) & 0x3F));
			ret += (char)(0x80 | (cp & 0x3F));
		    }
		    break;
		}
		default:
		    throw ParseError(std::string("invalid escape \\") + e);
		}
	    }
	}

	Value parseKeyword () {
	    Value v;
	    if (text.compare(pos, 4, "true") == 0) {
		v.type = Value::Bool_T;
		v.boolean = true;
		pos += 4;
	    } else if (text.compare(pos, 5, "false") == 0) {
		v.type = Value::Bool_T;
		v.boolean = false;
		pos += 5;
	    } else if (text.compare(pos, 4, "null") == 0) {
		v.type = Value::Null_T;
		pos += 4;
	    } else
		throw ParseError("unexpected token at offset " + offsetStr());
	    return v;
	}

	Value parseNumber () {
	    size_t start = pos;
	    if (pos < text.size() && text[pos] == '-')
		++pos;
	    while (pos < text.size() &&
		   ((text[pos] >= '0' && text[pos] <= '9') || text[pos] == '.'
		    || text[pos] == 'e' || text[pos] == 'E' || text[pos] == '+' || text[pos] == '-'))
		++pos;
	    if (pos == start)
		throw ParseError("unexpected character at offset " + offsetStr());
	    Value v;
	    v.type = Value::Number_T;
	    v.string = text.substr(start, pos - start);
	    v.number = atof(v.string.c_str());
	    return v;
	}
    };

    inline Value parse (const std::string& text) {
	Parser p(text);
	return p.parse();
    }

} // namespace MiniJSON
} // namespace w3c_sw

#endif // !SWOBJ_MINIJSON_H
