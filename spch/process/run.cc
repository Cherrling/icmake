#define XERR
#include "process.ih"

int Process::run()
{
    if (d_options.list())           // construct the ./spch file
        return spch();

    if (d_options.precompile())     // precompile the header at 'p' to dest
        return precompile();

    if (d_options.softLink())       // construct the soft-links to dest.
        return softLinks();

    throw Exception{} << "One of options --list, --precompile or --soft-links "
                         "must be specified";
}
