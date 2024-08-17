#define XERR
#include "process.ih"

int Process::spch() const
{
    return d_options.rh() ? 
                RHbuilder{ d_options }.run()
            :
                IHhandler{ d_options }.run();
}
