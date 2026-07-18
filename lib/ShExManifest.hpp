/* ShExManifest - the shex-webapp validation manifest format.
 *
 * A manifest is a list of entries, each naming a schema and a data graph
 * (inline or by URL relative to the manifest), a query shape map, and the
 * expected overall status:
 *
 *   - schemaLabel: clinical observation
 *     schema: |
 *       PREFIX : <http://hl7.org/fhir/> ...
 *     dataLabel: with birthdate
 *     data: | ...
 *     queryMap: "<Obs1>@START"
 *     status: conformant
 *
 * Readable from JSON (an array of objects with the same keys) or from the
 * YAML subset that shex-webapp's examples use (a top-level sequence of flat
 * mappings with plain, quoted and '|' literal block scalars).
 *
 * An entry is "conformant" when every shape-map association holds as
 * asserted: node@shape associations validate as conformant and node@!shape
 * associations as non-conformant.
 */

#ifndef SWOBJ_SHEX_MANIFEST_H
#define SWOBJ_SHEX_MANIFEST_H

#include "SWObjects.hpp"
#include "ShExShapeMap.hpp"

#include <string>
#include <vector>

namespace w3c_sw {
namespace ShEx {

    struct ManifestError : public std::runtime_error {
	ManifestError (std::string what) : std::runtime_error("manifest: " + what) {  }
    };

    struct ManifestEntry {
	std::string schemaLabel;
	std::string schema, schemaURL; // one of the two
	std::string dataLabel;
	std::string data, dataURL;
	std::string queryMap, queryMapURL;
	bool expectConformant;
    };

    struct Manifest {
	std::vector<ManifestEntry> entries;
	std::string directory; // for resolving relative URLs, ends in '/'
	std::string baseURI;   // base for parsing schemas/data/maps

	/** Load path as JSON or YAML (sniffed by leading characters). */
	static Manifest load (const std::string& path);
	static Manifest parse (const std::string& text, const std::string& path);
    };

    /** One entry's evaluation. */
    struct EntryOutcome {
	std::string error; // non-empty: could not run
	std::vector<AssociationResult> results;
	bool allAsAsserted;
	bool statusMatched; // allAsAsserted == entry.expectConformant
	EntryOutcome () : allAsAsserted(true), statusMatched(false) {  }
    };

    /** Parse the entry's schema, data and query map, validate every
     * association, and compare with the entry's expected status. */
    EntryOutcome runEntry (const ManifestEntry& entry, const Manifest& manifest,
			   AtomFactory& atomFactory);

    /** Expand a run specification over n entries:
     *   entry: range (',' range)* ','?
     *   range: index ('-' index)?
     *   index: [0-9]+ | '*'
     * Indexes are 0-based. '*' (alone or as either endpoint) selects all
     * entries. "5-2" runs 5,4,3,2. Out-of-range indexes are dropped.
     * Throws ManifestError on syntax errors. */
    std::vector<size_t> expandRanges (const std::string& spec, size_t n);

} // namespace ShEx
} // namespace w3c_sw

#endif // !SWOBJ_SHEX_MANIFEST_H
