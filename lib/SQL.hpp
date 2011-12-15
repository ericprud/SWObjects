#ifndef INCLUDE_SQL_HPP
 #define INCLUDE_SQL_HPP

#include <string>
#include <sstream>
#include <vector>
#include "SWObjects.hpp"

namespace w3c_sw {

    namespace sql {

	/**
	 * enforce type consistency for
	 *   Relation - a table name.
	 *   RelVar - a table alias.
	 *   Attribute - a table column name.
	 *   AttrAlias - an alias for a selected Attribute.
	 */
	struct Relation : public std::string {
	    Relation (std::string s) : std::string(s) {  }
	};
	struct RelVar : public std::string {
	    RelVar (std::string s) : std::string(s) {  }
	};
	struct Attribute : public std::string {
	    Attribute (std::string s) : std::string(s) {  }
	};
	// struct AttrAlias : public std::string {  }; select foo as bar;

	struct AliasMappingSet {
	    struct Mapping : public std::map<RelVar, RelVar> {
	    };
	};

	typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		      PREC_And, 
		      PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		      PREC_Plus, PREC_Minus, 
		      PREC_Times, PREC_Divide, 
		      PREC_Not, PREC_TTerm, PREC_Neg, PREC_High = PREC_Neg} e_PREC;

	class AliasAttr {
	public:
	    RelVar alias;
	    Attribute attr;
	    //	    AliasAttr () {  }
	    AliasAttr (RelVar alias, Attribute attr) : alias(alias), attr(attr) {  }
	    virtual ~AliasAttr () {  }
	    virtual bool operator== (const AliasAttr& ref) const {
		return alias == ref.alias && attr == ref.attr;
	    }
	    std::string str () const { return toString(); } // for debugger invocation
	    virtual std::string toString () const { return alias + "." + attr; }
	};

	/* Implementable subclassed of Constraint:  */
	class DisjunctionConstraint;
	class ConjunctionConstraint;
	class AliasAttrConstraint;
	class ReallyNullConstraint;
	class IntConstraint;
	class FloatConstraint;
	class DoubleConstraint;
	class LiteralConstraint;
	class BoolConstraint;
	//class BooleanConjunction;
	class NullConstraint;
	class NegationConstraint;
	class ArithOperation;
	class BooleanEQ;
	class BooleanNE;
	class BooleanLT;
	class BooleanGT;
	class BooleanLE;
	class BooleanGE;
	class BooleanNegation;
	class ArithmeticProduct;
	class ArithmeticInverse;
	class ArithmeticSum;
	class ArithmeticNegation;
	class HomologConstraint;
	class RegexConstraint;

	struct EquivSet;
	class Expression {
	protected:
	public:
	    Expression () {  }
	    virtual ~Expression () {  }
	    virtual Expression* clone() const = 0;
	    std::string str () const { return toString(); }
	    virtual std::string toString(std::string pad = "", e_PREC parentPrec = PREC_High, std::string driver = "") const = 0;
	    virtual e_PREC getPrecedence() const = 0;
	    virtual void getEquivs (struct EquivSet&) const {  }
	    virtual bool finalEq (const DisjunctionConstraint&) const { return false; }
	    virtual bool finalEq (const ConjunctionConstraint&) const { return false; }
	    virtual bool finalEq (const ReallyNullConstraint&) const { return false; }
	    virtual bool finalEq (const IntConstraint&) const { return false; }
	    virtual bool finalEq (const FloatConstraint&) const { return false; }
	    virtual bool finalEq (const DoubleConstraint&) const { return false; }
	    virtual bool finalEq (const LiteralConstraint&) const { return false; }
	    virtual bool finalEq (const BoolConstraint&) const { return false; }
	    //virtual bool finalEq (const BooleanConjunction&) const { return false; }
	    virtual bool finalEq (const NullConstraint&) const { return false; }
	    virtual bool finalEq (const NegationConstraint&) const { return false; }
	    virtual bool finalEq (const AliasAttrConstraint&) const { return false; }
	    virtual bool finalEq (const ArithOperation&) const { return false; }
	    virtual bool finalEq (const BooleanEQ&) const { return false; }
	    virtual bool finalEq (const BooleanNE&) const { return false; }
	    virtual bool finalEq (const BooleanLT&) const { return false; }
	    virtual bool finalEq (const BooleanGT&) const { return false; }
	    virtual bool finalEq (const BooleanLE&) const { return false; }
	    virtual bool finalEq (const BooleanGE&) const { return false; }
	    virtual bool finalEq (const BooleanNegation&) const { return false; }
	    virtual bool finalEq (const ArithmeticProduct&) const { return false; }
	    virtual bool finalEq (const ArithmeticInverse&) const { return false; }
	    virtual bool finalEq (const ArithmeticSum&) const { return false; }
	    virtual bool finalEq (const ArithmeticNegation&) const { return false; }
	    virtual bool finalEq (const HomologConstraint&) const { return false; }
	    virtual bool finalEq (const RegexConstraint&) const { return false; }
	    virtual bool operator==(const Expression&) const = 0;
	};
	struct ConstraintList : public std::vector<const Expression*> {
	    ConstraintList () {  }
	    ConstraintList (const_iterator start,
			    const_iterator end)
		: std::vector<const Expression*>(start, end)
	    {  }
	    std::ostream& print(std::ostream& s, std::string pad = "", std::string driver = "") const;
	};

	class JunctionConstraint : public Expression {
	public:
	    ConstraintList constraints;
	public:
	    JunctionConstraint () : Expression(), constraints() {  }
	    JunctionConstraint (ConstraintList::const_iterator start,
				ConstraintList::const_iterator end)
		: constraints(start, end)
	    {  }
	    virtual ~JunctionConstraint () {
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++)
		    delete *it;
	    }
	    virtual Expression* clone() const = 0;
	    void addConstraint (Expression* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High, std::string driver = "") const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    if (it != constraints.begin()) s << getJunctionString();
		    s << (*it)->toString(pad, getPrecedence(), driver);
		}
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	    bool finalEq (const JunctionConstraint& ref) const {
		if (constraints.size() != ref.constraints.size())
		    return false;

		// for ( ; mit != constraints.end(); ++mit, ++rit)
		//     if ( !(**mit == **rit) )
		// 	return false;

		ConstraintList copy(ref.constraints.begin(), ref.constraints.end());
		ConstraintList::const_iterator mit;
		ConstraintList::iterator rit;
		for (mit = constraints.begin(), rit = copy.begin(); mit != constraints.end(); ) {
		    while (!(**mit == **rit) && rit != copy.end())
			++rit;
		    if (rit == copy.end())
			return false; // didn't find it in our copy.
		    copy.erase(rit);
		    rit = copy.begin();
		    ++mit;
		}
		return true;
	    }
	    virtual std::string getJunctionString() const = 0;
	};
	class ConjunctionConstraint : public JunctionConstraint {
	public:
	    ConjunctionConstraint () : JunctionConstraint() {  }
	    ConjunctionConstraint (ConstraintList::const_iterator start,
				   ConstraintList::const_iterator end)
		: JunctionConstraint(start, end)
	    {  }
	    virtual Expression* clone () const {
		ConjunctionConstraint* ret = new ConjunctionConstraint();
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    ret->addConstraint((*it)->clone());
		}
		return ret;
	    }
	    virtual std::string getJunctionString () const { return " AND "; }
	    virtual e_PREC getPrecedence () const { return PREC_And; }
	    virtual bool finalEq (const ConjunctionConstraint& l) const {
		return JunctionConstraint::finalEq(l);
	    }
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual void getEquivs(struct EquivSet&) const;
	};
	class DisjunctionConstraint : public JunctionConstraint {
	public:
	    DisjunctionConstraint () {  }
	    DisjunctionConstraint (ConstraintList::const_iterator start,
				   ConstraintList::const_iterator end)
		: JunctionConstraint(start, end)
	    {  }
	    virtual Expression* clone () const {
		DisjunctionConstraint* ret = new DisjunctionConstraint();
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    ret->addConstraint((*it)->clone());
		}
		return ret;
	    }
	    virtual std::string getJunctionString () const { return " OR "; }
	    virtual e_PREC getPrecedence () const { return PREC_Or; }
	    virtual bool finalEq (const DisjunctionConstraint& l) const {
		return JunctionConstraint::finalEq(l);
	    }
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	};
	class BooleanJunction : public Expression { // @@ delme?
	public:
	    ConstraintList m_Expressions;
	    BooleanJunction (ConstraintList* p_Expressions) : m_Expressions(*p_Expressions) {  }
	    virtual Expression* clone() const = 0;
	    virtual const char* getInfixNotation() const = 0;
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High, std::string driver = "") const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		for (ConstraintList::const_iterator it = m_Expressions.begin();
		     it != m_Expressions.end(); it++) {
		    if (it != m_Expressions.begin()) s << getInfixNotation();
		    s << (*it)->toString(pad, getPrecedence(), driver);
		}
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	    bool operator== (const BooleanJunction& ref) const {
		if (m_Expressions.size() != ref.m_Expressions.size())
		    return false;
		ConstraintList::const_iterator mit = m_Expressions.begin();
		ConstraintList::const_iterator rit = ref.m_Expressions.begin();
		for ( ; mit != m_Expressions.end(); ++mit, ++rit)
		    if ( !(**mit == **rit) )
			return false;
		return true;
	    }
	};
// 	class BooleanConjunction : public BooleanJunction {
// 	public:
// 	    BooleanConjunction (const Expression* l, const Expression* r) : BooleanJunction(l, r) {  }
// 	    virtual e_PREC getPrecedence () const { return PREC_And; }
// 	    virtual bool finalEq (const BooleanConjunction& l) const {
// 		return l.BooleanJunction::operator==(*this);
// 	    }	    
// 	    virtual bool operator== (const Expression& r) const {
// 		return r.finalEq(*this);
// 	    }
// 	    virtual const char* getInfixNotation () const { return "&&"; }
// 	};
	class ArithOperation : public Expression {
	    ConstraintList constraints;
	    std::string sqlOperator;
	    e_PREC prec;

	public:
	    ArithOperation (std::string sqlOperator, e_PREC prec) : 
		Expression(), sqlOperator(sqlOperator), prec(prec) {  }
	    virtual ~ArithOperation () {
		for (ConstraintList::iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    delete *it;
	    }
	    virtual Expression* clone () const {
		ArithOperation* ret = new ArithOperation(sqlOperator, prec);
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    ret->push_back((*it)->clone());
		return ret;
	    }
	    void push_back (Expression* constraint) { constraints.push_back(constraint); }
	    virtual e_PREC getPrecedence () const { return PREC_Neg; }
	    virtual bool finalEq (const ArithOperation& l) const {
		return l.constraints == constraints && l.sqlOperator == sqlOperator;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High, std::string driver = "") const {
		std::stringstream s;
		if (prec < parentPrec) s << "(";
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); ++it) {
		    if (it != constraints.begin())
			s << " " <<  sqlOperator << " ";
		    s << (*it)->toString(pad, prec, driver);
		}
		if (prec < parentPrec) s << ")";
		return s.str();
	    }
	};
	class BooleanComparator : public Expression {
	protected:
	    const Expression* left;
	    const Expression* right;
	public:
	    BooleanComparator (const Expression* right) : Expression(), right(right) {  }
	    BooleanComparator (const Expression* left, const Expression* right) : Expression(), left(left), right(right) {  }
	    ~BooleanComparator () { delete left; delete right; }
	    virtual Expression* clone() const = 0;
	    virtual void setLeftParm (const Expression* p_left) { left = p_left; }
	    virtual const char* getComparisonNotation() const = 0;
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High, std::string driver = "") const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		s << left->toString(pad, getPrecedence(), driver);
		s << getComparisonNotation();
		s << right->toString(pad, getPrecedence(), driver);
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	};
	class BooleanEQ : public BooleanComparator {
	public:
	    BooleanEQ (const Expression* right) : BooleanComparator(right) {  }
	    BooleanEQ (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanEQ(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_EQ; }
	    virtual bool finalEq (const BooleanEQ& l) const {
		return (*l.left == *left  && *l.right == *right) // unordered
		    || (*l.left == *right && *l.right == *left);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "="; };
	    void getEquivs(struct EquivSet& equivs) const;
	};
	class BooleanNE : public BooleanComparator {
	public:
	    BooleanNE (const Expression* right) : BooleanComparator(right) {  }
	    BooleanNE (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanNE(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_NE; }
	    virtual bool finalEq (const BooleanNE& l) const {
		return (*l.left == *left  && *l.right == *right) // unordered
		    || (*l.left == *right && *l.right == *left);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "!="; };
	};
	class BooleanLT : public BooleanComparator {
	public:
	    BooleanLT (const Expression* right) : BooleanComparator(right) {  }
	    BooleanLT (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanLT(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_LT; }
	    virtual bool finalEq (const BooleanLT& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "<"; };
	};
	class BooleanGT : public BooleanComparator {
	public:
	    BooleanGT (const Expression* right) : BooleanComparator(right) {  }
	    BooleanGT (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanGT(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_GT; }
	    virtual bool finalEq (const BooleanGT& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return ">"; };
	};
	class BooleanLE : public BooleanComparator {
	public:
	    BooleanLE (const Expression* right) : BooleanComparator(right) {  }
	    BooleanLE (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanLE(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_LT; }
	    virtual bool finalEq (const BooleanLE& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "<="; };
	};
	class BooleanGE : public BooleanComparator {
	public:
	    BooleanGE (const Expression* right) : BooleanComparator(right) {  }
	    BooleanGE (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual Expression* clone () const {
		return new BooleanGE(left, right);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_GT; }
	    virtual bool finalEq (const BooleanGE& l) const {
		return *l.left == *left && *l.right == *right;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return ">="; };
	};
	class UnaryExpression : public Expression {
	protected:
	    const Expression* arg;
	public:
	    UnaryExpression (const Expression* arg) : Expression(), arg(arg) {  }
	    ~UnaryExpression () {
		delete arg;
	    }
	    virtual Expression* clone() const = 0;
	    bool baseEq (const UnaryExpression& r) const {
		return *arg == *r.arg;
	    }
	    virtual const char* getPrefixOperator() const = 0;
	    virtual std::string toString (std::string, e_PREC parentPrec = PREC_High, std::string driver = "") const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		s << getPrefixOperator();
		s << arg->toString();
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	};
	class NaryExpression : public Expression {
	protected:
	    ConstraintList args;
	public:
	    NaryExpression (ConstraintList::const_iterator start,
			    ConstraintList::const_iterator end)
		: args(start, end)
	    {  }
	    NaryExpression (ConstraintList* args) : Expression(), args(*args) {  }
	    ~NaryExpression () {
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); ++it)
		    delete *it;
	    }
	    virtual Expression* clone() const = 0;
	    bool baseEq (const NaryExpression& r) const {
		return ptrequal(args.begin(), args.end(), r.args.begin());
	    }
	    virtual const char* getInfixOperator() const = 0;
	    virtual std::string toString (std::string, e_PREC parentPrec = PREC_High, std::string driver = "") const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); ++it) {
		    if (it != args.begin())
			s << getInfixOperator();
		    s << (*it)->toString();
		}
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	};
	class BooleanNegation : public UnaryExpression {
	public:
	    BooleanNegation (const Expression* arg) : UnaryExpression(arg) {  }
	    virtual Expression* clone () const {
		return new BooleanNegation(arg->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const BooleanNegation& l) const {
		return l.UnaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getPrefixOperator () const { return "!"; }
	    virtual std::string toString (std::string, e_PREC, std::string driver = "") const {
		return std::string("CONCAT")
		    + UnaryExpression::toString("", PREC_Low, driver);
	    }
	};
	class ArithmeticProduct : public NaryExpression {
	public:
	    ArithmeticProduct (ConstraintList::const_iterator start,
			       ConstraintList::const_iterator end)
		: NaryExpression(start, end)
	    {  }
	    virtual Expression* clone () const {
		ConstraintList v;
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); it++) {
		    v.push_back((*it)->clone());
		}
		return new ArithmeticProduct(v.begin(), v.end());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ArithmeticProduct& l) const {
		return l.NaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getInfixOperator () const { return " * "; }
	};
	class ArithmeticInverse : public UnaryExpression {
	public:
	    ArithmeticInverse (const Expression* arg) : UnaryExpression(arg) {  }
	    virtual Expression* clone () const {
		return new ArithmeticInverse(arg->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ArithmeticInverse& l) const {
		return l.UnaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getPrefixOperator () const { return "1/"; }
	};
	class ArithmeticSum : public NaryExpression {
	public:
	    ArithmeticSum (ConstraintList::const_iterator start,
			   ConstraintList::const_iterator end)
		: NaryExpression(start, end)
	    {  }
	    virtual Expression* clone () const {
		ConstraintList v;
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); it++) {
		    v.push_back((*it)->clone());
		}
		return new ArithmeticSum(v.begin(), v.end());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ArithmeticSum& l) const {
		return l.NaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getInfixOperator () const { return " + "; }
	};
	class ArithmeticNegation : public UnaryExpression {
	public:
	    ArithmeticNegation (const Expression* arg) : UnaryExpression(arg) {  }
	    virtual Expression* clone () const {
		return new ArithmeticNegation(arg->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ArithmeticNegation& l) const {
		return l.UnaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getPrefixOperator () const { return "-"; }
	};
	class LiteralConstraint : public Expression {
	    std::string value;
	public:
	    LiteralConstraint (std::string value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new LiteralConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const LiteralConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		std::stringstream s;
		s << "\"" << value << "\"";
		return s.str();
	    }
	};
	class IntConstraint : public Expression {
	    int value;
	public:
	    IntConstraint (int value) : Expression(), value(value) {  }
	    virtual ~IntConstraint () {  }
	    virtual Expression* clone () const {
		return new IntConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const IntConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	    int getValue () const { return value; }
	};
	class FloatConstraint : public Expression {
	    float value;
	public:
	    FloatConstraint (float value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new FloatConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const FloatConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class DoubleConstraint : public Expression {
	    double value;
	public:
	    DoubleConstraint (double value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new DoubleConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const DoubleConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class BoolConstraint : public Expression {
	    bool value;
	public:
	    BoolConstraint (bool value) : Expression(), value(value) {  }
	    virtual Expression* clone () const {
		return new BoolConstraint(value);
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const BoolConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		return value ? "true" : "false";
	    }
	};
	class ReallyNullConstraint : public Expression {
	public:
	    ReallyNullConstraint () : Expression() {  }
	    virtual Expression* clone () const {
		return new ReallyNullConstraint();
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ReallyNullConstraint&) const {
		return true;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		return "NULL";
	    }
	};
	class NullConstraint : public Expression {
	    const Expression* tterm;
	public:
	    NullConstraint (const Expression* tterm) : Expression(), tterm(tterm) {  }
	    ~NullConstraint () { delete tterm; }
	    virtual Expression* clone () const {
		return new NullConstraint(tterm->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const NullConstraint&) const {
		return true;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string) const {
		std::stringstream s;
		s << tterm->toString();
		s << " IS NOT NULL";
		return s.str();
	    }
	};
	class NegationConstraint : public Expression {
	    Expression* negated;
	public:
	    NegationConstraint (Expression* negated) : Expression(), negated(negated) {  }
	    ~NegationConstraint () { delete negated; }
	    virtual Expression* clone () const {
		return new NegationConstraint(negated->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_Neg; }
	    virtual bool finalEq (const NegationConstraint& l) const {
		return *l.negated == *negated;
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad, e_PREC parentPrec, std::string driver = "") const {
		std::stringstream s;
		s << "!(" << negated->toString(pad, parentPrec, driver) << ")";
		return s.str();
	    }
	};
	class AliasAttrConstraint : public Expression {
	public: // !!!
	    AliasAttr aattr;
	public:
	    AliasAttrConstraint (AliasAttr aattr) : Expression(), aattr(aattr) {  }
	    virtual Expression* clone () const {
		return new AliasAttrConstraint(aattr);
	    }
	    virtual bool finalEq (const AliasAttrConstraint& l) const {
		return l.aattr == aattr;
	    }
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC, std::string driver = "") const {
		std::stringstream s;
		s << aattr.alias;
		s << ".";
		s << aattr.attr;
		return s.str();
	    }
	    virtual e_PREC getPrecedence () const { return PREC_TTerm; }
	};
	/** HomologConstraint - Nary functions which have the same parameter
	 * semantics in XPath and SQL.
	 */
	class HomologConstraint : public NaryExpression {
	    std::string sqlOp;
	public:
	    HomologConstraint (std::string sqlOp,
			       ConstraintList::const_iterator start,
			       ConstraintList::const_iterator end)
		: NaryExpression(start, end), sqlOp(sqlOp)
	    {  }
	    virtual Expression* clone () const {
		ConstraintList v;
		for (ConstraintList::const_iterator it = args.begin();
		     it != args.end(); it++) {
		    v.push_back((*it)->clone());
		}
		return new HomologConstraint(sqlOp, v.begin(), v.end());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const HomologConstraint& l) const {
		return l.NaryExpression::baseEq(*this);
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getInfixOperator () const { return ", "; }
	    virtual std::string toString (std::string pad, e_PREC prec, std::string driver = "") const {
		return sqlOp + "("
		    + NaryExpression::toString("", PREC_Low, driver) + ")";
	    }
	};

	class RegexConstraint : public Expression {
	    const Expression* text;
	    const Expression* pattern;
	public:
	    RegexConstraint (const Expression* text, const Expression* pattern) : Expression(), text(text), pattern(pattern) {  }
	    virtual Expression* clone () const {
		return new RegexConstraint(text->clone(), pattern->clone());
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const RegexConstraint& l) const {
		return l.text == text && l.pattern == pattern; // @@ does this compare by ref? by val?
	    }	    
	    virtual bool operator== (const Expression& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad, e_PREC prec, std::string driver = "") const {
		return std::string("REGEX(") + text->toString(pad, prec, driver) + ", " + pattern->toString() + ")";
	    }
	};

	class TableJoin;
	class SubqueryJoin;
	class Join {
	    RelVar alias;
	    bool optional;
	    ConstraintList constraints;
	public:
	    Join (RelVar alias, bool optional) : alias(alias), optional(optional) {  }
	    virtual ~Join () {
		for (ConstraintList::iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    delete *it;
	    }
	    std::string debug_getAlias () { return alias; }
	    virtual std::string getRelationText (std::string pad = "") const = 0;
	    bool baseEq (const Join& ref) const {
		return alias == ref.alias
		    && optional == ref.optional
		    && ptrequal(constraints.begin(), constraints.end(), ref.constraints.begin());
	    }
	    virtual bool finalEq (const TableJoin&) const { return false; }
	    virtual bool finalEq (const SubqueryJoin&) const { return false; }
	    virtual bool operator==(const Join& ref) const = 0;
	    std::string str () const { return toString(); } // for debugger invocation
	    std::string toString (ConstraintList* captureConstraints = NULL, std::string pad = "", std::string driver = "") const {
		std::stringstream s;
		if (captureConstraints == NULL) s << std::endl << pad << "            " << (optional ? "LEFT OUTER JOIN " : "INNER JOIN ");
		if (driver.find("oracle") == 0)
		    s << getRelationText(pad) << " " << alias;
		else
		    s << getRelationText(pad) << " AS " << alias;

		if (captureConstraints != NULL)
		    std::copy(constraints.begin(), constraints.end(), std::back_inserter(*captureConstraints));

		else 
		    for (ConstraintList::const_iterator it = constraints.begin();
			 it != constraints.end(); ++it)
			s << (it == constraints.begin() ? " ON " : " AND ")
			  << (*it)->toString(pad, PREC_High, driver);

		return s.str();
	    }
	    void addForeignKeyJoinConstraint (Attribute myAttr, RelVar otherAlias, Attribute otherAttr) {
		if (alias != otherAlias || myAttr != otherAttr)
		    constraints.push_back(new BooleanEQ(new AliasAttrConstraint(AliasAttr(alias, myAttr)), 
							new AliasAttrConstraint(AliasAttr(otherAlias, otherAttr))));
	    }
	    void addConstantJoinConstraint (Attribute myAttr, int value) {
		constraints.push_back(new BooleanEQ(new AliasAttrConstraint(AliasAttr(alias, myAttr)), 
						    new IntConstraint(value)));
	    }
	    void addConstantJoinConstraint (Attribute myAttr, std::string value) {
		constraints.push_back(new BooleanEQ(new AliasAttrConstraint(AliasAttr(alias, myAttr)), 
						    new LiteralConstraint(value)));
	    }
	};

	class TableJoin : public Join {
	    Relation relation;
	protected:
	    virtual std::string getRelationText (std::string) const { return relation; }
	public:
	    TableJoin (Relation relation, RelVar alias, bool optional) : Join(alias, optional), relation(relation) {  }
	    virtual bool finalEq (const TableJoin& l) const {
		return l.relation == relation;
	    }	    
	    virtual bool operator== (const Join& r) const {
		return Join::baseEq(r) && r.finalEq(*this);
	    }
	    virtual ~TableJoin () {  }
	};

	class AliasedSelect {
	    friend struct EquivSet;
	protected:
	    const Expression* exp;
	    std::string alias;
	public:
	    AliasedSelect (const Expression* exp, std::string alias) : exp(exp), alias(alias) {  }
	    virtual ~AliasedSelect () {
		delete exp;
	    }
	    virtual bool operator== (const AliasedSelect& ref) const { // virt in case of subclassing
		return *exp == *ref.exp && alias == ref.alias;
	    }
	    std::string str () const { return toString(); } // for debugger invocation
	    virtual std::string toString (std::string pad = "", std::string driver = "") const {
		if (driver.find("oracle") == 0)
		    return exp->toString(pad, PREC_High, driver) + " " + alias;
		else
		    return exp->toString(pad, PREC_High, driver) + " AS " + alias;
	    }
	};

	class SQLUnion;
	class SQLOptional;
	class SQLQuery { // !!! public SQLQueryBase
	public:

	    struct JoinList : public std::vector<Join*> {
		JoinList () {  }
		JoinList (std::vector<Join*>& joins) : std::vector<Join*>(joins) {  }
		std::ostream& print (std::ostream& s,
				     ConstraintList* captureConstraints = NULL,
				     std::string pad = "", std::string driver = "") const;
	    };
	    JoinList joins;

	    ConstraintList  constraints;
	    struct OrderBy : public ConstraintList {
		std::ostream& print(std::ostream& s, std::string pad = "", std::string driver = "") const;
	    };
	    OrderBy orderBy;
	    struct Selects : public std::vector<AliasedSelect*> {
		std::ostream& print(std::ostream& s, std::string pad = "", std::string driver = "") const;
	    };

	    Selects selects;
	    bool distinct;
	    int limit, offset;

	public:
	    SQLQuery () : distinct(false), limit(-1), offset(-1) {  }
	    SQLQuery (std::vector<Join*>* joins) : joins(*joins), distinct(false), limit(-1), offset(-1) {  }
	    virtual ~SQLQuery () {
		// w3c_sw_LINEN << "~TableJoin: " << this
		// 	     << ": " << iterStr<Join*>(joins.begin(), joins.end())
		// 	     << "\n";

		for (std::vector<AliasedSelect*>::iterator iSelects = selects.begin();
		     iSelects != selects.end(); ++iSelects)
		    delete *iSelects;

		for (std::vector<Join*>::iterator iJoins = joins.begin();
		     iJoins != joins.end(); ++iJoins) {
		    delete *iJoins;
		}

		for (ConstraintList::iterator iConstraints = constraints.begin();
		     iConstraints != constraints.end(); ++iConstraints)
		    delete *iConstraints;

		for (ConstraintList::iterator iOrderBy = orderBy.begin();
		     iOrderBy != orderBy.end(); ++iOrderBy)
		    delete *iOrderBy;
	    }

	    bool finalEq(const SQLQuery& ref) const;
	    virtual bool finalEq (const SQLUnion&) const { return false; }
	    virtual bool finalEq (const SQLOptional&) const { return false; }
	    // virtual bool operator==(const Join& ref) const = 0; //!!! for SQLQueryBase
	    virtual bool operator== (const SQLQuery& ref) const {
		return ref.finalEq(*this);
	    }

	    std::string str () const { // easy to call from debugger.
		return toString("");
	    }
	    virtual std::string toString (std::string pad = "", std::string driver = "") const {
		std::stringstream s;
		s << pad << "SELECT ";
		if (distinct) s << "DISTINCT ";

		selects.print(s, pad, driver);

		/* JOINs */
		ConstraintList where;
		joins.print(s, &where, pad, driver);

		/* WHERE */
		std::copy(constraints.begin(), constraints.end(), std::back_inserter(where));
		where.print(s, pad, driver);

		orderBy.print(s, pad, driver);

		if (driver.find("oracle") == 0) {
		    if (offset != -1) s << std::endl << pad << "rownum > " << offset;
		    if (limit != -1) s << std::endl << pad << " rownum <= " << limit;
		} else {
		    if (limit != -1) s << std::endl << pad << " LIMIT " << limit;
		    if (offset != -1) s << std::endl << pad << "OFFSET " << offset;
		}

		return s.str();
	    }

	    void add (Join* join) { joins.push_back(join); }
	};

	inline std::ostream& SQLQuery::Selects::print (std::ostream& s, std::string pad, std::string driver) const {
	    /* SELECT attributes */
	    for (std::vector<AliasedSelect*>::const_iterator it = begin();
		 it != end(); ++it) {
		if (it != begin()) s << ", ";
		s << (*it)->toString(pad, driver);
	    }
	    if (begin() == end()) s << "NULL";
	    return s;
	}
	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::Selects& selects) {
	    return selects.print(os);
	}

	inline std::ostream& SQLQuery::JoinList::print (std::ostream& s, ConstraintList* captureConstraints, std::string pad, std::string driver) const {
	    for (std::vector<Join*>::const_iterator it = begin();
		 it != end(); ++it)
		if (it == begin())
		    s << std::endl << pad << "       FROM " << (*it)->toString(captureConstraints, pad, driver);
		else
		    s << (*it)->toString(NULL, pad, driver);
	    return s;
	}
	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::JoinList& joinList) {
	    return joinList.print(os);
	}

	inline std::ostream& ConstraintList::print (std::ostream& s, std::string pad, std::string driver) const {
	    for (ConstraintList::const_iterator it = begin();
		 it != end(); ++it)
		s << (it == begin() ? " WHERE " : " AND ")
		  <<(*it)->toString(pad, PREC_High, driver);
	    return s;
	}
	inline std::ostream& operator<< (std::ostream& os, const ConstraintList& constraints) {
	    return constraints.print(os);
	}

	inline std::ostream& SQLQuery::OrderBy::print (std::ostream& s, std::string pad, std::string driver) const {
	    /* ORDER BY */
	    if (begin() != end()) {
		s << std::endl << pad << " ORDER BY ";
		for (ConstraintList::const_iterator it = begin();
		     it != end(); ++it) {
		    if (it != begin())
			s << ", ";
		    s << (*it)->toString(pad, PREC_High, driver);
		}
	    }
	    return s;
	}
	inline std::ostream& operator<< (std::ostream& os, const SQLQuery::OrderBy& orderBy) {
	    return orderBy.print(os);
	}

	struct EquivSet {
	    std::map<std::string, std::set<std::string> > equivs;
	    EquivSet (const ConstraintList constraints) {
		for (ConstraintList::const_iterator it = constraints.begin();
		     it != constraints.end(); ++it) {
		    (*it)->getEquivs(*this);
		}
	    }
	    void _insert (std::string k1, std::string k2) {
		equivs[k1].insert(k2);
		equivs[k2].insert(k1);
	    }
	    struct AliasedSelectSorter {
		bool operator() (const AliasedSelect*l, const AliasedSelect*r) {
		    return l->alias.compare(r->alias) < 0;
		}
	    };
	    bool sameValues (const std::vector<AliasedSelect*> lvec, const std::vector<AliasedSelect*> rvec) {
		AliasedSelectSorter sorter;
		std::vector<AliasedSelect*> lsort(lvec.begin(), lvec.end());
		std::vector<AliasedSelect*> rsort(rvec.begin(), rvec.end());
		std::sort(lsort.begin(), lsort.end(), sorter);
		std::sort(rsort.begin(), rsort.end(), sorter);

		std::vector<AliasedSelect*>::const_iterator l = lsort.begin();
		std::vector<AliasedSelect*>::const_iterator r = rsort.begin();
		while (l != lsort.end() && r != rsort.end()) {
		    if (!(**l == **r) && ((*l)->alias != (*r)->alias
					  || equivs[(*l)->exp->toString()].find((*r)->exp->toString()) == equivs[(*l)->exp->toString()].end()))
			return false;
		    ++l;
		    ++r;
		}
		return true;
	    }
	};

	inline void ConjunctionConstraint::getEquivs (struct EquivSet& equivs) const {
	    for (ConstraintList::const_iterator it = constraints.begin();
		 it != constraints.end(); ++it)
		(*it)->getEquivs(equivs);
	}
	inline void BooleanEQ::getEquivs (struct EquivSet& equivs) const {
	    if (dynamic_cast<const AliasAttrConstraint*>(left) != NULL
		&& dynamic_cast<const AliasAttrConstraint*>(right) != NULL)
		equivs._insert(left->toString(), right->toString());
	}

	inline bool SQLQuery::finalEq (const SQLQuery& ref) const { // not needed in SQLQueryBase
	    const char* f = "SQL Query inequivalence in ";
	    if (!(distinct == ref.distinct)) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "distinct: " << distinct << "!=" << ref.distinct << "\n";
		return false;
	    }
	    if (!(limit == ref.limit)) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "limit: " << limit << "!=" << ref.limit << "\n";
		return false;
	    }
	    if (!(offset == ref.offset)) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "offset: " << offset << "!=" << ref.offset << "\n";
		return false;
	    }
	    //  !ptrequal(selects.begin(), selects.end(), ref.selects.begin())
	    if (!EquivSet(constraints).sameValues(selects, ref.selects)) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "selects:\n" << selects << "\n != \n" << ref.selects << "\n";
		return false;
	    }
	    if (!ptrequal(joins.begin(), joins.end(), ref.joins.begin())) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "joins:\n" << joins << "\n != \n" << ref.joins << "\n";
		return false;
	    }
	    if (!ptrequal(constraints.begin(), constraints.end(), ref.constraints.begin())) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "constraints:\n" << constraints << "\n != \n" << ref.constraints << "\n";
		return false;
	    }
	    if (!ptrequal(orderBy.begin(), orderBy.end(), ref.orderBy.begin())) {
		BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer)
		    << f << "orderBy:\n" << orderBy << "\n != \n" << ref.orderBy << "\n";
		return false;
	    }
	    return true;
	}

	inline std::ostream& operator<< (std::ostream& os, SQLQuery const& my) {
	    return os << my.str();
	}

	class SQLDisjoint;
	class SQLUnion : public SQLQuery {
	public:
	    std::vector<SQLQuery*> disjoints;
	public:
	    SQLUnion () {  }
	    SQLUnion (std::vector<sql::SQLQuery*>::const_iterator start,
		      std::vector<sql::SQLQuery*>::const_iterator end) : disjoints(start, end)
	    {  }
	    virtual ~SQLUnion () {
		for (std::vector<SQLQuery*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it)
		    delete *it;
	    }
	    virtual bool finalEq (const SQLUnion& l) const {
		return ptrequal(l.disjoints.begin(), l.disjoints.end(), disjoints.begin());
	    }	    
	    virtual bool operator== (const SQLQuery& r) const {
		return r.finalEq(*this); // !!! no Join::baseEq(r) && 
	    }
	    virtual std::string toString (std::string pad = "", std::string driver = "") const {
		std::stringstream s;
		std::string newPad = pad + "    ";
		for (std::vector<SQLQuery*>::const_iterator it = disjoints.begin();
		     it != disjoints.end(); ++it) {
		    if (it != disjoints.begin())
			s << std::endl << pad << "  UNION" << std::endl;
		    s << (*it)->toString(newPad, driver);
		}
		return s.str();
	    }

	};

	class SubqueryJoin : public Join {
	    SQLQuery* subquery;
	protected:
	    virtual std::string getRelationText (std::string pad = "") const {
		std::stringstream s;
		s << "(" << std::endl << subquery->toString(pad) << std::endl << pad << "             )";
		return s.str();
	    }
	public:
	    SubqueryJoin (SQLQuery* subquery, RelVar alias, bool optional) : Join(alias, optional), subquery(subquery) {  }
	    virtual bool finalEq (const SubqueryJoin& l) const {
		return *l.subquery == *subquery;
	    }	    
	    virtual bool operator== (const Join& r) const {
		return Join::baseEq(r) && r.finalEq(*this);
	    }
	    virtual ~SubqueryJoin () { delete subquery; }
	};

	class SQLOptional : public SQLQuery {
	public:
	    SQLOptional () {  }
	    virtual ~SQLOptional () {  }
	    virtual bool finalEq (const SQLUnion& l) const { // !!! contains a what?
		return true;
	    }	    
	    virtual bool operator== (const SQLQuery& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad = "", std::string driver = "") const {
		std::string newPad = pad + "    ";
		return SQLQuery::toString(newPad, driver);
	    }
	};


	/**
	 * SQL Schema (derived from DDL)
	 */
	namespace schema {

	    typedef enum {TYPE_error, TYPE_int, TYPE_double, TYPE_date, TYPE_datetime, TYPE_string} e_TYPE;

	    struct FieldOrKey {
		int i;
		FieldOrKey () : i(7) {  }
		virtual ~FieldOrKey () {  }
		virtual bool operator==(const FieldOrKey& ref) const = 0;
		virtual std::string str() const = 0;
	    };

//	    I don't know what the prob was, but calling this got oddly circular:
// 	    inline std::ostream& operator<< (std::ostream& ostr, FieldOrKey const& ref) {
// 		std::cerr << ref << ".i = " << ref.i << "\n";
// 		return ostr << ref.str();
// 	    }

	    struct Field : public FieldOrKey {
		std::string name;
		e_TYPE type;
		Field (std::string name, e_TYPE type) : name(name), type(type)
		{  }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const Field* refp = dynamic_cast<const Field*>(&ref);
		    if (refp == NULL)
			return false;
		    return name == refp->name
			&& type == refp->type;
		}

		virtual std::string str () const {
		    return name + " " + (type == TYPE_error ? "ERROR" :
					 type == TYPE_int ? "INT" :
					 type == TYPE_double ? "DOUBLE" :
					 type == TYPE_date ? "DATE" :
					 type == TYPE_datetime ? "DATETIME" :
					 type == TYPE_string ? "STRING" :
					 "???" ) + "";
		}
	    };

	    struct Key : public FieldOrKey {
		std::vector<std::string>* attrs;
		Key (std::vector<std::string>* attrs) : attrs(attrs)
		{  }
		virtual ~Key () { delete attrs; }
		bool Key_equals (const FieldOrKey& ref) const {
		    const Key* refp = dynamic_cast<const Key*>(&ref);
		    if (refp == NULL
			|| attrs->size() != refp->attrs->size())
			return false;
		    std::vector<std::string>::const_iterator left = attrs->begin();
		    std::vector<std::string>::const_iterator right = refp->attrs->begin();
		    for (;
			 left != attrs->end(); ++left, ++right)
			if (*left != *right)
			    return false;
		    return true;
		}
	    };

	    struct PrimaryKey : public Key {
		PrimaryKey (std::vector<std::string>* attrs) : Key(attrs)
		{  }
		virtual ~PrimaryKey () {  }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const PrimaryKey* refp = dynamic_cast<const PrimaryKey*>(&ref);
		    return (refp != NULL && Key_equals(ref));
		}
		virtual std::string str () const {
		    std::stringstream ss;
		    ss << "PRIMARY KEY (";
		    for (std::vector<std::string>::const_iterator it = attrs->begin();
			 it != attrs->end(); ++it) {
			if (it != attrs->begin())
			    ss << ", ";
			ss << *it;
		    }
		    ss << ")";
		    return ss.str();
		}
	    };

	    struct ForeignKey : public Key {
		std::string targetRel;
		std::vector<std::string>* relAttrs;
		ForeignKey (std::vector<std::string>* myAttrs,
			    std::string targetRel,
			    std::vector<std::string>* relAttrs)
		    : Key(myAttrs), targetRel(targetRel), relAttrs(relAttrs)
		{  }
		virtual ~ForeignKey () { delete relAttrs; }
		virtual bool operator== (const FieldOrKey& ref) const {
		    const ForeignKey* refp = dynamic_cast<const ForeignKey*>(&ref);
		    if (refp == NULL
			|| targetRel != refp->targetRel
			|| !Key_equals(ref))
			return false;
		    std::vector<std::string>::const_iterator left = relAttrs->begin();
		    std::vector<std::string>::const_iterator right = refp->relAttrs->begin();
		    for (;
			 left != relAttrs->end(); ++left, ++right)
			if (*left != *right)
			    return false;
		    return true;
		}
		virtual std::string str () const {
		    std::stringstream ss;
		    ss << "FOREIGN KEY (";
		    for (std::vector<std::string>::const_iterator it = attrs->begin();
			 it != attrs->end(); ++it) {
			if (it != attrs->begin())
			    ss << ", ";
			ss << *it;
		    }
		    ss << ") REFERENCES " << targetRel << "(";
		    for (std::vector<std::string>::const_iterator it = relAttrs->begin();
			 it != relAttrs->end(); ++it) {
			if (it != relAttrs->begin())
			    ss << ", ";
			ss << *it;
		    }
		    ss << ")";
		    return ss.str();
		}
	    };

	    struct Relation {

		struct FieldInfo {

		    struct PKParticipation {
			const PrimaryKey* key;
			size_t position;
		    };

		    struct FKParticipation {
			const ForeignKey* key;
			size_t position;
		    };

		    std::string name;
		    e_TYPE type;
		    PKParticipation pk;
		    std::map<const ForeignKey*, FKParticipation> fks;
		};

		std::string name;
		std::vector<const FieldOrKey*> ordered;
		std::map<std::string, FieldInfo> fields;

		Relation (std::string name) : name(name)
		{  }

		~Relation () {
		    for (std::vector<const FieldOrKey*>::iterator it = ordered.begin();
			 it != ordered.end(); ++it)
			delete *it;
		    ordered.clear();
		    fields.clear();
		}

		bool operator== (const Relation& ref) const {
		    if (name != ref.name
			|| ordered.size() != ref.ordered.size()
			|| fields.size() != ref.fields.size())
			return false;
		    std::vector<const FieldOrKey*>::const_iterator left = ordered.begin();
		    std::vector<const FieldOrKey*>::const_iterator right = ref.ordered.begin();
		    for (;
			 left != ordered.end(); ++left, ++right)
			if (!(**left == **right))
			    return false;
		    return true;
		}

		std::string str () const {
		    std::stringstream ss;
		    for (std::vector<const FieldOrKey*>::const_iterator it = ordered.begin();
			 it != ordered.end(); ++it) {
			if (it != ordered.begin())
			    ss << ",\n";
			ss << "  " << (*it)->str();
		    }
		    return ss.str();
		}

		void addField (const Field* field) {
		    ordered.push_back(field);
		    fields[field->name].name = field->name;
		    fields[field->name].name = field->type;
		}

		void addPrimaryKey (PrimaryKey* primaryKey) {
		    ordered.push_back(primaryKey);
		    size_t posn = 0;
		    for (std::vector<std::string>::const_iterator attr = primaryKey->attrs->begin();
			 attr != primaryKey->attrs->end(); ++attr, ++posn) {
			// fields[*attr].name = primaryKey->name;
			fields[*attr].pk.key = primaryKey;
			fields[*attr].pk.position = posn;
		    }
		}

		void addForeignKey (ForeignKey* foreignKey) {
		    ordered.push_back(foreignKey);
		    size_t posn = 0;
		    for (std::vector<std::string>::const_iterator attr = foreignKey->attrs->begin();
			 attr != foreignKey->attrs->end(); ++attr, ++posn) {
			// fields[*attr].name = foreignKey->name;
			fields[*attr].fks[foreignKey].key = foreignKey;
			fields[*attr].fks[foreignKey].position = posn;
		    }
		}

	    };

	    inline std::ostream& operator<< (std::ostream& ostr, Relation const& ref) {
		return ostr << ref.str();
	    }

	    struct Database : public std::map<std::string, Relation*> {

		void clear () {
		    for (std::map<std::string, Relation*>::iterator it = begin();
			 it != end(); ++it)
			delete it->second;
		    std::map<std::string, Relation*>::clear();
		}

		bool operator== (const Database& ref) const {
		    if (size() != ref.size())
			return false;
		    std::map<std::string, Relation*>::const_iterator left = begin();
		    std::map<std::string, Relation*>::const_iterator right = ref.begin();
		    for (;
			 left != end(); ++left, ++right)
			if (left->first != right->first
			    || !(*left->second == *right->second))
			    return false;
		    return true;
		}

		std::string str () const {
		    std::stringstream ss;
		    for (std::map<std::string, Relation*>::const_iterator it = begin();
			 it != end(); ++it) {
			std::string s = it->first;
			const Relation& r = *it->second;
			ss << "CREATE TABLE " << s << " (\n" << r << "\n);\n";
		    }
		    return ss.str();
		}
	    };

	    inline std::ostream& operator<< (std::ostream& ostr, Database const& ref) {
		return ostr << ref.str();
	    }

	} // namespace schema

    } // namespace sql
} // namespace w3c_sw

#endif /* !INCLUDE_SQL_HPP */
