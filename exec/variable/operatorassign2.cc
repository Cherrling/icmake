//#define XERR
#include "variable.ih"

Variable &Variable::operator=(std::string const &str)
{
    Variable tmp{ new EString{ str } };    
    swap(tmp);
    return *this;
}
