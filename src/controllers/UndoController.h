#ifndef SRC_CONTROLLERS_UNDOCONTROLLER_H_
#define SRC_CONTROLLERS_UNDOCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class UndoController: public CombinationController {
public:
    UndoController(Game &game) :
        CombinationController(game)
    {
    }

    virtual ~UndoController(){
    }

    void undo() {
        assert(game.getState() == State::UNDO);

        game.getUndoRedoManager().Undo();

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
