//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"_( [options] argument(s)
Where:
  [options] - optional arguments (short options between parentheses):
    --about (-a)        - shows some info about icmake and terminates
    --compile (-c)      - the file specified as first argument is compiled if
                          it's younger than the .bim file or if the .bim file
                          doesn't exist. The .bim file is the 2nd file
                          argument or, if not specified, then the first
                          filename (using the extension .bim) is used.
    --dependencies (-d) - determines the dependencies among classes. All
                          options and arguments following this option are
                          forwarded to the icm-dep support program.
    --execute (-e)      - executes the (.bim) file specified as first
                          argument.  Options following --execute are forwarded
                          to icm-exec. Use option -- to separate options
                          forwared to icm-exec from options to be forwarded to
                          the .bim file.
    --force (-f)        - same as option as --compile, but compilation is
                          always performed, even if the .bim file is
                          up-to-date. 
    --help (-h)         - provide this help
    --no-prcoess (-N)   - implies -V. Child processes are not executed. To use
                          this option it must be specified before a -[dest]
                          option
    --multicomp (-m)    - arguments following -m: --quiet (-q), --threads (-t)
                          followed by 'jobs' and 'compiler' specs
    --no-version-check (-n) - when executing or unassembling .bim files the
                          icmake-versions used when constructing the .bim
                          files is not checked. 
                          Use only if you know what you're doing.
    --preprocess (-p)   - the file specified as first argument is
                          pre-processed. The .pim file is the 2nd file
                          argument or, if not specified, the first filename
                          (using the extension .pim), is used.
    --spch (-S)         - precompile a single precompiled header. All options
                          and arguments following this option are forwarded to
                          the icm-spch support program.
    --source (-s)       - uses --compile to compile the icmake source file
                          specified as first argument and then uses --execute
                          to execute the compiled .bim file.
    -t <arg>            - this option is provided for icmake-scripts.  <arg>
                          is either a single . (as in -t.) or the path-base of
                          the .bim-file (which is removed after its
                          execution). All arguments and options specified when
                          calling the icmake-script are forwarded as arguments
                          to the .bim file's main function. The -- option
                          should not be specified.
    --tmpdir (-T) <dir> - <dir> is the name of a (user-writable) directory
                          used by icmake to store temporary files. By default
                          /tmp is used. If /tmp is not writable the user's
                          HOME directory is used.
    --unassemble (-u)   - the file specified as first argument is an icmake
                          .bim file, which is unassembled.
    --verbose (-V)      - the full child process calls are written to the
                          std. output stream.
    --version (-v)      - show version information and terminate
    
    argument(s): for options requiring a file argument the first argument must
                 be a file. Depending on the specified option subsequent
                 arguments can be filenames or options that are forwared to
                 the option handler or to a .bim file.

)_";

}

void usage(std::string const &progname)
{
    Tools::usageTop(progname) << info;
}
