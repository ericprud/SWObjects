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
	size_t index;
	Rule (DefaultGraphPattern* head, const TableOperation* body) :
	    head(head), body(body), index(0) {  }
    };
    inline bool operator< (const Rule& l, const Rule& r) { return l.index < r.index; }
    std::ostream& operator<< (std::ostream& os, const Rule& rule) {
	SPARQLSerializer body, head;
	rule.body->express(&body);
	rule.head->express(&head);
	return os << body.str() << " => " << std::endl << head.str();
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
	typedef std::map<const Rule, ResultSet> Rule2rs;
	Rule2rs rule2rs;
	Failures failed;

	Bindings (POSFactory* posFactory, std::vector<Rule>& rules) : posFactory(posFactory), rules(rules) {  }

	/**
	 * Match a triple pattern against the rule heads.
	 * Ensure a binding entry for matched pattern.
	 *
	 * HEAD: { ?patient sdtm:dateTimeOfBirth ?dob }
	 * TRIPLE: ?who sdtm:dateTimeOfBirth "1966-11-08T00:00"^^xsd:dateTime .
	 *
	 */
	bool match (const BasicGraphPattern* bgp, const TriplePattern* triple) {
	    bool foundARule = false;

	    /** For each rule... */
	    for (std::vector<Rule>::const_iterator rule = rules.begin();
		 rule != rules.end(); ++rule) {

		/** For each triple in the rule head... */
		for (std::vector<const TriplePattern*>::const_iterator constraint = rule->head->begin();
		     constraint != rule->head->end(); constraint++) {

		    /** If the pattern matches the triple. */
		    ResultSet empty(posFactory);
		    if ((*constraint)->bindVariables(triple, false, &empty, DefaultGraph, *empty.begin(), NULL)) {
			foundARule = true;

			/** Test against existing variable bindings for that rule. */
			bool rowMatched = false;
			Rule2rs::iterator boundRule = rule2rs.find(*rule);
			if (boundRule != rule2rs.end()) {
			    ResultSet& rs(boundRule->second);
			    for (ResultSetIterator row = rs.begin() ; !rowMatched && row != rs.end(); ++row) {
				Result* newRow = (*row)->duplicate(&rs, row);
				if ((*constraint)->bindVariables(triple, false, &rs, DefaultGraph, newRow, NULL)) {
				    /** Replace the current row with one reflecting the new bindings. */
				    rs.insert(row, newRow);
				    delete *row;
				    row = rs.erase(row);
				    /** We're done (@@ is this complete?) */
				    rowMatched = true;
				} else {
				    delete newRow;
				}
			    }
			}
			if (!rowMatched) {
			    /** Start a new result. */
			    if (boundRule == rule2rs.end()) {
				/** First binding for this rule. */
				rule2rs.insert(std::pair<const w3c_sw::Rule, w3c_sw::ResultSet>(*rule, empty));
			    } else {
				ResultSet& rs(boundRule->second);
				rs.insert(rs.end(), *empty.begin());
			    }
			}
		    }
		}
	    }
	    if (!foundARule)
		failed.bgp2triples[bgp].insert(triple);
	    return foundARule;
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

	TableOperation* instantiate () {
	    // std::cerr << "instantiate " << str();
	    std::vector<TableOperation*> conjoints;
	    for (Rule2rs::const_iterator rule = rule2rs.begin();
		 rule != rule2rs.end(); ++rule) {
		for (ResultSetConstIterator res = rule->second.begin();
		     res != rule->second.end(); ++res)
		    conjoints.push_back(Instantiator(rule->first.body, *res, posFactory).apply());
	    }
	    if (conjoints.size() == 0)
		return NULL;
	    if (conjoints.size() == 1)
		return conjoints[0];
	    TableConjunction* ret = new TableConjunction();
	    for (std::vector<TableOperation*>::const_iterator conjoint = conjoints.begin();
		 conjoint != conjoints.end(); ++conjoint)
		ret->addTableOperation(*conjoint, false);
	    return ret;
	}
	std::string str () const {
	    std::stringstream ss;
	    for (Rule2rs::const_iterator rule = rule2rs.begin();
		 rule != rule2rs.end(); ++rule) {
		ss << rule->first << std::endl << rule->second;
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
    public:
	QueryWalker (std::vector<Rule>& rules, POSFactory* posFactory)
	    : SWObjectDuplicator(posFactory), bindings(posFactory, rules) {  }
	/* _TriplePatterns factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TriplePatterns (const BasicGraphPattern* bgp, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    for (std::vector<const TriplePattern*>::const_iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)
		bindings.match(bgp, *it);
	    last.tableOperation = bindings.instantiate();
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

	RuleParser () : d(NULL) {  }

	virtual void base (const Base* const /* self */, std::string productionName) {
	    throw std::string("RuleParser::base(") + productionName + ") called";
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause*) {
	    p_GroupGraphPattern->express(&d);
	    body = d.last.tableOperation;
	}
	virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>*, WhereClause* p_WhereClause, SolutionModifier*) {
	    p_ConstructTemplate->express(&d);
	    head = dynamic_cast<DefaultGraphPattern*>(d.last.tableOperation);
	    p_WhereClause->express(this);
	}
	Rule parseConstruct (const Construct* c) {
	    c->express(this);
	    return Rule(head, body);
	}
    };

    class ChainingMapper : public SWObjectDuplicator {
    protected:
	std::vector<Rule> rules;
	std::ostream** debugStream;

    public:
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
	int getRuleCount () { return rules.size(); }
	void addRule (const Construct* rule) {
	    Rule r = RuleParser().parseConstruct(rule);
	    r.index = rules.size();
	    rules.push_back(r);
	}
	const Operation* map (const Operation* query) {
	    return QueryWalker(rules, posFactory).mapQuery(query);
	}
    };

} // namespace w3c_sw

#endif // ChainingMapper_H

