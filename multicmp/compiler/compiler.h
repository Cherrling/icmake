#ifndef INCLUDED_COMPILER_
#define INCLUDED_COMPILER_

#include <fstream>
#include <vector>
#include <thread>

#include "../data/data.h"

class CompileFork;

namespace FBB
{
    class Arg;
}


class Compiler
{
    FBB::Arg const &d_arg;

    bool d_showID;
    size_t d_nQuiet;
    
    std::vector<Data> d_dataVect;

    std::vector<std::thread> d_thread;

    std::ifstream d_jobs;

    std::string d_source;
    std::string d_object;
    std::string d_compiler;

    size_t d_nThreads;

    static std::string s_compileCommand;

    public:
        Compiler(FBB::Arg const &arg);
        ~Compiler();                    // removes the jobs-file

        int compile();

    private:
        void setThreads();
        void fillData();

        void compileJobs(size_t threadIdx, std::string const &absCwd);
};

#endif

