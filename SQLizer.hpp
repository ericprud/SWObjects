/* SQLizer.hpp - simple SPARQL serializer for SPARQL compile trees.
 *
 * $Id: SQLizer.hpp,v 1.34 2008-10-02 17:38:26 eric Exp $
 */

#ifndef SQLizer_H
#define SQLizer_H

#include <cstdlib>
#include <limits>
#include <map>
#include "exs.hpp"
#include "POS2BGPMap.hpp"
#include "SPARQLSerializer.hpp"

namespace w3c_sw {

    class SQLizer : public Expressor {

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
	    virtual std::string toString(std::string pad = "", e_PREC prec = PREC_High) = 0;
	};
	class JunctionConstraint : public WhereConstraint {
	    std::vector<WhereConstraint*> constraints;
	public:
	    JunctionConstraint () : WhereConstraint(), constraints() {  }
	    void addConstraint (WhereConstraint* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad, e_PREC prec = PREC_High) {
		std::stringstream s;
		if (getPrecedence() < prec) s << "(";
		for (std::vector<WhereConstraint*>::iterator it = constraints.begin();
		     it != constraints.end(); it++) {
		    if (it != constraints.begin()) s << getJunctionString();
		    s << (*it)->toString(pad, getPrecedence());
		}
		if (getPrecedence() < prec) s << ")";
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
	class BooleanConstraint : public WhereConstraint {
	    WhereConstraint *left, *right;
	    std::string sqlOperator;
	public:
	    BooleanConstraint (std::string sqlOperator) : WhereConstraint(), left(), right(), sqlOperator(sqlOperator) {  }
	    void setLeft (WhereConstraint* constraint) { left = constraint; }
	    void setRight (WhereConstraint* constraint) { right = constraint; }
	    virtual std::string toString (std::string pad, e_PREC prec = PREC_High) {
		std::stringstream s;
		if (PREC_EQ < prec) s << "(";
		s << left->toString(pad, PREC_EQ);
		s << " " <<  sqlOperator << " ";
		s << right->toString(pad, PREC_EQ);
		if (PREC_EQ < prec) s << ")";
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
	    virtual std::string toString (std::string pad, e_PREC prec) {
		std::stringstream s;
		s << "!(" << negated->toString(pad, prec) << ")";
		return s.str();
	    }
	};
	class AliasAttrConstraint : public WhereConstraint {
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
	    Join (std::string alias, bool optional) : alias(alias), optional(optional) {
		//std::cerr << "new Join(" << alias << ", " << (optional ? "true" : "false") << ") = " << this << std::endl;
  }
	    virtual ~Join () {
		for (std::vector<JoinConstraint*>::iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    delete *it;
	    }
	    std::string debug_getAlias () { return alias; }
	    virtual std::string getRelationText (std::string pad = "") = 0;
	    std::string toString (std::string* captureConstraints = NULL, std::string pad = "") {
		std::stringstream s;
		if (captureConstraints == NULL) s << endl << pad << "            " << (optional ? "LEFT OUTER JOIN " : "INNER JOIN ");
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
	};

	class SQLQuery;
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

	class Attachment {
	protected:
	    std::string name;
	public:
	    Attachment (std::string name) : name(name) {  }
	    virtual ~Attachment () {  }
	    virtual std::string toString(std::string pad = "") = 0;
	    virtual void constrain(AliasAttr aattr, SQLQuery* query) = 0;
	    virtual AliasAttr getAliasAttr () { FAIL("unbound variable"); }
	};

	class TightAttachment : public Attachment {
	    AliasAttr aattr;
	public:
	    TightAttachment (AliasAttr aattr, std::string name) : Attachment(name), aattr(aattr) {  }
	    virtual std::string toString (std::string) {
		std::string ret;
		ret.append(aattr.alias); ret.append("."); ret.append(aattr.attr); ret.append(" AS "); ret.append(name);
		return ret;
	    }
	    virtual void constrain (AliasAttr aattr, SQLQuery* query) {
		query->constrain(aattr, this->aattr);
	    }
	    virtual AliasAttr getAliasAttr () { return aattr; }
	};

	class NullAttachment : public Attachment {
	public:
	    NullAttachment (std::string name) : Attachment(name) {  }
	    virtual std::string toString (std::string) {
		std::string ret;
		ret.append("NULL AS "); ret.append(name);
		return ret;
	    }
	    virtual void constrain (AliasAttr, SQLQuery*) {
		FAIL("trying to constrain against a NullAttachment");
	    }
	};
	class IntAttachment : public Attachment {
	    int value;
	public:
	    IntAttachment (int value, std::string name) : Attachment(name), value(value) {  }
	    virtual std::string toString (std::string) {
		std::stringstream ret;
		ret << value << " AS " << name;
		return ret.str();
	    }
	    virtual void constrain (AliasAttr, SQLQuery*) {
		FAIL1("trying to constrain against a IntAttachment %d", value);
	    }
	};
	class FloatAttachment : public Attachment {
	    float value;
	public:
	    FloatAttachment (float value, std::string name) : Attachment(name), value(value) {  }
	    virtual std::string toString (std::string) {
		std::stringstream ret;
		ret << value << " AS " << name;
		return ret.str();
	    }
	    virtual void constrain (AliasAttr, SQLQuery*) {
		FAIL1("trying to constrain against a FloatAttachment %f", value);
	    }
	};
	class DoubleAttachment : public Attachment {
	    double value;
	public:
	    DoubleAttachment (double value, std::string name) : Attachment(name), value(value) {  }
	    virtual std::string toString (std::string) {
		std::stringstream ret;
		ret << value << " AS " << name;
		return ret.str();
	    }
	    virtual void constrain (AliasAttr, SQLQuery*) {
		FAIL1("trying to constrain against a DoubleAttachment %f", value);
	    }
	};

	class SQLUnion;
	class SQLOptional;
	class SQLQuery {
	protected:
	    SQLQuery* parent;

	    std::map<POS*, map<std::string, Join*> > aliasMap;
	    std::set<string> usedAliases;
	    std::vector<Join*> joins;
	public: Join* curJoin; protected:
	    std::vector<WhereConstraint*> constraints;
	    std::map<std::string, Attachment*> attachments;
	    std::vector<Attachment*> selects;
	    bool distinct;
	    int nextUnionAlias;
	    int nextOptAlias;
	    int limit, offset;

	public:
	    SQLQuery (SQLQuery* parent) : parent(parent), distinct(false), nextUnionAlias(0), nextOptAlias(0), limit(-1), offset(-1) {  }
	    virtual ~SQLQuery () {

		for (std::vector<Join*>::iterator iJoins = joins.begin();
		     iJoins != joins.end(); ++iJoins)
		    delete *iJoins;

		for (std::vector<WhereConstraint*>::iterator iConstraints = constraints.begin();
		     iConstraints != constraints.end(); ++iConstraints)
		    delete *iConstraints;

		for (std::map<string, Attachment*>::iterator iAttachments = attachments.begin();
		     iAttachments != attachments.end(); ++iAttachments)
		    delete iAttachments->second;
	    }
	    void addConstraint (WhereConstraint* constraint) { constraints.push_back(constraint); }
	    virtual std::string toString (std::string pad = "") {
		std::stringstream s;
		s << pad << "SELECT ";
		if (distinct) s << "DISTINCT ";

		/* SELECT attributes */
		for (std::vector<Attachment*>::iterator it = selects.begin();
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
			s << endl << pad << "       FROM " << (*it)->toString(&where, pad);
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

		if (limit != -1) s << std::endl << pad << " LIMIT " << limit;
		if (offset != -1) s << std::endl << pad << "OFFSET " << offset;

		return s.str();
	    }
	    void setDistinct (bool state = true) { distinct = state; }
	    void setLimit (int limit) { this->limit = limit; }
	    void setOffset (int offset) { this->offset = offset; }
	    std::string attachTuple (POS* subject, std::string toRelation) {
		std::map<POS*, map<std::string, Join*> >::iterator byPOS = aliasMap.find(subject);
		if (byPOS != aliasMap.end()) {
		    map<std::string, Join*>::iterator byRelation = aliasMap[subject].find(toRelation);
		    if (byRelation != aliasMap[subject].end()) {
			curJoin = aliasMap[subject][toRelation];
			return curJoin->debug_getAlias();
		    }
		}
		string aliasName = subject->getTerminal();
		unsigned ordinal = 0;
		while (usedAliases.find(aliasName) != usedAliases.end()) {
		    std::stringstream s;
		    s << subject->getTerminal() << "_" << ++ordinal;
		    aliasName = s.str();
		}
		curJoin = new TableJoin(toRelation, aliasName, false);
		joins.push_back(curJoin);
		usedAliases.insert(aliasName);
		//std::cerr << "SQLQuery " << this << ": attachTuple: " << subject->getTerminal() << " bound to " << toRelation << " bound to " << aliasName << std::endl;
		aliasMap[subject][toRelation] = curJoin;
		return aliasName;
	    }
	    SQLUnion* makeUnion (std::vector<POS*> corefs) {
		std::stringstream s;
		s << "union" << ++nextUnionAlias;
		SQLUnion* ret = new SQLUnion(this, corefs, s.str());
		curJoin = new SubqueryJoin(ret, s.str(), false);
		joins.push_back(curJoin);
		return ret;
	    }
	    SQLOptional* makeOptional (std::vector<POS*> corefs) {
		std::stringstream s;
		s << "opt" << ++nextOptAlias;
		SQLOptional* ret = new SQLOptional(this, corefs, s.str());
		curJoin = new SubqueryJoin(ret, s.str(), true);
		joins.push_back(curJoin);
		return ret;
	    }
	    void attachVariable (AliasAttr aattr, std::string terminal) {
		std::map<string, Attachment*>::iterator it = attachments.find(terminal);
		if (it == attachments.end())
		    attachments[terminal] = new TightAttachment(aattr, terminal);
		else
		    attachments[terminal]->constrain(aattr, this);
	    }
	    AliasAttrConstraint* getVariableConstraint (std::string terminal) {
		std::map<string, Attachment*>::iterator it = attachments.find(terminal);
		if (it == attachments.end())
		    FAIL1("can't find variable \"%s\"", terminal.c_str());
		else
		    return new AliasAttrConstraint(it->second->getAliasAttr());
	    }
	    void selectVariable (std::string terminal) {
		if (attachments.find(terminal) == attachments.end())
		    attachments[terminal] = new NullAttachment(terminal);
		//std::cerr << "selectVariable " << terminal << " attached to " << attachments[terminal]->toString() << std::endl;
		selects.push_back(attachments[terminal]);
	    }
	    void selectConstant (int value, std::string alias) {
		if (attachments.find(alias) == attachments.end())
		    attachments[alias] = new IntAttachment(value, alias);
		//std::cerr << "selectVariable " << terminal << " attached to " << attachments[terminal]->toString() << std::endl;
		selects.push_back(attachments[alias]);
	    }
	    void selectConstant (float value, std::string alias) {
		if (attachments.find(alias) == attachments.end())
		    attachments[alias] = new FloatAttachment(value, alias);
		//std::cerr << "selectVariable " << terminal << " attached to " << attachments[terminal]->toString() << std::endl;
		selects.push_back(attachments[alias]);
	    }
	    void selectConstant (double value, std::string alias) {
		if (attachments.find(alias) == attachments.end())
		    attachments[alias] = new DoubleAttachment(value, alias);
		//std::cerr << "selectVariable " << terminal << " attached to " << attachments[terminal]->toString() << std::endl;
		selects.push_back(attachments[alias]);
	    }
	    /* Always add to the last join unless we figure out a reason this doesn't work. */
	    void constrain (AliasAttr x, AliasAttr y) {
		//std::cerr << "SQLQuery " << this << " constraint: " << x.alias << "." << x.attr << "=" << y.alias << "." << y.attr << std::endl;
		if (curJoin->debug_getAlias() != x.alias)
		    FAIL2("constraint on %s is not for last join %s", x.alias.c_str(), curJoin->debug_getAlias().c_str());
		curJoin->addForeignKeyJoinConstraint(x.attr, y.alias, y.attr);
	    }
	    void constrain (AliasAttr aattr, std::string value) {
		if (curJoin->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		curJoin->addConstantJoinConstraint(aattr.attr, value);
	    }
	    void constrain (AliasAttr aattr, int value) {
		if (curJoin->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		curJoin->addConstantJoinConstraint(aattr.attr, value);
	    }
	    void constrain (AliasAttr aattr, float value) {
		if (curJoin->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		curJoin->addConstantJoinConstraint(aattr.attr, value);
	    }
	    void constrain (AliasAttr aattr, double value) {
		if (curJoin->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		curJoin->addConstantJoinConstraint(aattr.attr, value);
	    }
	};

	class SQLDisjoint;
	class SQLUnion : public SQLQuery {
	    std::vector<SQLDisjoint*> disjoints;
	    std::vector<POS*> corefs;
	    std::string name;
	public:
	    SQLUnion (SQLQuery* parent, std::vector<POS*> corefs, std::string name) : 
		SQLQuery(parent), corefs(corefs), name(name)
	    {  }
	    virtual ~SQLUnion () {
		for (std::vector<SQLDisjoint*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it)
		    delete *it;
	    }
	    SQLDisjoint* makeDisjoint () {
		SQLDisjoint* ret = new SQLDisjoint(this);
		disjoints.push_back(ret);
		return ret;
	    }
	    void attach () {
		unsigned nextDisjointCardinal = 1;
		for (std::vector<SQLDisjoint*>::iterator dis = disjoints.begin();
		     dis != disjoints.end(); ++dis)
		    (*dis)->selectConstant((int)nextDisjointCardinal++, "_DISJOINT_"); // cast to int to select selectConstant(int...)
		for (std::vector<POS*>::iterator coref = corefs.begin();
		     coref != corefs.end(); ++coref) {
		    for (std::vector<SQLDisjoint*>::iterator dis = disjoints.begin();
			 dis != disjoints.end(); ++dis)
			// SELECT <field for coref> AS <coref name>
			(*dis)->selectVariable((*coref)->getTerminal());
		    // ON <name>.<coref name> = <parent's field for coref>
		    parent->attachVariable(AliasAttr(name, (*coref)->getTerminal()), (*coref)->getTerminal());
		}
	    }
	    virtual std::string toString (std::string pad = "") {
		std::stringstream s;
		std::string newPad = pad + "    ";
		for (std::vector<SQLDisjoint*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it) {
		    if (it != disjoints.begin())
			s << std::endl << pad << "  UNION" << std::endl;
		    s << (*it)->toString(newPad);
		}
		return s.str();
	    }
	};
	class SQLOptional : public SQLQuery {
	    std::vector<POS*> corefs;
	    std::string name;
	public:
	    SQLOptional (SQLQuery* parent, std::vector<POS*> corefs, std::string name) : 
		SQLQuery(parent), corefs(corefs), name(name)
	    {  }
	    virtual ~SQLOptional () {  }
	    void attach () {
		for (std::vector<POS*>::iterator coref = corefs.begin();
		     coref != corefs.end(); ++coref) {
		    // SELECT <field for coref> AS <coref name>
		    selectVariable((*coref)->getTerminal());
		    // ON <name>.<coref name> = <parent's field for coref>
		    parent->attachVariable(AliasAttr(name, (*coref)->getTerminal()), (*coref)->getTerminal());
		}
	    }
	    virtual std::string toString (std::string pad = "") {
		std::string newPad = pad + "    ";
		return SQLQuery::toString(newPad);
	    }
	};

	class SQLDisjoint : public SQLQuery {
	    SQLUnion* partOf;
	public:
	    SQLDisjoint (SQLUnion* partOf) : SQLQuery(NULL), partOf(partOf) {  }
	};

	struct nonLocalIdentifierException : StringException {
 	    std::string stem, crack;
	    nonLocalIdentifierException (std::string stem, std::string crack) : 
		StringException(make(stem, crack)), stem(stem), crack(crack) {  }
	    virtual ~nonLocalIdentifierException () throw() {  }
	protected:
	    std::string make (std::string stem, std::string crack) {
		std::stringstream s;
		s << "crack <" << crack << "> is not in the domain of "
		  << "stem <" << stem << ">";
		return s.str();
	    }
	};

	int resolve (std::string crack, std::string* relation, std::string* attribute, int* value = NULL) {
	    std::string valueS;

	    char* delim = value ? nodeDelims : predicateDelims;
	    std::string *strings[] = {relation, attribute, &valueS};
	    if (crack.compare(0, stem.size(), stem) != 0)
		throw(nonLocalIdentifierException(stem, crack));

	    size_t pos = 0;
	    for(std::string::iterator iter=crack.begin() + stem.size();
		iter != crack.end() && pos < (value == NULL ? 2 : 3); ++iter)
		if (*iter==delim[pos])
		    pos += 1;
		else
		    *(strings[pos])+=*iter;

	    if (value != NULL && valueS.size() > 0) {
		char *ep = 0;
		*value = std::strtol(valueS.c_str(), &ep, 10);
	    }

	    return pos+1;
	}
	AliasAttr getPKAttr (std::string alias) { return AliasAttr(alias, "id"); }

	std::string stem;
	/*	AliasContext* curAliases; */
	enum {MODE_outside, MODE_subject, MODE_predicate, MODE_object, MODE_selectVar, MODE_constraint, MODE_overrun} mode;
	SQLQuery* curQuery;
	POS* curSubject;
	AliasAttr curAliasAttr; // established by predicate
	TableOperation* curTableOperation;
	std::string subjectRelation, predicateRelation;
	Consequents* consequentsP;
	VarSet* selectVars;
	char* predicateDelims;
	char* nodeDelims;
	WhereConstraint* curConstraint;

	std::ostream* debugStream;

    public:
	SQLizer (std::string stem, char predicateDelims[], char nodeDelims[], std::ostream* debugStream = NULL) : 
	    stem(stem), mode(MODE_outside), curAliasAttr("bogusAlias", "bogusAttr"), selectVars(NULL), 
	    predicateDelims(predicateDelims), nodeDelims(nodeDelims), debugStream(debugStream)
	{  }
	~SQLizer () { delete curQuery; }

	std::string getSPARQLstring () { return curQuery->toString(); }

	virtual void base (Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void uri (URI*, std::string terminal) {
	    MARK;
	    std::string relation, attribute;
	    int value;

	    switch (mode) {

	    case MODE_predicate:
		NOW("URI as predicate");
		if (resolve(terminal, &relation, &attribute) != 2) FAIL2("malformed predicate \"%s\" didn't match \"%s\"", terminal.c_str(), stem.c_str());
		curAliasAttr.alias = curQuery->attachTuple(curSubject, relation);
		curAliasAttr.attr = attribute;
		predicateRelation = relation;
		break;

	    case MODE_subject:
		NOW("URI as subject");
		if (resolve(terminal, &relation, &attribute, &value) != 3) FAIL("incomplete key");
		if (predicateRelation != relation)
		    std::cerr << "!Subject relation is " << relation << " while predicate relation is " << predicateRelation << std::endl;
		curQuery->constrain(getPKAttr(curAliasAttr.alias), value);
		break;

	    case MODE_object:
		NOW("URI as object");
		if (resolve(terminal, &relation, &attribute, &value) != 3) FAIL("incomplete key");
		curQuery->constrain(curAliasAttr, value);
		break;

	    case MODE_constraint:
		FAIL1("URI <%s> as constraint is unimplemented", terminal.c_str());
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void variable (Variable*, std::string terminal) {

	    // enforce coreferences
	    switch (mode) {

	    case MODE_subject:
		NOW("Variable as subject");
		curQuery->attachVariable(getPKAttr(curAliasAttr.alias), terminal);
		break;

	    case MODE_predicate:
		FAIL("No variable predicates, please.");
		break;

	    case MODE_object:
		NOW("Variable as object");
		curQuery->attachVariable(curAliasAttr, terminal);
		break;

	    case MODE_selectVar:
		NOW("URI as selectVar");
		curQuery->selectVariable(terminal);
		break;

	    case MODE_constraint:
		NOW("Variable as constraint");
		curConstraint = curQuery->getVariableConstraint(terminal);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void bnode (BNode*, std::string terminal) {

	    // enforce coreferences
	    switch (mode) {

	    case MODE_subject:
		NOW("Variable as subject");
		curQuery->attachVariable(getPKAttr(curAliasAttr.alias), terminal);
		break;

	    case MODE_predicate:
		FAIL("No variable predicates, please.");
		break;

	    case MODE_object:
		NOW("Variable as object");
		curQuery->attachVariable(curAliasAttr, terminal);
		break;

	    case MODE_selectVar:
		FAIL("no told bnodes");
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	/* Literal Map -- http://www.w3.org/2008/07/MappingRules/#litMap !!! not done */
	virtual void rdfLiteral (RDFLiteral*, std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	    MARK;
	    std::string value = terminal;
	    if (datatype != NULL) {
		if (datatype->getTerminal() == "http://www.w3.org/2001/XMLSchema#dateTime")
		    value.replace(value.find("T"), 1, " ");
		else
		    FAIL1("unknown datatype: <%s>", datatype->getTerminal().c_str());
	    }
	    if (p_LANGTAG != NULL) {
		FAIL("how do we literalMap langtags?");
	    }

	    switch (mode) {

	    case MODE_subject:
		NOW("Literal as subject -- odd, but why not?");
		curQuery->constrain(getPKAttr(curAliasAttr.alias), value);
		break;

	    case MODE_predicate:
		FAIL("No literal predicates, please.");
		break;

	    case MODE_object:
		NOW("Literal as object");
		curQuery->constrain(curAliasAttr, value);
		break;

	    case MODE_selectVar:
		NOW("Literal as selectVar");
		curQuery->selectVariable(value);
		break;

	    case MODE_constraint:
		NOW("Literal as constraint");
		curConstraint = new LiteralConstraint(value);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void rdfLiteral (NumericRDFLiteral*, int p_value) {
	    MARK;
	    switch (mode) {

	    case MODE_subject:
		NOW("int as subject -- odd, but why not?");
		curQuery->constrain(getPKAttr(curAliasAttr.alias), p_value);
		break;

	    case MODE_predicate:
		FAIL("No literal predicates, please.");
		break;

	    case MODE_object:
		NOW("int as object");
		curQuery->constrain(curAliasAttr, p_value);
		break;

	    case MODE_selectVar:
		NOW("int as selectVar");
		curQuery->selectConstant(p_value, "__CONSTANT_INT__");
		break;

	    case MODE_constraint:
		NOW("int as constraint");
		curConstraint = new IntConstraint(p_value);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void rdfLiteral (NumericRDFLiteral*, float p_value) {
	    MARK;
	    switch (mode) {

	    case MODE_subject:
		NOW("float as subject -- odd, but why not?");
		curQuery->constrain(getPKAttr(curAliasAttr.alias), p_value);
		break;

	    case MODE_predicate:
		FAIL("No literal predicates, please.");
		break;

	    case MODE_object:
		NOW("float as object");
		curQuery->constrain(curAliasAttr, p_value);
		break;

	    case MODE_selectVar:
		NOW("float as selectVar");
		curQuery->selectConstant(p_value, "__CONSTANT_FLOAT__");
		break;

	    case MODE_constraint:
		NOW("float as constraint");
		curConstraint = new FloatConstraint(p_value);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void rdfLiteral (NumericRDFLiteral*, double p_value) {
	    MARK;
	    switch (mode) {

	    case MODE_subject:
		NOW("double as subject -- odd, but why not?");
		curQuery->constrain(getPKAttr(curAliasAttr.alias), p_value);
		break;

	    case MODE_predicate:
		FAIL("No literal predicates, please.");
		break;

	    case MODE_object:
		NOW("double as object");
		curQuery->constrain(curAliasAttr, p_value);
		break;

	    case MODE_selectVar:
		NOW("double as selectVar");
		curQuery->selectConstant(p_value, "__CONSTANT_DOUBLE__");
		break;

	    case MODE_constraint:
		NOW("double as constraint");
		curConstraint = new DoubleConstraint(p_value);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void rdfLiteral (BooleanRDFLiteral*, bool p_value) {
	    MARK;
	    switch (mode) {

	    case MODE_subject:
		NOW("bool as subject -- odd, but why not?");
		curQuery->constrain(getPKAttr(curAliasAttr.alias), p_value);
		break;

	    case MODE_predicate:
		FAIL("No literal predicates, please.");
		break;

	    case MODE_object:
		NOW("bool as object");
		curQuery->constrain(curAliasAttr, p_value);
		break;

	    case MODE_selectVar:
		NOW("bool as selectVar");
		curQuery->selectConstant(p_value, "__CONSTANT_BOOL__");
		break;

	    case MODE_constraint:
		NOW("bool as constraint");
		curConstraint = new BoolConstraint(p_value);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void nullpos (NULLpos*) {  }
	virtual void triplePattern (TriplePattern*, POS* p_s, POS* p_p, POS* p_o) {
	    // std::cerr << "triplePattern: " << self->toString() << std::endl;
	    curSubject = p_s;
	    START("checking predicate");
	    mode = MODE_predicate;
	    p_p->express(this);

	    NOW("checking subject");
	    mode = MODE_subject;
	    p_s->express(this);


	    NOW("checking object");
	    mode = MODE_object;
	    p_o->express(this);

	    mode = MODE_outside;
	    //curQuery->curJoin = NULL;
	}
	virtual void filter (Filter*, Expression* p_Constraint) {
	    p_Constraint->express(this);
	}
	void _BasicGraphPattern (ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    MARK;
	    for (std::vector<TriplePattern*>::iterator tripleIt = p_TriplePatterns->begin();
		 tripleIt != p_TriplePatterns->end(); ++tripleIt)
		try {
		    (*tripleIt)->express(this);
		} catch (nonLocalIdentifierException& e) {
		    SPARQLSerializer sparqlizer("  ");
		    (*tripleIt)->express(&sparqlizer);
		    std::cerr << "pattern {" << sparqlizer.getSPARQLstring() << "} is not handled by stem " << stem << " because " << e.what() << endl;
		}
	    NOW("bgp filters");
	    for (std::vector<Filter*>::iterator filterIt = p_Filters->begin();
		 filterIt != p_Filters->end(); ++filterIt)
		try {
		    (*filterIt)->express(this);
		    curQuery->addConstraint(curConstraint);
		} catch (nonLocalIdentifierException& e) {
		    SPARQLSerializer sparqlizer("  ");
		    (*filterIt)->express(&sparqlizer);
		    std::cerr << "filter {" << sparqlizer.getSPARQLstring() << "} is not handled by stem " << stem << " because " << e.what() << endl;
		}
	}
	virtual void namedGraphPattern (NamedGraphPattern*, POS*, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    MARK;
	    _BasicGraphPattern(p_TriplePatterns, p_Filters);
	}
	virtual void defaultGraphPattern (DefaultGraphPattern*, bool /*p_allOpts*/, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	    MARK;
	    _BasicGraphPattern(p_TriplePatterns, p_Filters);
	}
	virtual void tableDisjunction (TableDisjunction*, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    SQLQuery* parent = curQuery;
	    SQLUnion* disjunction = parent->makeUnion(consequentsP->entriesFor(curTableOperation));
	    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); ++it) {
		MARK;
		curQuery = disjunction->makeDisjoint();
		curTableOperation = *it;
		curTableOperation->express(this);
	    }
	    disjunction->attach();
	    p_Filters->express(this);
	    curQuery = parent;
	}
	virtual void tableConjunction (TableConjunction*, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	    MARK;
	    for (std::vector<TableOperation*>::iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); ++it) {
		MARK;
		curTableOperation = *it;
		curTableOperation->express(this);
	    }
	    p_Filters->express(this);
	}
	virtual void optionalGraphPattern (OptionalGraphPattern*, TableOperation* p_GroupGraphPattern) {
	    MARK;
	    SQLQuery* parent = curQuery;
	    //std::cerr << "checking for "<<curTableOperation<<" or "<<p_GroupGraphPattern<<std::endl;
	    SQLOptional* optional = parent->makeOptional(consequentsP->entriesFor(curTableOperation));
	    curQuery = optional;
	    curTableOperation = p_GroupGraphPattern; 
	    curTableOperation->express(this);
	    optional->attach();
	    curQuery = parent;
	}
	virtual void graphGraphPattern (GraphGraphPattern*, POS* p_POS, TableOperation* p_GroupGraphPattern) {
	    FAIL("don't do federation with GraphGraphPatterns yet");
	    p_POS->express(this);
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	}
	virtual void posList (POSList*, ProductionVector<POS*>* p_POSs) {
	    for (std::vector<POS*>::iterator it = p_POSs->begin();
		 it != p_POSs->end(); ++it)
		(*it)->express(this);
	}
	virtual void starVarSet (StarVarSet*) {
	    FAIL("need to select all pertinent vars");
	}
	virtual void defaultGraphClause (DefaultGraphClause*, POS* p_IRIref) {
	    p_IRIref->express(this);
	}
	virtual void namedGraphClause (NamedGraphClause*, POS* p_IRIref) {
	    p_IRIref->express(this);
	}
	virtual void solutionModifier (SolutionModifier*, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	    if (p_limit != LIMIT_None) curQuery->setLimit(p_limit);
	    if (p_offset != OFFSET_None) curQuery->setOffset(p_offset);
	    if (p_OrderConditions)
		for (std::vector<s_OrderConditionPair>::iterator it = p_OrderConditions->begin();
		     it != p_OrderConditions->end(); ++it)
		    /*bool desc = p_OrderConditions->at(i).ascOrDesc == ORDER_Desc;*/
		    // !!!
		    it->expression->express(this);
	}
	virtual void binding (Binding*, ProductionVector<POS*>* values) {//!!!
	    // !!!
	    for (std::vector<POS*>::iterator it = values->begin();
		 it != values->end(); ++it)
		(*it)->express(this);
	}
	virtual void bindingClause (BindingClause*, POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	    p_Vars->express(this);
	    p_Bindings->ProductionVector<Binding*>::express(this);
	}
	virtual void whereClause (WhereClause*, TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	    START("p_GroupGraphPattern");
	    Consequents consequents(p_GroupGraphPattern, selectVars, debugStream);
	    consequentsP = &consequents;
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	    if (p_BindingClause) p_BindingClause->express(this);
	}
	virtual void select (Select*, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    START("cracking select clause");
	    curQuery = new SQLQuery(NULL);
	    selectVars = p_VarSet;
	    if (p_distinctness == DIST_distinct) curQuery->setDistinct(true);
	    //if (p_distinctness == DIST_reduced) ...
	    if (p_DatasetClauses->size() > 0) FAIL("don't know what to do with DatasetClauses");
	    NOW("p_WhereClause");
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    mode = MODE_selectVar;
	    p_VarSet->express(this);
	}
	virtual void construct (Construct*, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    FAIL("CONSTRUCT");
	    p_ConstructTemplate->express(this);
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	}
	virtual void describe (Describe*, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    FAIL("DESCRIBE");
	    p_VarSet->express(this);
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	}
	virtual void ask (Ask*, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    FAIL("ASK");
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	}
	virtual void replace (Replace*, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    FAIL("REPLACE");
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	}
	virtual void insert (Insert*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    FAIL("INSERT {");
	    p_GraphTemplate->express(this);
	    if (p_WhereClause) p_WhereClause->express(this);
	}
	virtual void del (Delete*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    FAIL("DELET");
	    p_GraphTemplate->express(this);
	    p_WhereClause->express(this);
	}
	virtual void load (Load*, ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	    FAIL("LOAD");
	    p_IRIrefs->express(this);
	    p_into->express(this);
	}
	virtual void clear (Clear*, URI* p__QGraphIRI_E_Opt) {
	    FAIL("CLEAR");
	    p__QGraphIRI_E_Opt->express(this);
	}
	virtual void create (Create*, e_Silence p_Silence, URI* p_GraphIRI) {
	    FAIL("CREATE");
	    if (p_Silence != SILENT_Yes) ;// !!!
	    p_GraphIRI->express(this);
	}
	virtual void drop (Drop*, e_Silence p_Silence, URI* p_GraphIRI) {
	    if (p_Silence != SILENT_Yes) ;// !!!
	    p_GraphIRI->express(this);
	}
	virtual void varExpression (VarExpression*, Variable* p_Variable) {
	    MARK;
	    mode = MODE_constraint;
	    p_Variable->express(this);
	}
	virtual void literalExpression (LiteralExpression*, RDFLiteral* p_RDFLiteral) {
	    MARK;
	    p_RDFLiteral->express(this);
	}
	virtual void booleanExpression (BooleanExpression*, BooleanRDFLiteral* p_BooleanRDFLiteral) {
	    MARK;
	    p_BooleanRDFLiteral->express(this);
	}
	virtual void uriExpression (URIExpression*, URI* p_URI) {
	    MARK;
	    p_URI->express(this);
	}
	virtual void argList (ArgList*, ProductionVector<Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	    MARK;
	    p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
	}
	// !!!
	virtual void functionCall (FunctionCall*, URI* iri, ArgList* args) {
	    MARK;
	    args->express(this);
	    if (iri->getTerminal() == "http://www.w3.org/TR/rdf-sparql-query/#func-bound")
		curConstraint = new NullConstraint(curConstraint);
	    else
		iri->express(this);
	}
	virtual void functionCallExpression (FunctionCallExpression*, FunctionCall* p_FunctionCall) {
	    MARK;
	    p_FunctionCall->express(this);
	}
	/* Expressions */
	virtual void booleanNegation (BooleanNegation*, Expression* p_Expression) {
	    MARK;
	    p_Expression->express(this);
	    curConstraint = new NegationConstraint(curConstraint);
	}
	virtual void arithmeticNegation (ArithmeticNegation*, Expression* p_Expression) {
	    MARK;
	    p_Expression->express(this);
	}
	virtual void arithmeticInverse (ArithmeticInverse*, Expression* p_Expression) {
	    MARK;
	    p_Expression->express(this);
	}
	virtual void booleanConjunction (BooleanConjunction*, ProductionVector<Expression*>* p_Expressions) {
	    MARK;
	    ConjunctionConstraint* conj = new ConjunctionConstraint();
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it) {
		(*it)->express(this);
		conj->addConstraint(curConstraint);
	    }
	    curConstraint = conj;
	}
	virtual void booleanDisjunction (BooleanDisjunction*, ProductionVector<Expression*>* p_Expressions) {
	    MARK;
	    DisjunctionConstraint* disj = new DisjunctionConstraint();
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it) {
		(*it)->express(this);
		disj->addConstraint(curConstraint);
	    }
	    curConstraint = disj;
	}
	virtual void arithmeticSum (ArithmeticSum*, ProductionVector<Expression*>* p_Expressions) {
	    MARK;
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it)
		(*it)->express(this);
	}
	virtual void arithmeticProduct (ArithmeticProduct*, ProductionVector<Expression*>* p_Expressions) {
	    MARK;
	    for (std::vector<Expression*>::iterator it = p_Expressions->begin();

		 it != p_Expressions->end(); ++it)
		(*it)->express(this);
	}
	void _boolConstraint (Expression* p_left, std::string sqlOperator, Expression* p_right) {
	    BooleanConstraint* c = new BooleanConstraint(sqlOperator);
	    p_left->express(this);
	    c->setLeft(curConstraint);
	    p_right->express(this);
	    c->setRight(curConstraint);
	    curConstraint = c;
	}
	virtual void booleanEQ (BooleanEQ*, Expression* p_left, Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "=", p_right);
	}
	virtual void booleanNE (BooleanNE*, Expression* p_left, Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "!=", p_right);
	}
	virtual void booleanLT (BooleanLT*, Expression* p_left, Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "<", p_right);
	}
	virtual void booleanGT (BooleanGT*, Expression* p_left, Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, ">", p_right);
	}
	virtual void booleanLE (BooleanLE*, Expression* p_left, Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "<=", p_right);
	}
	virtual void booleanGE (BooleanGE*, Expression* p_left, Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, ">=", p_right);
	}
	virtual void comparatorExpression (ComparatorExpression*, BooleanComparator* p_BooleanComparator) {
	    MARK;
	    p_BooleanComparator->express(this);
	}
	virtual void numberExpression (NumberExpression*, NumericRDFLiteral* p_NumericRDFLiteral) {
	    MARK;
	    p_NumericRDFLiteral->express(this);
	}
    };

} // namespace w3c_sw

#endif // SQLizer_H

