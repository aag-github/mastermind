#ifndef SRC_CONTROLLERS_OPERATIONCONTROLLER_H_
#define SRC_CONTROLLERS_OPERATIONCONTROLLER_H_

#include <functional>
#include "Controller.h"
#include "OperationControllerVisitor.h"

namespace Mastermind {

class OperationController : public Controller {
public:
    typedef std::function<ProposedCombinationList&()> GetProposedCombinations;
    
	typedef std::function<SecretCombination&()> GetSecretCombination;
	
    OperationController(Game &game) :
        Controller(game)
    {
        getProposedCombinations = [&game]() -> ProposedCombinationList& { return game.getProposedCombinations(); };
        getSecretCombination = [&game]() -> SecretCombination& { return game.getSecretCombination(); };
    }

    virtual ~OperationController() {
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) = 0;

    GetProposedCombinations getProposedCombinations;

    GetSecretCombination getSecretCombination;

};

}

#endif
