#define XERR
#include "rhbuilder.ih"

RHbuilder::RHbuilder(Options const &options)
:
    Classes(options)            // provides 'options()'
{}

//    if (options.modify(options.spch()))
//        d_combined = Exception::factory<ofstream>(options.spch());
