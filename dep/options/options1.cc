#define XERR
#include "options.ih"

Options::Options()
:
    d_arg(Arg::instance()),
    d_cwd(filesystem::current_path().string()),
    d_mainIH("main.ih"),
    d_gch(UNSPECIFIED),
    d_go(DRY),
    d_spch(UNSPECIFIED)

{
    setVerbosity();

    if (not d_arg.option(&d_classes, 'c'))  // configured  CLASSES file
        d_classes = "CLASSES";

    if (not d_arg.option(&d_icmconf, 'i'))  // configured icmconf file
        d_icmconf = "icmconf";
    else
        log(V2) << "icm-dep: using icmconf `" << d_icmconf << "'\n";

                                            // may set d_spch, 
    scanIcmconf();                          // set scan icmconf 

    if (d_arg.option(&d_mainIH, 'm'))
        log(V2) << "using main.ih `" << d_mainIH << "'\n";

    setGch();

    setUseAll();    

    if (d_arg[0] == "go"s)
    {
        d_go = GO;

        if (not Tools::exists(d_classes))
        {
            log(V2) << "classes file `" << d_classes << "' not found\n";
            throw 0;
        }
    }
}
