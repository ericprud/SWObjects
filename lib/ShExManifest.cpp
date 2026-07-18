/* ShExManifest.cpp - JSON/YAML manifest reading and entry evaluation. */

#include "ShExManifest.hpp"
#include "MiniJSON.hpp"
#include "ShExCParser.hpp"
#include "TurtleParser.hpp"
#include "RdfDB.hpp"

#include <fstream>
#include <cctype>
#include <unistd.h>

namespace w3c_sw {
namespace ShEx {

    namespace {

	std::string readFileOrThrow (const std::string& path) {
	    std::ifstream in(path.c_str(), std::ios::binary);
	    if (!in)
		throw ManifestError("unable to open " + path);
	    std::stringstream ss;
	    ss << in.rdbuf();
	    return ss.str();
	}

	std::string rstrip (std::string s) {
	    while (!s.empty() && (s[s.size()-1] == ' ' || s[s.size()-1] == '\t'
				  || s[s.size()-1] == '\r'))
		s.resize(s.size()-1);
	    return s;
	}
	std::string strip (std::string s) {
	    size_t b = s.find_first_not_of(" \t");
	    if (b == std::string::npos)
		return "";
	    return rstrip(s.substr(b));
	}

	/* ------------------------------------------------ the YAML subset */

	struct YamlLines {
	    std::vector<std::string> lines;
	    YamlLines (const std::string& text) {
		std::string cur;
		for (size_t i = 0; i <= text.size(); ++i) {
		    if (i == text.size() || text[i] == '\n') {
			if (!cur.empty() && cur[cur.size()-1] == '\r')
			    cur.resize(cur.size()-1);
			lines.push_back(cur);
			cur.clear();
		    } else
			cur += text[i];
		}
	    }
	    static size_t indentOf (const std::string& line) {
		size_t i = 0;
		while (i < line.size() && line[i] == ' ')
		    ++i;
		return i;
	    }
	};

	std::string unescapeDoubleQuoted (const std::string& s, size_t lineNo) {
	    std::string ret;
	    for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] != '\\') {
		    ret += s[i];
		    continue;
		}
		if (++i >= s.size())
		    throw ManifestError("truncated escape in quoted scalar");
		switch (s[i]) {
		case 'n': ret += '\n'; break;
		case 't': ret += '\t'; break;
		case 'r': ret += '\r'; break;
		case '"': ret += '"'; break;
		case '\\': ret += '\\'; break;
		default: {
		    std::stringstream ss;
		    ss << "unsupported escape \\" << s[i] << " on line " << lineNo;
		    throw ManifestError(ss.str());
		}
		}
	    }
	    return ret;
	}

	/** Parse the YAML subset used by shex-webapp manifests: a top-level
	 * sequence of flat mappings whose values are plain scalars, quoted
	 * scalars or '|' literal block scalars. */
	std::vector<std::map<std::string, std::string> > parseYaml (const std::string& text) {
	    YamlLines yl(text);
	    std::vector<std::map<std::string, std::string> > items;
	    size_t i = 0;
	    while (i < yl.lines.size()) {
		std::string line = yl.lines[i];
		std::string t = strip(line);
		if (t.empty() || t == "---" || t[0] == '#') {
		    ++i;
		    continue;
		}
		if (line.compare(0, 2, "- ") != 0 && t != "-") {
		    std::stringstream ss;
		    ss << "expected a top-level \"- \" sequence item on line " << i+1
		       << ": \"" << line << "\"";
		    throw ManifestError(ss.str());
		}
		// one sequence item: its keys sit at the indent of the first key
		items.push_back(std::map<std::string, std::string>());
		std::map<std::string, std::string>& item = items.back();
		// rewrite "- key: value" as an indented "  key: value"
		yl.lines[i] = "  " + line.substr(2);
		size_t itemIndent = YamlLines::indentOf(yl.lines[i]);
		while (i < yl.lines.size()) {
		    std::string cur = yl.lines[i];
		    std::string ct = strip(cur);
		    if (ct.empty()) {
			++i;
			continue;
		    }
		    if (cur.compare(0, 2, "- ") == 0 || ct == "---")
			break; // next item / document
		    size_t indent = YamlLines::indentOf(cur);
		    if (indent < itemIndent)
			break;
		    if (ct[0] == '#') {
			++i;
			continue;
		    }
		    size_t colon = cur.find(':', indent);
		    if (colon == std::string::npos) {
			std::stringstream ss;
			ss << "expected \"key: value\" on line " << i+1 << ": \"" << cur << "\"";
			throw ManifestError(ss.str());
		    }
		    std::string key = strip(cur.substr(indent, colon - indent));
		    std::string value = strip(cur.substr(colon + 1));
		    ++i;
		    if (value == "|" || value == "|-") {
			bool clip = value == "|-";
			// literal block scalar: lines indented past the key
			std::vector<std::string> block;
			size_t blockIndent = 0;
			while (i < yl.lines.size()) {
			    std::string bl = yl.lines[i];
			    if (strip(bl).empty()) { // blank line inside block
				block.push_back("");
				++i;
				continue;
			    }
			    size_t bIndent = YamlLines::indentOf(bl);
			    if (bIndent <= indent)
				break;
			    if (blockIndent == 0)
				blockIndent = bIndent;
			    block.push_back(bl.size() >= blockIndent
					    ? bl.substr(blockIndent) : "");
			    ++i;
			}
			// drop trailing blank lines, keep one final newline
			while (!block.empty() && block.back().empty())
			    block.pop_back();
			std::string joined;
			for (size_t b = 0; b < block.size(); ++b)
			    joined += block[b] + "\n";
			if (clip && !joined.empty())
			    joined.resize(joined.size()-1);
			item[key] = joined;
		    } else if (!value.empty() && value[0] == '"') {
			if (value.size() < 2 || value[value.size()-1] != '"')
			    throw ManifestError("unterminated quoted scalar: " + value);
			item[key] = unescapeDoubleQuoted(value.substr(1, value.size()-2), i);
		    } else if (!value.empty() && value[0] == '\'') {
			if (value.size() < 2 || value[value.size()-1] != '\'')
			    throw ManifestError("unterminated quoted scalar: " + value);
			std::string body = value.substr(1, value.size()-2);
			std::string unesc;
			for (size_t c = 0; c < body.size(); ++c) {
			    unesc += body[c];
			    if (body[c] == '\'' && c+1 < body.size() && body[c+1] == '\'')
				++c;
			}
			item[key] = unesc;
		    } else
			item[key] = value;
		}
	    }
	    return items;
	}

	ManifestEntry entryFromKeyValues (const std::map<std::string, std::string>& kv,
					  size_t index) {
	    ManifestEntry e;
	    std::map<std::string, std::string>::const_iterator it;
	    if ((it = kv.find("schemaLabel")) != kv.end()) e.schemaLabel = it->second;
	    if ((it = kv.find("schema")) != kv.end()) e.schema = it->second;
	    if ((it = kv.find("schemaURL")) != kv.end()) e.schemaURL = it->second;
	    if ((it = kv.find("dataLabel")) != kv.end()) e.dataLabel = it->second;
	    if ((it = kv.find("data")) != kv.end()) e.data = it->second;
	    if ((it = kv.find("dataURL")) != kv.end()) e.dataURL = it->second;
	    if ((it = kv.find("queryMap")) != kv.end()) e.queryMap = it->second;
	    if ((it = kv.find("queryMapURL")) != kv.end()) e.queryMapURL = it->second;
	    std::string status;
	    if ((it = kv.find("status")) != kv.end()) status = it->second;
	    std::stringstream where;
	    where << "entry " << index;
	    if (status == "conformant")
		e.expectConformant = true;
	    else if (status == "nonconformant")
		e.expectConformant = false;
	    else
		throw ManifestError(where.str() + ": status must be conformant or nonconformant, got \""
				    + status + "\"");
	    if (e.schema.empty() && e.schemaURL.empty())
		throw ManifestError(where.str() + " needs schema or schemaURL");
	    if (e.data.empty() && e.dataURL.empty())
		throw ManifestError(where.str() + " needs data or dataURL");
	    if (e.queryMap.empty() && e.queryMapURL.empty())
		throw ManifestError(where.str() + " needs queryMap or queryMapURL");
	    return e;
	}
    } // namespace

    Manifest Manifest::parse (const std::string& text, const std::string& path) {
	Manifest m;
	size_t slash = path.find_last_of('/');
	m.directory = slash == std::string::npos ? "" : path.substr(0, slash + 1);
	if (path.compare(0, 1, "/") == 0)
	    m.baseURI = "file://" + path;
	else {
	    char cwd[4096];
	    m.baseURI = getcwd(cwd, sizeof cwd) != NULL
		? "file://" + std::string(cwd) + "/" + path
		: path;
	}

	// sniff: JSON starts with '[' or '{'
	size_t first = text.find_first_not_of(" \t\r\n");
	bool isJson = first != std::string::npos
	    && (text[first] == '[' || text[first] == '{');

	if (isJson) {
	    MiniJSON::Value doc = MiniJSON::parse(text);
	    if (!doc.isArray())
		throw ManifestError("expected a JSON array of entries");
	    for (size_t i = 0; i < doc.array.size(); ++i) {
		const MiniJSON::Value& o = doc.array[i];
		if (!o.isObject())
		    throw ManifestError("expected entry objects");
		std::map<std::string, std::string> kv;
		for (std::vector<std::pair<std::string, MiniJSON::Value> >::const_iterator
			 f = o.object.begin(); f != o.object.end(); ++f)
		    if (f->second.isString())
			kv[f->first] = f->second.string;
		m.entries.push_back(entryFromKeyValues(kv, i));
	    }
	} else {
	    std::vector<std::map<std::string, std::string> > items = parseYaml(text);
	    for (size_t i = 0; i < items.size(); ++i)
		m.entries.push_back(entryFromKeyValues(items[i], i));
	}
	return m;
    }

    Manifest Manifest::load (const std::string& path) {
	return parse(readFileOrThrow(path), path);
    }

    EntryOutcome runEntry (const ManifestEntry& entry, const Manifest& manifest,
			   AtomFactory& atomFactory) {
	EntryOutcome outcome;
	try {
	    // ---- schema
	    std::string schemaText = entry.schema;
	    std::string schemaBase = manifest.baseURI;
	    if (!entry.schemaURL.empty()) {
		schemaText = readFileOrThrow(manifest.directory + entry.schemaURL);
		schemaBase = libwww::GetAbsoluteURIstring(entry.schemaURL, manifest.baseURI);
	    }
	    Schema schema;
	    ShExDriver schemaDriver(schemaBase, &atomFactory);
	    {
		IStreamContext istr(schemaText, IStreamContext::STRING);
		istr.nameStr = schemaBase;
		schemaDriver.parse(istr, &schema);
	    }
	    schema.checkStructure();

	    // ---- data
	    std::string dataText = entry.data;
	    std::string dataBase = manifest.baseURI;
	    if (!entry.dataURL.empty()) {
		dataText = readFileOrThrow(manifest.directory + entry.dataURL);
		dataBase = libwww::GetAbsoluteURIstring(entry.dataURL, manifest.baseURI);
	    }
	    RdfDB db;
	    TurtleDriver dataDriver(dataBase, &atomFactory);
	    {
		IStreamContext istr(dataText, IStreamContext::STRING);
		istr.nameStr = dataBase;
		dataDriver.parse(istr, db.ensureGraph(DefaultGraph));
	    }
	    BasicGraphPattern* graph = db.ensureGraph(DefaultGraph);

	    // ---- shape map
	    std::string mapText = entry.queryMap;
	    if (!entry.queryMapURL.empty())
		mapText = readFileOrThrow(manifest.directory + entry.queryMapURL);
	    PrefixEnv nodeEnv(dataBase, dataDriver.getNamespaceMap());
	    PrefixEnv shapeEnv(schemaBase, schemaDriver.getNamespaceMap());
	    std::vector<Association> associations
		= parseQueryMap(mapText, &atomFactory, nodeEnv, shapeEnv, *graph);

	    // ---- validate
	    Validator validator(schema, *graph);
	    outcome.results = evaluate(validator, associations);
	    outcome.allAsAsserted = true;
	    for (std::vector<AssociationResult>::const_iterator it = outcome.results.begin();
		 it != outcome.results.end(); ++it)
		outcome.allAsAsserted = outcome.allAsAsserted && it->asAsserted;
	    outcome.statusMatched = outcome.allAsAsserted == entry.expectConformant;
	} catch (std::exception& e) {
	    outcome.error = e.what();
	} catch (std::string& e) {
	    outcome.error = e;
	}
	return outcome;
    }

    std::vector<size_t> expandRanges (const std::string& spec, size_t n) {
	std::vector<size_t> ret;
	size_t pos = 0;
	bool sawRange = false;
	while (pos <= spec.size()) {
	    size_t comma = spec.find(',', pos);
	    std::string tok = strip(spec.substr(pos, comma == std::string::npos
						? std::string::npos : comma - pos));
	    pos = comma == std::string::npos ? spec.size() + 1 : comma + 1;
	    if (tok.empty()) {
		if (comma == std::string::npos && sawRange)
		    break; // trailing ',' per the grammar
		throw ManifestError("empty range in \"" + spec + "\"");
	    }
	    sawRange = true;
	    size_t dash = tok.find('-');
	    std::string a = dash == std::string::npos ? tok : strip(tok.substr(0, dash));
	    std::string b = dash == std::string::npos ? tok : strip(tok.substr(dash + 1));
	    bool aStar = a == "*", bStar = b == "*";
	    if (!aStar && (a.empty() || a.find_first_not_of("0123456789") != std::string::npos))
		throw ManifestError("bad index \"" + a + "\" in \"" + spec + "\"");
	    if (!bStar && (b.empty() || b.find_first_not_of("0123456789") != std::string::npos))
		throw ManifestError("bad index \"" + b + "\" in \"" + spec + "\"");
	    if (aStar || bStar) {
		// a '*' endpoint selects everything
		for (size_t i = 0; i < n; ++i)
		    ret.push_back(i);
		continue;
	    }
	    size_t lo = strtoul(a.c_str(), NULL, 10);
	    size_t hi = strtoul(b.c_str(), NULL, 10);
	    if (lo <= hi) {
		for (size_t i = lo; i <= hi; ++i)
		    if (i < n)
			ret.push_back(i);
	    } else {
		for (size_t i = lo + 1; i-- > hi; )
		    if (i < n)
			ret.push_back(i);
	    }
	}
	return ret;
    }

} // namespace ShEx
} // namespace w3c_sw
