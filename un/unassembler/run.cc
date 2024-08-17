//#define XERR
#include "unassembler.ih"

void UnAssembler::run(string const &progname)
{
    Tools::usageTop(progname, false) <<hex << setfill('0');

    statistics();               // bim-file statistics
    varDump();                  
    stringDump();
    disassemble();              // disassemble the binary instructions
}
