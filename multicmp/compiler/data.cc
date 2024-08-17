#include "compiler.ih"

string Compiler::s_compileCommand
                 { "g++ -c -o $2 ${ICMAKE_CPPSTD} -Wall -Werror $1" };

