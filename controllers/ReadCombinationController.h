#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class ReadCombinationController : public CombinationController {
public:
    SetProposedCombination setProposedCombination;

    ReadCombinationController(Game &game) :
        CombinationController(game)
    {
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
        assert(getState() == State::READ_PROPOSED_COMBINATION);

        setState(State::GAME_END);
    }

};

}

#endif
