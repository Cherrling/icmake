#define XERR
#include "bimheader.ih"

BimHeader::BimHeader(char const *fname, char const *version, 
                     bool versionCheck)
:
    d_bimName(bimName(fname)),
    d_in(Exception::factory<ifstream>(d_bimName))
{
    if (not d_in.read(reinterpret_cast<char *>(&d_hdr), sizeof(Header)))
        throw Exception{} << "cannot read header from " << d_bimName;

    d_hdr.endian();                 // if necessary, convert to big endian

    if (versionCheck)
    {
        unsigned bimNr = Tools::versionNr(d_hdr.version);
        unsigned ourNr = Tools::versionNr(version);

        if (ourNr > bimNr)        
            throw Exception{} << d_bimName << " was created with an "
                    "older icmake version (" << bimNr << ")\n"
                    "Recompile the original script";
    
        if (ourNr < bimNr)        
            throw Exception{} << d_bimName << " was created with a more "
                    "recent icmake version (" << bimNr << ")\n"
                    "Please upgrade icmake";
    }

    checkOffsets();                         // verify that the hdr offsets are
                                            // within the file
}





