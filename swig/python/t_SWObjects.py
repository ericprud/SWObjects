#!/usr/bin/python
# 
# 

import unittest
import SWObjects

class TestSWObjects(unittest.TestCase):

    def setUp(self):
        11

    def test_constants(self):
        # Test access to constants.
        self.assertEqual(SWObjects.cvar.NS_xml, "http://www.w3.org/XML/1998/namespace")

    def test_type_integrity(self):
        DB = SWObjects.RdfDB()
        self.assertRaises(TypeError, DB.assureGraph, "blah")

    def test_turtleParser(self):
        # Test Turtle parser .
        F = SWObjects.POSFactory()
        manualDB = SWObjects.RdfDB()
        manDefault = manualDB.assureGraph(SWObjects.cvar.DefaultGraph)
        manDefault.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p1"), 
                F.getURI("o1")
                ))
        manDefault.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p2"), 
                F.getURI("o2")
                ))
        # print "manualDB: ", manualDB.toString()
        parsedDB = SWObjects.RdfDB()
        tparser = SWObjects.TurtleSDriver("", F)
        tparser.setGraph(parsedDB.assureGraph(SWObjects.cvar.DefaultGraph))
        tparser.parse(SWObjects.IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
                                               SWObjects.StreamContextIstream.STRING))
        # print "parsedDB: ", parsedDB.toString()
        self.assertEqual(manualDB, parsedDB)

        different = SWObjects.RdfDB()
        tparser.setGraph(different.assureGraph(SWObjects.cvar.DefaultGraph))
        tparser.parse(SWObjects.IStreamContext("<s2> <p1> <o1> ; <p2> <o2> .",
                                               SWObjects.StreamContextIstream.STRING))
        # print "different: ", different.toString()
        self.assertNotEqual(parsedDB, different)


    def test_s_p1_o1_p2_o2(self):
        # Test a query.
        F = SWObjects.POSFactory()
        DB = SWObjects.RdfDB()
        tparser = SWObjects.TurtleSDriver("", F)
        tparser.setGraph(DB.assureGraph(SWObjects.cvar.DefaultGraph))
        tparser.parse(SWObjects.IStreamContext("<s> <p1> <o1> ; <p2> <o2> .",
                                               SWObjects.StreamContextIstream.STRING))
        # print "DB: ", DB.toString()
        sparser = SWObjects.SPARQLfedDriver("", F)
        sparser.parse(SWObjects.IStreamContext("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }",
                                               SWObjects.StreamContextIstream.STRING))
        query = sparser.root
        # s = SWObjects.SPARQLSerializer()
        # query.express(s)
        # print "parsed: ", s.str()
        rs = SWObjects.ResultSet(F)
        query.execute(DB, rs)
        bnodereps = SWObjects.BNode2string()
        bnodeMap = SWObjects.String2BNode()
        reference = SWObjects.ResultSet(F, """
# Results for T1.
+------+------+-----+
| ?o1  | ?o2  | ?s  |
| <o1> | <o2> | <s> |
+------+------+-----+
""", False, bnodeMap);
        self.assertEqual(reference, rs)

        different = SWObjects.ResultSet(F, """
# Results for T1.
+------+------+------+
| ?o1  | ?o2  | ?s   |
| <o1> | <o2> | <s2> |
+------+------+------+
""", False, bnodeMap);
        self.assertNotEqual(different, rs)


if __name__ == '__main__':
    unittest.main()

