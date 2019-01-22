#ifndef SRC_CONTROLLERS_REDOCONTROLLER_H_
#define SRC_CONTROLLERS_REDOCONTROLLER_H_

#include "Controller.h"

namespace Mastermind {

class RedoController: public Controller {
public:
    RedoController(Game &game) :
        Controller(game)
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

};

}

#endif
