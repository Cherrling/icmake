#define XERR
#include "scanner.ih"

void Scanner::defineOptions()
{
    Arg const &arg = Arg::instance();

    for (                           // determine the number of -d options
        unsigned idx = 0, count = arg.option('d');   
            idx != count;
                ++idx
    )
    {
        string id;
        arg.option(idx, &id, 'd');  // get this option

        if (d_symtab.contains(id))
            error() << '`' << id << "' multiply defined\n";
        else
            d_symtab[id] = "1"s;
    }
}
