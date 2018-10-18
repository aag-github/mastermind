#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "OperationController.h"
#include "ReadCombinationViewController.h"

namespace Mastermind {

class ReadCombinationController : public OperationController, public ReadCombinationViewController {
public:
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

    virtual const ProposedCombinationList& getProposedCombinations() override final {
        return OperationController::getProposedCombinations();
    }

    virtual const SecretCombination& getSecretCombination() override final {
        return OperationController::getSecretCombination();
    }

    virtual void setProposedCombination(size_t proposedCombinationIndex, const Combination& proposedCombination) override final {
        assert(proposedCombinationIndex < OperationController::getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndex];
        target = proposedCombination;
    }

    virtual ReadCombinationViewController::ReadCombinationStatus checkReadCombinationStatus(size_t proposedCombinationIndex) override final {
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

    virtual void gameEnd() override final {
        setState(State::FINAL);
    }
};

}

#endif
