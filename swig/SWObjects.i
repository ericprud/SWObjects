/* File: SWObjects.i */
%module SWObjects

%{
#define SWIG_FILE_WITH_INIT
#include "config.h"
#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "RdfDB.hpp"
%}

#include "SWObjects.cpp"
#include "ResultSet.cpp"
#include "RdfDB.cpp"
#include "ParserCommon.cpp"
#include "TurtleSParser/TurtleSParser.cpp"
#include "TurtleSScanner.cpp"
#include "TrigSParser/TrigSParser.cpp"
#include "TrigSScanner.cpp"
