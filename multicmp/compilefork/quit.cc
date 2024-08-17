//#define XERR
#include "compilefork.ih"

bool CompileFork::quit()                // post-fork check
{
    lock_guard lg{ s_staticData };

    if (not s_ok)                       // another thread failed in between
        return true;

    if (d_ret != 0)                     // compilation failed
        s_ok = false;                   // end all threads at an error

    return false;
}
