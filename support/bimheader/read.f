template <typename Type>
void BimHeader::read(Type *dest, size_t nValues)
{
    if (not d_in.read(reinterpret_cast<char *>(dest), nValues * sizeof(Type)))
        throw FBB::Exception{} << nValues << " values of " << sizeof(Type) << 
                                    " bytes not available";

    if (not littleEndian())
    {
        std::for_each(dest, dest + nValues, 
            [](Type &dest)
            {
                dest = endian(dest);
            }
        );
    }
}
