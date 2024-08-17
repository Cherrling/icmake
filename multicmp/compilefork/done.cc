//#define XERR
#include "compilefork.ih"

bool CompileFork::done()                // pre-fork check
{
    lock_guard lg{ s_staticData };

    if (                                // stop if another thread failed
        not s_ok                        // or all done
        or s_dataIdx >= d_dataVect.size() 
    )
        return true;
    
    d_data = &d_dataVect[s_dataIdx++];
    return false;
}

