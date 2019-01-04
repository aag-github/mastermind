#ifndef SRC_CONTROLLERS_SERVEROPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_SERVEROPERATIONCONTROLLER_H_

#include "Controller.h"
#include "ServerOperationControllerVisitor.h"

namespace Mastermind {

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
