#ifndef SRC_CONTROLLERS_REDOCONTROLLER_H_
#define SRC_CONTROLLERS_REDOCONTROLLER_H_

#include "OperationController.h"

namespace Mastermind {

class RedoController: public OperationController {
public:
    RedoController(Game &game) :
        OperationController(game)
    {
    }

    virtual ~RedoController(){
    }

    void redo() {
        assert(game.getState() == State::REDO);

        std::cout << "********************* Redoing... \n";

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
