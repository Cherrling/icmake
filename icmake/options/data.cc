//#define XERR
#include "options.ih"

// static
char Options::s_empty[] = { 0 };

                                // d must be last: becomes d:
                                // q is recognized but ignored, and not used
                                // in s_options, below
string Options::s_optstring("+acefhmnNpPqSst:T:uvVd");

// the ordering of the s_options elements must follow enum Action, 
option Options::s_options[] =  
{
    { "dependencies",       no_argument, 0, 'd' },      // matches +
    { "about",              no_argument, 0, 'a' },
    { "compile",            no_argument, 0, 'c' },
    { "execute",            no_argument, 0, 'e' },
    { "force",              no_argument, 0, 'f' },
    { "help",               no_argument, 0, 'h' },
    { "multicomp",          no_argument, 0, 'm' },
    { "no-version-check",   no_argument, 0, 'n' },
    { "no-process",         no_argument, 0, 'N' },
    { "preprocess",         no_argument, 0, 'p' },
                                                    // -q: ignored
    { "spch",               no_argument, 0, 'S' },
    { "source",             no_argument, 0, 's' },
                                                    // -t: icmake scripts only
    { "tmpdir",             required_argument, 0, 'T' },
    { "unassemble",         no_argument, 0, 'u' },
    { "verbose",            no_argument, 0, 'V' },
    { "version",            no_argument, 0, 'v' },
    { 0 }
};

                                // chars must follow Action's ordering
                                // Handler::s_action must follow the
                                // ordering of the 1st word
string Options::s_xlat{ "cdefmpSstu" "ahv" };  

