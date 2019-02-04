#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
#include "ClientOperationController.h"

namespace Mastermind {

class StartController {
public:
    virtual ~StartController() {}

    virtual void start() = 0;
};

class StartControllerImpl: public ClientOperationController, public StartController {
public:
    StartControllerImpl(Game &game) :
        ClientOperationController(game),
        nextState(State::MAIN_MENU)
    {
    }

    virtual ~StartControllerImpl(){
    }

    virtual void start() override final {
        assert(game.getState() == State::START_MENU);

        game.start();

        game.setState(State::MAIN_MENU);
    };

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };
private:
    State nextState;
};

}

#endif
