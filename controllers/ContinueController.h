#ifndef SRC_CONTROLLERS_CONTINUECONTROLLER_H_
#define SRC_CONTROLLERS_CONTINUECONTROLLER_H_

#include "CharReader.h"
#include "OperationController.h"
#include "ContinueViewController.h"

namespace Mastermind {

class ContinueController: public OperationController, public ContinueViewController {
public:
    ContinueController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~ContinueController(){
    }

    virtual void resume(bool resume) override final {
        if (resume) {
            setState(State::INITIAL);
        } else {
            setState(State::EXIT);
        }

    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
