#ifndef INCLUDED_TOOLS_
#define INCLUDED_TOOLS_

#include <iosfwd>
#include <string>
#include <utility>
#include <time.h>


namespace FBB
{
    class Stat;
}

class Tools
{
    public:

        static bool exists(std::string const &path);        // these use
        static bool remove(std::string const &path);        // 'filesystem'
        static bool changeDir(std::string const &path);     // 
        static void mustChangeDir(std::string const &path); // throws an
                                                            // exception on
                                                            // failure

        static bool younger(std::string const &entry, FBB::Stat const &rhs);
        static bool older(std::string const &entry, FBB::Stat const &rhs);

                                                // convert main version number
                                                // to unsigned (>a -> >10)
        static unsigned versionNr(char const *version);  

                                                // append Type's bytes to dest
        template <typename Type>                                        // 1.f
        static void append(std::string &dest, Type value);

        template <typename UseType, typename Type>                      // 2.f
        static void append(std::string &dest, Type value);

        static std::ostream &usageTop(std::string const &progname, 
                                      bool showUsage = true);
                                                    
    private:
                                        // determine last modification seconds
                                        // of 'entry' and an existing Stat
        static std::pair<time_t, time_t> times(std::string const &entry, 
                                               FBB::Stat const &rhs);
};

#include "append1.f"
#include "append2.f"
#include "versionnr.f"

#endif
