#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class ReadCombinationController : public OperationController {
public:
    enum class ReadCombinationStatus {
        CONTINUE,
        WIN,
        LOSE
    };

    ReadCombinationController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~ReadCombinationController(){
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    const ProposedCombinationList& getProposedCombinations() {
        return OperationController::getProposedCombinations();
    }

    const SecretCombination& getSecretCombination() {
        return OperationController::getSecretCombination();
    }

    ReadCombinationStatus setProposedCombination(size_t proposedCombinationIndex, const Combination& proposedCombination) {
        assert(proposedCombinationIndex < getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndex];
        target = proposedCombination;

        target.calculateResult(getSecretCombination());
        bool right = target.isRight();

        bool lastCombination = (proposedCombinationIndex == (getProposedCombinations().size() - 1));

        if (right) {
            return ReadCombinationStatus::WIN;
        } else if (lastCombination ) {
            return ReadCombinationStatus::LOSE;
        } else {
            return ReadCombinationStatus::CONTINUE;
        }
    }

    void gameEnd() {
        setState(State::FINAL);
    }
};

}

#endif
