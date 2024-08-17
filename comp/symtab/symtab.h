#ifndef INCLUDED_SYMTAB_
#define INCLUDED_SYMTAB_

#include <cstdint>
#include <string>
#include <vector>

#include "../exprtype/exprtype.h"

class SemVal;
class Functions;

// see README.stackframe for the construction of stackframes

struct Symtab
{
    struct Var
    {
        std::string name;               // var's name
        ExprType    varType;            // int, string, list:  | e_var
        uint16_t    location;           // the variable's location 
                                        // (xx, 0xc0xx, 0xbfxx)
    };

    using VarVect = std::vector<Var>;

    private:
        Functions &d_functions;
    
        std::vector<VarVect> d_var;         // globals are at index 0
                                            // function params are at index 1
                                            // local vars are at index >= 2

        std::vector<ExprType> d_locals;     // types of all local variables
                                            // of a function.
        
        std::string d_globalCode;           // initialization code of 
                                            // global variables

    public:
        Symtab(Functions &functions);

        void defineFunction(ExprType type, std::string const &name);

        void functionParams();          // forward the parameter-types to
                                        // d_functions, and check the
                                        // uniqueness of the parameters

        SemVal defineVar(ExprType type, std::string const &name);

                                        // 0xc000: not found
        Var const &findVar(std::string const &name) const;

        ExprType globalType(unsigned idx) const; 
        
        VarVect const &globalVars() const;  // all global vars          .f

        void push();                        // next level of variables
        void pop();                         // previous level of variables

        SemVal functionDefined(SemVal &statements);
        SemVal makeFrame() const;

        void globalCode(std::string const &code);   // add initialization 1.f
                                                    // code
        std::string const &globalCode() const;  // initialization code of 2.f
                                                // global variables
    private:
                                            // -1 if not found or the var's
                                            // in d_var.back()
        int find(VarVect const &vect, std::string const &name) const;
};

#include "globaltype.f"
#include "pop.f"
#include "push.f"
#include "globalcode1.f"
#include "globalcode2.f"
#include "globalvars.f"

#endif

