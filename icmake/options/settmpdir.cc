//#define XERR
#include "options.ih"

void Options::setTmpDir()
{
    if (d_tmpDir.empty())                       // no 'T' option
    {
        d_tmpDir = "/tmp/";                     // first try /tmp
        if (writable(d_tmpDir))
            return;

        d_tmpDir = getHome();                   // else try HOME
        if (writable(d_tmpDir))
            return;
    }
    else if (writable(d_tmpDir))                 // 'T' option specified
        return;

    throw Exception{} << "tmp. dir `" << d_tmpDir << "' not writable";

}
