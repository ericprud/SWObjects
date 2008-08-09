# $Id: Makefile,v 1.22 2008-08-09 18:41:20 eric Exp $

# recipies:
#   normal build:
#     make SPARQLfed
#   force the use of the tracing facilities (and redirect to stdout):
#     make -W SPARQLfedTest.cc test
#   have valgrind start a debugger (works as M-x gdb invocation command):
#     valgrind --db-attach=yes --leak-check=yes SPARQLfedTest SPARQLfed.txt
#   same, if you aren't working in gdb:
#     make valgrind
#   debugging in emacs:
#     gdb --annotate=3 SPARQLfedTest    (set args SPARQLfed.txt)

LIBS=
DEFS=

GPP=g++ -DYYTEXT_POINTER=1 $(DEFS) -W -Wall -Wextra -ansi -g -c
LINK=g++ -W -Wall -Wextra -ansi -g $(LIBS) -o

SPARQLfedParser.cc SPARQLfedParser.hh location.hh position.hh stack.hh: SPARQLfedParser.yy SPARQL.hh ParserCommon.hh
	bison -o SPARQLfedParser.cc SPARQLfedParser.yy

SPARQLfedScanner.cc: SPARQLfedScanner.ll SPARQLfedParser.hh
	flex -o SPARQLfedScanner.cc SPARQLfedScanner.ll

SPARQLfedParser.o: SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.hh
	$(GPP)  -o SPARQLfedParser.o SPARQLfedParser.cc

SPARQLfedScanner.o: SPARQLfedScanner.cc SPARQLfedScanner.hh
	$(GPP)  -o SPARQLfedScanner.o SPARQLfedScanner.cc

TurtleSParser.cc TurtleSParser.hh: TurtleSParser.yy SPARQL.hh
	bison -o TurtleSParser.cc TurtleSParser.yy

TurtleSScanner.cc: TurtleSScanner.ll TurtleSParser.hh
	flex -o TurtleSScanner.cc TurtleSScanner.ll

TurtleSParser.o: TurtleSParser.cc TurtleSParser.hh TurtleSScanner.hh
	$(GPP)  -o TurtleSParser.o TurtleSParser.cc

TurtleSScanner.o: TurtleSScanner.cc TurtleSScanner.hh
	$(GPP)  -o TurtleSScanner.o TurtleSScanner.cc

SPARQL.o: SPARQL.cc SPARQL.hh
	$(GPP)  -o SPARQL.o SPARQL.cc

ResultSet.o: ResultSet.cc ResultSet.hh XMLSerializer.hh
	$(GPP)  -o ResultSet.o ResultSet.cc

RdfDB.o: RdfDB.cc RdfDB.hh XMLSerializer.hh
	$(GPP)  -o RdfDB.o RdfDB.cc

RdfQueryDB.o: RdfQueryDB.cc RdfQueryDB.hh RdfDB.hh
	$(GPP)  -o RdfQueryDB.o RdfQueryDB.cc

ParserCommon.o: ParserCommon.cc ParserCommon.hh
	$(GPP)  -o ParserCommon.o ParserCommon.cc

libSPARQLfed.a: SPARQL.o ResultSet.o RdfDB.o RdfQueryDB.o ParserCommon.o SPARQLfedParser.o SPARQLfedScanner.o TurtleSParser.o TurtleSScanner.o
	ar cru libSPARQLfed.a SPARQL.o ResultSet.o RdfDB.o RdfQueryDB.o ParserCommon.o SPARQLfedParser.o SPARQLfedScanner.o TurtleSParser.o TurtleSScanner.o
	ranlib libSPARQLfed.a

XMLQueryExpressor.hh: XMLSerializer.hh # !!! doesn't seem to trigger XQE's dependencies

SPARQLfedTest.o: SPARQLfedTest.cc SPARQLfedParser.hh TurtleSParser.hh XMLQueryExpressor.hh SPARQLSerializer.hh ResultSet.hh SPARQLDuplicator.hh SPARQLTransformer.hh SPARQLConstructInverter.hh
	$(GPP)  -o SPARQLfedTest.o SPARQLfedTest.cc

SPARQLfedTest: SPARQLfedTest.o libSPARQLfed.a
	$(LINK) SPARQLfedTest SPARQLfedTest.o libSPARQLfed.a

test: SPARQLfedTest
	./SPARQLfedTest SPARQLfed.txt 

valgrind: SPARQLfedTest
	valgrind --leak-check=yes --xml=no ./SPARQLfedTest SPARQLfed.txt 

clean:
	rm -f SPARQLfedTest SPARQLfedTest.o libSPARQLfed.a SPARQL.o RdfDB.o RdfQueryDB.o ResultSet.o  ParserCommon.o SPARQLfedParser.o SPARQLfedScanner.o SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.cc TurtleSParser.o TurtleSScanner.o TurtleSParser.cc TurtleSParser.hh TurtleSScanner.cc location.hh position.hh stack.hh

