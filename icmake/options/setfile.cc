//#define XERR
#include "options.ih"

string Options::setFile(unsigned idx)
{
    if (d_argv[idx][0] != '-')              // not an option
    {
        ++d_nFiles;
        return d_argv[idx];
    }

    return s_empty;
}
