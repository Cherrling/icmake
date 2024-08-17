//                     usage.cc

#include "main.ih"

namespace {
char const info1[] = R"_( [options] jobs [compiler]
Where:
    [options] - optional arguments (short options between parentheses):
        --help (-h)             - provide this help
        --nr (-n)               - show the thread number compiling a source
                                  file (not used when -qq is specified)
        --quiet (-q)            - only show the source filenames. Use twice to
                                  suppress listing the sourcefiles. 
        --threads (-t) nThreads - number of compilation threads
                                  (default )_";

char const info2[] = R"_( threads)
        --version (-v)          - show version information and terminate

    jobs     - the name of a file containing the specs of the files to
               compile. Specs start with lines like ': support tmp/o 5' where
               the 2nd element specifies the location of the source files; the
               3rd element specifies the destination directory of the compiled
               files; and the 4th element specifies the prefix to add in front
               of the compiled object files. The names of the source files to
               compile follow next. Non-existing destination directories are
               created. 

    compiler - this argument is optional. By default the following
               specification is used (all on one line)
           g++ -c -o $2 ${ICMAKE_CPPSTD} --Wall -Werror $1
              In this specification '$1' is replaced by the location of the
               source file to compile and '$2' is replaced by the location of
               the compiled object file. If the environment variable
               'ICMAKE_CPPSTD' is defined (specifying the bf(C++) standard to
               use, e.g., 'ICMAKE_CPPSTD=--std=c++23') then its value replaces
               '${ICMAKE_CPPSTD}' in the specification.
              Alternatively, the command compiling source files can be
               provided as second command-line argument (in which case it
               should be quoted), or the second command-line argument can be
               'f:file', where 'file' is the name of a file whose first line
               contains the specification of the command compiling source
               files (which must specify '$1' and '$2' and optionally
               '$ICMAKE_CPPSTD').
              The 'PATH' environment variable is used to locate
               the compiler; the compiler's absolute path can also be used.
)_";

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info1 << thread::hardware_concurrency() <<
                             info2;
}

