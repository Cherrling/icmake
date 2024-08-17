#define XERR
#include "options.ih"

void Options::softLinkOpt()
{
    d_softLinkOption = spchGch("--soft-link", 's');
}
