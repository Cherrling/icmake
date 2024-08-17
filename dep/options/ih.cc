//#define XERR
#include "options.ih"

void Options::ih()
{
    d_ih = s_icmconf[2];            // get the uses .ih extension
//    string const &value = s_icmconf[2];
//
//    if (value.empty())
//        return;
//
//    d_ih = value;
//    log(V2) << "used header extension: `" << d_ih << "'\n";
}
