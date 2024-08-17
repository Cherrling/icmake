//#define XERR
#include "estring.ih"

VarBase *EString::vcopy() const
{
    return new EString{ d_str };
}
