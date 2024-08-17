#define XERR
#include "options.ih"

void Options::precompileOpt()
{
    d_precompileOption = spchGch("--precompile", 'p');
}
