/* ShExMap - the http://shex.io/extensions/Map/# semantic-action language:
 * mapping data between two ShEx schemas.
 *
 * Validation of source data against a source schema whose triple constraints
 * carry %Map:{ ... %} actions collects variable bindings:
 *
 *   <BPfhir> { fhir:value xsd:float %Map:{ bp:sysVal %} }
 *
 * binds bp:sysVal (expanded with the source schema's prefixes) to the matched
 * object. Actions may instead call lift functions:
 *
 *   %Map:{ regex(/(?<bp:family>[a-zA-Z]+), (?<bp:given>[a-zA-Z]+)/) %}
 *   %Map:{ hashmap(bp:code, {"D": "Divorced", "M": "Married"}) %}
 *
 * Materialization walks a target schema with the collected bindings,
 * generating a graph that conforms to it: triple constraints with %Map:{...%}
 * actions emit the bound (or lowered) values, single-valued value sets emit
 * their constant, and nested shapes emit fresh blank nodes.
 */

#ifndef SWOBJ_SHEXMAP_H
#define SWOBJ_SHEXMAP_H

#include "SWObjects.hpp"
#include "ShExSchema.hpp"

#include <deque>
#include <map>
#include <string>
#include <vector>

namespace w3c_sw {
namespace ShExMap {

    extern const char* Name; // "http://shex.io/extensions/Map/#"

    struct MapError : public std::runtime_error {
	MapError (std::string what) : std::runtime_error("ShExMap: " + what) {  }
    };

    /** Variable bindings: FIFO queues per variable (repeated matches queue
     * multiple values) plus sticky statics (e.g. a manifest's staticVars).
     * get() pops multi-valued queues; a variable bound exactly once stays
     * available, like a static. Only pops count as "consumption": the
     * materializer repeats a triple constraint only while repetitions
     * consume, so sticky values cannot drive unbounded repetition. */
    class Bindings {
    public:
	/** Binds land in an ordered log first (so the collector can roll back
	 * failed validation subtrees); freeze() builds the queues. */
	std::vector<std::pair<std::string, const TTerm*> > log;
	std::map<std::string, std::deque<const TTerm*> > queues;
	std::map<std::string, size_t> totalBound;
	std::map<std::string, const TTerm*> statics;
	size_t consumed; // pops from multi-valued queues

	Bindings () : consumed(0) {  }

	void bind (const std::string& var, const TTerm* value) {
	    log.push_back(std::make_pair(var, value));
	}

	/** Build the per-variable queues from the log. */
	void freeze () {
	    queues.clear();
	    totalBound.clear();
	    for (std::vector<std::pair<std::string, const TTerm*> >::const_iterator it
		     = log.begin(); it != log.end(); ++it) {
		queues[it->first].push_back(it->second);
		++totalBound[it->first];
	    }
	}
	void setStatic (const std::string& var, const TTerm* value) {
	    statics[var] = value;
	}

	/** NULL when the variable has no (more) values. */
	const TTerm* get (const std::string& var) {
	    std::map<std::string, std::deque<const TTerm*> >::iterator q = queues.find(var);
	    if (q != queues.end() && !q->second.empty()) {
		const TTerm* ret = q->second.front();
		if (totalBound[var] > 1) { // repeated: consume
		    q->second.pop_front();
		    ++consumed;
		}
		return ret;
	    }
	    std::map<std::string, const TTerm*>::const_iterator s = statics.find(var);
	    if (s != statics.end())
		return s->second;
	    return NULL;
	}

	std::string str () const;
    };

    /** Expand a Map variable reference -- "<iri>" or "pfx:local" -- against a
     * schema's prefixes. Throws MapError on unknown prefixes; returns ""
     * when the code is not a variable reference. */
    std::string parseVariable (const std::string& code,
			       const std::map<std::string, std::string>& prefixes);

    /** A SemActHandler which collects Map bindings while a
     * ShEx::Validator runs. Other semantic-action languages are ignored. */
    class BindingCollector : public ShEx::SemActHandler {
    public:
	BindingCollector (Bindings& out, AtomFactory* atomFactory,
			  const std::map<std::string, std::string>& sourcePrefixes)
	    : out(out), atomFactory(atomFactory), prefixes(sourcePrefixes) {  }

	virtual bool evaluate (const ShEx::SemAct& act, const ShEx::SemActContext& ctx);
	virtual size_t mark () { return out.log.size(); }
	virtual void rollback (size_t m) {
	    if (m <= out.log.size())
		out.log.resize(m);
	}

    private:
	Bindings& out;
	AtomFactory* atomFactory;
	const std::map<std::string, std::string>& prefixes;
    };

    /** Generate a graph conforming to the target schema from bindings.
     * @param shapeLabel  the shape to materialize (NULL: the schema's start).
     * @param root        subject of the outermost shape (NULL: a fresh bnode).
     */
    void materialize (const ShEx::Schema& target, Bindings& bindings,
		      AtomFactory& atomFactory, BasicGraphPattern* out,
		      const TTerm* root = NULL, const TTerm* shapeLabel = NULL);

    /* -- lift/lower extension functions (regex, hashmap) -- */

    /** Apply a lift function ("regex(...)", "hashmap(...)") to a matched
     * value, producing variable -> string results. */
    std::map<std::string, std::string> lift (const std::string& code,
					     const std::string& input,
					     const std::map<std::string, std::string>& prefixes);

    /** Apply a lower function, rebuilding a value from bindings.
     * Returns NULL when a needed variable is absent. */
    const TTerm* lower (const std::string& code, Bindings& bindings,
			AtomFactory& atomFactory,
			const std::map<std::string, std::string>& prefixes);

} // namespace ShExMap
} // namespace w3c_sw

#endif // !SWOBJ_SHEXMAP_H
