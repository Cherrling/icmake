#define XERR
#include "options.ih"

void Options::dotRequired(string *member, char const *what, int optChar)
{
    if (listOnly(member, optChar) and member->front() != '.')
        emsg << "The --" << what << 
                " option value must start with a dot (.)" << endl;
}
