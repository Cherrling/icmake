//#define XERR
#include "compilefork.ih"

namespace
{
    int outFds[] =
        {
            Redirector::STDOUT,
            Redirector::STDERR
        };
}

void CompileFork::childRedirections()
{
    d_childOutput.writtenBy(outFds, 2);
}
