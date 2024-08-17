#define XERR
#include "classes.ih"

void Classes::add(string const &extension)
{
    string internal = d_options.internal();
    Glob glob{ Glob::REGULAR_FILE, "*" + internal, Glob::NOMATCH };
    if (glob.size() != 1)
        fmsg << "The topdir contains " << glob.size() << ' ' <<
                internal << " files instead of just one" << noid;

    fs::path file{ glob[0] };
    if (extension != internal)
        (file = file.stem()) += extension;

    d_files.insert(file.string());
}
