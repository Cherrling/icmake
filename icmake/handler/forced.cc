#define XERR
#include "handler.ih"

int Handler::forced()
{
    file2(".bim");

    if (d_splitter.pimFile())
        direct("icm-comp " + d_splitter.file1() + ' ' + d_file2);

    TempStream pim{ d_splitter.pidName() };

    return 
        child(
            "icm-pp" + d_preOptions + ' ' + d_splitter.file1() + 
            ' ' + pim.fileName()
        ) == 0
        and child("icm-comp " + pim.fileName() + ' ' + d_file2) == 0;
}
