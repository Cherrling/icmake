#ifndef INCLUDED_BIMHEADER_
#define INCLUDED_BIMHEADER_

#include <string>
#include <fstream>
#include <algorithm>

#include <bobcat/exception>

#include "../endian/endian.h"
#include "../header/header.h"

class BimHeader: private Endian
{
    std::string d_bimName;
    std::ifstream d_in;

    Header d_hdr;

    public:
        BimHeader(char const *fname, char const *version, bool versionCheck);

        uint32_t stringsOffset() const;
        void stringsSection();
        bool endStrings();
        std::string string();           // get the string from the current 
                                        // offset

        std::string string(size_t idx); // get string 'idx' from the string-
                                        // section (the initial stream offset 
                                        // is reset when returning

        uint32_t varsOffset() const;
        void varsSection();
        bool endVars();

        uint16_t varType(uint16_t idx); // get var 'idx'th type, restoring
                                        // the initial stream offset when
                                        // returning

        uint32_t filenameOffset() const;

        uint32_t startOffset() const;
        void start();

        uint32_t codeOffset() const;
        void codeSection();
        bool endCode();

        bool hasVariables() const;
        bool hasStrings() const;

        uint32_t offset();
        void seekg(int32_t step, std::ios::seekdir dir = std::ios::beg);

        template <typename Type>
        void read(Type *dest, size_t nValues);

        template <typename Type>
        Type get();

    private:
        uint32_t codeEndOffset() const;
        void readFrom(uint32_t offset);

        void checkOffsets() const;

        bool atOffset(uint32_t offset);

        static std::string bimName(char const *fname);
};

#include "read.f"
#include "get.f"
#include "offset.f"
#include "stringsoffset.f"
#include "stringssection.f"
#include "endstrings.f"
#include "varsoffset.f"
#include "varssection.f"
#include "endvars.f"
#include "startoffset.f"
#include "start.f"
#include "codeoffset.f"
#include "codesection.f"
#include "endcode.f"
#include "hasvariables.f"
#include "hasstrings.f"
#include "filenameoffset.f"

#endif


