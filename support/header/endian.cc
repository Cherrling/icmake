#include "header.ih"

void Header::endian()
{
    if (littleEndian())
        return;

    strings = Endian::endian(strings);
    variables = Endian::endian(variables);
    filenames = Endian::endian(filenames);
    firstOpcode = Endian::endian(firstOpcode);
}
