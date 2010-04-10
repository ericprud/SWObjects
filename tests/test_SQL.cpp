#include "SQL.hpp"
#include "SQLParser/SQLParser.hpp"

int main(int , char** ) {
    sql_parser::sqlContext context;
    sql_parser::Driver driver(context);
//     driver.trace_scanning = true;
//     driver.trace_parsing = true;

    // std::stringstream s("SELECT relvar.attr1 AS relvar1Attr1 FROM rel1 AS relvar1");
    // std::stringstream s("SELECT relvar.attr1 AS relvar1Attr1 FROM rel1 AS relvar1 INNER JOIN rel2 AS relvar2 ON relvar2.attr2=relvar1.attr1");
//     std::stringstream s("SELECT relvar.attr1 AS relvar1Attr1"
// 			" FROM rel1 AS relvar1"
// 			" WHERE relvar1.attr2<relvar1.attr1 AND relvar1.attr2=relvar1.attr1");
//     std::stringstream s("SELECT CONCAT(\"a\", 1, relvar.attr1) AS relvar1Attr1, \"a\" AS x"
// 			" FROM rel1 AS relvar1"
// 			" INNER JOIN rel2 AS relvar2 ON relvar2.attr2=relvar1.attr1"
// 			" INNER JOIN rel3 AS relvar3 ON relvar3.attr3=relvar2.attr2"
// 			"            AND (relvar3.attr1!=relvar1.attr1 OR relvar3.attr1=relvar1.attr1)"
// 			//"LIMIT 3 ORDER BY relvar1Attr1"
// 			);
//     std::stringstream s("SELECT 7 8 9");
//    std::stringstream s(" SELECT _union1.somePerson AS somePerson FROM (  SELECT 1 AS _DISJOINT_) AS _union1");
    std::stringstream s("SELECT union1.somePerson AS somePerson\n"
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
			"             ) AS union1");
    int result;
    try {
	result = driver.parse_stream(s, std::string("-internal string-"));
	std::cout << "final: " << driver.root->toString() << std::endl;
	delete driver.root;
    } catch (std::string msg) {
	std::cerr << "SQL parser error: " << msg << std::endl;
	result = -1;
    } catch (char const* msg) {
	std::cerr << "ERROR: " << msg << std::endl;
	result = -1;
    }
    return result;
}

