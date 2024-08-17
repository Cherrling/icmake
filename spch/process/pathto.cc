#define XERR
#include "process.ih"

string Process::pathTo(string const &dest, string const &ihFile)
{
    if (dest.front() == '/')                // dest is absolute: use as-is
        return dest;        
                                            // find the canonical dirnames
    string spch = canonical(dest);
    string ih = canonical(ihFile);

    size_t from = 0;
    size_t toSPCH = 0;
    size_t toIH = 0;
    while (true)
    {
        toSPCH = spch.find('/', from);
        toIH =   ih.find('/', from);
        if (
            toSPCH != toIH 
            or toSPCH == string::npos
            or spch.substr(0, toSPCH) != ih.substr(0, toIH)
        )
            break;

        from = toSPCH + 1;
    }
    ih.erase(0, from);                       // remove the equal prefixes
    spch.erase(0, from);
            
    for (                                   // insert steps to the parent
        size_t begin = 0, end = count(ihFile.begin(), ihFile.end(), '/');
            begin != end;
                ++begin
    )
        spch.insert(0, "../");

    return spch;
}




