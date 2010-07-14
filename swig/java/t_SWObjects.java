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
	//     DB.assureGraph("blah");
	// }
	// catch (NullPointerException npe) {
	//     return;
	// }
	// fail("Expected NullPointerException");
    }

    public void test_turtleParser () {
        // Test Turtle parser .
        POSFactory F = new POSFactory();
        RdfDB manualDB = new RdfDB();
        BasicGraphPattern manDefault = manualDB.assureGraph(SWObjects.getDefaultGraph());
        manDefault.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p1"), 
                F.getURI("o1")
                ));
        manDefault.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p2"), 
                F.getURI("o2")
                ));
        // print "manualDB: ", manualDB.toString();
        RdfDB parsedDB = new RdfDB();
        TurtleSDriver tparser = new TurtleSDriver("", F);
        tparser.setGraph(parsedDB.assureGraph(SWObjects.getDefaultGraph()));
        tparser.parse(new IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
					 StreamContextIstream.e_opts.STRING));
        // print "parsedDB: ", parsedDB.toString();
        assertTrue(manualDB.equals(parsedDB));

        RdfDB different = new RdfDB();
        tparser.setGraph(different.assureGraph(SWObjects.getDefaultGraph()));
        tparser.parse(new IStreamContext("<s2> <p1> <o1> ; <p2> <o2> .",
					 StreamContextIstream.e_opts.STRING));
        // print "different: ", different.toString();
	assertFalse(different.equals(parsedDB));
    }


    public void test_trigParser () {
        // Test Trig parser .
        POSFactory F = new POSFactory();
        RdfDB manualDB = new RdfDB();
        BasicGraphPattern manDefault = manualDB.assureGraph(SWObjects.getDefaultGraph());
        manDefault.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p1"), 
                F.getURI("o1")
                ));
        BasicGraphPattern manG = manualDB.assureGraph(F.getURI("g"));
        manG.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p2"), 
                F.getURI("o2")
                ));
        // print "manualDB: ", manualDB.toString();
        RdfDB parsedDB = new RdfDB();
        TrigSDriver tparser = new TrigSDriver("", F);
        tparser.setDB(parsedDB);
        tparser.parse(new IStreamContext("{ <s> <p1> <o1> . } <g> { <s> <p2> <o2> . }",
					 StreamContextIstream.e_opts.STRING));
        // print "parsedDB: ", parsedDB.toString();
        assertTrue(manualDB.equals(parsedDB));

        RdfDB different = new RdfDB();
        tparser.setDB(different);
        tparser.parse(new IStreamContext("<g> { <s> <p1> <o1> . } { <s> <p2> <o2> . }",
					 StreamContextIstream.e_opts.STRING));
        // print "different: ", different.toString();
	assertFalse(different.equals(parsedDB));
    }


    public void test_s_p1_o1_p2_o2 () {
        // Test a query.
        POSFactory F = new POSFactory();
        RdfDB DB = new RdfDB();
        TurtleSDriver tparser = new TurtleSDriver("", F);
        tparser.setGraph(DB.assureGraph(SWObjects.getDefaultGraph()));
        tparser.parse(new IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
                                               StreamContextIstream.e_opts.STRING));
        // print "DB: ", DB.toString();
        SPARQLfedDriver sparser = new SPARQLfedDriver("", F);
        sparser.parse(new IStreamContext("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }",
                                               StreamContextIstream.e_opts.STRING));
        Operation query = sparser.getRoot();
        // s = new SPARQLSerializer();
        // query.express(s);
        // print "parsed: ", s.str();
        ResultSet rs = new ResultSet(F);
        query.execute(DB, rs);
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
						  "# Results for T1.\n" +
						  "+------+------+------+\n" +
						  "| ?o1  | ?o2  | ?s   |\n" +
						  "| <o1> | <o2> | <s2> |\n" +
						  "+------+------+------+\n",
						  false, bnodeMap);
	assertFalse(different.equals(rs));
    }

    public void test_update () {
        // Test update .
	POSFactory F = new POSFactory();

        RdfDB updatedDB = new RdfDB();
        SPARQLfedDriver sparser = new SPARQLfedDriver("", F);
        sparser.parse(new IStreamContext("INSERT { <s> <p1> <o1> ; <p2> <o2> }",
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
        tparser.setGraph(referenceDB.assureGraph(SWObjects.getDefaultGraph()));
        tparser.parse(new IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
					 StreamContextIstream.e_opts.STRING));
        assertTrue(referenceDB.equals(updatedDB));
    }

}

