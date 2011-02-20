/* QueryMapper.hpp - simple SPARQL transformer for SPARQL compile trees.
 * This is a simple SWObjectDuplicator with an overloaded whereClause method
 * to match against each of the patterns in the rule heads.
 *
 * $Id: QueryMapper.hpp,v 1.12 2008-11-03 19:24:26 eric Exp $
 */

#ifndef QueryMapper_H
#define QueryMapper_H

#include "SWObjectDuplicator.hpp"
#include "RuleInverter.hpp"
#include "RdfQueryDB.hpp"
#include "prfxbuf.hpp"

namespace w3c_sw {

    struct LabeledConstruct {
	const TTerm* label;
	const Construct* constr;
	LabeledConstruct (const TTerm* label, const Construct* constr) : label(label), constr(constr) {  }
	virtual ~LabeledConstruct () {  }
	virtual void express (Expressor* p_expressor) const {
	    if (label != NULL) label->express(p_expressor);
	    constr->express(p_expressor);
	}
    };
    inline bool operator== (const LabeledConstruct& l, const LabeledConstruct& r) {
	return l.label == r.label && *(l.constr) == *(r.constr);
    }
    inline bool operator< (const LabeledConstruct& l, const LabeledConstruct& r) {
	return l.label != r.label ? 
	    l.label->getLexicalValue() < r.label->getLexicalValue() : // !!! should be AtomFactory::cmp
	    l.constr < r.constr; // compare addrs. really needs Construct::operator<(Construct&).
    }
    inline std::ostream& operator<< (std::ostream& os, LabeledConstruct const& lc) {
	os << "    rule " << (lc.label == NULL ? lc.constr->toString() : lc.label->toString());
	return os;
    }

    class QueryMapper : public SWObjectDuplicator {
    protected:
	std::vector<MappingConstruct*> invertedRules;
	int ruleCount;

    public:
	QueryMapper (AtomFactory* atomFactory) : SWObjectDuplicator(atomFactory), ruleCount(0) {  }
	~QueryMapper () { clear(); }
	void clear () {
	    for (std::vector<MappingConstruct*>::iterator it = invertedRules.begin();
		 it != invertedRules.end(); ++it)
		delete *it;
	    invertedRules.clear();
	}
	int getRuleCount () { return ruleCount; }
	MappingConstruct* addRule (const Construct* rule) {
	    RuleInverter inv(atomFactory);
	    rule->express(&inv);
	    MappingConstruct* c = inv.getConstruct();
	    invertedRules.push_back(c);
	    ++ruleCount;
	    return c;
	}
	void _map (const TableOperation* userQueryDisjoint, TableDisjunction* constructed) {
	    RdfQueryDB userQueryAsAssertions(userQueryDisjoint, atomFactory);

	    /* # 02 — For each rule R in MRs, with an antecedent A and a consequent C:
	     * http://www.w3.org/2008/07/MappingRules/#_02
	     */
	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "Firing " << invertedRules.size() << " rules againsts user query disjoint " << std::endl << 
		*userQueryDisjoint << std::endl << 
		"(as DB):" << std::endl << 
		userQueryAsAssertions << std::endl;
	    for (std::vector<MappingConstruct*>::iterator invertedRule = invertedRules.begin();
		 invertedRule != invertedRules.end(); ++invertedRule) {

		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "matched against rule head (expressed as a pattern)" << std::endl << 
		    *(*invertedRule)->getRuleBody() << std::endl;
		/* # 03 — Treat C as a query, each triple being optional.
		 * http://www.w3.org/2008/07/MappingRules/#_03
		 */
		OperationResultSet opRS(atomFactory, constructed, userQueryDisjoint);
		(*invertedRule)->executeMapping(&userQueryAsAssertions, &opRS);
		/* rules 04 - 08 are performed by MappingConstruct::execute, called above. */
	    }
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {

	    /* # 01 — Produce a disjunctive normal form DQI. For each disjunct D:
	     * http://www.w3.org/2008/07/MappingRules/#_01
	     */

	    /* This DNF form is a semi-shallow copy of the graph pattern:
	       It's a copy of the TableOperations, but uses the original
	       triples and filter expressions. It's safe to delete before
	       the original graph pattern.
	     */
	    TableOperation* userQueryAsDNF = p_GroupGraphPattern->getDNF();

	    /* constructed accumulates a deep copy of the new query.
	       The old graph pattern is deleted.
	     */
	    TableDisjunction* constructed = new TableDisjunction();
	    TableDisjunction* disjoints;
	    if ((disjoints = dynamic_cast<TableDisjunction*>(userQueryAsDNF)) != NULL)
		for (std::vector<const TableOperation*>::iterator d = disjoints->begin();
		     d != disjoints->end(); d++)
		    _map(*d, constructed); /* LIES */
	    else
		_map(userQueryAsDNF, constructed);
	    delete userQueryAsDNF;

	    /* # 08 — The final query is the union of each disjoint produce in step 07.
	     * http://www.w3.org/2008/07/MappingRules/#_08
	     */
	    TableOperation* pattern = constructed->simplify();
	    if (pattern == NULL)
		pattern = new DefaultGraphPattern();

	    last.bindingClause = NULL;
	    if (p_BindingClause != NULL)
		p_BindingClause->express(this);

	    last.whereClause = new WhereClause(pattern, last.bindingClause);
	}
    };

    struct Rule {
	DefaultGraphPattern* head;
	const TableOperation* body;
	const TTerm* label;

	/* It's not necessary to know all of the variables in a rule head
	   (bodyVars); just handy for explanation/debugging. */
	VariableList bodyVars;

	Rule (DefaultGraphPattern* head, const TableOperation* body, const TTerm* label, VariableList bodyVars)
	    : head(head), body(body), label(label), bodyVars(bodyVars) {  }
	Rule (const Rule& ref)
	    : head(ref.head), body(ref.body), label(ref.label), bodyVars(ref.bodyVars) {  }

	/** str - minimum string representation of a rule.
	 */
	std::string str () const {
	    return label == NULL ? toString() : label->toString();
	}

	/** toString - elaborate string representation of a rule.
	 */
	std::string toString (MediaType mediaType = MediaType(), NamespaceMap* namespaces = NULL) const {
	    std::string l;
	    if (label == NULL) {
		std::stringstream ss;
		ss << "?_" << this;
		l = ss.str();
	    } else
		l = label->toString() + " ";

	    SPARQLSerializer bodySer(mediaType, namespaces), headSer(mediaType, namespaces);
	    body->express(&bodySer);
	    head->express(&headSer);

	    /** Indent for readability: */
	    std::stringstream ss;
	    oprfxstream b(ss.rdbuf(), "   ");
	    b << "LABEL " << l << " CONSTRUCT " << headSer.str() << " WHERE " << bodySer.str();

	    return ss.str();
	}

	bool operator== (const Rule& ref) const {
	    return label == ref.label && head == ref.head && body == ref.body;
	}
    };
    inline bool operator< (const Rule& l, const Rule& r) { return l.label < r.label; }
    inline std::ostream& operator<< (std::ostream& os, const Rule& rule) {
	return os << rule.str();
    }

    struct RuleTerm {
	const TTerm* rule;
	const TTerm* term;
	RuleTerm (const TTerm* rule, const TTerm* term) : rule(rule), term(term) {  }
	RuleTerm (const RuleTerm& ref) : rule(ref.rule), term(ref.term) {  }
	std::string str () {
	    return rule->toString() + "." + term->toString();
	}
	void operator= (const RuleTerm& ref) { // @@ needed?
	    rule = ref.rule;
	    term = ref.term;
	}

	inline bool operator< (const RuleTerm& ref) const {
	    return rule == ref.rule ? term < ref.term : rule < ref.rule;
	}

    };

    /* A NodeShare asserts which RuleTerms connect to which other RuleTerms.
     */
    struct NodeShare {

	/* ConnectSet - Set of connected RuleTerm.
	 */
	struct ConnectSet : std::set<RuleTerm> {
	};
	std::vector<ConnectSet> allConnections;

	/* Map from RuleTerm to it's containing ConnectSet as stored in
	   allConnections.
	*/
	typedef std::map<RuleTerm, ConnectSet*> Index;
	Index index;

	void operator= (const NodeShare& ref) {
	    for (std::vector<ConnectSet>::const_iterator cs = ref.allConnections.begin();
		 cs != ref.allConnections.end(); ++cs) {
		std::vector<ConnectSet>::iterator x = allConnections.insert(allConnections.end(), *cs);
		ConnectSet* newSet = &*x;
		for (ConnectSet::const_iterator rt = cs->begin();
		     rt != cs->end(); ++rt)
		    index[*rt] = newSet;
	    }
	}

	void addIntersection (RuleTerm l, RuleTerm r) {
	    Index::const_iterator it = index.find(l);
	    if (it == index.end())
		it = index.find(r);
	    if (it == index.end()) {
		std::vector<ConnectSet>::iterator newCon = allConnections.insert(allConnections.end(), ConnectSet());
		it = index.insert(std::pair<RuleTerm, ConnectSet*>(l, &*newCon)).first;
	    }
	    it->second->insert(l);
	    it->second->insert(r);
	    index[l] = it->second;
	    index[r] = it->second;
	}

	bool connects (const RuleTerm l, const RuleTerm r) const {
	    Index::const_iterator it = index.find(l);
	    return it != index.end() && it->second->find(r) != it->second->end();
	}
    };

    /* A KeyMap asserts which RuleTerms connect to which other RuleTerms.
     */
    struct KeyMap : public std::map<std::string, std::string> {
    };

    class MapSet : public Operation {
	friend class MapSetParser;
    public:
	typedef std::vector<LabeledConstruct> ConstructList;

	const RDFLiteral* server;
	const RDFLiteral* user;
	const RDFLiteral* password;
	const RDFLiteral* database;
	const URI* stemURI;
	const RDFLiteral* primaryKey;
	typedef enum { e_PROMISCUOUS, e_VARNAMES, e_DRACONIAN } e_sharedVars;
	e_sharedVars sharedVars;
	NodeShare nodeShare;
	KeyMap keyMap;
	ConstructList maps;
#if REGEX_LIB == SWOb_BOOST
#endif /* REGEX_LIB == SWOb_BOOST */

    public:
	MapSet ()
	    : server(NULL), user(NULL), password(NULL), database(NULL),
	      stemURI(NULL), primaryKey(NULL), sharedVars(e_PROMISCUOUS),
	      nodeShare(), keyMap(), maps()
	{  }
	~MapSet () {
	    for (ConstructList::iterator it = maps.begin(); 
		 it != maps.end(); ++it) {
		delete it->constr;
	    }
	}
	virtual void express (Expressor* p_expressor) const { // ???
	    if (server != NULL) server->express(p_expressor);
	    if (user != NULL) user->express(p_expressor);
	    if (password != NULL) password->express(p_expressor);
	    if (database != NULL) database->express(p_expressor);
	    if (stemURI != NULL) stemURI->express(p_expressor);
	    if (primaryKey != NULL) primaryKey->express(p_expressor);
	    for (ConstructList::const_iterator it = maps.begin();
		 it != maps.end(); ++it)
		it->express(p_expressor);
	}

	virtual bool operator== (const Operation& ref) const {
	    const MapSet* pMapSet = dynamic_cast<const MapSet*>(&ref);
	    if (pMapSet == NULL)
		return false;
	    return
		server == pMapSet->server && 
		user == pMapSet->user && 
		password == pMapSet->password && 
		database == pMapSet->database && 
		stemURI == pMapSet->stemURI && 
		primaryKey == pMapSet->primaryKey && 
		maps == pMapSet->maps
#if REGEX_LIB != SWOb_DISABLED
#if NotYet
		&& rewriteVars == pMapSet->rewriteVars

#endif /* NotYet */
#endif /* REGEX_LIB != SWOb_DISABLED */
		;
	}
	/* Gives rules to QueryMapper and !deletes self!.
	 */
#if NotYet
	void addRules (QueryMapper* queryMapper) {
	    for (ConstructList::iterator it = maps.begin(); 
		 it != maps.end(); ++it) {
		queryMapper->addRule(*it);
	    }
	    maps.clear();
#if REGEX_LIB == SWOb_BOOST
	    for (ProductionVector<POSmap*>::iterator it = rewriteVars.begin(); 
		 it != rewriteVars.end(); ++it)
		queryMapper.addRule(*it); !!!
	    rewriteVars.clear();
#endif /* REGEX_LIB == SWOb_BOOST */
	    delete this;
	}
#endif /* NotYet */

	virtual e_OPTYPE getOperationType () const { return OPTYPE_unknown; } // @@ could try to unify with OPTYPE_operationSet
	std::string toString () const {
	    std::stringstream ss;
	    if (server != NULL) ss << "server: " << server->toString() << std::endl;
	    if (user != NULL) ss << "user: " << user->toString() << std::endl;
	    if (password != NULL) ss << "password: " << password->toString() << std::endl;
	    if (database != NULL) ss << "database: " << database->toString() << std::endl;
	    if (stemURI != NULL) ss << "stemURI: " << stemURI->toString() << std::endl;
	    if (primaryKey != NULL) ss << "primaryKey: " << primaryKey->toString() << std::endl;
	    size_t i = 0;
	    for (ConstructList::const_iterator it = maps.begin();
		 it != maps.end(); ++it, ++i) {
		ss << "[" << i << "]: ";
		SPARQLSerializer ser;
		it->express(&ser);
		ss << ser.str();
	    }
	    return ss.str();
	}

    };

    inline std::ostream& operator<< (std::ostream& os, MapSet const& my) {
	return os << my.toString();
    }

} // namespace w3c_sw

#endif // QueryMapper_H

