#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class ReadCombinationController : public OperationController {
public:
    typedef std::function<ProposedCombinationList&()> GetProposedCombinations;

    typedef std::function<SecretCombination&()> GetSecretCombination;

    typedef std::function<ReadCombinationStatus (const Combination& proposedCombination)> SetProposedCombination;

    GetProposedCombinations getProposedCombinations;

    GetSecretCombination getSecretCombination;

    SetProposedCombination setProposedCombination;

    ReadCombinationController(Game &game) :
        OperationController(game)
    {
        getProposedCombinations = [&game]() -> ProposedCombinationList& { return game.getProposedCombinations(); };
        getSecretCombination = [&game]() -> SecretCombination& { return game.getSecretCombination(); };
        setProposedCombination = [&game](const Combination& proposedCombination) { return game.setProposedCombination(proposedCombination); };
    }

    virtual ~ReadCombinationController(){
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    void gameEnd() {
        setState(State::FINAL);
    }

};

}

#endif
