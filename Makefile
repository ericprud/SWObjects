GPP=g++ -DYYTEXT_POINTER=1 -W -Wall -Wextra -ansi -g -c
LINK=g++ -W -Wall -Wextra -ansi -g -lboost_iostreams -o

SPARQLfedParser.cc SPARQLfedParser.hh location.hh position.hh stack.hh: SPARQLfedParser.yy
	bison -o SPARQLfedParser.cc SPARQLfedParser.yy

#/bin/sh ../scripts/ylwrap parser.yy y.tab.c parser.cc y.tab.h parser.h y.output parser.output -- bison -y  

SPARQLfedScanner.cc SPARQLfedScanner.h: SPARQLfedScanner.ll
	flex -o SPARQLfedScanner.cc SPARQLfedScanner.ll

#/bin/sh ../scripts/ylwrap scanner.ll lex.yy.c scanner.cc -- flex  -olex.yy.c

SPARQLfedParser.o: SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.h
	$(GPP)  -o SPARQLfedParser.o SPARQLfedParser.cc

SPARQLfedScanner.o: SPARQLfedScanner.cc
	$(GPP)  -o SPARQLfedScanner.o SPARQLfedScanner.cc

SPARQLfedDriver.o: SPARQLfedDriver.cc
	$(GPP)  -o SPARQLfedDriver.o SPARQLfedDriver.cc

#libSPARQLfed.a: SPARQLfedParser.o SPARQLfedScanner.o SPARQLfedDriver.o
#	ar cru libSPARQLfed.a SPARQLfedParser.o SPARQLfedScanner.o SPARQLfedDriver.o 
#	ranlib libSPARQLfed.a

#SPARQLfedTest.o: SPARQLfedTest.cc
#	$(GPP)  -o SPARQLfedTest.o SPARQLfedTest.cc

#SPARQLfedTest: SPARQLfedTest.o libSPARQLfed.a
#	$(LINK) SPARQLfedTest SPARQLfedTest.o libSPARQLfed.a

SPARQLfed: SPARQLfedParser.o SPARQLfedScanner.o
	$(LINK) SPARQLfed SPARQLfedParser.o SPARQLfedScanner.o

test: SPARQLfed
	./SPARQLfed SPARQLfed.txt 

clean:
	rm -f SPARQLfedTest libSPARQLfed.a SPARQLfedDriver.o SPARQLfedTest.o SPARQLfedParser.o SPARQLfedScanner.o SPARQLfedParser.cc SPARQLfedParser.hh SPARQLfedScanner.cc location.hh position.hh stack.hh

