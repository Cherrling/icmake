//#define XERR
#include "main.ih"

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"classes",      'c'},
        Arg::LongOption{"help",         'h'},
        Arg::LongOption{"guard",        'g'},
        Arg::LongOption{"internal",     'i'},
        Arg::LongOption{"keep",         'k'},
        Arg::LongOption{"list",         'l'},
        Arg::LongOption{"no-topdir",    'n'},
        Arg::LongOption{"precompile",   'p'},
        Arg::LongOption{"required",     'r'},
        Arg::LongOption{"soft-link",    's'},
        Arg::LongOption{"version",      'v'},
        Arg::LongOption{"warn",         'w'},
    };
    auto longEnd = longOpts + size(longOpts);
}

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::initialize("c:g:hi:k:lnp:r:s:vw", longOpts, longEnd, 
                                                            argc, argv);
    arg.versionHelp(usage, VERSION, 1);

    Process process;
    return process.run();
}
catch (...)
{
    return handleException();
}

