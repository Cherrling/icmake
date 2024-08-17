#define XERR
#include "semval.ih"
 
SemVal &SemVal::insert2(short value)
{
//    if (not d_ignoreNext)
//    {
    endian(&d_code, value);
//    }

    return *this;
}
