#define XERR
#include "generator.ih"

//  version
//  strings         offset of the string constant-area          (int32_t)
//  variables       offset of the global variable types area    (int32_t)
//  filenames       offset of the filenames area                (int32_t)
//  code            offset of the first instruction to execute  (int32_t)
// 
//  code   
//  ascii-z string constant area
//  variables
//  filenames


bool Generator::backend()
{
    Functions::Info const &mainInfo = d_functions.mainInfo();

    if (mainInfo.returnType == e_bool)
    {
        Error::set(Error::NO_MAIN);
        Error::msg();
        return false;
    }
            
    setVersion();                               // fill the version in 
                                                // d_hdr.version

    functionCode();                             // write the functions' code

    d_bim << d_symtab.globalCode();             // write the global vars.
                                                // initialization code
    
    callMain(mainInfo.offset);                  // append calling main

    strings();                                  // write the string constants

    variables();                                // append the types of the
                                                // global variables

    filenames();                                // write the used filenames

    d_bim.seekp(0);                             // rewind d_bim

    if (not littleEndian())                     // and write the header
        d_header.endian();
    d_bim.write(reinterpret_cast<char *>(&d_header), sizeof(Header));

    return true;
}
