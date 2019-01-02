#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
#include <functional>
#include "CombinationController.h"

namespace Mastermind {

class StartController: public OperationController {
public:
    StartController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~StartController(){
    }

    void start() {
        assert(game.getState() == State::INITIAL);

        game.start();

        game.setState(State::MENU);
    };

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
