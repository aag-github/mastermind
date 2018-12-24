#ifndef SRC_CONTROLLERS_LOGIC_H_
#define SRC_CONTROLLERS_LOGIC_H_

#include "StartController.h"
#include "ReadCombinationController.h"
#include "ContinueController.h"
#include "MenuController.h"
#include "QuitController.h"
#include "Game.h"

namespace Mastermind {

class Logic {
public:
    Logic() :
        startController(game),
        readCombinationController(game),
        continueController(game),
        menuController(game),
        quitController(game)
    {
    }
    virtual ~Logic() {
    }

    OperationController* getController() {
        switch (game.getState()){
        case State::INITIAL:
            return &startController;
        case State::MENU:
            return &menuController;
        case State::READ_PROPOSED_COMBINATION:
            return &readCombinationController;
        case State::QUIT:
            return &quitController;
        case State::GAME_END:
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

    MenuController menuController;

    QuitController quitController;
};

}

#endif
