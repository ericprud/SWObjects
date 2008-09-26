#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdarg>
#include "SWObjects.hpp"

using namespace std;

vector<string> journal;

struct barf : w3c_sw::StringException {
    barf (char const* type, char const* file, size_t line, const char* fmt, va_list args) : 
	w3c_sw::StringException(make(type, file, line, fmt, args)) {  }
protected:
    std::string make (char const* type, string file, size_t line, char const* fmt, va_list args) {
	static char str[1024];
	stringstream s;
	vsprintf(str, fmt, args);
	s << type << ": " << endl << file << ":" << line << ": " << str << endl;
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

barf varBarfer (char const* type, char const* file, size_t line, char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    barf ret = barf(type, file,  line, fmt, args);
    va_end(args);
    return ret;
}

#define MARK JournalState _(__FILE__,  __LINE__, __PRETTY_FUNCTION__)
#define START(X) JournalState _(__FILE__,  __LINE__, X)
#define NOW(X) JournalState::now(__FILE__,  __LINE__, X)
#define FAIL(X) throw(varBarfer("FAIL", __FILE__,  __LINE__, X))
#define FAIL1(X, a) throw(varBarfer("FAIL", __FILE__,  __LINE__, X, a))
#define FAIL2(X, a, b) throw(varBarfer("FAIL", __FILE__,  __LINE__, X, a, b))

