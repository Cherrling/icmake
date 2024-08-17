//#define XERR
#include "options.ih"

Pattern Options::s_icmconf
{
    "^[ \t]*#define[ \t]*"
        "([^ \t]+)"     //      [1]: key 
        "[ \t]*\""
        "([^\"]+)?"     //      [2]: value (opt)
        "\""        
};

unordered_map<std::string, void (Options::*)()> Options::s_icmconfEntry = 
{
    { "IH",          &Options::ih         },
    { "PARSER_DIR",  &Options::parserDir  },
    { "PRECOMP",     &Options::precomp    },
    { "SCANNER_DIR", &Options::scannerDir },
    { "SPCH",        &Options::spch       },
    { "USE_ALL",     &Options::icmUseAll  },
};

