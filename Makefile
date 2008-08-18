# $Id: Makefile,v 1.25 2008-08-18 14:20:34 eric Exp $

# recipies:
#   normal build:
#     make SPARQLfed
#   force the use of the tracing facilities (and redirect to stdout):
#     make -W sample_RuleMap1.cc test
#   have valgrind start a debugger (works as M-x gdb invocation command):
#     valgrind --db-attach=yes --leak-check=yes sample_RuleMap1 SPARQLfed.txt
#   same, if you aren't working in gdb:
#     make valgrind
#   debugging in emacs:
#     gdb --annotate=3 sample_RuleMap1    (set args SPARQLfed.txt)

LIBS=
DEFS=

GPP=g++ -DYYTEXT_POINTER=1 $(DEFS) -W -Wall -Wextra -ansi -g -c
LINK=g++ -W -Wall -Wextra -ansi -g $(LIBS) -o

# Core objects

SWObjects.o: SWObjects.cc SWObjects.hh
	$(GPP)  -o SWObjects.o SWObjects.cc

ResultSet.o: ResultSet.cc ResultSet.hh XMLSerializer.hh
	$(GPP)  -o ResultSet.o ResultSet.cc

RdfDB.o: RdfDB.cc RdfDB.hh XMLSerializer.hh
	$(GPP)  -o RdfDB.o RdfDB.cc

RdfQueryDB.o: RdfQueryDB.cc RdfQueryDB.hh RdfDB.hh
	$(GPP)  -o RdfQueryDB.o RdfQueryDB.cc

XMLQueryExpressor.hh: XMLSerializer.hh # !!! doesn't seem to trigger XQE's dependencies


# yacc parsers

ParserCommon.o: ParserCommon.cc ParserCommon.hh
	$(GPP)  -o ParserCommon.o ParserCommon.cc

## SPARQLfed
SPARQLfedParser.cc SPARQLfedParser.hh location.hh position.hh stack.hh: SPARQLfedParser.yy SWObjects.hh ParserCommon.hh
	bison -o SPARQLfedParser.cc SPARQLfedParser.yy

SPARQLfedScanner.cc: SPARQLfedScanner.ll SPARQLfedParser.hh
	flex -o SPARQLfedScanner.cc SPARQLfedScanner.ll

SPARQLfedParser.o: SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.hh
	$(GPP)  -o SPARQLfedParser.o SPARQLfedParser.cc

SPARQLfedScanner.o: SPARQLfedScanner.cc SPARQLfedScanner.hh
	$(GPP)  -o SPARQLfedScanner.o SPARQLfedScanner.cc

## TurtleS
TurtleSParser.cc TurtleSParser.hh: TurtleSParser.yy SWObjects.hh
	bison -o TurtleSParser.cc TurtleSParser.yy

TurtleSScanner.cc: TurtleSScanner.ll TurtleSParser.hh
	flex -o TurtleSScanner.cc TurtleSScanner.ll

TurtleSParser.o: TurtleSParser.cc TurtleSParser.hh TurtleSScanner.hh
	$(GPP)  -o TurtleSParser.o TurtleSParser.cc

TurtleSScanner.o: TurtleSScanner.cc TurtleSScanner.hh
	$(GPP)  -o TurtleSScanner.o TurtleSScanner.cc


# Libraries

libSWObjects.a: SWObjects.o ResultSet.o RdfDB.o RdfQueryDB.o ParserCommon.o SPARQLfedParser.o SPARQLfedScanner.o TurtleSParser.o TurtleSScanner.o
	ar cru libSWObjects.a SWObjects.o ResultSet.o RdfDB.o RdfQueryDB.o ParserCommon.o SPARQLfedParser.o SPARQLfedScanner.o TurtleSParser.o TurtleSScanner.o
	ranlib libSWObjects.a


# Sample apps
#   sample_TopicN - sample app number N for a given topic.
#   Vsample_TopicN - valgrind test of the this sample

## RuleMap1 - convert a SPARQL query on an interface graph to one that
##            works on a privage graph
sample_RuleMap1.o: sample_RuleMap1.cc SPARQLfedParser.hh TurtleSParser.hh XMLQueryExpressor.hh SPARQLSerializer.hh ResultSet.hh SWObjectDuplicator.hh QueryMapper.hh RuleInverter.hh
	$(GPP)  -o sample_RuleMap1.o sample_RuleMap1.cc

sample_RuleMap1: sample_RuleMap1.o libSWObjects.a
	$(LINK) sample_RuleMap1 sample_RuleMap1.o libSWObjects.a

Vsample_RuleMap1: sample_RuleMap1
	valgrind --leak-check=yes --xml=no ./sample_RuleMap1 SPARQLfed.txt 


# Tests
#   test: includes all samples
#   valgrind: valgrinds all samples

test: sample_RuleMap1
	./sample_RuleMap1 SPARQLfed.txt 

valgrind: Vsample_RuleMap1


# Clean - rm everything we remember to rm.
clean:
	rm -f sample_*[0-9] sample_*[0-9].o libSWObjects.a SWObjects.o RdfDB.o RdfQueryDB.o ResultSet.o  ParserCommon.o SPARQLfedParser.o SPARQLfedScanner.o SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.cc TurtleSParser.o TurtleSScanner.o TurtleSParser.cc TurtleSParser.hh TurtleSScanner.cc location.hh position.hh stack.hh

