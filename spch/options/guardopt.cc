#define XERR
#include "options.ih"

void Options::guardOpt()
{
    if (d_guardOption = listOnly(&d_guard, 'g'); not d_guardOption)
        d_guard = "SPCH_";
    else if (d_guard == "SPCH")
        throw Exception{} << "`--guard SPCH' cannot be specified";
}
