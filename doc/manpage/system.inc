
bf(SYSTEM FUNCTIONS:)

    itemization(
    itt(void arghead(string str))nl()
       support function of tt(exec()) (see also below at tt(exec())): defines
        the `argument head' that is used with tt(exec()). By default, the
        `argument head' is an empty string. The argument head is text that is
        prefixed to all tt(exec) arguments, like a directory in which provided
        arguments are found;

    itt(void argtail (string str))nl()
       support function of tt(exec()) (see also below at tt(exec())): defines
        the `argument tail' that is used with tt(exec()). By default, the
        `argument tail' is an empty string. The argument tail is text that is
        appended to all tt(exec) arguments, like the extensions of files that
        are passed as arguments to tt(exec);
    
    itt(cmdhead(string str))nl()
       support function of tt(exec()) (see also below at tt(exec())).  Defines
        a `command head' that is used with tt(exec()). By default it is an
        empty string. It can be used to specify, e.g., compiler options when
        the arguments themselves are modified by tt(arghead) and tt(argtail).
        The tt(cmdhead) argument itself is not modified by tt(arghead) or
        tt(argtail);

    itt(cmdtail(string str))nl()
       support function of tt(exec()) (see also below at tt(exec())).  Defines
        a `command tail that is used with tt(exec()). By default it is an
        empty string. It can be used to specify a final argument (not modified
        by tt(arghead) and tt(argtail));

    itt(list eval(string str))nl()
       this function can be used instead of the backtick operator (cf. section
        tt(OPERATORS)). The example provided with the backtick operator could
        therefore also have been written like this:
       verb( 
    printf << eval("ls");   // prints the elements in the current 
                            // directory 
        )
       As mentioned at the backtick operator: the elements of the list contain
        the subsequent lines of output (including a final newline, if present)
        produced by `cmd'. A command that could be executed but that did not
        produce any output returns a list containing one string element, which
        is empty.

        An empty list indicates that the command could not be executed.


    itt(int exec([int check,] string cmd, argument(s)))nl()
       Executes the command tt(cmd) with (optional) arguments. Each argument
        is prefixed by tt(arghead) and postfixed by tt(argtail). Note that no
        blanks are inserted between tt(arghead), argument(s), and
        tt(argtail). The thus modified arguments are concatenated, separated
        by single blanks. tt(Cmdhead) is inserted between tt(cmd) and the
        first argument (delimited by single blanks) and tt(cmdtail) is
        appended to the arguments, separated by a single blank. tt(PATH) is
        searched to locate tt(cmd). 0 is returned.

       The first argument is optional: if omitted and the command does not
        return 0 the icm() script terminates. By specifying tt(P_NOCHECK)
        tt(exec) won't terminate the script but returns the called command's
        exit status, or tt(0x7f00) if the command wasn't found.

       The remaining arguments may be ints, strings or lists. Int and list
        arguments are cast to strings. Their string representations are then
        appended to tt(cmd);

    itt(int execute([int checking,] string cmd, string cmdhead,
            string arghead, argument(s), string argtail, string cmdtail))nl()
       Same functionality as the previous function, but the tt(cmdhead,
        arghead, argtail,) and tt(cmdtail) are explicitly specified (and are
        reset to empty strings after executing tt(cmd));

    itt(exit(expression))nl()
       Ends the execution of an icm()-script. The tt(expression) must evaluate
        to an tt(int) value, which is used as the script's exit value;

    itt(list getenv(string envvar))nl()
       returns the value of environment variable tt(envvar) in a list
        containing two elements:

       if the first element ([0]) is tt("1") then the environment variable was
        defined;

       environment variables are of the form tt(variable=value).  If element
        tt([0]) is tt("1") then the returned list's second element [1] holds
        the tt(value) part of the environment variable, which is empty if the
        environment variable is merely defined;

    itt(int getpid())nl() 
       returns the process-id of the icmake byte code interpreter
        bf(icm-exec);

    itt(int putenv(string envvar))nl()
       adds or modifies tt(envvar) to the current icm()-script
        environment. Use the format: tt("VAR=value"). Use tt("VAR") to remove
        tt("VAR") from the environment. The function returns 0 unless
       tt(envvar) is empty, in which case 1 is returned;

    itt(int system([int check,] string command))nl()
       executes tt(command) using the bf(system)(3) function. The first
        argument is optional: if omitted and calling the bf(system)(3)
        function does not return 0 then the icm()-script ends with exit value
        1; by specifying tt(P_NOCHECK) icm()'s tt(system) function won't
        terminate the script but returns the return value of the bf(system)(3)
        function (normally the executed command's exit value). The string
        tt(command) may use redirection and/or piping.
    )
