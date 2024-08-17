#define XERR
#include "compiler.ih"

int Compiler::compile()
{
    string absCwd = Tools::absolute(Tools::currentPath().string()) + '/';

    for (size_t idx = 0; idx != d_nThreads; ++idx)      // start the threads
        d_thread[idx] = thread{ &Compiler::compileJobs, ref(*this), 
                                idx, absCwd };

                                                        // wait for them to
    for(size_t idx = 0; idx != d_nThreads; ++idx)       // end
        d_thread[idx].join();

    return CompileFork::ok() ? 0 : 1;
}
