#define XERR
#include "rhbuilder.ih"

    // inspect one rhfile
void RHbuilder::inspect(string const &rhFile)
{
    string ihFile = ihFrom(rhFile);

    char const *msgTxt = 0;
    if (not Tools::exists(ihFile))
        msgTxt = "found";
    else if (not options().modify(ihFile))
        msgTxt = "modified";

    if (msgTxt != 0)
    {
        wmsg << '`' << ihFile << "' not " << msgTxt << endl;
        return;
    }

    if (Tools::exists(rhFile))
    {
        wmsg << "existing file `" << rhFile << "' is not modified" << endl;
        return;
    }        
                                    // write rhStream, rewrite the ihfile
    write(Exception::factory<ofstream>(rhFile), ihFile);     
}
