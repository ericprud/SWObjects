/* ShExShapeMap.cpp - shape map parsing and evaluation. */

#include "ShExShapeMap.hpp"
#include "MiniJSON.hpp"

#include <cctype>

namespace w3c_sw {
namespace ShEx {

    namespace {

	/** Scanner/parser over the compact shape-map syntax. */
	struct MapParser {
	    const std::string& text;
	    size_t pos;
	    AtomFactory* atomFactory;
	    const PrefixEnv& nodeEnv;
	    const PrefixEnv& shapeEnv;
	    PatternMatcher& matcher;

	    MapParser (const std::string& text, AtomFactory* atomFactory,
		       const PrefixEnv& nodeEnv, const PrefixEnv& shapeEnv,
		       PatternMatcher& matcher)
		: text(text), pos(0), atomFactory(atomFactory),
		  nodeEnv(nodeEnv), shapeEnv(shapeEnv), matcher(matcher) {  }

	    void error (const std::string& msg) {
		std::stringstream ss;
		ss << msg << " at offset " << pos << " in \"" << text << "\"";
		throw ShapeMapError(ss.str());
	    }

	    void skipWS () {
		while (pos < text.size()) {
		    char c = text[pos];
		    if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
			++pos;
		    else if (c == '#') {
			while (pos < text.size() && text[pos] != '\n')
			    ++pos;
		    } else
			break;
		}
	    }
	    bool atEnd () {
		skipWS();
		return pos >= text.size();
	    }
	    char peek () {
		skipWS();
		return pos < text.size() ? text[pos] : '\0';
	    }
	    bool tryWord (const char* w) {
		skipWS();
		size_t len = strlen(w);
		if (text.compare(pos, len, w) != 0)
		    return false;
		char after = pos + len < text.size() ? text[pos + len] : '\0';
		if (isalnum(after) || after == '_')
		    return false;
		pos += len;
		return true;
	    }

	    const URI* iriref (const PrefixEnv& env) {
		// at '<'
		size_t close = text.find('>', pos);
		if (close == std::string::npos)
		    error("unterminated IRI");
		std::string rel = text.substr(pos + 1, close - pos - 1);
		pos = close + 1;
		return atomFactory->getURI(libwww::GetAbsoluteURIstring(rel, env.base));
	    }

	    bool pnameStartChar (char c) {
		return isalnum((unsigned char)c) || c == '_' || (unsigned char)c >= 0x80;
	    }
	    bool pnameChar (char c) {
		return pnameStartChar(c) || c == '-' || c == '.';
	    }

	    const URI* pname (const PrefixEnv& env) {
		size_t start = pos;
		while (pos < text.size() && pnameChar(text[pos]))
		    ++pos;
		if (pos >= text.size() || text[pos] != ':')
		    error("expected ':' in prefixed name");
		std::string prefix = text.substr(start, pos - start);
		++pos;
		size_t lstart = pos;
		while (pos < text.size() && (pnameChar(text[pos]) || text[pos] == '%'))
		    ++pos;
		std::string local = text.substr(lstart, pos - lstart);
		if (env.namespaces == NULL)
		    error("no prefixes available for \"" + prefix + ":\"");
		const URI* ns = env.namespaces->get(prefix, true);
		if (ns == NULL)
		    error("unknown prefix \"" + prefix + ":\"");
		return atomFactory->getURI(ns->getLexicalValue() + local);
	    }

	    const TTerm* literal () {
		// at '"' or '\''
		char quote = text[pos++];
		std::string lex;
		while (pos < text.size() && text[pos] != quote) {
		    char c = text[pos++];
		    if (c == '\\' && pos < text.size()) {
			char e = text[pos++];
			switch (e) {
			case 'n': lex += '\n'; break;
			case 't': lex += '\t'; break;
			case 'r': lex += '\r'; break;
			case '\\': lex += '\\'; break;
			case '"': lex += '"'; break;
			case '\'': lex += '\''; break;
			default: lex += e;
			}
		    } else
			lex += c;
		}
		if (pos >= text.size())
		    error("unterminated literal");
		++pos; // closing quote
		if (pos < text.size() && text[pos] == '@') {
		    size_t start = ++pos;
		    while (pos < text.size() && (isalnum((unsigned char)text[pos]) || text[pos] == '-'))
			++pos;
		    return atomFactory->getRDFLiteral(lex, NULL,
						      new LANGTAG(text.substr(start, pos - start)));
		}
		if (pos + 1 < text.size() && text[pos] == '^' && text[pos+1] == '^') {
		    pos += 2;
		    const URI* dt = peek() == '<' ? iriref(nodeEnv) : pname(nodeEnv);
		    return atomFactory->getRDFLiteral(lex, dt, NULL);
		}
		return atomFactory->getRDFLiteral(lex, NULL, NULL);
	    }

	    /** One term inside a {s p o} triple pattern.
	     * kind: 0 = FOCUS, 1 = wildcard, 2 = fixed term. */
	    const TTerm* patternTerm (int& kind) {
		skipWS();
		if (tryWord("FOCUS")) {
		    kind = 0;
		    return NULL;
		}
		if (peek() == '_' && (pos + 1 >= text.size() || text[pos+1] != ':')) {
		    ++pos;
		    kind = 1;
		    return NULL;
		}
		kind = 2;
		if (tryWord("a"))
		    return atomFactory->getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
		char c = peek();
		if (c == '<')
		    return iriref(nodeEnv);
		if (c == '"' || c == '\'')
		    return literal();
		return pname(nodeEnv);
	    }

	    /** The node side of an association. Appends the fixed node(s). */
	    void nodes (std::vector<const TTerm*>& into) {
		char c = peek();
		if (c == '{') {
		    ++pos;
		    int skind, pkind, okind;
		    const TTerm* s = patternTerm(skind);
		    const TTerm* p = patternTerm(pkind);
		    const TTerm* o = patternTerm(okind);
		    skipWS();
		    if (peek() != '}')
			error("expected '}'");
		    ++pos;
		    if (pkind != 2)
			error("triple pattern predicate must be an IRI");
		    if ((skind == 0) == (okind == 0))
			error("triple pattern needs FOCUS in subject or object");
		    if (skind == 0) // subject is FOCUS
			matcher.matchFocusSubject(p, okind == 2 ? o : NULL, into);
		    else // object is FOCUS
			matcher.matchFocusObject(skind == 2 ? s : NULL, p, into);
		    return;
		}
		if (c == '_' && pos + 1 < text.size() && text[pos+1] == ':') {
		    pos += 2;
		    size_t start = pos;
		    while (pos < text.size() && pnameChar(text[pos]))
			++pos;
		    // bnode labels are only meaningful with a shared map; the
		    // caller resolves them via the data's bnode map when known
		    into.push_back(atomFactory->getBNode(text.substr(start, pos - start),
							 bnodeMap));
		    return;
		}
		if (c == '<') {
		    into.push_back(iriref(nodeEnv));
		    return;
		}
		if (c == '"' || c == '\'') {
		    into.push_back(literal());
		    return;
		}
		into.push_back(pname(nodeEnv));
	    }
	    TTerm::String2BNode* bnodeMap;

	    /** The shape side: NULL for START. */
	    const TTerm* shape () {
		if (tryWord("START"))
		    return NULL;
		char c = peek();
		if (c == '<')
		    return iriref(shapeEnv);
		if (c == '_' && pos + 1 < text.size() && text[pos+1] == ':')
		    error("blank node shape labels are not supported in shape maps");
		return pname(shapeEnv);
	    }

	    std::vector<Association> parse (TTerm::String2BNode* dataBNodeMap) {
		bnodeMap = dataBNodeMap;
		std::vector<Association> ret;
		while (!atEnd()) {
		    std::vector<const TTerm*> ns;
		    nodes(ns);
		    skipWS();
		    if (peek() != '@')
			error("expected '@'");
		    ++pos;
		    bool negated = peek() == '!';
		    if (negated)
			++pos;
		    const TTerm* sh = shape();
		    for (std::vector<const TTerm*>::const_iterator it = ns.begin();
			 it != ns.end(); ++it)
			ret.push_back(Association(*it, sh, negated));
		    skipWS();
		    if (peek() == ',') {
			++pos;
			continue;
		    }
		    break;
		}
		if (!atEnd())
		    error("trailing content");
		return ret;
	    }
	};
    } // namespace

    void LocalPatternMatcher::matchFocusSubject (const TTerm* p, const TTerm* o,
						 std::vector<const TTerm*>& into) {
	for (std::vector<const TriplePattern*>::const_iterator it = data.begin();
	     it != data.end(); ++it)
	    if ((*it)->getP() == p && (o == NULL || (*it)->getO() == o))
		into.push_back((*it)->getS());
    }

    void LocalPatternMatcher::matchFocusObject (const TTerm* s, const TTerm* p,
						std::vector<const TTerm*>& into) {
	for (std::vector<const TriplePattern*>::const_iterator it = data.begin();
	     it != data.end(); ++it)
	    if ((*it)->getP() == p && (s == NULL || (*it)->getS() == s))
		into.push_back((*it)->getO());
    }

    std::vector<Association> parseQueryMap (const std::string& text,
					    AtomFactory* atomFactory,
					    const PrefixEnv& nodeEnv,
					    const PrefixEnv& shapeEnv,
					    PatternMatcher& matcher,
					    TTerm::String2BNode* dataBNodeMap) {
	MapParser p(text, atomFactory, nodeEnv, shapeEnv, matcher);
	TTerm::String2BNode transientBNodes;
	return p.parse(dataBNodeMap != NULL ? dataBNodeMap : &transientBNodes);
    }

    std::vector<Association> parseJsonMap (const std::string& text,
					   AtomFactory* atomFactory) {
	MiniJSON::Value doc = MiniJSON::parse(text);
	if (!doc.isArray())
	    throw ShapeMapError("expected a JSON array of {node, shape} objects");
	std::vector<Association> ret;
	for (std::vector<MiniJSON::Value>::const_iterator it = doc.array.begin();
	     it != doc.array.end(); ++it) {
	    if (!it->isObject())
		throw ShapeMapError("expected {node, shape} object");
	    std::string node = it->getString("node");
	    std::string shape = it->getString("shape");
	    if (node.empty() || shape.empty())
		throw ShapeMapError("association needs both node and shape");
	    ret.push_back(Association(atomFactory->getURI(node),
				      shape == "START" ? NULL : atomFactory->getURI(shape),
				      false));
	}
	return ret;
    }

    std::vector<AssociationResult> evaluate (Validator& validator,
					     const std::vector<Association>& associations) {
	std::vector<AssociationResult> ret;
	for (std::vector<Association>::const_iterator it = associations.begin();
	     it != associations.end(); ++it)
	    ret.push_back(AssociationResult(*it, validator.validate(it->node, it->shape)));
	return ret;
    }

} // namespace ShEx
} // namespace w3c_sw
