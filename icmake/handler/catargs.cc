#define XERR
#include "handler.ih"

string Handler::catArgs(unsigned begin, unsigned end) const
{
    string ret;

    for 
    (
        char const *const *from = d_splitter.argv() + begin,
                   *const *to = d_splitter.argv() + end;
            from != to; 
                ++from
    )
    {
        string arg = *from; 
        if (arg.find_first_of(" \t") != string::npos)
            arg.insert(0, 1, '\'') += '\'';
        (ret += ' ') += arg;
    }
    return ret;
}
