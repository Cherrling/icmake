#define XERR
#include "rhbuilder.ih"

void RHbuilder::write(ostream &&rhStream, string const &ihFile)
{
    StringVect ihLines = read(ihFile);      // read the .ihFile

    auto iter = ihLines.begin();
    while (iter != ihLines.end())           // move all ih lines to rhStream
    {
        if (xfer(iter, rhStream))           // xfer #include lines to rhStream
            iter = ihLines.erase(iter);     // and omit sequences of empty
        else                                // lines
            ++iter;
    }

    ofstream ihStream{ Exception::factory<ofstream>(ihFile) };

                                // ihFile includes the rhFile
    ihStream << "#include \"" << fs::path{ ihFile }.stem().string() << 
                                 options().extension() << "\"\n\n";
    
    for (string line: ihLines)
        ihStream << line << '\n';
}
