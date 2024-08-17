#define XERR
#include "rhbuilder.ih"

void RHbuilder::inspectRHfiles()
{
    for (string const &rhFile: d_rhFiles)
        inspect(rhFile);
}
