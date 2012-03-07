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

void dump(SQLclient& sqlDriver, std::string cmd);

typedef std::map<std::string, const TTerm*> TableRowNodes;
typedef std::map<sql::RelationName, TableRowNodes> RowNodes;
const char* Quote = "`";

void dumpTable(RowNodes& rowNodes, sql::schema::Relation& table, SQLclient& sqlDriver, AtomFactory& atomFactory, DefaultGraphPattern* bgp) {
    // DefaultGraphPattern* ret = new DefaultGraphPattern();
    // w3c_sw_LINEN << table << "\n";
    std::stringstream dumpQuery;
    dumpQuery << "SELECT ";

    /* fixup for various DBs */
    
    int colNo = 0;
    SQLclient::Result::Fixups fixups;
    std::vector<boost::shared_ptr<SQLclient::Result::Fixup> > holder;
    for (sql::schema::Relation::Fields::const_iterator it = table.fields.begin();
	 it != table.fields.end(); ++it) {
	if (it != table.fields.begin())
	    dumpQuery << ", ";
	dumpQuery << Quote << it->second.name << Quote;

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
    dumpQuery << " FROM " << Quote << table.name << Quote;
    SQLclient::Result* res = sqlDriver.executeQuery(dumpQuery.str(), fixups);

    SqlResultSet rs2(&atomFactory, res);
    w3c_sw_LINEN << rs2;

    const TTerm* rdfType = atomFactory.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");

    for (ResultSetConstIterator row = rs2.begin(); row != rs2.end(); ++row) {
	const TTerm* s;
	if (table.primaryKey == NULL) {
	    s = atomFactory.createBNode();
	} else {
	    std::stringstream node;
	    node << table.name << "/";
	    for (std::vector<sql::Attribute>::const_iterator a = table.primaryKey->attrs->begin();
		 a != table.primaryKey->attrs->end(); ++a) {
		if (a != table.primaryKey->attrs->begin())
		    node << ".";
		node << *a << "-" << (*row)->get(atomFactory.getVariable(*a))->getLexicalValue();
	    }
	    s = atomFactory.getURI(node.str());
	}

	/* row type triple */
	bgp->addTriplePattern
	    (atomFactory.getTriple
	     (s, rdfType, atomFactory.getURI(table.name)));

	/* literal triples */
	const VariableList* vars = rs2.getKnownVars();
	for (VariableListConstIterator var = vars->begin(); var != vars->end(); ++var) {
	    if ((*row)->get(*var) != NULL) {
		const TTerm* p = atomFactory.getURI(table.name + "#" + (*var)->getLexicalValue());
		bgp->addTriplePattern
		    (atomFactory.getTriple
		     (s, p, (*row)->get(*var)));
	    }
	}

	/* reference triples */
	for (std::vector<const sql::schema::FieldOrKey*>::iterator it = table.orderedFields.begin();
	     it != table.orderedFields.end(); ++it) {
	    const sql::schema::ForeignKey* key = dynamic_cast<const sql::schema::ForeignKey*>(*it);
	    if (key != NULL) {

		std::stringstream pstr;
		pstr << table.name << "#ref-";

		std::stringstream ostr;
		ostr << key->targetRel << "/";

		std::vector<sql::Attribute>::const_iterator attr = key->attrs->begin();
		std::vector<sql::Attribute>::const_iterator relAttr = key->relAttrs->begin();
		while (attr != key->attrs->end()) {
		    if (attr != key->attrs->begin()) {
			pstr << ".";
			ostr << ".";
		    }
		    pstr << *attr;
		    ostr << *relAttr << "-" << (*row)->get(atomFactory.getVariable(*attr))->getLexicalValue();
		    ++attr;
		    ++relAttr;
		}

		bgp->addTriplePattern
		    (atomFactory.getTriple
		     (s, atomFactory.getURI(pstr.str()), atomFactory.getURI(ostr.str())));
	    }
	}
    }
}

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

	RowNodes rowNodes;
	AtomFactory atomFactory;
	DefaultGraphPattern bgp;
	for (sql::schema::Database::const_iterator it = sqlParser.tables.begin();
	     it != sqlParser.tables.end(); ++it)
	    try {
		dumpTable(rowNodes, *it->second, sqlDriver, atomFactory, &bgp);
	    } catch (std::string& s) {
		std::cerr << s << "\n";
	    }

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

