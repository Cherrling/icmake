//#define XERR
#include "options.ih"

void Options::show() const
{
    cout <<
        "   versionCheck:   " << d_versionCheck << "\n"
        "   process:        " << d_process << "\n"
        "   verbose:        " << d_verbose << "\n"
        "   tmpDir:        `" << d_tmpDir << "'\n"
        "   action:         " << (char)d_action << "\n"
        "   files at:       " << d_optIdx << "\n"
        "   actionIdx:      " << d_actionIdx << "\n"
        "   execute:        " << d_execute << "\n"
        "   preProcess:     " << d_preProcess << "\n\n";

    cout << "file arguments at " << d_optIdx << '\n';

    for (unsigned idx = 0; idx != d_argc; ++idx)
        cout << "   " << idx << ": " << d_argv[idx] << '\n';

}
