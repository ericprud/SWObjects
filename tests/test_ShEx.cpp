/* test_ShEx - run the shexSpec/shexTest test suite against the ShEx2
 * implementation in lib/ShExCParser.ypp + lib/ShExSchema.{hpp,cpp}.
 *
 * Looks for a shexTest checkout in $SHEXTEST or ./shexTest (fetched by
 * tests/fetch-test-suites.sh). Runs:
 *  - schemas/manifest.ttl        (sht:RepresentationTest: schemas must parse)
 *  - negativeSyntax/manifest.ttl (sht:NegativeSyntax: schemas must not parse)
 *  - negativeStructure/manifest.ttl (sht:NegativeStructure: schemas must not load)
 *  - validation/manifest.ttl     (sht:ValidationTest / sht:ValidationFailure)
 */

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include "SWObjects.hpp"
#include "RdfDB.hpp"
#include "TurtleParser.hpp"
#include "ShExCParser.hpp"
#include "ShExSchema.hpp"
#include "ShExShapeMap.hpp"
#include "ShExManifest.hpp"
#include "MiniJSON.hpp"

#include <fstream>
#include <cstdlib>

#include "Logging.hpp"

w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. --log '*:-1'

namespace sw = w3c_sw;

namespace {

    const char* WebRoot = "https://raw.githubusercontent.com/shexSpec/shexTest/master/";

    std::string LocalRoot; // e.g. "shexTest/"

    sw::AtomFactory F;

    /** Expose the driver's bnode map so focus bnodes can be resolved by
     * their source labels. */
    struct TurtleDriverX : public sw::TurtleDriver {
	TurtleDriverX (std::string baseURI, sw::AtomFactory* f)
	    : sw::TurtleDriver(baseURI, f) {  }
	const sw::TTerm::String2BNode& getBNodeMap () const { return bnodeMap; }
    };

    /** Map a URL under WebRoot to a local path under LocalRoot. */
    std::string toLocalPath (std::string url) {
	if (url.compare(0, strlen(WebRoot), WebRoot) == 0)
	    return LocalRoot + url.substr(strlen(WebRoot));
	return url;
    }

    std::string readFile (const std::string& path) {
	std::ifstream in(path.c_str(), std::ios::binary);
	if (!in)
	    throw std::runtime_error("unable to open " + path);
	std::stringstream ss;
	ss << in.rdbuf();
	return ss.str();
    }

    /** Simple triple lookup over a graph. */
    struct GraphIndex {
	const sw::BasicGraphPattern& g;
	GraphIndex (const sw::BasicGraphPattern& g) : g(g) {  }
	const sw::TTerm* getObject (const sw::TTerm* s, const sw::TTerm* p) const {
	    for (std::vector<const sw::TriplePattern*>::const_iterator it = g.begin();
		 it != g.end(); ++it)
		if ((*it)->getS() == s && (*it)->getP() == p)
		    return (*it)->getO();
	    return NULL;
	}
	std::vector<const sw::TTerm*> rdfList (const sw::TTerm* head) const {
	    std::vector<const sw::TTerm*> ret;
	    const sw::TTerm* first = F.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	    const sw::TTerm* rest = F.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	    const sw::TTerm* nil = F.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	    while (head != NULL && head != nil) {
		const sw::TTerm* car = getObject(head, first);
		if (car != NULL)
		    ret.push_back(car);
		head = getObject(head, rest);
	    }
	    return ret;
	}
    };

    /** Load and cache ShEx schemas by web URL, resolving IMPORTs. */
    struct SchemaCache {
	struct Entry {
	    sw::ShEx::Schema* schema; // NULL when parsing failed
	    std::string parseError;
	    std::string structureError; // set when parsed but structurally bad
	    sw::TTerm::String2BNode bnodeMap; // shared across the import group
	    Entry () : schema(NULL) {  }
	    ~Entry () { delete schema; }
	};
	std::map<std::string, Entry*> cache;

	~SchemaCache () {
	    for (std::map<std::string, Entry*>::iterator it = cache.begin();
		 it != cache.end(); ++it)
		delete it->second;
	}

	/** Parse url (and its imports) into the entry's schema. */
	void loadInto (const std::string& url, Entry* entry,
		       std::set<std::string>& visited, bool isRoot) {
	    if (visited.find(url) != visited.end()
		|| visited.find(url + ".shex") != visited.end())
		return;
	    visited.insert(url);
	    std::string text;
	    try {
		text = readFile(toLocalPath(url));
	    } catch (std::runtime_error&) {
		// IMPORTs in shexTest are extensionless: retry as ShExC
		text = readFile(toLocalPath(url) + ".shex");
		visited.insert(url + ".shex");
	    }
	    sw::IStreamContext istr(text, sw::IStreamContext::STRING);
	    istr.nameStr = url;
	    sw::ShExDriver driver(url, &F);
	    driver.ignoreStart = !isRoot;
	    driver.shexBNodeMap = &entry->bnodeMap;
	    driver.parse(istr, entry->schema);
	    // resolve imports; each import parses into the same schema
	    std::vector<const sw::URI*> imports;
	    imports.swap(entry->schema->imports);
	    for (std::vector<const sw::URI*>::const_iterator it = imports.begin();
		 it != imports.end(); ++it)
		loadInto((*it)->getLexicalValue(), entry, visited, false);
	}

	Entry* get (const std::string& url) {
	    std::map<std::string, Entry*>::const_iterator hit = cache.find(url);
	    if (hit != cache.end())
		return hit->second;
	    Entry* entry = new Entry();
	    entry->schema = new sw::ShEx::Schema();
	    try {
		std::set<std::string> visited;
		loadInto(url, entry, visited, true);
	    } catch (sw::ParserException& e) {
		entry->parseError = e.what();
	    } catch (sw::ParserExceptions& e) {
		entry->parseError = e.what();
	    } catch (sw::ShEx::StructureError& e) {
		entry->parseError = e.what(); // e.g. duplicate labels at parse
	    } catch (std::exception& e) {
		entry->parseError = e.what();
	    } catch (std::string& e) {
		entry->parseError = e;
	    }
	    if (!entry->parseError.empty()) {
		delete entry->schema;
		entry->schema = NULL;
	    } else {
		try {
		    entry->schema->checkStructure();
		} catch (sw::ShEx::StructureError& e) {
		    entry->structureError = e.what();
		}
	    }
	    cache[url] = entry;
	    return entry;
	}
    };
    SchemaCache Schemas;

    /** Load and cache data graphs by web URL, keeping the bnode maps so
     * focus bnodes can be resolved by their source labels. */
    struct DataCache {
	struct Entry {
	    sw::RdfDB db;
	    sw::TTerm::String2BNode bnodeMap;
	    bool loaded;
	    std::string error;
	    Entry () : loaded(false) {  }
	};
	std::map<std::string, Entry*> cache;
	~DataCache () {
	    for (std::map<std::string, Entry*>::iterator it = cache.begin();
		 it != cache.end(); ++it)
		delete it->second;
	}
	Entry* get (const std::string& url) {
	    std::map<std::string, Entry*>::const_iterator hit = cache.find(url);
	    if (hit != cache.end())
		return hit->second;
	    Entry* e = new Entry();
	    try {
		std::string text = readFile(toLocalPath(url));
		sw::IStreamContext istr(text, sw::IStreamContext::STRING);
		istr.nameStr = url;
		TurtleDriverX parser(url, &F);
		parser.parse(istr, e->db.ensureGraph(sw::DefaultGraph));
		e->bnodeMap = parser.getBNodeMap();
		e->loaded = true;
	    } catch (std::exception& ex) {
		e->error = ex.what();
	    } catch (std::string& ex) {
		e->error = ex;
	    }
	    cache[url] = e;
	    return e;
	}
    };
    DataCache Data;

    /* ------------------------------------------------------------ test fns */

    void parseTest (std::string name, std::string shexUrl, bool expectParse,
		    bool structureTest) {
	SchemaCache::Entry* entry = Schemas.get(shexUrl);
	if (expectParse) {
	    // representation tests only require parsing, not structural validity
	    if (entry->schema == NULL)
		BOOST_ERROR(name + ": failed to parse " + shexUrl + ": " + entry->parseError);
	} else if (structureTest) {
	    if (entry->schema != NULL && entry->structureError.empty())
		BOOST_ERROR(name + ": expected structure error in " + shexUrl);
	} else {
	    if (entry->schema != NULL)
		BOOST_ERROR(name + ": expected syntax error in " + shexUrl);
	}
    }

    void validationTest (std::string name, std::string schemaUrl, std::string dataUrl,
			 const sw::TTerm* focus, std::string focusBNodeLabel,
			 const sw::TTerm* shape, std::string shapeBNodeLabel,
			 std::string externsUrl, bool expectPass) {
	SchemaCache::Entry* schemaEntry = Schemas.get(schemaUrl);
	if (schemaEntry->schema == NULL) {
	    BOOST_ERROR(name + ": failed to load schema " + schemaUrl + ": "
			+ schemaEntry->parseError);
	    return;
	}
	if (!schemaEntry->structureError.empty()) {
	    BOOST_ERROR(name + ": structurally invalid schema " + schemaUrl + ": "
			+ schemaEntry->structureError);
	    return;
	}
	sw::ShEx::Schema* schema = schemaEntry->schema;
	if (!shapeBNodeLabel.empty()) {
	    sw::TTerm::String2BNode::const_iterator b
		= schemaEntry->bnodeMap.find(shapeBNodeLabel);
	    if (b == schemaEntry->bnodeMap.end()) {
		BOOST_ERROR(name + ": shape bnode _:" + shapeBNodeLabel + " not in schema");
		return;
	    }
	    shape = b->second;
	}
	DataCache::Entry* data = Data.get(dataUrl);
	if (!data->loaded) {
	    BOOST_ERROR(name + ": failed to load data " + dataUrl + ": " + data->error);
	    return;
	}
	if (!focusBNodeLabel.empty()) {
	    sw::TTerm::String2BNode::const_iterator b = data->bnodeMap.find(focusBNodeLabel);
	    if (b == data->bnodeMap.end())
		// absent from the data: a fresh bnode with an empty neighbourhood
		focus = F.getBNode(focusBNodeLabel, &data->bnodeMap);
	    else
		focus = b->second;
	}
	// reverse the bnode map for the lexical-bnode facets
	std::map<const sw::TTerm*, std::string> bnodeLabels;
	for (sw::TTerm::String2BNode::const_iterator it = data->bnodeMap.begin();
	     it != data->bnodeMap.end(); ++it)
	    bnodeLabels[it->second] = it->first;
	sw::ShEx::Validator validator(*schema, *data->db.ensureGraph(sw::DefaultGraph));
	validator.setBNodeLabels(&bnodeLabels);
	std::unique_ptr<sw::ShEx::SchemaExternalResolver> resolver;
	if (!externsUrl.empty()) {
	    SchemaCache::Entry* externs = Schemas.get(externsUrl);
	    if (externs->schema == NULL) {
		BOOST_ERROR(name + ": failed to load shapeExterns " + externsUrl + ": "
			    + externs->parseError);
		return;
	    }
	    resolver.reset(new sw::ShEx::SchemaExternalResolver(*externs->schema));
	    validator.setExternalResolver(resolver.get());
	}
	bool got;
	try {
	    got = validator.validate(focus, shape);
	} catch (std::exception& e) {
	    BOOST_ERROR(name + ": exception: " + e.what());
	    return;
	} catch (std::string& e) {
	    BOOST_ERROR(name + ": exception: " + e);
	    return;
	}
	if (got != expectPass)
	    BOOST_ERROR(name + ": expected " + (expectPass ? "conformant" : "non-conformant")
			+ " but got " + (got ? "conformant" : "non-conformant")
			+ " for " + (focus ? focus->toString() : "(null)")
			+ " as " + (shape ? shape->toString() : "START")
			+ " in " + schemaUrl);
    }

    /** A shexTest sht:map test: validate every {node, shape} pair of the JSON
     * map. With an mf:result file, compare each pair to its expected result;
     * otherwise all pairs must conform (ValidationTest) or not all
     * (ValidationFailure). */
    void shapeMapTest (std::string name, std::string schemaUrl, std::string dataUrl,
		       std::string mapUrl, std::string resultUrl, bool expectPass) {
	SchemaCache::Entry* schemaEntry = Schemas.get(schemaUrl);
	if (schemaEntry->schema == NULL || !schemaEntry->structureError.empty()) {
	    BOOST_ERROR(name + ": failed to load schema " + schemaUrl + ": "
			+ schemaEntry->parseError + schemaEntry->structureError);
	    return;
	}
	DataCache::Entry* data = Data.get(dataUrl);
	if (!data->loaded) {
	    BOOST_ERROR(name + ": failed to load data " + dataUrl + ": " + data->error);
	    return;
	}
	try {
	    std::vector<sw::ShEx::Association> associations
		= sw::ShEx::parseJsonMap(readFile(toLocalPath(mapUrl)), &F);
	    sw::ShEx::Validator validator(*schemaEntry->schema,
					  *data->db.ensureGraph(sw::DefaultGraph));
	    std::vector<sw::ShEx::AssociationResult> results
		= sw::ShEx::evaluate(validator, associations);
	    if (!resultUrl.empty()) {
		sw::MiniJSON::Value expected = sw::MiniJSON::parse(readFile(toLocalPath(resultUrl)));
		for (std::vector<sw::ShEx::AssociationResult>::const_iterator r
			 = results.begin(); r != results.end(); ++r) {
		    const sw::MiniJSON::Value* forNode
			= expected.get(r->assoc.node->getLexicalValue());
		    if (forNode == NULL || !forNode->isArray()) {
			BOOST_ERROR(name + ": no expected result for "
				    + r->assoc.node->toString());
			continue;
		    }
		    bool found = false;
		    for (std::vector<sw::MiniJSON::Value>::const_iterator e
			     = forNode->array.begin(); e != forNode->array.end(); ++e)
			if (e->getString("shape")
			    == (r->assoc.shape ? r->assoc.shape->getLexicalValue()
			       : std::string("START"))) {
			    found = true;
			    const sw::MiniJSON::Value* res = e->get("result");
			    bool want = res != NULL && res->type == sw::MiniJSON::Value::Bool_T
				&& res->boolean;
			    if (r->conformant != want)
				BOOST_ERROR(name + ": " + r->assoc.node->toString()
					    + " expected " + (want ? "conformant" : "non-conformant")
					    + " but got "
					    + (r->conformant ? "conformant" : "non-conformant"));
			}
		    if (!found)
			BOOST_ERROR(name + ": no expected result for "
				    + r->assoc.node->toString());
		}
	    } else {
		bool all = true;
		for (std::vector<sw::ShEx::AssociationResult>::const_iterator r
			 = results.begin(); r != results.end(); ++r)
		    all = all && r->asAsserted;
		if (all != expectPass)
		    BOOST_ERROR(name + ": expected map to be "
				+ (expectPass ? "conformant" : "non-conformant"));
	    }
	} catch (std::exception& e) {
	    BOOST_ERROR(name + ": exception: " + e.what());
	} catch (std::string& e) {
	    BOOST_ERROR(name + ": exception: " + e);
	}
    }

    /* ------------------------------------------------------- manifest walk */

    struct Manifest {
	sw::RdfDB db;
	sw::TTerm::String2BNode bnodeMap;

	/** Reverse-map a manifest bnode to its source label. */
	std::string bnodeLabel (const sw::TTerm* t) const {
	    for (sw::TTerm::String2BNode::const_iterator it = bnodeMap.begin();
		 it != bnodeMap.end(); ++it)
		if (it->second == t)
		    return it->first;
	    return "";
	}

	bool load (const std::string& dir) { // e.g. "validation/"
	    std::string url = std::string(WebRoot) + dir + "manifest.ttl";
	    try {
		std::string text = readFile(toLocalPath(url));
		sw::IStreamContext istr(text, sw::IStreamContext::STRING);
		istr.nameStr = url;
		TurtleDriverX parser(url, &F);
		parser.parse(istr, db.ensureGraph(sw::DefaultGraph));
		bnodeMap = parser.getBNodeMap();
		return true;
	    } catch (std::exception& e) {
		BOOST_TEST_MESSAGE("skipping " + dir + ": " + e.what());
	    } catch (std::string& e) {
		BOOST_TEST_MESSAGE("skipping " + dir + ": " + e);
	    }
	    return false;
	}
    };

    const sw::URI* mf (const char* local) {
	return F.getURI(std::string("http://www.w3.org/2001/sw/DataAccess/tests/test-manifest#") + local);
    }
    const sw::URI* sht (const char* local) {
	return F.getURI(std::string("http://www.w3.org/ns/shacl/test-suite#") + local);
    }
    const sw::URI* sx (const char* local) {
	return F.getURI(std::string("https://shexspec.github.io/shexTest/ns#") + local);
    }
    const sw::URI* rdfType () {
	return F.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }

    std::string lexOrEmpty (const sw::TTerm* t) {
	return t == NULL ? "" : t->getLexicalValue();
    }

    /** Register one suite directory's entries as test cases. */
    void registerManifest (boost::unit_test::test_suite* parent, const std::string& dir) {
	Manifest* manifest = new Manifest(); // intentionally kept for the test run
	if (!manifest->load(dir))
	    return;
	boost::unit_test::test_suite* ts
	    = BOOST_TEST_SUITE(dir.substr(0, dir.size()-1));
	parent->add(ts);

	sw::BasicGraphPattern* g = manifest->db.ensureGraph(sw::DefaultGraph);
	GraphIndex idx(*g);

	// the manifest node is the subject of mf:entries
	std::vector<const sw::TTerm*> entries;
	for (std::vector<const sw::TriplePattern*>::const_iterator it = g->begin();
	     it != g->end(); ++it)
	    if ((*it)->getP() == mf("entries"))
		entries = idx.rdfList((*it)->getO());

	std::map<std::string, int> seenNames;
	for (std::vector<const sw::TTerm*>::const_iterator e = entries.begin();
	     e != entries.end(); ++e) {
	    const sw::TTerm* entry = *e;
	    std::string name = lexOrEmpty(idx.getObject(entry, mf("name")));
	    if (name.empty())
		name = entry->getLexicalValue();
	    int dup = ++seenNames[name];
	    if (dup > 1) {
		std::stringstream ss;
		ss << name << "-dup" << dup;
		name = ss.str();
	    }
	    const sw::TTerm* type = idx.getObject(entry, rdfType());

	    boost::function<void ()> testFn;
	    if (type == sht("ValidationTest") || type == sht("ValidationFailure")) {
		bool expectPass = type == sht("ValidationTest");
		const sw::TTerm* action = idx.getObject(entry, mf("action"));
		if (action == NULL)
		    continue;
		const sw::TTerm* schemaT = idx.getObject(action, sht("schema"));
		const sw::TTerm* dataT = idx.getObject(action, sht("data"));
		const sw::TTerm* focusT = idx.getObject(action, sht("focus"));
		const sw::TTerm* shapeT = idx.getObject(action, sht("shape"));
		const sw::TTerm* mapT = idx.getObject(action, sht("map"));
		const sw::TTerm* externsT = idx.getObject(action, sht("shapeExterns"));
		if (schemaT == NULL || dataT == NULL)
		    continue;
		if (mapT != NULL) {
		    const sw::TTerm* resultT = idx.getObject(entry, mf("result"));
		    testFn = boost::bind(&shapeMapTest, name,
					 schemaT->getLexicalValue(), dataT->getLexicalValue(),
					 mapT->getLexicalValue(),
					 lexOrEmpty(resultT), expectPass);
		} else if (focusT != NULL) {
		    std::string focusBNodeLabel;
		    if (dynamic_cast<const sw::BNode*>(focusT) != NULL)
			focusBNodeLabel = manifest->bnodeLabel(focusT);
		    std::string shapeBNodeLabel;
		    if (shapeT != NULL && dynamic_cast<const sw::BNode*>(shapeT) != NULL)
			shapeBNodeLabel = manifest->bnodeLabel(shapeT);
		    testFn = boost::bind(&validationTest, name,
					 schemaT->getLexicalValue(), dataT->getLexicalValue(),
					 focusT, focusBNodeLabel, shapeT, shapeBNodeLabel,
					 lexOrEmpty(externsT), expectPass);
		} else
		    continue;
	    } else if (type == sht("RepresentationTest")) {
		const sw::TTerm* shex = idx.getObject(entry, sx("shex"));
		if (shex == NULL)
		    continue;
		testFn = boost::bind(&parseTest, name, shex->getLexicalValue(), true, false);
	    } else if (type == sht("NegativeSyntax") || type == sht("NegativeStructure")) {
		const sw::TTerm* shex = idx.getObject(entry, sx("shex"));
		if (shex == NULL)
		    shex = idx.getObject(entry, sht("schema"));
		if (shex == NULL)
		    continue;
		testFn = boost::bind(&parseTest, name, shex->getLexicalValue(), false,
				     type == sht("NegativeStructure"));
	    } else
		continue;

	    ts->add(boost::unit_test::make_test_case
		    (testFn, boost::unit_test::const_string(name.c_str(), name.size()),
		     __FILE__, __LINE__));
	}
    }
} // namespace

namespace {

    /** Run a webapp-style manifest (tests/ShExManifest/*) and require every
     * entry's status to match. */
    void webappManifestTest (std::string path) {
	try {
	    sw::ShEx::Manifest manifest = sw::ShEx::Manifest::load(path);
	    if (manifest.entries.empty()) {
		BOOST_ERROR(path + ": no entries");
		return;
	    }
	    sw::AtomFactory factory;
	    for (size_t i = 0; i < manifest.entries.size(); ++i) {
		sw::ShEx::EntryOutcome outcome
		    = sw::ShEx::runEntry(manifest.entries[i], manifest, factory);
		std::stringstream at;
		at << path << " entry " << i
		   << " (" << manifest.entries[i].dataLabel << ")";
		if (!outcome.error.empty())
		    BOOST_ERROR(at.str() + ": " + outcome.error);
		else if (!outcome.statusMatched)
		    BOOST_ERROR(at.str() + ": expected "
				+ (manifest.entries[i].expectConformant
				   ? "conformant" : "nonconformant"));
	    }
	} catch (std::exception& e) {
	    BOOST_ERROR(path + ": " + e.what());
	}
    }

    std::string rangesStr (const std::string& spec, size_t n) {
	std::vector<size_t> got = sw::ShEx::expandRanges(spec, n);
	std::stringstream ss;
	for (size_t i = 0; i < got.size(); ++i) {
	    if (i > 0) ss << " ";
	    ss << got[i];
	}
	return ss.str();
    }

    void rangeExpansionTest () {
	BOOST_CHECK_EQUAL(rangesStr("*", 3), "0 1 2");
	BOOST_CHECK_EQUAL(rangesStr("1", 3), "1");
	BOOST_CHECK_EQUAL(rangesStr("0-2", 4), "0 1 2");
	BOOST_CHECK_EQUAL(rangesStr("2-5,*", 7), "2 3 4 5 0 1 2 3 4 5 6");
	BOOST_CHECK_EQUAL(rangesStr("*-3", 2), "0 1");   // '*' endpoint = all
	BOOST_CHECK_EQUAL(rangesStr("5-2", 8), "5 4 3 2");
	BOOST_CHECK_EQUAL(rangesStr("1,2,", 4), "1 2");  // trailing comma ok
	BOOST_CHECK_EQUAL(rangesStr("1-9", 4), "1 2 3"); // clipped to size
	BOOST_CHECK_THROW(sw::ShEx::expandRanges("1,,2", 4), sw::ShEx::ManifestError);
	BOOST_CHECK_THROW(sw::ShEx::expandRanges("x", 4), sw::ShEx::ManifestError);
    }
} // namespace

bool init_function () {
    boost::unit_test::framework::master_test_suite().p_name.value = "ShEx_tests";

    const char* env = getenv("SHEXTEST");
    LocalRoot = env != NULL ? std::string(env) : "shexTest";
    if (LocalRoot[LocalRoot.size()-1] != '/')
	LocalRoot += "/";

    boost::unit_test::test_suite* parent = &boost::unit_test::framework::master_test_suite();
    registerManifest(parent, "schemas/");
    registerManifest(parent, "negativeSyntax/");
    registerManifest(parent, "negativeStructure/");
    registerManifest(parent, "validation/");

    boost::unit_test::test_suite* webapp = BOOST_TEST_SUITE("webappManifest");
    parent->add(webapp);
    webapp->add(boost::unit_test::make_test_case
		(boost::function<void ()>(boost::bind(&webappManifestTest,
						      std::string("ShExManifest/manifest.yaml"))),
		 "yaml", __FILE__, __LINE__));
    webapp->add(boost::unit_test::make_test_case
		(boost::function<void ()>(boost::bind(&webappManifestTest,
						      std::string("ShExManifest/manifest.json"))),
		 "json", __FILE__, __LINE__));
    webapp->add(boost::unit_test::make_test_case
		(boost::function<void ()>(&rangeExpansionTest),
		 "ranges", __FILE__, __LINE__));
    return true;
}

int main (int argc, char* argv[]) {
    return boost::unit_test::unit_test_main(&init_function, argc, argv);
}
