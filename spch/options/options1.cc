#define XERR
#include "options.ih"

#include <sstream>

Options::Options()
:
    d_arg(Arg::instance()),
    d_listOnly(false),
    d_warn(d_arg.option('w'))
{
    classesOpt();

    internalOpt();
    dotRequired(&d_required, "required", 'r');

    guardOpt();

    keepOpt();

    listOpt();
    precompileOpt();
    softLinkOpt();

    topDirOpt();

    checkOptions();
}
