/* ShExShapeMap - ShEx shape maps <https://shexspec.github.io/shape-map/>.
 *
 * Supports:
 *  - fixed maps: node@shape pairs, plus the shexTest JSON form
 *    [{"node": ..., "shape": ...}, ...];
 *  - query maps: the node may be a triple pattern {FOCUS <p> _} or
 *    {_ <p> FOCUS} which is expanded against the data graph;
 *  - "@!shape" associations asserting NONconformance;
 *  - START for the schema's start shape.
 *
 * Node-side terms resolve against the data document's base/prefixes;
 * shape-side terms resolve against the schema document's.
 */

#ifndef SWOBJ_SHEX_SHAPEMAP_H
#define SWOBJ_SHEX_SHAPEMAP_H

#include "SWObjects.hpp"
#include "ShExSchema.hpp"

#include <string>
#include <vector>

namespace w3c_sw {
namespace ShEx {

    struct ShapeMapError : public std::runtime_error {
	ShapeMapError (std::string what) : std::runtime_error("shape map: " + what) {  }
    };

    struct Association {
	const TTerm* node;
	const TTerm* shape; // NULL = START
	bool negated;       // node@!shape: expected NONconformant
	Association (const TTerm* node, const TTerm* shape, bool negated)
	    : node(node), shape(shape), negated(negated) {  }
    };

    struct AssociationResult {
	Association assoc;
	bool conformant;  // what the validator said
	bool asAsserted;  // conformant XOR assoc.negated
	AssociationResult (Association assoc, bool conformant)
	    : assoc(assoc), conformant(conformant),
	      asAsserted(conformant != assoc.negated) {  }
    };

    /** Base URI and prefixes for resolving one side of an association. */
    struct PrefixEnv {
	std::string base;
	NamespaceMap* namespaces; // may be NULL
	PrefixEnv (std::string base = "", NamespaceMap* namespaces = NULL)
	    : base(base), namespaces(namespaces) {  }
    };

    /** Where a {FOCUS <p> o} / {s <p> FOCUS} triple pattern in a shape map
     * draws its candidates from: a local graph already in memory (the
     * default; see LocalPatternMatcher) or, e.g., a live SPARQL endpoint
     * (see bin/sparql's --shex-endpoint, which implements one against
     * bnr::BNodeResolver so candidate blank nodes are told-bnode-safe). */
    struct PatternMatcher {
	virtual ~PatternMatcher () {  }
	/** ?FOCUS p o ; o == NULL matches any object. */
	virtual void matchFocusSubject (const TTerm* p, const TTerm* o,
					std::vector<const TTerm*>& into) = 0;
	/** s p ?FOCUS ; s == NULL matches any subject. */
	virtual void matchFocusObject (const TTerm* s, const TTerm* p,
				       std::vector<const TTerm*>& into) = 0;
    };

    /** The original behavior: matches within a BasicGraphPattern already
     * resident in memory. */
    struct LocalPatternMatcher : public PatternMatcher {
	const BasicGraphPattern& data;
	LocalPatternMatcher (const BasicGraphPattern& data) : data(data) {  }
	virtual void matchFocusSubject (const TTerm* p, const TTerm* o,
					std::vector<const TTerm*>& into);
	virtual void matchFocusObject (const TTerm* s, const TTerm* p,
				       std::vector<const TTerm*>& into);
    };

    /** Parse a query/fixed shape map in the compact syntax, expanding triple
     * patterns through `matcher`. "_:label" nodes are resolved through
     * dataBNodeMap when given. Throws ShapeMapError. */
    std::vector<Association> parseQueryMap (const std::string& text,
					    AtomFactory* atomFactory,
					    const PrefixEnv& nodeEnv,
					    const PrefixEnv& shapeEnv,
					    PatternMatcher& matcher,
					    TTerm::String2BNode* dataBNodeMap = NULL);

    /** Convenience overload for a shape map matched against a local graph
     * (the pre-existing behavior; used by manifest-style tests). */
    inline std::vector<Association> parseQueryMap (const std::string& text,
						    AtomFactory* atomFactory,
						    const PrefixEnv& nodeEnv,
						    const PrefixEnv& shapeEnv,
						    const BasicGraphPattern& data,
						    TTerm::String2BNode* dataBNodeMap = NULL) {
	LocalPatternMatcher matcher(data);
	return parseQueryMap(text, atomFactory, nodeEnv, shapeEnv, matcher, dataBNodeMap);
    }

    /** Parse the shexTest JSON fixed map format:
     * [{"node": "iri-or-literal", "shape": "iri"}, ...]. */
    std::vector<Association> parseJsonMap (const std::string& text,
					   AtomFactory* atomFactory);

    /** Validate each association. */
    std::vector<AssociationResult> evaluate (Validator& validator,
					     const std::vector<Association>& associations);

} // namespace ShEx
} // namespace w3c_sw

#endif // !SWOBJ_SHEX_SHAPEMAP_H
