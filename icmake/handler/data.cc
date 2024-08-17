//#define XERR
#include "handler.ih"

    // elements must follow the ordering of Spitter::s_xlat's 1st word
int (Handler::*Handler::s_action[])()
{
    &Handler::compile,
    &Handler::dependencies,
    &Handler::exec,
    &Handler::forced,
    &Handler::multicomp,
    &Handler::preprocess,
    &Handler::spch,
    &Handler::source,
    &Handler::script,
    &Handler::unassemble,
};

