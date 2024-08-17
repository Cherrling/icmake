//#define XERR
#include "options.ih"

void Options::scannerDir()
{
    string const &value = s_icmconf[2];

    if (value.empty())
        return;

    d_scanner = value;
    log(V2) << "scanner dir.: `" << d_scanner << "'\n";
}
