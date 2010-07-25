/* ChainingMapper.hpp - backwards-chaining Operation transformer.
 *
 * $Id: ChainingMapper.hpp,v 1.12 2008-11-03 19:24:26 eric Exp $
 */

#ifndef ChainingMapper_H
#define ChainingMapper_H

#include <map>

#include "SWObjectDuplicator.hpp"
#include "SPARQLSerializer.hpp"
#include "RdfQueryDB.hpp"

namespace w3c_sw {

    class ChainingMapper;

    struct Rule {
	DefaultGraphPattern* head;
	const TableOperation* body;
	const POS* label;

	/* It's not necessary to know all of the variables in a rule head
	   (bodyVars); just handy for explanation/debugging. */
	VariableList bodyVars;

	Rule (DefaultGraphPattern* head, const TableOperation* body, const POS* label, VariableList bodyVars) :
	    head(head), body(body), label(label), bodyVars(bodyVars) {  }

	std::string str () const {
	    if (label == NULL) {
		SPARQLSerializer bodySer, headSer;
		body->express(&bodySer);
		head->express(&headSer);
		return bodySer.str() + " => \n" + headSer.str();
	    } else
		return label->toString();
	}

	bool operator== (const Rule& ref) const {
	    return label == ref.label && head == ref.head && body == ref.body;
	}
    };
    inline bool operator< (const Rule& l, const Rule& r) { return l.label < r.label; }
    std::ostream& operator<< (std::ostream& os, const Rule& rule) {
	return os << rule.str();
    }

    struct Bindings {
	struct Failures {
	    typedef std::set<const TriplePattern*> Triples;
	    typedef std::map<const BasicGraphPattern*, Triples > Bgp2Triples;
	    Bgp2Triples bgp2triples;
	    size_t size () const { return bgp2triples.size(); }

	    /**
	     * Single interface function to create and return the error string.
	     */
	    std::string toString (const Operation* op) {
		struct FailureSerializer : public SPARQLSerializer {
		    const Bgp2Triples& bgp2triples;
		    FailureSerializer (const Bgp2Triples& bgp2triples, 
				       const char* p_tab = "  ", e_DEBUG debug = DEBUG_none, const char* leadStr = "", NamespaceMap* namespaces = NULL) : 
			SPARQLSerializer(p_tab, debug, leadStr, namespaces), bgp2triples(bgp2triples)
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
		    virtual void namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
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
		};
		return FailureSerializer(bgp2triples).toString(op);
	    }
	};

	POSFactory* posFactory;
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

	    struct RuleTerm {
		Rule rule;
		const POS* term;
		RuleTerm (Rule rule, const POS* term) : rule(rule), term(term) {  }
		std::string str () {
		    return rule.str() + "." + term->toString();
		}
		// void operator= (const RuleTerm& ref) {
		// }

		inline bool operator< (const RuleTerm& ref) const {
		    return rule == ref.rule ? term < ref.term : rule < ref.rule;
		}

	    };
	    /* Map query terms to their uses in RuleTerms. Insertion of
	       incompatible RuleTerm into this map indicates an inconsistent
	       solution. (e.g. ?name used as People.?name and Places.?name.)
	    */
	    struct QueryTermUsage : std::map<const POS*, std::set<RuleTerm> > {
		// void operator= (const QueryTermUsage& ref) {
		// }
	    };

	    QueryTermUsage termUsage;

	    bool inconsistentWith (const Rule& rule, const ResultSet& testRS) {
		const Result* testRow = *testRS.begin();
		{
		    for (BindingSetConstIterator var = testRow->begin(); var != testRow->end(); ++var) {
			const POS* ruleVar = var->first;
			const POS* queryTerm = var->second.pos;
			QueryTermUsage::iterator it = termUsage.find(queryTerm);
			if (it != termUsage.end()) {
			    for (std::set<RuleTerm>::const_iterator existingRuleTerm = it->second.begin();
				 existingRuleTerm != it->second.end(); ++existingRuleTerm)
				if (ruleVar != existingRuleTerm->term)
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
			const POS* ruleVar = var->first;
			const POS* queryTerm = var->second.pos;
			// termUsage[queryTerm].insert(RuleTerm(rule, ruleVar));
			QueryTermUsage::iterator it = termUsage.find(queryTerm);
			if (it == termUsage.end()) {
			    std::set<RuleTerm> s;
			    std::pair<const POS*, std::set<RuleTerm> > pt(queryTerm, s);
			    it = termUsage.insert(pt).first;
			}
			it->second.insert(RuleTerm(rule, ruleVar));
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
	struct Alternatives : public std::vector<Rule2rs> {
	    bool sharedVars;

	    Alternatives (bool sharedVars) : std::vector<Rule2rs>(1), sharedVars(sharedVars) {  }

	    /** cross: create a cross product with the vector of added rule
	       bindings. Enforce all integrity constraints and return the count
	       of resulting alternatives.
	     */
	    size_t cross (const std::vector<Add> adds) {
		if (adds.size() == 0)
		    clear();
		else {
		    for (Alternatives::iterator alt = begin(); alt != end(); ) {
			for (std::vector<Add>::const_iterator it_add = adds.begin();
			     it_add != adds.end(); ) {
			    Add add = *it_add++;
			    if (sharedVars && alt->inconsistentWith(add.rule, add.rs)) {
				// Inconsistent solution.
				alt = erase(alt);
			    } else {
				// If this is the last add, overwrite the alternative,
				// otherwise copy and insert before.
				if (it_add != adds.end())
				    alt = insert(alt, *alt);
				alt->add(add.rule, add.rs);
				++alt;
			    }
			}
		    }
		}
		return size(); // 0 indicates we've run out of viable solutions.
	    }
	};

	// std::ostream& operator<< (std::ostream& os, const Alternatives& alt) {
	//     return os << alt.str();
	// }

	Alternatives alternatives;
	Failures failed;

	Bindings (POSFactory* posFactory, std::vector<Rule>& rules, bool sharedVars)
	    : posFactory(posFactory), rules(rules), alternatives(sharedVars) {  }
	void operator= (const Bindings& ref) {
	    posFactory = ref.posFactory;
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

		    ResultSet testRS(posFactory);
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

	struct Instantiator : public SWObjectDuplicator {
	    const TableOperation* pattern;
	    const Result* res;
	    Instantiator (const TableOperation* pattern, const Result* res, POSFactory* posFactory)
		: SWObjectDuplicator(posFactory), pattern(pattern), res(res) {  }
	    virtual void variable (const Variable* const self, std::string lexicalValue) {
		last.posz.pos = res->get(self) == NULL ? self : res->get(self);
		/* @@ doesn't set e.g. last.posz.variable */
	    }
	    virtual void bnode (const BNode* const self, std::string lexicalValue) {
		last.posz.pos = res->get(self) == NULL ? self : res->get(self);
		/* @@ doesn't set e.g. last.posz.variable */
	    }
	    TableOperation* apply () {
		pattern->express(this);
		return last.tableOperation;
	    }
	};

	const TableOperation* instantiate () {
	    // std::cerr << "instantiate " << str();
	    TableDisjunction* ret = NULL;
	    if (alternatives.size() > 1)
		ret = new TableDisjunction();
	    for (std::vector<Rule2rs>::const_iterator alternative = alternatives.begin();
		 alternative != alternatives.end(); ++alternative) {
		std::vector<const TableOperation*> conjoints;
		for (Rule2rs::const_iterator rule = alternative->begin();
		     rule != alternative->end(); ++rule)
		    for (ResultSetConstIterator res = rule->second.begin();
			 res != rule->second.end(); ++res)
			conjoints.push_back(Instantiator(rule->first.body, *res, posFactory).apply());

		const TableOperation* op = 
		    conjoints.size() == 0 ? NULL :
		    conjoints.size() == 1 ? conjoints[0] :
		    new TableConjunction(conjoints.begin(), conjoints.end());

		if (alternatives.size() > 1 && op != NULL)
		    ret->addTableOperation(op, false);
		else
		    return op; // ret = op loses const-ness.
	    }
	    return ret;
	}

	std::string str () const {
	    std::stringstream ss;
	    for (std::vector<Rule2rs>::const_iterator disjoint = alternatives.begin();
		 disjoint != alternatives.end(); ++disjoint) {
		if (disjoint != alternatives.begin())
		    ss << "UNION\n";
		for (Rule2rs::const_iterator rule = disjoint->begin();
		     rule != disjoint->end(); ++rule) {
		    ss << rule->first << std::endl << rule->second;
		}
	    }
	    return ss.str();
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
	bool sharedVars;
    public:
	QueryWalker (std::vector<Rule>& rules, POSFactory* posFactory, bool sharedVars)
	    : SWObjectDuplicator(posFactory), bindings(posFactory, rules, sharedVars) {  }
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const BasicGraphPattern* bgp, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    for (std::vector<const TriplePattern*>::const_iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)
		bindings.match(bgp, *it);
	    last.tableOperation = (TableOperation*)bindings.instantiate(); // @@ LIES
	}
	virtual void namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
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
	Rule parseConstruct (const Construct* c, const POS* name) {
	    c->express(this);
	    return Rule(head, body, name, bodyVars);
	}
    };

    class ChainingMapper : public SWObjectDuplicator {
    protected:
	std::vector<Rule> rules;
	std::ostream** debugStream;

    public:
	bool sharedVars;

	ChainingMapper (POSFactory* posFactory, std::ostream** debugStream) : SWObjectDuplicator(posFactory), debugStream(debugStream) {  }
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
	void addRule (const Construct* rule, const POS* name) {
	    if (name == NULL)
		name = posFactory->getRDFLiteral(rule->toString());
	    Rule r = RuleParser().parseConstruct(rule, name);
	    rules.push_back(r);
	}
	const Operation* map (const Operation* query) {
	    const Operation* op = QueryWalker(rules, posFactory, sharedVars).mapQuery(query);
	    BGPSimplifier dup(posFactory);
	    op->express(&dup);
	    delete op;
	    return dup.last.operation;
	}
    }; // class ChainingMapper

} // namespace w3c_sw

#endif // ChainingMapper_H

