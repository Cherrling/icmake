#define XERR
#include "options.ih"

bool Options::plainSpchName(char const *option)
{
    if (d_spch.contains('/') or fs::path{ d_spch }.extension() != "")
    {
        emsg << option << ": `" << d_spch <<
                "' extension and/or '/' characters are not supported" << endl;
        return false;
    }

    return true;
}
