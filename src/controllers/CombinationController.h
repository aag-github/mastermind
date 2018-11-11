#ifndef SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class CombinationController : public OperationController {
public:
    CombinationController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~CombinationController(){
    }

    const ProposedCombinationList& getProposedCombinations() const {
        return game.getProposedCombinations();
    };

    const SecretCombination& getSecretCombination() const {
        return game.getSecretCombination();
    };

};

}

#endif
