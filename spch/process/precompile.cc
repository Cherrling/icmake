#define XERR
#include "process.ih"

    // returns 0 if already or precompilation OK
int Process::precompile()
{
    string const &spch = d_options.spch();
    string const &spchGch = d_options.spchGch();

    bool ok = recent(spchGch, spch);
    if (not ok)
    {
        Exec exec;
        exec.execute(
                Tools::command(
                    Tools::compilerSpec(d_options.arg1(), s_precompileCmd),
                    spch, spchGch
                )
            );
        ok =  exec.ret() == 0;
    }

    if (ok)
    {
        cout << spchGch << ": ";
        double size = Stat{ spchGch }.size();
        cout << setiosflags(ios::fixed) << setprecision(1) <<
            (size / (1024 * 1024)) << " MB\n";
    }

    return ok == true ? 0 : 1;
}
