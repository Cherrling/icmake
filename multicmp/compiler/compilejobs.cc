#define XERR
#include "compiler.ih"

void Compiler::compileJobs(size_t threadIdx, string const &absCwd)
{
    CompileFork compileFork{ threadIdx, d_showID, d_nQuiet, d_compiler,
                             d_dataVect, absCwd };

    while (compileFork.compile())               // true: continue, false: stop
        ;
}

