#ifndef SRC_MODELS_MEMENTO_MEMENTOORIGINATOR_H_
#define SRC_MODELS_MEMENTO_MEMENTOORIGINATOR_H_

namespace Mastermind {

class Memento;

class MementoOriginator {
public:
    virtual ~MementoOriginator() {}

    virtual Memento* createMemento() const = 0;

    virtual int restoreMemento(Memento *snapshot) = 0;
};

}

#endif
