//#define XERR
#include "estring.ih"

strong_ordering EString::vOrder(VarBase const &rhs) const
{
    return d_str < rhs.str() ? strong_ordering::less    :
           d_str > rhs.str() ? strong_ordering::greater :
                               strong_ordering::equal;
}
