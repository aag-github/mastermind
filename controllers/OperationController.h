#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class OperationController : public Controller {
public:
    OperationController(Game &game) :
        Controller(game)
    {
    }

    virtual ~OperationController() {
    }

    virtual void control() = 0;

};

}

#endif
