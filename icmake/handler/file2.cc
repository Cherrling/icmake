#define XERR
#include "handler.ih"

string const &Handler::file2(char const *extension)
{
    string const &file1 = d_splitter.file1();

    if (d_file2.empty())
    {
        switch (d_splitter.nFiles())
        {
            case 0: 
            throw Exception{} << "filename missing for option `" <<
                             d_splitter.argv(d_splitter.actionIdx()) << '\'';

            case 1:
                d_file2 = 
                        path { file1 }.replace_extension(extension).string();
            break;

            default:
                d_file2 = d_splitter.file2();
            break;
        }
    }

    if (Tools::absolute(file1) == Tools::absolute(d_file2))
        throw Exception{} << '`' << file1 << "' and `" << d_file2 << 
                            "' are the same files";
    return d_file2;
}




