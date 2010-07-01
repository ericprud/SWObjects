#!/usr/bin/python
# file: runme.py
# Test various properties of classes defined in separate modules

print "Testing the %import directive"
import SWObjects

xmlns = SWObjects.cvar.NS_xml
print "xmlns= ", xmlns

ttl = "<s> <p> <o>"

F = SWObjects.POSFactory()
DB = SWObjects.RdfDB()
turtleParser = SWObjects.TurtleSDriver(SWObjects.string("http://example.org/", 1), F)

default = DB.assureGraph(SWObjects.cvar.DefaultGraph)
print "default: ", default

y = F.getTriple(
    F.getURI(SWObjects.string("s", 1)), 
    F.getURI(SWObjects.string("p", 1)), 
    F.getURI(SWObjects.string("o", 1))
)
default.addTriplePattern(y)
s = DB.toString()
print s.c_str()
print "y: ", y.toString().c_str()

exit()

# turtleParser.setGraph(x)
baseURI = SWObjects.string("", 1)
turtleParser.setBase(baseURI)

