#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>
#include <unordered_map>
#include <filesystem>

#include "../../tmp/build/arg/arg"

#include "../action/action.h"

namespace FBB
{
    class Pattern;
    class Arg;
}

class Options
{
    FBB::Arg const &d_arg;

    std::string d_cwd;
    std::string d_classes;
    std::string d_icmconf;
    std::string d_mainIH;
    std::string d_useAll;               // by default use the icmconf spec
                                        // changed to the name of the USE_ALL
                                        // file or empty
    std::string d_ih;
    std::string d_parser;
    std::string d_scanner;

    Action d_gch;
    Action d_go;
    Action d_spch;

    static FBB::Pattern s_icmconf;
    static std::unordered_map<std::string, void (Options::*)()> 
                                                            s_icmconfEntry;
    public:
        Options();

        Action go() const;                                          // .f
        Action gch() const;                                         // .f
        Action spch() const;                                        // .f

        void startDir() const;                                      // .f

        std::string const &classes() const;                         // .f
        std::string const &scanner() const;                         // .f
        std::string const &parser() const;                          // .f
        std::string const &useAll() const;                          // .f
        std::string const &mainIH() const;                          // .f
        std::string const &dotIH() const;                           // .f

        size_t verbosity() const;                                   // .f

    private:
        void setGch();
        void setUseAll();
        void setVerbosity() const;

        void scanIcmconf();

        void precomp();
        void ih();
        void spch();
        void icmUseAll();
        void parserDir();
        void scannerDir();
};

#include "options.f"
        
#endif
