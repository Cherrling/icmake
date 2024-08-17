#define XERR
#include "options.ih"

void Options::internalOpt()
{
    dotRequired(&d_internal, "internal", 'i');

    d_internalOption = not d_internal.empty();

    if (not d_internalOption)
        d_internal = ".ih";
}
