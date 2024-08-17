#include "compiler.ih"

Compiler::~Compiler()
{
    Tools::remove(d_arg[0]);
}
