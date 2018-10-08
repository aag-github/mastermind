#ifndef _MASTERMIND_H
#define _MASTERMIND_H

#include "Logic.h"

namespace Mastermind
{

class Mastermind {
private:
    Logic logic;

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
                controller->control();
            }
        } while (controller != nullptr);
    }
};

}
#endif
