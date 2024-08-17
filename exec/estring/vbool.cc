//#define XERR
#include "estring.ih"

bool EString::vBool() const
{
    return not d_str.empty();
}
