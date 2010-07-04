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
                F.getURI(SWObjects.string("s", 1)), 
                F.getURI(SWObjects.string("p1", 2)), 
                F.getURI(SWObjects.string("o1", 2))
                ))
        default.addTriplePattern(F.getTriple(
                F.getURI(SWObjects.string("s", 1)), 
                F.getURI(SWObjects.string("p2", 2)), 
                F.getURI(SWObjects.string("o2", 2))
                ))
        # print "DB: ", DB.toString().c_str()
        sparser = SWObjects.SPARQLfedDriver(SWObjects.string("", 1), F)
        query = SWObjects.SPARQLfedDriver.parseString("SELECT * { ?s <p1> ?o1 ; <p2> ?o2 }", F)
        # s = SWObjects.SPARQLSerializer()
        # query.express(s)
        # print "parsed: ", s.str().c_str()
        rs = SWObjects.ResultSet(F)
        query.execute(DB, rs)
        bnodeMap = SWObjects.String2BNode()
        s = SWObjects.string("", 0)
        print type(F), ",", type(s), ",", type(bnodeMap)
        reference = SWObjects.ResultSet(F, SWObjects.string("""+------+------+-----+
| ?o1  | ?o2  | ?s  |
| <o1> | <o2> | <s> |
+------+------+-----+
""", 89), False);
        self.assertEqual(reference, rs)

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

turtleParser = SWObjects.TurtleSDriver(SWObjects.string("http://example.org/", 19), F)
baseURI = SWObjects.string("", 1)
turtleParser.setBase(baseURI)

