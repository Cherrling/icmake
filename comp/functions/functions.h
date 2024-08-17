#ifndef INCLUDED_FUNCTIONS_H_
#define INCLUDED_FUNCTIONS_H_

#include <vector>
#include <unordered_map>
#include <string>

#include "../exprtype/exprtype.h"

struct Functions
{
    struct Info
    {
        unsigned offset;                // location in the code-section
        ExprType returnType;            // return type of this overload
        std::vector<ExprType> params;   // param types of this overload
        std::vector<ExprType> locals;   // types of this overload's local
                                        // variables
        std::string code;               // code of this overloaded function

        Info(unsigned from, ExprType retType);                      // 1.cc
    };

    using Overload = std::vector<Info>;

    private:
        using FunMap = std::unordered_map<std::string, Overload>;
    
        FunMap d_functions;

        std::string     d_code;         // code of all defined functions
                                        // d_code.size() is the offset in the
                                        // code-section of the next function

        Info d_main;                    // Info of main(). Returntype e_bool: 
                                        // not defined

        FunMap::iterator d_overload;    // the function that's currently
                                        // being defined (not main)

        Info *d_info;                   // ->Info of the function that's
                                        // currently being defined

        static std::string const s_main;    // main's function name

    public:
        Functions();

        void define(ExprType type, std::string const &name);
        void paramType(ExprType type);

        void checkOverload() const;

        ExprType type() const;              // return type of the current
                                            // function 
        bool isMain() const;                // true if the current function is
                                            // main
        std::string const &name() const;    // name of the current function

        Overload const *find(std::string const &name) const;

        void add(std::string const &code);  // code of the next function    .f

        std::string const &code() const;    // all function code bytes      .f

        Info const &mainInfo() const;                                    // .f

    private:
        void defineMain(ExprType type);
        void checkMainParams() const;
};
        
#include "paramtype.f"
#include "ismain.f"
#include "name.f"
#include "type.f"
#include "add.f"
#include "code.f"
#include "maininfo.f"

#endif
