//#define XERR
#include "options.ih"

void Options::parserDir()
{
    string const &value = s_icmconf[2];

    if (value.empty())
        return;

    d_parser = value;
    log(V2) << "parser dir.: `" << d_parser << "'\n";
}
