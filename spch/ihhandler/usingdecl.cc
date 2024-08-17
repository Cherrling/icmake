#define XERR
#include "ihhandler.ih"

    // return all encountered using decls., removing them from 'lines'
IHhandler::StringVect IHhandler::usingDecl(StringVect &lines) const
{
    StringVect ret;

    auto from = lines.begin();

    bool ifndefSection = false;

    while (from != lines.end())
    {
        if (not (s_usingDecl << *from))  // keep lines other than using decls
        {
            if (d_ifndefSPCHre << *from)    // rm exising ifndef SPCH section
            {
                ifndefSection = true;
                from = lines.erase(from);
                continue;
            }
                
            if (ifndefSection and s_endif << *from)
            {
                ifndefSection = false;
                from = lines.erase(from);
                continue;
            }
        }
        else                            // move using decls to ret
        {
            ret.push_back(String::trim(*from));
            from = lines.erase(from);
            continue;
        }
        ++from;
    }
    return ret;
}
