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

    def test_s_p1_o1_p2_o2(self):
        # Test a query.
        F = SWObjects.POSFactory()
        DB = SWObjects.RdfDB()
        default = DB.assureGraph(SWObjects.cvar.DefaultGraph)
        default.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p1"), 
                F.getURI("o1")
                ))
        default.addTriplePattern(F.getTriple(
                F.getURI("s" ), 
                F.getURI("p2"), 
                F.getURI("o2")
                ))
        # print "DB: ", DB.toString().c_str()
        sparser = SWObjects.SPARQLfedDriver("", F)
        query = SWObjects.SPARQLfedDriver.parseString("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }", F)
        # s = SWObjects.SPARQLSerializer()
        # query.express(s)
        # print "parsed: ", s.str().c_str()
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
        # self.assertRaises(TypeError, reference.classString2BNode, bnodeMap)
        # self.assertRaises(TypeError, random.shuffle, (1,2,3))
        # self.assertTrue(element in self.seq)

if __name__ == '__main__':
    unittest.main()

# TODO:

# turtleParser.setGraph(x)
qstr = SWObjects.string("ASK {}", 1)
print "qstr, ", type(qstr)
e = SWObjects.StreamContextIstream.STRING
print "e, ", type(e)
istr = SWObjects.IStreamContext(qstr, e)
print "=> ", sparser.parse(istr)

turtleParser = SWObjects.TurtleSDriver("http://example.org/", F)
baseURI = ""
turtleParser.setBase(baseURI)

