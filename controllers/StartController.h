#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
#include <functional>
#include "OperationController.h"

namespace Mastermind {

class StartController: public OperationController {
public:
    StartController(Game &game) :
        OperationController(game)
    {
        startGame = [&game](){ return game.start(); };
    }

    virtual ~StartController(){
    }

    void start() {
        startGame();

        setState(State::IN_GAME);
    };

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

private:
    typedef std::function<void ()> StartGame;

    StartGame startGame;

};

}

#endif
