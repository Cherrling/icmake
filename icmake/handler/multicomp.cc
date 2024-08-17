#define XERR
#include "handler.ih"

int Handler::multicomp()
{
    return direct("icm-multicomp" + 
                    catArgs(d_splitter.actionArgsIdx(), d_splitter.argc())); 
//    xerr( catArgs(d_splitter.actionArgsIdx(), d_splitter.argc())); 
//    xerr( d_splitter.argv(d_splitter.argc() - 1)); 
//    return 0;
}
