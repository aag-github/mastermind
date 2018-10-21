#ifndef SRC_CONTROLLERS_CONTROLLER_H_
#define SRC_CONTROLLERS_CONTROLLER_H_

#include "Game.h"

namespace Mastermind {

class Controller {
public:
    virtual ~Controller() {
    }

protected:
    Controller(Game &game) :
        game(game)
    {
    }

    void setState(State state) {
        game.setState(state);
    }

private:
    Game &game;

};

}

#endif
