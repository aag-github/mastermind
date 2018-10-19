#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class ReadCombinationController : public CombinationController {
public:
    enum class ReadCombinationStatus {
        CONTINUE,
        WIN,
        LOSE
    };

    ReadCombinationController(Game &game) :
        CombinationController(game)
    {
    }

    virtual ~ReadCombinationController(){
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    ReadCombinationStatus setProposedCombination(size_t proposedCombinationIndex, const Combination& proposedCombination) {
        assert(proposedCombinationIndex < getProposedCombinations().size());

        ProposedCombination& target = CombinationController::getProposedCombinations()[proposedCombinationIndex];
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
