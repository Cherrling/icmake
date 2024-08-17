inline Action Options::go() const
{
    return d_go;
}
inline Action Options::gch() const
{
    return d_gch;
}
inline void Options::startDir() const
{
    std::filesystem::current_path(d_cwd);
}
inline std::string const &Options::classes() const
{
    return d_classes;
}
inline std::string const &Options::parser() const
{
    return d_parser;
}
inline std::string const &Options::scanner() const
{
    return d_scanner;
}
inline std::string const &Options::mainIH() const
{
    return d_mainIH;
}
inline std::string const &Options::dotIH() const
{
    return d_ih;
}
inline size_t Options::verbosity() const
{
    return d_arg.option('V');
}
inline std::string const &Options::useAll() const
{
    return d_useAll;
}
