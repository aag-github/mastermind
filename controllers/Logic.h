#ifndef SRC_CONTROLLERS_LOGIC_H_
#define SRC_CONTROLLERS_LOGIC_H_

#include "StartController.h"
#include "ReadCombinationController.h"
#include "ContinueController.h"
#include "Game.h"

namespace Mastermind {

class Logic {
public:
    Logic() :
        startController(game),
        readCombinationController(game),
        continueController(game)
    {
    }
    virtual ~Logic() {
    }

    OperationController* getController() {
        switch (game.getState()){
        case State::INITIAL:
            return &startController;
        case State::IN_GAME:
            return &readCombinationController;
        case State::FINAL:
            return &continueController;
        case State::EXIT:
        default:
            return nullptr;
        }
}
private:
    Game game;

    StartController startController;

    ReadCombinationController readCombinationController;

    ContinueController continueController;

};

}

#endif
