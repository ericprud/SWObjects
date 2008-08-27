/* QueryMapper.hpp - simple SPARQL transformer for SPARQL compile trees.
 *
 * $Id: QueryMapper.hpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#ifndef QueryMapper_H
#define QueryMapper_H

#include "SWObjectDuplicator.hpp"
#include "RuleInverter.hpp"

namespace w3c_sw {

    class QueryMapper : public SWObjectDuplicator {
    protected:
	std::vector<MappingConstruct*> invertedRules;
    public:
	QueryMapper (POSFactory* posFactory) : SWObjectDuplicator(posFactory) {  }
	~QueryMapper() {
	    for (std::vector<MappingConstruct*>::iterator it = invertedRules.begin();
		 it != invertedRules.end(); ++it)
		delete *it;
	}
	MappingConstruct* addRule (Construct* rule) {
	    RuleInverter inv(posFactory);
	    rule->express(&inv);
	    MappingConstruct* c = inv.getConstruct();
	    invertedRules.push_back(c);
	    return c;
	}
	virtual TriplePattern* triplePattern999 (POS* p_s, POS* p_p, POS* p_o) {
	    return new TriplePattern(p_s->express(this), p_p->express(this), p_o->express(this));
	}
	virtual NamedGraphPattern* namedGraphPattern (POS* p_name, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    NamedGraphPattern* ret = new NamedGraphPattern(p_name->express(this));
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    DefaultGraphPattern* ret = new DefaultGraphPattern();
	    _TriplePatterns(p_TriplePatterns, ret);
	    _Filters(p_Filters, ret);
	    return ret;
	}
	void _map (TableOperation* op, TableDisjunction* constructed) {
	    RdfQueryDB db(op);

	    /* # 02 — For each rule R in MRs, with an antecedent A and a consequent C:
	     * http://www.w3.org/2008/07/MappingRules/#_02
	     */
	    for (std::vector<MappingConstruct*>::iterator invertedRule = invertedRules.begin();
		 invertedRule != invertedRules.end(); ++invertedRule) {

		/* # 03 — Treat C as a query, each triple being optional.
		 * http://www.w3.org/2008/07/MappingRules/#_03
		 */
		OperationResultSet opRS(constructed);
		(*invertedRule)->execute(&db, &opRS);
		/* rules 04 - 08 are performed by MappingConstruct::execute, called above. */
	    }
	}
	virtual WhereClause* whereClause (TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {

	    /* # 01 — Produce a disjunctive normal form DQI. For each disjunct D:
	     * http://www.w3.org/2008/07/MappingRules/#_01
	     */

	    /* This DNF form is a semi-shallow copy of the graph pattern:
	       It's a copy of the TableOperations, but uses the original
	       triples and filter expressions. It's safe to delete before
	       the original graph pattern.
	     */
	    TableOperation* op = p_GroupGraphPattern->getDNF();

	    /* constructed accumulates a deep copy of the new query.
	       The old graph pattern is deleted.
	     */
	    TableDisjunction* constructed = new TableDisjunction();
	    TableDisjunction* disjoints;
	    if ((disjoints = dynamic_cast<TableDisjunction*>(op)) != NULL)
		for (std::vector<TableOperation*>::iterator d = disjoints->begin();
		     d != disjoints->end(); d++)
		    _map(*d, constructed);
	    else
		_map(op, constructed);
	    delete op;

	    /* # 08 — The final query is the union of each disjoint produce in step 07.
	     * http://www.w3.org/2008/07/MappingRules/#_08
	     */

	    /* Don't return a disjoint with only one object in it. */
	    TableOperation* pattern;
	    if (constructed->size() == 1) {
		pattern = *constructed->begin();
		constructed->clear();
		delete constructed;
	    } else
		pattern = constructed;

	    return new WhereClause(pattern, p_BindingClause ? p_BindingClause->express(this) : NULL);
	}
    };

} // namespace w3c_sw

#endif // QueryMapper_H

