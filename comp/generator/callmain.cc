//#define XERR
#include "generator.ih"

void Generator::callMain(short mainOffset)
{
    // icm_exec pushes main's arguments on the stack, no code required here
    
    SemVal mainCall;
    mainCall << Opcode::call << as<short>(mainOffset) << Opcode::exit;

    d_bim << mainCall.code();
}
