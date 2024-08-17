#define XERR
#include "ihhandler.ih"

void IHhandler::write(string const &ihName, StringVect const &lines) const
{
    if (options().modify(ihName))
    {
        ofstream out{ Exception::factory<ofstream>(ihName) };
        copy(lines.begin(), lines.end(), 
            ostream_iterator<string>{ out, "\n" });
    }
}
