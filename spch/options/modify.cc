#define XERR
#include "options.ih"

//  if (modify(file-exists, wmsg << "...")
bool Options::modify(string const &filename) const
{
    if (not d_warn or not Tools::exists(filename))
        return true;                        // modifications OK

    cout << "[warning] " << filename << " exists\n"
            "modify [yN] " << endl;

    string line;
    return getline(cin, line) and line.find_first_of("yY") == 0;
}
