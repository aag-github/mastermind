#ifndef SRC_CONTROLLERS_UNDOCONTROLLER_H_
#define SRC_CONTROLLERS_UNDOCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class UndoController: public OperationController {
public:
    UndoController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~UndoController(){
    }

    void undo() {
        assert(game.getState() == State::UNDO);

        std::cout << "********************* Undoing... \n";

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
