#define XERR
#include "process.ih"
                                //      [1]: matched filename
                                //                      1     1
Pattern Process::s_include{ R"_(^\s*#include\s*")_" R"_(([^"]+)")_" };
string Process::s_precompileCmd
{ 
    "g++ -o $2 ${ICMAKE_CPPSTD} -O2 -Wall -Werror -x c++-header $1"
};

