// Generated by Flexc++ V2.07.06 on Sun, 12 Jan 2020 21:04:35 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "scannerbase.h"

#include <stack>

#include "../../tmp/build/pattern/pattern"

#include "../symtab/symtab.h"

namespace FBB
{
    class Exception;
}

// $insert classHead
class Scanner: public ScannerBase
{
    enum
    {
        s_maxReplacements = 100
    };

    std::string d_defineBuffer;         // filled at the <define> 

    unsigned d_nErrors = 0;
    bool d_active = true;

    struct StreamData
    {
        std::string path;
                                            // this file// lastWritten;
    };
    std::stack<StreamData> d_streamData; 
    

    std::stack<bool> d_nest;                // active #if.. nesting level
    std::string d_ident;                    // in #define / #if(n)def

    Symtab d_symtab;

    static FBB::Pattern s_matchIdent;
    static FBB::Pattern s_matchDirective;
    static FBB::Pattern s_matchDefVar;

    public:
        enum Token
        {
            ALL_DONE,
            SPACE,
            TEXT,
            NL,
            NEXT,                   // next stream: continue with START
            AT_EOF,                 // return to the previous file
            nTokens,                // also used in 'lexer' to avoid returning
        };                          // a token (cf.: ident.cc)

    private:
        static Token (Scanner::*s_startDirective[])();
        static char const *s_tokenName[];

    public:
        Scanner();

        // $insert lexFunctionDecl
        int lex();

        unsigned nErrors() const;

        void text();                // writes matched()
        void write(int ch);         // writes ch
        void write(char const *txt);// writes txt
        void writeLineNr();         // writes lineNr()
        void writeFilename();       // writes #>filename\n

        bool active() const;                        // .h
        char const *tokenName(int token) const;     // .h

    private:
        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.


        void setFiles();    // if args were specified, then switch files

        int endComment();

        void startString();                 // at initial "
        int endString();                    // at ending "
        void invalidString();               // at \n

        void defineOptions();               // handle -d options

        void defineDirective();
        void assignIdent();                 // assign d_ident from matched()
        Token storeIdentValue();
        void replaceDefines();
        void checkIdentRecursion() const;
        bool identCharAt(int pos) const;

        void   elseDirective();
        void  endifDirective();
        void  ifdefDirective();
        void ifndefDirective();
        void  undefDirective();
        void     noDirective();

        void addBuffer();                   // .ih, adds matched() 

        bool includeIM();
        bool includeLocal();

        std::string nextName(char sep0, char sep1); 
        void nextStream(std::string next);  // switch to the next stream


        int ident();                        // insert ident or push a #defined 
                                            // name's value

        int atEOF();

        FBB::Exception fatal() const;
        std::ostream &error();              // error message
};

#include "lex.f"
#include "print.f"
#include "nerrors.f"
#include "active.f"
#include "tokenname.f"


#endif // Scanner_H_INCLUDED_

