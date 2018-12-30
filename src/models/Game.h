#ifndef SRC_MODELS_GAME_H_
#define SRC_MODELS_GAME_H_

#include <memento/MementoManager.h>
#include "State.h"
#include "SecretCombination.h"
#include "ProposedCombinationList.h"
#include "ProposedCombinationState.h"

namespace Mastermind {

class Game : public MementoOriginator {
public:
    static constexpr int MAX_PROPOSED_COMBINATION = 10;

    Game() :
        state(State::INITIAL),
        currentProposedCombination(0),
        undoRedoManager(this)
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

    void start(bool undoRedoEvent = true) {
        currentProposedCombination = 0;

        secretCombination.random();

        for(auto& combination : proposedCombinations) {
            combination.clear();
        }

        if(undoRedoEvent) {
            undoRedoManager.clear();
            undoRedoManager.AddMemento();
        }
    }

    ProposedCombinationState setProposedCombination(const Combination& proposedCombination, bool undoRedoEvent = true) {
        ProposedCombination& target = proposedCombinations[currentProposedCombination];
        target = proposedCombination;

        bool right = target.calculateResult(secretCombination);

        bool lastCombination = (currentProposedCombination == (proposedCombinations.size() - 1));

        currentProposedCombination++;

        if (undoRedoEvent) {
            undoRedoManager.AddMemento();
        }

        if (right) {
            return ProposedCombinationState::WIN;
        } else if (lastCombination ) {
            return ProposedCombinationState::LOSE;
        } else {
            return ProposedCombinationState::CONTINUE;
        }
    }

    void setSecretCombination(const SecretCombination& secretCombination) {
        this->secretCombination = secretCombination;
    }

    virtual Memento* createMemento() const override final {
        Memento *snapShot = new Memento();
        snapShot->add("S:" + getSecretCombination().getString());
        auto combination = getProposedCombinations().cbegin();
        auto endCombination = getProposedCombinations().cend();
        for (;combination != endCombination, combination->isSet(); combination++) {
            snapShot->add("P:" + combination->getString());
        }
        return snapShot;
    }

    virtual int restoreMemento(Memento *snapshot) override final {
        int ret = 0;
        start(false);

        for(auto line : snapshot->get()) {
            if  (line == "") {
                continue;
            }
            auto separator = line.find(':');
            std::string command = line.substr(0, separator);
            std::string value = line.substr(separator +1);

            if (command == "S") {
                SecretCombination secret;
                if (value.size() != secret.size())
                {
                    ret = -2;
                    break;
                }
                secret = value;
                setSecretCombination(secret);
            } else if (command =="P") {
                Combination combination;
                if (value.size() != combination.size())
                {
                    ret = -3;
                    break;
                }
                combination = value;
                setProposedCombination(combination, false);
            }
        }
        return ret;
    }

    MementoManager& getUndoRedoManager() {
        return undoRedoManager;
    }
private:

    SecretCombination secretCombination;

    ProposedCombinationList proposedCombinations;

    State state;

    size_t currentProposedCombination;

    MementoManager undoRedoManager;
};

}

#endif
