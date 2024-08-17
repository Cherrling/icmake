#define XERR
#include "compiler.ih"

void Compiler::fillData()
{
    Data data;
    
    while (true)
    {
        if (d_jobs.peek() == ':')
        {
            d_jobs.ignore() >> data.sourceDir >> data.objDir >> data.prefix;

            error_code ec;
            if (not Tools::createDirectories(data.objDir))
                throw Exception{} << "cannot create directory " <<
                                                       data.objDir;
        }
        if (not (d_jobs >> data.source))        // no more source files
            break;
        d_dataVect.push_back(data);

        d_jobs.ignore(100, '\n');
    }

//    for (Data const &data: d_dataVect)
//        cout << data.sourceDir << '/' << data.source << ' ' << data.objDir <<
//                                                '/' << data.prefix << '\n';
}


