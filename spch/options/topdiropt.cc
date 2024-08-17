#define XERR
#include "options.ih"

void Options::topDirOpt()
{
    if (d_topDirOption = d_arg.option('n'); not d_topDirOption)
        d_topDir = true;
    else
    {
        d_topDir = false;
        d_listOnly = true;
    }
}

