#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class ReadCombinationController {
public:
    virtual ~ReadCombinationController() {};

    virtual void gameEnd(bool end) = 0;

    virtual ProposedCombinationState setProposedCombination (const Combination& proposedCombination) = 0;

    virtual const ProposedCombinationList& getProposedCombinations() const = 0;

    virtual const SecretCombination& getSecretCombination() const = 0;
};

class ReadCombinationControllerImpl : public CombinationController, public ReadCombinationController {
public:
    ReadCombinationControllerImpl(Game &game) :
        CombinationController(game)
    {
    }

    virtual ~ReadCombinationControllerImpl(){
    }

    virtual void gameEnd(bool end) override final {
        assert(game.getState() == State::MAIN_MENU);

        if (end) {
            game.setState(State::START_MENU);
        }
    }

    virtual ProposedCombinationState setProposedCombination (const Combination& proposedCombination) override final {
        return game.setProposedCombination(proposedCombination);
    }

    virtual const ProposedCombinationList& getProposedCombinations() const {
        return CombinationController::getProposedCombinations();
    }

    virtual const SecretCombination& getSecretCombination() const {
        return CombinationController::getSecretCombination();
    }

};

}

#endif
