#ifndef SRC_CONTROLLERS_REDOCONTROLLER_H_
#define SRC_CONTROLLERS_REDOCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class RedoController: public CombinationController {
public:
    RedoController(Game &game) :
        CombinationController(game)
    {
    }

    virtual ~RedoController(){
    }

    void redo() {
        assert(game.getState() == State::REDO);

        game.getUndoRedoManager().Redo();

        game.setState(State::MENU);
    }

    virtual void accept(OperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
