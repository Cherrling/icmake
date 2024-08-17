#define XERR
#include "options.ih"

void Options::scriptOption()
{
    if (d_action == UNUSED)
        d_preProcess = d_optIdx;

    setAction();

        // with  -t . -p -done -d two -e n
        //
        //      at d_optIdx: `-t . -p -done -d two -e n'
        //      optarg: ` . -p -done -d two -e n'
        // 
        // with -t. -p -done -d two -e n
        //
        //      at d_optIdx: `-t. -p -done -d two -e n'
        //      optarg: `. -p -done -d two -e n'

                                        // assign all ptrs until
                                        // d_argv[optIdx] to d_ptrs
    d_ptrs = std::vector<char *>{ d_argv, d_argv + d_optIdx };

    inspect(d_argv[d_optIdx]);          // inspect this possibly multi-valued
                                        // element

                                        // add the remaining elements + 
                                        // final zero-element
    d_ptrs.insert(d_ptrs.end(), d_argv + d_optIdx + 1, d_argv + d_argc + 1);

    d_argv = &d_ptrs.front();           // update d_argc and d_argv
    d_argc = d_ptrs.size() - 1;         // don't count the final 0 !

//    cout << "\n"
//            "post:\n";
//    for (unsigned idx = 0; idx != d_argc; ++idx)
//        cout << "   " << idx << ": `" << d_argv[idx] << "'\n";
//    cout << '\n';

}





