#ifndef INCLUDED_DEPENDENCIES_
#define INCLUDED_DEPENDENCIES_

#include <unordered_set>

#include "../../tmp/build/typedefs/typedefs.h"
#include "../action/action.h"

class Options;

namespace FBB
{
    class Pattern;
}

class Dependencies
{

    Options const &d_options;

    size_t d_size;                  // #directories
    std::string const &d_useAll;

    StringVect d_directory;         // current, scanner, parser and 
                                    // CLASSES dirs. All dirs end in '/'

    size_t d_dirWidth;              // max. width of the dir. names

    BoolMatrix d_dependency;        // holds the dependencies of row classes 
                                    // on column classes: if a column class
                                    // changes then the row class changes too.

    StringMatrix d_localHeader;     // local header files: the first element
                                    // of each row holds the directory's
                                    // own .ih file, which is precompiled to
                                    // .ih.gch, subsequent elements are 
                                    // additionally included local headers

    BoolVect d_indicator;           // used with useAll and gch checks

    UnsignedVect d_classCount;
    UnsignedVect d_classIdx;
                                    // local headers being inspecting ->
                                    // dependson.cc
    std::unordered_set<std::string> d_inspecting;

    static FBB::Pattern s_include;  // RegEx recognizing various #include
                                    // directives

    public:
        Dependencies(Options const &options);

        void find();                // find all dependencies amoung classes

        void useAll();              // check the 'USE_ALL' option and maybe
                                    // touch files in directories

        void gchFiles();            // check the 'PRECOMP' option and maybe
                                    // remove .gch files depending on headers
                                    // that were modified

        void showUsing();

    private:
        void addDirectory(std::string const &dirname);

        size_t readClasses();

        void directDependencies();

        void impliedDependencies();
        bool updateDependencies(size_t idx);

        // called via useAll:
        void useAllIndicator();
        void inspectUseAll(size_t idx);
        void recursiveUseAll(size_t dep);
        void touchUseAll() const;

        // called via gchFiles:
        void inspectGchAges();
        void inspectGchAge(size_t dir);
        void impliedGchRemovals();
        void dependentGch(size_t idx);
        void removeGch();

                                    // determine the dependencies of 'header',
                                    // living in d_directory[idx]
        void dependency(size_t idx, std::string const &header);

        void localHeader(size_t idx, std::string const &header);
        void setDependency(size_t idx, std::string const &dirName);

        void dependsOn(std::string const &line, size_t idx);

        void showDependencies(char const *label) const;

// NEW
        void setClassIdx();
        void setCount();

// ===

        static void tableLine(size_t nBlanks, size_t width);
        static void numberLine(size_t count);   // nrs 1 .. count (inclusive)

        void checkUseAll();

        std::string ihFile(size_t idx) const;

        static bool orBoolVect(BoolVect &lhs, BoolVect const &rhs);
        static bool changeDir(std::string const &path);
        static BoolMatrix identityMatrix(size_t size);
};
        
#endif




