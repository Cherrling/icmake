#define XERR
#include "process.ih"

int Process::softLinks() const
{
    string const &spchGch = d_options.spchGch();

    ifstream in{ Exception::factory<ifstream>(d_options.spch()) };
    string line;
    while (getline(in, line))           // get the files to precompile
    {
        if (spchFile(line) and not softLink(spchGch, line))
            return 1;
    }

    return 0;
}
