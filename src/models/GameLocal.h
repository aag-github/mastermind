#ifndef SRC_MODELS_GAMELOCAL_H_
#define SRC_MODELS_GAMELOCAL_H_

#include <memento/MementoManager.h>
#include "State.h"
#include "SecretCombination.h"
#include "ProposedCombinationList.h"
#include "ProposedCombinationState.h"

namespace Mastermind {

class GameLocal : public Game {
public:
    static constexpr int MAX_PROPOSED_COMBINATION = 10;

    GameLocal() :
        Game(),
        state(State::INITIAL),
        currentProposedCombination(0),
        undoRedoManager(this)
    {
        srand(time(nullptr));
        proposedCombinations.resize(MAX_PROPOSED_COMBINATION);
    }

    virtual ~GameLocal(){
    }

    virtual State getState() const override final {
        return state;
    }

    virtual void setState(State state) override final {
        this->state = state;
    }

    virtual const SecretCombination& getSecretCombination() const override final {
        return secretCombination;
    }

    virtual const ProposedCombinationList& getProposedCombinations() const override final {
        return proposedCombinations;
    }

    virtual void start(bool recordUndoEvent = true) override final {
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

    virtual ProposedCombinationState setProposedCombination(const Combination& proposedCombination, bool recordUndoEvent = true) override final {
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

    virtual void setSecretCombination(const SecretCombination& secretCombination, bool recordUndoEvent = true) override final {
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


    virtual void AddUndo() override final {
        undoRedoManager.AddMemento();
    }

    virtual bool canUndo() override final {
        return undoRedoManager.canUndo();
    }

    virtual bool canRedo() override final {
        return undoRedoManager.canRedo();
    }

    virtual bool Undo() override final {
        return undoRedoManager.Undo();
    }

    virtual bool Redo() override final {
        return undoRedoManager.Redo();
    }

    virtual void clearUndoRedo() override final {
        undoRedoManager.clear();
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
