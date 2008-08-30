/* SQLizer.hpp - simple SPARQL serializer for SPARQL compile trees.
 *
 * $Id: SQLizer.hpp,v 1.7 2008-08-30 23:48:17 eric Exp $
 */

#ifndef SQLizer_H
#define SQLizer_H

#include <cstdlib>
#include <limits>
#include <map>
#include "exs.hpp"
#include "POS2BGPMap.hpp"

namespace w3c_sw {

    class SQLizer : public Expressor {

	typedef struct {std::string alias; std::string attr; } AliasAttr;

	class Join {
	    class Constraint {
	    protected:
		std::string myAttr;
	    public:
		Constraint (std::string myAttr) : myAttr(myAttr) {  }
		virtual ~Constraint () {  }
		virtual std::string toString (std::string alias) = 0;
	    };
	    class ForeignKeyConstraint : public Constraint {
		std::string otherAlias;
		std::string otherAttr;
	    public:
		ForeignKeyConstraint (std::string myAttr, std::string otherAlias, std::string otherAttr) : Constraint(myAttr), otherAlias(otherAlias), otherAttr(otherAttr) {  }
		virtual std::string toString (std::string alias) {
		    std::stringstream s;
		    s << alias << "." << myAttr << "=" << otherAlias << "." << otherAttr;
		    return s.str();
		}
	    };
	    class IntegerConstraint : public Constraint {
		int value;
	    public:
		IntegerConstraint (std::string myAttr, int value) : Constraint(myAttr), value(value) {  }
		virtual std::string toString (std::string alias) {
		    std::stringstream s;
		    s << alias << "." << myAttr << "=" << value;
		    return s.str();
		}
	    };
	    class StringConstraint : public Constraint {
		std::string value;
	    public:
		StringConstraint (std::string myAttr, std::string value) : Constraint(myAttr), value(value) {  }
		virtual std::string toString (std::string alias) {
		    std::stringstream s;
		    s << alias << "." << myAttr << "=\"" << value << "\"";
		    return s.str();
		}
	    };
	    std::string alias;
	    bool optional;
	    std::vector<Constraint*> constraints;
	public:
	    Join (std::string alias, bool optional) : alias(alias), optional(optional) {  }
	    virtual ~Join () {
		for (std::vector<Constraint*>::iterator it = constraints.begin();
		     it != constraints.end(); ++it)
		    delete *it;
	    }
	    std::string debug_getAlias () { return alias; }
	    virtual std::string getRelationText () = 0;
	    std::string toString (std::string* captureConstraints = NULL) {
		std::stringstream s;
		if (captureConstraints == NULL) s << endl << "            " << (optional ? "LEFT OUTER JOIN " : "INNER JOIN ");
		s << getRelationText() << " AS " << alias;
		std::stringstream on;
		for (std::vector<Constraint*>::iterator it = constraints.begin();
		     it != constraints.end(); ++it) {
		    if (it != constraints.begin())
			on << " AND ";
		    on << (*it)->toString(alias);
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
	    void addForeignKeyConstraint (std::string myAttr, std::string otherAlias, std::string otherAttr) {
		constraints.push_back(new ForeignKeyConstraint(myAttr, otherAlias, otherAttr));
	    }
	    void addConstantConstraint (std::string myAttr, int value) {
		constraints.push_back(new IntegerConstraint(myAttr, value));
	    }
	    void addConstantConstraint (std::string myAttr, std::string value) {
		constraints.push_back(new StringConstraint(myAttr, value));
	    }
	};

	class TableJoin : public Join {
	    std::string relation;
	protected:
	    virtual std::string getRelationText () { return relation; }
	public:
	    TableJoin (std::string relation, std::string alias, bool optional) : Join(alias, optional), relation(relation) {  }
	};

	class SQLQuery;
	class SubqueryJoin : public Join {
	    SQLQuery* subquery;
	protected:
	    virtual std::string getRelationText () {
		std::stringstream s;
		s << "(" << std::endl << subquery->toString() << std::endl << "             )";
		return s.str();
	    }
	public:
	    SubqueryJoin (SQLQuery* subquery, std::string alias, bool optional) : Join(alias, optional), subquery(subquery) {  }
	    virtual ~SubqueryJoin () { delete subquery; }
	};

	class Attachment {
	    AliasAttr aattr;
	    std::string name;
	public:
	    Attachment () {  }
	    Attachment (AliasAttr aattr, std::string name) : aattr(aattr), name(name) {  }
	    void setName(std::string name) { this->name = name; }
	    std::string getName () { return name; }
	    void setAliasAttr(AliasAttr aattr) { this->aattr = aattr; }
	    AliasAttr getAliasAttr () { return aattr; }
	    std::string toString () {
		std::stringstream s;
		s << name << " attached to " << aattr.alias << "." << aattr.attr;
		return s.str();
	    }
	};

	class TightAttachment : public Attachment {
	public:
	    TightAttachment () : Attachment() {  }
	    TightAttachment (AliasAttr aattr, std::string name) : Attachment(aattr, name) {  }
	};

	class SQLUnion;
	class SQLQuery {
	    SQLQuery* parent;

	    std::map<POS*, map<std::string, std::string> > aliasMap;
	    std::set<string> usedAliases;
	    std::vector<Join*> joins;
	    std::map<std::string, Attachment> attachments;
	    std::vector<Attachment> selects;
	    bool distinct;
	    int nextUnionAlias;
	    int nextOptAlias;
	public:
	    SQLQuery (SQLQuery* parent) : parent(parent), distinct(false), nextUnionAlias(0), nextOptAlias(0) {  }
	    virtual ~SQLQuery () {
		for (std::vector<Join*>::iterator it = joins.begin();
		     it != joins.end(); ++it)
		    delete *it;
	    }
	    virtual std::string toString () {
		std::stringstream s;
		s << "SELECT ";
		if (distinct) s << "DISTINCT ";
		for (std::vector<Attachment>::iterator it = selects.begin();
		     it != selects.end(); ++it)
		    s << it->getAliasAttr().alias << "." << it->getAliasAttr().attr << " AS " << it->getName() << " ";
		std::string where;
		for (std::vector<Join*>::iterator it = joins.begin();
		     it != joins.end(); ++it)
		    if (it == joins.begin())
			s << endl << "       FROM " << (*it)->toString(&where);
		    else
			s << (*it)->toString();
		if (!where.empty()) s << std::endl << " WHERE " << where;
		return s.str();
	    }
	    void setDistinct (bool state = true) { distinct = state; }
	    std::string attachTuple (POS* subject, std::string toRelation, std::string attribute) {
		std::map<POS*, map<std::string, std::string> >::iterator byPOS = aliasMap.find(subject);
		if (byPOS != aliasMap.end()) {
		    map<std::string, std::string>::iterator byRelation = aliasMap[subject].find(toRelation);
		    if (byRelation != aliasMap[subject].end())
			return aliasMap[subject][toRelation];
		}
		string aliasName = subject->getTerminal();
		unsigned ordinal = 0;
		while (usedAliases.find(aliasName) != usedAliases.end()) {
		    std::stringstream s;
		    s << subject->getTerminal() << "_" << ++ordinal;
		    aliasName = s.str();
		}
		joins.push_back(new TableJoin(toRelation, aliasName, false));
		usedAliases.insert(aliasName);
		std::cerr << "SQLQuery " << this << ": attachTuple: " << subject << ", " << toRelation << "." << attribute << " bound to " << aliasName << std::endl;
		return aliasName;
	    }
	    SQLUnion* makeUnion () {
		SQLUnion* ret = new SQLUnion(this);
		std::stringstream s;
		s << "union" << ++nextUnionAlias;
		joins.push_back(new SubqueryJoin(ret, s.str(), false));		
		return ret;
	    }
	    void attachVariable (AliasAttr aattr, std::string terminal) {
		std::map<string, Attachment>::iterator it = attachments.find(terminal);
		if (it == attachments.end())
		    attachments[terminal] = TightAttachment(aattr, terminal);
		else
		    constrain(aattr, attachments[terminal].getAliasAttr());
		std::cerr << "SQLQuery " << this << ": attach " << terminal << " to " << attachments[terminal].toString() << std::endl;
		// !!!
	    }
	    void selectVariable (std::string terminal) {
		std::cerr << "selectVariable " << terminal << " attached to " << attachments[terminal].toString() << std::endl;
		selects.push_back(attachments[terminal]);
	    }
	    /* Always add to the last join unless we figure out a reason this doesn't work. */
	    void constrain (AliasAttr x, AliasAttr y) {
		std::cerr << "SQLQuery " << this << " constraint: " << x.alias << "." << x.attr << "=" << y.alias << "." << y.attr << std::endl;
		if (joins.back()->debug_getAlias() != x.alias) FAIL("constraint is not for last join");
		joins.back()->addForeignKeyConstraint(x.attr, y.alias, y.attr);
	    }
	    void constrain (AliasAttr aattr, std::string otherAlias, std::string otherAttribute) {
		if (joins.back()->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		joins.back()->addForeignKeyConstraint(aattr.attr, otherAlias, otherAttribute);
	    }
	    void constrain (AliasAttr aattr, std::string value) {
		if (joins.back()->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		joins.back()->addConstantConstraint(aattr.attr, value);
	    }
	    void constrain (AliasAttr aattr, int value) {
		if (joins.back()->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		joins.back()->addConstantConstraint(aattr.attr, value);
	    }
	};

	class SQLDisjoint;
	class SQLUnion : public SQLQuery {
	    std::vector<SQLDisjoint*> disjoints;
	public:
	    SQLUnion (SQLQuery* parent) : SQLQuery(parent) {  }
	    virtual ~SQLUnion () {
		for (std::vector<SQLDisjoint*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it)
		    delete *it;
	    }
	    virtual std::string toString () {
		std::stringstream s;
		for (std::vector<SQLDisjoint*>::iterator it = disjoints.begin();
		     it != disjoints.end(); ++it) {
		    if (it != disjoints.begin())
			s << std::endl << "UNION" << std::endl;
		    s << (*it)->toString();
		}
		return s.str();
	    }
	    SQLDisjoint* makeDisjoint () {
		SQLDisjoint* ret = new SQLDisjoint(this);
		disjoints.push_back(ret);
		return ret;
	    }
	};

	class SQLDisjoint : public SQLQuery {
	    SQLUnion* partOf;
	public:
	    SQLDisjoint (SQLUnion* partOf) : SQLQuery(NULL), partOf(partOf) {  }
	};

	int resolve (std::string crack, std::string* relation, std::string* attribute, int* value) {
	    std::string valueS;

	    char delim[]={'.','=',' '};
	    std::string *strings[] = {relation, attribute, &valueS};
	    if (crack.compare(0, stem.size(), stem) != 0)
		throw(std::runtime_error(__PRETTY_FUNCTION__));

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
	AliasAttr getPKAttr (std::string alias) { AliasAttr ret = {alias, "id"}; return ret; }

	std::string stem;
	/*	AliasContext* curAliases; */
	enum {MODE_outside, MODE_subject, MODE_predicate, MODE_object, MODE_selectVar, MODE_overrun} mode;
	SQLQuery* curQuery;
	POS* curSubject;
	AliasAttr curAliasAttr;
	TableOperation* curTableOperation;
	std::string subjectRelation, predicateRelation;
	Consequents* consequentsP;

	std::stringstream ret;
	typedef enum {PREC_Low, PREC_Or = PREC_Low, 
		      PREC_And, 
		      PREC_EQ, PREC_NE, PREC_LT, PREC_GT, PREC_LE, PREC_GE, 
		      PREC_Plus, PREC_Minus, 
		      PREC_Times, PREC_Divide, 
		      PREC_Not, PREC_Pos, PREC_Neg, PREC_High = PREC_Neg} e_PREC;
	const char* tab;
	size_t depth;
	std::stack<e_PREC> precStack;
	void start (e_PREC prec) {
	    if (prec < precStack.top())
		ret << "( ";
	    precStack.push(prec);
	}
	void end () {
	    e_PREC prec = precStack.top();
	    precStack.pop();
	    if (prec < precStack.top())
		ret << ")";
	}
	void lead () {
	    for (size_t i = 0; i < depth; i++)
		ret << tab;
	}
	void lead (size_t p_depth) {
	    for (size_t i = 0; i < p_depth; i++)
		ret << tab;
	}
    public:
	SQLizer (std::string stem, const char* p_tab = "  ") : stem(stem), /*curAliases(NULL),*/ mode(MODE_outside), tab(p_tab), depth(0), precStack() { precStack.push(PREC_High); }
	std::string getSPARQLstring () { return ret.str(); }
	//!!!
	virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual URI* uri (std::string terminal) {
	    MARK;
	    std::string relation, attribute;
	    int value;
	    int parms = resolve(terminal, &relation, &attribute, &value);

	    switch (mode) {

	    case MODE_predicate:
		NOW("URI as predicate");
		if (parms != 2) FAIL("malformed predicate");
		curAliasAttr.alias = curQuery->attachTuple(curSubject, relation, attribute);
		curAliasAttr.attr = attribute;
		predicateRelation = relation;
		break;

	    case MODE_subject:
		NOW("URI as subject");
		if (parms != 3) FAIL("incomplete key");
		if (predicateRelation != relation)
		    std::cerr << "!Subject relation is " << relation << " while predicate relation is " << predicateRelation << std::endl;
		curQuery->constrain(getPKAttr(curAliasAttr.alias), value);
		break;

	    case MODE_object:
		NOW("URI as object");
		if (parms != 3) FAIL("incomplete key");
		curQuery->constrain(curAliasAttr, value);
		break;

	    default:
		FAIL("wierd state");
	    }
	    ret << '<' << terminal << '>';
	    return NULL;
	}
	virtual Variable* variable (std::string terminal) {

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

	    default:
		FAIL("wierd state");
	    }
	    ret << '?' << terminal;
	    return NULL;
	}
	virtual BNode* bnode (std::string terminal) {

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

	    default:
		FAIL("wierd state");
	    }
	    ret << "_:" << terminal; // rewrite when combining named BNodes from multiple docs?
	    return NULL;
	}
	virtual RDFLiteral* rdfLiteral (std::string terminal, w3c_sw::URI* datatype, w3c_sw::LANGTAG* p_LANGTAG) {
	    ret << '"' << terminal << '"';
	    if (datatype != NULL) { ret << "^^<" << datatype->getTerminal() << '>'; }
	    if (p_LANGTAG != NULL) { ret << '@' << p_LANGTAG->getTerminal(); }
	    ret << ' ';
	    return NULL;
	}
	virtual NumericRDFLiteral* rdfLiteral (int p_value) {
	    ret << p_value << ' ';
	    return NULL;
	}
	virtual NumericRDFLiteral* rdfLiteral (float p_value) {
	    ret << p_value << ' ';
	    return NULL;
	}
	virtual NumericRDFLiteral* rdfLiteral (double p_value) {
	    ret << p_value << ' ';
	    return NULL;
	}
	virtual BooleanRDFLiteral* rdfLiteral (bool p_value) {
	    ret << (p_value ? "true" : "false") << ' ';
	    return NULL;
	}
	virtual NULLpos* nullpos () {
	    ret << "NULL ";
	    return NULL;
	}
	virtual TriplePattern* triplePattern (w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) {
	    lead();

	    curSubject = p_s;
	    START("checking predicate");
	    mode = MODE_predicate;
	    p_p->express(this);
	    ret << ' ';

	    NOW("checking subject");
	    mode = MODE_subject;
	    p_s->express(this);
	    ret << ' ';


	    NOW("checking object");
	    mode = MODE_object;
	    p_o->express(this);
	    ret << " ." << std::endl;

	    mode = MODE_outside;
	    return NULL;
	}
	virtual Filter* filter (w3c_sw::Expression* p_Constraint) {
	    lead();
	    ret << "FILTER ";
	    p_Constraint->express(this);
	    ret << std::endl;
	    return NULL;
	}
	void _BasicGraphPattern (ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	    lead();
	    ret << '{' << std::endl;
	    depth++;
	    MARK;
	    p_TriplePatterns->express(this);
	    p_Filters->express(this);
	    depth--;
	    lead();
	    ret << '}' << std::endl;
	}
	virtual NamedGraphPattern* namedGraphPattern (w3c_sw::POS*, bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	    MARK;
	    _BasicGraphPattern(p_TriplePatterns, p_Filters);
	    return NULL;
	}
	virtual DefaultGraphPattern* defaultGraphPattern (bool /*p_allOpts*/, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	    MARK;
	    _BasicGraphPattern(p_TriplePatterns, p_Filters);
	    return NULL;
	}
	virtual TableDisjunction* tableDisjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	    lead();
	    ret << '{' << std::endl;
	    depth++;
	    SQLQuery* parent = curQuery;
	    SQLUnion* disjunction = parent->makeUnion();
	    for (size_t i = 0; i < p_TableOperations->size(); i++) {
		MARK;
		curQuery = disjunction->makeDisjoint();
		curTableOperation = p_TableOperations->at(i);
		curTableOperation->express(this);
		if (i < p_TableOperations->size() - 1) {
		    lead(depth - 1);
		    ret << "UNION" << std::endl;
		}
	    }
	    p_Filters->express(this);
	    curQuery = parent;
	    depth--;
	    lead();
	    ret << '}' << std::endl;
	    return NULL;
	}
	virtual TableConjunction* tableConjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	    lead();
	    ret << '{' << std::endl;
	    depth++;
	    MARK;
	    for (size_t i = 0; i < p_TableOperations->size(); i++) {
		MARK;
		curTableOperation = p_TableOperations->at(i);
		curTableOperation->express(this);
	    }
	    p_Filters->express(this);
	    depth--;
	    lead();
	    ret << '}' << std::endl;
	    return NULL;
	}
	virtual OptionalGraphPattern* optionalGraphPattern (w3c_sw::TableOperation* p_GroupGraphPattern) {
	    lead();
	    ret << "OPTIONAL ";
	    depth++;
	    MARK;
	    curTableOperation = p_GroupGraphPattern; 
	    curTableOperation->express(this);
	    depth--;
	    return NULL;
	}
	virtual GraphGraphPattern* graphGraphPattern (w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
	    lead();
	    ret << "GRAPH ";
	    FAIL("don't know how to deal with GraphGraphPatterns yet");
	    p_POS->express(this);
	    ret << std::endl;
	    depth++;
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	    depth--;
	    return NULL;
	}
	virtual POSList* posList (ProductionVector<w3c_sw::POS*>* p_POSs) {
	    for (size_t i = 0; i < p_POSs->size(); i++) {
		p_POSs->at(i)->express(this);
		ret << ' ';
	    }
	    return NULL;
	}
	virtual StarVarSet* starVarSet () {
	    ret << "* ";
	    return NULL;
	}
	virtual DefaultGraphClause* defaultGraphClause (w3c_sw::POS* p_IRIref) {
	    ret << "FROM ";
	    p_IRIref->express(this);
	    return NULL;
	}
	virtual NamedGraphClause* namedGraphClause (w3c_sw::POS* p_IRIref) {
	    ret << "FROM NAMED ";
	    p_IRIref->express(this);
	    return NULL;
	}
	virtual SolutionModifier* solutionModifier (std::vector<w3c_sw::s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	    if (p_limit != LIMIT_None) ret << "LIMIT " << p_limit;
	    if (p_offset != OFFSET_None) ret << "OFFSET " << p_offset;
	    if (p_OrderConditions) {
		ret << "ORDER BY ";
		for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		    if (p_OrderConditions->at(i).ascOrDesc == w3c_sw::ORDER_Desc) ret << "DESC ";
		    p_OrderConditions->at(i).expression->express(this);
		}
	    }
	    return NULL;
	}
	virtual Binding* binding (ProductionVector<w3c_sw::POS*>* values) {//!!!
	    ret << "  { ";
	    for (size_t i = 0; i < values->size(); i++)
		values->at(i)->express(this);
	    ret << ')' << std::endl;
	    return NULL;
	}
	virtual BindingClause* bindingClause (w3c_sw::POSList* p_Vars, ProductionVector<w3c_sw::Binding*>* p_Bindings) {
	    ret << "BINDINGS ";
	    p_Vars->express(this);
	    ret << '{' << std::endl; //!!!
	    p_Bindings->ProductionVector<w3c_sw::Binding*>::express(this);
	    ret << '}' << std::endl;
	    return NULL;
	}
	virtual WhereClause* whereClause (w3c_sw::TableOperation* p_GroupGraphPattern, w3c_sw::BindingClause* p_BindingClause) {
	    ret << "WHERE" << std::endl;
	    START("p_GroupGraphPattern");
	    Consequents consequents(p_GroupGraphPattern);
	    consequentsP = &consequents;
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	    if (p_BindingClause) p_BindingClause->express(this);
	    return NULL;
	}
	virtual Select* select (w3c_sw::e_distinctness p_distinctness, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	    ret << "SELECT ";
	    START("cracking select clause");
	    SQLQuery root(NULL); // @@@ save for future use
	    curQuery = &root;
	    if (p_distinctness == w3c_sw::DIST_distinct) curQuery->setDistinct(true);
	    //if (p_distinctness == w3c_sw::DIST_reduced) ...
	    if (p_DatasetClauses->size() > 0) FAIL("don't know what to do with DatasetClauses");
	    ret << std::endl;
	    lead();
	    NOW("p_WhereClause");
	    p_WhereClause->express(this);
	    //p_SolutionModifier->express(this);
	    mode = MODE_selectVar;
	    p_VarSet->express(this);
	    ret << curQuery->toString();
	    return NULL;
	}
	virtual Construct* construct (w3c_sw::DefaultGraphPattern* p_ConstructTemplate, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	    ret << "CONSTRUCT ";
	    p_ConstructTemplate->express(this);
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    return NULL;
	}
	virtual Describe* describe (w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	    ret << "DESCRIBE ";
	    p_VarSet->express(this);
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	    return NULL;
	}
	virtual Ask* ask (ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause) {
	    ret << "ASK ";
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    return NULL;
	}
	virtual Replace* replace (w3c_sw::WhereClause* p_WhereClause, w3c_sw::TableOperation* p_GraphTemplate) {
	    ret << "REPLACE ";
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	    return NULL;
	}
	virtual Insert* insert (w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	    ret << "INSERT { ";
	    p_GraphTemplate->express(this);
	    if (p_WhereClause) p_WhereClause->express(this);
	    ret << "}" << std::endl;
	    return NULL;
	}
	virtual Delete* del (w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	    ret << "DELETE";
	    p_GraphTemplate->express(this);
	    p_WhereClause->express(this);
	    return NULL;
	}
	virtual Load* load (ProductionVector<w3c_sw::URI*>* p_IRIrefs, w3c_sw::URI* p_into) {
	    ret << "LOAD ";
	    p_IRIrefs->express(this);
	    p_into->express(this);
	    return NULL;
	}
	virtual Clear* clear (w3c_sw::URI* p__QGraphIRI_E_Opt) {
	    ret << "CLEAR ";
	    p__QGraphIRI_E_Opt->express(this);
	    return NULL;
	}
	virtual Create* create (w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) {
	    ret << "CREATE ";
	    if (p_Silence != w3c_sw::SILENT_Yes) ret << "SILENT";
	    p_GraphIRI->express(this);
	    return NULL;
	}
	virtual Drop* drop (w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) {
	    ret << "DROP ";
	    if (p_Silence != w3c_sw::SILENT_Yes) ret << "SILENT";
	    p_GraphIRI->express(this);
	    return NULL;
	}
	virtual VarExpression* varExpression (w3c_sw::Variable* p_Variable) {
	    p_Variable->express(this);
	    return NULL;
	}
	virtual LiteralExpression* literalExpression (w3c_sw::RDFLiteral* p_RDFLiteral) {
	    p_RDFLiteral->express(this);
	    return NULL;
	}
	virtual BooleanExpression* booleanExpression (w3c_sw::BooleanRDFLiteral* p_BooleanRDFLiteral) {
	    p_BooleanRDFLiteral->express(this);
	    return NULL;
	}
	virtual URIExpression* uriExpression (w3c_sw::URI* p_URI) {
	    p_URI->express(this);
	    return NULL;
	}
	virtual ArgList* argList (ProductionVector<w3c_sw::Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	    p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
	    return NULL;
	}
	virtual FunctionCall* functionCall (w3c_sw::URI* p_IRIref, w3c_sw::ArgList* p_ArgList) {
	    p_IRIref->express(this);
	    ret << "(";
	    p_ArgList->express(this);
	    ret << ")";
	    return NULL;
	}
	virtual FunctionCallExpression* functionCallExpression (w3c_sw::FunctionCall* p_FunctionCall) {
	    p_FunctionCall->express(this);
	    return NULL;
	}
	/* Expressions */
	virtual BooleanNegation* booleanNegation (w3c_sw::Expression* p_Expression) {
	    start(PREC_Not);
	    ret << '!';
	    p_Expression->express(this);
	    end();
	    return NULL;
	}
	virtual ArithmeticNegation* arithmeticNegation (w3c_sw::Expression* p_Expression) {
	    start(PREC_Neg);
	    ret << "- ";
	    p_Expression->express(this);
	    end();
	    return NULL;
	}
	virtual ArithmeticInverse* arithmeticInverse (w3c_sw::Expression* p_Expression) {
	    start(PREC_Divide);
	    ret << "1/";
	    p_Expression->express(this);
	    end();
	    return NULL;
	}
	virtual BooleanConjunction* booleanConjunction (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	    start(PREC_And);
	    for (size_t i = 0; i < p_Expressions->size(); i++) {
		p_Expressions->at(i)->express(this);
		if (i < p_Expressions->size() - 1)
		    ret << " && ";
	    }
	    end();
	    return NULL;
	}
	virtual BooleanDisjunction* booleanDisjunction (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	    start(PREC_Or);
	    for (size_t i = 0; i < p_Expressions->size(); i++) {
		p_Expressions->at(i)->express(this);
		if (i < p_Expressions->size() - 1)
		    ret << " || ";
	    }
	    end();
	    return NULL;
	}
	virtual ArithmeticSum* arithmeticSum (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	    start(PREC_Plus);
	    for (size_t i = 0; i < p_Expressions->size(); i++) {
		p_Expressions->at(i)->express(this);
		if (i < p_Expressions->size() - 1)
		    ret << " + ";
	    }
	    end();
	    return NULL;
	}
	virtual ArithmeticProduct* arithmeticProduct (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	    start(PREC_Times);
	    for (size_t i = 0; i < p_Expressions->size(); i++) {
		p_Expressions->at(i)->express(this);
		if (i < p_Expressions->size() - 1)
		    ret << " * ";
	    }
	    end();
	    return NULL;
	}
	virtual BooleanEQ* booleanEQ (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	    start(PREC_EQ);
	    p_left->express(this);
	    ret << " = ";
	    p_right->express(this);
	    end();
	    return NULL;
	}
	virtual BooleanNE* booleanNE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	    start(PREC_NE);
	    p_left->express(this);
	    ret << " != ";
	    p_right->express(this);
	    end();
	    return NULL;
	}
	virtual BooleanLT* booleanLT (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	    start(PREC_LT);
	    p_left->express(this);
	    ret << " < ";
	    p_right->express(this);
	    end();
	    return NULL;
	}
	virtual BooleanGT* booleanGT (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	    start(PREC_GT);
	    p_left->express(this);
	    ret << " > ";
	    p_right->express(this);
	    end();
	    return NULL;
	}
	virtual BooleanLE* booleanLE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	    start(PREC_LE);
	    p_left->express(this);
	    ret << " <= ";
	    p_right->express(this);
	    end();
	    return NULL;
	}
	virtual BooleanGE* booleanGE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	    start(PREC_GE);
	    p_left->express(this);
	    ret << " >= ";
	    p_right->express(this);
	    end();
	    return NULL;
	}
	virtual ComparatorExpression* comparatorExpression (w3c_sw::BooleanComparator* p_BooleanComparator) {
	    p_BooleanComparator->express(this);
	    return NULL;
	}
	virtual NumberExpression* numberExpression (w3c_sw::NumericRDFLiteral* p_NumericRDFLiteral) {
	    p_NumericRDFLiteral->express(this);
	    return NULL;
	}
    };

} // namespace w3c_sw

#endif // SQLizer_H

