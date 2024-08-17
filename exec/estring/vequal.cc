//#define XERR
#include "estring.ih"

bool EString::vEqual(VarBase const &rhs) const
{
    return d_str == rhs.str();
}
