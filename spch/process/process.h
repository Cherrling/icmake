#ifndef INCLUDED_PROCESS_
#define INCLUDED_PROCESS_

#include <iosfwd>

#include "../../tmp/build/datetime/datetime"

#include "../options/options.h"
#include "../support/support.h"

namespace FBB
{
    class Pattern;
}

class Process: private Support
{
    Options d_options;
    FBB::DateTime d_spchGchTime;
    
    static FBB::Pattern s_include;    // used for .ih/.rh files
    static std::string s_precompileCmd;

    public:
        Process();  // could be = default

        int run();                  // returns 0 on success, for main()

    private:
        int spch() const;           // construct/inspect the spch file

        int precompile();           // precompile the all.ih file
        int softLinks() const;      // create the soft-links to the SPCH
        bool softLink(std::string const &spchGch,   // define one soft-link
                      std::string const &spchFile) const;

        bool recent(std::string const &dest, std::string const &spch);
        bool older(std::string const &filename);

        static bool spchFile(std::string &line);
        static std::string pathTo(std::string const &spch, 
                                  std::string const &ihFile);
        static std::string canonical(std::string const &filename);

};
        
#endif
