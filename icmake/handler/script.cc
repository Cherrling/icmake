#define XERR
#include "handler.ih"

// an executable source file 'src' starting with
//      #!/usr/bin/icmake -t. [-p preprocess options] [-e execute options]

// results in calling
//      /usr/bin/icmake -t. src  + any additional options specified after src.
// If additional arguments on the #!/usr/bin/icmake line are specified then
// those arguments are listed between -t. and 'src', probably causing icmake
// to fail. Extra arguments should therefore be avoided.

int Handler::script()
{
    TempStream bim{ d_splitter.scriptBim() };

    d_file2 = bim.fileName();

    if (not forced())
        return 1;

    d_splitter.setArgv(d_splitter.endOpts(), &d_file2.front());

    return exec(&Handler::child);
}






