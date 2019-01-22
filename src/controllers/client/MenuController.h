#ifndef SRC_CONTROLLERS_MENUCONTROLLER_H_
#define SRC_CONTROLLERS_MENUCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

#include "ReadCombinationController.h"
#include "QuitController.h"
#include "RestartController.h"
#include "LoadGameController.h"
#include "SaveGameController.h"
#include "UndoController.h"
#include "RedoController.h"

namespace Mastermind {

class MenuController: public ClientOperationController {
public:
    MenuController(Game &game) :
        ClientOperationController(game),
        readCombinationController(game),
        quitController(game),
        restartController(game),
        loadGameController(game),
        saveGameController(game),
        undoController(game),
        redoController(game)
    {
    }

    virtual ~MenuController(){
    }

    void setNextState(State newState) {
        assert(game.getState() == State::MAIN_MENU);
        game.setState(newState);
    };

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    ReadCombinationController* getReadCombinationController() {
        return &readCombinationController;
    }

    QuitController* getQuitController() {
        return &quitController;
    }

    RestartController* getRestartController() {
        return &restartController;
    }

    LoadGameController* getLoadGameController() {
        return &loadGameController;
    }

    SaveGameController* getSaveGameController() {
        return &saveGameController;
    }

    UndoController* getUndoController() {
        return &undoController;
    }

    RedoController* getRedoController() {
        return &redoController;
    }

private:
    ReadCombinationController readCombinationController;

    QuitController quitController;

    RestartController restartController;

    LoadGameController loadGameController;

    SaveGameController saveGameController;

    UndoController undoController;

    RedoController redoController;
};

}

#endif
