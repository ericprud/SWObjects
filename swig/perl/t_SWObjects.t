#!/usr/bin/perl

use SWObjects;
use Test::Simple tests => 13;

ok( 1,     'test test'    );

sub test_constants {
    # Test access to constants.
    ok($SWObjects::NS_xml eq "http://www.w3.org/XML/1998/namespace", 'access to constants');
}

sub test_type_integrity {
    my $DB = new SWObjects::RdfDB();
    eval {
	$DB->ensureGraph("blah");
	ok(0, 'able to create an RdfDB with a string instead of a AtomFactory');
    };
    ok($@ eq "TypeError in method 'RdfDB_ensureGraph', argument 2 of type 'w3c_sw::TTerm const *'\n", "type integrity");
}

sub test_turtleParser {
    # Test Turtle parser .
    my $F = new SWObjects::AtomFactory();
    my $manualDB = new SWObjects::RdfDB();
    # Get the default graph from the database.
    my $manDefault = $manualDB->ensureGraph($SWObjects::DefaultGraph);
    # You can create a Triple from specific terms which you get from the AtomFactory.
    $manDefault->addTriplePattern($F->getTriple(
				      $F->getURI("s" ), 
				      $F->getURI("p1"), 
				      $F->getURI("o1")
				  ));
    my $bnodeMap = new SWObjects::String2BNode();
    # or you can parse NTriplePatterns:
    $F->parseNTPatterns($manDefault,
			"<s> <p2> <o2> ." .
			"<s> <p2> <o3> .", $bnodeMap);
    # print "manualDB: ", $manualDB->toString();
    $parsedDB = new SWObjects::RdfDB();
    my $tparser = new SWObjects::TurtleSDriver("", $F);
    # Shortcut: undef = SWObjects.cvar.DefaultGraph
    $tparser->setGraph($parsedDB->ensureGraph(undef));
    $tparser->parse(new SWObjects::IStreamContext(
			"<s> <p1> <o1> ; <p2> <o2> ; <p2> <o3> .",
			$SWObjects::StreamContextIstream::STRING));
    # print "parsedDB: ", $parsedDB->toString();
    ok($manualDB == $parsedDB, 'DB eqivalance');

    my $different = new SWObjects::RdfDB();
    $tparser->setGraph($different->ensureGraph(undef));
    $tparser->parse(new SWObjects::IStreamContext(
			"<s2> <p1> <o1> ; <p2> <o2> .",
			$SWObjects::StreamContextIstream::STRING));
    # print "different: ", different->toString();
    ok($parsedDB != $different, 'DB difference');
}

sub test_trigParser {
    my $F = new SWObjects::AtomFactory();
    my $manualDB = new SWObjects::RdfDB();
    my $manDefault = $manualDB->ensureGraph(undef);
    my $bnodeMap = new SWObjects::String2BNode();
    $F->parseNTPatterns($manDefault, "<s> <p1> <o1> .", $bnodeMap);
    my $manG = $manualDB->ensureGraph($F->getURI("g"));
    $F->parseNTPatterns($manG, "<s> <p2> <o2> .", $bnodeMap);
    # print "manualDB: ", $manualDB->toString();
    $parsedDB = new SWObjects::RdfDB();
    eval {
	my $tparser = new SWObjects::TrigSDriver("", $F);
	$tparser->setDB($parsedDB);
	$tparser->parse(new SWObjects::IStreamContext(
			    "{ <s> <p1> <o1> . } <g> { <s> <p2> <o2> . }",
			    $SWObjects::StreamContextIstream::STRING));
	# print "parsedDB: ", $parsedDB->toString();
	ok($manualDB == $parsedDB, 'trig DB eqivalance');

	my $different = new SWObjects::RdfDB();
	$tparser->setDB($different);
	$tparser->parse(new SWObjects::IStreamContext(
			    "<g> { <s> <p1> <o1> . } { <s> <p2> <o2> . }",
			    $SWObjects::StreamContextIstream::STRING));
	# print "different: ", different->toString();
	ok($parsedDB != $different, 'trig DB difference');
    }; if ($@) {
	ok(0, "got exception: $@");
    }
}

sub test_s_p1_o1_p2_o2 {
    # Test a query.
    my $F = new SWObjects::AtomFactory();
    my $DB = new SWObjects::RdfDB();
    my $tparser = new SWObjects::TurtleSDriver("", $F);
    $tparser->setGraph($DB->ensureGraph(undef));
    $tparser->parse(new SWObjects::IStreamContext(
			"<s> <p1> <o1> ; <p2> <o2> .",
			$SWObjects::StreamContextIstream::STRING));
    # print "DB: ", $DB->toString();
    my $sparser = new SWObjects::SPARQLfedDriver("", $F);
    $sparser->parse(new SWObjects::IStreamContext(
			"SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }",
			$SWObjects::StreamContextIstream::STRING));
    my $query = $sparser->{'root'};
    # my $s = &SWObjects::SPARQLSerializer();
    # $query->express($s)
    # print "parsed: ", $s->str();
    my $rs = new SWObjects::ResultSet($F);
    $query->execute($DB, $rs);
    my $bnodereps = new SWObjects::BNode2string();
    my $bnodeMap = new SWObjects::String2BNode();
    my $reference = new SWObjects::ResultSet($F, "
    # Results for T1.
+------+------+-----+
| ?o1  | ?o2  | ?s  |
| <o1> | <o2> | <s> |
+------+------+-----+
", 0, $bnodeMap);
    ok($reference == $rs, 'result equivalence');

    my $different = new SWObjects::ResultSet($F, "
# Results for T1.
+------+------+------+
| ?o1  | ?o2  | ?s   |
| <o1> | <o2> | <s2> |
+------+------+------+
", 0, $bnodeMap);
    ok($different != $rs, 'result difference');
}

sub test_remote {
    # Test a query.
    my $F = new SWObjects::AtomFactory();

    my $agent = new SWObjects::WEBagent_boostASIO();
    my $xmlParser = new SWObjects::SAXparser_expat();
    my $DB = new SWObjects::RdfDB($agent, $xmlParser);
    my $sparser = new SWObjects::SPARQLfedDriver("", $F);
    $sparser->parse(new SWObjects::IStreamContext("
PREFIX foaf: <http://xmlns.com/foaf/0.1/>
SELECT ?craft ?homepage
 WHERE {
  SERVICE <http://api.talis.com/stores/space/services/sparql> {
    ?craft foaf:name \"Apollo 8\" .
    ?craft foaf:homepage ?homepage
  }
}", $SWObjects::StreamContextIstream::STRING));
    my $query = $sparser->{'root'};
    my $rs = new SWObjects::ResultSet($F);
    $query->execute($DB, $rs);
    my $bnodeMap = new SWObjects::String2BNode();
    my $reference = new SWObjects::ResultSet($F, "
# name and homepage of Apollo 8
+------------------------------------------------------+------------------------------------------------------------------+
| ?craft                                               | ?homepage                                                        |
| <http://nasa.dataincubator.org/spacecraft/1968-118A> | <http://nssdc.gsfc.nasa.gov/database/MasterCatalog?sc=1968-118A> |
+------------------------------------------------------+------------------------------------------------------------------+
", 0, $bnodeMap);
    ok($reference == $rs, 'remote query');
}

sub test_update {
    # Test update .
    my $F = new SWObjects::AtomFactory();

    $updatedDB = new SWObjects::RdfDB();
    my $sparser = new SWObjects::SPARQLfedDriver("", $F);
    $sparser->parse(new SWObjects::IStreamContext(
			"INSERT { <s> <p1> <o1> ; <p2> <o2> }",
			$SWObjects::StreamContextIstream::STRING));
    my $query = $sparser->{'root'};
    # my $s = new SWObjects::SPARQLSerializer();
    # $query->express($s);
    # print "parsed: ", $s->str();
    my $rs = new SWObjects::ResultSet($F);
    $rs->setRdfDB($updatedDB);
    $query->execute($updatedDB, $rs);

    $referenceDB = new SWObjects::RdfDB();
    my $tparser = new SWObjects::TurtleSDriver("", $F);
    $tparser->setGraph($referenceDB->ensureGraph(undef));
    $tparser->parse(new SWObjects::IStreamContext(
			"<s> <p1> <o1> ; <p2> <o2> .",
			$SWObjects::StreamContextIstream::STRING));
    # print "referenceDB: ", $referenceDB->toString();
    ok($referenceDB == $updatedDB, 'update');
}

sub test_construct {
    # Test CONSTRUCT .
    my $F = new SWObjects::AtomFactory();

    my $sourceDB = new SWObjects::RdfDB();
    my $manDefault = $sourceDB->ensureGraph(undef);
    my $bnodeMap = new SWObjects::String2BNode();
    $F->parseNTPatterns($manDefault, "<s> <p1> <o1> .", $bnodeMap);
    my $sparser = new SWObjects::SPARQLfedDriver("", $F);
    $sparser->parse(new SWObjects::IStreamContext(
			"CONSTRUCT { ?s ?p <o2> ; <p2> <o3> } WHERE { ?s ?p ?o }",
			$SWObjects::StreamContextIstream::STRING));
    my $query = $sparser->{'root'};
    # my $s = new SWObjects::SPARQLSerializer();
    # $query->express($s);
    # print "parsed: ", $s->str();
    my $rs = new SWObjects::ResultSet($F);

    # We're expecting a CONSTRUCT, so give the ResultSet a fresh database
    # for storing the constructed triples.
    ok($query->getOperationType() == $SWObjects::Operation::CONSTRUCT, 'query enums');
    my $constructDB = new SWObjects::RdfDB();
    $rs->setRdfDB($constructDB);

    $query->execute($sourceDB, $rs);

    # Expected results:
    my $expectedDB = new SWObjects::RdfDB();
    $F->parseNTPatterns($expectedDB->ensureGraph(undef),
			"<s> <p1> <o2> ." .
			"<s> <p2> <o3> .", $bnodeMap);
    ok($expectedDB == $constructDB, 'CONSTRUCT results');
}

&test_constants      ();
&test_type_integrity ();
&test_turtleParser   ();
&test_trigParser     ();
&test_s_p1_o1_p2_o2  ();
&test_remote         ();
&test_update         ();
&test_construct      ();
