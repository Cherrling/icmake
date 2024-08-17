//#define XERR
#include "cpu.ih"

void CPU::itoa()
{
    d_stack.top() = new EString{ to_string(d_stack.top().value()) };  
                                                // using promotion to 
}                                               // assign Variable{ string }
