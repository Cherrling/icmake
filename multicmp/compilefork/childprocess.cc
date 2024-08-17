#define XERR
#include "compilefork.ih"

void CompileFork::childProcess()
{
    Tools::currentPath(d_data->sourceDir);

    Process process{ Process::DIRECT, Process::USE_PATH, d_compileCmd };
    process.start();

    // this point is never reached
}
