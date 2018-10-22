#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
#include <functional>
#include "CombinationController.h"

namespace Mastermind {

class StartController: public CombinationController {
public:
    StartController(Game &game) :
        CombinationController(game)
    {
        startGame = [&game](){ return game.start(); };
    }

    virtual ~StartController(){
    }

    void start() {
        assert(getState() == State::INITIAL);

        startGame();

        setState(State::READ_PROPOSED_COMBINATION);
    };

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

private:
    StartGame startGame;

};

}

#endif
