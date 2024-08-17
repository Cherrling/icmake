//#define XERR
#include "tools.ih"

// static
ostream &Tools::usageTop(string const &progname, bool showUsage)
{
    cout << '\n' <<
        progname << " by " AUTHOR "\n" <<
        progname << " V" VERSION "\n"
        "Copyright (c) GPL " YEARS ". NO WARRANTY.\n"
        "\n";

    if (showUsage)
        cout << "Usage: " << progname;

    return cout;
}
