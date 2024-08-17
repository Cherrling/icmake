#define XERR
#include "options.ih"

void Options::setFiles()
{
    switch (d_argc - d_optIdx)
    {
        case 0:
        return;

        case 1:
            d_file1 = setFile(d_optIdx);
        return;

        default:
            d_file1 = setFile(d_optIdx);
            if (not d_file1.empty() and d_action != SOURCE)
                d_file2 = setFile(d_optIdx + 1);
        return;            
    }
}


