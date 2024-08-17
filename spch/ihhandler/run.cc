#define XERR
#include "ihhandler.ih"

int IHhandler::run()
{
                                            // suppress the #ifndef SPCH_ 
    d_spch << d_defineSPCH;             // sections in .ih files

    d_ihFiles = readClasses();      // determine the ih files from CLASSES

    inspectIHfiles();
    
    d_spch.put('\n');

    for (string const &decl: d_usingDecls)  // write the using declarations
        d_spch << decl << '\n';

    return 0;
}
