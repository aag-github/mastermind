#ifndef SRC_CONTROLLERS_RESTARTCONTROLLER_H_
#define SRC_CONTROLLERS_RESTARTCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class RestartController: public ClientOperationController {
public:
    RestartController(Game &game) :
        ClientOperationController(game)
    {
    }

    virtual ~RestartController(){
    }

    void restart(bool restart) {
        assert(game.getState() == State::RESTART);

        if (restart) {
            game.setState(State::INITIAL);
        } else {
            game.setState(State::MENU);
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
