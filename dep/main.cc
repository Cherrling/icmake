#define XERR
#include "main.ih"

#include "../tmp/INSTALL.im"

namespace
{
    Arg::LongOption longOpts[] =
    {
        Arg::LongOption{"classes",      'c'             },
        Arg::LongOption{"gch",          Arg::None       },
        Arg::LongOption{"help",         'h'             },
        Arg::LongOption{"mainih",       'm'             },
        Arg::LongOption{"no-gch",       Arg::None       },
        Arg::LongOption{"no-use-all",   Arg::None       },
        Arg::LongOption{"use-all",      Arg::Required   },
        Arg::LongOption{"verbose",      'V'             },
        Arg::LongOption{"version",      'v'             },
    };
    auto longEnd = longOpts + size(longOpts);
}

Log g_log{ cout, 0 };

int main(int argc, char **argv)
try
{
    g_log.setTimestamp(NOTIMESTAMPS);

    Arg const &arg = Arg::initialize("c:hm:Vv", longOpts, longEnd, 
                                             argc, argv);
    arg.versionHelp(usage, VERSION, 1);

    Options options;                // handles options, using Arg

    if (options.go() == UNSPECIFIED)
        usage(arg.basename());

    Dependencies dependencies(options);
    dependencies.find();

    dependencies.useAll();          // when requested: check the useAll files
    dependencies.gchFiles();        // when requested: check the .gch files
}
catch(int x)
{
    return Arg::instance().option("hv") ? 0 : x;
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}

catch (...)
{
    cerr << "unexpected exception\n";
    return 1;
}
