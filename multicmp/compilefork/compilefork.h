#ifndef INCLUDED_COMPILEFORK_
#define INCLUDED_COMPILEFORK_

#include <iosfwd>
#include <vector>
#include <mutex>
#include <atomic>

#include "../../tmp/build/fork/fork"
#include "../../tmp/build/pipe/pipe"

#include "../data/data.h"

class CompileFork: public FBB::Fork
{
    using DataVect = std::vector<Data>;

    FBB::Pipe d_childOutput;   // child writes this

    size_t d_id;
    bool d_showID;    

    size_t d_nQuiet;

    std::string const &d_compiler;      // received
    std::string d_compileCmd;           // d_compiler with replaced $1 and $2

    DataVect const &d_dataVect;
    Data const *d_data;
    
    std::string const &d_absCwd;        // received
    std::vector<std::string> d_lines;   // compilation output

    int d_ret;

    static std::mutex s_staticData;     // mutex for the static data
    static std::mutex s_echo;           // mutex for the echo function
    static size_t s_dataIdx;
    static bool s_ok;

    public:
        CompileFork(size_t id, bool d_showID, size_t nQuiet, 
                    std::string const &compiler, DataVect const &dataVect, 
                    std::string const &absCwd);

        bool compile();

        static bool ok();

    private:
        void prepareCmd();

        bool done();
        void echo();                    // writes d_compileCmd 
        bool quit();

        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;
};

inline bool CompileFork::ok()
{
    return s_ok;
}

#endif




