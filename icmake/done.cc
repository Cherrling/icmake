#define XERR
#include "main.ih"

bool done(char const *program, Options::Action action)
{
    switch (action)
    {
        case Options::ABOUT:
            about(program);
        break;

        case Options::HELP:
            usage(program);
        break;

        case Options::VERS:
            version(program);
        break;

        default:
        return false;
    }

    return true;
}
