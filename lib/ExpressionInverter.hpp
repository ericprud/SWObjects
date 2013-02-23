
#ifndef INCLUDED_ExpressionInverter
#define INCLUDED_ExpressionInverter

namespace w3c_sw {
    class ExpressionInverter : public ExpressionExpressor {
	const TTerm* curTarget;
	Result* res;
	AtomFactory* atomFactory;
	std::vector<const Expression*> constraints;
	union {
	    const TTerm* term;
	    const Expression* expr;
	    const ArgList* args;
	} last;
	enum { Empty, Term, Expr, Args } lastType;
	typedef enum { None, Concat } FuncType;
	FuncType func;
	std::string concatRE;
	std::vector<const TTerm*> reCaptures;

	void setTerm(const TTerm* term) { last.term = term; lastType = Term; }
	void setExpr(const Expression* expr) { last.expr = expr; lastType = Expr; }
	void setArgs(const ArgList* args) { last.args = args; lastType = Args; }

    public:
	ExpressionInverter (const TTerm* curTarget, Result* res, AtomFactory* atomFactory)
	    : curTarget(curTarget), res(res), atomFactory(atomFactory), lastType(Empty), func(None) {  }
	~ExpressionInverter () {
	    delete last.args; // discoverd by valgrind -- not really investigated.
	}

	virtual void base(const Base* const /* self */, std::string /* productionName */) { throw "why did we call base?"; }

	virtual void members (const Members* const /* self */, ProductionVector<const TTerm*>* /* p_vars */) { w3c_sw_NEED_IMPL("inverse of members()"); }
	virtual void uri (const URI* const self, std::string) { setTerm(self); }
	virtual void variable (const Variable* const self, std::string) { setTerm(self); }
	virtual void bnode (const BNode* const self, std::string) { setTerm(self); }
	virtual void rdfLiteral (const RDFLiteral* const self, std::string, const URI* /* datatype */, const LANGTAG* /* p_LANGTAG */) { setTerm(self); }
	virtual void rdfLiteral (const NumericRDFLiteral* const self, int   , const URI*) { setTerm(self); }
	virtual void rdfLiteral (const NumericRDFLiteral* const self, float , const URI*) { setTerm(self); }
	virtual void rdfLiteral (const NumericRDFLiteral* const self, double, const URI*) { setTerm(self); }
	virtual void rdfLiteral (const BooleanRDFLiteral* const self, bool) { setTerm(self); }
	virtual void nulltterm (const NULLtterm* const self) { setTerm(self); }

	virtual void posExpression (const TTermExpression* const, const TTerm* p_TTerm) {
	    const Bindable* bindable = dynamic_cast<const Bindable*>(p_TTerm);
	    const TTerm* val = bindable ? res->get(bindable) : p_TTerm;
	    if (val == NULL) {
		reCaptures.push_back(p_TTerm);
		concatRE += "(.*?)";
	    } else {
		concatRE += val->getLexicalValue();
	    }
	    last.expr = new TTermExpression(p_TTerm);
	}
	ProductionVector<const Expression*>* _Expressions (const ProductionVector<const Expression*>* p_Expressions) {
	    ProductionVector<const Expression*>* l_Expressions = new ProductionVector<const Expression*>();
	    for (std::vector<const Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); it++) {
		(*it)->express(this);
		l_Expressions->push_back(last.expr);
	    }
	    return l_Expressions;
	}
	virtual void argList (const ArgList* const, ProductionVector<const Expression*>* expressions) {
	    setArgs(new ArgList(_Expressions(expressions)));
	}
	virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {
	    FuncType oldFunc = func;
	    if (p_IRIref == TTerm::FUNC_concat) {
		func = Concat;
		concatRE = "^";
		p_ArgList->express(this);
		concatRE += "$";
		std::string text(curTarget->getLexicalValue());
		boost::match_results<std::string::const_iterator> what;
		boost::regex pattern(concatRE);
		if (!regex_match(text, what, pattern, boost::match_default))
		    throw SafeEvaluationError(std::string("") + "literal value \"" + curTarget->getLexicalValue() + "\" did not match pattern \"" + concatRE + "\".");

#ifdef BOOST_REGEX_INDEX_BUG // not in 1.44
  #define FIRST_MATCH 3 // @@ by inspection, not documentation. different defaults for $^ and the like?
#else /* !BOOST_REGEX_INDEX_BUG */
  #define FIRST_MATCH 1 // consistent with comments in examples in docs: "what[0] contains the whole string"
#endif /* !BOOST_REGEX_INDEX_BUG */
		for (std::vector<const TTerm*>::size_type i = 0; i < reCaptures.size(); ++i)
		    res->set(reCaptures[i], atomFactory->getRDFLiteral(std::string(what[FIRST_MATCH + i].first, what[FIRST_MATCH + i].second)), false);
#undef FIRST_MATCH

		concatRE = "";
		reCaptures.clear();
	    } else {
		w3c_sw_NEED_IMPL(p_IRIref->toString());
	    }
	    func = oldFunc;
	}
	virtual void aggregateCall (const AggregateCall* const /* self */, const URI* /* p_IRIref */, const ArgList* /* p_ArgList */, e_distinctness /* distinctness */, const AggregateCall::ScalarVals* /* scalarVals */) {
	    w3c_sw_NEED_IMPL("AggregateCall inverter (can that even exist?)");
	}
	virtual void functionCallExpression (const FunctionCallExpression* const /* self */, FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	}
	virtual void existsExpression (const ExistsExpression* const /* self */, const TableOperation* /* p_TableOperation */) {
	    w3c_sw_NEED_IMPL("ExistsExpression inverter");
	}

	virtual void booleanNegation (const BooleanNegation* const, const Expression* /* p_Expression */) {  }
	virtual void arithmeticNegation (const ArithmeticNegation* const, const Expression* /* p_Expression */) {  }
	virtual void arithmeticInverse (const ArithmeticInverse* const, const Expression* /* p_Expression */) {  }
	virtual void booleanConjunction (const BooleanConjunction* const, const ProductionVector<const Expression*>* /* p_Expressions */) {  }
	virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const Expression*>* /* p_Expressions */) {  }
	virtual void arithmeticSum (const ArithmeticSum* const, const ProductionVector<const Expression*>* /* p_Expressions */) {  }
	virtual void arithmeticProduct (const ArithmeticProduct* const, const ProductionVector<const Expression*>* /* p_Expressions */) {  }
	virtual void arithmeticInverse (const ArithmeticInverse* const, ProductionVector<const Expression*>* /* p_Expressions */) {  }
	virtual void booleanEQ (const BooleanEQ* const, const Expression* /* p_left */, const Expression* /* p_right */) {  }
	virtual void booleanNE (const BooleanNE* const, const Expression* /* p_left */, const Expression* /* p_right */) {  }
	virtual void booleanLT (const BooleanLT* const, const Expression* /* p_left */, const Expression* /* p_right */) {  }
	virtual void booleanGT (const BooleanGT* const, const Expression* /* p_left */, const Expression* /* p_right */) {  }
	virtual void booleanLE (const BooleanLE* const, const Expression* /* p_left */, const Expression* /* p_right */) {  }
	virtual void booleanGE (const BooleanGE* const, const Expression* /* p_left */, const Expression* /* p_right */) {  }
	virtual void naryIn (const NaryIn* const, const Expression* /* p_left */, const ProductionVector<const Expression*>* /* p_right */) {  }
	virtual void comparatorExpression (const ComparatorExpression* const, const GeneralComparator* /* p_GeneralComparator */) {  }
	virtual void numberExpression (const NumberExpression* const, const NumericRDFLiteral* /* p_NumericRDFLiteral */) {  }
    };

}

#endif /* INCLUDED_ExpressionInverter */

