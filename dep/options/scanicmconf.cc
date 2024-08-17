//#define XERR
#include "options.ih"

void Options::scanIcmconf()
{
    auto in{ Exception::factory<ifstream>(d_icmconf) };

    string line;
    
    while (getline(in, line))
    {
        if (not (s_icmconf << line))            // no match
            continue;                           // inspect the next line

        auto iter = s_icmconfEntry.find(s_icmconf[1]);
        if (iter != s_icmconfEntry.end())
            (this->*(iter->second))();          // process s_icmconf[2] if
                                                // needed
    }

    if (d_spch != UNSPECIFIED and d_gch != UNSPECIFIED)
        throw Exception{} << "icm-dep: " << d_icmconf << 
                             " cannot declare both PRECOMP and SPCH";

    if (d_ih.empty())                           // by default use .ih
        d_ih = ".ih";
}

