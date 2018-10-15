#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include "Logic.h"
#include "MastermindView.h"

namespace Mastermind
{

class Mastermind {
private:
    Logic logic;

    MastermindView view;

public:
    Mastermind()
    {
    };

    void play()
    {
        OperationController* controller;
        do {
            controller = logic.getController();
            if (controller != nullptr){
                view.interact(controller);
            }
        } while (controller != nullptr);
    }
};

}
#endif
