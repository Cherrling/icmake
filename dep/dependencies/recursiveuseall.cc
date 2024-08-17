//#define XERR
#include "dependencies.ih"

    // called from inspectUseAll

void Dependencies::recursiveUseAll(size_t dep)
{
    d_indicator[dep] = true;

    Tools::mustChangeDir(d_directory[dep]);
    log(V4) << "add implied " << 
                        d_directory[dep] << '/' << d_useAll << '\n';
    touchUseAll();
    d_options.startDir();

    inspectUseAll(dep);             // check useAll files for directories
                                    // depending on dep
}
