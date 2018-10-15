#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "GameEndView.h"
#include "OperationController.h"
#include "ReadCombinationViewController.h"
#include "ProposedCombinationView.h"
#include "ResultView.h"
#include "BoardView.h"

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

    virtual const ProposedCombinationList& getProposedCombinations() {
        return OperationController::getProposedCombinations();
    }

    virtual void setProposedCombination(size_t proposedCombinationIndex, const Combination& proposedCombination) override final {
        assert(proposedCombinationIndex < OperationController::getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndex];
        target = proposedCombination;
    }

    virtual bool isGameFinished(size_t proposedCombinationIndexindex) override final {
        assert(proposedCombinationIndexindex < OperationController::getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndexindex];
        target.calculateResult(getSecretCombination());
        bool right = target.isRight();

        bool lastCombination = (proposedCombinationIndexindex == (OperationController::getProposedCombinations().size() - 1));

        if (lastCombination || right) {
            return true;
        } else {
            return false;
        }
    }

    virtual void gameEnd(size_t proposedCombinationIndexindex) override final {
        assert(proposedCombinationIndexindex < OperationController::getProposedCombinations().size());

        ProposedCombination& target = OperationController::getProposedCombinations()[proposedCombinationIndexindex];
        GameEndView(&getSecretCombination(), target.isRight()).show();

        setState(State::FINAL);
    }
};

}

#endif
