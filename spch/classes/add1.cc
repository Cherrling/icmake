#define XERR
#include "classes.ih"

void Classes::add(string const &line, string const &extension)
{
    fs::path path{ line };
    d_files.insert((path /= path.filename() += extension).string());
}
