//#define XERR
#include "dependencies.ih"

void Dependencies::inspectGchAge(size_t dir)
{
    auto const &hdrs = d_localHeader[dir];

    Tools::mustChangeDir(d_directory[dir]);

    xerr("\n\nInspecting dir. " << dir << ": " << d_directory[dir]);
    xerr("\t# local headers: " << hdrs.size());

    if (hdrs.size() != 0)
    {
        Stat gch{ hdrs[0] + ".gch" };       // obtain the .gch file's Stat data
    
        for (string const &hdr: hdrs)       // inspect all local headers
        {
            xerr("\tLocal hdr `" << hdr);
    
            if (Tools::younger(hdr, gch))   // hdr file is younger
            {
                log(V4) << '`' << d_directory[dir] <<
                            "': " << hdr << " younger " <<
                            hdrs[0] << ".gch: recompile\n";
    
                d_indicator[dir] = true;
                break;
            }
        }
    }

    d_options.startDir();
}


