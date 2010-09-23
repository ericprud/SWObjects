# $Id: Makefile,v 1.56 2009-01-16 11:29:21 eric Exp $
# SWObjects build rules -- you should edit the CONFIG file

# recipies:
#   normal build:
#     make SPARQLfed
#   force the use of the tracing facilities (and redirect to stdout):
#     make -W tests/test_HealthCare1.cpp test
#   have valgrind start a debugger (works as M-x gdb invocation command):
#     valgrind --db-attach=yes --leak-check=yes tests/execute_HealthCare1 tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
#   same, if you aren't working in gdb:
#     make valgrind
#   debugging in emacs:
#     gdb --annotate=3 sample_RuleMap1    (set args query_HealthCare1.rq ruleMap_HealthCare1.rq)
#
# linking to dlib requires special maneuvers 'cause of the need to 
# g++ -DHAVE_UTF8_OUTPUT -DHAVE_REGEX -I/home/eric/src/dlib-17.11 -o bin/SPARQL_server bin/SPARQL_server.o /home/eric/src/dlib-17.11/dlib/all/source.cpp -L/tmp/const-happy -lSWObjects -lboost_regex -lxml2 -lexpat -lmysqlclient
#
# Boost: @BOOST_CPPFLAGS@ @BOOST_THREAD_LIBS@ @BOOST_THREAD_LDFLAGS@
# MySQL: @MYSQL_CFLAGS@

ACLOCAL_AMFLAGS = -I .

.PHONY: all dep lib test NOGEN
all:   lib test
lib: dep $(LIB)

.SECONDARY:

lib/%.dep: lib/%.cpp config.h
	($(ECHO) -n $@ lib/; $(CXX) $(DEFS) $(INCLUDES) -MM $<) > $@ || (rm $@; false)
lib/SPARQLfedParser/%.dep: lib/SPARQLfedParser/%.cpp config.h
	($(ECHO) -n $@ lib/SPARQLfedParser/; $(CXX) $(DEFS) $(INCLUDES) -MM $<) > $@ || (rm $@; false)
lib/MapSetParser/%.dep: lib/MapSetParser/%.cpp config.h
	($(ECHO) -n $@ lib/MapSetParser/; $(CXX) $(DEFS) $(INCLUDES) -MM $<) > $@ || (rm $@; false)
lib/TurtleSParser/%.dep: lib/TurtleSParser/%.cpp config.h
	($(ECHO) -n $@ lib/TurtleSParser/; $(CXX) $(DEFS) $(INCLUDES) -MM $<) > $@ || (rm $@; false)
lib/TrigSParser/%.dep: lib/TrigSParser/%.cpp config.h
	($(ECHO) -n $@ lib/TrigSParser/; $(CXX) $(DEFS) $(INCLUDES) -MM $<) > $@ || (rm $@; false)
DEPEND = $(OBJLIST:.o=.dep) $(BISONOBJ:.o=.dep) $(FLEXOBJ:.o=.dep)
GENERATED = $(BISONOBJ:.o=.cpp) $(BISONOBJ:.o=.hpp) $(FLEXOBJ:.o=.cpp)

# don't run flex and bison
NOGEN:
	touch $(GENERATED)
	ln -s win/FlexLexer.h

lib/%.cpp  lib/%.hpp : lib/%.ypp
	$(YACC) -o $(@:.hpp=.cpp) $<
	$(SED) -i~ 's,# define PARSER_HEADER_H,#pragma once,' $(@:.cpp=.hpp)

lib/%.cpp : lib/%.lpp
	$(FLEX) -o $@  $<

#	$(SED) -i~ 's,extern "C" int isatty (int );,extern "C" int isatty (int ) throw();,' $@


##### bin dirs ####

# overrides for specific targets in bin
bin/SPARQL_server.o : bin/SPARQL_server.cpp config.h
	$(CXX) -DHTML_RESULTS=0 $(DEFS) $(OPT) $(DEBUG) $(INCLUDES) $(DLIB) -c -o $@ $<

bin/SPARQL_server : bin/SPARQL_server.o $(LIB) #lib
	$(CXX) -lnsl -o $@ $< $(LDAPPFLAGS) $(HTTP_SERVER_LIB)

# bin/ general rules
bin/%.dep: bin/%.cpp config.h $(BISONH)
	($(ECHO) -n $@ bin/; $(CXX) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)
DEPEND += $(BINOBJLIST:.o=.dep)

bin/%.o. : bin/%.cpp bin/.dep/%.d config.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/% : bin/%.o $(LIB) #lib
	$(CXX) -o $@ $< $(LDAPPFLAGS) $(HTTP_SERVER_LIB)


##### apache #####

# TODO: cleanup mod_sparul build, autoconf dependency paths?
apache/mod_sparul.dep: apache/mod_sparul.cpp config.h
	($(ECHO) $@ \\; $(CXX) -I`/usr/sbin/apxs -q INCLUDEDIR` -I/usr/local/src/codea -I/usr/local/src/ccl -I/usr/include/apr-1 $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)

apache/mod_sparul.so: $(LIB) apache/mod_sparul.dep
	cd apache; \
	gcc -fPIC -Wall `/usr/sbin/apxs -q CFLAGS` -I`/usr/sbin/apxs -q INCLUDEDIR` -I/usr/local/src/codea -I/usr/local/src/ccl -I/usr/include/apr-1 $(INCLUDES) -c mod_sparul.cpp -o mod_sparul.o; \
	apxs -c mod_sparul.o /usr/local/src/codea/codea_hooks.o ../lib/libSWObjects.a $(LDFLAGS)

clean-mod_sparul:
	rm -f apache/mod_sparul.{o,so,la} apache/.libs/mod_sparul.*

install-mod_sparul: apache/mod_sparul.so
	apxs -i -n sparul_module apache/.libs/mod_sparul.so


##### packaged tests ####

## test inferenced based on T, test_<T>.o=C/C++ query_<T>.rq ruleMap<T>.rq

#notes for ericP
# opts: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_leadTrailOpts.rq tests/ruleMap_leadTrailOpts.rq --stem http://stem.example/

# deep: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_deepNesting.rq tests/ruleMap_deepNesting.rq

# opt1: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_spec-opt1.rq --stem http://hr.example/DB/

# equivOpt1: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_spec-equivOpt1.rq --stem http://hr.example/DB/

# optJoin1: tests/execute_HealthCare1
#	valgrind tests/execute_HealthCare1 tests/query_spec-optJoin1.rq --stem http://hr.example/DB/

unitTESTS := $(subst tests/test_,t_,$(TESTNAMELIST))
unitTESTexes := $(TESTNAMELIST)
# You can override unitTESTS while fiddling with them.
#unitTESTS=t_GraphMatch
#$(error unitTESTS: $(unitTESTS))
# and control which subtests within a unit are run
#TEST_ARGS=--run_test=op_equals/* make -j 4 t_QueryMap
TEST_ARGS ?= ""

t_SPARQL: bin/SPARQL

tests/test_%.dep: tests/test_%.cpp config.h $(BISONH)
	($(ECHO) -n $@ tests/; $(CXX) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)

tests/test_%.o: tests/test_%.cpp $(LIB) tests/.dep/test_%.d config.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_%: tests/test_%.o $(LIB)
	$(CXX) -o $@ $< $(LDFLAGS) $(TEST_LIB)

tests/man_%.cpp: tests/test_%.cpp tests/makeMan.pl
	perl tests/makeMan.pl $< $@

tests/man_%.dep: tests/man_%.cpp config.h $(BISONH)
	($(ECHO) -n $@ tests/; $(CXX) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)
DEPEND += $(TESTSOBJLIST:.o=.dep)

tests/man_%.o: tests/man_%.cpp $(LIB) tests/.dep/man_%.d config.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/man_%: tests/man_%.o $(LIB)
	$(CXX) -o $@ $< $(LDFLAGS) $(TEST_LIB)

.PHONY: tests/manualHarness.dep


tests/test_WEBagents: tests/test_WEBagents.o $(LIB)
	$(CXX) -o $@ $< -lboost_filesystem$(BOOST_VERSION) -lboost_thread$(BOOST_VERSION) $(LDFLAGS) $(TEST_LIB)

t_%: tests/test_%
	( cd tests && ./$(notdir $<) $(TEST_ARGS) )

v_%: tests/test_%
	( cd tests && valgrind --leak-check=yes  --suppressions=boost-test.supp --xml=no ./$(notdir $<) $(TEST_ARGS) )
# update suppressions with --gen-suppressions=yes and copy to boost-test.supp

# "manual" (non-boost) tests, synthesized from the boost tests.
m_%: tests/man_%
	( cd tests && valgrind --leak-check=yes  --suppressions=boost-test.supp --xml=no ./$(notdir $<) $(TEST_ARGS) )


### SWtransformer tests:

tests/HealthCare1.results: bin/SPARQL tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	$< tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq --stem http://someClinic.exampe/DB/

tests/HealthCare1.valgrind: bin/SPARQL tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	valgrind --leak-check=yes --xml=no $< tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq --stem http://someClinic.exampe/DB/

transformTESTS=tests/HealthCare1

transformTEST_RESULTS=$(transformTESTS:=.results)
transformVALGRIND=$(transformTEST_RESULTS:.results=.valgrind)


### SPARQL_server tests:

tests/server_mouseToxicity_remote-all.results: \
	bin/SPARQL_server bin/SWtransformer \
	tests/mouseToxicity/remote-all/ToxicAssoc0.rq \
	tests/mouseToxicity/remote-all/MicroArray.map \
	tests/mouseToxicity/remote-all/Uniprot.map \
	tests/mouseToxicity/remote-all/ScreeningAssay.map \
	tests/mouseToxicity/remote-all/ChemStructure.map \
	tests/mouseToxicity/remote-all/MouseToxicity.map
	( cd tests/mouseToxicity/remote-all/ &&\
	  ../../../$< --once http://localhost:8881/microArray MicroArray.map |\
	  tee ../../../$@.ma )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  ../../../$< --once http://localhost:8882/uniprot Uniprot.map |\
	  tee ../../../$@.up )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  ../../../$< --once http://localhost:8883/screeningAssay ScreeningAssay.map |\
	  tee ../../../$@.sa )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  ../../../$< --once http://localhost:8884/chemStructure ChemStructure.map |\
	  tee ../../../$@.cs )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  ../../../$< --once http://localhost:8885/mouseToxicity MouseToxicity.map |\
	  tee ../../../$@.mt )&
	sleep 1 # give the servers time to start up
	( cd tests/mouseToxicity/remote-all/ &&\
	  time ../../../bin/SWtransformer\
	      -x -q ToxicAssoc0.rq )


tests/7tm_receptors-flat.results: bin/SPARQL_server bin/SPARQL tests/7tm_receptors/flat/q.rq tests/7tm_receptors/flat/receptors.map
	( cd tests/7tm_receptors/flat/ && ../../../$< --once http://localhost:8888/7tm_receptors receptors.map > ../../../$@ )&
	sleep 1
	( cd tests/7tm_receptors/flat/ && ../../../bin/SPARQL q.rq )

tests/7tm_receptors-flat.results2: bin/SPARQL bin/SPARQL tests/7tm_receptors/flat/q.rq tests/7tm_receptors/flat/receptors.map
	( cd tests/7tm_receptors/flat/ && ../../../$< --once --serve http://localhost:8888/7tm_receptors --mapset receptors.mapset > ../../../$@ )&
	sleep 1
	( cd tests/7tm_receptors/flat/ && ../../../$< q.rq )

SPARQL_serverTESTS=tests/server_mouseToxicity_remote-screening-assay

SPARQL_serverTEST_RESULTS=$(SPARQL_serverTESTS:=.results)

.PHONY: test valgrind tests/7tm_receptors-flat.results
test: lib $(unitTESTS) $(transformTEST_RESULTS)
valgrind: lib $(transformVALGRIND)

### Generate SWIG Interfaces ###

SWIG ?= swig
# SWIG output fixups:
#   1. const const => const
#   2. in  va_list * temp = reinterpret_cast< va_list * >(argp3);
#          arg3 = *temp;
#      arg3 = *temp => va_copy(arg3, *temp)
SWIG_SUBST = perl -0777 -pi -e 's{const const}{const}g; s{(va_list\s*\*[^\r\n]+\r?\n\s*)(arg\d) = (\*temp)}{$${1}va_copy($$2, $$3)}g'

SWIG_OBJS = lib/exs.o lib/RdfQueryDB.o lib/ParserCommon.o lib/TurtleSParser/TurtleSParser.o lib/TurtleSScanner.o lib/TrigSParser/TrigSParser.o lib/TrigSScanner.o lib/SPARQLfedParser/SPARQLfedParser.o lib/SPARQLfedScanner.o lib/MapSetParser/MapSetParser.o lib/MapSetScanner.o
SWIG_HPP = lib/SWObjects.hpp lib/SWObjects.cpp lib/SWObjects.hpp interface/SAXparser.hpp lib/XMLSerializer.hpp lib/ResultSet.hpp lib/ResultSet.cpp lib/RdfDB.hpp lib/SWObjects.cpp lib/SPARQLSerializer.hpp interface/WEBagent_boostASIO.hpp
SWIG_LIBS =  $(REGEX_LIB) $(HTTP_CLIENT_LIB) $(XML_PARSER_LIB) $(SQL_CLIENT_LIB)

 # Python
swig/python/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HPP)
	$(SWIG) -o $@ -c++ -python -I. -Ilib -Iinterface $<
	$(SWIG_SUBST) $@

swig/python/SWObjects_wrap.o: swig/python/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -fno-stack-protector -c -o swig/python/SWObjects_wrap.o swig/python/SWObjects_wrap.cxx -I$(PYTHON_HOME)

swig/python/_SWObjects.so: swig/python/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS)

# The _SWObjects.so target can be built with the python distutils package,
# but it's noisier and doesn't re-use the object files in lib:

# swig/python/_SWObjects.so: swig/python/SWObjects_wrap.cxx swig/python/SWObjects_setup.py
# 	python swig/python/SWObjects_setup.py build_ext --inplace -I.:lib/:interface/
# 	mv _SWObjects.so swig/python/

python-test: swig/python/_SWObjects.so
	(cd swig/python/ && python t_SWObjects.py)

python-clean:
	$(RM) -f swig/python/SWObjects.* swig/python/SWObjects_wrap.* swig/python/_SWObjects.so

SWIG_TEST = python-test
SWIG_CLEAN = python-clean

# Java
swig/java/src/POSFactory.java swig/java/src/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HPP)
	$(SWIG) -o swig/java/src/SWObjects_wrap.cxx -c++ -java -I. -Ilib -Iinterface swig/SWObjects.i
	$(SWIG_SUBST) swig/java/src/SWObjects_wrap.cxx

swig/java/src/SWObjects_wrap.o: swig/java/src/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -fno-stack-protector -c -o $@ $< -I$(JAVA_HOME)/include

swig/java/libSWObjects.so: swig/java/src/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS)

swig/java/SWObjects.jar: swig/java/src/POSFactory.java # there are zillions of class files
	rm $@
	javac -d swig/java/class swig/java/src/*.java
	jar cf $@ -C swig/java/class .

swig/java/t_SWObjects.class: swig/java/t_SWObjects.java swig/java/SWObjects.jar
	javac -d swig/java -classpath .:/usr/share/java/junit4-4.8.1.jar:swig/java/SWObjects.jar $<

java-test: swig/java/libSWObjects.so swig/java/t_SWObjects.class
	LD_LIBRARY_PATH=swig/java java -classpath .:/usr/share/java/junit4-4.8.1.jar:swig/java:swig/java/SWObjects.jar org.junit.runner.JUnitCore t_SWObjects

java-clean:
	$(RM) -f swig/java/libSWObjects.so swig/java/class/* swig/java/src/* swig/java/t_SWObjects.class

SWIG_TEST += java-test
SWIG_CLEAN += java-clean

# Perl
swig/perl/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HPP)
	$(SWIG) -o $@ -c++ -perl5 -I. -Ilib -Iinterface $<
	$(SWIG_SUBST) $@

swig/perl/SWObjects_wrap.o: swig/perl/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -c -o $@ $< -I$(PERL_HOME)/CORE

swig/perl/libSWObjects.so: swig/perl/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS)

perl-test: swig/perl/libSWObjects.so
	(cd swig/perl/ && perl t_SWObjects.t)

perl-clean:
	$(RM) -f swig/perl/SWObjects.* swig/perl/SWObjects_wrap.* swig/perl/libSWObjects.so

SWIG_TEST += perl-test
SWIG_CLEAN += perl-clean


swig-test: $(SWIG_TEST)
swig-clean: $(SWIG_CLEAN)

# Clean - rm everything we remember to rm.
.PHONY: clean cleaner
clean-local:
	$(RM) */*.o lib/*.a lib/*.dylib lib/*.so lib/*.la */*.bak config.h \
	$(subst .ypp,.o,$(wildcard lib/*/*.ypp)) \
        $(transformTEST_RESULTS) $(transformVALGRIND) \
	$(unitTESTexes) *~ */*.dep */*/*.dep

cleaner: clean-local swig-clean
	$(RM) \
	$(subst .lpp,.cpp,$(wildcard lib/*.lpp)) \
	$(subst .ypp,.cpp,$(wildcard lib/*/*.ypp)) \
	$(subst .ypp,.hpp,$(wildcard lib/*/*.ypp)) \
	$(BISONHH:%=*/%)

dep: $(DEPEND)

BISONHH=location.hh stack.hh position.hh
#$(BISONHH): $(BISONOBJ)
-include $(DEPEND)
