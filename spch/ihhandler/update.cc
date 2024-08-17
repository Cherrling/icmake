#define XERR
#include "ihhandler.ih"

    // collect the namespace lines from ihLines, removing them from
    // ihLines, returning them in the returned vector
IHhandler::StringVect IHhandler::update(StringVect &ihLines) const
{
    StringVect decls{ usingDecl(ihLines) };

    if (not decls.empty())                 // found using decls
    {
        ihLines.push_back(d_ifndefSPCH);
        ihLines.insert(ihLines.end(), decls.begin(), decls.end());
        ihLines.push_back("#endif");
    }

    return decls;
}
