#define XERR
#include "options.ih"

void Options::keepOpt()
{
    string value;
    if (d_keepOption= listOnly(&value, 'k'); not d_keepOption)
        return;

    error_code ec;
    if (value.find("f:") == 0)
        readKeepFile(value.substr(2));
    else
        s_keep = Pattern{ value };
}
