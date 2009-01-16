# $Id: Makefile,v 1.56 2009-01-16 11:29:21 eric Exp $
# SWObjects build rules -- see http://www.w3.org/2008/04/SPARQLfed/

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

FLEX:=flex
YACC:=bison
TEE:=tee
SED:=sed
#LIBS
DEBUG:=-g
#OPT=-O4
DEFS:=-DYYTEXT_POINTER=1
WARN:=-W -Wall -Wextra -Wnon-virtual-dtor
# --pedantic
# pedantic works on GNU if you uncomment the isatty (int ) throw() patch below

INCLUDES += -I${PWD}  
I2=$(subst /, ,$(BISONOBJ:.o=))
I3=$(sort $(I2))

INCLUDES += $(I3:%=-I${PWD}/%)
.PHONY: all dep lib test
all:   lib test


PWD ?= $(shell pwd -P)

.SECONDARY:

%.d : %.cpp
	-touch $@
	-makedepend -y -f $@ $^ $(DEFS) $(INCLUDES) 2>/dev/null

%.cpp  %.hpp : %.ypp
	$(YACC) -o $(@:.hpp=.cpp) $<
	$(SED) -i~ 's,# define PARSER_HEADER_H,#pragma once,' $(@:.cpp=.hpp)

%.cpp : %.lpp
	$(FLEX) -o $@  $<

#	$(SED) -i~ 's,extern "C" int isatty (int );,extern "C" int isatty (int ) throw();,' $@


#the gcc commands to make deps used in .d rules
#if -M[M]D is also in the build-clause without -E it update .d's as needed
TOONOISEY=-ansi
#for macports
CFLAGS += $(DEFS) $(OPT) $(DEBUG) $(WARN) $(INCLUDES) -pipe
CXXFLAGS += $(CFLAGS)

### absolutely neccessry for c++ linking ###
LD = $(CXX)
LDFLAGS += $(LIBINC)
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
LIBINC	+= -L$(PWD)

### dirt simple generic static module ###
BISONOBJ :=  $(subst .ypp,.o,$(wildcard */*.ypp)) 
FLEXOBJ  :=  $(subst .lpp,.o,$(wildcard *.lpp))
OBJLIST  :=  $(subst .cpp,.o,$(wildcard *.cpp))
LIBNAME  :=  SWObjects
LIB	 :=	 lib$(LIBNAME).a
LIBINC	+=	 -l$(LIBNAME) -lboost_regex

$(LIB): $(BISONOBJ) $(FLEXOBJ) $(OBJLIST)
	$(AR) rcvs $@ $^

.PHONY: lib
lib: dep $(LIB)

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

# bin/
bin/%.d : bin/%.cpp
	-touch $@
	-makedepend -y -f $@ $^ $(DEFS) $(INCLUDES) 2>/dev/null

bin/%.o. : bin/%.cpp bin/%.d
	$(CXX) $(CXXFLAGS) -o $@ $<

bin/% : bin/%.o $(LIB) #lib
	$(CXX) -o $@ $< $(LDFLAGS)

# tests/
tests/test_%: tests/test_%.cpp $(LIB) SWObjects.hpp
	$(CXX) $(CXXFLAGS) -lboost_regex -lboost_unit_test_framework -o $@ $< $(LDFLAGS)
	$@

unitTESTS=tests/test_GraphMatch

### SWtransformer tests:

tests/HealthCare1.results: bin/SWtransformer tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	$< -q -d tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq -s http://someClinic.exampe/DB/

tests/HealthCare1.valgrind: bin/SWtransformer tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq
	valgrind --leak-check=yes --xml=no $< -q -d tests/query_HealthCare1.rq tests/ruleMap_HealthCare1.rq -s http://someClinic.exampe/DB/

transformTESTS=tests/HealthCare1

transformTEST_RESULTS=$(transformTESTS:=.results)
transformVALGRIND=$(transformTEST_RESULTS:.results=.valgrind)

.PHONY: test valgrind
test: lib $(unitTESTS) $(transformTEST_RESULTS)
valgrind: lib $(transformVALGRIND)

# Distributions

release:
	$(RM) -f SWObjects_$(VER).tar.gz README.html
	lynx -dump -source http://www.w3.org/2008/04/SPARQLfed/ | perl -pe 's{href="\.\./\.\./\.\.}{href="http://www.w3.org}g;s{href="\.\./\.\.}{href="http://www.w3.org/2008}g'> README.html
	@echo "Generating the inclusion from the manifest (HEADER.html)"
	@(echo "README.html" && perl -ne 'print join("\n", m/class="tar" href="([a-zA-Z]{2}[a-zA-Z0-9._\/]+)"/g, undef)' HEADER.html) | xargs tar czf SWObjects_$(VER).tar.gz --transform s,,SWObjects_$(VER)/,1
	$(RM) README.html


# Clean - rm everything we remember to rm.
.PHONY: clean cleaner
clean:
	$(RM) *.o */*.o *.a *.dylib *.so *.la */*.bak *.bak \
        $(subst .lpp,.cpp,$(wildcard *.lpp)) \
        $(subst .ypp,.cpp,$(wildcard */*.ypp)) \
        $(subst .ypp,.hpp,$(wildcard */*.ypp)) \
        $(transformTEST_RESULTS) $(transformVALGRIND)
	$(RM) -fr tests/execute_*

cleaner: clean
	 $(RM) *~ */*.d *.d $(BISONHH:%=*/%)

deps=$(BISONOBJ:.o=.d) $(FLEXOBJ:.o=.d) $(OBJLIST:.o=.d)

dep: $(deps)

BISONHH=location.hh stack.hh position.hh
#$(BISONHH): $(BISONOBJ)
-include $(deps)


