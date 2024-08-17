#ifndef INCLUDED_RHBUILDER_
#define INCLUDED_RHBUILDER_

#include <iosfwd>
#include "../classes/classes.h"

namespace FBB
{
    class Pattern;
}

class RHbuilder: private Classes
{
    StringSet d_rhFiles;                    // all .rh files

    static FBB::Pattern s_include;

    public:
        RHbuilder(Options const &options);
        int run();

    private:
        void inspectRHfiles();                      // inspect all rh-files
        void inspect(std::string const &rhFile);    // inspect one rh-file

        std::string ihFrom(std::string const &rhFile) const;

        void write(std::ostream &&rhStream, std::string const &ihFile);
        bool xfer(StringVect::iterator &iter, std::ostream &rhStream);
};

#endif
