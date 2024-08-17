#define XERR
#include "ihhandler.ih"

IHhandler::StringVect IHhandler::inspect(string const &ihName)
{
    StringVect lines = read(ihName);

    StringVect ret;             // to contain the using declarations;

    if (not lines.empty())
    {
        if (ret = update(lines); not ret.empty())
            write(ihName, lines);
    
        d_spch << "#include \"" << ihName << "\"\n";
    }

    return ret;
}
