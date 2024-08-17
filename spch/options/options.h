#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <vector>
#include <string>
#include <iosfwd>

#include "../../tmp/build/arg/arg"

namespace FBB
{
    class Pattern;
}

class Options
{
    FBB::Arg const &d_arg;

    std::string d_spch;
    std::string d_spchGch;

    bool d_listOption;
    bool d_listOnly;
    bool d_precompileOption;
    bool d_softLinkOption;
    bool d_topDirOption;
    bool d_topDir;
    bool d_warn;

    bool d_internalOption;
    std::string d_internal;

    bool d_guardOption;
    std::string d_guard;
    
    bool d_classesOption;
    std::string d_classes;

    std::string d_required;

    bool d_keepOption;
    static FBB::Pattern s_keep;
    static FBB::Pattern s_spec;     // filename spec. pattern for --keep

    public:
        Options();

        bool list() const;
        bool rh() const;
        bool topDir() const;
        std::string const &classes() const;
        std::string const &spch() const;
        std::string const &spchGch() const;
        std::string const &extension() const;       // the targeted extension
        char const *arg1() const;                   // d_arg[1] with --precomp

        std::string const &internal() const;        // the .ih extension
        std::string const &guard() const;
        bool modify(std::string const &filename) const;
        static bool keep(std::string const &spec);  // #include file spec.
        bool precompile() const;
        bool softLink() const;

    private:
        bool listOnly(std::string *member, int optChar);    // true: specified
        bool plainSpchName(char const *option);
        bool spchGch(char const *option, int optChar); 
        void checkOptions();
        void classesOpt();
        void dotRequired(std::string *member, char const *what, int optChar);
        void guardOpt();
        void internalOpt();
        void keepOpt();
        void listOpt();
        void precompileOpt();
        void readKeepFile(std::string const &filename);
        void softLinkOpt();
        void topDirOpt();
};

#include "options.f"
        
#endif
