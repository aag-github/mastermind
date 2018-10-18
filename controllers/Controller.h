#ifndef SRC_CONTROLLERS_CONTROLLER_H_
#define SRC_CONTROLLERS_CONTROLLER_H_

#include "Game.h"

namespace Mastermind {

class Controller {
public:
    virtual ~Controller() {
    }

protected:
    Controller(Game &game) :
        game(game)
    {

    }

    State getState() {
        return game.getState();
    }

    void setState(State state) {
        game.setState(state);
    }

    ProposedCombinationList& getProposedCombinations() {
        return game.getProposedCombinations();
    }

    SecretCombination &getSecretCombination() {
        return game.getSecretCombination();
    }

private:
    Game &game;

};

}

#endif
