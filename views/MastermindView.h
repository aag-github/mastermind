#ifndef SRC_VIEWS_MASTERMINDVIEW_H_
#define SRC_VIEWS_MASTERMINDVIEW_H_

#include <assert.h>
#include "OperationController.h"
#include "OperationControllerVisitor.h"
#include "StartView.h"
#include "ContinueView.h"
#include "ReadCombinationView.h"

namespace Mastermind {

class StartController;
class ContinueController;
class ReadCombinationController;


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

private:
    StartView startView;

    ReadCombinationView readCombinationView;

    ContinueView continueView;

};

}

#endif
