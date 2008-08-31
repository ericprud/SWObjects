#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> journal;

struct barf : exception {
    char const* str;
    char const* what() const throw() { return str; }
    barf (char const* type, char const* file, size_t line, const char* str) : 
	exception() , str(make(type, file, line, str)) {  }
protected:
    char const* make (char const* type, string file, size_t line, char const* str) {
	stringstream s;
	s << type << ": " << file << ":" << line << ": " << str << endl;
	for (vector<string>::reverse_iterator it = journal.rbegin();
	     it != journal.rend(); ++it)
	    s << *it << endl;
	cerr << s.str().c_str();
	return str;
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

