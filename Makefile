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

# linking to dlib requires special maneuvers 'cause of the need to 
# g++ -DHAVE_UTF8_OUTPUT -DHAVE_REGEX -I/home/eric/src/dlib-17.11 -o bin/SPARQL_server bin/SPARQL_server.o /home/eric/src/dlib-17.11/dlib/all/source.cpp -L/tmp/const-happy -lSWObjects -lboost_regex -lxml2 -lexpat -lmysqlclient

# Edit CONFIG to set your build preferences.
-include CONFIG

FLEX:=flex
YACC:=bison
TEE:=tee
SED:=sed
# GNU Make 3.81 seems to have a built-in echo which doesn't swallow "-e"
ECHO:=`which echo`
ECHO ?= echo
#LIBS
DEBUG:=-g -O0
OPT=-fPIC
DEFS += -DYYTEXT_POINTER=1
WARN:=-W -Wall -Wextra -Wnon-virtual-dtor -ansi -std=c++98
# --pedantic
# pedantic works on GNU if you uncomment the isatty (int ) throw() patch below


INCLUDES += -I${PWD} -I${PWD}/lib  # . (for config.h) and ./lib (for the rest)
I2=$(subst /, ,$(BISONOBJ:.o=))
I3=$(sort $(I2))
INCLUDES += $(I3:%=-I${PWD}/%)

PWD ?= $(shell pwd -P)


ifeq ($(XML_PARSER), LIBXML2)
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_LIBXML2 "\\n"
  INCLUDES += -I/usr/include/libxml2
  XML_PARSER_LIB?= -lxml2
else ifeq ($(XML_PARSER), EXPAT1)
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_EXPAT1 "\\n"
  XML_PARSER_LIB?= -lexpat
else ifeq ($(XML_PARSER), MSXML3)
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_MSXML3 "\\n"
  XML_PARSER_LIB?= -lmsxml
else
  ifneq ($(XML_PARSER), )
    $(warning $(XML_PARSER) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_DISABLED "\\n"
endif


ifeq ($(CONSOLE_ENCODING), UTF8)
  CONFIG_DEFS+= \\\#define CONSOLE_ENCODING	SWOb_UTF8 "\\n"
else
  ifneq ($(CONSOLE_ENCODING), )
    $(warning CONSOLE_ENCODING= $(CONSOLE_ENCODING) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define CONSOLE_ENCODING	SWOb_DISABLED "\\n"
endif


ifeq ($(REGEX), BOOST)
  CONFIG_DEFS+= \\\#define REGEX_LIB	SWOb_BOOST "\\n"
  REGEX_LIB?= -lboost_regex$(BOOST_VERSION)
else
  ifneq ($(REGEX), )
    $(warning $(REGEX_LIB) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define REGEX_LIB	SWOb_DISABLED "\\n"
endif


ifeq ($(HTTP_CLIENT), ASIO)
  CONFIG_DEFS+= \\\#define HTTP_CLIENT	SWOb_ASIO "\\n"
  HTTP_CLIENT_LIB?= -lboost_system$(BOOST_VERSION)
else ifeq ($(HTTP_CLIENT), DLIB)
  CONFIG_DEFS+= \\\#define HTTP_CLIENT	SWOb_DLIB "\\n"
  $(warning DLIB HTTP client code not yet written)
else
  ifneq ($(HTTP_CLIENT), )
    $(warning $(HTTP_CLIENT) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define HTTP_CLIENT	SWOb_DISABLED "\\n"
endif


ifeq ($(HTTP_SERVER), ASIO)
  CONFIG_DEFS+= \\\#define HTTP_SERVER	SWOb_ASIO "\\n"
  HTTP_SERVER_LIB?= -lboost_system$(BOOST_VERSION) -lboost_thread$(BOOST_VERSION)
else ifeq ($(HTTP_SERVER), DLIB)
  CONFIG_DEFS+= \\\#define HTTP_SERVER	SWOb_DLIB "\\n"
  DLIB= -DDLIB_TIGHT_LOOP=1 -DNO_MAKEFILE
else
  ifneq ($(HTTP_SERVER), )
    $(warning $(HTTP_SERVER) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define HTTP_SERVER	SWOb_DISABLED "\\n"
endif


ifeq ($(SQL_CLIENT), MYSQL)
  CONFIG_DEFS+= \\\#define SQL_CLIENT	SWOb_MYSQL "\\n"
  SQL_CLIENT_LIB?= -lmysqlclient
else
  ifneq ($(SQL_CLIENT), )
    $(warning $(SQL_CLIENT) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define SQL_CLIENT	SWOb_DISABLED "\\n"
endif


TEST_LIB?= -lboost_unit_test_framework$(BOOST_VERSION)


.PHONY: all dep lib test
all:   lib test


config.h: CONFIG
	@$(ECHO) -e "/* Generated from CONFIG.\\n" \
	"* In order to keep your link directives appropriate for the features enabled\\n" \
	"* by defines in this header, you should edit CONFIG and then \`make config.h\`.\\n" \
	"*/\\n" \
	"#define SWOb_DISABLED		135\\n" \
	"/* XML Parsers: */\\n" \
	"#define SWOb_LIBXML2		137\\n" \
	"#define SWOb_EXPAT1		138\\n" \
	"#define SWOb_MSXML3		139\\n" \
	"/* Character Encodings: */\\n" \
	"#define SWOb_UTF8		143\\n" \
	"/* Regexp Libs: */\\n" \
	"#define SWOb_BOOST		144\\n" \
	"/* HTTP Libs: */\\n" \
	"#define SWOb_ASIO		145\\n" \
	"#define SWOb_DLIB		146\\n" \
	"/* SQL Libs: */\\n" \
	"#define SWOb_MYSQL		148\\n" \
	"\\n" $(CONFIG_DEFS) > config.h
	@$(ECHO) config.h updated.

#the gcc commands to make deps used in .d rules
#if -M[M]D is also in the build-clause without -E it update .d's as needed
TOONOISEY=-ansi
#for macports
CFLAGS += $(DEFS) $(OPT) $(DEBUG) $(WARN) $(INCLUDES) -pipe
CXXFLAGS += $(CFLAGS)

### absolutely neccessry for c++ linking ###
LD = $(CXX)
LDFLAGS += $(LIBINC) $(REGEX_LIB) $(HTTP_CLIENT_LIB) $(XML_PARSER_LIB) $(SQL_CLIENT_LIB)
LDAPPFLAGS += $(LDFLAGS) -lboost_program_options$(BOOST_VERSION) -lboost_filesystem$(BOOST_VERSION)
VER=0.1

#some progressive macports
#CC=llvm-gcc
#CXX=llvm-g++
#LLVMCFLAGS = ` llvm-config --cflags` -O4
#LLVMCXXFLAGS = ` llvm-config --cxxflags` -O4
#LLVMLDFLAGS = ` llvm-config --ldflags --libs `
#LLVMLIBS= ` llvm-config --libs`
# ... you get the idea...
CFLAGS	+= $(LLVMCFLAGS)
LIBINC	+= -L$(PWD)/lib

### dirt simple generic static module ###
BISONOBJ :=  $(subst .ypp,.o,$(wildcard lib/*/*.ypp)) 
FLEXOBJ  :=  $(subst .lpp,.o,$(wildcard lib/*.lpp))
OBJLIST  :=  $(subst .cpp,.o,$(wildcard lib/*.cpp))
BINOBJLIST  :=  $(subst .cpp,.o,$(wildcard bin/*.cpp))
TESTSOBJLIST  :=  $(subst .cpp,.o,$(wildcard tests/*.cpp))
TESTNAMELIST  :=  $(subst .cpp,,$(wildcard tests/test_*.cpp))
LIBNAME  :=  SWObjects
LIB	 :=	 lib/lib$(LIBNAME).a
LIBINC	+=	 -l$(LIBNAME)

$(LIB): $(BISONOBJ) $(FLEXOBJ) $(OBJLIST)
	$(AR) rcvs $@ $^

.PHONY: lib
lib: dep $(LIB)

.SECONDARY:

lib/%.dep: lib/%.cpp config.h
	(echo $@ \\; $(CXX) $(DEFS) $(INCLUDES) -MM $<) > $@ || (rm $@; false)
DEPEND += $(OBJLIST:.o=.dep) $(BISONOBJ:.o=.dep) $(FLEXOBJ:.o=.dep)

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
	$(CXX) -lnsl -lpthread -o $@ $< $(LDAPPFLAGS) $(HTTP_SERVER_LIB)

# bin/ general rules
bin/%.dep: bin/%.cpp config.h
	(echo $@ \\; $(CXX) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)
DEPEND += $(BINOBJLIST:.o=.dep)

bin/%.o. : bin/%.cpp bin/.dep/%.d config.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bin/% : bin/%.o $(LIB) #lib
	$(CXX) -o $@ $< $(LDAPPFLAGS)


##### apache #####

# TODO: cleanup mod_sparul build, autoconf dependency paths?
apache/mod_sparul.dep: apache/mod_sparul.cpp config.h
	(echo $@ \\; $(CXX) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)

apache/mod_sparul.so: $(LIB) apache/mod_sparul.dep
	cd bin; \
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
# 	valgrind tests/execute_HealthCare1 tests/query_leadTrailOpts.rq tests/ruleMap_leadTrailOpts.rq -s http://stem.example/

# deep: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_deepNesting.rq tests/ruleMap_deepNesting.rq

# opt1: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_spec-opt1.rq -s http://hr.example/DB/

# equivOpt1: tests/execute_HealthCare1
# 	valgrind tests/execute_HealthCare1 tests/query_spec-equivOpt1.rq -s http://hr.example/DB/

# optJoin1: tests/execute_HealthCare1
#	valgrind tests/execute_HealthCare1 tests/query_spec-optJoin1.rq -s http://hr.example/DB/

unitTESTS := $(subst tests/test_,t_,$(TESTNAMELIST))
unitTESTexes := $(TESTNAMELIST)
# You can override unitTESTS while fiddling with them.
#unitTESTS=t_GraphMatch
#$(error unitTESTS: $(unitTESTS))
# and control which subtests within a unit are run
#TEST_ARGS=--run_test=op_equals/* make -j 4 t_QueryMap
TEST_ARGS ?= ""

tests/test_%.dep: tests/test_%.cpp config.h
	(echo $@ \\; $(CXX) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)
DEPEND += $(TESTSOBJLIST:.o=.dep)

tests/test_%.o: tests/test_%.cpp $(LIB) tests/.dep/test_%.d config.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/test_%: tests/test_%.o $(LIB)
	$(CXX) $(TEST_LIB) -o $@ $< $(LDFLAGS)

tests/test_WEBagents: tests/test_WEBagents.o $(LIB)
	$(CXX) $(TEST_LIB) -o $@ $< -lboost_filesystem$(BOOST_VERSION) -lboost_thread$(BOOST_VERSION)

t_%: tests/test_%
	( cd tests && ./$(notdir $<) $(TEST_ARGS) )

v_%: tests/test_%
	( cd tests && valgrind --leak-check=yes  --suppressions=boost-test.supp --xml=no ./$(notdir $<) $(TEST_ARGS) )
# update suppressions with --gen-suppressions=yes and copy to boost-test.supp


### SWtransformer tests:

tests/HealthCare1.results: bin/SWtransformer tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	$< -q -d tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq -s http://someClinic.exampe/DB/

tests/HealthCare1.valgrind: bin/SWtransformer tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	valgrind --leak-check=yes --xml=no $< -q -d tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq -s http://someClinic.exampe/DB/

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
	# Start servers.
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


tests/7tm_receptors-flat.results: bin/SPARQL_server bin/SWtransformer tests/7tm_receptors/flat/q.rq tests/7tm_receptors/flat/receptors.map
	( cd tests/7tm_receptors/flat/ && ../../../$< --once http://localhost:8888/7tm_receptors receptors.map > ../../../$@ )&
	sleep 1
	( cd tests/7tm_receptors/flat/ && ../../../bin/SWtransformer -x -q q.rq )


SPARQL_serverTESTS=tests/server_mouseToxicity_remote-screening-assay

SPARQL_serverTEST_RESULTS=$(SPARQL_serverTESTS:=.results)


.PHONY: test valgrind tests/7tm_receptors-flat.results
test: lib $(unitTESTS) $(transformTEST_RESULTS)
valgrind: lib $(transformVALGRIND)

# Distributions

release:
	$(RM) -f SWObjects_$(VER).tar.gz README.html
	lynx -dump -source http://www.w3.org/2008/04/SPARQLfed/ | perl -pe 's{href="\.\./\.\./\.\.}{href="http://www.w3.org}g;s{href="\.\./\.\.}{href="http://www.w3.org/2008}g'> README.html
	@$(echo) "Generating the inclusion from the manifest (HEADER.html)"
	@($(echo) "README.html" && perl -ne 'print join("\n", m/class="tar" href="([a-zA-Z]{2}[a-zA-Z0-9._\/]+)"/g, undef)' HEADER.html) | xargs tar czf SWObjects_$(VER).tar.gz --transform s,,SWObjects_$(VER)/,1
	$(RM) README.html


# Clean - rm everything we remember to rm.
.PHONY: clean cleaner
clean:
	$(RM) */*.o lib/*.a lib/*.dylib lib/*.so lib/*.la */*.bak config.h \
        $(transformTEST_RESULTS) $(transformVALGRIND) \
	$(unitTESTexes) *~ */*.dep */*/*.d

cleaner: clean
	$(subst .lpp,.cpp,$(wildcard lib/*.lpp)) \
	$(subst .ypp,.cpp,$(wildcard lib/*/*.ypp)) \
	$(subst .ypp,.hpp,$(wildcard lib/*/*.ypp)) \
	$(RM) $(BISONHH:%=*/%)

dep: $(DEPEND)

BISONHH=location.hh stack.hh position.hh
#$(BISONHH): $(BISONOBJ)
-include $(DEPEND)
