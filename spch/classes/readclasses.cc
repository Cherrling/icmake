#define XERR
#include "classes.ih"

Classes::StringSet const &Classes::readClasses()
{
    string const &classes = d_options.classes();
    string const &extension = d_options.extension();

    if (not Tools::exists(classes))
        cout << "[warning] `" << classes << "' does not exist\n";
    else
    {
        ifstream in{ Exception::factory<ifstream>(classes) };
    
        string line;
        while (getline(in, line))
        {
            if (not skip(line))     // true: empty/comment; line is trimmed
                add(line, extension);
        }
    }

    if (d_options.topDir())
        add(extension);
    
    return d_files;
}
