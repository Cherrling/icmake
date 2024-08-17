#ifndef INCLUDED_BUILTIN_
#define INCLUDED_BUILTIN_

#include <initializer_list>
#include <unordered_set>

#include "../../tmp/build/builtinfunctions/builtinfunctions.h"

#include "../exprtype/exprtype.h"

struct Builtin: public BuiltinFunctions
{
    using Args = std::initializer_list<ExprType>;   // argument types
    using ArgsIter =  Args::const_iterator;

    private:
        struct Info                                 // Builtin function info:
        {   
            ExprType    type;       // return type 
            Args args;              // argument types
        };
    
        static Info s_builtin[];
        static std::unordered_set<Builtin::Function> s_argCount;

    public:
        static ExprType returnType(Function function);  // includes d_reg
        static Args const &arguments(Function function);
        static int defaultArg(Function function);
        static bool argCount(Function function);
};

#include "arguments.f"
#include "returntype.f"
#include "defaultarg.f"
#include "argcount.f"

#endif


