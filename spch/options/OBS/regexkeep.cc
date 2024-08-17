#define XERR
#include "options.ih"

void Options::splitKeep(string spec)
{
    while (s_spec << spec)
    {
        d_keep.insert(s_spec[0]);
        spec = s_spec.beyond();
    }
}
