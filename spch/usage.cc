//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"_( [options] dest ['compiler']
Where:
    [options] - optional arguments (short options between parentheses):
        --classes (-c) file    - 'file' contains the list of directories
                                 inspected by the --list option (by default
                                 CLASSES). The project's top directory is
                                 automatically inspected unless the option
                                 --no-topdir is specified.
        --guard (-g) name      - 'name' is the name of the include-guard name
                                 in internal headers. By default 'name' is
                                 SPCH_.
        --help (-h)            - provide this help and end the program.
        --internal (-i) .ext   - .ext is the extension used for the internal
                                 headers (including the dot) by default: .ih
        --keep (-k) regex      - keep (and do not inspect)
                                 include-specification(s) in internal headers
                                 matching regular expressions in 'regex'. Use
                                 (...)|(...) to specify multiple regexes. Use
                                 f:file to specify a file whose non-empty
                                 lines contain regexex.
        --list (-l)            - write the file 'dest' containing the
                                 filenames of the files to process when
                                 constructing a single precompiled header
                                 (SPCH). 
                                 'dest' must be a filename (without extension)
                                 in the CWD. 
        --no-topdir (-n)       - Ignore the project's top directory when
                                 specifying the --list option.
        --precompile (-p) file - precompile 'file' (the filename specified at
                                 the option '--list') to the SPCH file 'dest',
                                 specified as icm-spch's first command-line
                                 argument. If 'dest' ends in / then the SPCH
                                 is the file 'dest'file.gch.
                                By default the SPCH is constructed using the
                                 following command:
             g++ -c -o $2 ${ICMAKE_CPPSTD} -Wall -Werror -O2 -x c++header $2'
                                Here, $1 refers to 'file', $2 refers to
                                 'dest', and '$ICMAKE_CPPSTD' refers to the
                                 value of the 'ICMAKE_CPPSTD' environment
                                 variable (specifying the bf(C++) standard to
                                 use, e.g., ICMAKE_CPPSTD=--std=c++23).nl()
                                Alternatively, the command constructing the
                                 SPCH can be provided as second command-line
                                 argument (in which case it should be quoted),
                                 or the second command-line argument can be
                                 'f:file', where 'file' is the name of a file
                                 whose first line specifies the command
                                 constructing the SPCH (which must specify
                                 '$1' and '$2' and optionally
                                 '$ICMAKE_CPPSTD').nl()
                                The 'PATH' environment variable is used to
                                 locate the compiler, but the compiler's
                                 absolute path can also be used.
        --soft-link (-s) file  - 'file' and 'dest' are identical to the ones
                                 specified at option --precompile. --soft-link
                                 creates .gch soft-links from the header files
                                 listed in 'file' to the SPCH-file specified
                                 as the program's argument 'dest'
        --version (-v)         - show version information and end the program.
        --warn (-w)            - warn when existing files are about to be
                                 modified

)_";

//       --required (-r) .ext   - .ext is the extension used by the required
//                               headers (including the dot). There's no
//                               default: if not specified the internal
//                               headers are precompiled.


}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info;
}
