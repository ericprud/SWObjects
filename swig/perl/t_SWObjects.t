#!/usr/bin/perl

use SWObjects;
use Test::Simple tests => 5;

ok( 1,     'start'    );

sub test_constants {
# Test access to constants.
    ok($SWObjects::cvar::NS_xml eq "http://www.w3.org/XML/1998/namespace");
}

sub test_type_integrity {
    my $DB = &SWObjects::RdfDB();
    eval {
	$DB->assureGraph("blah");
    };
    ok($@, "type integrity");
}

sub test_turtleParser {
# Test Turtle parser .
    my $F = &SWObjects::POSFactory();
    my $manualDB = &SWObjects::RdfDB();
    my $manDefault = $manualDB->assureGraph($SWObjects::cvar::DefaultGraph);
    $manDefault->addTriplePattern($F->getTriple(
				      $F->getURI("s" ), 
				      $F->getURI("p1"), 
				      $F->getURI("o1")
				  ));
    $manDefault->addTriplePattern($F->getTriple(
				      $F->getURI("s" ), 
				      $F->getURI("p2"), 
				      $F->getURI("o2")
				  ));
# print "manualDB: ", $manualDB->toString()->c_str();
    $parsedDB = &SWObjects::RdfDB();
    my $tparser = &SWObjects::TurtleSDriver("", $F);
    $tparser->setGraph($parsedDB->assureGraph($SWObjects::cvar::DefaultGraph));
    $tparser->parse(&SWObjects::IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
					      $SWObjects::StreamContextIstream::STRING));
# print "parsedDB: ", $parsedDB->toString()->c_str();
    ok($manualDB == $parsedDB, 'DB eqivalance');

    my $different = &SWObjects::RdfDB();
    $tparser->setGraph($different->assureGraph($SWObjects::cvar::DefaultGraph));
    $tparser->parse(&SWObjects::IStreamContext("<s2> <p1> <o1> ; <p2> <o2> .",
					      $SWObjects::StreamContextIstream::STRING));
# print "different: ", different->toString()->c_str();
    ok($parsedDB != $different, 'DB difference');
}

sub test_s_p1_o1_p2_o2 {
# Test a query.
    my $F = &SWObjects::POSFactory();
    my $DB = &SWObjects::RdfDB();
    my $tparser = &SWObjects::TurtleSDriver("", $F);
    $tparser->setGraph($DB->assureGraph($SWObjects::cvar::DefaultGraph));
    $tparser->parse(&SWObjects::IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
					      $SWObjects::StreamContextIstream::STRING));
# print "DB: ", $DB->toString()->c_str();
    my $sparser = &SWObjects::SPARQLfedDriver("", $F);
    $sparser->parse(&SWObjects::IStreamContext("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }",
					      $SWObjects::StreamContextIstream::STRING));
    my $query = $sparser->root;
# my $s = &SWObjects::SPARQLSerializer();
# $query->express($s)
# print "parsed: ", $s->str()->c_str();
    my $rs = &SWObjects::ResultSet($F);
    $query->execute($DB, $rs);
    my $bnodereps = &SWObjects::BNode2string();
    my $bnodeMap = &SWObjects::String2BNode();
    my $reference = &SWObjects::ResultSet($F, "
# Results for T1.
+------+------+-----+
| ?o1  | ?o2  | ?s  |
| <o1> | <o2> | <s> |
+------+------+-----+
", 0, $bnodeMap);
    ok($reference == $rs, 'result equivalence');

    my $different = &SWObjects::ResultSet($F, "
# Results for T1.
+------+------+------+
| ?o1  | ?o2  | ?s   |
| <o1> | <o2> | <s2> |
+------+------+------+
", 0, $bnodeMap);
    ok($different != $rs, 'result difference');
}

&test_constants      ();
&test_type_integrity ();
&test_turtleParser   ();
&test_s_p1_o1_p2_o2  ();

