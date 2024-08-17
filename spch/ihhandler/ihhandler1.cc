#define XERR
#include "ihhandler.ih"

IHhandler::IHhandler(Options const &options)
:
    Classes(options),
//    d_options(options),
//    d_classes(options.classes()),
//    d_useTopDir(options.topDir())
    d_defineSPCH("#define " + options.guard() + "\n\n"),
    d_ifndefSPCH("#ifndef " + options.guard()),
    d_ifndefSPCHre(R"_(^\s*#ifndef\s+)_" + options.guard() + R"_((\s|$))_" )
{
    if (options.modify(options.spch()))
        d_spch = Exception::factory<ofstream>(options.spch());
}
