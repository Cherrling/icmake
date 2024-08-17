#define XERR
#include "options.ih"

void Options::checkOptions()
{
    if (
        not
        (d_listOption or d_precompileOption or d_softLinkOption)
    )
        emsg << "One of the options --list, --precompile or --soft-link "
                " must be specified" << endl;
    else
    {        
        if (
            (d_listOption and (d_precompileOption or d_softLinkOption))
            or
            (d_precompileOption and d_softLinkOption)
        )
            emsg << "Only one of the options --list, --precompile or "
                    "--soft-link can be specified" << endl;
    
//        if (d_listOption and d_required.empty() and d_keepOption)
//            emsg << "--keep requires option --required" << endl;

        if (d_topDirOption and (d_precompileOption or d_softLinkOption))
            emsg << "--classes, --guard, --internal, --keep, --no-topdir, "
                    "--required, and --no-topdir cannot be specified with "
                    "--precompile or --soft-link" << endl;
    }

    if (emsg.count() != 0)
        throw 1;
}
