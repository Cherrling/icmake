//#define XERR
#include "compilefork.ih"

void CompileFork::echo()
{
    string const &srcDir = d_data->sourceDir;

    lock_guard lg{ s_echo };

    switch (d_nQuiet)
    {
        case 0:
            if (d_showID)
                cout << d_id << ": ";
            cout << d_compileCmd << " (" << srcDir << ")\n";
        break;

        case 1:
        {
            if (d_showID)
                cout << d_id << ": ";
            size_t pos = d_compileCmd.find_last_of(" \t");
            cout << srcDir << '/' << d_compileCmd.substr(pos + 1) << '\n';
        }
        break;

        default:
        break;
    }

    if (d_ret != 0)
    {
        for (string const &line: d_lines)
            cout << line << '\n';
    }
}


