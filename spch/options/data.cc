#define XERR
#include "options.ih"

Pattern Options::s_spec{ R"_([<"][^">]+[">])_" };
Pattern Options::s_keep;
