#ifndef SRC_CONTROLLERS_UNDOCONTROLLER_H_
#define SRC_CONTROLLERS_UNDOCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class UndoController: public Controller {
public:
    UndoController(Game &game) :
        Controller(game)
    {
    }

    virtual ~UndoController(){
    }

    void undo() {
        assert(game.getState() == State::MAIN_MENU);

        game.Undo();

        game.setState(State::MAIN_MENU);
    }

    bool canUndo() {
        return game.canUndo();
    }

};

}

#endif
