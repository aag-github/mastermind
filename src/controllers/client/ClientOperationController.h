#ifndef SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLER_H_

#include "Controller.h"
#include "ClientOperationControllerVisitor.h"

namespace Mastermind {

class ClientOperationController : public Controller {
public:
    ClientOperationController(Game &game) :
        Controller(game)
    {
    }

    virtual ~ClientOperationController() {
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) = 0;

};

}

#endif
