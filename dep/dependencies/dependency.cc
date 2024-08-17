//#define XERR
#include "dependencies.ih"

    // inspect the header files of directory 'idx'. 
    // headers including headers from other project directories depend
    // on those directories and such dependencies are registered in
    // d_dependency
    // Once a dependency has been registered (e.g., dir. b depends on dir. c)
    // no further action wrt c is taken.
    // Inside a directory, once a header is being inspected it is registered
    // to avoid circular inclusion.

void Dependencies::dependency(size_t idx, string const &header)
{
    ifstream in{ header };
    if (not in)
    {
        log(V4) << "cannot read '`" << header << "': skipped\n";
        return;
    }

    log(V4) << "inspecting header `" << header << "'\n";
    d_localHeader[idx].push_back(header);

    string line;
    while (getline(in, line))           // inspect header's #include
        dependsOn(line, idx);           // directives
}
