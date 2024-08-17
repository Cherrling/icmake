//#define XERR
#include "dependencies.ih"

void Dependencies::directDependencies()
{
    if (not d_options.mainIH().empty())     // start with main.ih, if present
    {
        log(V4) << "Inspecting the main project directory\n";
        dependency(0, d_options.mainIH());
    }

                                            // then visit all other dirs.
    for (size_t idx = 1; idx != d_size; ++idx)
    {
        log(V4) << "Inspecting directory `" << 
                                                d_directory[idx] << "'\n";

        d_inspecting.clear();           // local headers being inspected

        Tools::mustChangeDir(d_directory[idx]);
        dependency(idx, ihFile(idx));
        d_options.startDir();
    }

    setCount();

    showDependencies("Direct class dependencies:");
}


