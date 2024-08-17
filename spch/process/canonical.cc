#define XERR
#include "process.ih"

// static
string Process::canonical(string const &filename)
{
    fs::path path{"./" + filename};
    
    return fs::canonical(path.parent_path()).string() + '/' 
            + path.filename().string();
}
