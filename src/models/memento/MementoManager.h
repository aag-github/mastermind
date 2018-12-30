#ifndef SRC_MODELS_MEMENTO_MEMENTOMANAGER_H_
#define SRC_MODELS_MEMENTO_MEMENTOMANAGER_H_

#include <memento/Memento.h>
#include <memento/MementoOriginator.h>
#include <vector>
#include <iostream>

namespace Mastermind {

class MementoManager {
public:
    MementoManager(MementoOriginator *mementoOriginator) :
        mementoOriginator(mementoOriginator)
    {
        currentMemento = mementoes.begin();
    }
    virtual ~MementoManager() {
        clear();
    }

    void AddMemento() {
        if (mementoes.size() > 0) {
            mementoes.erase(currentMemento + 1, mementoes.end());
        }
        Memento* m = mementoOriginator->createMemento();
        mementoes.push_back(m);
        currentMemento = (mementoes.end() - 1);
    }

    bool canUndo() {
        return (mementoes.size() > 0 && currentMemento != mementoes.begin());
    }

    bool canRedo() {
        return (mementoes.size() > 0 && currentMemento != (mementoes.end() - 1));
    }

    bool Undo() {
        if (canUndo()) {
            --currentMemento;
            mementoOriginator->restoreMemento(*currentMemento);
            return true;
        } else {
            return false;
        }
    }

    bool Redo() {
        if (canRedo()) {
            ++currentMemento;
            mementoOriginator->restoreMemento(*currentMemento);
            return true;
        } else {
            return false;
        }
    }

    void clear() {
        for (auto memento : mementoes) {
            delete memento;
        }
        mementoes.clear();
        currentMemento = mementoes.begin();
    }
private:
    std::vector<Memento*> mementoes;

    std::vector<Memento*>::iterator currentMemento;

    MementoOriginator *mementoOriginator;
};

}

#endif
