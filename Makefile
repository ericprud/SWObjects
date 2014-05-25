# $Id: Makefile,v 1.56 2009-01-16 11:29:21 eric Exp $
# SWObjects build rules -- you should edit the CONFIG file

# recipies:
#   normal build:
#     make SPARQL
#   force the use of the tracing facilities (and redirect to stdout):
#     make -W tests/test_HealthCare1.cpp test
#   have valgrind start a debugger
#     valgrind --db-attach=yes --leak-check=yes tests/execute_HealthCare1 tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
#     (may require root to first `echo 0 > /proc/sys/kernel/yama/ptrace_scope` on Ubuntu >= 10.04)
#   M-x gdb invocation command:
#     M-x gdb valgrind --db-attach=yes "--db-command=gdb --annotate=3 %f %p" --leak-check=yes  --suppressions=boost-test.supp --xml=no --num-callers=32 ./test_QueryMap --run_test=bsbm/q1
#   same, if you aren't working in gdb:
#     make valgrind
#   debugging in emacs:
#     gdb --annotate=3 sample_RuleMap1    (set args query_HealthCare1.rq ruleMap_HealthCare1.rq)

# Edit CONFIG to set your build preferences.
-include CONFIG

FLEX:=flex
YACC:=bison
TEE:=tee
SED:=sed
XSLT ?= saxonb-xslt -ext:on
OPTIM:=-g -O0
PYTHON_INC:=$(shell python-config --includes)
PHP_HOME:=/usr/include/php5 -I/usr/include/php5/Zend -I/usr/include/php5/TSRM -I/usr/include/php5/main
LUA_HOME:=/usr/include/lua5.1
PERL_HOME:=/usr/lib/perl/5.10.1
JAVA_HOME:=/usr/lib/jvm/java-6-openjdk
# GNU Make 3.81 seems to have a built-in echo which doesn't swallow "-e"
#ECHO:=`which echo`
#OSX: ECHO:= /bin/echo
ECHO ?= echo
#LIBS
DEBUG:=-g -O0
OPT=-fPIC
DEFS += -DYYTEXT_POINTER=1
WARN:=-W -Wall -Wextra -Wnon-virtual-dtor -ansi -std=c++98
# --pedantic
# pedantic works on GNU if you uncomment the isatty (int ) throw() patch below

# Apache modules:
# 
# One can override APXS to point to a debug build of apache which will reference
# a config_vars.mk with CFLAGS and EXTRACFLAGS containing -g, e.g.
# APXS='perl ../apache/apache2-2.2.17/support/apxs' make -k apache/mod_sparul.la -Wapache/mod_sparul.cpp
# $(apache2-2.2.17$ ./configure --enable-maintainer-mode) will create such a config_vars.mk
APXS ?= apxs2
CODEA ?= ../codea
CCL ?= ../ccl
APR ?= /usr/include/apr-1.0

INCLUDES += -I${PWD} -I${PWD}/lib -I${PWD}/docs -I${PWD}/utf8_v2.3.2_source  # . (for config.h) and ./lib (for the rest)
I2=$(subst /, ,$(BISONOBJ:.o=)) # e.g. lib JSONresultsParser JSONresultsParser lib MapSetParser MapSetParser
I3=$(sort $(I2)) # e.g. JSONresultsParser MapSetParser ... lib
#INCLUDES += $(I3:%=-I${PWD}/%)

PWD ?= $(shell pwd -P)


ifeq ($(XML_PARSER), LIBXML2)
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_LIBXML2 "\n"
  INCLUDES += -I/usr/include/libxml2
  XML_PARSER_LIB?= -lxml2
else ifeq ($(XML_PARSER), EXPAT1)
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_EXPAT1 "\n"
  XML_PARSER_LIB?= -lexpat
else ifeq ($(XML_PARSER), MSXML3)
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_MSXML3 "\n"
  XML_PARSER_LIB?= -lmsxml
else
  ifneq ($(XML_PARSER), )
    $(warning $(XML_PARSER) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define XML_PARSER	SWOb_DISABLED "\n"
endif


ifeq ($(CONSOLE_ENCODING), UTF8)
  CONFIG_DEFS+= \\\#define CONSOLE_ENCODING	SWOb_UTF8 "\n"
else
  ifneq ($(CONSOLE_ENCODING), )
    $(warning CONSOLE_ENCODING= $(CONSOLE_ENCODING) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define CONSOLE_ENCODING	SWOb_DISABLED "\n"
endif


ifeq ($(REGEX), BOOST)
  CONFIG_DEFS+= \\\#define REGEX_LIB	SWOb_BOOST "\n"
  REGEX_LIB?= -lboost_regex$(BOOST_SUFFIX) -lpthread
else
  ifneq ($(REGEX), )
    $(warning $(REGEX_LIB) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define REGEX_LIB	SWOb_DISABLED "\n"
endif


ifeq ($(HTTP_CLIENT), ASIO)
  CONFIG_DEFS+= \\\#define HTTP_CLIENT	SWOb_ASIO "\n"
  HTTP_CLIENT_LIB?= -lboost_system$(BOOST_SUFFIX)
else ifeq ($(HTTP_CLIENT), DLIB)
  CONFIG_DEFS+= \\\#define HTTP_CLIENT	SWOb_DLIB "\n"
  $(warning DLIB HTTP client code not yet written)
else
  ifneq ($(HTTP_CLIENT), )
    $(warning $(HTTP_CLIENT) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define HTTP_CLIENT	SWOb_DISABLED "\n"
endif


ifeq ($(HTTP_SERVER), ASIO)
  CONFIG_DEFS+= \\\#define HTTP_SERVER	SWOb_ASIO "\n"
  HTTP_SERVER_LIB?= -lboost_system$(BOOST_SUFFIX) -lboost_thread$(BOOST_SUFFIX) -lpthread
else ifeq ($(HTTP_SERVER), DLIB)
  CONFIG_DEFS+= \\\#define HTTP_SERVER	SWOb_DLIB "\n"
  DLIB= -DDLIB_TIGHT_LOOP=1 -DNO_MAKEFILE
else
  ifneq ($(HTTP_SERVER), )
    $(warning $(HTTP_SERVER) may not be supported)
  endif
  CONFIG_DEFS+= \\\#define HTTP_SERVER	SWOb_DISABLED "\n"
endif


ifeq ($(findstring MYSQL, $(SQL_CLIENTS)), MYSQL)
  CONFIG_DEFS+= \\\#define SQL_CLIENT_MYSQL "\n"
  SOME_SQL_CLIENT = 1
  SQL_CLIENT_LIB+= -lmysqlclient -lz
endif

ifeq ($(findstring POSTGRES, $(SQL_CLIENTS)), POSTGRES)
  CONFIG_DEFS+= \\\#define SQL_CLIENT_POSTGRES "\n"
  SOME_SQL_CLIENT = 1
  SQL_CLIENT_LIB+= -lpq
endif

ifeq ($(findstring ORACLE, $(SQL_CLIENTS)), ORACLE)
  CONFIG_DEFS+= \\\#define SQL_CLIENT_ORACLE "\n"
  SOME_SQL_CLIENT = 1
  SQL_CLIENT_LIB+= -locci -lclntsh -laio -lnnz11
endif

ifeq ($(findstring MSSQL, $(SQL_CLIENTS)), MSSQL)
  CONFIG_DEFS+= \\\#define SQL_CLIENT_MSSQL "\n"
  SOME_SQL_CLIENT = 1
  SQL_CLIENT_LIB+= -lsybdb
endif

ifeq ($(findstring ODBC, $(SQL_CLIENTS)), ODBC)
  CONFIG_DEFS+= \\\#define SQL_CLIENT_ODBC "\n"
  SOME_SQL_CLIENT = 1
  SQL_CLIENT_LIB+= -lodbc -lltdl -ldl
endif

ifeq ($(SOME_SQL_CLIENT), )
  $(warning no SQL client)
  CONFIG_DEFS+= \\\#define SQL_CLIENT_NONE "\n"
endif


TEST_LIB?= -lboost_unit_test_framework$(BOOST_SUFFIX)


ifeq ($(LINK), DYNAMIC)
  CONFIG_DEFS+= \\\#define BOOST_ALL_DYN_LINK "\\n"
  STATICITY=
else
  STATICITY= -static
endif

CRYPTLIBDEFINED = CRYPTLIB
ifdef $(CRYPTLIBDEFINED)
  CONFIG_DEFS+= \\\#define CRYPT_LIB "\\n"
endif


.PHONY: all dep lib test TOUCH_PARSER_GENERATED
all:   lib test


config.h: CONFIG
	$(ECHO) "/* Generated from CONFIG.\n" \
	"* In order to keep your link directives appropriate for the features enabled\n" \
	"* by defines in this header, you should edit CONFIG and then \`make config.h\`.\n" \
	"*/\n" \
	"#define SWOb_DISABLED		135\n" \
	"/* XML Parsers: */\n" \
	"#define SWOb_LIBXML2		137\n" \
	"#define SWOb_EXPAT1		138\n" \
	"#define SWOb_MSXML3		139\n" \
	"/* Character Encodings: */\n" \
	"#define SWOb_UTF8		143\n" \
	"/* Regexp Libs: */\n" \
	"#define SWOb_BOOST		144\n" \
	"/* HTTP Libs: */\n" \
	"#define SWOb_ASIO		145\n" \
	"#define SWOb_DLIB		146\n" \
	"\n" $(CONFIG_DEFS) "\n" > config.h
	@$(ECHO) config.h updated.

#the gcc commands to make deps used in .d rules
#if -M[M]D is also in the build-clause without -E it update .d's as needed
TOONOISEY=-ansi
#for macports

# fussiness directives removed from CFLAGS:
#   -std=c++0x -- can't count on 0x on all platforms
#   -pedantic-errors -- breaks on OSX, aborts on #pragma
CFLAGS += $(DEFS) $(OPT) $(DEBUG) $(WARN) $(INCLUDES) -pipe -Wno-empty-body -Wno-missing-field-initializers -Wwrite-strings -Wno-deprecated -Wno-unused -Wno-non-virtual-dtor -Wno-variadic-macros -ftemplate-depth-128 -fno-merge-constants
CXXFLAGS += $(CFLAGS)

### absolutely neccessry for c++ linking ###
LD = $(CXX)
#LDFLAGS += $(STATICITY) $(LIBINC) $(REGEX_LIB) $(HTTP_CLIENT_LIB) $(XML_PARSER_LIB) $(SQL_CLIENT_LIB) -lrt
LDFLAGS += $(STATICITY) $(LIBINC) $(REGEX_LIB) $(HTTP_CLIENT_LIB) $(XML_PARSER_LIB) $(SQL_CLIENT_LIB) -luuid
LDAPPFLAGS += $(LDFLAGS) -lboost_program_options$(BOOST_SUFFIX) -lboost_filesystem$(BOOST_SUFFIX)
VER=0.1
COMPILE=CPATH=$(CPATH) $(CXX)
# LINK=LIBRARY_PATH=$(LIBRARY_PATH) $(CXX) $(LDFLAGS)
LINK=LIBRARY_PATH=$(LIBRARY_PATH) $(CXX)

#some progressive macports
#CC=llvm-gcc
#CXX=llvm-g++
#LLVMCFLAGS = ` llvm-config --cflags` -O4
#LLVMCXXFLAGS = ` llvm-config --cxxflags` -O4
#LLVMLDFLAGS = ` llvm-config --ldflags --libs `
#LLVMLIBS= ` llvm-config --libs`
# ... you get the idea...
CFLAGS	+= $(LLVMCFLAGS)
LIBINC	+= $(LIBS) -L$(PWD)/lib

### dirt simple generic static module ###
BISONOBJ :=  $(subst .ypp,.o,$(wildcard lib/*.ypp)) 
BISONH :=  $(subst .ypp,.hpp,$(wildcard lib/*.ypp)) 
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


ifdef $(CRYPTLIBDEFINED)
  INCLUDES += -I$(CRYPTLIB)
  LIBINC += -L$(CRYPTLIB) -lcryptopp
endif


LIBINC	 += -lboost_log$(BOOST_SUFFIX) -lboost_thread$(BOOST_SUFFIX) -lboost_filesystem$(BOOST_SUFFIX) -lboost_system$(BOOST_SUFFIX) -lboost_date_time$(BOOST_SUFFIX)


lib: dep $(LIB)

.SECONDARY:

lib/%.dep: lib/%.cpp config.h $(BISONH) docs/version.h
	($(ECHO) -n $@ lib/; $(COMPILE) -MM $< $(CFLAGS)) > $@ || (rm $@; false)

lib/%.o : lib/%.cpp lib/%.dep config.h docs/version.h
	$(COMPILE) -c -o $@ $< $(CFLAGS)



DEPEND += $(OBJLIST:.o=.dep) $(BISONOBJ:.o=.dep) $(FLEXOBJ:.o=.dep)
PARSER_GENERATED += $(BISONOBJ:.o=.cpp) $(BISONOBJ:.o=.hpp) $(FLEXOBJ:.o=.cpp)

# don't run flex and bison
TOUCH_PARSER_GENERATED:
	touch $(PARSER_GENERATED)

lib/%.cpp  lib/%.hpp : lib/%.ypp
	@mkdir -p tmp/$(*F)
	$(YACC) -o tmp/$(*F)/$(*F).cpp $<
	$(SED) -i~ 's,# define PARSER_HEADER_H,#pragma once,' tmp/$(*F)/$(*F).cpp
	$(SED) -i~ 's,"tmp/$(*F)/$(*F).cpp","lib/$(*F).cpp",' tmp/$(*F)/$(*F).cpp
	@mv tmp/$(*F)/$(*F).[hc]pp lib
	@rm -r tmp/$(*F)

lib/%.cpp : lib/%.lpp
	$(FLEX) -o $@  $<
	$(SED) -i~ 's,extern "C" int isatty (int );,extern "C" int isatty (int ) throw();,' $@


# # Parser maintenance
# lib/SPARQLParser/bnf-new:
# 	curl http://www.w3.org/2005/01/yacker/uploads/SPARUL_EGP/bnf | perl -pi -e 's{^\[\d+\]\s+(\S+)\s+::=\s+}{"[0]     $$1".(" " x (27-length($$1)))."::= "}e' > $@
# 
# lib/SPARQLParser/SPARQLParser-new.yy:
# 	curl http://www.w3.org/2005/01/yacker/uploads/SPARUL_EGP/SPARUL_EGPParser.yy -o $@
# 
# lib/SPARQLScanner-new.ll:
# 	curl http://www.w3.org/2005/01/yacker/uploads/SPARUL_EGP/SPARUL_EGPScanner.ll -o $@
# 
# SPARQL-next: lib/SPARQLParser/bnf-new lib/SPARQLParser/SPARQLParser-new.yy lib/SPARQLScanner-new.ll


# Status files
docs/version.h:
	((svn info 2>/dev/null) || (git --no-pager log --max-count=1 | perl -ne 'print "URL: $$1\nRevision: $$2\nLast Changed Date: $$1\n" if (m/^ +git-svn-id: (.*?)@(\d+) (.*)$$/); print "Last Changed Author: $$1\n" if (m/^Author: ([^ ]+) </);')) | perl -ne 'if (m/([^:]+): (.*)/) { my ($$attr, $$val) = ($$1, $$2); $$attr =~ s/ /_/g; print "#define SVN_$$attr \"$$val\"\n" }' > $@
	cp $@ win/

win/version.h: docs/version.h

# Was:	svn info . | perl -ne 'if (m/([^:]+): (.*)/) { my ($$attr, $$val) = ($$1, $$2); $$attr =~ s/ /_/g; print "#define SVN_$$attr \"$$val\"\n" }' > $@
# Made more complicated to address import to git by
##  git svn clone  -s -r1400:HEAD https://swobjects.svn.sourceforge.net/svnroot/swobjects -T trunk --branches=branches
##  cd swobjects/
##  git svn fetch --all
##  git checkout -b sparql11 remotes/sparql11


##### bin dirs ####

bin/%.dep: bin/%.cpp config.h $(BISONH) docs/version.h
	($(ECHO) -n $@ bin/; $(COMPILE) -MM $< $(CFLAGS)) > $@ || (rm $@; false)
DEPEND += $(BINOBJLIST:.o=.dep)

bin/%.o : bin/%.cpp bin/%.dep config.h docs/version.h
	$(COMPILE) -c -o $@ $< $(CFLAGS)

bin/% : bin/%.o $(LIB) #lib
	$(LINK) -o $@ $< $(LDAPPFLAGS) $(HTTP_SERVER_LIB)

unitTESTS := $(subst tests/test_,t_,$(TESTNAMELIST))
bin: $(BINOBJLIST:.o=)

release: bin/sparql.o $(LIB)
	$(LINK) -o $@ -static $< $(LDAPPFLAGS) $(HTTP_SERVER_LIB)


##### apache #####

# TODO: cleanup mod_sparul build, autoconf dependency paths?
apache/mod_sparul.dep: apache/mod_sparul.cpp config.h
	($(ECHO) $@ \\; $(CXX) -I`$(APXS) -q INCLUDEDIR` -I$(CODEA) -I$(CCL) -I$(APR) $(DEFS) $(CXXFLAGS) -MM $<) > $@ || (rm $@; false)

apache/mod_sparul.o: $(LIB) apache/mod_sparul.dep
	gcc -fPIC -Wall `$(APXS) -q CFLAGS` -I`$(APXS) -q INCLUDEDIR` -I$(CODEA) -I$(CCL) -I$(APR) $(INCLUDES) -c apache/mod_sparul.cpp -o apache/mod_sparul.o

# Using the freaky libtool .la file (which also builds .libs/mod_sparul.so , which is what we really want).
apache/mod_sparul.la: $(LIB) apache/mod_sparul.o
	$(APXS) -I$(CODEA) -I$(CCL) -I$(APR) -c apache/mod_sparul.o $(CODEA)/codea_hooks.o lib/libSWObjects.a $(LDFLAGS)

# Gets libtool to $(cp .libs/mod_sparul.so /usr/lib/apache2/modules/mod_sparul.so).
# Will need write privs on /usr/lib/apache2/modules/mod_sparul.{so,la} .
install-mod_sparul: apache/mod_sparul.la
	$(APXS) -i -n sparul_module apache/mod_sparul.la

clean-mod_sparul:
	rm -f apache/mod_sparul.{o,so,la} apache/.libs/mod_sparul.*


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

TEST_ARGS ?= ""
# Harness-specific arguments
# e.g. TEST_ARGS=--run_test=op_equals/* make -j 4 t_QueryMap
# e.g. TEST_ARGS=--output_format=XML\ --report_level=detailed\ --log_level=all\ --show_progress

# test-specific arguments:
# t_DM: --keep
# t_Turtle: --allchars

## Rules for all tests ##
tests/test_%.dep: tests/test_%.cpp config.h $(BISONH)
	($(ECHO) -n $@ tests/; $(COMPILE) -MM $< $(CFLAGS)) > $@ || (rm $@; false)

tests/test_%.o: tests/test_%.cpp tests/test_%.dep config.h
	$(COMPILE) -c -o $@ $< $(CFLAGS)

tests/test_%: tests/test_%.o $(LIB)
	$(LINK) -o $@ $< $(LDFLAGS) $(TEST_LIB)

t_%: tests/test_%
	@# Most of the tests are run from the tests dir to make it easier to find errant files.
	( cd tests && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ./$(notdir $<) $(TEST_ARGS) )


## Rules specific to certain tests ##
tests/TurtleTests:
	(cd tests && curl http://www.w3.org/2013/TurtleTests/TESTS.tar.gz | tar xzf -)

t_Turtle: tests/TurtleTests

tests/sparql11-test-suite:
	(cd tests && curl http://www.w3.org/2009/sparql/docs/tests/sparql11-test-suite-20121023.tar.gz | tar xzf -)
	# normalize expected results and apply fix described in
	#   http://www.w3.org/mid/50897A80.5020701@epimorphics.com
	(cd tests/sparql11-test-suite && patch -p 0 < ../sparql11-test-suite.patch)

t_SPARQL11: tests/sparql11-test-suite

tests/TrigTests:
	(cd tests && curl http://www.w3.org/2014/05/RDF-1.1-TrigTests.tar.gz | tar xzf -)

t_Trig: tests/TrigTests

t_DM: tests/test_DM tests/DM-manifest.txt bin/dm-materialize
	NLS_LANG=_.UTF8 LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(BOOST_TARGET)lib $^ $(DM_BASE_URI) $(SQL_DM_TESTS) $(TEST_ARGS)

tests/test_WEBagents: tests/test_WEBagents.o $(LIB)
	$(LINK) -o $@ $< -lboost_filesystem$(BOOST_SUFFIX) -lboost_thread$(BOOST_SUFFIX) $(LDFLAGS) $(TEST_LIB)

examples/functionExtension.o: examples/functionExtension.cpp
	$(COMPILE) -fPIC -c -o $@ $< $(CFLAGS)

examples/functionExtension.so: examples/functionExtension.o
	$(LINK) -shared -o $@ $< $(LDFLAGS)

ifdef $(CRYPTLIBDEFINED)
  t_SPARQL: bin/sparql
else
  t_SPARQL: bin/sparql examples/functionExtension.so
endif
t_SPARQL11: bin/sparql
t_SADI: bin/sparql
t_LDP: bin/sparql

tests/DM-report.xml: tests/test_DM tests/DM-manifest.txt bin/dm-materialize
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(BOOST_TARGET)lib $^ $(SQL_DM_TESTS) $(TEST_ARGS) --output_format=XML --report_level=detailed 2> $@

tests/DM-report-EARL.ttl: tests/DM-report.xml tests/report2earl.xsl
	$(XSLT) $^ > $@

DM-test: tests/DM-report-EARL.ttl bin/sparql
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(BOOST_TARGET)lib bin/sparql -d tests/DM-report-EARL.ttl -e 'PREFIX earl: <http://www.w3.org/ns/earl#> SELECT (substr(str(?name), 47) AS ?t) ?db (if (?result = <http://www.w3.org/ns/earl#passed>, 1, 0) AS ?p) { ?s earl:result [ earl:outcome ?result ] ; earl:test ?name ; earl:info ?db }'


## Valgrind tests ##
v_%: tests/test_%
	( cd tests && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib valgrind --leak-check=yes  --suppressions=boost-test.supp --xml=no --num-callers=32 ./$(notdir $<) $(TEST_ARGS) )
# update suppressions with --gen-suppressions=yes and copy to boost-test.supp


## "manual" (non-boost) tests, synthesized from the boost tests ##
.PHONY: tests/manualHarness.dep

tests/man_%.cpp: tests/test_%.cpp tests/makeMan.pl tests/manualHarness.cpp
	perl tests/makeMan.pl $< $@

tests/man_%.dep: tests/man_%.cpp config.h $(BISONH)
	($(ECHO) -n $@ tests/; $(COMPILE) -MM $< $(CFLAGS)) > $@ || (rm $@; false)
DEPEND += $(TESTSOBJLIST:.o=.dep)

tests/man_%.o: tests/man_%.cpp $(LIB) tests/.dep/man_%.d config.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tests/man_%: tests/man_%.o $(LIB)
	$(CXX) -o $@ $< $(LDFLAGS) $(TEST_LIB)

m_%: tests/man_%
	( cd tests && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib valgrind --leak-check=yes  --suppressions=boost-test.supp --xml=no --num-callers=32 ./$(notdir $<) $(TEST_ARGS) )


## Query Map tests tests ##

tests/HealthCare1.results: bin/sparql tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(BOOST_TARGET)lib $< tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq --stem http://someClinic.exampe/DB/

tests/HealthCare1.valgrind: bin/sparql tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(BOOST_TARGET)lib valgrind --leak-check=yes --xml=no $< tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq --stem http://someClinic.exampe/DB/

transformTESTS=tests/HealthCare1

transformTEST_RESULTS=$(transformTESTS:=.results)
transformVALGRIND=$(transformTEST_RESULTS:.results=.valgrind)


## sparql server tests ##

tests/server_mouseToxicity_remote-all.results: \
	bin/sparql \
	tests/mouseToxicity/remote-all/ToxicAssoc0.rq \
	tests/mouseToxicity/remote-all/MicroArray.map \
	tests/mouseToxicity/remote-all/Uniprot.map \
	tests/mouseToxicity/remote-all/ScreeningAssay.map \
	tests/mouseToxicity/remote-all/ChemStructure.map \
	tests/mouseToxicity/remote-all/MouseToxicity.map
	# Start servers.
	( cd tests/mouseToxicity/remote-all/ &&\
	  LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --debug 1 --once --serve http://localhost:8881/microArray -m MicroArray.map |\
	  tee ../../../$@.ma )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --debug 1 --once --serve http://localhost:8882/uniprot -m Uniprot.map |\
	  tee ../../../$@.up )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --debug 1 --once --serve http://localhost:8883/screeningAssay -m ScreeningAssay.map |\
	  tee ../../../$@.sa )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --debug 1 --once --serve http://localhost:8884/chemStructure -m ChemStructure.map |\
	  tee ../../../$@.cs )&
	( cd tests/mouseToxicity/remote-all/ &&\
	  LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --debug 1 --once --serve http://localhost:8885/mouseToxicity -m MouseToxicity.map |\
	  tee ../../../$@.mt )&
	sleep 1 # give the servers time to start up
	( cd tests/mouseToxicity/remote-all/ &&\
	  LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib time ../../../bin/sparql ToxicAssoc0.rq )


tests/7tm_receptors-flat.results: bin/sparql tests/7tm_receptors/flat/q.rq tests/7tm_receptors/flat/receptors.map
	( cd tests/7tm_receptors/flat/ && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --once --serve http://localhost:8888/7tm_receptors receptors.map > ../../../$@ )&
	sleep 1
	( cd tests/7tm_receptors/flat/ && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< q.rq )

tests/7tm_receptors-flat.results2: bin/sparql tests/7tm_receptors/flat/q.rq tests/7tm_receptors/flat/receptors.map
	( cd tests/7tm_receptors/flat/ && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< --once --serve --serve http://localhost:8888/7tm_receptors --mapset receptors.mapset > ../../../$@ )&
	sleep 1
	( cd tests/7tm_receptors/flat/ && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../$(BOOST_TARGET)lib ../../../$< q.rq )

SPARQL_serverTESTS=tests/server_mouseToxicity_remote-screening-assay

SPARQL_serverTEST_RESULTS=$(SPARQL_serverTESTS:=.results)

.PHONY: test valgrind tests/7tm_receptors-flat.results
test: lib $(unitTESTS) $(transformTEST_RESULTS)
valgrind: lib $(transformVALGRIND)


##### Generate SWIG Interfaces #####

SWIG ?= swig
# SWIG output fixups:
#   1. const const => const
#   2. in  va_list * temp = reinterpret_cast< va_list * >(argp3);
#          arg3 = *temp;
#      arg3 = *temp => va_copy(arg3, *temp)
SWIG_SUBST = perl -0777 -pi -e 's{const const}{const}g; s{(va_list\s*\*[^\r\n]+\r?\n\s*)(arg\d) = (\*temp)}{$${1}va_copy($$2, $$3)}g; s{( +)(arg\d) = \*\(reinterpret_cast< va_list \* >\((argp\d)\)\)}{$$1va_list * temp = reinterpret_cast< va_list * >($$3);\n$$1va_copy($$2, *temp)}g'

SWIG_SUBST_LUA = perl -0777 -pi -e 's{const const}{const}g; s{(va_list\s+arg(\d)\s+;)(.*?)(arg\2 = \*argp\2)}{\1\3va_copy(arg\2, *argp\2)}sg'

SWIG_SUBST_PHP = perl -0777 -pi -e 's{const const}{const}g; s{(va_list\s+arg(\d)\s+;)(.*?)(arg\2 = \*tmp\2)}{\1\3va_copy(arg\2, *tmp\2)}sg'


SWIG_OBJS = lib/exs.o lib/RdfQueryDB.o lib/ParserCommon.o lib/TurtleParser.o lib/TurtleScanner.o lib/TrigSParser.o lib/TrigSScanner.o lib/SPARQLParser.o lib/SPARQLScanner.o lib/MapSetParser.o lib/MapSetScanner.o lib/JSONresultsParser.o lib/JSONresultsScanner.o lib/ShExCSParser.o lib/ShExCSScanner.o
SWIG_HEADERS = lib/SWObjects.hpp lib/SWObjects.cpp lib/SWObjectDuplicator.hpp interface/SAXparser.hpp lib/XMLSerializer.hpp lib/RdfDB.cpp lib/ResultSet.hpp lib/ResultSet.cpp lib/RdfDB.hpp lib/SWObjects.cpp lib/SPARQLSerializer.hpp lib/RuleInverter.hpp lib/QueryMapper.hpp lib/MapSetParser.hpp interface/WEBagent_boostASIO.hpp interface/SAXparser_expat.hpp lib/ParserCommon.hpp lib/SPARQLParser.hpp lib/TurtleParser.hpp lib/TrigSParser.hpp interface/WEBagent.hpp lib/JSONresultsParser.hpp lib/ShExCSParser.hpp
SWIG_LIBS =  $(REGEX_LIB) $(HTTP_CLIENT_LIB) $(XML_PARSER_LIB) $(SQL_CLIENT_LIB)

 # Python
swig/python/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HEADERS)
	$(SWIG) -o $@ -c++ -python -I. -Ilib -Iinterface $<
	$(SWIG_SUBST) $@

swig/python/SWObjects_wrap.o: swig/python/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -fno-stack-protector -c -o swig/python/SWObjects_wrap.o swig/python/SWObjects_wrap.cxx $(PYTHON_INC) $(INCLUDES)

swig/python/_SWObjects.so: swig/python/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS) -L$(BOOST_TARGET)lib

# The _SWObjects.so target can be built with the python distutils package,
# but it's noisier and doesn't re-use the object files in lib:

# swig/python/_SWObjects.so: swig/python/SWObjects_wrap.cxx swig/python/SWObjects_setup.py
# 	python swig/python/SWObjects_setup.py build_ext --inplace -I.:lib/:interface/
# 	mv _SWObjects.so swig/python/

python-test: swig/python/_SWObjects.so
	(cd swig/python/ && LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):../../$(BOOST_TARGET)lib python t_SWObjects.py)

python-clean:
	$(RM) -f swig/python/SWObjects.* swig/python/SWObjects_wrap.* swig/python/_SWObjects.so

SWIG-TEST += python-test
SWIG-CLEAN += python-clean

## Java ##
swig/java/src/AtomFactory.java swig/java/src/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HEADERS)
	-$(RM) swig/java/src/*.java
	$(SWIG) -o swig/java/src/SWObjects_wrap.cxx -c++ -java -I. -Ilib -Iinterface swig/SWObjects.i
	$(SWIG_SUBST_LUA) swig/java/src/SWObjects_wrap.cxx

swig/java/src/SWObjects_wrap.o: swig/java/src/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -fno-stack-protector -c -o $@ $< -I$(JAVA_HOME)/include $(INCLUDES)

swig/java/libSWObjects.so: swig/java/src/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS) -L$(BOOST_TARGET)lib

swig/java/SWObjects.jar: swig/java/src/AtomFactory.java # there are zillions of class files, use AtomFactory as an indicator
	-$(RM) $@
	javac -d swig/java/class swig/java/src/*.java
	jar cf $@ -C swig/java/class .

swig/java/t_SWObjects.class: swig/java/t_SWObjects.java swig/java/SWObjects.jar
	javac -d swig/java -classpath .:/usr/share/java/hamcrest-core.jar:/usr/share/java/junit4.jar:swig/java/SWObjects.jar $<

java-test: swig/java/libSWObjects.so swig/java/t_SWObjects.class
	LD_LIBRARY_PATH=$(BOOST_TARGET)lib:swig/java java -classpath .:/usr/share/java/hamcrest-core.jar:/usr/share/java/junit4.jar:swig/java:swig/java/SWObjects.jar org.junit.runner.JUnitCore t_SWObjects

java-clean:
	$(RM) -f swig/java/libSWObjects.so swig/java/class/* swig/java/src/* swig/java/t_SWObjects.class

SWIG-TEST += java-test
SWIG-CLEAN += java-clean

## Perl ##
swig/perl/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HEADERS)
	$(SWIG) -o $@ -c++ -perl5 -I. -Ilib -Iinterface $<
	$(SWIG_SUBST) $@

swig/perl/SWObjects_wrap.o: swig/perl/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -c -o $@ $< -I$(PERL_HOME)/CORE $(INCLUDES)

swig/perl/libSWObjects.so: swig/perl/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS) -L$(BOOST_TARGET)lib

perl-test: swig/perl/libSWObjects.so
	(cd swig/perl/ && LD_LIBRARY_PATH=../../$(BOOST_TARGET)lib perl t_SWObjects.t)

perl-clean:
	$(RM) -f swig/perl/SWObjects.* swig/perl/SWObjects_wrap.* swig/perl/libSWObjects.so

SWIG-TEST += perl-test
SWIG-CLEAN += perl-clean


## Lua ##
swig/lua/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HEADERS)
	$(SWIG) -o $@ -c++ -lua -I. -Ilib -Iinterface $<
	$(SWIG_SUBST_LUA) $@

swig/lua/SWObjects_wrap.o: swig/lua/SWObjects_wrap.cxx
	g++ $(OPTIM) -I. -Ilib/ -Iinterface/ -fPIC -c -o $@ $< -I$(LUA_HOME) $(INCLUDES)

swig/lua/SWObjects.so: swig/lua/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS)

lua-test: swig/lua/SWObjects.so
	(cd swig/lua/ && LD_LIBRARY_PATH=../../$(BOOST_TARGET)lib shake t_SWObjects.lua)

lua-clean:
	$(RM) -f swig/lua/SWObjects.* swig/lua/SWObjects_wrap.* swig/lua/libSWObjects.so

SWIG-TEST += lua-test
SWIG-CLEAN += lua-clean


## Php ##
swig/php/SWObjects_wrap.cxx: swig/SWObjects.i $(SWIG_HEADERS)
	$(SWIG) -DYYDEBUG=0 -o $@ -c++ -php -I. -Ilib -Iinterface $<
	$(SWIG_SUBST_PHP) $@

swig/php/SWObjects_wrap.o: swig/php/SWObjects_wrap.cxx
	g++ $(OPTIM) -DHAVE_LIBEXPAT=1 -I. -Ilib/ -Iinterface/ -fPIC -fno-stack-protector -c -o swig/php/SWObjects_wrap.o swig/php/SWObjects_wrap.cxx -I$(PHP_HOME) $(INCLUDES)

swig/php/SWObjects.so: swig/php/SWObjects_wrap.o $(SWIG_OBJS)
	g++ -shared -o $@ $< $(SWIG_OBJS) $(SWIG_LIBS) -L$(BOOST_TARGET)lib

php-test: swig/php/SWObjects.so
	(cd swig/php/ && LD_LIBRARY_PATH=../../$(BOOST_TARGET)lib php -d extension=./SWObjects.so t_SWObjects.php)

php-clean:
	$(RM) -f swig/php/SWObjects.* swig/php/SWObjects_wrap.* swig/php/_SWObjects.so

SWIG-TEST += php-test
SWIG-CLEAN += php-clean

swig-test: $(SWIG-TEST)
swig-clean: $(SWIG-CLEAN)


##### Mac OSX stuff #####
Sparql.app/Contents/MacOS:
	mkdir -p $@

Sparql.app/Contents/Frameworks:
	mkdir -p $@

.PHONY: RenamedFrameworks

RenamedFrameworks: Sparql.app/Contents/Frameworks
	cp /usr/lib/libstdc++.6.dylib $<
	install_name_tool -id @executable_path/../Frameworks/libstdc++.6.dylib $</libstdc++.6.dylib
	for l in regex system program_options log filesystem thread date_time; do \
		cp /opt/local/lib/libboost_$$l-mt.dylib $< && \
		install_name_tool -id @executable_path/../Frameworks/libboost_$$l-mt.dylib $</libboost_$$l-mt.dylib && \
		install_name_tool -change /opt/local/lib/libboost_system-mt.dylib @executable_path/../Frameworks/libboost_system-mt.dylib $</libboost_$$l-mt.dylib; \
	done
	for l in ssl.0.9.8 crypto.0.9.8 z.1; do \
		cp /opt/local/lib/lib$$l.dylib $< && \
		install_name_tool -id @executable_path/../Frameworks/lib$$l.dylib $</lib$$l.dylib && \
		install_name_tool -change /opt/local/lib/libcrypto.0.9.8.dylib @executable_path/../Frameworks/libcrypto.0.9.8.dylib $</lib$$l.dylib && \
		install_name_tool -change /opt/local/lib/libz.1.dylib @executable_path/../Frameworks/libz.1.dylib $</lib$$l.dylib; \
	done
	cp /opt/local/lib/mysql5/mysql/libmysqlclient.16.dylib $</libmysqlclient.dylib
	install_name_tool -id @executable_path/../Frameworks/libmysqlclient.16.dylib $</libmysqlclient.dylib
	install_name_tool -change /opt/local/lib/libssl.0.9.8.dylib @executable_path/../Frameworks/libssl.0.9.8.dylib $</libmysqlclient.dylib
	install_name_tool -change /opt/local/lib/libcrypto.0.9.8.dylib @executable_path/../Frameworks/libcrypto.0.9.8.dylib $</libmysqlclient.dylib
	install_name_tool -change /opt/local/lib/libz.1.dylib @executable_path/../Frameworks/libz.1.dylib $</libmysqlclient.dylib


Sparql.app/Contents/MacOS/Sparql: bin/sparql.o $(LIB) Sparql.app/Contents/MacOS RenamedFrameworks
	$(CXX) -o $@ $< -LSparql.app/Contents/Frameworks $(LDAPPFLAGS) $(HTTP_SERVER_LIB)
# Runs something like:
#	g++ -o Sparql.app/Contents/MacOS/Sparql bin/sparql.o -LSparql.app/Contents/Frameworks
#	 -mmacosx-version-min=10.5 -L/opt/local/lib/mysql5/mysql/ -arch x86_64
#	 -L/opt/local/lib/ -L/opt/local/lib/mysql5/ -L/Users/ericp/checkouts/sparql11/lib
#	 -lSWObjects -lboost_regex-mt -lpthread -lboost_system-mt -lexpat -lmysqlclient -lz
#	 -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt -lboost_thread-mt -lpthread
# It would be nice to eliminate -L/opt/* as they should all be in @executable_path/../Frameworks/ .


Sparql.dmg: Sparql.app/Contents/MacOS/Sparql
	rm -f $@
	hdiutil create -srcfolder Sparql.app $@
	mkdir tmp_mount && hdiutil mount Sparql.dmg -mountroot tmp_mount && (cd tmp_mount/Sparql/Sparql.app/Contents/MacOS/ && ./Sparql --version); hdiutil detach tmp_mount/Sparql && rmdir tmp_mount


##### Clean - rm everything we remember to rm #####
.PHONY: clean parse-clean meta-clean cleaner
clean:
	$(RM) *.o lib/*.a lib/*.dylib lib/*.so lib/*.la *.bak config.h \
	$(subst .ypp,.o,$(wildcard lib/*.ypp)) \
        $(transformTEST_RESULTS) $(transformVALGRIND) \
	$(unitTESTexes) *~ *.dep */*.dep

parse-clean:
	$(RM) \
	$(subst .lpp,.cpp,$(wildcard lib/*.lpp)) \
	$(subst .ypp,.cpp,$(wildcard lib/*.ypp)) \
	$(subst .ypp,.hpp,$(wildcard lib/*.ypp)) \
	$(BISONHH:%=*/%)

meta-clean:
	$(RM) \
	docs/version.h

cleaner: clean parse-clean meta-clean swig-clean

dep: $(DEPEND)

BISONHH=location.hh stack.hh position.hh
#$(BISONHH): $(BISONOBJ)
-include $(DEPEND)
