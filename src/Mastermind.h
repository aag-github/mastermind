#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include "ArgParser.h"
#include "MastermindView.h"
#include "Logic.h"

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
    virtual ~Mastermind()
    {
        delete logic;
    }

    void play()
    {
        OperationController* controller;
        do {
            controller = logic->getController();
            if (controller != nullptr){
                view.interact(controller);
            }
        } while (controller != nullptr);
    }
};

}

#endif
