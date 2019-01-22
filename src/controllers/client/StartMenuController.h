#ifndef SRC_CONTROLLERS_STARTMENUCONTROLLER_H_
#define SRC_CONTROLLERS_STARTMENUCONTROLLER_H_

#include <assert.h>
#include "CombinationController.h"

#include "QuitController.h"
#include "StartController.h"
#include "LoadGameController.h"

namespace Mastermind {

class StartMenuController: public ClientOperationController {
public:
    StartMenuController(Game &game) :
        ClientOperationController(game),
        quitController(game),
        startController(game),
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

    StartController* getStartController() {
        return &startController;
    }

    LoadGameController* getLoadGameController() {
        return &loadGameController;
    }

private:
    QuitController quitController;

    StartController startController;

    LoadGameController loadGameController;
};

}

#endif
