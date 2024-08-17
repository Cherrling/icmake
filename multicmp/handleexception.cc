#include "main.ih"

int handleException()
try
{
    rethrow_exception(current_exception());
} 
catch (int ret)                 // handle the known exceptions
{
    return Arg::instance().option("hv") ? 0 : ret;
}
catch (exception const &exc)
{
    cerr << "Error: " << exc.what() << '\n';
    return 1;
}
catch (...)                     // and handle an unexpected exception
{
    cerr << "unexpected exception\n";
    return 1;
}
