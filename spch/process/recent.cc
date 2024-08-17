#define XERR
#include "process.ih"

bool Process::recent(string const &spchGch, string const &spch)
{
    if (not Tools::exists(spchGch))
        return false;

    d_spchGchTime = Stat{ spchGch }.lastModification();

                                // true if spch.gch is older than an 
    return not older(spch);         // #included "..." file
}
