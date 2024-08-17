#define XERR
#include "options.ih"

bool Options::spchGch(char const *option, int optChar)
{
    if (not (d_arg.option(&d_spch, optChar) and plainSpchName(option)))
        return false;

    d_spchGch = d_arg[0];                       // name/path to spch.gch 

    if (d_spchGch.back() == '/')                // last == '/': append d_spch 
        d_spchGch += d_spch + ".gch";

    error_code ec;
    if (not Tools::createDirectories(fs::path{ d_spchGch }.parent_path()))
        throw Exception{} << "cannot create the directory of " << d_spchGch;

    return true;
}   
