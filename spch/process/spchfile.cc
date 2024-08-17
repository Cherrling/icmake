#define XERR
#include "process.ih"

// static
bool Process::spchFile(string &line)
{
    if (not (s_include << line))
        return false;

    line = s_include[1];
    return true;
}
