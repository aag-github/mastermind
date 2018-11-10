#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class ReadCombinationController : public CombinationController {
public:
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

    void gameEnd() {
        assert(game.getState() == State::READ_PROPOSED_COMBINATION);

        game.setState(State::GAME_END);
    }

    ProposedCombinationState setProposedCombination (const Combination& proposedCombination) {
        return game.setProposedCombination(proposedCombination);
    }

};

}

#endif
