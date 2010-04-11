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

BOOST_AUTO_TEST_CASE( SQL1 ) {
    sqlContext context;
    SQLDriver driver(context);
    IStreamContext istr("SELECT union1.somePerson AS somePerson\n"
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
			"             ) AS union1", IStreamContext::STRING);
    int result = driver.parse(istr);
    std::cout << "final: " << driver.root->toString() << std::endl;
    delete driver.root;
    BOOST_CHECK_EQUAL(result, 0);
}

