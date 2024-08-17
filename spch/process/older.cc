#define XERR
#include "process.ih"

bool Process::older(string const &filename)
{
    ifstream in{ filename };                // open the file
    
    string line;
    while (getline(in, line))               // read all its lines
    {
        if (not (s_include << line))        // not an #include spec
            continue;
                                            // the spch.gch file is older
        if (d_spchGchTime < Stat{ s_include[1] }.lastModification())
            return true;

        fs::path parent = fs::path{ s_include[1] }.parent_path();
        if (parent != "")               // if the file has a path, go there
        {
            fs::path cwd = Tools::currentPath();   // remember the CWD
            Tools::currentPath(parent);
                                        // inspect the nested file
            bool old = older(fs::path{ s_include[1] }.filename());

            Tools::currentPath(cwd);
            if (old)
                return old;
        }
    }

    return false;
}
