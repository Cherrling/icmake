//#define XERR
#include "dependencies.ih"

void Dependencies::touchUseAll() const
{
    if (d_options.go() == GO)
        Exception::factory<ofstream>(d_useAll); // touch by creating the file
}
