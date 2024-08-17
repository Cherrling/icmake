//#define XERR
#include "compilefork.ih"

CompileFork::CompileFork(size_t id, bool showID, size_t nQuiet, 
                         string const &compiler, DataVect const &dataVect, 
                         string const &absCwd)
:
    d_id(id),
    d_showID(showID),
    d_nQuiet(nQuiet),
    d_compiler(compiler),
    d_dataVect(dataVect),
    d_absCwd(absCwd),
    d_ret(0)
{}
