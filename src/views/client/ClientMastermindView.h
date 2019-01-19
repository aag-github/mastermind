#ifndef SRC_VIEWS_CLIENTMASTERMINDVIEW_H_
#define SRC_VIEWS_CLIENTMASTERMINDVIEW_H_

#include <assert.h>
#include "client/ClientOperationController.h"
#include "client/ClientOperationControllerVisitor.h"
#include "StartView.h"
#include "ContinueView.h"
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
class ContinueController;
class ReadCombinationController;
class MenuController;
class QuitController;
class RestartController;
class LoadGameController;
class SaveGameController;
class UndoController;
class RedoController;

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

    virtual void visit(ReadCombinationController *readCombinationController) override final {
        assert(readCombinationController != nullptr);
        readCombinationView.interact(readCombinationController);
    }

    virtual void visit(ContinueController *continueController) override final {
        assert(continueController != nullptr);
        continueView.interact(continueController);
    }

    virtual void visit(MenuController *menuController) override final {
        assert(menuController != nullptr);
        menuView.interact(menuController);
    }

    virtual void visit(QuitController *quitController) override final {
        assert(quitController != nullptr);
        quitView.interact(quitController);
    }

    virtual void visit(RestartController *restartController) override final {
        assert(restartController != nullptr);
        restartView.interact(restartController);
    }

    virtual void visit(LoadGameController *loadGameController) override final {
        assert(loadGameController != nullptr);
        loadGameView.interact(loadGameController);
    }

    virtual void visit(SaveGameController *saveGameController) override final {
        assert(saveGameController != nullptr);
        saveGameView.interact(saveGameController);
    }

    virtual void visit(UndoController *undoController) override final {
        assert(undoController != nullptr);
        undoView.interact(undoController);
    }

    virtual void visit(RedoController *redoController) override final {
        assert(redoController != nullptr);
        redoView.interact(redoController);
    }

private:
    StartView startView;

    ReadCombinationView readCombinationView;

    ContinueView continueView;

    MenuView menuView;

    QuitView quitView;

    RestartView restartView;

    LoadGameView loadGameView;

    SaveGameView saveGameView;

    UndoView undoView;

    RedoView redoView;
};

}

#endif
