#ifndef INCLUDED_BUILTIN_
#define INCLUDED_BUILTIN_

#include <unordered_map>
#include <filesystem>
#include <string>
#include <vector>

#include "../../tmp/build/glob/glob"

#include "../../tmp/build/builtinfunctions/builtinfunctions.h"

// see stack/README for a description of the organization of the stack.

class Variable;
class Stack;

namespace FBB
{
    class Pattern;
    class Process;
    class Stat;
}
class Builtin
{
    struct GlobSpecs
    {
        FBB::Glob::Type  type;
        int              flags;
    };

    std::filesystem::path d_orgDir;     // startup working directory

    std::string d_cmdHead;
    std::string d_cmdTail;
    std::string d_argHead;
    std::string d_argTail;

    Stack &d_stack;
    bool d_echo = true;
    Variable &d_reg;
    std::unordered_map<std::string, std::string> d_environment;

    static char const s_space[];        // all isspace() characters
    static FBB::Pattern s_percent;
    static std::unordered_map<int, GlobSpecs> const s_globSpecs;
    static void(Builtin::*s_function[])();

    public:
        Builtin(Variable &reg, Stack &stack);

        void call(size_t funIdx);       // call builtin function 'funIdx'

        static char const *name(size_t funIdx);

        bool echo() const;

    private:
                                        // begin: index of 1st arg to process,
                                        // end: index beyond the last arg
        void insert(std::ostream &out, size_t begin, size_t end) const;  

                                            // insert the args without 
                                            // arg-replacements
        void insertDirect(std::ostream &out, size_t begin, size_t end) const;

                                            // insert the args replacing
                                            // %\d elements. 
        void insertReplace(std::ostream &out, std::string arg1, size_t begin) 
                                                                        const;

        std::vector<std::string> patternList()  const;
        std::vector<std::string> olderList()  const;                    // .f
        std::vector<std::string> youngerList()  const;                  // .f

        std::vector<std::string> patternCompare(
                    bool (*keep)(std::string const &, FBB::Stat const &)
                ) const;

        void execute(bool check, char const *label, 
                     FBB::Process &process, void (FBB::Process::*member)());

        bool setEnv(std::string const &spec);   // called by putEnvironment
        void removeEnv(std::string &spec);

        static void unionAdd(std::vector<std::string> &dest, 
                             std::string const &src);

    // See ../../tmp/build/builtinfunctions/builtinfunctions.h
    // 0
    void argHead();
    void argTail();
    void asciiStr2int();
    void asciiInt2str();            

    // 4
    void backtick();
    void changeBase();
    void changeExtension();
    void changePath();

    // 8
    void chdir();
    void cmdHead();
    void cmdTail();
    void echo();

    // c
    void listElement();
    // eval()                      eval: handled by backtick
    void exec();
    // ececute()                // execute: only used by the compiler();
                                //          no separate function required
    // 10
    void exists();
    void fgets();
    void fprintf();
    void getBase();

    // 14
    void getDotExtension();
    void getExtension();
    void getPath();
    void getCh();  

    // 18
    void getEnvironVar();
    void getPid();
    void gets();
    void listLen();

    // 1c
    void makeList();
    void printf();
    void putEnvironment();
    void stat();

    // 20
    void strElement();
    void strFind();
    void strFormat();
    void strLength();

    // 24
    void strLowercase();
    void resize();
    void strTok();
    void strUppercase();

    // 28
    void substring();
    void system();
    void trim();
    void trimLeft();

    // 2c
    void trimRight();
    void strChr();
    void listFind();
    void listUnion();

    // 30
    void listConstruct();
};

#include "call.f"
#include "name.f"
#include "echo.f"

#endif
