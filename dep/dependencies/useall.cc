//#define XERR
#include "dependencies.ih"

void Dependencies::useAll()
{
    xerr("useAll: `" << d_useAll << '\'');

    if (d_useAll.empty())               // no use-all checks requested
        return;

    useAllIndicator();                  // prepare d_indicator for useAll

                                        // visit all directories and maybe
                                        // touch all files in those
                                        // directories 
    for (size_t idx = 0; idx != d_size; ++idx)
        inspectUseAll(idx);

    log(V4) << "UseALL inspection completed\n";
}







