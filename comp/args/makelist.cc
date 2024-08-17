#define XERR
#include "args.ih"

bool Args::makelist(Builtin::ArgsIter funBegin, Builtin::ArgsIter funEnd,
                    unsigned argBegin, unsigned argEnd)
{
    if (argEnd - argBegin == 0)                     // zero trailing args: OK
        return true;
                                                    // # specs/args differ
    if (int argDiff = argEnd - argBegin; funEnd - funBegin != argDiff)     
        return false;

                                                    // check trailing args
    for (; funBegin != funEnd; ++funBegin, ++argBegin)
    {
        if (not equalTypes(funBegin, argBegin))
            return false;
    }

    return true;
}
