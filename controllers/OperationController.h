#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"
#include "OperationControllerVisitor.h"

namespace Mastermind {

class OperationController : public Controller {
public:
    OperationController(Game &game) :
        Controller(game)
    {
    }

    virtual ~OperationController() {
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) = 0;

};

}

#endif
