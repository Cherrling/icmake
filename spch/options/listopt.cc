#define XERR
#include "options.ih"

void Options::listOpt()
{
    if (                                    // continue at --list option
        d_listOption = d_arg.option('l');
        not d_listOption
    )
        return;

    d_spch = d_arg[0];

    if (not plainSpchName("--list"))        // the spch must be a plain name 
        return;


    if (d_internal == d_required)           // check for equal extensions
        emsg << "--internal and --required must specify "
                "different extensions" << endl;
}
