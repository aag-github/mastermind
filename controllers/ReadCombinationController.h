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
        return Controller::getProposedCombinations();
    }

    const SecretCombination& getSecretCombination() {
        return Controller::getSecretCombination();
    }

    void setProposedCombination(size_t proposedCombinationIndex, const Combination& proposedCombination) {
        assert(proposedCombinationIndex < OperationController::getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndex];
        target = proposedCombination;
    }

    ReadCombinationStatus checkReadCombinationStatus(size_t proposedCombinationIndex) {
        assert(proposedCombinationIndex < OperationController::getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndex];
        target.calculateResult(getSecretCombination());
        bool right = target.isRight();

        bool lastCombination = (proposedCombinationIndex == (OperationController::getProposedCombinations().size() - 1));

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
