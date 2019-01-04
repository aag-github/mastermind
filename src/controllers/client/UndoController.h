#ifndef SRC_CONTROLLERS_UNDOCONTROLLER_H_
#define SRC_CONTROLLERS_UNDOCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class UndoController: public ClientOperationController {
public:
    UndoController(Game &game) :
        ClientOperationController(game)
    {
    }

    virtual ~UndoController(){
    }

    void undo() {
        assert(game.getState() == State::UNDO);

        game.Undo();

        game.setState(State::MENU);
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
