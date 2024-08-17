#ifndef INCLUDED_CLASSES_
#define INCLUDED_CLASSES_

#include "../support/support.h"

class Options;

class Classes: public Support
{
    Options const &d_options;
    StringSet d_files;                  // all .ih or .rh files

    protected:
        Classes(Options const &options);
        StringSet const &readClasses();     // determine the files fm CLASSES
        Options const &options() const;

    private:
        void add(std::string const &line, std::string const &extension);  // 1
        void add(std::string const &extension);                           // 2
};

#include "classes.f"
        
#endif




