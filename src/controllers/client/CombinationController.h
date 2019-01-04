#ifndef SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class CombinationController : public ClientOperationController {
public:
    CombinationController(Game &game) :
        ClientOperationController(game)
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
