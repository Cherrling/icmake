#define XERR
#include "support.ih"

// static
bool Support::skip(string &line)
{
    if (
        size_t pos = line.find("//");       // find comment
        pos != string::npos                 // if found, remove the comment
    )
        line.resize(pos);

    line = String::trim(line);
    return line.empty();
}
