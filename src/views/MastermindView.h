#ifndef SRC_VIEWS_MASTERMINDVIEW_H_
#define SRC_VIEWS_MASTERMINDVIEW_H_

#include <assert.h>
#include "OperationController.h"
#include "OperationControllerVisitor.h"
#include "StartView.h"
#include "ContinueView.h"
#include "ReadCombinationView.h"
#include "MenuView.h"
#include "QuitView.h"
#include "RestartView.h"

namespace Mastermind {

class StartController;
class ContinueController;
class ReadCombinationController;
class MenuController;
class QuitController;
class RestartController;


class MastermindView : public OperationControllerVisitor {
public:
    MastermindView(){};
    virtual ~MastermindView(){};


    void interact(OperationController *operationController) {
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
        menuView.build();
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

private:
    StartView startView;

    ReadCombinationView readCombinationView;

    ContinueView continueView;

    MenuView menuView;

    QuitView quitView;

    RestartView restartView;
};

}

#endif
