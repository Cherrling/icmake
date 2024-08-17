#define XERR
#include "options.ih"

// static
bool Options::keep(std::string const &spec)
{
    return s_keep << spec;
}
