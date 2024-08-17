#define XERR
#include "process.ih"

bool Process::softLink(string const &spchGch,       // define one soft-link
                       string const &spchFile) const
{
    string dest = pathTo(spchGch, spchFile);        // prefix ../ if needed


    string link = spchFile + ".gch";                // the name of the link

    error_code s_ec;

    Tools::remove(link);

    return Tools::createSymlink(dest, link);
}
