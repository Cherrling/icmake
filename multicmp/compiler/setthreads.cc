#include "compiler.ih"

void Compiler::setThreads()
{
    string value;
    if (d_arg.option(&value, 't'))
        d_nThreads = stoul(value);
    else 
        d_nThreads = thread::hardware_concurrency();

    d_thread.resize(d_nThreads);
}
