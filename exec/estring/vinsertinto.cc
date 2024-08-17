//#define XERR
#include "estring.ih"

ostream &EString::vInsertInto(ostream &out) const
{
    return out << d_str;
}
