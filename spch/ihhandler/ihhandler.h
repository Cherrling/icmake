#ifndef INCLUDED_IHHANDLER_
#define INCLUDED_IHHANDLER_

#include <fstream>
#include <string>

#include "../../tmp/build/pattern/pattern"

#include "../classes/classes.h"

class IHhandler: private Classes
{
    std::ofstream d_spch;

    StringSet d_ihFiles;
    StringVect d_usingDecls;

    std::string d_defineSPCH;
    std::string d_ifndefSPCH;

    mutable FBB::Pattern d_ifndefSPCHre;

    static FBB::Pattern s_endif;
    static FBB::Pattern s_usingDecl;    // matches 'using <namespace>' and
                                        //  'namespace <name> = <namespace>'

    public:
        IHhandler(Options const &options);
        int run();

    private:
        void inspectIHfiles();
                                            
        StringVect inspect(std::string const &ihName);  // process an .ih file
        StringVect update(StringVect &lines) const;     // get namesp. decls
        void merge(StringVect const &usingDecls);       // add new using decls

                                    // write the protected using decls. to
                                    // an .ih file and add the ih-#include 
                                    // to the spch file
        void write(std::string const &ihName, StringVect const &lines) const;

                                    // return all encountered using decls.
                                    // removing them from 'lines'
        StringVect usingDecl(StringVect &lines) const;

};
        
#endif



