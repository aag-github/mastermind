#ifndef SRC_CONTROLLERS_RESTARTCONTROLLER_H_
#define SRC_CONTROLLERS_RESTARTCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class RestartController : public Controller{
public:
    RestartController(Game &game) :
        Controller(game)
    {
    }

    virtual ~RestartController(){
    }

    void restart(bool restart) {
        assert(game.getState() == State::MAIN_MENU);

        if (restart) {
            game.setState(State::INITIAL);
        } else {
            game.setState(State::MAIN_MENU);
        }
    }
};

}

#endif
