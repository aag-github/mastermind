#ifndef SRC_MODELS_GAME_H_
#define SRC_MODELS_GAME_H_

#include "State.h"
#include "ReadCombinationStatus.h"
#include "SecretCombination.h"
#include "ProposedCombinationList.h"

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

    SecretCombination& getSecretCombination() {
        return secretCombination;
    }

    ProposedCombinationList& getProposedCombinations() {
        return proposedCombinations;
    }

    void start() {
        currentProposedCombination = 0;

        secretCombination.random();

        for(auto& combination : proposedCombinations) {
            combination.clear();
        }
    }

    ReadCombinationStatus setProposedCombination(const Combination& proposedCombination) {
        ProposedCombination& target = proposedCombinations[currentProposedCombination];
        target = proposedCombination;

        target.calculateResult(secretCombination);
        bool right = target.isRight();

        bool lastCombination = (currentProposedCombination == (proposedCombinations.size() - 1));

        currentProposedCombination++;

        if (right) {
            return ReadCombinationStatus::WIN;
        } else if (lastCombination ) {
            return ReadCombinationStatus::LOSE;
        } else {
            return ReadCombinationStatus::CONTINUE;
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
