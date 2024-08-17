//#define XERR
#include "options.ih"

Options::Options()
:
    d_arg(Arg::instance()),
    d_cwd(filesystem::current_path().string())
{
    setVerbosity();

    d_arg.option(&d_classes, 'c');

    if (d_arg.option(&d_icmconf, 'i'))
        g_log << level(V2) << "icm-dep: using icmconf `" << d_icmconf << 
                                                                        "'\n";

    if (d_arg.option(0, "gch"))
    {
        d_gch = GCH;
        g_log << level(V2) << "icm-dep: inspecting .gch files\n";
    }

    if (d_arg.option(&d_mainIH, 'm'))
        g_log << level(V2) << "icm-dep: using main.ih `" << d_mainIH << "'\n";

    if (d_arg.option(0, "no-use-all"))
    {
        g_log << level(V2) << "icm-dep: USE_ALL files are not inspected\n";
        d_useAll.clear();
    }
    else if (d_arg.option(&d_useAll, "use-all"))
        g_log << level(V2) << "icm-dep: using USE_ALL filename `" << 
                                d_useAll << "'\n";

    if (d_arg[0] == "go"s)
        d_go = GO;

    if (not Tools::exists(d_classes))
    {
        g_log << level(V2) << "icm-dep: Classes file `" << d_classes << 
                                                            "' not found\n";
        throw 0;
    }

    scanIcmconf();

    if (d_gch == UNSPECIFIED)
    {
        g_log << level(V1) << "icm-dep: .gch files are not handled\n";
        d_gch = NO_GCH;
    }

    if (d_useAll[0] == 0)   
    {
        g_log << level(V1) << "icm-dep: USE_ALL files are not handled\n";
        d_useAll.clear();
    }
}
