#ifndef SRC_MODELS_GAME_H_
#define SRC_MODELS_GAME_H_

#include "State.h"
#include "SecretCombination.h"
#include "ProposedCombination.h"

namespace Mastermind {

class Game {
public:
    static constexpr int MAX_PROPOSED_COMBINATION = 10;

    Game() :
        state(State::INITIAL)
    {
        srand(time(nullptr));
        proposedCombinations.resize(MAX_PROPOSED_COMBINATION);
    }

    virtual ~Game(){
    }

    State getState() {
        return state;
    }

    void setState(State state) {
        this->state = state;
    }

    SecretCombination& getSecretCombination() {
        return secretCombination;
    }

    std::vector<ProposedCombination>& getProposedCombinations() {
        return proposedCombinations;
    }


private:

    SecretCombination secretCombination;

    std::vector<ProposedCombination> proposedCombinations;

    State state;
};

}

#endif
