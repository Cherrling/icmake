#ifndef INCLUDED_SUPPORT_
#define INCLUDED_SUPPORT_

#include <iosfwd>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_set>

#include "../../tmp/build/exception/exception"

namespace std
{
    class error_code;
}

class Support
{
    protected:
        static std::error_code s_ec;

    public:
        using StringSet = std::unordered_set<std::string>;
        using StringVect = std::vector<std::string>;

        Support();
    
                                                        // return the lines of
        StringVect read(std::string const &filename);   // filename
    
        static bool skip(std::string &line);            // skip comment
};
        
#endif
