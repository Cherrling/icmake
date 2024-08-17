//#define XERR
#include "dependencies.ih"

// d_indicator indicates whether a header must be precompiled.  
// Initially, none are considered too old, indicated by d_indicator's elements
// set to false.
// In the first round all directories are visited and the ages of their gch
// files are compared to the local headers. If the gch file is older than any
// of those headers it is marked for recompilation.
// At the next round the gch files of all directories whose gch files were not
// marked for removal but that depend on directories whose gch files were 
// marked for removal are also marked for removal. This check is recursively
// performed. 
// Finally, all gch files in directories whose gch files are marked for
// removal are actually removed.

void Dependencies::gchFiles()
{
    d_indicator = BoolVect(d_size);     // no gch files marked so far

    inspectGchAges();                   // mark all old gch files for removal

    impliedGchRemovals();               // determine implied gch removals

    removeGch();                        // remove gch files indicated by 
                                        // d_indicator

    log(V4) << "Precompiled header inspection completed\n";
    
}



