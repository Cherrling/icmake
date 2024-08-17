#include "endian.ih"

Endian::LBE const Endian::s_lbe = { 0x102 };
bool const Endian::s_little = s_lbe.chars[0] == 2;  // true: little endian

