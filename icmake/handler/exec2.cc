#define XERR
#include "handler.ih"

        // how is &direct or &child
int Handler::exec(int (Handler::*how)(std::string const &cmd))
{
    return (this->*how)("icm-exec" + d_splitter.versionCheck() + 
                        d_execOptions + 
                        catArgs(d_splitter.endOpts(), d_splitter.argc())); 
}
