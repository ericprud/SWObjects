/**
 *
 */

#include <iostream>
#include "SQL.hpp"
#include "SQLParser/SQLParser.hpp"
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#define NEEDDEF_W3C_SW_SQLCLIENT
#include "interface/SQLclient_MySQL.hpp"

using namespace w3c_sw;
AtomFactory atomFactory;

void dump(SQLclient& sqlDriver, std::string cmd);

struct Materializer {
    typedef std::map<std::string, const TTerm*> TableRowNodes;
    typedef std::map<sql::RelationName, TableRowNodes> RowNodes;
    SQLclient& sqlDriver;
    const char* Quote;
    size_t nextTableAlias, nextAttrAlias;

    Materializer (SQLclient& sqlDriver)
	: sqlDriver(sqlDriver), Quote("`"), nextTableAlias(0), nextAttrAlias(0)
    {  }
    void operator() (sql::schema::Database& db, DefaultGraphPattern* bgp) {
	RowNodes rowNodes;
	std::vector<sql::schema::Relation*> orderedTables;
	for (sql::schema::Database::const_iterator it = db.begin();
	     it != db.end(); ++it)
	    orderedTables.push_back(it->second);

	for (std::vector<sql::schema::Relation*>::const_iterator it = orderedTables.begin();
	     it != orderedTables.end(); ++it) {
	    sql::schema::Relation& table = **it;
	    dumpTable(table, db, rowNodes, sqlDriver, atomFactory, bgp);
	}
    }
    static std::string replace (std::string replaceMe, char from, const char* to) {
	for (size_t i = 0; i < replaceMe.size(); ++i)
	    if (replaceMe[i] == from)
		replaceMe.replace(i, 1, to);
	return replaceMe;
    }

    static std::string IRIsafe (std::string s) {
	const unsigned char* segment = (unsigned char*) s.c_str();
	const size_t size = s.size();
	std::string ret;
	// pecent-encode everything outside of rfc3987:iunreserved.
	// iunreserved = ALPHA / DIGIT / "-" / "." / "_" / "~" / ucschar
	//               41-5a,61-7a / 30-39 / 2d / 2e / 5f / 7e / >7f
	for (size_t i = 0; i < size; ++i) {
	    if (!((segment[i] >= 0x41 && segment[i] <= 0x5a) ||
		  (segment[i] >= 0x61 && segment[i] <= 0x7a) ||
		  (segment[i] >= 0x30 && segment[i] <= 0x39) ||
		  (segment[i] == 0x2d) ||
		  (segment[i] == 0x2e) ||
		  (segment[i] == 0x5f) ||
		  (segment[i] == 0x7e) ||
		  (segment[i] >  0x7f))) {
		std::stringstream ss;
		ss << '%' << std::hex << (int)segment[i];
		ret += ss.str();
	    } else {
		ret += segment[i];
	    }
	}
	return ret;
    }

    static std::string attrname (std::string name) {
	name = IRIsafe(name);
	name = replace(name, '-', "%3D");
	return name;
    }

    static std::string attrvalue (std::string value) {
	value = IRIsafe(value);
	value = replace(value, '.', "%2E");
	return value;
    }

    std::string newTableAlias () {
	std::stringstream ss;
	ss << "_" << nextTableAlias++;
	return ss.str();
    }

    std::string newAttrAlias () {
	std::stringstream ss;
	ss << "_" << nextAttrAlias++;
	return ss.str();
    }

    struct PkCols : std::vector<size_t> {
	void resize (size_t s) {
	    std::vector<size_t>::resize(s);
	}
    };

    struct LiteralAttribute {
	size_t colNo;
	const TTerm* p;
	LiteralAttribute (size_t colNo, const TTerm* p)
	    : colNo(colNo), p(p)
	{  }
    };

    struct ReferenceAttribute {
	std::string p;
	sql::RelationName targetRel;
	std::vector<size_t>  colNos;
	std::vector<std::string> safeNames;
	ReferenceAttribute (std::string tableName, sql::RelationName targetRel) : p(tableName + "#ref-"), targetRel(targetRel) {  }
	void insert(size_t colNo, std::string fromAttr, std::string toAttr) {
	    if (colNos.size() > 0)
		p += ".";
	    p += IRIsafe(fromAttr);
	    colNos.push_back(colNo);
	    safeNames.push_back(attrname(toAttr));
	}
	size_t size () const { return colNos.size(); }
    };

    void dumpTable (sql::schema::Relation& table, sql::schema::Database& db, RowNodes& rowNodes, SQLclient& sqlDriver, AtomFactory& atomFactory, DefaultGraphPattern* bgp) {

	std::string thisTableAlias = newTableAlias();
	// w3c_sw_LINEN << table << "\n";
	std::stringstream selects;
	selects << "SELECT ";
	std::stringstream joins;

	/* fixup for various DBs */
	size_t colNo = 0;
	SQLclient::Result::Fixups fixups;
	// std::vector<boost::shared_ptr<SQLclient::Result::Fixup> > holder;

	PkCols pkCols;
	if (table.primaryKey != NULL)
	    pkCols.resize(table.primaryKey->size());
	std::vector<LiteralAttribute> literalAttributes;
	for (sql::schema::Relation::Fields::const_iterator it = table.fields.begin();
	     it != table.fields.end(); ++it) {
	    std::string attrAlias = newAttrAlias();
	    const TTerm* p = atomFactory.getURI(IRIsafe(table.name) + "#" + IRIsafe(it->second.name));
	    literalAttributes.push_back(LiteralAttribute(colNo, p));
	    if (table.primaryKey != NULL)
		for (size_t i = 0; i < table.primaryKey->size(); ++i)
		    if (it->second.name == table.primaryKey->at(i))
			pkCols[i] = colNo;
	    if (it != table.fields.begin())
		selects << ", ";
	    selects << thisTableAlias << "." << Quote << it->second.name << Quote
		// << " AS " << attrAlias
		;


#ifdef W3C_SW_MYSQL_SQLCLIENT // MySQL doesn't preserve trailing spaces on CHAR(n)
	    if (it->second.type == sql::TYPE_binary)
		fixups.insert(colNo, new SQLclient_MySQL::Result::LiteralToBinary());
	    // w3c_sw_LINEN << "rewrite " << colNo << " to base64\n";

	    if (it->second.type == sql::TYPE_boolean)
		fixups.insert(colNo, new SQLclient_MySQL::Result::IntToBoolean());
	    // w3c_sw_LINEN << "rewrite " << colNo << " to boolean\n";

	    if (it->second.type == sql::TYPE_char &&
		it->second.precision != SQL_PRECISION_unspecified)
		fixups.insert(colNo, new SQLclient_MySQL::Result::CharTrailingChars(it->second.precision));
#endif /* W3C_SW_MYSQL_SQLCLIENT */

	    ++colNo;
	}
	joins << " FROM " << Quote << table.name << Quote << " AS " << thisTableAlias;

	std::vector<ReferenceAttribute> referenceAttributes;
	for (std::vector<const sql::schema::FieldOrKey*>::iterator it = table.orderedFields.begin();
	     it != table.orderedFields.end(); ++it) {
	    const sql::schema::ForeignKey* fk = dynamic_cast<const sql::schema::ForeignKey*>(*it);
	    if (fk != NULL) {
		ReferenceAttribute queuedAttr(IRIsafe(table.name), fk->targetRel);
		std::string thatTableAlias = newTableAlias();
		const sql::schema::Relation& refdTable = *db[fk->targetRel];
		joins << " LEFT OUTER JOIN " << Quote << fk->targetRel << Quote << " AS " << thatTableAlias << " ON ";
		if (fk->size() > 1)
		    joins << "(";
		for (size_t i = 0; i < fk->size(); ++i) {
		    if (i != 0)
			joins << " AND ";
		    joins << thisTableAlias << "." << Quote << fk->at(i) << Quote << "="
			  << thatTableAlias << "." << Quote << fk->relAttrs->at(i) << Quote;
		    queuedAttr.insert(colNo++, fk->at(i), fk->relAttrs->at(i));
		}
		if (fk->size() > 1)
		    joins << ")";
		if (refdTable.primaryKey == NULL) {
		    for (std::set<const sql::schema::Key*>::const_iterator key = refdTable.keys.begin();
			 key != refdTable.keys.end(); ++key)
			for (std::vector<sql::Attribute>::const_iterator attr = (*key)->begin();
			     attr != (*key)->end(); ++attr)
			    selects << ", " << thatTableAlias << "." << Quote << *attr << Quote
				// << " AS " << Quote << thatTableAlias << *attr << Quote
				;
		// } else if (*refdTable.primaryKey == *fk->relAttrs) { // no need to join
		} else {
		    for (std::vector<sql::Attribute>::const_iterator attr = refdTable.primaryKey->begin();
			 attr != refdTable.primaryKey->end(); ++attr) {
			selects << ", " << thatTableAlias << "." << Quote << *attr << Quote
			    // << " AS " << Quote << thatTableAlias << *attr << Quote
			    ;
			
		    }
		}
		referenceAttributes.push_back(queuedAttr);
	    }
	}


	SQLclient::Result* res = sqlDriver.executeQuery(selects.str() + joins.str(), fixups);

	const TTerm* rdfType = atomFactory.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	const TTerm* type = atomFactory.getURI(IRIsafe(table.name));

	SQLclient::Result::Row row;
	while ((row = res->nextRow()) != res->end()) {
	    std::string node = IRIsafe(table.name) + "/";
	    const TTerm* s;
	    if (table.primaryKey == NULL) {
		s = atomFactory.createBNode();
	    } else {
		for (size_t i = 0; i < table.primaryKey->size(); ++i) {
		    if (i != 0)
			node += ".";
		    node += attrname(table.primaryKey->at(i)) + "-" + attrvalue(row[pkCols[i]].get());
		}
		s = atomFactory.getURI(node);
	    }

	    bgp->addTriplePattern
		(atomFactory.getTriple
		 (s, rdfType, type));
	    // w3c_sw_LINEN << s->toString() << " " << rdfType->toString() << " " << type->toString() << "\n";
		
	    for (std::vector<LiteralAttribute>::const_iterator lit = literalAttributes.begin();
		 lit != literalAttributes.end(); ++lit) {
		if (row[lit->colNo].is_initialized()) {
		    const TTerm* o = row.getTTerm(lit->colNo, res->cols(), &atomFactory);
		    bgp->addTriplePattern
			(atomFactory.getTriple
			 (s, lit->p, o));
		    // w3c_sw_LINEN << s->toString() << " " << lit->p->toString() << " " << o->toString() << " .\n";
		}
	    }

	    for (std::vector<ReferenceAttribute>::const_iterator rit = referenceAttributes.begin();
		 rit != referenceAttributes.end(); ++rit) {
		const TTerm* p = atomFactory.getURI(rit->p);
		std::string oStr = rit->targetRel + "/";
		for (size_t i = 0; i < rit->size(); ++i) {
		    if (!row[rit->colNos[i]].is_initialized()) {
			oStr = "";
			break;
		    }
		    if (i != 0)
			oStr += ".";
		    oStr += attrname(rit->safeNames[i]) + "-" + attrvalue(row[rit->colNos[i]].get());
		}
		if (oStr.size() > 0) {
		    const TTerm* o = atomFactory.getURI(oStr);
		    bgp->addTriplePattern
			(atomFactory.getTriple
			 (s, p, o));
		    // w3c_sw_LINEN << s->toString() << " " << p->toString() << " " << o->toString() << " .\n";
		}
	    }
	}

	SqlResultSet rs2(&atomFactory, res);
	// w3c_sw_LINEN << rs2;

	// for (ResultSetConstIterator row = rs2.begin(); row != rs2.end(); ++row) {
	//     const TTerm* s;
	//     if (table.primaryKey == NULL) {
	// 	s = atomFactory.createBNode();
	//     } else {
	// 	std::stringstream node;
	// 	node << IRIsafe(table.name) << "/";
	// 	for (std::vector<sql::Attribute>::const_iterator a = table.primaryKey->attrs->begin();
	// 	     a != table.primaryKey->attrs->end(); ++a) {
	// 	    if (a != table.primaryKey->attrs->begin())
	// 		node << ".";
	// 	    node << attrname(*a) << "-" << attrvalue((*row)->get(atomFactory.getVariable(*a))->getLexicalValue());
	// 	}
	// 	s = atomFactory.getURI(node.str());
	//     }

	//     /* row type triple */
	//     bgp->addTriplePattern
	// 	(atomFactory.getTriple
	// 	 (s, rdfType, atomFactory.getURI(IRIsafe(table.name))));

	//     /* literal triples */
	//     for (std::vector<LiteralAttribute>::const_iterator it = literalAttributes.begin();
	// 	 it != literalAttributes.end(); ++it)
	// 	if ((*row)->get(it->alias) != NULL) {
	// 	    bgp->addTriplePattern
	// 		(atomFactory.getTriple
	// 		 (s, it->p, (*row)->get(it->alias)));
	// 	}

	//     /* reference triples */
	//     for (std::vector<ReferenceAttribute>::const_iterator it = ReferencesAttributes.begin();
	// 	 it != refrenceAttributes.end(); ++it) {
	// 	const sql::schema::ForeignKey* key = dynamic_cast<const sql::schema::ForeignKey*>(*it);
	// 	if (key != NULL) {

	// 	    std::stringstream ostr;
	// 	    ostr << key->targetRel << "/";

	// 	    std::vector<sql::Attribute>::const_iterator attr = key->attrs->begin();
	// 	    std::vector<sql::Attribute>::const_iterator relAttr = key->relAttrs->begin();
	// 	    while (attr != key->attrs->end()) {
	// 		const TTerm* val = (*row)->get(atomFactory.getVariable(*attr));
	// 		if (val == NULL)
	// 		    goto skipTriple;
	// 		if (attr != key->attrs->begin()) {
	// 		    ostr << ".";
	// 		}
	// 		pstr << IRIsafe(*attr);
	// 		ostr << attrname(*relAttr) << "-" << attrvalue(val->getLexicalValue());
	// 		++attr;
	// 		++relAttr;
	// 	    }

	// 	    bgp->addTriplePattern
	// 		(atomFactory.getTriple
	// 		 (s, atomFactory.getURI(pstr.str()), atomFactory.getURI(ostr.str())));
	// 	skipTriple:
	// 	    ;
	// 	}
	//     }
	// }
	nextTableAlias = 0;
	nextAttrAlias = 0;
    }

};

int main (int argc, const char* argv[]) {
    sqlContext sqlParserContext;
    SQLDriver sqlParser(sqlParserContext);
    try {
	IStreamContext ddlStream(argv[1], IStreamContext::FILE);
	sqlParser.parse(ddlStream);

#if 0 /* debugging dump */
	w3c_sw_LINEN << sqlParser.tables;
	for (std::vector<const sql::Insert*>::const_iterator it = sqlParser.inserts.begin();
	     it != sqlParser.inserts.end(); ++it)
	    w3c_sw_LINEN << **it << std::endl;
#endif /* 0 - debugging dump */

	W3C_SW_SQLCLIENT sqlDriver;
	sqlDriver.connect("", "DM", "root");
	// dump(sqlDriver, "SELECT ID, fname, addr FROM People");
	// dump(sqlDriver, "SHOW TABLES");

	DefaultGraphPattern bgp;
	Materializer m(sqlDriver);
	m(sqlParser.tables, &bgp);
	std::cout << bgp.toString("text/turtle");
    } catch (ParserException& e) {
	std::cerr << e.what();
	return 1;
    } catch (std::string& s) {
	std::cerr << "string exception: " << s << std::endl;
	return 1;
    }

    return 0;
}

void dump (SQLclient& sqlDriver, std::string cmd) {

    SQLclient::Result* res = sqlDriver.executeQuery(cmd.c_str());

    SQLclient::Result::ColumnSet cols = res->cols();

    /* dump headers */
    std::cout << "|";
    for (SQLclient::Result::ColumnSet::const_iterator it = cols.begin();
	 it != cols.end(); ++it)
	std::cout << it->name << "|";
    std::cout << std::endl;

    /* dump rows */
    SQLclient::Result::Row row;
    while ((row = res->nextRow()) != res->end()) { // !!! use iterator
	std::cout << "|";
	for(size_t i = 0; i < cols.size(); i++)
	    if (row[i].is_initialized()) {
		std::string dt = SQLclient::Result::Field::typeNames[cols[i].type];
		std::string lexval(row[i].get());
		if (cols[i].type == SQLclient::Result::Field::TYPE__err || 
		    cols[i].type == SQLclient::Result::Field::TYPE__unknown)
		    throw std::string("field value \"") + lexval + "\" has unknown datatype";// + cols[i].type;

		if (cols[i].type != SQLclient::Result::Field::TYPE__null) {
		    std::cout << lexval << " of " << (dt.size() > 0 ? dt.c_str() : "plain literal") << "|";
		}
	    }
	std::cout << std::endl;
    }
}

