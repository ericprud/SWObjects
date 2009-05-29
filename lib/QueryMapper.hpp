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

namespace w3c_sw {

    struct LabeledConstruct {
	const RDFLiteral* label;
	const Construct* constr;
	LabeledConstruct (const RDFLiteral* label, const Construct* constr) : label(label), constr(constr) {  }
    };
    inline bool operator== (const LabeledConstruct& l, const LabeledConstruct& r) {
	return l.label == r.label && *(l.constr) == *(r.constr);
    }
    inline bool operator< (const LabeledConstruct& l, const LabeledConstruct& r) {
	return l.label != r.label ? 
	    l.label->getLexicalValue() < r.label->getLexicalValue() : // !!! should be POSFactory::cmp
	    l.constr < r.constr; // compare addrs. really needs Construct::operator<(Construct&).
    }
    inline std::ostream& operator<< (std::ostream& os, LabeledConstruct const& labeledConstruct) {
	os << "    rule " << labeledConstruct.label->toString();
	return os;
    }

    class QueryMapper : public SWObjectDuplicator {
    protected:
	std::vector<MappingConstruct*> invertedRules;
	int ruleCount;
	std::ostream** debugStream;

    public:
	QueryMapper (POSFactory* posFactory, std::ostream** debugStream) : SWObjectDuplicator(posFactory), ruleCount(0), debugStream(debugStream) {  }
	~QueryMapper () { clear(); }
	void clear () {
	    for (std::vector<MappingConstruct*>::iterator it = invertedRules.begin();
		 it != invertedRules.end(); ++it)
		delete *it;
	    invertedRules.clear();
	}
	int getRuleCount () { return ruleCount; }
	MappingConstruct* addRule (Construct* rule) {
	    RuleInverter inv(posFactory, debugStream);
	    rule->express(&inv);
	    MappingConstruct* c = inv.getConstruct();
	    invertedRules.push_back(c);
	    ++ruleCount;
	    return c;
	}
	void _map (const TableOperation* userQueryDisjoint, TableDisjunction* constructed) {
	    RdfQueryDB userQueryAsAssertions(userQueryDisjoint, posFactory);

	    /* # 02 — For each rule R in MRs, with an antecedent A and a consequent C:
	     * http://www.w3.org/2008/07/MappingRules/#_02
	     */
	    if (*debugStream != NULL)
		**debugStream << "User query disjoint " << endl << 
		    *userQueryDisjoint << endl << 
		    "(as DB):" << endl << 
		    userQueryAsAssertions << endl;
	    for (std::vector<MappingConstruct*>::iterator invertedRule = invertedRules.begin();
		 invertedRule != invertedRules.end(); ++invertedRule) {

		if (*debugStream != NULL)
		    **debugStream << "matched against rule head (expressed as a pattern)" << endl << 
			*(*invertedRule)->getRuleBody() << endl;
		/* # 03 — Treat C as a query, each triple being optional.
		 * http://www.w3.org/2008/07/MappingRules/#_03
		 */
		OperationResultSet opRS(posFactory, constructed, userQueryDisjoint);
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

    class MapSet : public Operation {
	friend class MapSetParser;
    protected:
	const RDFLiteral* server;
	const RDFLiteral* user;
	const RDFLiteral* password;
	const RDFLiteral* database;
	const URI* stemURI;
	const RDFLiteral* primaryKey;
	std::vector<LabeledConstruct> maps;
#if REGEX_LIB == SWOb_BOOST
#endif /* REGEX_LIB == SWOb_BOOST */

    public:
	~MapSet () {
	    for (std::vector<LabeledConstruct>::iterator it = maps.begin(); 
		 it != maps.end(); ++it) {
		delete it->constr;
	    }
	}
	virtual void express(Expressor* p_expressor) const;
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
	    for (std::vector<LabeledConstruct>::iterator it = maps.begin(); 
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
    };

    inline void MapSet::express (Expressor* /* p_expressor */) const {
	// p_expressor->construct(this, m_ConstructTemplate, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
    }

} // namespace w3c_sw

#endif // QueryMapper_H

