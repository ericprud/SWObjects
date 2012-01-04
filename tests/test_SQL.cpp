/* test_SQL.hpp -- 
 *
 * Test a SPARQL Parser and algebra serializer against references like
 *   http://www.sparql.org/validator.html
 *
 * $Id: test_SQL.cpp,v 1.5 2008-12-04 22:37:09 eric Exp $
 */

#define BOOST_TEST_MODULE SQL

#include <iostream>
#include "SWObjects.hpp"
#include "SQL.hpp"
#include "SQLParser/SQLParser.hpp"

/* Keep all inclusions of boost *after* the inclusion of SWObjects.hpp
 * (or define BOOST_*_DYN_LINK manually).
 */
#ifndef MANUAL_TEST
  #include <boost/test/unit_test.hpp>
  w3c_sw_PREPARE_TEST_LOGGER("--log"); // invoke with e.g. "--log *:-1,SQL,IO:3"
#endif

using namespace w3c_sw;

struct EqTest {
    sqlContext context;
    SQLDriver driver;
    sql::SQLQuery* q1;
    sql::SQLQuery* q2;
    EqTest (const char* s1, const char* s2)
	: context(), driver(context)
    {
	IStreamContext str1(s1, IStreamContext::STRING);
	q1 = driver.parse(str1);
	IStreamContext str2(s2, IStreamContext::STRING);
	q2 = driver.parse(str2);
    }
    ~EqTest () {
	delete q1;
	delete q2;
    }
};

BOOST_AUTO_TEST_SUITE( op_equals )
BOOST_AUTO_TEST_CASE( SelExprEq1_1 ) {
    EqTest t("SELECT 1=1",
	     " sElEcT 1 = 1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprEql1_2_3 ) {
    EqTest t("SELECT 1+2=3",
	     "SELECT 1+2=3");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprEql3_1_2_AS_x ) {
    EqTest t("SELECT 1+2=3 AS x",
	     "SELECT 3=1+2 AS x");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprEql3_2_1_AS_x ) {
    EqTest t("SELECT 1+2=3 AS x",
	     "SELECT 3=2+1 AS x");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprEql3_2_1 ) {
    EqTest t("SELECT 1+2=3",  // implies AS `1+2=3`
	     "SELECT 3=1+2"); // implies AS `3=1+2`
    BOOST_CHECK_MESSAGE( !(*t.q1 == *t.q2), *t.q1 << " == " << *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelUnorderedAttrs ) {
    EqTest t("SELECT relvar1.attr1 AS sel1, relvar1.attr2 AS sel2 FROM tbl1 AS relvar1",
	     "SELECT relvar1.attr2 AS sel2, relvar1.attr1 AS sel1 FROM tbl1 AS relvar1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( TwoRVs ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl1 AS rv2",
	     "\
SELECT rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3,\n\
       rv1.attr1 AS sel1\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl1 AS rv2");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( LeftOuter ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3\n\
  FROM tbl1 AS rv1\n\
       LEFT OUTER JOIN tbl1 AS rv2 ON rv2.attr1=rv1.attr3",
	     "\
SELECT rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3,\n\
       rv1.attr1 AS sel1\n\
  FROM tbl1 AS rv1\n\
       LEFT OUTER JOIN tbl1 AS rv2 ON rv2.attr1=rv1.attr3");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( InnerOuter ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl1 AS rv2 ON rv2.attr1=rv1.attr3",
	     "\
SELECT rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3,\n\
       rv1.attr1 AS sel1\n\
  FROM tbl1 AS rv1\n\
       LEFT OUTER JOIN tbl1 AS rv2 ON rv2.attr1=rv1.attr3");
    BOOST_CHECK_MESSAGE( !(*t.q1 == *t.q2), *t.q1 << " == " << *t.q2 );
}
BOOST_AUTO_TEST_CASE( LeftOuterUnmapped ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv2.attr2 AS sel2\n\
  FROM tbl1 AS rv1\n\
       LEFT OUTER JOIN tbl1 AS rv2 ON rv2.attr1=rv1.attr3",
	     "\
SELECT rvB.attr2 AS sel2,\n\
       rvA.attr1 AS sel1\n\
  FROM tbl1 AS rvA\n\
       LEFT OUTER JOIN tbl1 AS rvB ON rvB.attr1=rvA.attr3");
    BOOST_CHECK_MESSAGE( !(*t.q1 == *t.q2), *t.q1 << " == " << *t.q2 );
}
BOOST_AUTO_TEST_CASE( InnerWhereMapped ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv2.attr2 AS sel2\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl2 AS rv2 WHERE rv2.attr1=rv1.attr3",
	     "\
SELECT rvB.attr2 AS sel2,\n\
       rvA.attr1 AS sel1\n\
  FROM tbl1 AS rvA\n\
       INNER JOIN tbl2 AS rvB WHERE rvB.attr1=rvA.attr3");
    BOOST_CHECK_EQUAL( sql::SQLQuery::MappedEquivalence(*t.q1), *t.q2 );
}
BOOST_AUTO_TEST_CASE( InnerOnMapped ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv2.attr2 AS sel2\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl2 AS rv2 ON rv2.attr1=rv1.attr3",
	     "\
SELECT rvB.attr2 AS sel2,\n\
       rvA.attr1 AS sel1\n\
  FROM tbl1 AS rvA\n\
       INNER JOIN tbl2 AS rvB ON rvB.attr1=rvA.attr3");
    BOOST_CHECK_EQUAL( sql::SQLQuery::MappedEquivalence(*t.q1), *t.q2 );
}
BOOST_AUTO_TEST_CASE( LeftOuterMapped ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv2.attr2 AS sel2\n\
  FROM tbl1 AS rv1\n\
       LEFT OUTER JOIN tbl2 AS rv2 ON rv2.attr1=rv1.attr3",
	     "\
SELECT rvB.attr2 AS sel2,\n\
       rvA.attr1 AS sel1\n\
  FROM tbl1 AS rvA\n\
       LEFT OUTER JOIN tbl2 AS rvB ON rvB.attr1=rvA.attr3");
    BOOST_CHECK_EQUAL( sql::SQLQuery::MappedEquivalence(*t.q1), *t.q2 );
}
BOOST_AUTO_TEST_CASE( ThreeRVs ) {
    EqTest t("\
SELECT rv1.attr1 AS sel1,\n\
       rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3 + rv3.attr4 AS sel3\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl1 AS rv2\n\
       INNER JOIN tbl3 AS rv3",
	     "\
SELECT rv1.attr2 AS sel2,\n\
       rv1.attr1 + rv1.attr2 + rv2.attr3 + rv3.attr4 AS sel3,\n\
       rv1.attr1 AS sel1\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl1 AS rv2\n\
       INNER JOIN tbl3 AS rv3");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( OneMappedRV ) {
    EqTest t("\
SELECT rvA.attr1 AS sel1\n\
  FROM tbl1 AS rvA",
	     "\
SELECT rv1.attr1 AS sel1\n\
  FROM tbl1 AS rv1");
    BOOST_CHECK_EQUAL( sql::SQLQuery::MappedEquivalence(*t.q1), *t.q2 );
}
BOOST_AUTO_TEST_CASE( ThreeMappedRVs ) {
    EqTest t("\
SELECT rvA.attr1 AS sel1,\n\
       rvA.attr2 AS sel2,\n\
       rvA.attr1 + rvA.attr2 + rvB.attr3 + rvC.attr4 AS sel3\n\
  FROM tbl1 AS rvA\n\
       INNER JOIN tbl1 AS rvB\n\
       INNER JOIN tbl3 AS rvC",
	     "\
SELECT rv1.attr2 AS sel2,\n\
       rv1.attr2 + rv2.attr3 + rv1.attr1 + rv3.attr4 AS sel3,\n\
       rv1.attr1 AS sel1\n\
  FROM tbl1 AS rv1\n\
       INNER JOIN tbl1 AS rv2\n\
       INNER JOIN tbl3 AS rv3");
    BOOST_CHECK_EQUAL( sql::SQLQuery::MappedEquivalence(*t.q1), *t.q2 );
}
BOOST_AUTO_TEST_CASE( SubSelSame ) {
    EqTest t("SELECT op1.sel1 AS sel1 FROM (SELECT rv1.attr1 AS sel1 FROM tbl1 AS rv1) AS op1",
	     "SELECT op1.sel1 AS sel1 FROM (SELECT rv1.attr1 AS sel1 FROM tbl1 AS rv1) AS op1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SubSel_1_X ) {
    EqTest t("SELECT op1.sel1 AS sel1 FROM (SELECT rv1.attr1 AS sel1 FROM tbl1 AS rv1) AS op1",
	     "SELECT opX.sel1 AS sel1 FROM (SELECT rv1.attr1 AS sel1 FROM tbl1 AS rv1) AS opX");
    BOOST_CHECK_MESSAGE( !(*t.q1 == *t.q2), *t.q1 << " == " << *t.q2 );
}
BOOST_AUTO_TEST_CASE( SubSelMapped_1_X ) {
    EqTest t("SELECT op1.sel1 AS sel1 FROM (SELECT rv1.attr1 AS sel1 FROM tbl1 AS rv1) AS op1",
	     "SELECT opX.sel1 AS sel1 FROM (SELECT rv1.attr1 AS sel1 FROM tbl1 AS rv1) AS opX");
    BOOST_CHECK_EQUAL( sql::SQLQuery::MappedEquivalence(*t.q1), *t.q2 );
}

BOOST_AUTO_TEST_CASE( SelExprEq11X ) {
    EqTest t("SELECT 1=1",
	     "SELECT 1=2");
    BOOST_CHECK_MESSAGE( !(*t.q1 == *t.q2), *t.q1 << " == " << *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprNe11 ) {
    EqTest t("SELECT 1!=1",
	     "SELECT 1!= 1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprLt11 ) {
    EqTest t("SELECT 1<1",
	     "SELECT 1<1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprGt11 ) {
    EqTest t("SELECT 1>1",
	     "SELECT 1>1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprLe11 ) {
    EqTest t("SELECT 1<=1",
	     "SELECT 1<=1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SelExprGe11 ) {
    EqTest t("SELECT 1>=1",
	     "SELECT 1>=1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SqlExprEq12 ) {
    EqTest t("SELECT 1=2",
	     "SELECT 1=2 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( ConstAsAttr ) {
    EqTest t("SELECT 1 AS attr",
	     "SELECT 1 AS attr ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( From ) {
    EqTest t("SELECT rel.attr FROM rel",
	     "SELECT rel.attr FROM rel ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( AttrAsAttr ) {
    EqTest t("SELECT rel.attr AS attr FROM rel",
	     "SELECT rel.attr AS attr FROM rel ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromAs ) {
    EqTest t("SELECT relvar.attr FROM rel AS relvar",
	     "SELECT relvar . attr FROM rel AS relvar ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereEq11 ) {
    EqTest t("SELECT rel.attr FROM rel WHERE 1=2",
	     "SELECT rel.attr FROM rel WHERE 2=1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereEqAttr1 ) {
    EqTest t("SELECT rel.attr FROM rel WHERE rel.attr=2",
	     "SELECT rel.attr FROM rel WHERE rel.attr=2 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereEq1Attr ) {
    EqTest t("SELECT rel.attr FROM rel WHERE 2=rel.attr",
	     "SELECT rel.attr FROM rel WHERE 2=rel.attr ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereEqAttr2 ) {
    EqTest t("SELECT rel.attr FROM rel WHERE rel.attr=2", 
	     "SELECT rel.attr FROM rel WHERE 2=rel.attr");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWherePlus11 ) {
    EqTest t("SELECT rel.attr FROM rel WHERE 1+2",
	     "SELECT rel.attr FROM rel WHERE 1+2 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereMinus11 ) {
    EqTest t("SELECT rel.attr FROM rel WHERE 1-2",
	     "SELECT rel.attr FROM rel WHERE 1-2 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereNegation ) {
    EqTest t("SELECT rel.attr FROM rel WHERE -1+-2",
	     "SELECT rel.attr FROM rel WHERE -1+-2 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereSumation ) {
    EqTest t("SELECT rel.attr FROM rel WHERE 1+2=3",
	     "SELECT rel.attr FROM rel WHERE 1+2=3 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( FromWhereArith ) {
    EqTest t("SELECT rel.attr FROM rel WHERE 1*2/3+4-5",
	     "SELECT rel.attr FROM rel WHERE 1*2/3+4-5 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
//EQTEST(FromWhereArithBORK, "SELECT rel.attr FROM rel WHERE 1*2+3*4/5-6-(7*8)");
BOOST_AUTO_TEST_CASE( AttrAsAttrFromAsWhere ) {
    EqTest t("SELECT relvar.attr FROM rel AS relvar WHERE 1=2",
	     "SELECT relvar.attr FROM rel AS relvar WHERE 1=2 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( AttrAsAttrFromAsWhere2 ) {
    EqTest t("SELECT relvar.attr FROM rel AS relvar WHERE 1=2",
	     "SELECT relvar.attr FROM rel AS relvar WHERE 2=1 ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( AttrAsAttrFromAsOn ) {
    EqTest t("SELECT relvar1.attr FROM rel AS relvar1 INNER JOIN rel AS relvar2 ON relvar1.attr=relvar2.attr",
	     "SELECT relvar1.attr FROM rel AS relvar1 INNER JOIN rel AS relvar2 ON relvar2.attr=relvar1.attr ");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( AttrAsAttrFromAsOnX ) {
    EqTest t("SELECT relvar1.attr FROM rel AS relvar1 INNER JOIN rel AS relvar2 ON relvar1.attr=relvar2.attr",
	     "SELECT relvar1.attr FROM rel AS relvar1 LEFT OUTER JOIN rel AS relvar2 ON relvar2.attr=relvar1.attr ");
    BOOST_CHECK_MESSAGE( !(*t.q1 == *t.q2), *t.q1 << " == " << *t.q2 );
}
BOOST_AUTO_TEST_CASE( Sub ) {
    EqTest t("SELECT sub1.attr FROM (SELECT relvar1.attr FROM rel AS relvar1) AS sub1",
	     "SELECT sub1.attr FROM (SELECT relvar1.attr FROM rel AS relvar1) AS sub1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( SubUnion ) {
    EqTest t("SELECT union1.attr FROM (SELECT relvar1.attr FROM rel AS relvar1 UNION SELECT relvar2.attr FROM rel AS relvar2) AS union1",
	     "SELECT union1.attr FROM (SELECT relvar1.attr FROM rel AS relvar1 UNION SELECT relvar2.attr FROM rel AS relvar2) AS union1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( JoinUnion ) {
    EqTest t("SELECT union1.attr FROM rel AS relvar1 INNER JOIN (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1",
	     "SELECT union1.attr FROM rel AS relvar1 INNER JOIN (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( JoinUnionOn ) {
    EqTest t("SELECT union1.attr FROM rel AS relvar1 INNER JOIN (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 ON union1.attr=relvar1.attr",
	     "SELECT union1.attr FROM rel AS relvar1 INNER JOIN (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 ON union1.attr=relvar1.attr");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( UnionJoin ) {
    EqTest t("SELECT union1.attr FROM (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 INNER JOIN rel AS relvar1",
	     "SELECT union1.attr FROM (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 INNER JOIN rel AS relvar1");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_CASE( UnionJoinOn ) {
    EqTest t("SELECT union1.attr FROM (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 INNER JOIN rel AS relvar1 ON relvar1.attr=union1.attr",
	     "SELECT union1.attr FROM (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 INNER JOIN rel AS relvar1 ON relvar1.attr=union1.attr");
    BOOST_CHECK_EQUAL( *t.q1, *t.q2 );
}
BOOST_AUTO_TEST_SUITE_END()


/* test != */

const char* qs1 =
	"SELECT union1.somePerson AS somePerson\n"
	"       FROM (\n"
	"    SELECT 1 AS _DISJOINT_, HAS_attr1_gen0.attr1 AS somePerson\n"
	"           FROM Patient AS ADMINISTRATION_gen3\n"
	"                INNER JOIN baz AS HAS_attr1_gen0\n"
	"                INNER JOIN Names AS PATIENT_name_gen1 ON PATIENT_name_gen1.id=ADMINISTRATION_gen3.name\n"
	"                INNER JOIN bar AS PATIENT_gen2 ON PATIENT_gen2.id=PATIENT_name_gen1.patient AND PATIENT_gen2.attr2=HAS_attr1_gen0.attr1\n"
	"                INNER JOIN bar AS HAS_attr1_gen0_1 ON HAS_attr1_gen0_1.id=HAS_attr1_gen0.id AND HAS_attr1_gen0_1.attr3=HAS_attr1_gen0.attr1\n"
	"  UNION\n"
	"    SELECT 2 AS _DISJOINT_, PATIENT_name_gen2.patient AS somePerson\n"
	"           FROM Patient AS ADMINISTRATION_gen4\n"
	"                INNER JOIN Names AS PATIENT_name_gen2 ON PATIENT_name_gen2.id=ADMINISTRATION_gen4.name\n"
	"                INNER JOIN bar AS somePerson ON somePerson.id=PATIENT_name_gen2.patient\n"
	"             ) AS union1";
const char* qs2 =
	"SELECT union1.somePerson AS somePerson\n"
	"       FROM (\n"
	"    SELECT 1 AS _DISJOINT_, HAS_attr1_gen0.attr1 AS somePerson\n"
	"           FROM Patient AS ADMINISTRATION_gen3\n"
	"                INNER JOIN baz AS HAS_attr1_gen0\n"
	"                INNER JOIN Names999 AS PATIENT_name_gen1 ON PATIENT_name_gen1.id=ADMINISTRATION_gen3.name\n"
	"                INNER JOIN bar AS PATIENT_gen2 ON PATIENT_gen2.id=PATIENT_name_gen1.patient AND PATIENT_gen2.attr2=HAS_attr1_gen0.attr1\n"
	"                INNER JOIN bar AS HAS_attr1_gen0_1 ON HAS_attr1_gen0_1.id=HAS_attr1_gen0.id AND HAS_attr1_gen0_1.attr3=HAS_attr1_gen0.attr1\n"
	"  UNION\n"
	"    SELECT 2 AS _DISJOINT_, PATIENT_name_gen2.patient AS somePerson\n"
	"           FROM Patient AS ADMINISTRATION_gen4\n"
	"                INNER JOIN Names AS PATIENT_name_gen2 ON PATIENT_name_gen2.id=ADMINISTRATION_gen4.name\n"
	"                INNER JOIN bar AS somePerson ON somePerson.id=PATIENT_name_gen2.patient\n"
	"             ) AS union1";

BOOST_AUTO_TEST_CASE( SQL1 ) {
    sqlContext context;
    SQLDriver driver(context);

    sql::SQLQuery* q1 = driver.parse(qs1);
    sql::SQLQuery* q2 = driver.parse(qs1);
    BOOST_CHECK_EQUAL(*q1, *q2);
    delete q2;

    sql::SQLQuery* q3 = driver.parse(qs2); 
    BOOST_CHECK(!(*q1 == *q3));
    delete q3;
    delete q1;
}

std::string Rel0("CREATE TABLE rel (\n"
		 "  id0 INT,\n"
		 "  id1 INT,\n"
		 "  str STRING,\n"
		 "  dt DATETIME,\n"
		 "  FOREIGN KEY (id1, str) REFERENCES rel2(candkey1, candkey2),\n"
		 "  PRIMARY KEY (id0, id1)\n"
		 ");\n"
		 );

std::string Rel1("CREATE TABLE rel (\n"
		 "  id0 INT,\n"
		 "  id1 INT,\n"
		 "  str STRING,\n"
		 "  dt DATETIME,\n"
		 "  FOREIGN KEY (id1, str) REFERENCES rel2(candkey2, candkey1),\n"
		 "  PRIMARY KEY (id0, id1)\n"
		 ");\n"
		 );

BOOST_AUTO_TEST_CASE( DDLP0 ) {
    sqlContext context;
    SQLDriver ddl1Driver(context);
    ddl1Driver.parse("CREATE TABLE rel (\n"
		 "  id0 INT,\n"
		 "  id1 INT,\n"
		 "  str STRING,\n"
		 "  dt DATETIME,\n"
		 "  FOREIGN KEY (id1, str) REFERENCES rel2(candkey1, candkey2),\n"
		 "  PRIMARY KEY (id0, id1)\n"
		 ");\n");
    ddl1Driver.tables.clear();
}

BOOST_AUTO_TEST_CASE( DDL0 ) {
    sqlContext context;
    SQLDriver ddl1Driver(context);
    ddl1Driver.parse(Rel0);
    ddl1Driver.tables.clear();
}

BOOST_AUTO_TEST_CASE( DDL1 ) {
    sqlContext context;
    SQLDriver ddl1Driver(context);
    IStreamContext ddl1Str(Rel0, IStreamContext::STRING);
    ddl1Driver.parse(ddl1Str);

    SQLDriver ddl2Driver(context);
    IStreamContext ddl2Str(Rel0, IStreamContext::STRING);
    ddl2Driver.parse(ddl2Str);

    BOOST_CHECK_EQUAL(ddl1Driver.tables, ddl2Driver.tables);
    ddl2Driver.tables.clear();
    ddl1Driver.tables.clear();
}

BOOST_AUTO_TEST_CASE( DDL2 ) {
    sqlContext context;
    SQLDriver ddl1Driver(context);
    IStreamContext ddl1Str(Rel0, IStreamContext::STRING);
    ddl1Driver.parse(ddl1Str);

    SQLDriver ddl2Driver(context);
    IStreamContext ddl2Str(Rel1, IStreamContext::STRING);
    ddl2Driver.parse(ddl2Str);

    BOOST_CHECK_MESSAGE( !(ddl1Driver.tables == ddl2Driver.tables), ddl1Driver.tables << " == " << ddl2Driver.tables );
    ddl2Driver.tables.clear();
    ddl1Driver.tables.clear();
}

BOOST_AUTO_TEST_CASE( bsbm_ddl ) {
    sqlContext context;
    SQLDriver ddl1Driver(context);
    IStreamContext ddl1Str("bsbm/ddl.sql", IStreamContext::FILE);
    ddl1Driver.parse(ddl1Str);

    SQLDriver ddl2Driver(context);
    IStreamContext ddl2Str("bsbm/ddl.sql", IStreamContext::FILE);
    ddl2Driver.parse(ddl2Str);

    BOOST_CHECK_EQUAL(ddl1Driver.tables, ddl2Driver.tables);
    ddl2Driver.tables.clear();
    ddl1Driver.tables.clear();
}

// #include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "QueryMapper.hpp" // @@ include defn for KeyMap for SQLizer
#include "SQLizer.hpp"

AtomFactory F;
char predicateDelims[]={'#',' ',' '};
char nodeDelims[]={'/','.',' '};
const char* pkAttribute = "ID";
KeyMap keyMap;
const char* drv = "mysql";

BOOST_AUTO_TEST_CASE( sqlizer_1 ) {
    SPARQLfedDriver sparqlParser("", &F);
    const Operation* query = sparqlParser.parse("\
PREFIX people: <http://example.com/swat4ls_demo/people#>\n\
PREFIX addresses: <http://example.com/swat4ls_demo/addresses#>\n\
PREFIX fn: <http://www.w3.org/2005/xpath-functions#>\n\
\n\
SELECT ?person ?city ?cityuri ?city_lower WHERE {\n\
    ?person people:fname \"Bob\" ;\n\
            people:addr ?address .\n\
    ?address addresses:city ?city .\n\
    BIND(IRI(concat(\"http://dbpedia.org/resource/\", ?city)) as ?cityuri)\n\
    BIND(fn:lower-case(?city) as ?city_lower)\n\
}");
    SQLizer sqlizer(&F, "http://example.com/swat4ls_demo/", predicateDelims, nodeDelims, pkAttribute, keyMap, drv);
    query->express(&sqlizer);

    sqlContext context;

    SQLDriver tested(context);
    tested.parse(sqlizer.getSQLstring());

    SQLDriver expected(context);
    expected.parse("\
SELECT \n\
    person.ID AS person, \n\
    address.city AS city, \n\
    CONCAT(\"http://dbpedia.org/resource/\", address.city) AS cityuri, \n\
    LCASE(address.city) AS city_lower\n\
  FROM people AS person\n\
       INNER JOIN addresses AS address \n\
         ON address.ID=person.addr\n\
 WHERE person.fname=\"Bob\"");
    //    BOOST_CHECK_EQUAL(sql::SQLQuery::MappedEquivalence(*expected.root), *tested.root);
}

