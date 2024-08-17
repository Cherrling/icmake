#include "ihhandler.ih"

//char const *Ihhandler::s_defineSPCH = "#define SPCH_\n\n";
//char const *Ihhandler::s_ifndefSPCH = "#ifndef SPCH_";

Pattern IHhandler::s_endif{ R"(\s*#endif\b)" };
Pattern IHhandler::s_usingDecl{ 
                            R"((^\s*namespace\s+\w+\s*=))"
                            "|"
                            R"((^\s*using\s+namespace\s+\w+))"
                        };


