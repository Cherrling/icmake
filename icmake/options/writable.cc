#define XERR
#include "options.ih"

bool Options::writable(string &dirName)
{
    if (Stat{ dirName }.isType(Stat::DIRECTORY) 
        and
        access(dirName.c_str(), R_OK | W_OK | X_OK) == 0
    )
    {
        if (dirName.back() != '/')
            dirName += '/';
        return true;
    }

    return false;
}
