#ifndef INCLUDE_SQL_HPP
 #define INCLUDE_SQL_HPP

namespace w3c_sw {

    namespace sql {

	typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		      PREC_And, 
		      PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		      PREC_Plus, PREC_Minus, 
		      PREC_Times, PREC_Divide, 
		      PREC_Not, PREC_Pos, PREC_Neg, PREC_High = PREC_Neg} e_PREC;

	class AliasAttr {
	public:
	    std::string alias;
	    std::string attr;
	    //	    AliasAttr () {  }
	    AliasAttr (std::string alias, std::string attr) : alias(alias), attr(attr) {  }
	    virtual ~AliasAttr () {  }
	    virtual bool operator== (const AliasAttr& ref) const {
		return alias == ref.alias && attr == ref.attr;
	    }
	};

	class Constraint {
	protected:
	public:
	    Constraint () {  }
	    virtual ~Constraint () {  }
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
	class ConcatConstraint;
	class RegexConstraint;

	class WhereConstraint : public Constraint {
	protected:
	public:
	    WhereConstraint () {  }
	    virtual ~WhereConstraint () {  }
	    std::string str () const { return toString("", PREC_High); }
	    virtual std::string toString(std::string pad = "", e_PREC parentPrec = PREC_High) const = 0;
	    virtual e_PREC getPrecedence() const = 0;
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
	    virtual bool finalEq (const ConcatConstraint&) const { return false; }
	    virtual bool finalEq (const RegexConstraint&) const { return false; }
	    virtual bool operator==(const WhereConstraint&) const = 0;
	};
	typedef WhereConstraint Expression;
	class JunctionConstraint : public WhereConstraint {
	public:
	    std::vector<const Expression*> constraints;
	public:
	    JunctionConstraint () : WhereConstraint(), constraints() {  }
	    JunctionConstraint (const Expression* l, const Expression* r) : WhereConstraint(), constraints() {
		constraints.push_back(l);
		constraints.push_back(r);
	    }
	    ~JunctionConstraint () {
		for (std::vector<const Expression*>::const_iterator it = constraints.begin();
		     it != constraints.end(); it++)
		    delete *it;
	    }
	    void addConstraint (WhereConstraint* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High) const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		for (std::vector<const Expression*>::const_iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    if (it != constraints.begin()) s << getJunctionString();
		    s << (*it)->toString(pad, getPrecedence());
		}
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	    bool finalEq (const JunctionConstraint& ref) const {
		if (constraints.size() != ref.constraints.size())
		    return false;
		std::vector<const Expression*>::const_iterator mit = constraints.begin();
		std::vector<const Expression*>::const_iterator rit = ref.constraints.begin();
		for ( ; mit != constraints.end(); ++mit, ++rit)
		    if ( !(**mit == **rit) )
			return false;
		return true;
	    }
	    virtual std::string getJunctionString() const = 0;
	};
	class ConjunctionConstraint : public JunctionConstraint {
	public:
	    ConjunctionConstraint () : JunctionConstraint() {  }
	    ConjunctionConstraint (const Expression* l, const Expression* r) : JunctionConstraint(l, r) {  }
	    virtual std::string getJunctionString () const { return " AND "; }
	    virtual e_PREC getPrecedence () const { return PREC_And; }
	    virtual bool finalEq (const ConjunctionConstraint& l) const {
		return JunctionConstraint::finalEq(l);
	    }
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	};
	class DisjunctionConstraint : public JunctionConstraint {
	    // DisjunctionConstraint (const Expression* l, const Expression* r) : JunctionConstraint(l, r) {  }
	    virtual std::string getJunctionString () const { return " OR "; }
	    virtual e_PREC getPrecedence () const { return PREC_Or; }
	    virtual bool finalEq (const DisjunctionConstraint& l) const {
		return JunctionConstraint::finalEq(l);
	    }
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	};
	class BooleanJunction : public WhereConstraint {
	public:
	    std::vector<const Expression*> m_Expressions;
	    BooleanJunction (std::vector<const Expression*>* p_Expressions) : m_Expressions(*p_Expressions) {  }
	    virtual const char* getInfixNotation() const = 0;
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High) const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
		     it != m_Expressions.end(); it++) {
		    if (it != m_Expressions.begin()) s << getInfixNotation();
		    s << (*it)->toString(pad, getPrecedence());
		}
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	    bool operator== (const BooleanJunction& ref) const {
		if (m_Expressions.size() != ref.m_Expressions.size())
		    return false;
		std::vector<const Expression*>::const_iterator mit = m_Expressions.begin();
		std::vector<const Expression*>::const_iterator rit = ref.m_Expressions.begin();
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
// 	    virtual bool operator== (const WhereConstraint& r) const {
// 		return r.finalEq(*this);
// 	    }
// 	    virtual const char* getInfixNotation () const { return "&&"; }
// 	};
	class ArithOperation : public WhereConstraint {
	    std::vector<WhereConstraint*> constraints;
	    std::string sqlOperator;
	    e_PREC prec;

	public:
	    ArithOperation (std::string sqlOperator, e_PREC prec) : 
		WhereConstraint(), sqlOperator(sqlOperator), prec(prec) {  }
	    void push_back (WhereConstraint* constraint) { constraints.push_back(constraint); }
	    virtual e_PREC getPrecedence () const { return PREC_Neg; }
	    virtual bool finalEq (const ArithOperation& l) const {
		return l.constraints == constraints && l.sqlOperator == sqlOperator;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High) const {
		std::stringstream s;
		if (prec < parentPrec) s << "(";
		for (std::vector<WhereConstraint*>::const_iterator it = constraints.begin();
		     it != constraints.end(); ++it) {
		    if (it != constraints.begin())
			s << " " <<  sqlOperator << " ";
		    s << (*it)->toString(pad, prec);
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
	    BooleanComparator (const Expression* p_Expression) : Expression(), right(p_Expression) {  }
	    BooleanComparator (const Expression* left, const Expression* right) : Expression(), left(left), right(right) {  }
	    ~BooleanComparator () { delete left; delete right; }
	    virtual void setLeftParm (const Expression* p_left) { left = p_left; }
	    virtual const char* getComparisonNotation() const = 0;
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High) const {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		s << left->toString(pad, getPrecedence());
		s << getComparisonNotation();
		s << right->toString(pad, getPrecedence());
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	};
	class BooleanEQ : public BooleanComparator {
	public:
	    BooleanEQ (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
	    BooleanEQ (const Expression* left, const Expression* right) : BooleanComparator(left, right) {  }
	    virtual e_PREC getPrecedence () const { return PREC_EQ; }
	    virtual bool finalEq (const BooleanEQ& l) const {
		return (l.left == left && l.right == right) // unordered
		    || (l.left == right && l.right == left);
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "="; };
	};
	class BooleanNE : public BooleanComparator {
	public:
	    BooleanNE (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
	    virtual e_PREC getPrecedence () const { return PREC_NE; }
	    virtual bool finalEq (const BooleanNE& l) const {
		return (l.left == left && l.right == right) // unordered
		    || (l.left == right && l.right == left);
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "!="; };
	};
	class BooleanLT : public BooleanComparator {
	public:
	    BooleanLT (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
	    virtual e_PREC getPrecedence () const { return PREC_LT; }
	    virtual bool finalEq (const BooleanLT& l) const {
		return l.left == left && l.right == right;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "<"; };
	};
	class BooleanGT : public BooleanComparator {
	public:
	    BooleanGT (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
	    virtual e_PREC getPrecedence () const { return PREC_GT; }
	    virtual bool finalEq (const BooleanGT& l) const {
		return l.left == left && l.right == right;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return ">"; };
	};
	class BooleanLE : public BooleanComparator {
	public:
	    BooleanLE (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
	    virtual e_PREC getPrecedence () const { return PREC_LT; }
	    virtual bool finalEq (const BooleanLE& l) const {
		return l.left == left && l.right == right;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return "<="; };
	};
	class BooleanGE : public BooleanComparator {
	public:
	    BooleanGE (const Expression* p_Expression) : BooleanComparator(p_Expression) {  }
	    virtual e_PREC getPrecedence () const { return PREC_GT; }
	    virtual bool finalEq (const BooleanGE& l) const {
		return l.left == left && l.right == right;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual const char* getComparisonNotation () const { return ">="; };
	};
	class LiteralConstraint : public WhereConstraint {
	    std::string value;
	public:
	    LiteralConstraint (std::string value) : WhereConstraint(), value(value) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const LiteralConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << "\"" << value << "\"";
		return s.str();
	    }
	};
	class IntConstraint : public WhereConstraint {
	    int value;
	public:
	    IntConstraint (int value) : WhereConstraint(), value(value) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const IntConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class FloatConstraint : public WhereConstraint {
	    float value;
	public:
	    FloatConstraint (float value) : WhereConstraint(), value(value) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const FloatConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class DoubleConstraint : public WhereConstraint {
	    double value;
	public:
	    DoubleConstraint (double value) : WhereConstraint(), value(value) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const DoubleConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class BoolConstraint : public WhereConstraint {
	    bool value;
	public:
	    BoolConstraint (bool value) : WhereConstraint(), value(value) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const BoolConstraint& l) const {
		return l.value == value;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		return value ? "true" : "false";
	    }
	};
	class ReallyNullConstraint : public WhereConstraint {
	public:
	    ReallyNullConstraint () : WhereConstraint() {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ReallyNullConstraint&) const {
		return true;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		return "NULL";
	    }
	};
	class NullConstraint : public WhereConstraint {
	    WhereConstraint* pos;
	public:
	    NullConstraint (WhereConstraint* pos) : WhereConstraint(), pos(pos) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const NullConstraint&) const {
		return true;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << pos->toString();
		s << " IS NOT NULL";
		return s.str();
	    }
	};
	class NegationConstraint : public WhereConstraint {
	    WhereConstraint* negated;
	public:
	    NegationConstraint (WhereConstraint* negated) : WhereConstraint(), negated(negated) {  }
	    virtual e_PREC getPrecedence () const { return PREC_Neg; }
	    virtual bool finalEq (const NegationConstraint& l) const {
		return l.negated == negated;
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string pad, e_PREC parentPrec) const {
		std::stringstream s;
		s << "!(" << negated->toString(pad, parentPrec) << ")";
		return s.str();
	    }
	};
	class AliasAttrConstraint : public WhereConstraint {
	public: // !!!
	    AliasAttr aattr;
	public:
	    AliasAttrConstraint (AliasAttr aattr) : WhereConstraint(), aattr(aattr) {  }
	    virtual bool finalEq (const AliasAttrConstraint& l) const {
		return l.aattr == aattr;
	    }
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << aattr.alias;
		s << ".";
		s << aattr.attr;
		return s.str();
	    }
	    virtual e_PREC getPrecedence () const { return PREC_Pos; }
	};
	class ConcatConstraint : public WhereConstraint {
	    std::vector<const Expression*> args;
	public:
	    ConcatConstraint (std::vector<const Expression*>* args) : WhereConstraint(), args(*args) {  }
	    ~ConcatConstraint () {
		for (std::vector<const Expression*>::const_iterator it = args.begin();
		     it != args.end(); ++it)
		    delete *it;
	    }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const ConcatConstraint& l) const {
		return l.args == args; // @@ does this compare by ref? by val?
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		std::stringstream s;
		s << "CONCAT(";
		for (std::vector<const Expression*>::const_iterator it = args.begin();
		     it != args.end(); ++it) {
		    if (it != args.begin())
			s << ", ";
		    s << (*it)->toString();
		}
		s << ")";
		return s.str();
	    }
	};

	class RegexConstraint : public WhereConstraint {
	    const Expression* text;
	    const Expression* pattern;
	public:
	    RegexConstraint (const Expression* text, const Expression* pattern) : WhereConstraint(), text(text), pattern(pattern) {  }
	    virtual e_PREC getPrecedence () const { return PREC_High; }
	    virtual bool finalEq (const RegexConstraint& l) const {
		return l.text == text && l.pattern == pattern; // @@ does this compare by ref? by val?
	    }	    
	    virtual bool operator== (const WhereConstraint& r) const {
		return r.finalEq(*this);
	    }
	    virtual std::string toString (std::string, e_PREC) const {
		return std::string("REGEX(") + text->toString() + ", " + pattern->toString() + ")";
	    }
	};

	class Join {
	    class JoinConstraint : public Constraint {
	    protected:
		std::string myAttr;
	    public:
		JoinConstraint (std::string myAttr) : Constraint(), myAttr(myAttr) {  }
		virtual ~JoinConstraint () {  }
		virtual std::string toString(std::string alias, std::string pad = "") = 0;
	    };
	    class ForeignKeyJoinConstraint : public JoinConstraint {
		std::string otherAlias;
		std::string otherAttr;
	    public:
		ForeignKeyJoinConstraint (std::string myAttr, std::string otherAlias, std::string otherAttr) : JoinConstraint(myAttr), otherAlias(otherAlias), otherAttr(otherAttr) {  }
		virtual std::string toString (std::string alias, std::string) {
		    std::stringstream s;
		    s << alias << "." << myAttr << "=" << otherAlias << "." << otherAttr;
		    return s.str();
		}
	    };
	    class IntegerJoinConstraint : public JoinConstraint {
		int value;
	    public:
		IntegerJoinConstraint (std::string myAttr, int value) : JoinConstraint(myAttr), value(value) {  }
		virtual std::string toString (std::string alias, std::string) {
		    std::stringstream s;
		    s << alias << "." << myAttr << "=" << value;
		    return s.str();
		}
	    };
	    class StringJoinConstraint : public JoinConstraint {
		std::string value;
	    public:
		StringJoinConstraint (std::string myAttr, std::string value) : JoinConstraint(myAttr), value(value) {  }
		virtual std::string toString (std::string alias, std::string) {
		    std::stringstream s;
		    s << alias << "." << myAttr << "=\"" << value << "\"";
		    return s.str();
		}
	    };
	    std::string alias;
	    bool optional;
	    std::vector<JoinConstraint*> constraints;
	public:
	    Join (std::string alias, bool optional) : alias(alias), optional(optional) {  }
	    virtual ~Join () {
		for (std::vector<JoinConstraint*>::iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    delete *it;
	    }
	    std::string debug_getAlias () { return alias; }
	    virtual std::string getRelationText (std::string pad = "") = 0;
	    std::string toString (std::string* captureConstraints = NULL, std::string pad = "") {
		std::stringstream s;
		if (captureConstraints == NULL) s << std::endl << pad << "            " << (optional ? "LEFT OUTER JOIN " : "INNER JOIN ");
		s << getRelationText(pad) << " AS " << alias;
		std::stringstream on;
		for (std::vector<JoinConstraint*>::iterator it = constraints.begin();
		     it != constraints.end(); ++it) {
		    if (it != constraints.begin())
			on << " AND ";
		    on << (*it)->toString(alias, pad);
		}
		std::string onStr = on.str();
		if (!onStr.empty()) {
		    if (captureConstraints == NULL)
			s << " ON " << onStr;
		    else
			*captureConstraints = onStr;
		}
		return s.str();
	    }
	    void addForeignKeyJoinConstraint (std::string myAttr, std::string otherAlias, std::string otherAttr) {
		if (alias != otherAlias || myAttr != otherAttr)
		    constraints.push_back(new ForeignKeyJoinConstraint(myAttr, otherAlias, otherAttr));
	    }
	    void addConstantJoinConstraint (std::string myAttr, int value) {
		constraints.push_back(new IntegerJoinConstraint(myAttr, value));
	    }
	    void addConstantJoinConstraint (std::string myAttr, std::string value) {
		constraints.push_back(new StringJoinConstraint(myAttr, value));
	    }
	};

	class TableJoin : public Join {
	    std::string relation;
	protected:
	    virtual std::string getRelationText (std::string) { return relation; }
	public:
	    TableJoin (std::string relation, std::string alias, bool optional) : Join(alias, optional), relation(relation) {  }
	    virtual ~TableJoin () {  }
	};

	class AliasedSelect {
	protected:
	    const Expression* exp;
	    std::string alias;
	public:
	    AliasedSelect (const Expression* exp, std::string alias) : exp(exp), alias(alias) {  }
	    virtual ~AliasedSelect () {
		delete exp;
	    }
	    std::string toString (std::string pad = "") {
		return exp->toString(pad) + " AS " + alias;
	    }
	};

	class SQLQuery {
	public:

	    std::vector<Join*> joins;

	    std::vector<const WhereConstraint*> constraints;
	    std::vector<const WhereConstraint*> orderBy;
	    std::vector<AliasedSelect*> selects;
	    bool distinct;
	    int limit, offset;

	public:
	    SQLQuery () : distinct(false), limit(-1), offset(-1) {  }
	    SQLQuery (std::vector<Join*>* joins) : joins(*joins), distinct(false), limit(-1), offset(-1) {  }
	    virtual ~SQLQuery () {

		for (std::vector<AliasedSelect*>::iterator iSelects = selects.begin();
		     iSelects != selects.end(); ++iSelects) {
		    delete *iSelects;
		}

		for (std::vector<Join*>::iterator iJoins = joins.begin();
		     iJoins != joins.end(); ++iJoins) {
		    delete *iJoins;
		}

		for (std::vector<const WhereConstraint*>::iterator iConstraints = constraints.begin();
		     iConstraints != constraints.end(); ++iConstraints)
		    delete *iConstraints;

		for (std::vector<const WhereConstraint*>::iterator iOrderBy = orderBy.begin();
		     iOrderBy != orderBy.end(); ++iOrderBy)
		    delete *iOrderBy;
	    }
	    virtual std::string toString (std::string pad = "") {
		std::stringstream s;
		s << pad << "SELECT ";
		if (distinct) s << "DISTINCT ";

		/* SELECT attributes */
		for (std::vector<AliasedSelect*>::iterator it = selects.begin();
		     it != selects.end(); ++it) {
		    if (it != selects.begin()) s << ", ";
		    s << (*it)->toString(pad);
		}
		if (selects.begin() == selects.end()) s << "NULL";

		/* JOINs */
		std::string where;
		for (std::vector<Join*>::iterator it = joins.begin();
		     it != joins.end(); ++it)
		    if (it == joins.begin())
			s << std::endl << pad << "       FROM " << (*it)->toString(&where, pad);
		    else
			s << (*it)->toString(NULL, pad);

		/* WHERE */
		for (std::vector<const WhereConstraint*>::iterator it = constraints.begin();
		     it != constraints.end(); ++it) {
		    if (where.length() != 0)
			where += " AND ";
		    where += (*it)->toString(pad);
		}

		if (where.length() != 0)
		    s << std::endl << pad << " WHERE " << where;

		/* ORDER BY */
		if (orderBy.begin() != orderBy.end()) {
		    s << std::endl << pad << " ORDER BY ";
		    for (std::vector<const WhereConstraint*>::iterator it = orderBy.begin();
			 it != orderBy.end(); ++it) {
			if (it != orderBy.begin())
			    s << ", ";
			s << (*it)->toString(pad);
		    }
		}

		if (limit != -1) s << std::endl << pad << " LIMIT " << limit;
		if (offset != -1) s << std::endl << pad << "OFFSET " << offset;

		return s.str();
	    }
	};

	class SQLDisjoint;
	class SQLUnion : public SQLQuery {
	public:
	    std::vector<SQLQuery*> disjoints;
	public:
	    SQLUnion () {  }
	    virtual ~SQLUnion () {
		for (std::vector<SQLQuery*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it)	
		    delete *it;
	    }


	    virtual std::string toString (std::string pad = "") {
		std::stringstream s;
		std::string newPad = pad + "    ";
		for (std::vector<SQLQuery*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it) {
		    if (it != disjoints.begin())
			s << std::endl << pad << "  UNION" << std::endl;
		    s << (*it)->toString(newPad);
		}
		return s.str();
	    }

	};

	class SubqueryJoin : public Join {
	    SQLQuery* subquery;
	protected:
	    virtual std::string getRelationText (std::string pad = "") {
		std::stringstream s;
		s << "(" << std::endl << subquery->toString(pad) << std::endl << pad << "             )";
		return s.str();
	    }
	public:
	    SubqueryJoin (SQLQuery* subquery, std::string alias, bool optional) : Join(alias, optional), subquery(subquery) {  }
	    virtual ~SubqueryJoin () { delete subquery; }
	};

	class SQLOptional : public SQLQuery {
	public:
	    SQLOptional () {  }
	    virtual ~SQLOptional () {  }
	    virtual std::string toString (std::string pad = "") {
		std::string newPad = pad + "    ";
		return SQLQuery::toString(newPad);
	    }
	};

    }
}

#endif /* !INCLUDE_SQL_HPP */
