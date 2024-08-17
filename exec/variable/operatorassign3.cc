//#define XERR
#include "variable.ih"

Variable &Variable::operator=(string &&str)
{
    Variable tmp{ new EString{ move(str) } };    
    swap(tmp);
    return *this;
}
