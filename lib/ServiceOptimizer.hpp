
#ifndef INCLUDED_ServiceOptimizer
#define INCLUDED_ServiceOptimizer

namespace w3c_sw {
    /** Example overload of SWObjectCanonicalizer to order SERVICEs by
     *  some supplied order.
     */

    struct ServiceOptimizer : public SWObjectCanonicalizer {
	std::map<const TTerm*, int> order;

	struct ServiceOptimizerTableOperationSorter : public SWObjectCanonicalizer::TableOperationSorter {
	    std::map<const TTerm*, int> order;

	    struct OptimizingOperationSorter : public SWObjectCanonicalizer::TableOperationSorter::OperationSorter {
		std::map<const TTerm*, int> order;

		struct RHS_serviceGraphPattern_Opt : public SWObjectCanonicalizer::TableOperationSorter::OperationSorter::RHS_serviceGraphPattern {
		    std::map<const TTerm*, int> order;
		    RHS_serviceGraphPattern_Opt (AtomFactory* atomFactory, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, bool lex, std::map<const TTerm*, int> order)
			: RHS_serviceGraphPattern(atomFactory, p_TTerm, p_GroupGraphPattern, lex), order(order)
		    {  }
		    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory*, bool) {
			ret = l_TTerm != p_TTerm ? order[l_TTerm] < order[p_TTerm] ? SORT_lt : SORT_gt : _tableOperationOnOperation(p_GroupGraphPattern);
		    }
		};


		OptimizingOperationSorter (AtomFactory* atomFactory, const TableOperation* rhs, std::map<const TTerm*, int> order)
		    : OperationSorter(atomFactory, rhs), order(order)
		{  }

		virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, AtomFactory* atomFactory, bool lexicalCompare) {
		    RHS_serviceGraphPattern_Opt slave(atomFactory, p_TTerm, p_GroupGraphPattern, lexicalCompare, order);
		    rhs->express(&slave);
		    ret = slave.ret;
		}
		
	    };
	    ServiceOptimizerTableOperationSorter (AtomFactory* atomFactory, std::map<const TTerm*, int> order)
		: TableOperationSorter (atomFactory), order(order)
	    {  }
	    bool operator () (const TableOperation* lhs, const TableOperation* rhs) {
		OptimizingOperationSorter os(atomFactory, rhs, order);
		lhs->express(&os);
		return os.ret == SORT_lt;
	    }
	};

	ServiceOptimizer (AtomFactory* atomFactory, std::map<const TTerm*, int> order)
	    : SWObjectCanonicalizer (atomFactory), order(order)
	{  }

	/* _TableOperations factored out supporter function; virtual for MappedDuplicator. */
	virtual void _TableOperations (const ProductionVector<const TableOperation*>* p_TableOperations, TableJunction* j) {
	    ProductionVector<const TableOperation*> ops;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
	    	 it != p_TableOperations->end(); it++) {
	    	(*it)->express(this);
	    	ops.push_back(last.tableOperation);
	    }
	    std::sort(ops.begin(), ops.end(), ServiceOptimizerTableOperationSorter(atomFactory));
	    for (std::vector<const TableOperation*>::const_iterator it = ops.begin();
	    	 it != ops.end(); it++)
		j->addTableOperation(*it, false);
	    ops.clear(); // don't delete members.
	}
    };

}

#endif /* INCLUDED_ServiceOptimizer */

