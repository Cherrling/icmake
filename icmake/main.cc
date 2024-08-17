#define XERR
#include "main.ih"

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        usage(*argv);
        return 1;
    }

    Options splitter(argc, argv);

    if (done(*argv, splitter.actionOpt()))
        return 0;

    Handler handler{ splitter };
    return handler.process();
}
catch(int x)
{
    return x;
}
catch (exception const &exc)
{
    cerr << "Error: " << exc.what() << '\n';
}
catch (...)
{
    cerr << "unexpected exception\n";
    return 1;
}
