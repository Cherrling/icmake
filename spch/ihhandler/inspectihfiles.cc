#define XERR
#include "ihhandler.ih"

void IHhandler::inspectIHfiles()
{
    for (string const &filename: d_ihFiles)
        merge(inspect(filename));
}
