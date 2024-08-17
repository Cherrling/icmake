#include "log.ih"

ostream &log(LogLevel vx)
{
    return g_log << level(vx) << "icm-dep: ";
}
