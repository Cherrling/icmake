#define XERR
#include "semval.ih"

void SemVal::patch(vector<unsigned> &list, PatchDest dest)
{
    if (list.empty())
        return;

    unsigned patchDest = dest == END ? d_code.size() : 0;

            //  offset is the offset immediately beyond the jump instruction
            //  including the two bytes jmp offset following the jmp, jf, jt
            //  instruction. This is the position where the jump
            //  starts after having read the jump instruction. Hence, the
            //  jumpsize is determined by the distance 'patchDest - offset',
            //  whereas this jumpsize must be inserted 2 bytes before offset
            //  because that's where jmp reads the #bytes the jmp must skip 

//xerr("size: " << list.size());
    for (unsigned offset: list)
    {
//cerr << "insert jump size at " << (offset - 2) << '\n';

        short jumpSize = patchDest - offset;
//cerr << "jump size: " << hex << jumpSize << dec << '\n';

        endian(&d_code[offset - 2], jumpSize);
    }
//cerr << '\n';
    list.clear();               // this patch is completed, code may be 
                                // appended to which this patch-vector no 
                                // longer applies.
}
