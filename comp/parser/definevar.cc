#define XERR
#include "parser.ih"

//                                            // pmv_expressionAssign(&$1, &$3);
//        $$ = d_symtab.defineVar(d_type, $1).assign($4, Opcode::pop_var);  
//                                            // define the var. assign its
//                                            // value, use 

SemVal Parser::defineVar(SemVal &lhs, SemVal &expr)
{
    SemVal ret{lhs.assign(move(expr), Opcode::pop_var) };

    if (static_cast<short>(ret.value()) >= 0)  // global variables have pos. 
//    if (as<short>(ret.value()) >= 0)        // global variables have pos. 
        d_symtab.globalCode(ret.code());    // index values

    return ret;
}
