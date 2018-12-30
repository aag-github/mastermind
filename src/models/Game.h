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

    void start(bool recordUndoEvent = true) {
        currentProposedCombination = 0;

        secretCombination.random();

        for(auto& combination : proposedCombinations) {
            combination.clear();
        }

        if(recordUndoEvent) {
            undoRedoManager.clear();
            undoRedoManager.AddMemento();
        }
    }

    ProposedCombinationState setProposedCombination(const Combination& proposedCombination, bool recordUndoEvent = true) {
        ProposedCombination& target = proposedCombinations[currentProposedCombination];
        target = proposedCombination;

        bool right = target.calculateResult(secretCombination);

        bool lastCombination = (currentProposedCombination == (proposedCombinations.size() - 1));

        currentProposedCombination++;

        if (recordUndoEvent) {
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

    void setSecretCombination(const SecretCombination& secretCombination, bool recordUndoEvent = true) {
        this->secretCombination = secretCombination;

        if (recordUndoEvent) {
            undoRedoManager.clear();
            undoRedoManager.AddMemento();
        }
    }

    virtual std::shared_ptr<Memento> createMemento() const override final {
        std::shared_ptr<Memento> memento = std::make_shared<Memento>();
        memento->add("S:" + getSecretCombination().getString());
        auto combination = getProposedCombinations().cbegin();
        auto endCombination = getProposedCombinations().cend();
        for (;combination != endCombination, combination->isSet(); combination++) {
            memento->add("P:" + combination->getString());
        }
        return memento;
    }

    virtual MementoRestoreResult restoreMemento(std::shared_ptr<Memento> snapshot, bool recordUndoEvent) override final {
        MementoRestoreResult ret = MementoRestoreResult::OK;
        start(recordUndoEvent);

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
                    ret = MementoRestoreResult::SECRET_COMBINATION_ERROR;
                    break;
                }
                secret = value;
                setSecretCombination(secret, recordUndoEvent);
            } else if (command =="P") {
                Combination combination;
                if (value.size() != combination.size())
                {
                    ret = MementoRestoreResult::PROPOSED_COMBINATION_ERROR;
                    break;
                }
                combination = value;
                setProposedCombination(combination, recordUndoEvent);
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
