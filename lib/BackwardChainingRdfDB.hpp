/**
 * @file lib/BackwardChainingRdfDB.hpp
 *
 * This RdfDB executes queries over the closure of a set of rules over
 * the ground facts.
 *
 * This implementation uses the ChainingMapper to transform the goal
 * query to a query over the antecedents of the rules, then executes
 * a conjunction of that query with the supporting ground facts.
 */

#include "ChainingMapper.hpp"

namespace w3c_sw {

    /** BackwardChainingRdfDB - an RdfDB which does backward-chaining.
     * @param ms	MapSet of rules
     */
    class BackwardChainingRdfDB : public RdfDB {
    protected:
	AtomFactory* atomFactory;	///< An AtomFactory for creating new TTerm s.
	std::vector<Rule> rules;	///< The set of rules defining the virtual DB.
	MapSet::e_sharedVars sharedVars;///< The rule intersection policy.
	NodeShare nodeShare;		///< For #sharedVars=e_DRACONIAN, the list of mergable rule nodes.

    public:
	/** 
	 * @param atomFactory	An AtomFactory for creating new TTerm s
	 * @param ms		MapSet of rules
	 */
	BackwardChainingRdfDB (AtomFactory* atomFactory, const MapSet* ms)
	    : RdfDB(), atomFactory(atomFactory), sharedVars(MapSet::e_PROMISCUOUS) 
	{
	    for (MapSet::ConstructList::const_iterator it = ms->maps.begin();
		 it != ms->maps.end(); ++it)
		addRule(it->constr, it->label);
	}

	/** This is how you supply rules to the BackwardChainingRdfDB.
	 * @param rule	a SPARQL CONSTRUCT rule.
	 * @param name	an identifier for this rule. This identifier
	 * is used or debugging and when constructing implicit
	 * variable names.
	 */
	void addRule (const Construct* rule, const TTerm* name) {
	    if (name == NULL) {
		std::stringstream ss;
		ss << rule;
		name = atomFactory->getRDFLiteral(ss.str());
	    }
	    Rule r = RuleParser().parseConstruct(rule, name);
	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "adding rule: " << r.toString();
	    rules.push_back(r);
	}

	/** This RdfDB virtual function allows the
	 * BackwardChainingRdfDB to intercept queries and test them
	 * against the rule heads in addition to executing
	 * RdfDB::bindVariables()
	 */
	virtual void bindVariables (ResultSet* rs, const TTerm* graph, const BasicGraphPattern* toMatch) const {
	    ResultSet island(rs->getAtomFactory());
	    RdfDB::bindVariables(&island, graph, toMatch);

	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "matching: " << *toMatch << "\nagainst ground facts got:\n" << island;

	    std::vector<const TriplePattern*> ground;
	    Bindings bindings(atomFactory, rules, sharedVars, nodeShare);
	    bindings.alternatives.opts.clear();
	    bindings.alternatives.opts.push_back(Bindings::Rule2rs());
	    for (std::vector<const TriplePattern*>::const_iterator it = toMatch->begin();
		 it != toMatch->end(); it++) {
		DefaultGraphPattern bgp;
		bgp.addTriplePattern(*it);
		ResultSet forRule(rs->getAtomFactory());
		RdfDB::bindVariables(&forRule, graph, &bgp);
		if (forRule.size() > 0) {
		    ground.push_back(*it);
		} else {
// 		// We only want to include the above "rules" if they interact with the rules added by match.
		    bindings.match(toMatch, graph, *it);
		}
	    }

// w3c_sw_LINEN << "opts: " << bindings.alternatives.opts.str() << "\n";
	    if (bindings.failed.size() > 0) {
		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "unable to match\n" << bindings.failed.toString(toMatch);
	    } else {
		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "reachable by rules: " << bindings << " -> [[\n";
		ResultSet disjoint(rs->getAtomFactory());

		Bindings::Alternatives::VarUniquifier varUniquifier;
		const TableOperation* gp = bindings.alternatives.instantiate(atomFactory, varUniquifier);
		if (gp != NULL) {
		    DefaultGraphPattern bgp;
		    for (std::vector<const TriplePattern*>::const_iterator tp = ground.begin();
			 tp != ground.end(); ++tp)
			bgp.addTriplePattern(*tp);
		    TableConjunction conj;
		    conj.addTableOperation(&bgp, false);
		    conj.addTableOperation(gp, false);
		    conj.bindVariables(this, rs);

		    for (ResultSetIterator row = disjoint.begin() ; row != disjoint.end(); ) {
			island.insert(island.end(), (*row)->duplicate(&island, island.end()));
			delete *row;
			row = disjoint.erase(row);
		    }
		    conj.clear(); // don't delete gp
		}
		BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "]]\n";
	    }

	    rs->joinIn(&island);
	    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "Backward chaining produced\n" << *rs;
	}
    };

}

