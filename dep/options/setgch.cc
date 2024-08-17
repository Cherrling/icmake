//#define XERR
#include "options.ih"

void Options::setGch()
{
    bool gch = d_arg.option(0, "gch");          // maybe update gch by option
    if (d_arg.option(0, "no-gch") and gch)
        throw Exception{} << "icm-dep: cannot specify both --gch and "
                                                        "--no-gch";
    if (d_spch != UNSPECIFIED)
    {
        log(V2) << "#define SPCH is used: no .gch inspection\n";
        return;
    }

    switch (d_gch)
    {
        default:
        break;

        case GCH:
            log(V1) << "inspecting precompiled headers (.gch files)\n";
        break;
    
        case NO_GCH:
            log(V1) << "not inspecting precompiled headers (.gch files)\n";
        break;
    }
}



