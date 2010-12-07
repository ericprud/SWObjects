#!/usr/bin/php-cgi                                                                                                                                         
<?php
require_once('simpletest/unit_tester.php');
require_once('simpletest/reporter.php');
dl('swobjects.so');

class TestOfLogging extends UnitTestCase {
    function testCreatingNewFile() {
	# print_r(get_defined_functions());
	$f = new_atomfactory(); # really? that's pretty ugly.
    }
}
$test = &new TestOfLogging();
exit ($test->run(new TextReporter()) ? 0 : 1);
?>
