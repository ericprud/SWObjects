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
	};

	class Constraint {
	protected:
	public:
	    Constraint () {  }
	    virtual ~Constraint () {  }
	};
	class WhereConstraint : public Constraint {
	protected:
	public:
	    WhereConstraint () {  }
	    virtual ~WhereConstraint () {  }
	    virtual std::string toString(std::string pad = "", e_PREC parentPrec = PREC_High) = 0;
	};
	typedef WhereConstraint Expression;
	class JunctionConstraint : public WhereConstraint {
	    std::vector<WhereConstraint*> constraints;
	public:
	    JunctionConstraint () : WhereConstraint(), constraints() {  }
	    void addConstraint (WhereConstraint* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High) {
		std::stringstream s;
		if (getPrecedence() < parentPrec) s << "(";
		for (std::vector<WhereConstraint*>::iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    if (it != constraints.begin()) s << getJunctionString();
		    s << (*it)->toString(pad, getPrecedence());
		}
		if (getPrecedence() < parentPrec) s << ")";
		return s.str();
	    }
	    virtual std::string getJunctionString() = 0;
	    virtual e_PREC getPrecedence() = 0;
	};
	class ConjunctionConstraint : public JunctionConstraint {
	    virtual std::string getJunctionString () { return " AND "; }
	    virtual e_PREC getPrecedence () { return PREC_And; }
	};
	class DisjunctionConstraint : public JunctionConstraint {
	    virtual std::string getJunctionString () { return " OR "; }
	    virtual e_PREC getPrecedence () { return PREC_Or; }
	};
	class ArithOperation : public WhereConstraint {
	    std::vector<WhereConstraint*> constraints;
	    std::string sqlOperator;
	    e_PREC prec;

	public:
	    ArithOperation (std::string sqlOperator, e_PREC prec) : 
		WhereConstraint(), sqlOperator(sqlOperator), prec(prec) {  }
	    void push_back (WhereConstraint* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad, e_PREC parentPrec = PREC_High) {
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
	class LiteralConstraint : public WhereConstraint {
	    std::string value;
	public:
	    LiteralConstraint (std::string value) : WhereConstraint(), value(value) {  }
	    virtual std::string toString (std::string, e_PREC) {
		std::stringstream s;
		s << "\"" << value << "\"";
		return s.str();
	    }
	};
	class IntConstraint : public WhereConstraint {
	    int value;
	public:
	    IntConstraint (int value) : WhereConstraint(), value(value) {  }
	    virtual std::string toString (std::string, e_PREC) {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class FloatConstraint : public WhereConstraint {
	    float value;
	public:
	    FloatConstraint (float value) : WhereConstraint(), value(value) {  }
	    virtual std::string toString (std::string, e_PREC) {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class DoubleConstraint : public WhereConstraint {
	    double value;
	public:
	    DoubleConstraint (double value) : WhereConstraint(), value(value) {  }
	    virtual std::string toString (std::string, e_PREC) {
		std::stringstream s;
		s << value;
		return s.str();
	    }
	};
	class BoolConstraint : public WhereConstraint {
	    bool value;
	public:
	    BoolConstraint (bool value) : WhereConstraint(), value(value) {  }
	    virtual std::string toString (std::string, e_PREC) {
		return value ? "true" : "false";
	    }
	};
	class ReallyNullConstraint : public WhereConstraint {
	public:
	    ReallyNullConstraint () : WhereConstraint() {  }
	    virtual std::string toString (std::string, e_PREC) {
		return "NULL";
	    }
	};
	class NullConstraint : public WhereConstraint {
	    WhereConstraint* pos;
	public:
	    NullConstraint (WhereConstraint* pos) : WhereConstraint(), pos(pos) {  }
	    virtual std::string toString (std::string, e_PREC) {
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
	    virtual std::string toString (std::string pad, e_PREC parentPrec) {
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
	    virtual std::string toString (std::string, e_PREC) {
		std::stringstream s;
		s << aattr.alias;
		s << ".";
		s << aattr.attr;
		return s.str();
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
	    Expression* exp;
	    std::string alias;
	public:
	    AliasedSelect (Expression* exp, std::string alias) : exp(exp), alias(alias) {  }
	    virtual ~AliasedSelect () {  }
	    std::string toString (std::string pad = "") {
		return exp->toString(pad) + " AS " + alias;
	    }
	};

	class SQLQuery {
	public:

	    std::vector<Join*> joins;

	    std::vector<WhereConstraint*> constraints;
	    std::vector<WhereConstraint*> orderBy;
	    std::vector<AliasedSelect*> selects;
	    bool distinct;
	    int limit, offset;

	public:
	    SQLQuery () : distinct(false), limit(-1), offset(-1) {  }
	    virtual ~SQLQuery () {

// 		for (std::vector<Join*>::iterator iJoins = joins.begin();
// 		     iJoins != joins.end(); ++iJoins) {
// 		    delete *iJoins;
// 		}

// 		for (std::vector<WhereConstraint*>::iterator iConstraints = constraints.begin();
// 		     iConstraints != constraints.end(); ++iConstraints)
// 		    delete *iConstraints;

// 		for (std::vector<WhereConstraint*>::iterator iOrderBy = orderBy.begin();
// 		     iOrderBy != orderBy.end(); ++iOrderBy)
// 		    delete *iOrderBy;
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
		for (std::vector<WhereConstraint*>::iterator it = constraints.begin();
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
		    for (std::vector<WhereConstraint*>::iterator it = orderBy.begin();
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
	    virtual ~SQLUnion ();
	    virtual std::string toString(std::string pad = "");
	};

	std::string SQLUnion::toString (std::string pad) {
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

	SQLUnion::~SQLUnion () {
	    for (std::vector<SQLQuery*>::iterator it = disjoints.begin();
		 it != disjoints.end(); ++it)	
	delete *it;
	}

    }
}

#endif /* !INCLUDE_SQL_HPP */
