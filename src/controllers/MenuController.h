#ifndef SRC_CONTROLLERS_MENUCONTROLLER_H_
#define SRC_CONTROLLERS_MENUCONTROLLER_H_

#include <iostream>
#include <assert.h>
#include <functional>
#include "CombinationController.h"

namespace Mastermind {

class MenuController: public OperationController {
public:
    MenuController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~MenuController(){
    }

    void setNextState(State newState) {
        assert(game.getState() == State::MENU);
        game.setState(newState);
    };

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
