#ifndef SRC_CONTROLLERS_STARTMENUCONTROLLER_H_
#define SRC_CONTROLLERS_STARTMENUCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

#include "QuitController.h"
#include "RestartController.h"
#include "LoadGameController.h"

namespace Mastermind {

class StartMenuController: public ClientOperationController {
public:
    StartMenuController(Game &game) :
        ClientOperationController(game),
        quitController(game),
        restartController(game, false),
        loadGameController(game)
    {
    }

    virtual ~StartMenuController(){
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    QuitController* getQuitController() {
        return &quitController;
    }

    RestartController* getRestartController() {
        return &restartController;
    }

    LoadGameController* getLoadGameController() {
        return &loadGameController;
    }

private:
    QuitController quitController;

    RestartController restartController;

    LoadGameController loadGameController;
};

}

#endif
