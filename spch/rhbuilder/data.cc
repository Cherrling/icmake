#define XERR
#include "rhbuilder.ih"

                                    //    <file> or "file"
                                    // [1] is the matched <file> or "file"
                                    //           1              1
Pattern RHbuilder::s_include{ R"_(^\s*#include\s+([<"][^">]+[">]))_" };

