#ifndef SRC_CONTROLLERS_REDOCONTROLLER_H_
#define SRC_CONTROLLERS_REDOCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class RedoController {
public:
    virtual ~RedoController() {};

    virtual void redo() = 0;

    virtual bool canRedo() = 0;
};

class RedoControllerImpl: public Controller, public RedoController {
public:
    RedoControllerImpl(Game &game) :
        Controller(game)
    {
    }

    virtual ~RedoControllerImpl(){
    }

    virtual void redo() override final {
        assert(game.getState() == State::MAIN_MENU);

        game.Redo();

        game.setState(State::MAIN_MENU);
    }

    virtual bool canRedo() override final {
        return game.canRedo();
    }

};

}

#endif
