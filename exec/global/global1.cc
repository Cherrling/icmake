//#define XERR
#include "global.ih"

Global::Global(BimHeader &hdr)
{
    hdr.varsSection();

    while (not hdr.endVars())
    {
        xerr("at offset " << hex << hdr.offset() << ' ' <<dec << hdr.offset());
        switch (hdr.get<uint8_t>())
        {
            case e_int:
                xerr("int");
                push_back(new Int);
            break;

            case e_str:
                xerr("string");
                push_back(new EString);
            break;

            case e_list:
                xerr("list");
                push_back(new List);
            break;

            default:
            throw Exception{} << "invalid variable type at offset " << hex <<
                                                    (hdr.offset() - 1);
        }
    }
    xerr("done");
}
