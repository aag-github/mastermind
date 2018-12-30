#ifndef SRC_MODELS_MEMENTO_MEMENTOORIGINATOR_H_
#define SRC_MODELS_MEMENTO_MEMENTOORIGINATOR_H_

#include "MementoRestoreResult.h"
#include <memory>

namespace Mastermind {

class Memento;

class MementoOriginator {
public:
    virtual ~MementoOriginator() {}

    virtual std::shared_ptr<Memento> createMemento() const = 0;

    virtual MementoRestoreResult restoreMemento(std::shared_ptr<Memento> memento, bool recordUndoEvent) = 0;
};

}

#endif
