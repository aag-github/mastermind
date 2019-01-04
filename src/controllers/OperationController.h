#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"
#include "OperationControllerVisitor.h"

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

class ServerOperationController : public Controller {
public:
    ServerOperationController(Game &game) :
        Controller(game)
    {
    }

    virtual ~ServerOperationController() {
    }

    virtual void accept(ServerOperationControllerVisitor *operationControllerVisitor) = 0;

};

}

#endif
