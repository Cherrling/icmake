#define XERR
#include "handler.ih"

Handler::Handler(Options &splitter)
:
    d_splitter(splitter),
    d_verbose(d_splitter.verbose()),
    d_doProcess(d_splitter.process())
{
    setPreOptions();
    setExecOptions();
}
