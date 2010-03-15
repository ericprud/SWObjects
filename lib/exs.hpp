#ifndef EXS_HPP
#define EXS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdarg>
#include "SWObjects.hpp"

extern std::vector<std::string> journal;

struct StackException : w3c_sw::StringException {
    StackException (char const* type, char const* file, size_t line, const char* fmt, va_list args) : 
	w3c_sw::StringException(make(type, file, line, fmt, args)) {  }
protected:
    std::string make (char const* type, std::string file, size_t line, char const* fmt, va_list args) {
	static char str[1024];
	std::stringstream s;
	vsprintf(str, fmt, args);
	s << type << ": " << std::endl << file << ":" << line << ": " << str << std::endl;
	for (std::vector<std::string>::reverse_iterator it = journal.rbegin();
	     it != journal.rend(); ++it)
	    s << *it << std::endl;
	return s.str();
    }
};

class JournalState {
public:
    JournalState (std::string file, size_t line, std::string what) {
	journal.push_back(format(file, line, what));
    }
    ~JournalState () { journal.pop_back(); }
    static void now (std::string file, size_t line, std::string what) {
	journal.pop_back();
	journal.push_back(format(file, line, what));
    }
    static std::string format (std::string file, size_t line, std::string what) {
	std::stringstream loc;
	loc << file << ":" << line << ": " << what;
	return loc.str();
    }
};

StackException varBarfer (char const* type, char const* file, size_t line, char const* fmt, ...);

#define MARK JournalState _(__FILE__,  __LINE__, FUNCTION_STRING)
#define START(X) JournalState _(__FILE__,  __LINE__, X)
#define NOW(X) JournalState::now(__FILE__,  __LINE__, X)
#define FAIL(X) throw(varBarfer("FAIL", __FILE__,  __LINE__, X))
#define FAIL1(X, a) throw(varBarfer("FAIL", __FILE__,  __LINE__, X, a))
#define FAIL2(X, a, b) throw(varBarfer("FAIL", __FILE__,  __LINE__, X, a, b))
#define FAIL3(X, a, b, c) throw(varBarfer("FAIL", __FILE__,  __LINE__, X, a, b, c))
#define FAIL4(X, a, b, c, d) throw(varBarfer("FAIL", __FILE__,  __LINE__, X, a, b, c, d))

#endif /* !EXS_HPP */
