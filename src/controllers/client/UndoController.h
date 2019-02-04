#ifndef SRC_CONTROLLERS_UNDOCONTROLLER_H_
#define SRC_CONTROLLERS_UNDOCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class UndoController {
public:
    virtual ~UndoController() {};

    virtual void undo() = 0;

    virtual bool canUndo() = 0;
};

class UndoControllerImpl: public Controller, public UndoController {
public:
    UndoControllerImpl(Game &game) :
        Controller(game)
    {
    }

    virtual ~UndoControllerImpl(){
    }

    virtual void undo() override final {
        assert(game.getState() == State::MAIN_MENU);

        game.Undo();

        game.setState(State::MAIN_MENU);
    }

    virtual bool canUndo() override final {
        return game.canUndo();
    }

};

}

#endif
