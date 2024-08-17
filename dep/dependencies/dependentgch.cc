//#define XERR
#include "dependencies.ih"

    // the gch in directory 'idx' was marked for removal. Mark all gch files
    // in directories that depend on directory 'idx' also for removal
void Dependencies::dependentGch(size_t idx)
{
        // find directories not requiring gch removals
    size_t dep = 0;
    while ((dep = findIdx(d_indicator, dep, false)) != d_size)
    {
        if (d_dependency[dep][idx])     // if it depends on 'idx'
        {
            log(V4) << '`' << d_directory[dep] << 
                    "' depends on `" << d_directory[idx] << 
                    "': recompile\n";

            d_indicator[dep] = true;    // so it's dir. must be removed

            dependentGch(dep);          // recursively inspect directory[dep]
        }
        ++dep;
    }
}

