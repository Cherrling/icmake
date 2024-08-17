#define XERR
#include "options.ih"

void Options::classesOpt()
{
    if (d_classesOption = d_arg.option(&d_classes, 'c'); not d_classesOption)
        d_classes = "CLASSES";
}
