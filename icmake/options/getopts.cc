#define XERR
#include "options.ih"

void Options::getOpts()
{
    opterr = 0;                     // global getopt variable

    while (true)
    {
        d_optIdx = optind;
        d_opt = getopt_long(d_argc, d_argv, s_optstring.c_str(), 
                            s_options,  0);

        if (d_opt == -1)
            break;

        switch (d_opt)
        {
            case 'a':
            case 'h':
            case 'v':
                endAction();
            return;
            
            case 'c':
            case 'f':
            case 's':
                if (d_action == UNUSED)
                    d_preProcess = d_optIdx;
                setAction();
            break;
 
            case 'm':
            case 'S':
            case 'u':
                setAction();
            return;

            case 'd':
                if (depOrDef())
                    return;
            break;

            case 'e':
                action(&d_execute);
            break;

            case 'n':
                d_versionCheck = " -n";
//                argv[d_optIdx] = s_empty;
            break;

            case 'N':
                d_process = false;
            [[fallthrough]];

            case 'V':
                if (d_actionIdx == 0)   // no action idx seen so far
                    d_verbose = true;
            break;

            case 'P':
                d_pimFile = true;
            break;

            case 'p':
                if (d_preProcess != 0)
                    d_preProcess = d_optIdx;
                action(&d_preProcess);
            break;

            case 'q':               // recognized but ignored
            break;

            case 'T':
                d_tmpDir = optarg;
            break;

            case 't':
                scriptOption();
            break;

            case '?':
                throw Exception{} << "argument index " << d_optIdx << 
                                    ": option `" << d_argv[d_optIdx] << 
                                    "' not supported";
            break;
        }
    }
}

