#define XERR
#include "rhbuilder.ih"

namespace 
{
    bool n_lastEmpty = false;
}

bool RHbuilder::xfer(StringVect::iterator &iter, ostream &rhStream)
{
                                // found an #include in the .ih file: write it
                                // to the .rh file
    if ((s_include << *iter) and not options().keep(s_include[1]))
    {
        rhStream << *iter << '\n';
        return true;
    }

    if (iter->find_first_not_of(" \t") != string::npos) // not an empty line
        n_lastEmpty = false;
    else
    {
        if (n_lastEmpty)                        // rm series of empty lines
            return true;

        n_lastEmpty = true;                     // keep the 1st empty line
    }

    return false;
}
