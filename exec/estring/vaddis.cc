//#define XERR
#include "estring.ih"

VarBase &EString::vAddIs(VarBase const &rhs)
{
    d_str += rhs.str();
    return *this;
}
