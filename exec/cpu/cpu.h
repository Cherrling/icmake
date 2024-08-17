#ifndef INCLUDED_ICMAKECPU_
#define INCLUDED_ICMAKECPU_

#include "../../tmp/build/exprtype/exprtype.h"
#include "../../tmp/build/constmember/constmember.h"

#include "../variable/variable.h"
#include "../stack/stack.h"
#include "../builtin/builtin.h"
#include "../global/global.h"

class BimHeader;

class CPU: public ConstMember<CPU>
{
    BimHeader &d_hdr;
    Stack  &d_stack;                    // the function call stack

    Global d_global;                    // global variables
    Variable d_reg;                     // register storing return values of    
                                        // functions
    Builtin d_builtin;                  // builtin functions handler

    static void (CPU::*s_execute[])();    // functions called at the
                                                // various opcodes

    public:
        CPU(BimHeader &hdr, Stack &stack);
        int run();

    private:
        Variable variableFactory();

        bool isTrue();
        Variable &variable();   // reads the Var's index, then returns its
                                // reference.

        void jmp();             //     00   
        void jmpFalse();        //     01   
        void jmpTrue();         //     02   
        void push1jmpEnd();     //     03   -
        void push0();           //     04   
        void pushImm();         //     05   
        void pushStrConst();    //     06   
        void pushVar();         //     07    
        void pushReg();         //     08   
        void popVar();          //     09    
        void umin();            //     0a   
        void atoi();            //     0b   
        void itoa();            //     0c   
        void atol();            //     0d   
        void mul();             //     0e   
        void div();             //     0f   
        void mod();             //     10   
        void add();             //     11   
        void sub();             //     12   
        void eq();              //     13   
        void neq();             //     14   
        void sm();              //     15   
        void gr();              //     16   
        void younger();         //     17   
        void older();           //     18   
        void smeq();            //     19   
        void greq();            //     1a   
        void callRss();         //     1b   
        void asp();             //     1c    
        void exit() const;      //     1d      
        void copyVar();         //     1e
        void inc();             //     1f   
        void dec();             //     20   
        void call();            //     21   
        void frame();           //     22   
        void ret();             //     23   
        void popReg();          //     24   
        void band();            //     25   
        void bor();             //     26   
        void bnot();            //     27   
        void bxor();            //     28   
        void shl();             //     29   
        void shr();             //     2a   
};
        
#endif





