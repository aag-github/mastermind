#ifndef SRC_CONTROLLERS_STANDALONELOGIC_H_
#define SRC_CONTROLLERS_STANDALONELOGIC_H_

#include "Logic.h"
#include "GameLocal.h"
#include "StartController.h"
#include "ReadCombinationController.h"
#include "ContinueController.h"
#include "MenuController.h"
#include "QuitController.h"
#include "RestartController.h"
#include "LoadGameController.h"
#include "SaveGameController.h"
#include "UndoController.h"
#include "RedoController.h"

namespace Mastermind {

class StandaloneLogic : public Logic {
public:
    StandaloneLogic() :
        startController(game),
        readCombinationController(game),
        continueController(game),
        menuController(game),
        quitController(game),
        restartController(game),
        loadGameController(game),
        saveGameController(game),
        undoController(game),
        redoController(game)
    {
    }
    virtual ~StandaloneLogic() {
    }

    virtual OperationController* getController() override final {
        switch (game.getState()){
        case State::INITIAL:
            return &startController;
        case State::MENU:
            return &menuController;
        case State::READ_PROPOSED_COMBINATION:
            return &readCombinationController;
        case State::QUIT:
            return &quitController;
        case State::RESTART:
            return &restartController;
        case State::LOAD_GAME:
            return &loadGameController;
        case State::SAVE_GAME:
            return &saveGameController;
        case State::GAME_END:
            return &continueController;
        case State::UNDO:
            return &undoController;
        case State::REDO:
            return &redoController;
        case State::EXIT:
            return nullptr;
        default:
            assert(false);
            return nullptr;
        }
}
private:
    GameLocal game;

    StartController startController;

    ReadCombinationController readCombinationController;

    ContinueController continueController;

    MenuController menuController;

    QuitController quitController;

    RestartController restartController;

    LoadGameController loadGameController;

    SaveGameController saveGameController;

    UndoController undoController;

    RedoController redoController;
};

}

#endif