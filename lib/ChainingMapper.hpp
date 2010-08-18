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
	struct Rule2rs : public std::map<const Rule, ResultSet> {

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
		    ss << rule->first << std::endl << rule->second;
		}
		return ss.str();
	    }

	    /* Find out any term bound in testRS with by rule is inconsistent
	       with existing term usage. e.g. can product.producer be the same
	       as product.publisher (In BSBM, both reference producer.producer.
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

	    void add (const Rule& rule, const ResultSet& testRS) {
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
		if (boundRule != end()) {
		    ResultSet& rs(boundRule->second);
		    for (ResultSetIterator row = rs.begin() ; !rowMatched && row != rs.end(); ++row)
			if ((*row)->isCompatibleWith(testRow)) {
			    (*row)->assumeNewBindings(testRow);
			    rowMatched = true;
			}
		}
		if (!rowMatched) {
		    /** Start a new result. */
		    if (boundRule == end()) {
			/** First binding for this rule. */
			insert(std::pair<const w3c_sw::Rule, w3c_sw::ResultSet>(rule, testRS));
		    } else {
			ResultSet& rs(boundRule->second);
			rs.insert(rs.end(), testRow->duplicate(&rs, rs.end()));
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
	    Add (Rule rule, ResultSet rs) : rule(rule), rs(rs) {  }
	    void operator= (const Add& ref) {
		rule = ref.rule;
		rs = ref.rs;
	    }
	};
	struct Alternatives {
	    typedef std::vector<Rule2rs> Opts;
	    Opts opts;
	    MapSet::e_sharedVars sharedVars;
	    NodeShare& nodeShare;

	    Alternatives (MapSet::e_sharedVars sharedVars, NodeShare& nodeShare)
		: opts(1), sharedVars(sharedVars), nodeShare(nodeShare) {  }
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

	    /** cross: create a cross product with the vector of added rule
	       bindings. Enforce all integrity constraints and return the count
	       of resulting alternatives.
	     */
	    size_t cross (const std::vector<Add> adds) {
		if (adds.size() == 0)
		    opts.clear();
		else {
		    Opts newOpts;
		    for (Opts::iterator alt = opts.begin(); alt != opts.end(); ++alt) {
			for (std::vector<Add>::const_iterator it_add = adds.begin();
			     it_add != adds.end(); ++it_add) {
			    Add add = *it_add;
			    if (!alt->inconsistentWith(add.rule, add.rs, sharedVars, nodeShare)) {
				Rule2rs merge(*alt);
				merge.add(add.rule, add.rs);
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
		virtual void variable (const Variable* const self, std::string label) {
		    if ((last.tterms.tterm = res->get(self)) == NULL)
			last.tterms.tterm = atomFactory->getVariable(uniquePrefix+self->getLexicalValue());
		    //throw "no unique binding for variable " + label;
		}
		virtual void bnode (const BNode* const self, std::string label) {
		    if ((last.tterms.tterm = res->get(self)) == NULL)
			last.tterms.tterm = atomFactory->getBNode(uniquePrefix+self->getLexicalValue(), nodeMap);
		    //throw "no unique binding for bnode " + label;
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

	    const TableOperation* instantiate (AtomFactory* atomFactory, VarUniquifier& varUniquifier) const {
		// std::cerr << "instantiate " << str();
		TableDisjunction* ret = NULL;
		if (opts.size() > 1)
		    ret = new TableDisjunction();
		for (Opts::const_iterator alternative = opts.begin();
		     alternative != opts.end(); ++alternative) {
		    std::vector<const TableOperation*> conjoints;
		    for (Rule2rs::const_iterator rule = alternative->begin();
			 rule != alternative->end(); ++rule)
			for (ResultSetConstIterator res = rule->second.begin();
			     res != rule->second.end(); ++res)
			    conjoints.push_back(Instantiator(rule->first.body, *res, atomFactory, varUniquifier.uniquePrefix(rule->first.label)).apply());

		    const TableOperation* op = 
			conjoints.size() == 0 ? NULL :
			conjoints.size() == 1 ? conjoints[0] :
			new TableConjunction(conjoints.begin(), conjoints.end());

		    if (opts.size() > 1 && op != NULL)
			ret->addTableOperation(op, false);
		    else
			return op; // ret = op loses const-ness.
		}
		return ret;
	    }

	};

	// std::ostream& operator<< (std::ostream& os, const Alternatives& alt) {
	//     return os << alt.str();
	// }

	Alternatives alternatives;
	Failures failed;

	Bindings (AtomFactory* atomFactory, std::vector<Rule>& rules, MapSet::e_sharedVars sharedVars, NodeShare& nodeShare)
	    : atomFactory(atomFactory), rules(rules), alternatives(sharedVars, nodeShare) {  }
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
		    if ((*constraint)->bindVariables(triple, false, &testRS, DefaultGraph, *testRS.begin(), NULL))
			adds.push_back(Add(*rule, testRS));
		}
	    }
	    if (adds.size() == 0 || alternatives.cross(adds) == 0)
		failed.bgp2triples[bgp].insert(triple);
	    // std::cerr << triple->toString() << "\n" << str();
	    return adds.size() > 0;
	}

	const TableOperation* instantiate (Alternatives::VarUniquifier& varUniquifier) {
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

    public:
	QueryWalker (std::vector<Rule>& rules, AtomFactory* atomFactory, MapSet::e_sharedVars sharedVars, NodeShare& nodeShare)
	    : SWObjectDuplicator(atomFactory), bindings(atomFactory, rules, sharedVars, nodeShare) {  }
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const BasicGraphPattern* bgp, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    bindings.alternatives.opts.clear();
	    bindings.alternatives.opts.push_back(Bindings::Rule2rs());
	    for (std::vector<const TriplePattern*>::const_iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)
		bindings.match(bgp, *it);
	    last.tableOperation = (TableOperation*)bindings.instantiate(varUniquifier); // @@ LIES
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
	    p_GroupGraphPattern->express(&d);
	    body = d.last.tableOperation;
	    RecursiveExpressor::whereClause(self, p_GroupGraphPattern, p_BindingClause); // to call variable above.
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
	    if (*debugStream != NULL)
		**debugStream << "adding rule: " << r.toString();
	    rules.push_back(r);
	}
	const Operation* map (const Operation* query) {
	    const Operation* op = QueryWalker(rules, atomFactory, sharedVars, nodeShare).mapQuery(query);
	    BGPSimplifier dup(atomFactory);
	    op->express(&dup);
	    delete op;
	    return dup.last.operation;
	}
    }; // class ChainingMapper

} // namespace w3c_sw

#endif // ChainingMapper_H

