//#define XERR
#include "functions.ih"

Functions::Info::Info(unsigned from, ExprType retType)
:
    offset(from),
    returnType(retType)
{}
