#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include "ArgParser.h"

namespace Mastermind
{

class Logic;
class MastermindView;

class Mastermind {
private:
    Logic *logic;

    MastermindView *view;

public:
    Mastermind(Logic *logic, MastermindView *view) :
        logic(logic),
        view(view)
    {
    }

public:
    ~Mastermind();

    void play();

};

}

#endif
