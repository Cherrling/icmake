#define XERR
#include "rhbuilder.ih"

    // determine the .ih filename from rhFile

string RHbuilder::ihFrom(string const &rhFile) const
{
    size_t pos = rhFile.rfind(options().extension());   // find the extension
    return rhFile.substr(0, pos) + options().internal();
}
