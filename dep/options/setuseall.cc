//#define XERR
#include "options.ih"

void Options::setUseAll()
{
    if (not d_arg.option(0, "no-use-all"))
        log(d_arg.option(&d_useAll, "use-all") ? V1 : V2) <<
                "USE_ALL filename: `" << d_useAll << "'\n";
    else
    {
        log(V1) << "not inspecting USE_ALL files\n";
        d_useAll.clear();
    }
}
