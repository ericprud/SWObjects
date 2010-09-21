import junit.framework.*;

public class t_SWObjects extends TestCase {

    protected void setUp() {
	System.loadLibrary("SWObjects");
    }

    protected void tearDown() {  }

    public void test_constants() {
  	assertEquals(SWObjects.getNS_xml(), "http://www.w3.org/XML/1998/namespace");
    }

    public void test_type_integrity () {
        RdfDB DB = new RdfDB();
	// try {
	//     DB.ensureGraph("blah");
	// }
	// catch (NullPointerException npe) {
	//     return;
	// }
	// fail("Expected NullPointerException");
    }

    public void test_turtleParser () {
        // Test Turtle parser .
        AtomFactory F = new AtomFactory();
        RdfDB manualDB = new RdfDB();
	// Get the default graph from the database.
        BasicGraphPattern manDefault = manualDB.ensureGraph(SWObjects.getDefaultGraph());
	// You can create a Triple from specific terms which you get from the AtomFactory.
        manDefault.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p1"), 
                F.getURI("o1")
                ));
	String2BNode bnodeMap = new String2BNode();
	// or you can parse NTriplePatterns:
	F.parseNTPatterns(manDefault,
			  "<s> <p2> <o2> ." +
			  "<s> <p2> <o3> .", bnodeMap);
        // print "manualDB: ", manualDB.toString();
        RdfDB parsedDB = new RdfDB();
        TurtleSDriver tparser = new TurtleSDriver("", F);
        // Instruct the parser to insert data into the default graph.
        // Shortcut: null = SWObjects.cvar.DefaultGraph
        tparser.setGraph(parsedDB.ensureGraph(null));
        // Parse a turtle string with an IStreamContext.
        tparser.parse(new IStreamContext(
                "<s> <p1> <o1> ; <p2> <o2> ; <p2> <o3> .",
		StreamContextIstream.e_opts.STRING));
        // print "parsedDB: ", parsedDB.toString();
        assertTrue(manualDB.equals(parsedDB));

        RdfDB different = new RdfDB();
        // Shortcut: parse strings without the IStreamContext.
        // Shortcut: let TurtleSDriver parse directly to default graph in a DB.
        tparser.parse("<s2> <p1> <o1> ; <p2> <o2> ; <p2> <o2> .", different);
        // print "different: ", different.toString();
	assertFalse(different.equals(parsedDB));
    }


    public void test_trigParser () {
        // Test Trig parser .
        AtomFactory F = new AtomFactory();
        RdfDB manualDB = new RdfDB();
        BasicGraphPattern manDefault = manualDB.ensureGraph(null);
        String2BNode bnodeMap = new String2BNode();
        F.parseNTPatterns(manDefault, "<s> <p1> <o1> .", bnodeMap);
        BasicGraphPattern manG = manualDB.ensureGraph(F.getURI("g"));
        F.parseNTPatterns(manG, "<s> <p2> <o2> .", bnodeMap);
        // print "manualDB: ", manualDB.toString();
        RdfDB parsedDB = new RdfDB();
        TrigSDriver tparser = new TrigSDriver("", F);
        tparser.parse("{ <s> <p1> <o1> . } <g> { <s> <p2> <o2> . }", parsedDB);
        // print "parsedDB: ", parsedDB.toString();
        assertTrue(manualDB.equals(parsedDB));

        RdfDB different = new RdfDB();
        tparser.parse("<g> { <s> <p1> <o1> . } { <s> <p2> <o2> . }", different);
        // print "different: ", different.toString();
	assertFalse(different.equals(parsedDB));
    }


    public void test_s_p1_o1_p2_o2 () {
        // Test a query.
        AtomFactory F = new AtomFactory();
        RdfDB DB = new RdfDB();
        TurtleSDriver tparser = new TurtleSDriver("", F);
        tparser.parse("<s> <p1> <o1> ; <p2> <o2> .", DB);
        // print "DB: ", DB.toString();
        ResultSet rs = new ResultSet(F);
        // Parse simple query strings with a SPARQLfedDriver.
        new SPARQLfedDriver("", F).executeSelect("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }", DB, rs);
        BNode2string bnodereps = new BNode2string();
        String2BNode bnodeMap = new String2BNode();
        ResultSet reference = new ResultSet(F,
						  "# Results for T1.\n" +
						  "+------+------+-----+\n" +
						  "| ?o1  | ?o2  | ?s  |\n" +
						  "| <o1> | <o2> | <s> |\n" +
						  "+------+------+-----+\n",
						  false, bnodeMap);
        assertTrue(reference.equals(rs));

        ResultSet different = new ResultSet(F,
						  "# NOT results for T1.\n" +
						  "+------+------+------+\n" +
						  "| ?o1  | ?o2  | ?s   |\n" +
						  "| <o1> | <o2> | <s2> |\n" +
						  "+------+------+------+\n",
						  false, bnodeMap);
	assertFalse(different.equals(rs));
    }

    public void test_update () {
        // Test update .
	AtomFactory F = new AtomFactory();

        RdfDB updatedDB = new RdfDB();
        SPARQLfedDriver sparser = new SPARQLfedDriver("", F);
        sparser.parse(new IStreamContext(
                "INSERT { <s> <p1> <o1> ; <p2> <o2> }",
		StreamContextIstream.e_opts.STRING));
        Operation query = sparser.getRoot();
        // SPARQLSerializer s = SPARQLSerializer();
        // query.express(s);
        // print "parsed: ", s.str();
        ResultSet rs = new ResultSet(F);
        //rs.setRdfDB(updatedDB);
        query.execute(updatedDB, rs);

        RdfDB referenceDB = new RdfDB();
        TurtleSDriver tparser = new TurtleSDriver("", F);
        tparser.setGraph(referenceDB.ensureGraph(null));
        tparser.parse(new IStreamContext(
                "<s> <p1> <o1> ; <p2> <o2> .",
		StreamContextIstream.e_opts.STRING));
        assertTrue(referenceDB.equals(updatedDB));
    }

    public void test_construct () {
        // Test CONSTRUCT .
	AtomFactory F = new AtomFactory();

        RdfDB sourceDB = new RdfDB();
        BasicGraphPattern manDefault = sourceDB.ensureGraph(null);
        String2BNode bnodeMap = new String2BNode();
	F.parseNTPatterns(manDefault, "<s> <p1> <o1> .", bnodeMap);
        SPARQLfedDriver sparser = new SPARQLfedDriver("", F);
        sparser.parse(new IStreamContext(
                "CONSTRUCT { ?s ?p <o2> ; <p2> <o3> } WHERE { ?s ?p ?o }",
		StreamContextIstream.e_opts.STRING));
        Operation query = sparser.getRoot();
        // SPARQLSerializer s = SPARQLSerializer();
        // query.express(s);
        // print "parsed: ", s.str();
        ResultSet rs = new ResultSet(F);

        // We're expecting a CONSTRUCT, so give the ResultSet a fresh database
        // for storing the constructed triples.
        assertTrue(query.getOperationType().equals(Operation.e_OPTYPE.OPTYPE_construct));
        RdfDB constructDB = new RdfDB();
        rs.setRdfDB(constructDB);

        query.execute(sourceDB, rs);

        RdfDB expectedDB = new RdfDB();
	F.parseNTPatterns(expectedDB.ensureGraph(null),
			  "<s> <p1> <o2> ." +
			  "<s> <p2> <o3> .", bnodeMap);
        assertTrue(expectedDB.equals(constructDB));
    }

}

