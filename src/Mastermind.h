#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include "ArgParser.h"
#include "MastermindView.h"

namespace Mastermind
{

class Logic;

class Mastermind {
private:
    Logic *logic;

    MastermindView view;

public:
    Mastermind(Logic *logic) :
        logic(logic)
    {
    }

public:
    ~Mastermind();

    void play();

};

}

#endif
