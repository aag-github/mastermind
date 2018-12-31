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
    Game() : MementoOriginator() {
    }

    virtual ~Game(){
    }

    virtual State getState() const = 0;

    virtual void setState(State state) = 0;

    virtual const SecretCombination& getSecretCombination() const = 0;

    virtual const ProposedCombinationList& getProposedCombinations() const = 0;

    virtual void start(bool recordUndoEvent = true) = 0;

    virtual ProposedCombinationState setProposedCombination(const Combination& proposedCombination, bool recordUndoEvent = true) = 0;

    virtual void setSecretCombination(const SecretCombination& secretCombination, bool recordUndoEvent = true) = 0;

    virtual void AddUndo() = 0;

    virtual bool canUndo() = 0;

    virtual bool canRedo() = 0;

    virtual bool Undo() = 0;

    virtual bool Redo() = 0;

    virtual void clearUndoRedo() = 0;
};

}

#endif
