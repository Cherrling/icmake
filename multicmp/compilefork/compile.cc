#define XERR
#include "compilefork.ih"

bool CompileFork::compile()
{
    if (done())
        return false;

    prepareCmd();

    d_childOutput = Pipe{};                 // to collect output fm the child

    fork();                                 // compile the source file
    
    if (quit())
        return false;

    if (d_ret != 0 and d_nQuiet == 0)
        ++d_nQuiet;

    echo();

    return d_ret == 0;
}


