#ifndef INCLUDED_EXPRTYPE_H_
#define INCLUDED_EXPRTYPE_H_

#include <iosfwd>

#include "../../tmp/build/exprtype/exprtype.h"

unsigned const N_EXPR_TYPES = 4;    // #types used at e_mask

#include "opor.f"
#include "opand.f"
#include "equalmask.f"
#include "voidmask.f"

std::ostream &operator<<(std::ostream &out, ExprType type);

#endif
