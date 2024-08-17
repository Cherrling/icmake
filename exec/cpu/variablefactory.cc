//#define XERR
#include "cpu.ih"

Variable CPU::variableFactory()
{
    switch (as<ExprType>(d_hdr.get<uint8_t>()) )
    {
        case e_int:
        xerr("e_int");
        return new Int;

        case e_str:
        xerr("e_str");
        return new EString;

        case e_list:
        xerr("e_list");
        return new List;

        default:
        throw Exception{} << "Invalid Expression Type at offset " << 
                             (d_hdr.offset() - 1);
    }
}
