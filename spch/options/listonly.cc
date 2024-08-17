#define XERR
#include "options.ih"

bool Options::listOnly(string *member, int optChar)
{
    if (not d_arg.option(member, optChar))
        return false;
    d_listOnly = true;
    return true;
}
