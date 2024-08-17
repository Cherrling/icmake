inline std::string const &Options::extension() const
{
    return d_required.empty() ? d_internal : d_required;
}

inline std::string const &Options::guard() const
{
    return d_guard;
}

inline std::string const &Options::classes() const
{
    return d_classes;
}

inline std::string const &Options::internal() const
{
    return d_internal;
}

inline bool Options::list() const
{
    return d_listOption;
}

inline bool Options::precompile() const
{
    return d_precompileOption;
}

inline bool Options::softLink() const
{
    return d_softLinkOption;
}

inline bool Options::rh() const
{
    return not d_required.empty();
}

inline bool Options::topDir() const
{
    return d_topDir;
}

inline std::string const &Options::spch() const
{
    return d_spch;
}

inline std::string const &Options::spchGch() const
{
    return d_spchGch;
}

inline char const *Options::arg1() const
{
    return d_arg[1];
}
