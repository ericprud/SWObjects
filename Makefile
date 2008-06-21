# $Id: Makefile,v 1.7 2008-06-21 16:11:26 eric Exp $

# recipies:
#   normal build:
#     make SPARQLfed
#   force the use of the tracing facilities (and redirect to stdout):
#     HAVE_BOOST=1 TRACE_FD=1 make -W SPARQLfedTest.cc test
#   have valgrind start a debugger (works as M-x gdb invocation command):
#     valgrind --db-attach=yes --leak-check=yes SPARQLfedTest SPARQLfed.txt
#   same, if you aren't working in gdb:
#     HAVE_BOOST=1 TRACE_FD=1 make valgrind
#   debugging in emacs:
#     gdb --annotate=3 SPARQLfedTest    (set args SPARQLfed.txt)

ifdef HAVE_BOOST
LIBS=-lboost_iostreams
DEFS=-DHAVE_BOOST
else
LIBS=
DEFS=
endif

GPP=g++ -DYYTEXT_POINTER=1 $(DEFS) -W -Wall -Wextra -ansi -g -c
LINK=g++ -W -Wall -Wextra -ansi -g $(LIBS) -o

SPARQLfedParser.cc SPARQLfedParser.hh location.hh position.hh stack.hh: SPARQLfedParser.yy
	bison -o SPARQLfedParser.cc SPARQLfedParser.yy

#/bin/sh ../scripts/ylwrap parser.yy y.tab.c parser.cc y.tab.h parser.h y.output parser.output -- bison -y  

SPARQLfedScanner.cc: SPARQLfedScanner.ll SPARQLfedParser.hh
	flex -o SPARQLfedScanner.cc SPARQLfedScanner.ll

#/bin/sh ../scripts/ylwrap scanner.ll lex.yy.c scanner.cc -- flex  -olex.yy.c

SPARQLfedParser.o: SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.hh
	$(GPP)  -o SPARQLfedParser.o SPARQLfedParser.cc

SPARQLfedScanner.o: SPARQLfedScanner.cc SPARQLfedScanner.hh
	$(GPP)  -o SPARQLfedScanner.o SPARQLfedScanner.cc

libSPARQLfed.a: SPARQLfedParser.o SPARQLfedScanner.o
	ar cru libSPARQLfed.a SPARQLfedParser.o SPARQLfedScanner.o
	ranlib libSPARQLfed.a

SPARQLfedTest.o: SPARQLfedTest.cc SPARQLfedParser.hh XMLSerializer.hh SPARQLSerializer.hh
	$(GPP)  -o SPARQLfedTest.o SPARQLfedTest.cc

SPARQLfedTest: SPARQLfedTest.o libSPARQLfed.a
	$(LINK) SPARQLfedTest SPARQLfedTest.o libSPARQLfed.a

#SPARQLfed: SPARQLfedParser.o SPARQLfedScanner.o
#	$(LINK) SPARQLfed SPARQLfedParser.o SPARQLfedScanner.o

test: SPARQLfedTest
	./SPARQLfedTest SPARQLfed.txt 

valgrind: SPARQLfedTest
	valgrind --leak-check=yes --xml=no ./SPARQLfedTest SPARQLfed.txt 

clean:
	rm -f SPARQLfedTest SPARQLfedTest.o libSPARQLfed.a SPARQLfedParser.o SPARQLfedScanner.o SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.cc location.hh position.hh stack.hh

