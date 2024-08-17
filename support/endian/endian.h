#ifndef INCLUDED_ENDIAN_
#define INCLUDED_ENDIAN_

#include <string>
#include <algorithm>
#include <inttypes.h>

class Endian
{
    union LBE           // little/big endian
    {
        short uShort;
        char  chars[2];
    };

    static LBE const s_lbe;
    static bool const s_little;               // true: little endian
    
    template <typename Type>
    static Type (*s_endian)(Type value);

    public:
        static bool littleEndian();

        template <typename Type>
        static Type endian(Type value);

        template <typename Type>            // append value to code's text
        static void endian(std::string *code, Type value);

        template <typename Type>
        static void  endian(char *code, Type value);
};

inline bool Endian::littleEndian()
{
    return s_little;
}

template <typename Type>            // returns BE binary value representations
Type Endian::endian(Type value)     // on BE machines
{
    if (s_little or sizeof(Type) == 1)
        return value;

    union Xform
    {
        Type value;
        uint8_t bytes[sizeof(Type)];
    };

    Xform xform{ value };

    for (size_t lhs = 0, rhs = sizeof(Type); lhs != rhs--; ++lhs)
    {
        std::swap(xform.bytes[lhs], xform.bytes[rhs]);
    }

    return xform.value;
}

                                    // appends value's bytes to *code, using
                                    // BE's binary value representations
template <typename Type>            // on BE machines
void  Endian::endian(std::string *code, Type value)
{
    if (sizeof(Type) == 1)
    {
        *code += static_cast<char>(value);
        return;
    }

    union Xform
    {
        Type value;
        uint8_t bytes[sizeof(Type)];
    };

    Xform xform{ value };

    if (s_little)
    {
        std::for_each(xform.bytes, xform.bytes + sizeof(Type), 
            [&](uint8_t byte)
            {
                *code += byte;
            }
        );
    }        
    else
    {
        for (size_t nr = sizeof(Type); nr; )    // modified canonical for-loop:
            *code += xform.bytes[--nr];         // here nr is converted to idx
    }
}    
        
                                    // stores value's bytes to *code and 
                                    // beyond, using BE's binary value 
template <typename Type>            // representations on BE machines
void  Endian::endian(char *code, Type value)
{
    if (sizeof(Type) == 1)
    {
        *code = static_cast<char>(value);
        return;
    }

    union Xform
    {
        Type value;
        uint8_t bytes[sizeof(Type)];
    };

    Xform xform{ value };

    if (s_little)
        std::copy(xform.bytes, xform.bytes + sizeof(Type), code);
    else
        std::reverse_copy(xform.bytes, xform.bytes + sizeof(Type), code);
}    
        
#endif












