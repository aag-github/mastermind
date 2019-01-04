#ifndef SRC_CONTROLLERS_CONTINUECONTROLLER_H_
#define SRC_CONTROLLERS_CONTINUECONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class ContinueController: public ClientOperationController {
public:
    ContinueController(Game &game) :
        ClientOperationController(game)
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

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
