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
#include <boost/test/unit_test.hpp>

using namespace w3c_sw;

template<typename LEFT, typename RIGHT>
inline bool _ptrequal(LEFT lit, LEFT end, RIGHT rit) {
    LINE;
    for (; lit != end; ++lit, ++rit) {
	LINE;
	sql::AliasedSelect* l = *lit;
	sql::AliasedSelect* r = *rit;
	LINE << l->str() << std::endl;
	LINE << r->str() << std::endl;
	if (!(**lit == **rit)) {
	    LINE;
	    return false;
	}
    }
    LINE;
    return true;
}

#if 0
bool w3c_sw::sql::SQLQuery::finalEq (const SQLQuery& ref) const {
    // The many ifs make it easy to follow in a debugger.
    if (distinct != ref.distinct) return false;
    if (limit != ref.limit) return false;
    if (offset != ref.offset) return false;
    if (!ptrequal(selects.begin(), selects.end(), ref.selects.begin())) return false;
    if (!ptrequal(joins.begin(), joins.end(), ref.joins.begin())) return false;
    if (!ptrequal(constraints.begin(), constraints.end(), ref.constraints.begin())) return false;
    if (!ptrequal(orderBy.begin(), orderBy.end(), ref.orderBy.begin())) return false;
    return true;
}
#endif

struct EqTest {
    sqlContext context;
    SQLDriver driver;
    IStreamContext str1;
    IStreamContext str2;
    sql::SQLQuery* q1;
    sql::SQLQuery* q2;
    EqTest (const char* q) : context(), driver(context), str1(q, IStreamContext::STRING), str2(q, IStreamContext::STRING) {
	BOOST_CHECK_EQUAL(0, driver.parse(str1));
	q1 = driver.root;
	BOOST_CHECK_EQUAL(0, driver.parse(str2));
	q2 = driver.root;
    }
};

#define EQTEST(NAME,STR) BOOST_AUTO_TEST_CASE(NAME) {	\
	EqTest t(STR);					\
	BOOST_CHECK_EQUAL(*t.q1, *t.q2);		\
    }
EQTEST(SelExprEq11, "SELECT 1=1");
EQTEST(SelExprNe11, "SELECT 1!=1");
EQTEST(SelExprLt11, "SELECT 1<1");
EQTEST(SelExprGt11, "SELECT 1>1");
EQTEST(SelExprLe11, "SELECT 1<=1");
EQTEST(SelExprGe11, "SELECT 1>=1");
EQTEST(SqlExprEq12, "SELECT 1=2");
EQTEST(ConstAsAttr, "SELECT 1 AS attr");
EQTEST(From, "SELECT rel.attr FROM rel");
EQTEST(AttrAsAttr, "SELECT rel.attr AS attr FROM rel");
EQTEST(FromAs, "SELECT relvar.attr FROM rel AS relvar");
EQTEST(FromWhereEq11, "SELECT rel.attr FROM rel WHERE 1=2");
EQTEST(FromWhereEqAttr1, "SELECT rel.attr FROM rel WHERE rel.attr=2");
EQTEST(FromWhereEq1Attr, "SELECT rel.attr FROM rel WHERE 2=rel.attr");
EQTEST(FromWherePlus11, "SELECT rel.attr FROM rel WHERE 1+2");
EQTEST(FromWhereMinus11, "SELECT rel.attr FROM rel WHERE 1-2");
EQTEST(FromWhereNegation, "SELECT rel.attr FROM rel WHERE -1+-2");
EQTEST(FromWhereSumation, "SELECT rel.attr FROM rel WHERE 1+2=3");
EQTEST(FromWhereArith, "SELECT rel.attr FROM rel WHERE 1*2+3*4/5-6-(7*8)");
EQTEST(AttrAsAttrFromAsWhere, "SELECT relvar.attr FROM rel AS relvar WHERE 1=2");
EQTEST(AttrAsAttrFromAsOn, "SELECT relvar1.attr FROM rel AS relvar1 INNER JOIN rel AS relvar2 ON relvar1.attr=relvar2.attr");
EQTEST(Union, "SELECT union1.attr FROM (SELECT relvar1.attr FROM rel AS relvar1 UNION SELECT relvar2.attr FROM rel AS relvar2) AS union1");
EQTEST(JoinUnion, "SELECT union1.attr FROM rel AS relvar1 INNER JOIN (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1");
EQTEST(JoinUnionOn, "SELECT union1.attr FROM rel AS relvar1 INNER JOIN (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 ON union1.attr=relvar1.attr");
EQTEST(UnionJoin, "SELECT union1.attr FROM (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 INNER JOIN rel AS relvar1");
EQTEST(UnionJoinOn, "SELECT union1.attr FROM (SELECT relvar2.attr FROM rel AS relvar2 UNION SELECT relvar3.attr FROM rel AS relvar3) AS union1 INNER JOIN rel AS relvar1 ON relvar1.attr=union1.attr");


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

    IStreamContext str1(qs1, IStreamContext::STRING);
    BOOST_CHECK_EQUAL(0, driver.parse(str1));
    sql::SQLQuery* q1 = driver.root;

    IStreamContext str2(qs1, IStreamContext::STRING);
    BOOST_CHECK_EQUAL(0, driver.parse(str2));
    sql::SQLQuery* q2 = driver.root;

    BOOST_CHECK_EQUAL(*q1, *q2);
    delete q2;

    IStreamContext str3(qs2, IStreamContext::STRING);
    BOOST_CHECK_EQUAL(0, driver.parse(str3));
    sql::SQLQuery* q3 = driver.root;

    BOOST_CHECK(!(*q1 == *q3));
    delete q3;
    delete q1;
}

