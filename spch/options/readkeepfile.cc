#define XERR
#include "options.ih"

void Options::readKeepFile(string const &filename)
{
    ifstream in{ Exception::factory<ifstream>(filename) };

    string regex;
    string line;
    while (getline(in, line))
    {
        line = String::trim(line);
        if (not line.empty())
            regex += '(' + line + ")|";
    }

    if (regex.empty())
    {
        emsg << "--keep filename: at least one regex is required" << endl;
        return;
    }

    regex.resize(regex.length() - 1);       // rm the final '|'
    s_keep = Pattern{ regex };
}
