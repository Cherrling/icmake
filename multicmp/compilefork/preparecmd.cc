//#define XERR
#include "compilefork.ih"

void CompileFork::prepareCmd()
{
    d_compileCmd = 
        Tools::command(
                d_compiler, d_data->source, 
                Tools::absolute(d_data->objDir) +     // the obj. file
                '/' + d_data->prefix + 
                fs::path{ d_data->source }.replace_extension(".o").string()
        );
                                                // create the object's base
    Tools::createDirectories(d_data->objDir);  // directory if not existing
}
