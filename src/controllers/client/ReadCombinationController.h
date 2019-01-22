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

    void gameEnd(bool end) {
        assert(game.getState() == State::MAIN_MENU);

        if (end) {
            game.setState(State::START_MENU);
        }
    }

    ProposedCombinationState setProposedCombination (const Combination& proposedCombination) {
        return game.setProposedCombination(proposedCombination);
    }

};

}

#endif
