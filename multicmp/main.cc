//#define XERR
#include "main.ih"

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"help", 'h'},
        Arg::LongOption{"nr", 'n'},
        Arg::LongOption{"quiet", 'q'},
        Arg::LongOption{"threads", 't'},
        Arg::LongOption{"version", 'v'},
    };
    auto longEnd = longOpts + size(longOpts);
}

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::initialize("hnt:qv", longOpts, longEnd, argc, argv);
    arg.versionHelp(usage, VERSION, 1);

    return Compiler{ arg }.compile();
}
catch (...)
{
    return handleException();
}
