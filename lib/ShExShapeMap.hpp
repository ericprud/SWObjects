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

    /** Parse a query/fixed shape map in the compact syntax, expanding triple
     * patterns against data. "_:label" nodes are resolved through
     * dataBNodeMap when given. Throws ShapeMapError. */
    std::vector<Association> parseQueryMap (const std::string& text,
					    AtomFactory* atomFactory,
					    const PrefixEnv& nodeEnv,
					    const PrefixEnv& shapeEnv,
					    const BasicGraphPattern& data,
					    TTerm::String2BNode* dataBNodeMap = NULL);

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
