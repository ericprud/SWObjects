# $Id: Makefile,v 1.29 2008-08-20 07:16:04 eric Exp $
# SWObjects build rules -- see http://www.w3.org/2008/04/SPARQLfed/

# recipies:
#   normal build:
#     make SPARQLfed
#   force the use of the tracing facilities (and redirect to stdout):
#     make -W sample_RuleMap1.cc test
#   have valgrind start a debugger (works as M-x gdb invocation command):
#     valgrind --db-attach=yes --leak-check=yes sample_RuleMap1 query_HealthCare1.rq ruleMap_HealthCare1.rq
#   same, if you aren't working in gdb:
#     make valgrind
#   debugging in emacs:
#     gdb --annotate=3 sample_RuleMap1    (set args query_HealthCare1.rq ruleMap_HealthCare1.rq)

# BUGS:
#   .hh dependency probs -- use .deps?

#%.d : %.ll 
#	touch $@	
#	makedepend -f $@ $^ $(DEFS) $(INC)

#%.d : %.yy
#	touch $@	
#	makedepend -f $@ $^ $(DEFS) $(INC) 

#%.d :  %.cc  
#	touch $@	
#	makedepend -f $@ $^ $(DEFS) $(INC) 

#buggered
#%.d : %.cc 
#	$(CXX) $(DEFS) $(INC) -MMD -E $^

%.d : %.cc
	touch $@
	makedepend -f $@ $^ $(DEFS) $(INC) 2>/dev/null

%.cc %.hh : %.yy 
	$(YACC) -o $(@:.hh=.cc) -b $(<:.yy=)  $< 
	$(SED) -i.d.bak 's,# define PARSER_HEADER_H,#pragma once,' $(@:.cc=.hh)


#%.cc : %.yy
#	$(YACC) -o $@ -o $(subst .hh,.cc,$@)   $< 

%.cc : %.ll
	$(FLEX) -o $@  $< 

FLEX=flex
YACC=bison
TEE=tee
SED=sed
#LIBS
DEBUG=-g
#OPT=-O4
DEFS=-DYYTEXT_POINTER=1
WARN=-W -Wall -Wextra 

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
CFLAGS += $(LLVMCFLAGS)   
INCLUDES+=-I${PWD} -I/opt/include
LIBINC+= -L${PWD} -L/opt/local/lib -lm


### dirt simple generic static module ###
BISONOBJ =$(subst .yy,.o,$(wildcard *.yy))
BISONHH=location.hh stack.hh position.hh
FLEXOBJ=  $(subst .ll,.o,$(wildcard *.ll))
OBJLIST = $(subst .cc,.o,$(wildcard *.cc))
LIBNAME=SWObjects
LIB=lib$(LIBNAME).a
LIBINC+=-l$(LIBNAME)

$(LIB):$(BISONOBJ) $(FLEXOBJ) $(OBJLIST) 
	$(AR) rcvs $@ $^
##############

##### packaged tests ####

## test inferenced based on T, test_<T>.o=C/C++ query_<T>.rq ruleMap<T>.rq

tests/execute_%  : tests/test_%.o  tests/query_%.rq tests/ruleMap_%.rq $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

%_test.results : tests/execute_% tests/query_%.rq tests/ruleMap_%.rq
	$^ > $@  && cat $@

%_test.valgrind  : tests/execute_% tests/query_%.rq tests/ruleMap_%.rq
	valgrind --leak-check=yes --xml=no $@ $^

### named unit tests

TESTS=HealthCare1

TEST_RESULTS=$(TESTS:=_test.results)
test: $(LIB) $(TEST_RESULTS) 


VALGRIND=$(TEST_RESULTS:.results=.valgrind)
valgrind: $(VALGRIND)

# Distributions

dist: $(LIB)
	$(RM) -f SWObjects_$(VER).tar.gz README.html
	lynx -dump -source http://www.w3.org/2008/04/SPARQLfed/ | perl -pe 's{href="\.\./\.\./\.\.}{href="http://www.w3.org}g;s{href="\.\./\.\.}{href="http://www.w3.org/2008}g'> README.html
	$(ECHO) "Generating the inclusion from the manifest (HEADER.html)"
	$(PERL) -ne 'print join("\n", "README.html", m/href="([a-zA-Z]{2}[a-zA-Z0-9._]+)"/g, undef)' HEADER.html | xargs tar czf SWObjects_$(VER).tar.gz --transform s,,SWObjects_$(VER)/,1
	$(RM) README.html
# Clean - rm everything we remember to rm.

clean:
	$(RM) *.o *.a *.dylib *.so *.la *.d.bak \
        $(subst .ll,.cc,$(wildcard *.ll)) \
        $(subst .yy,.cc,$(wildcard *.yy)) \
        $(subst .yy,.hh,$(wildcard *.yy)) \
        $(TEST_RESULTS) $(VALGRIND) 
	rm -fr tests/execute_*

cleaner: clean
	$(RM) *.d $(BISONHH)

.PHONY:  all test valgrind dist clean cleaner

all: $(LIB) test 

include $(BISONOBJ:.o=.d) $(FLEXOBJ:.o=.d) $(OBJ:.o=.d) 

