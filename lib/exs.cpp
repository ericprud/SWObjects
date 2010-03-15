#include "exs.hpp"

std::vector<std::string> journal;

StackException varBarfer (char const* type, char const* file, size_t line, char const* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    StackException ret = StackException(type, file,  line, fmt, args);
    va_end(args);
    return ret;
}
