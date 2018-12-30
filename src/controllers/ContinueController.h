#ifndef SRC_CONTROLLERS_CONTINUECONTROLLER_H_
#define SRC_CONTROLLERS_CONTINUECONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class ContinueController: public OperationController {
public:
    ContinueController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~ContinueController(){
    }

    void resume(bool resume) {
        assert(game.getState() == State::GAME_END);

        if (resume) {
            game.setState(State::INITIAL);
        } else {
            game.setState(State::EXIT);
        }

    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif