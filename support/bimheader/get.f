template <typename Type>
Type BimHeader::get()
{
    Type ret;
    if (not d_in.read(reinterpret_cast<char *>(&ret), sizeof(Type)))
        throw FBB::Exception{} << (sizeof(Type) * 8) << 
                                    "-bit value not available";
    return endian(ret);
}
