#define XERR
#include "options.ih"

bool Options::depOrDef()
{
    if (s_options[0].name != "dependencies"s)
        return false;

    setAction();
    return true;
}
