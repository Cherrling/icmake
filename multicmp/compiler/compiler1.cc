#define XERR
#include "compiler.ih"

Compiler::Compiler(Arg const &arg)
:
    d_arg(arg),
    d_showID(d_arg.option('n')),
    d_nQuiet(d_arg.option('q')),
    d_jobs(Exception::factory<ifstream>(arg[0])),
    d_compiler(Tools::compilerSpec(arg[1], s_compileCommand))
{
    setThreads();                       // sets d_available
    fillData();                         // sets d_filled

    if (d_dataVect.size() < d_nThreads)     // nJobs < d_nThread? then reduce
        d_nThreads = d_dataVect.size();     // d_nThreads

    if (d_nThreads == 0)
        throw 0;
}

