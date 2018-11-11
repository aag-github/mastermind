#ifndef SRC_MODELS_GAME_H_
#define SRC_MODELS_GAME_H_

#include "State.h"
#include "SecretCombination.h"
#include "ProposedCombinationList.h"
#include "ProposedCombinationState.h"

namespace Mastermind {

class Game {
public:
    static constexpr int MAX_PROPOSED_COMBINATION = 10;

    Game() :
        state(State::INITIAL),
        currentProposedCombination(0)
    {
        srand(time(nullptr));
        proposedCombinations.resize(MAX_PROPOSED_COMBINATION);
    }

    virtual ~Game(){
    }

    State getState() const {
        return state;
    }

    void setState(State state) {
        this->state = state;
    }

    const SecretCombination& getSecretCombination() const {
        return secretCombination;
    }

    const ProposedCombinationList& getProposedCombinations() const {
        return proposedCombinations;
    }

    void start() {
        currentProposedCombination = 0;

        secretCombination.random();

        for(auto& combination : proposedCombinations) {
            combination.clear();
        }
    }

    ProposedCombinationState setProposedCombination(const Combination& proposedCombination) {
        ProposedCombination& target = proposedCombinations[currentProposedCombination];
        target = proposedCombination;

        bool right = target.calculateResult(secretCombination);

        bool lastCombination = (currentProposedCombination == (proposedCombinations.size() - 1));

        currentProposedCombination++;

        if (right) {
            return ProposedCombinationState::WIN;
        } else if (lastCombination ) {
            return ProposedCombinationState::LOSE;
        } else {
            return ProposedCombinationState::CONTINUE;
        }
    }

private:

    SecretCombination secretCombination;

    ProposedCombinationList proposedCombinations;

    State state;

    size_t currentProposedCombination;
};

}

#endif
