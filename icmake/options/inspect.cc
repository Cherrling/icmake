#define XERR
#include "options.ih"

void Options::inspect(char *tArguments)
{
    d_ptrs.push_back(strtok(tArguments, " \t"));

    while (true)
    {
        char *field = strtok(0, " \t");         // get subsequent fields

        if (field == 0)
            break;

        d_ptrs.push_back(field);                // store them
    }
}



