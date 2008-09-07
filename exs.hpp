#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "SWObjects.hpp"

using namespace std;

vector<string> journal;

struct barf : w3c_sw::StringException {
    barf (char const* type, char const* file, size_t line, const char* str) : 
	w3c_sw::StringException(make(type, file, line, str)) {  }
protected:
    std::string make (char const* type, string file, size_t line, char const* str) {
	stringstream s;
	s << type << ": " << file << ":" << line << ": " << str << endl;
	for (vector<string>::reverse_iterator it = journal.rbegin();
	     it != journal.rend(); ++it)
	    s << *it << endl;
	return s.str();
    }
};

class JournalState {
public:
    JournalState (string file, size_t line, string what) {
	journal.push_back(format(file, line, what));
    }
    ~JournalState () { journal.pop_back(); }
    static void now (string file, size_t line, string what) {
	journal.pop_back();
	journal.push_back(format(file, line, what));
    }
    static string format (string file, size_t line, string what) {
	stringstream loc;
	loc << file << ":" << line << ": " << what;
	return loc.str();
    }
};

#define MARK JournalState _(__FILE__,  __LINE__, __PRETTY_FUNCTION__)
#define START(X) JournalState _(__FILE__,  __LINE__, X)
#define NOW(X) JournalState::now(__FILE__,  __LINE__, X)
#define FAIL(X) throw(barf("FAIL", __FILE__,  __LINE__, X))

