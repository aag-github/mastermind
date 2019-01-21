#ifndef SRC_CONTROLLERS_REDOCONTROLLER_H_
#define SRC_CONTROLLERS_REDOCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class RedoController: public ClientOperationController {
public:
    RedoController(Game &game) :
        ClientOperationController(game)
    {
    }

    virtual ~RedoController(){
    }

    void redo() {
        assert(game.getState() == State::MAIN_MENU);

        game.Redo();

        game.setState(State::MAIN_MENU);
    }

    bool canRedo() {
        return game.canRedo();
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
