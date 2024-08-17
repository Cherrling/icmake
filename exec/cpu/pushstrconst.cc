//#define XERR
#include "cpu.ih"

void CPU::pushStrConst()
{
    d_stack.push( new EString{ d_hdr.string(d_hdr.get<uint16_t>()) } );
}
