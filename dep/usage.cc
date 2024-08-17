//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"_( [options] [go]
Where:
    [options] - optional arguments (short options between parentheses):
        --classes (-c) file  - file defining the class-subdirectories 
                               (default: CLASSES)
        --gch                - inspect/remove .gch precompiled headers,
                               otherwise: don't handle precompiled headers.
        --help (-h)          - provide this help
        --icmconf (-i) file  - icmconf file to use (default: icmconf)
        --mainih (-m) ihfile - the top directory's main .ih file 
                               (default: main.ih)
        --no-gch             - do not inspect .gch precompiled headers.
        --no-use-all         - do not inspect USE_ALL files
        --use-all file       - use 'file' as USE_ALL filename, and add 
                               files implied by 'file' where necessary
        --verbose (-V)       - show touched files; more info if specified
                               multiple times
        --version (-v)       - show version information and terminate
   
When neither --gch nor --no-gch is specified icmonf's PRECOMP specification
is used;
When neither --use-all nor --no-use-all is specified icmonf's USE_ALL
specification is used.

Files are only changed if the program argument 'go' is specified

)_";

//        --spch               - silently ignore the Single Pre-Compiled Header:
//                               it is handled elsewhere.

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info;
}

/****************************************
All directories mentioned in CLASSES and cwd are inspected for USE_ALL
(defined in icmconf) files.  If a directory contains a USE_ALL file then a
USE_ALL file is also created in all directories including that directory's .h
file.

When the --precomp option is specified then all not yet visited directories in
CLASSES (and the cwd) are scanned for files matching the comma-separated list
of files. 
    If the directory has already been visited then nothing happens in that
        directory. Otherwise the directory is marked as inspected.
    If no file matches the list of --precomp files then that directory has 
        been processed. 
    If the .gch file does not yet exist or if at least one of the comma
        separated patterns in --inspect is younger than the .gch file then
        this directory's .gch file must be (re)compiled
    If a gch file must be recompiled, then indicate that the gch files of
        classes depending on the gch file's class must also be recompiled. 

Once the list of gch files to recompile has been determined 
    - show the files to recompile on stdout, 
    - or rm the gch files if --rm was specified.

****************************************/
