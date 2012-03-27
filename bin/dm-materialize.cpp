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
w3c_sw::sql::MySQLSerializer Serializer;

void dump(SQLclient& sqlDriver, std::string cmd);

struct Materializer {
    typedef std::map<std::string, const TTerm*> TableRowNodes;
    typedef std::map<sql::RelationName, TableRowNodes> RowNodes;
    RowNodes rowNodes;
    struct Values2BNode : public std::map<std::string, const BNode*> {
    };
    std::map<const sql::schema::Key*, Values2BNode> allmaps;
    SQLclient& sqlDriver;
    size_t nextTableAlias;

    Materializer (SQLclient& sqlDriver)
	: sqlDriver(sqlDriver), nextTableAlias(0)
    {  }
    void operator() (sql::schema::Database& db, DefaultGraphPattern* bgp) {
	std::vector<sql::schema::Relation*> orderedTables;
	for (sql::schema::Database::const_iterator it = db.begin();
	     it != db.end(); ++it)
	    orderedTables.push_back(it->second);

	for (std::vector<sql::schema::Relation*>::const_iterator it = orderedTables.begin();
	     it != orderedTables.end(); ++it) {
	    sql::schema::Relation& table = **it;
	    dumpTable(table, db, atomFactory, bgp);
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

    sql::RelVar newTableAlias () {
	std::stringstream ss;
	ss << "_" << nextTableAlias++;
	return ss.str();
    }

    struct PkCols : std::vector<size_t> {
	void resize (size_t s) {
	    std::vector<size_t>::resize(s);
	}
    };

    struct TripleMaker {
	AtomFactory* atomFactory;
	TripleMaker (AtomFactory* atomFactory)
	    : atomFactory(atomFactory)
	{  }
	virtual void doIt(SQLclient::Result* res, SQLclient::Result::Row& row,
			  BasicGraphPattern* bgp, const TTerm* s) const = 0;
    };

    struct TypeTripleMaker : public TripleMaker {
	const TTerm* p;
	const TTerm* type;
	TypeTripleMaker (AtomFactory* atomFactory, const TTerm* p, const TTerm* type)
	    : TripleMaker(atomFactory), p(p), type(type)
	{  }
	virtual void doIt (SQLclient::Result* res, SQLclient::Result::Row& row,
			   BasicGraphPattern* bgp, const TTerm* s) const {
	    bgp->addTriplePattern
		(atomFactory->getTriple
		 (s, p, type));
	    // w3c_sw_LINEN << s->toString() << " " << rdfType->toString() << " " << type->toString() << "\n";
	}
    };

    struct LiteralTripleMaker : public TripleMaker {
	size_t colNo;
	const TTerm* p;
	LiteralTripleMaker (AtomFactory* atomFactory, size_t colNo, const TTerm* p)
	    : TripleMaker(atomFactory), colNo(colNo), p(p)
	{  }
	virtual void doIt (SQLclient::Result* res, SQLclient::Result::Row& row,
			   BasicGraphPattern* bgp, const TTerm* s) const {
	    if (row[colNo].is_initialized()) {
		const TTerm* o = row.getTTerm(colNo, res->cols(), atomFactory);
		bgp->addTriplePattern
		    (atomFactory->getTriple
		     (s, p, o));
		// w3c_sw_LINEN << s->toString() << " " << p->toString() << " " << o->toString() << " .\n";
	    }
	}
    };

    struct ReferenceTripleMaker : public TripleMaker {
	std::string p;
	sql::RelationName targetRel;
	std::vector<size_t>  colNos;
	ReferenceTripleMaker (AtomFactory* atomFactory, std::string tableName, sql::RelationName targetRel,
			      const sql::schema::ForeignKey* from, const sql::schema::Key* to,
			      const std::vector<size_t>& colNos)
	    : TripleMaker(atomFactory), p(tableName + "#ref-"), targetRel(targetRel), colNos(colNos)
	{ reference(colNos, from, to); }
	void reference (const std::vector<size_t>& colNos,
			const sql::schema::ForeignKey* from, const sql::schema::Key* to) {
	    for (size_t i = 0; i < from->size(); ++i) {
		if (i > 0)
		    p += ".";
		p += IRIsafe(from->at(i));
	    }
	}
	size_t size () const { return colNos.size(); }
    };
    struct PKReferenceTripleMaker : public ReferenceTripleMaker {
	std::vector<std::string> attrNames;
	PKReferenceTripleMaker (AtomFactory* atomFactory, std::string tableName, sql::RelationName targetRel,
				const sql::schema::ForeignKey* from, const sql::schema::Key* to,
				const std::vector<size_t>& colNos,
				const sql::schema::PrimaryKey* pk)
	    : ReferenceTripleMaker(atomFactory, tableName, targetRel, from, to, colNos)
	{
	    for (size_t i = 0; i < pk->size(); ++i)
		attrNames.push_back(attrname(pk->at(i)));
	}
	virtual void doIt (SQLclient::Result* res, SQLclient::Result::Row& row,
			   BasicGraphPattern* bgp, const TTerm* s) const {
	    std::string oStr = targetRel + "/";
	    for (size_t i = 0; i < size(); ++i) {
		if (!(row[colNos[i]].is_initialized())) {
		    oStr = "";
		    break;
		}
		if (i != 0)
		    oStr += ".";
		oStr += attrname(attrNames[i]) + "-" + attrvalue(row[colNos[i]].get());
	    }
	    if (oStr.size() > 0)
		bgp->addTriplePattern
		    (atomFactory->getTriple
		     (s, atomFactory->getURI(p), atomFactory->getURI(oStr)));
	    // w3c_sw_LINEN << s->toString() << " " << p->toString() << " " << o->toString() << " .\n";
	}
    };

    struct NoPKReferenceTripleMaker : public ReferenceTripleMaker {
	Values2BNode& v2b;
	NoPKReferenceTripleMaker (AtomFactory* atomFactory, std::string tableName, sql::RelationName targetRel,
				  const sql::schema::ForeignKey* from, const sql::schema::Key* to,
				  const std::vector<size_t>& colNos,
				  Values2BNode& v2b)
	    : ReferenceTripleMaker(atomFactory, tableName, targetRel, from, to, colNos),
	      v2b(v2b)
	{  }
	virtual void doIt (SQLclient::Result* res, SQLclient::Result::Row& row,
			   BasicGraphPattern* bgp, const TTerm* s) const {
	    std::string key;
	    for (size_t i = 0; i < size(); ++i)
		key
		    += row[colNos[i]].is_initialized()
		    ? attrvalue(row[colNos[i]].get())
		    : "NULL";

	    Values2BNode::iterator it = v2b.find(key);
	    const BNode* o;
	    if (it == v2b.end()) {
		o = atomFactory->createBNode();
		v2b.insert(std::pair<std::string, const BNode*>(key, o));
		// v2b[key] = o;
	    } else
		o = v2b[key];
	    bgp->addTriplePattern
		(atomFactory->getTriple
		 (s, atomFactory->getURI(p), o));
	    // // w3c_sw_LINEN << s->toString() << " " << p->toString() << " " << o->toString() << " .\n";
	}
    };

    void dumpTable (sql::schema::Relation& table, sql::schema::Database& db, AtomFactory& atomFactory, DefaultGraphPattern* bgp) {

	sql::RelVar thisTableAlias = newTableAlias();
	// w3c_sw_LINEN << table << "\n";
	struct SelectList : public std::vector<sql::AliasAttr> {
	    size_t lastColumn () { return size() - 1; }
	};
	SelectList selectList;

	std::stringstream joins;

	PkCols pkCols;
	if (table.primaryKey != NULL)
	    pkCols.resize(table.primaryKey->size());

	struct TripleMakers : public std::vector<boost::shared_ptr<TripleMaker> > {
	    void push_back (TripleMaker* tm) {
		std::vector<boost::shared_ptr<TripleMaker> >::push_back
		    (boost::shared_ptr<TripleMaker>(tm));
	    }
	};
	TripleMakers tripleMakers;

	tripleMakers.push_back(new TypeTripleMaker
			       (&atomFactory, atomFactory.getURI
				("http://www.w3.org/1999/02/22-rdf-syntax-ns#type"),
				atomFactory.getURI(IRIsafe(table.name))));

	/* fixup for various DBs */
	SQLclient::Result::Fixups fixups;

	std::vector<size_t> rowIndexColNos;

	for (sql::schema::Relation::Fields::const_iterator it = table.fields.begin();
	     it != table.fields.end(); ++it) {

	    sql::AliasAttr fqAttr(thisTableAlias, it->second.name);
	    selectList.push_back(fqAttr);

	    const TTerm* p = atomFactory.getURI(IRIsafe(table.name) + "#" + IRIsafe(it->second.name));

	    tripleMakers.push_back(new LiteralTripleMaker(&atomFactory, selectList.lastColumn(), p));

	    if (table.primaryKey != NULL) {
		// Find out if this field participates in a primary key.
		for (size_t i = 0; i < table.primaryKey->size(); ++i)
		    if (it->second.name == table.primaryKey->at(i)) {
			pkCols[i] = selectList.lastColumn(); // subject node will use this column.
			break;
		    }
	    } else if (table.keys.size() != 0) {
		// Find out if this field participates in the indexing key.
		const sql::schema::Key* rowIndexKey = *(table.keys.begin());
		rowIndexColNos.resize(rowIndexKey->size());
		for (size_t i = 0; i < rowIndexKey->size(); ++i)
		    if (it->second.name == rowIndexKey->at(i)) {
			rowIndexColNos[i] = selectList.lastColumn(); // subject node will use this column.
			break;
		    }
	    }

	    if (it->second.type == sql::TYPE_binary)
		fixups.insert(selectList.lastColumn(),
			      new SQLclient_MySQL::Result::LiteralToBinary());
	    // w3c_sw_LINEN << "rewrite " << selectList.lastColumn() << " to base64\n";

#ifdef W3C_SW_MYSQL_SQLCLIENT // MySQL doesn't preserve trailing spaces on CHAR(n)
	    if (it->second.type == sql::TYPE_boolean)
		fixups.insert(selectList.lastColumn(),
			      new SQLclient_MySQL::Result::IntToBoolean());
	    // w3c_sw_LINEN << "rewrite " << selectList.lastColumn() << " to boolean\n";

	    if (it->second.type == sql::TYPE_char &&
		it->second.precision != SQL_PRECISION_unspecified)
		fixups.insert(selectList.lastColumn(),
			      new SQLclient_MySQL::Result::CharTrailingChars(it->second.precision));
#endif /* W3C_SW_MYSQL_SQLCLIENT */

	}
	joins << " FROM " << Serializer.name(table.name) << " AS " << thisTableAlias;


	for (std::vector<const sql::schema::FieldOrKey*>::iterator it = table.orderedFields.begin();
	     it != table.orderedFields.end(); ++it) {
	    const sql::schema::ForeignKey* fk = dynamic_cast<const sql::schema::ForeignKey*>(*it);
	    if (fk != NULL) {
		// This entry is a forign key.
		sql::RelVar thatTableAlias = newTableAlias();
		const sql::schema::Relation& refdTable = *db[fk->targetRel];
		joins << " LEFT OUTER JOIN " << Serializer.name(fk->targetRel)
		      << " AS " << thatTableAlias << " ON ";
		std::vector<size_t> fkColumns;
		if (fk->size() > 1)
		    joins << "(";
		for (size_t i = 0; i < fk->size(); ++i) {
		    if (i != 0)
			joins << " AND ";
		    sql::AliasAttr from(thisTableAlias, fk->at(i));
		    sql::AliasAttr to(thatTableAlias, fk->relAttrs->at(i));
		    joins << "("
			  << Serializer.Serializer::name(from) << "="
			  << Serializer.Serializer::name(to)
			  << " OR ("
			  << Serializer.Serializer::name(from) << " IS NULL AND "
			  << Serializer.Serializer::name(to) << " IS NULL"
			  << ")"
			  << ")";
		}
		if (fk->size() > 1)
		    joins << ")";

		const sql::schema::Key* rowIndexKey
		    = refdTable.primaryKey == NULL
		    ? *(refdTable.keys.begin())
		    : refdTable.primaryKey;
		for (std::vector<sql::Attribute>::const_iterator attr = rowIndexKey->begin();
		     attr != rowIndexKey->end(); ++attr) {
		    sql::AliasAttr refdAttr(thatTableAlias, *attr);
		    selectList.push_back(refdAttr);
		    fkColumns.push_back(selectList.lastColumn());
		}

		if (refdTable.primaryKey == NULL) {
		    tripleMakers.push_back(new NoPKReferenceTripleMaker
					   (&atomFactory, IRIsafe(table.name), fk->targetRel, fk, fk->relAttrs,
					    fkColumns, allmaps[rowIndexKey]));
		// } else if (*refdTable.primaryKey == *fk->relAttrs) { // no need to join
		} else {
		    tripleMakers.push_back(new PKReferenceTripleMaker
					   (&atomFactory, IRIsafe(table.name), fk->targetRel, fk, fk->relAttrs,
					    fkColumns, refdTable.primaryKey));
		}
	    }
	}

	std::string selectsString = "SELECT ";
	for (SelectList::const_iterator it = selectList.begin();
	     it != selectList.end(); ++it) {
	    if (it != selectList.begin())
		selectsString += ", ";
	    selectsString += Serializer.Serializer::name(*it);
	}
	// w3c_sw_LINEN << "q: " << (selectsString + joins.str()) << "\n";
	SQLclient::Result* res = sqlDriver.executeQuery(selectsString + joins.str(), fixups);

	const TTerm* rdfType = atomFactory.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	const TTerm* type = atomFactory.getURI(IRIsafe(table.name));

	SQLclient::Result::Row row;
	while ((row = res->nextRow()) != res->end()) {
	    std::string node = IRIsafe(table.name) + "/";
	    const TTerm* s;
	    if (table.primaryKey == NULL) {
		if (table.keys.size() == 0) {
		    s = atomFactory.createBNode();
		} else {
		    const sql::schema::Key* rowIndexKey = *(table.keys.begin());
		    Values2BNode& v2b = allmaps[rowIndexKey];
		    std::string key;
		    for (size_t i = 0; i < rowIndexColNos.size(); ++i)
			key
			    += row[rowIndexColNos[i]].is_initialized()
			    ? attrvalue(row[rowIndexColNos[i]].get())
			    : "NULL";

		    Values2BNode::iterator it = v2b.find(key);
		    const BNode* b;
		    if (it == v2b.end()) {
			b = atomFactory.createBNode();
			v2b.insert(std::pair<std::string, const BNode*>(key, b));
			// v2b[key] = b;
		    } else {
			b = v2b[key];
		    }
		    s = b;
		}
	    } else {
		for (size_t i = 0; i < table.primaryKey->size(); ++i) {
		    if (i != 0)
			node += ".";
		    node += attrname(table.primaryKey->at(i)) + "-" + attrvalue(row[pkCols[i]].get());
		}
		s = atomFactory.getURI(node);
	    }

	    for (std::vector<boost::shared_ptr<TripleMaker> >::const_iterator tmit = tripleMakers.begin();
		 tmit != tripleMakers.end(); ++tmit)
		(*tmit)->doIt(res, row, bgp, s);
	}
	nextTableAlias = 0;
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

