//#define XERR
#include "options.ih"

void Options::action(unsigned *index)
{
    if (*index == 0)
        *index = d_optIdx;

    setAction();
}
