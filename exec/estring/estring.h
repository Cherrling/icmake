#ifndef INCLUDED_ESTRING_
#define INCLUDED_ESTRING_

#include <string>

#include "../varbase/varbase.h"

class EString: public VarBase
{
    std::string d_str;

    public:
        EString(std::string const &str = "");                            // 1.f

        ~EString() override;

    private:
        // these members *may* be overridden:

        std::string const &vStr() const override;
        std::strong_ordering vOrder(VarBase const &rhs) const override;

        // these members *must* be overridden:

        bool vEqual(VarBase const &rhs) const override;
        std::ostream &vInsertInto(std::ostream &out) const override;
        bool vBool() const override;
        VarBase &vAddIs(VarBase const &rhs) override;
        std::string vto_string() const override;
        bool vIsString() const override;
        VarBase *vcopy() const override;
};

#include "estring1.f"

#endif
