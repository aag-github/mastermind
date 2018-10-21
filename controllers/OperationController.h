#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"
#include "OperationControllerVisitor.h"

namespace Mastermind {

class OperationController : public Controller {
public:
    typedef std::function<ReadCombinationState (const Combination& proposedCombination)> SetProposedCombination;

    typedef std::function<void ()> StartGame;

    typedef std::function<ProposedCombinationList&()> GetProposedCombinations;

    typedef std::function<SecretCombination&()> GetSecretCombination;

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
