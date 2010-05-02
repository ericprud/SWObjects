/* SQLizer.hpp - simple SPARQL serializer for SPARQL compile trees.
 *
 * $Id: SQLizer.hpp,v 1.42 2008-11-16 13:50:59 eric Exp $
 */

#ifndef SQLizer_H
#define SQLizer_H

#include <cstdlib>
#include <limits>
#include <map>
#include "exs.hpp"
#include "POS2BGPMap.hpp"
#include "SPARQLSerializer.hpp"
#include "SQL.hpp"


namespace w3c_sw {

    using namespace w3c_sw::sql;

    class SQLizer : public Expressor {

	class SQLOptionalGenerator;
	class SQLUnionGenerator;
	class SQLQueryGenerator {
	    friend class SQLizer;
            friend class SQLUnionGenerator;
	protected:
	    SQLQuery query;
	    SQLQueryGenerator* parent;
	    std::map<std::string, sql::Expression*> attachments;

	    std::map<const POS*, std::map<std::string, Join*> > aliasMap;
	    std::set<std::string> usedAliases;
	    Join* curJoin;
	    int nextUnionAlias;
	    int nextOptAlias;

	public:
	    SQLQueryGenerator (SQLQueryGenerator* parent) : parent(parent), nextUnionAlias(0), nextOptAlias(0) {  }
	    ~SQLQueryGenerator () {  }
	    void attachVariable (AliasAttr aattr, std::string lexicalValue) {
		std::map<std::string, sql::Expression*>::iterator it = attachments.find(lexicalValue);
		if (it == attachments.end())
		    attachments[lexicalValue] = new AliasAttrConstraint(aattr);
		else
		    constrain(aattr, dynamic_cast<AliasAttrConstraint*>(attachments[lexicalValue])->aattr);
	    }
	    sql::Expression* getVariableConstraint (std::string lexicalValue) {
		std::map<std::string, sql::Expression*>::iterator it = attachments.find(lexicalValue);
		if (it == attachments.end())
		    FAIL1("can't find variable \"%s\"", lexicalValue.c_str());
		else
		    return it->second;
	    }
	    void selectVariable (std::string lexicalValue) {
		if (attachments.find(lexicalValue) == attachments.end())
		    attachments[lexicalValue] = new ReallyNullConstraint();
		//std::cerr << "selectVariable " << lexicalValue << " attached to " << attachments[lexicalValue]->toString() << std::endl;
		query.selects.push_back(new AliasedSelect(attachments[lexicalValue], lexicalValue));
	    }
	    void selectConstant (int value, std::string alias) {
		if (attachments.find(alias) == attachments.end())
		    attachments[alias] = new IntConstraint(value);
		//std::cerr << "selectVariable " << lexicalValue << " attached to " << attachments[lexicalValue]->toString() << std::endl;
		query.selects.push_back(new AliasedSelect(attachments[alias], alias));
	    }
	    void selectConstant (float value, std::string alias) {
		if (attachments.find(alias) == attachments.end())
		    attachments[alias] = new FloatConstraint(value);
		//std::cerr << "selectVariable " << lexicalValue << " attached to " << attachments[lexicalValue]->toString() << std::endl;
		query.selects.push_back(new AliasedSelect(attachments[alias], alias));
	    }
	    void selectConstant (double value, std::string alias) {
		if (attachments.find(alias) == attachments.end())
		    attachments[alias] = new DoubleConstraint(value);
		//std::cerr << "selectVariable " << lexicalValue << " attached to " << attachments[lexicalValue]->toString() << std::endl;
		query.selects.push_back(new AliasedSelect(attachments[alias], alias));
	    }
	    /* Always add to the last join unless we figure out a reason this doesn't work. */
	    void constrain (AliasAttr x, AliasAttr y) {
		//std::cerr << "SQLQueryGenerator " << this << " constraint: " << x.alias << "." << x.attr << "=" << y.alias << "." << y.attr << std::endl;
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
		curJoin->addConstantJoinConstraint(aattr.attr, (int)value);
	    }
	    void constrain (AliasAttr aattr, float value) {
		if (curJoin->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		curJoin->addConstantJoinConstraint(aattr.attr, (float)value);
	    }
	    void constrain (AliasAttr aattr, double value) {
		if (curJoin->debug_getAlias() != aattr.alias) FAIL("constraint is not for last join");
		curJoin->addConstantJoinConstraint(aattr.attr, (double)value);
	    }
	    SQLUnionGenerator* makeUnion (std::vector<const POS*> corefs) {
		std::stringstream s;
		s << "union" << ++nextUnionAlias;
		SQLUnionGenerator* ret = new SQLUnionGenerator(this, corefs, s.str());
		curJoin = new SubqueryJoin(&ret->onion, s.str(), false);
		query.joins.push_back(curJoin);
		return ret;
	    }
	    SQLOptionalGenerator* makeOptional (std::vector<const POS*> corefs) {
		std::stringstream s;
		s << "opt" << ++nextOptAlias;
		SQLOptionalGenerator* ret = new SQLOptionalGenerator(this, corefs, s.str());
		curJoin = new SubqueryJoin(&ret->query, s.str(), true);
		query.joins.push_back(curJoin);
		return ret;
	    }
	    std::string attachTuple (const POS* subject, std::string toRelation) {
		std::map<const POS*, std::map<std::string, Join*> >::iterator byPOS = aliasMap.find(subject);
		if (byPOS != aliasMap.end()) {
		    std::map<std::string, Join*>::iterator byRelation = aliasMap[subject].find(toRelation);
		    if (byRelation != aliasMap[subject].end()) {
			curJoin = aliasMap[subject][toRelation];
			return curJoin->debug_getAlias();
		    }
		}

		std::string aliasName = subject->getLexicalValue();
		/* Try to get a good name for URIs.
		 * e.g. http://bsbm.example/db/producttypeproduct/producttype.59
		 *   => producttype_59
		 */
		size_t slash = aliasName.rfind('/');
		if (slash != std::string::npos) {
		    if (slash == aliasName.size()) {
			size_t secondSlash = aliasName.rfind('/', slash);
			if (secondSlash != std::string::npos)
			    slash = secondSlash;
		    }
		    aliasName = aliasName.substr(slash+1);
		    const std::string allowedChars("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");
		    size_t badChar = aliasName.find_first_not_of(allowedChars);
		    while (badChar != std::string::npos) {
			aliasName.replace(badChar, 1, 1, '_');
			badChar = aliasName.find_first_not_of(allowedChars, badChar+1);
		    }
		}

		unsigned ordinal = 0;
		while (usedAliases.find(aliasName) != usedAliases.end()) {
		    std::stringstream s;
		    s << subject->getLexicalValue() << "_" << ++ordinal;
		    aliasName = s.str();
		}
		curJoin = new TableJoin(toRelation, aliasName, false);
		query.joins.push_back(curJoin);
		usedAliases.insert(aliasName);
		//std::cerr << "SQLQuery " << this << ": attachTuple: " << subject->getLexicalValue() << " bound to " << toRelation << " bound to " << aliasName << std::endl;
		aliasMap[subject][toRelation] = curJoin;
		return aliasName;
	    }
	    void addConstraint (WhereConstraint* constraint) { query.constraints.push_back(constraint); }
	    void addOrderClause (WhereConstraint* constraint) { query.orderBy.push_back(constraint); }
	    void setDistinct (bool state = true) { query.distinct = state; }
	    void setLimit (int limit) { query.limit = limit; }
	    void setOffset (int offset) { query.offset = offset; }
	};

	class SQLOptionalGenerator : public SQLQueryGenerator {
	    std::vector<const POS*> corefs;
	    std::string name;
	public:
	    SQLOptionalGenerator (SQLQueryGenerator* parent, std::vector<const POS*> corefs, std::string name) : 
		SQLQueryGenerator(parent), corefs(corefs), name(name)
	    {  }
	    virtual ~SQLOptionalGenerator () {  }
	    void attach () {
		for (std::vector<const POS*>::iterator coref = corefs.begin();
		     coref != corefs.end(); ++coref) {
		    // SELECT <field for coref> AS <coref name>
		    selectVariable((*coref)->getLexicalValue());
		    // ON <name>.<coref name> = <parent's field for coref>
		    parent->attachVariable(AliasAttr(name, (*coref)->getLexicalValue()), (*coref)->getLexicalValue());
		}
	    }
// 	    virtual std::string toString (std::string pad = "") {
// 		std::string newPad = pad + "    ";
// 		return SQLQueryGenerator::toString(newPad);
// 	    }
	};

	class SQLDisjointGenerator : public SQLQueryGenerator {
// 	public:
// 	    SQLDisjoint disjoint;
	    // SQLUnionGenerator* partOf;
	public:
	    SQLDisjointGenerator (SQLUnionGenerator* parent) : SQLQueryGenerator(parent) {  }
	};

	class SQLUnionGenerator : public SQLQueryGenerator {
	    friend class SQLizer;
            friend class SQLQueryGenerator;
	protected:
	    SQLUnion onion;
	    // SQLQueryGenerator* parent;
	    std::vector<const POS*> corefs;
	    std::string name;
	    std::vector<SQLDisjointGenerator*> disjointGenerators;
	public:
	    SQLUnionGenerator (SQLQueryGenerator* parent, std::vector<const POS*> corefs, std::string name) : 
		SQLQueryGenerator(parent), corefs(corefs), name(name)
	    {  }
            // std::string toString () {
            //     std::stringstream ss;
            //     ss << "Union " << name << " corefs: " << corefs;
            //     return ss.str() + std::endl;
            // }
	    void attach () {
		unsigned nextDisjointCardinal = 1;
		for (std::vector<SQLDisjointGenerator*>::iterator dis = disjointGenerators.begin();
		     dis != disjointGenerators.end(); ++dis) {
                    // SQLDisjoint* d = *dis;
                    // SQLQueryGenerator* qg = dynamic_cast<SQLQueryGenerator*>(*dis);
		    (*dis)->selectConstant((int)nextDisjointCardinal++, "_DISJOINT_"); // cast to int to select selectConstant(int...)
                }
		for (std::vector<const POS*>::iterator coref = corefs.begin();
		     coref != corefs.end(); ++coref) {
		    for (std::vector<SQLDisjointGenerator*>::iterator dis = disjointGenerators.begin();
			 dis != disjointGenerators.end(); ++dis)
			// SELECT <field for coref> AS <coref name>
			(*dis)->selectVariable((*coref)->getLexicalValue());
		    // ON <name>.<coref name> = <parent's field for coref>
		    parent->attachVariable(AliasAttr(name, (*coref)->getLexicalValue()), (*coref)->getLexicalValue());
		}
	    }

	    SQLDisjointGenerator* makeDisjoint () {
		SQLDisjointGenerator* ret = new SQLDisjointGenerator(this);
		disjointGenerators.push_back(ret);
		onion.disjoints.push_back(&ret->query);
		return ret;
	    }

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

	    int pos = 0;
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
	AliasAttr getPKAttr (std::string alias) { return AliasAttr(alias, defaultPKAttr); }

	std::string stem;
	/*	AliasContext* curAliases; */
	typedef enum {MODE_outside, MODE_subject, MODE_predicate, MODE_object, MODE_selectVar, MODE_constraint, MODE_overrun} e_Mode;
	e_Mode mode;
	SQLQueryGenerator* curQuery;
	const POS* curSubject;
	AliasAttr curAliasAttr; // established by predicate
	const TableOperation* curTableOperation;
	std::string subjectRelation, predicateRelation;
	Consequents* consequentsP;
	VarSet* selectVars;
	char* predicateDelims;
	char* nodeDelims;
	WhereConstraint* curConstraint;
	std::string defaultPKAttr;

	std::ostream** debugStream;

    public:
	//static std::ostream** ErrorStream;

	SQLizer (std::string stem, char predicateDelims[], char nodeDelims[], std::string defaultPKAttr, std::ostream** debugStream = NULL) : 
	    stem(stem), mode(MODE_outside), curQuery(NULL), curAliasAttr("bogusAlias", "bogusAttr"), selectVars(NULL), 
	    predicateDelims(predicateDelims), nodeDelims(nodeDelims), defaultPKAttr(defaultPKAttr), debugStream(debugStream)
	{  }
	~SQLizer () {  }

	std::string getSQLstring () { return curQuery->query.toString(); }

	virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

	virtual void uri (const URI* const, std::string lexicalValue) {
	    MARK;
	    std::string relation, attribute;
	    int value;

	    switch (mode) {

	    case MODE_predicate:
		NOW("URI as predicate");
		if (resolve(lexicalValue, &relation, &attribute) != 2) FAIL2("malformed predicate \"%s\" didn't match \"%s\"", lexicalValue.c_str(), stem.c_str());
		curAliasAttr.alias = curQuery->attachTuple(curSubject, relation);
		curAliasAttr.attr = attribute;
		predicateRelation = relation;
		break;

	    case MODE_subject:
		NOW("URI as subject");
		if (resolve(lexicalValue, &relation, &attribute, &value) != 3) FAIL("incomplete key");
		if (predicateRelation != relation)
		    std::cerr << "!Subject relation is " << relation << " while predicate relation is " << predicateRelation << std::endl;
		curQuery->constrain(AliasAttr(curAliasAttr.alias, attribute), value);
		break;

	    case MODE_object:
		NOW("URI as object");
		if (resolve(lexicalValue, &relation, &attribute, &value) != 3) FAIL("incomplete key");
		curQuery->constrain(curAliasAttr, value);
		break;

	    case MODE_constraint:
		if (lexicalValue == "http://www.w3.org/2001/XMLSchema#integer" || 
		    lexicalValue == "http://www.w3.org/2001/XMLSchema#decimal" || 
		    lexicalValue == "http://www.w3.org/2001/XMLSchema#float" || 
		    lexicalValue == "http://www.w3.org/2001/XMLSchema#double"  ) {
		} else {
		    FAIL1("URI <%s> as constraint is unimplemented", lexicalValue.c_str());
		}
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void variable (const Variable* const, std::string lexicalValue) {

	    // enforce coreferences
	    switch (mode) {

	    case MODE_subject:
		NOW("Variable as subject");
		curQuery->attachVariable(getPKAttr(curAliasAttr.alias), lexicalValue);
		break;

	    case MODE_predicate:
		FAIL("No variable predicates, please.");
		break;

	    case MODE_object:
		NOW("Variable as object");
		curQuery->attachVariable(curAliasAttr, lexicalValue);
		break;

	    case MODE_selectVar:
		NOW("URI as selectVar");
		curQuery->selectVariable(lexicalValue);
		break;

	    case MODE_constraint:
		NOW("Variable as constraint");
		curConstraint = curQuery->getVariableConstraint(lexicalValue);
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	virtual void bnode (const BNode* const, std::string lexicalValue) {

	    // enforce coreferences
	    switch (mode) {

	    case MODE_subject:
		NOW("Variable as subject");
		curQuery->attachVariable(getPKAttr(curAliasAttr.alias), lexicalValue);
		break;

	    case MODE_predicate:
		FAIL("No variable predicates, please.");
		break;

	    case MODE_object:
		NOW("Variable as object");
		curQuery->attachVariable(curAliasAttr, lexicalValue);
		break;

	    case MODE_selectVar:
		FAIL("no told bnodes");
		break;

	    default:
		FAIL("wierd state");
	    }
	}
	/* Literal Map -- http://www.w3.org/2008/07/MappingRules/#litMap !!! not done */
	virtual void rdfLiteral (const RDFLiteral* const, std::string lexicalValue, const URI* datatype, LANGTAG* p_LANGTAG) {
	    MARK;
	    std::string value = lexicalValue;
	    if (datatype != NULL) {
		if (datatype->getLexicalValue() == "http://www.w3.org/2001/XMLSchema#dateTime")
		    value.replace(value.find("T"), 1, " ");
		/* These have the same lexical value in SQL as in RDF. */
		else if (datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#integer" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#decimal" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#float" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#double" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#string" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#boolean" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#nonPositiveInteger" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#negativeInteger" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#long" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#int" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#short" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#byte" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#nonNegativeInteger" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#unsignedLong" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#unsignedInt" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#unsignedShort" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#unsignedByte" && 
			 datatype->getLexicalValue() != "http://www.w3.org/2001/XMLSchema#positiveInteger" )
		    FAIL1("unknown datatype: <%s>", datatype->getLexicalValue().c_str());
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
	virtual void rdfLiteral (const NumericRDFLiteral* const, int p_value) {
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
	virtual void rdfLiteral (const NumericRDFLiteral* const, float p_value) {
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
	virtual void rdfLiteral (const NumericRDFLiteral* const, double p_value) {
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
	virtual void rdfLiteral (const BooleanRDFLiteral* const, bool p_value) {
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
	virtual void nullpos (const NULLpos* const) {  }
	virtual void triplePattern (const TriplePattern* const, const POS* p_s, const POS* p_p, const POS* p_o) {
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
	virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const w3c_sw::Expression*>* p_Constraints) {
	    p_op->express(this);
	    mode = MODE_constraint;
	    for (std::vector<const w3c_sw::Expression*>::const_iterator it = p_Constraints->begin();
		 it != p_Constraints->end(); ++it)
		try {
		    (*it)->express(this);
		    curQuery->addConstraint(curConstraint);
		} catch (nonLocalIdentifierException& e) {
		    std::cerr << "filter {" << *it << "} is not handled by stem " << stem << " because " << e.what() << std::endl;
		}
	}
	void _BasicGraphPattern (const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    MARK;
	    for (std::vector<const TriplePattern*>::const_iterator tripleIt = p_TriplePatterns->begin();
		 tripleIt != p_TriplePatterns->end(); ++tripleIt)
		try {
		    (*tripleIt)->express(this);
		} catch (nonLocalIdentifierException& e) {
		    std::cerr << "pattern {" << (*tripleIt) << "} is not handled by stem " << stem << " because " << e.what() << std::endl;
		}
	}
	virtual void namedGraphPattern (const NamedGraphPattern* const, const POS* /* p_name */, bool /* p_allOpts */, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    MARK;
	    _BasicGraphPattern(p_TriplePatterns);
	}
	virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool /*p_allOpts*/, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	    MARK;
	    _BasicGraphPattern(p_TriplePatterns);
	}
	virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    SQLQueryGenerator* parent = curQuery;
	    SQLUnionGenerator* disjunction = parent->makeUnion(consequentsP->entriesFor(curTableOperation));
            // std::cout << disjunction->toString();
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); ++it) {
		MARK;
		curQuery = disjunction->makeDisjoint();
		curTableOperation = *it;
		curTableOperation->express(this);
	    }
	    disjunction->attach();
	    curQuery = parent;
	}
	virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	    MARK;
	    for (std::vector<const TableOperation*>::const_iterator it = p_TableOperations->begin();
		 it != p_TableOperations->end(); ++it) {
		MARK;
		curTableOperation = *it;
		curTableOperation->express(this);
	    }
	}
	virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
	    MARK;
	    SQLQueryGenerator* parent = curQuery;
	    //std::cerr << "checking for "<<curTableOperation<<" or "<<p_GroupGraphPattern<<std::endl;
	    SQLOptionalGenerator* optional = parent->makeOptional(consequentsP->entriesFor(curTableOperation));
	    curQuery = optional;
	    curTableOperation = p_GroupGraphPattern; 
	    curTableOperation->express(this);
	    e_Mode oldMode = mode;
	    mode = MODE_constraint;
	    for (std::vector<const w3c_sw::Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it)
		try {
		    (*it)->express(this);
		    curQuery->addConstraint(curConstraint);
		} catch (nonLocalIdentifierException& e) {
		    std::cerr << "filter {" << *it << "} is not handled by stem " << stem << " because " << e.what() << std::endl;
		}
	    mode = oldMode;
	    optional->attach();
	    curQuery = parent;
	}
	virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* /* p_GroupGraphPattern */) {
	    throw(NotImplemented("SQLizer(minusGraphPattern)"));
	}
	virtual void graphGraphPattern (const GraphGraphPattern* const, const POS* p_POS, const TableOperation* p_GroupGraphPattern) {
	    FAIL("don't do federation with GraphGraphPatterns yet");
	    p_POS->express(this);
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	}
	virtual void serviceGraphPattern (const ServiceGraphPattern* const, const POS* p_POS, const TableOperation* p_GroupGraphPattern, POSFactory* /* posFactory */, bool /* lexicalCompare */) {
	    FAIL("don't do federation with ServiceGraphPatterns yet");
	    p_POS->express(this);
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	}
	virtual void expressionAlias (const ExpressionAlias* const, const w3c_sw::Expression* expr, const Bindable* label) {
	    if (label != NULL) {
		NEED_IMPL("SQLizer(ExpressionAliase)");
	    } else
		expr->express(this);
	}
	virtual void expressionAliasList (const ExpressionAliasList* const, const ProductionVector<const w3c_sw::ExpressionAlias*>* p_Expressions) {
	    for (std::vector<const w3c_sw::ExpressionAlias*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it)
		(*it)->express(this);
	}
	virtual void posList (const POSList* const, const ProductionVector<const POS*>* p_POSs) {
	    FAIL("no SQL for POSList");
	}
	virtual void starVarSet (const StarVarSet* const) {
	    FAIL("need to select all pertinent vars");
	}
	virtual void defaultGraphClause (const DefaultGraphClause* const, const POS* p_IRIref) {
	    p_IRIref->express(this);
	}
	virtual void namedGraphClause (const NamedGraphClause* const, const POS* p_IRIref) {
	    p_IRIref->express(this);
	}
	virtual void solutionModifier (const SolutionModifier* const, ExpressionAliasList* groupBy, ProductionVector<const w3c_sw::Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	    IF_IMPL(groupBy != NULL || having != NULL, "SPARQL 1.1 SolutionModifier (groupBy, having)");
	    if (p_limit != LIMIT_None) curQuery->setLimit(p_limit);
	    if (p_offset != OFFSET_None) curQuery->setOffset(p_offset);
	    if (p_OrderConditions)
		for (std::vector<s_OrderConditionPair>::iterator it = p_OrderConditions->begin();
		     it != p_OrderConditions->end(); ++it) {
		    /*bool desc = p_OrderConditions->at(i).ascOrDesc == ORDER_Desc;*/
		    // !!!
		    it->expression->express(this);
		    curQuery->addOrderClause(curConstraint);
		}
	}
	virtual void binding (const Binding* const, const ProductionVector<const POS*>* values) {//!!!
	    // !!!
	    for (std::vector<const POS*>::const_iterator it = values->begin();
		 it != values->end(); ++it)
		(*it)->express(this);
	}
	virtual void bindingClause (const BindingClause* const, POSList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) {
	    p_Vars->express(this);
	    p_Bindings->ProductionVector<const Binding*>::express(this);
	}
	virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	    START("p_GroupGraphPattern");
	    Consequents consequents(p_GroupGraphPattern, selectVars, debugStream);
	    consequentsP = &consequents;
	    curTableOperation = p_GroupGraphPattern;
	    curTableOperation->express(this);
	    if (p_BindingClause) p_BindingClause->express(this);
	}
	virtual void select (const Select* const, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    START("cracking select clause");
	    curQuery = new SQLQueryGenerator(NULL);
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
	virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	    NEED_IMPL("SQLizer(subselect)");
	}
	virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    FAIL("CONSTRUCT");
	    p_ConstructTemplate->express(this);
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	}
	virtual void describe (const Describe* const, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	    FAIL("DESCRIBE");
	    p_VarSet->express(this);
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	    p_SolutionModifier->express(this);
	}
	virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	    FAIL("ASK");
	    p_DatasetClauses->express(this);
	    p_WhereClause->express(this);
	}
	virtual void replace (const Replace* const, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	    FAIL("REPLACE");
	    p_WhereClause->express(this);
	    p_GraphTemplate->express(this);
	}
	virtual void insert (const Insert* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    FAIL("INSERT {");
	    p_GraphTemplate->express(this);
	    if (p_WhereClause) p_WhereClause->express(this);
	}
	virtual void del (const Delete* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	    FAIL("DELET");
	    p_GraphTemplate->express(this);
	    p_WhereClause->express(this);
	}
	virtual void load (const Load* const, ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) {
	    FAIL("LOAD");
	    p_IRIrefs->express(this);
	    p_into->express(this);
	}
	virtual void clear (const Clear* const, const URI* p__QGraphIRI_E_Opt) {
	    FAIL("CLEAR");
	    p__QGraphIRI_E_Opt->express(this);
	}
	virtual void create (const Create* const, e_Silence /* p_Silence */, const URI* p_GraphIRI) {
	    FAIL("CREATE");
	    // !!! if (p_Silence != SILENT_Yes) ;
	    p_GraphIRI->express(this);
	}
	virtual void drop (const Drop* const, e_Silence /* p_Silence */, const URI* p_GraphIRI) {
	    // !!! if (p_Silence != SILENT_Yes) ;
	    p_GraphIRI->express(this);
	}
	virtual void posExpression (const POSExpression* const, const POS* p_POS) {
	    MARK;
	    p_POS->express(this);
	}
	virtual void argList (const ArgList* const, ProductionVector<const w3c_sw::Expression*>* expressions) {
	    MARK;
	    expressions->express(this);
	}
	// !!!
	virtual void functionCall (const FunctionCall* const, const URI* iri, const ArgList* args) {
	    MARK;
	    args->express(this);
	    if (iri->getLexicalValue() == "http://www.w3.org/TR/rdf-sparql-query/#func-bound")
		curConstraint = new NullConstraint(curConstraint);
	    else
		iri->express(this);
	}
	virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	    MARK;
	    p_FunctionCall->express(this);
	}
	/* Expressions */
	virtual void booleanNegation (const w3c_sw::BooleanNegation* const, const w3c_sw::Expression* p_Expression) {
	    MARK;
	    p_Expression->express(this);
	    curConstraint = new NegationConstraint(curConstraint);
	}
	virtual void arithmeticNegation (const w3c_sw::ArithmeticNegation* const, const w3c_sw::Expression* p_Expression) {
	    MARK;
	    p_Expression->express(this);
	}
	virtual void arithmeticInverse (const w3c_sw::ArithmeticInverse* const, const w3c_sw::Expression* p_Expression) {
	    MARK;
	    p_Expression->express(this);
	}
	virtual void booleanConjunction (const w3c_sw::BooleanConjunction* const, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
	    MARK;
	    ConjunctionConstraint* conj = new ConjunctionConstraint();
	    for (std::vector<const w3c_sw::Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it) {
		(*it)->express(this);
		conj->addConstraint(curConstraint);
	    }
	    curConstraint = conj;
	}
	virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
	    MARK;
	    DisjunctionConstraint* disj = new DisjunctionConstraint();
	    for (std::vector<const w3c_sw::Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it) {
		(*it)->express(this);
		disj->addConstraint(curConstraint);
	    }
	    curConstraint = disj;
	}
	void _arithOp (std::string sqlOperator, const ProductionVector<const w3c_sw::Expression*>* p_Expressions, e_PREC prec) {
	    ArithOperation* c = new ArithOperation(sqlOperator, prec);
	    for (std::vector<const w3c_sw::Expression*>::const_iterator it = p_Expressions->begin();
		 it != p_Expressions->end(); ++it) {
		(*it)->express(this);
		c->push_back(curConstraint);
	    }
	    curConstraint = c;
	}
	virtual void arithmeticSum (const w3c_sw::ArithmeticSum* const, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
	    MARK;
	    _arithOp("+", p_Expressions, PREC_Plus);
	}
	virtual void arithmeticProduct (const w3c_sw::ArithmeticProduct* const, const ProductionVector<const w3c_sw::Expression*>* p_Expressions) {
	    MARK;
	    _arithOp("*", p_Expressions, PREC_Times);
	}
	void _boolConstraint (const w3c_sw::Expression* p_left, std::string sqlOperator, const w3c_sw::Expression* p_right, e_PREC prec) {
	    ArithOperation* c = new ArithOperation(sqlOperator, prec);
	    p_left->express(this);
	    c->push_back(curConstraint);
	    p_right->express(this);
	    c->push_back(curConstraint);
	    curConstraint = c;
	}
	virtual void booleanEQ (const w3c_sw::BooleanEQ* const, const w3c_sw::Expression* p_left, const w3c_sw::Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "=", p_right, PREC_EQ);
	}
	virtual void booleanNE (const w3c_sw::BooleanNE* const, const w3c_sw::Expression* p_left, const w3c_sw::Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "!=", p_right, PREC_NE);
	}
	virtual void booleanLT (const w3c_sw::BooleanLT* const, const w3c_sw::Expression* p_left, const w3c_sw::Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "<", p_right, PREC_LT);
	}
	virtual void booleanGT (const w3c_sw::BooleanGT* const, const w3c_sw::Expression* p_left, const w3c_sw::Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, ">", p_right, PREC_GT);
	}
	virtual void booleanLE (const w3c_sw::BooleanLE* const, const w3c_sw::Expression* p_left, const w3c_sw::Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, "<=", p_right, PREC_LE);
	}
	virtual void booleanGE (const w3c_sw::BooleanGE* const, const w3c_sw::Expression* p_left, const w3c_sw::Expression* p_right) {
	    MARK;
	    _boolConstraint(p_left, ">=", p_right, PREC_GE);
	}
	virtual void comparatorExpression (const w3c_sw::ComparatorExpression* const, const w3c_sw::BooleanComparator* p_BooleanComparator) {
	    MARK;
	    p_BooleanComparator->express(this);
	}
	virtual void numberExpression (const w3c_sw::NumberExpression* const, const NumericRDFLiteral* p_NumericRDFLiteral) {
	    MARK;
	    p_NumericRDFLiteral->express(this);
	}
    };

} // namespace w3c_sw

#endif // SQLizer_H

