#ifndef SRC_VIEWS_CLIENTMASTERMINDVIEW_H_
#define SRC_VIEWS_CLIENTMASTERMINDVIEW_H_

#include <assert.h>
#include "client/ClientOperationController.h"
#include "client/ClientOperationControllerVisitor.h"
#include "commands/StartView.h"
#include "MainMenuView.h"
#include "StartMenuView.h"

namespace Mastermind {

class StartController;
class MainMenuController;
class StartMenuController;

class ClientMastermindView : public ClientOperationControllerVisitor {
public:
    ClientMastermindView(){};
    virtual ~ClientMastermindView(){};


    void interact(ClientOperationController *operationController) {
        assert(operationController != nullptr);
        operationController->accept(this);
    }

    virtual void visit(StartController *startController) override final {
        assert(startController != nullptr);
        startView.interact(startController);
    }

    virtual void visit(MainMenuController *menuController) override final {
        assert(menuController != nullptr);
        mainMenuView.interact(menuController);
    }

    virtual void visit(StartMenuController *menuController) override final {
        assert(menuController != nullptr);
        startMenuView.interact(menuController);
    }

private:
    StartView startView;

    MainMenuView mainMenuView;

    StartMenuView startMenuView;
};

}

#endif
