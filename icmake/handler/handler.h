#ifndef INCLUDED_HANDLER_
#define INCLUDED_HANDLER_

#include <iosfwd>
#include <string>

#include "../../tmp/build/process/process"

class Options;

class Handler
{
    Options &d_splitter;
    FBB::Process d_process;

    unsigned d_idx;
    bool d_verbose;
    bool d_doProcess;
    std::string d_tmpDir;
    std::string d_file2;
    std::string d_preOptions;
    std::string d_execOptions;
    static int (Handler::*s_action[])();

    public:
        Handler(Options &splitter);
        int process();

    private:
        int compile();
        int dependencies();
        int exec();                                                 // 1
        int forced();
        int multicomp();
        int preprocess();
        int spch();
        int source();
        int script();
        int unassemble();

        bool run(std::string const &cmd);
                                                // how is &direct or &child
        int exec(int (Handler::*how)(std::string const &cmd));      // 2

        int direct(std::string const &cmd);     // calls LIBDIR/cmd 
                                                // using Process::DIRECT
        int child(std::string const &cmd);      // same, uses Process::NONE

        std::string const &file2(char const *extension);

                                    // concatenate all argv elements from
                                    // begin to end, starting with an initial
                                    // space
        std::string catArgs(unsigned begin, unsigned end) const;

        bool doCompile() const;

        void setPreOptions();                       // .ih
        void setExecOptions();

        std::string range(unsigned begin, unsigned end) const;
};
        
#endif
