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

protected:
    Mastermind(Logic *logic, MastermindView *view) :
        logic(logic),
        view(view)
    {
    }

public:
    ~Mastermind();

    void play();

    static Mastermind* build(const ArgParser &parser);
};

}

#endif
