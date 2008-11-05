DEBUG:=-g
#OPT=-O4
WARN:=-W -Wall -Wextra -Wnon-virtual-dtor
# --pedantic
# pedantic works on GNU if you uncomment the isatty (int ) throw() patch below
# -ansi
# ansi is or was a bit noisy

INCLUDES += -I.. -I../SPARQLfedParser -I../TurtleSParser
.PHONY: all dep lib test

PWD ?= $(shell pwd -P)

.SECONDARY:

%.d : %.cpp
	-touch $@
	-makedepend -y -f $@ $^ $(DEFS) $(INCLUDES) 2>/dev/null

#the gcc commands to make deps used in .d rules
#if -M[M]D is also in the build-clause without -E it update .d's as needed
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
LIBINC	+= -L..

### dirt simple generic static module ###
OBJLIST  :=  $(subst .cpp,.o,$(wildcard *.cpp))
EXELIST  :=  $(subst .cpp,,$(wildcard *.cpp))
LIBNAME  :=  SWObjects
LIB	 :=	 ../lib$(LIBNAME).a
LIBINC	+=	 -l$(LIBNAME)

all:   $(EXELIST)

$(LIB): ../SWObjects.hpp
	cd .. && make $(LIB)

.PHONY: lib
#lib: dep $(LIB)
lib: dep $(LIB)

%.o. : %.cpp %.d
	$(CXX) $(CXXFLAGS) -o $@ $<

% : %.o $(LIB) #lib
	$(CXX) -o $@ $< $(LDFLAGS)

DLIBINC ?= ../../dlib
DLIB= -D NO_MAKEFILE -I$(DLIBDIR)

SPARQL_server.o : SPARQL_server.cpp
	$(CXX) $(DEFS) $(OPT) $(DEBUG) $(INCLUDES) $(DLIB) -c -o $@ $<

SPARQL_server : SPARQL_server.o $(LIB) #lib
	$(CXX) -lnsl -lpthread -lboost_regex -L/usr/local/lib/mysql -lmysqlclient -o $@ $< $(LDFLAGS)

# list of tests

TEST_RESULTS += HealthCare1.results
HealthCare1.results: SWtransformer ../tests/query_HealthCare1.rq ../tests/ruleMap_HealthCare1.rq
	$< -q -d ../tests/query_HealthCare1.rq ../tests/ruleMap_HealthCare1.rq -s http://someClinic.exampe/DB/

HealthCare1.valgrind: SWtransformer ../tests/query_HealthCare1.rq ../tests/ruleMap_HealthCare1.rq
	valgrind --leak-check=yes --xml=no $< -q -d ../tests/query_HealthCare1.rq ../tests/ruleMap_HealthCare1.rq -s http://someClinic.exampe/DB/


VALG_RESULTS =  $(subst .results,.valgrind,$(TEST_RESULTS))

test: $(TEST_RESULTS)

valgrind: $(VALG_RESULTS)

# Clean - rm everything we remember to rm.
.PHONY: clean cleaner
clean:
	$(RM) $(EXELIST) *.o \
        $(TEST_RESULTS) $(VALG_RESULTS)

cleaner: clean
	$(RM) *.d *.bak

deps=SWtransformer.d SPARQL_server.d

dep: $(deps)

-include $(deps)
