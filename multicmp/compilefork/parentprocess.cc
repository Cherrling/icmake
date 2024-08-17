//#define XERR
#include "compilefork.ih"

void CompileFork::parentProcess()
{
    IFdStream fromChild(d_childOutput.readOnly());

    string line;

    while (getline(fromChild, line))
        d_lines.push_back(move(line));

    d_ret = waitForChild();
}
