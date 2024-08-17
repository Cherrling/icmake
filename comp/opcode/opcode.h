#ifndef INCLUDED_OPCODE_
#define INCLUDED_OPCODE_

#include <cstdint>

#include "../../tmp/build/opcodes/opcodes.h"
#include "../exprtype/exprtype.h"

class Opcode: public Opcodes
{
    static ExprType s_types[];      // allowed operand types of the opcodes

    public:
        static ExprType types(Byte opCode);

        // use SemVal::accept to check whether an opcode is acceptable
};

#include "types.f"

#endif


