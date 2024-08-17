#define XERR
#include "support.ih"

Support::StringVect Support::read(string const &filename)
{
    StringVect ret;

    
    if (
        size_t pos = filename.find_first_not_of(" \t");     // 1st non-ws pos
        pos == string::npos                                 // not found or
        or filename[pos] == '#' or filename.find("//") == pos   // comment
    )
        return ret;

    if (not Tools::exists(filename))
        cout << "skipping non-existing `" << filename << "'\n";
    else
    {        
        ifstream in{ Exception::factory<ifstream>(filename) };
        
        string line;
        while (getline(in, line))       // store all the lines in the .ih file
            ret.push_back(line);    
    }

    return ret;
}
