#ifndef SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class CombinationController : public OperationController {
public:
    GetProposedCombinations getProposedCombinations;

    GetSecretCombination getSecretCombination;

    CombinationController(Game &game) :
        OperationController(game)
    {
        getProposedCombinations = [&game]() -> const ProposedCombinationList& { return game.getProposedCombinations(); };
        getSecretCombination = [&game]() -> const SecretCombination& { return game.getSecretCombination(); };
    }

    virtual ~CombinationController(){
    }

    void gameEnd() {
        setState(State::GAME_END);
    }

};

}

#endif
