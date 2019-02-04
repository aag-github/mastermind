#ifndef SRC_CONTROLLERS_RESTARTCONTROLLER_H_
#define SRC_CONTROLLERS_RESTARTCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class RestartController {
public:
    virtual ~RestartController() {};

    virtual void restart() = 0;
};

class RestartControllerImpl : public Controller, public RestartController {
public:
    RestartControllerImpl(Game &game) :
        Controller(game)
    {
    }

    virtual ~RestartControllerImpl(){
    }

    virtual void restart() override final {
        assert(game.getState() == State::MAIN_MENU);

        game.setState(State::START_MENU);
    }
};

}

#endif
