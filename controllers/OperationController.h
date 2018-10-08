#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class OperationController : public Controller {
public:
    virtual ~OperationController() {
    }

    virtual void control() = 0;

protected:
    OperationController(Game &game) :
        Controller(game)
    {
    }
};

}

#endif
