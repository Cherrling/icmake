#ifndef INCLUDED_GENERATOR_
#define INCLUDED_GENERATOR_

//         version
//         offset of the string constant-area  (int32_t)    0
//         offset of the variable area         (int32_t)    1
//         offset of the strings area          (int32_t)    2
//         offset of the first instruction     (int32_t)    3
// 
//         code                                (first byte is first instruction)
//         ascii-z string constant area
//         variables
//         filenames

#include <fstream>

#include "../../support/endian/endian.h"
#include "../../support/header/header.h"

class Parser;
class Scanner;
class Functions;
class Symtab;

class Generator: private Endian
{
    Header d_header;

    char const *d_bimName;        
    std::ofstream d_bim;

    Scanner const &d_scanner;
    Functions const &d_functions;
    Symtab const &d_symtab;
    
    public:
        Generator(char const *bimName, Parser const &parser);
        ~Generator();

        bool backend();
        int noBim();                    // bim construction not completed

    private:
        void setVersion();              // fill the version in d_hdr.version
        void functionCode();            // writes the functions' code to file
        void callMain(short offset);    // call main()
        void strings();                 // write the string constants
        void variables();               // write the global var. types
        void filenames();               // write the encountered filenames
};
        
#endif
