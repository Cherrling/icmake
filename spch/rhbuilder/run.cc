#define XERR
#include "rhbuilder.ih"

// make a list of .rh files (returned by readClasses). For each .rh file: if
// it exists, continue. If not: move all #includes in the .ih file to the .rh
// file and include the .rh file as the .ih file's first line

int RHbuilder::run()
{
    d_rhFiles = readClasses();              // determine the .rh files

    inspectRHfiles();                       // inspect the .rh files 

    ofstream spch{ Exception::factory<ofstream>(options().spch()) };

    for (string const &rhFile: d_rhFiles)
        spch << "#include \"" << rhFile << "\"\n";
    
    return 0;
}
