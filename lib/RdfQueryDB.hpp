/* RdfQueryDB - sets of variable bindings and their proofs.
 * $Id: RdfQueryDB.hpp,v 1.4 2008-10-24 10:57:31 eric Exp $
 */

#ifndef RDF_QUERY_DB_H
#define RDF_QUERY_DB_H

#include "RdfDB.hpp"

namespace w3c_sw {
    class DBExpressor;
    class RdfQueryDB : public RdfDB {
	friend class DBExpressor;
	Operation* op;
	const TableOperation* top;

    public:
	RdfQueryDB (const TableOperation* p_op, POSFactory* posFactory);
    };
    class DBExpressor : public RecursiveExpressor {
    protected:
	RdfQueryDB* db;
	POSFactory* posFactory;
	bool optState;

    public:
	DBExpressor (RdfQueryDB* p_db, POSFactory* posFactory) : db(p_db), posFactory(posFactory), optState(false) {  }
	virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
	    p_op->express(this);
	    p_Constraints->express(this);
	}
	void _absorbGraphPattern (BasicGraphPattern* g, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    for (std::vector<const TriplePattern*>::const_iterator it = p_TriplePatterns->begin();
		 it != p_TriplePatterns->end(); it++)
		g->addTriplePattern(posFactory->getTriple(*it, optState));
	}
	virtual void namedGraphPattern (const NamedGraphPattern* const, const POS* p_IRIref, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    _absorbGraphPattern(db->assureGraph(p_IRIref), p_TriplePatterns);
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    _absorbGraphPattern(db->assureGraph(DefaultGraph), p_TriplePatterns);
	}
	virtual void tableDisjunction (TableDisjunction*, const ProductionVector<const TableOperation*>*, const ProductionVector<const Filter*>*) { // p_TableOperations p_Filters
	    throw(std::runtime_error(FUNCTION_STRING)); // query should already be DNF'd, ergo no disjunctions.
	}
	virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    p_TableOperations->express(this);
	}
	virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
	    bool oldOptState = optState;
	    optState = true;
	    p_GroupGraphPattern->express(this);
	    p_Expressions->express(this);
	    optState = oldOptState;
	}
    };

} // namespace w3c_sw

#endif // !RDF_QUERY_DB_H

