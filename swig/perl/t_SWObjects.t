#!/usr/bin/perl

use SWObjects;
use Test::Simple tests => 14;

my $SKIP = \ "SKIP";

ok( 1,     'test test'    );

sub timeout {
    my ($f, $timeout, $failure) = @_;
    eval {
        local $SIG{ALRM} = sub { die $failure };
        alarm $timeout;
	# `sleep $timeout`; # force timeout for testing
	$f->();
        alarm 0;
    };
    if ($@) {
	if ($@ =~ m/^$failure/) {
	    ok(1, $failure);
	    die $SKIP;
	} else {
	    die $@;
	}
    }
}

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
    my $tparser = new SWObjects::TurtleDriver("", $F);
    # Instruct the parser to insert data into the default graph.
    # Shortcut: undef = SWObjects.cvar.DefaultGraph
    $tparser->setGraph($parsedDB->ensureGraph(undef));
    # Parse a turtle string with an IStreamContext.
    $tparser->parse(new SWObjects::IStreamContext(
			"<s> <p1> <o1> ; <p2> <o2> ; <p2> <o3> .",
			$SWObjects::StreamContextIstream::STRING));
    # print "parsedDB: ", $parsedDB->toString();
    ok($manualDB == $parsedDB, 'DB eqivalance');

    my $different = new SWObjects::RdfDB();
    # Shortcut: parse strings without the IStreamContext.
    # Shortcut: let TurtleDriver parse directly to default graph in a DB.
    $tparser->parse("<s2> <p1> <o1> ; <p2> <o2> .", $different);
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
	my $tparser = new SWObjects::TrigDriver("", $F);
	$tparser->parse("{ <s> <p1> <o1> . } <g> { <s> <p2> <o2> . }", $parsedDB);
	# print "parsedDB: ", $parsedDB->toString();
	ok($manualDB == $parsedDB, 'trig DB eqivalance');

	my $different = new SWObjects::RdfDB();
	$tparser->parse("<g> { <s> <p1> <o1> . } { <s> <p2> <o2> . }", $different);
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
    my $tparser = new SWObjects::TurtleDriver("", $F);
    $tparser->parse("<s> <p1> <o1> ; <p2> <o2> .", $DB);
    # print "DB: ", $DB->toString();
    my $rs = new SWObjects::ResultSet($F);
    # Parse simple query strings with a SPARQLDriver.
    new SWObjects::SPARQLDriver("", $F)->executeSelect("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }", $DB, $rs);
    my $bnodereps = new SWObjects::BNode2string();
    my $bnodeMap = new SWObjects::String2BNode();
    my $reference = new SWObjects::ResultSet($F, new SWObjects::IStreamContext("
    # Results for T1.
┌──────┬──────┬─────┐
│ ?o1  │ ?o2  │ ?s  │
│ <o1> │ <o2> │ <s> │
└──────┴──────┴─────┘
", $SWObjects::StreamContextIstream::STRING, "text/sparql-results"), 0, $bnodeMap);
    ok($reference == $rs, 'result equivalence');

    my $different = new SWObjects::ResultSet($F, new SWObjects::IStreamContext("
# NOT results for T1.
+------+------+------+
| ?o1  | ?o2  | ?s   |
| <o1> | <o2> | <s2> |
+------+------+------+
", $SWObjects::StreamContextIstream::STRING, "text/sparql-results"), 0, $bnodeMap);
    ok($different != $rs, 'result difference');
}

sub test_remote {
    # Test a query.
    my $F = new SWObjects::AtomFactory();

    my $agent = new SWObjects::WEBagent_boostASIO();
    my $xmlParser = new SWObjects::SAXparser_expat();
    my $DB = new SWObjects::RdfDB($agent, $xmlParser);
    my $sparser = new SWObjects::SPARQLDriver("", $F);
    my $srvc = 'http://api.talis.com/stores/space/services/sparql';
    # Parsing can be done from a FILE or a STRING (shown below).
    # The StreamContextIstream.STRING argument is eqivalent to parse("...").
    my $query = $sparser->parse(new SWObjects::IStreamContext("
PREFIX foaf: <http://xmlns.com/foaf/0.1/>
SELECT ?craft ?homepage
 WHERE {
  SERVICE <$srvc> {
    ?craft foaf:name \"Apollo 8\" .
    ?craft foaf:homepage ?homepage
  }
}", $SWObjects::StreamContextIstream::STRING));
    my $rs = new SWObjects::ResultSet($F);

    # Try remote query with a timeout of 1s.
    &timeout(sub { $query->execute($DB, $rs) }, 1,
	     "timeout querying remote SPARQL service");

    my $bnodeMap = new SWObjects::String2BNode();
    my $reference = new SWObjects::ResultSet($F, "
# name and homepage of Apollo 8
?craft                                               ?homepage
<http://nasa.dataincubator.org/spacecraft/1968-118A> <http://nssdc.gsfc.nasa.gov/database/MasterCatalog?sc=1968-118A>
", 0, $bnodeMap);
    ok($reference == $rs, 'remote query');
}

sub test_update {
    # Test update .
    my $F = new SWObjects::AtomFactory();

    $updatedDB = new SWObjects::RdfDB();
    my $sparser = new SWObjects::SPARQLDriver("", $F);
    my $query = $sparser->parse("INSERT DATA { <s> <p1> <o1> ; <p2> <o2> }");
    # my $s = new SWObjects::SPARQLSerializer();
    # $query->express($s);
    # print "parsed: ", $s->str();
    my $rs = new SWObjects::ResultSet($F);
    $rs->setRdfDB($updatedDB);
    $query->execute($updatedDB, $rs);

    $referenceDB = new SWObjects::RdfDB();
    my $tparser = new SWObjects::TurtleDriver("", $F);
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
    my $sparser = new SWObjects::SPARQLDriver("", $F);
    my $query = $sparser->parse("CONSTRUCT { ?s ?p <o2> ; <p2> <o3> } WHERE { ?s ?p ?o }");
    # my $s = new SWObjects::SPARQLSerializer();
    # $query->express($s);
    # print "parsed: ", $s->str();
    my $rs = new SWObjects::ResultSet($F);

    # We're expecting a CONSTRUCT, so give the ResultSet a fresh database
    # for storing the constructed triples.
    ok($query->getOperationType() == $SWObjects::Operation::OPTYPE_construct, 'query enums');
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

sub test_parser_exception {
    # Test SPARQL parser exception .
    my $F = new SWObjects::AtomFactory();
    my $sparser = new SWObjects::SPARQLDriver("", $F);
    my $istr = new SWObjects::IStreamContext(
	    "SELECT * WHERE ~~~",
	    $SWObjects::StreamContextIstream::STRING);
    eval {
	$sparser->parse($istr);
	ok(0, 'no error parsing bogus SPARQL query');
    };
    ok($@ eq "ValueError SELECT * WHERE ~~~:1.16: unexpected input: '~'\n", "parser exceptions");
}

my @T = (
    "test_constants"       ,
    "test_type_integrity"  ,
    "test_turtleParser"    ,
    "test_trigParser"      ,
    "test_s_p1_o1_p2_o2"   ,
    "test_remote"          ,
    "test_update"          ,
    "test_construct"       ,
    "test_parser_exception"
);

foreach (@T) {
    eval {
	&{$_}();
    }; if ($@ && $@ != $SKIP) {
	ok(0, "error running $_");
	$@ = undef;
    }
}

