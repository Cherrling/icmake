#define XERR
#include "ihhandler.ih"

void IHhandler::merge(StringVect const &usingDecls)
{
    for (string const &decl: usingDecls)
    {
        if (
            find(d_usingDecls.begin(), d_usingDecls.end(), decl) 
            == d_usingDecls.end()
        )
            d_usingDecls.push_back(decl);
    }
}
