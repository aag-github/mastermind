#ifndef SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class CombinationController : public Controller {
public:
    CombinationController(Game &game) :
        Controller(game)
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
