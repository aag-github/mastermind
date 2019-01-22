#ifndef SRC_VIEWS_CLIENTMASTERMINDVIEW_H_
#define SRC_VIEWS_CLIENTMASTERMINDVIEW_H_

#include <assert.h>
#include "client/ClientOperationController.h"
#include "client/ClientOperationControllerVisitor.h"
#include "StartView.h"
#include "ReadCombinationView.h"
#include "MenuView.h"
#include "QuitView.h"
#include "RestartView.h"
#include "LoadGameView.h"
#include "SaveGameView.h"
#include "UndoView.h"
#include "RedoView.h"

namespace Mastermind {

class StartController;
class MenuController;

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

    virtual void visit(MenuController *menuController) override final {
        assert(menuController != nullptr);
        menuView.interact(menuController);
    }


private:
    StartView startView;

    MenuView menuView;
};

}

#endif
