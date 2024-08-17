//#define XERR
#include "options.ih"

// static
char const *Options::getHome()
{
    char const *cp = getenv("HOME");
    return cp != 0 ? cp : s_empty;
}
