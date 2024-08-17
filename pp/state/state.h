#ifndef INCLUDED_STATE_
#define INCLUDED_STATE_

#include "../../tmp/build/constmember/constmember.h"
#include "../scanner/scanner.h"

class State: private ConstMember<State>
{
    friend class ConstMember<State>;

    enum States
    {
        START,
        CONTENT,
        WS,
        NL0,
        NL1,
        NLn,
        nStates
    };

    States d_state = START;

    Scanner d_scanner;

    static void (State::*s_state[][nStates])();
    static char const *s_stateName[];

    public:
        State() = default;

        int run();        

    private:
        void text2content();    // text -> CONTENT
        void writeNLtext();     // \n and text
        void writeHashLine();   // #\n -> START
        void writeLineNrText(); // #lineNr()\n and text

        void nop() const;
        void err() const;

        void ws();

                                // these functions check wether 
        void text();            // scanner.active()
        void nlText();          // 
        void spaceText();       // 
        void lineNrText();      // 
        void nlLineNrText();    // 
        void filename();        // 
        void nlFilename();      // 
        void hashLine();        // 
        void nlHashLine();      // 

        void nl0();
        void nl1();
        void nlN();
};
        
#endif
