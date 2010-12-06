/* ChainingMapper.hpp - backwards-chaining Operation transformer.
 *
 * $Id: ChainingMapper.hpp,v 1.12 2008-11-03 19:24:26 eric Exp $
 */

#ifndef ChainingMapper_H
#define ChainingMapper_H

#include <map>
#include <set>
#include <vector>

#include "SWObjectDuplicator.hpp"
#include "SPARQLSerializer.hpp"
#include "RdfQueryDB.hpp"
#include "ExpressionInverter.hpp"
#include "prfxbuf.hpp"

namespace w3c_sw {

    class ChainingMapper;

    struct Bindings {
	struct Failures {
	    typedef std::set<const TriplePattern*> Triples;
	    typedef std::map<const BasicGraphPattern*, Triples > Bgp2Triples;
	    Bgp2Triples bgp2triples;
	    size_t size () const { return bgp2triples.size(); }

	    /**
	     * SPARQLSerializer to create and return the error string.
	     */
	    struct FailureSerializer : public SPARQLSerializer {
		const Bgp2Triples& bgp2triples;
		FailureSerializer (const Bgp2Triples& bgp2triples, MediaType mediaType, NamespaceMap* namespaces, 
				   const char* p_tab = "  ", e_DEBUG debug = DEBUG_none, const char* leadStr = "") : 
		    SPARQLSerializer(mediaType, namespaces, p_tab, debug, leadStr), bgp2triples(bgp2triples)
		{  }
		void markError (const BasicGraphPattern* bgp, const TriplePattern* triple) {
		    Bgp2Triples::const_iterator b = bgp2triples.find(bgp);
		    if (b != bgp2triples.end() && b->second.find(triple) != b->second.end())
			ret << "!";
		    else
			ret << " ";
		}
		void _BasicGraphPattern (const BasicGraphPattern* self, const ProductionVector<const TriplePattern*>* p_TriplePatterns, bool p_allOpts) {
		    ret << '{';
		    if (debug & DEBUG_graphs) ret << ' ' << self;
		    ret << std::endl;
		    depth++;
		    const ExprSet* filters = injectFilter; injectFilter = NULL;
		    if (p_allOpts)
			for (std::vector<const TriplePattern*>::const_iterator triple = p_TriplePatterns->begin();
			     triple != p_TriplePatterns->end(); triple++) {
			    lead(); ret << "optional {" << std::endl << "  ";
			    depth++;
			    markError(self, *triple); (*triple)->express(this);
			    depth--;
			    lead(); ret << "}" << std::endl;;
			}
		    else
			for (std::vector<const TriplePattern*>::const_iterator triple = p_TriplePatterns->begin();
			     triple != p_TriplePatterns->end(); triple++) {
			    depth++;
			    markError(self, *triple); (*triple)->express(this);
			    depth--;
			}
		    serializeFilter(filters);
		    depth--;
		    lead();
		    ret << '}' << std::endl;
		}
		/** _BasicGraphPattern isn't virtual, so overload its invokers. */
		virtual void namedGraphPattern (const NamedGraphPattern* const self, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		    lead();
		    p_name->express(this);
		    ret << ' ';
		    _BasicGraphPattern(self, p_TriplePatterns, p_allOpts);
		}
		virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
		    lead();
		    _BasicGraphPattern(self, p_TriplePatterns, p_allOpts);
		}

		/**
		 * Single interface function to create and return the error string.
		 */
		std::string toString (const Operation* op) {
		    op->express(this);
		    return ret.str();
		}
		std::string toString (const TableOperation* op) {
		    op->express(this);
		    return ret.str();
		}
	    };
	    std::string toString (const Operation* op, MediaType mediaType = MediaType(), NamespaceMap* namespaces = NULL) const {
		return FailureSerializer(bgp2triples, mediaType, namespaces).toString(op);
	    }
	    std::string toString (const TableOperation* op, MediaType mediaType = MediaType(), NamespaceMap* namespaces = NULL) const {
		return FailureSerializer(bgp2triples, mediaType, namespaces).toString(op);
	    }
	    std::string str () const {
		std::stringstream ss;
		for (Bgp2Triples::const_iterator optriples = bgp2triples.begin();
		     optriples != bgp2triples.end(); ++optriples)
		    ss << "Match failure: " << toString(optriples->first);
		return ss.str();
	    }
	};

	AtomFactory* atomFactory;
	std::vector<Rule>& rules;

	/* Mapping from a Rule to a set of instantiations of that Rule.<br/>

	   Example: Query { ?a foaf:knows ?b . ?b foaf:knows ?c } requires two
	   instantiations of Rule head { ?x foaf:knows ?y }. This will look like:<br>
	   <pre>
	     +----+----+
	     | ?x | ?y |
	     | ?a | ?b |
	     | ?b | ?c |
	     +----+----+
	   </pre>
	 */
	struct BindingsForTriples {
	    ResultSet rs;
	    std::set<const TriplePattern*> triples;
	    BindingsForTriples (ResultSet rs, const TriplePattern* triple) : rs(rs) {
		triples.insert(triple);
	    }
	    std::string str () const {
		std::stringstream ss;
		ss << rs.toString();
		ss << "bound by triple patterns [[\n";
		for (std::set<const TriplePattern*>::const_iterator it = triples.begin();
		     it != triples.end(); ++it)
		    ss << "  " << (*it)->toString() << "\n";
		ss << "]]\n";
		return ss.str();
	    }
	};
	struct Rule2rs : public std::map<const Rule, BindingsForTriples> {

	    /* Map query terms to their uses in RuleTerms. Insertion of
	       incompatible RuleTerm into this map indicates an inconsistent
	       solution. (e.g. ?name used as People.?name and Places.?name.)
	    */
	    struct QueryTermUsage : std::map<const TTerm*, std::set<RuleTerm> > {
		// void operator= (const QueryTermUsage& ref) {
		// }
	    };
	    QueryTermUsage termUsage;

	    std::string str () const {
		std::stringstream ss;
		for (Rule2rs::const_iterator rule = begin();
		     rule != end(); ++rule) {
		    ss << rule->first << std::endl << rule->second.str();
		}
		return ss.str();
	    }

	    /* Find out any term bound in testRS with by rule is inconsistent
	       with existing term usage. e.g. can product.producer be the same
	       as product.publisher (in BSBM, both reference producer.producer).
	     */
	    bool inconsistentWith (const Rule& rule, const ResultSet& testRS, MapSet::e_sharedVars sharedVars, const NodeShare& nodeShare) {
		const Result* testRow = *testRS.begin();
		{
		    for (BindingSetConstIterator var = testRow->begin(); var != testRow->end(); ++var) {
			const TTerm* ruleVar = var->first;
			const TTerm* queryTerm = var->second.tterm;
			QueryTermUsage::iterator it = termUsage.find(queryTerm);
			if (it != termUsage.end()) {
			    for (std::set<RuleTerm>::const_iterator existingRuleTerm = it->second.begin();
				 existingRuleTerm != it->second.end(); ++existingRuleTerm)
				if (rule.label == existingRuleTerm->rule && ruleVar == existingRuleTerm->term) // @@ try rule == existingRuleTerm.rule
				    ; // Used for the same node in the same rule.
				else if (sharedVars == MapSet::e_PROMISCUOUS)
				    ;
				else if (sharedVars == MapSet::e_VARNAMES && ruleVar == existingRuleTerm->term)
				    ; // sharedVars flag says same-named vars are the same object.
				else if (nodeShare.connects(RuleTerm(rule.label, ruleVar), *existingRuleTerm))
				    ; // sharedVars flag says same-named vars are the same object.
				else 
				    return true;
			}
		    }
		}
		return false;
	    }

	    /** someShorterPath - determine if the current bindings for rule
	     * plus a candidate binding testRS is the minimal expression of
	     * triples.
	     * 
	     * @@ unfinished -- instead testing for apparent redundancy at
	     * instantiation.

	    bool someShorterPath (const Rule& rule, const ResultSet& testRS, std::set<const TriplePattern*> triples) {
		const Result* testRow = *testRS.begin();
		{
		    Rule2rs::const_iterator boundRule = find(rule);
		    if (boundRule == end())
			return false;
		    const ResultSet& rs(boundRule->second);
		    // std::cerr << "someShorterPath(" << rule << ",\n" << testRS << ", " << triple->toString() << ")?\n";
		    for (ResultSetConstIterator res = rs.begin();
			 res != rs.end(); ++res) {
		    }
		}
		return false;
	    }
	     */

	    void add (const Rule& rule, const ResultSet& testRS, const TriplePattern* triple) {
		const Result* testRow = *testRS.begin();
		{
		    for (BindingSetConstIterator var = testRow->begin(); var != testRow->end(); ++var) {
			const TTerm* ruleVar = var->first;
			const TTerm* queryTerm = var->second.tterm;
			// termUsage[queryTerm].insert(RuleTerm(rule, ruleVar));
			QueryTermUsage::iterator it = termUsage.find(queryTerm);
			if (it == termUsage.end()) {
			    std::set<RuleTerm> s;
			    std::pair<const TTerm*, std::set<RuleTerm> > pt(queryTerm, s);
			    it = termUsage.insert(pt).first;
			}
			it->second.insert(RuleTerm(rule.label, ruleVar));
		    }
		}

		/** Test against existing variable bindings for that rule. */
		bool rowMatched = false;
		Rule2rs::iterator boundRule = find(rule);

		/**
		 * Walk through the current instantiations of the rule, seeing
		 * if the new bindings (testRow) can be added to one of the
		 * existing rows. It much be SPARQL-compatible and contiguous
		 * with the existing binding (as otherwise we invent solutions
		 * with a random mix of the matched variables).
		 */
		if (boundRule != end()) {
		    BindingsForTriples& bindings(boundRule->second);
		    for (ResultSetIterator row = bindings.rs.begin();
			 !rowMatched && row != bindings.rs.end(); ++row)
			if ((*row)->isCompatibleWith(testRow)
			    /* && (*row)->isContiguousWith(testRow)*/) { // !!! kills test_QueryMap healthCare/simple/sdtm_db
			    (*row)->assumeNewBindings(testRow);
			    bindings.triples.insert(triple);
			    rowMatched = true;
			    break; // @@ apply to first available instantiation. good?
			}
		}
		if (!rowMatched) {
		    /** Start a new result. */
		    if (boundRule == end()) {
			/** First binding for this rule. */
			insert(std::pair<const Rule, BindingsForTriples>
			       (rule, BindingsForTriples(testRS, triple)));
		    } else {
			ResultSet& rs(boundRule->second.rs);
			rs.insert(rs.end(), testRow->duplicate(&rs, rs.end()));
			boundRule->second.triples.insert(triple);
		    }
		}
	    }
	};

	/* Simple structure for adding a ResultSet bound from matching a
	   rule. (Should this be a std::pair?)
	*/
	struct Add {
	    Rule rule;
	    ResultSet rs;
	    const TriplePattern* triple;
	    Add (Rule rule, ResultSet rs, const TriplePattern* triple)
		: rule(rule), rs(rs), triple(triple) {  }
	    void operator= (const Add& ref) {
		rule = ref.rule;
		rs = ref.rs;
		triple = ref.triple;
	    }
	    std::string str () {
		return rule.label->toString() + "\n" + rs.toString();
	    }
	};
	struct Alternatives {
	    struct Opts : public std::vector<Rule2rs> {
		Opts () : std::vector<Rule2rs>() {  }
		Opts (size_t s) : std::vector<Rule2rs>(s) {  }
		std::string str () {
		    std::stringstream ss;
		    size_t i = 0;
		    for (const_iterator it = begin(); it != end(); ++it, ++i) {
			ss << "[" << i << "]" << it->str();
		    }
		    return ss.str();
		}
	    };
	    Opts opts;
	    MapSet::e_sharedVars sharedVars;
	    NodeShare& nodeShare;
	    std::ostream** debugStream;

	    Alternatives (MapSet::e_sharedVars sharedVars, NodeShare& nodeShare, std::ostream** debugStream)
		: opts(1), sharedVars(sharedVars), nodeShare(nodeShare), debugStream(debugStream) {  }
	    void operator= (const Alternatives& ref) {
		sharedVars = ref. sharedVars;
		nodeShare = ref.nodeShare;
	    }

	    std::string str () const {
		std::stringstream ss;
		for (Alternatives::Opts::const_iterator disjoint = opts.begin();
		     disjoint != opts.end(); ++disjoint) {
		    if (disjoint != opts.begin())
			ss << "UNION\n";
		    ss << disjoint->str();
		}
		return ss.str();
	    }

	    /** cross: Create a cross product with the vector of added rule.
	     * bindings. Enforce all integrity constraints and return the count
	     * of resulting alternatives.
	     */
	    size_t cross (const std::vector<Add> adds) {
		if (adds.size() == 0)
		    opts.clear();
		else {
		    Opts newOpts;
		    for (Opts::iterator alt = opts.begin(); alt != opts.end(); ++alt) {
			// std::cerr << "alt: " << alt->str();
			for (std::vector<Add>::const_iterator it_add = adds.begin();
			     it_add != adds.end(); ++it_add) {
			    Add add = *it_add;
			    // std::cerr << "add: " << add.str();

			    /**
			     * inconsistentWith handles the exotic rules to
			     * avoid the spurious self-joins which stem from the
			     * rule-head offering multiple arcs which match a
			     * query arc.
			     */
			    if (!alt->inconsistentWith(add.rule, add.rs, sharedVars, nodeShare) /* &&
				!alt->someShorterPath(add.rule, add.rs, triples) */) {
				Rule2rs merge(*alt);
				merge.add(add.rule, add.rs, add.triple);
				newOpts.insert(newOpts.end(), merge);
			    }
			}
		    }
		    opts = newOpts;
		}
		return opts.size(); // 0 indicates we've run out of viable solutions.
	    }

	    struct Instantiator : public SWObjectDuplicator {
		const TableOperation* pattern;
		const Result* res;
		std::string uniquePrefix;
		TTerm::String2BNode nodeMap;
		Instantiator (const TableOperation* pattern, const Result* res, AtomFactory* atomFactory, std::string uniquePrefix)
		    : SWObjectDuplicator(atomFactory), pattern(pattern), res(res), uniquePrefix(uniquePrefix) {  }
		virtual void variable (const Variable* const self, std::string) {
		    if ((last.tterms.tterm = res->get(self)) == NULL)
			last.tterms.tterm = atomFactory->getVariable(uniquePrefix+self->getLexicalValue());
		    //throw "no unique binding for variable " + label;
		}
		virtual void bnode (const BNode* const self, std::string) {
		    if ((last.tterms.tterm = res->get(self)) == NULL)
			last.tterms.tterm = atomFactory->getBNode(uniquePrefix+self->getLexicalValue(), nodeMap);
		    //throw "no unique binding for bnode " + label;
		}
		virtual void expressionAlias (const ExpressionAlias* const self, const Expression* expr, const Bindable* label) {
		    const TTerm* curBinding = label ? res->get(label) : NULL;
		    if (curBinding != NULL && dynamic_cast<const Bindable*>(curBinding) == NULL) {
			ExpressionInverter inv(curBinding, const_cast<Result*>(res), atomFactory); // !!!! res shouldn't be const
			expr->express(&inv); // binds variables !! will add filters
			last.expressionAlias = new ExpressionAlias(new TTermExpression(curBinding), label);
		    } else {
			SWObjectDuplicator::expressionAlias(self, expr, label);
		    }
		}
		TableOperation* apply () {
		    pattern->express(this);
		    return last.tableOperation;
		}
	    };

	    struct VarUniquifier {
		typedef std::map<std::string, int> UniqueVars;
		typedef std::pair<std::string, int> UniquePair;
		UniqueVars uniqueVars;
		std::string uniquePrefix (const TTerm* label) {
		    std::string key = label == NULL ? "" : label->getLexicalValue();
		    if (key.size() > 10)
			key = key.substr(0, 32);
		    key = std::string("_") + key + "_";
		    UniqueVars::iterator cur = uniqueVars.find(key);
		    if (cur == uniqueVars.end())
			cur = uniqueVars.insert(UniquePair(key, 0)).first;
		    std::stringstream ss;
		    ss << key << cur->second++ << "_";
		    return ss.str();
		}
	    };

	    /** eliminateRedundancies - eliminate each opt for which another opt
	     * more succinctly uses the same rules to cover the same triples.
	     * 
	     */
	    void eliminateRedundancies () {
		typedef std::map<const Rule, std::set<const TriplePattern*> > Key;
		typedef std::map<Key, size_t> Bests;
		Bests best;
		// opts: vector<Rule2rs>


		/**
		 * Use a disjoint index o (because e.g. a pointer will change as
		 * soon as you delete an entry).
		 */
		size_t o = 0;
		for (Opts::const_iterator alternative = opts.begin();
		     alternative != opts.end(); ++alternative, ++o) {

		    /**
		     * Generate the key for this disjoint.
		     */
		    std::map<const Rule, std::set<const TriplePattern*> > cur;
		    for (Rule2rs::const_iterator rule = alternative->begin();
			 rule != alternative->end(); ++rule)
			// rule->first: Rule
			// rule->second.rs: ResultSet
			// rule->second.triples: std::set<const TriplePattern*>
			cur[rule->first] = rule->second.triples;

		    if (best.find(cur) == best.end())
			best[cur] = o;
		    else {
			for (Rule2rs::const_iterator rule = alternative->begin();
			     rule != alternative->end(); ++rule)
			    if (rule->second.rs.size() < opts[best[cur]].find(rule->first)->second.rs.size()) {
				best[cur] = o;
				break;
			    }
		    }
		}

		std::set<size_t> keep;
		for (Bests::const_iterator it = best.begin();
		     it != best.end(); ++it)
		    keep.insert(it->second);

		o = 0;
		for (Opts::iterator alternative = opts.begin();
		     alternative != opts.end(); ++o)
		    if (keep.find(o) == keep.end())
			alternative = opts.erase(alternative);
		    else
			++alternative;

		// std::cerr << "trimmed: \n" << str();
	    }

	    const TableOperation* instantiate (AtomFactory* atomFactory, VarUniquifier& varUniquifier) const {
		// std::cerr << "instantiate " << str();
		TableDisjunction* ret = NULL;
		if (opts.size() > 1)
		    ret = new TableDisjunction();

		oprfxstream* newDebugStream = NULL;
		std::ostream* oldDebugStream = NULL;
		if (debugStream && *debugStream != NULL) {
		    newDebugStream = new oprfxstream((*debugStream)->rdbuf(), "   ");
		    oldDebugStream = *debugStream;
		    *debugStream = newDebugStream;
		}

		for (Opts::const_iterator alternative = opts.begin();
		     alternative != opts.end(); ++alternative) {
		    if (newDebugStream != NULL && alternative != opts.begin()) {
			newDebugStream->prefix("");
			*newDebugStream << "UNION" << std::endl;
			newDebugStream->prefix("   ");
		    }
		    if (debugStream && *debugStream != NULL) {
			if (opts.size() > 1)
			    **debugStream << "alternative: ";
			**debugStream << alternative->str();
		    }
		    std::vector<const TableOperation*> conjoints;
		    for (Rule2rs::const_iterator rule = alternative->begin();
			 rule != alternative->end(); ++rule)
			for (ResultSetConstIterator res = rule->second.rs.begin();
			     res != rule->second.rs.end(); ++res) {
			    TableOperation* bgp = Instantiator(rule->first.body, *res, atomFactory, varUniquifier.uniquePrefix(rule->first.label)).apply();
			    if (debugStream && *debugStream != NULL) {
				**debugStream << "bindings: " << **res << " instantiates as:\n";
				newDebugStream->prefix("      ");
				**debugStream << bgp->toString(MediaType("text/turtle"));
				newDebugStream->prefix("   ");
			    }
			    conjoints.push_back(bgp);
			}

		    const TableOperation* op = 
			conjoints.size() == 0 ? NULL :
			conjoints.size() == 1 ? conjoints[0] :
			new TableConjunction(conjoints.begin(), conjoints.end());

		    if (opts.size() > 1 && op != NULL)
			ret->addTableOperation(op, false);
		    else
			return op; // ret = op loses const-ness.
		}
		if (debugStream && *debugStream != NULL) {
		    delete newDebugStream;
		    *debugStream = oldDebugStream;
		}
		return ret;
	    }

	};

	// std::ostream& operator<< (std::ostream& os, const Alternatives& alt) {
	//     return os << alt.str();
	// }

	Alternatives alternatives;
	Failures failed;
	std::ostream** debugStream;

	Bindings (AtomFactory* atomFactory, std::vector<Rule>& rules, MapSet::e_sharedVars sharedVars, NodeShare& nodeShare, std::ostream** debugStream)
	    : atomFactory(atomFactory), rules(rules), alternatives(sharedVars, nodeShare, debugStream), debugStream(debugStream) {  }
	void operator= (const Bindings& ref) {
	    atomFactory = ref.atomFactory;
	    rules = ref.rules;
	    alternatives = ref.alternatives;
	    failed = ref.failed;
	}

	/**
	 * Match a triple pattern against the rule heads.
	 * Ensure a binding entry for matched pattern.
	 *
	 * HEAD: { ?patient sdtm:dateTimeOfBirth ?dob }
	 * TRIPLE: ?who sdtm:dateTimeOfBirth "1966-11-08T00:00"^^xsd:dateTime .
	 *
	 */
	bool match (const BasicGraphPattern* bgp, const TriplePattern* triple) {
	    std::vector<Add> adds;

	    // std::cerr << "query: " << triple->toString() << "\n";

	    /** For each rule... */
	    for (std::vector<Rule>::const_iterator rule = rules.begin();
		 rule != rules.end(); ++rule) {

		/** For each triple in the rule head... */
		for (std::vector<const TriplePattern*>::const_iterator constraint = rule->head->begin();
		     constraint != rule->head->end(); constraint++) {

		    ResultSet testRS(atomFactory);
		    for (VariableListConstIterator it = rule->bodyVars.begin();
			 it != rule->bodyVars.end(); ++it)
			testRS.addKnownVar(*it);

		    /** If the pattern matches the triple,
		          we will add it to the <alternatives>. */
		    // std::cerr << "  rule: " << (*constraint)->toString();
		    if ((*constraint)->bindVariables(triple, false, &testRS, *testRS.begin())) {
			/**
			 * Queue adding this combination of rule and bindings to
			 * the opts.
			 */
			adds.push_back(Add(*rule, testRS, triple));
			// std::cerr << "\n  new binding " << adds.rbegin()->str() << "\n" << adds.rbegin()->rs;
		    } else {
			// std::cerr << "\n" << testRS;
		    }
		}
	    }
	    if (adds.size() == 0 || alternatives.cross(adds) == 0)
		failed.bgp2triples[bgp].insert(triple);
	    // std::cerr << "final:\n" << str();
	    return adds.size() > 0;
	}

	const TableOperation* instantiate (Alternatives::VarUniquifier& varUniquifier) {
	    alternatives.eliminateRedundancies();
	    return alternatives.instantiate(atomFactory, varUniquifier);
	}

	std::string str () const {
	    return alternatives.str() + failed.str();
	}
    };

    std::ostream& operator<< (std::ostream& os, const Bindings& b) {
	return os << b.str();
    }

    struct RuleMatchingException : StringException {
	std::string msg;
	RuleMatchingException (std::string msg) : 
	    StringException(make(msg)), msg(msg) {  }
	virtual ~RuleMatchingException () throw() {  }
    protected:
	std::string make (std::string msg) {
	    std::stringstream s;
	    s << "failed to match triples prefixed by \"!\" in\n" << msg;
	    return s.str();
	}
    };

    class QueryWalker : public SWObjectDuplicator {
    protected:
	Bindings bindings;
	MapSet::e_sharedVars sharedVars;
	Bindings::Alternatives::VarUniquifier varUniquifier;
	std::ostream** debugStream;

    public:
	QueryWalker (std::vector<Rule>& rules, AtomFactory* atomFactory, MapSet::e_sharedVars sharedVars, NodeShare& nodeShare, std::ostream** debugStream)
	    : SWObjectDuplicator(atomFactory), bindings(atomFactory, rules, sharedVars, nodeShare, debugStream), debugStream(debugStream) {  }
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const BasicGraphPattern* bgp, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    bindings.alternatives.opts.clear();
	    bindings.alternatives.opts.push_back(Bindings::Rule2rs());
	    for (std::vector<const TriplePattern*>::const_iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)
		bindings.match(bgp, *it);

	    if (debugStream && *debugStream != NULL)
		**debugStream << "transforming bgp: " << *bgp << " -> [[\n";
	    last.tableOperation = (TableOperation*)bindings.instantiate(varUniquifier); // @@ LIES
	    if (debugStream && *debugStream != NULL)
		**debugStream << "]]\n";
	}
	virtual void namedGraphPattern (const NamedGraphPattern* const self, const TTerm* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    p_name->express(this);
	    _TriplePatterns(self, p_TriplePatterns);
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const self, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    _TriplePatterns(self, p_TriplePatterns);
	}
	const Operation* mapQuery (const Operation* query) {
	    query->express(this);
	    // std::cerr << bindings;
	    if (bindings.failed.size() > 0) {
		delete last.operation;
		throw RuleMatchingException(bindings.failed.toString(query));
	    }
	    return last.operation;
	}
    };

    struct RuleParser : public RecursiveExpressor {
	DefaultGraphPattern* head;
	const TableOperation* body;
	SWObjectDuplicator d;
	VariableList bodyVars;

	RuleParser () : d(NULL) {  }

	virtual void base (const Base* const /* self */, std::string productionName) {
	    throw std::string("RuleParser::base(") + productionName + ") called";
	}
	virtual void variable (const Variable* const self, std::string lexicalValue) {
	    if (bodyVars.find(self) == bodyVars.end())
		bodyVars.insert(self);
	    RecursiveExpressor::variable(self, lexicalValue); // in case we are defined from some other useful class.
	}
	virtual void whereClause (const WhereClause* const self, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	    RecursiveExpressor::whereClause(self, p_GroupGraphPattern, p_BindingClause); // to call variable above.
	    p_GroupGraphPattern->express(&d);
	    body = d.last.tableOperation;
	}
	virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>*, WhereClause* p_WhereClause, SolutionModifier*) {
	    p_ConstructTemplate->express(&d);
	    // bodyVars.clear(); -- unnecessary because p_ConstructTemplate was only visited with an SWObjectDuplicator.
	    head = dynamic_cast<DefaultGraphPattern*>(d.last.tableOperation);
	    p_WhereClause->express(this);
	}
	Rule parseConstruct (const Construct* c, const TTerm* name) {
	    c->express(this);
	    return Rule(head, body, name, bodyVars);
	}
    };

    class ChainingMapper : public SWObjectDuplicator {
    protected:
	std::vector<Rule> rules;
	std::ostream** debugStream;

    public:
	MapSet::e_sharedVars sharedVars;
	NodeShare nodeShare;

	ChainingMapper (AtomFactory* atomFactory, std::ostream** debugStream) : SWObjectDuplicator(atomFactory), debugStream(debugStream) {  }
	~ChainingMapper () { clear(); }
	void clear () {
	    /* clear rules -- called twice for some reason, needs the erase to guard against double delete. */
	    for (std::vector<Rule>::iterator rule = rules.begin();
		 rule != rules.end();) {
		delete rule->head;
		delete rule->body;
		rule = rules.erase(rule);
	    }
	}
	size_t getRuleCount () { return rules.size(); }
	void addRule (const Construct* rule, const TTerm* name) {
	    if (name == NULL) {
		std::stringstream ss;
		ss << rule;
		name = atomFactory->getRDFLiteral(ss.str());
	    }
	    Rule r = RuleParser().parseConstruct(rule, name);
	    if (debugStream && *debugStream != NULL)
		**debugStream << "adding rule: " << r.toString();
	    rules.push_back(r);
	}
	const Operation* map (const Operation* query) {
	    const Operation* op = QueryWalker(rules, atomFactory, sharedVars, nodeShare, debugStream).mapQuery(query);
	    BGPSimplifier dup(atomFactory);
	    op->express(&dup);
	    delete op;
	    return dup.last.operation;
	}
    }; // class ChainingMapper

} // namespace w3c_sw

#endif // ChainingMapper_H

