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

const char* qs0 = "SELECT 1=1\n";
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
BOOST_AUTO_TEST_CASE( SQL0 ) {
    sqlContext context;
    SQLDriver driver(context);

    IStreamContext str1(qs0, IStreamContext::STRING);
    BOOST_CHECK_EQUAL(0, driver.parse(str1));
    sql::SQLQuery* q1 = driver.root;

    IStreamContext str2(qs0, IStreamContext::STRING);
    BOOST_CHECK_EQUAL(0, driver.parse(str2));
    sql::SQLQuery* q2 = driver.root;

    BOOST_CHECK_EQUAL(*q1, *q2);
    delete q2;
    delete q1;
}

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

