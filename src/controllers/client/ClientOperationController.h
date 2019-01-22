#ifndef SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_CLIENTOPERATIONCONTROLLER_H_

#include "CombinationController.h"
#include "ClientOperationControllerVisitor.h"

namespace Mastermind {

class ClientOperationController : public CombinationController {
public:
    ClientOperationController(Game &game) :
        CombinationController(game)
    {
    }

    virtual ~ClientOperationController() {
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) = 0;

};

}

#endif
