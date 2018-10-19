#ifndef SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_COMBINATIONCONTROLLER_H_

#include <functional>
#include "OperationController.h"

namespace Mastermind {

class CombinationController : public OperationController {
public:
    typedef std::function<ProposedCombinationList&()> GetProposedCombinations;
    
	typedef std::function<SecretCombination&()> GetSecretCombination;
	
    CombinationController(Game &game) :
        OperationController(game)
    {
        getProposedCombinations = [&game]() -> ProposedCombinationList& { return game.getProposedCombinations(); };
        getSecretCombination = [&game]() -> SecretCombination& { return game.getSecretCombination(); };
    }

    virtual ~CombinationController() {
    }

    GetProposedCombinations getProposedCombinations;

    GetSecretCombination getSecretCombination;

};

}

#endif
