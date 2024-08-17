#ifndef INCLUDED_SEMVAL_
#define INCLUDED_SEMVAL_

#include <vector>
#include <string>

#include "../exprtype/exprtype.h"
#include "../builtin/builtin.h"
#include "../opcode/opcode.h"
#include "../stringstore/stringstore.h"
#include "../tokens/tokens.h"
#include "../../support/as/as.h"
#include "../../support/endian/endian.h"

// e_int const values are directly stored in d_value
// e_str const values are the offsets of strings in the string section
// e_list const values are constructed by listconst

// types of global variables are defined in the variables section by their
// ExprType type values (e.g., e_int == 1, e_str == 2, e_list == 4)


class SemVal: private Endian
{
    friend SemVal &operator<<(SemVal &semVal, uint8_t opcode);      // 1.f
    friend SemVal &operator<<(SemVal &semVal, short value);         // 2.f
    friend SemVal &operator<<(SemVal &lhs,    SemVal &rhs);         // 3.f
    friend SemVal &operator<<(SemVal &semVal, Opcode::Byte opcode); // 4.cc

    ExprType d_type = e_null;       // type of the expression

    int d_value;                    // index or value of the expression
                                    // for '(f)printf <<' calls: index 
                                    // in s_printfMap

    std::vector<unsigned> d_patchTrue;
    std::vector<unsigned> d_patchFalse;
    std::vector<unsigned> d_patchBreak;
    std::vector<unsigned> d_patchContinue;

    std::vector<SemVal> d_printfArgs;

    std::string d_code;

    enum State              // at catStatements: rhs is accepted at
    {                       // ACCEPT, otherwise it's ignored, and lhs
        ACCEPT = 0,         // gets the rhs's NextState
        DEAD = 1,           // (using bit-flags)
        RETURN = 2
    };

    unsigned d_state = ACCEPT;

//    static SemVal &(SemVal::*s_insert1)(uint8_t opcode);
//    static SemVal &(SemVal::*s_insert2)(short value);  
//    static SemVal &(SemVal::*s_insert3)(SemVal &rhs);  

    Opcode::Byte d_lastOpcode = Opcode::invalid;

    static Opcode::Byte s_lastOpcode;
    static std::vector<bool> s_deadCode;        // vector, to initialize to
                                                // an initial size
    static bool s_returns;                      // last statement is return

    public:
        enum PatchDest
        {
            BEGIN,
            END
        };
    
        std::string const &code() const;

        SemVal() = default;

        SemVal(ExprType type, int value = 0);

        ExprType type() const;          // the SemVal's type
        int value() const;

        int constCompare(SemVal const &rhs) const;
                                                            // copy
        SemVal assign(SemVal &&rhs, Opcode::Byte opcode);   // '=' 
        SemVal compound(Opcode::Byte opType, SemVal &&rhs); 
        SemVal negate();                                    // '-'
        SemVal bitNot();                                    // '~'
        SemVal boolNot();                                   // '!'
        SemVal incDec(Opcode::Byte opcode, ExprType prepost);
        SemVal logicOr(SemVal &&rhs) &&;
        SemVal logicAnd(SemVal &&rhs) &&;
        SemVal binary(Opcode::Byte opcode, SemVal &&rhs);

        SemVal cast(Tokens::Tokens_ destType);
        SemVal ternary(SemVal &&trueExpr, SemVal &&falseExpr) &&;

        bool assignable(Opcode::Byte opcode, SemVal &rhs) const;


        bool isLvalue(Opcode::Byte opcode) const;               // 1.f
        bool isLvalue(char const *mnemonic) const;              // 2.cc

        void setValue(int value);
        void setType(ExprType type);                                    // .f
        void setResult(ExprType result);            // e_var, e_stack, ...
        void set(ExprType type, int value);

        SemVal printfArg(SemVal &rhs);

        void push();                    // convert to code pushed on the stack
                                        // (performs bool2int)

        void callrss(Builtin builtin, unsigned nArgs = 0);  // # args,
                                        // including a push_imm (if used)

        void catString(SemVal const &rhs);      // this, rhs: e_str | e_const

        bool accept(Opcode::Byte opCode) const;                     // 1.cc
        bool accept(SemVal const &rhs, Opcode::Byte opCode) const;  // 2.cc

        bool sameType(SemVal const &rhs, Opcode::Byte opcode) const;

        SemVal exprStmnt();
        SemVal ifStmnt(SemVal &cond, SemVal &trueStmnt, SemVal &falseStmnt);
        SemVal forStmnt(SemVal &cond, SemVal &inc, SemVal &stmnt);
        void breakStmnt();                      // add jmp + short 0
        void continueStmnt();                   // add jmp + short 0

        void catStatement(SemVal &next);

        void patchFalse(PatchDest dest);                                 // .f

        std::vector<SemVal> &printfArgs();      // grabbed by Args
        size_t nPrintfArgs() const;                                      // .f

        void ends();                            // state: DEAD & RETURN     .f
        static bool returns();                                           // .f

        static void pushDead();                 // push the dead-code state .f
        static void popDead();                  // pop the former           .f
                                                // dead-code state 
        static void resetDead();

        // tmp
        void bytes() const;

    private:
        bool copiedVar();               // change last pop_var into copy_var
                                        // (instead of pop/push

        void stackType();                       // e_mask | e_stack

        void bool2int();                        // patchup a e_bool to e_int

        void toInt();
        void toStr();
        void toList();

        void asBool();                  // also pushes const values,
                                        // initializes true and false patch
                                        // vectors 

        bool boolConst() const;         // use only when const:
                                        // true: int != 0, string length != 0,
                                        //       otherwise false

        void swapTrueFalse();           // .f
        void rmJmpZero();

        void invalidCast(char const *msg);      // Error msg, e_null

        void constBinary(Opcode::Byte opcode, SemVal const &rhs);

        bool tryString2Int(SemVal &rhs);

        SemVal &insert1(uint8_t byte);          // also: Opcode::Byte
        SemVal &insert2(short value);
        SemVal &insert3(SemVal &rhs);           // -> scvatenate.c

//        void insert();                          // activates adding code
//        void dead();
//        SemVal &dead1(uint8_t opcode);
//        SemVal &dead2(short value);
//        SemVal &dead3(SemVal &rhs);

                                                // maybe erase list?
        void patch(std::vector<unsigned> &list, PatchDest dest);

        void patchBreak();                      // always to the end        .f
        void patchContinue(PatchDest dest);                             //  .f

        void patchTrue(PatchDest dest);         // patchFalse: public       .f

        void addPatchTrue(Opcode::Byte jmpCode);// add jmpCode + short 0   2.f
        void addPatchTrue();                    // add short 0 to d_code   1.f

        void addPatchFalse(Opcode::Byte jmpCode);// add jmpCode + short 0  2.f
        void addPatchFalse();                   // add short 0 to d_code   1.f

        void shiftPatchFalse(unsigned shift);

        void addPatch(std::vector<unsigned> &pvect);
        void addPatch(std::vector<unsigned> &pvect, Opcode::Byte);


        static void extend(std::vector<unsigned> &dest, 
                           std::vector<unsigned> &src, 
                           unsigned shift);

        static void merge(std::vector<unsigned> &dest, 
                          std::vector<unsigned> &src);
};

#include "type.f"
#include "value.f"
#include "setvalue.f"
#include "settype.f"
#include "islvalue1.f"
#include "setresult.f"
#include "constcompare.f"
#include "code.f"

#include "patchfalse.f"
#include "popdead.f"
#include "pushdead.f"
#include "ends.f"
#include "returns.f"

#include "printfargs.f"
#include "nprintfargs.f"

#include "opinsert1.f"
#include "opinsert2.f"
#include "opinsert3.f"
// #include "opinsert4.f"   tmp: .cc

#endif
